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

#include <npmx_core.h>
#include <npmx_instance.h>

#define NPMX_CORE_EVENTS_EVENT_CLEAR_OFFSET \
      (offsetof(NPM_MAIN_Type, EVENTSADCCLR) - offsetof(NPM_MAIN_Type, EVENTSADCSET))      ///< Clear register address offset from SET register, in bytes.
#define NPMX_CORE_EVENTS_INTERRUPT_ENABLE_SET_OFFSET \
      (offsetof(NPM_MAIN_Type, INTENEVENTSADCSET) - offsetof(NPM_MAIN_Type, EVENTSADCSET)) ///< Interrupt Enable Set register address offset from SET register, in bytes.
#define NPMX_CORE_EVENTS_INTERRUPT_ENABLE_CLEAR_OFFSET \
      (offsetof(NPM_MAIN_Type, INTENEVENTSADCCLR) - offsetof(NPM_MAIN_Type, EVENTSADCSET)) ///< Interrupt Enable Clear register address offset from SET register, in bytes.

/**
 * @brief Get the event callback based on event group.
 *
 * @param[in] event Specified event group.
 *
 * @return Callback type.
 */
static npmx_callback_type_t event_callback_get(npmx_event_group_t event)
{
    static const npmx_callback_type_t callbacks_tab[NPMX_EVENT_GROUP_COUNT] =
    {
        [NPMX_EVENT_GROUP_ADC]             = NPMX_CALLBACK_TYPE_EVENT_ADC,
        [NPMX_EVENT_GROUP_BAT_CHAR_TEMP]   = NPMX_CALLBACK_TYPE_EVENT_BAT_CHAR_TEMP,
        [NPMX_EVENT_GROUP_BAT_CHAR_STATUS] = NPMX_CALLBACK_TYPE_EVENT_BAT_CHAR_STATUS,
        [NPMX_EVENT_GROUP_BAT_CHAR_BAT]    = NPMX_CALLBACK_TYPE_EVENT_BAT_CHAR_BAT,
        [NPMX_EVENT_GROUP_SHIPHOLD]        = NPMX_CALLBACK_TYPE_EVENT_SHIPHOLD,
        [NPMX_EVENT_GROUP_VBUSIN_VOLTAGE]  = NPMX_CALLBACK_TYPE_EVENT_VBUSIN_VOLTAGE,
        [NPMX_EVENT_GROUP_VBUSIN_THERMAL]  = NPMX_CALLBACK_TYPE_EVENT_VBUSIN_THERMAL_USB,
        [NPMX_EVENT_GROUP_GPIO]            = NPMX_CALLBACK_TYPE_EVENT_EVENTSGPIOSET,
    };

    return callbacks_tab[event];
}

/**
 * @brief Get the address of Set register for specified event group.
 *
 * @param[in] event Specified event group.
 *
 * @return The address of Set register.
 */
static uint16_t event_set_register_get(npmx_event_group_t event)
{
    static const uint16_t registers_tab[NPMX_EVENT_GROUP_COUNT] =
    {
        [NPMX_EVENT_GROUP_ADC]             = NPMX_REG_TO_ADDR(NPM_MAIN->EVENTSADCSET),
        [NPMX_EVENT_GROUP_BAT_CHAR_TEMP]   = NPMX_REG_TO_ADDR(NPM_MAIN->EVENTSBCHARGER0SET),
        [NPMX_EVENT_GROUP_BAT_CHAR_STATUS] = NPMX_REG_TO_ADDR(NPM_MAIN->EVENTSBCHARGER1SET),
        [NPMX_EVENT_GROUP_BAT_CHAR_BAT]    = NPMX_REG_TO_ADDR(NPM_MAIN->EVENTSBCHARGER2SET),
        [NPMX_EVENT_GROUP_SHIPHOLD]        = NPMX_REG_TO_ADDR(NPM_MAIN->EVENTSSHPHLDSET),
        [NPMX_EVENT_GROUP_VBUSIN_VOLTAGE]  = NPMX_REG_TO_ADDR(NPM_MAIN->EVENTSVBUSIN0SET),
        [NPMX_EVENT_GROUP_VBUSIN_THERMAL]  = NPMX_REG_TO_ADDR(NPM_MAIN->EVENTSVBUSIN1SET),
        [NPMX_EVENT_GROUP_GPIO]            = NPMX_REG_TO_ADDR(NPM_MAIN->EVENTSGPIOSET),
    };

    return registers_tab[event];
}

