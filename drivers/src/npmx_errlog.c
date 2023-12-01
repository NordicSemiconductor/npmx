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

#include <npmx_errlog.h>
#include <npmx_instance.h>

/* Static assertion for errors registers */
NPMX_STATIC_ASSERT((offsetof(NPM_ERRLOG_Type, CHARGERERRREASON) -
                    offsetof(NPM_ERRLOG_Type, RSTCAUSE)) == 1);
NPMX_STATIC_ASSERT((offsetof(NPM_ERRLOG_Type, CHARGERERRSENSOR) -
                    offsetof(NPM_ERRLOG_Type, CHARGERERRREASON)) == 1);

static const uint16_t m_scratch_reg_addr[] =
{
    [NPMX_ERRLOG_SCRATCH0] = NPMX_REG_TO_ADDR(NPM_ERRLOG->SCRATCH0),
    [NPMX_ERRLOG_SCRATCH1] = NPMX_REG_TO_ADDR(NPM_ERRLOG->SCRATCH1),
};

static npmx_error_t task_trigger(npmx_errlog_t const * p_instance, npmx_errlog_task_t task)
{
    uint8_t data = NPMX_TASK_TRIGGER;

    static const uint16_t task_addr[NPMX_ERRLOG_TASK_COUNT] =
    {
        [NPMX_ERRLOG_TASK_CLEAR] = NPMX_REG_TO_ADDR(NPM_ERRLOG->TASKCLRERRLOG),
    };

    return npmx_backend_register_write(p_instance->p_pmic->p_backend,
                                       task_addr[task],
                                       &data,
                                       1);
}

npmx_errlog_t * npmx_errlog_get(npmx_instance_t * p_pmic, uint8_t idx)
{
    NPMX_ASSERT(p_pmic);
    NPMX_ASSERT(idx < NPM_ERRLOG_COUNT);

    return &p_pmic->errlog[idx];
}

npmx_error_t npmx_errlog_task_trigger(npmx_errlog_t const * p_instance, npmx_errlog_task_t task)
{
    NPMX_ASSERT(p_instance);
    NPMX_ASSERT(task < NPMX_ERRLOG_TASK_COUNT);

    return task_trigger(p_instance, task);
}

npmx_error_t npmx_errlog_reset_errors_check(npmx_errlog_t const * p_instance)
{
    NPMX_ASSERT(p_instance);

    uint8_t errors[NPM_ERRLOG_ERR_COUNT];

    npmx_error_t err_code = npmx_backend_register_read(p_instance->p_pmic->p_backend,
                                                       NPMX_REG_TO_ADDR(NPM_ERRLOG->RSTCAUSE),
                                                       errors,
                                                       NPM_ERRLOG_ERR_COUNT);

    if (err_code != NPMX_SUCCESS)
    {
        return err_code;
    }

    for (uint8_t i = 0; i < NPM_ERRLOG_ERR_COUNT; i++)
    {
        if (errors[i] != 0)
        {
            err_code = task_trigger(p_instance, NPMX_ERRLOG_TASK_CLEAR);
            if (err_code != NPMX_SUCCESS)
            {
                return err_code;
            }

            break;
        }
    }

    static const npmx_callback_type_t m_id_to_callback[NPM_ERRLOG_ERR_COUNT] =
    {
        NPMX_CALLBACK_TYPE_RSTCAUSE,
        NPMX_CALLBACK_TYPE_CHARGER_ERROR,
        NPMX_CALLBACK_TYPE_SENSOR_ERROR
    };

    for (uint8_t i = 0; i < NPM_ERRLOG_ERR_COUNT; i++)
    {
        if ((errors[i] != 0) && (p_instance->p_pmic->registered_cb[m_id_to_callback[i]] != NULL))
        {
            p_instance->p_pmic->registered_cb[m_id_to_callback[i]](p_instance->p_pmic,
                                                                   m_id_to_callback[i],
                                                                   errors[i]);
        }
    }

    return NPMX_SUCCESS;
}

