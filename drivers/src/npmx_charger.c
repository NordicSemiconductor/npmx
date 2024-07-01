/*
 * Copyright (c) 2022 - 2023, Nordic Semiconductor ASA
 * All rights reserved.
 *
 * SPDX-License-Identifier: BSD-3-Clause
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions are met:
 *
 * 1. Redistributions of source code must retain the above copyright notice, this
 *    list of conditions and the following disclaimer.
 *
 * 2. Redistributions in binary form must reproduce the above copyright
 *    notice, this list of conditions and the following disclaimer in the
 *    documentation and/or other materials provided with the distribution.
 *
 * 3. Neither the name of the copyright holder nor the names of its
 *    contributors may be used to endorse or promote products derived from this
 *    software without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
 * AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
 * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
 * ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE
 * LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
 * CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF
 * SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS
 * INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN
 * CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)
 * ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
 * POSSIBILITY OF SUCH DAMAGE.
 */

#include <npmx_charger.h>
#include <npmx_instance.h>

/* Check if the mask for all NTC temperatures values are the same. */
NPMX_STATIC_ASSERT(BCHARGER_NTCCOLDLSB_NTCCOLDLVLLSB_Msk == BCHARGER_NTCCOOLLSB_NTCCOOLLVLLSB_Msk);
NPMX_STATIC_ASSERT(BCHARGER_NTCCOLDLSB_NTCCOLDLVLLSB_Msk == BCHARGER_NTCWARMLSB_NTCWARMLVLLSB_Msk);
NPMX_STATIC_ASSERT(BCHARGER_NTCCOLDLSB_NTCCOLDLVLLSB_Msk == BCHARGER_NTCHOTLSB_NTCHOTLVLLSB_Msk);

/* Static assertion for errors registers. */
NPMX_STATIC_ASSERT((offsetof(NPM_BCHARGER_Type, BCHGERRSENSOR) -
                    offsetof(NPM_BCHARGER_Type, BCHGERRREASON)) == 1);

/** @brief Minimum possible value of NTC temperature threshold. */
#define CHARGER_NTC_TEMPERATURE_MIN -20L

/** @brief Maximum possible value of NTC temperature threshold. */
#define CHARGER_NTC_TEMPERATURE_MAX 60L

/** @brief The difference in centigrade scale between 0 degrees Celsius to absolute zero temperature. */
#define ABSOLUTE_ZERO_DIFFERENCE 273.15f

/**
 * @brief All thermistors values are defined for 25 degrees Celsius.
 *        For calculations, values must be converted into degrees Kelvin.
 */
#define THERMISTOR_NOMINAL_TEMPERATURE (25.0f + ABSOLUTE_ZERO_DIFFERENCE)

/**
 * @brief Function for activating the specified charger task.
 *
 * @param[in] p_instance Pointer to the CHARGER instance.
 * @param[in] task       Task to be activated.
 *
 * @retval NPMX_SUCCESS  Operation performed successfully.
 * @retval NPMX_ERROR_IO Error using IO bus line.
 */
static npmx_error_t task_trigger(npmx_charger_t const * p_instance, npmx_charger_task_t task)
{
    uint8_t data = NPMX_TASK_TRIGGER;

    static const uint16_t task_addr[NPMX_CHARGER_TASK_COUNT] =
    {
        [NPMX_CHARGER_TASK_RELEASE]      = NPMX_REG_TO_ADDR(NPM_BCHARGER->TASKRELEASEERR),
        [NPMX_CHARGER_TASK_CLEAR_ERROR]  = NPMX_REG_TO_ADDR(NPM_BCHARGER->TASKCLEARCHGERR),
        [NPMX_CHARGER_TASK_CLEAR_TIMERS] = NPMX_REG_TO_ADDR(NPM_BCHARGER->TASKCLEARSAFETYTIMER),
    };

    return npmx_backend_register_write(p_instance->p_pmic->p_backend,
                                       task_addr[task],
                                       &data,
                                       1);
}

/**
 * @brief Function for calculating NTC code based on nominal and desired NTC resistance.
 *
 * @param[in] desired_resistance The resistance value in Ohms at which NTC threshold event happen.
 * @param[in] nominal_resistance The nominal resistance value of NTC battery resistor in Ohms.
 *
 * @return Registers code.
 */
static uint16_t ntc_code_get(uint64_t desired_resistance, uint64_t nominal_resistance)
{
    uint64_t code = NPM_BCHARGER_ADC_BITS_RESOLUTION;

    code *= desired_resistance;
    code /= (desired_resistance + nominal_resistance);

    return (uint16_t)(code & (uint64_t)UINT16_MAX);
}

/**
 * @brief Function for getting the die temperature code value from the temperature value.
 *        The equation and magic numbers based on product specification.
 *
 * @param temperature The temperature in *C at which die threshold event happens.
 *
 * @return The code value.
 */
static uint16_t die_temperature_to_code(int16_t temperature)
{
    uint32_t code = (uint32_t)((int32_t)NPM_BCHARGER_DIE_TEMPERATURE_CONST_1 -
                               (int32_t)((int32_t)temperature *
                                         (int32_t)NPM_BCHARGER_DIE_TEMPERATURE_MULTIPLIER));

    return (uint16_t)npmx_common_div_round_closest(code, NPM_BCHARGER_DIE_TEMPERATURE_CONST_2);
}

/**
 * @brief Function for getting the temperature value from the die temperature code value.
 *        The equation and magic numbers based on product specification.
 *        Because of the rounding in @ref die_temperature_to_code()
 *        the @em temperature set by  @ref die_code_to_temperature() can be different
 *        then the @em temperature in @ref die_temperature_to_code().
 *
 * @param code Code temperature from register device.
 *
 * @return The temperature value.
 */
static int16_t die_code_to_temperature(uint16_t code)
{
    int32_t temperature = (int32_t)NPM_BCHARGER_DIE_TEMPERATURE_CONST_1 -
                          (int32_t)((uint32_t)code * NPM_BCHARGER_DIE_TEMPERATURE_CONST_2);

    return (int16_t)npmx_common_div_round_closest(temperature,
                                                  (int32_t)NPM_BCHARGER_DIE_TEMPERATURE_MULTIPLIER);
}

