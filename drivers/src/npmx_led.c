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

#include <npmx_led.h>
#include <npmx_instance.h>

/* A static assert of LEDDRV0, LEDDRV1, LEDDRV2 enable and disable bit position. */
NPMX_STATIC_ASSERT(LEDDRV_LEDDRV0SET_LEDDRV0ON_Msk == LEDDRV_LEDDRV0CLR_LEDDRV0OFF_Msk);
NPMX_STATIC_ASSERT(LEDDRV_LEDDRV0SET_LEDDRV0ON_Msk == LEDDRV_LEDDRV1SET_LEDDRV1ON_Msk);
NPMX_STATIC_ASSERT(LEDDRV_LEDDRV0SET_LEDDRV0ON_Msk == LEDDRV_LEDDRV1CLR_LEDDRV1OFF_Msk);
NPMX_STATIC_ASSERT(LEDDRV_LEDDRV0SET_LEDDRV0ON_Msk == LEDDRV_LEDDRV2SET_LEDDRV2ON_Msk);
NPMX_STATIC_ASSERT(LEDDRV_LEDDRV0SET_LEDDRV0ON_Msk == LEDDRV_LEDDRV2CLR_LEDDRV2OFF_Msk);

/* A static assert of LED mode selection for all instances. */
NPMX_STATIC_ASSERT(
    LEDDRV_LEDDRV0MODESEL_LEDDRV0MODESEL_Msk == LEDDRV_LEDDRV1MODESEL_LEDDRV1MODESEL_Msk);
NPMX_STATIC_ASSERT(
    LEDDRV_LEDDRV0MODESEL_LEDDRV0MODESEL_Msk == LEDDRV_LEDDRV2MODESEL_LEDDRV2MODESEL_Msk);

static const uint16_t m_led_mode_reg_addr[NPM_LEDDRV_COUNT] =
{
    [0] = NPMX_REG_TO_ADDR(NPM_LEDDRV->LEDDRV0MODESEL),
    [1] = NPMX_REG_TO_ADDR(NPM_LEDDRV->LEDDRV1MODESEL),
    [2] = NPMX_REG_TO_ADDR(NPM_LEDDRV->LEDDRV2MODESEL),
};

static const uint16_t m_led_set_reg_addr[NPM_LEDDRV_COUNT] =
{
    [0] = NPMX_REG_TO_ADDR(NPM_LEDDRV->LEDDRV0SET),
    [1] = NPMX_REG_TO_ADDR(NPM_LEDDRV->LEDDRV1SET),
    [2] = NPMX_REG_TO_ADDR(NPM_LEDDRV->LEDDRV2SET),
};

static const uint16_t m_led_clr_reg_addr[NPM_LEDDRV_COUNT] =
{
    [0] = NPMX_REG_TO_ADDR(NPM_LEDDRV->LEDDRV0CLR),
    [1] = NPMX_REG_TO_ADDR(NPM_LEDDRV->LEDDRV1CLR),
    [2] = NPMX_REG_TO_ADDR(NPM_LEDDRV->LEDDRV2CLR),
};

npmx_led_t * npmx_led_get(npmx_instance_t * p_pmic, uint8_t idx)
{
    NPMX_ASSERT(p_pmic);
    NPMX_ASSERT(idx < NPM_LEDDRV_COUNT);

    return &p_pmic->led[idx];
}

npmx_error_t npmx_led_mode_set(npmx_led_t const * p_instance, npmx_led_mode_t mode)
{
    NPMX_ASSERT(p_instance);
    NPMX_ASSERT(mode < NPMX_LED_MODE_COUNT);

    uint8_t data = ((uint8_t)mode << LEDDRV_LEDDRV0MODESEL_LEDDRV0MODESEL_Pos) &
                   LEDDRV_LEDDRV0MODESEL_LEDDRV0MODESEL_Msk;

    return npmx_backend_register_write(p_instance->p_backend,
                                       m_led_mode_reg_addr[p_instance->hw_index],
                                       &data,
                                       1);
}

npmx_error_t npmx_led_mode_get(npmx_led_t const * p_instance, npmx_led_mode_t * p_mode)
{
    NPMX_ASSERT(p_instance);
    NPMX_ASSERT(p_mode);

    uint8_t      data;
    npmx_error_t err_code = npmx_backend_register_read(p_instance->p_backend,
                                                       m_led_mode_reg_addr[p_instance->hw_index],
                                                       &data,
                                                       1);

    if (err_code != NPMX_SUCCESS)
    {
        return err_code;
    }

    *p_mode = (npmx_led_mode_t)((data & LEDDRV_LEDDRV0MODESEL_LEDDRV0MODESEL_Msk)
                                >> LEDDRV_LEDDRV0MODESEL_LEDDRV0MODESEL_Pos);

    return NPMX_SUCCESS;
}

npmx_error_t npmx_led_state_set(npmx_led_t const * p_instance, bool state)
{
    NPMX_ASSERT(p_instance);

    uint16_t reg = state ? m_led_set_reg_addr[p_instance->hw_index] :
                           m_led_clr_reg_addr[p_instance->hw_index];
    uint8_t data = LEDDRV_LEDDRV0SET_LEDDRV0ON_SET << LEDDRV_LEDDRV0SET_LEDDRV0ON_Pos;

    return npmx_backend_register_write(p_instance->p_backend, reg, &data, 1);
}
