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

#include <npmx_adc.h>
#include <npmx_instance.h>

/**
 * @brief Definition of pointer to funtion type, that evaluates value for ADC measurement from received code.
 *
 * @param[in]  p_instance Pointer to the ADC instance.
 * @param[in]  code       Code read from ADC.
 * @param[out] p_val      Pointer to evaluated value.
 *
 * @retval NPMX_SUCCESS  Operation performed successfully.
 * @retval NPMX_ERROR_IO Error using IO bus line.
 */
typedef npmx_error_t (*code_to_val_fun_t)(npmx_adc_t const * p_instance,
                                          uint16_t           code,
                                          uint16_t *         p_val);

static npmx_error_t task_trigger(npmx_adc_t const * p_instance, npmx_adc_task_t task)
{
    uint8_t data = NPMX_TASK_TRIGGER;

    static const uint16_t task_addr[] =
    {
        [NPMX_ADC_TASK_SINGLE_SHOT_VBAT]     = NPMX_REG_TO_ADDR(NPM_ADC->TASKVBATMEASURE),
        [NPMX_ADC_TASK_SINGLE_SHOT_NTC]      = NPMX_REG_TO_ADDR(NPM_ADC->TASKNTCMEASURE),
        [NPMX_ADC_TASK_SINGLE_SHOT_DIE_TEMP] = NPMX_REG_TO_ADDR(NPM_ADC->TASKTEMPMEASURE),
        [NPMX_ADC_TASK_SINGLE_SHOT_VSYS]     = NPMX_REG_TO_ADDR(NPM_ADC->TASKVSYSMEASURE),
        [NPMX_ADC_TASK_SINGLE_SHOT_VBUS]     = NPMX_REG_TO_ADDR(NPM_ADC->TASKVBUS7MEASURE),
        [NPMX_ADC_TASK_DELAYED_MEAS_VBAT]    = NPMX_REG_TO_ADDR(NPM_ADC->TASKDELAYEDVBATMEASURE),
        [NPMX_ADC_TASK_UPDATE_AUTO_INTERVAL] = NPMX_REG_TO_ADDR(NPM_ADC->TASKAUTOTIMUPDATE),
    };

    return npmx_backend_register_write(p_instance->p_backend, task_addr[task], &data, 1);
}

/**
 * @brief Function for converting the value from NTC enumeration type to resistance.
 *
 * @param[in] battery_ntc Battery NTC type.
 *
 * @return Resistance value in ohms.
 */
static uint32_t ntc_type_convert_to_ohms(npmx_adc_ntc_type_t battery_ntc)
{
    static const uint32_t resistances[] =
    {
        [NPMX_ADC_NTC_TYPE_HI_Z]  = 0,
        [NPMX_ADC_NTC_TYPE_10_K]  = 10000,
        [NPMX_ADC_NTC_TYPE_47_K]  = 47000,
        [NPMX_ADC_NTC_TYPE_100_K] = 100000,
    };

    return resistances[battery_ntc];
}

/**
 * @brief Function for getting MSB registers' addresses.
 *
 * @param[in] meas Measurement for which MSB register's address should be returned.
 *
 * @return Address of MSB register for given measurement.
 */
static uint16_t msb_register_address_get(npmx_adc_meas_t meas)
{
    static const uint16_t msb_addresses[] =
    {
        [NPMX_ADC_MEAS_VBAT]     = NPMX_REG_TO_ADDR(NPM_ADC->ADCVBATRESULTMSB),
        [NPMX_ADC_MEAS_NTC]      = NPMX_REG_TO_ADDR(NPM_ADC->ADCNTCRESULTMSB),
        [NPMX_ADC_MEAS_DIE_TEMP] = NPMX_REG_TO_ADDR(NPM_ADC->ADCTEMPRESULTMSB),
        [NPMX_ADC_MEAS_VSYS]     = NPMX_REG_TO_ADDR(NPM_ADC->ADCVSYSRESULTMSB),
        [NPMX_ADC_MEAS_VBUS]     = NPMX_REG_TO_ADDR(NPM_ADC->ADCVBAT3RESULTMSB),
        [NPMX_ADC_MEAS_VBAT0]    = NPMX_REG_TO_ADDR(NPM_ADC->ADCVBAT0RESULTMSB),
        [NPMX_ADC_MEAS_VBAT1]    = NPMX_REG_TO_ADDR(NPM_ADC->ADCVBAT1RESULTMSB),
        [NPMX_ADC_MEAS_VBAT2]    = NPMX_REG_TO_ADDR(NPM_ADC->ADCVBAT2RESULTMSB),
        [NPMX_ADC_MEAS_VBAT3]    = NPMX_REG_TO_ADDR(NPM_ADC->ADCVBAT3RESULTMSB),
    };

    return msb_addresses[meas];
}