/**
 * @brief Function for setting the NTC resistance threshold.
 *
 * @note Resistance value should be read from NTC characteristic for selected temperature.
 *
 * @param[in] p_instance Pointer to the CHARGER instance.
 * @param[in] reg        Start MSB register address, can be address to: NTCCOLD, NTCCOOL, NTCWARM, NTCHOT.
 * @param[in] resistance Resistance threshold in Ohms, value should be greater than 0.
 *
 * @retval NPMX_SUCCESS  Operation performed successfully.
 * @retval NPMX_ERROR_IO Error using IO bus line.
 */
static npmx_error_t resistance_set(npmx_charger_t const * p_instance,
                                   uint16_t               reg,
                                   uint32_t               resistance)
{
    uint32_t     ntc_resistance;
    npmx_error_t err_code = npmx_adc_ntc_resistance_get(npmx_adc_get(p_instance->p_pmic, 0),
                                                        &ntc_resistance);

    if (err_code != NPMX_SUCCESS)
    {
        return err_code;
    }

    uint16_t code    = ntc_code_get(resistance, ntc_resistance);
    uint8_t  data[2] =
    {
        [0] = (uint8_t)(code >> NPM_BCHARGER_RESISTANCE_MSB_SHIFT),
        [1] = (uint8_t)(code & BCHARGER_NTCCOLDLSB_NTCCOLDLVLLSB_Msk),
    };

    return npmx_backend_register_write(p_instance->p_pmic->p_backend, reg, data, 2);
}

/**
 * @brief Function for reading the resistance from specified MSB start register.
 *
 * @param[in]  p_instance   Pointer to the CHARGER instance.
 * @param[in]  reg          Start MSB register address, can be address to: NTCCOLD, NTCCOOL, NTCWARM, NTCHOT.
 * @param[out] p_resistance Pointer to the resistance variable, in Ohms.
 *
 * @retval NPMX_SUCCESS  Operation performed successfully.
 * @retval NPMX_ERROR_IO Error using IO bus line.
 */
static npmx_error_t resistance_get(npmx_charger_t const * p_instance,
                                   uint16_t               reg,
                                   uint32_t *             p_resistance)
{
    uint8_t      data[2];
    uint32_t     ntc_resistance;
    npmx_error_t err_code = npmx_backend_register_read(p_instance->p_pmic->p_backend,
                                                       reg,
                                                       data,
                                                       2);

    if (err_code != NPMX_SUCCESS)
    {
        return err_code;
    }

    err_code = npmx_adc_ntc_resistance_get(npmx_adc_get(p_instance->p_pmic, 0), &ntc_resistance);

    if (err_code != NPMX_SUCCESS)
    {
        return err_code;
    }

    uint32_t code = ((uint16_t)data[0] << NPM_BCHARGER_RESISTANCE_MSB_SHIFT) |
                    (uint16_t)(data[1] & BCHARGER_NTCCOLDLSB_NTCCOLDLVLLSB_Msk);

    *p_resistance = (code * ntc_resistance) / (NPM_BCHARGER_ADC_BITS_RESOLUTION - code);

    return NPMX_SUCCESS;
}

/**
 * @brief Function for setting the NTC temperature threshold.
 *
 * @note Resistance value should be read from NTC characteristic for selected temperature.
 *
 * @param[in] p_instance  Pointer to the CHARGER instance.
 * @param[in] reg         Start MSB register address, can be address to: NTCCOLD, NTCCOOL, NTCWARM, NTCHOT.
 * @param[in] temperature Temperature threshold in Celsius, value should be in range [-20,60].
 *
 * @retval NPMX_SUCCESS  Operation performed successfully.
 * @retval NPMX_ERROR_IO Error using IO bus line.
 */
static npmx_error_t temperature_set(npmx_charger_t const * p_instance,
                                    uint16_t               reg,
                                    int16_t                temperature)
{
    npmx_adc_ntc_config_t ntc_config;
    npmx_error_t          err_code = npmx_adc_ntc_config_get(npmx_adc_get(p_instance->p_pmic, 0),
                                                             &ntc_config);

    if (err_code != NPMX_SUCCESS)
    {
        return err_code;
    }

    float target_temperature = ((float)temperature + ABSOLUTE_ZERO_DIFFERENCE);
    float exp_val            =
        ((1.0f / THERMISTOR_NOMINAL_TEMPERATURE) - (1.0f / target_temperature)) *
        (float)ntc_config.beta;
    float code_float = NPM_BCHARGER_ADC_BITS_RESOLUTION / (npmx_common_exp_get(exp_val) + 1);

    uint16_t code    = (uint16_t)npmx_common_round_get(code_float);
    uint8_t  data[2] =
    {
        [0] = (uint8_t)(code >> NPM_BCHARGER_RESISTANCE_MSB_SHIFT),
        [1] = (uint8_t)(code & BCHARGER_NTCCOLDLSB_NTCCOLDLVLLSB_Msk),
    };

    return npmx_backend_register_write(p_instance->p_pmic->p_backend, reg, data, 2);
}

/**
 * @brief Function for reading the temperature from specified MSB start register.
 *
 * @param[in]  p_instance    Pointer to the CHARGER instance.
 * @param[in]  reg           Start MSB register address, can be address to: NTCCOLD, NTCCOOL, NTCWARM, NTCHOT.
 * @param[out] p_temperature Pointer to the temperature variable, in Celsius.
 *
 * @retval NPMX_SUCCESS  Operation performed successfully.
 * @retval NPMX_ERROR_IO Error using IO bus line.
 */
static npmx_error_t temperature_get(npmx_charger_t const * p_instance,
                                    uint16_t               reg,
                                    int16_t *              p_temperature)
{
    uint8_t      data[2];
    npmx_error_t err_code = npmx_backend_register_read(p_instance->p_pmic->p_backend,
                                                       reg,
                                                       data,
                                                       2);

    if (err_code != NPMX_SUCCESS)
    {
        return err_code;
    }

    npmx_adc_ntc_config_t ntc_config;

    err_code = npmx_adc_ntc_config_get(npmx_adc_get(p_instance->p_pmic, 0),
                                       &ntc_config);

    if (err_code != NPMX_SUCCESS)
    {
        return err_code;
    }

    uint32_t code = ((uint16_t)data[0] << NPM_BCHARGER_RESISTANCE_MSB_SHIFT) |
                    (uint16_t)(data[1] & BCHARGER_NTCCOLDLSB_NTCCOLDLVLLSB_Msk);

    float numerator = THERMISTOR_NOMINAL_TEMPERATURE * (float)ntc_config.beta;
    float ln_value  = npmx_common_ln_get((float)NPM_BCHARGER_ADC_BITS_RESOLUTION /
                                         (float)code - 1.0f);
    float   denominator = (float)ntc_config.beta - (THERMISTOR_NOMINAL_TEMPERATURE * ln_value);
    int32_t temperature = npmx_common_round_get((numerator / denominator) -
                                                ABSOLUTE_ZERO_DIFFERENCE);

    *p_temperature = (int16_t)(temperature <= CHARGER_NTC_TEMPERATURE_MAX ?
                               (temperature >=
                                CHARGER_NTC_TEMPERATURE_MIN ? temperature :
                                                              CHARGER_NTC_TEMPERATURE_MIN)
    :
                                                              CHARGER_NTC_TEMPERATURE_MAX);

    return NPMX_SUCCESS;
}

