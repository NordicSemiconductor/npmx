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

#ifndef NPMX_BACKEND_H__
#define NPMX_BACKEND_H__

#include <stdint.h>
#include <npmx_error.h>

#ifdef __cplusplus
extern "C" {
#endif

/** @brief Struct for backend handler and device address. */
typedef struct
{
    uint16_t address;    ///< nPM device address (for example, I2C address).
    void *   p_backend;  ///< Pointer to nPM backend handler.
} npmx_backend_instance_t;

/**
 * @brief Init function for the chosen transport backend.
 *
 * @param[in] p_inst      Pointer to backend instance.
 * @param[in] p_backend   Pointer to backend.
 * @param[in] dev_address Device address.
 */
void npmx_backend_init(npmx_backend_instance_t * const p_inst,
                       void *                          p_backend,
                       uint16_t                        dev_address);

/**
 * @brief Function for sending a message over the chosen transport backend.
 *
 * This function is used by services to write to npmx registers.
 *
 * @param[in] p_inst           Pointer to the backend instance.
 * @param[in] register_address Register address in npmx device to be modified.
 * @param[in] p_data           Pointer to data to write.
 * @param[in] num_of_bytes     Number of bytes of data to write.
 *
 * @return NPMX_SUCCESS  All data written successfully.
 * @return NPMX_ERROR_IO Backend returned IO error during data writing.
 */
npmx_error_t npmx_backend_register_write(npmx_backend_instance_t const * p_inst,
                                         uint16_t                        register_address,
                                         uint8_t *                       p_data,
                                         size_t                          num_of_bytes);

/**
 * @brief Function for reading a message over the chosen transport backend.
 *
 * This function is used by services to read npmx registers.
 *
 * @param[in] p_inst           Pointer to the backend instance.
 * @param[in] register_address Register address in npmx device to be read.
 * @param[in] p_data           Pointer to buffer for read data.
 * @param[in] num_of_bytes     Number of bytes to read.
 *
 * @return NPMX_SUCCESS  All data read successfully.
 * @return NPMX_ERROR_IO Backend returned IO error during data reading.
 */
npmx_error_t npmx_backend_register_read(npmx_backend_instance_t const * p_inst,
                                        uint16_t                        register_address,
                                        uint8_t *                       p_data,
                                        size_t                          num_of_bytes);

#ifdef __cplusplus
}
#endif

#endif // NPMX_BACKEND_H__
