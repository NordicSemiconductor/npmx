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

#include <npmx_vbusin.h>
#include <npmx_instance.h>

/* Static assertion for CC1 and CC2 statuses. */
NPMX_STATIC_ASSERT(VBUSIN_USBCDETECTSTATUS_VBUSINCC1CMP_NOCONNECTION ==
                   VBUSIN_USBCDETECTSTATUS_VBUSINCC2CMP_NOCONNECTION);
NPMX_STATIC_ASSERT(VBUSIN_USBCDETECTSTATUS_VBUSINCC1CMP_DEFAULTUSB ==
                   VBUSIN_USBCDETECTSTATUS_VBUSINCC2CMP_DEFAULTUSB);
NPMX_STATIC_ASSERT(VBUSIN_USBCDETECTSTATUS_VBUSINCC1CMP_1A5HIGHPOWER ==
                   VBUSIN_USBCDETECTSTATUS_VBUSINCC2CMP_1A5HIGHPOWER);
NPMX_STATIC_ASSERT(VBUSIN_USBCDETECTSTATUS_VBUSINCC1CMP_3AHIGHPOWER ==
                   VBUSIN_USBCDETECTSTATUS_VBUSINCC2CMP_3AHIGHPOWER);

npmx_vbusin_t * npmx_vbusin_get(npmx_instance_t * p_pmic, uint8_t idx)
{
    NPMX_ASSERT(p_pmic);
    NPMX_ASSERT(idx < NPMX_PERIPH_VBUSIN_COUNT);

    return &p_pmic->vbusin[idx];
}

npmx_vbusin_current_t npmx_vbusin_current_convert(uint32_t milliamperes)
{
    switch (milliamperes)
    {
        case 100:
            return NPMX_VBUSIN_CURRENT_100_MA;
        case 500:
            return NPMX_VBUSIN_CURRENT_500_MA;
        case 600:
            return NPMX_VBUSIN_CURRENT_600_MA;
        case 700:
            return NPMX_VBUSIN_CURRENT_700_MA;
        case 800:
            return NPMX_VBUSIN_CURRENT_800_MA;
        case 900:
            return NPMX_VBUSIN_CURRENT_900_MA;
        case 1000:
            return NPMX_VBUSIN_CURRENT_1000_MA;
        case 1100:
            return NPMX_VBUSIN_CURRENT_1100_MA;
        case 1200:
            return NPMX_VBUSIN_CURRENT_1200_MA;
        case 1300:
            return NPMX_VBUSIN_CURRENT_1300_MA;
        case 1400:
            return NPMX_VBUSIN_CURRENT_1400_MA;
        case 1500:
            return NPMX_VBUSIN_CURRENT_1500_MA;
        default:
            return NPMX_VBUSIN_CURRENT_INVALID;
    }
}

bool npmx_vbusin_current_convert_to_ma(npmx_vbusin_current_t enum_value, uint32_t * p_val)
{
    switch (enum_value)
    {
        case NPMX_VBUSIN_CURRENT_100_MA:
            *p_val = 100;
            break;
        case NPMX_VBUSIN_CURRENT_500_MA:
            *p_val = 500;
            break;
        case NPMX_VBUSIN_CURRENT_600_MA:
            *p_val = 600;
            break;
        case NPMX_VBUSIN_CURRENT_700_MA:
            *p_val = 700;
            break;
        case NPMX_VBUSIN_CURRENT_800_MA:
            *p_val = 800;
            break;
        case NPMX_VBUSIN_CURRENT_900_MA:
            *p_val = 900;
            break;
        case NPMX_VBUSIN_CURRENT_1000_MA:
            *p_val = 1000;
            break;
        case NPMX_VBUSIN_CURRENT_1100_MA:
            *p_val = 1100;
            break;
        case NPMX_VBUSIN_CURRENT_1200_MA:
            *p_val = 1200;
            break;
        case NPMX_VBUSIN_CURRENT_1300_MA:
            *p_val = 1300;
            break;
        case NPMX_VBUSIN_CURRENT_1400_MA:
            *p_val = 1400;
            break;
        case NPMX_VBUSIN_CURRENT_1500_MA:
            *p_val = 1500;
            break;
        default:
            return false;
    }
    return true;
}

const char * const npmx_vbusin_cc_status_map_to_string(npmx_vbusin_cc_t enum_value)
{
    switch (enum_value)
    {
        case NPMX_VBUSIN_CC_NOT_CONNECTED:
            return "NOT_CONNECTED";
        case NPMX_VBUSIN_CC_DEFAULT:
            return "DEFAULT";
        case NPMX_VBUSIN_CC_HIGH_POWER_1A5:
            return "HIGH_POWER_1A5";
        case NPMX_VBUSIN_CC_HIGH_POWER_3A0:
            return "HIGH_POWER_3A0";
        default:
            return "INVALID";
    }
}

npmx_error_t npmx_vbusin_task_trigger(npmx_vbusin_t const * p_instance, npmx_vbusin_task_t task)
{
    NPMX_ASSERT(p_instance);
    NPMX_ASSERT(task < NPMX_VBUSIN_TASK_COUNT);

    uint8_t data = NPMX_TASK_TRIGGER;

    static const uint16_t task_addr[NPMX_VBUSIN_TASK_COUNT] =
    {
        [NPMX_VBUSIN_TASK_APPLY_CURRENT_LIMIT] = NPMX_REG_TO_ADDR(NPM_VBUSIN->TASKUPDATEILIMSW),
    };

    return npmx_backend_register_write(p_instance->p_backend, task_addr[task], &data, 1);
}