/**
 * @brief Function for getting difference in MSB and LSB registers' addresses.
 *
 * @param[in] meas Measurement for which offset should be returned.
 *
 * @return Delta of MSB and LSB registers addresses for a given measurement.
 */
static uint16_t lsb_register_offset_get(npmx_adc_meas_t meas)
{
    static const uint16_t lsb_registers[] =
    {
        [NPMX_ADC_MEAS_VBAT]     = NPMX_REG_TO_ADDR(NPM_ADC->ADCGP0RESULTLSBS) -
                                   NPMX_REG_TO_ADDR(NPM_ADC->ADCVBATRESULTMSB),
        [NPMX_ADC_MEAS_NTC]      = NPMX_REG_TO_ADDR(NPM_ADC->ADCGP0RESULTLSBS) -
                                   NPMX_REG_TO_ADDR(NPM_ADC->ADCNTCRESULTMSB),
        [NPMX_ADC_MEAS_DIE_TEMP] = NPMX_REG_TO_ADDR(NPM_ADC->ADCGP0RESULTLSBS) -
                                   NPMX_REG_TO_ADDR(NPM_ADC->ADCTEMPRESULTMSB),
        [NPMX_ADC_MEAS_VSYS]     = NPMX_REG_TO_ADDR(NPM_ADC->ADCGP0RESULTLSBS) -
                                   NPMX_REG_TO_ADDR(NPM_ADC->ADCVSYSRESULTMSB),
        [NPMX_ADC_MEAS_VBUS]     = NPMX_REG_TO_ADDR(NPM_ADC->ADCGP1RESULTLSBS) -
                                   NPMX_REG_TO_ADDR(NPM_ADC->ADCVBAT3RESULTMSB),
        [NPMX_ADC_MEAS_VBAT0]    = NPMX_REG_TO_ADDR(NPM_ADC->ADCGP1RESULTLSBS) -
                                   NPMX_REG_TO_ADDR(NPM_ADC->ADCVBAT0RESULTMSB),
        [NPMX_ADC_MEAS_VBAT1]    = NPMX_REG_TO_ADDR(NPM_ADC->ADCGP1RESULTLSBS) -
                                   NPMX_REG_TO_ADDR(NPM_ADC->ADCVBAT1RESULTMSB),
        [NPMX_ADC_MEAS_VBAT2]    = NPMX_REG_TO_ADDR(NPM_ADC->ADCGP1RESULTLSBS) -
                                   NPMX_REG_TO_ADDR(NPM_ADC->ADCVBAT2RESULTMSB),
        [NPMX_ADC_MEAS_VBAT3]    = NPMX_REG_TO_ADDR(NPM_ADC->ADCGP1RESULTLSBS) -
                                   NPMX_REG_TO_ADDR(NPM_ADC->ADCVBAT3RESULTMSB),
    };

    return lsb_registers[meas];
}

/**
 * @brief Function for getting LSB mask for given measurement.
 *
 * @param[in] meas Measurement type.
 *
 * @return LSB mask.
 */
static uint16_t lsb_mask_get(npmx_adc_meas_t meas)
{
    static const uint16_t lsb_masks[] =
    {
        [NPMX_ADC_MEAS_VBAT]     = ADC_ADCGP0RESULTLSBS_VBATRESULTLSB_Msk,
        [NPMX_ADC_MEAS_NTC]      = ADC_ADCGP0RESULTLSBS_NTCRESULTLSB_Msk,
        [NPMX_ADC_MEAS_DIE_TEMP] = ADC_ADCGP0RESULTLSBS_TEMPRESULTLSB_Msk,
        [NPMX_ADC_MEAS_VSYS]     = ADC_ADCGP0RESULTLSBS_VSYSRESULTLSB_Msk,
        [NPMX_ADC_MEAS_VBUS]     = ADC_ADCGP1RESULTLSBS_VBAT3RESULTLSB_Msk,
        [NPMX_ADC_MEAS_VBAT0]    = ADC_ADCGP1RESULTLSBS_VBAT0RESULTLSB_Msk,
        [NPMX_ADC_MEAS_VBAT1]    = ADC_ADCGP1RESULTLSBS_VBAT1RESULTLSB_Msk,
        [NPMX_ADC_MEAS_VBAT2]    = ADC_ADCGP1RESULTLSBS_VBAT2RESULTLSB_Msk,
        [NPMX_ADC_MEAS_VBAT3]    = ADC_ADCGP1RESULTLSBS_VBAT3RESULTLSB_Msk,
    };

    return lsb_masks[meas];
}

/**
 * @brief Function for getting LSB position for given measurement.
 *
 * @param[in] meas Measurement type.
 *
 * @return LSB position.
 */
