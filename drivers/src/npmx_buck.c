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

#include <npmx_buck.h>
#include <npmx_instance.h>

/**
 * @brief Symbols used in @ref npmx_buck_voltage_convert_to_mv function
 *        in the conversion from enumeration to millivolts.
 */
#define BUCK_VOLTAGE_BASE 1000UL
#define BUCK_VOLTAGE_DIFF 100UL

/* Checking that the BUCK1NORMVOUT and BUCK2NORMVOUT registers are the same. */
NPMX_STATIC_ASSERT(BUCK_BUCK1NORMVOUT_BUCK1NORMVOUT_Pos == BUCK_BUCK2NORMVOUT_BUCK2NORMVOUT_Pos);
NPMX_STATIC_ASSERT(BUCK_BUCK1NORMVOUT_BUCK1NORMVOUT_Msk == BUCK_BUCK2NORMVOUT_BUCK2NORMVOUT_Msk);

/* Checking that the BUCK1RETVOUT and BUCK2RETVOUT registers are the same. */
NPMX_STATIC_ASSERT(BUCK_BUCK1RETVOUT_BUCK1RETVOUT_Pos == BUCK_BUCK2RETVOUT_BUCK2RETVOUT_Pos);
NPMX_STATIC_ASSERT(BUCK_BUCK1RETVOUT_BUCK1RETVOUT_Msk == BUCK_BUCK2RETVOUT_BUCK2RETVOUT_Msk);

typedef enum
{
    NPMX_BUCK_GPIO_TYPE_ENABLE,
    NPMX_BUCK_GPIO_TYPE_VRET,
    NPMX_BUCK_GPIO_TYPE_PWM,
} npmx_buck_gpio_type_t;

static const uint16_t m_reten_vol_addr[NPMX_PERIPH_BUCK_COUNT] =
{
    [0] = NPMX_REG_TO_ADDR(NPM_BUCK->BUCK1RETVOUT),
    [1] = NPMX_REG_TO_ADDR(NPM_BUCK->BUCK2RETVOUT),
};

static const uint8_t m_ctrl_pos[NPMX_PERIPH_BUCK_COUNT] =
{
    [0] = BUCK_BUCKSWCTRLSEL_BUCK1SWCTRLSEL_Pos,
    [1] = BUCK_BUCKSWCTRLSEL_BUCK2SWCTRLSEL_Pos,
};

static const uint8_t m_ctrl_msk[NPMX_PERIPH_BUCK_COUNT] =
{
    [0] = BUCK_BUCKSWCTRLSEL_BUCK1SWCTRLSEL_Msk,
    [1] = BUCK_BUCKSWCTRLSEL_BUCK2SWCTRLSEL_Msk,
};

static const uint8_t m_pull_down_pos[NPMX_PERIPH_BUCK_COUNT] =
{
    [0] = BUCK_BUCKCTRL0_BUCK1ENPULLDOWN_Pos,
    [1] = BUCK_BUCKCTRL0_BUCK2ENPULLDOWN_Pos,
};

static const uint8_t m_pull_down_msk[NPMX_PERIPH_BUCK_COUNT] =
{
    [0] = BUCK_BUCKCTRL0_BUCK1ENPULLDOWN_Msk,
    [1] = BUCK_BUCKCTRL0_BUCK2ENPULLDOWN_Msk,
};

static const uint16_t m_norm_vol_addr[NPMX_PERIPH_BUCK_COUNT] =
{
    [0] = NPMX_REG_TO_ADDR(NPM_BUCK->BUCK1NORMVOUT),
    [1] = NPMX_REG_TO_ADDR(NPM_BUCK->BUCK2NORMVOUT),
};

#if defined(BUCK_BUCKSTATUS_BUCK1MODE_Msk)
static const uint8_t m_status_mode_msk[NPMX_PERIPH_BUCK_COUNT] =
{
    [0] = BUCK_BUCKSTATUS_BUCK1MODE_Msk,
    [1] = BUCK_BUCKSTATUS_BUCK2MODE_Msk,
};

static const uint8_t m_status_mode_pos[NPMX_PERIPH_BUCK_COUNT] =
{
    [0] = BUCK_BUCKSTATUS_BUCK1MODE_Pos,
    [1] = BUCK_BUCKSTATUS_BUCK2MODE_Pos,
};

static const uint8_t m_status_pwrgood_msk[NPMX_PERIPH_BUCK_COUNT] =
{
    [0] = BUCK_BUCKSTATUS_BUCK1PWRGOOD_Msk,
    [1] = BUCK_BUCKSTATUS_BUCK2PWRGOOD_Msk,
};

