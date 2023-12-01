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

#ifndef NPMX_INSTANCE_H__
#define NPMX_INSTANCE_H__

#include <npmx_event.h>

#include <npmx_adc.h>
#include <npmx_buck.h>
#include <npmx_charger.h>
#include <npmx_errlog.h>
#include <npmx_gpio.h>
#include <npmx_ldsw.h>
#include <npmx_led.h>
#include <npmx_pof.h>
#include <npmx_ship.h>
#include <npmx_timer.h>
#include <npmx_vbusin.h>

#ifdef __cplusplus
extern "C" {
#endif

/**
 * @defgroup npmx_instance INSTANCE
 * @{
 * @ingroup npmx_drivers
 *
 * @brief nPM device instance.
 */

/** @brief npmx struct definition. */
typedef struct npmx_instance
{
    void *           p_user_context;                                         ///< Pointer to user-defined context data.
    npmx_backend_t * p_backend;                                              ///< Pointer to specified backend instance used by this npmx instance to communicate with npmx device.

#if NPMX_CHECK(NPM_ADC_PRESENT) || defined(__NPMX_DOXYGEN__)
    npmx_adc_t adc[NPM_ADC_COUNT];                                   ///< ADC instances.
#endif

#if NPMX_CHECK(NPM_BUCK_PRESENT) || defined(__NPMX_DOXYGEN__)
    npmx_buck_t buck[NPM_BUCK_COUNT];                                ///< BUCK instances.
#endif

#if NPMX_CHECK(NPM_ERRLOG_PRESENT) || defined(__NPMX_DOXYGEN__)
    npmx_errlog_t errlog[NPM_ERRLOG_COUNT];                          ///< Error log instances.
#endif

#if NPMX_CHECK(NPM_GPIOS_PRESENT) || defined(__NPMX_DOXYGEN__)
    npmx_gpio_t gpio[NPM_GPIOS_COUNT];                               ///< GPIO instances.
#endif

#if NPMX_CHECK(NPM_LDSW_PRESENT) || defined(__NPMX_DOXYGEN__)
    npmx_ldsw_t ldsw[NPM_LDSW_COUNT];                                ///< LDSW instances.
#endif

#if NPMX_CHECK(NPM_LEDDRV_PRESENT) || defined(__NPMX_DOXYGEN__)
    npmx_led_t led[NPM_LEDDRV_COUNT];                                ///< LED instances.
#endif

#if NPMX_CHECK(NPM_POF_PRESENT) || defined(__NPMX_DOXYGEN__)
    npmx_pof_t pof[NPM_POF_COUNT];                                   ///< POF instances.
#endif

#if NPMX_CHECK(NPM_SHPHLD_PRESENT) || defined(__NPMX_DOXYGEN__)
    npmx_ship_t ship[NPM_SHPHLD_COUNT];                              ///< SHIP instances.
#endif

#if NPMX_CHECK(NPM_TIMER_PRESENT) || defined(__NPMX_DOXYGEN__)
    npmx_timer_t timer[NPM_TIMER_COUNT];                             ///< TIMER instances.
#endif

#if NPMX_CHECK(NPM_VBUSIN_PRESENT) || defined(__NPMX_DOXYGEN__)
    npmx_vbusin_t vbusin[NPM_VBUSIN_COUNT];                          ///< VBUSIN instances.
#endif

#if NPMX_CHECK(NPM_BCHARGER_PRESENT) || defined(__NPMX_DOXYGEN__)
    npmx_charger_t charger[NPM_BCHARGER_COUNT];                      ///< CHARGER instances.
#endif

    npmx_callback_t         generic_cb;                                      ///< Function used when @ref registered_cb for @ref npmx_callback_type_t is not set.
    npmx_callback_t         registered_cb[NPMX_CALLBACK_TYPE_COUNT];         ///< Table of registered callbacks.
    uint8_t                 event_group_enable_mask[NPMX_EVENT_GROUP_COUNT]; ///< Enabled events in specified events group, see npmx_event_group_xxx_t for selected event.
    bool                    interrupt;                                       ///< Flag set in interrupt to inform npmx_proc about incoming GPIO interrupt.
    bool                    restore_values;                                  ///< True for reading initial values from nPM device, false for setting default values.
} npmx_instance_t;

/** @} */

#ifdef __cplusplus
}
#endif

#endif /* NPMX_INSTANCE_H__ */
