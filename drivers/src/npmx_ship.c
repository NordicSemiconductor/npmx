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
#if defined(SHPHLD_TASKENTERWAKEUP_TASKENTERWAKEUP_Msk)
        [NPMX_SHIP_TASK_HIBERNATE]       = NPMX_REG_TO_ADDR(NPM_SHIP->TASKENTERWAKEUP),
#elif defined(SHPHLD_TASKENTERHIBERNATE_TASKENTERHIBERNATE_Msk)
        [NPMX_SHIP_TASK_HIBERNATE]       = NPMX_REG_TO_ADDR(NPM_SHIP->TASKENTERHIBERNATE),
#endif
        [NPMX_SHIP_TASK_CONFIG_SHIPHOLD] = NPMX_REG_TO_ADDR(NPM_SHIP->TASKSHPHLDCFGSTROBE),
        [NPMX_SHIP_TASK_SHIPMODE]        = NPMX_REG_TO_ADDR(NPM_SHIP->TASKENTERSHIPMODE),
        [NPMX_SHIP_TASK_CONFIG_RESET]    = NPMX_REG_TO_ADDR(NPM_SHIP->TASKRESETCFG),
    };

    return npmx_backend_register_write(p_instance->p_backend, task_addr[task], &data, 1);
}

npmx_ship_t * npmx_ship_get(npmx_instance_t * p_pmic, uint8_t idx)
{
    NPMX_ASSERT(p_pmic);
    NPMX_ASSERT(idx < NPMX_PERIPH_SHIP_COUNT);

    return &p_pmic->ship[idx];
}

npmx_ship_time_t npmx_ship_time_convert(uint32_t time_ms)
{
    switch (time_ms)
    {
#if NPMX_SHIP_HAS_10MS_SHPHLDCONFIG
        case 10:
            return NPMX_SHIP_TIME_10_MS;
        case 30:
            return NPMX_SHIP_TIME_30_MS;
        case 60:
            return NPMX_SHIP_TIME_60_MS;
        case 100:
            return NPMX_SHIP_TIME_100_MS;
        case 300:
            return NPMX_SHIP_TIME_300_MS;
        case 600:
            return NPMX_SHIP_TIME_600_MS;
        case 1000:
            return NPMX_SHIP_TIME_1000_MS;
        case 3000:
            return NPMX_SHIP_TIME_3000_MS;
#elif NPMX_SHIP_HAS_16MS_SHPHLDCONFIG
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
#endif
        default:
            return NPMX_SHIP_INVALID;
    }
}

uint32_t npmx_ship_time_convert_to_ms(npmx_ship_time_t enum_value)
{
    NPMX_ASSERT(enum_value != NPMX_SHIP_INVALID);

    static const uint32_t convert_table[] =
    {
#if NPMX_SHIP_HAS_10MS_SHPHLDCONFIG
        [NPMX_SHIP_TIME_10_MS]   = 10,
        [NPMX_SHIP_TIME_30_MS]   = 30,
        [NPMX_SHIP_TIME_60_MS]   = 60,
        [NPMX_SHIP_TIME_100_MS]  = 100,
        [NPMX_SHIP_TIME_300_MS]  = 300,
        [NPMX_SHIP_TIME_600_MS]  = 600,
        [NPMX_SHIP_TIME_1000_MS] = 1000,
        [NPMX_SHIP_TIME_3000_MS] = 3000,
#endif
#if NPMX_SHIP_HAS_16MS_SHPHLDCONFIG
        [NPMX_SHIP_TIME_16_MS]   = 16,
        [NPMX_SHIP_TIME_32_MS]   = 32,
        [NPMX_SHIP_TIME_64_MS]   = 64,
        [NPMX_SHIP_TIME_96_MS]   = 96,
        [NPMX_SHIP_TIME_304_MS]  = 304,
        [NPMX_SHIP_TIME_608_MS]  = 608,
        [NPMX_SHIP_TIME_1008_MS] = 1008,
        [NPMX_SHIP_TIME_3008_MS] = 3008,
#endif
    };

    return convert_table[enum_value];
}

