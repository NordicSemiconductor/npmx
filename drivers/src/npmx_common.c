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

#include <npmx_common.h>

#ifdef NPMX_DEBUG

#define NPMX_COMMON_BITS_COUNT 8U ///< Bits count in event registers.

/** @brief All possible callback names. */
static const char * callbacks_register_name[NPMX_CALLBACK_TYPE_COUNT] =
{
    [NPMX_CALLBACK_TYPE_EVENT_ADC]                = "ADC",
    [NPMX_CALLBACK_TYPE_EVENT_BAT_CHAR_TEMP]      = "BAT_CHAR_TEMP",
    [NPMX_CALLBACK_TYPE_EVENT_BAT_CHAR_STATUS]    = "BAT_CHAR_STATUS",
    [NPMX_CALLBACK_TYPE_EVENT_BAT_CHAR_BAT]       = "BAT_CHAR_BAT",
    [NPMX_CALLBACK_TYPE_EVENT_SHIPHOLD]           = "SHIPHOLD",
    [NPMX_CALLBACK_TYPE_EVENT_VBUSIN_VOLTAGE]     = "VBUSIN_VOLTAGE",
    [NPMX_CALLBACK_TYPE_EVENT_VBUSIN_THERMAL_USB] = "VBUSIN_THERMAL_USB",
#if defined(MAIN_EVENTSUSBBSET_EVENTUSBBDETECT_Msk)
    [NPMX_CALLBACK_TYPE_EVENT_USB_B]              = "USB_B",
#endif
#if defined(MAIN_EVENTSGPIOSET_EVENTGPIOEDGEDETECT0_Msk)
    [NPMX_CALLBACK_TYPE_EVENT_EVENTSGPIOSET]      = "GPIO",
#endif
    [NPMX_CALLBACK_TYPE_RSTCAUSE]                 = "RSTCAUSE",
    [NPMX_CALLBACK_TYPE_CHARGER_ERROR]            = "CHARGER_ERROR",
    [NPMX_CALLBACK_TYPE_SENSOR_ERROR]             = "SENSOR_ERROR",
};

/** @brief All possible callback bit names. */
static const char * callbacks_bits_names[NPMX_CALLBACK_TYPE_COUNT][NPMX_COMMON_BITS_COUNT] =
{
    [NPMX_CALLBACK_TYPE_EVENT_ADC] =
    {
        [0] = "VBAT",              [1] = "Battery NTC",
        [2] = "Internal Die Temp", [3] = "VSYS Voltage",
        [4] = "BUCK VSET1 pin",    [5] = "BUCK VSET2 pin",
        [6] = "IBAT",              [7] = "VBUS"
    },
    [NPMX_CALLBACK_TYPE_EVENT_BAT_CHAR_TEMP] =
    {
        [0] = "Cold Battery",  [1] = "Cool Battery",
        [2] = "Warm Battery",  [3] = "Hot Battery",
        [4] = "Die high temp", [5] = "Die resume temp"
    },
    [NPMX_CALLBACK_TYPE_EVENT_BAT_CHAR_STATUS] =
    {
        [0] = "Supplement mode activated", [1] = "Trickle Charge started",
        [2] = "Constant Current started",  [3] = "Constant Voltage started",
        [4] = "Charging completed",        [5] = "Charging error"
    },
    [NPMX_CALLBACK_TYPE_EVENT_BAT_CHAR_BAT] =
    {
        [0] = "Battery Detected",
        [1] = "Battery Lost",
        [2] = "Battery re-charge needed"
    },
    [NPMX_CALLBACK_TYPE_EVENT_SHIPHOLD] =
    {
        [0] = "Pressed",      [1] = "Released",
        [2] = "Held to Exit",
#if defined(SHPHLD_LPRESETCONFIG_LONGTIMRESETENA_Msk)
        [3] = "Held for 10 s",
#endif
        "Watchdog Timeout Warn"
    },
    [NPMX_CALLBACK_TYPE_EVENT_VBUSIN_VOLTAGE] =
    {
        [0] = "VBUS input detected",    [1] = "VBUS input removed",
        [2] = "Over Voltage Detected",  [3] = "Over Voltage Removed",
        [4] = "Under Voltage Detected", [5] = "Under Voltage Removed"
    },
    [NPMX_CALLBACK_TYPE_EVENT_VBUSIN_THERMAL_USB] =
    {
        [0] = "Warning detected",       [1] = "Warning removed",
        [2] = "Shutdown detected",      [3] = "Shutdown removed",
        [4] = "Voltage on CC1 changes", [5] = "Voltage on CC2 changes"
    },
#if defined(MAIN_EVENTSUSBBSET_EVENTUSBBDETECT_Msk)
    [NPMX_CALLBACK_TYPE_EVENT_USB_B] =
    {
        [0] = "USB-B DP/DN detection"
    },
#endif
#if defined(MAIN_EVENTSGPIOSET_EVENTGPIOEDGEDETECT0_Msk)
    [NPMX_CALLBACK_TYPE_EVENT_EVENTSGPIOSET] =
    {
        [0] = "GPIO0 input", [1] = "GPIO 1 input",
        [2] = "GPIO2 input", [3] = "GPIO 3 input",
        [4] = "GPIO4 input"
    },
#endif
    [NPMX_CALLBACK_TYPE_RSTCAUSE] =
    {
        [0] = "Shipmode exit",    [1] = "Boot monitor timeout",
        [2] = "Watchdog timeout", [3] = "Shphld long press",
        [4] = "TSD",              [5] = "VSYS low",
        [6] = "Soft reset"
    },
    [NPMX_CALLBACK_TYPE_CHARGER_ERROR] =
    {
        [0] = "NTC sensor error",     [1] = "VBAT Sensor Error",
        [2] = "VBAT Low Error",       [3] = "Measurement Timeout Error",
        [4] = "Charge Timeout Error", [5] = "Trickle Timeout Error"
    },
    [NPMX_CALLBACK_TYPE_SENSOR_ERROR] =
    {
        [0] = "Ntc Cold sensor", [1] = "Ntc Cool sensor",
        [2] = "Ntc Warm sensor", [3] = "Ntc Hot sensor",
        [4] = "Vterm sensor",    [5] = "Recharge sensor",
        [6] = "Vtrickle sensor", [7] = "VbatLow sensor"
    },
};

#endif /* NPMX_DEBUG */

const char * npmx_callback_to_str(npmx_callback_type_t type)
{
#ifdef NPMX_DEBUG
    NPMX_ASSERT(type < NPMX_CALLBACK_TYPE_COUNT);
    return callbacks_register_name[type];
#else
    return NULL;
#endif /* NPMX_DEBUG */
}

const char * npmx_callback_bit_to_str(npmx_callback_type_t type, uint8_t bit)
{
#ifdef NPMX_DEBUG
    NPMX_ASSERT(type < NPMX_CALLBACK_TYPE_COUNT);
    NPMX_ASSERT(bit < 8);
    return callbacks_bits_names[type][bit];
#else
    return NULL;
#endif /* NPMX_DEBUG */
}