static const uint8_t m_status_pwrgood_pos[NPMX_PERIPH_BUCK_COUNT] =
{
    [0] = BUCK_BUCKSTATUS_BUCK1PWRGOOD_Pos,
    [1] = BUCK_BUCKSTATUS_BUCK2PWRGOOD_Pos,
};

static const uint8_t m_status_pwmok_msk[NPMX_PERIPH_BUCK_COUNT] =
{
    [0] = BUCK_BUCKSTATUS_BUCK1PWMOK_Msk,
    [1] = BUCK_BUCKSTATUS_BUCK2PWMOK_Msk,
};

static const uint8_t m_status_pwmok_pos[NPMX_PERIPH_BUCK_COUNT] =
{
    [0] = BUCK_BUCKSTATUS_BUCK1PWMOK_Pos,
    [1] = BUCK_BUCKSTATUS_BUCK2PWMOK_Pos,
};
#endif

/**
 * @brief Function for activating the specified BUCK task.
 *
 * @param p_instance Pointer to the BUCK instance.
 * @param task       Task to be activated.
 *
 * @retval NPMX_SUCCESS  Operation performed successfully.
 * @retval NPMX_ERROR_IO Error using IO bus line.
 */
static npmx_error_t task_trigger(npmx_buck_t const * p_instance, npmx_buck_task_t task)
{
    uint8_t data = NPMX_TASK_TRIGGER;

    static const uint16_t task_addr[][NPMX_PERIPH_BUCK_COUNT] =
    {
        [NPMX_BUCK_TASK_ENABLE] =
        {
            [0] = NPMX_REG_TO_ADDR(NPM_BUCK->BUCK1ENASET),
            [1] = NPMX_REG_TO_ADDR(NPM_BUCK->BUCK2ENASET),
        },
        [NPMX_BUCK_TASK_DISABLE] =
        {
            [0] = NPMX_REG_TO_ADDR(NPM_BUCK->BUCK1ENACLR),
            [1] = NPMX_REG_TO_ADDR(NPM_BUCK->BUCK2ENACLR),
        },
        [NPMX_BUCK_TASK_ENABLE_PWM] =
        {
            [0] = NPMX_REG_TO_ADDR(NPM_BUCK->BUCK1PWMSET),
            [1] = NPMX_REG_TO_ADDR(NPM_BUCK->BUCK2PWMSET),
        },
        [NPMX_BUCK_TASK_DISABLE_PWM] =
        {
            [0] = NPMX_REG_TO_ADDR(NPM_BUCK->BUCK1PWMCLR),
            [1] = NPMX_REG_TO_ADDR(NPM_BUCK->BUCK2PWMCLR),
        },
    };

    uint16_t address = task_addr[task][p_instance->hw_index];

    return npmx_backend_register_write(p_instance->p_backend, address, &data, 1);
}

/**
 * @brief Function for setting the PWM mode of the buck converter.
 *
 * @param[in] p_instance Pointer to the BUCK instance.
 * @param[in] enable     True for PWM mode, false for AUTO mode.
 *
 * @retval NPMX_SUCCESS             Operation performed successfully.
 * @retval NPMX_ERROR_IO            Error using IO bus line.
 */
static npmx_error_t pwm_enable_set(npmx_buck_t const * p_instance, bool enable)
{
    return task_trigger(p_instance, enable ? NPMX_BUCK_TASK_ENABLE_PWM :
                                             NPMX_BUCK_TASK_DISABLE_PWM);
}

/**
 * @brief Function for setting the PFM mode of the buck converter.
 *
 * @param[in] p_instance Pointer to the BUCK instance.
 * @param[in] enable     True for PFM mode, false for AUTO mode.
 *
 * @retval NPMX_SUCCESS             Operation performed successfully.
 * @retval NPMX_ERROR_IO            Error using IO bus line.
 */
