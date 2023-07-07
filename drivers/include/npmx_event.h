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

#ifndef NPMX_EVENT_H__
#define NPMX_EVENT_H__

#include <npmx.h>

#ifdef __cplusplus
extern "C" {
#endif

/**
 * @defgroup npmx_event EVENT
 * @{
 * @ingroup npmx_drivers
 * @brief   All possible events to be registered.
 */

/** @brief Macro to define all possible bits in event group. */
#define NPMX_EVENT_GROUP_ALL_EVENTS_MASK 0xFF

/** @brief Possible events groups. */
typedef enum
{
    NPMX_EVENT_GROUP_ADC,                               ///< ADC events.
    NPMX_EVENT_GROUP_BAT_CHAR_TEMP,                     ///< Battery Charger temperature events.
    NPMX_EVENT_GROUP_BAT_CHAR_STATUS,                   ///< Battery Charger status events.
    NPMX_EVENT_GROUP_BAT_CHAR_BAT,                      ///< Battery Charger battery events.
    NPMX_EVENT_GROUP_SHIPHOLD,                          ///< ShipHold pin events.
    NPMX_EVENT_GROUP_VBUSIN_VOLTAGE,                    ///< VBUSIN voltage detection events.
    NPMX_EVENT_GROUP_VBUSIN_THERMAL,                    ///< VBUSIN Thermal and USB C events.
    NPMX_EVENT_GROUP_GPIO,                              ///< GPIO events.
    NPMX_EVENT_GROUP_COUNT,                             ///< Events groups count.
    NPMX_EVENT_GROUP_INVALID = NPMX_INVALID_ENUM_VALUE, ///< Invalid events group.
} npmx_event_group_t;

/** @brief ADC Events fields. */
typedef enum
{
    NPMX_EVENT_GROUP_ADC_BAT_READY_MASK      = MAIN_EVENTSADCSET_EVENTADCVBATRDY_Msk,    ///< VBAT measurement finished.
    NPMX_EVENT_GROUP_ADC_NTC_READY_MASK      = MAIN_EVENTSADCSET_EVENTADCNTCRDY_Msk,     ///< Battery NTC measurement finished.
    NPMX_EVENT_GROUP_ADC_DIE_TEMP_READY_MASK = MAIN_EVENTSADCSET_EVENTADCTEMPRDY_Msk,    ///< Internal die temperature measurement finished.
    NPMX_EVENT_GROUP_ADC_VSYS_READY_MASK     = MAIN_EVENTSADCSET_EVENTADCVSYSRDY_Msk,    ///< VSYS voltage measurement measurement finished.
    NPMX_EVENT_GROUP_ADC_VSET1_READY_MASK    = MAIN_EVENTSADCSET_EVENTADCVSET1RDY_Msk,   ///< BUCK VSET1 pin measurement finished.
    NPMX_EVENT_GROUP_ADC_VSET2_READY_MASK    = MAIN_EVENTSADCSET_EVENTADCVSET2RDY_Msk,   ///< BUCK VSET2 pin measurement finished.
    NPMX_EVENT_GROUP_ADC_IBAT_READY_MASK     = MAIN_EVENTSADCSET_EVENTADCIBATRDY_Msk,    ///< IBAT measurement finished.
    NPMX_EVENT_GROUP_ADC_VBUS_READY_MASK     = MAIN_EVENTSADCSET_EVENTADCVBUS7V0RDY_Msk, ///< VBUS (7 Volt range) measurement finished.
} npmx_event_group_adc_mask_t;

/** @brief Battery Charger Temperature events fields. */
typedef enum
{
    NPMX_EVENT_GROUP_TEMP_COLD_MASK       = MAIN_EVENTSBCHARGER0SET_EVENTNTCCOLD_Msk,       ///< Event when Cold Battery detected from NTC measurement.
    NPMX_EVENT_GROUP_TEMP_COOL_MASK       = MAIN_EVENTSBCHARGER0SET_EVENTNTCCOOL_Msk,       ///< Event when Cool Battery detected from NTC measurement.
    NPMX_EVENT_GROUP_TEMP_WARM_MASK       = MAIN_EVENTSBCHARGER0SET_EVENTNTCWARM_Msk,       ///< Event when Warm Battery detected from NTC measurement.
    NPMX_EVENT_GROUP_TEMP_HOT_MASK        = MAIN_EVENTSBCHARGER0SET_EVENTNTCHOT_Msk,        ///< Event when Hot Battery detected from NTC measurement.
    NPMX_EVENT_GROUP_TEMP_DIE_HIGH_MASK   = MAIN_EVENTSBCHARGER0SET_EVENTDIETEMPHIGH_Msk,   ///< Event when die high temperature detected from die temperature measurement.
    NPMX_EVENT_GROUP_TEMP_DIE_RESUME_MASK = MAIN_EVENTSBCHARGER0SET_EVENTDIETEMPRESUME_Msk, ///< Event when die resume temperature detected from die temperature measurement.
} npmx_event_group_temp_mask_t;

/** @brief Battery Charger Status events fields. */
typedef enum
{
    NPMX_EVENT_GROUP_CHARGER_SUPPLEMENT_MASK = MAIN_EVENTSBCHARGER1SET_EVENTSUPPLEMENT_Msk,   ///< Event Supplement Mode activated.
    NPMX_EVENT_GROUP_CHARGER_TRICKLE_MASK    = MAIN_EVENTSBCHARGER1SET_EVENTCHGTRICKLE_Msk,   ///< Event Trickle Charge started.
    NPMX_EVENT_GROUP_CHARGER_CC_MASK         = MAIN_EVENTSBCHARGER1SET_EVENTCHGCC_Msk,        ///< Event Constant Current charging started.
    NPMX_EVENT_GROUP_CHARGER_CV_MASK         = MAIN_EVENTSBCHARGER1SET_EVENTCHGCV_Msk,        ///< Event Constant Voltage charging started.
    NPMX_EVENT_GROUP_CHARGER_COMPLETED_MASK  = MAIN_EVENTSBCHARGER1SET_EVENTCHGCOMPLETED_Msk, ///< Event Charging completed (Battery Full).
    NPMX_EVENT_GROUP_CHARGER_ERROR_MASK      = MAIN_EVENTSBCHARGER1SET_EVENTCHGERROR_Msk,     ///< Event Charging error.
} npmx_event_group_charger_mask_t;

/** @brief Battery Charger Battery events fields. */
typedef enum
{
    NPMX_EVENT_GROUP_BATTERY_DETECTED_MASK = MAIN_EVENTSBCHARGER2SET_EVENTBATDETECTED_Msk, ///< Event Battery Detected.
    NPMX_EVENT_GROUP_BATTERY_REMOVED_MASK  = MAIN_EVENTSBCHARGER2SET_EVENTBATLOST_Msk,     ///< Event Battery Lost.
    NPMX_EVENT_GROUP_BATTERY_RECHARGE_MASK = MAIN_EVENTSBCHARGER2SET_EVENTBATRECHARGE_Msk, ///< Event Battery re-charge needed.
} npmx_event_group_battery_mask_t;

/** @brief ShipHold pin events fields. */
typedef enum
{
    NPMX_EVENT_GROUP_SHIPHOLD_PRESSED_MASK   = MAIN_EVENTSSHPHLDSET_EVENTSHPHLDBTNPRESS_Msk,   ///< Event when Ship-Hold button is pressed.
    NPMX_EVENT_GROUP_SHIPHOLD_RELEASED_MASK  = MAIN_EVENTSSHPHLDSET_EVENTSHPHLDBTNRELEASE_Msk, ///< Event when Ship-Hold button is released.
    NPMX_EVENT_GROUP_SHIPHOLD_HELD_EXIT_MASK = MAIN_EVENTSSHPHLDSET_EVENTSHPHLDEXIT_Msk,       ///< Event when Ship-Hold button held to exit.
    NPMX_EVENT_GROUP_SHIPHOLD_WATCHDOG_MASK  = MAIN_EVENTSSHPHLDSET_EVENTWATCHDOGWARN_Msk,     ///< Event when Watchdog Timeout warning detected.
} npmx_event_group_shiphold_mask_t;

/** @brief VBUSIN Voltage Detection events fields. */
typedef enum
{
    NPMX_EVENT_GROUP_VBUSIN_DETECTED_MASK           = MAIN_EVENTSVBUSIN0CLR_EVENTVBUSDETECTED_Msk, ///< Event VBUS input detected.
    NPMX_EVENT_GROUP_VBUSIN_REMOVED_MASK            = MAIN_EVENTSVBUSIN0CLR_EVENTVBUSREMOVED_Msk,  ///< Event VBUS input removed.

    NPMX_EVENT_GROUP_VBUSIN_OVERVOLT_DETECTED_MASK  =
        MAIN_EVENTSVBUSIN0CLR_EVENTVBUSOVRVOLTDETECTED_Msk,                                        ///< Event VBUS Over Voltage detected.

    NPMX_EVENT_GROUP_VBUSIN_OVRVOLT_REMOVED_MASK    =
        MAIN_EVENTSVBUSIN0CLR_EVENTVBUSOVRVOLTREMOVED_Msk,                                         ///< Event VBUS Over Voltage removed.
    NPMX_EVENT_GROUP_VBUSIN_UNDERVOLT_DETECTED_MASK =
        MAIN_EVENTSVBUSIN0CLR_EVENTVBUSUNDVOLTDETECTED_Msk,                                        ///< Event VBUS Under Voltage detected.
    NPMX_EVENT_GROUP_VBUSIN_UNDERVOLT_REMOVED_MASK  =
        MAIN_EVENTSVBUSIN0CLR_EVENTVBUSUNDVOLTREMOVED_Msk,                                         ///< Event VBUS Under Voltage removed.
} npmx_event_group_vbusin_mask_t;

/** @brief VBUSIN Thermal and USB events fields. */
typedef enum
{
    NPMX_EVENT_GROUP_THERMAL_WARN_DETECTED_MASK     =
        MAIN_EVENTSVBUSIN1SET_EVENTTHERMALWARNDETECTED_Msk,     ///< Event Thermal Warning detected.
    NPMX_EVENT_GROUP_THERMAL_WARN_REMOVED_MASK      =
        MAIN_EVENTSVBUSIN1SET_EVENTTHERMALWARNREMOVED_Msk,      ///< Event Thermal Warning removed.
    NPMX_EVENT_GROUP_THERMAL_SHUTDOWN_DETECTED_MASK =
        MAIN_EVENTSVBUSIN1SET_EVENTTHERMALSHUTDOWNDETECTED_Msk, ///< Event Thermal Shutdown detected.
    NPMX_EVENT_GROUP_THERMAL_SHUTDOWN_REMOVED_MASK  =
        MAIN_EVENTSVBUSIN1SET_EVENTTHERMALSHUTDOWNREMOVED_Msk,  ///< Event Thermal Shutdown removed.
    NPMX_EVENT_GROUP_USB_CC1_MASK                   =
        MAIN_EVENTSVBUSIN1SET_EVENTCC1STATECHANGE_Msk,          ///< Event when Voltage on CC1 changes.
    NPMX_EVENT_GROUP_USB_CC2_MASK                   =
        MAIN_EVENTSVBUSIN1SET_EVENTCC2STATECHANGE_Msk,          ///< Event when Voltage on CC2 changes.
} npmx_event_group_thermal_usb_mask_t;

/** @brief GPIO events fields. */
typedef enum
{
    NPMX_EVENT_GROUP_GPIO0_DETECTED_MASK = MAIN_EVENTSGPIOSET_EVENTGPIOEDGEDETECT0_Msk, ///< Event when GPIO input 0 edge is detected.
    NPMX_EVENT_GROUP_GPIO1_DETECTED_MASK = MAIN_EVENTSGPIOSET_EVENTGPIOEDGEDETECT1_Msk, ///< Event when GPIO input 1 edge is detected.
    NPMX_EVENT_GROUP_GPIO2_DETECTED_MASK = MAIN_EVENTSGPIOSET_EVENTGPIOEDGEDETECT2_Msk, ///< Event when GPIO input 2 edge is detected.
    NPMX_EVENT_GROUP_GPIO3_DETECTED_MASK = MAIN_EVENTSGPIOSET_EVENTGPIOEDGEDETECT3_Msk, ///< Event when GPIO input 3 edge is detected.
    NPMX_EVENT_GROUP_GPIO4_DETECTED_MASK = MAIN_EVENTSGPIOSET_EVENTGPIOEDGEDETECT4_Msk, ///< Event when GPIO input 4 edge is detected.
} npmx_event_group_gpio_mask_t;

/** @} */

#ifdef __cplusplus
}
#endif

#endif /* NPMX_EVENT_H__ */
