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

#ifndef NPMX_ERRLOG_H__
#define NPMX_ERRLOG_H__

#include <npmx.h>

#ifdef __cplusplus
extern "C" {
#endif

/**
 * @defgroup npmx_errlog ERRLOG
 * @{
 * @ingroup npmx_drivers
 * @brief   Error Log (ERRLOG) peripheral driver.
 */

/** @brief Available scratch registers. */
typedef enum
{
    NPMX_ERRLOG_SCRATCH0,      ///< Scratch 0 register.
    NPMX_ERRLOG_SCRATCH1,      ///< Scratch 1 register.
    NPMX_ERRLOG_SCRATCH_COUNT, ///< Scratch registers count.
} npmx_errlog_scratch_t;

/** @brief Data structure of the error log driver instance. */
typedef struct
{
    npmx_instance_t * p_pmic; ///< Pointer to the PMIC instance.
} npmx_errlog_t;

/** @brief Error log tasks. */
typedef enum
{
    NPMX_ERRLOG_TASK_CLEAR, ///< Clear all error log registers.
} npmx_errlog_task_t;

/**
 * @brief Function for returning error log instance based on index.
 *
 * @param[in] p_pmic Pointer to the PMIC instance.
 * @param[in] idx    Index of the error log instance.
 *
 * @return Pointer to the error log instance.
 */
npmx_errlog_t * npmx_errlog_get(npmx_instance_t * p_pmic, uint8_t idx);

/**
 * @brief Function for activating the specified error log task.
 *
 * @param[in] p_instance Pointer to the instance of error log.
 * @param[in] task       Task to be activated.
 *
 * @retval NPMX_SUCCESS  Operation performed successfully.
 * @retval NPMX_ERROR_IO Error using IO bus line.
 */
npmx_error_t npmx_errlog_task_trigger(npmx_errlog_t const * p_instance, npmx_errlog_task_t task);

/**
 * @brief Function for checking reset errors and running registered callbacks.
 *
 * @param[in] p_instance Pointer to the instance of error log.
 *
 * @retval NPMX_SUCCESS  Operation performed successfully.
 * @retval NPMX_ERROR_IO Error using IO bus line.
 */
npmx_error_t npmx_errlog_reset_errors_check(npmx_errlog_t const * p_instance);

/**
 * @brief Function for setting scratch value for specified scratch register.
 *
 * @param[in] p_instance Pointer to the instance of error log.
 * @param[in] scratch    Selected scratch register.
 * @param[in] value      Scratch register value to be saved.
 *
 * @retval NPMX_SUCCESS  Operation performed successfully.
 * @retval NPMX_ERROR_IO Error using IO bus line.
 */
npmx_error_t npmx_errlog_scratch_set(npmx_errlog_t const * p_instance,
                                     npmx_errlog_scratch_t scratch,
                                     uint8_t               value);

/**
 * @brief Function for reading scratch value for specified scratch register.
 *
 * @param[in]  p_instance Pointer to the instance of error log.
 * @param[in]  scratch    Selected scratch register.
 * @param[out] p_value    Pointer to value OF variable.
 *
 * @retval NPMX_SUCCESS  Operation performed successfully.
 * @retval NPMX_ERROR_IO Error using IO bus line.
 */
npmx_error_t npmx_errlog_scratch_get(npmx_errlog_t const * p_instance,
                                     npmx_errlog_scratch_t scratch,
                                     uint8_t *             p_value);

#if defined(ERRLOG_SCRATCH0_BOOTTIMEREN_Msk) || defined(__NPMX_DOXYGEN__)
/**
 * @brief Function for enabling or disabling boot monitor timer.
 *
 * @param[in] p_instance Pointer to the instance of error log.
 * @param[in] enable     True if boot monitor is to be enabled, false otherwise.
 *
 * @retval NPMX_SUCCESS  Operation performed successfully.
 * @retval NPMX_ERROR_IO Error using IO bus line.
 */
npmx_error_t npmx_errlog_boot_timer_enable_set(npmx_errlog_t const * p_instance, bool enable);

/**
 * @brief Function checking whether boot monitor timer is enabled.
 *
 * @param[in]  p_instance Pointer to the instance of error log.
 * @param[out] p_enable   Pointer to the boot monitor timer variable. True if timer is enabled, false otherwise.
 *
 * @retval NPMX_SUCCESS  Operation performed successfully.
 * @retval NPMX_ERROR_IO Error using IO bus line.
 */
npmx_error_t npmx_errlog_boot_timer_enable_get(npmx_errlog_t const * p_instance, bool * p_enable);

#endif

/** @} */

#ifdef __cplusplus
}
#endif

#endif /* NPMX_ERRLOG_H__ */