static npmx_error_t pfm_enable_set(npmx_buck_t const * p_instance, bool enable)
{
    uint8_t mode_mask = p_instance->hw_index == 0 ? BUCK_BUCKCTRL0_BUCK1AUTOCTRLSEL_Msk :
                                                    BUCK_BUCKCTRL0_BUCK2AUTOCTRLSEL_Msk;
    uint8_t mode_pos  = p_instance->hw_index == 0 ? BUCK_BUCKCTRL0_BUCK1AUTOCTRLSEL_Pos :
                                                    BUCK_BUCKCTRL0_BUCK2AUTOCTRLSEL_Pos;
    uint8_t control;

    npmx_error_t err_code = npmx_backend_register_read(p_instance->p_backend,
                                                       NPMX_REG_TO_ADDR(NPM_BUCK->BUCKCTRL0),
                                                       &control,
                                                       1);

    if (err_code != NPMX_SUCCESS)
    {
        return err_code;
    }

    control &= ~mode_mask;
    control |= ((enable ? BUCK_BUCKCTRL0_BUCK1AUTOCTRLSEL_PFM :
                          BUCK_BUCKCTRL0_BUCK1AUTOCTRLSEL_AUTO)
                << mode_pos) & mode_mask;

    err_code = npmx_backend_register_write(p_instance->p_backend,
                                           NPMX_REG_TO_ADDR(NPM_BUCK->BUCKCTRL0),
                                           &control,
                                           1);

    if (err_code != NPMX_SUCCESS)
    {
        return err_code;
    }

    return NPMX_SUCCESS;
}

static uint16_t gpio_config_addr_get(npmx_buck_gpio_type_t type)
{
    static const uint16_t gpio_conf[] =
    {
        [NPMX_BUCK_GPIO_TYPE_ENABLE] = NPMX_REG_TO_ADDR(NPM_BUCK->BUCKENCTRL),
        [NPMX_BUCK_GPIO_TYPE_VRET]   = NPMX_REG_TO_ADDR(NPM_BUCK->BUCKVRETCTRL),
        [NPMX_BUCK_GPIO_TYPE_PWM]    = NPMX_REG_TO_ADDR(NPM_BUCK->BUCKPWMCTRL),
    };

    return gpio_conf[type];
}

static uint8_t gpio_config_pin_mask_get(npmx_buck_t const * p_instance, npmx_buck_gpio_type_t type)
{
    static const uint8_t pin_mask[][NPMX_PERIPH_BUCK_COUNT] =
    {
        [NPMX_BUCK_GPIO_TYPE_ENABLE] =
        {
            [0] = BUCK_BUCKENCTRL_BUCK1ENGPISEL_Msk,
            [1] = BUCK_BUCKENCTRL_BUCK2ENGPISEL_Msk,
        },
        [NPMX_BUCK_GPIO_TYPE_VRET] =
        {
            [0] = BUCK_BUCKVRETCTRL_BUCK1VRETGPISEL_Msk,
            [1] = BUCK_BUCKVRETCTRL_BUCK2VRETGPISEL_Msk,
        },
        [NPMX_BUCK_GPIO_TYPE_PWM] =
        {
            [0] = BUCK_BUCKPWMCTRL_BUCK1PWMGPISEL_Msk,
            [1] = BUCK_BUCKPWMCTRL_BUCK2PWMGPISEL_Msk,
        },
    };

    return pin_mask[type][p_instance->hw_index];
}

static uint8_t gpio_config_pin_pos_get(npmx_buck_t const * p_instance, npmx_buck_gpio_type_t type)
{
    static const uint8_t pos_mask[][NPMX_PERIPH_BUCK_COUNT] =
    {
        [NPMX_BUCK_GPIO_TYPE_ENABLE] =
        {
            [0] = BUCK_BUCKENCTRL_BUCK1ENGPISEL_Pos,
            [1] = BUCK_BUCKENCTRL_BUCK2ENGPISEL_Pos,
        },
        [NPMX_BUCK_GPIO_TYPE_VRET] =
        {
            [0] = BUCK_BUCKVRETCTRL_BUCK1VRETGPISEL_Pos,
            [1] = BUCK_BUCKVRETCTRL_BUCK2VRETGPISEL_Pos,
        },
        [NPMX_BUCK_GPIO_TYPE_PWM] =
        {
            [0] = BUCK_BUCKPWMCTRL_BUCK1PWMGPISEL_Pos,
            [1] = BUCK_BUCKPWMCTRL_BUCK2PWMGPISEL_Pos,
        },
    };

    return pos_mask[type][p_instance->hw_index];
}

static uint8_t gpio_config_inv_mask_get(npmx_buck_t const * p_instance, npmx_buck_gpio_type_t type)
{
    static const uint8_t inv_mask[][NPMX_PERIPH_BUCK_COUNT] =
    {
        [NPMX_BUCK_GPIO_TYPE_ENABLE] =
        {
            [0] = BUCK_BUCKENCTRL_BUCK1ENGPIINV_Msk,
            [1] = BUCK_BUCKENCTRL_BUCK2ENGPIINV_Msk,
        },
        [NPMX_BUCK_GPIO_TYPE_VRET] =
        {
            [0] = BUCK_BUCKVRETCTRL_BUCK1VRETGPIINV_Msk,
            [1] = BUCK_BUCKVRETCTRL_BUCK2VRETGPIINV_Msk,
        },
        [NPMX_BUCK_GPIO_TYPE_PWM] =
        {
            [0] = BUCK_BUCKPWMCTRL_BUCK1PWMGPIINV_Msk,
            [1] = BUCK_BUCKPWMCTRL_BUCK2PWMGPIINV_Msk,
        },
    };

    return inv_mask[type][p_instance->hw_index];
}

