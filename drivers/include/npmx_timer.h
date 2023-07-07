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

#ifndef NPMX_TIMER_H__
#define NPMX_TIMER_H__

#include <npmx.h>

#ifdef __cplusplus
extern "C" {
#endif

/**
 * @defgroup npmx_timer TIMER
 * @{
 * @ingroup npmx_drivers
 * @brief   TIMER peripheral driver.
 */

/** @brief TIMER tasks. */
typedef enum
{
    NPMX_TIMER_TASK_ENABLE,  ///< Start timer.
    NPMX_TIMER_TASK_DISABLE, ///< Stop timer.
    NPMX_TIMER_TASK_STROBE,  ///< Load timer value from 24-bit timer's register.
    NPMX_TIMER_TASK_KICK,    ///< Kick watchdog.
    NPMX_TIMER_TASK_COUNT,   ///< Timer tasks count.
} npmx_timer_task_t;

/** @brief Available modes of the timer. */
typedef enum
{
    NPMX_TIMER_MODE_BOOT_MONITOR     = TIMER_TIMERCONFIG_TIMERMODESEL_BOOTMONITOR,     ///< Boot monitor.
    NPMX_TIMER_MODE_WATCHDOG_WARNING = TIMER_TIMERCONFIG_TIMERMODESEL_WATCHDOGWARNING, ///< Watchdog warning.
    NPMX_TIMER_MODE_WATCHDOG_RESET   = TIMER_TIMERCONFIG_TIMERMODESEL_WATCHDOGRESET,   ///< Watchdog reset.
    NPMX_TIMER_MODE_GENERAL_PURPOSE  = TIMER_TIMERCONFIG_TIMERMODESEL_GENPURPOSETIMER, ///< General purpose timer.
    NPMX_TIMER_MODE_WAKEUP           = TIMER_TIMERCONFIG_TIMERMODESEL_WAKEUPTIMER,     ///< Wake-up timer.
    NPMX_TIMER_MODE_COUNT,                                                             ///< Timer modes count.
    NPMX_TIMER_MODE_INVALID          = NPMX_INVALID_ENUM_VALUE,                        ///< Invalid timer mode.
} npmx_timer_mode_t;

/** @brief Switches between 64 Hz and 512 Hz timer clock . */
typedef enum
{
    NPMX_TIMER_PRESCALER_SLOW    = TIMER_TIMERCONFIG_TIMERPRESCALER_SLOW, ///< Timer clock set to 64 Hz.
    NPMX_TIMER_PRESCALER_FAST    = TIMER_TIMERCONFIG_TIMERPRESCALER_FAST, ///< Timer clock set to 512 Hz.
    NPMX_TIMER_PRESCALER_COUNT,                                           ///< Timer prescalers count.
    NPMX_TIMER_PRESCALER_INVALID = NPMX_INVALID_ENUM_VALUE,               ///< Invalid timer prescaler.
} npmx_timer_prescaler_t;

/** @brief Data structure of the TIMER driver instance. */
typedef struct
{
    npmx_backend_t * p_backend; ///< Pointer to backend instance.
} npmx_timer_t;

/** @brief Configuration structure for timer. */
typedef struct
{
    npmx_timer_mode_t      mode;          ///< Mode of the timer.
    npmx_timer_prescaler_t prescaler;     ///< Prescaler value to use.
    uint32_t               compare_value; ///< Timer's 24 bits counter compare value.
} npmx_timer_config_t;

/** @brief Timer status structure. */
typedef struct
{
    bool boot_monitor;       ///< Boot monitor running.
    bool slow_domain_config; ///< Slow domain configuration status.
} npmx_timer_status_t;

/**
 * @brief Function for returning TIMER instance based on index.
 *
 * @param[in] p_pmic Pointer to the PMIC instance.
 * @param[in] idx    Index of the TIMER instance.
 *
 * @return Pointer to the TIMER instance.
 */
npmx_timer_t * npmx_timer_get(npmx_instance_t * p_pmic, uint8_t idx);

/**
 * @brief Function for activating the specified TIMER task.
 *
 * @param p_instance Pointer to the TIMER instance.
 * @param task       Task to be activated.
 *
 * @retval NPMX_SUCCESS  Operation performed successfully.
 * @retval NPMX_ERROR_IO Error using IO bus line.
 */
npmx_error_t npmx_timer_task_trigger(npmx_timer_t const * p_instance, npmx_timer_task_t task);

/**
 * @brief Function for setting timer's configuration with mode, prescaler, and compare value.
 *
 * @note To apply compare value, call @ref npmx_timer_task_trigger() with @ref NPMX_TIMER_TASK_STROBE argument.
 *
 * @param[in] p_instance Pointer to the TIMER instance.
 * @param[in] p_config   Pointer to the configuration of the TIMER to apply.
 *
 * @retval NPMX_SUCCESS  Operation performed successfully.
 * @retval NPMX_ERROR_IO Error using IO bus line.
 */
npmx_error_t npmx_timer_config_set(npmx_timer_t const *        p_instance,
                                   npmx_timer_config_t const * p_config);

/**
 * @brief Function for reading the ADC configuration.
 *
 * @param[in]  p_instance Pointer to the ADC instance.
 * @param[out] p_config   Pointer to the ADC configuration structure.
 *
 * @retval NPMX_SUCCESS  Operation performed successfully.
 * @retval NPMX_ERROR_IO Error using IO bus line.
 */
npmx_error_t npmx_timer_config_get(npmx_timer_t const * p_instance, npmx_timer_config_t * p_config);

/**
 * @brief Function for getting TIMER status.
 *
 * @param[in]  p_instance Pointer to the TIMER instance.
 * @param[out] p_status   Pointer to the structure to be filled with TIMER status.
 *
 * @retval NPMX_SUCCESS  Operation performed successfully.
 * @retval NPMX_ERROR_IO Error using IO bus line.
 */
npmx_error_t npmx_timer_status_get(npmx_timer_t const *  p_instance,
                                   npmx_timer_status_t * p_status);

/** @} */

#ifdef __cplusplus
}
#endif

#endif /* NPMX_TIMER_H__ */