npmx_charger_t * npmx_charger_get(npmx_instance_t * p_pmic, uint8_t idx)
{
    NPMX_ASSERT(p_pmic);
    NPMX_ASSERT(idx < NPM_BCHARGER_COUNT);

    return &p_pmic->charger[idx];
}

npmx_charger_voltage_t npmx_charger_voltage_convert(uint32_t millivolts)
{
    switch (millivolts)
    {
        case 3500:
            return NPMX_CHARGER_VOLTAGE_3V50;
        case 3550:
            return NPMX_CHARGER_VOLTAGE_3V55;
        case 3600:
            return NPMX_CHARGER_VOLTAGE_3V60;
        case 3650:
            return NPMX_CHARGER_VOLTAGE_3V65;
        case 4000:
            return NPMX_CHARGER_VOLTAGE_4V00;
        case 4050:
            return NPMX_CHARGER_VOLTAGE_4V05;
        case 4100:
            return NPMX_CHARGER_VOLTAGE_4V10;
        case 4150:
            return NPMX_CHARGER_VOLTAGE_4V15;
        case 4200:
            return NPMX_CHARGER_VOLTAGE_4V20;
        case 4250:
            return NPMX_CHARGER_VOLTAGE_4V25;
        case 4300:
            return NPMX_CHARGER_VOLTAGE_4V30;
        case 4350:
            return NPMX_CHARGER_VOLTAGE_4V35;
        case 4400:
            return NPMX_CHARGER_VOLTAGE_4V40;
        case 4450:
            return NPMX_CHARGER_VOLTAGE_4V45;
        default:
            return NPMX_CHARGER_VOLTAGE_INVALID;
    }
}

bool npmx_charger_voltage_convert_to_mv(npmx_charger_voltage_t enum_value, uint32_t * p_val)
{
    switch (enum_value)
    {
        case NPMX_CHARGER_VOLTAGE_3V50:
            *p_val = 3500;
            break;
        case NPMX_CHARGER_VOLTAGE_3V55:
            *p_val = 3550;
            break;
        case NPMX_CHARGER_VOLTAGE_3V60:
            *p_val = 3600;
            break;
        case NPMX_CHARGER_VOLTAGE_3V65:
            *p_val = 3650;
            break;
        case NPMX_CHARGER_VOLTAGE_4V00:
            *p_val = 4000;
            break;
        case NPMX_CHARGER_VOLTAGE_4V05:
            *p_val = 4050;
            break;
        case NPMX_CHARGER_VOLTAGE_4V10:
            *p_val = 4100;
            break;
        case NPMX_CHARGER_VOLTAGE_4V15:
            *p_val = 4150;
            break;
        case NPMX_CHARGER_VOLTAGE_4V20:
            *p_val = 4200;
            break;
        case NPMX_CHARGER_VOLTAGE_4V25:
            *p_val = 4250;
            break;
        case NPMX_CHARGER_VOLTAGE_4V30:
            *p_val = 4300;
            break;
        case NPMX_CHARGER_VOLTAGE_4V35:
            *p_val = 4350;
            break;
        case NPMX_CHARGER_VOLTAGE_4V40:
            *p_val = 4400;
            break;
        case NPMX_CHARGER_VOLTAGE_4V45:
            *p_val = 4450;
            break;
        default:
            return false;
    }
    return true;
}

npmx_charger_trickle_t npmx_charger_trickle_convert(uint32_t millivolts)
{
    switch (millivolts)
    {
        case 2500:
            return NPMX_CHARGER_TRICKLE_2V5;
        case 2900:
            return NPMX_CHARGER_TRICKLE_2V9;
        default:
            return NPMX_CHARGER_TRICKLE_INVALID;
    }
}

bool npmx_charger_trickle_convert_to_mv(npmx_charger_trickle_t enum_value, uint32_t * p_val)
{
    switch (enum_value)
    {
        case NPMX_CHARGER_TRICKLE_2V5:
            *p_val = 2500;
            break;
        case NPMX_CHARGER_TRICKLE_2V9:
            *p_val = 2900;
            break;
        default:
            return false;
    }
    return true;
}

npmx_charger_iterm_t npmx_charger_iterm_convert(uint32_t percent)
{
    switch (percent)
    {
        case 10:
            return NPMX_CHARGER_ITERM_10;
        case 20:
            return NPMX_CHARGER_ITERM_20;
        default:
            return NPMX_CHARGER_ITERM_INVALID;
    }
}

bool npmx_charger_iterm_convert_to_pct(npmx_charger_iterm_t enum_value, uint32_t * p_val)
{
    switch (enum_value)
    {
        case NPMX_CHARGER_ITERM_10:
            *p_val = 10;
            break;
        case NPMX_CHARGER_ITERM_20:
            *p_val = 20;
            break;
        default:
            return false;
    }
    return true;
}

npmx_error_t npmx_charger_task_trigger(npmx_charger_t const * p_instance, npmx_charger_task_t task)
{
    NPMX_ASSERT(p_instance);
    NPMX_ASSERT(task < NPMX_CHARGER_TASK_COUNT);

    return task_trigger(p_instance, task);
}