/**
 * @brief Get the address of Interrupt Enable register for specified event group.
 *
 * @param[in] event Specified event group.
 *
 * @return The address of Interrupt Enable register.
 */
static uint16_t event_irq_enable_register_get(npmx_event_group_t event)
{
    return event_set_register_get(event) + NPMX_CORE_EVENTS_INTERRUPT_ENABLE_SET_OFFSET;
}

/**
 * @brief Get the address of Interrupt Clear (Disable) register for specified event group
 *
 * @param[in] event Specified event group.
 *
 * @return The address of Interrupt Clear (Disable) register.
 */
static uint16_t event_irq_disable_register_get(npmx_event_group_t event)
{
    return event_set_register_get(event) + NPMX_CORE_EVENTS_INTERRUPT_ENABLE_CLEAR_OFFSET;
}

/**
 * @brief Get the address of Clear register for specified event group.
 *
 * @param[in] event Specified event group.
 *
 * @return The address of Clear register.
 */
static uint16_t event_clear_register_get(npmx_event_group_t event)
{
    return event_set_register_get(event) + NPMX_CORE_EVENTS_EVENT_CLEAR_OFFSET;
}

/**
 * @brief Get events field from specified event group.
 *
 * @param[in]  p_pm         The pointer to the instance of nPM device.
 * @param[in]  event        Specified event group type.
 * @param[out] p_flags_mask The pointer to the flags variable, NPMX_event_group_xxx_t for selected event group.
 *
 * @retval NPMX_SUCCESS  Operation performed successfully.
 * @retval NPMX_ERROR_IO Error using IO bus line.
 */
static npmx_error_t event_get(npmx_instance_t *  p_pm,
                              npmx_event_group_t event,
                              uint8_t *          p_flags_mask)
{
    return npmx_backend_register_read(p_pm->p_backend,
                                      event_set_register_get(event),
                                      p_flags_mask,
                                      1);
}

/**
 * @brief Clear event fields in specified event group.
 * @param[in] p_pm       The pointer to the instance of nPM device.
 * @param[in] event      Specified event group type.
 * @param[in] flags_mask Specified bit flags for event group type.
 *
 * @retval NPMX_SUCCESS  Operation performed successfully.
 * @retval NPMX_ERROR_IO Error using IO bus line.
 */
static npmx_error_t event_clear(npmx_instance_t *  p_pm,
                                npmx_event_group_t event,
                                uint8_t            flags_mask)
{
    uint16_t reg = event_clear_register_get(event);

    return npmx_backend_register_write(p_pm->p_backend, reg, &flags_mask, 1);
}

/**
 * @brief Check if any registered event in event group happened on nPM device.
 *
 * @param[in] p_pm The pointer to the instance of nPM device.
 *
 * @retval NPMX_SUCCESS  Operation performed successfully.
 * @retval NPMX_ERROR_IO Error using IO bus line.
 */
static npmx_error_t check_events(npmx_instance_t * p_pm)
{
    uint8_t         flags_mask;
    npmx_callback_t cb;
    npmx_error_t    err_code;

    for (uint8_t i = 0; i < NPMX_EVENT_GROUP_COUNT; i++)
    {
        if (p_pm->event_group_enable_mask[i] == 0)  /* Skip checking unregistered event group. */
        {
            continue;
        }

        err_code = event_get(p_pm, (npmx_event_group_t)i, &flags_mask);
        if (err_code != NPMX_SUCCESS)
        {
            return err_code;
        }

        flags_mask &= p_pm->event_group_enable_mask[i];

        if (flags_mask)
        {
            err_code = event_clear(p_pm, (npmx_event_group_t)i, flags_mask);
            if (err_code != NPMX_SUCCESS)
            {
                return err_code;
            }

            cb = p_pm->registered_cb[event_callback_get((npmx_event_group_t)i)];
            if (cb)
            {
                cb(p_pm, event_callback_get((npmx_event_group_t)i), flags_mask);
            }
        }
    }

    return NPMX_SUCCESS;
}

