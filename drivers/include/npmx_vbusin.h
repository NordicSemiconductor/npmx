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

#ifndef NPMX_VBUSIN_H__
#define NPMX_VBUSIN_H__

#include <npmx.h>

#ifdef __cplusplus
extern "C" {
#endif

/**
 * @defgroup npmx_vbusin VBUSIN
 * @{
 * @ingroup npmx_drivers
 * @brief   VBUS input (VBUSIN) peripheral driver.
 */

/** @brief VBUSIN tasks. */
typedef enum
{
    NPMX_VBUSIN_TASK_APPLY_CURRENT_LIMIT, ///< Applying the selected current limit set with @ref npmx_vbusin_current_limit_set().
} npmx_vbusin_task_t;

/** @brief Available current limits for VBUS. */
typedef enum
{
    NPMX_VBUSIN_CURRENT_100_MA  = VBUSIN_VBUSINILIM0_VBUSINILIM0_100MA,  ///< 100 mA.
    NPMX_VBUSIN_CURRENT_500_MA  = VBUSIN_VBUSINILIM0_VBUSINILIM0_500MA,  ///< 500 mA.
    NPMX_VBUSIN_CURRENT_600_MA  = VBUSIN_VBUSINILIM0_VBUSINILIM0_600MA,  ///< 600 mA.
    NPMX_VBUSIN_CURRENT_700_MA  = VBUSIN_VBUSINILIM0_VBUSINILIM0_700MA,  ///< 700 mA.
    NPMX_VBUSIN_CURRENT_800_MA  = VBUSIN_VBUSINILIM0_VBUSINILIM0_800MA,  ///< 800 mA.
    NPMX_VBUSIN_CURRENT_900_MA  = VBUSIN_VBUSINILIM0_VBUSINILIM0_900MA,  ///< 900 mA.
    NPMX_VBUSIN_CURRENT_1000_MA = VBUSIN_VBUSINILIM0_VBUSINILIM0_1000MA, ///< 1000 mA.
    NPMX_VBUSIN_CURRENT_1100_MA = VBUSIN_VBUSINILIM0_VBUSINILIM0_1100MA, ///< 1100 mA.
    NPMX_VBUSIN_CURRENT_1200_MA = VBUSIN_VBUSINILIM0_VBUSINILIM0_1200MA, ///< 1200 mA.
    NPMX_VBUSIN_CURRENT_1300_MA = VBUSIN_VBUSINILIM0_VBUSINILIM0_1300MA, ///< 1300 mA.
    NPMX_VBUSIN_CURRENT_1400_MA = VBUSIN_VBUSINILIM0_VBUSINILIM0_1400MA, ///< 1400 mA.
    NPMX_VBUSIN_CURRENT_1500_MA = VBUSIN_VBUSINILIM0_VBUSINILIM0_1500MA, ///< 1500 mA.
    NPMX_VBUSIN_CURRENT_DEFAULT = NPMX_VBUSIN_CURRENT_500_MA,            ///< Default current.
    NPMX_VBUSIN_CURRENT_MAX     = NPMX_VBUSIN_CURRENT_1500_MA,           ///< Maximum current.
    NPMX_VBUSIN_CURRENT_INVALID = NPMX_INVALID_ENUM_VALUE,               ///< Invalid current.
} npmx_vbusin_current_t;

/** @brief Available CCx pins status connections. */
typedef enum
{
    NPMX_VBUSIN_CC_NOT_CONNECTED  = VBUSIN_USBCDETECTSTATUS_VBUSINCC1CMP_NOCONNECTION, ///< No CCx connection.
    NPMX_VBUSIN_CC_DEFAULT        = VBUSIN_USBCDETECTSTATUS_VBUSINCC1CMP_DEFAULTUSB,   ///< Default USB 100/500 mA.
    NPMX_VBUSIN_CC_HIGH_POWER_1A5 = VBUSIN_USBCDETECTSTATUS_VBUSINCC1CMP_1A5HIGHPOWER, ///< 1.5 A High Power.
    NPMX_VBUSIN_CC_HIGH_POWER_3A0 = VBUSIN_USBCDETECTSTATUS_VBUSINCC1CMP_3AHIGHPOWER,  ///< 3.0 A High Power.
    NPMX_VBUSIN_CC_INVALID        = NPMX_INVALID_ENUM_VALUE,                           ///< Invalid CCx pins status connection.
} npmx_vbusin_cc_t;

/** @brief VBUS status flag mask. */
typedef enum
{
    NPMX_VBUSIN_STATUS_CONNECTED_MASK     = VBUSIN_VBUSINSTATUS_VBUSINPRESENT_Msk,           ///< VBUS detected.
    NPMX_VBUSIN_STATUS_CURRENT_LIMIT_MASK = VBUSIN_VBUSINSTATUS_VBUSINCURRLIMACTIVE_Msk,     ///< VBUS current limit detected.
    NPMX_VBUSIN_STATUS_OVER_VOLTAGE_MASK  = VBUSIN_VBUSINSTATUS_VBUSINOVRPROTACTIVE_Msk,     ///< VBUS over voltage protection active.
    NPMX_VBUSIN_STATUS_UNDER_VOLTAGE_MASK = VBUSIN_VBUSINSTATUS_VBUSINUNDERVOLTAGE_Msk,      ///< VBUS under voltage detected.
    NPMX_VBUSIN_STATUS_SUSPEND_MODE_MASK  = VBUSIN_VBUSINSTATUS_VBUSINSUSPENDMODEACTIVE_Msk, ///< VBUS suspended.
} npmx_vbusin_status_mask_t;

/** @brief Data structure of the VBUSIN driver instance. */
typedef struct
{
    npmx_backend_instance_t * p_backend; ///< Pointer to backend instance.
} npmx_vbusin_t;

/**
 * @brief Function for returning VBUSIN instance based on index.
 *
 * @param[in] p_pmic Pointer to the PMIC instance.
 * @param[in] idx    Index of the VBUSIN instance.
 *
 * @return Pointer to the VBUSIN instance.
 */
npmx_vbusin_t * npmx_vbusin_get(npmx_instance_t * p_pmic, uint8_t idx);

/**
 * @brief Function for converting milliamperes to @ref npmx_vbusin_current_t enumeration.
 *
 * @param[in] milliamperes Current in milliamperes to be converted
 *                         into @ref npmx_vbusin_current_t enumeration.
 *
 * @return Result of conversion. @ref NPMX_VBUSIN_CURRENT_INVALID if given current is not
 *         represented in enumeration.
 */
npmx_vbusin_current_t npmx_vbusin_current_convert(uint32_t milliamperes);

/**
 * @brief Function for converting @ref npmx_vbusin_current_t enumeration to milliamperes.
 *
 * @param[in] enum_value Current defined as @ref npmx_vbusin_current_t enumeration to be
 *                       converted into milliamperes.
 *
 * @return Result of conversion.
 */
uint32_t npmx_vbusin_current_convert_to_ma(npmx_vbusin_current_t enum_value);

/**
 * @brief Function for mapping @ref npmx_vbusin_cc_t enumeration values to string.
 *
 * @param[in] enum_value CC status defined as @ref npmx_vbusin_cc_t enumeration to be
 *                       mapped to string.
 *
 * @return Result of conversion.
 */
const char * const npmx_vbusin_cc_status_map_to_string(npmx_vbusin_cc_t enum_value);

/**
 * @brief Function for activating the specified VBUSIN task.
 *
 * @param p_instance Pointer to the VBUSIN instance.
 * @param task       Task to be activated.
 *
 * @retval NPMX_SUCCESS  Operation performed successfully.
 * @retval NPMX_ERROR_IO Error using IO bus line.
 */
npmx_error_t npmx_vbusin_task_trigger(npmx_vbusin_t const * p_instance, npmx_vbusin_task_t task);

/**
 * @brief Function for setting the current limit for VBUS.
 *
 * @param[in] p_instance    Pointer to the VBUSIN instance.
 * @param[in] current_limit Current limit to set.
 *
 * @retval NPMX_SUCCESS  Operation performed successfully.
 * @retval NPMX_ERROR_IO Error using IO bus line.
 */
npmx_error_t npmx_vbusin_current_limit_set(npmx_vbusin_t const * p_instance,
                                           npmx_vbusin_current_t current_limit);

/**
 * @brief Function for getting the current limit for VBUS.
 *
 * @param[in]  p_instance      Pointer to the VBUSIN instance.
 * @param[out] p_current_limit Pointer to the current limit variable.
 *
 * @retval NPMX_SUCCESS  Operation performed successfully.
 * @retval NPMX_ERROR_IO Error using IO bus line.
 */
npmx_error_t npmx_vbusin_current_limit_get(npmx_vbusin_t const *   p_instance,
                                           npmx_vbusin_current_t * p_current_limit);

/**
 * @brief Function for enabling and disabling the suspend mode.
 *
 * @param[in] p_instance Pointer to the VBUSIN instance.
 * @param[in] enable     True if device is to enter the suspend mode, false if it is to exit from the suspend mode.
 *
 * @retval NPMX_SUCCESS  Operation performed successfully.
 * @retval NPMX_ERROR_IO Error using IO bus line.
 */
npmx_error_t npmx_vbusin_suspend_mode_enable_set(npmx_vbusin_t const * p_instance, bool enable);

/**
 * @brief Function for reading the suspend mode.
 *
 * @param[in]  p_instance Pointer to the VBUSIN instance.
 * @param[out] p_enable   Pointer to the suspend mode variable.
 *
 * @retval NPMX_SUCCESS  Operation performed successfully.
 * @retval NPMX_ERROR_IO Error using IO bus line.
 */
npmx_error_t npmx_vbusin_suspend_mode_enable_get(npmx_vbusin_t const * p_instance, bool * p_enable);

/**
 * @brief Function for reading status of USB CCx pins.
 *
 * @param[in]  p_instance Pointer to the VBUSIN instance.
 * @param[out] p_cc1      Pointer to the CC1 status variable.
 * @param[out] p_cc2      Pointer to the CC2 status variable.
 *
 * @retval NPMX_SUCCESS  Operation performed successfully.
 * @retval NPMX_ERROR_IO Error using IO bus line.
 */
npmx_error_t npmx_vbusin_cc_status_get(npmx_vbusin_t const * p_instance,
                                       npmx_vbusin_cc_t *    p_cc1,
                                       npmx_vbusin_cc_t *    p_cc2);

/**
 * @brief Function for reading VBUS status register.
 *
 * @param[in]  p_instance    Pointer to the VBUSIN instance.
 * @param[out] p_status_mask Pointer to the VBUS status mask composed of values from @ref npmx_vbusin_status_mask_t.
 *
 * @retval NPMX_SUCCESS  Operation performed successfully.
 * @retval NPMX_ERROR_IO Error using IO bus line.
 */
npmx_error_t npmx_vbusin_vbus_status_get(npmx_vbusin_t const * p_instance, uint8_t * p_status_mask);

/** @} */

#ifdef __cplusplus
}
#endif

#endif /* NPMX_VBUSIN_H__ */
