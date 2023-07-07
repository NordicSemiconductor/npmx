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

/** @} */

#ifdef __cplusplus
}
#endif

#endif // NPMX_GLUE_H__