npmx_error_t npmx_charger_module_enable_set(npmx_charger_t const * p_instance, uint32_t module_mask)
{
    NPMX_ASSERT(p_instance);

    npmx_error_t err_code;

    uint8_t data_enable_register = (module_mask >> NPM_BCHARGER_ENABLE_LOGIC_POSITIVE_Pos) &
                                   NPM_BCHARGER_ENABLE_LOGIC_POSITIVE_Msk;

    uint8_t data_disable_register = (module_mask >> NPM_BCHARGER_ENABLE_LOGIC_NEGATIVE_Pos) &
                                    NPM_BCHARGER_ENABLE_LOGIC_NEGATIVE_Msk;

    if (data_enable_register > 0)
    {
        err_code = npmx_backend_register_write(p_instance->p_pmic->p_backend,
                                               NPMX_REG_TO_ADDR(NPM_BCHARGER->BCHGENABLESET),
                                               &data_enable_register,
                                               1);
        if (err_code != NPMX_SUCCESS)
        {
            return err_code;
        }
    }

    if (data_disable_register > 0)
    {
        err_code = npmx_backend_register_write(p_instance->p_pmic->p_backend,
                                               NPMX_REG_TO_ADDR(NPM_BCHARGER->BCHGDISABLECLR),
                                               &data_disable_register,
                                               1);
        if (err_code != NPMX_SUCCESS)
        {
            return err_code;
        }
    }

    return NPMX_SUCCESS;
}

npmx_error_t npmx_charger_module_disable_set(npmx_charger_t const * p_instance,
                                             uint32_t               module_mask)
{
    NPMX_ASSERT(p_instance);

    npmx_error_t err_code;

    uint8_t data_disable_register = (module_mask >> NPM_BCHARGER_ENABLE_LOGIC_POSITIVE_Pos) &
                                    NPM_BCHARGER_ENABLE_LOGIC_POSITIVE_Msk;

    uint8_t data_enable_register = (module_mask >> NPM_BCHARGER_ENABLE_LOGIC_NEGATIVE_Pos) &
                                   NPM_BCHARGER_ENABLE_LOGIC_NEGATIVE_Msk;

    if (data_disable_register > 0)
    {
        err_code = npmx_backend_register_write(p_instance->p_pmic->p_backend,
                                               NPMX_REG_TO_ADDR(NPM_BCHARGER->BCHGENABLECLR),
                                               &data_disable_register,
                                               1);
        if (err_code != NPMX_SUCCESS)
        {
            return err_code;
        }
    }

    if (data_enable_register > 0)
    {
        err_code = npmx_backend_register_write(p_instance->p_pmic->p_backend,
                                               NPMX_REG_TO_ADDR(NPM_BCHARGER->BCHGDISABLESET),
                                               &data_enable_register,
                                               1);
        if (err_code != NPMX_SUCCESS)
        {
            return err_code;
        }
    }

    return NPMX_SUCCESS;
}

npmx_error_t npmx_charger_module_get(npmx_charger_t const * p_instance, uint32_t * p_module_mask)
{
    NPMX_ASSERT(p_instance);
    NPMX_ASSERT(p_module_mask);

    uint8_t ret_data[3];
    /* Only first and third bytes are used, but reading three bytes in a row is faster. */
    npmx_error_t err_code = npmx_backend_register_read(p_instance->p_pmic->p_backend,
                                                       NPMX_REG_TO_ADDR(
                                                           NPM_BCHARGER->BCHGENABLESET),
                                                       ret_data,
                                                       3);

    if (err_code != NPMX_SUCCESS)
    {
        return err_code;
    }

    *p_module_mask = (ret_data[0] << NPM_BCHARGER_ENABLE_LOGIC_POSITIVE_Pos) &
                     NPM_BCHARGER_ENABLE_LOGIC_POSITIVE_Msk;

    *p_module_mask |= ((~ret_data[2]) & NPM_BCHARGER_ENABLE_LOGIC_NEGATIVE_Msk)
                      << NPM_BCHARGER_ENABLE_LOGIC_NEGATIVE_Pos;

    return NPMX_SUCCESS;
}

npmx_error_t npmx_charger_charging_current_set(npmx_charger_t * p_instance, uint16_t current)
{
    NPMX_ASSERT(p_instance);

    if ((current < NPM_BCHARGER_CHARGING_CURRENT_MIN_MA) ||
        (current > NPM_BCHARGER_CHARGING_CURRENT_MAX_MA))
    {
        return NPMX_ERROR_INVALID_PARAM;
    }

    if (current % NPM_BCHARGER_CHARGING_CURRENT_STEP_MA)
    {
        return NPMX_ERROR_INVALID_PARAM;
    }

    uint16_t code = current / NPM_BCHARGER_CHARGING_CURRENT_DIVIDER;

    uint8_t data[2] =
    {
        [0] = (uint8_t)(code >> NPM_BCHARGER_CHARGING_CODE_MSB_SHIFT),
        [1] = (uint8_t)(code & 1U)
    };

    p_instance->charging_current_ma = current;

    return npmx_backend_register_write(p_instance->p_pmic->p_backend,
                                       NPMX_REG_TO_ADDR(NPM_BCHARGER->BCHGISETMSB),
                                       data,
                                       2);
}

npmx_error_t npmx_charger_charging_current_get(npmx_charger_t * p_instance, uint16_t * p_current)
{
    NPMX_ASSERT(p_instance);
    NPMX_ASSERT(p_current);

    uint8_t      data[2];
    uint16_t     code;
    npmx_error_t err_code = npmx_backend_register_read(p_instance->p_pmic->p_backend,
                                                       NPMX_REG_TO_ADDR(NPM_BCHARGER->BCHGISETMSB),
                                                       data,
                                                       2);

    if (err_code != NPMX_SUCCESS)
    {
        return err_code;
    }

    /* Get MSB code data. */
    code = (uint16_t)data[0] << NPM_BCHARGER_CHARGING_CODE_MSB_SHIFT;

    /* Get LSB code data. */
    code += data[1];

    *p_current = (uint16_t)(code * NPM_BCHARGER_CHARGING_CURRENT_DIVIDER);

    p_instance->charging_current_ma = *p_current;

    return NPMX_SUCCESS;
}

npmx_error_t npmx_charger_discharging_current_set(npmx_charger_t * p_instance, uint16_t current)
{
    NPMX_ASSERT(p_instance);

    if ((current < NPM_BCHARGER_DISCHARGING_CURRENT_MIN_MA) ||
        (current > NPM_BCHARGER_DISCHARGING_CURRENT_MAX_MA))
    {
        return NPMX_ERROR_INVALID_PARAM;
    }

    uint32_t code = (uint32_t)current * NPM_BCHARGER_DISCHARGING_MULTIPLIER;
    uint32_t mod  = code % NPM_BCHARGER_DISCHARGING_CONST;

    code /= NPM_BCHARGER_DISCHARGING_CONST;

    if (mod > (NPM_BCHARGER_DISCHARGING_CONST / 2UL))
    {
        code++;
    }

    uint8_t data[2] =
    {
        [0] = (uint8_t)(code >> NPM_BCHARGER_DISCHARGING_CODE_MSB_SHIFT),
        [1] = (uint8_t)(code & 1UL)
    };

    p_instance->discharging_current_ma = current;

    return npmx_backend_register_write(p_instance->p_pmic->p_backend,
                                       NPMX_REG_TO_ADDR(NPM_BCHARGER->BCHGISETDISCHARGEMSB),
                                       data,
                                       2);
}

