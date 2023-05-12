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

    static const uint16_t task_addr[] =
    {
        [NPMX_CHARGER_TASK_RELEASE]      = NPMX_REG_TO_ADDR(NPM_BCHARGER->TASKRELEASEERR),
        [NPMX_CHARGER_TASK_CLEAR_ERROR]  = NPMX_REG_TO_ADDR(NPM_BCHARGER->TASKCLEARCHGERR),
        [NPMX_CHARGER_TASK_CLEAR_TIMERS] = NPMX_REG_TO_ADDR(NPM_BCHARGER->TASKCLEARSAFETYTIMER),
    };

    return npmx_backend_register_write(&p_instance->p_pmic->backend_inst,
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
    uint64_t code = NPMX_PERIPH_CHARGER_ADC_BITS_RESOLUTION;

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
static uint16_t die_temperature_to_code(uint16_t temperature)
{
    uint16_t code = NPMX_PERIPH_CHARGER_DIE_TEMPERATURE_CONST_1 -
                    (temperature * NPMX_PERIPH_CHARGER_DIE_TEMPERATURE_MULTIPLIER);
    uint16_t mod = code % NPMX_PERIPH_CHARGER_DIE_TEMPERATURE_CONST_2;

    code /= NPMX_PERIPH_CHARGER_DIE_TEMPERATURE_CONST_2;
    if (mod > (NPMX_PERIPH_CHARGER_DIE_TEMPERATURE_CONST_2 / 2))
    {
        code++;
    }

    return code;
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
static uint16_t die_code_to_temperature(uint16_t code)
{
    uint16_t temperature = NPMX_PERIPH_CHARGER_DIE_TEMPERATURE_CONST_1 -
                           (code * NPMX_PERIPH_CHARGER_DIE_TEMPERATURE_CONST_2);

    temperature /= NPMX_PERIPH_CHARGER_DIE_TEMPERATURE_MULTIPLIER;

    return temperature;
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
        [0] = (uint8_t)(code >> NPMX_PERIPH_CHARGER_RESISTANCE_MSB_SHIFT),
        [1] = (uint8_t)(code & BCHARGER_NTCCOLDLSB_NTCCOLDLVLLSB_Msk),
    };

    return npmx_backend_register_write(&p_instance->p_pmic->backend_inst, reg, data, 2);
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
    npmx_error_t err_code = npmx_backend_register_read(&p_instance->p_pmic->backend_inst,
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

    uint32_t code = ((uint16_t)data[0] << NPMX_PERIPH_CHARGER_RESISTANCE_MSB_SHIFT) |
                    (uint16_t)(data[1] & BCHARGER_NTCCOLDLSB_NTCCOLDLVLLSB_Msk);

    *p_resistance = (code * ntc_resistance) / (NPMX_PERIPH_CHARGER_ADC_BITS_RESOLUTION - code);

    return NPMX_SUCCESS;
}

npmx_charger_t * npmx_charger_get(npmx_instance_t * p_pmic, uint8_t idx)
{
    NPMX_ASSERT(p_pmic);
    NPMX_ASSERT(idx < NPMX_PERIPH_CHARGER_COUNT);

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

uint32_t npmx_charger_voltage_convert_to_mv(npmx_charger_voltage_t enum_value)
{
    NPMX_ASSERT(enum_value != NPMX_CHARGER_VOLTAGE_INVALID);

    static const uint32_t convert_table[] =
    {
        [NPMX_CHARGER_VOLTAGE_3V50] = 3500,
        [NPMX_CHARGER_VOLTAGE_3V55] = 3550,
        [NPMX_CHARGER_VOLTAGE_3V60] = 3600,
        [NPMX_CHARGER_VOLTAGE_3V65] = 3650,
        [NPMX_CHARGER_VOLTAGE_4V00] = 4000,
        [NPMX_CHARGER_VOLTAGE_4V05] = 4050,
        [NPMX_CHARGER_VOLTAGE_4V10] = 4100,
        [NPMX_CHARGER_VOLTAGE_4V15] = 4150,
        [NPMX_CHARGER_VOLTAGE_4V20] = 4200,
        [NPMX_CHARGER_VOLTAGE_4V25] = 4250,
        [NPMX_CHARGER_VOLTAGE_4V30] = 4300,
        [NPMX_CHARGER_VOLTAGE_4V35] = 4350,
        [NPMX_CHARGER_VOLTAGE_4V40] = 4400,
        [NPMX_CHARGER_VOLTAGE_4V45] = 4450,
    };

    return convert_table[enum_value];
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

uint32_t npmx_charger_trickle_convert_to_mv(npmx_charger_trickle_t enum_value)
{
    NPMX_ASSERT(enum_value != NPMX_CHARGER_TRICKLE_INVALID);

    static const uint32_t convert_table[] =
    {
        [NPMX_CHARGER_TRICKLE_2V5] = 2500,
        [NPMX_CHARGER_TRICKLE_2V9] = 2900,
    };

    return convert_table[enum_value];
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

uint32_t npmx_charger_iterm_convert_to_pct(npmx_charger_iterm_t enum_value)
{
    NPMX_ASSERT(enum_value != NPMX_CHARGER_ITERM_INVALID);

    static const uint32_t convert_table[] =
    {
        [NPMX_CHARGER_ITERM_10] = 10,
        [NPMX_CHARGER_ITERM_20] = 20,
    };

    return convert_table[enum_value];
}

npmx_error_t npmx_charger_task_trigger(npmx_charger_t const * p_instance, npmx_charger_task_t task)
{
    NPMX_ASSERT(p_instance);

    return task_trigger(p_instance, task);
}

npmx_error_t npmx_charger_module_enable_set(npmx_charger_t const * p_instance, uint32_t module_mask)
{
    NPMX_ASSERT(p_instance);

    npmx_error_t err_code;

    uint8_t data_enable_register = (module_mask >> NPMX_PERIPH_CHARGER_ENABLE_LOGIC_POSITIVE_Pos) &
                                   NPMX_PERIPH_CHARGER_ENABLE_LOGIC_POSITIVE_Msk;

    uint8_t data_disable_register = (module_mask >> NPMX_PERIPH_CHARGER_ENABLE_LOGIC_NEGATIVE_Pos) &
                                    NPMX_PERIPH_CHARGER_ENABLE_LOGIC_NEGATIVE_Msk;

    if (data_enable_register > 0)
    {
        err_code = npmx_backend_register_write(&p_instance->p_pmic->backend_inst,
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
        err_code = npmx_backend_register_write(&p_instance->p_pmic->backend_inst,
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

    uint8_t data_disable_register = (module_mask >> NPMX_PERIPH_CHARGER_ENABLE_LOGIC_POSITIVE_Pos) &
                                    NPMX_PERIPH_CHARGER_ENABLE_LOGIC_POSITIVE_Msk;

    uint8_t data_enable_register = (module_mask >> NPMX_PERIPH_CHARGER_ENABLE_LOGIC_NEGATIVE_Pos) &
                                   NPMX_PERIPH_CHARGER_ENABLE_LOGIC_NEGATIVE_Msk;

    if (data_disable_register > 0)
    {
        err_code = npmx_backend_register_write(&p_instance->p_pmic->backend_inst,
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
        err_code = npmx_backend_register_write(&p_instance->p_pmic->backend_inst,
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
    npmx_error_t err_code = npmx_backend_register_read(&p_instance->p_pmic->backend_inst,
                                                       NPMX_REG_TO_ADDR(
                                                           NPM_BCHARGER->BCHGENABLESET),
                                                       ret_data,
                                                       3);
    if (err_code != NPMX_SUCCESS)
    {
        return err_code;
    }

    *p_module_mask = (ret_data[0] << NPMX_PERIPH_CHARGER_ENABLE_LOGIC_POSITIVE_Pos) &
                     NPMX_PERIPH_CHARGER_ENABLE_LOGIC_POSITIVE_Msk;

    *p_module_mask |= ((~ret_data[2]) & NPMX_PERIPH_CHARGER_ENABLE_LOGIC_NEGATIVE_Msk)
                      << NPMX_PERIPH_CHARGER_ENABLE_LOGIC_NEGATIVE_Pos;

    return NPMX_SUCCESS;
}

npmx_error_t npmx_charger_charging_current_set(npmx_charger_t const * p_instance, uint16_t current)
{
    NPMX_ASSERT(p_instance);

    if ((current < NPMX_PERIPH_CHARGER_CHARGING_CURRENT_MIN_MA) ||
        (current > NPMX_PERIPH_CHARGER_CHARGING_CURRENT_MAX_MA))
    {
        return NPMX_ERROR_INVALID_PARAM;
    }

    if (current % NPMX_PERIPH_CHARGER_CHARGING_CURRENT_STEP_MA)
    {
        return NPMX_ERROR_INVALID_PARAM;
    }

    uint16_t code = current / NPMX_PERIPH_CHARGER_CHARGING_CURRENT_DIVIDER;

    uint8_t data[2] =
    {
        [0] = (uint8_t)(code >> NPMX_PERIPH_CHARGER_CHARGING_CODE_MSB_SHIFT),
        [1] = (uint8_t)(code & 1U)
    };

    return npmx_backend_register_write(&p_instance->p_pmic->backend_inst,
                                       NPMX_REG_TO_ADDR(NPM_BCHARGER->BCHGISETMSB),
                                       data,
                                       2);
}

npmx_error_t npmx_charger_charging_current_get(npmx_charger_t const * p_instance,
                                               uint16_t *             p_current)
{
    NPMX_ASSERT(p_instance);
    NPMX_ASSERT(p_current);

    uint8_t      data[2];
    uint16_t     code;
    npmx_error_t err_code = npmx_backend_register_read(&p_instance->p_pmic->backend_inst,
                                                       NPMX_REG_TO_ADDR(NPM_BCHARGER->BCHGISETMSB),
                                                       data,
                                                       2);
    if (err_code != NPMX_SUCCESS)
    {
        return err_code;
    }

    /* Get MSB code data. */
    code = (uint16_t)data[0] << NPMX_PERIPH_CHARGER_CHARGING_CODE_MSB_SHIFT;

    /* Get LSB code data. */
    code += data[1];

    *p_current = (uint16_t)(code * NPMX_PERIPH_CHARGER_CHARGING_CURRENT_DIVIDER);

    return NPMX_SUCCESS;
}

npmx_error_t npmx_charger_discharging_current_set(npmx_charger_t const * p_instance,
                                                  uint16_t               current)
{
    NPMX_ASSERT(p_instance);

    if ((current < NPMX_PERIPH_CHARGER_DISCHARGING_CURRENT_MIN_MA) ||
        (current > NPMX_PERIPH_CHARGER_DISCHARGING_CURRENT_MAX_MA))
    {
        return NPMX_ERROR_INVALID_PARAM;
    }

    uint32_t code = (uint32_t)current * NPMX_PERIPH_CHARGER_DISCHARGING_MULTIPLIER;
    uint32_t mod  = code % NPMX_PERIPH_CHARGER_DISCHARGING_CONST;

    code /= NPMX_PERIPH_CHARGER_DISCHARGING_CONST;

    if (mod > (NPMX_PERIPH_CHARGER_DISCHARGING_CONST / 2UL))
    {
        code++;
    }

    uint8_t data[2] =
    {
        [0] = (uint8_t)(code >> NPMX_PERIPH_CHARGER_DISCHARGING_CODE_MSB_SHIFT),
        [1] = (uint8_t)(code & 1UL)
    };

    return npmx_backend_register_write(&p_instance->p_pmic->backend_inst,
                                       NPMX_REG_TO_ADDR(NPM_BCHARGER->BCHGISETDISCHARGEMSB),
                                       data,
                                       2);
}

npmx_error_t npmx_charger_discharging_current_get(npmx_charger_t const * p_instance,
                                                  uint16_t *             p_current)
{
    NPMX_ASSERT(p_instance);
    NPMX_ASSERT(p_current);

    uint8_t      data[2];
    uint16_t     code;
    npmx_error_t err_code = npmx_backend_register_read(&p_instance->p_pmic->backend_inst,
                                                       NPMX_REG_TO_ADDR(NPM_BCHARGER->
                                                                        BCHGISETDISCHARGEMSB),
                                                       data,
                                                       2);
    if (err_code != NPMX_SUCCESS)
    {
        return err_code;
    }

    /* Get MSB current data. */
    code = (uint16_t)data[0] << NPMX_PERIPH_CHARGER_DISCHARGING_CODE_MSB_SHIFT;

    /* Get LSB current data. */
    code += data[1];

    *p_current = (uint16_t)(((uint32_t)code * NPMX_PERIPH_CHARGER_DISCHARGING_CONST) /
                            NPMX_PERIPH_CHARGER_DISCHARGING_MULTIPLIER);

    return NPMX_SUCCESS;
}

npmx_error_t npmx_charger_termination_normal_voltage_set(npmx_charger_t const * p_instance,
                                                         npmx_charger_voltage_t voltage)
{
    NPMX_ASSERT(p_instance);
    NPMX_ASSERT(voltage <= NPMX_CHARGER_VOLTAGE_4V45);

    uint8_t data = ((uint8_t)voltage << BCHARGER_BCHGVTERM_BCHGVTERMNORM_Pos) &
                   BCHARGER_BCHGVTERM_BCHGVTERMNORM_Msk;

    return npmx_backend_register_write(&p_instance->p_pmic->backend_inst,
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
    npmx_error_t err_code = npmx_backend_register_read(&p_instance->p_pmic->backend_inst,
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
    NPMX_ASSERT(voltage <= NPMX_CHARGER_VOLTAGE_4V45);

    uint8_t data = ((uint8_t)voltage << BCHARGER_BCHGVTERMR_BCHGVTERMREDUCED_Pos) &
                   BCHARGER_BCHGVTERMR_BCHGVTERMREDUCED_Msk;

    return npmx_backend_register_write(&p_instance->p_pmic->backend_inst,
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
    npmx_error_t err_code = npmx_backend_register_read(&p_instance->p_pmic->backend_inst,
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
    NPMX_ASSERT(trickle != NPMX_CHARGER_TRICKLE_INVALID);

    uint8_t data = ((uint8_t)trickle << BCHARGER_BCHGVTRICKLESEL_BCHGVTRICKLESEL_Pos) &
                   BCHARGER_BCHGVTRICKLESEL_BCHGVTRICKLESEL_Msk;

    return npmx_backend_register_write(&p_instance->p_pmic->backend_inst,
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
    npmx_error_t err_code = npmx_backend_register_read(&p_instance->p_pmic->backend_inst,
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

    uint8_t data = ((uint8_t)iterm << BCHARGER_BCHGITERMSEL_BCHGITERMSEL_Pos) &
                   BCHARGER_BCHGITERMSEL_BCHGITERMSEL_Msk;

    return npmx_backend_register_write(&p_instance->p_pmic->backend_inst,
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
    npmx_error_t err_code = npmx_backend_register_read(&p_instance->p_pmic->backend_inst,
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

npmx_error_t npmx_charger_die_temp_stop_set(npmx_charger_t const * p_instance, uint16_t temperature)
{
    NPMX_ASSERT(p_instance);
    NPMX_ASSERT(temperature <= NPMX_PERIPH_CHARGER_DIE_TEMPERATURE_MAX_VAL);

#if defined(BCHARGER_DIETEMPSTOPLSB_DIETEMPSTOPCHGLSB_Msk)
    uint16_t code = die_temperature_to_code(temperature);

    uint8_t data[2] =
    {
        /* To properly align 10 bit value some bit shifting is needed.
         * Data for MSB stored as data[0].*/
        [0] = (uint8_t)(((code >> NPMX_PERIPH_CHARGER_DIE_TEMPERATURE_MSB_SHIFT) &
                         BCHARGER_DIETEMPSTOP_DIETEMPSTOPCHG_Msk)
                        >> BCHARGER_DIETEMPSTOP_DIETEMPSTOPCHG_Pos),
        /* Data for LSB stored as data[1]. */
        [1] = (uint8_t)(code & BCHARGER_DIETEMPSTOPLSB_DIETEMPSTOPCHGLSB_Msk)
              >> BCHARGER_DIETEMPSTOPLSB_DIETEMPSTOPCHGLSB_Pos
    };

    return npmx_backend_register_write(&p_instance->p_pmic->backend_inst,
                                       NPMX_REG_TO_ADDR(NPM_BCHARGER->DIETEMPSTOP),
                                       data,
                                       2);
#else
    uint8_t code = (uint8_t)die_temperature_to_code(temperature);

    return npmx_backend_register_write(&p_instance->p_pmic->backend_inst,
                                       NPMX_REG_TO_ADDR(NPM_BCHARGER->DIETEMPSTOP),
                                       &code,
                                       1);
#endif
}

npmx_error_t npmx_charger_die_temp_stop_get(npmx_charger_t const * p_instance,
                                            uint16_t *             p_temperature)
{
    NPMX_ASSERT(p_instance);
    NPMX_ASSERT(p_temperature);

#if defined(BCHARGER_DIETEMPSTOPLSB_DIETEMPSTOPCHGLSB_Msk)
    uint8_t      data[2];
    npmx_error_t err_code = npmx_backend_register_read(&p_instance->p_pmic->backend_inst,
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
    code |= ((uint16_t)data[0] << NPMX_PERIPH_CHARGER_DIE_TEMPERATURE_MSB_SHIFT);

    /* Transform code to value. */
    *p_temperature = die_code_to_temperature(code);
#else
    uint8_t      data;
    npmx_error_t err_code = npmx_backend_register_read(&p_instance->p_pmic->backend_inst,
                                                       NPMX_REG_TO_ADDR(NPM_BCHARGER->DIETEMPSTOP),
                                                       &data,
                                                       1);
    if (err_code != NPMX_SUCCESS)
    {
        return err_code;
    }

    *p_temperature = die_code_to_temperature(data);
#endif

    return NPMX_SUCCESS;
}

npmx_error_t npmx_charger_die_temp_resume_set(npmx_charger_t const * p_instance,
                                              uint16_t               temperature)
{
    NPMX_ASSERT(p_instance);
    NPMX_ASSERT(temperature <= NPMX_PERIPH_CHARGER_DIE_TEMPERATURE_MAX_VAL);

#if defined(BCHARGER_DIETEMPRESUMELSB_DIETEMPRESUMECHGLSB_Msk)
    uint16_t code = die_temperature_to_code(temperature);

    uint8_t data[2] =
    {
        [0] = (uint8_t)(((code >> NPMX_PERIPH_CHARGER_DIE_TEMPERATURE_MSB_SHIFT) &
                         BCHARGER_DIETEMPRESUME_DIETEMPRESUMECHG_Msk)
                        >> BCHARGER_DIETEMPRESUME_DIETEMPRESUMECHG_Pos),
        [1] = (uint8_t)(code & BCHARGER_DIETEMPRESUMELSB_DIETEMPRESUMECHGLSB_Msk)
              >> BCHARGER_DIETEMPRESUMELSB_DIETEMPRESUMECHGLSB_Pos
    };

    return npmx_backend_register_write(&p_instance->p_pmic->backend_inst,
                                       NPMX_REG_TO_ADDR(NPM_BCHARGER->DIETEMPRESUME),
                                       data,
                                       2);
#else
    uint8_t code = (uint8_t)die_temperature_to_code(temperature);

    return npmx_backend_register_write(&p_instance->p_pmic->backend_inst,
                                       NPMX_REG_TO_ADDR(NPM_BCHARGER->DIETEMPRESUME),
                                       &code,
                                       1);
#endif
}

npmx_error_t npmx_charger_die_temp_resume_get(npmx_charger_t const * p_instance,
                                              uint16_t *             p_temperature)
{
    NPMX_ASSERT(p_instance);
    NPMX_ASSERT(p_temperature);

#if defined(BCHARGER_DIETEMPRESUMELSB_DIETEMPRESUMECHGLSB_Msk)
    uint8_t      data[2];
    npmx_error_t err_code = npmx_backend_register_read(&p_instance->p_pmic->backend_inst,
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
    code |= ((uint16_t)data[0] << NPMX_PERIPH_CHARGER_DIE_TEMPERATURE_MSB_SHIFT);

    /* Transform code to value. */
    *p_temperature = die_code_to_temperature(code);
#else
    uint8_t      data;
    npmx_error_t err_code = npmx_backend_register_read(&p_instance->p_pmic->backend_inst,
                                                       NPMX_REG_TO_ADDR(
                                                           NPM_BCHARGER->DIETEMPRESUME),
                                                       &data,
                                                       1);
    if (err_code != NPMX_SUCCESS)
    {
        return err_code;
    }

    *p_temperature = die_code_to_temperature(data);
#endif

    return NPMX_SUCCESS;
}

npmx_error_t npmx_charger_current_limiter_get(npmx_charger_t const * p_instance,
                                              bool *                 p_current_lim_status)
{
    NPMX_ASSERT(p_instance);
    NPMX_ASSERT(p_current_lim_status);

    uint8_t      data;
    npmx_error_t err_code = npmx_backend_register_read(&p_instance->p_pmic->backend_inst,
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

    return npmx_backend_register_read(&p_instance->p_pmic->backend_inst,
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
    npmx_error_t err_code = npmx_backend_register_read(&p_instance->p_pmic->backend_inst,
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

    return npmx_backend_register_read(&p_instance->p_pmic->backend_inst,
                                      NPMX_REG_TO_ADDR(NPM_BCHARGER->BCHGCHARGESTATUS),
                                      p_status_mask,
                                      1);
}

npmx_error_t npmx_charger_errors_check(npmx_charger_t const * p_instance)
{
    NPMX_ASSERT(p_instance);

    npmx_instance_t * p_pmic = p_instance->p_pmic;
    uint8_t           errors[NPMX_PERIPH_CHARGER_ERR_COUNT];

    npmx_error_t err_code = npmx_backend_register_read(&p_pmic->backend_inst,
                                                       NPMX_REG_TO_ADDR(
                                                           NPM_BCHARGER->BCHGERRREASON),
                                                       errors,
                                                       NPMX_PERIPH_CHARGER_ERR_COUNT);
    if (err_code != NPMX_SUCCESS)
    {
        return err_code;
    }

    for (uint8_t i = 0; i < NPMX_PERIPH_CHARGER_ERR_COUNT; i++)
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

    const static npmx_callback_type_t m_id_to_callback[NPMX_PERIPH_CHARGER_ERR_COUNT] =
    {
        NPMX_CALLBACK_TYPE_CHARGER_ERROR,
        NPMX_CALLBACK_TYPE_SENSOR_ERROR
    };

    for (uint8_t i = 0; i < NPMX_PERIPH_CHARGER_ERR_COUNT; i++)
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

    return npmx_backend_register_write(&p_instance->p_pmic->backend_inst,
                                       NPMX_REG_TO_ADDR(NPM_BCHARGER->BCHGCONFIG),
                                       &data,
                                       1);
}

npmx_error_t npmx_charger_warm_disable_get(npmx_charger_t const * p_instance, bool * p_disable)
{
    NPMX_ASSERT(p_instance);
    NPMX_ASSERT(p_disable);

    uint8_t      data;
    npmx_error_t err_code = npmx_backend_register_read(&p_instance->p_pmic->backend_inst,
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