npmx_error_t npmx_core_task_trigger(npmx_instance_t const * p_pm, npmx_core_task_t task)
{
    NPMX_ASSERT(p_pm);

    uint8_t data = NPMX_TASK_TRIGGER;

    static const uint16_t task_addr[] =
    {
        [NPMX_CORE_TASK_RESET] = NPMX_REG_TO_ADDR(NPM_MAIN->TASKSWRESET),
    };

    return npmx_backend_register_write(p_pm->p_backend, task_addr[task], &data, 1);
}

npmx_error_t npmx_core_init(npmx_instance_t * p_pm,
                            npmx_backend_t *  p_backend,
                            npmx_callback_t   generic_callback,
                            bool              restore_values)
{
    NPMX_ASSERT(p_pm);
    NPMX_ASSERT(p_backend);

    p_pm->p_backend = p_backend;

#if NPMX_CHECK(NPM_ADC_PRESENT)
    for (uint8_t i = 0; i < NPM_ADC_COUNT; i++)
    {
        p_pm->adc[i].p_pmic = p_pm;
        if (restore_values)
        {
            npmx_adc_t * adc = npmx_adc_get(p_pm, i);
            npmx_adc_config_t adc_config;
            npmx_error_t ret = npmx_adc_config_get(adc, &adc_config);
            if (ret != NPMX_SUCCESS)
            {
                return ret;
            }

            npmx_adc_ntc_config_t ntc_config;
            ret = npmx_adc_ntc_config_get(adc, &ntc_config);
            if (ret != NPMX_SUCCESS)
            {
                return ret;
            }
        }
        else
        {
            p_pm->adc[i].burst    = false;
            p_pm->adc[i].ntc_beta = 3380;
        }
    }
#endif

#if NPMX_CHECK(NPM_BUCK_PRESENT)
    for (uint8_t i = 0; i < NPM_BUCK_COUNT; i++)
    {
        p_pm->buck[i].p_backend = p_backend;
        p_pm->buck[i].hw_index  = i;
    }
#endif

#if NPMX_CHECK(NPM_BCHARGER_PRESENT)
    for (uint8_t i = 0; i < NPM_BCHARGER_COUNT; i++)
    {
        p_pm->charger[i].p_pmic = p_pm;
        if (restore_values)
        {
            uint16_t current;
            npmx_charger_t * charger = npmx_charger_get(p_pm, i);
            npmx_error_t ret = npmx_charger_charging_current_get(charger, &current);
            if (ret != NPMX_SUCCESS)
            {
                return ret;
            }

            ret = npmx_charger_discharging_current_get(charger, &current);
            if (ret != NPMX_SUCCESS)
            {
                return ret;
            }
        }
        else
        {
            p_pm->charger[i].charging_current_ma    = NPM_BCHARGER_CHARGING_CURRENT_DEFAULT;
            p_pm->charger[i].discharging_current_ma = NPM_BCHARGER_DISCHARGING_CURRENT_DEFAULT;
        }
    }
#endif

#if NPMX_CHECK(NPM_ERRLOG_PRESENT)
    for (uint8_t i = 0; i < NPM_ERRLOG_COUNT; i++)
    {
        p_pm->errlog[i].p_pmic = p_pm;
    }
#endif

#if NPMX_CHECK(NPM_GPIOS_PRESENT)
    for (uint8_t i = 0; i < NPM_GPIOS_COUNT; i++)
    {
        p_pm->gpio[i].p_backend = p_backend;
        p_pm->gpio[i].hw_index  = i;
    }
#endif

#if NPMX_CHECK(NPM_LDSW_PRESENT)
    for (uint8_t i = 0; i < NPM_LDSW_COUNT; i++)
    {
        p_pm->ldsw[i].p_backend = p_backend;
        p_pm->ldsw[i].hw_index  = i;
    }
#endif

#if NPMX_CHECK(NPM_LEDDRV_PRESENT)
    for (uint8_t i = 0; i < NPM_LEDDRV_COUNT; i++)
    {
        p_pm->led[i].p_backend = p_backend;
        p_pm->led[i].hw_index  = i;
    }
#endif

#if NPMX_CHECK(NPM_POF_PRESENT)
    for (uint8_t i = 0; i < NPM_POF_COUNT; i++)
    {
        p_pm->pof[i].p_backend = p_backend;
    }
#endif

#if NPMX_CHECK(NPM_SHPHLD_PRESENT)
    for (uint8_t i = 0; i < NPM_SHPHLD_COUNT; i++)
    {
        p_pm->ship[i].p_backend = p_backend;
        if (restore_values)
        {
            npmx_ship_t * ship = npmx_ship_get(p_pm, i);
            npmx_ship_config_t ship_config;
            npmx_error_t ret = npmx_ship_config_get(ship, &ship_config);
            if (ret != NPMX_SUCCESS)
            {
                return ret;
            }
        }
        else
        {
            p_pm->ship[i].ship_button_inverted = false;
        }
    }
#endif

#if NPMX_CHECK(NPM_TIMER_PRESENT)
    for (uint8_t i = 0; i < NPM_TIMER_COUNT; i++)
    {
        p_pm->timer[i].p_backend = p_backend;
    }
#endif

#if NPMX_CHECK(NPM_VBUSIN_PRESENT)
    for (uint8_t i = 0; i < NPM_VBUSIN_COUNT; i++)
    {
        p_pm->vbusin[i].p_backend = p_backend;
    }
#endif

    p_pm->interrupt  = false;
    p_pm->generic_cb = generic_callback;

    for (uint32_t i = 0; i < NPMX_CALLBACK_TYPE_COUNT; i++)
    {
        p_pm->registered_cb[i] = generic_callback;
    }

    p_pm->p_user_context = NULL;
    p_pm->restore_values = restore_values;

    return NPMX_SUCCESS;
}