static uint16_t lsb_position_get(npmx_adc_meas_t meas)
{
    static const uint16_t lsb_positions[] =
    {
        [NPMX_ADC_MEAS_VBAT]     = ADC_ADCGP0RESULTLSBS_VBATRESULTLSB_Pos,
        [NPMX_ADC_MEAS_NTC]      = ADC_ADCGP0RESULTLSBS_NTCRESULTLSB_Pos,
        [NPMX_ADC_MEAS_DIE_TEMP] = ADC_ADCGP0RESULTLSBS_TEMPRESULTLSB_Pos,
        [NPMX_ADC_MEAS_VSYS]     = ADC_ADCGP0RESULTLSBS_VSYSRESULTLSB_Pos,
        [NPMX_ADC_MEAS_VBUS]     = ADC_ADCGP1RESULTLSBS_VBAT3RESULTLSB_Pos,
        [NPMX_ADC_MEAS_VBAT0]    = ADC_ADCGP1RESULTLSBS_VBAT0RESULTLSB_Pos,
        [NPMX_ADC_MEAS_VBAT1]    = ADC_ADCGP1RESULTLSBS_VBAT1RESULTLSB_Pos,
        [NPMX_ADC_MEAS_VBAT2]    = ADC_ADCGP1RESULTLSBS_VBAT2RESULTLSB_Pos,
        [NPMX_ADC_MEAS_VBAT3]    = ADC_ADCGP1RESULTLSBS_VBAT3RESULTLSB_Pos,
    };

    return lsb_positions[meas];
}

/**
 * @brief Function for calculating measured battery voltage from ADC code.
 *
 * @param[in]  p_instance Pointer to the ADC instance.
 * @param[in]  code       Code read from ADC.
 * @param[out] p_val      Pointer to measured battery voltage in millivolts.
 *
 * @retval NPMX_SUCCESS Operation performed successfully.
 */
static npmx_error_t vbat_value_from_code(npmx_adc_t const * p_instance,
                                         uint16_t           code,
                                         uint16_t *         p_val)
{
    (void)p_instance;
    *p_val = (uint16_t)(((uint32_t)code * NPMX_PERIPH_ADC_VFS_VBAT_MV) /
                        NPMX_PERIPH_ADC_BITS_RESOLUTION);

    return NPMX_SUCCESS;
}

/**
 * @brief Function for getting configured battery NTC type in ADC.
 *
 * @param[in]  p_instance Pointer to the ADC instance.
 * @param[out] p_ntc      Pointer to type of the NTC battery thermistor variable.
 *
 * @retval NPMX_SUCCESS  Operation performed successfully.
 * @retval NPMX_ERROR_IO Error using IO bus line.
 */
static npmx_error_t ntc_get(npmx_adc_t const * p_instance, npmx_adc_ntc_type_t * p_ntc)
{
    uint8_t data;

    npmx_error_t err_code = npmx_backend_register_read(p_instance->p_backend,
                                                       NPMX_REG_TO_ADDR(NPM_ADC->ADCNTCRSEL),
                                                       &data,
                                                       1);

    if (err_code != NPMX_SUCCESS)
    {
        return err_code;
    }

    *p_ntc = (npmx_adc_ntc_type_t)data;

    return NPMX_SUCCESS;
}

static npmx_error_t ntc_resistance_get(npmx_adc_t const * p_instance, uint32_t * p_resistance)
{
    npmx_adc_ntc_type_t ntc_type;

    npmx_error_t err_code = ntc_get(p_instance, &ntc_type);

    if (err_code != NPMX_SUCCESS)
    {
        return err_code;
    }

    *p_resistance = ntc_type_convert_to_ohms(ntc_type);

    return NPMX_SUCCESS;
}

/**
 * @brief Function for calculating measured NTC value from ADC code.
 *
 * @param[in]  p_instance Pointer to the ADC instance.
 * @param[in]  code       Code read from ADC.
 * @param[out] p_val      Pointer to measured NTC value in ohms
 *
 * @retval NPMX_SUCCESS  Operation performed successfully.
 * @retval NPMX_ERROR_IO Error using IO bus line.
 */
static npmx_error_t ntc_value_from_code(npmx_adc_t const * p_instance,
                                        uint16_t           code,
                                        uint16_t *         p_val)
{
    uint32_t     ntc_resistance;
    npmx_error_t err_code = ntc_resistance_get(p_instance, &ntc_resistance);

    if (err_code != NPMX_SUCCESS)
    {
        return err_code;
    }

    *p_val = (uint16_t)((ntc_resistance * ((uint32_t)code)) /
                        (NPMX_PERIPH_ADC_BITS_RESOLUTION - code));

    return NPMX_SUCCESS;
}

