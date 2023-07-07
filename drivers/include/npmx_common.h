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

#ifndef NPMX_COMMON_H__
#define NPMX_COMMON_H__

#include <npmx.h>

#ifdef __cplusplus
extern "C" {
#endif

typedef struct npmx_instance npmx_instance_t;

/**
 * @defgroup npmx_common COMMON
 * @{
 * @ingroup npmx_drivers
 *
 * @brief Common functions for nPM device drivers.
 */

/**
 * @brief Macro for checking if the specified identifier is defined and it has
 *        a non-zero value.
 *
 * Normally, preprocessors treat all undefined identifiers as having the value
 * of zero. However, some tools, like static code analyzers, can issue a warning
 * when such identifier is evaluated. This macro gives the possibility to suppress
 * such warnings only in places where this macro is used for evaluation, not in
 * the whole analyzed code.
 */
#define NPMX_CHECK(module_enabled) (module_enabled)

/** @brief Macro for getting peripheral register address. */
#define NPMX_REG_TO_ADDR(x) ((uint16_t)(size_t)(&(x)))

/** @brief Trigger value for all tasks. */
#define NPMX_TASK_TRIGGER 1U

/** @brief Invalid enum value. */
#define NPMX_INVALID_ENUM_VALUE UINT_MAX

/** @brief All possible callback types to be registered. */
typedef enum
{
    NPMX_CALLBACK_TYPE_EVENT_ADC,                         ///< Callback run when EVENTSADCSET register is not empty.
    NPMX_CALLBACK_TYPE_EVENT_BAT_CHAR_TEMP,               ///< Callback run when EVENTSBCHARGER0SET register is not empty.
    NPMX_CALLBACK_TYPE_EVENT_BAT_CHAR_STATUS,             ///< Callback run when EVENTSBCHARGER1SET register is not empty.
    NPMX_CALLBACK_TYPE_EVENT_BAT_CHAR_BAT,                ///< Callback run when EVENTSBCHARGER2SET register is not empty.
    NPMX_CALLBACK_TYPE_EVENT_SHIPHOLD,                    ///< Callback run when EVENTSSHPHLDSET register is not empty.
    NPMX_CALLBACK_TYPE_EVENT_VBUSIN_VOLTAGE,              ///< Callback run when EVENTSVBUSIN0SET register is not empty.
    NPMX_CALLBACK_TYPE_EVENT_VBUSIN_THERMAL_USB,          ///< Callback run when EVENTSVBUSIN1SET register is not empty.
    NPMX_CALLBACK_TYPE_EVENT_EVENTSGPIOSET,               ///< Callback run when EVENTSGPIOSET register is not empty.
    NPMX_CALLBACK_TYPE_RSTCAUSE,                          ///< Callback run when RSTCAUSE register is not empty.
    NPMX_CALLBACK_TYPE_CHARGER_ERROR,                     ///< Callback run when CHARGERERRREASON or BCHGERRREASON register is not empty.
    NPMX_CALLBACK_TYPE_SENSOR_ERROR,                      ///< Callback run when CHARGERERRSENSOR or BCHGERRSENSOR register is not empty.
    NPMX_CALLBACK_TYPE_COUNT,                             ///< Callbacks count.
    NPMX_CALLBACK_TYPE_INVALID = NPMX_INVALID_ENUM_VALUE, ///< Invalid callback type.
} npmx_callback_type_t;

/** @brief Callback function declaration. */
typedef void (*npmx_callback_t)(npmx_instance_t * p_pm, npmx_callback_type_t type, uint8_t mask);

/**
 * @brief Function for getting the callback name.
 *
 * @param[in] type The specified callback type.
 *
 * @return Pointer to the callback name.
 */
const char * npmx_callback_to_str(npmx_callback_type_t type);

/**
 * @brief Function for getting a name of a callback bit.
 *
 * @param[in] type The specified callback type.
 * @param[in] bit  The bit in callback register.
 *
 * @return Pointer to the bit name.
 */
const char * npmx_callback_bit_to_str(npmx_callback_type_t type, uint8_t bit);

/** @} */

#ifdef __cplusplus
}
#endif

#endif /* NPMX_COMMON_H__ */
