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

#include <npmx_ldsw.h>
#include <npmx_instance.h>

#if defined(LDSW_LDSW1VOUTSEL_LDSW1VOUTSEL_1V)
/**
 * @brief Symbols used in @ref npmx_ldsw_voltage_convert_to_mv function
 *        in the conversion from enumeration to millivolts.
 */
#define LDSW_VOLTAGE_BASE 1000UL
#define LDSW_VOLTAGE_DIFF 100UL
#endif

/**
 * @brief Symbols used in @ref npmx_ldsw_soft_start_current_convert_to_ma function
 *        in the conversion from enumeration to millivolts.
 */
#define LDSW_SOFT_START_CURRENT_BASE 25UL
#define LDSW_SOFT_START_CURRENT_DIFF 25UL

/* A static assert of LDSW Soft Start Levels. */
NPMX_STATIC_ASSERT(LDSW_LDSWCONFIG_LDSW1SOFTSTARTSEL_25mA ==
                   LDSW_LDSWCONFIG_LDSW2SOFTSTARTSEL_25mA);
NPMX_STATIC_ASSERT(LDSW_LDSWCONFIG_LDSW1SOFTSTARTSEL_50mA ==
                   LDSW_LDSWCONFIG_LDSW2SOFTSTARTSEL_50mA);
NPMX_STATIC_ASSERT(LDSW_LDSWCONFIG_LDSW1SOFTSTARTSEL_75mA ==
                   LDSW_LDSWCONFIG_LDSW2SOFTSTARTSEL_75mA);
NPMX_STATIC_ASSERT(LDSW_LDSWCONFIG_LDSW1SOFTSTARTSEL_100mA ==
                   LDSW_LDSWCONFIG_LDSW2SOFTSTARTSEL_100mA);

static const uint8_t m_en_gpio_pos[NPMX_PERIPH_LDSW_COUNT] =
{
    [0] = LDSW_LDSW1GPISEL_LDSW1GPISEL_Pos,
    [1] = LDSW_LDSW2GPISEL_LDSW2GPISEL_Pos,
};

static const uint8_t m_en_gpio_mask[NPMX_PERIPH_LDSW_COUNT] =
{
    [0] = LDSW_LDSW1GPISEL_LDSW1GPISEL_Msk,
    [1] = LDSW_LDSW2GPISEL_LDSW2GPISEL_Msk,
};

static const uint8_t m_inv_gpio_pos[NPMX_PERIPH_LDSW_COUNT] =
{
    [0] = LDSW_LDSW1GPISEL_LDSW1GPIINV_Pos,
    [1] = LDSW_LDSW2GPISEL_LDSW2GPIINV_Pos,
};

static const uint8_t m_inv_gpio_mask[NPMX_PERIPH_LDSW_COUNT] =
{
    [0] = LDSW_LDSW1GPISEL_LDSW1GPIINV_Msk,
    [1] = LDSW_LDSW2GPISEL_LDSW2GPIINV_Msk,
};

static const uint16_t m_en_reg_addr[NPMX_PERIPH_LDSW_COUNT] =
{
    [0] = NPMX_REG_TO_ADDR(NPM_LDSW->LDSW1GPISEL),
    [1] = NPMX_REG_TO_ADDR(NPM_LDSW->LDSW2GPISEL),
};

static const uint8_t m_soft_start_current_pos[NPMX_PERIPH_LDSW_COUNT] =
{
    [0] = LDSW_LDSWCONFIG_LDSW1SOFTSTARTSEL_Pos,
    [1] = LDSW_LDSWCONFIG_LDSW2SOFTSTARTSEL_Pos,
};

static const uint8_t m_soft_start_current_mask[NPMX_PERIPH_LDSW_COUNT] =
{
    [0] = LDSW_LDSWCONFIG_LDSW1SOFTSTARTSEL_Msk,
    [1] = LDSW_LDSWCONFIG_LDSW2SOFTSTARTSEL_Msk,
};