static uint8_t gpio_config_inv_pos_get(npmx_buck_t const * p_instance, npmx_buck_gpio_type_t type)
{
    static const uint8_t inv_pos[][NPMX_PERIPH_BUCK_COUNT] =
    {
        [NPMX_BUCK_GPIO_TYPE_ENABLE] =
        {
            [0] = BUCK_BUCKENCTRL_BUCK1ENGPIINV_Pos,
            [1] = BUCK_BUCKENCTRL_BUCK2ENGPIINV_Pos,
        },
        [NPMX_BUCK_GPIO_TYPE_VRET] =
        {
            [0] = BUCK_BUCKVRETCTRL_BUCK1VRETGPIINV_Pos,
            [1] = BUCK_BUCKVRETCTRL_BUCK2VRETGPIINV_Pos,
        },
        [NPMX_BUCK_GPIO_TYPE_PWM] =
        {
            [0] = BUCK_BUCKPWMCTRL_BUCK1PWMGPIINV_Pos,
            [1] = BUCK_BUCKPWMCTRL_BUCK2PWMGPIINV_Pos,
        },
    };

    return inv_pos[type][p_instance->hw_index];
}

static uint8_t gpio_config_normal_get(npmx_buck_t const * p_instance, npmx_buck_gpio_type_t type)
{
    static const uint8_t normal[][NPMX_PERIPH_BUCK_COUNT] =
    {
        [NPMX_BUCK_GPIO_TYPE_ENABLE] =
        {
            [0] = BUCK_BUCKENCTRL_BUCK1ENGPIINV_NORMAL,
            [1] = BUCK_BUCKENCTRL_BUCK2ENGPIINV_NORMAL,
        },
        [NPMX_BUCK_GPIO_TYPE_VRET] =
        {
            [0] = BUCK_BUCKVRETCTRL_BUCK1VRETGPIINV_NORMAL,
            [1] = BUCK_BUCKVRETCTRL_BUCK2VRETGPIINV_NORMAL,
        },
        [NPMX_BUCK_GPIO_TYPE_PWM] =
        {
            [0] = BUCK_BUCKPWMCTRL_BUCK1PWMGPIINV_NORMAL,
            [1] = BUCK_BUCKPWMCTRL_BUCK2PWMGPIINV_NORMAL,
        },
    };

    return normal[type][p_instance->hw_index];
}

static uint8_t gpio_config_inverted_get(npmx_buck_t const * p_instance, npmx_buck_gpio_type_t type)
{
    static const uint8_t inverted[][NPMX_PERIPH_BUCK_COUNT] =
    {
        [NPMX_BUCK_GPIO_TYPE_ENABLE] =
        {
            [0] = BUCK_BUCKENCTRL_BUCK1ENGPIINV_INVERTED,
            [1] = BUCK_BUCKENCTRL_BUCK2ENGPIINV_INVERTED,
        },
        [NPMX_BUCK_GPIO_TYPE_VRET] =
        {
            [0] = BUCK_BUCKVRETCTRL_BUCK1VRETGPIINV_INVERTED,
            [1] = BUCK_BUCKVRETCTRL_BUCK2VRETGPIINV_INVERTED,
        },
        [NPMX_BUCK_GPIO_TYPE_PWM] =
        {
            [0] = BUCK_BUCKPWMCTRL_BUCK1PWMGPIINV_INVERTED,
            [1] = BUCK_BUCKPWMCTRL_BUCK2PWMGPIINV_INVERTED,
        },
    };

    return inverted[type][p_instance->hw_index];
}