/**
 * @brief Function for calculating measured die temperature from ADC code.
 *
 * @param[in]  p_instance Pointer to the ADC instance.
 * @param[in]  code       Code read from ADC.
 * @param[out] p_val      Pointer to measured die temperature in millicelsius.
 *
 * @retval NPMX_SUCCESS Operation performed successfully.
 */
static npmx_error_t die_temp_value_from_code(npmx_adc_t const * p_instance,
                                             uint16_t           code,
                                             uint16_t *         p_val)
{
    (void)p_instance;
    *p_val = (uint16_t)(NPMX_PERIPH_ADC_DIE_TEMP_OFFSET_MC -
                        (NPMX_PERIPH_ADC_DIE_TEMP_MULT_MC * (uint32_t)code));

    return NPMX_SUCCESS;
}

/**
 * @brief Function for calculating measured external supply voltage from ADC code.
 *
 * @param[in]  p_instance Pointer to the ADC instance.
 * @param[in]  code       Code read from ADC.
 * @param[out] p_val      Pointer to measured external supply voltage in millivolts.
 *
 * @retval NPMX_SUCCESS Operation performed successfully.
 */
static npmx_error_t vsys_value_from_code(npmx_adc_t const * p_instance,
                                         uint16_t           code,
                                         uint16_t *         p_val)
{
    (void)p_instance;
    *p_val = (uint16_t)(((uint32_t)code * NPMX_PERIPH_ADC_VFS_VSYS_MV) /
                        NPMX_PERIPH_ADC_BITS_RESOLUTION);

    return NPMX_SUCCESS;
}

/**
 * @brief Function for calculating measured supply voltage from ADC code.
 *
 * @param[in]  p_instance Pointer to the ADC instance.
 * @param[in]  code       Code read from ADC.
 * @param[out] p_val      Pointer to measured supply voltage in millivolts.
 *
 * @retval NPMX_SUCCESS Operation performed successfully.
 */
static npmx_error_t vbus_value_from_code(npmx_adc_t const * p_instance,
                                         uint16_t           code,
                                         uint16_t *         p_val)
{
    (void)p_instance;
    *p_val = (uint16_t)(((uint32_t)code * NPMX_PERIPH_ADC_VFS_VBUS_MV) /
                        NPMX_PERIPH_ADC_BITS_RESOLUTION);

    return NPMX_SUCCESS;
}

/**
 * @brief Function for calculating measured value from ADC code.
 *
 * @param[in]  p_instance Pointer to the ADC instance.
 * @param[in]  meas       Measurement type.
 * @param[in]  code       Code read from ADC.
 * @param[out] p_val      Pointer to measured value.
 *
 * @retval NPMX_SUCCESS             Operation performed successfully.
 * @retval NPMX_ERROR_IO            Error using IO bus line.
 * @retval NPMX_ERROR_INVALID_PARAM No possibility to calculate value for geaven npmx_adc_meas_t.
 */
static npmx_error_t value_from_code_get(npmx_adc_t const * p_instance,
                                        npmx_adc_meas_t    meas,
                                        uint16_t           code,
                                        uint16_t *         p_val)
{
    static const code_to_val_fun_t code_to_value_funs[NPMX_PERIPH_ADC_MEAS_REGISTERS_COUNT] =
    {
        [NPMX_ADC_MEAS_VBAT]     = vbat_value_from_code,
        [NPMX_ADC_MEAS_NTC]      = ntc_value_from_code,
        [NPMX_ADC_MEAS_DIE_TEMP] = die_temp_value_from_code,
        [NPMX_ADC_MEAS_VSYS]     = vsys_value_from_code,
        [NPMX_ADC_MEAS_VBUS]     = vbus_value_from_code,
        [NPMX_ADC_MEAS_VBAT0]    = NULL,
        [NPMX_ADC_MEAS_VBAT1]    = NULL,
        [NPMX_ADC_MEAS_VBAT2]    = NULL,
        [NPMX_ADC_MEAS_VBAT3]    = NULL,
    };

    if (code_to_value_funs[meas] == NULL)
    {
        return NPMX_ERROR_INVALID_PARAM;
    }

    return code_to_value_funs[meas](p_instance, code, p_val);
}

npmx_adc_t * npmx_adc_get(npmx_instance_t * p_pmic, uint8_t idx)
{
    NPMX_ASSERT(p_pmic);
    NPMX_ASSERT(idx < NPMX_PERIPH_ADC_COUNT);

    return &p_pmic->adc[idx];
}

npmx_adc_ntc_type_t npmx_adc_ntc_type_convert(uint32_t resistance)
{
    switch (resistance)
    {
        case 0:
            return NPMX_ADC_NTC_TYPE_HI_Z;
        case 10000:
            return NPMX_ADC_NTC_TYPE_10_K;
        case 47000:
            return NPMX_ADC_NTC_TYPE_47_K;
        case 100000:
            return NPMX_ADC_NTC_TYPE_100_K;
        default:
            return NPMX_ADC_NTC_TYPE_INVALID;
    }
}

