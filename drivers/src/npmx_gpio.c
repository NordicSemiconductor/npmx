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

#include <npmx_gpio.h>
#include <npmx_instance.h>

/* Static assertion for GPIO mode register masks. */
NPMX_STATIC_ASSERT(GPIOS_GPIOMODE0_GPIOMODE_Msk == GPIOS_GPIOMODE1_GPIOMODE_Msk);
NPMX_STATIC_ASSERT(GPIOS_GPIOMODE0_GPIOMODE_Msk == GPIOS_GPIOMODE2_GPIOMODE_Msk);
NPMX_STATIC_ASSERT(GPIOS_GPIOMODE0_GPIOMODE_Msk == GPIOS_GPIOMODE3_GPIOMODE_Msk);
NPMX_STATIC_ASSERT(GPIOS_GPIOMODE0_GPIOMODE_Msk == GPIOS_GPIOMODE4_GPIOMODE_Msk);

/* Static assertion for GPIO drive register masks. */
NPMX_STATIC_ASSERT(GPIOS_GPIODRIVE0_GPIODRIVE_Msk == GPIOS_GPIODRIVE1_GPIODRIVE_Msk);
NPMX_STATIC_ASSERT(GPIOS_GPIODRIVE0_GPIODRIVE_Msk == GPIOS_GPIODRIVE2_GPIODRIVE_Msk);
NPMX_STATIC_ASSERT(GPIOS_GPIODRIVE0_GPIODRIVE_Msk == GPIOS_GPIODRIVE3_GPIODRIVE_Msk);
NPMX_STATIC_ASSERT(GPIOS_GPIODRIVE0_GPIODRIVE_Msk == GPIOS_GPIODRIVE4_GPIODRIVE_Msk);

/* Static assertion for GPIO pull-up enable register masks. */
NPMX_STATIC_ASSERT(GPIOS_GPIOPUEN0_GPIOPUEN_Msk == GPIOS_GPIOPUEN1_GPIOPUEN_Msk);
NPMX_STATIC_ASSERT(GPIOS_GPIOPUEN0_GPIOPUEN_Msk == GPIOS_GPIOPUEN2_GPIOPUEN_Msk);
NPMX_STATIC_ASSERT(GPIOS_GPIOPUEN0_GPIOPUEN_Msk == GPIOS_GPIOPUEN3_GPIOPUEN_Msk);
NPMX_STATIC_ASSERT(GPIOS_GPIOPUEN0_GPIOPUEN_Msk == GPIOS_GPIOPUEN4_GPIOPUEN_Msk);

/* Static assertion for GPIO pull-down register masks */
NPMX_STATIC_ASSERT(GPIOS_GPIOPDEN0_GPIOPDEN_Msk == GPIOS_GPIOPDEN1_GPIOPDEN_Msk);
NPMX_STATIC_ASSERT(GPIOS_GPIOPDEN0_GPIOPDEN_Msk == GPIOS_GPIOPDEN2_GPIOPDEN_Msk);
NPMX_STATIC_ASSERT(GPIOS_GPIOPDEN0_GPIOPDEN_Msk == GPIOS_GPIOPDEN3_GPIOPDEN_Msk);
NPMX_STATIC_ASSERT(GPIOS_GPIOPDEN0_GPIOPDEN_Msk == GPIOS_GPIOPDEN4_GPIOPDEN_Msk);

/* Static assertion for GPIO open drain register masks */
NPMX_STATIC_ASSERT(GPIOS_GPIOOPENDRAIN0_GPIOOPENDRAIN_Msk ==
                   GPIOS_GPIOOPENDRAIN1_GPIOOPENDRAIN_Msk);
NPMX_STATIC_ASSERT(GPIOS_GPIOOPENDRAIN0_GPIOOPENDRAIN_Msk ==
                   GPIOS_GPIOOPENDRAIN2_GPIOOPENDRAIN_Msk);
NPMX_STATIC_ASSERT(GPIOS_GPIOOPENDRAIN0_GPIOOPENDRAIN_Msk ==
                   GPIOS_GPIOOPENDRAIN3_GPIOOPENDRAIN_Msk);
NPMX_STATIC_ASSERT(GPIOS_GPIOOPENDRAIN0_GPIOOPENDRAIN_Msk ==
                   GPIOS_GPIOOPENDRAIN4_GPIOOPENDRAIN_Msk);