static const uint8_t m_soft_start_en_pos[NPMX_PERIPH_LDSW_COUNT] =
{
    [0] = LDSW_LDSWCONFIG_LDSW1SOFTSTARTDISABLE_Pos,
    [1] = LDSW_LDSWCONFIG_LDSW2SOFTSTARTDISABLE_Pos,
};

static const uint8_t m_soft_start_en_mask[NPMX_PERIPH_LDSW_COUNT] =
{
    [0] = LDSW_LDSWCONFIG_LDSW1SOFTSTARTDISABLE_Msk,
    [1] = LDSW_LDSWCONFIG_LDSW2SOFTSTARTDISABLE_Msk,
};

static const uint8_t m_en_dis_pos[NPMX_PERIPH_LDSW_COUNT] =
{
    [0] = LDSW_LDSWCONFIG_LDSW1ACTIVEDISCHARGE_Pos,
    [1] = LDSW_LDSWCONFIG_LDSW2ACTIVEDISCHARGE_Pos,
};

static const uint8_t m_en_dis_mask[NPMX_PERIPH_LDSW_COUNT] =
{
    [0] = LDSW_LDSWCONFIG_LDSW1ACTIVEDISCHARGE_Msk,
    [1] = LDSW_LDSWCONFIG_LDSW2ACTIVEDISCHARGE_Msk,
};

static const uint16_t m_ldo_sel_reg_addr[NPMX_PERIPH_LDSW_COUNT] =
{
    [0] = NPMX_REG_TO_ADDR(NPM_LDSW->LDSW1LDOSEL),
    [1] = NPMX_REG_TO_ADDR(NPM_LDSW->LDSW2LDOSEL),
};

static const uint8_t m_ldo_sel_pos[NPMX_PERIPH_LDSW_COUNT] =
{
    [0] = LDSW_LDSW1LDOSEL_LDSW1LDOSEL_Pos,
    [1] = LDSW_LDSW2LDOSEL_LDSW2LDOSEL_Pos,
};

static const uint8_t m_ldo_sel_mask[NPMX_PERIPH_LDSW_COUNT] =
{
    [0] = LDSW_LDSW1LDOSEL_LDSW1LDOSEL_Msk,
    [1] = LDSW_LDSW2LDOSEL_LDSW2LDOSEL_Msk,
};

static const uint16_t m_vout_sel_reg_addr[NPMX_PERIPH_LDSW_COUNT] =
{
    [0] = NPMX_REG_TO_ADDR(NPM_LDSW->LDSW1VOUTSEL),
    [1] = NPMX_REG_TO_ADDR(NPM_LDSW->LDSW2VOUTSEL),
};

/**
 * @brief Function for activating the specified LDSW task.
 *
 * @param[in] p_instance Pointer to the PMIC instance.
 * @param[in] task       Task to be activated.
 *
 * @retval NPMX_SUCCESS  Operation performed successfully.
 * @retval NPMX_ERROR_IO Error using IO bus line.
 */
static npmx_error_t task_trigger(npmx_ldsw_t const * p_instance, npmx_ldsw_task_t task)
{
    uint8_t data = NPMX_TASK_TRIGGER;

    static const uint16_t task_addr[NPMX_LDSW_TASK_COUNT][NPMX_PERIPH_LDSW_COUNT] =
    {
        [NPMX_LDSW_TASK_ENABLE] =
        {
            [0] = NPMX_REG_TO_ADDR(NPM_LDSW->TASKLDSW1SET),
            [1] = NPMX_REG_TO_ADDR(NPM_LDSW->TASKLDSW2SET),
        },
        [NPMX_LDSW_TASK_DISABLE] =
        {
            [0] = NPMX_REG_TO_ADDR(NPM_LDSW->TASKLDSW1CLR),
            [1] = NPMX_REG_TO_ADDR(NPM_LDSW->TASKLDSW2CLR),
        }
    };

    uint16_t address = task_addr[task][p_instance->hw_index];

    return npmx_backend_register_write(p_instance->p_backend, address, &data, 1);
}