uint32_t npmx_adc_ntc_type_convert_to_ohms(npmx_adc_ntc_type_t battery_ntc)
{
    NPMX_ASSERT(battery_ntc != NPMX_ADC_NTC_TYPE_INVALID);

    return ntc_type_convert_to_ohms(battery_ntc);
}

npmx_adc_ntc_meas_interval_t npmx_adc_ntc_meas_interval_convert(uint32_t time) {
    switch (time)
    {
        case 4:
            return NPMX_ADC_NTC_MEAS_INTERVAL_4_MS;
        case 64:
            return NPMX_ADC_NTC_MEAS_INTERVAL_64_MS;
        case 128:
            return NPMX_ADC_NTC_MEAS_INTERVAL_128_MS;
        case 1024:
            return NPMX_ADC_NTC_MEAS_INTERVAL_1024_MS;
        default:
            return NPMX_ADC_NTC_MEAS_INTERVAL_INVALID;
    }
}

uint32_t npmx_adc_ntc_meas_interval_convert_to_ms(npmx_adc_ntc_meas_interval_t enum_value)
{
    NPMX_ASSERT(enum_value != NPMX_ADC_NTC_MEAS_INTERVAL_INVALID);

    static const uint32_t convert_table[] =
    {
        [NPMX_ADC_NTC_MEAS_INTERVAL_4_MS]    = 4,
        [NPMX_ADC_NTC_MEAS_INTERVAL_64_MS]   = 64,
        [NPMX_ADC_NTC_MEAS_INTERVAL_128_MS]  = 128,
        [NPMX_ADC_NTC_MEAS_INTERVAL_1024_MS] = 1024,
    };

    return convert_table[enum_value];
}

npmx_adc_die_temp_meas_interval_t npmx_adc_die_temp_meas_interval_convert(uint32_t time)
{
    switch (time)
    {
        case 4:
            return NPMX_ADC_DIE_TEMP_MEAS_INTERVAL_4_MS;
        case 8:
            return NPMX_ADC_DIE_TEMP_MEAS_INTERVAL_8_MS;
        case 16:
            return NPMX_ADC_DIE_TEMP_MEAS_INTERVAL_16_MS;
        case 32:
            return NPMX_ADC_DIE_TEMP_MEAS_INTERVAL_32_MS;
        default:
            return NPMX_ADC_DIE_TEMP_MEAS_INTERVAL_INVALID;
    }
}

uint32_t npmx_adc_die_temp_meas_interval_convert_to_ms(npmx_adc_die_temp_meas_interval_t enum_value)
{
    NPMX_ASSERT(enum_value != NPMX_ADC_DIE_TEMP_MEAS_INTERVAL_INVALID);

    static const uint32_t convert_table[] =
    {
        [NPMX_ADC_DIE_TEMP_MEAS_INTERVAL_4_MS]  = 4,
        [NPMX_ADC_DIE_TEMP_MEAS_INTERVAL_8_MS]  = 8,
        [NPMX_ADC_DIE_TEMP_MEAS_INTERVAL_16_MS] = 16,
        [NPMX_ADC_DIE_TEMP_MEAS_INTERVAL_32_MS] = 32,
    };

    return convert_table[enum_value];
}

const char * const npmx_adc_ntc_type_map_to_string(npmx_adc_ntc_type_t enum_value)
{
    NPMX_ASSERT(enum_value != NPMX_ADC_NTC_TYPE_INVALID);

    static const char * const mapping_table [] =
    {
        [NPMX_ADC_NTC_TYPE_HI_Z]  = "HI_Z",
        [NPMX_ADC_NTC_TYPE_10_K]  = "10k",
        [NPMX_ADC_NTC_TYPE_47_K]  = "47k",
        [NPMX_ADC_NTC_TYPE_100_K] = "100k",
    };

    return mapping_table[enum_value];
}

npmx_error_t npmx_adc_task_trigger(npmx_adc_t const * p_instance, npmx_adc_task_t task)
{
    NPMX_ASSERT(p_instance);

    return task_trigger(p_instance, task);
}

