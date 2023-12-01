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

#include <npmx_pof.h>
#include <npmx_instance.h>

npmx_pof_t * npmx_pof_get(npmx_instance_t * p_pmic, uint8_t idx)
{
    NPMX_ASSERT(p_pmic);
    NPMX_ASSERT(idx < NPM_POF_COUNT);

    return &p_pmic->pof[idx];
}

npmx_pof_threshold_t npmx_pof_threshold_convert(uint32_t millivolts)
{
    switch (millivolts)
    {
        case 2600:
            return NPMX_POF_THRESHOLD_2V6;
        case 2700:
            return NPMX_POF_THRESHOLD_2V7;
        case 2800:
            return NPMX_POF_THRESHOLD_2V8;
        case 2900:
            return NPMX_POF_THRESHOLD_2V9;
        case 3000:
            return NPMX_POF_THRESHOLD_3V0;
        case 3100:
            return NPMX_POF_THRESHOLD_3V1;
        case 3200:
            return NPMX_POF_THRESHOLD_3V2;
        case 3300:
            return NPMX_POF_THRESHOLD_3V3;
        case 3400:
            return NPMX_POF_THRESHOLD_3V4;
        case 3500:
            return NPMX_POF_THRESHOLD_3V5;
        default:
            return NPMX_POF_THRESHOLD_INVALID;
    }
}

bool npmx_pof_threshold_convert_to_mv(npmx_pof_threshold_t enum_value, uint32_t * p_val)
{
    switch (enum_value)
    {
        case NPMX_POF_THRESHOLD_2V6:
            *p_val = 2600;
            break;
        case NPMX_POF_THRESHOLD_2V7:
            *p_val = 2700;
            break;
        case NPMX_POF_THRESHOLD_2V8:
            *p_val = 2800;
            break;
        case NPMX_POF_THRESHOLD_2V9:
            *p_val = 2900;
            break;
        case NPMX_POF_THRESHOLD_3V0:
            *p_val = 3000;
            break;
        case NPMX_POF_THRESHOLD_3V1:
            *p_val = 3100;
            break;
        case NPMX_POF_THRESHOLD_3V2:
            *p_val = 3200;
            break;
        case NPMX_POF_THRESHOLD_3V3:
            *p_val = 3300;
            break;
        case NPMX_POF_THRESHOLD_3V4:
            *p_val = 3400;
            break;
        case NPMX_POF_THRESHOLD_3V5:
            *p_val = 3500;
            break;
        default:
            return false;
    }
    return true;
}

npmx_error_t npmx_pof_config_set(npmx_pof_t const * p_instance, npmx_pof_config_t const * p_config)
{
    NPMX_ASSERT(p_instance);
    NPMX_ASSERT(p_config);
    NPMX_ASSERT(p_config->status < NPMX_POF_STATUS_COUNT);
    NPMX_ASSERT(p_config->threshold < NPMX_POF_THRESHOLD_COUNT);
    NPMX_ASSERT(p_config->polarity < NPMX_POF_POLARITY_COUNT);

    uint8_t data = (((p_config->status == NPMX_POF_STATUS_ENABLE) ?
                     POF_POFCONFIG_POFENA_ENABLED : POF_POFCONFIG_POFENA_OFF)
                    << POF_POFCONFIG_POFENA_Pos) & POF_POFCONFIG_POFENA_Msk;

    data |= ((uint8_t)p_config->polarity << POF_POFCONFIG_POFWARNPOLARITY_Pos) &
            POF_POFCONFIG_POFWARNPOLARITY_Msk;

    data |= ((uint8_t)p_config->threshold << POF_POFCONFIG_POFVSYSTHRESHSEL_Pos) &
            POF_POFCONFIG_POFVSYSTHRESHSEL_Msk;

    return npmx_backend_register_write(p_instance->p_backend,
                                       NPMX_REG_TO_ADDR(NPM_POF->POFCONFIG),
                                       &data,
                                       1);
}

npmx_error_t npmx_pof_config_get(npmx_pof_t const * p_instance, npmx_pof_config_t * p_config)
{
    NPMX_ASSERT(p_instance);
    NPMX_ASSERT(p_config);

    uint8_t      data;
    npmx_error_t err_code = npmx_backend_register_read(p_instance->p_backend,
                                                       NPMX_REG_TO_ADDR(NPM_POF->POFCONFIG),
                                                       &data,
                                                       1);
    if (err_code != NPMX_SUCCESS)
    {
        return err_code;
    }

    p_config->status = (((data & POF_POFCONFIG_POFENA_Msk) >> POF_POFCONFIG_POFENA_Pos) ==
                        POF_POFCONFIG_POFENA_ENABLED) ? NPMX_POF_STATUS_ENABLE :
                                                        NPMX_POF_STATUS_DISABLE;

    p_config->polarity = (npmx_pof_polarity_t)((data & POF_POFCONFIG_POFWARNPOLARITY_Msk)
                                               >> POF_POFCONFIG_POFWARNPOLARITY_Pos);

    p_config->threshold = (npmx_pof_threshold_t)((data & POF_POFCONFIG_POFVSYSTHRESHSEL_Msk)
                                                 >> POF_POFCONFIG_POFVSYSTHRESHSEL_Pos);

    return NPMX_SUCCESS;
}

npmx_error_t npmx_pof_disable_set(npmx_pof_t const * p_instance)
{
    NPMX_ASSERT(p_instance);

    uint8_t data = (POF_POFCONFIG_POFENA_OFF << POF_POFCONFIG_POFENA_Pos) &
                   POF_POFCONFIG_POFENA_Msk;

    return npmx_backend_register_write(p_instance->p_backend,
                                       NPMX_REG_TO_ADDR(NPM_POF->POFCONFIG),
                                       &data,
                                       1);
}
