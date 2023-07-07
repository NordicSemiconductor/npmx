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

#ifndef NPMX_CHARGER_H__
#define NPMX_CHARGER_H__

#include <npmx.h>

#ifdef __cplusplus
extern "C" {
#endif

/**
 * @defgroup npmx_charger CHARGER
 * @{
 * @ingroup npmx_drivers
 * @brief   Battery charger peripheral driver.
 */

/** @brief Charger tasks. */
typedef enum
{
    NPMX_CHARGER_TASK_RELEASE,      ///< SW release from charger error state.
    NPMX_CHARGER_TASK_CLEAR_ERROR,  ///< Clear registers of BCHGERRREASON and BCHGERRSENSOR.
    NPMX_CHARGER_TASK_CLEAR_TIMERS, ///< Clear TRICKLE and CHARGE safety timers.
    NPMX_CHARGER_TASK_COUNT,        ///< Charger tasks count.
} npmx_charger_task_t;

/** @brief Charger modules to be enabled and disabled. */
typedef enum
{
    NPMX_CHARGER_MODULE_CHARGER_MASK    = (1U << 0U), ///< Battery charger module.
    /* Default: charger not set. */
    NPMX_CHARGER_MODULE_FULL_COOL_MASK  = (1U << 1U), ///< Battery charger module full charge in Cool temperature.
    /* When:    not set:     50% charge current value of BCHGISETMSB and BCHGISETLSB registers.
     *          set:         100% charge current value of BCHGISETMSB and BCHGISETLSB registers.
     * Default: not set. */
    NPMX_CHARGER_MODULE_RECHARGE_MASK   = (1U << 2U), ///< Battery charger module recharge.
    /* When:    set:         The charger waits until the battery voltage is below VRECHARGE before starting a new charging cycle.
     *          not set:     Optional automatic recharge is disabled.
     * Default: set. */
    NPMX_CHARGER_MODULE_NTC_LIMITS_MASK = (1U << 3U), ///< Battery charger module NTC temperature limits.
    /* When:    set:         Battery charger does not ignore NTC temperature limits.
     *          not set:     Battery charger ignores NTC temperature limits.
     * Default: set. */
} npmx_charger_module_mask_t;

/** @brief Battery charger termination voltage Normal and Warm. */
typedef enum
{
    NPMX_CHARGER_VOLTAGE_3V50    = BCHARGER_BCHGVTERMR_BCHGVTERMREDUCED_3V50, ///< 3.50 V
    NPMX_CHARGER_VOLTAGE_3V55    = BCHARGER_BCHGVTERMR_BCHGVTERMREDUCED_3V55, ///< 3.55 V
    NPMX_CHARGER_VOLTAGE_3V60    = BCHARGER_BCHGVTERMR_BCHGVTERMREDUCED_3V60, ///< 3.60 V
    NPMX_CHARGER_VOLTAGE_3V65    = BCHARGER_BCHGVTERMR_BCHGVTERMREDUCED_3V65, ///< 3.65 V
    NPMX_CHARGER_VOLTAGE_4V00    = BCHARGER_BCHGVTERMR_BCHGVTERMREDUCED_4V00, ///< 4.00 V
    NPMX_CHARGER_VOLTAGE_4V05    = BCHARGER_BCHGVTERMR_BCHGVTERMREDUCED_4V05, ///< 4.05 V
    NPMX_CHARGER_VOLTAGE_4V10    = BCHARGER_BCHGVTERMR_BCHGVTERMREDUCED_4V10, ///< 4.10 V
    NPMX_CHARGER_VOLTAGE_4V15    = BCHARGER_BCHGVTERMR_BCHGVTERMREDUCED_4V15, ///< 4.15 V
    NPMX_CHARGER_VOLTAGE_4V20    = BCHARGER_BCHGVTERMR_BCHGVTERMREDUCED_4V20, ///< 4.20 V
    NPMX_CHARGER_VOLTAGE_4V25    = BCHARGER_BCHGVTERMR_BCHGVTERMREDUCED_4V25, ///< 4.25 V
    NPMX_CHARGER_VOLTAGE_4V30    = BCHARGER_BCHGVTERMR_BCHGVTERMREDUCED_4V30, ///< 4.30 V
    NPMX_CHARGER_VOLTAGE_4V35    = BCHARGER_BCHGVTERMR_BCHGVTERMREDUCED_4V35, ///< 4.35 V
    NPMX_CHARGER_VOLTAGE_4V40    = BCHARGER_BCHGVTERMR_BCHGVTERMREDUCED_4V40, ///< 4.40 V
    NPMX_CHARGER_VOLTAGE_4V45    = BCHARGER_BCHGVTERMR_BCHGVTERMREDUCED_4V45, ///< 4.45 V
    NPMX_CHARGER_VOLTAGE_COUNT,                                               ///< Possible voltages count.
    NPMX_CHARGER_VOLTAGE_DEFAULT = NPMX_CHARGER_VOLTAGE_3V60,                 ///< Default 3.60 V.
    NPMX_CHARGER_VOLTAGE_MAX     = NPMX_CHARGER_VOLTAGE_4V45,                 ///< Maximum voltage.
    NPMX_CHARGER_VOLTAGE_INVALID = NPMX_INVALID_ENUM_VALUE,                   ///< Invalid voltage.
} npmx_charger_voltage_t;

/** @brief Battery charger status. */
typedef enum
{
    NPMX_CHARGER_STATUS_BATTERY_DETECTED_MASK  = BCHARGER_BCHGCHARGESTATUS_BATTERYDETECTED_Msk,      ///< Battery is connected.
    NPMX_CHARGER_STATUS_COMPLETED_MASK         = BCHARGER_BCHGCHARGESTATUS_COMPLETED_Msk,            ///< Charging completed (Battery Full).
    NPMX_CHARGER_STATUS_TRICKLE_CHARGE_MASK    = BCHARGER_BCHGCHARGESTATUS_TRICKLECHARGE_Msk,        ///< Trickle charge.
    NPMX_CHARGER_STATUS_CONSTANT_CURRENT_MASK  = BCHARGER_BCHGCHARGESTATUS_CONSTANTCURRENT_Msk,      ///< Constant current charging.
    NPMX_CHARGER_STATUS_CONSTANT_VOLTAGE_MASK  = BCHARGER_BCHGCHARGESTATUS_CONSTANTVOLTAGE_Msk,      ///< Constant voltage charging.
    NPMX_CHARGER_STATUS_RECHARGE_MASK          = BCHARGER_BCHGCHARGESTATUS_RECHARGE_Msk,             ///< Battery recharge is needed.
    NPMX_CHARGER_STATUS_DIE_TEMP_HIGH_MASK     = BCHARGER_BCHGCHARGESTATUS_DIETEMPHIGHCHGPAUSED_Msk, ///< Charging stopped due to the high die temperature.
    NPMX_CHARGER_STATUS_SUPPLEMENT_ACTIVE_MASK = BCHARGER_BCHGCHARGESTATUS_SUPPLEMENTACTIVE_Msk,     ///< Supplement mode Active.
} npmx_charger_status_mask_t;

/** @brief Battery charger trickle level select. */
typedef enum
{
    NPMX_CHARGER_TRICKLE_2V9     = BCHARGER_BCHGVTRICKLESEL_BCHGVTRICKLESEL_2V9, ///< Trickle voltage level 2.9 V.
    NPMX_CHARGER_TRICKLE_2V5     = BCHARGER_BCHGVTRICKLESEL_BCHGVTRICKLESEL_2V5, ///< Trickle voltage level 2.5 V.
    NPMX_CHARGER_TRICKLE_COUNT,                                                  ///< Trickle voltage levels count.
    NPMX_CHARGER_TRICKLE_DEFAULT = NPMX_CHARGER_TRICKLE_2V9,                     ///< Default trickle voltage level 2.9 V.
    NPMX_CHARGER_TRICKLE_MAX     = NPMX_CHARGER_TRICKLE_2V9,                     ///< Maximum trickle voltage.
    NPMX_CHARGER_TRICKLE_INVALID = NPMX_INVALID_ENUM_VALUE,                      ///< Invalid trickle voltage.
} npmx_charger_trickle_t;

/** @brief Battery charger termination current select. */
typedef enum
{
    NPMX_CHARGER_ITERM_10      = BCHARGER_BCHGITERMSEL_BCHGITERMSEL_SEL10, ///< ITERM current set to 10 percent of charging current.
    NPMX_CHARGER_ITERM_20      = BCHARGER_BCHGITERMSEL_BCHGITERMSEL_SEL20, ///< ITERM current set to 20 percent of charging current.
    NPMX_CHARGER_ITERM_COUNT,                                              ///< ITERM current max count.
    NPMX_CHARGER_ITERM_DEFAULT = NPMX_CHARGER_ITERM_10,                    ///< Default ITERM current set to 10 percent of charging current.
    NPMX_CHARGER_ITERM_MAX     = NPMX_CHARGER_ITERM_20,                    ///< Maximum ITERM current set to 20 percent of charging current.
    NPMX_CHARGER_ITERM_INVALID = NPMX_INVALID_ENUM_VALUE,                  ///< Invalid ITERM current.
} npmx_charger_iterm_t;

/** @brief NTC comparator status fields. */
typedef enum
{
    NPMX_CHARGER_NTC_STATUS_COLD_MASK = BCHARGER_NTCSTATUS_NTCCOLD_Msk, ///< NTC temperature is cold.
    NPMX_CHARGER_NTC_STATUS_COOL_MASK = BCHARGER_NTCSTATUS_NTCCOOL_Msk, ///< NTC temperature is cool.
    NPMX_CHARGER_NTC_STATUS_WARM_MASK = BCHARGER_NTCSTATUS_NTCWARM_Msk, ///< NTC temperature is warm.
    NPMX_CHARGER_NTC_STATUS_HOT_MASK  = BCHARGER_NTCSTATUS_NTCHOT_Msk,  ///< NTC temperature is hot.
} npmx_charger_ntc_status_mask_t;

/** @brief Data structure of the CHARGER driver instance. */
typedef struct
{
    npmx_instance_t * p_pmic;                 ///< Pointer to the PMIC instance.
    uint16_t          charging_current_ma;    ///< Charging current in milliamperes.
    uint16_t          discharging_current_ma; ///< Discharging current in milliamperes.
} npmx_charger_t;

/**
 * @brief Function for returning CHARGER instance based on index.
 *
 * @param[in] p_pmic Pointer to the PMIC instance.
 * @param[in] idx    Index of the CHARGER instance.
 *
 * @return Pointer to the CHARGER instance.
 */
npmx_charger_t * npmx_charger_get(npmx_instance_t * p_pmic, uint8_t idx);

/**
 * @brief Function for converting millivolts to @ref npmx_charger_voltage_t enumeration.
 *
 * @param[in] millivolts Voltage in millivolts to be converted into @ref npmx_charger_voltage_t enumeration.
 *
 * @return Result of conversion. @ref NPMX_CHARGER_VOLTAGE_INVALID if given voltage is not
 *         represented in enumeration.
 */
npmx_charger_voltage_t npmx_charger_voltage_convert(uint32_t millivolts);

/**
 * @brief Function for converting @ref npmx_charger_voltage_t enumeration to millivolts.
 *
 * @param[in]  enum_value Voltage defined as @ref npmx_charger_voltage_t enumeration to be converted into millivolts.
 * @param[out] p_val      Pointer to the variable that stores the conversion result.
 * 
 * @retval true  Conversion is valid.
 * @retval false Conversion is invalid - an invalid argument was passed to the function.
 */
bool npmx_charger_voltage_convert_to_mv(npmx_charger_voltage_t enum_value, uint32_t * p_val);

/**
 * @brief Function for converting millivolts to @ref npmx_charger_trickle_t enumeration.
 *
 * @param[in] millivolts Voltage in millivolts to be converted into @ref npmx_charger_trickle_t enumeration.
 *
 * @return Result of conversion. @ref NPMX_CHARGER_TRICKLE_INVALID if given voltage is not
 *         represented in enumeration.
 */
npmx_charger_trickle_t npmx_charger_trickle_convert(uint32_t millivolts);

/**
 * @brief Function for converting @ref npmx_charger_trickle_t enumeration to millivolts.
 *
 * @param[in]  enum_value Voltage defined as @ref npmx_charger_trickle_t enumeration to be converted into millivolts.
 * @param[out] p_val      Pointer to the variable that stores the conversion result.
 * 
 * @retval true  Conversion is valid.
 * @retval false Conversion is invalid - an invalid argument was passed to the function.
 */
bool npmx_charger_trickle_convert_to_mv(npmx_charger_trickle_t enum_value, uint32_t * p_val);

/**
 * @brief Function for converting percentage value of charging current to @ref npmx_charger_iterm_t enumeration.
 *
 * @param[in] percent Termination current, as a percent of charging current, to be converted into
 *                    @ref npmx_charger_iterm_t enumeration.
 *
 * @return Result of conversion. @ref NPMX_CHARGER_ITERM_INVALID if given termination current
 *         is not represented in enumeration.
 */
npmx_charger_iterm_t npmx_charger_iterm_convert(uint32_t percent);

/**
 * @brief Function for converting percentage value of charging current to @ref npmx_charger_iterm_t enumeration.
 *
 * @param[in]  enum_value Termination current defined as @ref npmx_charger_iterm_t enumeration to be converted
 *                        into a percent of charging current.
 * @param[out] p_val      Pointer to the variable that stores the conversion result.
 * 
 * @retval true  Conversion is valid.
 * @retval false Conversion is invalid - an invalid argument was passed to the function.
 */
bool npmx_charger_iterm_convert_to_pct(npmx_charger_iterm_t enum_value, uint32_t * p_val);

/**
 * @brief Function for activating the specified charger task.
 *
 * @param[in] p_instance Pointer to the CHARGER instance.
 * @param[in] task       Task to be activated.
 *
 * @retval NPMX_SUCCESS  Operation performed successfully.
 * @retval NPMX_ERROR_IO Error using IO bus line.
 */
npmx_error_t npmx_charger_task_trigger(npmx_charger_t const * p_instance, npmx_charger_task_t task);

/**
 * @brief Function for enabling specified charger modules.
 *
 * @param[in] p_instance  Pointer to the CHARGER instance.
 * @param[in] module_mask Mask of modules to be enabled, variable composed of values from @ref npmx_charger_module_mask_t.
 *
 * @retval NPMX_SUCCESS  Operation performed successfully.
 * @retval NPMX_ERROR_IO Error using IO bus line.
 */
npmx_error_t npmx_charger_module_enable_set(npmx_charger_t const * p_instance,
                                            uint32_t               module_mask);

/**
 * @brief Function for disabling specified charger modules.
 *
 * @param[in] p_instance  Pointer to the CHARGER instance.
 * @param[in] module_mask Mask of modules to be disabled, variable composed of values from @ref npmx_charger_module_mask_t.
 *
 * @retval NPMX_SUCCESS  Operation performed successfully.
 * @retval NPMX_ERROR_IO Error using IO bus line.
 */
npmx_error_t npmx_charger_module_disable_set(npmx_charger_t const * p_instance,
                                             uint32_t               module_mask);

/**
 * @brief Function for checking which charger modules are enabled.
 *
 * @param[in]  p_instance     Pointer to the CHARGER instance.
 * @param[out] p_modules_mask Pointer to modules status variable composed of values from @ref npmx_charger_module_mask_t.
 *
 * @retval NPMX_SUCCESS  Operation performed successfully.
 * @retval NPMX_ERROR_IO Error using IO bus line.
 */
npmx_error_t npmx_charger_module_get(npmx_charger_t const * p_instance,
                                     uint32_t *             p_modules_mask);

/**
 * @brief Function for setting charger current of nPM device. Default value after reset is 32 mA.
 *
 * @note Charger has to be disabled before changing the current setting.
 *       The setting takes effect when charging is enabled or re-enabled.
 *
 * @param[in] p_instance Pointer to the CHARGER instance.
 * @param[in] current    Charger current in milliamperes in a range from 32 to 800 with a step of 2.
 *
 * @retval NPMX_SUCCESS             Operation performed successfully.
 * @retval NPMX_ERROR_INVALID_PARAM Current out of range.
 * @retval NPMX_ERROR_IO            Error using IO bus line.
 */
npmx_error_t npmx_charger_charging_current_set(npmx_charger_t * p_instance, uint16_t current);

/**
 * @brief Function for reading charger current from nPM device. Default value after reset is 32 mA.
 *
 * @param[in]  p_instance Pointer to the CHARGER instance.
 * @param[out] p_current  Pointer to the current variable.
 *                        Charger current in milliamperes in a range from 32 to 800 with a step of 2.
 *
 * @retval NPMX_SUCCESS  Operation performed successfully.
 * @retval NPMX_ERROR_IO Error using IO bus line.
 */
npmx_error_t npmx_charger_charging_current_get(npmx_charger_t * p_instance, uint16_t * p_current);

/**
 * @brief Function for setting maximum discharging current of nPM device. Default value after reset is 1000 mA.
 *
 * @param[in] p_instance Pointer to the CHARGER instance.
 * @param[in] current    Maximum discharging current in milliamperes in a range from 270 to 1340 with a step of 2.
 *
 * @retval NPMX_SUCCESS             Operation performed successfully.
 * @retval NPMX_ERROR_INVALID_PARAM Current out of range.
 * @retval NPMX_ERROR_IO            Error using IO bus line.
 */
npmx_error_t npmx_charger_discharging_current_set(npmx_charger_t * p_instance, uint16_t current);

/**
 * @brief Function for reading maximum discharging current of nPM device. Default value after reset is 1000 mA.
 *
 * @param[in]  p_instance Pointer to the CHARGER instance.
 * @param[out] p_current  Pointer to the current variable.
 *                        Maximum discharging current in milliamperes from in a range from 270 to 1340 with a step of 2.
 *
 * @retval NPMX_SUCCESS  Operation performed successfully.
 * @retval NPMX_ERROR_IO Error using IO bus line.
 */
npmx_error_t npmx_charger_discharging_current_get(npmx_charger_t * p_instance,
                                                  uint16_t *       p_current);

/**
 * @brief Function for setting the normal termination battery voltage.
 *
 * @note This termination voltage is used when battery is in cool or normal temperature region.
 *
 * @param[in] p_instance Pointer to the CHARGER instance.
 * @param[in] voltage    Voltage, in ranges 3.5-3.65 V or 4.0-4.45 V in 50 mV steps.
 *
 * @retval NPMX_SUCCESS  Operation performed successfully.
 * @retval NPMX_ERROR_IO Error using IO bus line.
 */
npmx_error_t npmx_charger_termination_normal_voltage_set(npmx_charger_t const * p_instance,
                                                         npmx_charger_voltage_t voltage);

/**
 * @brief Function for reading the normal termination battery voltage.
 *
 * @note This termination voltage is used when battery is in cool or normal temperature region.
 *
 * @param[in]  p_instance Pointer to the CHARGER instance.
 * @param[out] p_voltage  Pointer to the charger voltage variable.
 *
 * @retval NPMX_SUCCESS  Operation performed successfully.
 * @retval NPMX_ERROR_IO Error using IO bus line.
 */
npmx_error_t npmx_charger_termination_normal_voltage_get(npmx_charger_t const *   p_instance,
                                                         npmx_charger_voltage_t * p_voltage);

/**
 * @brief Function for setting the warm termination battery voltage.
 *
 * @note This termination voltage is used when battery is in warm temperature region.
 *
 * @param[in] p_instance Pointer to the CHARGER instance.
 * @param[in] voltage    Voltage, in ranges 3.5-3.65 V or 4.0-4.45 V in 50 mV steps.
 *
 * @retval NPMX_SUCCESS  Operation performed successfully.
 * @retval NPMX_ERROR_IO Error using IO bus line.
 */
npmx_error_t npmx_charger_termination_warm_voltage_set(npmx_charger_t const * p_instance,
                                                       npmx_charger_voltage_t voltage);

/**
 * @brief Function for reading the warm termination battery voltage.
 *
 * @note This termination voltage is used when battery is in warm temperature region.
 *
 * @param[in]  p_instance Pointer to the CHARGER instance.
 * @param[out] p_voltage  Pointer to the voltage variable.
 *
 * @retval NPMX_SUCCESS  Operation performed successfully.
 * @retval NPMX_ERROR_IO Error using IO bus line.
 */
npmx_error_t npmx_charger_termination_warm_voltage_get(npmx_charger_t const *   p_instance,
                                                       npmx_charger_voltage_t * p_voltage);

/**
 * @brief Function for setting the trickle voltage.
 *        Trickle charging is performed when VBAT < V_TRICKLE_FAST.
 *
 * @param[in] p_instance Pointer to the CHARGER instance.
 * @param[in] trickle    Trickle voltage value.
 *
 * @retval NPMX_SUCCESS  Operation performed successfully.
 * @retval NPMX_ERROR_IO Error using IO bus line.
 */
npmx_error_t npmx_charger_trickle_voltage_set(npmx_charger_t const * p_instance,
                                              npmx_charger_trickle_t trickle);

/**
 * @brief Function for reading the trickle voltage.
 *
 * @param[in]  p_instance Pointer to the CHARGER instance.
 * @param[out] p_trickle  Pointer to the trickle variable.
 *
 * @retval NPMX_SUCCESS  Operation performed successfully.
 * @retval NPMX_ERROR_IO Error using IO bus line.
 */
npmx_error_t npmx_charger_trickle_voltage_get(npmx_charger_t const *   p_instance,
                                              npmx_charger_trickle_t * p_trickle);

/**
 * @brief Function for setting the termination current ITERM.
 *        Trickle charging current I_TRICKLE is 10% or 20% of I_CHG (charging current).
 *
 * @param[in] p_instance Pointer to the CHARGER instance.
 * @param[in] iterm      Trickle charging percent value: 10% or 20%.
 *
 * @retval NPMX_SUCCESS  Operation performed successfully.
 * @retval NPMX_ERROR_IO Error using IO bus line.
 */
npmx_error_t npmx_charger_termination_current_set(npmx_charger_t const * p_instance,
                                                  npmx_charger_iterm_t   iterm);

/**
 * @brief Function for reading the termination current ITERM.
 *
 * @param[in]  p_instance Pointer to the CHARGER instance.
 * @param[out] p_iterm    Pointer to the iterm variable.
 *
 * @retval NPMX_SUCCESS  Operation performed successfully.
 * @retval NPMX_ERROR_IO Error using IO bus line.
 */
npmx_error_t npmx_charger_termination_current_get(npmx_charger_t const * p_instance,
                                                  npmx_charger_iterm_t * p_iterm);

/**
 * @brief Function for setting the NTC cold resistance threshold.
 *
 * @note Resistance value should be read from NTC characteristic for selected temperature.
 *
 * @param[in] p_instance Pointer to the CHARGER instance.
 * @param[in] resistance Resistance threshold in Ohms, value should be greater than 0.
 *
 * @retval NPMX_SUCCESS  Operation performed successfully.
 * @retval NPMX_ERROR_IO Error using IO bus line.
 */
npmx_error_t npmx_charger_cold_resistance_set(npmx_charger_t const * p_instance,
                                              uint32_t               resistance);

/**
 * @brief Function for reading the NTC cold resistance threshold.
 *
 * @param[in]  p_instance   Pointer to the CHARGER instance.
 * @param[out] p_resistance Pointer to the resistance variable in Ohms.
 *
 * @retval NPMX_SUCCESS  Operation performed successfully.
 * @retval NPMX_ERROR_IO Error using IO bus line.
 */
npmx_error_t npmx_charger_cold_resistance_get(npmx_charger_t const * p_instance,
                                              uint32_t *             p_resistance);

/**
 * @brief Function for setting the NTC cool resistance threshold.
 *
 * @note Resistance value should be read from NTC characteristic for selected temperature.
 *
 * @param[in] p_instance Pointer to the CHARGER instance.
 * @param[in] resistance Resistance threshold in Ohms, value should be greater than 0.
 *
 * @retval NPMX_SUCCESS  Operation performed successfully.
 * @retval NPMX_ERROR_IO Error using IO bus line.
 */
npmx_error_t npmx_charger_cool_resistance_set(npmx_charger_t const * p_instance,
                                              uint32_t               resistance);

/**
 * @brief Function for reading the NTC cool resistance threshold.
 *
 * @param[in]  p_instance   Pointer to the CHARGER instance.
 * @param[out] p_resistance Pointer to the resistance variable.
 *
 * @retval NPMX_SUCCESS  Operation performed successfully.
 * @retval NPMX_ERROR_IO Error using IO bus line.
 */
npmx_error_t npmx_charger_cool_resistance_get(npmx_charger_t const * p_instance,
                                              uint32_t *             p_resistance);

/**
 * @brief Function for setting the NTC warm resistance threshold.
 *
 * @note Resistance value should be read from NTC characteristic for selected temperature.
 *
 * @param[in] p_instance Pointer to the CHARGER instance.
 * @param[in] resistance Resistance threshold in Ohms, value should be greater than 0.
 *
 * @retval NPMX_SUCCESS  Operation performed successfully.
 * @retval NPMX_ERROR_IO Error using IO bus line.
 */
npmx_error_t npmx_charger_warm_resistance_set(npmx_charger_t const * p_instance,
                                              uint32_t               resistance);

/**
 * @brief Function for reading the NTC warm resistance threshold.
 *
 * @param[in]  p_instance   Pointer to the CHARGER instance.
 * @param[out] p_resistance Pointer to the resistance variable.
 *
 * @retval NPMX_SUCCESS  Operation performed successfully.
 * @retval NPMX_ERROR_IO Error using IO bus line.
 */
npmx_error_t npmx_charger_warm_resistance_get(npmx_charger_t const * p_instance,
                                              uint32_t *             p_resistance);

/**
 * @brief Function for setting the NTC hot resistance threshold.
 *
 * @note resistance value should be read from NTC characteristic for selected temperature.
 *
 * @param[in] p_instance Pointer to the CHARGER instance.
 * @param[in] resistance Resistance threshold in Ohms, value should be greater than 0.
 *
 * @retval NPMX_SUCCESS  Operation performed successfully.
 * @retval NPMX_ERROR_IO Error using IO bus line.
 */
npmx_error_t npmx_charger_hot_resistance_set(npmx_charger_t const * p_instance,
                                             uint32_t               resistance);

/**
 * @brief Function for reading the NTC hot resistance threshold.
 *
 * @param[in]  p_instance   Pointer to the CHARGER instance.
 * @param[out] p_resistance Pointer to the resistance variable.
 *
 * @retval NPMX_SUCCESS  Operation performed successfully.
 * @retval NPMX_ERROR_IO Error using IO bus line.
 */
npmx_error_t npmx_charger_hot_resistance_get(npmx_charger_t const * p_instance,
                                             uint32_t *             p_resistance);

/**
 * @brief Function for setting die temperature value when charging needs to be stopped.
 *
 * @param[in] p_instance  Pointer to the CHARGER instance.
 * @param[in] temperature Temperature in *C at which die stop threshold event happens.
 *
 * @retval NPMX_SUCCESS  Operation performed successfully.
 * @retval NPMX_ERROR_IO Error using IO bus line.
 */
npmx_error_t npmx_charger_die_temp_stop_set(npmx_charger_t const * p_instance,
                                            uint16_t               temperature);

/**
 * @brief Function for reading die temperature value when charging needs to be stopped.
 *
 * @param[in]  p_instance    Pointer to the CHARGER instance.
 * @param[out] p_temperature Pointer to the temperature variable.
 *
 * @retval NPMX_SUCCESS  Operation performed successfully.
 * @retval NPMX_ERROR_IO Error using IO bus line.
 */
npmx_error_t npmx_charger_die_temp_stop_get(npmx_charger_t const * p_instance,
                                            uint16_t *             p_temperature);

/**
 * @brief Function for setting die temperature value when charging needs to be resumed.
 *
 * @param[in] p_instance  Pointer to the CHARGER instance.
 * @param[in] temperature Temperature in *C at which die resume threshold event happens.
 *
 * @retval NPMX_SUCCESS  Operation performed successfully.
 * @retval NPMX_ERROR_IO Error using IO bus line.
 */
npmx_error_t npmx_charger_die_temp_resume_set(npmx_charger_t const * p_instance,
                                              uint16_t               temperature);

/**
 * @brief Function for reading die temperature value when charging needs to be resumed.
 *
 * @param[in]  p_instance    Pointer to the CHARGER instance.
 * @param[out] p_temperature Pointer to the temperature variable.
 *
 * @retval NPMX_SUCCESS  Operation performed successfully.
 * @retval NPMX_ERROR_IO Error using IO bus line.
 */
npmx_error_t npmx_charger_die_temp_resume_get(npmx_charger_t const * p_instance,
                                              uint16_t *             p_temperature);

/**
 * @brief Function for reading the status of a NTC comparator.
 *
 * @param[in]  p_instance   Pointer to the CHARGER instance.
 * @param[out] p_ntc_status Pointer to the NTC comparator status mask composed of values from @ref npmx_charger_ntc_status_mask_t.
 *
 * @retval NPMX_SUCCESS  Operation performed successfully.
 * @retval NPMX_ERROR_IO Error using IO bus line.
 */
npmx_error_t npmx_charger_ntc_status_get(npmx_charger_t const * p_instance, uint8_t * p_ntc_status);

/**
 * @brief Function for reading the status of a die temp comparator.
 *
 * @param[in]  p_instance        Pointer to the CHARGER instance.
 * @param[out] p_die_temp_status Pointer to the die temperature status variable. True for high die temperature.
 *
 * @retval NPMX_SUCCESS  Operation performed successfully.
 * @retval NPMX_ERROR_IO Error using IO bus line.
 */
npmx_error_t npmx_charger_die_temp_status_get(npmx_charger_t const * p_instance,
                                              bool *                 p_die_temp_status);

/**
 * @brief Function for reading the status of a current charger limiter.
 *
 * @param[in]  p_instance           Pointer to the CHARGER instance.
 * @param[out] p_current_lim_status Pointer to the current charger limiter status indicator. True if limiter is active.
 *
 * @retval NPMX_SUCCESS  Operation performed successfully.
 * @retval NPMX_ERROR_IO Error using IO bus line.
 */
npmx_error_t npmx_charger_current_limiter_get(npmx_charger_t const * p_instance,
                                              bool *                 p_current_lim_status);

/**
 * @brief Function for reading the charger status register.
 *
 * @param[in]  p_instance    Pointer to the CHARGER instance.
 * @param[out] p_status_mask Pointer to the charger status mask composed of values from @ref npmx_charger_status_mask_t.
 *
 * @retval NPMX_SUCCESS  Operation performed successfully.
 * @retval NPMX_ERROR_IO Error using IO bus line.
 */
npmx_error_t npmx_charger_status_get(npmx_charger_t const * p_instance, uint8_t * p_status_mask);

/**
 * @brief Function for checking charger errors and running registered callbacks.
 *
 * @note Function should be called when event charging error occurs.
 *
 * @param[in] p_instance Pointer to the CHARGER instance.
 *
 * @retval NPMX_SUCCESS  Operation performed successfully.
 * @retval NPMX_ERROR_IO Error using IO bus line.
 */
npmx_error_t npmx_charger_errors_check(npmx_charger_t const * p_instance);

/**
 * @brief Function for setting a specific charger configuration: disable charging if battery is warm.
 *
 * @param[in] p_instance Pointer to the CHARGER instance.
 * @param[in] disable    True for disabling the charging when battery is warm.
 *
 * @retval NPMX_SUCCESS  Operation performed successfully.
 * @retval NPMX_ERROR_IO Error using IO bus line.
 */
npmx_error_t npmx_charger_warm_disable_set(npmx_charger_t const * p_instance, bool disable);

/**
 * @brief Function for reading a specific charger configuration: disable charging if battery is warm.
 *
 * @param[in]  p_instance Pointer to the CHARGER instance.
 * @param[out] p_disable  Pointer to the temperature variable. True when charger disables charging if battery is warm.
 *
 * @retval NPMX_SUCCESS  Operation performed successfully.
 * @retval NPMX_ERROR_IO Error using IO bus line.
 */
npmx_error_t npmx_charger_warm_disable_get(npmx_charger_t const * p_instance, bool * p_disable);

/** @} */

#ifdef __cplusplus
}
#endif

#endif /* NPMX_CHARGER_H__ */