npmx_error_t npmx_charger_discharging_current_get(npmx_charger_t * p_instance, uint16_t * p_current)
{
    NPMX_ASSERT(p_instance);
    NPMX_ASSERT(p_current);

    uint8_t      data[2];
    uint16_t     code;
    npmx_error_t err_code = npmx_backend_register_read(p_instance->p_pmic->p_backend,
                                                       NPMX_REG_TO_ADDR(NPM_BCHARGER->
                                                                        BCHGISETDISCHARGEMSB),
                                                       data,
                                                       2);

    if (err_code != NPMX_SUCCESS)
    {
        return err_code;
    }

    /* Get MSB current data. */
    code = (uint16_t)data[0] << NPM_BCHARGER_DISCHARGING_CODE_MSB_SHIFT;

    /* Get LSB current data. */
    code += data[1];

    *p_current = (uint16_t)(((uint32_t)code * NPM_BCHARGER_DISCHARGING_CONST) /
                            NPM_BCHARGER_DISCHARGING_MULTIPLIER);

    p_instance->discharging_current_ma = *p_current;

    return NPMX_SUCCESS;
}

npmx_error_t npmx_charger_termination_normal_voltage_set(npmx_charger_t const * p_instance,
                                                         npmx_charger_voltage_t voltage)
{
    NPMX_ASSERT(p_instance);
    NPMX_ASSERT(voltage < NPMX_CHARGER_VOLTAGE_COUNT);

    uint8_t data = ((uint8_t)voltage << BCHARGER_BCHGVTERM_BCHGVTERMNORM_Pos) &
                   BCHARGER_BCHGVTERM_BCHGVTERMNORM_Msk;

    return npmx_backend_register_write(p_instance->p_pmic->p_backend,
                                       NPMX_REG_TO_ADDR(NPM_BCHARGER->BCHGVTERM),
                                       &data,
                                       1);
}

npmx_error_t npmx_charger_termination_normal_voltage_get(npmx_charger_t const *   p_instance,
                                                         npmx_charger_voltage_t * p_voltage)
{
    NPMX_ASSERT(p_instance);
    NPMX_ASSERT(p_voltage);

    uint8_t      data;
    npmx_error_t err_code = npmx_backend_register_read(p_instance->p_pmic->p_backend,
                                                       NPMX_REG_TO_ADDR(NPM_BCHARGER->BCHGVTERM),
                                                       &data,
                                                       1);

    if (err_code != NPMX_SUCCESS)
    {
        return err_code;
    }

    *p_voltage = (npmx_charger_voltage_t)((data & BCHARGER_BCHGVTERM_BCHGVTERMNORM_Msk)
                                          >> BCHARGER_BCHGVTERM_BCHGVTERMNORM_Pos);

    return NPMX_SUCCESS;
}

npmx_error_t npmx_charger_termination_warm_voltage_set(npmx_charger_t const * p_instance,
                                                       npmx_charger_voltage_t voltage)
{
    NPMX_ASSERT(p_instance);
    NPMX_ASSERT(voltage < NPMX_CHARGER_VOLTAGE_COUNT);

    uint8_t data = ((uint8_t)voltage << BCHARGER_BCHGVTERMR_BCHGVTERMREDUCED_Pos) &
                   BCHARGER_BCHGVTERMR_BCHGVTERMREDUCED_Msk;

    return npmx_backend_register_write(p_instance->p_pmic->p_backend,
                                       NPMX_REG_TO_ADDR(NPM_BCHARGER->BCHGVTERMR),
                                       &data,
                                       1);
}

npmx_error_t npmx_charger_termination_warm_voltage_get(npmx_charger_t const *   p_instance,
                                                       npmx_charger_voltage_t * p_voltage)
{
    NPMX_ASSERT(p_instance);
    NPMX_ASSERT(p_voltage);

    uint8_t      data;
    npmx_error_t err_code = npmx_backend_register_read(p_instance->p_pmic->p_backend,
                                                       NPMX_REG_TO_ADDR(NPM_BCHARGER->BCHGVTERMR),
                                                       &data,
                                                       1);

    if (err_code != NPMX_SUCCESS)
    {
        return err_code;
    }

    *p_voltage = (npmx_charger_voltage_t)((data & BCHARGER_BCHGVTERMR_BCHGVTERMREDUCED_Msk)
                                          >> BCHARGER_BCHGVTERMR_BCHGVTERMREDUCED_Pos);

    return NPMX_SUCCESS;
}

npmx_error_t npmx_charger_trickle_voltage_set(npmx_charger_t const * p_instance,
                                              npmx_charger_trickle_t trickle)
{
    NPMX_ASSERT(p_instance);
    NPMX_ASSERT(trickle < NPMX_CHARGER_TRICKLE_COUNT);

    uint8_t data = ((uint8_t)trickle << BCHARGER_BCHGVTRICKLESEL_BCHGVTRICKLESEL_Pos) &
                   BCHARGER_BCHGVTRICKLESEL_BCHGVTRICKLESEL_Msk;

    return npmx_backend_register_write(p_instance->p_pmic->p_backend,
                                       NPMX_REG_TO_ADDR(NPM_BCHARGER->BCHGVTRICKLESEL),
                                       &data,
                                       1);
}

npmx_error_t npmx_charger_trickle_voltage_get(npmx_charger_t const *   p_instance,
                                              npmx_charger_trickle_t * p_trickle)
{
    NPMX_ASSERT(p_instance);
    NPMX_ASSERT(p_trickle);

    uint8_t      data;
    npmx_error_t err_code = npmx_backend_register_read(p_instance->p_pmic->p_backend,
                                                       NPMX_REG_TO_ADDR(NPM_BCHARGER->
                                                                        BCHGVTRICKLESEL),
                                                       &data,
                                                       1);

    if (err_code != NPMX_SUCCESS)
    {
        return err_code;
    }

    *p_trickle = (npmx_charger_trickle_t)((data & BCHARGER_BCHGVTRICKLESEL_BCHGVTRICKLESEL_Msk)
                                          >> BCHARGER_BCHGVTRICKLESEL_BCHGVTRICKLESEL_Pos);

    return NPMX_SUCCESS;
}