/* Static assertion for GPIO debounce register masks */
NPMX_STATIC_ASSERT(GPIOS_GPIODEBOUNCE0_GPIODEBOUNCE_Msk == GPIOS_GPIODEBOUNCE1_GPIODEBOUNCE_Msk);
NPMX_STATIC_ASSERT(GPIOS_GPIODEBOUNCE0_GPIODEBOUNCE_Msk == GPIOS_GPIODEBOUNCE2_GPIODEBOUNCE_Msk);
NPMX_STATIC_ASSERT(GPIOS_GPIODEBOUNCE0_GPIODEBOUNCE_Msk == GPIOS_GPIODEBOUNCE3_GPIODEBOUNCE_Msk);
NPMX_STATIC_ASSERT(GPIOS_GPIODEBOUNCE0_GPIODEBOUNCE_Msk == GPIOS_GPIODEBOUNCE4_GPIODEBOUNCE_Msk);

static const uint16_t m_mode_reg_addr[NPMX_PERIPH_GPIO_COUNT] =
{
    [0] = NPMX_REG_TO_ADDR(NPM_GPIOS->GPIOMODE0),
    [1] = NPMX_REG_TO_ADDR(NPM_GPIOS->GPIOMODE1),
    [2] = NPMX_REG_TO_ADDR(NPM_GPIOS->GPIOMODE2),
    [3] = NPMX_REG_TO_ADDR(NPM_GPIOS->GPIOMODE3),
    [4] = NPMX_REG_TO_ADDR(NPM_GPIOS->GPIOMODE4),
};

static const uint16_t m_drive_reg_addr[NPMX_PERIPH_GPIO_COUNT] =
{
    [0] = NPMX_REG_TO_ADDR(NPM_GPIOS->GPIODRIVE0),
    [1] = NPMX_REG_TO_ADDR(NPM_GPIOS->GPIODRIVE1),
    [2] = NPMX_REG_TO_ADDR(NPM_GPIOS->GPIODRIVE2),
    [3] = NPMX_REG_TO_ADDR(NPM_GPIOS->GPIODRIVE3),
    [4] = NPMX_REG_TO_ADDR(NPM_GPIOS->GPIODRIVE4),
};

static const uint16_t m_pull_up_reg_addr[NPMX_PERIPH_GPIO_COUNT] =
{
    [0] = NPMX_REG_TO_ADDR(NPM_GPIOS->GPIOPUEN0),
    [1] = NPMX_REG_TO_ADDR(NPM_GPIOS->GPIOPUEN1),
    [2] = NPMX_REG_TO_ADDR(NPM_GPIOS->GPIOPUEN2),
    [3] = NPMX_REG_TO_ADDR(NPM_GPIOS->GPIOPUEN3),
    [4] = NPMX_REG_TO_ADDR(NPM_GPIOS->GPIOPUEN4),
};

static const uint16_t m_pull_down_reg_addr[NPMX_PERIPH_GPIO_COUNT] =
{
    [0] = NPMX_REG_TO_ADDR(NPM_GPIOS->GPIOPDEN0),
    [1] = NPMX_REG_TO_ADDR(NPM_GPIOS->GPIOPDEN1),
    [2] = NPMX_REG_TO_ADDR(NPM_GPIOS->GPIOPDEN2),
    [3] = NPMX_REG_TO_ADDR(NPM_GPIOS->GPIOPDEN3),
    [4] = NPMX_REG_TO_ADDR(NPM_GPIOS->GPIOPDEN4),
};

static const uint16_t m_open_drain_reg_addr[NPMX_PERIPH_GPIO_COUNT] =
{
    [0] = NPMX_REG_TO_ADDR(NPM_GPIOS->GPIOOPENDRAIN0),
    [1] = NPMX_REG_TO_ADDR(NPM_GPIOS->GPIOOPENDRAIN1),
    [2] = NPMX_REG_TO_ADDR(NPM_GPIOS->GPIOOPENDRAIN2),
    [3] = NPMX_REG_TO_ADDR(NPM_GPIOS->GPIOOPENDRAIN3),
    [4] = NPMX_REG_TO_ADDR(NPM_GPIOS->GPIOOPENDRAIN4),
};