static npmx_error_t gpio_config_set(npmx_buck_t const *             p_instance,
                                    npmx_buck_gpio_type_t           type,
                                    npmx_buck_gpio_config_t const * p_config)
{
    uint8_t pin_mask = gpio_config_pin_mask_get(p_instance, type);
    uint8_t pin_pos  = gpio_config_pin_pos_get(p_instance, type);
    uint8_t inv_mask = gpio_config_inv_mask_get(p_instance, type);
    uint8_t inv_pos  = gpio_config_inv_pos_get(p_instance, type);
    uint8_t control;

    npmx_error_t err_code = npmx_backend_register_read(p_instance->p_backend,
                                                       gpio_config_addr_get(type),
                                                       &control,
                                                       1);

    if (err_code != NPMX_SUCCESS)
    {
        return err_code;
    }

    control &= ~pin_mask;
    control &= ~inv_mask;

    control |= (p_config->gpio << pin_pos) & pin_mask;

    control |= ((p_config->inverted ? gpio_config_inverted_get(p_instance, type) :
                 gpio_config_normal_get(p_instance, type)) << inv_pos) & inv_mask;

    return npmx_backend_register_write(p_instance->p_backend,
                                       gpio_config_addr_get(type),
                                       &control,
                                       1);
}

static npmx_error_t gpio_config_get(npmx_buck_t const *       p_instance,
                                    npmx_buck_gpio_type_t     type,
                                    npmx_buck_gpio_config_t * p_config)
{
    uint8_t pin_mask = gpio_config_pin_mask_get(p_instance, type);
    uint8_t pin_pos  = gpio_config_pin_pos_get(p_instance, type);
    uint8_t inv_mask = gpio_config_inv_mask_get(p_instance, type);
    uint8_t inv_pos  = gpio_config_inv_pos_get(p_instance, type);

    uint8_t      data;
    npmx_error_t err_code = npmx_backend_register_read(p_instance->p_backend,
                                                       gpio_config_addr_get(type),
                                                       &data,
                                                       1);

    if (err_code != NPMX_SUCCESS)
    {
        return err_code;
    }

    p_config->gpio     = (data & pin_mask) >> pin_pos;
    p_config->inverted = ((data & inv_mask) >> inv_pos) ==
                         gpio_config_inverted_get(p_instance, type);

    return NPMX_SUCCESS;
}

npmx_buck_t * npmx_buck_get(npmx_instance_t * p_pmic, uint8_t idx)
{
    NPMX_ASSERT(p_pmic);
    NPMX_ASSERT(idx < NPMX_PERIPH_BUCK_COUNT);

    return &p_pmic->buck[idx];
}

npmx_buck_voltage_t npmx_buck_voltage_convert(uint32_t millivolts)
{
    switch (millivolts)
    {
        case 1000:
            return NPMX_BUCK_VOLTAGE_1V0;
        case 1100:
            return NPMX_BUCK_VOLTAGE_1V1;
        case 1200:
            return NPMX_BUCK_VOLTAGE_1V2;
        case 1300:
            return NPMX_BUCK_VOLTAGE_1V3;
        case 1400:
            return NPMX_BUCK_VOLTAGE_1V4;
        case 1500:
            return NPMX_BUCK_VOLTAGE_1V5;
        case 1600:
            return NPMX_BUCK_VOLTAGE_1V6;
        case 1700:
            return NPMX_BUCK_VOLTAGE_1V7;
        case 1800:
            return NPMX_BUCK_VOLTAGE_1V8;
        case 1900:
            return NPMX_BUCK_VOLTAGE_1V9;
        case 2000:
            return NPMX_BUCK_VOLTAGE_2V0;
        case 2100:
            return NPMX_BUCK_VOLTAGE_2V1;
        case 2200:
            return NPMX_BUCK_VOLTAGE_2V2;
        case 2300:
            return NPMX_BUCK_VOLTAGE_2V3;
        case 2400:
            return NPMX_BUCK_VOLTAGE_2V4;
        case 2500:
            return NPMX_BUCK_VOLTAGE_2V5;
        case 2600:
            return NPMX_BUCK_VOLTAGE_2V6;
        case 2700:
            return NPMX_BUCK_VOLTAGE_2V7;
        case 2800:
            return NPMX_BUCK_VOLTAGE_2V8;
        case 2900:
            return NPMX_BUCK_VOLTAGE_2V9;
        case 3000:
            return NPMX_BUCK_VOLTAGE_3V0;
        case 3100:
            return NPMX_BUCK_VOLTAGE_3V1;
        case 3200:
            return NPMX_BUCK_VOLTAGE_3V2;
        case 3300:
            return NPMX_BUCK_VOLTAGE_3V3;
        default:
            return NPMX_BUCK_VOLTAGE_INVALID;
    }
}

uint32_t npmx_buck_voltage_convert_to_mv(npmx_buck_voltage_t enum_value)
{
    NPMX_ASSERT(enum_value != NPMX_BUCK_VOLTAGE_INVALID);

    return BUCK_VOLTAGE_BASE + (uint32_t)enum_value * BUCK_VOLTAGE_DIFF;
}

