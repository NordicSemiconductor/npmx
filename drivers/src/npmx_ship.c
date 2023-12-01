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

#include <npmx_ship.h>
#include <npmx_instance.h>

/**
 * @brief Function for activating the specified SHIP task.
 *
 * @param p_instance Pointer to the SHIP instance.
 * @param task       Task to be activated.
 *
 * @retval NPMX_SUCCESS  Operation performed successfully.
 * @retval NPMX_ERROR_IO Error using IO bus line.
 */
static npmx_error_t task_trigger(npmx_ship_t const * p_instance, npmx_ship_task_t task)
{
    uint8_t data = NPMX_TASK_TRIGGER;

    static const uint16_t task_addr[] =
    {
        [NPMX_SHIP_TASK_HIBERNATE]       = NPMX_REG_TO_ADDR(NPM_SHIP->TASKENTERHIBERNATE),
        [NPMX_SHIP_TASK_CONFIG_SHIPHOLD] = NPMX_REG_TO_ADDR(NPM_SHIP->TASKSHPHLDCFGSTROBE),
        [NPMX_SHIP_TASK_SHIPMODE]        = NPMX_REG_TO_ADDR(NPM_SHIP->TASKENTERSHIPMODE),
        [NPMX_SHIP_TASK_CONFIG_RESET]    = NPMX_REG_TO_ADDR(NPM_SHIP->TASKRESETCFG),
    };

    return npmx_backend_register_write(p_instance->p_backend, task_addr[task], &data, 1);
}

npmx_ship_t * npmx_ship_get(npmx_instance_t * p_pmic, uint8_t idx)
{
    NPMX_ASSERT(p_pmic);
    NPMX_ASSERT(idx < NPM_SHPHLD_COUNT);

    return &p_pmic->ship[idx];
}

npmx_ship_time_t npmx_ship_time_convert(uint32_t time_ms)
{
    switch (time_ms)
    {
        case 16:
            return NPMX_SHIP_TIME_16_MS;
        case 32:
            return NPMX_SHIP_TIME_32_MS;
        case 64:
            return NPMX_SHIP_TIME_64_MS;
        case 96:
            return NPMX_SHIP_TIME_96_MS;
        case 304:
            return NPMX_SHIP_TIME_304_MS;
        case 608:
            return NPMX_SHIP_TIME_608_MS;
        case 1008:
            return NPMX_SHIP_TIME_1008_MS;
        case 3008:
            return NPMX_SHIP_TIME_3008_MS;
        default:
            return NPMX_SHIP_TIME_INVALID;
    }
}

bool npmx_ship_time_convert_to_ms(npmx_ship_time_t enum_value, uint32_t * p_val)
{
    switch (enum_value)
    {
        case NPMX_SHIP_TIME_16_MS:
            *p_val = 16;
            break;
        case NPMX_SHIP_TIME_32_MS:
            *p_val = 32;
            break;
        case NPMX_SHIP_TIME_64_MS:
            *p_val = 64;
            break;
        case NPMX_SHIP_TIME_96_MS:
            *p_val = 96;
            break;
        case NPMX_SHIP_TIME_304_MS:
            *p_val = 304;
            break;
        case NPMX_SHIP_TIME_608_MS:
            *p_val = 608;
            break;
        case NPMX_SHIP_TIME_1008_MS:
            *p_val = 1008;
            break;
        case NPMX_SHIP_TIME_3008_MS:
            *p_val = 3008;
            break;
        default:
            return false;
    }
    return true;
}

npmx_error_t npmx_ship_task_trigger(npmx_ship_t const * p_instance, npmx_ship_task_t task)
{
    NPMX_ASSERT(p_instance);
    NPMX_ASSERT(task < NPMX_SHIP_TASK_COUNT);

    return task_trigger(p_instance, task);
}

npmx_error_t npmx_ship_config_set(npmx_ship_t * p_instance, npmx_ship_config_t const * p_config)
{
    NPMX_ASSERT(p_instance);
    NPMX_ASSERT(p_config);
    NPMX_ASSERT(p_config->time < NPMX_SHIP_TIME_COUNT);

    uint8_t data = ((uint8_t)p_config->time << SHPHLD_SHPHLDCONFIG_SHPHLDTIM_Pos) &
                   SHPHLD_SHPHLDCONFIG_SHPHLDTIM_Msk;

    data |= ((p_config->inverted_polarity ? SHPHLD_SHPHLDCONFIG_SHPHLDPOLARITY_INVERT :
                                            SHPHLD_SHPHLDCONFIG_SHPHLDPOLARITY_NOEFFECT)
             << SHPHLD_SHPHLDCONFIG_SHPHLDPOLARITY_Pos) & SHPHLD_SHPHLDCONFIG_SHPHLDPOLARITY_Msk;

    npmx_error_t err_code = npmx_backend_register_write(p_instance->p_backend,
                                                        NPMX_REG_TO_ADDR(NPM_SHIP->SHPHLDCONFIG),
                                                        &data,
                                                        1);
    if (err_code != NPMX_SUCCESS)
    {
        return err_code;
    }

    p_instance->ship_button_inverted = p_config->inverted_polarity;

    return task_trigger(p_instance, NPMX_SHIP_TASK_CONFIG_SHIPHOLD);
}

