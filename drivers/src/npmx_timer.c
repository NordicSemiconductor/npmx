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

#include <npmx_timer.h>
#include <npmx_instance.h>

/** @brief Macros used to get timer bytes from 24 bits variable. */
#define NPMX_TIMER_COUNTER_PERIOD_HI_BYTE_MASK  0xFF0000UL
#define NPMX_TIMER_COUNTER_PERIOD_HI_BYTE_POS   16UL

#define NPMX_TIMER_COUNTER_PERIOD_MID_BYTE_MASK 0x00FF00UL
#define NPMX_TIMER_COUNTER_PERIOD_MID_BYTE_POS  8UL

#define NPMX_TIMER_COUNTER_PERIOD_LO_BYTE_MASK  0x0000FFUL
#define NPMX_TIMER_COUNTER_PERIOD_LO_BYTE_POS   0UL

static npmx_error_t task_trigger(npmx_timer_t const * p_instance, npmx_timer_task_t task)
{
    uint8_t data = NPMX_TASK_TRIGGER;

    static const uint16_t task_addr[NPMX_TIMER_TASK_COUNT] =
    {
        [NPMX_TIMER_TASK_ENABLE]  = NPMX_REG_TO_ADDR(NPM_TIMER->TIMERSET),
        [NPMX_TIMER_TASK_DISABLE] = NPMX_REG_TO_ADDR(NPM_TIMER->TIMERCLR),
        [NPMX_TIMER_TASK_STROBE]  = NPMX_REG_TO_ADDR(NPM_TIMER->TIMERTARGETSTROBE),
        [NPMX_TIMER_TASK_KICK]    = NPMX_REG_TO_ADDR(NPM_TIMER->WATCHDOGKICK),
    };

    return npmx_backend_register_write(p_instance->p_backend, task_addr[task], &data, 1);
}

npmx_timer_t * npmx_timer_get(npmx_instance_t * p_pmic, uint8_t idx)
{
    NPMX_ASSERT(p_pmic);
    NPMX_ASSERT(idx < NPM_TIMER_COUNT);

    return &p_pmic->timer[idx];
}

npmx_error_t npmx_timer_task_trigger(npmx_timer_t const * p_instance, npmx_timer_task_t task)
{
    NPMX_ASSERT(p_instance);
    NPMX_ASSERT(task < NPMX_TIMER_TASK_COUNT);

    return task_trigger(p_instance, task);
}

npmx_error_t npmx_timer_config_set(npmx_timer_t const *        p_instance,
                                   npmx_timer_config_t const * p_config)
{
    NPMX_ASSERT(p_instance);
    NPMX_ASSERT(p_config);
    NPMX_ASSERT(p_config->mode < NPMX_TIMER_MODE_COUNT);
    NPMX_ASSERT(p_config->prescaler < NPMX_TIMER_PRESCALER_COUNT);
    NPMX_ASSERT(p_config->compare_value <= NPM_TIMER_COUNTER_COMPARE_VALUE_MAX);

    uint8_t data = ((uint8_t)p_config->mode << TIMER_TIMERCONFIG_TIMERMODESEL_Pos) &
                   TIMER_TIMERCONFIG_TIMERMODESEL_Msk;

    data |= ((uint8_t)p_config->prescaler << TIMER_TIMERCONFIG_TIMERPRESCALER_Pos) &
            TIMER_TIMERCONFIG_TIMERPRESCALER_Msk;

    npmx_error_t err_code = npmx_backend_register_write(p_instance->p_backend,
                                                        NPMX_REG_TO_ADDR(NPM_TIMER->TIMERCONFIG),
                                                        &data,
                                                        1);
    if (err_code != NPMX_SUCCESS)
    {
        return err_code;
    }

    uint8_t period_data[3];

    period_data[0] = (uint8_t)((p_config->compare_value & NPMX_TIMER_COUNTER_PERIOD_HI_BYTE_MASK)
                               >> NPMX_TIMER_COUNTER_PERIOD_HI_BYTE_POS);
    period_data[1] = (uint8_t)((p_config->compare_value & NPMX_TIMER_COUNTER_PERIOD_MID_BYTE_MASK)
                               >> NPMX_TIMER_COUNTER_PERIOD_MID_BYTE_POS);
    period_data[2] = (uint8_t)((p_config->compare_value & NPMX_TIMER_COUNTER_PERIOD_LO_BYTE_MASK)
                               >> NPMX_TIMER_COUNTER_PERIOD_LO_BYTE_POS);

    err_code = npmx_backend_register_write(p_instance->p_backend,
                                           NPMX_REG_TO_ADDR(NPM_TIMER->TIMERHIBYTE),
                                           period_data,
                                           3);
    if (err_code != NPMX_SUCCESS)
    {
        return err_code;
    }

    return task_trigger(p_instance, NPMX_TIMER_TASK_STROBE);
}