npmx_error_t npmx_buck_task_trigger(npmx_buck_t const * p_instance, npmx_buck_task_t task)
{
    NPMX_ASSERT(p_instance);

    return task_trigger(p_instance, task);
}

npmx_error_t npmx_buck_converter_mode_set(npmx_buck_t const * p_instance, npmx_buck_mode_t mode)
{
    NPMX_ASSERT(p_instance);

    /* Setting the mode of the buck converter to force PWM mode or AUTO. */
    npmx_error_t err_code = pwm_enable_set(p_instance, (mode == NPMX_BUCK_MODE_PWM));

    if (err_code != NPMX_SUCCESS)
    {
        return err_code;
    }

    /* Setting the mode of the buck converter to force PFM mode or AUTO. */
    return pfm_enable_set(p_instance, (mode == NPMX_BUCK_MODE_PFM));
}

npmx_error_t npmx_buck_pfm_enable_get(npmx_buck_t const * p_instance, bool * p_enable)
{
    NPMX_ASSERT(p_instance);
    NPMX_ASSERT(p_enable);

    uint8_t mode_mask = p_instance->hw_index == 0 ? BUCK_BUCKCTRL0_BUCK1AUTOCTRLSEL_Msk :
                                                    BUCK_BUCKCTRL0_BUCK2AUTOCTRLSEL_Msk;
    uint8_t mode_pos  = p_instance->hw_index == 0 ? BUCK_BUCKCTRL0_BUCK1AUTOCTRLSEL_Pos :
                                                    BUCK_BUCKCTRL0_BUCK2AUTOCTRLSEL_Pos;

    uint8_t      data;
    npmx_error_t err_code = npmx_backend_register_read(p_instance->p_backend,
                                                       NPMX_REG_TO_ADDR(NPM_BUCK->BUCKCTRL0),
                                                       &data,
                                                       1);

    if (err_code != NPMX_SUCCESS)
    {
        return err_code;
    }

    *p_enable = ((data & mode_mask) >> mode_pos) ==
                BUCK_BUCKCTRL0_BUCK1AUTOCTRLSEL_PFM;

    return NPMX_SUCCESS;
}

npmx_error_t npmx_buck_normal_voltage_set(npmx_buck_t const * p_instance,
                                          npmx_buck_voltage_t voltage)
{
    NPMX_ASSERT(p_instance);
    NPMX_ASSERT(voltage <= NPMX_BUCK_VOLTAGE_MAX);

    uint8_t data = ((uint8_t)voltage << BUCK_BUCK1NORMVOUT_BUCK1NORMVOUT_Pos) &
                   BUCK_BUCK1NORMVOUT_BUCK1NORMVOUT_Msk;

    return npmx_backend_register_write(p_instance->p_backend,
                                       m_norm_vol_addr[p_instance->hw_index],
                                       &data,
                                       1);
}

npmx_error_t npmx_buck_normal_voltage_get(npmx_buck_t const *   p_instance,
                                          npmx_buck_voltage_t * p_voltage)
{
    NPMX_ASSERT(p_instance);
    NPMX_ASSERT(p_voltage);

    uint8_t      data;
    npmx_error_t err_code = npmx_backend_register_read(p_instance->p_backend,
                                                       m_norm_vol_addr[p_instance->hw_index],
                                                       &data,
                                                       1);
    if (err_code != NPMX_SUCCESS)
    {
        return err_code;
    }

    *p_voltage = ((uint8_t)data & BUCK_BUCK1NORMVOUT_BUCK1NORMVOUT_Msk)
                 >> BUCK_BUCK1NORMVOUT_BUCK1NORMVOUT_Pos;

    return NPMX_SUCCESS;
}

npmx_error_t npmx_buck_retention_voltage_set(npmx_buck_t const * p_instance,
                                             npmx_buck_voltage_t voltage)
{
    NPMX_ASSERT(p_instance);
    NPMX_ASSERT(voltage <= NPMX_BUCK_VOLTAGE_MAX);

    uint8_t data = ((uint8_t)voltage << BUCK_BUCK1RETVOUT_BUCK1RETVOUT_Pos) &
                   BUCK_BUCK1RETVOUT_BUCK1RETVOUT_Msk;

    return npmx_backend_register_write(p_instance->p_backend,
                                       m_reten_vol_addr[p_instance->hw_index],
                                       &data,
                                       1);
}