npmx_error_t npmx_ship_task_trigger(npmx_ship_t const * p_instance, npmx_ship_task_t task)
{
    NPMX_ASSERT(p_instance);

    return task_trigger(p_instance, task);
}

npmx_error_t npmx_ship_config_set(npmx_ship_t * p_instance, npmx_ship_config_t const * p_config)
{
    NPMX_ASSERT(p_instance);
    NPMX_ASSERT(p_config);

    uint8_t data = ((uint8_t)p_config->time << SHPHLD_SHPHLDCONFIG_SHPHLDTIM_Pos) &
                   SHPHLD_SHPHLDCONFIG_SHPHLDTIM_Msk;

#if defined(SHPHLD_SHPHLDCONFIG_SHPHLDDISPULLDOWN_Msk)
    data |= ((p_config->disable_active_pd ? SHPHLD_SHPHLDCONFIG_SHPHLDDISPULLDOWN_DISABLED :
                                            SHPHLD_SHPHLDCONFIG_SHPHLDDISPULLDOWN_ENABLED)
             << SHPHLD_SHPHLDCONFIG_SHPHLDDISPULLDOWN_Pos) &
            SHPHLD_SHPHLDCONFIG_SHPHLDDISPULLDOWN_Msk;
#endif

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

#if defined(SHPHLD_SHPHLDCONFIG_SHPHLDDISPULLDOWN_Msk)
    p_config->disable_active_pd = ((data & SHPHLD_SHPHLDCONFIG_SHPHLDDISPULLDOWN_Msk)
                                   >> SHPHLD_SHPHLDCONFIG_SHPHLDDISPULLDOWN_Pos) ==
                                  SHPHLD_SHPHLDCONFIG_SHPHLDDISPULLDOWN_DISABLED;
#endif

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

#if defined(SHPHLD_LPRESETCONFIG_LONGTIMRESETENA_Msk)
    data |= ((p_config->long_press ? SHPHLD_LPRESETCONFIG_LONGTIMRESETENA_ENABLED :
                                     SHPHLD_LPRESETCONFIG_LONGTIMRESETENA_DISABLED)
             << SHPHLD_LPRESETCONFIG_LONGTIMRESETENA_Pos) &
            SHPHLD_LPRESETCONFIG_LONGTIMRESETENA_Msk;
#elif defined(SHPHLD_LPRESETCONFIG_LONGTIMRESETDIS_Msk)
    data |= ((p_config->long_press ? SHPHLD_LPRESETCONFIG_LONGTIMRESETDIS_ENABLED :
                                     SHPHLD_LPRESETCONFIG_LONGTIMRESETDIS_DISABLED)
             << SHPHLD_LPRESETCONFIG_LONGTIMRESETDIS_Pos) &
            SHPHLD_LPRESETCONFIG_LONGTIMRESETDIS_Msk;
#endif

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

    return task_trigger(p_instance, NPMX_SHIP_TASK_CONFIG_RESET);
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

#if defined(SHPHLD_LPRESETCONFIG_LONGTIMRESETENA_Msk)
    p_config->long_press = ((data & SHPHLD_LPRESETCONFIG_LONGTIMRESETENA_Msk)
                            >> SHPHLD_LPRESETCONFIG_LONGTIMRESETENA_Pos) ==
                           SHPHLD_LPRESETCONFIG_LONGTIMRESETENA_ENABLED;
#elif defined(SHPHLD_LPRESETCONFIG_LONGTIMRESETDIS_Msk)
    p_config->long_press = ((data & SHPHLD_LPRESETCONFIG_LONGTIMRESETDIS_Msk)
                            >> SHPHLD_LPRESETCONFIG_LONGTIMRESETDIS_Pos) ==
                           SHPHLD_LPRESETCONFIG_LONGTIMRESETDIS_ENABLED;
#endif

    p_config->two_buttons = ((data & SHPHLD_LPRESETCONFIG_LONGTIMTWOBUTTONSEL_Msk)
                             >> SHPHLD_LPRESETCONFIG_LONGTIMTWOBUTTONSEL_Pos) ==
                            SHPHLD_LPRESETCONFIG_LONGTIMTWOBUTTONSEL_SHPHLDGPIO0;

    return NPMX_SUCCESS;
}