static const uint16_t m_deb_regreg_addr[NPMX_PERIPH_GPIO_COUNT] =
{
    [0] = NPMX_REG_TO_ADDR(NPM_GPIOS->GPIODEBOUNCE0),
    [1] = NPMX_REG_TO_ADDR(NPM_GPIOS->GPIODEBOUNCE1),
    [2] = NPMX_REG_TO_ADDR(NPM_GPIOS->GPIODEBOUNCE2),
    [3] = NPMX_REG_TO_ADDR(NPM_GPIOS->GPIODEBOUNCE3),
    [4] = NPMX_REG_TO_ADDR(NPM_GPIOS->GPIODEBOUNCE4),
};

static const uint8_t m_gpio_status_pos[NPMX_PERIPH_GPIO_COUNT] =
{
    [0] = GPIOS_GPIOSTATUS_GPIO0STATUS_Pos,
    [1] = GPIOS_GPIOSTATUS_GPIO1STATUS_Pos,
    [2] = GPIOS_GPIOSTATUS_GPIO2STATUS_Pos,
    [3] = GPIOS_GPIOSTATUS_GPIO3STATUS_Pos,
    [4] = GPIOS_GPIOSTATUS_GPIO4STATUS_Pos,
};

static const uint8_t m_gpio_status_msk[NPMX_PERIPH_GPIO_COUNT] =
{
    [0] = GPIOS_GPIOSTATUS_GPIO0STATUS_Msk,
    [1] = GPIOS_GPIOSTATUS_GPIO1STATUS_Msk,
    [2] = GPIOS_GPIOSTATUS_GPIO2STATUS_Msk,
    [3] = GPIOS_GPIOSTATUS_GPIO3STATUS_Msk,
    [4] = GPIOS_GPIOSTATUS_GPIO4STATUS_Msk,
};

/**
 * @brief Function for setting GPIO mode.
 *
 * @param[in] p_instance Pointer to the GPIO instance.
 * @param[in] mode       The mode of GPIO to set.
 *
 * @retval NPMX_SUCCESS  Operation performed successfully.
 * @retval NPMX_ERROR_IO Error using IO bus line.
 */
static npmx_error_t mode_set(npmx_gpio_t const * p_instance, npmx_gpio_mode_t mode)
{
    uint8_t data = ((uint8_t)mode << GPIOS_GPIOMODE0_GPIOMODE_Pos) & GPIOS_GPIOMODE0_GPIOMODE_Msk;

    return npmx_backend_register_write(p_instance->p_backend,
                                       m_mode_reg_addr[p_instance->hw_index],
                                       &data,
                                       1);
}

/**
 * @brief Function for reading GPIO mode.
 *
 * @param[in] p_instance Pointer to the GPIO instance.
 * @param[in] p_mode     Pointer to mode of GPIO.
 *
 * @retval NPMX_SUCCESS  Operation performed successfully.
 * @retval NPMX_ERROR_IO Error using IO bus line.
 */
static npmx_error_t mode_get(npmx_gpio_t const * p_instance, npmx_gpio_mode_t * p_mode)
{
    uint8_t      data;
    npmx_error_t err_code = npmx_backend_register_read(p_instance->p_backend,
                                                       m_mode_reg_addr[p_instance->hw_index],
                                                       &data,
                                                       1);

    if (err_code != NPMX_SUCCESS)
    {
        return err_code;
    }

    *p_mode = (npmx_gpio_mode_t)((data & GPIOS_GPIOMODE0_GPIOMODE_Msk)
                                 >> GPIOS_GPIOMODE0_GPIOMODE_Pos);

    return NPMX_SUCCESS;
}

/**
 * @brief Function for setting GPIO drive current.
 *
 * @param[in] p_instance Pointer to the GPIO instance.
 * @param[in] drive      Drive current of GPIO to set.
 *
 * @retval NPMX_SUCCESS  Operation performed successfully.
 * @retval NPMX_ERROR_IO Error using IO bus line.
 */
static npmx_error_t drive_current_set(npmx_gpio_t const * p_instance, npmx_gpio_drive_t drive)
{
    uint8_t data = ((uint8_t)drive << GPIOS_GPIODRIVE0_GPIODRIVE_Pos) &
                   GPIOS_GPIODRIVE0_GPIODRIVE_Msk;

    return npmx_backend_register_write(p_instance->p_backend,
                                       m_drive_reg_addr[p_instance->hw_index],
                                       &data,
                                       1);
}

