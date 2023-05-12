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

#ifndef NPMX_LED_H__
#define NPMX_LED_H__

#include <npmx.h>

#ifdef __cplusplus
extern "C" {
#endif

/**
 * @defgroup npmx_led LED
 * @{
 * @ingroup npmx_drivers
 * @brief   LED peripheral driver.
 */

/** @brief Possible LED working modes. */
typedef enum
{
    NPMX_LED_MODE_ERROR    = LEDDRV_LEDDRV1MODESEL_LEDDRV1MODESEL_ERROR,    ///< Charging error indicator.
    NPMX_LED_MODE_CHARGING = LEDDRV_LEDDRV1MODESEL_LEDDRV1MODESEL_CHARGING, ///< Charging indicator (ON during charging).
    NPMX_LED_MODE_HOST     = LEDDRV_LEDDRV1MODESEL_LEDDRV1MODESEL_HOST,     ///< Driven from register LEDDRV_x_SET/CLR.
    NPMX_LED_MODE_NOTUSED  = LEDDRV_LEDDRV1MODESEL_LEDDRV1MODESEL_NOTUSED,  ///< Not used.
} npmx_led_mode_t;

/** @brief Data structure of the LED driver instance. */
typedef struct
{
    npmx_backend_instance_t * p_backend; ///< Pointer to backend instance.
    uint8_t                   hw_index;  ///< Hardware index of LED instance.
} npmx_led_t;

/**
 * @brief Function for returning LED instance based on index.
 *
 * @param[in] p_pmic Pointer to the PMIC instance.
 * @param[in] idx    Index of the LED instance.
 *
 * @return Pointer to the LED instance.
 */
npmx_led_t * npmx_led_get(npmx_instance_t * p_pmic, uint8_t idx);

/**
 * @brief Function for setting the mode of specified LED instance.
 *
 * @param[in] p_instance Pointer to the LED instance.
 * @param[in] mode       Mode of the LED to be set.
 *
 * @retval NPMX_SUCCESS  Operation performed successfully.
 * @retval NPMX_ERROR_IO Error using IO bus line.
 */
npmx_error_t npmx_led_mode_set(npmx_led_t const * p_instance, npmx_led_mode_t mode);

/**
 * @brief Function for reading the mode of specified LED instance.
 *
 * @param[in] p_instance Pointer to the LED instance.
 * @param[in] p_mode     Pointer to the mode of the LED.
 *
 * @retval NPMX_SUCCESS  Operation performed successfully.
 * @retval NPMX_ERROR_IO Error using IO bus line.
 */
npmx_error_t npmx_led_mode_get(npmx_led_t const * p_instance, npmx_led_mode_t * p_mode);

/**
 * @brief Function for setting the state of specified LED instance.
 *
 * @note This function can be called only after calling @ref npmx_led_mode_set() with NPMX_LED_MODE_HOST.
 *
 * @param[in] p_instance Pointer to the LED instance.
 * @param[in] state      True to enable LED current source, false to disable.
 *
 * @retval NPMX_SUCCESS  Operation performed successfully.
 * @retval NPMX_ERROR_IO Error using IO bus line.
 */
npmx_error_t npmx_led_state_set(npmx_led_t const * p_instance, bool state);

/** @} */

#ifdef __cplusplus
}
#endif

#endif /* NPMX_LED_H__ */
