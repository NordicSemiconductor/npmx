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

#ifndef NPMX_ERROR_H__
#define NPMX_ERROR_H__

/**
 * @defgroup npmx_error_codes Global Error Codes
 * @{
 * @ingroup npmx
 *
 * @brief Global error code definitions.
 */

/** @brief Base number of error codes. */
#define NPMX_ERROR_BASE_NUM 0x2BAD0000

/** @brief Enumerated type for error codes. */
typedef enum
{
    NPMX_SUCCESS             = (NPMX_ERROR_BASE_NUM + 0), ///< Operation performed successfully.
    NPMX_ERROR_INVALID_PARAM = (NPMX_ERROR_BASE_NUM + 1), ///< Invalid parameter.
    NPMX_ERROR_IO            = (NPMX_ERROR_BASE_NUM + 2), ///< Error using IO bus line.
    NPMX_ERROR_INVALID_MEAS  = (NPMX_ERROR_BASE_NUM + 3), ///< Invalid measurement.
    NPMX_ERROR_NOT_SUPPORTED = (NPMX_ERROR_BASE_NUM + 4), ///< Not supported for given PMIC.
} npmx_error_t;

/** @} */

#endif // NPMX_ERROR_H__