npmx_error_t npmx_adc_config_set(npmx_adc_t const * p_instance, npmx_adc_config_t const * p_config)
{
    NPMX_ASSERT(p_instance);
    NPMX_ASSERT(p_config);

    npmx_error_t err_code;
    uint8_t      data = 0;

    if (p_config->vbat_auto)
    {
        /* Autoupdate needs to be enabled before VBATAUTOENABLE in ADCCONFIG. */
        err_code = task_trigger(p_instance, NPMX_ADC_TASK_UPDATE_AUTO_INTERVAL);
        if (err_code != NPMX_SUCCESS)
        {
            return err_code;
        }
    }

    data |= ((p_config->vbat_auto ? ADC_ADCCONFIG_VBATAUTOENABLE_AUTOENABLE :
                                    ADC_ADCCONFIG_VBATAUTOENABLE_NOAUTO)
             << ADC_ADCCONFIG_VBATAUTOENABLE_Pos) & ADC_ADCCONFIG_VBATAUTOENABLE_Msk;

    data |= ((p_config->vbat_burst ? ADC_ADCCONFIG_VBATBURSTENABLE_BURSTMODE :
                                     ADC_ADCCONFIG_VBATBURSTENABLE_SINGLEMODE)
             << ADC_ADCCONFIG_VBATBURSTENABLE_Pos) &
            ADC_ADCCONFIG_VBATBURSTENABLE_Msk;

    return npmx_backend_register_write(p_instance->p_backend,
                                       NPMX_REG_TO_ADDR(NPM_ADC->ADCCONFIG),
                                       &data,
                                       1);
}

npmx_error_t npmx_adc_config_get(npmx_adc_t const * p_instance, npmx_adc_config_t * p_config)
{
    NPMX_ASSERT(p_instance);
    NPMX_ASSERT(p_config);

    uint8_t      data;
    npmx_error_t err_code = npmx_backend_register_read(p_instance->p_backend,
                                                       NPMX_REG_TO_ADDR(NPM_ADC->ADCCONFIG),
                                                       &data,
                                                       1);
    if (err_code != NPMX_SUCCESS)
    {
        return err_code;
    }

    p_config->vbat_auto = (((data & ADC_ADCCONFIG_VBATAUTOENABLE_Msk)
                            >> ADC_ADCCONFIG_VBATAUTOENABLE_Pos) ==
                           ADC_ADCCONFIG_VBATAUTOENABLE_AUTOENABLE);

    p_config->vbat_burst = (((data & ADC_ADCCONFIG_VBATBURSTENABLE_Msk)
                             >> ADC_ADCCONFIG_VBATBURSTENABLE_Pos) ==
                            ADC_ADCCONFIG_VBATBURSTENABLE_BURSTMODE);

    return NPMX_SUCCESS;
}

npmx_error_t npmx_adc_ntc_set(npmx_adc_t * p_instance, npmx_adc_ntc_type_t battery_ntc)
{
    NPMX_ASSERT(p_instance);

    uint8_t data = (((uint8_t)battery_ntc) << ADC_ADCNTCRSEL_ADCNTCRSEL_Pos) &
                   ADC_ADCNTCRSEL_ADCNTCRSEL_Msk;

    return npmx_backend_register_write(p_instance->p_backend,
                                       NPMX_REG_TO_ADDR(NPM_ADC->ADCNTCRSEL),
                                       &data,
                                       1);
}

npmx_error_t npmx_adc_ntc_get(npmx_adc_t * p_instance, npmx_adc_ntc_type_t * p_ntc)
{
    NPMX_ASSERT(p_instance);
    NPMX_ASSERT(p_ntc);

    return ntc_get(p_instance, p_ntc);
}

npmx_error_t npmx_adc_ntc_resistance_get(npmx_adc_t const * p_instance, uint32_t * p_resistance)
{
    NPMX_ASSERT(p_instance);
    NPMX_ASSERT(p_resistance);

    return ntc_resistance_get(p_instance, p_resistance);
}

npmx_error_t npmx_adc_meas_check(npmx_adc_t const * p_instance,
                                 npmx_adc_meas_t    meas,
                                 bool *             p_ready)
{
    NPMX_ASSERT(p_instance);
    NPMX_ASSERT(meas < NPMX_ADC_MEAS_COUNT);
    NPMX_ASSERT(p_ready);

    static const uint8_t meas_masks[] =
    {
        [NPMX_ADC_MEAS_VBAT]     = MAIN_EVENTSADCSET_EVENTADCVBATRDY_Msk,
        [NPMX_ADC_MEAS_NTC]      = MAIN_EVENTSADCSET_EVENTADCNTCRDY_Msk,
        [NPMX_ADC_MEAS_DIE_TEMP] = MAIN_EVENTSADCSET_EVENTADCTEMPRDY_Msk,
        [NPMX_ADC_MEAS_VSYS]     = MAIN_EVENTSADCSET_EVENTADCVSYSRDY_Msk,
        [NPMX_ADC_MEAS_VBUS]     = MAIN_EVENTSADCSET_EVENTADCVBUS7V0RDY_Msk,
        [NPMX_ADC_MEAS_VBAT0]    = MAIN_EVENTSADCSET_EVENTADCVBATRDY_Msk,
        [NPMX_ADC_MEAS_VBAT1]    = MAIN_EVENTSADCSET_EVENTADCVBATRDY_Msk,
        [NPMX_ADC_MEAS_VBAT2]    = MAIN_EVENTSADCSET_EVENTADCVBATRDY_Msk,
        [NPMX_ADC_MEAS_VBAT3]    = MAIN_EVENTSADCSET_EVENTADCVBATRDY_Msk,
    };

    uint8_t      data;
    npmx_error_t err_code = npmx_backend_register_read(p_instance->p_backend,
                                                       NPMX_REG_TO_ADDR(NPM_MAIN->EVENTSADCSET),
                                                       &data,
                                                       1);
    if (err_code != NPMX_SUCCESS)
    {
        return err_code;
    }

    *p_ready = (data & meas_masks[meas]) != 0;

    return NPMX_SUCCESS;
}