/**
 * @brief Function for reading GPIO drive current.
 *
 * @param[in] p_instance Pointer to the GPIO instance.
 * @param[in] p_drive    Pointer to drive current of GPIO.
 *
 * @retval NPMX_SUCCESS  Operation performed successfully.
 * @retval NPMX_ERROR_IO Error using IO bus line.
 */
static npmx_error_t drive_current_get(npmx_gpio_t const * p_instance, npmx_gpio_drive_t * p_drive)
{
    uint8_t      data;
    npmx_error_t err_code = npmx_backend_register_read(p_instance->p_backend,
                                                       m_drive_reg_addr[p_instance->hw_index],
                                                       &data,
                                                       1);

    if (err_code != NPMX_SUCCESS)
    {
        return err_code;
    }

    *p_drive = (npmx_gpio_drive_t)((data & GPIOS_GPIODRIVE0_GPIODRIVE_Msk)
                                   >> GPIOS_GPIODRIVE0_GPIODRIVE_Pos);

    return NPMX_SUCCESS;
}

/**
 * @brief Function for enabling and disabling GPIO pull-up.
 *
 * @param[in] p_instance Pointer to the GPIO instance.
 * @param[in] enable     True to enable, false to disable pull-up.
 *
 * @retval NPMX_SUCCESS  Operation performed successfully.
 * @retval NPMX_ERROR_IO Error using IO bus line.
 */
static npmx_error_t pull_up_enable_set(npmx_gpio_t const * p_instance, bool enable)
{
    uint8_t data = ((enable ? GPIOS_GPIOPUEN0_GPIOPUEN_PULLUP1 : GPIOS_GPIOPUEN0_GPIOPUEN_PULLUP0)
                    << GPIOS_GPIOPUEN0_GPIOPUEN_Pos) & GPIOS_GPIOPUEN0_GPIOPUEN_Msk;

    return npmx_backend_register_write(p_instance->p_backend,
                                       m_pull_up_reg_addr[p_instance->hw_index],
                                       &data,
                                       1);
}

/**
 * @brief Function for reading if GPIO pull-up is enabled.
 *
 * @param[in] p_pm     The pointer to the instance of nPM device.
 * @param[in] gpio     The instance of GPIO driver.
 * @param[in] p_enable The pointer to pull-up enable variable.
 *
 * @retval NPMX_SUCCESS  Operation performed successfully.
 * @retval NPMX_ERROR_IO Error using IO bus line.
 */
static npmx_error_t pull_up_enable_get(npmx_gpio_t const * p_instance, bool * p_enable)
{
    uint8_t      data;
    npmx_error_t err_code = npmx_backend_register_read(p_instance->p_backend,
                                                       m_pull_up_reg_addr[p_instance->hw_index],
                                                       &data,
                                                       1);

    if (err_code != NPMX_SUCCESS)
    {
        return err_code;
    }

    *p_enable = ((data & GPIOS_GPIOPUEN0_GPIOPUEN_Msk) >> GPIOS_GPIOPUEN0_GPIOPUEN_Pos) ==
                GPIOS_GPIOPUEN0_GPIOPUEN_PULLUP1;

    return NPMX_SUCCESS;
}

/**
 * @brief Function for enabling and disabling GPIO pull-down.
 *
 * @param[in] p_instance Pointer to the GPIO instance.
 * @param[in] enable     True to enable, false to disable pull-down.
 *
 * @retval NPMX_SUCCESS  Operation performed successfully.
 * @retval NPMX_ERROR_IO Error using IO bus line.
 */
static npmx_error_t pull_down_enable_set(npmx_gpio_t const * p_instance, bool enable)
{
    uint8_t data = ((enable ? GPIOS_GPIOPDEN0_GPIOPDEN_PULLDOWN1 :
                              GPIOS_GPIOPDEN0_GPIOPDEN_PULLDOWN0)
                    << GPIOS_GPIOPDEN0_GPIOPDEN_Pos) & GPIOS_GPIOPDEN0_GPIOPDEN_Msk;

    return npmx_backend_register_write(p_instance->p_backend,
                                       m_pull_down_reg_addr[p_instance->hw_index],
                                       &data,
                                       1);
}