npmx_ldsw_t * npmx_ldsw_get(npmx_instance_t * p_pmic, uint8_t idx)
{
    NPMX_ASSERT(p_pmic);
    NPMX_ASSERT(idx < NPMX_PERIPH_LDSW_COUNT);

    return &p_pmic->ldsw[idx];
}

npmx_ldsw_voltage_t npmx_ldsw_voltage_convert(uint32_t millivolts)
{
    switch (millivolts)
    {
        case 1000:
            return NPMX_LDSW_VOLTAGE_1V0;
        case 1100:
            return NPMX_LDSW_VOLTAGE_1V1;
        case 1200:
            return NPMX_LDSW_VOLTAGE_1V2;
        case 1300:
            return NPMX_LDSW_VOLTAGE_1V3;
        case 1400:
            return NPMX_LDSW_VOLTAGE_1V4;
        case 1500:
            return NPMX_LDSW_VOLTAGE_1V5;
        case 1600:
            return NPMX_LDSW_VOLTAGE_1V6;
        case 1700:
            return NPMX_LDSW_VOLTAGE_1V7;
        case 1800:
            return NPMX_LDSW_VOLTAGE_1V8;
        case 1900:
            return NPMX_LDSW_VOLTAGE_1V9;
        case 2000:
            return NPMX_LDSW_VOLTAGE_2V0;
        case 2100:
            return NPMX_LDSW_VOLTAGE_2V1;
        case 2200:
            return NPMX_LDSW_VOLTAGE_2V2;
        case 2300:
            return NPMX_LDSW_VOLTAGE_2V3;
        case 2400:
            return NPMX_LDSW_VOLTAGE_2V4;
        case 2500:
            return NPMX_LDSW_VOLTAGE_2V5;
        case 2600:
            return NPMX_LDSW_VOLTAGE_2V6;
        case 2700:
            return NPMX_LDSW_VOLTAGE_2V7;
        case 2800:
            return NPMX_LDSW_VOLTAGE_2V8;
        case 2900:
            return NPMX_LDSW_VOLTAGE_2V9;
        case 3000:
            return NPMX_LDSW_VOLTAGE_3V0;
        case 3100:
            return NPMX_LDSW_VOLTAGE_3V1;
        case 3200:
            return NPMX_LDSW_VOLTAGE_3V2;
        case 3300:
            return NPMX_LDSW_VOLTAGE_3V3;
        default:
            return NPMX_LDSW_VOLTAGE_INVALID;
    }
}

bool npmx_ldsw_voltage_convert_to_mv(npmx_ldsw_voltage_t enum_value,  uint32_t * p_val)
{
    if (enum_value < NPMX_LDSW_VOLTAGE_COUNT)
    {
        *p_val = LDSW_VOLTAGE_BASE + (uint32_t)enum_value * LDSW_VOLTAGE_DIFF;
        return true;
    }
    else
    {
        return false;
    }
}

npmx_ldsw_soft_start_current_t npmx_ldsw_soft_start_current_convert(uint32_t milliamperes)
{
    switch (milliamperes)
    {
        case 25:
            return NPMX_LDSW_SOFT_START_CURRENT_25_MA;
        case 50:
            return NPMX_LDSW_SOFT_START_CURRENT_50_MA;
        case 75:
            return NPMX_LDSW_SOFT_START_CURRENT_75_MA;
        case 100:
            return NPMX_LDSW_SOFT_START_CURRENT_100_MA;
        default:
            return NPMX_LDSW_SOFT_START_CURRENT_INVALID;
    }
}

bool npmx_ldsw_soft_start_current_convert_to_ma(npmx_ldsw_soft_start_current_t enum_value,
                                                uint32_t *                     p_val)
{
    if (enum_value < NPMX_LDSW_SOFT_START_CURRENT_COUNT)
    {
        *p_val = LDSW_SOFT_START_CURRENT_BASE + (uint32_t)enum_value * LDSW_SOFT_START_CURRENT_DIFF;
        return true;
    }
    else
    {
        return false;
    }
}

