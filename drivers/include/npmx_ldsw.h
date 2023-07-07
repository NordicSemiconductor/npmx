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

#ifndef NPMX_LDSW_H__
#define NPMX_LDSW_H__

#include <npmx.h>

#ifdef __cplusplus
extern "C" {
#endif

/**
 * @defgroup npmx_ldsw LDSW
 * @{
 * @ingroup npmx_drivers
 * @brief   Load switch (LDSW) peripheral driver.
 */

/** @brief LDSW tasks. */
typedef enum
{
    NPMX_LDSW_TASK_ENABLE,  ///< Enable LDSW.
    NPMX_LDSW_TASK_DISABLE, ///< Disable LDSW.
    NPMX_LDSW_TASK_COUNT,   ///< LDSW tasks count.
} npmx_ldsw_task_t;

/** @brief Possible GPIO to be selected with LDSW configurations. */
typedef enum
{
    NPMX_LDSW_GPIO_NC      = LDSW_LDSW1GPISEL_LDSW1GPISEL_NOTUSED1, ///< No GPIO selected.
    NPMX_LDSW_GPIO_0       = LDSW_LDSW1GPISEL_LDSW1GPISEL_GPIO0,    ///< GPIO_0 selected.
    NPMX_LDSW_GPIO_1       = LDSW_LDSW1GPISEL_LDSW1GPISEL_GPIO1,    ///< GPIO_1 selected.
    NPMX_LDSW_GPIO_2       = LDSW_LDSW1GPISEL_LDSW1GPISEL_GPIO2,    ///< GPIO_2 selected.
    NPMX_LDSW_GPIO_3       = LDSW_LDSW1GPISEL_LDSW1GPISEL_GPIO3,    ///< GPIO_3 selected.
    NPMX_LDSW_GPIO_4       = LDSW_LDSW1GPISEL_LDSW1GPISEL_GPIO4,    ///< GPIO_4 selected.
    NPMX_LDSW_GPIO_COUNT,                                           ///< GPIOs count.
    NPMX_LDSW_GPIO_INVALID = NPMX_INVALID_ENUM_VALUE,               ///< Invalid GPIO.
} npmx_ldsw_gpio_t;

/** @brief LDSW status fields. */
typedef enum
{
    NPMX_LDSW_STATUS_POWERUP_LDSW_1_MASK = LDSW_LDSWSTATUS_LDSW1PWRUPLDSW_Msk, ///< LDSW 1 Power Up signal.
    NPMX_LDSW_STATUS_POWERUP_LDO_1_MASK  = LDSW_LDSWSTATUS_LDSW1PWRUPLDO_Msk,  ///< LDO 1 Power Up signal.
    NPMX_LDSW_STATUS_POWERUP_LDSW_2_MASK = LDSW_LDSWSTATUS_LDSW2PWRUPLDSW_Msk, ///< LDSW 1 Power Up signal.
    NPMX_LDSW_STATUS_POWERUP_LDO_2_MASK  = LDSW_LDSWSTATUS_LDSW2PWRUPLDO_Msk,  ///< LDO 1 Power Up signal.
    NPMX_LDSW_STATUS_DEEPSLEEP_MASK      = LDSW_LDSWSTATUS_LDSWENABLE_Msk,     ///< LDSW/LDO Enable Deep Sleep signal.
} npmx_ldsw_status_mask_t;

/** @brief Possible LDSW soft start current levels. */
typedef enum
{
    NPMX_LDSW_SOFT_START_CURRENT_25_MA   = LDSW_LDSWCONFIG_LDSW1SOFTSTARTSEL_25mA,  ///< LDSW soft start level 25 mA.
    NPMX_LDSW_SOFT_START_CURRENT_50_MA   = LDSW_LDSWCONFIG_LDSW1SOFTSTARTSEL_50mA,  ///< LDSW soft start level 50 mA.
    NPMX_LDSW_SOFT_START_CURRENT_75_MA   = LDSW_LDSWCONFIG_LDSW1SOFTSTARTSEL_75mA,  ///< LDSW soft start level 75 mA.
    NPMX_LDSW_SOFT_START_CURRENT_100_MA  = LDSW_LDSWCONFIG_LDSW1SOFTSTARTSEL_100mA, ///< LDSW soft start level 100 mA.
    NPMX_LDSW_SOFT_START_CURRENT_COUNT,                                             ///< Current levels count.
    NPMX_LDSW_SOFT_START_CURRENT_DEFAULT = NPMX_LDSW_SOFT_START_CURRENT_25_MA,      ///< Default LDSW soft start level.
    NPMX_LDSW_SOFT_START_CURRENT_MAX     = NPMX_LDSW_SOFT_START_CURRENT_100_MA,     ///< Maximum LDSW soft start level.
    NPMX_LDSW_SOFT_START_CURRENT_INVALID = NPMX_INVALID_ENUM_VALUE,                 ///< Invalid LDSW soft start level.
} npmx_ldsw_soft_start_current_t;

/** @brief Possible LDO output voltages to be set. */
typedef enum
{
    NPMX_LDSW_VOLTAGE_1V0     = LDSW_LDSW1VOUTSEL_LDSW1VOUTSEL_1V,  ///< 1.0 V
    NPMX_LDSW_VOLTAGE_1V1     = LDSW_LDSW1VOUTSEL_LDSW1VOUTSEL_1V1, ///< 1.1 V
    NPMX_LDSW_VOLTAGE_1V2     = LDSW_LDSW1VOUTSEL_LDSW1VOUTSEL_1V2, ///< 1.2 V
    NPMX_LDSW_VOLTAGE_1V3     = LDSW_LDSW1VOUTSEL_LDSW1VOUTSEL_1V3, ///< 1.3 V
    NPMX_LDSW_VOLTAGE_1V4     = LDSW_LDSW1VOUTSEL_LDSW1VOUTSEL_1V4, ///< 1.4 V
    NPMX_LDSW_VOLTAGE_1V5     = LDSW_LDSW1VOUTSEL_LDSW1VOUTSEL_1V5, ///< 1.5 V
    NPMX_LDSW_VOLTAGE_1V6     = LDSW_LDSW1VOUTSEL_LDSW1VOUTSEL_1V6, ///< 1.6 V
    NPMX_LDSW_VOLTAGE_1V7     = LDSW_LDSW1VOUTSEL_LDSW1VOUTSEL_1V7, ///< 1.7 V
    NPMX_LDSW_VOLTAGE_1V8     = LDSW_LDSW1VOUTSEL_LDSW1VOUTSEL_1V8, ///< 1.8 V
    NPMX_LDSW_VOLTAGE_1V9     = LDSW_LDSW1VOUTSEL_LDSW1VOUTSEL_1V9, ///< 1.9 V
    NPMX_LDSW_VOLTAGE_2V0     = LDSW_LDSW1VOUTSEL_LDSW1VOUTSEL_2V,  ///< 2.0 V
    NPMX_LDSW_VOLTAGE_2V1     = LDSW_LDSW1VOUTSEL_LDSW1VOUTSEL_2V1, ///< 2.1 V
    NPMX_LDSW_VOLTAGE_2V2     = LDSW_LDSW1VOUTSEL_LDSW1VOUTSEL_2V2, ///< 2.2 V
    NPMX_LDSW_VOLTAGE_2V3     = LDSW_LDSW1VOUTSEL_LDSW1VOUTSEL_2V3, ///< 2.3 V
    NPMX_LDSW_VOLTAGE_2V4     = LDSW_LDSW1VOUTSEL_LDSW1VOUTSEL_2V4, ///< 2.4 V
    NPMX_LDSW_VOLTAGE_2V5     = LDSW_LDSW1VOUTSEL_LDSW1VOUTSEL_2V5, ///< 2.5 V
    NPMX_LDSW_VOLTAGE_2V6     = LDSW_LDSW1VOUTSEL_LDSW1VOUTSEL_2V6, ///< 2.6 V
    NPMX_LDSW_VOLTAGE_2V7     = LDSW_LDSW1VOUTSEL_LDSW1VOUTSEL_2V7, ///< 2.7 V
    NPMX_LDSW_VOLTAGE_2V8     = LDSW_LDSW1VOUTSEL_LDSW1VOUTSEL_2V8, ///< 2.8 V
    NPMX_LDSW_VOLTAGE_2V9     = LDSW_LDSW1VOUTSEL_LDSW1VOUTSEL_2V9, ///< 2.9 V
    NPMX_LDSW_VOLTAGE_3V0     = LDSW_LDSW1VOUTSEL_LDSW1VOUTSEL_3V,  ///< 3.0 V
    NPMX_LDSW_VOLTAGE_3V1     = LDSW_LDSW1VOUTSEL_LDSW1VOUTSEL_3V1, ///< 3.1 V
    NPMX_LDSW_VOLTAGE_3V2     = LDSW_LDSW1VOUTSEL_LDSW1VOUTSEL_3V2, ///< 3.2 V
    NPMX_LDSW_VOLTAGE_3V3     = LDSW_LDSW1VOUTSEL_LDSW1VOUTSEL_3V3, ///< 3.3 V
    NPMX_LDSW_VOLTAGE_COUNT,                                        ///< LDO voltages count.
    NPMX_LDSW_VOLTAGE_DEFAULT = NPMX_LDSW_VOLTAGE_1V0,              ///< Default LDO voltage.
    NPMX_LDSW_VOLTAGE_MAX     = NPMX_LDSW_VOLTAGE_3V3,              ///< Maximum LDO voltage.
    NPMX_LDSW_VOLTAGE_INVALID = NPMX_INVALID_ENUM_VALUE,            ///< Invalid LDO voltage.
} npmx_ldsw_voltage_t;

/** @brief Possible LDSW modes. */
typedef enum
{
    NPMX_LDSW_MODE_LOAD_SWITCH = LDSW_LDSW1LDOSEL_LDSW1LDOSEL_LDSW, ///< LDSW configured as load switch.
    NPMX_LDSW_MODE_LDO         = LDSW_LDSW1LDOSEL_LDSW1LDOSEL_LDO,  ///< LDSW configured as LDO.
    NPMX_LDSW_MODE_COUNT,                                           ///< LDSW modes count.
    NPMX_LDSW_MODE_INVALID     = NPMX_INVALID_ENUM_VALUE,           ///< Invalid LDSW mode.
} npmx_ldsw_mode_t;

/** @brief Data structure of the LDSW driver instance. */
typedef struct
{
    npmx_backend_t * p_backend; ///< Pointer to backend instance.
    uint8_t          hw_index;  ///< Hardware index of LDSW instance.
} npmx_ldsw_t;

/** @brief Configuration structure for GPIO used as input signal for LDSW. */
typedef struct
{
    npmx_ldsw_gpio_t gpio;     ///< The GPIO to be used as the signal.
    bool             inverted; ///< If true, the input state will be inverted, and logical low state will activate the signal.
} npmx_ldsw_gpio_config_t;

/** @brief Configuration structure for soft start. */
typedef struct
{
    bool                           enable;  ///< Soft start enable status.
    npmx_ldsw_soft_start_current_t current; ///< Soft start current level.
} npmx_ldsw_soft_start_config_t;

/**
 * @brief Function for returning LDSW instance based on index.
 *
 * @param[in] p_pmic Pointer to the PMIC instance.
 * @param[in] idx    Index of the LDSW instance.
 *
 * @return Pointer to the LDSW instance.
 */
npmx_ldsw_t * npmx_ldsw_get(npmx_instance_t * p_pmic, uint8_t idx);

/**
 * @brief Function for converting millivolts to @ref npmx_ldsw_voltage_t enumeration.
 *
 * @param[in] millivolts Voltage in millivolts to be converted into @ref npmx_ldsw_voltage_t enumeration.
 *
 * @return Result of conversion. @ref NPMX_LDSW_VOLTAGE_INVALID if given voltage is not
 *         represented in enumeration.
 */
npmx_ldsw_voltage_t npmx_ldsw_voltage_convert(uint32_t millivolts);

/**
 * @brief Function for converting @ref npmx_ldsw_voltage_t enumeration to millivolts.
 *
 * @param[in]  enum_value Voltage defined as @ref npmx_ldsw_voltage_t enumeration to be converted into millivolts.
 * @param[out] p_val      Pointer to the variable that stores the conversion result.
 *
 * @retval true  Conversion is valid.
 * @retval false Conversion is invalid - an invalid argument was passed to the function.
 */
bool npmx_ldsw_voltage_convert_to_mv(npmx_ldsw_voltage_t enum_value, uint32_t * p_val);

/**
 * @brief Function for converting milliamperes to @ref npmx_ldsw_soft_start_current_t enumeration.
 *
 * @param[in] milliamperes Current in milliamperes to be converted into
 *                         @ref npmx_ldsw_soft_start_current_t enumeration.
 *
 * @return Result of conversion. @ref NPMX_LDSW_SOFT_START_CURRENT_INVALID if given current is not
 *         represented in enumeration.
 */
npmx_ldsw_soft_start_current_t npmx_ldsw_soft_start_current_convert(uint32_t milliamperes);

/**
 * @brief Function for converting @ref npmx_ldsw_soft_start_current_t enumeration to milliamperes.
 *
 * @param[in]  enum_value Current defined as @ref npmx_ldsw_soft_start_current_t enumeration to
 *                        be converted into milliamperes.
 * @param[out] p_val      Pointer to the variable that stores the conversion result.
 *
 * @retval true  Conversion is valid.
 * @retval false Conversion is invalid - an invalid argument was passed to the function.
 */
bool npmx_ldsw_soft_start_current_convert_to_ma(npmx_ldsw_soft_start_current_t enum_value,
                                                uint32_t *                     p_val);

/**
 * @brief Function for activating the specified LDSW task.
 *
 * @param[in] p_instance Pointer to the LDSW instance.
 * @param[in] task       Task to be activated.
 *
 * @retval NPMX_SUCCESS  Operation performed successfully.
 * @retval NPMX_ERROR_IO Error using IO bus line.
 */
npmx_error_t npmx_ldsw_task_trigger(npmx_ldsw_t const * p_instance, npmx_ldsw_task_t task);

/**
 * @brief Function for setting the GPIO pin which will be used for enabling and disabling the specified LDSW instance.
 *
 * @note Selected GPIO should be configured as input using GPIO driver.
 *
 * @param[in] p_instance Pointer to the LDSW instance.
 * @param[in] p_config   Pointer to the configuration of specified GPIO to be used as the enable signal.
 *
 * @retval NPMX_SUCCESS  Operation performed successfully.
 * @retval NPMX_ERROR_IO Error using IO bus line.
 */
npmx_error_t npmx_ldsw_enable_gpio_set(npmx_ldsw_t const *             p_instance,
                                       npmx_ldsw_gpio_config_t const * p_config);

/**
 * @brief Function for reading which GPIO pin will be used for enabling and disabling the specified LDSW instance.
 *
 * @note Selected GPIO should be configured as input using GPIO driver.
 *
 * @param[in]  p_instance Pointer to the LDSW instance.
 * @param[out] p_config   Pointer to the configuration of GPIO used as the enable signal.
 *
 * @retval NPMX_SUCCESS  Operation performed successfully.
 * @retval NPMX_ERROR_IO Error using IO bus line.
 */
npmx_error_t npmx_ldsw_enable_gpio_get(npmx_ldsw_t const *       p_instance,
                                       npmx_ldsw_gpio_config_t * p_config);

/**
 * @brief Function for getting status for specified LDSW instance.
 *
 * @param[in]  p_instance    Pointer to the LDSW instance.
 * @param[out] p_status_mask Pointer to the LDSW status mask composed of values from @ref npmx_ldsw_status_mask_t.
 *
 * @retval NPMX_SUCCESS  Operation performed successfully.
 * @retval NPMX_ERROR_IO Error using IO bus line.
 */
npmx_error_t npmx_ldsw_status_get(npmx_ldsw_t const * p_instance, uint8_t * p_status_mask);

/**
 * @brief Function for configuring soft start for given instance of LDSW.
 *
 * @param[in] p_instance Pointer to the LDSW instance.
 * @param[in] p_config   Pointer to the configuration of soft start to apply.
 *
 * @retval NPMX_SUCCESS  Operation performed successfully.
 * @retval NPMX_ERROR_IO Error using IO bus line.
 */
npmx_error_t npmx_ldsw_soft_start_config_set(npmx_ldsw_t const *                   p_instance,
                                             npmx_ldsw_soft_start_config_t const * p_config);

/**
 * @brief Function for reading configuration of soft start for given instance of LDSW.
 *
 * @param[in]  p_instance Pointer to the LDSW instance.
 * @param[out] p_config   Pointer to the configuration of soft start.
 *
 * @retval NPMX_SUCCESS  Operation performed successfully.
 * @retval NPMX_ERROR_IO Error using IO bus line.
 */
npmx_error_t npmx_ldsw_soft_start_config_get(npmx_ldsw_t const *             p_instance,
                                             npmx_ldsw_soft_start_config_t * p_config);

/**
 * @brief Function for enabling and disabling active discharge for given instance of LDSW.
 *
 * @param[in] p_instance Pointer to the LDSW instance.
 * @param[in] enable     True to enable active discharge, false to disable active discharge.
 *
 * @retval NPMX_SUCCESS  Operation performed successfully.
 * @retval NPMX_ERROR_IO Error using IO bus line.
 */
npmx_error_t npmx_ldsw_active_discharge_enable_set(npmx_ldsw_t const * p_instance, bool enable);

/**
 * @brief Function for reading if active discharge is enabled for given instance of LDSW.
 *
 * @param[in]  p_instance Pointer to the LDSW instance.
 * @param[out] p_enable   Pointer to active discharge enable variable.
 *
 * @retval NPMX_SUCCESS  Operation performed successfully.
 * @retval NPMX_ERROR_IO Error using IO bus line.
 */
npmx_error_t npmx_ldsw_active_discharge_enable_get(npmx_ldsw_t const * p_instance, bool * p_enable);

/**
 * @brief Function for configuring given instance of LDSW to work as LDO or load switch.
 *
 * @param[in] p_instance Pointer to the LDSW instance.
 * @param[in] mode       LDSW mode to be set.
 *
 * @retval NPMX_SUCCESS  Operation performed successfully.
 * @retval NPMX_ERROR_IO Error using IO bus line.
 */
npmx_error_t npmx_ldsw_mode_set(npmx_ldsw_t const * p_instance, npmx_ldsw_mode_t mode);

/**
 * @brief Function for reading if a given instance of LDSW works as LDO or load switch.
 *
 * @param[in]  p_instance Pointer to the LDSW instance.
 * @param[out] p_mode     Pointer to the LDSW mode variable.
 *
 * @retval NPMX_SUCCESS  Operation performed successfully.
 * @retval NPMX_ERROR_IO Error using IO bus line.
 */
npmx_error_t npmx_ldsw_mode_get(npmx_ldsw_t const * p_instance, npmx_ldsw_mode_t * p_mode);

/**
 * @brief Function for setting the output voltage of LDO for given instance of LDSW.
 *
 * @param[in] p_instance Pointer to the LDSW instance.
 * @param[in] voltage    Voltage to set the LDO to.
 *
 * @retval NPMX_SUCCESS  Operation performed successfully.
 * @retval NPMX_ERROR_IO Error using IO bus line.
 */
npmx_error_t npmx_ldsw_ldo_voltage_set(npmx_ldsw_t const * p_instance, npmx_ldsw_voltage_t voltage);

/**
 * @brief Function for getting the output voltage of LDO for given instance of LDSW.
 *
 * @param[in]  p_instance Pointer to the LDSW instance.
 * @param[out] p_voltage  Pointer to buck voltage variable.
 *
 * @retval NPMX_SUCCESS  Operation performed successfully.
 * @retval NPMX_ERROR_IO Error using IO bus line.
 */
npmx_error_t npmx_ldsw_ldo_voltage_get(npmx_ldsw_t const *   p_instance,
                                       npmx_ldsw_voltage_t * p_voltage);

/** @} */

#ifdef __cplusplus
}
#endif

#endif /* NPMX_LDSW_H__ */
