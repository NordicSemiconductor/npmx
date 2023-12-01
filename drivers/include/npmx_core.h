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

#ifndef NPMX_CORE_H__
#define NPMX_CORE_H__

#include <npmx.h>
#include <npmx_common.h>
#include <npmx_event.h>

#ifdef __cplusplus
extern "C" {
#endif

/**
 * @defgroup npmx_core CORE
 * @{
 * @ingroup npmx_drivers
 * @brief   Core events peripheral driver.
 */

/** @brief Main core tasks. */
typedef enum
{
    NPMX_CORE_TASK_RESET = offsetof(NPM_MAIN_Type, TASKSWRESET), ///< Turn off all power supplies and apply an internal reset.
} npmx_core_task_t;

/**
 * @brief Function for activating the specified main core task.
 *
 * @param p_pm Pointer to the instance of nPM device.
 * @param task Task to be activated.
 *
 * @retval NPMX_SUCCESS  Operation performed successfully.
 * @retval NPMX_ERROR_IO Error using IO bus line.
 */
npmx_error_t npmx_core_task_trigger(npmx_instance_t const * p_pm, npmx_core_task_t task);

/**
 * @brief Function for initialization of nPM device instance with default values.
 *        Should be called in setup function to avoid runtime errors.
 *
 * @param[in] p_pm             Pointer to the instance of nPM device.
 * @param[in] p_backend        Pointer to the initialized backend instance.
 * @param[in] generic_callback Function callback pointer to be registered as generic callback.
 * @param[in] restore_values   True if initial values are to be restored from nPM device, false for setting default values.
 *                             If true, scratch registers are used to store state and cannot be used by application.
 *
 * @retval NPMX_SUCCESS  Operation performed successfully.
 * @retval NPMX_ERROR_IO Error using IO bus line.
 */
npmx_error_t npmx_core_init(npmx_instance_t * p_pm,
                            npmx_backend_t *  p_backend,
                            npmx_callback_t   generic_callback,
                            bool              restore_values);

/**
 * @brief Function for registering callback handler to specified callback type event/error.
 *        If no callback is registered, generlic callback specified in pm->generic_cb is called.
 *
 * @param[in] p_pm Instance of nPM device.
 * @param[in] cb   Function callback pointer to be registered.
 * @param[in] type Type of registered function callback pointer.
 */
void npmx_core_register_cb(npmx_instance_t * p_pm, npmx_callback_t cb, npmx_callback_type_t type);

/**
 * @brief Function for signaling an interrupt.
 *
 * This function should be called when an interrupt associated with nPM
 * device's GPIO pin is handled, to register event from nPM device.
 *
 * @param[in] p_pm Pointer to the instance of nPM device.
 */
void npmx_core_interrupt(npmx_instance_t * p_pm);

/**
 * @brief Function for running in loop a task to handle all interrupts from nPM device.
 *
 * @param[in] p_pm Pointer to the instance of nPM device.
 *
 * @retval NPMX_SUCCESS  Operation performed successfully.
 * @retval NPMX_ERROR_IO Error using IO bus line.
 */
npmx_error_t npmx_core_proc(npmx_instance_t * p_pm);

/**
 * @brief Function for enabling event interrupt.
 *
 * @param[in] p_pm       Pointer to the instance of nPM device.
 * @param[in] event      Specified event group type.
 * @param[in] flags_mask Specified bits in event group, see npmx_event_group_xxx_t for selected event to be enabled.
 *
 * @retval NPMX_SUCCESS  Operation performed successfully.
 * @retval NPMX_ERROR_IO Error using IO bus line.
 */
npmx_error_t npmx_core_event_interrupt_enable(npmx_instance_t *  p_pm,
                                              npmx_event_group_t event,
                                              uint8_t            flags_mask);

/**
 * @brief Function for disabling and clearing event interrupt.
 *
 * @param[in] p_pm       Pointer to the instance of nPM device.
 * @param[in] event      Specified event group type.
 * @param[in] flags_mask Specified bits in event group, see npmx_event_group_xxx_t for selected event to be disabled.
 *
 * @retval NPMX_SUCCESS  Operation performed successfully.
 * @retval NPMX_ERROR_IO Error using IO bus line.
 */
npmx_error_t npmx_core_event_interrupt_disable(npmx_instance_t *  p_pm,
                                               npmx_event_group_t event,
                                               uint8_t            flags_mask);

/**
 * @brief Function for setting user-defined context data.
 *
 * @param[in] p_pm      Pointer to the instance of nPM device.
 * @param[in] p_context Pointer to context data.
 */
void npmx_core_context_set(npmx_instance_t * p_pm, void * p_context);

/**
 * @brief Function for getting user-defined context data.
 *
 * @param[in] p_pm Pointer to the instance of nPM device.
 *
 * @return Pointer to context data.
 */
void * npmx_core_context_get(npmx_instance_t * p_pm);

/** @} */

#ifdef __cplusplus
}
#endif

#endif /* NPMX_CORE_H__ */