npmx_error_t npmx_buck_retention_voltage_get(npmx_buck_t const *   p_instance,
                                             npmx_buck_voltage_t * p_voltage)
{
    NPMX_ASSERT(p_instance);
    NPMX_ASSERT(p_voltage);

    uint8_t      data;
    npmx_error_t err_code = npmx_backend_register_read(p_instance->p_backend,
                                                       m_reten_vol_addr[p_instance->hw_index],
                                                       &data,
                                                       1);
    if (err_code != NPMX_SUCCESS)
    {
        return err_code;
    }

    *p_voltage = ((uint8_t)data & BUCK_BUCK1RETVOUT_BUCK1RETVOUT_Msk)
                 >> BUCK_BUCK1RETVOUT_BUCK1RETVOUT_Pos;

    return NPMX_SUCCESS;
}

npmx_error_t npmx_buck_enable_gpio_config_set(npmx_buck_t const *             p_instance,
                                              npmx_buck_gpio_config_t const * p_config)
{
    NPMX_ASSERT(p_instance);
    NPMX_ASSERT(p_config);

    return gpio_config_set(p_instance, NPMX_BUCK_GPIO_TYPE_ENABLE, p_config);
}

npmx_error_t npmx_buck_enable_gpio_config_get(npmx_buck_t const *       p_instance,
                                              npmx_buck_gpio_config_t * p_config)
{
    NPMX_ASSERT(p_instance);
    NPMX_ASSERT(p_config);

    return gpio_config_get(p_instance, NPMX_BUCK_GPIO_TYPE_ENABLE, p_config);
}

npmx_error_t npmx_buck_retention_gpio_config_set(npmx_buck_t const *             p_instance,
                                                 npmx_buck_gpio_config_t const * p_config)
{
    NPMX_ASSERT(p_instance);
    NPMX_ASSERT(p_config);

    return gpio_config_set(p_instance, NPMX_BUCK_GPIO_TYPE_VRET, p_config);
}

npmx_error_t npmx_buck_retention_gpio_config_get(npmx_buck_t const *       p_instance,
                                                 npmx_buck_gpio_config_t * p_config)
{
    NPMX_ASSERT(p_instance);
    NPMX_ASSERT(p_config);

    return gpio_config_get(p_instance, NPMX_BUCK_GPIO_TYPE_VRET, p_config);
}

npmx_error_t npmx_buck_forced_pwm_gpio_config_set(npmx_buck_t const *             p_instance,
                                                  npmx_buck_gpio_config_t const * p_config)
{
    NPMX_ASSERT(p_instance);
    NPMX_ASSERT(p_config);

    return gpio_config_set(p_instance, NPMX_BUCK_GPIO_TYPE_PWM, p_config);
}

npmx_error_t npmx_buck_forced_pwm_gpio_config_get(npmx_buck_t const *       p_instance,
                                                  npmx_buck_gpio_config_t * p_config)
{
    NPMX_ASSERT(p_instance);
    NPMX_ASSERT(p_config);

    return gpio_config_get(p_instance, NPMX_BUCK_GPIO_TYPE_PWM, p_config);
}

npmx_error_t npmx_buck_vout_select_set(npmx_buck_t const *     p_instance,
                                       npmx_buck_vout_select_t selection)
{
    NPMX_ASSERT(p_instance);

    uint8_t control;

    npmx_error_t err_code = npmx_backend_register_read(p_instance->p_backend,
                                                       NPMX_REG_TO_ADDR(NPM_BUCK->BUCKSWCTRLSEL),
                                                       &control,
                                                       1);

    if (err_code != NPMX_SUCCESS)
    {
        return err_code;
    }

    control &= ~m_ctrl_msk[p_instance->hw_index];
    control |= ((uint8_t)selection << m_ctrl_pos[p_instance->hw_index]) &
               m_ctrl_msk[p_instance->hw_index];

    return npmx_backend_register_write(p_instance->p_backend,
                                       NPMX_REG_TO_ADDR(NPM_BUCK->BUCKSWCTRLSEL),
                                       &control,
                                       1);
}

npmx_error_t npmx_buck_vout_select_get(npmx_buck_t const *       p_instance,
                                       npmx_buck_vout_select_t * p_selection)
{
    NPMX_ASSERT(p_instance);
    NPMX_ASSERT(p_selection);

    uint8_t      data;
    npmx_error_t err_code = npmx_backend_register_read(p_instance->p_backend,
                                                       NPMX_REG_TO_ADDR(NPM_BUCK->BUCKSWCTRLSEL),
                                                       &data,
                                                       1);
    if (err_code != NPMX_SUCCESS)
    {
        return err_code;
    }

    *p_selection = (npmx_buck_vout_select_t)((data & m_ctrl_msk[p_instance->hw_index])
                                             >> m_ctrl_pos[p_instance->hw_index]);

    return NPMX_SUCCESS;
}

