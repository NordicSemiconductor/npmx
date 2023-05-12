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

#ifndef NPMX_BUCK_H__
#define NPMX_BUCK_H__

#include <npmx.h>

#ifdef __cplusplus
extern "C" {
#endif

/**
 * @defgroup npmx_buck BUCK
 * @{
 * @ingroup npmx_drivers
 * @brief   Buck converter (DC/DC step-down converter) peripheral driver.
 */

/** @brief Data structure of the buck converter (BUCK) driver instance. */
typedef struct
{
    npmx_backend_instance_t * p_backend; ///< Pointer to backend instance.
    uint8_t                   hw_index;  ///< Hardware index of buck instance.
} npmx_buck_t;

/** @brief Buck tasks. */
typedef enum
{
    NPMX_BUCK_TASK_ENABLE,      ///< Enable buck.
    NPMX_BUCK_TASK_DISABLE,     ///< Disable buck.
    NPMX_BUCK_TASK_ENABLE_PWM,  ///< Enable PWM mode for buck.
    NPMX_BUCK_TASK_DISABLE_PWM, ///< Disable PWM mode for buck.
} npmx_buck_task_t;

/** @brief Possible converter modes of each buck. */
typedef enum
{
#if defined(BUCK_BUCKSTATUS_BUCK1MODE_AUTOMODE) || defined(__NPMX_DOXYGEN__)
    NPMX_BUCK_MODE_AUTO = BUCK_BUCKSTATUS_BUCK1MODE_AUTOMODE, ///< AUTO converter mode, PWM or PFM.
    NPMX_BUCK_MODE_PFM  = BUCK_BUCKSTATUS_BUCK1MODE_PFMMODE,  ///< Force PFM converter mode.
    NPMX_BUCK_MODE_PWM  = BUCK_BUCKSTATUS_BUCK1MODE_PWMMODE,  ///< Force PWM converter mode.
#else
    NPMX_BUCK_MODE_AUTO, ///< AUTO converter mode, PWM or PFM.
    NPMX_BUCK_MODE_PFM,  ///< Force PFM converter mode.
    NPMX_BUCK_MODE_PWM,  ///< Force PWM converter mode.
#endif
} npmx_buck_mode_t;

/** @brief The source of VOUT voltage reference.
 *         Output voltage can be controlled by external VSETx feedback pin
 *         or by software register value.
 */
typedef enum
{
    NPMX_BUCK_VOUT_SELECT_VSET_PIN = BUCK_BUCKSWCTRLSEL_BUCK1SWCTRLSEL_VSETANDSWCTRL, ///< Allow VSET pins to set VOUT.
    NPMX_BUCK_VOUT_SELECT_SOFTWARE = BUCK_BUCKSWCTRLSEL_BUCK1SWCTRLSEL_SWCTRL,        ///< Allow software to override VSET pin.
} npmx_buck_vout_select_t;

/** @brief Possible buck output voltages to be set. */
typedef enum
{
    NPMX_BUCK_VOLTAGE_1V0     = BUCK_BUCK1NORMVOUT_BUCK1NORMVOUT_1V,   ///< 1.0 V
    NPMX_BUCK_VOLTAGE_1V1     = BUCK_BUCK1NORMVOUT_BUCK1NORMVOUT_1V1,  ///< 1.1 V
    NPMX_BUCK_VOLTAGE_1V2     = BUCK_BUCK1NORMVOUT_BUCK1NORMVOUT_1V2,  ///< 1.2 V
    NPMX_BUCK_VOLTAGE_1V3     = BUCK_BUCK1NORMVOUT_BUCK1NORMVOUT_1V3,  ///< 1.3 V
    NPMX_BUCK_VOLTAGE_1V4     = BUCK_BUCK1NORMVOUT_BUCK1NORMVOUT_1V4,  ///< 1.4 V
    NPMX_BUCK_VOLTAGE_1V5     = BUCK_BUCK1NORMVOUT_BUCK1NORMVOUT_1V5,  ///< 1.5 V
    NPMX_BUCK_VOLTAGE_1V6     = BUCK_BUCK1NORMVOUT_BUCK1NORMVOUT_1V6,  ///< 1.6 V
    NPMX_BUCK_VOLTAGE_1V7     = BUCK_BUCK1NORMVOUT_BUCK1NORMVOUT_1V7,  ///< 1.7 V
    NPMX_BUCK_VOLTAGE_1V8     = BUCK_BUCK1NORMVOUT_BUCK1NORMVOUT_1V8,  ///< 1.8 V
    NPMX_BUCK_VOLTAGE_1V9     = BUCK_BUCK1NORMVOUT_BUCK1NORMVOUT_1V9,  ///< 1.9 V
#if defined(BUCK_BUCK1NORMVOUT_BUCK1NORMVOUT_2V) || defined(__NPMX_DOXYGEN__)
    NPMX_BUCK_VOLTAGE_2V0     = BUCK_BUCK1NORMVOUT_BUCK1NORMVOUT_2V,   ///< 2.0 V
#elif defined(BUCK_BUCK1NORMVOUT_BUCK1NORMVOUT_2V0)
    NPMX_BUCK_VOLTAGE_2V0     = BUCK_BUCK1NORMVOUT_BUCK1NORMVOUT_2V0,  ///< 2.0 V
#endif
    NPMX_BUCK_VOLTAGE_2V1     = BUCK_BUCK1NORMVOUT_BUCK1NORMVOUT_2V1,  ///< 2.1 V
    NPMX_BUCK_VOLTAGE_2V2     = BUCK_BUCK1NORMVOUT_BUCK1NORMVOUT_2V2,  ///< 2.2 V
    NPMX_BUCK_VOLTAGE_2V3     = BUCK_BUCK1NORMVOUT_BUCK1NORMVOUT_2V3,  ///< 2.3 V
    NPMX_BUCK_VOLTAGE_2V4     = BUCK_BUCK1NORMVOUT_BUCK1NORMVOUT_2V4,  ///< 2.4 V
    NPMX_BUCK_VOLTAGE_2V5     = BUCK_BUCK1NORMVOUT_BUCK1NORMVOUT_2V5,  ///< 2.5 V
    NPMX_BUCK_VOLTAGE_2V6     = BUCK_BUCK1NORMVOUT_BUCK1NORMVOUT_2V6,  ///< 2.6 V
    NPMX_BUCK_VOLTAGE_2V7     = BUCK_BUCK1NORMVOUT_BUCK1NORMVOUT_2V7,  ///< 2.7 V
    NPMX_BUCK_VOLTAGE_2V8     = BUCK_BUCK1NORMVOUT_BUCK1NORMVOUT_2V8,  ///< 2.8 V
    NPMX_BUCK_VOLTAGE_2V9     = BUCK_BUCK1NORMVOUT_BUCK1NORMVOUT_2V9,  ///< 2.9 V
#if defined(BUCK_BUCK1NORMVOUT_BUCK1NORMVOUT_3V) || defined(__NPMX_DOXYGEN__)
    NPMX_BUCK_VOLTAGE_3V0     = BUCK_BUCK1NORMVOUT_BUCK1NORMVOUT_3V,   ///< 3.0 V
#elif defined(BUCK_BUCK1NORMVOUT_BUCK1NORMVOUT_3V0)
    NPMX_BUCK_VOLTAGE_3V0     = BUCK_BUCK1NORMVOUT_BUCK1NORMVOUT_3V0,  ///< 3.0 V
#endif
    NPMX_BUCK_VOLTAGE_3V1     = BUCK_BUCK1NORMVOUT_BUCK1NORMVOUT_3V1,  ///< 3.1 V
    NPMX_BUCK_VOLTAGE_3V2     = BUCK_BUCK1NORMVOUT_BUCK1NORMVOUT_3V2,  ///< 3.2 V
    NPMX_BUCK_VOLTAGE_3V3     = BUCK_BUCK1NORMVOUT_BUCK1NORMVOUT_3V3,  ///< 3.3 V
    NPMX_BUCK_VOLTAGE_MAX     = BUCK_BUCK1NORMVOUT_BUCK1NORMVOUT_3V3,  ///< 3.3 V
    NPMX_BUCK_VOLTAGE_INVALID = NPMX_INVALID_ENUM_VALUE,               ///< Invalid voltage.
} npmx_buck_voltage_t;

/** @brief Possible GPIO to be selected with buck configurations. */
typedef enum
{
    NPMX_BUCK_GPIO_NC  = BUCK_BUCKENCTRL_BUCK1ENGPISEL_NOTUSED,  ///< Not used.
    NPMX_BUCK_GPIO_0   = BUCK_BUCKENCTRL_BUCK1ENGPISEL_GPIO0,    ///< GPI_0 selected.
    NPMX_BUCK_GPIO_1   = BUCK_BUCKENCTRL_BUCK1ENGPISEL_GPIO1,    ///< GPI_1 selected.
    NPMX_BUCK_GPIO_2   = BUCK_BUCKENCTRL_BUCK1ENGPISEL_GPIO2,    ///< GPI_2 selected.
    NPMX_BUCK_GPIO_3   = BUCK_BUCKENCTRL_BUCK1ENGPISEL_GPIO3,    ///< GPI_3 selected.
    NPMX_BUCK_GPIO_4   = BUCK_BUCKENCTRL_BUCK1ENGPISEL_GPIO4,    ///< GPI_4 selected.
    NPMX_BUCK_GPIO_NC1 = BUCK_BUCKENCTRL_BUCK1ENGPISEL_NOTUSED1, ///< No GPI selected.
} npmx_buck_gpio_t;

/** @brief Configuration structure for GPIO used as input signal for buck. */
typedef struct
{
    npmx_buck_gpio_t gpio;     ///< The GPIO to be used as the signal.
    bool             inverted; ///< If true, the GPI state will be inverted, logical low will activate the signal.
} npmx_buck_gpio_config_t;

#if defined(BUCK_BUCKSTATUS_BUCK1MODE_Msk) || defined(__NPMX_DOXYGEN__)
/** @brief Buck status structure. */
typedef struct
{
    npmx_buck_mode_t buck_mode;   ///< Buck mode.
    bool             powered;     ///< True if buck is powered on, false otherwise.
    bool             pwm_enabled; ///< True if PWM mode is enabled, false otherwise.
} npmx_buck_status_t;
#endif

/**
 * @brief Function for returning buck instance based on index.
 *
 * @param[in] p_pmic Pointer to the PMIC instance.
 * @param[in] idx    Index of the buck instance.
 *
 * @return Pointer to the buck instance.
 */
npmx_buck_t * npmx_buck_get(npmx_instance_t * p_pmic, uint8_t idx);

/**
 * @brief Function for converting millivolts to @ref npmx_buck_voltage_t enumeration.
 *
 * @param[in] millivolts Voltage in millivolts to be converted into @ref npmx_buck_voltage_t enumeration.
 *
 * @return Result of conversion. @ref NPMX_BUCK_VOLTAGE_INVALID if given voltage is not
 *         represented in enumeration.
 */
npmx_buck_voltage_t npmx_buck_voltage_convert(uint32_t millivolts);

/**
 * @brief Function for converting @ref npmx_buck_voltage_t enumeration to millivolts.
 *
 * @param[in] enum_value Voltage defined as @ref npmx_buck_voltage_t enumeration to be converted into millivolts.
 *
 * @return Result of conversion.
 */
uint32_t npmx_buck_voltage_convert_to_mv(npmx_buck_voltage_t enum_value);

/**
 * @brief Function for activating the specified buck task.
 *
 * @param[in] p_instance Pointer to the buck instance.
 * @param[in] task       Task to be activated.
 *
 * @retval NPMX_SUCCESS  Operation performed successfully.
 * @retval NPMX_ERROR_IO Error using IO bus line.
 */
npmx_error_t npmx_buck_task_trigger(npmx_buck_t const * p_instance, npmx_buck_task_t task);

/**
 * @brief Function for setting the buck converter mode to either PWM, PFM or AUTO (PFM & PWM).
 *
 * @param[in] p_instance Pointer to the buck instance.
 * @param[in] mode       PWM, PFM or AUTO mode.
 *
 * @retval NPMX_SUCCESS  Operation performed successfully.
 * @retval NPMX_ERROR_IO Error using IO bus line.
 */
npmx_error_t npmx_buck_converter_mode_set(npmx_buck_t const * p_instance, npmx_buck_mode_t mode);

/**
 * @brief Function for reading the PFM mode of the buck converter.
 *
 * @param[in]  p_instance Pointer to the buck instance.
 * @param[out] p_enable   Pointer to enable PWM mode variable.
 *
 * @retval NPMX_SUCCESS  Operation performed successfully.
 * @retval NPMX_ERROR_IO Error using IO bus line.
 */
npmx_error_t npmx_buck_pfm_enable_get(npmx_buck_t const * p_instance, bool * p_enable);

/**
 * @brief Function for setting the normal voltage of the specified buck instance.
 *
 * @note To apply the voltage in nPM device, call @ref npmx_buck_vout_select_set() function
 *       with @ref NPMX_BUCK_VOUT_SELECT_SOFTWARE value.
 *
 * @param[in] p_instance Pointer to the buck instance.
 * @param[in] voltage    Voltage to be set at buck's output.
 *
 * @retval NPMX_SUCCESS  Operation performed successfully.
 * @retval NPMX_ERROR_IO Error using IO bus line.
 */
npmx_error_t npmx_buck_normal_voltage_set(npmx_buck_t const * p_instance,
                                          npmx_buck_voltage_t voltage);

/**
 * @brief Function for reading the normal voltage of the specified buck instance.
 *
 * @param[in]  p_instance Pointer to the buck instance.
 * @param[out] p_voltage  Pointer to buck voltage variable.
 *
 * @retval NPMX_SUCCESS  Operation performed successfully.
 * @retval NPMX_ERROR_IO Error using IO bus line.
 */
npmx_error_t npmx_buck_normal_voltage_get(npmx_buck_t const *   p_instance,
                                          npmx_buck_voltage_t * p_voltage);

/**
 * @brief Function for setting the buck retention voltage for the specified buck instance.
 *
 * @note Entering retention mode is done by toggling the selected GPIO @ref npmx_buck_retention_gpio_config_set().
 *       Returning to normal mode is done by toggling GPIO again.
 *
 * @param[in] p_instance Pointer to the buck instance.
 * @param[in] voltage    Voltage to be set at buck's output.
 *
 * @retval NPMX_SUCCESS  Operation performed successfully.
 * @retval NPMX_ERROR_IO Error using IO bus line.
 */
npmx_error_t npmx_buck_retention_voltage_set(npmx_buck_t const * p_instance,
                                             npmx_buck_voltage_t voltage);

/**
 * @brief Function for reading the buck retention voltage for the specified buck instance.
 *
 * @note Entering retention mode is done by toggling the selected GPIO @ref npmx_buck_retention_gpio_config_set().
 *       Returning to normal mode is done by toggling GPIO again.
 *
 * @param[in]  p_instance Pointer to the buck instance.
 * @param[out] p_voltage  Pointer to buck voltage variable.
 *
 * @retval NPMX_SUCCESS  Operation performed successfully.
 * @retval NPMX_ERROR_IO Error using IO bus line.
 */
npmx_error_t npmx_buck_retention_voltage_get(npmx_buck_t const *   p_instance,
                                             npmx_buck_voltage_t * p_voltage);

/**
 * @brief Function for configuring the GPIO pin which will be used for enabling and disabling the specified buck instance converter.
 *
 * @note Selected GPIO should be configured as input using GPIO driver.
 *
 * @param[in] p_instance Pointer to the buck instance.
 * @param[in] p_config   Pointer to the configuration of GPIO to be applied.
 *
 * @retval NPMX_SUCCESS  Operation performed successfully.
 * @retval NPMX_ERROR_IO Error using IO bus line.
 */
npmx_error_t npmx_buck_enable_gpio_config_set(npmx_buck_t const *             p_instance,
                                              npmx_buck_gpio_config_t const * p_config);

/**
 * @brief Function for reading configuration of the GPIO pin used for enabling and disabling the specified buck instance converter.
 *
 * @param[in]  p_instance Pointer to the buck instance.
 * @param[out] p_config   Pointer to the configuration of GPIO.
 *
 * @retval NPMX_SUCCESS  Operation performed successfully.
 * @retval NPMX_ERROR_IO Error using IO bus line.
 */
npmx_error_t npmx_buck_enable_gpio_config_get(npmx_buck_t const *       p_instance,
                                              npmx_buck_gpio_config_t * p_config);

/**
 * @brief Function for configuring the GPIO pin which will be used for controlling the specified buck's retention mode.
 *
 * @note Selected GPIO should be configured as input using GPIO driver.
 *
 * @param[in] p_instance Pointer to the buck instance.
 * @param[in] p_config   Pointer to the configuration of GPIO to be applied.
 *
 * @retval NPMX_SUCCESS  Operation performed successfully.
 * @retval NPMX_ERROR_IO Error using IO bus line.
 */
npmx_error_t npmx_buck_retention_gpio_config_set(npmx_buck_t const *             p_instance,
                                                 npmx_buck_gpio_config_t const * p_config);

/**
 * @brief Function for reading configuration of the GPIO pin used for controlling the specified buck's retention mode.
 *
 * @note Selected GPIO should be configured as input using GPIO driver.
 *
 * @param[in]  p_instance Pointer to the buck instance.
 * @param[out] p_config   Pointer to the configuration of GPIO.
 *
 * @retval NPMX_SUCCESS  Operation performed successfully.
 * @retval NPMX_ERROR_IO Error using IO bus line.
 */
npmx_error_t npmx_buck_retention_gpio_config_get(npmx_buck_t const *       p_instance,
                                                 npmx_buck_gpio_config_t * p_config);

/**
 * @brief Function for configuring the GPIO pin to use forced PWM mode in the specified buck instance converter.
 *
 * @note Selected GPIO should be configured as input using GPIO driver.
 *       When GPIO has been configured for this purpose, it overrides the register setting for either one or both converters.
 *
 * @param[in] p_instance Pointer to the buck instance.
 * @param[in] p_config   Pointer to the configuration of GPIO to be applied.
 *
 * @retval NPMX_SUCCESS  Operation performed successfully.
 * @retval NPMX_ERROR_IO Error using IO bus line.
 */
npmx_error_t npmx_buck_forced_pwm_gpio_config_set(npmx_buck_t const *             p_instance,
                                                  npmx_buck_gpio_config_t const * p_config);

/**
 * @brief Function for reading the GPIO pin configuration used to force PWM mode.
 *
 * @param[in]  p_instance Pointer to the buck instance.
 * @param[out] p_config   Pointer to the configuration structure.
 *
 * @retval NPMX_SUCCESS  Operation performed successfully.
 * @retval NPMX_ERROR_IO Error using IO bus line.
 */
npmx_error_t npmx_buck_forced_pwm_gpio_config_get(npmx_buck_t const *       p_instance,
                                                  npmx_buck_gpio_config_t * p_config);

/**
 * @brief Function for selecting the output voltage reference of the specified buck instance converter.
 *
 * @param[in] p_instance Pointer to the buck instance.
 * @param[in] selection  Selection of the output voltage reference.
 *
 * @retval NPMX_SUCCESS  Operation performed successfully.
 * @retval NPMX_ERROR_IO Error using IO bus line.
 */
npmx_error_t npmx_buck_vout_select_set(npmx_buck_t const *     p_instance,
                                       npmx_buck_vout_select_t selection);

/**
 * @brief Function for reading selected output voltage reference of the specified buck instance converter.
 *
 * @param[in]  p_instance  Pointer to the buck instance.
 * @param[out] p_selection Pointer to selection of the output voltage reference.
 *
 * @retval NPMX_SUCCESS  Operation performed successfully.
 * @retval NPMX_ERROR_IO Error using IO bus line.
 */
npmx_error_t npmx_buck_vout_select_get(npmx_buck_t const *       p_instance,
                                       npmx_buck_vout_select_t * p_selection);

/**
 * @brief Function for reading the voltage status register of the specified buck instance.
 *
 * @param[in]  p_instance Pointer to the buck instance.
 * @param[out] p_voltage  Pointer to the voltage variable of the buck.
 *
 * @retval NPMX_SUCCESS  Operation performed successfully.
 * @retval NPMX_ERROR_IO Error using IO bus line.
 */
npmx_error_t npmx_buck_status_voltage_get(npmx_buck_t const *   p_instance,
                                          npmx_buck_voltage_t * p_voltage);

/**
 * @brief Function for setting active output capacitor discharge state of the specified buck converter.
 *        When selected, discharge is ON when converter is disabled.
 *
 * @note Discharge of the capacitor is forced automatically by nPM device in case of a power cycle reset.
 *
 * @param[in] p_instance Pointer to the buck instance.
 * @param[in] enable     True to enable active discharge, false to disable active discharge.
 *
 * @retval NPMX_SUCCESS  Operation performed successfully.
 * @retval NPMX_ERROR_IO Error using IO bus line.
 */
npmx_error_t npmx_buck_active_discharge_enable_set(npmx_buck_t const * p_instance, bool enable);

/**
 * @brief Function for reading active output capacitor discharge state of the specified buck converter.
 *        When selected, discharge is ON when converter is disabled.
 *
 * @param[in]  p_instance Pointer to the buck instance.
 * @param[out] p_enable   Pointer to the enable active discharge variable.
 *
 * @retval NPMX_SUCCESS  Operation performed successfully.
 * @retval NPMX_ERROR_IO Error using IO bus line.
 */
npmx_error_t npmx_buck_active_discharge_enable_get(npmx_buck_t const * p_instance, bool * p_enable);

#if defined(BUCK_BUCKSTATUS_BUCK1MODE_Msk) || defined(__NPMX_DOXYGEN__)
/**
 * @brief Function for getting status of the specified buck converter.
 *
 * @param[in]  p_instance Pointer to the buck instance.
 * @param[out] p_status   Pointer to the buck status structure.
 *
 * @retval NPMX_SUCCESS  Operation performed successfully.
 * @retval NPMX_ERROR_IO Error using IO bus line.
 */
npmx_error_t npmx_buck_status_get(npmx_buck_t const * p_instance, npmx_buck_status_t * p_status);
#endif

/** @} */

#ifdef __cplusplus
}
#endif

#endif /* NPMX_BUCK_H__ */
