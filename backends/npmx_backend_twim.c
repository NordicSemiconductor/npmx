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

#include <npmx.h>

void npmx_backend_init(npmx_backend_instance_t * const p_inst,
                       void *                          p_backend,
                       uint16_t                        dev_address)
{
    NPMX_ASSERT(p_inst);
    NPMX_ASSERT(p_backend);

    p_inst->p_backend = p_backend;
    p_inst->address   = dev_address;
}

npmx_error_t npmx_backend_register_write(npmx_backend_instance_t const * p_inst,
                                         uint16_t                        register_address,
                                         uint8_t *                       p_data,
                                         size_t                          num_of_bytes)
{
    return npmx_backend_i2c_write(p_inst, register_address, p_data, num_of_bytes);
}

npmx_error_t npmx_backend_register_read(npmx_backend_instance_t const * p_inst,
                                        uint16_t                        register_address,
                                        uint8_t *                       p_data,
                                        size_t                          num_of_bytes)
{
    return npmx_backend_i2c_read(p_inst, register_address, p_data, num_of_bytes);
}