npmx_error_t npmx_charger_termination_current_set(npmx_charger_t const * p_instance,
                                                  npmx_charger_iterm_t   iterm)
{
    NPMX_ASSERT(p_instance);
    NPMX_ASSERT(iterm < NPMX_CHARGER_ITERM_COUNT);

    uint8_t data = ((uint8_t)iterm << BCHARGER_BCHGITERMSEL_BCHGITERMSEL_Pos) &
                   BCHARGER_BCHGITERMSEL_BCHGITERMSEL_Msk;

    return npmx_backend_register_write(p_instance->p_pmic->p_backend,
                                       NPMX_REG_TO_ADDR(NPM_BCHARGER->BCHGITERMSEL),
                                       &data,
                                       1);
}

npmx_error_t npmx_charger_termination_current_get(npmx_charger_t const * p_instance,
                                                  npmx_charger_iterm_t * p_iterm)
{
    NPMX_ASSERT(p_instance);
    NPMX_ASSERT(p_iterm);

    uint8_t      data;
    npmx_error_t err_code = npmx_backend_register_read(p_instance->p_pmic->p_backend,
                                                       NPMX_REG_TO_ADDR(NPM_BCHARGER->BCHGITERMSEL),
                                                       &data,
                                                       1);

    if (err_code != NPMX_SUCCESS)
    {
        return err_code;
    }

    *p_iterm = (npmx_charger_iterm_t)((data & BCHARGER_BCHGITERMSEL_BCHGITERMSEL_Msk)
                                      >> BCHARGER_BCHGITERMSEL_BCHGITERMSEL_Pos);

    return NPMX_SUCCESS;
}

npmx_error_t npmx_charger_cold_resistance_set(npmx_charger_t const * p_instance,
                                              uint32_t               resistance)
{
    NPMX_ASSERT(p_instance);
    NPMX_ASSERT(resistance > 0);

    return resistance_set(p_instance, NPMX_REG_TO_ADDR(NPM_BCHARGER->NTCCOLD), resistance);
}

npmx_error_t npmx_charger_cold_resistance_get(npmx_charger_t const * p_instance,
                                              uint32_t *             p_resistance)
{
    NPMX_ASSERT(p_instance);
    NPMX_ASSERT(p_resistance);

    return resistance_get(p_instance, NPMX_REG_TO_ADDR(NPM_BCHARGER->NTCCOLD), p_resistance);
}

npmx_error_t npmx_charger_cool_resistance_set(npmx_charger_t const * p_instance,
                                              uint32_t               resistance)
{
    NPMX_ASSERT(p_instance);
    NPMX_ASSERT(resistance > 0);

    return resistance_set(p_instance, NPMX_REG_TO_ADDR(NPM_BCHARGER->NTCCOOL), resistance);
}

npmx_error_t npmx_charger_cool_resistance_get(npmx_charger_t const * p_instance,
                                              uint32_t *             p_resistance)
{
    NPMX_ASSERT(p_instance);
    NPMX_ASSERT(p_resistance);

    return resistance_get(p_instance, NPMX_REG_TO_ADDR(NPM_BCHARGER->NTCCOOL), p_resistance);
}

npmx_error_t npmx_charger_warm_resistance_set(npmx_charger_t const * p_instance,
                                              uint32_t               resistance)
{
    NPMX_ASSERT(p_instance);
    NPMX_ASSERT(resistance > 0);

    return resistance_set(p_instance, NPMX_REG_TO_ADDR(NPM_BCHARGER->NTCWARM), resistance);
}

npmx_error_t npmx_charger_warm_resistance_get(npmx_charger_t const * p_instance,
                                              uint32_t *             p_resistance)
{
    NPMX_ASSERT(p_instance);
    NPMX_ASSERT(p_resistance);

    return resistance_get(p_instance, NPMX_REG_TO_ADDR(NPM_BCHARGER->NTCWARM), p_resistance);
}

npmx_error_t npmx_charger_hot_resistance_set(npmx_charger_t const * p_instance, uint32_t resistance)
{
    NPMX_ASSERT(p_instance);
    NPMX_ASSERT(resistance > 0);

    return resistance_set(p_instance, NPMX_REG_TO_ADDR(NPM_BCHARGER->NTCHOT), resistance);
}

npmx_error_t npmx_charger_hot_resistance_get(npmx_charger_t const * p_instance,
                                             uint32_t *             p_resistance)
{
    NPMX_ASSERT(p_instance);
    NPMX_ASSERT(p_resistance);

    return resistance_get(p_instance, NPMX_REG_TO_ADDR(NPM_BCHARGER->NTCHOT), p_resistance);
}

npmx_error_t npmx_charger_cold_temperature_set(npmx_charger_t const * p_instance,
                                               int16_t                temperature)
{
    NPMX_ASSERT(p_instance);
    NPMX_ASSERT(temperature >= CHARGER_NTC_TEMPERATURE_MIN);
    NPMX_ASSERT(temperature <= CHARGER_NTC_TEMPERATURE_MAX);

    return temperature_set(p_instance, NPMX_REG_TO_ADDR(NPM_BCHARGER->NTCCOLD), temperature);
}

npmx_error_t npmx_charger_cold_temperature_get(npmx_charger_t const * p_instance,
                                               int16_t *              p_temperature)
{
    NPMX_ASSERT(p_instance);
    NPMX_ASSERT(p_temperature);

    return temperature_get(p_instance, NPMX_REG_TO_ADDR(NPM_BCHARGER->NTCCOLD), p_temperature);
}

npmx_error_t npmx_charger_cool_temperature_set(npmx_charger_t const * p_instance,
                                               int16_t                temperature)
{
    NPMX_ASSERT(p_instance);
    NPMX_ASSERT(temperature >= CHARGER_NTC_TEMPERATURE_MIN);
    NPMX_ASSERT(temperature <= CHARGER_NTC_TEMPERATURE_MAX);

    return temperature_set(p_instance, NPMX_REG_TO_ADDR(NPM_BCHARGER->NTCCOOL), temperature);
}