/**
 * @brief Function for reading if GPIO pull-down is enabled.
 *
 * @param[in] p_instance Pointer to the GPIO instance.
 * @param[in] p_enable   Pointer to pull-down enable variable.
 *
 * @retval NPMX_SUCCESS  Operation performed successfully.
 * @retval NPMX_ERROR_IO Error using IO bus line.
 */
static npmx_error_t pull_down_enable_get(npmx_gpio_t const * p_instance, bool * p_enable)
{
    uint8_t      data;
    npmx_error_t err_code = npmx_backend_register_read(p_instance->p_backend,
                                                       m_pull_down_reg_addr[p_instance->hw_index],
                                                       &data,
                                                       1);

    if (err_code != NPMX_SUCCESS)
    {
        return err_code;
    }

    *p_enable = ((data & GPIOS_GPIOPDEN0_GPIOPDEN_Msk) >> GPIOS_GPIOPDEN0_GPIOPDEN_Pos) ==
                GPIOS_GPIOPDEN0_GPIOPDEN_PULLDOWN1;

    return NPMX_SUCCESS;
}

/**
 * @brief Function for enabling and disabling GPIO pull-down or pull-up.
 *
 * @param[in] p_instance Pointer to the GPIO instance.
 * @param[in] pull       Pull-down, pull-up or no pull.
 *
 * @retval NPMX_SUCCESS             Operation performed successfully.
 * @retval NPMX_ERROR_IO            Error using IO bus line.
 */
static npmx_error_t pull_set(npmx_gpio_t const * p_instance, npmx_gpio_pull_t pull)
{
    npmx_error_t err_code;

    switch (pull)
    {
        case NPMX_GPIO_PULL_DOWN:
            err_code = pull_up_enable_set(p_instance, false);
            if (err_code != NPMX_SUCCESS)
            {
                return err_code;
            }

            return pull_down_enable_set(p_instance, true);
        case NPMX_GPIO_PULL_UP:
            err_code = pull_down_enable_set(p_instance, false);
            if (err_code != NPMX_SUCCESS)
            {
                return err_code;
            }

            return pull_up_enable_set(p_instance, true);
        case NPMX_GPIO_PULL_NONE:
            err_code = pull_down_enable_set(p_instance, false);
            if (err_code != NPMX_SUCCESS)
            {
                return err_code;
            }

            return pull_up_enable_set(p_instance, false);
        default:
            return NPMX_ERROR_INVALID_PARAM;
    }

    return NPMX_SUCCESS;
}

static npmx_error_t pull_get(npmx_gpio_t const * p_instance, npmx_gpio_pull_t * p_pull)
{
    bool pull_up;
    bool pull_down;

    npmx_error_t err_code = pull_down_enable_get(p_instance, &pull_down);

    if (err_code != NPMX_SUCCESS)
    {
        return err_code;
    }

    err_code = pull_up_enable_get(p_instance, &pull_up);

    if (err_code != NPMX_SUCCESS)
    {
        return err_code;
    }

    if (pull_down)
    {
        *p_pull = NPMX_GPIO_PULL_DOWN;
    }
    else if (pull_up)
    {
        *p_pull = NPMX_GPIO_PULL_UP;
    }
    else
    {
        *p_pull = NPMX_GPIO_PULL_NONE;
    }

    return NPMX_SUCCESS;
}

/**
 * @brief Function for enabling and disabling GPIO open drain.
 *
 * @param[in] p_instance Pointer to the GPIO instance.
 * @param[in] enable     True to enable, false to disable open drain.
 *
 * @retval NPMX_SUCCESS  Operation performed successfully.
 * @retval NPMX_ERROR_IO Error using IO bus line.
 */
static npmx_error_t open_drain_set(npmx_gpio_t const * p_instance, bool enable)
{
    uint8_t data = ((enable ? GPIOS_GPIOOPENDRAIN0_GPIOOPENDRAIN_OPENDRAIN1 :
                              GPIOS_GPIOOPENDRAIN0_GPIOOPENDRAIN_OPENDRAIN0)
                    << GPIOS_GPIOOPENDRAIN0_GPIOOPENDRAIN_Pos) &
                   GPIOS_GPIOOPENDRAIN0_GPIOOPENDRAIN_Msk;

    return npmx_backend_register_write(p_instance->p_backend,
                                       m_open_drain_reg_addr[p_instance->hw_index],
                                       &data,
                                       1);
}