npmx_error_t npmx_adc_meas_get(npmx_adc_t const * p_instance,
                               npmx_adc_meas_t    meas,
                               uint16_t *         p_value)
{
    NPMX_ASSERT(p_instance);
    NPMX_ASSERT(meas < NPMX_ADC_MEAS_COUNT);
    NPMX_ASSERT(p_value);

    uint8_t  data[NPMX_PERIPH_ADC_MEAS_LSB_MAX_OFFSET];
    uint16_t msb_reg_address = msb_register_address_get(meas);

    uint8_t lsb_reg_offset = lsb_register_offset_get(meas);

    npmx_error_t err_code = npmx_backend_register_read(p_instance->p_backend,
                                                       msb_reg_address,
                                                       data,
                                                       lsb_reg_offset + 1U);
    if (err_code != NPMX_SUCCESS)
    {
        return err_code;
    }

    /* Get LSB data. */
    uint16_t code = (data[lsb_reg_offset] & (uint8_t)lsb_mask_get(meas)) >> lsb_position_get(meas);

    /* Get MSB data. */
    code |= ((uint16_t)data[0] << NPMX_PERIPH_ADC_RESULT_MSB_SHIFT);

    /* Transform code to value */
    return value_from_code_get(p_instance, meas, code, p_value);
}

npmx_error_t npmx_adc_meas_all_get(npmx_adc_t const *    p_instance,
                                   npmx_adc_meas_all_t * p_values)
{
    NPMX_ASSERT(p_instance);
    NPMX_ASSERT(p_values);

    uint8_t data[NPMX_PERIPH_ADC_MEAS_REGISTERS_COUNT];

    npmx_error_t err_code = npmx_backend_register_read(p_instance->p_backend,
                                                       NPMX_REG_TO_ADDR(NPM_ADC->ADCVBATRESULTMSB),
                                                       data,
                                                       NPMX_PERIPH_ADC_MEAS_REGISTERS_COUNT);
    if (err_code != NPMX_SUCCESS)
    {
        return err_code;
    }

    for (uint8_t i = NPMX_ADC_MEAS_VBAT; i < NPMX_ADC_MEAS_COUNT; i++)
    {
        uint8_t lsb_reg_offset = lsb_register_offset_get(i);
        uint16_t code = (data[i + lsb_reg_offset] & (uint8_t)lsb_mask_get(i))
                        >> lsb_position_get(i);
        code |= ((uint16_t)data[i] << NPMX_PERIPH_ADC_RESULT_MSB_SHIFT);

        err_code = value_from_code_get(p_instance, (npmx_adc_meas_t)i, code, &p_values->values[i]);
        if (err_code != NPMX_SUCCESS)
        {
            return err_code;
        }
    }

    return NPMX_SUCCESS;
}

npmx_error_t npmx_adc_ntc_meas_interval_set(npmx_adc_t *                 p_instance,
                                            npmx_adc_ntc_meas_interval_t interval)
{
    NPMX_ASSERT(p_instance);

    uint8_t      data;
    npmx_error_t err_code = npmx_backend_register_read(p_instance->p_backend,
                                                       NPMX_REG_TO_ADDR(NPM_ADC->ADCAUTOTIMCONF),
                                                       &data,
                                                       1);
    if (err_code != NPMX_SUCCESS)
    {
        return err_code;
    }

    data &= ~ADC_ADCAUTOTIMCONF_NTCAUTOTIM_Msk;
    data |= ((uint8_t)interval << ADC_ADCAUTOTIMCONF_NTCAUTOTIM_Pos) &
            ADC_ADCAUTOTIMCONF_NTCAUTOTIM_Msk;

    err_code = npmx_backend_register_write(p_instance->p_backend,
                                           NPMX_REG_TO_ADDR(NPM_ADC->ADCAUTOTIMCONF),
                                           &data,
                                           1);

    if (err_code != NPMX_SUCCESS)
    {
        return err_code;
    }

    return task_trigger(p_instance, NPMX_ADC_TASK_UPDATE_AUTO_INTERVAL);
}