npmx_error_t npmx_ldsw_task_trigger(npmx_ldsw_t const * p_instance, npmx_ldsw_task_t task)
{
    NPMX_ASSERT(p_instance);
    NPMX_ASSERT(task < NPMX_LDSW_TASK_COUNT);

    return task_trigger(p_instance, task);
}

npmx_error_t npmx_ldsw_enable_gpio_set(npmx_ldsw_t const *             p_instance,
                                       npmx_ldsw_gpio_config_t const * p_config)
{
    NPMX_ASSERT(p_instance);
    NPMX_ASSERT(p_config);
    NPMX_ASSERT(p_config->gpio < NPMX_LDSW_GPIO_COUNT);

    uint8_t data = ((uint8_t)p_config->gpio << m_en_gpio_pos[p_instance->hw_index]) &
                   m_en_gpio_mask[p_instance->hw_index];

    data |= ((p_config->inverted ? LDSW_LDSW1GPISEL_LDSW1GPIINV_INVERTED :
                                   LDSW_LDSW1GPISEL_LDSW1GPIINV_NORMAL)
             << m_inv_gpio_pos[p_instance->hw_index]) &
            m_inv_gpio_mask[p_instance->hw_index];

    return npmx_backend_register_write(p_instance->p_backend,
                                       m_en_reg_addr[p_instance->hw_index],
                                       &data,
                                       1);
}

npmx_error_t npmx_ldsw_enable_gpio_get(npmx_ldsw_t const *       p_instance,
                                       npmx_ldsw_gpio_config_t * p_config)
{
    NPMX_ASSERT(p_instance);
    NPMX_ASSERT(p_config);

    uint8_t      data;
    npmx_error_t err_code = npmx_backend_register_read(p_instance->p_backend,
                                                       m_en_reg_addr[p_instance->hw_index],
                                                       &data,
                                                       1);

    if (err_code != NPMX_SUCCESS)
    {
        return err_code;
    }

    p_config->gpio = (npmx_ldsw_gpio_t)((data & m_en_gpio_mask[p_instance->hw_index])
                                        >> m_en_gpio_pos[p_instance->hw_index]);

    p_config->inverted = ((data & m_inv_gpio_mask[p_instance->hw_index])
                          >> m_inv_gpio_pos[p_instance->hw_index]) ==
                         LDSW_LDSW1GPISEL_LDSW1GPIINV_INVERTED;

    return NPMX_SUCCESS;
}

npmx_error_t npmx_ldsw_status_get(npmx_ldsw_t const * p_instance, uint8_t * p_status_mask)
{
    NPMX_ASSERT(p_instance);
    NPMX_ASSERT(p_status_mask);

    return npmx_backend_register_read(p_instance->p_backend,
                                      NPMX_REG_TO_ADDR(NPM_LDSW->LDSWSTATUS),
                                      p_status_mask,
                                      1);
}

