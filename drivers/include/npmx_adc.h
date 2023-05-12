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

#ifndef NPMX_ADC_H__
#define NPMX_ADC_H__

#include <npmx.h>

#ifdef __cplusplus
extern "C" {
#endif

/**
 * @defgroup npmx_adc ADC
 * @{
 * @ingroup npmx_drivers
 * @brief   Analog-to-Digital Converter (ADC) peripheral driver.
 */

/** @brief Data structure of the Analog-to-Digital Converter (ADC) driver instance. */
typedef struct
{
    npmx_backend_instance_t * p_backend; ///< Pointer to backend instance.
} npmx_adc_t;

/** @brief ADC tasks. */
typedef enum
{
    NPMX_ADC_TASK_SINGLE_SHOT_VBAT,     ///< VBAT single-shot measurement trigger.
    NPMX_ADC_TASK_SINGLE_SHOT_NTC,      ///< Battery NTC single-shot measurement trigger.
    NPMX_ADC_TASK_SINGLE_SHOT_DIE_TEMP, ///< Internal die temperature single-shot measurement trigger.
    NPMX_ADC_TASK_SINGLE_SHOT_VSYS,     ///< VSYS voltage single-shot measurement trigger.
    NPMX_ADC_TASK_SINGLE_SHOT_VBUS,     ///< VBUS (7 Volt range) single-shot measurement trigger.
    NPMX_ADC_TASK_DELAYED_MEAS_VBAT,    ///< VBAT delay measurement trigger.
    NPMX_ADC_TASK_UPDATE_AUTO_INTERVAL, ///< Update intervals for NTC and die temperature auto measurements trigger.
} npmx_adc_task_t;

/** @brief Possible measurements that can be read from ADC. */
typedef enum
{
    NPMX_ADC_MEAS_VBAT,     ///< VBAT measurement.
    NPMX_ADC_MEAS_NTC,      ///< Battery NTC measurement.
    NPMX_ADC_MEAS_DIE_TEMP, ///< Internal die temperature measurement.
    NPMX_ADC_MEAS_VSYS,     ///< VSYS voltage measurement.
    NPMX_ADC_MEAS_VBUS,     ///< VBUS (7 Volt range) measurement.
    NPMX_ADC_MEAS_VBAT0,    ///< VBAT0 from burst mode.
    NPMX_ADC_MEAS_VBAT1,    ///< VBAT1 from burst mode.
    NPMX_ADC_MEAS_VBAT2,    ///< VBAT2 from burst mode.
    NPMX_ADC_MEAS_VBAT3,    ///< VBAT3 from burst mode.
    NPMX_ADC_MEAS_COUNT,    ///< ADC requests maximum count.
} npmx_adc_meas_t;

/**
 * @brief Battery NTC type.
 *        Should be checked in battery documentation.
 */
typedef enum
{
    NPMX_ADC_NTC_TYPE_HI_Z    = ADC_ADCNTCRSEL_ADCNTCRSEL_Hi_Z, ///< No resistor.
    NPMX_ADC_NTC_TYPE_10_K    = ADC_ADCNTCRSEL_ADCNTCRSEL_10K,  ///< NTC10K.
    NPMX_ADC_NTC_TYPE_47_K    = ADC_ADCNTCRSEL_ADCNTCRSEL_47K,  ///< NTC47K.
    NPMX_ADC_NTC_TYPE_100_K   = ADC_ADCNTCRSEL_ADCNTCRSEL_100K, ///< NTC100K.
    NPMX_ADC_NTC_TYPE_MAX     = NPMX_ADC_NTC_TYPE_100_K,        ///< Maximum resistance.
    NPMX_ADC_NTC_TYPE_INVALID = NPMX_INVALID_ENUM_VALUE,        ///< Invalid battery NTC type.
} npmx_adc_ntc_type_t;

/** @brief Intervals of automatic measurements of NTC during charging. */
typedef enum
{
    NPMX_ADC_NTC_MEAS_INTERVAL_4_MS    = ADC_ADCAUTOTIMCONF_NTCAUTOTIM_4MS,    ///< Interval equal to 4 ms.
    NPMX_ADC_NTC_MEAS_INTERVAL_64_MS   = ADC_ADCAUTOTIMCONF_NTCAUTOTIM_64MS,   ///< Interval equal to 64 ms.
    NPMX_ADC_NTC_MEAS_INTERVAL_128_MS  = ADC_ADCAUTOTIMCONF_NTCAUTOTIM_128MS,  ///< Interval equal to 128 ms.
    NPMX_ADC_NTC_MEAS_INTERVAL_1024_MS = ADC_ADCAUTOTIMCONF_NTCAUTOTIM_1024MS, ///< Interval equal to 1024 ms.
    NPMX_ADC_NTC_MEAS_INTERVAL_MAX     = NPMX_ADC_NTC_MEAS_INTERVAL_1024_MS,   ///< Maximum interval value.
    NPMX_ADC_NTC_MEAS_INTERVAL_INVALID = NPMX_INVALID_ENUM_VALUE,              ///< Invalid interval value.
} npmx_adc_ntc_meas_interval_t;

/** @brief Intervals of automatic measurements of die temperature during charging. */
typedef enum
{
    NPMX_ADC_DIE_TEMP_MEAS_INTERVAL_4_MS    = ADC_ADCAUTOTIMCONF_TEMPAUTOTIM_4MS,    ///< Interval equal to 4 ms.
    NPMX_ADC_DIE_TEMP_MEAS_INTERVAL_8_MS    = ADC_ADCAUTOTIMCONF_TEMPAUTOTIM_8MS,    ///< Interval equal to 8 ms.
    NPMX_ADC_DIE_TEMP_MEAS_INTERVAL_16_MS   = ADC_ADCAUTOTIMCONF_TEMPAUTOTIM_16MS,   ///< Interval equal to 16 ms.
    NPMX_ADC_DIE_TEMP_MEAS_INTERVAL_32_MS   = ADC_ADCAUTOTIMCONF_TEMPAUTOTIM_32MS,   ///< Interval equal to 32 ms.
    NPMX_ADC_DIE_TEMP_MEAS_INTERVAL_MAX     = NPMX_ADC_DIE_TEMP_MEAS_INTERVAL_32_MS, ///< Maximum interval value.
    NPMX_ADC_DIE_TEMP_MEAS_INTERVAL_INVALID = NPMX_INVALID_ENUM_VALUE,               ///< Invalid interval value.
} npmx_adc_die_temp_meas_interval_t;

/** @brief Configuration structure for ADC. */
typedef struct
{
    bool vbat_auto;  ///< Enable VBAT auto measurement every 1 second.
    bool vbat_burst; ///< Enable VBAT Burst mode VBAT0, VBAT1, VBAT2, VBAT3.
} npmx_adc_config_t;

/** @brief Structure for all measurements readings. */
typedef struct
{
    uint16_t values[NPMX_ADC_MEAS_COUNT]; ///< Table for all measurements readings.
} npmx_adc_meas_all_t;

/**
 * @brief Function for returning ADC instance based on index.
 *
 * @param[in] p_pmic Pointer to the PMIC instance.
 * @param[in] idx    Index of the ADC instance.
 *
 * @return Pointer to the ADC instance.
 */
npmx_adc_t * npmx_adc_get(npmx_instance_t * p_pmic, uint8_t idx);

/**
 * @brief Function for converting resistance in ohms to
 *        @ref npmx_adc_ntc_type_t enumeration.
 *
 * @param[in] resistance Resistance in ohms to be converted into
 *                       @ref npmx_adc_ntc_type_t enumeration.
 *
 * @return Result of conversion. @ref NPMX_ADC_NTC_TYPE_INVALID if given resistance is not
 *         represented in enumeration.
 */
npmx_adc_ntc_type_t npmx_adc_ntc_type_convert(uint32_t resistance);

/**
 * @brief Function for converting the value from NTC enumeration type to resistance.
 *
 * @param[in] battery_ntc Battery NTC type.
 *
 * @return Resistance value in ohms.
 */
uint32_t npmx_adc_ntc_type_convert_to_ohms(npmx_adc_ntc_type_t battery_ntc);

/**
 * @brief Function for converting time in milliseconds to
 *        @ref npmx_adc_ntc_meas_interval_t enumeration.
 *
 * @param[in] time Time in milliseconds to be converted into
 *                 @ref npmx_adc_ntc_meas_interval_t enumeration.
 *
 * @return Result of conversion. @ref NPMX_ADC_NTC_MEAS_INTERVAL_INVALID if given time
 *         is not represented in enumeration.
 */
npmx_adc_ntc_meas_interval_t npmx_adc_ntc_meas_interval_convert(uint32_t time);

/**
 * @brief Function for converting @ref npmx_adc_ntc_meas_interval_t enumeration to milliseconds.
 *
 * @param[in] enum_value Time defined as @ref npmx_adc_ntc_meas_interval_t enumeration to be converted into milliseconds.
 *
 * @return Result of conversion.
 */
uint32_t npmx_adc_ntc_meas_interval_convert_to_ms(npmx_adc_ntc_meas_interval_t enum_value);

/**
 * @brief Function for converting time in milliseconds to
 *        @ref npmx_adc_die_temp_meas_interval_t enumeration.
 *
 * @param[in] time Time in milliseconds to be converted into
 *                 @ref npmx_adc_die_temp_meas_interval_t enumeration.
 *
 * @return Result of conversion. @ref NPMX_ADC_DIE_TEMP_MEAS_INTERVAL_INVALID if given time
 *         is not represented in enumeration.
 */
npmx_adc_die_temp_meas_interval_t npmx_adc_die_temp_meas_interval_convert(uint32_t time);

/**
 * @brief Function for converting @ref npmx_adc_die_temp_meas_interval_t enumeration to milliseconds.
 *
 * @param[in] enum_value Time defined as @ref npmx_adc_die_temp_meas_interval_t enumeration to be converted into milliseconds.
 *
 * @return Result of conversion.
 */
uint32_t
npmx_adc_die_temp_meas_interval_convert_to_ms(npmx_adc_die_temp_meas_interval_t enum_value);

/**
 * @brief Function for mapping @ref npmx_adc_ntc_type_t enumeration values to string.
 *
 * @param[in] enum_value NTC type as @ref npmx_adc_ntc_type_t enumeration to be mapped.
 *
 * @return Result of conversion.
 */
const char * const npmx_adc_ntc_type_map_to_string(npmx_adc_ntc_type_t enum_value);

/**
 * @brief Function for activating the specified ADC task.
 *
 * @param[in] p_instance Pointer to the ADC instance.
 * @param[in] task       Task to be activated.
 *
 * @retval NPMX_SUCCESS  Operation performed successfully.
 * @retval NPMX_ERROR_IO Error using IO bus line.
 */
npmx_error_t npmx_adc_task_trigger(npmx_adc_t const * p_instance, npmx_adc_task_t task);

/**
 * @brief Function for setting the configuration for ADC.
 *
 * @param[in] p_instance Pointer to the ADC instance.
 * @param[in] p_config   Pointer to the configuration of the ADC to be applied.
 *
 * @retval NPMX_SUCCESS  Operation performed successfully.
 * @retval NPMX_ERROR_IO Error using IO bus line.
 */
npmx_error_t npmx_adc_config_set(npmx_adc_t const * p_instance, npmx_adc_config_t const * p_config);

/**
 * @brief Function for reading the ADC configuration.
 *
 * @param[in]  p_instance Pointer to the ADC instance.
 * @param[out] p_config   Pointer to the ADC configuration structure.
 *
 * @retval NPMX_SUCCESS  Operation performed successfully.
 * @retval NPMX_ERROR_IO Error using IO bus line.
 */
npmx_error_t npmx_adc_config_get(npmx_adc_t const * p_instance, npmx_adc_config_t * p_config);

/**
 * @brief Function for configuring ADC with battery NTC type.
 *
 * @param[in] p_instance  Pointer to the ADC instance.
 * @param[in] battery_ntc Type of the NTC battery thermistor.
 *
 * @retval NPMX_SUCCESS  Operation performed successfully.
 * @retval NPMX_ERROR_IO Error using IO bus line.
 */
npmx_error_t npmx_adc_ntc_set(npmx_adc_t * p_instance, npmx_adc_ntc_type_t battery_ntc);

/**
 * @brief Function for getting configured battery NTC type in ADC.
 *
 * @param[in]  p_instance Pointer to the ADC instance.
 * @param[out] p_ntc      Pointer to type of the NTC battery thermistor variable.
 *
 * @retval NPMX_SUCCESS  Operation performed successfully.
 * @retval NPMX_ERROR_IO Error using IO bus line.
 */
npmx_error_t npmx_adc_ntc_get(npmx_adc_t * p_instance, npmx_adc_ntc_type_t * p_ntc);

/**
 * @brief Function for getting the nominal NTC resistance.
 *
 * @param[in]  p_instance   Pointer to the ADC instance.
 * @param[out] p_resistance Pointer to the nominal NTC resistance value in ohms.
 *
 * @retval NPMX_SUCCESS  Operation performed successfully.
 * @retval NPMX_ERROR_IO Error using IO bus line.
 */
npmx_error_t npmx_adc_ntc_resistance_get(npmx_adc_t const * p_instance, uint32_t * p_resistance);

/**
 * @brief Function for checking if measured value is ready to be read.
 *
 * @note This function should not be used when interrupt for measurement is enabled.
 *
 * @param[in]  p_instance Pointer to the ADC instance.
 * @param[in]  meas       Measurement value to be checked.
 * @param[out] p_ready    Pointer to variable for check value.
 *
 * @retval NPMX_SUCCESS  Operation performed successfully.
 * @retval NPMX_ERROR_IO Error using IO bus line.
 */
npmx_error_t npmx_adc_meas_check(npmx_adc_t const * p_instance,
                                 npmx_adc_meas_t    meas,
                                 bool *             p_ready);

/**
 * @brief Function for getting measured value.
 *
 * @param[in]  p_instance Pointer to the ADC instance.
 * @param[in]  meas       Measurement value to be read.
 * @param[out] p_value    Pointer to variable for read value.
 *
 * @retval NPMX_SUCCESS  Operation performed successfully.
 * @retval NPMX_ERROR_IO Error using IO bus line.
 */
npmx_error_t npmx_adc_meas_get(npmx_adc_t const * p_instance,
                               npmx_adc_meas_t    meas,
                               uint16_t *         p_value);

/**
 * @brief Function for getting all measured values.
 *
 * @param[in]  p_instance Pointer to the ADC instance.
 * @param[out] p_values   Pointer to structure with read values.
 *
 * @retval NPMX_SUCCESS  Operation performed successfully.
 * @retval NPMX_ERROR_IO Error using IO bus line.
 */
npmx_error_t npmx_adc_meas_all_get(npmx_adc_t const * p_instance, npmx_adc_meas_all_t * p_values);

/**
 * @brief Function for setting the NTC measurement interval during charging.
 *
 * @param[in] p_instance Pointer to the ADC instance.
 * @param[in] interval   Interval value.
 *
 * @retval NPMX_SUCCESS  Operation performed successfully.
 * @retval NPMX_ERROR_IO Error using IO bus line.
 */
npmx_error_t npmx_adc_ntc_meas_interval_set(npmx_adc_t *                 p_instance,
                                            npmx_adc_ntc_meas_interval_t interval);

/**
 * @brief Function for getting NTC auto measurement interval during charging.
 *
 * @param[in]  p_instance Pointer to the ADC instance.
 * @param[out] p_interval Pointer to interval for NTC auto measurement during charging.
 *
 * @retval NPMX_SUCCESS  Operation performed successfully.
 * @retval NPMX_ERROR_IO Error using IO bus line.
 */
npmx_error_t npmx_adc_ntc_meas_interval_get(npmx_adc_t *                   p_instance,
                                            npmx_adc_ntc_meas_interval_t * p_interval);

/**
 * @brief Function for setting the die temperature measurement interval during charging.
 *
 * @param[in] p_instance Pointer to the ADC instance.
 * @param[in] interval   Interval value.
 *
 * @retval NPMX_SUCCESS  Operation performed successfully.
 * @retval NPMX_ERROR_IO Error using IO bus line.
 */
npmx_error_t npmx_adc_die_temp_meas_interval_set(npmx_adc_t *                      p_instance,
                                                 npmx_adc_die_temp_meas_interval_t interval);

/**
 * @brief Function for getting die temperature auto measurement interval during charging.
 *
 * @param[in]  p_instance Pointer to the ADC instance.
 * @param[out] p_interval Pointer to interval for die temperature auto measurement during charging.
 *
 * @retval NPMX_SUCCESS  Operation performed successfully.
 * @retval NPMX_ERROR_IO Error using IO bus line.
 */
npmx_error_t npmx_adc_die_temp_meas_interval_get(npmx_adc_t *                        p_instance,
                                                 npmx_adc_die_temp_meas_interval_t * p_interval);

/**
 * @brief Function for setting the delay of battery voltage measurement after going into sleep mode.
 *
 * @param[in] p_instance Pointer to the ADC instance.
 * @param[in] delay      Delay value in ms, min 2, max 255.
 *
 * @retval NPMX_SUCCESS  Operation performed successfully.
 * @retval NPMX_ERROR_IO Error using IO bus line.
 */
npmx_error_t npmx_adc_vbat_meas_delay_set(npmx_adc_t const * p_instance, uint8_t delay);

/**
 * @brief Function for getting the delay of battery voltage measurement after going into sleep mode.
 *
 * @param[in]  p_instance Pointer to the ADC instance.
 * @param[out] p_delay    Pointer to read delay value.
 *
 * @retval NPMX_SUCCESS  Operation performed successfully.
 * @retval NPMX_ERROR_IO Error using IO bus line.
 */
npmx_error_t npmx_adc_vbat_meas_delay_get(npmx_adc_t const * p_instance, uint8_t * p_delay);

/** @} */

#ifdef __cplusplus
}
#endif

#endif /* NPMX_ADC_H__ */