void npmx_core_register_cb(npmx_instance_t * p_pm, npmx_callback_t cb, npmx_callback_type_t type)
{
    NPMX_ASSERT(p_pm);
    NPMX_ASSERT(cb);
    NPMX_ASSERT(type < NPMX_CALLBACK_TYPE_COUNT);

    p_pm->registered_cb[type] = cb;
}

void npmx_core_interrupt(npmx_instance_t * p_pm)
{
    NPMX_ASSERT(p_pm);

    p_pm->interrupt = true;
}

npmx_error_t npmx_core_proc(npmx_instance_t * p_pm)
{
    NPMX_ASSERT(p_pm);

    npmx_error_t err_code;

    if (p_pm->interrupt)
    {
        p_pm->interrupt = false;
        err_code        = check_events(p_pm);
        if (err_code != NPMX_SUCCESS)
        {
            return err_code;
        }
    }

    return NPMX_SUCCESS;
}

npmx_error_t npmx_core_event_interrupt_enable(npmx_instance_t *  p_pm,
                                              npmx_event_group_t event,
                                              uint8_t            flags_mask)
{
    NPMX_ASSERT(p_pm);
    NPMX_ASSERT(event < NPMX_EVENT_GROUP_COUNT);

    npmx_error_t err_code = event_clear(p_pm, event, flags_mask);
    if (err_code != NPMX_SUCCESS)
    {
        return err_code;
    }

    p_pm->event_group_enable_mask[event] = flags_mask;
    uint16_t reg = event_irq_enable_register_get(event);

    return npmx_backend_register_write(p_pm->p_backend, reg, &flags_mask, 1);
}

npmx_error_t npmx_core_event_interrupt_disable(npmx_instance_t *  p_pm,
                                               npmx_event_group_t event,
                                               uint8_t            flags_mask)
{
    NPMX_ASSERT(p_pm);
    NPMX_ASSERT(event < NPMX_EVENT_GROUP_COUNT);

    p_pm->event_group_enable_mask[event] &= ~flags_mask;
    uint16_t reg = event_irq_disable_register_get(event);

    npmx_error_t err_code = npmx_backend_register_write(p_pm->p_backend, reg, &flags_mask, 1);
    if (err_code != NPMX_SUCCESS)
    {
        return err_code;
    }

    return event_clear(p_pm, event, flags_mask);
}

void npmx_core_context_set(npmx_instance_t * p_pm, void * p_context)
{
    NPMX_ASSERT(p_pm);
    NPMX_ASSERT(p_context);

    p_pm->p_user_context = p_context;
}

void * npmx_core_context_get(npmx_instance_t * p_pm)
{
    NPMX_ASSERT(p_pm);

    return p_pm->p_user_context;
}