npmx_error_t npmx_ship_config_get(npmx_ship_t * p_instance, npmx_ship_config_t * p_config)
{
    NPMX_ASSERT(p_instance);
    NPMX_ASSERT(p_config);

    uint8_t      data;
    npmx_error_t err_code = npmx_backend_register_read(p_instance->p_backend,
                                                       NPMX_REG_TO_ADDR(NPM_SHIP->SHPHLDCONFIG),
                                                       &data,
                                                       1);
    if (err_code != NPMX_SUCCESS)
    {
        return err_code;
    }

    p_config->time = (npmx_ship_time_t)((data & SHPHLD_SHPHLDCONFIG_SHPHLDTIM_Msk)
                                        >> SHPHLD_SHPHLDCONFIG_SHPHLDTIM_Pos);

    p_config->inverted_polarity = ((data & SHPHLD_SHPHLDCONFIG_SHPHLDPOLARITY_Msk)
                                   >> SHPHLD_SHPHLDCONFIG_SHPHLDPOLARITY_Pos) ==
                                  SHPHLD_SHPHLDCONFIG_SHPHLDPOLARITY_INVERT;

    p_instance->ship_button_inverted = p_config->inverted_polarity;

    return NPMX_SUCCESS;
}

npmx_error_t npmx_ship_gpio_status_check(npmx_ship_t const * p_instance, bool * p_active)
{
    NPMX_ASSERT(p_instance);
    NPMX_ASSERT(p_active);

    uint8_t      data;
    npmx_error_t err_code = npmx_backend_register_read(p_instance->p_backend,
                                                       NPMX_REG_TO_ADDR(NPM_SHIP->SHPHLDSTATUS),
                                                       &data,
                                                       1);
    if (err_code != NPMX_SUCCESS)
    {
        return err_code;
    }

    uint8_t expected = (SHPHLD_SHPHLDSTATUS_SHPHLDPINSTATUS_HIGH
                        << SHPHLD_SHPHLDSTATUS_SHPHLDPINSTATUS_Pos) &
                       SHPHLD_SHPHLDSTATUS_SHPHLDPINSTATUS_Msk;

    *p_active = ((data == expected) ^ p_instance->ship_button_inverted) ? false : true;

    return NPMX_SUCCESS;
}

npmx_error_t npmx_ship_reset_config_set(npmx_ship_t const *              p_instance,
                                        npmx_ship_reset_config_t const * p_config)
{
    NPMX_ASSERT(p_instance);
    NPMX_ASSERT(p_config);

    uint8_t data = 0;

    data |= ((p_config->long_press ? SHPHLD_LPRESETCONFIG_LONGTIMRESETDIS_ENABLED :
                                     SHPHLD_LPRESETCONFIG_LONGTIMRESETDIS_DISABLED)
             << SHPHLD_LPRESETCONFIG_LONGTIMRESETDIS_Pos) &
            SHPHLD_LPRESETCONFIG_LONGTIMRESETDIS_Msk;

    data |= ((p_config->two_buttons ? SHPHLD_LPRESETCONFIG_LONGTIMTWOBUTTONSEL_SHPHLDGPIO0 :
                                      SHPHLD_LPRESETCONFIG_LONGTIMTWOBUTTONSEL_SHPHLD)
             << SHPHLD_LPRESETCONFIG_LONGTIMTWOBUTTONSEL_Pos) &
            SHPHLD_LPRESETCONFIG_LONGTIMTWOBUTTONSEL_Msk;

    npmx_error_t err_code = npmx_backend_register_write(p_instance->p_backend,
                                                        NPMX_REG_TO_ADDR(NPM_SHIP->LPRESETCONFIG),
                                                        &data,
                                                        1);
    if (err_code != NPMX_SUCCESS)
    {
        return err_code;
    }

    return task_trigger(p_instance, NPMX_SHIP_TASK_CONFIG_SHIPHOLD);
}

npmx_error_t npmx_ship_reset_config_get(npmx_ship_t const *        p_instance,
                                        npmx_ship_reset_config_t * p_config)
{
    NPMX_ASSERT(p_instance);
    NPMX_ASSERT(p_config);

    uint8_t      data;
    npmx_error_t err_code = npmx_backend_register_read(p_instance->p_backend,
                                                       NPMX_REG_TO_ADDR(NPM_SHIP->LPRESETCONFIG),
                                                       &data,
                                                       1);
    if (err_code != NPMX_SUCCESS)
    {
        return err_code;
    }

    p_config->long_press = ((data & SHPHLD_LPRESETCONFIG_LONGTIMRESETDIS_Msk)
                            >> SHPHLD_LPRESETCONFIG_LONGTIMRESETDIS_Pos) ==
                           SHPHLD_LPRESETCONFIG_LONGTIMRESETDIS_ENABLED;

    p_config->two_buttons = ((data & SHPHLD_LPRESETCONFIG_LONGTIMTWOBUTTONSEL_Msk)
                             >> SHPHLD_LPRESETCONFIG_LONGTIMTWOBUTTONSEL_Pos) ==
                            SHPHLD_LPRESETCONFIG_LONGTIMTWOBUTTONSEL_SHPHLDGPIO0;

    return NPMX_SUCCESS;
}