npmx_error_t npmx_charger_cool_temperature_get(npmx_charger_t const * p_instance,
                                               int16_t *              p_temperature)
{
    NPMX_ASSERT(p_instance);
    NPMX_ASSERT(p_temperature);

    return temperature_get(p_instance, NPMX_REG_TO_ADDR(NPM_BCHARGER->NTCCOOL), p_temperature);
}

npmx_error_t npmx_charger_warm_temperature_set(npmx_charger_t const * p_instance,
                                               int16_t                temperature)
{
    NPMX_ASSERT(p_instance);
    NPMX_ASSERT(temperature >= CHARGER_NTC_TEMPERATURE_MIN);
    NPMX_ASSERT(temperature <= CHARGER_NTC_TEMPERATURE_MAX);

    return temperature_set(p_instance, NPMX_REG_TO_ADDR(NPM_BCHARGER->NTCWARM), temperature);
}

npmx_error_t npmx_charger_warm_temperature_get(npmx_charger_t const * p_instance,
                                               int16_t *              p_temperature)
{
    NPMX_ASSERT(p_instance);
    NPMX_ASSERT(p_temperature);

    return temperature_get(p_instance, NPMX_REG_TO_ADDR(NPM_BCHARGER->NTCWARM), p_temperature);
}

npmx_error_t npmx_charger_hot_temperature_set(npmx_charger_t const * p_instance,
                                              int16_t                temperature)
{
    NPMX_ASSERT(p_instance);
    NPMX_ASSERT(temperature >= CHARGER_NTC_TEMPERATURE_MIN);
    NPMX_ASSERT(temperature <= CHARGER_NTC_TEMPERATURE_MAX);

    return temperature_set(p_instance, NPMX_REG_TO_ADDR(NPM_BCHARGER->NTCHOT), temperature);
}

npmx_error_t npmx_charger_hot_temperature_get(npmx_charger_t const * p_instance,
                                              int16_t *              p_temperature)
{
    NPMX_ASSERT(p_instance);
    NPMX_ASSERT(p_temperature);

    return temperature_get(p_instance, NPMX_REG_TO_ADDR(NPM_BCHARGER->NTCHOT), p_temperature);
}

npmx_error_t npmx_charger_die_temp_stop_set(npmx_charger_t const * p_instance, int16_t temperature)
{
    NPMX_ASSERT(p_instance);
    NPMX_ASSERT(temperature <= NPM_BCHARGER_DIE_TEMPERATURE_MAX_VAL);
    NPMX_ASSERT(temperature >= NPM_BCHARGER_DIE_TEMPERATURE_MIN_VAL);

    uint16_t code = die_temperature_to_code(temperature);

    uint8_t data[2] =
    {
        /* To properly align 10 bit value some bit shifting is needed.
         * Data for MSB stored as data[0].*/
        [0] = (uint8_t)(((code >> NPM_BCHARGER_DIE_TEMPERATURE_MSB_SHIFT) &
                         BCHARGER_DIETEMPSTOP_DIETEMPSTOPCHG_Msk)
                        >> BCHARGER_DIETEMPSTOP_DIETEMPSTOPCHG_Pos),
        /* Data for LSB stored as data[1]. */
        [1] = (uint8_t)(code & BCHARGER_DIETEMPSTOPLSB_DIETEMPSTOPCHGLSB_Msk)
              >> BCHARGER_DIETEMPSTOPLSB_DIETEMPSTOPCHGLSB_Pos
    };

    return npmx_backend_register_write(p_instance->p_pmic->p_backend,
                                       NPMX_REG_TO_ADDR(NPM_BCHARGER->DIETEMPSTOP),
                                       data,
                                       2);
}

npmx_error_t npmx_charger_die_temp_stop_get(npmx_charger_t const * p_instance,
                                            int16_t *              p_temperature)
{
    NPMX_ASSERT(p_instance);
    NPMX_ASSERT(p_temperature);

    uint8_t      data[2];
    npmx_error_t err_code = npmx_backend_register_read(p_instance->p_pmic->p_backend,
                                                       NPMX_REG_TO_ADDR(NPM_BCHARGER->DIETEMPSTOP),
                                                       data,
                                                       2);

    if (err_code != NPMX_SUCCESS)
    {
        return err_code;
    }

    /* Get LSB data. */
    uint16_t code = (uint16_t)data[1];

    /* Get MSB data. */
    code |= ((uint16_t)data[0] << NPM_BCHARGER_DIE_TEMPERATURE_MSB_SHIFT);

    /* Transform code to value. */
    *p_temperature = die_code_to_temperature(code);

    return NPMX_SUCCESS;
}

npmx_error_t npmx_charger_die_temp_resume_set(npmx_charger_t const * p_instance,
                                              int16_t                temperature)
{
    NPMX_ASSERT(p_instance);
    NPMX_ASSERT(temperature <= NPM_BCHARGER_DIE_TEMPERATURE_MAX_VAL);
    NPMX_ASSERT(temperature >= NPM_BCHARGER_DIE_TEMPERATURE_MIN_VAL);

    uint16_t code = die_temperature_to_code(temperature);

    uint8_t data[2] =
    {
        [0] = (uint8_t)(((code >> NPM_BCHARGER_DIE_TEMPERATURE_MSB_SHIFT) &
                         BCHARGER_DIETEMPRESUME_DIETEMPRESUMECHG_Msk)
                        >> BCHARGER_DIETEMPRESUME_DIETEMPRESUMECHG_Pos),
        [1] = (uint8_t)(code & BCHARGER_DIETEMPRESUMELSB_DIETEMPRESUMECHGLSB_Msk)
              >> BCHARGER_DIETEMPRESUMELSB_DIETEMPRESUMECHGLSB_Pos
    };

    return npmx_backend_register_write(p_instance->p_pmic->p_backend,
                                       NPMX_REG_TO_ADDR(NPM_BCHARGER->DIETEMPRESUME),
                                       data,
                                       2);
}