npmx_error_t npmx_adc_ntc_meas_interval_get(npmx_adc_t *                   p_instance,
                                            npmx_adc_ntc_meas_interval_t * p_interval)
{
    NPMX_ASSERT(p_instance);
    NPMX_ASSERT(p_interval);

    uint8_t      data;
    npmx_error_t err_code = npmx_backend_register_read(p_instance->p_backend,
                                                       NPMX_REG_TO_ADDR(NPM_ADC->ADCAUTOTIMCONF),
                                                       &data,
                                                       1);
    if (err_code != NPMX_SUCCESS)
    {
        return err_code;
    }

    *p_interval = ((data & ADC_ADCAUTOTIMCONF_NTCAUTOTIM_Msk)
                   >> ADC_ADCAUTOTIMCONF_NTCAUTOTIM_Pos);

    return NPMX_SUCCESS;
}

npmx_error_t npmx_adc_die_temp_meas_interval_set(npmx_adc_t *                      p_instance,
                                                 npmx_adc_die_temp_meas_interval_t interval)
{
    NPMX_ASSERT(p_instance);

    uint8_t      data;
    npmx_error_t err_code = npmx_backend_register_read(p_instance->p_backend,
                                                       NPMX_REG_TO_ADDR(NPM_ADC->ADCAUTOTIMCONF),
                                                       &data,
                                                       1);
    if (err_code != NPMX_SUCCESS)
    {
        return err_code;
    }

    data &= ~ADC_ADCAUTOTIMCONF_TEMPAUTOTIM_Msk;
    data |= ((uint8_t)interval << ADC_ADCAUTOTIMCONF_TEMPAUTOTIM_Pos) &
            ADC_ADCAUTOTIMCONF_TEMPAUTOTIM_Msk;

    err_code = npmx_backend_register_write(p_instance->p_backend,
                                           NPMX_REG_TO_ADDR(NPM_ADC->ADCAUTOTIMCONF),
                                           &data,
                                           1);

    if (err_code != NPMX_SUCCESS)
    {
        return err_code;
    }

    err_code = task_trigger(p_instance, NPMX_ADC_TASK_UPDATE_AUTO_INTERVAL);

    if (err_code != NPMX_SUCCESS)
    {
        return err_code;
    }

    return NPMX_SUCCESS;
}

npmx_error_t npmx_adc_die_temp_meas_interval_get(npmx_adc_t *                        p_instance,
                                                 npmx_adc_die_temp_meas_interval_t * p_interval)
{
    NPMX_ASSERT(p_instance);
    NPMX_ASSERT(p_interval);

    uint8_t      data;
    npmx_error_t err_code = npmx_backend_register_read(p_instance->p_backend,
                                                       NPMX_REG_TO_ADDR(NPM_ADC->ADCAUTOTIMCONF),
                                                       &data,
                                                       1);
    if (err_code != NPMX_SUCCESS)
    {
        return err_code;
    }

    *p_interval = ((data & ADC_ADCAUTOTIMCONF_TEMPAUTOTIM_Msk)
                   >> ADC_ADCAUTOTIMCONF_TEMPAUTOTIM_Pos);

    return NPMX_SUCCESS;
}

npmx_error_t npmx_adc_vbat_meas_delay_set(npmx_adc_t const * p_instance, uint8_t delay)
{
    NPMX_ASSERT(p_instance);

    uint8_t data = delay << ADC_ADCDELTIMCONF_VBATDELTIM_Pos;
    data &= ADC_ADCDELTIMCONF_VBATDELTIM_Msk;

    return npmx_backend_register_write(p_instance->p_backend,
                                       NPMX_REG_TO_ADDR(NPM_ADC->ADCDELTIMCONF),
                                       &data,
                                       1);
}

npmx_error_t npmx_adc_vbat_meas_delay_get(npmx_adc_t const * p_instance, uint8_t * p_delay)
{
    NPMX_ASSERT(p_instance);
    NPMX_ASSERT(p_delay);

    uint8_t      data;
    npmx_error_t err_code = npmx_backend_register_read(p_instance->p_backend,
                                                       NPMX_REG_TO_ADDR(NPM_ADC->ADCDELTIMCONF),
                                                       &data,
                                                       1);

    if (err_code != NPMX_SUCCESS)
    {
        return err_code;
    }

    *p_delay = ((data & ADC_ADCDELTIMCONF_VBATDELTIM_Msk)
                >> ADC_ADCDELTIMCONF_VBATDELTIM_Pos);

    return NPMX_SUCCESS;
}
