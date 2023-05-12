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

#ifndef NPMX_POF_H__
#define NPMX_POF_H__

#include <npmx.h>

#ifdef __cplusplus
extern "C" {
#endif

/**
 * @defgroup npmx_pof POF
 * @{
 * @ingroup npmx_drivers
 * @brief   Power fail (POF) comparator peripheral driver.
 */

/** @brief POF warning status. */
typedef enum
{
    NPMX_POF_STATUS_DISABLE = POF_POFCONFIG_POFENA_OFF,     ///< Disable POF warning.
    NPMX_POF_STATUS_ENABLE  = POF_POFCONFIG_POFENA_ENABLED, ///< Enable POF warning.
} npmx_pof_status_t;

/** @brief POF warning polarity. */
typedef enum
{
    NPMX_POF_POLARITY_HIGH = POF_POFCONFIG_POFWARNPOLARITY_HIACTIVE, ///< Active in high state.
    NPMX_POF_POLARITY_LOW  = POF_POFCONFIG_POFWARNPOLARITY_LOACTIVE, ///< Active in low state.
} npmx_pof_polarity_t;

/** @brief POF warning voltage threshold values. */
typedef enum
{
    NPMX_POF_THRESHOLD_2V6     = POF_POFCONFIG_POFVSYSTHRESHSEL_2V6, ///< 2.6 V.
    NPMX_POF_THRESHOLD_2V7     = POF_POFCONFIG_POFVSYSTHRESHSEL_2V7, ///< 2.7 V.
    NPMX_POF_THRESHOLD_2V8     = POF_POFCONFIG_POFVSYSTHRESHSEL_2V8, ///< 2.8 V.
    NPMX_POF_THRESHOLD_2V9     = POF_POFCONFIG_POFVSYSTHRESHSEL_2V9, ///< 2.9 V.
    NPMX_POF_THRESHOLD_3V0     = POF_POFCONFIG_POFVSYSTHRESHSEL_3V0, ///< 3.0 V.
    NPMX_POF_THRESHOLD_3V1     = POF_POFCONFIG_POFVSYSTHRESHSEL_3V1, ///< 3.1 V.
    NPMX_POF_THRESHOLD_3V2     = POF_POFCONFIG_POFVSYSTHRESHSEL_3V2, ///< 3.2 V.
    NPMX_POF_THRESHOLD_3V3     = POF_POFCONFIG_POFVSYSTHRESHSEL_3V3, ///< 3.3 V.
    NPMX_POF_THRESHOLD_3V4     = POF_POFCONFIG_POFVSYSTHRESHSEL_3V4, ///< 3.4 V.
    NPMX_POF_THRESHOLD_3V5     = POF_POFCONFIG_POFVSYSTHRESHSEL_3V5, ///< 3.5 V.
    NPMX_POF_THRESHOLD_DEFAULT = NPMX_POF_THRESHOLD_2V8,             ///< Default voltage.
    NPMX_POF_THRESHOLD_MAX     = NPMX_POF_THRESHOLD_3V5,             ///< Maximum voltage.
    NPMX_POF_THRESHOLD_INVALID = NPMX_INVALID_ENUM_VALUE,            ///< Invalid voltage.
} npmx_pof_threshold_t;

/** @brief Data structure of the POF driver instance. */
typedef struct
{
    npmx_backend_instance_t * p_backend; ///< Pointer to backend instance.
} npmx_pof_t;

/** @brief Configuration structure for POF comparator. */
typedef struct
{
    npmx_pof_status_t    status;    ///< Enable status of POF.
    npmx_pof_threshold_t threshold; ///< Threshold at which the POF will trigger.
    npmx_pof_polarity_t  polarity;  ///< Polarity of selected GPIO POF signal trigger.
} npmx_pof_config_t;

/**
 * @brief Function for returning POF instance based on index.
 *
 * @param[in] p_pmic Pointer to the PMIC instance.
 * @param[in] idx    Index of the POF instance.
 *
 * @return Pointer to the POF instance.
 */
npmx_pof_t * npmx_pof_get(npmx_instance_t * p_pmic, uint8_t idx);

/**
 * @brief Function for converting millivolts to @ref npmx_pof_threshold_t enumeration.
 *
 * @param[in] millivolts Voltage in millivolts to be converted into @ref npmx_pof_threshold_t enumeration.
 *
 * @return Result of conversion. @ref NPMX_POF_THRESHOLD_INVALID if given voltage is not
 *         represented in enumeration.
 */
npmx_pof_threshold_t npmx_pof_threshold_convert(uint32_t millivolts);

/**
 * @brief Function for converting @ref npmx_pof_threshold_t enumeration to millivolts.
 *
 * @param[in] enum_value Voltage defined as @ref npmx_pof_threshold_t enumeration to be converted into millivolts.
 *
 * @return Result of conversion.
 */
uint32_t npmx_pof_threshold_convert_to_mv(npmx_pof_threshold_t enum_value);

/**
 * @brief Function for setting configuration and enabling POF comparator.
 *
 * @note Before using this function, configure one GPIO as a power loss warning output (@ref NPMX_GPIO_MODE_OUTPUT_PLW).
 *
 * @param[in] p_instance Pointer to the POF instance.
 * @param[in] p_config   Pointer to the configuration of the POF to apply.
 *
 * @retval NPMX_SUCCESS  Operation performed successfully.
 * @retval NPMX_ERROR_IO Error using IO bus line.
 */
npmx_error_t npmx_pof_config_set(npmx_pof_t const * p_instance, npmx_pof_config_t const * p_config);

/**
 * @brief Function for reading the POF configuration.
 *
 * @param[in]  p_instance Pointer to the POF instance.
 * @param[out] p_config   Pointer to the POF configuration structure.
 *
 * @retval NPMX_SUCCESS  Operation performed successfully.
 * @retval NPMX_ERROR_IO Error using IO bus line.
 */
npmx_error_t npmx_pof_config_get(npmx_pof_t const * p_instance, npmx_pof_config_t * p_config);

/**
 * @brief Function for disabling POF comparator.
 *
 * @param[in] p_instance Pointer to the POF instance.
 *
 * @retval NPMX_SUCCESS  Operation performed successfully.
 * @retval NPMX_ERROR_IO Error using IO bus line.
 */
npmx_error_t npmx_pof_disable_set(npmx_pof_t const * p_instance);

/** @} */

#ifdef __cplusplus
}
#endif

#endif /* NPMX_POF_H__ */