npmx_error_t npmx_buck_status_voltage_get(npmx_buck_t const *   p_instance,
                                          npmx_buck_voltage_t * p_voltage)
{
    NPMX_ASSERT(p_instance);
    NPMX_ASSERT(p_voltage);

    static const uint16_t status_registers[] =
    {
        [0] = NPMX_REG_TO_ADDR(NPM_BUCK->BUCK1VOUTSTATUS),
        [1] = NPMX_REG_TO_ADDR(NPM_BUCK->BUCK2VOUTSTATUS),
    };

    uint8_t      data;
    npmx_error_t err_code = npmx_backend_register_read(p_instance->p_backend,
                                                       status_registers[p_instance->hw_index],
                                                       &data,
                                                       1);

    if (err_code != NPMX_SUCCESS)
    {
        return err_code;
    }

    *p_voltage = (npmx_buck_voltage_t)data;

    return NPMX_SUCCESS;
}

npmx_error_t npmx_buck_active_discharge_enable_set(npmx_buck_t const * p_instance, bool enable)
{
    NPMX_ASSERT(p_instance);

    uint8_t      control;
    npmx_error_t err_code = npmx_backend_register_read(p_instance->p_backend,
                                                       NPMX_REG_TO_ADDR(NPM_BUCK->BUCKCTRL0),
                                                       &control,
                                                       1);

    if (err_code != NPMX_SUCCESS)
    {
        return err_code;
    }

    control &= ~m_pull_down_msk[p_instance->hw_index];
    control |= ((enable ? BUCK_BUCKCTRL0_BUCK1ENPULLDOWN_HIGH :
                          BUCK_BUCKCTRL0_BUCK1ENPULLDOWN_LOW)
                << m_pull_down_pos[p_instance->hw_index]) & m_pull_down_msk[p_instance->hw_index];

    return npmx_backend_register_write(p_instance->p_backend,
                                                       NPMX_REG_TO_ADDR(NPM_BUCK->BUCKCTRL0),
                                       &control,
                                       1);
}

npmx_error_t npmx_buck_active_discharge_enable_get(npmx_buck_t const * p_instance, bool * p_enable)
{
    NPMX_ASSERT(p_instance);
    NPMX_ASSERT(p_enable);

    uint8_t      data;
    npmx_error_t err_code = npmx_backend_register_read(p_instance->p_backend,
                                                       NPMX_REG_TO_ADDR(NPM_BUCK->BUCKCTRL0),
                                                       &data,
                                                       1);
    if (err_code != NPMX_SUCCESS)
    {
        return err_code;
    }

    *p_enable = ((data & m_pull_down_msk[p_instance->hw_index])
                 >> m_pull_down_pos[p_instance->hw_index]) == BUCK_BUCKCTRL0_BUCK1ENPULLDOWN_HIGH;

    return NPMX_SUCCESS;
}

#if defined(BUCK_BUCKSTATUS_BUCK1MODE_Msk)
npmx_error_t npmx_buck_status_get(npmx_buck_t const * p_instance, npmx_buck_status_t * p_status)
{
    NPMX_ASSERT(p_instance);
    NPMX_ASSERT(p_status);

    uint8_t      data;
    npmx_error_t err_code = npmx_backend_register_read(p_instance->p_backend,
                                                       NPMX_REG_TO_ADDR(NPM_BUCK->BUCKSTATUS),
                                                       &data,
                                                       1);
    if (err_code != NPMX_SUCCESS)
    {
        return err_code;
    }

    p_status->buck_mode = (npmx_buck_mode_t)((data & m_status_mode_msk[p_instance->hw_index])
                                             >> m_status_mode_pos[p_instance->hw_index]);

    p_status->powered = ((data & m_status_pwrgood_msk[p_instance->hw_index])
                         >> m_status_pwrgood_pos[p_instance->hw_index]) ==
                        BUCK_BUCKSTATUS_BUCK1PWRGOOD_BUCKPOWERED;

    p_status->pwm_enabled = ((data & m_status_pwmok_msk[p_instance->hw_index])
                             >> m_status_pwmok_pos[p_instance->hw_index]) ==
                            BUCK_BUCKSTATUS_BUCK1PWMOK_PWMMODEENABLED;

    return NPMX_SUCCESS;
}
#endif
