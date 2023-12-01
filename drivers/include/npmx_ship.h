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

#ifndef NPMX_SHIP_H__
#define NPMX_SHIP_H__

#include <npmx.h>

#ifdef __cplusplus
extern "C" {
#endif

/**
 * @defgroup npmx_ship SHIP
 * @{
 * @ingroup npmx_drivers
 * @brief   Ship and hibernate modes peripheral driver.
 */

/** @brief Data structure of the SHIP driver instance. */
typedef struct
{
    npmx_backend_t * p_backend;            ///< Pointer to backend instance.
    bool             ship_button_inverted; ///< Flag set when polarity of SHPHLD button is inverted. False by default.
} npmx_ship_t;

/** @brief Ship and hibernate tasks. */
typedef enum
{
    NPMX_SHIP_TASK_HIBERNATE,       ///< Task enter hibernate.
    NPMX_SHIP_TASK_CONFIG_SHIPHOLD, ///< Task ship hold configuration.
    NPMX_SHIP_TASK_SHIPMODE,        ///< Task enter ship mode.
    NPMX_SHIP_TASK_CONFIG_RESET,    ///< Task request reset configuration.
    NPMX_SHIP_TASK_COUNT,           ///< Tasks count.
} npmx_ship_task_t;

/** @brief SHPHLD duration button must be pressed to exit ship or hibernate mode. */
typedef enum
{
    NPMX_SHIP_TIME_16_MS   = SHPHLD_SHPHLDCONFIG_SHPHLDTIM_16ms,   ///< 16 ms.
    NPMX_SHIP_TIME_32_MS   = SHPHLD_SHPHLDCONFIG_SHPHLDTIM_32ms,   ///< 32 ms.
    NPMX_SHIP_TIME_64_MS   = SHPHLD_SHPHLDCONFIG_SHPHLDTIM_64ms,   ///< 64 ms.
    NPMX_SHIP_TIME_96_MS   = SHPHLD_SHPHLDCONFIG_SHPHLDTIM_96ms,   ///< 96 ms.
    NPMX_SHIP_TIME_304_MS  = SHPHLD_SHPHLDCONFIG_SHPHLDTIM_304ms,  ///< 304 ms.
    NPMX_SHIP_TIME_608_MS  = SHPHLD_SHPHLDCONFIG_SHPHLDTIM_608ms,  ///< 608 ms.
    NPMX_SHIP_TIME_1008_MS = SHPHLD_SHPHLDCONFIG_SHPHLDTIM_1008ms, ///< 1008 ms.
    NPMX_SHIP_TIME_3008_MS = SHPHLD_SHPHLDCONFIG_SHPHLDTIM_3008ms, ///< 3008 ms.
    NPMX_SHIP_TIME_COUNT,                                          ///< Possible durations count.
    NPMX_SHIP_TIME_MIN     = NPMX_SHIP_TIME_16_MS,                 ///< Minimum time.
    NPMX_SHIP_TIME_DEFAULT = NPMX_SHIP_TIME_96_MS,                 ///< Default time.
    NPMX_SHIP_TIME_MAX     = NPMX_SHIP_TIME_3008_MS,               ///< Maximum time.
    NPMX_SHIP_TIME_INVALID = NPMX_INVALID_ENUM_VALUE,              ///< Invalid time.
} npmx_ship_time_t;

/** @brief Configuration structure for ship hold. */
typedef struct
{
    npmx_ship_time_t time;              ///< Time required to exit from the ship or the hibernate mode.
    bool             inverted_polarity; ///< True if the device is to invert the SHPHLD button active status, false otherwise. By default, the button is active in the LOW state.
} npmx_ship_config_t;

/** @brief Configuration structure for reset button. */
typedef struct
{
    bool long_press;  ///< True if device is to use long press (10 s) button, false otherwise.
    bool two_buttons; ///< True if device is to use two buttons (SHPHLD and GPIO0) to perform long press reset, false if only one button should be used (SHPHLD).
} npmx_ship_reset_config_t;

/**
 * @brief Function for returning SHIP instance based on index.
 *
 * @param[in] p_pmic Pointer to the SHIP instance.
 * @param[in] idx    Index of the SHIP instance.
 *
 * @return Pointer to the SHIP instance.
 */
npmx_ship_t * npmx_ship_get(npmx_instance_t * p_pmic, uint8_t idx);

/**
 * @brief Function for converting milliseconds to @ref npmx_ship_time_t enumeration.
 *
 * @param[in] time_ms Time in milliseconds to be converted into @ref npmx_ship_time_t enumeration.
 *
 * @return Result of conversion. @ref NPMX_SHIP_TIME_INVALID if given time is not
 *         represented in enumeration.
 */
npmx_ship_time_t npmx_ship_time_convert(uint32_t time_ms);

/**
 * @brief Function for converting @ref npmx_ship_time_t enumeration to milliseconds.
 *
 * @param[in]  enum_value Time defined as @ref npmx_ship_time_t enumeration to be converted into milliseconds.
 * @param[out] p_val      Pointer to the variable that stores the conversion result.
 *
 * @retval true  Conversion is valid.
 * @retval false Conversion is invalid - an invalid argument was passed to the function.
 */
bool npmx_ship_time_convert_to_ms(npmx_ship_time_t enum_value, uint32_t * p_val);

/**
 * @brief Function for activating the specified SHIP task.
 *
 * @note The wakeup timer needs to be configured before entering the hibernate mode.
 *
 * @param p_instance Pointer to the SHIP instance.
 * @param task       Task to be activated.
 *
 * @retval NPMX_SUCCESS  Operation performed successfully.
 * @retval NPMX_ERROR_IO Error using IO bus line.
 */
npmx_error_t npmx_ship_task_trigger(npmx_ship_t const * p_instance, npmx_ship_task_t task);

/**
 * @brief Function for setting the ship hold configuration.
 *
 * @param[in] p_instance Pointer to the SHIP instance.
 * @param[in] p_config   Pointer to the configuration of the SHIP to be applied.
 *
 * @retval NPMX_SUCCESS  Operation performed successfully.
 * @retval NPMX_ERROR_IO Error using IO bus line.
 */
npmx_error_t npmx_ship_config_set(npmx_ship_t * p_instance, npmx_ship_config_t const * p_config);

/**
 * @brief Function for reading the ship hold configuration.
 *
 * @param[in]  p_instance Pointer to the SHIP instance.
 * @param[out] p_config   Pointer to the SHIP configuration structure.
 *
 * @retval NPMX_SUCCESS  Operation performed successfully.
 * @retval NPMX_ERROR_IO Error using IO bus line.
 */
npmx_error_t npmx_ship_config_get(npmx_ship_t * p_instance, npmx_ship_config_t * p_config);

/**
 * @brief Function for checking whether the ship button is active.
 *
 * @param[in]  p_instance Pointer to the SHIP instance.
 * @param[out] p_active   Pointer to the variable to be filled with ship button status.
 *                        True if button is active, false otherwise.
 *
 * @retval NPMX_SUCCESS  Operation performed successfully.
 * @retval NPMX_ERROR_IO Error using IO bus line.
 */
npmx_error_t npmx_ship_gpio_status_check(npmx_ship_t const * p_instance, bool * p_active);

/**
 * @brief Function for setting long press reset button configuration.
 *
 * @param[in] p_instance Pointer to the SHIP instance.
 * @param[in] p_config   Pointer to the configuration of the reset button to be applied.
 *
 * @retval NPMX_SUCCESS  Operation performed successfully.
 * @retval NPMX_ERROR_IO Error using IO bus line.
 */
npmx_error_t npmx_ship_reset_config_set(npmx_ship_t const *              p_instance,
                                        npmx_ship_reset_config_t const * p_config);

/**
 * @brief Function for reading the long press reset button configuration.
 *
 * @param[in]  p_instance Pointer to the SHIP instance.
 * @param[out] p_config   Pointer to the reset button configuration structure.
 *
 * @retval NPMX_SUCCESS  Operation performed successfully.
 * @retval NPMX_ERROR_IO Error using IO bus line.
 */
npmx_error_t npmx_ship_reset_config_get(npmx_ship_t const *        p_instance,
                                        npmx_ship_reset_config_t * p_config);

/** @} */

#ifdef __cplusplus
}
#endif

#endif /* NPMX_SHIP_H__ */
