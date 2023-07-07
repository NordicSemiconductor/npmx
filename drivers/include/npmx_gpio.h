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

#ifndef NPMX_GPIO_H__
#define NPMX_GPIO_H__

#include <npmx.h>

#ifdef __cplusplus
extern "C" {
#endif

/**
 * @defgroup npmx_gpio GPIO
 * @{
 * @ingroup npmx_drivers
 * @brief   GPIO peripheral driver.
 */

/** @brief Configuration for GPIO mode selection. */
typedef enum
{
    NPMX_GPIO_MODE_INPUT              = GPIOS_GPIOMODE0_GPIOMODE_GPIINPUT,     ///< GPI Input.
    NPMX_GPIO_MODE_INPUT_OVERRIDE_1   = GPIOS_GPIOMODE0_GPIOMODE_GPILOGIC1,    ///< GPI Logic1.
    NPMX_GPIO_MODE_INPUT_OVERRIDE_0   = GPIOS_GPIOMODE0_GPIOMODE_GPILOGIC0,    ///< GPI Logic0.
    NPMX_GPIO_MODE_INPUT_RISING_EDGE  = GPIOS_GPIOMODE0_GPIOMODE_GPIEVENTRISE, ///< GPI Rising Edge Event.
    NPMX_GPIO_MODE_INPUT_FALLING_EDGE = GPIOS_GPIOMODE0_GPIOMODE_GPIEVENTFALL, ///< GPI Falling Edge Event.
    NPMX_GPIO_MODE_OUTPUT_IRQ         = GPIOS_GPIOMODE0_GPIOMODE_GPOIRQ,       ///< GPO Interrupt.
    NPMX_GPIO_MODE_OUTPUT_RESET       = GPIOS_GPIOMODE0_GPIOMODE_GPORESET,     ///< GPO Reset.
    NPMX_GPIO_MODE_OUTPUT_PLW         = GPIOS_GPIOMODE0_GPIOMODE_GPOPLW,       ///< GPO PwrLossWarn.
    NPMX_GPIO_MODE_OUTPUT_OVERRIDE_1  = GPIOS_GPIOMODE0_GPIOMODE_GPOLOGIC1,    ///< GPO Logic1.
    NPMX_GPIO_MODE_OUTPUT_OVERRIDE_0  = GPIOS_GPIOMODE0_GPIOMODE_GPOLOGIC0,    ///< GPO Logic0.
    NPMX_GPIO_MODE_COUNT,                                                      ///< GPIO modes count.
    NPMX_GPIO_MODE_INVALID            = NPMX_INVALID_ENUM_VALUE,               ///< Invalid GPIO mode.
} npmx_gpio_mode_t;

/** @brief Configuration for GPIO drive current. */
typedef enum
{
    NPMX_GPIO_DRIVE_1_MA    = GPIOS_GPIODRIVE1_GPIODRIVE_1MA, ///< 1 mA.
    NPMX_GPIO_DRIVE_6_MA    = GPIOS_GPIODRIVE1_GPIODRIVE_6MA, ///< 6 mA.
    NPMX_GPIO_DRIVE_COUNT,                                    ///< GPIO drive currents count.
    NPMX_GPIO_DRIVE_MIN     = NPMX_GPIO_DRIVE_1_MA,           ///< Minimum current.
    NPMX_GPIO_DRIVE_DEFAULT = NPMX_GPIO_DRIVE_1_MA,           ///< Default current.
    NPMX_GPIO_DRIVE_MAX     = NPMX_GPIO_DRIVE_6_MA,           ///< Maximum current.
    NPMX_GPIO_DRIVE_INVALID = NPMX_INVALID_ENUM_VALUE,        ///< Invalid current.
} npmx_gpio_drive_t;

/** @brief Configuration for GPIO pull resistors. By default, all GPIOs are in NPMX_GPIO_PULL_DOWN mode. */
typedef enum
{
    NPMX_GPIO_PULL_DOWN,                              ///< GPIO pull-down enable.
    NPMX_GPIO_PULL_UP,                                ///< GPIO pull-up enable.
    NPMX_GPIO_PULL_NONE,                              ///< GPIO pull-down and pull-up disable.
    NPMX_GPIO_PULL_COUNT,                             ///< GPIO pull configs count.
    NPMX_GPIO_PULL_INVALID = NPMX_INVALID_ENUM_VALUE, ///< Invalid GPIO pull configuration.
} npmx_gpio_pull_t;

/** @brief Data structure of the GPIO driver instance. */
typedef struct
{
    npmx_backend_t * p_backend; ///< Pointer to backend instance.
    uint8_t          hw_index;  ///< Hardware index of GPIO instance.
} npmx_gpio_t;

/** @brief Configuration structure for GPIO. */
typedef struct
{
    npmx_gpio_mode_t  mode;       ///< Configuration for GPIO mode selection.
    npmx_gpio_drive_t drive;      ///< GPIO drive current.
    npmx_gpio_pull_t  pull;       ///< GPIO pull mode.
    bool              open_drain; ///< Enable GPIO open drain.
    bool              debounce;   ///< Enable GPIO debounce.
} npmx_gpio_config_t;

/**
 * @brief Function for returning GPIO instance based on index.
 *
 * @param[in] p_pmic Pointer to the PMIC instance.
 * @param[in] idx    Index of the GPIO instance.
 *
 * @return Pointer to the GPIO instance.
 */
npmx_gpio_t * npmx_gpio_get(npmx_instance_t * p_pmic, uint8_t idx);

/**
 * @brief Function for converting milliamperes to @ref npmx_gpio_drive_t enumeration.
 *
 * @param[in] milliamperes Current in milliamperes to be converted
 *                         into @ref npmx_gpio_drive_t enumeration.
 *
 * @return Result of conversion. @ref NPMX_GPIO_DRIVE_INVALID if given current is not
 *         represented in enumeration.
 */
npmx_gpio_drive_t npmx_gpio_drive_convert(uint32_t milliamperes);

/**
 * @brief Function for converting @ref npmx_gpio_drive_t enumeration to milliamperes.
 *
 * @param[in]  enum_value Current defined as @ref npmx_gpio_drive_t enumeration to be
 *                        converted into milliamperes.
 * @param[out] p_val      Pointer to the variable that stores the conversion result.
 *
 * @retval true  Conversion is valid.
 * @retval false Conversion is invalid - an invalid argument was passed to the function.
 */
bool npmx_gpio_drive_convert_to_ma(npmx_gpio_drive_t enum_value, uint32_t * p_val);

/**
 * @brief Function for configuring GPIO.
 *
 * @param[in] p_instance Pointer to the GPIO instance.
 * @param[in] p_config   Pointer to the configuration of GPIO to be applied.
 *
 * @retval NPMX_SUCCESS  Operation performed successfully.
 * @retval NPMX_ERROR_IO Error using IO bus line.
 */
npmx_error_t npmx_gpio_config_set(npmx_gpio_t const *        p_instance,
                                  npmx_gpio_config_t const * p_config);

/**
 * @brief Function for reading GPIO configuration.
 *
 * @param[in]  p_instance Pointer to the GPIO instance.
 * @param[out] p_config   Pointer to the configuration of GPIO.
 *
 * @retval NPMX_SUCCESS  Operation performed successfully.
 * @retval NPMX_ERROR_IO Error using IO bus line.
 */
npmx_error_t npmx_gpio_config_get(npmx_gpio_t const * p_instance, npmx_gpio_config_t * p_config);

/**
 * @brief Function for setting GPIO mode.
 *
 * @param[in] p_instance Pointer to the GPIO instance.
 * @param[in] mode       Mode of GPIO to set.
 *
 * @retval NPMX_SUCCESS  Operation performed successfully.
 * @retval NPMX_ERROR_IO Error using IO bus line.
 */
npmx_error_t npmx_gpio_mode_set(npmx_gpio_t const * p_instance, npmx_gpio_mode_t mode);

/**
 * @brief Function for reading GPIO mode.
 *
 * @param[in]  p_instance Pointer to the GPIO instance.
 * @param[out] p_mode     Pointer to mode of GPIO.
 *
 * @retval NPMX_SUCCESS  Operation performed successfully.
 * @retval NPMX_ERROR_IO Error using IO bus line.
 */
npmx_error_t npmx_gpio_mode_get(npmx_gpio_t const * p_instance, npmx_gpio_mode_t * p_mode);

/**
 * @brief Function for checking GPIO status of specified GPIO pin.
 *
 * @param[in]  p_instance Pointer to the GPIO instance.
 * @param[out] p_status   Pointer to the status of GPIO. True if specified GPIO is in a high state, false otherwise.
 *
 * @retval NPMX_SUCCESS  Operation performed successfully.
 * @retval NPMX_ERROR_IO Error using IO bus line.
 */
npmx_error_t npmx_gpio_status_check(npmx_gpio_t const * p_instance, bool * p_status);

/** @} */

#ifdef __cplusplus
}
#endif

#endif // NPMX_GPIO_H__