/**
 * @brief Function for reading if GPIO open drain is enabled.
 *
 * @param[in] p_instance Pointer to the GPIO instance.
 * @param[in] p_enable   Pointer to open drain enable variable.
 *
 * @retval NPMX_SUCCESS  Operation performed successfully.
 * @retval NPMX_ERROR_IO Error using IO bus line.
 */
static npmx_error_t open_drain_get(npmx_gpio_t const * p_instance, bool * p_enable)
{
    uint8_t      data;
    npmx_error_t err_code = npmx_backend_register_read(p_instance->p_backend,
                                                       m_open_drain_reg_addr[p_instance->hw_index],
                                                       &data,
                                                       1);

    if (err_code != NPMX_SUCCESS)
    {
        return err_code;
    }

    *p_enable = ((data & GPIOS_GPIOOPENDRAIN0_GPIOOPENDRAIN_Msk)
                 >> GPIOS_GPIOOPENDRAIN0_GPIOOPENDRAIN_Pos) ==
                GPIOS_GPIOOPENDRAIN0_GPIOOPENDRAIN_OPENDRAIN1;

    return NPMX_SUCCESS;
}

/**
 * @brief Function for enabling and disabling GPIO debounce.
 *
 * @param[in] p_instance Pointer to the GPIO instance.
 * @param[in] enable     True to enable, false to disable debounce.
 *
 * @retval NPMX_SUCCESS  Operation performed successfully.
 * @retval NPMX_ERROR_IO Error using IO bus line.
 */
static npmx_error_t debounce_set(npmx_gpio_t const * p_instance, bool enable)
{
    uint8_t data = ((enable ? GPIOS_GPIODEBOUNCE0_GPIODEBOUNCE_DEBOUNCE1 :
                              GPIOS_GPIODEBOUNCE0_GPIODEBOUNCE_DEBOUNCE0)
                    << GPIOS_GPIODEBOUNCE0_GPIODEBOUNCE_Pos) & GPIOS_GPIODEBOUNCE0_GPIODEBOUNCE_Msk;

    return npmx_backend_register_write(p_instance->p_backend,
                                       m_deb_regreg_addr[p_instance->hw_index],
                                       &data,
                                       1);
}

/**
 * @brief Function for reading if GPIO debounce is enabled.
 *
 * @param[in] p_instance Pointer to the GPIO instance.
 * @param[in] p_enable   Pointer to open drain enable variable.
 *
 * @retval NPMX_SUCCESS  Operation performed successfully.
 * @retval NPMX_ERROR_IO Error using IO bus line.
 */
static npmx_error_t debounce_get(npmx_gpio_t const * p_instance, bool * p_enable)
{
    uint8_t      data;
    npmx_error_t err_code = npmx_backend_register_read(p_instance->p_backend,
                                                       m_deb_regreg_addr[p_instance->hw_index],
                                                       &data,
                                                       1);

    if (err_code != NPMX_SUCCESS)
    {
        return err_code;
    }

    *p_enable = ((data & GPIOS_GPIODEBOUNCE0_GPIODEBOUNCE_Msk)
                 >> GPIOS_GPIODEBOUNCE0_GPIODEBOUNCE_Pos) ==
                GPIOS_GPIODEBOUNCE0_GPIODEBOUNCE_DEBOUNCE1;

    return NPMX_SUCCESS;
}

npmx_gpio_t * npmx_gpio_get(npmx_instance_t * p_pmic, uint8_t idx)
{
    NPMX_ASSERT(p_pmic);
    NPMX_ASSERT(idx < NPMX_PERIPH_GPIO_COUNT);

    return &p_pmic->gpio[idx];
}

npmx_gpio_drive_t npmx_gpio_drive_convert(uint32_t milliamperes)
{
    switch (milliamperes)
    {
        case 1:
            return NPMX_GPIO_DRIVE_1_MA;
        case 6:
            return NPMX_GPIO_DRIVE_6_MA;
        default:
            return NPMX_GPIO_DRIVE_INVALID;
    }
}

