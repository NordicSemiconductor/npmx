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

#ifndef NPMX_GLUE_H__
#define NPMX_GLUE_H__

// THIS IS A TEMPLATE FILE.
// It should be copied to a suitable location within the host environment into
// which npmx is integrated, and the following macros should be provided with
// appropriate implementations.
// And this comment should be removed from the customized file.

#include <npmx.h>

#ifdef __cplusplus
extern "C" {
#endif

/**
 * @defgroup npmx_glue Glue template
 * @{
 * @ingroup npmx
 *
 * @brief This file contains functions declarations and macros that should be
 * implemented according to the needs of the host environment into which @em
 * npmx is integrated.
 */

//------------------------------------------------------------------------------

/**
 * @brief Macro for placing a runtime assertion.
 *
 * @param expression Expression to be evaluated.
 */
#define NPMX_ASSERT(expression)

/**
 * @brief Macro for placing a compile time assertion.
 *
 * @param expression Expression to be evaluated.
 */
#define NPMX_STATIC_ASSERT(expression)

/**
 * @brief Function for I2C write.
 *
 * @param[in] p_inst           The pointer to the backend instance.
 * @param[in] register_address The register address in npmx device to be modified.
 * @param[in] p_data           The pointer to data to write.
 * @param[in] num_of_bytes     The number of bytes of data to write.
 *
 * @return NPMX_SUCCESS  All data written successfully.
 * @return NPMX_ERROR_IO Backend returned IO error during data writing.
 */
npmx_error_t npmx_backend_i2c_write(npmx_backend_instance_t const * p_inst,
                                    uint16_t                        register_address,
                                    uint8_t *                       p_data,
                                    uint32_t                        num_of_bytes);
/**
 * @brief Function for I2C read.
 *
 * @param[in] p_inst           The pointer to the backend instance.
 * @param[in] register_address The register address in npmx device to be read.
 * @param[in] p_data           The pointer to buffer for read data.
 * @param[in] num_of_bytes     The number of bytes to read.
 *
 * @return NPMX_SUCCESS  All data read successfully.
 * @return NPMX_ERROR_IO Backend returned IO error during data reading.
 */
npmx_error_t npmx_backend_i2c_read(npmx_backend_instance_t const * p_inst,
                                   uint16_t                        register_address,
                                   uint8_t *                       p_data,
                                   uint32_t                        num_of_bytes);

/** @} */

#ifdef __cplusplus
}
#endif

#endif // NPMX_GLUE_H__