npmx_error_t npmx_vbusin_current_limit_set(npmx_vbusin_t const * p_instance,
                                           npmx_vbusin_current_t current_limit)
{
    NPMX_ASSERT(p_instance);
    NPMX_ASSERT(current_limit < NPMX_VBUSIN_CURRENT_COUNT);

    uint8_t data = ((uint8_t)current_limit << VBUSIN_VBUSINILIM0_VBUSINILIM0_Pos) &
                   VBUSIN_VBUSINILIM0_VBUSINILIM0_Msk;

    return npmx_backend_register_write(p_instance->p_backend,
                                       NPMX_REG_TO_ADDR(NPM_VBUSIN->VBUSINILIM0),
                                       &data,
                                       1);
}

npmx_error_t npmx_vbusin_current_limit_get(npmx_vbusin_t const *   p_instance,
                                           npmx_vbusin_current_t * p_current_limit)
{
    NPMX_ASSERT(p_instance);
    NPMX_ASSERT(p_current_limit);

    uint8_t      data;
    npmx_error_t err_code = npmx_backend_register_read(p_instance->p_backend,
                                                       NPMX_REG_TO_ADDR(NPM_VBUSIN->VBUSINILIM0),
                                                       &data,
                                                       1);
    if (err_code != NPMX_SUCCESS)
    {
        return err_code;
    }

    *p_current_limit = (npmx_vbusin_current_t)((data & VBUSIN_VBUSINILIM0_VBUSINILIM0_Msk)
                                               >> VBUSIN_VBUSINILIM0_VBUSINILIM0_Pos);

    return NPMX_SUCCESS;
}

npmx_error_t npmx_vbusin_suspend_mode_enable_set(npmx_vbusin_t const * p_instance, bool enable)
{
    NPMX_ASSERT(p_instance);

    uint8_t data = ((enable ? VBUSIN_VBUSSUSPEND_VBUSSUSPENDENA_SUSPENDMODE :
                              VBUSIN_VBUSSUSPEND_VBUSSUSPENDENA_NORMAL)
                    << VBUSIN_VBUSSUSPEND_VBUSSUSPENDENA_Pos) &
                   VBUSIN_VBUSSUSPEND_VBUSSUSPENDENA_Msk;

    return npmx_backend_register_write(p_instance->p_backend,
                                       NPMX_REG_TO_ADDR(NPM_VBUSIN->VBUSSUSPEND),
                                       &data,
                                       1);
}

npmx_error_t npmx_vbusin_suspend_mode_enable_get(npmx_vbusin_t const * p_instance, bool * p_enable)
{
    NPMX_ASSERT(p_instance);
    NPMX_ASSERT(p_enable);

    uint8_t      data;
    npmx_error_t err_code = npmx_backend_register_read(p_instance->p_backend,
                                                       NPMX_REG_TO_ADDR(NPM_VBUSIN->VBUSSUSPEND),
                                                       &data,
                                                       1);
    if (err_code != NPMX_SUCCESS)
    {
        return err_code;
    }

    *p_enable = (((data & VBUSIN_VBUSSUSPEND_VBUSSUSPENDENA_Msk)
                  >> VBUSIN_VBUSSUSPEND_VBUSSUSPENDENA_Pos) ==
                 VBUSIN_VBUSSUSPEND_VBUSSUSPENDENA_SUSPENDMODE);

    return NPMX_SUCCESS;
}

npmx_error_t npmx_vbusin_cc_status_get(npmx_vbusin_t const * p_instance,
                                       npmx_vbusin_cc_t *    p_cc1,
                                       npmx_vbusin_cc_t *    p_cc2)
{
    NPMX_ASSERT(p_instance);
    NPMX_ASSERT(p_cc1);
    NPMX_ASSERT(p_cc2);

    uint8_t      data;
    npmx_error_t err_code = npmx_backend_register_read(p_instance->p_backend,
                                                       NPMX_REG_TO_ADDR(
                                                           NPM_VBUSIN->USBCDETECTSTATUS),
                                                       &data,
                                                       1);
    if (err_code != NPMX_SUCCESS)
    {
        return err_code;
    }

    *p_cc1 = (npmx_vbusin_cc_t)((data & VBUSIN_USBCDETECTSTATUS_VBUSINCC1CMP_Msk)
                                >> VBUSIN_USBCDETECTSTATUS_VBUSINCC1CMP_Pos);
    *p_cc2 = (npmx_vbusin_cc_t)((data & VBUSIN_USBCDETECTSTATUS_VBUSINCC2CMP_Msk)
                                >> VBUSIN_USBCDETECTSTATUS_VBUSINCC2CMP_Pos);

    return NPMX_SUCCESS;
}

npmx_error_t npmx_vbusin_vbus_status_get(npmx_vbusin_t const * p_instance, uint8_t * p_status_mask)
{
    NPMX_ASSERT(p_instance);
    NPMX_ASSERT(p_status_mask);

    return npmx_backend_register_read(p_instance->p_backend,
                                      NPMX_REG_TO_ADDR(NPM_VBUSIN->VBUSINSTATUS),
                                      p_status_mask,
                                      1);
}