npmx_error_t npmx_ldsw_soft_start_config_set(npmx_ldsw_t const *                   p_instance,
                                             npmx_ldsw_soft_start_config_t const * p_config)
{
    NPMX_ASSERT(p_instance);
    NPMX_ASSERT(p_config);
    NPMX_ASSERT(p_config->current < NPMX_LDSW_SOFT_START_CURRENT_COUNT);

    uint8_t      data;
    npmx_error_t err_code = npmx_backend_register_read(p_instance->p_backend,
                                                       NPMX_REG_TO_ADDR(NPM_LDSW->LDSWCONFIG),
                                                       &data,
                                                       1);
    if (err_code != NPMX_SUCCESS)
    {
        return err_code;
    }

    data &= ~m_soft_start_current_mask[p_instance->hw_index];
    data &= ~m_soft_start_en_mask[p_instance->hw_index];

    data |= ((uint8_t)p_config->current << m_soft_start_current_pos[p_instance->hw_index]) &
            m_soft_start_current_mask[p_instance->hw_index];
    data |= ((p_config->enable ? LDSW_LDSWCONFIG_LDSW1SOFTSTARTDISABLE_NOEFFECT :
                                 LDSW_LDSWCONFIG_LDSW1SOFTSTARTDISABLE_NOSOFTSTART)
             << m_soft_start_en_pos[p_instance->hw_index]) &
            m_soft_start_en_mask[p_instance->hw_index];

    err_code = npmx_backend_register_write(p_instance->p_backend,
                                                       NPMX_REG_TO_ADDR(NPM_LDSW->LDSWCONFIG),
                                           &data,
                                           1);
    if (err_code != NPMX_SUCCESS)
    {
        return err_code;
    }

    return NPMX_SUCCESS;
}

npmx_error_t npmx_ldsw_soft_start_config_get(npmx_ldsw_t const *             p_instance,
                                             npmx_ldsw_soft_start_config_t * p_config)
{
    NPMX_ASSERT(p_instance);
    NPMX_ASSERT(p_config);

    uint8_t      data;
    npmx_error_t err_code = npmx_backend_register_read(p_instance->p_backend,
                                                       NPMX_REG_TO_ADDR(NPM_LDSW->LDSWCONFIG),
                                                       &data,
                                                       1);
    if (err_code != NPMX_SUCCESS)
    {
        return err_code;
    }

    p_config->current =
        (npmx_ldsw_soft_start_current_t)((data & m_soft_start_current_mask[p_instance->hw_index])
                                         >> m_soft_start_current_pos[p_instance->hw_index]);
    p_config->enable = ((data & m_soft_start_en_mask[p_instance->hw_index])
                        >> m_soft_start_en_pos[p_instance->hw_index]) ==
                       LDSW_LDSWCONFIG_LDSW2SOFTSTARTDISABLE_NOSOFTSTART;

    return NPMX_SUCCESS;
}

npmx_error_t npmx_ldsw_active_discharge_enable_set(npmx_ldsw_t const * p_instance, bool enable)
{
    NPMX_ASSERT(p_instance);

    uint8_t      data;
    npmx_error_t err_code = npmx_backend_register_read(p_instance->p_backend,
                                                       NPMX_REG_TO_ADDR(NPM_LDSW->LDSWCONFIG),
                                                       &data,
                                                       1);
    if (err_code != NPMX_SUCCESS)
    {
        return err_code;
    }

    data &= ~m_en_dis_mask[p_instance->hw_index];

    data |= ((enable ? LDSW_LDSWCONFIG_LDSW1ACTIVEDISCHARGE_ACTIVE :
                       LDSW_LDSWCONFIG_LDSW1ACTIVEDISCHARGE_NODISCHARGE)
             << m_en_dis_pos[p_instance->hw_index]) & m_en_dis_mask[p_instance->hw_index];

    err_code = npmx_backend_register_write(p_instance->p_backend,
                                           NPMX_REG_TO_ADDR(NPM_LDSW->LDSWCONFIG),
                                           &data,
                                           1);
    if (err_code != NPMX_SUCCESS)
    {
        return err_code;
    }

    return NPMX_SUCCESS;
}

npmx_error_t npmx_ldsw_active_discharge_enable_get(npmx_ldsw_t const * p_instance, bool * p_enable)
{
    NPMX_ASSERT(p_instance);
    NPMX_ASSERT(p_enable);

    uint8_t      data;
    npmx_error_t err_code = npmx_backend_register_read(p_instance->p_backend,
                                                       NPMX_REG_TO_ADDR(NPM_LDSW->LDSWCONFIG),
                                                       &data,
                                                       1);
    if (err_code != NPMX_SUCCESS)
    {
        return err_code;
    }

    *p_enable = ((data & m_en_dis_mask[p_instance->hw_index])
                 >> m_en_dis_pos[p_instance->hw_index]) ==
                LDSW_LDSWCONFIG_LDSW1ACTIVEDISCHARGE_ACTIVE;

    return NPMX_SUCCESS;
}