npmx_error_t npmx_timer_config_get(npmx_timer_t const * p_instance, npmx_timer_config_t * p_config)
{
    NPMX_ASSERT(p_instance);
    NPMX_ASSERT(p_config);

    uint8_t      data;
    uint8_t      period_data[3];
    npmx_error_t err_code = npmx_backend_register_read(p_instance->p_backend,
                                                       NPMX_REG_TO_ADDR(NPM_TIMER->TIMERCONFIG),
                                                       &data,
                                                       1);
    if (err_code != NPMX_SUCCESS)
    {
        return err_code;
    }

    err_code = npmx_backend_register_read(p_instance->p_backend,
                                          NPMX_REG_TO_ADDR(NPM_TIMER->TIMERHIBYTE),
                                          period_data,
                                          3);
    if (err_code != NPMX_SUCCESS)
    {
        return err_code;
    }

    p_config->mode = (npmx_timer_mode_t)((data & TIMER_TIMERCONFIG_TIMERMODESEL_Msk)
                                         >> TIMER_TIMERCONFIG_TIMERMODESEL_Pos);

    p_config->prescaler = (npmx_timer_prescaler_t)((data & TIMER_TIMERCONFIG_TIMERPRESCALER_Msk)
                                                   >> TIMER_TIMERCONFIG_TIMERPRESCALER_Pos);

    p_config->compare_value  = (uint32_t)period_data[2] << NPMX_TIMER_COUNTER_PERIOD_LO_BYTE_POS;
    p_config->compare_value |= (uint32_t)period_data[1] << NPMX_TIMER_COUNTER_PERIOD_MID_BYTE_POS;
    p_config->compare_value |= (uint32_t)period_data[0] << NPMX_TIMER_COUNTER_PERIOD_HI_BYTE_POS;

    return NPMX_SUCCESS;
}

npmx_error_t npmx_timer_status_get(npmx_timer_t const *  p_instance,
                                   npmx_timer_status_t * p_status)
{
    NPMX_ASSERT(p_instance);
    NPMX_ASSERT(p_status);

    uint8_t      data;
    npmx_error_t err_code = npmx_backend_register_read(p_instance->p_backend,
                                                       NPMX_REG_TO_ADDR(NPM_TIMER->TIMERSTATUS),
                                                       &data,
                                                       1);
    if (err_code != NPMX_SUCCESS)
    {
        return err_code;
    }

    p_status->boot_monitor = ((data & TIMER_TIMERSTATUS_BOOTMONITORACTIVE_Msk)
                              >> TIMER_TIMERSTATUS_BOOTMONITORACTIVE_Pos)
                             == TIMER_TIMERSTATUS_BOOTMONITORACTIVE_ACTIVE ? true : false;

    p_status->slow_domain_config = ((data & TIMER_TIMERSTATUS_SLOWDOMAINCONFIGURED_Msk)
                                    >> TIMER_TIMERSTATUS_SLOWDOMAINCONFIGURED_Pos)
                                   == TIMER_TIMERSTATUS_SLOWDOMAINCONFIGURED_CONFIG ?
                                   true : false;

    return NPMX_SUCCESS;
}