npmx_error_t npmx_charger_die_temp_resume_get(npmx_charger_t const * p_instance,
                                              int16_t *              p_temperature)
{
    NPMX_ASSERT(p_instance);
    NPMX_ASSERT(p_temperature);

    uint8_t      data[2];
    npmx_error_t err_code = npmx_backend_register_read(p_instance->p_pmic->p_backend,
                                                       NPMX_REG_TO_ADDR(
                                                           NPM_BCHARGER->DIETEMPRESUME),
                                                       data,
                                                       2);

    if (err_code != NPMX_SUCCESS)
    {
        return err_code;
    }

    /* Get LSB data. */
    uint16_t code = (uint16_t)data[1];

    /* Get MSB data. */
    code |= ((uint16_t)data[0] << NPM_BCHARGER_DIE_TEMPERATURE_MSB_SHIFT);

    /* Transform code to value. */
    *p_temperature = die_code_to_temperature(code);

    return NPMX_SUCCESS;
}

npmx_error_t npmx_charger_current_limiter_get(npmx_charger_t const * p_instance,
                                              bool *                 p_current_lim_status)
{
    NPMX_ASSERT(p_instance);
    NPMX_ASSERT(p_current_lim_status);

    uint8_t      data;
    npmx_error_t err_code = npmx_backend_register_read(p_instance->p_pmic->p_backend,
                                                       NPMX_REG_TO_ADDR(
                                                           NPM_BCHARGER->BCHGILIMSTATUS),
                                                       &data,
                                                       1);

    if (err_code != NPMX_SUCCESS)
    {
        return err_code;
    }

    *p_current_lim_status = (data & BCHARGER_BCHGILIMSTATUS_BCHGILIMBATACTIVE_Msk) > 0;

    return NPMX_SUCCESS;
}

npmx_error_t npmx_charger_ntc_status_get(npmx_charger_t const * p_instance, uint8_t * p_ntc_status)
{
    NPMX_ASSERT(p_instance);
    NPMX_ASSERT(p_ntc_status);

    return npmx_backend_register_read(p_instance->p_pmic->p_backend,
                                      NPMX_REG_TO_ADDR(NPM_BCHARGER->NTCSTATUS),
                                      p_ntc_status,
                                      1);
}

npmx_error_t npmx_charger_die_temp_status_get(npmx_charger_t const * p_instance,
                                              bool *                 p_die_temp_status)
{
    NPMX_ASSERT(p_instance);
    NPMX_ASSERT(p_die_temp_status);

    uint8_t      data;
    npmx_error_t err_code = npmx_backend_register_read(p_instance->p_pmic->p_backend,
                                                       NPMX_REG_TO_ADDR(
                                                           NPM_BCHARGER->DIETEMPSTATUS),
                                                       &data,
                                                       1);

    if (err_code != NPMX_SUCCESS)
    {
        return err_code;
    }

    *p_die_temp_status = (data & BCHARGER_DIETEMPSTATUS_DIETEMPHIGH_Msk) > 0;

    return NPMX_SUCCESS;
}

npmx_error_t npmx_charger_status_get(npmx_charger_t const * p_instance, uint8_t * p_status_mask)
{
    NPMX_ASSERT(p_instance);
    NPMX_ASSERT(p_status_mask);

    return npmx_backend_register_read(p_instance->p_pmic->p_backend,
                                      NPMX_REG_TO_ADDR(NPM_BCHARGER->BCHGCHARGESTATUS),
                                      p_status_mask,
                                      1);
}

npmx_error_t npmx_charger_errors_check(npmx_charger_t const * p_instance)
{
    NPMX_ASSERT(p_instance);

    npmx_instance_t * p_pmic = p_instance->p_pmic;
    uint8_t           errors[NPM_BCHARGER_ERR_COUNT];

    npmx_error_t err_code = npmx_backend_register_read(p_instance->p_pmic->p_backend,
                                                       NPMX_REG_TO_ADDR(
                                                           NPM_BCHARGER->BCHGERRREASON),
                                                       errors,
                                                       NPM_BCHARGER_ERR_COUNT);

    if (err_code != NPMX_SUCCESS)
    {
        return err_code;
    }

    for (uint8_t i = 0; i < NPM_BCHARGER_ERR_COUNT; i++)
    {
        if (errors[i] != 0)
        {
            err_code = task_trigger(p_instance, NPMX_CHARGER_TASK_CLEAR_ERROR);
            if (err_code != NPMX_SUCCESS)
            {
                return err_code;
            }

            err_code = task_trigger(p_instance, NPMX_CHARGER_TASK_RELEASE);
            if (err_code != NPMX_SUCCESS)
            {
                return err_code;
            }

            break;
        }
    }

    const static npmx_callback_type_t m_id_to_callback[NPM_BCHARGER_ERR_COUNT] =
    {
        NPMX_CALLBACK_TYPE_CHARGER_ERROR,
        NPMX_CALLBACK_TYPE_SENSOR_ERROR
    };

    for (uint8_t i = 0; i < NPM_BCHARGER_ERR_COUNT; i++)
    {
        if ((errors[i] != 0) && (p_pmic->registered_cb[m_id_to_callback[i]] != NULL))
        {
            p_pmic->registered_cb[m_id_to_callback[i]] (p_pmic, m_id_to_callback[i], errors[i]);
        }
    }

    return NPMX_SUCCESS;
}

npmx_error_t npmx_charger_warm_disable_set(npmx_charger_t const * p_instance, bool disable)
{
    NPMX_ASSERT(p_instance);

    uint8_t data = ((disable ? BCHARGER_BCHGCONFIG_DISABLECHARGEWARM_DISABLED :
                               BCHARGER_BCHGCONFIG_DISABLECHARGEWARM_ENABLED)
                    << BCHARGER_BCHGCONFIG_DISABLECHARGEWARM_Pos) &
                   BCHARGER_BCHGCONFIG_DISABLECHARGEWARM_Msk;

    return npmx_backend_register_write(p_instance->p_pmic->p_backend,
                                       NPMX_REG_TO_ADDR(NPM_BCHARGER->BCHGCONFIG),
                                       &data,
                                       1);
}

npmx_error_t npmx_charger_warm_disable_get(npmx_charger_t const * p_instance, bool * p_disable)
{
    NPMX_ASSERT(p_instance);
    NPMX_ASSERT(p_disable);

    uint8_t      data;
    npmx_error_t err_code = npmx_backend_register_read(p_instance->p_pmic->p_backend,
                                                       NPMX_REG_TO_ADDR(NPM_BCHARGER->BCHGCONFIG),
                                                       &data,
                                                       1);

    if (err_code != NPMX_SUCCESS)
    {
        return err_code;
    }

    *p_disable = (data & BCHARGER_BCHGCONFIG_DISABLECHARGEWARM_Msk) > 0;

    return NPMX_SUCCESS;
}