npmx_error_t npmx_errlog_scratch_set(npmx_errlog_t const * p_instance,
                                     npmx_errlog_scratch_t scratch,
                                     uint8_t               value)
{
    NPMX_ASSERT(p_instance);
    NPMX_ASSERT(scratch < NPMX_ERRLOG_SCRATCH_COUNT);

    uint8_t data;

    if (scratch == NPMX_ERRLOG_SCRATCH0)
    {
        NPMX_ASSERT(value <= NPM_ERRLOG_SCRATCH0_MAX_VAL);

        npmx_error_t err_code = npmx_backend_register_read(p_instance->p_pmic->p_backend,
                                                           m_scratch_reg_addr[scratch],
                                                           &data,
                                                           1);
        if (err_code != NPMX_SUCCESS)
        {
            return err_code;
        }

        data &= ~ERRLOG_SCRATCH0_SCRATCH0_Msk;

        data |= ((uint8_t)value << ERRLOG_SCRATCH0_SCRATCH0_Pos);
    }
    else
    {
        data = value;
    }

    return npmx_backend_register_write(p_instance->p_pmic->p_backend,
                                       m_scratch_reg_addr[scratch],
                                       &data,
                                       1);
}

npmx_error_t npmx_errlog_scratch_get(npmx_errlog_t const * p_instance,
                                     npmx_errlog_scratch_t scratch,
                                     uint8_t *             p_value)
{
    NPMX_ASSERT(p_instance);
    NPMX_ASSERT(scratch < NPMX_ERRLOG_SCRATCH_COUNT);
    NPMX_ASSERT(p_value);

    if (scratch == NPMX_ERRLOG_SCRATCH0)
    {
        uint8_t data;
        npmx_error_t err_code = npmx_backend_register_read(p_instance->p_pmic->p_backend,
                                                           m_scratch_reg_addr[scratch],
                                                           &data,
                                                           1);
        if (err_code != NPMX_SUCCESS)
        {
            return err_code;
        }

        *p_value = ((data & ERRLOG_SCRATCH0_SCRATCH0_Msk) >> ERRLOG_SCRATCH0_SCRATCH0_Pos);

        return NPMX_SUCCESS;
    }

    return npmx_backend_register_read(p_instance->p_pmic->p_backend,
                                      m_scratch_reg_addr[scratch],
                                      p_value,
                                      1);
}

npmx_error_t npmx_errlog_boot_timer_enable_set(npmx_errlog_t const * p_instance, bool enable)
{
    NPMX_ASSERT(p_instance);

    uint8_t data;
    npmx_error_t err_code = npmx_backend_register_read(p_instance->p_pmic->p_backend,
                                                       m_scratch_reg_addr[NPMX_ERRLOG_SCRATCH0],
                                                       &data,
                                                       1);
    if (err_code != NPMX_SUCCESS)
    {
        return err_code;
    }

    data &= ~ERRLOG_SCRATCH0_BOOTTIMEREN_Msk;

    data |= ((enable ? ERRLOG_SCRATCH0_BOOTTIMEREN_BOOTMON : ERRLOG_SCRATCH0_BOOTTIMEREN_NOBOOTMON)
             << ERRLOG_SCRATCH0_BOOTTIMEREN_Pos);

    return npmx_backend_register_write(p_instance->p_pmic->p_backend,
                                       m_scratch_reg_addr[NPMX_ERRLOG_SCRATCH0],
                                       &data,
                                       1);
}

npmx_error_t npmx_errlog_boot_timer_enable_get(npmx_errlog_t const * p_instance, bool * p_enable)
{
    NPMX_ASSERT(p_instance);
    NPMX_ASSERT(p_enable);

    uint8_t      data;
    npmx_error_t err_code = npmx_backend_register_read(p_instance->p_pmic->p_backend,
                                                       m_scratch_reg_addr[NPMX_ERRLOG_SCRATCH0],
                                                       &data,
                                                       1);
    if (err_code != NPMX_SUCCESS)
    {
        return err_code;
    }

    *p_enable = (((data & ERRLOG_SCRATCH0_BOOTTIMEREN_Msk) >> ERRLOG_SCRATCH0_BOOTTIMEREN_Pos) ==
                 ERRLOG_SCRATCH0_BOOTTIMEREN_BOOTMON);

    return NPMX_SUCCESS;
}