bool npmx_gpio_drive_convert_to_ma(npmx_gpio_drive_t enum_value, uint32_t * p_val)
{
    switch (enum_value)
    {
        case NPMX_GPIO_DRIVE_1_MA:
            *p_val = 1;
            break;
        case NPMX_GPIO_DRIVE_6_MA:
            *p_val = 6;
            break;
        default:
            return false;
    }
    return true;
}

npmx_error_t npmx_gpio_config_set(npmx_gpio_t const *        p_instance,
                                  npmx_gpio_config_t const * p_config)
{
    NPMX_ASSERT(p_instance);
    NPMX_ASSERT(p_config);
    NPMX_ASSERT(p_config->drive < NPMX_GPIO_DRIVE_COUNT);
    NPMX_ASSERT(p_config->pull < NPMX_GPIO_PULL_COUNT);
    NPMX_ASSERT(p_config->mode < NPMX_GPIO_MODE_COUNT);

    npmx_error_t err_code;

    err_code = drive_current_set(p_instance, p_config->drive);
    if (err_code != NPMX_SUCCESS)
    {
        return err_code;
    }

    err_code = pull_set(p_instance, p_config->pull);
    if (err_code != NPMX_SUCCESS)
    {
        return err_code;
    }

    err_code = open_drain_set(p_instance, p_config->open_drain);
    if (err_code != NPMX_SUCCESS)
    {
        return err_code;
    }

    err_code = debounce_set(p_instance, p_config->debounce);
    if (err_code != NPMX_SUCCESS)
    {
        return err_code;
    }

    err_code = mode_set(p_instance, p_config->mode);
    if (err_code != NPMX_SUCCESS)
    {
        return err_code;
    }

    return NPMX_SUCCESS;
}

npmx_error_t npmx_gpio_config_get(npmx_gpio_t const * p_instance, npmx_gpio_config_t * p_config)
{
    NPMX_ASSERT(p_instance);
    NPMX_ASSERT(p_config);

    npmx_error_t err_code = drive_current_get(p_instance, &p_config->drive);
    if (err_code != NPMX_SUCCESS)
    {
        return err_code;
    }

    err_code = pull_get(p_instance, &p_config->pull);
    if (err_code != NPMX_SUCCESS)
    {
        return err_code;
    }

    err_code = open_drain_get(p_instance, &p_config->open_drain);
    if (err_code != NPMX_SUCCESS)
    {
        return err_code;
    }

    err_code = debounce_get(p_instance, &p_config->debounce);
    if (err_code != NPMX_SUCCESS)
    {
        return err_code;
    }

    err_code = mode_get(p_instance, &p_config->mode);
    if (err_code != NPMX_SUCCESS)
    {
        return err_code;
    }

    return NPMX_SUCCESS;
}

npmx_error_t npmx_gpio_mode_set(npmx_gpio_t const * p_instance, npmx_gpio_mode_t mode)
{
    NPMX_ASSERT(p_instance);
    NPMX_ASSERT(mode < NPMX_GPIO_MODE_COUNT);

    return mode_set(p_instance, mode);
}

npmx_error_t npmx_gpio_mode_get(npmx_gpio_t const * p_instance, npmx_gpio_mode_t * p_mode)
{
    NPMX_ASSERT(p_instance);
    NPMX_ASSERT(p_mode);

    return mode_get(p_instance, p_mode);
}

npmx_error_t npmx_gpio_status_check(npmx_gpio_t const * p_instance, bool * p_status)
{
    NPMX_ASSERT(p_instance);
    NPMX_ASSERT(p_status);

    uint8_t      data;
    npmx_error_t err_code = npmx_backend_register_read(p_instance->p_backend,
                                                       NPMX_REG_TO_ADDR(NPM_GPIOS->GPIOSTATUS),
                                                       &data,
                                                       1);
    if (err_code != NPMX_SUCCESS)
    {
        return err_code;
    }

    *p_status = ((data & m_gpio_status_msk[p_instance->hw_index])
                 >> m_gpio_status_pos[p_instance->hw_index]) == GPIOS_GPIOSTATUS_GPIO0STATUS_HIGH;

    return NPMX_SUCCESS;
}