npmx_error_t npmx_ldsw_mode_set(npmx_ldsw_t const * p_instance, npmx_ldsw_mode_t mode)
{
    NPMX_ASSERT(p_instance);
    NPMX_ASSERT(mode < NPMX_LDSW_MODE_COUNT);

    uint8_t      data;
    npmx_error_t err_code = npmx_backend_register_read(p_instance->p_backend,
                                                       m_ldo_sel_reg_addr[p_instance->hw_index],
                                                       &data,
                                                       1);
    if (err_code != NPMX_SUCCESS)
    {
        return err_code;
    }

    data &= ~m_ldo_sel_mask[p_instance->hw_index];

    data |= ((mode ? LDSW_LDSW1LDOSEL_LDSW1LDOSEL_LDO :
                     LDSW_LDSW1LDOSEL_LDSW1LDOSEL_LDSW)
             << m_ldo_sel_pos[p_instance->hw_index]) & m_ldo_sel_mask[p_instance->hw_index];

    err_code = npmx_backend_register_write(p_instance->p_backend,
                                           m_ldo_sel_reg_addr[p_instance->hw_index],
                                           &data,
                                           1);

    if (err_code != NPMX_SUCCESS)
    {
        return err_code;
    }

    return NPMX_SUCCESS;
}

npmx_error_t npmx_ldsw_mode_get(npmx_ldsw_t const * p_instance, npmx_ldsw_mode_t * p_mode)
{
    NPMX_ASSERT(p_instance);
    NPMX_ASSERT(p_mode);

    uint8_t      data;
    npmx_error_t err_code = npmx_backend_register_read(p_instance->p_backend,
                                                       m_ldo_sel_reg_addr[p_instance->hw_index],
                                                       &data,
                                                       1);

    if (err_code != NPMX_SUCCESS)
    {
        return err_code;
    }

    *p_mode = ((data & m_ldo_sel_mask[p_instance->hw_index])
               >> m_ldo_sel_pos[p_instance->hw_index]) ==
              LDSW_LDSW1LDOSEL_LDSW1LDOSEL_LDO;

    return NPMX_SUCCESS;
}

npmx_error_t npmx_ldsw_ldo_voltage_set(npmx_ldsw_t const * p_instance, npmx_ldsw_voltage_t voltage)
{
    NPMX_ASSERT(p_instance);
    NPMX_ASSERT(voltage < NPMX_LDSW_VOLTAGE_COUNT);

    uint8_t data = ((uint8_t)voltage << LDSW_LDSW1VOUTSEL_LDSW1VOUTSEL_Pos) &
                   LDSW_LDSW1VOUTSEL_LDSW1VOUTSEL_Msk;

    return npmx_backend_register_write(p_instance->p_backend,
                                       m_vout_sel_reg_addr[p_instance->hw_index],
                                       &data,
                                       1);
}

npmx_error_t npmx_ldsw_ldo_voltage_get(npmx_ldsw_t const *   p_instance,
                                       npmx_ldsw_voltage_t * p_voltage)
{
    NPMX_ASSERT(p_instance);
    NPMX_ASSERT(p_voltage);

    uint8_t data;
    npmx_error_t err_code = npmx_backend_register_read(p_instance->p_backend,
                                                       m_vout_sel_reg_addr[p_instance->hw_index],
                                                       &data,
                                                       1);

    if (err_code != NPMX_SUCCESS)
    {
        return err_code;
    }

    *p_voltage = ((uint8_t)data & LDSW_LDSW1VOUTSEL_LDSW1VOUTSEL_Msk)
                 >> LDSW_LDSW1VOUTSEL_LDSW1VOUTSEL_Pos;

    return NPMX_SUCCESS;
}
