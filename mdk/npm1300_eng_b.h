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

#ifndef NPM1300_ENG_B_H
#define NPM1300_ENG_B_H

#ifdef __cplusplus
    extern "C" {
#endif

/* ====================================================== Include types ====================================================== */
#include "npm1300_eng_b_types.h"

/* ========================================= Start of section using anonymous unions ========================================= */

#if defined (__CC_ARM)
  #pragma anon_unions
#elif defined (__ICCARM__)
  #pragma language=extended
#elif defined(__ARMCC_VERSION) && (__ARMCC_VERSION >= 6010050)
  #pragma clang diagnostic push
  #pragma clang diagnostic ignored "-Wc11-extensions"
  #pragma clang diagnostic ignored "-Wreserved-id-macro"
  #pragma clang diagnostic ignored "-Wgnu-anonymous-struct"
  #pragma clang diagnostic ignored "-Wnested-anon-types"
#elif defined (__GNUC__)
  /* anonymous unions are enabled by default */
#elif defined (__TMS470__)
  /* anonymous unions are enabled by default */
#elif defined (__TASKING__)
  #pragma warning 586
#elif defined (__CSMC__)
  /* anonymous unions are enabled by default */
#else
  #warning Unsupported compiler type
#endif

/* =========================================================================================================================== */
/* ================                                    Peripherals Section                                    ================ */
/* =========================================================================================================================== */


/* =========================================================================================================================== */
/* ================                                           MAIN                                           ================ */
/* =========================================================================================================================== */

/* ======================================================= Struct MAIN ======================================================= */
/**
  * @brief Neutrino MAIN  Registers
  */
typedef struct {                                     /*!< MAIN Structure                                                       */
  __IM  uint8_t   RESERVED;
  __OM  uint8_t   TASKSWRESET;                       /*!< (@ 0x00000001) Task Force a full reboot power-cycle                  */
  __IOM uint8_t   EVENTSADCSET;                      /*!< (@ 0x00000002) ADC Events Event Set                                  */
  __IOM uint8_t   EVENTSADCCLR;                      /*!< (@ 0x00000003) ADC Events Event Clear                                */
  __IOM uint8_t   INTENEVENTSADCSET;                 /*!< (@ 0x00000004) ADC Events Interrupt Enable Set                       */
  __IOM uint8_t   INTENEVENTSADCCLR;                 /*!< (@ 0x00000005) ADC Events Interrupt Enable Clear                     */
  __IOM uint8_t   EVENTSBCHARGER0SET;                /*!< (@ 0x00000006) Battery Charger Temperature Events Event Set          */
  __IOM uint8_t   EVENTSBCHARGER0CLR;                /*!< (@ 0x00000007) Battery Charger Temperature Events Event Clear        */
  __IOM uint8_t   INTENEVENTSBCHARGER0SET;           /*!< (@ 0x00000008) Battery Charger Temperature Events Interrupt Enable
                                                                         Set*/                                                    
  __IOM uint8_t   INTENEVENTSBCHARGER0CLR;           /*!< (@ 0x00000009) Battery Charger Temperature Events Interrupt Enable
                                                                         Clear*/                                                  
  __IOM uint8_t   EVENTSBCHARGER1SET;                /*!< (@ 0x0000000A) Battery Charger Status Events Event Set               */
  __IOM uint8_t   EVENTSBCHARGER1CLR;                /*!< (@ 0x0000000B) Battery Charger Status Events Event Clear             */
  __IOM uint8_t   INTENEVENTSBCHARGER1SET;           /*!< (@ 0x0000000C) Battery Charger Status Events Interrupt Enable Set    */
  __IOM uint8_t   INTENEVENTSBCHARGER1CLR;           /*!< (@ 0x0000000D) Battery Charger Status Events Interrupt Enable Clear  */
  __IOM uint8_t   EVENTSBCHARGER2SET;                /*!< (@ 0x0000000E) Battery Charger Battery Events Event Set              */
  __IOM uint8_t   EVENTSBCHARGER2CLR;                /*!< (@ 0x0000000F) Battery Charger Battery Events Event Clear            */
  __IOM uint8_t   INTENEVENTSBCHARGER2SET;           /*!< (@ 0x00000010) Battery Charger Battery Events Interrupt Enable Set   */
  __IOM uint8_t   INTENEVENTSBCHARGER2CLR;           /*!< (@ 0x00000011) Battery Charger Battery Events Interrupt Enable Clear */
  __IOM uint8_t   EVENTSSHPHLDSET;                   /*!< (@ 0x00000012) ShipHold pin Events Event Set                         */
  __IOM uint8_t   EVENTSSHPHLDCLR;                   /*!< (@ 0x00000013) ShipHold pin Events Event Clear                       */
  __IOM uint8_t   INTENEVENTSSHPHLDSET;              /*!< (@ 0x00000014) ShipHold pin Events Interrupt Enable Set              */
  __IOM uint8_t   INTENEVENTSSHPHLDCLR;              /*!< (@ 0x00000015) ShipHold pin Events Interrupt Enable Clear            */
  __IOM uint8_t   EVENTSVBUSIN0SET;                  /*!< (@ 0x00000016) VBUSIN Voltage Detection Events Event Set             */
  __IOM uint8_t   EVENTSVBUSIN0CLR;                  /*!< (@ 0x00000017) VBUSIN Voltage Detection Events Event Clear           */
  __IOM uint8_t   INTENEVENTSVBUSIN0SET;             /*!< (@ 0x00000018) VBUSIN Voltage Detection Events Interrupt Enable Set  */
  __IOM uint8_t   INTENEVENTSVBUSIN0CLR;             /*!< (@ 0x00000019) VBUSIN Voltage Detection Events Interrupt Enable Clear*/
  __IOM uint8_t   EVENTSVBUSIN1SET;                  /*!< (@ 0x0000001A) VBUSIN Thermal and USB Events Event Set               */
  __IOM uint8_t   EVENTSVBUSIN1CLR;                  /*!< (@ 0x0000001B) VBUSIN Thermal and USB Events Event Clear             */
  __IOM uint8_t   INTENEVENTSVBUSIN1SET;             /*!< (@ 0x0000001C) VBUSIN Thermal and USB Events Interrupt Enable Set    */
  __IOM uint8_t   INTENEVENTSVBUSIN1CLR;             /*!< (@ 0x0000001D) VBUSIN Thermal and USB Events Interrupt Enable Clear  */
  __IM  uint8_t   RESERVED1[4];
  __IOM uint8_t   EVENTSGPIOSET;                     /*!< (@ 0x00000022) GPIO Event Event Set                                  */
  __IOM uint8_t   EVENTSGPIOCLR;                     /*!< (@ 0x00000023) GPIO Event Event Clear                                */
  __IOM uint8_t   INTENEVENTSGPIOSET;                /*!< (@ 0x00000024) GPIO Event Interrupt Enable Set                       */
  __IOM uint8_t   INTENEVENTSGPIOCLR;                /*!< (@ 0x00000025) GPIO Event Interrupt Enable Clear                     */
}NPM_MAIN_Type;                                      /*!< Size = 38 (0x026)                                                    */

/* MAIN_TASKSWRESET: Task Force a full reboot power-cycle */

/* TASKSWRESET @Bit 0 : Turn off all Supplies and apply internal reset */
#define MAIN_TASKSWRESET_TASKSWRESET_Pos (0UL)       /*!< Position of TASKSWRESET field.                                       */
#define MAIN_TASKSWRESET_TASKSWRESET_Msk (0x1UL << MAIN_TASKSWRESET_TASKSWRESET_Pos) /*!< Bit mask of TASKSWRESET field.       */
#define MAIN_TASKSWRESET_TASKSWRESET_NOEFFECT (0)    /*!< no effect                                                            */
#define MAIN_TASKSWRESET_TASKSWRESET_TRIGGER (1)     /*!< Trigger task                                                         */


/* MAIN_EVENTSADCSET: ADC Events Event Set */

/* EVENTADCVBATRDY @Bit 0 : VBAT measurement finished.
          Writing 1 sets the event (for debugging). */
#define MAIN_EVENTSADCSET_EVENTADCVBATRDY_Pos (0UL)  /*!< Position of EVENTADCVBATRDY field.                                   */
#define MAIN_EVENTSADCSET_EVENTADCVBATRDY_Msk (0x1UL << MAIN_EVENTSADCSET_EVENTADCVBATRDY_Pos) /*!< Bit mask of EVENTADCVBATRDY
                                                                            field.*/                                              
#define MAIN_EVENTSADCSET_EVENTADCVBATRDY_LOW (0)    /*!< low                                                                  */
#define MAIN_EVENTSADCSET_EVENTADCVBATRDY_HIGH (1)   /*!< high                                                                 */

/* EVENTADCNTCRDY @Bit 1 : Battery NTC measurement finished.
          Writing 1 sets the event (for debugging). */
#define MAIN_EVENTSADCSET_EVENTADCNTCRDY_Pos (1UL)   /*!< Position of EVENTADCNTCRDY field.                                    */
#define MAIN_EVENTSADCSET_EVENTADCNTCRDY_Msk (0x1UL << MAIN_EVENTSADCSET_EVENTADCNTCRDY_Pos) /*!< Bit mask of EVENTADCNTCRDY
                                                                            field.*/                                              
#define MAIN_EVENTSADCSET_EVENTADCNTCRDY_LOW (0)     /*!< low                                                                  */
#define MAIN_EVENTSADCSET_EVENTADCNTCRDY_HIGH (1)    /*!< high                                                                 */

/* EVENTADCTEMPRDY @Bit 2 : Internal Die Temperature measurement finished.
          Writing 1 sets the event (for debugging). */
#define MAIN_EVENTSADCSET_EVENTADCTEMPRDY_Pos (2UL)  /*!< Position of EVENTADCTEMPRDY field.                                   */
#define MAIN_EVENTSADCSET_EVENTADCTEMPRDY_Msk (0x1UL << MAIN_EVENTSADCSET_EVENTADCTEMPRDY_Pos) /*!< Bit mask of EVENTADCTEMPRDY
                                                                            field.*/                                              
#define MAIN_EVENTSADCSET_EVENTADCTEMPRDY_LOW (0)    /*!< low                                                                  */
#define MAIN_EVENTSADCSET_EVENTADCTEMPRDY_HIGH (1)   /*!< high                                                                 */

/* EVENTADCVSYSRDY @Bit 3 : VSYS Voltage measurement measurement finished.
          Writing 1 sets the event (for debugging). */
#define MAIN_EVENTSADCSET_EVENTADCVSYSRDY_Pos (3UL)  /*!< Position of EVENTADCVSYSRDY field.                                   */
#define MAIN_EVENTSADCSET_EVENTADCVSYSRDY_Msk (0x1UL << MAIN_EVENTSADCSET_EVENTADCVSYSRDY_Pos) /*!< Bit mask of EVENTADCVSYSRDY
                                                                            field.*/                                              
#define MAIN_EVENTSADCSET_EVENTADCVSYSRDY_LOW (0)    /*!< low                                                                  */
#define MAIN_EVENTSADCSET_EVENTADCVSYSRDY_HIGH (1)   /*!< high                                                                 */

/* EVENTADCVSET1RDY @Bit 4 : DCDC VSET1 pin measurement finished.
          Writing 1 sets the event (for debugging). */
#define MAIN_EVENTSADCSET_EVENTADCVSET1RDY_Pos (4UL) /*!< Position of EVENTADCVSET1RDY field.                                  */
#define MAIN_EVENTSADCSET_EVENTADCVSET1RDY_Msk (0x1UL << MAIN_EVENTSADCSET_EVENTADCVSET1RDY_Pos) /*!< Bit mask of
                                                                            EVENTADCVSET1RDY field.*/                             
#define MAIN_EVENTSADCSET_EVENTADCVSET1RDY_LOW (0)   /*!< low                                                                  */
#define MAIN_EVENTSADCSET_EVENTADCVSET1RDY_HIGH (1)  /*!< high                                                                 */

/* EVENTADCVSET2RDY @Bit 5 : DCDC VSET2 pin measurement finished.
          Writing 1 sets the event (for debugging). */
#define MAIN_EVENTSADCSET_EVENTADCVSET2RDY_Pos (5UL) /*!< Position of EVENTADCVSET2RDY field.                                  */
#define MAIN_EVENTSADCSET_EVENTADCVSET2RDY_Msk (0x1UL << MAIN_EVENTSADCSET_EVENTADCVSET2RDY_Pos) /*!< Bit mask of
                                                                            EVENTADCVSET2RDY field.*/                             
#define MAIN_EVENTSADCSET_EVENTADCVSET2RDY_LOW (0)   /*!< low                                                                  */
#define MAIN_EVENTSADCSET_EVENTADCVSET2RDY_HIGH (1)  /*!< high                                                                 */

/* EVENTADCIBATRDY @Bit 6 : IBAT measurement finished.
          Writing 1 sets the event (for debugging). */
#define MAIN_EVENTSADCSET_EVENTADCIBATRDY_Pos (6UL)  /*!< Position of EVENTADCIBATRDY field.                                   */
#define MAIN_EVENTSADCSET_EVENTADCIBATRDY_Msk (0x1UL << MAIN_EVENTSADCSET_EVENTADCIBATRDY_Pos) /*!< Bit mask of EVENTADCIBATRDY
                                                                            field.*/                                              
#define MAIN_EVENTSADCSET_EVENTADCIBATRDY_LOW (0)    /*!< low                                                                  */
#define MAIN_EVENTSADCSET_EVENTADCIBATRDY_HIGH (1)   /*!< high                                                                 */

/* EVENTADCVBUS7V0RDY @Bit 7 : VBUS (7Volt range) measurement finished.
          Writing 1 sets the event (for debugging). */
#define MAIN_EVENTSADCSET_EVENTADCVBUS7V0RDY_Pos (7UL) /*!< Position of EVENTADCVBUS7V0RDY field.                              */
#define MAIN_EVENTSADCSET_EVENTADCVBUS7V0RDY_Msk (0x1UL << MAIN_EVENTSADCSET_EVENTADCVBUS7V0RDY_Pos) /*!< Bit mask of
                                                                            EVENTADCVBUS7V0RDY field.*/                           
#define MAIN_EVENTSADCSET_EVENTADCVBUS7V0RDY_LOW (0) /*!< low                                                                  */
#define MAIN_EVENTSADCSET_EVENTADCVBUS7V0RDY_HIGH (1) /*!< high                                                                */


/* MAIN_EVENTSADCCLR: ADC Events Event Clear */

/* EVENTADCVBATRDY @Bit 0 : VBAT measurement finished.
          Writing 1 clears the event (e.g. to acknowledge an interrupt).
                            */                                                                                                    
                                                                                                                                  
#define MAIN_EVENTSADCCLR_EVENTADCVBATRDY_Pos (0UL)  /*!< Position of EVENTADCVBATRDY field.                                   */
#define MAIN_EVENTSADCCLR_EVENTADCVBATRDY_Msk (0x1UL << MAIN_EVENTSADCCLR_EVENTADCVBATRDY_Pos) /*!< Bit mask of EVENTADCVBATRDY
                                                                            field.*/                                              
#define MAIN_EVENTSADCCLR_EVENTADCVBATRDY_LOW (0)    /*!< low                                                                  */
#define MAIN_EVENTSADCCLR_EVENTADCVBATRDY_HIGH (1)   /*!< high                                                                 */

/* EVENTADCNTCRDY @Bit 1 : Battery NTC measurement finished.
          Writing 1 clears the event (e.g. to acknowledge an
                           interrupt). */                                                                                         
                                                                                                                                  
#define MAIN_EVENTSADCCLR_EVENTADCNTCRDY_Pos (1UL)   /*!< Position of EVENTADCNTCRDY field.                                    */
#define MAIN_EVENTSADCCLR_EVENTADCNTCRDY_Msk (0x1UL << MAIN_EVENTSADCCLR_EVENTADCNTCRDY_Pos) /*!< Bit mask of EVENTADCNTCRDY
                                                                            field.*/                                              
#define MAIN_EVENTSADCCLR_EVENTADCNTCRDY_LOW (0)     /*!< low                                                                  */
#define MAIN_EVENTSADCCLR_EVENTADCNTCRDY_HIGH (1)    /*!< high                                                                 */

/* EVENTADCTEMPRDY @Bit 2 : Internal Die Temperature measurement finished.
          Writing 1 clears the event (e.g. to
                            acknowledge an interrupt). */                                                                         
                                                                                                                                  
#define MAIN_EVENTSADCCLR_EVENTADCTEMPRDY_Pos (2UL)  /*!< Position of EVENTADCTEMPRDY field.                                   */
#define MAIN_EVENTSADCCLR_EVENTADCTEMPRDY_Msk (0x1UL << MAIN_EVENTSADCCLR_EVENTADCTEMPRDY_Pos) /*!< Bit mask of EVENTADCTEMPRDY
                                                                            field.*/                                              
#define MAIN_EVENTSADCCLR_EVENTADCTEMPRDY_LOW (0)    /*!< low                                                                  */
#define MAIN_EVENTSADCCLR_EVENTADCTEMPRDY_HIGH (1)   /*!< high                                                                 */

/* EVENTADCVSYSRDY @Bit 3 : VSYS Voltage measurement measurement finished.
          Writing 1 clears the event (e.g. to
                            acknowledge an interrupt). */                                                                         
                                                                                                                                  
#define MAIN_EVENTSADCCLR_EVENTADCVSYSRDY_Pos (3UL)  /*!< Position of EVENTADCVSYSRDY field.                                   */
#define MAIN_EVENTSADCCLR_EVENTADCVSYSRDY_Msk (0x1UL << MAIN_EVENTSADCCLR_EVENTADCVSYSRDY_Pos) /*!< Bit mask of EVENTADCVSYSRDY
                                                                            field.*/                                              
#define MAIN_EVENTSADCCLR_EVENTADCVSYSRDY_LOW (0)    /*!< low                                                                  */
#define MAIN_EVENTSADCCLR_EVENTADCVSYSRDY_HIGH (1)   /*!< high                                                                 */

/* EVENTADCVSET1RDY @Bit 4 : DCDC VSET1 pin measurement finished.
          Writing 1 clears the event (e.g. to acknowledge an
                             interrupt). */                                                                                       
                                                                                                                                  
#define MAIN_EVENTSADCCLR_EVENTADCVSET1RDY_Pos (4UL) /*!< Position of EVENTADCVSET1RDY field.                                  */
#define MAIN_EVENTSADCCLR_EVENTADCVSET1RDY_Msk (0x1UL << MAIN_EVENTSADCCLR_EVENTADCVSET1RDY_Pos) /*!< Bit mask of
                                                                            EVENTADCVSET1RDY field.*/                             
#define MAIN_EVENTSADCCLR_EVENTADCVSET1RDY_LOW (0)   /*!< low                                                                  */
#define MAIN_EVENTSADCCLR_EVENTADCVSET1RDY_HIGH (1)  /*!< high                                                                 */

/* EVENTADCVSET2RDY @Bit 5 : DCDC VSET2 pin measurement finished.
          Writing 1 clears the event (e.g. to acknowledge an
                             interrupt). */                                                                                       
                                                                                                                                  
#define MAIN_EVENTSADCCLR_EVENTADCVSET2RDY_Pos (5UL) /*!< Position of EVENTADCVSET2RDY field.                                  */
#define MAIN_EVENTSADCCLR_EVENTADCVSET2RDY_Msk (0x1UL << MAIN_EVENTSADCCLR_EVENTADCVSET2RDY_Pos) /*!< Bit mask of
                                                                            EVENTADCVSET2RDY field.*/                             
#define MAIN_EVENTSADCCLR_EVENTADCVSET2RDY_LOW (0)   /*!< low                                                                  */
#define MAIN_EVENTSADCCLR_EVENTADCVSET2RDY_HIGH (1)  /*!< high                                                                 */

/* EVENTADCIBATRDY @Bit 6 : IBAT measurement finished.
          Writing 1 clears the event (e.g. to acknowledge an interrupt).
                            */                                                                                                    
                                                                                                                                  
#define MAIN_EVENTSADCCLR_EVENTADCIBATRDY_Pos (6UL)  /*!< Position of EVENTADCIBATRDY field.                                   */
#define MAIN_EVENTSADCCLR_EVENTADCIBATRDY_Msk (0x1UL << MAIN_EVENTSADCCLR_EVENTADCIBATRDY_Pos) /*!< Bit mask of EVENTADCIBATRDY
                                                                            field.*/                                              
#define MAIN_EVENTSADCCLR_EVENTADCIBATRDY_LOW (0)    /*!< low                                                                  */
#define MAIN_EVENTSADCCLR_EVENTADCIBATRDY_HIGH (1)   /*!< high                                                                 */

/* EVENTADCVBUS7V0RDY @Bit 7 : VBUS (7Volt range) measurement finished.
          Writing 1 clears the event (e.g. to
                               acknowledge an interrupt). */                                                                      
                                                                                                                                  
#define MAIN_EVENTSADCCLR_EVENTADCVBUS7V0RDY_Pos (7UL) /*!< Position of EVENTADCVBUS7V0RDY field.                              */
#define MAIN_EVENTSADCCLR_EVENTADCVBUS7V0RDY_Msk (0x1UL << MAIN_EVENTSADCCLR_EVENTADCVBUS7V0RDY_Pos) /*!< Bit mask of
                                                                            EVENTADCVBUS7V0RDY field.*/                           
#define MAIN_EVENTSADCCLR_EVENTADCVBUS7V0RDY_LOW (0) /*!< low                                                                  */
#define MAIN_EVENTSADCCLR_EVENTADCVBUS7V0RDY_HIGH (1) /*!< high                                                                */


/* MAIN_INTENEVENTSADCSET: ADC Events Interrupt Enable Set */

/* EVENTADCVBATRDY @Bit 0 : Writing 1 enables interrupts from EVENTADCVBATRDY */
#define MAIN_INTENEVENTSADCSET_EVENTADCVBATRDY_Pos (0UL) /*!< Position of EVENTADCVBATRDY field.                               */
#define MAIN_INTENEVENTSADCSET_EVENTADCVBATRDY_Msk (0x1UL << MAIN_INTENEVENTSADCSET_EVENTADCVBATRDY_Pos) /*!< Bit mask of
                                                                            EVENTADCVBATRDY field.*/                              
#define MAIN_INTENEVENTSADCSET_EVENTADCVBATRDY_LOW (0) /*!< low                                                                */
#define MAIN_INTENEVENTSADCSET_EVENTADCVBATRDY_HIGH (1) /*!< high                                                              */

/* EVENTADCNTCRDY @Bit 1 : Writing 1 enables interrupts from EVENTADCNTCRDY */
#define MAIN_INTENEVENTSADCSET_EVENTADCNTCRDY_Pos (1UL) /*!< Position of EVENTADCNTCRDY field.                                 */
#define MAIN_INTENEVENTSADCSET_EVENTADCNTCRDY_Msk (0x1UL << MAIN_INTENEVENTSADCSET_EVENTADCNTCRDY_Pos) /*!< Bit mask of
                                                                            EVENTADCNTCRDY field.*/                               
#define MAIN_INTENEVENTSADCSET_EVENTADCNTCRDY_LOW (0) /*!< low                                                                 */
#define MAIN_INTENEVENTSADCSET_EVENTADCNTCRDY_HIGH (1) /*!< high                                                               */

/* EVENTADCTEMPRDY @Bit 2 : Writing 1 enables interrupts from EVENTADCTEMPRDY */
#define MAIN_INTENEVENTSADCSET_EVENTADCTEMPRDY_Pos (2UL) /*!< Position of EVENTADCTEMPRDY field.                               */
#define MAIN_INTENEVENTSADCSET_EVENTADCTEMPRDY_Msk (0x1UL << MAIN_INTENEVENTSADCSET_EVENTADCTEMPRDY_Pos) /*!< Bit mask of
                                                                            EVENTADCTEMPRDY field.*/                              
#define MAIN_INTENEVENTSADCSET_EVENTADCTEMPRDY_LOW (0) /*!< low                                                                */
#define MAIN_INTENEVENTSADCSET_EVENTADCTEMPRDY_HIGH (1) /*!< high                                                              */

/* EVENTADCVSYSRDY @Bit 3 : Writing 1 enables interrupts from EVENTADCVSYSRDY */
#define MAIN_INTENEVENTSADCSET_EVENTADCVSYSRDY_Pos (3UL) /*!< Position of EVENTADCVSYSRDY field.                               */
#define MAIN_INTENEVENTSADCSET_EVENTADCVSYSRDY_Msk (0x1UL << MAIN_INTENEVENTSADCSET_EVENTADCVSYSRDY_Pos) /*!< Bit mask of
                                                                            EVENTADCVSYSRDY field.*/                              
#define MAIN_INTENEVENTSADCSET_EVENTADCVSYSRDY_LOW (0) /*!< low                                                                */
#define MAIN_INTENEVENTSADCSET_EVENTADCVSYSRDY_HIGH (1) /*!< high                                                              */

/* EVENTADCVSET1RDY @Bit 4 : Writing 1 enables interrupts from EVENTADCVSET1RDY */
#define MAIN_INTENEVENTSADCSET_EVENTADCVSET1RDY_Pos (4UL) /*!< Position of EVENTADCVSET1RDY field.                             */
#define MAIN_INTENEVENTSADCSET_EVENTADCVSET1RDY_Msk (0x1UL << MAIN_INTENEVENTSADCSET_EVENTADCVSET1RDY_Pos) /*!< Bit mask of
                                                                            EVENTADCVSET1RDY field.*/                             
#define MAIN_INTENEVENTSADCSET_EVENTADCVSET1RDY_LOW (0) /*!< low                                                               */
#define MAIN_INTENEVENTSADCSET_EVENTADCVSET1RDY_HIGH (1) /*!< high                                                             */

/* EVENTADCVSET2RDY @Bit 5 : Writing 1 enables interrupts from EVENTADCVSET2RDY */
#define MAIN_INTENEVENTSADCSET_EVENTADCVSET2RDY_Pos (5UL) /*!< Position of EVENTADCVSET2RDY field.                             */
#define MAIN_INTENEVENTSADCSET_EVENTADCVSET2RDY_Msk (0x1UL << MAIN_INTENEVENTSADCSET_EVENTADCVSET2RDY_Pos) /*!< Bit mask of
                                                                            EVENTADCVSET2RDY field.*/                             
#define MAIN_INTENEVENTSADCSET_EVENTADCVSET2RDY_LOW (0) /*!< low                                                               */
#define MAIN_INTENEVENTSADCSET_EVENTADCVSET2RDY_HIGH (1) /*!< high                                                             */

/* EVENTADCIBATRDY @Bit 6 : Writing 1 enables interrupts from EVENTADCIBATRDY */
#define MAIN_INTENEVENTSADCSET_EVENTADCIBATRDY_Pos (6UL) /*!< Position of EVENTADCIBATRDY field.                               */
#define MAIN_INTENEVENTSADCSET_EVENTADCIBATRDY_Msk (0x1UL << MAIN_INTENEVENTSADCSET_EVENTADCIBATRDY_Pos) /*!< Bit mask of
                                                                            EVENTADCIBATRDY field.*/                              
#define MAIN_INTENEVENTSADCSET_EVENTADCIBATRDY_LOW (0) /*!< low                                                                */
#define MAIN_INTENEVENTSADCSET_EVENTADCIBATRDY_HIGH (1) /*!< high                                                              */

/* EVENTADCVBUS7V0RDY @Bit 7 : Writing 1 enables interrupts from EVENTADCVBUS7V0RDY */
#define MAIN_INTENEVENTSADCSET_EVENTADCVBUS7V0RDY_Pos (7UL) /*!< Position of EVENTADCVBUS7V0RDY field.                         */
#define MAIN_INTENEVENTSADCSET_EVENTADCVBUS7V0RDY_Msk (0x1UL << MAIN_INTENEVENTSADCSET_EVENTADCVBUS7V0RDY_Pos) /*!< Bit mask of
                                                                            EVENTADCVBUS7V0RDY field.*/                           
#define MAIN_INTENEVENTSADCSET_EVENTADCVBUS7V0RDY_LOW (0) /*!< low                                                             */
#define MAIN_INTENEVENTSADCSET_EVENTADCVBUS7V0RDY_HIGH (1) /*!< high                                                           */


/* MAIN_INTENEVENTSADCCLR: ADC Events Interrupt Enable Clear */

/* EVENTADCVBATRDY @Bit 0 : Writing 1 disables interrupts from EVENTADCVBATRDY */
#define MAIN_INTENEVENTSADCCLR_EVENTADCVBATRDY_Pos (0UL) /*!< Position of EVENTADCVBATRDY field.                               */
#define MAIN_INTENEVENTSADCCLR_EVENTADCVBATRDY_Msk (0x1UL << MAIN_INTENEVENTSADCCLR_EVENTADCVBATRDY_Pos) /*!< Bit mask of
                                                                            EVENTADCVBATRDY field.*/                              
#define MAIN_INTENEVENTSADCCLR_EVENTADCVBATRDY_LOW (0) /*!< low                                                                */
#define MAIN_INTENEVENTSADCCLR_EVENTADCVBATRDY_HIGH (1) /*!< high                                                              */

/* EVENTADCNTCRDY @Bit 1 : Writing 1 disables interrupts from EVENTADCNTCRDY */
#define MAIN_INTENEVENTSADCCLR_EVENTADCNTCRDY_Pos (1UL) /*!< Position of EVENTADCNTCRDY field.                                 */
#define MAIN_INTENEVENTSADCCLR_EVENTADCNTCRDY_Msk (0x1UL << MAIN_INTENEVENTSADCCLR_EVENTADCNTCRDY_Pos) /*!< Bit mask of
                                                                            EVENTADCNTCRDY field.*/                               
#define MAIN_INTENEVENTSADCCLR_EVENTADCNTCRDY_LOW (0) /*!< low                                                                 */
#define MAIN_INTENEVENTSADCCLR_EVENTADCNTCRDY_HIGH (1) /*!< high                                                               */

/* EVENTADCTEMPRDY @Bit 2 : Writing 1 disables interrupts from EVENTADCTEMPRDY */
#define MAIN_INTENEVENTSADCCLR_EVENTADCTEMPRDY_Pos (2UL) /*!< Position of EVENTADCTEMPRDY field.                               */
#define MAIN_INTENEVENTSADCCLR_EVENTADCTEMPRDY_Msk (0x1UL << MAIN_INTENEVENTSADCCLR_EVENTADCTEMPRDY_Pos) /*!< Bit mask of
                                                                            EVENTADCTEMPRDY field.*/                              
#define MAIN_INTENEVENTSADCCLR_EVENTADCTEMPRDY_LOW (0) /*!< low                                                                */
#define MAIN_INTENEVENTSADCCLR_EVENTADCTEMPRDY_HIGH (1) /*!< high                                                              */

/* EVENTADCVSYSRDY @Bit 3 : Writing 1 disables interrupts from EVENTADCVSYSRDY */
#define MAIN_INTENEVENTSADCCLR_EVENTADCVSYSRDY_Pos (3UL) /*!< Position of EVENTADCVSYSRDY field.                               */
#define MAIN_INTENEVENTSADCCLR_EVENTADCVSYSRDY_Msk (0x1UL << MAIN_INTENEVENTSADCCLR_EVENTADCVSYSRDY_Pos) /*!< Bit mask of
                                                                            EVENTADCVSYSRDY field.*/                              
#define MAIN_INTENEVENTSADCCLR_EVENTADCVSYSRDY_LOW (0) /*!< low                                                                */
#define MAIN_INTENEVENTSADCCLR_EVENTADCVSYSRDY_HIGH (1) /*!< high                                                              */

/* EVENTADCVSET1RDY @Bit 4 : Writing 1 disables interrupts from EVENTADCVSET1RDY */
#define MAIN_INTENEVENTSADCCLR_EVENTADCVSET1RDY_Pos (4UL) /*!< Position of EVENTADCVSET1RDY field.                             */
#define MAIN_INTENEVENTSADCCLR_EVENTADCVSET1RDY_Msk (0x1UL << MAIN_INTENEVENTSADCCLR_EVENTADCVSET1RDY_Pos) /*!< Bit mask of
                                                                            EVENTADCVSET1RDY field.*/                             
#define MAIN_INTENEVENTSADCCLR_EVENTADCVSET1RDY_LOW (0) /*!< low                                                               */
#define MAIN_INTENEVENTSADCCLR_EVENTADCVSET1RDY_HIGH (1) /*!< high                                                             */

/* EVENTADCVSET2RDY @Bit 5 : Writing 1 disables interrupts from EVENTADCVSET2RDY */
#define MAIN_INTENEVENTSADCCLR_EVENTADCVSET2RDY_Pos (5UL) /*!< Position of EVENTADCVSET2RDY field.                             */
#define MAIN_INTENEVENTSADCCLR_EVENTADCVSET2RDY_Msk (0x1UL << MAIN_INTENEVENTSADCCLR_EVENTADCVSET2RDY_Pos) /*!< Bit mask of
                                                                            EVENTADCVSET2RDY field.*/                             
#define MAIN_INTENEVENTSADCCLR_EVENTADCVSET2RDY_LOW (0) /*!< low                                                               */
#define MAIN_INTENEVENTSADCCLR_EVENTADCVSET2RDY_HIGH (1) /*!< high                                                             */

/* EVENTADCIBATRDY @Bit 6 : Writing 1 disables interrupts from EVENTADCIBATRDY */
#define MAIN_INTENEVENTSADCCLR_EVENTADCIBATRDY_Pos (6UL) /*!< Position of EVENTADCIBATRDY field.                               */
#define MAIN_INTENEVENTSADCCLR_EVENTADCIBATRDY_Msk (0x1UL << MAIN_INTENEVENTSADCCLR_EVENTADCIBATRDY_Pos) /*!< Bit mask of
                                                                            EVENTADCIBATRDY field.*/                              
#define MAIN_INTENEVENTSADCCLR_EVENTADCIBATRDY_LOW (0) /*!< low                                                                */
#define MAIN_INTENEVENTSADCCLR_EVENTADCIBATRDY_HIGH (1) /*!< high                                                              */

/* EVENTADCVBUS7V0RDY @Bit 7 : Writing 1 disables interrupts from EVENTADCVBUS7V0RDY */
#define MAIN_INTENEVENTSADCCLR_EVENTADCVBUS7V0RDY_Pos (7UL) /*!< Position of EVENTADCVBUS7V0RDY field.                         */
#define MAIN_INTENEVENTSADCCLR_EVENTADCVBUS7V0RDY_Msk (0x1UL << MAIN_INTENEVENTSADCCLR_EVENTADCVBUS7V0RDY_Pos) /*!< Bit mask of
                                                                            EVENTADCVBUS7V0RDY field.*/                           
#define MAIN_INTENEVENTSADCCLR_EVENTADCVBUS7V0RDY_LOW (0) /*!< low                                                             */
#define MAIN_INTENEVENTSADCCLR_EVENTADCVBUS7V0RDY_HIGH (1) /*!< high                                                           */


/* MAIN_EVENTSBCHARGER0SET: Battery Charger Temperature Events Event Set */

/* EVENTNTCCOLD @Bit 0 : Event when Cold Battery detected from NTC measure.
          Writing 1 sets the event (for debugging).
                         */                                                                                                       
                                                                                                                                  
#define MAIN_EVENTSBCHARGER0SET_EVENTNTCCOLD_Pos (0UL) /*!< Position of EVENTNTCCOLD field.                                    */
#define MAIN_EVENTSBCHARGER0SET_EVENTNTCCOLD_Msk (0x1UL << MAIN_EVENTSBCHARGER0SET_EVENTNTCCOLD_Pos) /*!< Bit mask of
                                                                            EVENTNTCCOLD field.*/                                 
#define MAIN_EVENTSBCHARGER0SET_EVENTNTCCOLD_LOW (0) /*!< low                                                                  */
#define MAIN_EVENTSBCHARGER0SET_EVENTNTCCOLD_HIGH (1) /*!< high                                                                */

/* EVENTNTCCOOL @Bit 1 : Event when Cool Battery detected from NTC measure.
          Writing 1 sets the event (for debugging).
                         */                                                                                                       
                                                                                                                                  
#define MAIN_EVENTSBCHARGER0SET_EVENTNTCCOOL_Pos (1UL) /*!< Position of EVENTNTCCOOL field.                                    */
#define MAIN_EVENTSBCHARGER0SET_EVENTNTCCOOL_Msk (0x1UL << MAIN_EVENTSBCHARGER0SET_EVENTNTCCOOL_Pos) /*!< Bit mask of
                                                                            EVENTNTCCOOL field.*/                                 
#define MAIN_EVENTSBCHARGER0SET_EVENTNTCCOOL_LOW (0) /*!< low                                                                  */
#define MAIN_EVENTSBCHARGER0SET_EVENTNTCCOOL_HIGH (1) /*!< high                                                                */

/* EVENTNTCWARM @Bit 2 : Event when Warm Battery detected from NTC measure.
          Writing 1 sets the event (for debugging).
                         */                                                                                                       
                                                                                                                                  
#define MAIN_EVENTSBCHARGER0SET_EVENTNTCWARM_Pos (2UL) /*!< Position of EVENTNTCWARM field.                                    */
#define MAIN_EVENTSBCHARGER0SET_EVENTNTCWARM_Msk (0x1UL << MAIN_EVENTSBCHARGER0SET_EVENTNTCWARM_Pos) /*!< Bit mask of
                                                                            EVENTNTCWARM field.*/                                 
#define MAIN_EVENTSBCHARGER0SET_EVENTNTCWARM_LOW (0) /*!< low                                                                  */
#define MAIN_EVENTSBCHARGER0SET_EVENTNTCWARM_HIGH (1) /*!< high                                                                */

/* EVENTNTCHOT @Bit 3 : Event when Hot Battery detected from NTC measure.
          Writing 1 sets the event (for debugging). */
#define MAIN_EVENTSBCHARGER0SET_EVENTNTCHOT_Pos (3UL) /*!< Position of EVENTNTCHOT field.                                      */
#define MAIN_EVENTSBCHARGER0SET_EVENTNTCHOT_Msk (0x1UL << MAIN_EVENTSBCHARGER0SET_EVENTNTCHOT_Pos) /*!< Bit mask of EVENTNTCHOT
                                                                            field.*/                                              
#define MAIN_EVENTSBCHARGER0SET_EVENTNTCHOT_LOW (0)  /*!< low                                                                  */
#define MAIN_EVENTSBCHARGER0SET_EVENTNTCHOT_HIGH (1) /*!< high                                                                 */

/* EVENTDIETEMPHIGH @Bit 4 : Event when die high temperature detected from Die Temp measure.
          Writing 1 sets the event
                             (for debugging). */                                                                                  
                                                                                                                                  
#define MAIN_EVENTSBCHARGER0SET_EVENTDIETEMPHIGH_Pos (4UL) /*!< Position of EVENTDIETEMPHIGH field.                            */
#define MAIN_EVENTSBCHARGER0SET_EVENTDIETEMPHIGH_Msk (0x1UL << MAIN_EVENTSBCHARGER0SET_EVENTDIETEMPHIGH_Pos) /*!< Bit mask of
                                                                            EVENTDIETEMPHIGH field.*/                             
#define MAIN_EVENTSBCHARGER0SET_EVENTDIETEMPHIGH_LOW (0) /*!< low                                                              */
#define MAIN_EVENTSBCHARGER0SET_EVENTDIETEMPHIGH_HIGH (1) /*!< high                                                            */

/* EVENTDIETEMPRESUME @Bit 5 : Event when die resume temperature detected from Die Temp measure.
          Writing 1 sets the
                               event (for debugging). */                                                                          
                                                                                                                                  
#define MAIN_EVENTSBCHARGER0SET_EVENTDIETEMPRESUME_Pos (5UL) /*!< Position of EVENTDIETEMPRESUME field.                        */
#define MAIN_EVENTSBCHARGER0SET_EVENTDIETEMPRESUME_Msk (0x1UL << MAIN_EVENTSBCHARGER0SET_EVENTDIETEMPRESUME_Pos) /*!< Bit mask
                                                                            of EVENTDIETEMPRESUME field.*/                        
#define MAIN_EVENTSBCHARGER0SET_EVENTDIETEMPRESUME_LOW (0) /*!< low                                                            */
#define MAIN_EVENTSBCHARGER0SET_EVENTDIETEMPRESUME_HIGH (1) /*!< high                                                          */


/* MAIN_EVENTSBCHARGER0CLR: Battery Charger Temperature Events Event Clear */

/* EVENTNTCCOLD @Bit 0 : Event when Cold Battery detected from NTC measure.
          Writing 1 clears the event (e.g. to
                         acknowledge an interrupt). */                                                                            
                                                                                                                                  
#define MAIN_EVENTSBCHARGER0CLR_EVENTNTCCOLD_Pos (0UL) /*!< Position of EVENTNTCCOLD field.                                    */
#define MAIN_EVENTSBCHARGER0CLR_EVENTNTCCOLD_Msk (0x1UL << MAIN_EVENTSBCHARGER0CLR_EVENTNTCCOLD_Pos) /*!< Bit mask of
                                                                            EVENTNTCCOLD field.*/                                 
#define MAIN_EVENTSBCHARGER0CLR_EVENTNTCCOLD_LOW (0) /*!< low                                                                  */
#define MAIN_EVENTSBCHARGER0CLR_EVENTNTCCOLD_HIGH (1) /*!< high                                                                */

/* EVENTNTCCOOL @Bit 1 : Event when Cool Battery detected from NTC measure.
          Writing 1 clears the event (e.g. to
                         acknowledge an interrupt). */                                                                            
                                                                                                                                  
#define MAIN_EVENTSBCHARGER0CLR_EVENTNTCCOOL_Pos (1UL) /*!< Position of EVENTNTCCOOL field.                                    */
#define MAIN_EVENTSBCHARGER0CLR_EVENTNTCCOOL_Msk (0x1UL << MAIN_EVENTSBCHARGER0CLR_EVENTNTCCOOL_Pos) /*!< Bit mask of
                                                                            EVENTNTCCOOL field.*/                                 
#define MAIN_EVENTSBCHARGER0CLR_EVENTNTCCOOL_LOW (0) /*!< low                                                                  */
#define MAIN_EVENTSBCHARGER0CLR_EVENTNTCCOOL_HIGH (1) /*!< high                                                                */

/* EVENTNTCWARM @Bit 2 : Event when Warm Battery detected from NTC measure.
          Writing 1 clears the event (e.g. to
                         acknowledge an interrupt). */                                                                            
                                                                                                                                  
#define MAIN_EVENTSBCHARGER0CLR_EVENTNTCWARM_Pos (2UL) /*!< Position of EVENTNTCWARM field.                                    */
#define MAIN_EVENTSBCHARGER0CLR_EVENTNTCWARM_Msk (0x1UL << MAIN_EVENTSBCHARGER0CLR_EVENTNTCWARM_Pos) /*!< Bit mask of
                                                                            EVENTNTCWARM field.*/                                 
#define MAIN_EVENTSBCHARGER0CLR_EVENTNTCWARM_LOW (0) /*!< low                                                                  */
#define MAIN_EVENTSBCHARGER0CLR_EVENTNTCWARM_HIGH (1) /*!< high                                                                */

/* EVENTNTCHOT @Bit 3 : Event when Hot Battery detected from NTC measure.
          Writing 1 clears the event (e.g. to
                        acknowledge an interrupt). */                                                                             
                                                                                                                                  
#define MAIN_EVENTSBCHARGER0CLR_EVENTNTCHOT_Pos (3UL) /*!< Position of EVENTNTCHOT field.                                      */
#define MAIN_EVENTSBCHARGER0CLR_EVENTNTCHOT_Msk (0x1UL << MAIN_EVENTSBCHARGER0CLR_EVENTNTCHOT_Pos) /*!< Bit mask of EVENTNTCHOT
                                                                            field.*/                                              
#define MAIN_EVENTSBCHARGER0CLR_EVENTNTCHOT_LOW (0)  /*!< low                                                                  */
#define MAIN_EVENTSBCHARGER0CLR_EVENTNTCHOT_HIGH (1) /*!< high                                                                 */

/* EVENTDIETEMPHIGH @Bit 4 : Event when die high temperature detected from Die Temp measure.
          Writing 1 clears the
                             event (e.g. to acknowledge an interrupt). */                                                         
                                                                                                                                  
#define MAIN_EVENTSBCHARGER0CLR_EVENTDIETEMPHIGH_Pos (4UL) /*!< Position of EVENTDIETEMPHIGH field.                            */
#define MAIN_EVENTSBCHARGER0CLR_EVENTDIETEMPHIGH_Msk (0x1UL << MAIN_EVENTSBCHARGER0CLR_EVENTDIETEMPHIGH_Pos) /*!< Bit mask of
                                                                            EVENTDIETEMPHIGH field.*/                             
#define MAIN_EVENTSBCHARGER0CLR_EVENTDIETEMPHIGH_LOW (0) /*!< low                                                              */
#define MAIN_EVENTSBCHARGER0CLR_EVENTDIETEMPHIGH_HIGH (1) /*!< high                                                            */

/* EVENTDIETEMPRESUME @Bit 5 : Event when die resume temperature detected from Die Temp measure.
          Writing 1 clears the
                               event (e.g. to acknowledge an interrupt). */                                                       
                                                                                                                                  
#define MAIN_EVENTSBCHARGER0CLR_EVENTDIETEMPRESUME_Pos (5UL) /*!< Position of EVENTDIETEMPRESUME field.                        */
#define MAIN_EVENTSBCHARGER0CLR_EVENTDIETEMPRESUME_Msk (0x1UL << MAIN_EVENTSBCHARGER0CLR_EVENTDIETEMPRESUME_Pos) /*!< Bit mask
                                                                            of EVENTDIETEMPRESUME field.*/                        
#define MAIN_EVENTSBCHARGER0CLR_EVENTDIETEMPRESUME_LOW (0) /*!< low                                                            */
#define MAIN_EVENTSBCHARGER0CLR_EVENTDIETEMPRESUME_HIGH (1) /*!< high                                                          */


/* MAIN_INTENEVENTSBCHARGER0SET: Battery Charger Temperature Events Interrupt Enable Set */

/* EVENTNTCCOLD @Bit 0 : Writing 1 enables interrupts from EVENTNTCCOLD */
#define MAIN_INTENEVENTSBCHARGER0SET_EVENTNTCCOLD_Pos (0UL) /*!< Position of EVENTNTCCOLD field.                               */
#define MAIN_INTENEVENTSBCHARGER0SET_EVENTNTCCOLD_Msk (0x1UL << MAIN_INTENEVENTSBCHARGER0SET_EVENTNTCCOLD_Pos) /*!< Bit mask of
                                                                            EVENTNTCCOLD field.*/                                 
#define MAIN_INTENEVENTSBCHARGER0SET_EVENTNTCCOLD_LOW (0) /*!< low                                                             */
#define MAIN_INTENEVENTSBCHARGER0SET_EVENTNTCCOLD_HIGH (1) /*!< high                                                           */

/* EVENTNTCCOOL @Bit 1 : Writing 1 enables interrupts from EVENTNTCCOOL */
#define MAIN_INTENEVENTSBCHARGER0SET_EVENTNTCCOOL_Pos (1UL) /*!< Position of EVENTNTCCOOL field.                               */
#define MAIN_INTENEVENTSBCHARGER0SET_EVENTNTCCOOL_Msk (0x1UL << MAIN_INTENEVENTSBCHARGER0SET_EVENTNTCCOOL_Pos) /*!< Bit mask of
                                                                            EVENTNTCCOOL field.*/                                 
#define MAIN_INTENEVENTSBCHARGER0SET_EVENTNTCCOOL_LOW (0) /*!< low                                                             */
#define MAIN_INTENEVENTSBCHARGER0SET_EVENTNTCCOOL_HIGH (1) /*!< high                                                           */

/* EVENTNTCWARM @Bit 2 : Writing 1 enables interrupts from EVENTNTCWARM */
#define MAIN_INTENEVENTSBCHARGER0SET_EVENTNTCWARM_Pos (2UL) /*!< Position of EVENTNTCWARM field.                               */
#define MAIN_INTENEVENTSBCHARGER0SET_EVENTNTCWARM_Msk (0x1UL << MAIN_INTENEVENTSBCHARGER0SET_EVENTNTCWARM_Pos) /*!< Bit mask of
                                                                            EVENTNTCWARM field.*/                                 
#define MAIN_INTENEVENTSBCHARGER0SET_EVENTNTCWARM_LOW (0) /*!< low                                                             */
#define MAIN_INTENEVENTSBCHARGER0SET_EVENTNTCWARM_HIGH (1) /*!< high                                                           */

/* EVENTNTCHOT @Bit 3 : Writing 1 enables interrupts from EVENTNTCHOT */
#define MAIN_INTENEVENTSBCHARGER0SET_EVENTNTCHOT_Pos (3UL) /*!< Position of EVENTNTCHOT field.                                 */
#define MAIN_INTENEVENTSBCHARGER0SET_EVENTNTCHOT_Msk (0x1UL << MAIN_INTENEVENTSBCHARGER0SET_EVENTNTCHOT_Pos) /*!< Bit mask of
                                                                            EVENTNTCHOT field.*/                                  
#define MAIN_INTENEVENTSBCHARGER0SET_EVENTNTCHOT_LOW (0) /*!< low                                                              */
#define MAIN_INTENEVENTSBCHARGER0SET_EVENTNTCHOT_HIGH (1) /*!< high                                                            */

/* EVENTDIETEMPHIGH @Bit 4 : Writing 1 enables interrupts from EVENTDIETEMPHIGH */
#define MAIN_INTENEVENTSBCHARGER0SET_EVENTDIETEMPHIGH_Pos (4UL) /*!< Position of EVENTDIETEMPHIGH field.                       */
#define MAIN_INTENEVENTSBCHARGER0SET_EVENTDIETEMPHIGH_Msk (0x1UL << MAIN_INTENEVENTSBCHARGER0SET_EVENTDIETEMPHIGH_Pos) /*!< Bit
                                                                            mask of EVENTDIETEMPHIGH field.*/                     
#define MAIN_INTENEVENTSBCHARGER0SET_EVENTDIETEMPHIGH_LOW (0) /*!< low                                                         */
#define MAIN_INTENEVENTSBCHARGER0SET_EVENTDIETEMPHIGH_HIGH (1) /*!< high                                                       */

/* EVENTDIETEMPRESUME @Bit 5 : Writing 1 enables interrupts from EVENTDIETEMPRESUME */
#define MAIN_INTENEVENTSBCHARGER0SET_EVENTDIETEMPRESUME_Pos (5UL) /*!< Position of EVENTDIETEMPRESUME field.                   */
#define MAIN_INTENEVENTSBCHARGER0SET_EVENTDIETEMPRESUME_Msk (0x1UL << MAIN_INTENEVENTSBCHARGER0SET_EVENTDIETEMPRESUME_Pos) /*!<
                                                                            Bit mask of EVENTDIETEMPRESUME field.*/               
#define MAIN_INTENEVENTSBCHARGER0SET_EVENTDIETEMPRESUME_LOW (0) /*!< low                                                       */
#define MAIN_INTENEVENTSBCHARGER0SET_EVENTDIETEMPRESUME_HIGH (1) /*!< high                                                     */


/* MAIN_INTENEVENTSBCHARGER0CLR: Battery Charger Temperature Events Interrupt Enable Clear */

/* EVENTNTCCOLD @Bit 0 : Writing 1 disables interrupts from EVENTNTCCOLD */
#define MAIN_INTENEVENTSBCHARGER0CLR_EVENTNTCCOLD_Pos (0UL) /*!< Position of EVENTNTCCOLD field.                               */
#define MAIN_INTENEVENTSBCHARGER0CLR_EVENTNTCCOLD_Msk (0x1UL << MAIN_INTENEVENTSBCHARGER0CLR_EVENTNTCCOLD_Pos) /*!< Bit mask of
                                                                            EVENTNTCCOLD field.*/                                 
#define MAIN_INTENEVENTSBCHARGER0CLR_EVENTNTCCOLD_LOW (0) /*!< low                                                             */
#define MAIN_INTENEVENTSBCHARGER0CLR_EVENTNTCCOLD_HIGH (1) /*!< high                                                           */

/* EVENTNTCCOOL @Bit 1 : Writing 1 disables interrupts from EVENTNTCCOOL */
#define MAIN_INTENEVENTSBCHARGER0CLR_EVENTNTCCOOL_Pos (1UL) /*!< Position of EVENTNTCCOOL field.                               */
#define MAIN_INTENEVENTSBCHARGER0CLR_EVENTNTCCOOL_Msk (0x1UL << MAIN_INTENEVENTSBCHARGER0CLR_EVENTNTCCOOL_Pos) /*!< Bit mask of
                                                                            EVENTNTCCOOL field.*/                                 
#define MAIN_INTENEVENTSBCHARGER0CLR_EVENTNTCCOOL_LOW (0) /*!< low                                                             */
#define MAIN_INTENEVENTSBCHARGER0CLR_EVENTNTCCOOL_HIGH (1) /*!< high                                                           */

/* EVENTNTCWARM @Bit 2 : Writing 1 disables interrupts from EVENTNTCWARM */
#define MAIN_INTENEVENTSBCHARGER0CLR_EVENTNTCWARM_Pos (2UL) /*!< Position of EVENTNTCWARM field.                               */
#define MAIN_INTENEVENTSBCHARGER0CLR_EVENTNTCWARM_Msk (0x1UL << MAIN_INTENEVENTSBCHARGER0CLR_EVENTNTCWARM_Pos) /*!< Bit mask of
                                                                            EVENTNTCWARM field.*/                                 
#define MAIN_INTENEVENTSBCHARGER0CLR_EVENTNTCWARM_LOW (0) /*!< low                                                             */
#define MAIN_INTENEVENTSBCHARGER0CLR_EVENTNTCWARM_HIGH (1) /*!< high                                                           */

/* EVENTNTCHOT @Bit 3 : Writing 1 disables interrupts from EVENTNTCHOT */
#define MAIN_INTENEVENTSBCHARGER0CLR_EVENTNTCHOT_Pos (3UL) /*!< Position of EVENTNTCHOT field.                                 */
#define MAIN_INTENEVENTSBCHARGER0CLR_EVENTNTCHOT_Msk (0x1UL << MAIN_INTENEVENTSBCHARGER0CLR_EVENTNTCHOT_Pos) /*!< Bit mask of
                                                                            EVENTNTCHOT field.*/                                  
#define MAIN_INTENEVENTSBCHARGER0CLR_EVENTNTCHOT_LOW (0) /*!< low                                                              */
#define MAIN_INTENEVENTSBCHARGER0CLR_EVENTNTCHOT_HIGH (1) /*!< high                                                            */

/* EVENTDIETEMPHIGH @Bit 4 : Writing 1 disables interrupts from EVENTDIETEMPHIGH */
#define MAIN_INTENEVENTSBCHARGER0CLR_EVENTDIETEMPHIGH_Pos (4UL) /*!< Position of EVENTDIETEMPHIGH field.                       */
#define MAIN_INTENEVENTSBCHARGER0CLR_EVENTDIETEMPHIGH_Msk (0x1UL << MAIN_INTENEVENTSBCHARGER0CLR_EVENTDIETEMPHIGH_Pos) /*!< Bit
                                                                            mask of EVENTDIETEMPHIGH field.*/                     
#define MAIN_INTENEVENTSBCHARGER0CLR_EVENTDIETEMPHIGH_LOW (0) /*!< low                                                         */
#define MAIN_INTENEVENTSBCHARGER0CLR_EVENTDIETEMPHIGH_HIGH (1) /*!< high                                                       */

/* EVENTDIETEMPRESUME @Bit 5 : Writing 1 disables interrupts from EVENTDIETEMPRESUME */
#define MAIN_INTENEVENTSBCHARGER0CLR_EVENTDIETEMPRESUME_Pos (5UL) /*!< Position of EVENTDIETEMPRESUME field.                   */
#define MAIN_INTENEVENTSBCHARGER0CLR_EVENTDIETEMPRESUME_Msk (0x1UL << MAIN_INTENEVENTSBCHARGER0CLR_EVENTDIETEMPRESUME_Pos) /*!<
                                                                            Bit mask of EVENTDIETEMPRESUME field.*/               
#define MAIN_INTENEVENTSBCHARGER0CLR_EVENTDIETEMPRESUME_LOW (0) /*!< low                                                       */
#define MAIN_INTENEVENTSBCHARGER0CLR_EVENTDIETEMPRESUME_HIGH (1) /*!< high                                                     */


/* MAIN_EVENTSBCHARGER1SET: Battery Charger Status Events Event Set */

/* EVENTSUPPLEMENT @Bit 0 : Event supplement mode activated.
          Writing 1 sets the event (for debugging). */
#define MAIN_EVENTSBCHARGER1SET_EVENTSUPPLEMENT_Pos (0UL) /*!< Position of EVENTSUPPLEMENT field.                              */
#define MAIN_EVENTSBCHARGER1SET_EVENTSUPPLEMENT_Msk (0x1UL << MAIN_EVENTSBCHARGER1SET_EVENTSUPPLEMENT_Pos) /*!< Bit mask of
                                                                            EVENTSUPPLEMENT field.*/                              
#define MAIN_EVENTSBCHARGER1SET_EVENTSUPPLEMENT_LOW (0) /*!< low                                                               */
#define MAIN_EVENTSBCHARGER1SET_EVENTSUPPLEMENT_HIGH (1) /*!< high                                                             */

/* EVENTCHGTRICKLE @Bit 1 : Event Trickle Charge started.
          Writing 1 sets the event (for debugging). */
#define MAIN_EVENTSBCHARGER1SET_EVENTCHGTRICKLE_Pos (1UL) /*!< Position of EVENTCHGTRICKLE field.                              */
#define MAIN_EVENTSBCHARGER1SET_EVENTCHGTRICKLE_Msk (0x1UL << MAIN_EVENTSBCHARGER1SET_EVENTCHGTRICKLE_Pos) /*!< Bit mask of
                                                                            EVENTCHGTRICKLE field.*/                              
#define MAIN_EVENTSBCHARGER1SET_EVENTCHGTRICKLE_LOW (0) /*!< low                                                               */
#define MAIN_EVENTSBCHARGER1SET_EVENTCHGTRICKLE_HIGH (1) /*!< high                                                             */

/* EVENTCHGCC @Bit 2 : Event Constant Current charging started.
          Writing 1 sets the event (for debugging). */
#define MAIN_EVENTSBCHARGER1SET_EVENTCHGCC_Pos (2UL) /*!< Position of EVENTCHGCC field.                                        */
#define MAIN_EVENTSBCHARGER1SET_EVENTCHGCC_Msk (0x1UL << MAIN_EVENTSBCHARGER1SET_EVENTCHGCC_Pos) /*!< Bit mask of EVENTCHGCC
                                                                            field.*/                                              
#define MAIN_EVENTSBCHARGER1SET_EVENTCHGCC_LOW (0)   /*!< low                                                                  */
#define MAIN_EVENTSBCHARGER1SET_EVENTCHGCC_HIGH (1)  /*!< high                                                                 */

/* EVENTCHGCV @Bit 3 : Event Constant Voltage charging started.
          Writing 1 sets the event (for debugging). */
#define MAIN_EVENTSBCHARGER1SET_EVENTCHGCV_Pos (3UL) /*!< Position of EVENTCHGCV field.                                        */
#define MAIN_EVENTSBCHARGER1SET_EVENTCHGCV_Msk (0x1UL << MAIN_EVENTSBCHARGER1SET_EVENTCHGCV_Pos) /*!< Bit mask of EVENTCHGCV
                                                                            field.*/                                              
#define MAIN_EVENTSBCHARGER1SET_EVENTCHGCV_LOW (0)   /*!< low                                                                  */
#define MAIN_EVENTSBCHARGER1SET_EVENTCHGCV_HIGH (1)  /*!< high                                                                 */

/* EVENTCHGCOMPLETED @Bit 4 : Event charging completed (Battery Full).
          Writing 1 sets the event (for debugging). */
#define MAIN_EVENTSBCHARGER1SET_EVENTCHGCOMPLETED_Pos (4UL) /*!< Position of EVENTCHGCOMPLETED field.                          */
#define MAIN_EVENTSBCHARGER1SET_EVENTCHGCOMPLETED_Msk (0x1UL << MAIN_EVENTSBCHARGER1SET_EVENTCHGCOMPLETED_Pos) /*!< Bit mask of
                                                                            EVENTCHGCOMPLETED field.*/                            
#define MAIN_EVENTSBCHARGER1SET_EVENTCHGCOMPLETED_LOW (0) /*!< low                                                             */
#define MAIN_EVENTSBCHARGER1SET_EVENTCHGCOMPLETED_HIGH (1) /*!< high                                                           */

/* EVENTCHGERROR @Bit 5 : Event charging error.
          Writing 1 sets the event (for debugging). */
#define MAIN_EVENTSBCHARGER1SET_EVENTCHGERROR_Pos (5UL) /*!< Position of EVENTCHGERROR field.                                  */
#define MAIN_EVENTSBCHARGER1SET_EVENTCHGERROR_Msk (0x1UL << MAIN_EVENTSBCHARGER1SET_EVENTCHGERROR_Pos) /*!< Bit mask of
                                                                            EVENTCHGERROR field.*/                                
#define MAIN_EVENTSBCHARGER1SET_EVENTCHGERROR_LOW (0) /*!< low                                                                 */
#define MAIN_EVENTSBCHARGER1SET_EVENTCHGERROR_HIGH (1) /*!< high                                                               */


/* MAIN_EVENTSBCHARGER1CLR: Battery Charger Status Events Event Clear */

/* EVENTSUPPLEMENT @Bit 0 : Event supplement mode activated.
          Writing 1 clears the event (e.g. to acknowledge an
                            interrupt). */                                                                                        
                                                                                                                                  
#define MAIN_EVENTSBCHARGER1CLR_EVENTSUPPLEMENT_Pos (0UL) /*!< Position of EVENTSUPPLEMENT field.                              */
#define MAIN_EVENTSBCHARGER1CLR_EVENTSUPPLEMENT_Msk (0x1UL << MAIN_EVENTSBCHARGER1CLR_EVENTSUPPLEMENT_Pos) /*!< Bit mask of
                                                                            EVENTSUPPLEMENT field.*/                              
#define MAIN_EVENTSBCHARGER1CLR_EVENTSUPPLEMENT_LOW (0) /*!< low                                                               */
#define MAIN_EVENTSBCHARGER1CLR_EVENTSUPPLEMENT_HIGH (1) /*!< high                                                             */

/* EVENTCHGTRICKLE @Bit 1 : Event Trickle Charge started.
          Writing 1 clears the event (e.g. to acknowledge an
                            interrupt). */                                                                                        
                                                                                                                                  
#define MAIN_EVENTSBCHARGER1CLR_EVENTCHGTRICKLE_Pos (1UL) /*!< Position of EVENTCHGTRICKLE field.                              */
#define MAIN_EVENTSBCHARGER1CLR_EVENTCHGTRICKLE_Msk (0x1UL << MAIN_EVENTSBCHARGER1CLR_EVENTCHGTRICKLE_Pos) /*!< Bit mask of
                                                                            EVENTCHGTRICKLE field.*/                              
#define MAIN_EVENTSBCHARGER1CLR_EVENTCHGTRICKLE_LOW (0) /*!< low                                                               */
#define MAIN_EVENTSBCHARGER1CLR_EVENTCHGTRICKLE_HIGH (1) /*!< high                                                             */

/* EVENTCHGCC @Bit 2 : Event Constant Current charging started.
          Writing 1 clears the event (e.g. to acknowledge an
                       interrupt). */                                                                                             
                                                                                                                                  
#define MAIN_EVENTSBCHARGER1CLR_EVENTCHGCC_Pos (2UL) /*!< Position of EVENTCHGCC field.                                        */
#define MAIN_EVENTSBCHARGER1CLR_EVENTCHGCC_Msk (0x1UL << MAIN_EVENTSBCHARGER1CLR_EVENTCHGCC_Pos) /*!< Bit mask of EVENTCHGCC
                                                                            field.*/                                              
#define MAIN_EVENTSBCHARGER1CLR_EVENTCHGCC_LOW (0)   /*!< low                                                                  */
#define MAIN_EVENTSBCHARGER1CLR_EVENTCHGCC_HIGH (1)  /*!< high                                                                 */

/* EVENTCHGCV @Bit 3 : Event Constant Voltage charging started.
          Writing 1 clears the event (e.g. to acknowledge an
                       interrupt). */                                                                                             
                                                                                                                                  
#define MAIN_EVENTSBCHARGER1CLR_EVENTCHGCV_Pos (3UL) /*!< Position of EVENTCHGCV field.                                        */
#define MAIN_EVENTSBCHARGER1CLR_EVENTCHGCV_Msk (0x1UL << MAIN_EVENTSBCHARGER1CLR_EVENTCHGCV_Pos) /*!< Bit mask of EVENTCHGCV
                                                                            field.*/                                              
#define MAIN_EVENTSBCHARGER1CLR_EVENTCHGCV_LOW (0)   /*!< low                                                                  */
#define MAIN_EVENTSBCHARGER1CLR_EVENTCHGCV_HIGH (1)  /*!< high                                                                 */

/* EVENTCHGCOMPLETED @Bit 4 : Event charging completed (Battery Full).
          Writing 1 clears the event (e.g. to acknowledge
                              an interrupt). */                                                                                   
                                                                                                                                  
#define MAIN_EVENTSBCHARGER1CLR_EVENTCHGCOMPLETED_Pos (4UL) /*!< Position of EVENTCHGCOMPLETED field.                          */
#define MAIN_EVENTSBCHARGER1CLR_EVENTCHGCOMPLETED_Msk (0x1UL << MAIN_EVENTSBCHARGER1CLR_EVENTCHGCOMPLETED_Pos) /*!< Bit mask of
                                                                            EVENTCHGCOMPLETED field.*/                            
#define MAIN_EVENTSBCHARGER1CLR_EVENTCHGCOMPLETED_LOW (0) /*!< low                                                             */
#define MAIN_EVENTSBCHARGER1CLR_EVENTCHGCOMPLETED_HIGH (1) /*!< high                                                           */

/* EVENTCHGERROR @Bit 5 : Event charging error.
          Writing 1 clears the event (e.g. to acknowledge an interrupt). */
#define MAIN_EVENTSBCHARGER1CLR_EVENTCHGERROR_Pos (5UL) /*!< Position of EVENTCHGERROR field.                                  */
#define MAIN_EVENTSBCHARGER1CLR_EVENTCHGERROR_Msk (0x1UL << MAIN_EVENTSBCHARGER1CLR_EVENTCHGERROR_Pos) /*!< Bit mask of
                                                                            EVENTCHGERROR field.*/                                
#define MAIN_EVENTSBCHARGER1CLR_EVENTCHGERROR_LOW (0) /*!< low                                                                 */
#define MAIN_EVENTSBCHARGER1CLR_EVENTCHGERROR_HIGH (1) /*!< high                                                               */


/* MAIN_INTENEVENTSBCHARGER1SET: Battery Charger Status Events Interrupt Enable Set */

/* EVENTSUPPLEMENT @Bit 0 : Writing 1 enables interrupts from EVENTSUPPLEMENT */
#define MAIN_INTENEVENTSBCHARGER1SET_EVENTSUPPLEMENT_Pos (0UL) /*!< Position of EVENTSUPPLEMENT field.                         */
#define MAIN_INTENEVENTSBCHARGER1SET_EVENTSUPPLEMENT_Msk (0x1UL << MAIN_INTENEVENTSBCHARGER1SET_EVENTSUPPLEMENT_Pos) /*!< Bit
                                                                            mask of EVENTSUPPLEMENT field.*/                      
#define MAIN_INTENEVENTSBCHARGER1SET_EVENTSUPPLEMENT_LOW (0) /*!< low                                                          */
#define MAIN_INTENEVENTSBCHARGER1SET_EVENTSUPPLEMENT_HIGH (1) /*!< high                                                        */

/* EVENTCHGTRICKLE @Bit 1 : Writing 1 enables interrupts from EVENTCHGTRICKLE */
#define MAIN_INTENEVENTSBCHARGER1SET_EVENTCHGTRICKLE_Pos (1UL) /*!< Position of EVENTCHGTRICKLE field.                         */
#define MAIN_INTENEVENTSBCHARGER1SET_EVENTCHGTRICKLE_Msk (0x1UL << MAIN_INTENEVENTSBCHARGER1SET_EVENTCHGTRICKLE_Pos) /*!< Bit
                                                                            mask of EVENTCHGTRICKLE field.*/                      
#define MAIN_INTENEVENTSBCHARGER1SET_EVENTCHGTRICKLE_LOW (0) /*!< low                                                          */
#define MAIN_INTENEVENTSBCHARGER1SET_EVENTCHGTRICKLE_HIGH (1) /*!< high                                                        */

/* EVENTCHGCC @Bit 2 : Writing 1 enables interrupts from EVENTCHGCC */
#define MAIN_INTENEVENTSBCHARGER1SET_EVENTCHGCC_Pos (2UL) /*!< Position of EVENTCHGCC field.                                   */
#define MAIN_INTENEVENTSBCHARGER1SET_EVENTCHGCC_Msk (0x1UL << MAIN_INTENEVENTSBCHARGER1SET_EVENTCHGCC_Pos) /*!< Bit mask of
                                                                            EVENTCHGCC field.*/                                   
#define MAIN_INTENEVENTSBCHARGER1SET_EVENTCHGCC_LOW (0) /*!< low                                                               */
#define MAIN_INTENEVENTSBCHARGER1SET_EVENTCHGCC_HIGH (1) /*!< high                                                             */

/* EVENTCHGCV @Bit 3 : Writing 1 enables interrupts from EVENTCHGCV */
#define MAIN_INTENEVENTSBCHARGER1SET_EVENTCHGCV_Pos (3UL) /*!< Position of EVENTCHGCV field.                                   */
#define MAIN_INTENEVENTSBCHARGER1SET_EVENTCHGCV_Msk (0x1UL << MAIN_INTENEVENTSBCHARGER1SET_EVENTCHGCV_Pos) /*!< Bit mask of
                                                                            EVENTCHGCV field.*/                                   
#define MAIN_INTENEVENTSBCHARGER1SET_EVENTCHGCV_LOW (0) /*!< low                                                               */
#define MAIN_INTENEVENTSBCHARGER1SET_EVENTCHGCV_HIGH (1) /*!< high                                                             */

/* EVENTCHGCOMPLETED @Bit 4 : Writing 1 enables interrupts from EVENTCHGCOMPLETED */
#define MAIN_INTENEVENTSBCHARGER1SET_EVENTCHGCOMPLETED_Pos (4UL) /*!< Position of EVENTCHGCOMPLETED field.                     */
#define MAIN_INTENEVENTSBCHARGER1SET_EVENTCHGCOMPLETED_Msk (0x1UL << MAIN_INTENEVENTSBCHARGER1SET_EVENTCHGCOMPLETED_Pos) /*!<
                                                                            Bit mask of EVENTCHGCOMPLETED field.*/                
#define MAIN_INTENEVENTSBCHARGER1SET_EVENTCHGCOMPLETED_LOW (0) /*!< low                                                        */
#define MAIN_INTENEVENTSBCHARGER1SET_EVENTCHGCOMPLETED_HIGH (1) /*!< high                                                      */

/* EVENTCHGERROR @Bit 5 : Writing 1 enables interrupts from EVENTCHGERROR */
#define MAIN_INTENEVENTSBCHARGER1SET_EVENTCHGERROR_Pos (5UL) /*!< Position of EVENTCHGERROR field.                             */
#define MAIN_INTENEVENTSBCHARGER1SET_EVENTCHGERROR_Msk (0x1UL << MAIN_INTENEVENTSBCHARGER1SET_EVENTCHGERROR_Pos) /*!< Bit mask
                                                                            of EVENTCHGERROR field.*/                             
#define MAIN_INTENEVENTSBCHARGER1SET_EVENTCHGERROR_LOW (0) /*!< low                                                            */
#define MAIN_INTENEVENTSBCHARGER1SET_EVENTCHGERROR_HIGH (1) /*!< high                                                          */


/* MAIN_INTENEVENTSBCHARGER1CLR: Battery Charger Status Events Interrupt Enable Clear */

/* EVENTSUPPLEMENT @Bit 0 : Writing 1 disables interrupts from EVENTSUPPLEMENT */
#define MAIN_INTENEVENTSBCHARGER1CLR_EVENTSUPPLEMENT_Pos (0UL) /*!< Position of EVENTSUPPLEMENT field.                         */
#define MAIN_INTENEVENTSBCHARGER1CLR_EVENTSUPPLEMENT_Msk (0x1UL << MAIN_INTENEVENTSBCHARGER1CLR_EVENTSUPPLEMENT_Pos) /*!< Bit
                                                                            mask of EVENTSUPPLEMENT field.*/                      
#define MAIN_INTENEVENTSBCHARGER1CLR_EVENTSUPPLEMENT_LOW (0) /*!< low                                                          */
#define MAIN_INTENEVENTSBCHARGER1CLR_EVENTSUPPLEMENT_HIGH (1) /*!< high                                                        */

/* EVENTCHGTRICKLE @Bit 1 : Writing 1 disables interrupts from EVENTCHGTRICKLE */
#define MAIN_INTENEVENTSBCHARGER1CLR_EVENTCHGTRICKLE_Pos (1UL) /*!< Position of EVENTCHGTRICKLE field.                         */
#define MAIN_INTENEVENTSBCHARGER1CLR_EVENTCHGTRICKLE_Msk (0x1UL << MAIN_INTENEVENTSBCHARGER1CLR_EVENTCHGTRICKLE_Pos) /*!< Bit
                                                                            mask of EVENTCHGTRICKLE field.*/                      
#define MAIN_INTENEVENTSBCHARGER1CLR_EVENTCHGTRICKLE_LOW (0) /*!< low                                                          */
#define MAIN_INTENEVENTSBCHARGER1CLR_EVENTCHGTRICKLE_HIGH (1) /*!< high                                                        */

/* EVENTCHGCC @Bit 2 : Writing 1 disables interrupts from EVENTCHGCC */
#define MAIN_INTENEVENTSBCHARGER1CLR_EVENTCHGCC_Pos (2UL) /*!< Position of EVENTCHGCC field.                                   */
#define MAIN_INTENEVENTSBCHARGER1CLR_EVENTCHGCC_Msk (0x1UL << MAIN_INTENEVENTSBCHARGER1CLR_EVENTCHGCC_Pos) /*!< Bit mask of
                                                                            EVENTCHGCC field.*/                                   
#define MAIN_INTENEVENTSBCHARGER1CLR_EVENTCHGCC_LOW (0) /*!< low                                                               */
#define MAIN_INTENEVENTSBCHARGER1CLR_EVENTCHGCC_HIGH (1) /*!< high                                                             */

/* EVENTCHGCV @Bit 3 : Writing 1 disables interrupts from EVENTCHGCV */
#define MAIN_INTENEVENTSBCHARGER1CLR_EVENTCHGCV_Pos (3UL) /*!< Position of EVENTCHGCV field.                                   */
#define MAIN_INTENEVENTSBCHARGER1CLR_EVENTCHGCV_Msk (0x1UL << MAIN_INTENEVENTSBCHARGER1CLR_EVENTCHGCV_Pos) /*!< Bit mask of
                                                                            EVENTCHGCV field.*/                                   
#define MAIN_INTENEVENTSBCHARGER1CLR_EVENTCHGCV_LOW (0) /*!< low                                                               */
#define MAIN_INTENEVENTSBCHARGER1CLR_EVENTCHGCV_HIGH (1) /*!< high                                                             */

/* EVENTCHGCOMPLETED @Bit 4 : Writing 1 disables interrupts from EVENTCHGCOMPLETED */
#define MAIN_INTENEVENTSBCHARGER1CLR_EVENTCHGCOMPLETED_Pos (4UL) /*!< Position of EVENTCHGCOMPLETED field.                     */
#define MAIN_INTENEVENTSBCHARGER1CLR_EVENTCHGCOMPLETED_Msk (0x1UL << MAIN_INTENEVENTSBCHARGER1CLR_EVENTCHGCOMPLETED_Pos) /*!<
                                                                            Bit mask of EVENTCHGCOMPLETED field.*/                
#define MAIN_INTENEVENTSBCHARGER1CLR_EVENTCHGCOMPLETED_LOW (0) /*!< low                                                        */
#define MAIN_INTENEVENTSBCHARGER1CLR_EVENTCHGCOMPLETED_HIGH (1) /*!< high                                                      */

/* EVENTCHGERROR @Bit 5 : Writing 1 disables interrupts from EVENTCHGERROR */
#define MAIN_INTENEVENTSBCHARGER1CLR_EVENTCHGERROR_Pos (5UL) /*!< Position of EVENTCHGERROR field.                             */
#define MAIN_INTENEVENTSBCHARGER1CLR_EVENTCHGERROR_Msk (0x1UL << MAIN_INTENEVENTSBCHARGER1CLR_EVENTCHGERROR_Pos) /*!< Bit mask
                                                                            of EVENTCHGERROR field.*/                             
#define MAIN_INTENEVENTSBCHARGER1CLR_EVENTCHGERROR_LOW (0) /*!< low                                                            */
#define MAIN_INTENEVENTSBCHARGER1CLR_EVENTCHGERROR_HIGH (1) /*!< high                                                          */


/* MAIN_EVENTSBCHARGER2SET: Battery Charger Battery Events Event Set */

/* EVENTBATDETECTED @Bit 0 : Event Battery Detected.
          Writing 1 sets the event (for debugging). */
#define MAIN_EVENTSBCHARGER2SET_EVENTBATDETECTED_Pos (0UL) /*!< Position of EVENTBATDETECTED field.                            */
#define MAIN_EVENTSBCHARGER2SET_EVENTBATDETECTED_Msk (0x1UL << MAIN_EVENTSBCHARGER2SET_EVENTBATDETECTED_Pos) /*!< Bit mask of
                                                                            EVENTBATDETECTED field.*/                             
#define MAIN_EVENTSBCHARGER2SET_EVENTBATDETECTED_LOW (0) /*!< low                                                              */
#define MAIN_EVENTSBCHARGER2SET_EVENTBATDETECTED_HIGH (1) /*!< high                                                            */

/* EVENTBATLOST @Bit 1 : Event Battery Lost.
          Writing 1 sets the event (for debugging). */
#define MAIN_EVENTSBCHARGER2SET_EVENTBATLOST_Pos (1UL) /*!< Position of EVENTBATLOST field.                                    */
#define MAIN_EVENTSBCHARGER2SET_EVENTBATLOST_Msk (0x1UL << MAIN_EVENTSBCHARGER2SET_EVENTBATLOST_Pos) /*!< Bit mask of
                                                                            EVENTBATLOST field.*/                                 
#define MAIN_EVENTSBCHARGER2SET_EVENTBATLOST_LOW (0) /*!< low                                                                  */
#define MAIN_EVENTSBCHARGER2SET_EVENTBATLOST_HIGH (1) /*!< high                                                                */

/* EVENTBATRECHARGE @Bit 2 : Event Battery re-charge needed.
          Writing 1 sets the event (for debugging). */
#define MAIN_EVENTSBCHARGER2SET_EVENTBATRECHARGE_Pos (2UL) /*!< Position of EVENTBATRECHARGE field.                            */
#define MAIN_EVENTSBCHARGER2SET_EVENTBATRECHARGE_Msk (0x1UL << MAIN_EVENTSBCHARGER2SET_EVENTBATRECHARGE_Pos) /*!< Bit mask of
                                                                            EVENTBATRECHARGE field.*/                             
#define MAIN_EVENTSBCHARGER2SET_EVENTBATRECHARGE_LOW (0) /*!< low                                                              */
#define MAIN_EVENTSBCHARGER2SET_EVENTBATRECHARGE_HIGH (1) /*!< high                                                            */


/* MAIN_EVENTSBCHARGER2CLR: Battery Charger Battery Events Event Clear */

/* EVENTBATDETECTED @Bit 0 : Event Battery Detected.
          Writing 1 clears the event (e.g. to acknowledge an interrupt). */
#define MAIN_EVENTSBCHARGER2CLR_EVENTBATDETECTED_Pos (0UL) /*!< Position of EVENTBATDETECTED field.                            */
#define MAIN_EVENTSBCHARGER2CLR_EVENTBATDETECTED_Msk (0x1UL << MAIN_EVENTSBCHARGER2CLR_EVENTBATDETECTED_Pos) /*!< Bit mask of
                                                                            EVENTBATDETECTED field.*/                             
#define MAIN_EVENTSBCHARGER2CLR_EVENTBATDETECTED_LOW (0) /*!< low                                                              */
#define MAIN_EVENTSBCHARGER2CLR_EVENTBATDETECTED_HIGH (1) /*!< high                                                            */

/* EVENTBATLOST @Bit 1 : Event Battery Lost.
          Writing 1 clears the event (e.g. to acknowledge an interrupt). */
#define MAIN_EVENTSBCHARGER2CLR_EVENTBATLOST_Pos (1UL) /*!< Position of EVENTBATLOST field.                                    */
#define MAIN_EVENTSBCHARGER2CLR_EVENTBATLOST_Msk (0x1UL << MAIN_EVENTSBCHARGER2CLR_EVENTBATLOST_Pos) /*!< Bit mask of
                                                                            EVENTBATLOST field.*/                                 
#define MAIN_EVENTSBCHARGER2CLR_EVENTBATLOST_LOW (0) /*!< low                                                                  */
#define MAIN_EVENTSBCHARGER2CLR_EVENTBATLOST_HIGH (1) /*!< high                                                                */

/* EVENTBATRECHARGE @Bit 2 : Event Battery re-charge needed.
          Writing 1 clears the event (e.g. to acknowledge an
                             interrupt). */                                                                                       
                                                                                                                                  
#define MAIN_EVENTSBCHARGER2CLR_EVENTBATRECHARGE_Pos (2UL) /*!< Position of EVENTBATRECHARGE field.                            */
#define MAIN_EVENTSBCHARGER2CLR_EVENTBATRECHARGE_Msk (0x1UL << MAIN_EVENTSBCHARGER2CLR_EVENTBATRECHARGE_Pos) /*!< Bit mask of
                                                                            EVENTBATRECHARGE field.*/                             
#define MAIN_EVENTSBCHARGER2CLR_EVENTBATRECHARGE_LOW (0) /*!< low                                                              */
#define MAIN_EVENTSBCHARGER2CLR_EVENTBATRECHARGE_HIGH (1) /*!< high                                                            */


/* MAIN_INTENEVENTSBCHARGER2SET: Battery Charger Battery Events Interrupt Enable Set */

/* EVENTBATDETECTED @Bit 0 : Writing 1 enables interrupts from EVENTBATDETECTED */
#define MAIN_INTENEVENTSBCHARGER2SET_EVENTBATDETECTED_Pos (0UL) /*!< Position of EVENTBATDETECTED field.                       */
#define MAIN_INTENEVENTSBCHARGER2SET_EVENTBATDETECTED_Msk (0x1UL << MAIN_INTENEVENTSBCHARGER2SET_EVENTBATDETECTED_Pos) /*!< Bit
                                                                            mask of EVENTBATDETECTED field.*/                     
#define MAIN_INTENEVENTSBCHARGER2SET_EVENTBATDETECTED_LOW (0) /*!< low                                                         */
#define MAIN_INTENEVENTSBCHARGER2SET_EVENTBATDETECTED_HIGH (1) /*!< high                                                       */

/* EVENTBATLOST @Bit 1 : Writing 1 enables interrupts from EVENTBATLOST */
#define MAIN_INTENEVENTSBCHARGER2SET_EVENTBATLOST_Pos (1UL) /*!< Position of EVENTBATLOST field.                               */
#define MAIN_INTENEVENTSBCHARGER2SET_EVENTBATLOST_Msk (0x1UL << MAIN_INTENEVENTSBCHARGER2SET_EVENTBATLOST_Pos) /*!< Bit mask of
                                                                            EVENTBATLOST field.*/                                 
#define MAIN_INTENEVENTSBCHARGER2SET_EVENTBATLOST_LOW (0) /*!< low                                                             */
#define MAIN_INTENEVENTSBCHARGER2SET_EVENTBATLOST_HIGH (1) /*!< high                                                           */

/* EVENTBATRECHARGE @Bit 2 : Writing 1 enables interrupts from EVENTBATRECHARGE */
#define MAIN_INTENEVENTSBCHARGER2SET_EVENTBATRECHARGE_Pos (2UL) /*!< Position of EVENTBATRECHARGE field.                       */
#define MAIN_INTENEVENTSBCHARGER2SET_EVENTBATRECHARGE_Msk (0x1UL << MAIN_INTENEVENTSBCHARGER2SET_EVENTBATRECHARGE_Pos) /*!< Bit
                                                                            mask of EVENTBATRECHARGE field.*/                     
#define MAIN_INTENEVENTSBCHARGER2SET_EVENTBATRECHARGE_LOW (0) /*!< low                                                         */
#define MAIN_INTENEVENTSBCHARGER2SET_EVENTBATRECHARGE_HIGH (1) /*!< high                                                       */


/* MAIN_INTENEVENTSBCHARGER2CLR: Battery Charger Battery Events Interrupt Enable Clear */

/* EVENTBATDETECTED @Bit 0 : Writing 1 disables interrupts from EVENTBATDETECTED */
#define MAIN_INTENEVENTSBCHARGER2CLR_EVENTBATDETECTED_Pos (0UL) /*!< Position of EVENTBATDETECTED field.                       */
#define MAIN_INTENEVENTSBCHARGER2CLR_EVENTBATDETECTED_Msk (0x1UL << MAIN_INTENEVENTSBCHARGER2CLR_EVENTBATDETECTED_Pos) /*!< Bit
                                                                            mask of EVENTBATDETECTED field.*/                     
#define MAIN_INTENEVENTSBCHARGER2CLR_EVENTBATDETECTED_LOW (0) /*!< low                                                         */
#define MAIN_INTENEVENTSBCHARGER2CLR_EVENTBATDETECTED_HIGH (1) /*!< high                                                       */

/* EVENTBATLOST @Bit 1 : Writing 1 disables interrupts from EVENTBATLOST */
#define MAIN_INTENEVENTSBCHARGER2CLR_EVENTBATLOST_Pos (1UL) /*!< Position of EVENTBATLOST field.                               */
#define MAIN_INTENEVENTSBCHARGER2CLR_EVENTBATLOST_Msk (0x1UL << MAIN_INTENEVENTSBCHARGER2CLR_EVENTBATLOST_Pos) /*!< Bit mask of
                                                                            EVENTBATLOST field.*/                                 
#define MAIN_INTENEVENTSBCHARGER2CLR_EVENTBATLOST_LOW (0) /*!< low                                                             */
#define MAIN_INTENEVENTSBCHARGER2CLR_EVENTBATLOST_HIGH (1) /*!< high                                                           */

/* EVENTBATRECHARGE @Bit 2 : Writing 1 disables interrupts from EVENTBATRECHARGE */
#define MAIN_INTENEVENTSBCHARGER2CLR_EVENTBATRECHARGE_Pos (2UL) /*!< Position of EVENTBATRECHARGE field.                       */
#define MAIN_INTENEVENTSBCHARGER2CLR_EVENTBATRECHARGE_Msk (0x1UL << MAIN_INTENEVENTSBCHARGER2CLR_EVENTBATRECHARGE_Pos) /*!< Bit
                                                                            mask of EVENTBATRECHARGE field.*/                     
#define MAIN_INTENEVENTSBCHARGER2CLR_EVENTBATRECHARGE_LOW (0) /*!< low                                                         */
#define MAIN_INTENEVENTSBCHARGER2CLR_EVENTBATRECHARGE_HIGH (1) /*!< high                                                       */


/* MAIN_EVENTSSHPHLDSET: ShipHold pin Events Event Set */

/* EVENTSHPHLDBTNPRESS @Bit 0 : Event when Ship-Hold button is pressed.
          Writing 1 sets the event (for debugging). */
#define MAIN_EVENTSSHPHLDSET_EVENTSHPHLDBTNPRESS_Pos (0UL) /*!< Position of EVENTSHPHLDBTNPRESS field.                         */
#define MAIN_EVENTSSHPHLDSET_EVENTSHPHLDBTNPRESS_Msk (0x1UL << MAIN_EVENTSSHPHLDSET_EVENTSHPHLDBTNPRESS_Pos) /*!< Bit mask of
                                                                            EVENTSHPHLDBTNPRESS field.*/                          
#define MAIN_EVENTSSHPHLDSET_EVENTSHPHLDBTNPRESS_LOW (0) /*!< low                                                              */
#define MAIN_EVENTSSHPHLDSET_EVENTSHPHLDBTNPRESS_HIGH (1) /*!< high                                                            */

/* EVENTSHPHLDBTNRELEASE @Bit 1 : Event when Ship-Hold button is Released.
          Writing 1 sets the event (for debugging). */
#define MAIN_EVENTSSHPHLDSET_EVENTSHPHLDBTNRELEASE_Pos (1UL) /*!< Position of EVENTSHPHLDBTNRELEASE field.                     */
#define MAIN_EVENTSSHPHLDSET_EVENTSHPHLDBTNRELEASE_Msk (0x1UL << MAIN_EVENTSSHPHLDSET_EVENTSHPHLDBTNRELEASE_Pos) /*!< Bit mask
                                                                            of EVENTSHPHLDBTNRELEASE field.*/                     
#define MAIN_EVENTSSHPHLDSET_EVENTSHPHLDBTNRELEASE_LOW (0) /*!< low                                                            */
#define MAIN_EVENTSSHPHLDSET_EVENTSHPHLDBTNRELEASE_HIGH (1) /*!< high                                                          */

/* EVENTSHPHLDEXIT @Bit 2 : Event when Ship-Hold button held to Exit.
          Writing 1 sets the event (for debugging). */
#define MAIN_EVENTSSHPHLDSET_EVENTSHPHLDEXIT_Pos (2UL) /*!< Position of EVENTSHPHLDEXIT field.                                 */
#define MAIN_EVENTSSHPHLDSET_EVENTSHPHLDEXIT_Msk (0x1UL << MAIN_EVENTSSHPHLDSET_EVENTSHPHLDEXIT_Pos) /*!< Bit mask of
                                                                            EVENTSHPHLDEXIT field.*/                              
#define MAIN_EVENTSSHPHLDSET_EVENTSHPHLDEXIT_LOW (0) /*!< low                                                                  */
#define MAIN_EVENTSSHPHLDSET_EVENTSHPHLDEXIT_HIGH (1) /*!< high                                                                */

/* EVENTWATCHDOGWARN @Bit 3 : Event when Watchdog Timeout Warning detected.
          Writing 1 sets the event (for debugging).
                              */                                                                                                  
                                                                                                                                  
#define MAIN_EVENTSSHPHLDSET_EVENTWATCHDOGWARN_Pos (3UL) /*!< Position of EVENTWATCHDOGWARN field.                             */
#define MAIN_EVENTSSHPHLDSET_EVENTWATCHDOGWARN_Msk (0x1UL << MAIN_EVENTSSHPHLDSET_EVENTWATCHDOGWARN_Pos) /*!< Bit mask of
                                                                            EVENTWATCHDOGWARN field.*/                            
#define MAIN_EVENTSSHPHLDSET_EVENTWATCHDOGWARN_LOW (0) /*!< low                                                                */
#define MAIN_EVENTSSHPHLDSET_EVENTWATCHDOGWARN_HIGH (1) /*!< high                                                              */


/* MAIN_EVENTSSHPHLDCLR: ShipHold pin Events Event Clear */

/* EVENTSHPHLDBTNPRESS @Bit 0 : Event when Ship-Hold button is pressed.
          Writing 1 clears the event (e.g. to
                                acknowledge an interrupt). */                                                                     
                                                                                                                                  
#define MAIN_EVENTSSHPHLDCLR_EVENTSHPHLDBTNPRESS_Pos (0UL) /*!< Position of EVENTSHPHLDBTNPRESS field.                         */
#define MAIN_EVENTSSHPHLDCLR_EVENTSHPHLDBTNPRESS_Msk (0x1UL << MAIN_EVENTSSHPHLDCLR_EVENTSHPHLDBTNPRESS_Pos) /*!< Bit mask of
                                                                            EVENTSHPHLDBTNPRESS field.*/                          
#define MAIN_EVENTSSHPHLDCLR_EVENTSHPHLDBTNPRESS_LOW (0) /*!< low                                                              */
#define MAIN_EVENTSSHPHLDCLR_EVENTSHPHLDBTNPRESS_HIGH (1) /*!< high                                                            */

/* EVENTSHPHLDBTNRELEASE @Bit 1 : Event when Ship-Hold button is Released.
          Writing 1 clears the event (e.g. to
                                  acknowledge an interrupt). */                                                                   
                                                                                                                                  
#define MAIN_EVENTSSHPHLDCLR_EVENTSHPHLDBTNRELEASE_Pos (1UL) /*!< Position of EVENTSHPHLDBTNRELEASE field.                     */
#define MAIN_EVENTSSHPHLDCLR_EVENTSHPHLDBTNRELEASE_Msk (0x1UL << MAIN_EVENTSSHPHLDCLR_EVENTSHPHLDBTNRELEASE_Pos) /*!< Bit mask
                                                                            of EVENTSHPHLDBTNRELEASE field.*/                     
#define MAIN_EVENTSSHPHLDCLR_EVENTSHPHLDBTNRELEASE_LOW (0) /*!< low                                                            */
#define MAIN_EVENTSSHPHLDCLR_EVENTSHPHLDBTNRELEASE_HIGH (1) /*!< high                                                          */

/* EVENTSHPHLDEXIT @Bit 2 : Event when Ship-Hold button held to Exit.
          Writing 1 clears the event (e.g. to acknowledge
                            an interrupt). */                                                                                     
                                                                                                                                  
#define MAIN_EVENTSSHPHLDCLR_EVENTSHPHLDEXIT_Pos (2UL) /*!< Position of EVENTSHPHLDEXIT field.                                 */
#define MAIN_EVENTSSHPHLDCLR_EVENTSHPHLDEXIT_Msk (0x1UL << MAIN_EVENTSSHPHLDCLR_EVENTSHPHLDEXIT_Pos) /*!< Bit mask of
                                                                            EVENTSHPHLDEXIT field.*/                              
#define MAIN_EVENTSSHPHLDCLR_EVENTSHPHLDEXIT_LOW (0) /*!< low                                                                  */
#define MAIN_EVENTSSHPHLDCLR_EVENTSHPHLDEXIT_HIGH (1) /*!< high                                                                */

/* EVENTWATCHDOGWARN @Bit 3 : Event when Watchdog Timeout Warning detected.
          Writing 1 clears the event (e.g. to
                              acknowledge an interrupt). */                                                                       
                                                                                                                                  
#define MAIN_EVENTSSHPHLDCLR_EVENTWATCHDOGWARN_Pos (3UL) /*!< Position of EVENTWATCHDOGWARN field.                             */
#define MAIN_EVENTSSHPHLDCLR_EVENTWATCHDOGWARN_Msk (0x1UL << MAIN_EVENTSSHPHLDCLR_EVENTWATCHDOGWARN_Pos) /*!< Bit mask of
                                                                            EVENTWATCHDOGWARN field.*/                            
#define MAIN_EVENTSSHPHLDCLR_EVENTWATCHDOGWARN_LOW (0) /*!< low                                                                */
#define MAIN_EVENTSSHPHLDCLR_EVENTWATCHDOGWARN_HIGH (1) /*!< high                                                              */


/* MAIN_INTENEVENTSSHPHLDSET: ShipHold pin Events Interrupt Enable Set */

/* EVENTSHPHLDBTNPRESS @Bit 0 : Writing 1 enables interrupts from EVENTSHPHLDBTNPRESS */
#define MAIN_INTENEVENTSSHPHLDSET_EVENTSHPHLDBTNPRESS_Pos (0UL) /*!< Position of EVENTSHPHLDBTNPRESS field.                    */
#define MAIN_INTENEVENTSSHPHLDSET_EVENTSHPHLDBTNPRESS_Msk (0x1UL << MAIN_INTENEVENTSSHPHLDSET_EVENTSHPHLDBTNPRESS_Pos) /*!< Bit
                                                                            mask of EVENTSHPHLDBTNPRESS field.*/                  
#define MAIN_INTENEVENTSSHPHLDSET_EVENTSHPHLDBTNPRESS_LOW (0) /*!< low                                                         */
#define MAIN_INTENEVENTSSHPHLDSET_EVENTSHPHLDBTNPRESS_HIGH (1) /*!< high                                                       */

/* EVENTSHPHLDBTNRELEASE @Bit 1 : Writing 1 enables interrupts from EVENTSHPHLDBTNRELEASE */
#define MAIN_INTENEVENTSSHPHLDSET_EVENTSHPHLDBTNRELEASE_Pos (1UL) /*!< Position of EVENTSHPHLDBTNRELEASE field.                */
#define MAIN_INTENEVENTSSHPHLDSET_EVENTSHPHLDBTNRELEASE_Msk (0x1UL << MAIN_INTENEVENTSSHPHLDSET_EVENTSHPHLDBTNRELEASE_Pos) /*!<
                                                                            Bit mask of EVENTSHPHLDBTNRELEASE field.*/            
#define MAIN_INTENEVENTSSHPHLDSET_EVENTSHPHLDBTNRELEASE_LOW (0) /*!< low                                                       */
#define MAIN_INTENEVENTSSHPHLDSET_EVENTSHPHLDBTNRELEASE_HIGH (1) /*!< high                                                     */

/* EVENTSHPHLDEXIT @Bit 2 : Writing 1 enables interrupts from EVENTSHPHLDEXIT */
#define MAIN_INTENEVENTSSHPHLDSET_EVENTSHPHLDEXIT_Pos (2UL) /*!< Position of EVENTSHPHLDEXIT field.                            */
#define MAIN_INTENEVENTSSHPHLDSET_EVENTSHPHLDEXIT_Msk (0x1UL << MAIN_INTENEVENTSSHPHLDSET_EVENTSHPHLDEXIT_Pos) /*!< Bit mask of
                                                                            EVENTSHPHLDEXIT field.*/                              
#define MAIN_INTENEVENTSSHPHLDSET_EVENTSHPHLDEXIT_LOW (0) /*!< low                                                             */
#define MAIN_INTENEVENTSSHPHLDSET_EVENTSHPHLDEXIT_HIGH (1) /*!< high                                                           */

/* EVENTWATCHDOGWARN @Bit 3 : Writing 1 enables interrupts from EVENTWATCHDOGWARN */
#define MAIN_INTENEVENTSSHPHLDSET_EVENTWATCHDOGWARN_Pos (3UL) /*!< Position of EVENTWATCHDOGWARN field.                        */
#define MAIN_INTENEVENTSSHPHLDSET_EVENTWATCHDOGWARN_Msk (0x1UL << MAIN_INTENEVENTSSHPHLDSET_EVENTWATCHDOGWARN_Pos) /*!< Bit mask
                                                                            of EVENTWATCHDOGWARN field.*/                         
#define MAIN_INTENEVENTSSHPHLDSET_EVENTWATCHDOGWARN_LOW (0) /*!< low                                                           */
#define MAIN_INTENEVENTSSHPHLDSET_EVENTWATCHDOGWARN_HIGH (1) /*!< high                                                         */


/* MAIN_INTENEVENTSSHPHLDCLR: ShipHold pin Events Interrupt Enable Clear */

/* EVENTSHPHLDBTNPRESS @Bit 0 : Writing 1 disables interrupts from EVENTSHPHLDBTNPRESS */
#define MAIN_INTENEVENTSSHPHLDCLR_EVENTSHPHLDBTNPRESS_Pos (0UL) /*!< Position of EVENTSHPHLDBTNPRESS field.                    */
#define MAIN_INTENEVENTSSHPHLDCLR_EVENTSHPHLDBTNPRESS_Msk (0x1UL << MAIN_INTENEVENTSSHPHLDCLR_EVENTSHPHLDBTNPRESS_Pos) /*!< Bit
                                                                            mask of EVENTSHPHLDBTNPRESS field.*/                  
#define MAIN_INTENEVENTSSHPHLDCLR_EVENTSHPHLDBTNPRESS_LOW (0) /*!< low                                                         */
#define MAIN_INTENEVENTSSHPHLDCLR_EVENTSHPHLDBTNPRESS_HIGH (1) /*!< high                                                       */

/* EVENTSHPHLDBTNRELEASE @Bit 1 : Writing 1 disables interrupts from EVENTSHPHLDBTNRELEASE */
#define MAIN_INTENEVENTSSHPHLDCLR_EVENTSHPHLDBTNRELEASE_Pos (1UL) /*!< Position of EVENTSHPHLDBTNRELEASE field.                */
#define MAIN_INTENEVENTSSHPHLDCLR_EVENTSHPHLDBTNRELEASE_Msk (0x1UL << MAIN_INTENEVENTSSHPHLDCLR_EVENTSHPHLDBTNRELEASE_Pos) /*!<
                                                                            Bit mask of EVENTSHPHLDBTNRELEASE field.*/            
#define MAIN_INTENEVENTSSHPHLDCLR_EVENTSHPHLDBTNRELEASE_LOW (0) /*!< low                                                       */
#define MAIN_INTENEVENTSSHPHLDCLR_EVENTSHPHLDBTNRELEASE_HIGH (1) /*!< high                                                     */

/* EVENTSHPHLDEXIT @Bit 2 : Writing 1 disables interrupts from EVENTSHPHLDEXIT */
#define MAIN_INTENEVENTSSHPHLDCLR_EVENTSHPHLDEXIT_Pos (2UL) /*!< Position of EVENTSHPHLDEXIT field.                            */
#define MAIN_INTENEVENTSSHPHLDCLR_EVENTSHPHLDEXIT_Msk (0x1UL << MAIN_INTENEVENTSSHPHLDCLR_EVENTSHPHLDEXIT_Pos) /*!< Bit mask of
                                                                            EVENTSHPHLDEXIT field.*/                              
#define MAIN_INTENEVENTSSHPHLDCLR_EVENTSHPHLDEXIT_LOW (0) /*!< low                                                             */
#define MAIN_INTENEVENTSSHPHLDCLR_EVENTSHPHLDEXIT_HIGH (1) /*!< high                                                           */

/* EVENTWATCHDOGWARN @Bit 3 : Writing 1 disables interrupts from EVENTWATCHDOGWARN */
#define MAIN_INTENEVENTSSHPHLDCLR_EVENTWATCHDOGWARN_Pos (3UL) /*!< Position of EVENTWATCHDOGWARN field.                        */
#define MAIN_INTENEVENTSSHPHLDCLR_EVENTWATCHDOGWARN_Msk (0x1UL << MAIN_INTENEVENTSSHPHLDCLR_EVENTWATCHDOGWARN_Pos) /*!< Bit mask
                                                                            of EVENTWATCHDOGWARN field.*/                         
#define MAIN_INTENEVENTSSHPHLDCLR_EVENTWATCHDOGWARN_LOW (0) /*!< low                                                           */
#define MAIN_INTENEVENTSSHPHLDCLR_EVENTWATCHDOGWARN_HIGH (1) /*!< high                                                         */


/* MAIN_EVENTSVBUSIN0SET: VBUSIN Voltage Detection Events Event Set */

/* EVENTVBUSDETECTED @Bit 0 : Event VBUS input detected.
          Writing 1 sets the event (for debugging). */
#define MAIN_EVENTSVBUSIN0SET_EVENTVBUSDETECTED_Pos (0UL) /*!< Position of EVENTVBUSDETECTED field.                            */
#define MAIN_EVENTSVBUSIN0SET_EVENTVBUSDETECTED_Msk (0x1UL << MAIN_EVENTSVBUSIN0SET_EVENTVBUSDETECTED_Pos) /*!< Bit mask of
                                                                            EVENTVBUSDETECTED field.*/                            
#define MAIN_EVENTSVBUSIN0SET_EVENTVBUSDETECTED_LOW (0) /*!< low                                                               */
#define MAIN_EVENTSVBUSIN0SET_EVENTVBUSDETECTED_HIGH (1) /*!< high                                                             */

/* EVENTVBUSREMOVED @Bit 1 : Event VBUS input removed.
          Writing 1 sets the event (for debugging). */
#define MAIN_EVENTSVBUSIN0SET_EVENTVBUSREMOVED_Pos (1UL) /*!< Position of EVENTVBUSREMOVED field.                              */
#define MAIN_EVENTSVBUSIN0SET_EVENTVBUSREMOVED_Msk (0x1UL << MAIN_EVENTSVBUSIN0SET_EVENTVBUSREMOVED_Pos) /*!< Bit mask of
                                                                            EVENTVBUSREMOVED field.*/                             
#define MAIN_EVENTSVBUSIN0SET_EVENTVBUSREMOVED_LOW (0) /*!< low                                                                */
#define MAIN_EVENTSVBUSIN0SET_EVENTVBUSREMOVED_HIGH (1) /*!< high                                                              */

/* EVENTVBUSOVRVOLTDETECTED @Bit 2 : Event VBUS Over Voltage Detected.
          Writing 1 sets the event (for debugging). */
#define MAIN_EVENTSVBUSIN0SET_EVENTVBUSOVRVOLTDETECTED_Pos (2UL) /*!< Position of EVENTVBUSOVRVOLTDETECTED field.              */
#define MAIN_EVENTSVBUSIN0SET_EVENTVBUSOVRVOLTDETECTED_Msk (0x1UL << MAIN_EVENTSVBUSIN0SET_EVENTVBUSOVRVOLTDETECTED_Pos) /*!<
                                                                            Bit mask of EVENTVBUSOVRVOLTDETECTED field.*/         
#define MAIN_EVENTSVBUSIN0SET_EVENTVBUSOVRVOLTDETECTED_LOW (0) /*!< low                                                        */
#define MAIN_EVENTSVBUSIN0SET_EVENTVBUSOVRVOLTDETECTED_HIGH (1) /*!< high                                                      */

/* EVENTVBUSOVRVOLTREMOVED @Bit 3 : Event VBUS Over Removed.
          Writing 1 sets the event (for debugging). */
#define MAIN_EVENTSVBUSIN0SET_EVENTVBUSOVRVOLTREMOVED_Pos (3UL) /*!< Position of EVENTVBUSOVRVOLTREMOVED field.                */
#define MAIN_EVENTSVBUSIN0SET_EVENTVBUSOVRVOLTREMOVED_Msk (0x1UL << MAIN_EVENTSVBUSIN0SET_EVENTVBUSOVRVOLTREMOVED_Pos) /*!< Bit
                                                                            mask of EVENTVBUSOVRVOLTREMOVED field.*/              
#define MAIN_EVENTSVBUSIN0SET_EVENTVBUSOVRVOLTREMOVED_LOW (0) /*!< low                                                         */
#define MAIN_EVENTSVBUSIN0SET_EVENTVBUSOVRVOLTREMOVED_HIGH (1) /*!< high                                                       */

/* EVENTVBUSUNDVOLTDETECTED @Bit 4 : Event VBUS Under Voltage Detected.
          Writing 1 sets the event (for debugging). */
#define MAIN_EVENTSVBUSIN0SET_EVENTVBUSUNDVOLTDETECTED_Pos (4UL) /*!< Position of EVENTVBUSUNDVOLTDETECTED field.              */
#define MAIN_EVENTSVBUSIN0SET_EVENTVBUSUNDVOLTDETECTED_Msk (0x1UL << MAIN_EVENTSVBUSIN0SET_EVENTVBUSUNDVOLTDETECTED_Pos) /*!<
                                                                            Bit mask of EVENTVBUSUNDVOLTDETECTED field.*/         
#define MAIN_EVENTSVBUSIN0SET_EVENTVBUSUNDVOLTDETECTED_LOW (0) /*!< low                                                        */
#define MAIN_EVENTSVBUSIN0SET_EVENTVBUSUNDVOLTDETECTED_HIGH (1) /*!< high                                                      */

/* EVENTVBUSUNDVOLTREMOVED @Bit 5 : Event VBUS Under Removed.
          Writing 1 sets the event (for debugging). */
#define MAIN_EVENTSVBUSIN0SET_EVENTVBUSUNDVOLTREMOVED_Pos (5UL) /*!< Position of EVENTVBUSUNDVOLTREMOVED field.                */
#define MAIN_EVENTSVBUSIN0SET_EVENTVBUSUNDVOLTREMOVED_Msk (0x1UL << MAIN_EVENTSVBUSIN0SET_EVENTVBUSUNDVOLTREMOVED_Pos) /*!< Bit
                                                                            mask of EVENTVBUSUNDVOLTREMOVED field.*/              
#define MAIN_EVENTSVBUSIN0SET_EVENTVBUSUNDVOLTREMOVED_LOW (0) /*!< low                                                         */
#define MAIN_EVENTSVBUSIN0SET_EVENTVBUSUNDVOLTREMOVED_HIGH (1) /*!< high                                                       */


/* MAIN_EVENTSVBUSIN0CLR: VBUSIN Voltage Detection Events Event Clear */

/* EVENTVBUSDETECTED @Bit 0 : Event VBUS input detected.
          Writing 1 clears the event (e.g. to acknowledge an
                              interrupt). */                                                                                      
                                                                                                                                  
#define MAIN_EVENTSVBUSIN0CLR_EVENTVBUSDETECTED_Pos (0UL) /*!< Position of EVENTVBUSDETECTED field.                            */
#define MAIN_EVENTSVBUSIN0CLR_EVENTVBUSDETECTED_Msk (0x1UL << MAIN_EVENTSVBUSIN0CLR_EVENTVBUSDETECTED_Pos) /*!< Bit mask of
                                                                            EVENTVBUSDETECTED field.*/                            
#define MAIN_EVENTSVBUSIN0CLR_EVENTVBUSDETECTED_LOW (0) /*!< low                                                               */
#define MAIN_EVENTSVBUSIN0CLR_EVENTVBUSDETECTED_HIGH (1) /*!< high                                                             */

/* EVENTVBUSREMOVED @Bit 1 : Event VBUS input removed.
          Writing 1 clears the event (e.g. to acknowledge an interrupt).
                             */                                                                                                   
                                                                                                                                  
#define MAIN_EVENTSVBUSIN0CLR_EVENTVBUSREMOVED_Pos (1UL) /*!< Position of EVENTVBUSREMOVED field.                              */
#define MAIN_EVENTSVBUSIN0CLR_EVENTVBUSREMOVED_Msk (0x1UL << MAIN_EVENTSVBUSIN0CLR_EVENTVBUSREMOVED_Pos) /*!< Bit mask of
                                                                            EVENTVBUSREMOVED field.*/                             
#define MAIN_EVENTSVBUSIN0CLR_EVENTVBUSREMOVED_LOW (0) /*!< low                                                                */
#define MAIN_EVENTSVBUSIN0CLR_EVENTVBUSREMOVED_HIGH (1) /*!< high                                                              */

/* EVENTVBUSOVRVOLTDETECTED @Bit 2 : Event VBUS Over Voltage Detected.
          Writing 1 clears the event (e.g. to acknowledge
                                     an interrupt). */                                                                            
                                                                                                                                  
#define MAIN_EVENTSVBUSIN0CLR_EVENTVBUSOVRVOLTDETECTED_Pos (2UL) /*!< Position of EVENTVBUSOVRVOLTDETECTED field.              */
#define MAIN_EVENTSVBUSIN0CLR_EVENTVBUSOVRVOLTDETECTED_Msk (0x1UL << MAIN_EVENTSVBUSIN0CLR_EVENTVBUSOVRVOLTDETECTED_Pos) /*!<
                                                                            Bit mask of EVENTVBUSOVRVOLTDETECTED field.*/         
#define MAIN_EVENTSVBUSIN0CLR_EVENTVBUSOVRVOLTDETECTED_LOW (0) /*!< low                                                        */
#define MAIN_EVENTSVBUSIN0CLR_EVENTVBUSOVRVOLTDETECTED_HIGH (1) /*!< high                                                      */

/* EVENTVBUSOVRVOLTREMOVED @Bit 3 : Event VBUS Over Removed.
          Writing 1 clears the event (e.g. to acknowledge an
                                    interrupt). */                                                                                
                                                                                                                                  
#define MAIN_EVENTSVBUSIN0CLR_EVENTVBUSOVRVOLTREMOVED_Pos (3UL) /*!< Position of EVENTVBUSOVRVOLTREMOVED field.                */
#define MAIN_EVENTSVBUSIN0CLR_EVENTVBUSOVRVOLTREMOVED_Msk (0x1UL << MAIN_EVENTSVBUSIN0CLR_EVENTVBUSOVRVOLTREMOVED_Pos) /*!< Bit
                                                                            mask of EVENTVBUSOVRVOLTREMOVED field.*/              
#define MAIN_EVENTSVBUSIN0CLR_EVENTVBUSOVRVOLTREMOVED_LOW (0) /*!< low                                                         */
#define MAIN_EVENTSVBUSIN0CLR_EVENTVBUSOVRVOLTREMOVED_HIGH (1) /*!< high                                                       */

/* EVENTVBUSUNDVOLTDETECTED @Bit 4 : Event VBUS Under Voltage Detected.
          Writing 1 clears the event (e.g. to
                                     acknowledge an interrupt). */                                                                
                                                                                                                                  
#define MAIN_EVENTSVBUSIN0CLR_EVENTVBUSUNDVOLTDETECTED_Pos (4UL) /*!< Position of EVENTVBUSUNDVOLTDETECTED field.              */
#define MAIN_EVENTSVBUSIN0CLR_EVENTVBUSUNDVOLTDETECTED_Msk (0x1UL << MAIN_EVENTSVBUSIN0CLR_EVENTVBUSUNDVOLTDETECTED_Pos) /*!<
                                                                            Bit mask of EVENTVBUSUNDVOLTDETECTED field.*/         
#define MAIN_EVENTSVBUSIN0CLR_EVENTVBUSUNDVOLTDETECTED_LOW (0) /*!< low                                                        */
#define MAIN_EVENTSVBUSIN0CLR_EVENTVBUSUNDVOLTDETECTED_HIGH (1) /*!< high                                                      */

/* EVENTVBUSUNDVOLTREMOVED @Bit 5 : Event VBUS Under Removed.
          Writing 1 clears the event (e.g. to acknowledge an
                                    interrupt). */                                                                                
                                                                                                                                  
#define MAIN_EVENTSVBUSIN0CLR_EVENTVBUSUNDVOLTREMOVED_Pos (5UL) /*!< Position of EVENTVBUSUNDVOLTREMOVED field.                */
#define MAIN_EVENTSVBUSIN0CLR_EVENTVBUSUNDVOLTREMOVED_Msk (0x1UL << MAIN_EVENTSVBUSIN0CLR_EVENTVBUSUNDVOLTREMOVED_Pos) /*!< Bit
                                                                            mask of EVENTVBUSUNDVOLTREMOVED field.*/              
#define MAIN_EVENTSVBUSIN0CLR_EVENTVBUSUNDVOLTREMOVED_LOW (0) /*!< low                                                         */
#define MAIN_EVENTSVBUSIN0CLR_EVENTVBUSUNDVOLTREMOVED_HIGH (1) /*!< high                                                       */


/* MAIN_INTENEVENTSVBUSIN0SET: VBUSIN Voltage Detection Events Interrupt Enable Set */

/* EVENTVBUSDETECTED @Bit 0 : Writing 1 enables interrupts from EVENTVBUSDETECTED */
#define MAIN_INTENEVENTSVBUSIN0SET_EVENTVBUSDETECTED_Pos (0UL) /*!< Position of EVENTVBUSDETECTED field.                       */
#define MAIN_INTENEVENTSVBUSIN0SET_EVENTVBUSDETECTED_Msk (0x1UL << MAIN_INTENEVENTSVBUSIN0SET_EVENTVBUSDETECTED_Pos) /*!< Bit
                                                                            mask of EVENTVBUSDETECTED field.*/                    
#define MAIN_INTENEVENTSVBUSIN0SET_EVENTVBUSDETECTED_LOW (0) /*!< low                                                          */
#define MAIN_INTENEVENTSVBUSIN0SET_EVENTVBUSDETECTED_HIGH (1) /*!< high                                                        */

/* EVENTVBUSREMOVED @Bit 1 : Writing 1 enables interrupts from EVENTVBUSREMOVED */
#define MAIN_INTENEVENTSVBUSIN0SET_EVENTVBUSREMOVED_Pos (1UL) /*!< Position of EVENTVBUSREMOVED field.                         */
#define MAIN_INTENEVENTSVBUSIN0SET_EVENTVBUSREMOVED_Msk (0x1UL << MAIN_INTENEVENTSVBUSIN0SET_EVENTVBUSREMOVED_Pos) /*!< Bit mask
                                                                            of EVENTVBUSREMOVED field.*/                          
#define MAIN_INTENEVENTSVBUSIN0SET_EVENTVBUSREMOVED_LOW (0) /*!< low                                                           */
#define MAIN_INTENEVENTSVBUSIN0SET_EVENTVBUSREMOVED_HIGH (1) /*!< high                                                         */

/* EVENTVBUSOVRVOLTDETECTED @Bit 2 : Writing 1 enables interrupts from EVENTVBUSOVRVOLTDETECTED */
#define MAIN_INTENEVENTSVBUSIN0SET_EVENTVBUSOVRVOLTDETECTED_Pos (2UL) /*!< Position of EVENTVBUSOVRVOLTDETECTED field.         */
#define MAIN_INTENEVENTSVBUSIN0SET_EVENTVBUSOVRVOLTDETECTED_Msk (0x1UL << MAIN_INTENEVENTSVBUSIN0SET_EVENTVBUSOVRVOLTDETECTED_Pos)
                                                                            /*!< Bit mask of EVENTVBUSOVRVOLTDETECTED field.*/    
#define MAIN_INTENEVENTSVBUSIN0SET_EVENTVBUSOVRVOLTDETECTED_LOW (0) /*!< low                                                   */
#define MAIN_INTENEVENTSVBUSIN0SET_EVENTVBUSOVRVOLTDETECTED_HIGH (1) /*!< high                                                 */

/* EVENTVBUSOVRVOLTREMOVED @Bit 3 : Writing 1 enables interrupts from EVENTVBUSOVRVOLTREMOVED */
#define MAIN_INTENEVENTSVBUSIN0SET_EVENTVBUSOVRVOLTREMOVED_Pos (3UL) /*!< Position of EVENTVBUSOVRVOLTREMOVED field.           */
#define MAIN_INTENEVENTSVBUSIN0SET_EVENTVBUSOVRVOLTREMOVED_Msk (0x1UL << MAIN_INTENEVENTSVBUSIN0SET_EVENTVBUSOVRVOLTREMOVED_Pos)
                                                                            /*!< Bit mask of EVENTVBUSOVRVOLTREMOVED field.*/     
#define MAIN_INTENEVENTSVBUSIN0SET_EVENTVBUSOVRVOLTREMOVED_LOW (0) /*!< low                                                    */
#define MAIN_INTENEVENTSVBUSIN0SET_EVENTVBUSOVRVOLTREMOVED_HIGH (1) /*!< high                                                  */

/* EVENTVBUSUNDVOLTDETECTED @Bit 4 : Writing 1 enables interrupts from EVENTVBUSUNDVOLTDETECTED */
#define MAIN_INTENEVENTSVBUSIN0SET_EVENTVBUSUNDVOLTDETECTED_Pos (4UL) /*!< Position of EVENTVBUSUNDVOLTDETECTED field.         */
#define MAIN_INTENEVENTSVBUSIN0SET_EVENTVBUSUNDVOLTDETECTED_Msk (0x1UL << MAIN_INTENEVENTSVBUSIN0SET_EVENTVBUSUNDVOLTDETECTED_Pos)
                                                                            /*!< Bit mask of EVENTVBUSUNDVOLTDETECTED field.*/    
#define MAIN_INTENEVENTSVBUSIN0SET_EVENTVBUSUNDVOLTDETECTED_LOW (0) /*!< low                                                   */
#define MAIN_INTENEVENTSVBUSIN0SET_EVENTVBUSUNDVOLTDETECTED_HIGH (1) /*!< high                                                 */

/* EVENTVBUSUNDVOLTREMOVED @Bit 5 : Writing 1 enables interrupts from EVENTVBUSUNDVOLTREMOVED */
#define MAIN_INTENEVENTSVBUSIN0SET_EVENTVBUSUNDVOLTREMOVED_Pos (5UL) /*!< Position of EVENTVBUSUNDVOLTREMOVED field.           */
#define MAIN_INTENEVENTSVBUSIN0SET_EVENTVBUSUNDVOLTREMOVED_Msk (0x1UL << MAIN_INTENEVENTSVBUSIN0SET_EVENTVBUSUNDVOLTREMOVED_Pos)
                                                                            /*!< Bit mask of EVENTVBUSUNDVOLTREMOVED field.*/     
#define MAIN_INTENEVENTSVBUSIN0SET_EVENTVBUSUNDVOLTREMOVED_LOW (0) /*!< low                                                    */
#define MAIN_INTENEVENTSVBUSIN0SET_EVENTVBUSUNDVOLTREMOVED_HIGH (1) /*!< high                                                  */


/* MAIN_INTENEVENTSVBUSIN0CLR: VBUSIN Voltage Detection Events Interrupt Enable Clear */

/* EVENTVBUSDETECTED @Bit 0 : Writing 1 disables interrupts from EVENTVBUSDETECTED */
#define MAIN_INTENEVENTSVBUSIN0CLR_EVENTVBUSDETECTED_Pos (0UL) /*!< Position of EVENTVBUSDETECTED field.                       */
#define MAIN_INTENEVENTSVBUSIN0CLR_EVENTVBUSDETECTED_Msk (0x1UL << MAIN_INTENEVENTSVBUSIN0CLR_EVENTVBUSDETECTED_Pos) /*!< Bit
                                                                            mask of EVENTVBUSDETECTED field.*/                    
#define MAIN_INTENEVENTSVBUSIN0CLR_EVENTVBUSDETECTED_LOW (0) /*!< low                                                          */
#define MAIN_INTENEVENTSVBUSIN0CLR_EVENTVBUSDETECTED_HIGH (1) /*!< high                                                        */

/* EVENTVBUSREMOVED @Bit 1 : Writing 1 disables interrupts from EVENTVBUSREMOVED */
#define MAIN_INTENEVENTSVBUSIN0CLR_EVENTVBUSREMOVED_Pos (1UL) /*!< Position of EVENTVBUSREMOVED field.                         */
#define MAIN_INTENEVENTSVBUSIN0CLR_EVENTVBUSREMOVED_Msk (0x1UL << MAIN_INTENEVENTSVBUSIN0CLR_EVENTVBUSREMOVED_Pos) /*!< Bit mask
                                                                            of EVENTVBUSREMOVED field.*/                          
#define MAIN_INTENEVENTSVBUSIN0CLR_EVENTVBUSREMOVED_LOW (0) /*!< low                                                           */
#define MAIN_INTENEVENTSVBUSIN0CLR_EVENTVBUSREMOVED_HIGH (1) /*!< high                                                         */

/* EVENTVBUSOVRVOLTDETECTED @Bit 2 : Writing 1 disables interrupts from EVENTVBUSOVRVOLTDETECTED */
#define MAIN_INTENEVENTSVBUSIN0CLR_EVENTVBUSOVRVOLTDETECTED_Pos (2UL) /*!< Position of EVENTVBUSOVRVOLTDETECTED field.         */
#define MAIN_INTENEVENTSVBUSIN0CLR_EVENTVBUSOVRVOLTDETECTED_Msk (0x1UL << MAIN_INTENEVENTSVBUSIN0CLR_EVENTVBUSOVRVOLTDETECTED_Pos)
                                                                            /*!< Bit mask of EVENTVBUSOVRVOLTDETECTED field.*/    
#define MAIN_INTENEVENTSVBUSIN0CLR_EVENTVBUSOVRVOLTDETECTED_LOW (0) /*!< low                                                   */
#define MAIN_INTENEVENTSVBUSIN0CLR_EVENTVBUSOVRVOLTDETECTED_HIGH (1) /*!< high                                                 */

/* EVENTVBUSOVRVOLTREMOVED @Bit 3 : Writing 1 disables interrupts from EVENTVBUSOVRVOLTREMOVED */
#define MAIN_INTENEVENTSVBUSIN0CLR_EVENTVBUSOVRVOLTREMOVED_Pos (3UL) /*!< Position of EVENTVBUSOVRVOLTREMOVED field.           */
#define MAIN_INTENEVENTSVBUSIN0CLR_EVENTVBUSOVRVOLTREMOVED_Msk (0x1UL << MAIN_INTENEVENTSVBUSIN0CLR_EVENTVBUSOVRVOLTREMOVED_Pos)
                                                                            /*!< Bit mask of EVENTVBUSOVRVOLTREMOVED field.*/     
#define MAIN_INTENEVENTSVBUSIN0CLR_EVENTVBUSOVRVOLTREMOVED_LOW (0) /*!< low                                                    */
#define MAIN_INTENEVENTSVBUSIN0CLR_EVENTVBUSOVRVOLTREMOVED_HIGH (1) /*!< high                                                  */

/* EVENTVBUSUNDVOLTDETECTED @Bit 4 : Writing 1 disables interrupts from EVENTVBUSUNDVOLTDETECTED */
#define MAIN_INTENEVENTSVBUSIN0CLR_EVENTVBUSUNDVOLTDETECTED_Pos (4UL) /*!< Position of EVENTVBUSUNDVOLTDETECTED field.         */
#define MAIN_INTENEVENTSVBUSIN0CLR_EVENTVBUSUNDVOLTDETECTED_Msk (0x1UL << MAIN_INTENEVENTSVBUSIN0CLR_EVENTVBUSUNDVOLTDETECTED_Pos)
                                                                            /*!< Bit mask of EVENTVBUSUNDVOLTDETECTED field.*/    
#define MAIN_INTENEVENTSVBUSIN0CLR_EVENTVBUSUNDVOLTDETECTED_LOW (0) /*!< low                                                   */
#define MAIN_INTENEVENTSVBUSIN0CLR_EVENTVBUSUNDVOLTDETECTED_HIGH (1) /*!< high                                                 */

/* EVENTVBUSUNDVOLTREMOVED @Bit 5 : Writing 1 disables interrupts from EVENTVBUSUNDVOLTREMOVED */
#define MAIN_INTENEVENTSVBUSIN0CLR_EVENTVBUSUNDVOLTREMOVED_Pos (5UL) /*!< Position of EVENTVBUSUNDVOLTREMOVED field.           */
#define MAIN_INTENEVENTSVBUSIN0CLR_EVENTVBUSUNDVOLTREMOVED_Msk (0x1UL << MAIN_INTENEVENTSVBUSIN0CLR_EVENTVBUSUNDVOLTREMOVED_Pos)
                                                                            /*!< Bit mask of EVENTVBUSUNDVOLTREMOVED field.*/     
#define MAIN_INTENEVENTSVBUSIN0CLR_EVENTVBUSUNDVOLTREMOVED_LOW (0) /*!< low                                                    */
#define MAIN_INTENEVENTSVBUSIN0CLR_EVENTVBUSUNDVOLTREMOVED_HIGH (1) /*!< high                                                  */


/* MAIN_EVENTSVBUSIN1SET: VBUSIN Thermal and USB Events Event Set */

/* EVENTTHERMALWARNDETECTED @Bit 0 : Event Thermal Warning detected.
          Writing 1 sets the event (for debugging). */
#define MAIN_EVENTSVBUSIN1SET_EVENTTHERMALWARNDETECTED_Pos (0UL) /*!< Position of EVENTTHERMALWARNDETECTED field.              */
#define MAIN_EVENTSVBUSIN1SET_EVENTTHERMALWARNDETECTED_Msk (0x1UL << MAIN_EVENTSVBUSIN1SET_EVENTTHERMALWARNDETECTED_Pos) /*!<
                                                                            Bit mask of EVENTTHERMALWARNDETECTED field.*/         
#define MAIN_EVENTSVBUSIN1SET_EVENTTHERMALWARNDETECTED_LOW (0) /*!< low                                                        */
#define MAIN_EVENTSVBUSIN1SET_EVENTTHERMALWARNDETECTED_HIGH (1) /*!< high                                                      */

/* EVENTTHERMALWARNREMOVED @Bit 1 : Event Thermal Warning removed.
          Writing 1 sets the event (for debugging). */
#define MAIN_EVENTSVBUSIN1SET_EVENTTHERMALWARNREMOVED_Pos (1UL) /*!< Position of EVENTTHERMALWARNREMOVED field.                */
#define MAIN_EVENTSVBUSIN1SET_EVENTTHERMALWARNREMOVED_Msk (0x1UL << MAIN_EVENTSVBUSIN1SET_EVENTTHERMALWARNREMOVED_Pos) /*!< Bit
                                                                            mask of EVENTTHERMALWARNREMOVED field.*/              
#define MAIN_EVENTSVBUSIN1SET_EVENTTHERMALWARNREMOVED_LOW (0) /*!< low                                                         */
#define MAIN_EVENTSVBUSIN1SET_EVENTTHERMALWARNREMOVED_HIGH (1) /*!< high                                                       */

/* EVENTTHERMALSHUTDOWNDETECTED @Bit 2 : Event Thermal Shutown detected.
          Writing 1 sets the event (for debugging). */
#define MAIN_EVENTSVBUSIN1SET_EVENTTHERMALSHUTDOWNDETECTED_Pos (2UL) /*!< Position of EVENTTHERMALSHUTDOWNDETECTED field.      */
#define MAIN_EVENTSVBUSIN1SET_EVENTTHERMALSHUTDOWNDETECTED_Msk (0x1UL << MAIN_EVENTSVBUSIN1SET_EVENTTHERMALSHUTDOWNDETECTED_Pos)
                                                                            /*!< Bit mask of EVENTTHERMALSHUTDOWNDETECTED
                                                                            field.*/                                              
#define MAIN_EVENTSVBUSIN1SET_EVENTTHERMALSHUTDOWNDETECTED_LOW (0) /*!< low                                                    */
#define MAIN_EVENTSVBUSIN1SET_EVENTTHERMALSHUTDOWNDETECTED_HIGH (1) /*!< high                                                  */

/* EVENTTHERMALSHUTDOWNREMOVED @Bit 3 : Event Thermal Shutdown removed.
          Writing 1 sets the event (for debugging). */
#define MAIN_EVENTSVBUSIN1SET_EVENTTHERMALSHUTDOWNREMOVED_Pos (3UL) /*!< Position of EVENTTHERMALSHUTDOWNREMOVED field.        */
#define MAIN_EVENTSVBUSIN1SET_EVENTTHERMALSHUTDOWNREMOVED_Msk (0x1UL << MAIN_EVENTSVBUSIN1SET_EVENTTHERMALSHUTDOWNREMOVED_Pos)
                                                                            /*!< Bit mask of EVENTTHERMALSHUTDOWNREMOVED field.*/ 
#define MAIN_EVENTSVBUSIN1SET_EVENTTHERMALSHUTDOWNREMOVED_LOW (0) /*!< low                                                     */
#define MAIN_EVENTSVBUSIN1SET_EVENTTHERMALSHUTDOWNREMOVED_HIGH (1) /*!< high                                                   */

/* EVENTCC1STATECHANGE @Bit 4 : Event when Voltage on CC1 changes.
          Writing 1 sets the event (for debugging). */
#define MAIN_EVENTSVBUSIN1SET_EVENTCC1STATECHANGE_Pos (4UL) /*!< Position of EVENTCC1STATECHANGE field.                        */
#define MAIN_EVENTSVBUSIN1SET_EVENTCC1STATECHANGE_Msk (0x1UL << MAIN_EVENTSVBUSIN1SET_EVENTCC1STATECHANGE_Pos) /*!< Bit mask of
                                                                            EVENTCC1STATECHANGE field.*/                          
#define MAIN_EVENTSVBUSIN1SET_EVENTCC1STATECHANGE_LOW (0) /*!< low                                                             */
#define MAIN_EVENTSVBUSIN1SET_EVENTCC1STATECHANGE_HIGH (1) /*!< high                                                           */

/* EVENTCC2STATECHANGE @Bit 5 : Event when Voltage on CC2 changes.
          Writing 1 sets the event (for debugging). */
#define MAIN_EVENTSVBUSIN1SET_EVENTCC2STATECHANGE_Pos (5UL) /*!< Position of EVENTCC2STATECHANGE field.                        */
#define MAIN_EVENTSVBUSIN1SET_EVENTCC2STATECHANGE_Msk (0x1UL << MAIN_EVENTSVBUSIN1SET_EVENTCC2STATECHANGE_Pos) /*!< Bit mask of
                                                                            EVENTCC2STATECHANGE field.*/                          
#define MAIN_EVENTSVBUSIN1SET_EVENTCC2STATECHANGE_LOW (0) /*!< low                                                             */
#define MAIN_EVENTSVBUSIN1SET_EVENTCC2STATECHANGE_HIGH (1) /*!< high                                                           */


/* MAIN_EVENTSVBUSIN1CLR: VBUSIN Thermal and USB Events Event Clear */

/* EVENTTHERMALWARNDETECTED @Bit 0 : Event Thermal Warning detected.
          Writing 1 clears the event (e.g. to acknowledge
                                     an interrupt). */                                                                            
                                                                                                                                  
#define MAIN_EVENTSVBUSIN1CLR_EVENTTHERMALWARNDETECTED_Pos (0UL) /*!< Position of EVENTTHERMALWARNDETECTED field.              */
#define MAIN_EVENTSVBUSIN1CLR_EVENTTHERMALWARNDETECTED_Msk (0x1UL << MAIN_EVENTSVBUSIN1CLR_EVENTTHERMALWARNDETECTED_Pos) /*!<
                                                                            Bit mask of EVENTTHERMALWARNDETECTED field.*/         
#define MAIN_EVENTSVBUSIN1CLR_EVENTTHERMALWARNDETECTED_LOW (0) /*!< low                                                        */
#define MAIN_EVENTSVBUSIN1CLR_EVENTTHERMALWARNDETECTED_HIGH (1) /*!< high                                                      */

/* EVENTTHERMALWARNREMOVED @Bit 1 : Event Thermal Warning removed.
          Writing 1 clears the event (e.g. to acknowledge an
                                    interrupt). */                                                                                
                                                                                                                                  
#define MAIN_EVENTSVBUSIN1CLR_EVENTTHERMALWARNREMOVED_Pos (1UL) /*!< Position of EVENTTHERMALWARNREMOVED field.                */
#define MAIN_EVENTSVBUSIN1CLR_EVENTTHERMALWARNREMOVED_Msk (0x1UL << MAIN_EVENTSVBUSIN1CLR_EVENTTHERMALWARNREMOVED_Pos) /*!< Bit
                                                                            mask of EVENTTHERMALWARNREMOVED field.*/              
#define MAIN_EVENTSVBUSIN1CLR_EVENTTHERMALWARNREMOVED_LOW (0) /*!< low                                                         */
#define MAIN_EVENTSVBUSIN1CLR_EVENTTHERMALWARNREMOVED_HIGH (1) /*!< high                                                       */

/* EVENTTHERMALSHUTDOWNDETECTED @Bit 2 : Event Thermal Shutown detected.
          Writing 1 clears the event (e.g. to
                                         acknowledge an interrupt). */                                                            
                                                                                                                                  
#define MAIN_EVENTSVBUSIN1CLR_EVENTTHERMALSHUTDOWNDETECTED_Pos (2UL) /*!< Position of EVENTTHERMALSHUTDOWNDETECTED field.      */
#define MAIN_EVENTSVBUSIN1CLR_EVENTTHERMALSHUTDOWNDETECTED_Msk (0x1UL << MAIN_EVENTSVBUSIN1CLR_EVENTTHERMALSHUTDOWNDETECTED_Pos)
                                                                            /*!< Bit mask of EVENTTHERMALSHUTDOWNDETECTED
                                                                            field.*/                                              
#define MAIN_EVENTSVBUSIN1CLR_EVENTTHERMALSHUTDOWNDETECTED_LOW (0) /*!< low                                                    */
#define MAIN_EVENTSVBUSIN1CLR_EVENTTHERMALSHUTDOWNDETECTED_HIGH (1) /*!< high                                                  */

/* EVENTTHERMALSHUTDOWNREMOVED @Bit 3 : Event Thermal Shutdown removed.
          Writing 1 clears the event (e.g. to
                                        acknowledge an interrupt). */                                                             
                                                                                                                                  
#define MAIN_EVENTSVBUSIN1CLR_EVENTTHERMALSHUTDOWNREMOVED_Pos (3UL) /*!< Position of EVENTTHERMALSHUTDOWNREMOVED field.        */
#define MAIN_EVENTSVBUSIN1CLR_EVENTTHERMALSHUTDOWNREMOVED_Msk (0x1UL << MAIN_EVENTSVBUSIN1CLR_EVENTTHERMALSHUTDOWNREMOVED_Pos)
                                                                            /*!< Bit mask of EVENTTHERMALSHUTDOWNREMOVED field.*/ 
#define MAIN_EVENTSVBUSIN1CLR_EVENTTHERMALSHUTDOWNREMOVED_LOW (0) /*!< low                                                     */
#define MAIN_EVENTSVBUSIN1CLR_EVENTTHERMALSHUTDOWNREMOVED_HIGH (1) /*!< high                                                   */

/* EVENTCC1STATECHANGE @Bit 4 : Event when Voltage on CC1 changes.
          Writing 1 clears the event (e.g. to acknowledge an
                                interrupt). */                                                                                    
                                                                                                                                  
#define MAIN_EVENTSVBUSIN1CLR_EVENTCC1STATECHANGE_Pos (4UL) /*!< Position of EVENTCC1STATECHANGE field.                        */
#define MAIN_EVENTSVBUSIN1CLR_EVENTCC1STATECHANGE_Msk (0x1UL << MAIN_EVENTSVBUSIN1CLR_EVENTCC1STATECHANGE_Pos) /*!< Bit mask of
                                                                            EVENTCC1STATECHANGE field.*/                          
#define MAIN_EVENTSVBUSIN1CLR_EVENTCC1STATECHANGE_LOW (0) /*!< low                                                             */
#define MAIN_EVENTSVBUSIN1CLR_EVENTCC1STATECHANGE_HIGH (1) /*!< high                                                           */

/* EVENTCC2STATECHANGE @Bit 5 : Event when Voltage on CC2 changes.
          Writing 1 clears the event (e.g. to acknowledge an
                                interrupt). */                                                                                    
                                                                                                                                  
#define MAIN_EVENTSVBUSIN1CLR_EVENTCC2STATECHANGE_Pos (5UL) /*!< Position of EVENTCC2STATECHANGE field.                        */
#define MAIN_EVENTSVBUSIN1CLR_EVENTCC2STATECHANGE_Msk (0x1UL << MAIN_EVENTSVBUSIN1CLR_EVENTCC2STATECHANGE_Pos) /*!< Bit mask of
                                                                            EVENTCC2STATECHANGE field.*/                          
#define MAIN_EVENTSVBUSIN1CLR_EVENTCC2STATECHANGE_LOW (0) /*!< low                                                             */
#define MAIN_EVENTSVBUSIN1CLR_EVENTCC2STATECHANGE_HIGH (1) /*!< high                                                           */


/* MAIN_INTENEVENTSVBUSIN1SET: VBUSIN Thermal and USB Events Interrupt Enable Set */

/* EVENTTHERMALWARNDETECTED @Bit 0 : Writing 1 enables interrupts from EVENTTHERMALWARNDETECTED */
#define MAIN_INTENEVENTSVBUSIN1SET_EVENTTHERMALWARNDETECTED_Pos (0UL) /*!< Position of EVENTTHERMALWARNDETECTED field.         */
#define MAIN_INTENEVENTSVBUSIN1SET_EVENTTHERMALWARNDETECTED_Msk (0x1UL << MAIN_INTENEVENTSVBUSIN1SET_EVENTTHERMALWARNDETECTED_Pos)
                                                                            /*!< Bit mask of EVENTTHERMALWARNDETECTED field.*/    
#define MAIN_INTENEVENTSVBUSIN1SET_EVENTTHERMALWARNDETECTED_LOW (0) /*!< low                                                   */
#define MAIN_INTENEVENTSVBUSIN1SET_EVENTTHERMALWARNDETECTED_HIGH (1) /*!< high                                                 */

/* EVENTTHERMALWARNREMOVED @Bit 1 : Writing 1 enables interrupts from EVENTTHERMALWARNREMOVED */
#define MAIN_INTENEVENTSVBUSIN1SET_EVENTTHERMALWARNREMOVED_Pos (1UL) /*!< Position of EVENTTHERMALWARNREMOVED field.           */
#define MAIN_INTENEVENTSVBUSIN1SET_EVENTTHERMALWARNREMOVED_Msk (0x1UL << MAIN_INTENEVENTSVBUSIN1SET_EVENTTHERMALWARNREMOVED_Pos)
                                                                            /*!< Bit mask of EVENTTHERMALWARNREMOVED field.*/     
#define MAIN_INTENEVENTSVBUSIN1SET_EVENTTHERMALWARNREMOVED_LOW (0) /*!< low                                                    */
#define MAIN_INTENEVENTSVBUSIN1SET_EVENTTHERMALWARNREMOVED_HIGH (1) /*!< high                                                  */

/* EVENTTHERMALSHUTDOWNDETECTED @Bit 2 : Writing 1 enables interrupts from EVENTTHERMALSHUTDOWNDETECTED */
#define MAIN_INTENEVENTSVBUSIN1SET_EVENTTHERMALSHUTDOWNDETECTED_Pos (2UL) /*!< Position of EVENTTHERMALSHUTDOWNDETECTED field. */
#define MAIN_INTENEVENTSVBUSIN1SET_EVENTTHERMALSHUTDOWNDETECTED_Msk (0x1UL << MAIN_INTENEVENTSVBUSIN1SET_EVENTTHERMALSHUTDOWNDETECTED_Pos)
                                                                            /*!< Bit mask of EVENTTHERMALSHUTDOWNDETECTED
                                                                            field.*/                                              
#define MAIN_INTENEVENTSVBUSIN1SET_EVENTTHERMALSHUTDOWNDETECTED_LOW (0) /*!< low                                               */
#define MAIN_INTENEVENTSVBUSIN1SET_EVENTTHERMALSHUTDOWNDETECTED_HIGH (1) /*!< high                                             */

/* EVENTTHERMALSHUTDOWNREMOVED @Bit 3 : Writing 1 enables interrupts from EVENTTHERMALSHUTDOWNREMOVED */
#define MAIN_INTENEVENTSVBUSIN1SET_EVENTTHERMALSHUTDOWNREMOVED_Pos (3UL) /*!< Position of EVENTTHERMALSHUTDOWNREMOVED field.   */
#define MAIN_INTENEVENTSVBUSIN1SET_EVENTTHERMALSHUTDOWNREMOVED_Msk (0x1UL << MAIN_INTENEVENTSVBUSIN1SET_EVENTTHERMALSHUTDOWNREMOVED_Pos)
                                                                            /*!< Bit mask of EVENTTHERMALSHUTDOWNREMOVED field.*/ 
#define MAIN_INTENEVENTSVBUSIN1SET_EVENTTHERMALSHUTDOWNREMOVED_LOW (0) /*!< low                                                */
#define MAIN_INTENEVENTSVBUSIN1SET_EVENTTHERMALSHUTDOWNREMOVED_HIGH (1) /*!< high                                              */

/* EVENTCC1STATECHANGE @Bit 4 : Writing 1 enables interrupts from EVENTCC1STATECHANGE */
#define MAIN_INTENEVENTSVBUSIN1SET_EVENTCC1STATECHANGE_Pos (4UL) /*!< Position of EVENTCC1STATECHANGE field.                   */
#define MAIN_INTENEVENTSVBUSIN1SET_EVENTCC1STATECHANGE_Msk (0x1UL << MAIN_INTENEVENTSVBUSIN1SET_EVENTCC1STATECHANGE_Pos) /*!<
                                                                            Bit mask of EVENTCC1STATECHANGE field.*/              
#define MAIN_INTENEVENTSVBUSIN1SET_EVENTCC1STATECHANGE_LOW (0) /*!< low                                                        */
#define MAIN_INTENEVENTSVBUSIN1SET_EVENTCC1STATECHANGE_HIGH (1) /*!< high                                                      */

/* EVENTCC2STATECHANGE @Bit 5 : Writing 1 enables interrupts from EVENTCC2STATECHANGE */
#define MAIN_INTENEVENTSVBUSIN1SET_EVENTCC2STATECHANGE_Pos (5UL) /*!< Position of EVENTCC2STATECHANGE field.                   */
#define MAIN_INTENEVENTSVBUSIN1SET_EVENTCC2STATECHANGE_Msk (0x1UL << MAIN_INTENEVENTSVBUSIN1SET_EVENTCC2STATECHANGE_Pos) /*!<
                                                                            Bit mask of EVENTCC2STATECHANGE field.*/              
#define MAIN_INTENEVENTSVBUSIN1SET_EVENTCC2STATECHANGE_LOW (0) /*!< low                                                        */
#define MAIN_INTENEVENTSVBUSIN1SET_EVENTCC2STATECHANGE_HIGH (1) /*!< high                                                      */


/* MAIN_INTENEVENTSVBUSIN1CLR: VBUSIN Thermal and USB Events Interrupt Enable Clear */

/* EVENTTHERMALWARNDETECTED @Bit 0 : Writing 1 disables interrupts from EVENTTHERMALWARNDETECTED */
#define MAIN_INTENEVENTSVBUSIN1CLR_EVENTTHERMALWARNDETECTED_Pos (0UL) /*!< Position of EVENTTHERMALWARNDETECTED field.         */
#define MAIN_INTENEVENTSVBUSIN1CLR_EVENTTHERMALWARNDETECTED_Msk (0x1UL << MAIN_INTENEVENTSVBUSIN1CLR_EVENTTHERMALWARNDETECTED_Pos)
                                                                            /*!< Bit mask of EVENTTHERMALWARNDETECTED field.*/    
#define MAIN_INTENEVENTSVBUSIN1CLR_EVENTTHERMALWARNDETECTED_LOW (0) /*!< low                                                   */
#define MAIN_INTENEVENTSVBUSIN1CLR_EVENTTHERMALWARNDETECTED_HIGH (1) /*!< high                                                 */

/* EVENTTHERMALWARNREMOVED @Bit 1 : Writing 1 disables interrupts from EVENTTHERMALWARNREMOVED */
#define MAIN_INTENEVENTSVBUSIN1CLR_EVENTTHERMALWARNREMOVED_Pos (1UL) /*!< Position of EVENTTHERMALWARNREMOVED field.           */
#define MAIN_INTENEVENTSVBUSIN1CLR_EVENTTHERMALWARNREMOVED_Msk (0x1UL << MAIN_INTENEVENTSVBUSIN1CLR_EVENTTHERMALWARNREMOVED_Pos)
                                                                            /*!< Bit mask of EVENTTHERMALWARNREMOVED field.*/     
#define MAIN_INTENEVENTSVBUSIN1CLR_EVENTTHERMALWARNREMOVED_LOW (0) /*!< low                                                    */
#define MAIN_INTENEVENTSVBUSIN1CLR_EVENTTHERMALWARNREMOVED_HIGH (1) /*!< high                                                  */

/* EVENTTHERMALSHUTDOWNDETECTED @Bit 2 : Writing 1 disables interrupts from EVENTTHERMALSHUTDOWNDETECTED */
#define MAIN_INTENEVENTSVBUSIN1CLR_EVENTTHERMALSHUTDOWNDETECTED_Pos (2UL) /*!< Position of EVENTTHERMALSHUTDOWNDETECTED field. */
#define MAIN_INTENEVENTSVBUSIN1CLR_EVENTTHERMALSHUTDOWNDETECTED_Msk (0x1UL << MAIN_INTENEVENTSVBUSIN1CLR_EVENTTHERMALSHUTDOWNDETECTED_Pos)
                                                                            /*!< Bit mask of EVENTTHERMALSHUTDOWNDETECTED
                                                                            field.*/                                              
#define MAIN_INTENEVENTSVBUSIN1CLR_EVENTTHERMALSHUTDOWNDETECTED_LOW (0) /*!< low                                               */
#define MAIN_INTENEVENTSVBUSIN1CLR_EVENTTHERMALSHUTDOWNDETECTED_HIGH (1) /*!< high                                             */

/* EVENTTHERMALSHUTDOWNREMOVED @Bit 3 : Writing 1 disables interrupts from EVENTTHERMALSHUTDOWNREMOVED */
#define MAIN_INTENEVENTSVBUSIN1CLR_EVENTTHERMALSHUTDOWNREMOVED_Pos (3UL) /*!< Position of EVENTTHERMALSHUTDOWNREMOVED field.   */
#define MAIN_INTENEVENTSVBUSIN1CLR_EVENTTHERMALSHUTDOWNREMOVED_Msk (0x1UL << MAIN_INTENEVENTSVBUSIN1CLR_EVENTTHERMALSHUTDOWNREMOVED_Pos)
                                                                            /*!< Bit mask of EVENTTHERMALSHUTDOWNREMOVED field.*/ 
#define MAIN_INTENEVENTSVBUSIN1CLR_EVENTTHERMALSHUTDOWNREMOVED_LOW (0) /*!< low                                                */
#define MAIN_INTENEVENTSVBUSIN1CLR_EVENTTHERMALSHUTDOWNREMOVED_HIGH (1) /*!< high                                              */

/* EVENTCC1STATECHANGE @Bit 4 : Writing 1 disables interrupts from EVENTCC1STATECHANGE */
#define MAIN_INTENEVENTSVBUSIN1CLR_EVENTCC1STATECHANGE_Pos (4UL) /*!< Position of EVENTCC1STATECHANGE field.                   */
#define MAIN_INTENEVENTSVBUSIN1CLR_EVENTCC1STATECHANGE_Msk (0x1UL << MAIN_INTENEVENTSVBUSIN1CLR_EVENTCC1STATECHANGE_Pos) /*!<
                                                                            Bit mask of EVENTCC1STATECHANGE field.*/              
#define MAIN_INTENEVENTSVBUSIN1CLR_EVENTCC1STATECHANGE_LOW (0) /*!< low                                                        */
#define MAIN_INTENEVENTSVBUSIN1CLR_EVENTCC1STATECHANGE_HIGH (1) /*!< high                                                      */

/* EVENTCC2STATECHANGE @Bit 5 : Writing 1 disables interrupts from EVENTCC2STATECHANGE */
#define MAIN_INTENEVENTSVBUSIN1CLR_EVENTCC2STATECHANGE_Pos (5UL) /*!< Position of EVENTCC2STATECHANGE field.                   */
#define MAIN_INTENEVENTSVBUSIN1CLR_EVENTCC2STATECHANGE_Msk (0x1UL << MAIN_INTENEVENTSVBUSIN1CLR_EVENTCC2STATECHANGE_Pos) /*!<
                                                                            Bit mask of EVENTCC2STATECHANGE field.*/              
#define MAIN_INTENEVENTSVBUSIN1CLR_EVENTCC2STATECHANGE_LOW (0) /*!< low                                                        */
#define MAIN_INTENEVENTSVBUSIN1CLR_EVENTCC2STATECHANGE_HIGH (1) /*!< high                                                      */


/* MAIN_EVENTSGPIOSET: GPIO Event Event Set */

/* EVENTGPIOEDGEDETECT0 @Bit 0 : Event when GPIO input 0 edge is detected. GPIOS.GPIO_MODE = 3 : Rising Edge
GPIOS.GPIO_MODE = 4
                                 : Falling Edge.
          Writing 1 sets the event (for debugging). */                           
                                                                                                                                  
#define MAIN_EVENTSGPIOSET_EVENTGPIOEDGEDETECT0_Pos (0UL) /*!< Position of EVENTGPIOEDGEDETECT0 field.                         */
#define MAIN_EVENTSGPIOSET_EVENTGPIOEDGEDETECT0_Msk (0x1UL << MAIN_EVENTSGPIOSET_EVENTGPIOEDGEDETECT0_Pos) /*!< Bit mask of
                                                                            EVENTGPIOEDGEDETECT0 field.*/                         
#define MAIN_EVENTSGPIOSET_EVENTGPIOEDGEDETECT0_LOW (0) /*!< low                                                               */
#define MAIN_EVENTSGPIOSET_EVENTGPIOEDGEDETECT0_HIGH (1) /*!< high                                                             */

/* EVENTGPIOEDGEDETECT1 @Bit 1 : Event when GPIO input 1 edge is detected. GPIOS.GPIO_MODE = 3 : Rising Edge
GPIOS.GPIO_MODE = 4
                                 : Falling Edge.
          Writing 1 sets the event (for debugging). */                           
                                                                                                                                  
#define MAIN_EVENTSGPIOSET_EVENTGPIOEDGEDETECT1_Pos (1UL) /*!< Position of EVENTGPIOEDGEDETECT1 field.                         */
#define MAIN_EVENTSGPIOSET_EVENTGPIOEDGEDETECT1_Msk (0x1UL << MAIN_EVENTSGPIOSET_EVENTGPIOEDGEDETECT1_Pos) /*!< Bit mask of
                                                                            EVENTGPIOEDGEDETECT1 field.*/                         
#define MAIN_EVENTSGPIOSET_EVENTGPIOEDGEDETECT1_LOW (0) /*!< low                                                               */
#define MAIN_EVENTSGPIOSET_EVENTGPIOEDGEDETECT1_HIGH (1) /*!< high                                                             */

/* EVENTGPIOEDGEDETECT2 @Bit 2 : Event when GPIO input 2 edge is detected. GPIOS.GPIO_MODE = 3 : Rising Edge
GPIOS.GPIO_MODE = 4
                                 : Falling Edge.
          Writing 1 sets the event (for debugging). */                           
                                                                                                                                  
#define MAIN_EVENTSGPIOSET_EVENTGPIOEDGEDETECT2_Pos (2UL) /*!< Position of EVENTGPIOEDGEDETECT2 field.                         */
#define MAIN_EVENTSGPIOSET_EVENTGPIOEDGEDETECT2_Msk (0x1UL << MAIN_EVENTSGPIOSET_EVENTGPIOEDGEDETECT2_Pos) /*!< Bit mask of
                                                                            EVENTGPIOEDGEDETECT2 field.*/                         
#define MAIN_EVENTSGPIOSET_EVENTGPIOEDGEDETECT2_LOW (0) /*!< low                                                               */
#define MAIN_EVENTSGPIOSET_EVENTGPIOEDGEDETECT2_HIGH (1) /*!< high                                                             */

/* EVENTGPIOEDGEDETECT3 @Bit 3 : Event when GPIO input 3 edge is detected. GPIOS.GPIO_MODE = 3 : Rising Edge
GPIOS.GPIO_MODE = 4
                                 : Falling Edge.
          Writing 1 sets the event (for debugging). */                           
                                                                                                                                  
#define MAIN_EVENTSGPIOSET_EVENTGPIOEDGEDETECT3_Pos (3UL) /*!< Position of EVENTGPIOEDGEDETECT3 field.                         */
#define MAIN_EVENTSGPIOSET_EVENTGPIOEDGEDETECT3_Msk (0x1UL << MAIN_EVENTSGPIOSET_EVENTGPIOEDGEDETECT3_Pos) /*!< Bit mask of
                                                                            EVENTGPIOEDGEDETECT3 field.*/                         
#define MAIN_EVENTSGPIOSET_EVENTGPIOEDGEDETECT3_LOW (0) /*!< low                                                               */
#define MAIN_EVENTSGPIOSET_EVENTGPIOEDGEDETECT3_HIGH (1) /*!< high                                                             */

/* EVENTGPIOEDGEDETECT4 @Bit 4 : Event when GPIO input 4 edge is detected. GPIOS.GPIO_MODE = 3 : Rising Edge
GPIOS.GPIO_MODE = 4
                                 : Falling Edge.
          Writing 1 sets the event (for debugging). */                           
                                                                                                                                  
#define MAIN_EVENTSGPIOSET_EVENTGPIOEDGEDETECT4_Pos (4UL) /*!< Position of EVENTGPIOEDGEDETECT4 field.                         */
#define MAIN_EVENTSGPIOSET_EVENTGPIOEDGEDETECT4_Msk (0x1UL << MAIN_EVENTSGPIOSET_EVENTGPIOEDGEDETECT4_Pos) /*!< Bit mask of
                                                                            EVENTGPIOEDGEDETECT4 field.*/                         
#define MAIN_EVENTSGPIOSET_EVENTGPIOEDGEDETECT4_LOW (0) /*!< low                                                               */
#define MAIN_EVENTSGPIOSET_EVENTGPIOEDGEDETECT4_HIGH (1) /*!< high                                                             */


/* MAIN_EVENTSGPIOCLR: GPIO Event Event Clear */

/* EVENTGPIOEDGEDETECT0 @Bit 0 : Event when GPIO input 0 edge is detected. GPIOS.GPIO_MODE = 3 : Rising Edge
GPIOS.GPIO_MODE = 4
                                 : Falling Edge.
          Writing 1 clears the event (e.g. to acknowledge an interrupt). */      
                                                                                                                                  
#define MAIN_EVENTSGPIOCLR_EVENTGPIOEDGEDETECT0_Pos (0UL) /*!< Position of EVENTGPIOEDGEDETECT0 field.                         */
#define MAIN_EVENTSGPIOCLR_EVENTGPIOEDGEDETECT0_Msk (0x1UL << MAIN_EVENTSGPIOCLR_EVENTGPIOEDGEDETECT0_Pos) /*!< Bit mask of
                                                                            EVENTGPIOEDGEDETECT0 field.*/                         
#define MAIN_EVENTSGPIOCLR_EVENTGPIOEDGEDETECT0_LOW (0) /*!< low                                                               */
#define MAIN_EVENTSGPIOCLR_EVENTGPIOEDGEDETECT0_HIGH (1) /*!< high                                                             */

/* EVENTGPIOEDGEDETECT1 @Bit 1 : Event when GPIO input 1 edge is detected. GPIOS.GPIO_MODE = 3 : Rising Edge
GPIOS.GPIO_MODE = 4
                                 : Falling Edge.
          Writing 1 clears the event (e.g. to acknowledge an interrupt). */      
                                                                                                                                  
#define MAIN_EVENTSGPIOCLR_EVENTGPIOEDGEDETECT1_Pos (1UL) /*!< Position of EVENTGPIOEDGEDETECT1 field.                         */
#define MAIN_EVENTSGPIOCLR_EVENTGPIOEDGEDETECT1_Msk (0x1UL << MAIN_EVENTSGPIOCLR_EVENTGPIOEDGEDETECT1_Pos) /*!< Bit mask of
                                                                            EVENTGPIOEDGEDETECT1 field.*/                         
#define MAIN_EVENTSGPIOCLR_EVENTGPIOEDGEDETECT1_LOW (0) /*!< low                                                               */
#define MAIN_EVENTSGPIOCLR_EVENTGPIOEDGEDETECT1_HIGH (1) /*!< high                                                             */

/* EVENTGPIOEDGEDETECT2 @Bit 2 : Event when GPIO input 2 edge is detected. GPIOS.GPIO_MODE = 3 : Rising Edge
GPIOS.GPIO_MODE = 4
                                 : Falling Edge.
          Writing 1 clears the event (e.g. to acknowledge an interrupt). */      
                                                                                                                                  
#define MAIN_EVENTSGPIOCLR_EVENTGPIOEDGEDETECT2_Pos (2UL) /*!< Position of EVENTGPIOEDGEDETECT2 field.                         */
#define MAIN_EVENTSGPIOCLR_EVENTGPIOEDGEDETECT2_Msk (0x1UL << MAIN_EVENTSGPIOCLR_EVENTGPIOEDGEDETECT2_Pos) /*!< Bit mask of
                                                                            EVENTGPIOEDGEDETECT2 field.*/                         
#define MAIN_EVENTSGPIOCLR_EVENTGPIOEDGEDETECT2_LOW (0) /*!< low                                                               */
#define MAIN_EVENTSGPIOCLR_EVENTGPIOEDGEDETECT2_HIGH (1) /*!< high                                                             */

/* EVENTGPIOEDGEDETECT3 @Bit 3 : Event when GPIO input 3 edge is detected. GPIOS.GPIO_MODE = 3 : Rising Edge
GPIOS.GPIO_MODE = 4
                                 : Falling Edge.
          Writing 1 clears the event (e.g. to acknowledge an interrupt). */      
                                                                                                                                  
#define MAIN_EVENTSGPIOCLR_EVENTGPIOEDGEDETECT3_Pos (3UL) /*!< Position of EVENTGPIOEDGEDETECT3 field.                         */
#define MAIN_EVENTSGPIOCLR_EVENTGPIOEDGEDETECT3_Msk (0x1UL << MAIN_EVENTSGPIOCLR_EVENTGPIOEDGEDETECT3_Pos) /*!< Bit mask of
                                                                            EVENTGPIOEDGEDETECT3 field.*/                         
#define MAIN_EVENTSGPIOCLR_EVENTGPIOEDGEDETECT3_LOW (0) /*!< low                                                               */
#define MAIN_EVENTSGPIOCLR_EVENTGPIOEDGEDETECT3_HIGH (1) /*!< high                                                             */

/* EVENTGPIOEDGEDETECT4 @Bit 4 : Event when GPIO input 4 edge is detected. GPIOS.GPIO_MODE = 3 : Rising Edge
GPIOS.GPIO_MODE = 4
                                 : Falling Edge.
          Writing 1 clears the event (e.g. to acknowledge an interrupt). */      
                                                                                                                                  
#define MAIN_EVENTSGPIOCLR_EVENTGPIOEDGEDETECT4_Pos (4UL) /*!< Position of EVENTGPIOEDGEDETECT4 field.                         */
#define MAIN_EVENTSGPIOCLR_EVENTGPIOEDGEDETECT4_Msk (0x1UL << MAIN_EVENTSGPIOCLR_EVENTGPIOEDGEDETECT4_Pos) /*!< Bit mask of
                                                                            EVENTGPIOEDGEDETECT4 field.*/                         
#define MAIN_EVENTSGPIOCLR_EVENTGPIOEDGEDETECT4_LOW (0) /*!< low                                                               */
#define MAIN_EVENTSGPIOCLR_EVENTGPIOEDGEDETECT4_HIGH (1) /*!< high                                                             */


/* MAIN_INTENEVENTSGPIOSET: GPIO Event Interrupt Enable Set */

/* EVENTGPIOEDGEDETECT0 @Bit 0 : Writing 1 enables interrupts from EVENTGPIOEDGEDETECT0 */
#define MAIN_INTENEVENTSGPIOSET_EVENTGPIOEDGEDETECT0_Pos (0UL) /*!< Position of EVENTGPIOEDGEDETECT0 field.                    */
#define MAIN_INTENEVENTSGPIOSET_EVENTGPIOEDGEDETECT0_Msk (0x1UL << MAIN_INTENEVENTSGPIOSET_EVENTGPIOEDGEDETECT0_Pos) /*!< Bit
                                                                            mask of EVENTGPIOEDGEDETECT0 field.*/                 
#define MAIN_INTENEVENTSGPIOSET_EVENTGPIOEDGEDETECT0_LOW (0) /*!< low                                                          */
#define MAIN_INTENEVENTSGPIOSET_EVENTGPIOEDGEDETECT0_HIGH (1) /*!< high                                                        */

/* EVENTGPIOEDGEDETECT1 @Bit 1 : Writing 1 enables interrupts from EVENTGPIOEDGEDETECT1 */
#define MAIN_INTENEVENTSGPIOSET_EVENTGPIOEDGEDETECT1_Pos (1UL) /*!< Position of EVENTGPIOEDGEDETECT1 field.                    */
#define MAIN_INTENEVENTSGPIOSET_EVENTGPIOEDGEDETECT1_Msk (0x1UL << MAIN_INTENEVENTSGPIOSET_EVENTGPIOEDGEDETECT1_Pos) /*!< Bit
                                                                            mask of EVENTGPIOEDGEDETECT1 field.*/                 
#define MAIN_INTENEVENTSGPIOSET_EVENTGPIOEDGEDETECT1_LOW (0) /*!< low                                                          */
#define MAIN_INTENEVENTSGPIOSET_EVENTGPIOEDGEDETECT1_HIGH (1) /*!< high                                                        */

/* EVENTGPIOEDGEDETECT2 @Bit 2 : Writing 1 enables interrupts from EVENTGPIOEDGEDETECT2 */
#define MAIN_INTENEVENTSGPIOSET_EVENTGPIOEDGEDETECT2_Pos (2UL) /*!< Position of EVENTGPIOEDGEDETECT2 field.                    */
#define MAIN_INTENEVENTSGPIOSET_EVENTGPIOEDGEDETECT2_Msk (0x1UL << MAIN_INTENEVENTSGPIOSET_EVENTGPIOEDGEDETECT2_Pos) /*!< Bit
                                                                            mask of EVENTGPIOEDGEDETECT2 field.*/                 
#define MAIN_INTENEVENTSGPIOSET_EVENTGPIOEDGEDETECT2_LOW (0) /*!< low                                                          */
#define MAIN_INTENEVENTSGPIOSET_EVENTGPIOEDGEDETECT2_HIGH (1) /*!< high                                                        */

/* EVENTGPIOEDGEDETECT3 @Bit 3 : Writing 1 enables interrupts from EVENTGPIOEDGEDETECT3 */
#define MAIN_INTENEVENTSGPIOSET_EVENTGPIOEDGEDETECT3_Pos (3UL) /*!< Position of EVENTGPIOEDGEDETECT3 field.                    */
#define MAIN_INTENEVENTSGPIOSET_EVENTGPIOEDGEDETECT3_Msk (0x1UL << MAIN_INTENEVENTSGPIOSET_EVENTGPIOEDGEDETECT3_Pos) /*!< Bit
                                                                            mask of EVENTGPIOEDGEDETECT3 field.*/                 
#define MAIN_INTENEVENTSGPIOSET_EVENTGPIOEDGEDETECT3_LOW (0) /*!< low                                                          */
#define MAIN_INTENEVENTSGPIOSET_EVENTGPIOEDGEDETECT3_HIGH (1) /*!< high                                                        */

/* EVENTGPIOEDGEDETECT4 @Bit 4 : Writing 1 enables interrupts from EVENTGPIOEDGEDETECT4 */
#define MAIN_INTENEVENTSGPIOSET_EVENTGPIOEDGEDETECT4_Pos (4UL) /*!< Position of EVENTGPIOEDGEDETECT4 field.                    */
#define MAIN_INTENEVENTSGPIOSET_EVENTGPIOEDGEDETECT4_Msk (0x1UL << MAIN_INTENEVENTSGPIOSET_EVENTGPIOEDGEDETECT4_Pos) /*!< Bit
                                                                            mask of EVENTGPIOEDGEDETECT4 field.*/                 
#define MAIN_INTENEVENTSGPIOSET_EVENTGPIOEDGEDETECT4_LOW (0) /*!< low                                                          */
#define MAIN_INTENEVENTSGPIOSET_EVENTGPIOEDGEDETECT4_HIGH (1) /*!< high                                                        */


/* MAIN_INTENEVENTSGPIOCLR: GPIO Event Interrupt Enable Clear */

/* EVENTGPIOEDGEDETECT0 @Bit 0 : Writing 1 disables interrupts from EVENTGPIOEDGEDETECT0 */
#define MAIN_INTENEVENTSGPIOCLR_EVENTGPIOEDGEDETECT0_Pos (0UL) /*!< Position of EVENTGPIOEDGEDETECT0 field.                    */
#define MAIN_INTENEVENTSGPIOCLR_EVENTGPIOEDGEDETECT0_Msk (0x1UL << MAIN_INTENEVENTSGPIOCLR_EVENTGPIOEDGEDETECT0_Pos) /*!< Bit
                                                                            mask of EVENTGPIOEDGEDETECT0 field.*/                 
#define MAIN_INTENEVENTSGPIOCLR_EVENTGPIOEDGEDETECT0_LOW (0) /*!< low                                                          */
#define MAIN_INTENEVENTSGPIOCLR_EVENTGPIOEDGEDETECT0_HIGH (1) /*!< high                                                        */

/* EVENTGPIOEDGEDETECT1 @Bit 1 : Writing 1 disables interrupts from EVENTGPIOEDGEDETECT1 */
#define MAIN_INTENEVENTSGPIOCLR_EVENTGPIOEDGEDETECT1_Pos (1UL) /*!< Position of EVENTGPIOEDGEDETECT1 field.                    */
#define MAIN_INTENEVENTSGPIOCLR_EVENTGPIOEDGEDETECT1_Msk (0x1UL << MAIN_INTENEVENTSGPIOCLR_EVENTGPIOEDGEDETECT1_Pos) /*!< Bit
                                                                            mask of EVENTGPIOEDGEDETECT1 field.*/                 
#define MAIN_INTENEVENTSGPIOCLR_EVENTGPIOEDGEDETECT1_LOW (0) /*!< low                                                          */
#define MAIN_INTENEVENTSGPIOCLR_EVENTGPIOEDGEDETECT1_HIGH (1) /*!< high                                                        */

/* EVENTGPIOEDGEDETECT2 @Bit 2 : Writing 1 disables interrupts from EVENTGPIOEDGEDETECT2 */
#define MAIN_INTENEVENTSGPIOCLR_EVENTGPIOEDGEDETECT2_Pos (2UL) /*!< Position of EVENTGPIOEDGEDETECT2 field.                    */
#define MAIN_INTENEVENTSGPIOCLR_EVENTGPIOEDGEDETECT2_Msk (0x1UL << MAIN_INTENEVENTSGPIOCLR_EVENTGPIOEDGEDETECT2_Pos) /*!< Bit
                                                                            mask of EVENTGPIOEDGEDETECT2 field.*/                 
#define MAIN_INTENEVENTSGPIOCLR_EVENTGPIOEDGEDETECT2_LOW (0) /*!< low                                                          */
#define MAIN_INTENEVENTSGPIOCLR_EVENTGPIOEDGEDETECT2_HIGH (1) /*!< high                                                        */

/* EVENTGPIOEDGEDETECT3 @Bit 3 : Writing 1 disables interrupts from EVENTGPIOEDGEDETECT3 */
#define MAIN_INTENEVENTSGPIOCLR_EVENTGPIOEDGEDETECT3_Pos (3UL) /*!< Position of EVENTGPIOEDGEDETECT3 field.                    */
#define MAIN_INTENEVENTSGPIOCLR_EVENTGPIOEDGEDETECT3_Msk (0x1UL << MAIN_INTENEVENTSGPIOCLR_EVENTGPIOEDGEDETECT3_Pos) /*!< Bit
                                                                            mask of EVENTGPIOEDGEDETECT3 field.*/                 
#define MAIN_INTENEVENTSGPIOCLR_EVENTGPIOEDGEDETECT3_LOW (0) /*!< low                                                          */
#define MAIN_INTENEVENTSGPIOCLR_EVENTGPIOEDGEDETECT3_HIGH (1) /*!< high                                                        */

/* EVENTGPIOEDGEDETECT4 @Bit 4 : Writing 1 disables interrupts from EVENTGPIOEDGEDETECT4 */
#define MAIN_INTENEVENTSGPIOCLR_EVENTGPIOEDGEDETECT4_Pos (4UL) /*!< Position of EVENTGPIOEDGEDETECT4 field.                    */
#define MAIN_INTENEVENTSGPIOCLR_EVENTGPIOEDGEDETECT4_Msk (0x1UL << MAIN_INTENEVENTSGPIOCLR_EVENTGPIOEDGEDETECT4_Pos) /*!< Bit
                                                                            mask of EVENTGPIOEDGEDETECT4 field.*/                 
#define MAIN_INTENEVENTSGPIOCLR_EVENTGPIOEDGEDETECT4_LOW (0) /*!< low                                                          */
#define MAIN_INTENEVENTSGPIOCLR_EVENTGPIOEDGEDETECT4_HIGH (1) /*!< high                                                        */



/* =========================================================================================================================== */
/* ================                                          SYSTEM                                          ================ */
/* =========================================================================================================================== */

/* ====================================================== Struct SYSTEM ====================================================== */
/**
  * @brief Neutrino SYSTEM registers
  */
typedef struct {                                     /*!< SYSTEM Structure                                                     */
  __IM  uint8_t   RESERVED;
  __IM  uint8_t   SYSLABEL;                          /*!< (@ 0x00000001) Label Value                                           */
}NPM_SYSTEM_Type;                                    /*!< Size = 2 (0x002)                                                     */

/* SYSTEM_SYSLABEL: Label Value */

/* SYSLABEL @Bits 0..7 : label word */
#define SYSTEM_SYSLABEL_SYSLABEL_Pos (0UL)           /*!< Position of SYSLABEL field.                                          */
#define SYSTEM_SYSLABEL_SYSLABEL_Msk (0xFFUL << SYSTEM_SYSLABEL_SYSLABEL_Pos) /*!< Bit mask of SYSLABEL field.                 */



/* =========================================================================================================================== */
/* ================                                          VBUSIN                                          ================ */
/* =========================================================================================================================== */

/* ====================================================== Struct VBUSIN ====================================================== */
/**
  * @brief Neutrino VBUSIN registers
  */
typedef struct {                                     /*!< VBUSIN Structure                                                     */
  __OM  uint8_t   TASKUPDATEILIMSW;                  /*!< (@ 0x00000000) Select Input Current limit for VBUS                   */
  __IOM uint8_t   VBUSINILIM0;                       /*!< (@ 0x00000001) Select Input Current limit for VBUS   NOTE: Reset value
                                                                         from OTP, value listed in this table may not be
                                                                         correct.*/                                               
  __IM  uint8_t   RESERVED;
  __IOM uint8_t   VBUSSUSPEND;                       /*!< (@ 0x00000003) Suspend mode enable                                   */
  __IM  uint8_t   RESERVED1;
  __IM  uint8_t   USBCDETECTSTATUS;                  /*!< (@ 0x00000005) VBUS CC comparator status flags                       */
  __IM  uint8_t   RESERVED2;
  __IM  uint8_t   VBUSINSTATUS;                      /*!< (@ 0x00000007) VBUS status flags                                     */
}NPM_VBUSIN_Type;                                    /*!< Size = 8 (0x008)                                                     */

/* VBUSIN_TASKUPDATEILIMSW: Select Input Current limit for VBUS */

/* TASKUPDATEILIM @Bit 0 : Set to switch from vbusinIlimStartup to vbusinIlim0 */
#define VBUSIN_TASKUPDATEILIMSW_TASKUPDATEILIM_Pos (0UL) /*!< Position of TASKUPDATEILIM field.                                */
#define VBUSIN_TASKUPDATEILIMSW_TASKUPDATEILIM_Msk (0x1UL << VBUSIN_TASKUPDATEILIMSW_TASKUPDATEILIM_Pos) /*!< Bit mask of
                                                                            TASKUPDATEILIM field.*/                               
#define VBUSIN_TASKUPDATEILIMSW_TASKUPDATEILIM_NOEFFECT (0) /*!< No effect                                                     */
#define VBUSIN_TASKUPDATEILIMSW_TASKUPDATEILIM_SELVBUSILIM0 (1) /*!< Set to use vbusinilim0. Vbus removal results in switch back
                                                                     to vbusinIlimStartup*/                                       


/* VBUSIN_VBUSINILIM0: Select Input Current limit for VBUS

        NOTE: Reset value from OTP, value listed in this table may
                        not be correct. */                                                                                        
                                                                                                                                  

/* VBUSINILIM0 @Bits 0..3 : Input current limit for VBUS selected by Host */
#define VBUSIN_VBUSINILIM0_VBUSINILIM0_Pos (0UL)     /*!< Position of VBUSINILIM0 field.                                       */
#define VBUSIN_VBUSINILIM0_VBUSINILIM0_Msk (0xFUL << VBUSIN_VBUSINILIM0_VBUSINILIM0_Pos) /*!< Bit mask of VBUSINILIM0 field.   */
#define VBUSIN_VBUSINILIM0_VBUSINILIM0_500MA (0)     /*!< 500mA                                                                */
#define VBUSIN_VBUSINILIM0_VBUSINILIM0_100MA (1)     /*!< 100mA                                                                */
#define VBUSIN_VBUSINILIM0_VBUSINILIM0_NOTUSED2 (2)  /*!< 100mA (Not used)                                                     */
#define VBUSIN_VBUSINILIM0_VBUSINILIM0_NOTUSED3 (3)  /*!< 100mA (Not used)                                                     */
#define VBUSIN_VBUSINILIM0_VBUSINILIM0_NOTUSED4 (4)  /*!< 100mA (Not used)                                                     */
#define VBUSIN_VBUSINILIM0_VBUSINILIM0_DEFAULT500MA (5) /*!< 500mA (default)                                                   */
#define VBUSIN_VBUSINILIM0_VBUSINILIM0_600MA (6)     /*!< 600mA                                                                */
#define VBUSIN_VBUSINILIM0_VBUSINILIM0_700MA (7)     /*!< 700mA                                                                */
#define VBUSIN_VBUSINILIM0_VBUSINILIM0_800MA (8)     /*!< 800mA                                                                */
#define VBUSIN_VBUSINILIM0_VBUSINILIM0_900MA (9)     /*!< 900mA                                                                */
#define VBUSIN_VBUSINILIM0_VBUSINILIM0_1000MA (10)   /*!< 1000mA                                                               */
#define VBUSIN_VBUSINILIM0_VBUSINILIM0_1100MA (11)   /*!< 1100mA                                                               */
#define VBUSIN_VBUSINILIM0_VBUSINILIM0_1200MA (12)   /*!< 1200mA                                                               */
#define VBUSIN_VBUSINILIM0_VBUSINILIM0_1300MA (13)   /*!< 1300mA                                                               */
#define VBUSIN_VBUSINILIM0_VBUSINILIM0_1400MA (14)   /*!< 1400mA                                                               */
#define VBUSIN_VBUSINILIM0_VBUSINILIM0_1500MA (15)   /*!< 1500mA                                                               */


/* VBUSIN_VBUSSUSPEND: Suspend mode enable */

/* VBUSSUSPENDENA @Bit 0 : VBUS suspend control bit */
#define VBUSIN_VBUSSUSPEND_VBUSSUSPENDENA_Pos (0UL)  /*!< Position of VBUSSUSPENDENA field.                                    */
#define VBUSIN_VBUSSUSPEND_VBUSSUSPENDENA_Msk (0x1UL << VBUSIN_VBUSSUSPEND_VBUSSUSPENDENA_Pos) /*!< Bit mask of VBUSSUSPENDENA
                                                                            field.*/                                              
#define VBUSIN_VBUSSUSPEND_VBUSSUSPENDENA_NORMAL (0) /*!< Normal mode                                                          */
#define VBUSIN_VBUSSUSPEND_VBUSSUSPENDENA_SUSPENDMODE (1) /*!< Suspend Mode                                                    */


/* VBUSIN_USBCDETECTSTATUS: VBUS CC comparator status flags */

/* VBUSINCC1CMP @Bits 0..1 : CC1 Charger detection comparator output */
#define VBUSIN_USBCDETECTSTATUS_VBUSINCC1CMP_Pos (0UL) /*!< Position of VBUSINCC1CMP field.                                    */
#define VBUSIN_USBCDETECTSTATUS_VBUSINCC1CMP_Msk (0x3UL << VBUSIN_USBCDETECTSTATUS_VBUSINCC1CMP_Pos) /*!< Bit mask of
                                                                            VBUSINCC1CMP field.*/                                 
#define VBUSIN_USBCDETECTSTATUS_VBUSINCC1CMP_NOCONNECTION (0) /*!< no connection                                               */
#define VBUSIN_USBCDETECTSTATUS_VBUSINCC1CMP_DEFAULTUSB (1) /*!< Default USB 100/500mA                                         */
#define VBUSIN_USBCDETECTSTATUS_VBUSINCC1CMP_1A5HIGHPOWER (2) /*!< 1.5A High Power                                             */
#define VBUSIN_USBCDETECTSTATUS_VBUSINCC1CMP_3AHIGHPOWER (3) /*!< 3A High Power                                                */

/* VBUSINCC2CMP @Bits 2..3 : CC2 Charger detection comparator output */
#define VBUSIN_USBCDETECTSTATUS_VBUSINCC2CMP_Pos (2UL) /*!< Position of VBUSINCC2CMP field.                                    */
#define VBUSIN_USBCDETECTSTATUS_VBUSINCC2CMP_Msk (0x3UL << VBUSIN_USBCDETECTSTATUS_VBUSINCC2CMP_Pos) /*!< Bit mask of
                                                                            VBUSINCC2CMP field.*/                                 
#define VBUSIN_USBCDETECTSTATUS_VBUSINCC2CMP_NOCONNECTION (0) /*!< no connection                                               */
#define VBUSIN_USBCDETECTSTATUS_VBUSINCC2CMP_DEFAULTUSB (1) /*!< Default USB 100/500mA                                         */
#define VBUSIN_USBCDETECTSTATUS_VBUSINCC2CMP_1A5HIGHPOWER (2) /*!< 1.5A High Power                                             */
#define VBUSIN_USBCDETECTSTATUS_VBUSINCC2CMP_3AHIGHPOWER (3) /*!< 3A High Power                                                */


/* VBUSIN_VBUSINSTATUS: VBUS status flags */

/* VBUSINPRESENT @Bit 0 : Vbus has been detected */
#define VBUSIN_VBUSINSTATUS_VBUSINPRESENT_Pos (0UL)  /*!< Position of VBUSINPRESENT field.                                     */
#define VBUSIN_VBUSINSTATUS_VBUSINPRESENT_Msk (0x1UL << VBUSIN_VBUSINSTATUS_VBUSINPRESENT_Pos) /*!< Bit mask of VBUSINPRESENT
                                                                            field.*/                                              
#define VBUSIN_VBUSINSTATUS_VBUSINPRESENT_NOTDETECTED (0) /*!< NotDetected                                                     */
#define VBUSIN_VBUSINSTATUS_VBUSINPRESENT_DETECTED (1) /*!< Detected                                                           */

/* VBUSINCURRLIMACTIVE @Bit 1 : VBUS Current limit detected */
#define VBUSIN_VBUSINSTATUS_VBUSINCURRLIMACTIVE_Pos (1UL) /*!< Position of VBUSINCURRLIMACTIVE field.                          */
#define VBUSIN_VBUSINSTATUS_VBUSINCURRLIMACTIVE_Msk (0x1UL << VBUSIN_VBUSINSTATUS_VBUSINCURRLIMACTIVE_Pos) /*!< Bit mask of
                                                                            VBUSINCURRLIMACTIVE field.*/                          
#define VBUSIN_VBUSINSTATUS_VBUSINCURRLIMACTIVE_NOTDETECTED (0) /*!< NotDetected                                               */
#define VBUSIN_VBUSINSTATUS_VBUSINCURRLIMACTIVE_DETECTED (1) /*!< Detected                                                     */

/* VBUSINOVRPROTACTIVE @Bit 2 : VBUS Over voltage protection Active */
#define VBUSIN_VBUSINSTATUS_VBUSINOVRPROTACTIVE_Pos (2UL) /*!< Position of VBUSINOVRPROTACTIVE field.                          */
#define VBUSIN_VBUSINSTATUS_VBUSINOVRPROTACTIVE_Msk (0x1UL << VBUSIN_VBUSINSTATUS_VBUSINOVRPROTACTIVE_Pos) /*!< Bit mask of
                                                                            VBUSINOVRPROTACTIVE field.*/                          
#define VBUSIN_VBUSINSTATUS_VBUSINOVRPROTACTIVE_NOTACTIVE (0) /*!< NotActive                                                   */
#define VBUSIN_VBUSINSTATUS_VBUSINOVRPROTACTIVE_ACTIVE (1) /*!< Active                                                         */

/* VBUSINUNDERVOLTAGE @Bit 3 : VBUS Under voltage detected */
#define VBUSIN_VBUSINSTATUS_VBUSINUNDERVOLTAGE_Pos (3UL) /*!< Position of VBUSINUNDERVOLTAGE field.                            */
#define VBUSIN_VBUSINSTATUS_VBUSINUNDERVOLTAGE_Msk (0x1UL << VBUSIN_VBUSINSTATUS_VBUSINUNDERVOLTAGE_Pos) /*!< Bit mask of
                                                                            VBUSINUNDERVOLTAGE field.*/                           
#define VBUSIN_VBUSINSTATUS_VBUSINUNDERVOLTAGE_NOTDETECTED (0) /*!< NotDetected                                                */
#define VBUSIN_VBUSINSTATUS_VBUSINUNDERVOLTAGE_DETECTED (1) /*!< Detected                                                      */

/* VBUSINSUSPENDMODEACTIVE @Bit 4 : VBUS suspended */
#define VBUSIN_VBUSINSTATUS_VBUSINSUSPENDMODEACTIVE_Pos (4UL) /*!< Position of VBUSINSUSPENDMODEACTIVE field.                  */
#define VBUSIN_VBUSINSTATUS_VBUSINSUSPENDMODEACTIVE_Msk (0x1UL << VBUSIN_VBUSINSTATUS_VBUSINSUSPENDMODEACTIVE_Pos) /*!< Bit mask
                                                                            of VBUSINSUSPENDMODEACTIVE field.*/                   
#define VBUSIN_VBUSINSTATUS_VBUSINSUSPENDMODEACTIVE_NORMAL (0) /*!< Normal                                                     */
#define VBUSIN_VBUSINSTATUS_VBUSINSUSPENDMODEACTIVE_SUSPEND (1) /*!< Suspended                                                 */

/* VBUSINVBUSOUTACTIVE @Bit 5 : VBUS Out is Active */
#define VBUSIN_VBUSINSTATUS_VBUSINVBUSOUTACTIVE_Pos (5UL) /*!< Position of VBUSINVBUSOUTACTIVE field.                          */
#define VBUSIN_VBUSINSTATUS_VBUSINVBUSOUTACTIVE_Msk (0x1UL << VBUSIN_VBUSINSTATUS_VBUSINVBUSOUTACTIVE_Pos) /*!< Bit mask of
                                                                            VBUSINVBUSOUTACTIVE field.*/                          
#define VBUSIN_VBUSINSTATUS_VBUSINVBUSOUTACTIVE_NOTACTIVE (0) /*!< NotActive                                                   */
#define VBUSIN_VBUSINSTATUS_VBUSINVBUSOUTACTIVE_ACTIVE (1) /*!< Active                                                         */



/* =========================================================================================================================== */
/* ================                                         BCHARGER                                         ================ */
/* =========================================================================================================================== */

/* ===================================================== Struct BCHARGER ===================================================== */
/**
  * @brief Neutrino BCHARGER registers
  */
typedef struct {                                     /*!< BCHARGER Structure                                                   */
  __OM  uint8_t   TASKRELEASEERR;                    /*!< (@ 0x00000000) Release Charger from Error                            */
  __OM  uint8_t   TASKCLEARCHGERR;                   /*!< (@ 0x00000001) Clear error registers                                 */
  __OM  uint8_t   TASKCLEARSAFETYTIMER;              /*!< (@ 0x00000002) Clear safety timers                                   */
  __IM  uint8_t   RESERVED;
  __IOM uint8_t   BCHGENABLESET;                     /*!< (@ 0x00000004) Charger Enable Set                                    */
  __IOM uint8_t   BCHGENABLECLR;                     /*!< (@ 0x00000005) Charger Enable Clear                                  */
  __IOM uint8_t   BCHGDISABLESET;                    /*!< (@ 0x00000006) Charger Disable Recharge Set                          */
  __IOM uint8_t   BCHGDISABLECLR;                    /*!< (@ 0x00000007) Charger Disable Recharge Clear                        */
  __IOM uint8_t   BCHGISETMSB;                       /*!< (@ 0x00000008) Battery Charger Current Configuration                 */
  __IOM uint8_t   BCHGISETLSB;                       /*!< (@ 0x00000009) Battery Charger Current Configuration                 */
  __IOM uint8_t   BCHGISETDISCHARGEMSB;              /*!< (@ 0x0000000A) Battery Charger Discharge Configuration               */
  __IOM uint8_t   BCHGISETDISCHARGELSB;              /*!< (@ 0x0000000B) Battery Charger Discharge Configuration               */
  __IOM uint8_t   BCHGVTERM;                         /*!< (@ 0x0000000C) Battery Charger Termination Voltage Normal temp       */
  __IOM uint8_t   BCHGVTERMR;                        /*!< (@ 0x0000000D) Battery Charger Termination Voltage Warm temp         */
  __IOM uint8_t   BCHGVTRICKLESEL;                   /*!< (@ 0x0000000E) Battery Charger Trickle Level Select                  */
  __IOM uint8_t   BCHGITERMSEL;                      /*!< (@ 0x0000000F) Battery Charger ITERM Level Select                    */
  __IOM uint8_t   NTCCOLD;                           /*!< (@ 0x00000010) NTC threshold for COLD temperature region             */
  __IOM uint8_t   NTCCOLDLSB;                        /*!< (@ 0x00000011) NTC threshold for COLD temperature region             */
  __IOM uint8_t   NTCCOOL;                           /*!< (@ 0x00000012) NTC threshold for COOL temperature region             */
  __IOM uint8_t   NTCCOOLLSB;                        /*!< (@ 0x00000013) NTC threshold for COOL temperature region             */
  __IOM uint8_t   NTCWARM;                           /*!< (@ 0x00000014) NTC threshold for WARM temperature region             */
  __IOM uint8_t   NTCWARMLSB;                        /*!< (@ 0x00000015) NTC threshold for WARM temperature region             */
  __IOM uint8_t   NTCHOT;                            /*!< (@ 0x00000016) NTC threshold for HOT temperature region              */
  __IOM uint8_t   NTCHOTLSB;                         /*!< (@ 0x00000017) NTC threshold for HOT temperature region              */
  __IOM uint8_t   DIETEMPSTOP;                       /*!< (@ 0x00000018) DIE TEMP threshold for stop charging                  */
  __IOM uint8_t   DIETEMPSTOPLSB;                    /*!< (@ 0x00000019) DIE TEMP threshold for stop charging lsb              */
  __IOM uint8_t   DIETEMPRESUME;                     /*!< (@ 0x0000001A) DIE TEMP threshold for resuming charging              */
  __IOM uint8_t   DIETEMPRESUMELSB;                  /*!< (@ 0x0000001B) DIE TEMP threshold for resuming charging lsb          */
  __IM  uint8_t   RESERVED1[17];
  __IM  uint8_t   BCHGILIMSTATUS;                    /*!< (@ 0x0000002D) BCHARGER Ilim Status                                  */
  __IM  uint8_t   RESERVED2[4];
  __IM  uint8_t   NTCSTATUS;                         /*!< (@ 0x00000032) Ntc Comparator Status                                 */
  __IM  uint8_t   DIETEMPSTATUS;                     /*!< (@ 0x00000033) DieTemp Comparator Status                             */
  __IM  uint8_t   BCHGCHARGESTATUS;                  /*!< (@ 0x00000034) Charging Status                                       */
  __IM  uint8_t   RESERVED3;
  __IM  uint8_t   BCHGERRREASON;                     /*!< (@ 0x00000036) Charger-FSM Error. Latched error reasons. Cleared with
                                                                         TASKS_CLEAR_CHG_ERR*/                                    
  __IM  uint8_t   BCHGERRSENSOR;                     /*!< (@ 0x00000037) Charger-FSM Error. Latched sensor values. Cleared with
                                                                         TASKS_CLEAR_CHG_ERR*/                                    
  __IM  uint8_t  RESERVED4[4];
  __IOM uint8_t   BCHGCONFIG;                        /*!< (@ 0x0000003C) Charger configuration                                 */
}NPM_BCHARGER_Type;                                  /*!< Size = 61 (0x03D)                                                    */

/* BCHARGER_TASKRELEASEERR: Release Charger from Error */

/* TASKRELEASEERROR @Bit 0 : SW release from Charger Error state */
#define BCHARGER_TASKRELEASEERR_TASKRELEASEERROR_Pos (0UL) /*!< Position of TASKRELEASEERROR field.                            */
#define BCHARGER_TASKRELEASEERR_TASKRELEASEERROR_Msk (0x1UL << BCHARGER_TASKRELEASEERR_TASKRELEASEERROR_Pos) /*!< Bit mask of
                                                                            TASKRELEASEERROR field.*/                             
#define BCHARGER_TASKRELEASEERR_TASKRELEASEERROR_NOEFFECT (0) /*!< No effect                                                   */
#define BCHARGER_TASKRELEASEERR_TASKRELEASEERROR_TRIGGER (1) /*!< Trigger task                                                 */


/* BCHARGER_TASKCLEARCHGERR: Clear error registers */

/* TASKCLEARCHGERR @Bit 0 : Clear registers BCHGERRREASON and BCHGERRSENSOR */
#define BCHARGER_TASKCLEARCHGERR_TASKCLEARCHGERR_Pos (0UL) /*!< Position of TASKCLEARCHGERR field.                             */
#define BCHARGER_TASKCLEARCHGERR_TASKCLEARCHGERR_Msk (0x1UL << BCHARGER_TASKCLEARCHGERR_TASKCLEARCHGERR_Pos) /*!< Bit mask of
                                                                            TASKCLEARCHGERR field.*/                              
#define BCHARGER_TASKCLEARCHGERR_TASKCLEARCHGERR_NOEFFECT (0) /*!< No effect                                                   */
#define BCHARGER_TASKCLEARCHGERR_TASKCLEARCHGERR_TRIGGER (1) /*!< Trigger task                                                 */


/* BCHARGER_TASKCLEARSAFETYTIMER: Clear safety timers */

/* TASKCLEARSAFETYTIMER @Bit 0 : Clear TRICKLE and CHARGE safety timers */
#define BCHARGER_TASKCLEARSAFETYTIMER_TASKCLEARSAFETYTIMER_Pos (0UL) /*!< Position of TASKCLEARSAFETYTIMER field.              */
#define BCHARGER_TASKCLEARSAFETYTIMER_TASKCLEARSAFETYTIMER_Msk (0x1UL << BCHARGER_TASKCLEARSAFETYTIMER_TASKCLEARSAFETYTIMER_Pos)
                                                                            /*!< Bit mask of TASKCLEARSAFETYTIMER field.*/        
#define BCHARGER_TASKCLEARSAFETYTIMER_TASKCLEARSAFETYTIMER_NOEFFECT (0) /*!< No effect                                         */
#define BCHARGER_TASKCLEARSAFETYTIMER_TASKCLEARSAFETYTIMER_TRIGGER (1) /*!< Trigger task                                       */


/* BCHARGER_BCHGENABLESET: Charger Enable Set */

/* ENABLECHARGING @Bit 0 : Battery Charger Enable SET.
(Read 0: Charging disabled).
(Read 1: Charging enabled). */
#define BCHARGER_BCHGENABLESET_ENABLECHARGING_Pos (0UL) /*!< Position of ENABLECHARGING field.                                 */
#define BCHARGER_BCHGENABLESET_ENABLECHARGING_Msk (0x1UL << BCHARGER_BCHGENABLESET_ENABLECHARGING_Pos) /*!< Bit mask of
                                                                            ENABLECHARGING field.*/                               
#define BCHARGER_BCHGENABLESET_ENABLECHARGING_NOEFFECT (0) /*!< No effect                                                      */
#define BCHARGER_BCHGENABLESET_ENABLECHARGING_ENABLECHG (1) /*!< Enable Battery Charging                                       */

/* ENABLEFULLCHGCOOL @Bit 1 : Battery Charger Enable Full Charge in Cool temp SET.
(Read 0: 50 percent charge current value of
                              BCHGISETMSB and BCHGISETLSB registers). 
(Read 1: 100 percent charge current value of BCHGISETMSB
                              and BCHGISETLSB registers). */                                                                      
                                                                                                                                  
#define BCHARGER_BCHGENABLESET_ENABLEFULLCHGCOOL_Pos (1UL) /*!< Position of ENABLEFULLCHGCOOL field.                           */
#define BCHARGER_BCHGENABLESET_ENABLEFULLCHGCOOL_Msk (0x1UL << BCHARGER_BCHGENABLESET_ENABLEFULLCHGCOOL_Pos) /*!< Bit mask of
                                                                            ENABLEFULLCHGCOOL field.*/                            
#define BCHARGER_BCHGENABLESET_ENABLEFULLCHGCOOL_NOEFFECT (0) /*!< No effect                                                   */
#define BCHARGER_BCHGENABLESET_ENABLEFULLCHGCOOL_ENABLECOOL (1) /*!< Enable Charging of Cool battery                           */


/* BCHARGER_BCHGENABLECLR: Charger Enable Clear */

/* ENABLECHARGING @Bit 0 : Battery Charger Enable CLEAR.
(Read 0: Charging disabled).
(Read 1: Charging enabled). */
#define BCHARGER_BCHGENABLECLR_ENABLECHARGING_Pos (0UL) /*!< Position of ENABLECHARGING field.                                 */
#define BCHARGER_BCHGENABLECLR_ENABLECHARGING_Msk (0x1UL << BCHARGER_BCHGENABLECLR_ENABLECHARGING_Pos) /*!< Bit mask of
                                                                            ENABLECHARGING field.*/                               
#define BCHARGER_BCHGENABLECLR_ENABLECHARGING_NOEFFECT (0) /*!< No effect                                                      */
#define BCHARGER_BCHGENABLECLR_ENABLECHARGING_DISABLECHG (1) /*!< Disable Battery Charging                                     */

/* ENABLEFULLCHGCOOL @Bit 1 : Battery Charger Enable Full Charge in Cool temp CLEAR. 
(Read 0: 50 percent charge current value
                              of BCHGISETMSB and BCHGISETLSB registers). 
(Read 1: 100 percent charge current value of
                              BCHGISETMSB and BCHGISETLSB registers). */                                                          
                                                                                                                                  
#define BCHARGER_BCHGENABLECLR_ENABLEFULLCHGCOOL_Pos (1UL) /*!< Position of ENABLEFULLCHGCOOL field.                           */
#define BCHARGER_BCHGENABLECLR_ENABLEFULLCHGCOOL_Msk (0x1UL << BCHARGER_BCHGENABLECLR_ENABLEFULLCHGCOOL_Pos) /*!< Bit mask of
                                                                            ENABLEFULLCHGCOOL field.*/                            
#define BCHARGER_BCHGENABLECLR_ENABLEFULLCHGCOOL_NOEFFECT (0) /*!< No effect                                                   */
#define BCHARGER_BCHGENABLECLR_ENABLEFULLCHGCOOL_DISABLECOOL (1) /*!< Disable Charging of Cool battery                         */


/* BCHARGER_BCHGDISABLESET: Charger Disable Recharge Set */

/* DISABLERECHARGE @Bit 0 : Battery Charger Disable Recharge SET.
(Read 0: Recharge enabled).
(Read 1: Recharge disabled). */
#define BCHARGER_BCHGDISABLESET_DISABLERECHARGE_Pos (0UL) /*!< Position of DISABLERECHARGE field.                              */
#define BCHARGER_BCHGDISABLESET_DISABLERECHARGE_Msk (0x1UL << BCHARGER_BCHGDISABLESET_DISABLERECHARGE_Pos) /*!< Bit mask of
                                                                            DISABLERECHARGE field.*/                              
#define BCHARGER_BCHGDISABLESET_DISABLERECHARGE_NOEFFECT (0) /*!< No effect                                                    */
#define BCHARGER_BCHGDISABLESET_DISABLERECHARGE_DISABLERCHG (1) /*!< Disable Recharging of battery once charged                */

/* DISABLENTC @Bit 1 : Battery Charger ignore NTC temperature limits  SET.
(Read 0: NTC values enabled)
(Read 1: NTC values
                       ignored) */                                                                                                
                                                                                                                                  
#define BCHARGER_BCHGDISABLESET_DISABLENTC_Pos (1UL) /*!< Position of DISABLENTC field.                                        */
#define BCHARGER_BCHGDISABLESET_DISABLENTC_Msk (0x1UL << BCHARGER_BCHGDISABLESET_DISABLENTC_Pos) /*!< Bit mask of DISABLENTC
                                                                            field.*/                                              
#define BCHARGER_BCHGDISABLESET_DISABLENTC_NOEFFECT (0) /*!< No effect                                                         */
#define BCHARGER_BCHGDISABLESET_DISABLENTC_IGNORENTC (1) /*!< Charging will ignore the NTC resistor measure                    */


/* BCHARGER_BCHGDISABLECLR: Charger Disable Recharge Clear */

/* DISABLERECHARGE @Bit 0 : Battery Charger Disable Recharge CLEAR.
(Read 0: Recharge enabled).
(Read 1: Recharge disabled). */
#define BCHARGER_BCHGDISABLECLR_DISABLERECHARGE_Pos (0UL) /*!< Position of DISABLERECHARGE field.                              */
#define BCHARGER_BCHGDISABLECLR_DISABLERECHARGE_Msk (0x1UL << BCHARGER_BCHGDISABLECLR_DISABLERECHARGE_Pos) /*!< Bit mask of
                                                                            DISABLERECHARGE field.*/                              
#define BCHARGER_BCHGDISABLECLR_DISABLERECHARGE_NOEFFECT (0) /*!< No effect                                                    */
#define BCHARGER_BCHGDISABLECLR_DISABLERECHARGE_ENABLERCHG (1) /*!< Enable Recharging of battery once charged                  */

/* DISABLENTC @Bit 1 : Battery Charger ignore NTC temperature limits CLEAR.
(Read 0: NTC values enabled).
(Read 1: NTC values
                       ignored). */                                                                                               
                                                                                                                                  
#define BCHARGER_BCHGDISABLECLR_DISABLENTC_Pos (1UL) /*!< Position of DISABLENTC field.                                        */
#define BCHARGER_BCHGDISABLECLR_DISABLENTC_Msk (0x1UL << BCHARGER_BCHGDISABLECLR_DISABLENTC_Pos) /*!< Bit mask of DISABLENTC
                                                                            field.*/                                              
#define BCHARGER_BCHGDISABLECLR_DISABLENTC_NOEFFECT (0) /*!< No effect                                                         */
#define BCHARGER_BCHGDISABLECLR_DISABLENTC_USENTC (1) /*!< Charging will use the NTC resistor measure                          */


/* BCHARGER_BCHGISETMSB: Battery Charger Current Configuration */

/* BCHGISETCHARGEMSB @Bits 0..7 : Battery Charger current setting (BCHG_ISET_CHARGE MSB bits [8:1]) default 32mA. See more from
                                  Charging Current chapter. */                                                                    
                                                                                                                                  
#define BCHARGER_BCHGISETMSB_BCHGISETCHARGEMSB_Pos (0UL) /*!< Position of BCHGISETCHARGEMSB field.                             */
#define BCHARGER_BCHGISETMSB_BCHGISETCHARGEMSB_Msk (0xFFUL << BCHARGER_BCHGISETMSB_BCHGISETCHARGEMSB_Pos) /*!< Bit mask of
                                                                            BCHGISETCHARGEMSB field.*/                            


/* BCHARGER_BCHGISETLSB: Battery Charger Current Configuration */

/* BCHGISETCHARGELSB @Bit 0 : Battery Charger current fine tune by 2mA (BCHG_ISET_CHARGE LSB bit [0]). See more from Charging
                              Current chapter. */                                                                                 
                                                                                                                                  
#define BCHARGER_BCHGISETLSB_BCHGISETCHARGELSB_Pos (0UL) /*!< Position of BCHGISETCHARGELSB field.                             */
#define BCHARGER_BCHGISETLSB_BCHGISETCHARGELSB_Msk (0x1UL << BCHARGER_BCHGISETLSB_BCHGISETCHARGELSB_Pos) /*!< Bit mask of
                                                                            BCHGISETCHARGELSB field.*/                            


/* BCHARGER_BCHGISETDISCHARGEMSB: Battery Charger Discharge Configuration */

/* BCHGISETDISCHARGEMSB @Bits 0..7 : Battery Charger discharge current limiter (BCHG_ISET_DISCHARGE MSB bits [8:1]) default 1A
                                     limitation. See more from Discharge Current Limiter chapter. */                              
                                                                                                                                  
#define BCHARGER_BCHGISETDISCHARGEMSB_BCHGISETDISCHARGEMSB_Pos (0UL) /*!< Position of BCHGISETDISCHARGEMSB field.              */
#define BCHARGER_BCHGISETDISCHARGEMSB_BCHGISETDISCHARGEMSB_Msk (0xFFUL << BCHARGER_BCHGISETDISCHARGEMSB_BCHGISETDISCHARGEMSB_Pos)
                                                                            /*!< Bit mask of BCHGISETDISCHARGEMSB field.*/        


/* BCHARGER_BCHGISETDISCHARGELSB: Battery Charger Discharge Configuration */

/* BCHGISETDISCHARGELSB @Bit 0 : Battery Charger discharge current limiter fine tune (BCHG_ISET_DISCHARGE LSB bit [0]). See more
                                 from Discharge Current Limiter chapter. */                                                       
                                                                                                                                  
#define BCHARGER_BCHGISETDISCHARGELSB_BCHGISETDISCHARGELSB_Pos (0UL) /*!< Position of BCHGISETDISCHARGELSB field.              */
#define BCHARGER_BCHGISETDISCHARGELSB_BCHGISETDISCHARGELSB_Msk (0x1UL << BCHARGER_BCHGISETDISCHARGELSB_BCHGISETDISCHARGELSB_Pos)
                                                                            /*!< Bit mask of BCHGISETDISCHARGELSB field.*/        


/* BCHARGER_BCHGVTERM: Battery Charger Termination Voltage Normal temp */

/* BCHGVTERMNORM @Bits 0..3 : Battery Charger Normal termination voltage. Values 14-15 are equals with default value(3V60). */
#define BCHARGER_BCHGVTERM_BCHGVTERMNORM_Pos (0UL)   /*!< Position of BCHGVTERMNORM field.                                     */
#define BCHARGER_BCHGVTERM_BCHGVTERMNORM_Msk (0xFUL << BCHARGER_BCHGVTERM_BCHGVTERMNORM_Pos) /*!< Bit mask of BCHGVTERMNORM
                                                                            field.*/                                              
#define BCHARGER_BCHGVTERM_BCHGVTERMNORM_3V50 (0)    /*!< 3.50V                                                                */
#define BCHARGER_BCHGVTERM_BCHGVTERMNORM_3V55 (1)    /*!< 3.55V                                                                */
#define BCHARGER_BCHGVTERM_BCHGVTERMNORM_3V60 (2)    /*!< 3.60V(default)                                                       */
#define BCHARGER_BCHGVTERM_BCHGVTERMNORM_3V65 (3)    /*!< 3.65V                                                                */
#define BCHARGER_BCHGVTERM_BCHGVTERMNORM_4V00 (4)    /*!< 4.00V                                                                */
#define BCHARGER_BCHGVTERM_BCHGVTERMNORM_4V05 (5)    /*!< 4.05V                                                                */
#define BCHARGER_BCHGVTERM_BCHGVTERMNORM_4V10 (6)    /*!< 4.10V                                                                */
#define BCHARGER_BCHGVTERM_BCHGVTERMNORM_4V15 (7)    /*!< 4.15V                                                                */
#define BCHARGER_BCHGVTERM_BCHGVTERMNORM_4V20 (8)    /*!< 4.20V                                                                */
#define BCHARGER_BCHGVTERM_BCHGVTERMNORM_4V25 (9)    /*!< 4.25V                                                                */
#define BCHARGER_BCHGVTERM_BCHGVTERMNORM_4V30 (10)   /*!< 4.30V                                                                */
#define BCHARGER_BCHGVTERM_BCHGVTERMNORM_4V35 (11)   /*!< 4.35V                                                                */
#define BCHARGER_BCHGVTERM_BCHGVTERMNORM_4V40 (12)   /*!< 4.40V                                                                */
#define BCHARGER_BCHGVTERM_BCHGVTERMNORM_4V45 (13)   /*!< 4.45V                                                                */


/* BCHARGER_BCHGVTERMR: Battery Charger Termination Voltage Warm temp */

/* BCHGVTERMREDUCED @Bits 0..3 : Battery Charger Warm  termination voltage. Values 14-15 are equals with default value(3V60). */
#define BCHARGER_BCHGVTERMR_BCHGVTERMREDUCED_Pos (0UL) /*!< Position of BCHGVTERMREDUCED field.                                */
#define BCHARGER_BCHGVTERMR_BCHGVTERMREDUCED_Msk (0xFUL << BCHARGER_BCHGVTERMR_BCHGVTERMREDUCED_Pos) /*!< Bit mask of
                                                                            BCHGVTERMREDUCED field.*/                             
#define BCHARGER_BCHGVTERMR_BCHGVTERMREDUCED_3V50 (0) /*!< 3.50V                                                               */
#define BCHARGER_BCHGVTERMR_BCHGVTERMREDUCED_3V55 (1) /*!< 3.55V                                                               */
#define BCHARGER_BCHGVTERMR_BCHGVTERMREDUCED_3V60 (2) /*!< 3.60V(default)                                                      */
#define BCHARGER_BCHGVTERMR_BCHGVTERMREDUCED_3V65 (3) /*!< 3.65V                                                               */
#define BCHARGER_BCHGVTERMR_BCHGVTERMREDUCED_4V00 (4) /*!< 4.00V                                                               */
#define BCHARGER_BCHGVTERMR_BCHGVTERMREDUCED_4V05 (5) /*!< 4.05V                                                               */
#define BCHARGER_BCHGVTERMR_BCHGVTERMREDUCED_4V10 (6) /*!< 4.10V                                                               */
#define BCHARGER_BCHGVTERMR_BCHGVTERMREDUCED_4V15 (7) /*!< 4.15V                                                               */
#define BCHARGER_BCHGVTERMR_BCHGVTERMREDUCED_4V20 (8) /*!< 4.20V                                                               */
#define BCHARGER_BCHGVTERMR_BCHGVTERMREDUCED_4V25 (9) /*!< 4.25V                                                               */
#define BCHARGER_BCHGVTERMR_BCHGVTERMREDUCED_4V30 (10) /*!< 4.30V                                                              */
#define BCHARGER_BCHGVTERMR_BCHGVTERMREDUCED_4V35 (11) /*!< 4.35V                                                              */
#define BCHARGER_BCHGVTERMR_BCHGVTERMREDUCED_4V40 (12) /*!< 4.40V                                                              */
#define BCHARGER_BCHGVTERMR_BCHGVTERMREDUCED_4V45 (13) /*!< 4.45V                                                              */


/* BCHARGER_BCHGVTRICKLESEL: Battery Charger Trickle Level Select */

/* BCHGVTRICKLESEL @Bit 0 : Battery Charger Vtrickle select */
#define BCHARGER_BCHGVTRICKLESEL_BCHGVTRICKLESEL_Pos (0UL) /*!< Position of BCHGVTRICKLESEL field.                             */
#define BCHARGER_BCHGVTRICKLESEL_BCHGVTRICKLESEL_Msk (0x1UL << BCHARGER_BCHGVTRICKLESEL_BCHGVTRICKLESEL_Pos) /*!< Bit mask of
                                                                            BCHGVTRICKLESEL field.*/                              
#define BCHARGER_BCHGVTRICKLESEL_BCHGVTRICKLESEL_2V9 (0) /*!< 2.9V(default)                                                    */
#define BCHARGER_BCHGVTRICKLESEL_BCHGVTRICKLESEL_2V5 (1) /*!< 2.5V                                                             */


/* BCHARGER_BCHGITERMSEL: Battery Charger ITERM Level Select */

/* BCHGITERMSEL @Bit 0 : Battery Charger ITERM select */
#define BCHARGER_BCHGITERMSEL_BCHGITERMSEL_Pos (0UL) /*!< Position of BCHGITERMSEL field.                                      */
#define BCHARGER_BCHGITERMSEL_BCHGITERMSEL_Msk (0x1UL << BCHARGER_BCHGITERMSEL_BCHGITERMSEL_Pos) /*!< Bit mask of BCHGITERMSEL
                                                                            field.*/                                              
#define BCHARGER_BCHGITERMSEL_BCHGITERMSEL_SEL10 (0) /*!< 10 percent(default)                                                  */
#define BCHARGER_BCHGITERMSEL_BCHGITERMSEL_SEL20 (1) /*!< 20 percent                                                           */


/* BCHARGER_NTCCOLD: NTC threshold for COLD temperature region */

/* NTCCOLDLVLMSB @Bits 0..7 : NTC COLD level MSB bits */
#define BCHARGER_NTCCOLD_NTCCOLDLVLMSB_Pos (0UL)     /*!< Position of NTCCOLDLVLMSB field.                                     */
#define BCHARGER_NTCCOLD_NTCCOLDLVLMSB_Msk (0xFFUL << BCHARGER_NTCCOLD_NTCCOLDLVLMSB_Pos) /*!< Bit mask of NTCCOLDLVLMSB field.*/


/* BCHARGER_NTCCOLDLSB: NTC threshold for COLD temperature region */

/* NTCCOLDLVLLSB @Bits 0..1 : NTC COLD level LSB bits */
#define BCHARGER_NTCCOLDLSB_NTCCOLDLVLLSB_Pos (0UL)  /*!< Position of NTCCOLDLVLLSB field.                                     */
#define BCHARGER_NTCCOLDLSB_NTCCOLDLVLLSB_Msk (0x3UL << BCHARGER_NTCCOLDLSB_NTCCOLDLVLLSB_Pos) /*!< Bit mask of NTCCOLDLVLLSB
                                                                            field.*/                                              


/* BCHARGER_NTCCOOL: NTC threshold for COOL temperature region */

/* NTCCOOLLVLMSB @Bits 0..7 : NTC COOL level MSB bits */
#define BCHARGER_NTCCOOL_NTCCOOLLVLMSB_Pos (0UL)     /*!< Position of NTCCOOLLVLMSB field.                                     */
#define BCHARGER_NTCCOOL_NTCCOOLLVLMSB_Msk (0xFFUL << BCHARGER_NTCCOOL_NTCCOOLLVLMSB_Pos) /*!< Bit mask of NTCCOOLLVLMSB field.*/


/* BCHARGER_NTCCOOLLSB: NTC threshold for COOL temperature region */

/* NTCCOOLLVLLSB @Bits 0..1 : NTC COOL level LSB bits */
#define BCHARGER_NTCCOOLLSB_NTCCOOLLVLLSB_Pos (0UL)  /*!< Position of NTCCOOLLVLLSB field.                                     */
#define BCHARGER_NTCCOOLLSB_NTCCOOLLVLLSB_Msk (0x3UL << BCHARGER_NTCCOOLLSB_NTCCOOLLVLLSB_Pos) /*!< Bit mask of NTCCOOLLVLLSB
                                                                            field.*/                                              


/* BCHARGER_NTCWARM: NTC threshold for WARM temperature region */

/* NTCWARMLVLMSB @Bits 0..7 : NTC WARM level MSB bits */
#define BCHARGER_NTCWARM_NTCWARMLVLMSB_Pos (0UL)     /*!< Position of NTCWARMLVLMSB field.                                     */
#define BCHARGER_NTCWARM_NTCWARMLVLMSB_Msk (0xFFUL << BCHARGER_NTCWARM_NTCWARMLVLMSB_Pos) /*!< Bit mask of NTCWARMLVLMSB field.*/


/* BCHARGER_NTCWARMLSB: NTC threshold for WARM temperature region */

/* NTCWARMLVLLSB @Bits 0..1 : NTC WARM level LSB bits */
#define BCHARGER_NTCWARMLSB_NTCWARMLVLLSB_Pos (0UL)  /*!< Position of NTCWARMLVLLSB field.                                     */
#define BCHARGER_NTCWARMLSB_NTCWARMLVLLSB_Msk (0x3UL << BCHARGER_NTCWARMLSB_NTCWARMLVLLSB_Pos) /*!< Bit mask of NTCWARMLVLLSB
                                                                            field.*/                                              


/* BCHARGER_NTCHOT: NTC threshold for HOT temperature region */

/* NTCHOTLVLMSB @Bits 0..7 : NTC HOT level MSB bits */
#define BCHARGER_NTCHOT_NTCHOTLVLMSB_Pos (0UL)       /*!< Position of NTCHOTLVLMSB field.                                      */
#define BCHARGER_NTCHOT_NTCHOTLVLMSB_Msk (0xFFUL << BCHARGER_NTCHOT_NTCHOTLVLMSB_Pos) /*!< Bit mask of NTCHOTLVLMSB field.     */


/* BCHARGER_NTCHOTLSB: NTC threshold for HOT temperature region */

/* NTCHOTLVLLSB @Bits 0..1 : NTC HOT level LSB bits */
#define BCHARGER_NTCHOTLSB_NTCHOTLVLLSB_Pos (0UL)    /*!< Position of NTCHOTLVLLSB field.                                      */
#define BCHARGER_NTCHOTLSB_NTCHOTLVLLSB_Msk (0x3UL << BCHARGER_NTCHOTLSB_NTCHOTLVLLSB_Pos) /*!< Bit mask of NTCHOTLVLLSB field.*/


/* BCHARGER_DIETEMPSTOP: DIE TEMP threshold for stop charging */

/* DIETEMPSTOPCHG @Bits 0..7 : DIE TEMP STOP charging level */
#define BCHARGER_DIETEMPSTOP_DIETEMPSTOPCHG_Pos (0UL) /*!< Position of DIETEMPSTOPCHG field.                                   */
#define BCHARGER_DIETEMPSTOP_DIETEMPSTOPCHG_Msk (0xFFUL << BCHARGER_DIETEMPSTOP_DIETEMPSTOPCHG_Pos) /*!< Bit mask of
                                                                            DIETEMPSTOPCHG field.*/                               


/* BCHARGER_DIETEMPSTOPLSB: DIE TEMP threshold for stop charging lsb */

/* DIETEMPSTOPCHGLSB @Bits 0..1 : DIE TEMP STOP charging level Lsb bits */
#define BCHARGER_DIETEMPSTOPLSB_DIETEMPSTOPCHGLSB_Pos (0UL) /*!< Position of DIETEMPSTOPCHGLSB field.                          */
#define BCHARGER_DIETEMPSTOPLSB_DIETEMPSTOPCHGLSB_Msk (0x3UL << BCHARGER_DIETEMPSTOPLSB_DIETEMPSTOPCHGLSB_Pos) /*!< Bit mask of
                                                                            DIETEMPSTOPCHGLSB field.*/                            


/* BCHARGER_DIETEMPRESUME: DIE TEMP threshold for resuming charging */

/* DIETEMPRESUMECHG @Bits 0..7 : DIE TEMP RESUME charging level */
#define BCHARGER_DIETEMPRESUME_DIETEMPRESUMECHG_Pos (0UL) /*!< Position of DIETEMPRESUMECHG field.                             */
#define BCHARGER_DIETEMPRESUME_DIETEMPRESUMECHG_Msk (0xFFUL << BCHARGER_DIETEMPRESUME_DIETEMPRESUMECHG_Pos) /*!< Bit mask of
                                                                            DIETEMPRESUMECHG field.*/                             


/* BCHARGER_DIETEMPRESUMELSB: DIE TEMP threshold for resuming charging lsb */

/* DIETEMPRESUMECHGLSB @Bits 0..1 : DIE TEMP RESUME charging level Lsb bits */
#define BCHARGER_DIETEMPRESUMELSB_DIETEMPRESUMECHGLSB_Pos (0UL) /*!< Position of DIETEMPRESUMECHGLSB field.                    */
#define BCHARGER_DIETEMPRESUMELSB_DIETEMPRESUMECHGLSB_Msk (0x3UL << BCHARGER_DIETEMPRESUMELSB_DIETEMPRESUMECHGLSB_Pos) /*!< Bit
                                                                            mask of DIETEMPRESUMECHGLSB field.*/                  


/* BCHARGER_BCHGILIMSTATUS: BCHARGER Ilim Status */

/* BCHGILIMBATACTIVE @Bit 0 : BCHARGER Ilimiter active */
#define BCHARGER_BCHGILIMSTATUS_BCHGILIMBATACTIVE_Pos (0UL) /*!< Position of BCHGILIMBATACTIVE field.                          */
#define BCHARGER_BCHGILIMSTATUS_BCHGILIMBATACTIVE_Msk (0x1UL << BCHARGER_BCHGILIMSTATUS_BCHGILIMBATACTIVE_Pos) /*!< Bit mask of
                                                                            BCHGILIMBATACTIVE field.*/                            
#define BCHARGER_BCHGILIMSTATUS_BCHGILIMBATACTIVE_INACTIVE (0) /*!< Ilimbat not triggered                                      */
#define BCHARGER_BCHGILIMSTATUS_BCHGILIMBATACTIVE_ACTIVE (1) /*!< Ilimbat triggered                                            */


/* BCHARGER_NTCSTATUS: Ntc Comparator Status */

/* NTCCOLD @Bit 0 : Ntc Cold */
#define BCHARGER_NTCSTATUS_NTCCOLD_Pos (0UL)         /*!< Position of NTCCOLD field.                                           */
#define BCHARGER_NTCSTATUS_NTCCOLD_Msk (0x1UL << BCHARGER_NTCSTATUS_NTCCOLD_Pos) /*!< Bit mask of NTCCOLD field.               */

/* NTCCOOL @Bit 1 : Ntc Cool */
#define BCHARGER_NTCSTATUS_NTCCOOL_Pos (1UL)         /*!< Position of NTCCOOL field.                                           */
#define BCHARGER_NTCSTATUS_NTCCOOL_Msk (0x1UL << BCHARGER_NTCSTATUS_NTCCOOL_Pos) /*!< Bit mask of NTCCOOL field.               */

/* NTCWARM @Bit 2 : Ntc Warm */
#define BCHARGER_NTCSTATUS_NTCWARM_Pos (2UL)         /*!< Position of NTCWARM field.                                           */
#define BCHARGER_NTCSTATUS_NTCWARM_Msk (0x1UL << BCHARGER_NTCSTATUS_NTCWARM_Pos) /*!< Bit mask of NTCWARM field.               */

/* NTCHOT @Bit 3 : Ntc Hot */
#define BCHARGER_NTCSTATUS_NTCHOT_Pos (3UL)          /*!< Position of NTCHOT field.                                            */
#define BCHARGER_NTCSTATUS_NTCHOT_Msk (0x1UL << BCHARGER_NTCSTATUS_NTCHOT_Pos) /*!< Bit mask of NTCHOT field.                  */


/* BCHARGER_DIETEMPSTATUS: DieTemp Comparator Status */

/* DIETEMPHIGH @Bit 0 : DieTemp High */
#define BCHARGER_DIETEMPSTATUS_DIETEMPHIGH_Pos (0UL) /*!< Position of DIETEMPHIGH field.                                       */
#define BCHARGER_DIETEMPSTATUS_DIETEMPHIGH_Msk (0x1UL << BCHARGER_DIETEMPSTATUS_DIETEMPHIGH_Pos) /*!< Bit mask of DIETEMPHIGH
                                                                            field.*/                                              
#define BCHARGER_DIETEMPSTATUS_DIETEMPHIGH_NORMAL (0) /*!< Die below high threshold                                            */
#define BCHARGER_DIETEMPSTATUS_DIETEMPHIGH_HIGH (1)  /*!< Die above high threshold                                             */


/* BCHARGER_BCHGCHARGESTATUS: Charging Status */

/* BATTERYDETECTED @Bit 0 : Battery is connected */
#define BCHARGER_BCHGCHARGESTATUS_BATTERYDETECTED_Pos (0UL) /*!< Position of BATTERYDETECTED field.                            */
#define BCHARGER_BCHGCHARGESTATUS_BATTERYDETECTED_Msk (0x1UL << BCHARGER_BCHGCHARGESTATUS_BATTERYDETECTED_Pos) /*!< Bit mask of
                                                                            BATTERYDETECTED field.*/                              

/* COMPLETED @Bit 1 : Charging completed (Battery Full) */
#define BCHARGER_BCHGCHARGESTATUS_COMPLETED_Pos (1UL) /*!< Position of COMPLETED field.                                        */
#define BCHARGER_BCHGCHARGESTATUS_COMPLETED_Msk (0x1UL << BCHARGER_BCHGCHARGESTATUS_COMPLETED_Pos) /*!< Bit mask of COMPLETED
                                                                            field.*/                                              

/* TRICKLECHARGE @Bit 2 : Trickle charge */
#define BCHARGER_BCHGCHARGESTATUS_TRICKLECHARGE_Pos (2UL) /*!< Position of TRICKLECHARGE field.                                */
#define BCHARGER_BCHGCHARGESTATUS_TRICKLECHARGE_Msk (0x1UL << BCHARGER_BCHGCHARGESTATUS_TRICKLECHARGE_Pos) /*!< Bit mask of
                                                                            TRICKLECHARGE field.*/                                

/* CONSTANTCURRENT @Bit 3 : Constant Current charging */
#define BCHARGER_BCHGCHARGESTATUS_CONSTANTCURRENT_Pos (3UL) /*!< Position of CONSTANTCURRENT field.                            */
#define BCHARGER_BCHGCHARGESTATUS_CONSTANTCURRENT_Msk (0x1UL << BCHARGER_BCHGCHARGESTATUS_CONSTANTCURRENT_Pos) /*!< Bit mask of
                                                                            CONSTANTCURRENT field.*/                              

/* CONSTANTVOLTAGE @Bit 4 : Constant Voltage charging */
#define BCHARGER_BCHGCHARGESTATUS_CONSTANTVOLTAGE_Pos (4UL) /*!< Position of CONSTANTVOLTAGE field.                            */
#define BCHARGER_BCHGCHARGESTATUS_CONSTANTVOLTAGE_Msk (0x1UL << BCHARGER_BCHGCHARGESTATUS_CONSTANTVOLTAGE_Pos) /*!< Bit mask of
                                                                            CONSTANTVOLTAGE field.*/                              

/* RECHARGE @Bit 5 : Battery re-charge is needed */
#define BCHARGER_BCHGCHARGESTATUS_RECHARGE_Pos (5UL) /*!< Position of RECHARGE field.                                          */
#define BCHARGER_BCHGCHARGESTATUS_RECHARGE_Msk (0x1UL << BCHARGER_BCHGCHARGESTATUS_RECHARGE_Pos) /*!< Bit mask of RECHARGE
                                                                            field.*/                                              

/* DIETEMPHIGHCHGPAUSED @Bit 6 : Charging stopped due Die Temp high. */
#define BCHARGER_BCHGCHARGESTATUS_DIETEMPHIGHCHGPAUSED_Pos (6UL) /*!< Position of DIETEMPHIGHCHGPAUSED field.                  */
#define BCHARGER_BCHGCHARGESTATUS_DIETEMPHIGHCHGPAUSED_Msk (0x1UL << BCHARGER_BCHGCHARGESTATUS_DIETEMPHIGHCHGPAUSED_Pos) /*!<
                                                                            Bit mask of DIETEMPHIGHCHGPAUSED field.*/             

/* SUPPLEMENTACTIVE @Bit 7 : Supplement Mode Active */
#define BCHARGER_BCHGCHARGESTATUS_SUPPLEMENTACTIVE_Pos (7UL) /*!< Position of SUPPLEMENTACTIVE field.                          */
#define BCHARGER_BCHGCHARGESTATUS_SUPPLEMENTACTIVE_Msk (0x1UL << BCHARGER_BCHGCHARGESTATUS_SUPPLEMENTACTIVE_Pos) /*!< Bit mask
                                                                            of SUPPLEMENTACTIVE field.*/                          


/* BCHARGER_BCHGERRREASON: Charger-FSM Error. Latched error reasons. Cleared with TASKS_CLEAR_CHG_ERR */

/* NTCSENSORERROR @Bit 0 : Ntc sensor error */
#define BCHARGER_BCHGERRREASON_NTCSENSORERROR_Pos (0UL) /*!< Position of NTCSENSORERROR field.                                 */
#define BCHARGER_BCHGERRREASON_NTCSENSORERROR_Msk (0x1UL << BCHARGER_BCHGERRREASON_NTCSENSORERROR_Pos) /*!< Bit mask of
                                                                            NTCSENSORERROR field.*/                               

/* VBATSENSORERROR @Bit 1 : Vbat sensor error */
#define BCHARGER_BCHGERRREASON_VBATSENSORERROR_Pos (1UL) /*!< Position of VBATSENSORERROR field.                               */
#define BCHARGER_BCHGERRREASON_VBATSENSORERROR_Msk (0x1UL << BCHARGER_BCHGERRREASON_VBATSENSORERROR_Pos) /*!< Bit mask of
                                                                            VBATSENSORERROR field.*/                              

/* VBATLOW @Bit 2 : VbatLow error */
#define BCHARGER_BCHGERRREASON_VBATLOW_Pos (2UL)     /*!< Position of VBATLOW field.                                           */
#define BCHARGER_BCHGERRREASON_VBATLOW_Msk (0x1UL << BCHARGER_BCHGERRREASON_VBATLOW_Pos) /*!< Bit mask of VBATLOW field.       */

/* VTRICKLE @Bit 3 : Vtrickle error */
#define BCHARGER_BCHGERRREASON_VTRICKLE_Pos (3UL)    /*!< Position of VTRICKLE field.                                          */
#define BCHARGER_BCHGERRREASON_VTRICKLE_Msk (0x1UL << BCHARGER_BCHGERRREASON_VTRICKLE_Pos) /*!< Bit mask of VTRICKLE field.    */

/* MEASTIMEOUT @Bit 4 : Measurement timer timeout */
#define BCHARGER_BCHGERRREASON_MEASTIMEOUT_Pos (4UL) /*!< Position of MEASTIMEOUT field.                                       */
#define BCHARGER_BCHGERRREASON_MEASTIMEOUT_Msk (0x1UL << BCHARGER_BCHGERRREASON_MEASTIMEOUT_Pos) /*!< Bit mask of MEASTIMEOUT
                                                                            field.*/                                              

/* CHARGETIMEOUT @Bit 5 : Charge timer timeout */
#define BCHARGER_BCHGERRREASON_CHARGETIMEOUT_Pos (5UL) /*!< Position of CHARGETIMEOUT field.                                   */
#define BCHARGER_BCHGERRREASON_CHARGETIMEOUT_Msk (0x1UL << BCHARGER_BCHGERRREASON_CHARGETIMEOUT_Pos) /*!< Bit mask of
                                                                            CHARGETIMEOUT field.*/                                

/* TRICKLETIMEOUT @Bit 6 : Trickle timer timeout */
#define BCHARGER_BCHGERRREASON_TRICKLETIMEOUT_Pos (6UL) /*!< Position of TRICKLETIMEOUT field.                                 */
#define BCHARGER_BCHGERRREASON_TRICKLETIMEOUT_Msk (0x1UL << BCHARGER_BCHGERRREASON_TRICKLETIMEOUT_Pos) /*!< Bit mask of
                                                                            TRICKLETIMEOUT field.*/                               


/* BCHARGER_BCHGERRSENSOR: Charger-FSM Error. Latched sensor values. Cleared with TASKS_CLEAR_CHG_ERR */

/* SENSORNTCCOLD @Bit 0 : Ntc Cold sensor value during error */
#define BCHARGER_BCHGERRSENSOR_SENSORNTCCOLD_Pos (0UL) /*!< Position of SENSORNTCCOLD field.                                   */
#define BCHARGER_BCHGERRSENSOR_SENSORNTCCOLD_Msk (0x1UL << BCHARGER_BCHGERRSENSOR_SENSORNTCCOLD_Pos) /*!< Bit mask of
                                                                            SENSORNTCCOLD field.*/                                

/* SENSORNTCCOOL @Bit 1 : Ntc Cool sensor value during error */
#define BCHARGER_BCHGERRSENSOR_SENSORNTCCOOL_Pos (1UL) /*!< Position of SENSORNTCCOOL field.                                   */
#define BCHARGER_BCHGERRSENSOR_SENSORNTCCOOL_Msk (0x1UL << BCHARGER_BCHGERRSENSOR_SENSORNTCCOOL_Pos) /*!< Bit mask of
                                                                            SENSORNTCCOOL field.*/                                

/* SENSORNTCWARM @Bit 2 : Ntc Warm sensor value during error */
#define BCHARGER_BCHGERRSENSOR_SENSORNTCWARM_Pos (2UL) /*!< Position of SENSORNTCWARM field.                                   */
#define BCHARGER_BCHGERRSENSOR_SENSORNTCWARM_Msk (0x1UL << BCHARGER_BCHGERRSENSOR_SENSORNTCWARM_Pos) /*!< Bit mask of
                                                                            SENSORNTCWARM field.*/                                

/* SENSORNTCHOT @Bit 3 : Ntc Hot sensor value during error */
#define BCHARGER_BCHGERRSENSOR_SENSORNTCHOT_Pos (3UL) /*!< Position of SENSORNTCHOT field.                                     */
#define BCHARGER_BCHGERRSENSOR_SENSORNTCHOT_Msk (0x1UL << BCHARGER_BCHGERRSENSOR_SENSORNTCHOT_Pos) /*!< Bit mask of SENSORNTCHOT
                                                                            field.*/                                              

/* SENSORVTERM @Bit 4 : Vterm sensor value during error */
#define BCHARGER_BCHGERRSENSOR_SENSORVTERM_Pos (4UL) /*!< Position of SENSORVTERM field.                                       */
#define BCHARGER_BCHGERRSENSOR_SENSORVTERM_Msk (0x1UL << BCHARGER_BCHGERRSENSOR_SENSORVTERM_Pos) /*!< Bit mask of SENSORVTERM
                                                                            field.*/                                              

/* SENSORRECHARGE @Bit 5 : Recharge sensor value during error */
#define BCHARGER_BCHGERRSENSOR_SENSORRECHARGE_Pos (5UL) /*!< Position of SENSORRECHARGE field.                                 */
#define BCHARGER_BCHGERRSENSOR_SENSORRECHARGE_Msk (0x1UL << BCHARGER_BCHGERRSENSOR_SENSORRECHARGE_Pos) /*!< Bit mask of
                                                                            SENSORRECHARGE field.*/                               

/* SENSORVTRICKLE @Bit 6 : Vtrickle sensor value during error */
#define BCHARGER_BCHGERRSENSOR_SENSORVTRICKLE_Pos (6UL) /*!< Position of SENSORVTRICKLE field.                                 */
#define BCHARGER_BCHGERRSENSOR_SENSORVTRICKLE_Msk (0x1UL << BCHARGER_BCHGERRSENSOR_SENSORVTRICKLE_Pos) /*!< Bit mask of
                                                                            SENSORVTRICKLE field.*/                               

/* SENSORVBATLOW @Bit 7 : Vbatlow sensor value during error */
#define BCHARGER_BCHGERRSENSOR_SENSORVBATLOW_Pos (7UL) /*!< Position of SENSORVBATLOW field.                                   */
#define BCHARGER_BCHGERRSENSOR_SENSORVBATLOW_Msk (0x1UL << BCHARGER_BCHGERRSENSOR_SENSORVBATLOW_Pos) /*!< Bit mask of
                                                                            SENSORVBATLOW field.*/                                


/* BCHARGER_BCHGCONFIG: Charger configuration */

/* DISABLECHARGEWARM @Bit 0 : Disable charging if battery is warm */
#define BCHARGER_BCHGCONFIG_DISABLECHARGEWARM_Pos (0UL) /*!< Position of DISABLECHARGEWARM field.                              */
#define BCHARGER_BCHGCONFIG_DISABLECHARGEWARM_Msk (0x1UL << BCHARGER_BCHGCONFIG_DISABLECHARGEWARM_Pos) /*!< Bit mask of
                                                                            DISABLECHARGEWARM field.*/                            
#define BCHARGER_BCHGCONFIG_DISABLECHARGEWARM_ENABLED (0) /*!< Enable Charging if battery is warm                              */
#define BCHARGER_BCHGCONFIG_DISABLECHARGEWARM_DISABLED (1) /*!< Disable Charging if battery is warm                            */



/* =========================================================================================================================== */
/* ================                                           BUCK                                           ================ */
/* =========================================================================================================================== */

/* ======================================================= Struct BUCK ======================================================= */
/**
  * @brief Neutrino BUCK registers
  */
typedef struct {                                     /*!< BUCK Structure                                                       */
  __OM  uint8_t   BUCK1ENASET;                       /*!< (@ 0x00000000) BUCK1 Enable pulse                                    */
  __OM  uint8_t   BUCK1ENACLR;                       /*!< (@ 0x00000001) BUCK1 Disable pulse                                   */
  __OM  uint8_t   BUCK2ENASET;                       /*!< (@ 0x00000002) BUCK2 Enable pulse                                    */
  __OM  uint8_t   BUCK2ENACLR;                       /*!< (@ 0x00000003) BUCK2 Disable pulse                                   */
  __OM  uint8_t   BUCK1PWMSET;                       /*!< (@ 0x00000004) BUCK1 PWM mode enable pulse                           */
  __OM  uint8_t   BUCK1PWMCLR;                       /*!< (@ 0x00000005) BUCK1 PWM mode disable pulse                          */
  __OM  uint8_t   BUCK2PWMSET;                       /*!< (@ 0x00000006) BUCK2 PWM mode enable pulse                           */
  __OM  uint8_t   BUCK2PWMCLR;                       /*!< (@ 0x00000007) BUCK2 PWM mode disable pulse                          */
  __IOM uint8_t   BUCK1NORMVOUT;                     /*!< (@ 0x00000008) BUCK1 Output voltage Normal mode                      */
  __IOM uint8_t   BUCK1RETVOUT;                      /*!< (@ 0x00000009) BUCK1 Output voltage Retention mode                   */
  __IOM uint8_t   BUCK2NORMVOUT;                     /*!< (@ 0x0000000A) BUCK2 Output voltage Normal mode                      */
  __IOM uint8_t   BUCK2RETVOUT;                      /*!< (@ 0x0000000B) BUCK2 Output voltage Retention mode                   */
  __IOM uint8_t   BUCKENCTRL;                        /*!< (@ 0x0000000C) BUCK Enable GPIO Select                               */
  __IOM uint8_t   BUCKVRETCTRL;                      /*!< (@ 0x0000000D) BUCK Retention Voltage select                         */
  __IOM uint8_t   BUCKPWMCTRL;                       /*!< (@ 0x0000000E) BUCK Forced PWM mode GPIO select                      */
  __IOM uint8_t   BUCKSWCTRLSEL;                     /*!< (@ 0x0000000F) BUCK Software Control select                          */
  __IM  uint8_t   BUCK1VOUTSTATUS;                   /*!< (@ 0x00000010) BUCK1 Vout Status register. Lets software read the Vout
                                                                         value in case its driven by the FSM.*/                   
  __IM  uint8_t   BUCK2VOUTSTATUS;                   /*!< (@ 0x00000011) BUCK2 Vout Status register. Lets software read the Vout
                                                                         value in case its driven by the FSM.*/                   
  __IM  uint8_t   RESERVED[3];
  __IOM uint8_t   BUCKCTRL0;                         /*!< (@ 0x00000015) BUCK Auto PFM to PWM Control select                   */
  __IM  uint8_t   RESERVED1[30];
  __IM  uint8_t   BUCKSTATUS;                        /*!< (@ 0x00000034) BUCK status register                                  */
}NPM_BUCK_Type;                                      /*!< Size = 53 (0x035)                                                    */

/* BUCK_BUCK1ENASET: BUCK1 Enable pulse */

/* TASKBUCK1ENASET @Bit 0 : Request to enable BUCK1 */
#define BUCK_BUCK1ENASET_TASKBUCK1ENASET_Pos (0UL)   /*!< Position of TASKBUCK1ENASET field.                                   */
#define BUCK_BUCK1ENASET_TASKBUCK1ENASET_Msk (0x1UL << BUCK_BUCK1ENASET_TASKBUCK1ENASET_Pos) /*!< Bit mask of TASKBUCK1ENASET
                                                                            field.*/                                              
#define BUCK_BUCK1ENASET_TASKBUCK1ENASET_NOEFFECT (0) /*!< no effect                                                           */
#define BUCK_BUCK1ENASET_TASKBUCK1ENASET_SET (1)     /*!< BUCK1 Enable request set                                             */


/* BUCK_BUCK1ENACLR: BUCK1 Disable pulse */

/* TASKBUCK1ENACLR @Bit 0 : Request to disable BUCK1 */
#define BUCK_BUCK1ENACLR_TASKBUCK1ENACLR_Pos (0UL)   /*!< Position of TASKBUCK1ENACLR field.                                   */
#define BUCK_BUCK1ENACLR_TASKBUCK1ENACLR_Msk (0x1UL << BUCK_BUCK1ENACLR_TASKBUCK1ENACLR_Pos) /*!< Bit mask of TASKBUCK1ENACLR
                                                                            field.*/                                              
#define BUCK_BUCK1ENACLR_TASKBUCK1ENACLR_NOEFFECT (0) /*!< no effect                                                           */
#define BUCK_BUCK1ENACLR_TASKBUCK1ENACLR_SET (1)     /*!< BUCK1 Enable request clr                                             */


/* BUCK_BUCK2ENASET: BUCK2 Enable pulse */

/* TASKBUCK2ENASET @Bit 0 : Request to enable BUCK2 */
#define BUCK_BUCK2ENASET_TASKBUCK2ENASET_Pos (0UL)   /*!< Position of TASKBUCK2ENASET field.                                   */
#define BUCK_BUCK2ENASET_TASKBUCK2ENASET_Msk (0x1UL << BUCK_BUCK2ENASET_TASKBUCK2ENASET_Pos) /*!< Bit mask of TASKBUCK2ENASET
                                                                            field.*/                                              
#define BUCK_BUCK2ENASET_TASKBUCK2ENASET_NOEFFECT (0) /*!< no effect                                                           */
#define BUCK_BUCK2ENASET_TASKBUCK2ENASET_SET (1)     /*!< BUCK2 Enable request set                                             */


/* BUCK_BUCK2ENACLR: BUCK2 Disable pulse */

/* TASKBUCK2ENACLR @Bit 0 : Request to enable BUCK2 */
#define BUCK_BUCK2ENACLR_TASKBUCK2ENACLR_Pos (0UL)   /*!< Position of TASKBUCK2ENACLR field.                                   */
#define BUCK_BUCK2ENACLR_TASKBUCK2ENACLR_Msk (0x1UL << BUCK_BUCK2ENACLR_TASKBUCK2ENACLR_Pos) /*!< Bit mask of TASKBUCK2ENACLR
                                                                            field.*/                                              
#define BUCK_BUCK2ENACLR_TASKBUCK2ENACLR_NOEFFECT (0) /*!< no effect                                                           */
#define BUCK_BUCK2ENACLR_TASKBUCK2ENACLR_SET (1)     /*!< BUCK2 Enable request clr                                             */


/* BUCK_BUCK1PWMSET: BUCK1 PWM mode enable pulse */

/* TASKBUCK1PWMSET @Bit 0 : request for BUCK1 to enter forced PWM mode */
#define BUCK_BUCK1PWMSET_TASKBUCK1PWMSET_Pos (0UL)   /*!< Position of TASKBUCK1PWMSET field.                                   */
#define BUCK_BUCK1PWMSET_TASKBUCK1PWMSET_Msk (0x1UL << BUCK_BUCK1PWMSET_TASKBUCK1PWMSET_Pos) /*!< Bit mask of TASKBUCK1PWMSET
                                                                            field.*/                                              
#define BUCK_BUCK1PWMSET_TASKBUCK1PWMSET_NOEFFECT (0) /*!< no effect                                                           */
#define BUCK_BUCK1PWMSET_TASKBUCK1PWMSET_SET (1)     /*!< BUCK1 Forced PWM request                                             */


/* BUCK_BUCK1PWMCLR: BUCK1 PWM mode disable pulse */

/* TASKBUCK1PWMCLR @Bit 0 : request for BUCK1 to leave forced PWM mode and return to Auto mode */
#define BUCK_BUCK1PWMCLR_TASKBUCK1PWMCLR_Pos (0UL)   /*!< Position of TASKBUCK1PWMCLR field.                                   */
#define BUCK_BUCK1PWMCLR_TASKBUCK1PWMCLR_Msk (0x1UL << BUCK_BUCK1PWMCLR_TASKBUCK1PWMCLR_Pos) /*!< Bit mask of TASKBUCK1PWMCLR
                                                                            field.*/                                              
#define BUCK_BUCK1PWMCLR_TASKBUCK1PWMCLR_NOEFFECT (0) /*!< no effect                                                           */
#define BUCK_BUCK1PWMCLR_TASKBUCK1PWMCLR_SET (1)     /*!< BUCK1 Auto mode request                                              */


/* BUCK_BUCK2PWMSET: BUCK2 PWM mode enable pulse */

/* TASKBUCK2PWMSET @Bit 0 : request for BUCK2 to enter forced PWM mode */
#define BUCK_BUCK2PWMSET_TASKBUCK2PWMSET_Pos (0UL)   /*!< Position of TASKBUCK2PWMSET field.                                   */
#define BUCK_BUCK2PWMSET_TASKBUCK2PWMSET_Msk (0x1UL << BUCK_BUCK2PWMSET_TASKBUCK2PWMSET_Pos) /*!< Bit mask of TASKBUCK2PWMSET
                                                                            field.*/                                              
#define BUCK_BUCK2PWMSET_TASKBUCK2PWMSET_NOEFFECT (0) /*!< no effect                                                           */
#define BUCK_BUCK2PWMSET_TASKBUCK2PWMSET_SET (1)     /*!< BUCK2 Forced PWM request                                             */


/* BUCK_BUCK2PWMCLR: BUCK2 PWM mode disable pulse */

/* TASKBUCK2PWMCLR @Bit 0 : request for BUCK2 to leave forced PWM mode and return to Auto mode */
#define BUCK_BUCK2PWMCLR_TASKBUCK2PWMCLR_Pos (0UL)   /*!< Position of TASKBUCK2PWMCLR field.                                   */
#define BUCK_BUCK2PWMCLR_TASKBUCK2PWMCLR_Msk (0x1UL << BUCK_BUCK2PWMCLR_TASKBUCK2PWMCLR_Pos) /*!< Bit mask of TASKBUCK2PWMCLR
                                                                            field.*/                                              
#define BUCK_BUCK2PWMCLR_TASKBUCK2PWMCLR_NOEFFECT (0) /*!< no effect                                                           */
#define BUCK_BUCK2PWMCLR_TASKBUCK2PWMCLR_SET (1)     /*!< BUCK2 Auto mode request                                              */


/* BUCK_BUCK1NORMVOUT: BUCK1 Output voltage Normal mode */

/* BUCK1NORMVOUT @Bits 0..4 : BUCK1 Output voltage Normal mode */
#define BUCK_BUCK1NORMVOUT_BUCK1NORMVOUT_Pos (0UL)   /*!< Position of BUCK1NORMVOUT field.                                     */
#define BUCK_BUCK1NORMVOUT_BUCK1NORMVOUT_Msk (0x1FUL << BUCK_BUCK1NORMVOUT_BUCK1NORMVOUT_Pos) /*!< Bit mask of BUCK1NORMVOUT
                                                                            field.*/                                              
#define BUCK_BUCK1NORMVOUT_BUCK1NORMVOUT_1V (0)      /*!< 1V                                                                   */
#define BUCK_BUCK1NORMVOUT_BUCK1NORMVOUT_1V1 (1)     /*!< 1.1V                                                                 */
#define BUCK_BUCK1NORMVOUT_BUCK1NORMVOUT_1V2 (2)     /*!< 1.2V(Default)                                                        */
#define BUCK_BUCK1NORMVOUT_BUCK1NORMVOUT_1V3 (3)     /*!< 1.3V                                                                 */
#define BUCK_BUCK1NORMVOUT_BUCK1NORMVOUT_1V4 (4)     /*!< 1.4V                                                                 */
#define BUCK_BUCK1NORMVOUT_BUCK1NORMVOUT_1V5 (5)     /*!< 1.5V                                                                 */
#define BUCK_BUCK1NORMVOUT_BUCK1NORMVOUT_1V6 (6)     /*!< 1.6V                                                                 */
#define BUCK_BUCK1NORMVOUT_BUCK1NORMVOUT_1V7 (7)     /*!< 1.7V                                                                 */
#define BUCK_BUCK1NORMVOUT_BUCK1NORMVOUT_1V8 (8)     /*!< 1.8V                                                                 */
#define BUCK_BUCK1NORMVOUT_BUCK1NORMVOUT_1V9 (9)     /*!< 1.9V                                                                 */
#define BUCK_BUCK1NORMVOUT_BUCK1NORMVOUT_2V0 (10)    /*!< 2V                                                                   */
#define BUCK_BUCK1NORMVOUT_BUCK1NORMVOUT_2V1 (11)    /*!< 2.1V                                                                 */
#define BUCK_BUCK1NORMVOUT_BUCK1NORMVOUT_2V2 (12)    /*!< 2.2V                                                                 */
#define BUCK_BUCK1NORMVOUT_BUCK1NORMVOUT_2V3 (13)    /*!< 2.3V                                                                 */
#define BUCK_BUCK1NORMVOUT_BUCK1NORMVOUT_2V4 (14)    /*!< 2.4V                                                                 */
#define BUCK_BUCK1NORMVOUT_BUCK1NORMVOUT_2V5 (15)    /*!< 2.5V                                                                 */
#define BUCK_BUCK1NORMVOUT_BUCK1NORMVOUT_2V6 (16)    /*!< 2.6V                                                                 */
#define BUCK_BUCK1NORMVOUT_BUCK1NORMVOUT_2V7 (17)    /*!< 2.7V                                                                 */
#define BUCK_BUCK1NORMVOUT_BUCK1NORMVOUT_2V8 (18)    /*!< 2.8V                                                                 */
#define BUCK_BUCK1NORMVOUT_BUCK1NORMVOUT_2V9 (19)    /*!< 2.9V                                                                 */
#define BUCK_BUCK1NORMVOUT_BUCK1NORMVOUT_3V0 (20)    /*!< 3V                                                                   */
#define BUCK_BUCK1NORMVOUT_BUCK1NORMVOUT_3V1 (21)    /*!< 3.1V                                                                 */
#define BUCK_BUCK1NORMVOUT_BUCK1NORMVOUT_3V2 (22)    /*!< 3.2V                                                                 */
#define BUCK_BUCK1NORMVOUT_BUCK1NORMVOUT_3V3 (23)    /*!< 3.3V                                                                 */
#define BUCK_BUCK1NORMVOUT_BUCK1NORMVOUT_3V30 (24)   /*!< 3.3V                                                                 */


/* BUCK_BUCK1RETVOUT: BUCK1 Output voltage Retention mode */

/* BUCK1RETVOUT @Bits 0..4 : BUCK1 Output voltage Retention mode */
#define BUCK_BUCK1RETVOUT_BUCK1RETVOUT_Pos (0UL)     /*!< Position of BUCK1RETVOUT field.                                      */
#define BUCK_BUCK1RETVOUT_BUCK1RETVOUT_Msk (0x1FUL << BUCK_BUCK1RETVOUT_BUCK1RETVOUT_Pos) /*!< Bit mask of BUCK1RETVOUT field. */
#define BUCK_BUCK1RETVOUT_BUCK1RETVOUT_1V (0)        /*!< 1V                                                                   */
#define BUCK_BUCK1RETVOUT_BUCK1RETVOUT_1V1 (1)       /*!< 1.1V                                                                 */
#define BUCK_BUCK1RETVOUT_BUCK1RETVOUT_1V2 (2)       /*!< 1.2V(Default)                                                        */
#define BUCK_BUCK1RETVOUT_BUCK1RETVOUT_1V3 (3)       /*!< 1.3V                                                                 */
#define BUCK_BUCK1RETVOUT_BUCK1RETVOUT_1V4 (4)       /*!< 1.4V                                                                 */
#define BUCK_BUCK1RETVOUT_BUCK1RETVOUT_1V5 (5)       /*!< 1.5V                                                                 */
#define BUCK_BUCK1RETVOUT_BUCK1RETVOUT_1V6 (6)       /*!< 1.6V                                                                 */
#define BUCK_BUCK1RETVOUT_BUCK1RETVOUT_1V7 (7)       /*!< 1.7V                                                                 */
#define BUCK_BUCK1RETVOUT_BUCK1RETVOUT_1V8 (8)       /*!< 1.8V                                                                 */
#define BUCK_BUCK1RETVOUT_BUCK1RETVOUT_1V9 (9)       /*!< 1.9V                                                                 */
#define BUCK_BUCK1RETVOUT_BUCK1RETVOUT_2V0 (10)      /*!< 2V                                                                   */
#define BUCK_BUCK1RETVOUT_BUCK1RETVOUT_2V1 (11)      /*!< 2.1V                                                                 */
#define BUCK_BUCK1RETVOUT_BUCK1RETVOUT_2V2 (12)      /*!< 2.2V                                                                 */
#define BUCK_BUCK1RETVOUT_BUCK1RETVOUT_2V3 (13)      /*!< 2.3V                                                                 */
#define BUCK_BUCK1RETVOUT_BUCK1RETVOUT_2V4 (14)      /*!< 2.4V                                                                 */
#define BUCK_BUCK1RETVOUT_BUCK1RETVOUT_2V5 (15)      /*!< 2.5V                                                                 */
#define BUCK_BUCK1RETVOUT_BUCK1RETVOUT_2V6 (16)      /*!< 2.6V                                                                 */
#define BUCK_BUCK1RETVOUT_BUCK1RETVOUT_2V7 (17)      /*!< 2.7V                                                                 */
#define BUCK_BUCK1RETVOUT_BUCK1RETVOUT_2V8 (18)      /*!< 2.8V                                                                 */
#define BUCK_BUCK1RETVOUT_BUCK1RETVOUT_2V9 (19)      /*!< 2.9V                                                                 */
#define BUCK_BUCK1RETVOUT_BUCK1RETVOUT_3V0 (20)      /*!< 3V                                                                   */
#define BUCK_BUCK1RETVOUT_BUCK1RETVOUT_3V1 (21)      /*!< 3.1V                                                                 */
#define BUCK_BUCK1RETVOUT_BUCK1RETVOUT_3V2 (22)      /*!< 3.2V                                                                 */
#define BUCK_BUCK1RETVOUT_BUCK1RETVOUT_3V3 (23)      /*!< 3.3V                                                                 */
#define BUCK_BUCK1RETVOUT_BUCK1RETVOUT_3V30 (24)     /*!< 3.3V                                                                 */


/* BUCK_BUCK2NORMVOUT: BUCK2 Output voltage Normal mode */

/* BUCK2NORMVOUT @Bits 0..4 : BUCK2 Output voltage Normal mode */
#define BUCK_BUCK2NORMVOUT_BUCK2NORMVOUT_Pos (0UL)   /*!< Position of BUCK2NORMVOUT field.                                     */
#define BUCK_BUCK2NORMVOUT_BUCK2NORMVOUT_Msk (0x1FUL << BUCK_BUCK2NORMVOUT_BUCK2NORMVOUT_Pos) /*!< Bit mask of BUCK2NORMVOUT
                                                                            field.*/                                              
#define BUCK_BUCK2NORMVOUT_BUCK2NORMVOUT_1V (0)      /*!< 1V                                                                   */
#define BUCK_BUCK2NORMVOUT_BUCK2NORMVOUT_1V1 (1)     /*!< 1.1V                                                                 */
#define BUCK_BUCK2NORMVOUT_BUCK2NORMVOUT_1V2 (2)     /*!< 1.2V                                                                 */
#define BUCK_BUCK2NORMVOUT_BUCK2NORMVOUT_1V3 (3)     /*!< 1.3V                                                                 */
#define BUCK_BUCK2NORMVOUT_BUCK2NORMVOUT_1V4 (4)     /*!< 1.4V                                                                 */
#define BUCK_BUCK2NORMVOUT_BUCK2NORMVOUT_1V5 (5)     /*!< 1.5V                                                                 */
#define BUCK_BUCK2NORMVOUT_BUCK2NORMVOUT_1V6 (6)     /*!< 1.6V                                                                 */
#define BUCK_BUCK2NORMVOUT_BUCK2NORMVOUT_1V7 (7)     /*!< 1.7V                                                                 */
#define BUCK_BUCK2NORMVOUT_BUCK2NORMVOUT_1V8 (8)     /*!< 1.8V(Default)                                                        */
#define BUCK_BUCK2NORMVOUT_BUCK2NORMVOUT_1V9 (9)     /*!< 1.9V                                                                 */
#define BUCK_BUCK2NORMVOUT_BUCK2NORMVOUT_2V0 (10)    /*!< 2V                                                                   */
#define BUCK_BUCK2NORMVOUT_BUCK2NORMVOUT_2V1 (11)    /*!< 2.1V                                                                 */
#define BUCK_BUCK2NORMVOUT_BUCK2NORMVOUT_2V2 (12)    /*!< 2.2V                                                                 */
#define BUCK_BUCK2NORMVOUT_BUCK2NORMVOUT_2V3 (13)    /*!< 2.3V                                                                 */
#define BUCK_BUCK2NORMVOUT_BUCK2NORMVOUT_2V4 (14)    /*!< 2.4V                                                                 */
#define BUCK_BUCK2NORMVOUT_BUCK2NORMVOUT_2V5 (15)    /*!< 2.5V                                                                 */
#define BUCK_BUCK2NORMVOUT_BUCK2NORMVOUT_2V6 (16)    /*!< 2.6V                                                                 */
#define BUCK_BUCK2NORMVOUT_BUCK2NORMVOUT_2V7 (17)    /*!< 2.7V                                                                 */
#define BUCK_BUCK2NORMVOUT_BUCK2NORMVOUT_2V8 (18)    /*!< 2.8V                                                                 */
#define BUCK_BUCK2NORMVOUT_BUCK2NORMVOUT_2V9 (19)    /*!< 2.9V                                                                 */
#define BUCK_BUCK2NORMVOUT_BUCK2NORMVOUT_3V0 (20)    /*!< 3V                                                                   */
#define BUCK_BUCK2NORMVOUT_BUCK2NORMVOUT_3V1 (21)    /*!< 3.1V                                                                 */
#define BUCK_BUCK2NORMVOUT_BUCK2NORMVOUT_3V2 (22)    /*!< 3.2V                                                                 */
#define BUCK_BUCK2NORMVOUT_BUCK2NORMVOUT_3V3 (23)    /*!< 3.3V                                                                 */
#define BUCK_BUCK2NORMVOUT_BUCK2NORMVOUT_3V30 (24)   /*!< 3.3V                                                                 */


/* BUCK_BUCK2RETVOUT: BUCK2 Output voltage Retention mode */

/* BUCK2RETVOUT @Bits 0..4 : BUCK2 Output voltage Retention mode */
#define BUCK_BUCK2RETVOUT_BUCK2RETVOUT_Pos (0UL)     /*!< Position of BUCK2RETVOUT field.                                      */
#define BUCK_BUCK2RETVOUT_BUCK2RETVOUT_Msk (0x1FUL << BUCK_BUCK2RETVOUT_BUCK2RETVOUT_Pos) /*!< Bit mask of BUCK2RETVOUT field. */
#define BUCK_BUCK2RETVOUT_BUCK2RETVOUT_1V (0)        /*!< 1V                                                                   */
#define BUCK_BUCK2RETVOUT_BUCK2RETVOUT_1V1 (1)       /*!< 1.1V                                                                 */
#define BUCK_BUCK2RETVOUT_BUCK2RETVOUT_1V2 (2)       /*!< 1.2V(                                                                */
#define BUCK_BUCK2RETVOUT_BUCK2RETVOUT_1V3 (3)       /*!< 1.3V                                                                 */
#define BUCK_BUCK2RETVOUT_BUCK2RETVOUT_1V4 (4)       /*!< 1.4V                                                                 */
#define BUCK_BUCK2RETVOUT_BUCK2RETVOUT_1V5 (5)       /*!< 1.5V                                                                 */
#define BUCK_BUCK2RETVOUT_BUCK2RETVOUT_1V6 (6)       /*!< 1.6V                                                                 */
#define BUCK_BUCK2RETVOUT_BUCK2RETVOUT_1V7 (7)       /*!< 1.7V                                                                 */
#define BUCK_BUCK2RETVOUT_BUCK2RETVOUT_1V8 (8)       /*!< 1.8VDefault)                                                         */
#define BUCK_BUCK2RETVOUT_BUCK2RETVOUT_1V9 (9)       /*!< 1.9V                                                                 */
#define BUCK_BUCK2RETVOUT_BUCK2RETVOUT_2V0 (10)      /*!< 2V                                                                   */
#define BUCK_BUCK2RETVOUT_BUCK2RETVOUT_2V1 (11)      /*!< 2.1V                                                                 */
#define BUCK_BUCK2RETVOUT_BUCK2RETVOUT_2V2 (12)      /*!< 2.2V                                                                 */
#define BUCK_BUCK2RETVOUT_BUCK2RETVOUT_2V3 (13)      /*!< 2.3V                                                                 */
#define BUCK_BUCK2RETVOUT_BUCK2RETVOUT_2V4 (14)      /*!< 2.4V                                                                 */
#define BUCK_BUCK2RETVOUT_BUCK2RETVOUT_2V5 (15)      /*!< 2.5V                                                                 */
#define BUCK_BUCK2RETVOUT_BUCK2RETVOUT_2V6 (16)      /*!< 2.6V                                                                 */
#define BUCK_BUCK2RETVOUT_BUCK2RETVOUT_2V7 (17)      /*!< 2.7V                                                                 */
#define BUCK_BUCK2RETVOUT_BUCK2RETVOUT_2V8 (18)      /*!< 2.8V                                                                 */
#define BUCK_BUCK2RETVOUT_BUCK2RETVOUT_2V9 (19)      /*!< 2.9V                                                                 */
#define BUCK_BUCK2RETVOUT_BUCK2RETVOUT_3V0 (20)      /*!< 3V                                                                   */
#define BUCK_BUCK2RETVOUT_BUCK2RETVOUT_3V1 (21)      /*!< 3.1V                                                                 */
#define BUCK_BUCK2RETVOUT_BUCK2RETVOUT_3V2 (22)      /*!< 3.2V                                                                 */
#define BUCK_BUCK2RETVOUT_BUCK2RETVOUT_3V3 (23)      /*!< 3.3V                                                                 */
#define BUCK_BUCK2RETVOUT_BUCK2RETVOUT_3V30 (24)     /*!< 3.3V                                                                 */


/* BUCK_BUCKENCTRL: BUCK Enable GPIO Select */

/* BUCK1ENGPISEL @Bits 0..2 : Select which GPI controls BUCK1_enable */
#define BUCK_BUCKENCTRL_BUCK1ENGPISEL_Pos (0UL)      /*!< Position of BUCK1ENGPISEL field.                                     */
#define BUCK_BUCKENCTRL_BUCK1ENGPISEL_Msk (0x7UL << BUCK_BUCKENCTRL_BUCK1ENGPISEL_Pos) /*!< Bit mask of BUCK1ENGPISEL field.   */
#define BUCK_BUCKENCTRL_BUCK1ENGPISEL_NOTUSED (0)    /*!< Not used                                                             */
#define BUCK_BUCKENCTRL_BUCK1ENGPISEL_GPIO0 (1)      /*!< GPI_0 selected                                                       */
#define BUCK_BUCKENCTRL_BUCK1ENGPISEL_GPIO1 (2)      /*!< GPI_1 selected                                                       */
#define BUCK_BUCKENCTRL_BUCK1ENGPISEL_GPIO2 (3)      /*!< GPI_2 selected                                                       */
#define BUCK_BUCKENCTRL_BUCK1ENGPISEL_GPIO3 (4)      /*!< GPI_3 selected                                                       */
#define BUCK_BUCKENCTRL_BUCK1ENGPISEL_GPIO4 (5)      /*!< GPI_4 selected                                                       */
#define BUCK_BUCKENCTRL_BUCK1ENGPISEL_NOTUSED1 (6)   /*!< no GPI selected                                                      */
#define BUCK_BUCKENCTRL_BUCK1ENGPISEL_NOTUSED2 (7)   /*!< no GPI selected                                                      */

/* BUCK2ENGPISEL @Bits 3..5 : Select which GPI controls BUCK2_enable */
#define BUCK_BUCKENCTRL_BUCK2ENGPISEL_Pos (3UL)      /*!< Position of BUCK2ENGPISEL field.                                     */
#define BUCK_BUCKENCTRL_BUCK2ENGPISEL_Msk (0x7UL << BUCK_BUCKENCTRL_BUCK2ENGPISEL_Pos) /*!< Bit mask of BUCK2ENGPISEL field.   */
#define BUCK_BUCKENCTRL_BUCK2ENGPISEL_NOTUSED1 (0)   /*!< Not used                                                             */
#define BUCK_BUCKENCTRL_BUCK2ENGPISEL_GPIO0 (1)      /*!< GPI_0 selected                                                       */
#define BUCK_BUCKENCTRL_BUCK2ENGPISEL_GPIO1 (2)      /*!< GPI_1 selected                                                       */
#define BUCK_BUCKENCTRL_BUCK2ENGPISEL_GPIO2 (3)      /*!< GPI_2 selected                                                       */
#define BUCK_BUCKENCTRL_BUCK2ENGPISEL_GPIO3 (4)      /*!< GPI_3 selected                                                       */
#define BUCK_BUCKENCTRL_BUCK2ENGPISEL_GPIO4 (5)      /*!< GPI_4 selected                                                       */
#define BUCK_BUCKENCTRL_BUCK2ENGPISEL_NOTUSED3 (6)   /*!< no GPI selected                                                      */
#define BUCK_BUCKENCTRL_BUCK2ENGPISEL_NOTUSED4 (7)   /*!< no GPI selected                                                      */

/* BUCK1ENGPIINV @Bit 6 : Invert the sense of the selected GPIO */
#define BUCK_BUCKENCTRL_BUCK1ENGPIINV_Pos (6UL)      /*!< Position of BUCK1ENGPIINV field.                                     */
#define BUCK_BUCKENCTRL_BUCK1ENGPIINV_Msk (0x1UL << BUCK_BUCKENCTRL_BUCK1ENGPIINV_Pos) /*!< Bit mask of BUCK1ENGPIINV field.   */
#define BUCK_BUCKENCTRL_BUCK1ENGPIINV_NORMAL (0)     /*!< not Inverted                                                         */
#define BUCK_BUCKENCTRL_BUCK1ENGPIINV_INVERTED (1)   /*!< Inverted                                                             */

/* BUCK2ENGPIINV @Bit 7 : Invert the sense of the selected GPIO */
#define BUCK_BUCKENCTRL_BUCK2ENGPIINV_Pos (7UL)      /*!< Position of BUCK2ENGPIINV field.                                     */
#define BUCK_BUCKENCTRL_BUCK2ENGPIINV_Msk (0x1UL << BUCK_BUCKENCTRL_BUCK2ENGPIINV_Pos) /*!< Bit mask of BUCK2ENGPIINV field.   */
#define BUCK_BUCKENCTRL_BUCK2ENGPIINV_NORMAL (0)     /*!< not Inverted                                                         */
#define BUCK_BUCKENCTRL_BUCK2ENGPIINV_INVERTED (1)   /*!< Inverted                                                             */


/* BUCK_BUCKVRETCTRL: BUCK Retention Voltage select */

/* BUCK1VRETGPISEL @Bits 0..2 : Select which GPI controls BUCK1_retention voltage sel */
#define BUCK_BUCKVRETCTRL_BUCK1VRETGPISEL_Pos (0UL)  /*!< Position of BUCK1VRETGPISEL field.                                   */
#define BUCK_BUCKVRETCTRL_BUCK1VRETGPISEL_Msk (0x7UL << BUCK_BUCKVRETCTRL_BUCK1VRETGPISEL_Pos) /*!< Bit mask of BUCK1VRETGPISEL
                                                                            field.*/                                              
#define BUCK_BUCKVRETCTRL_BUCK1VRETGPISEL_NOTUSED (0) /*!< Not used                                                            */
#define BUCK_BUCKVRETCTRL_BUCK1VRETGPISEL_GPIO0 (1)  /*!< GPI_0 selected                                                       */
#define BUCK_BUCKVRETCTRL_BUCK1VRETGPISEL_GPIO1 (2)  /*!< GPI_1 selected                                                       */
#define BUCK_BUCKVRETCTRL_BUCK1VRETGPISEL_GPIO2 (3)  /*!< GPI_2 selected                                                       */
#define BUCK_BUCKVRETCTRL_BUCK1VRETGPISEL_GPIO3 (4)  /*!< GPI_3 selected                                                       */
#define BUCK_BUCKVRETCTRL_BUCK1VRETGPISEL_GPIO4 (5)  /*!< GPI_4 selected                                                       */
#define BUCK_BUCKVRETCTRL_BUCK1VRETGPISEL_NOTUSED2 (6) /*!< Not used                                                           */
#define BUCK_BUCKVRETCTRL_BUCK1VRETGPISEL_NOTUSED1 (7) /*!< Not used                                                           */

/* BUCK2VRETGPISEL @Bits 3..5 : Select which GPI controls BUCK2_retention voltage sel */
#define BUCK_BUCKVRETCTRL_BUCK2VRETGPISEL_Pos (3UL)  /*!< Position of BUCK2VRETGPISEL field.                                   */
#define BUCK_BUCKVRETCTRL_BUCK2VRETGPISEL_Msk (0x7UL << BUCK_BUCKVRETCTRL_BUCK2VRETGPISEL_Pos) /*!< Bit mask of BUCK2VRETGPISEL
                                                                            field.*/                                              
#define BUCK_BUCKVRETCTRL_BUCK2VRETGPISEL_NOTUSED (0) /*!< Not used                                                            */
#define BUCK_BUCKVRETCTRL_BUCK2VRETGPISEL_GPIO0 (1)  /*!< GPI_0 selected                                                       */
#define BUCK_BUCKVRETCTRL_BUCK2VRETGPISEL_GPIO1 (2)  /*!< GPI_1 selected                                                       */
#define BUCK_BUCKVRETCTRL_BUCK2VRETGPISEL_GPIO2 (3)  /*!< GPI_2 selected                                                       */
#define BUCK_BUCKVRETCTRL_BUCK2VRETGPISEL_GPIO3 (4)  /*!< GPI_3 selected                                                       */
#define BUCK_BUCKVRETCTRL_BUCK2VRETGPISEL_GPIO4 (5)  /*!< GPI_4 selected                                                       */
#define BUCK_BUCKVRETCTRL_BUCK2VRETGPISEL_NOTUSED2 (6) /*!< Not used                                                           */
#define BUCK_BUCKVRETCTRL_BUCK2VRETGPISEL_NOTUSED1 (7) /*!< Not used                                                           */

/* BUCK1VRETGPIINV @Bit 6 : Invert the sense of the selected GPIO */
#define BUCK_BUCKVRETCTRL_BUCK1VRETGPIINV_Pos (6UL)  /*!< Position of BUCK1VRETGPIINV field.                                   */
#define BUCK_BUCKVRETCTRL_BUCK1VRETGPIINV_Msk (0x1UL << BUCK_BUCKVRETCTRL_BUCK1VRETGPIINV_Pos) /*!< Bit mask of BUCK1VRETGPIINV
                                                                            field.*/                                              
#define BUCK_BUCKVRETCTRL_BUCK1VRETGPIINV_NORMAL (0) /*!< not Inverted                                                         */
#define BUCK_BUCKVRETCTRL_BUCK1VRETGPIINV_INVERTED (1) /*!< Inverted                                                           */

/* BUCK2VRETGPIINV @Bit 7 : Invert the sense of the selected GPIO */
#define BUCK_BUCKVRETCTRL_BUCK2VRETGPIINV_Pos (7UL)  /*!< Position of BUCK2VRETGPIINV field.                                   */
#define BUCK_BUCKVRETCTRL_BUCK2VRETGPIINV_Msk (0x1UL << BUCK_BUCKVRETCTRL_BUCK2VRETGPIINV_Pos) /*!< Bit mask of BUCK2VRETGPIINV
                                                                            field.*/                                              
#define BUCK_BUCKVRETCTRL_BUCK2VRETGPIINV_NORMAL (0) /*!< not Inverted                                                         */
#define BUCK_BUCKVRETCTRL_BUCK2VRETGPIINV_INVERTED (1) /*!< Inverted                                                           */


/* BUCK_BUCKPWMCTRL: BUCK Forced PWM mode GPIO select */

/* BUCK1PWMGPISEL @Bits 0..2 : Select which GPI controls BUCK1 force PWM */
#define BUCK_BUCKPWMCTRL_BUCK1PWMGPISEL_Pos (0UL)    /*!< Position of BUCK1PWMGPISEL field.                                    */
#define BUCK_BUCKPWMCTRL_BUCK1PWMGPISEL_Msk (0x7UL << BUCK_BUCKPWMCTRL_BUCK1PWMGPISEL_Pos) /*!< Bit mask of BUCK1PWMGPISEL
                                                                            field.*/                                              
#define BUCK_BUCKPWMCTRL_BUCK1PWMGPISEL_NOTUSED1 (0) /*!< Not used                                                             */
#define BUCK_BUCKPWMCTRL_BUCK1PWMGPISEL_GPIO0 (1)    /*!< GPI_0 selected                                                       */
#define BUCK_BUCKPWMCTRL_BUCK1PWMGPISEL_GPIO1 (2)    /*!< GPI_1 selected                                                       */
#define BUCK_BUCKPWMCTRL_BUCK1PWMGPISEL_GPIO2 (3)    /*!< GPI_2 selected                                                       */
#define BUCK_BUCKPWMCTRL_BUCK1PWMGPISEL_GPIO3 (4)    /*!< GPI_3 selected                                                       */
#define BUCK_BUCKPWMCTRL_BUCK1PWMGPISEL_GPIO4 (5)    /*!< GPI_4 selected                                                       */
#define BUCK_BUCKPWMCTRL_BUCK1PWMGPISEL_NOTUSED (6)  /*!< Not used                                                             */
#define BUCK_BUCKPWMCTRL_BUCK1PWMGPISEL_NOTUSED2 (7) /*!< Not used                                                             */

/* BUCK2PWMGPISEL @Bits 3..5 : Select which GPI controls BUCK2 force PWM */
#define BUCK_BUCKPWMCTRL_BUCK2PWMGPISEL_Pos (3UL)    /*!< Position of BUCK2PWMGPISEL field.                                    */
#define BUCK_BUCKPWMCTRL_BUCK2PWMGPISEL_Msk (0x7UL << BUCK_BUCKPWMCTRL_BUCK2PWMGPISEL_Pos) /*!< Bit mask of BUCK2PWMGPISEL
                                                                            field.*/                                              
#define BUCK_BUCKPWMCTRL_BUCK2PWMGPISEL_NOTUSED1 (0) /*!< Not used                                                             */
#define BUCK_BUCKPWMCTRL_BUCK2PWMGPISEL_GPIO0 (1)    /*!< GPI_0 selected                                                       */
#define BUCK_BUCKPWMCTRL_BUCK2PWMGPISEL_GPIO1 (2)    /*!< GPI_1 selected                                                       */
#define BUCK_BUCKPWMCTRL_BUCK2PWMGPISEL_GPIO2 (3)    /*!< GPI_2 selected                                                       */
#define BUCK_BUCKPWMCTRL_BUCK2PWMGPISEL_GPIO3 (4)    /*!< GPI_3 selected                                                       */
#define BUCK_BUCKPWMCTRL_BUCK2PWMGPISEL_GPIO4 (5)    /*!< GPI_4 selected                                                       */
#define BUCK_BUCKPWMCTRL_BUCK2PWMGPISEL_NOTUSED (6)  /*!< Not used                                                             */
#define BUCK_BUCKPWMCTRL_BUCK2PWMGPISEL_NOTUSED2 (7) /*!< Not used                                                             */

/* BUCK1PWMGPIINV @Bit 6 : Invert the sense of the selected GPIO */
#define BUCK_BUCKPWMCTRL_BUCK1PWMGPIINV_Pos (6UL)    /*!< Position of BUCK1PWMGPIINV field.                                    */
#define BUCK_BUCKPWMCTRL_BUCK1PWMGPIINV_Msk (0x1UL << BUCK_BUCKPWMCTRL_BUCK1PWMGPIINV_Pos) /*!< Bit mask of BUCK1PWMGPIINV
                                                                            field.*/                                              
#define BUCK_BUCKPWMCTRL_BUCK1PWMGPIINV_NORMAL (0)   /*!< not Inverted                                                         */
#define BUCK_BUCKPWMCTRL_BUCK1PWMGPIINV_INVERTED (1) /*!< Inverted                                                             */

/* BUCK2PWMGPIINV @Bit 7 : Invert the sense of the selected GPIO */
#define BUCK_BUCKPWMCTRL_BUCK2PWMGPIINV_Pos (7UL)    /*!< Position of BUCK2PWMGPIINV field.                                    */
#define BUCK_BUCKPWMCTRL_BUCK2PWMGPIINV_Msk (0x1UL << BUCK_BUCKPWMCTRL_BUCK2PWMGPIINV_Pos) /*!< Bit mask of BUCK2PWMGPIINV
                                                                            field.*/                                              
#define BUCK_BUCKPWMCTRL_BUCK2PWMGPIINV_NORMAL (0)   /*!< not Inverted                                                         */
#define BUCK_BUCKPWMCTRL_BUCK2PWMGPIINV_INVERTED (1) /*!< Inverted                                                             */


/* BUCK_BUCKSWCTRLSEL: BUCK Software Control select */

/* BUCK1SWCTRLSEL @Bit 0 : BUCK1SwCtrlSel */
#define BUCK_BUCKSWCTRLSEL_BUCK1SWCTRLSEL_Pos (0UL)  /*!< Position of BUCK1SWCTRLSEL field.                                    */
#define BUCK_BUCKSWCTRLSEL_BUCK1SWCTRLSEL_Msk (0x1UL << BUCK_BUCKSWCTRLSEL_BUCK1SWCTRLSEL_Pos) /*!< Bit mask of BUCK1SWCTRLSEL
                                                                            field.*/                                              
#define BUCK_BUCKSWCTRLSEL_BUCK1SWCTRLSEL_VSETANDSWCTRL (0) /*!< Allow VSET pins to set VOUT                                   */
#define BUCK_BUCKSWCTRLSEL_BUCK1SWCTRLSEL_SWCTRL (1) /*!< Allow SW to override VSET pin                                        */

/* BUCK2SWCTRLSEL @Bit 1 : BUCK2SwCtrlSel */
#define BUCK_BUCKSWCTRLSEL_BUCK2SWCTRLSEL_Pos (1UL)  /*!< Position of BUCK2SWCTRLSEL field.                                    */
#define BUCK_BUCKSWCTRLSEL_BUCK2SWCTRLSEL_Msk (0x1UL << BUCK_BUCKSWCTRLSEL_BUCK2SWCTRLSEL_Pos) /*!< Bit mask of BUCK2SWCTRLSEL
                                                                            field.*/                                              
#define BUCK_BUCKSWCTRLSEL_BUCK2SWCTRLSEL_VSETANDSWCTRL (0) /*!< Allow VSET pins to set VOUT                                   */
#define BUCK_BUCKSWCTRLSEL_BUCK2SWCTRLSEL_SWCTRL (1) /*!< Allow SW to override VSET pin                                        */


/* BUCK_BUCK1VOUTSTATUS: BUCK1 Vout Status register. Lets software read the Vout value in case its driven by the FSM. */

/* BUCK1VOUTSTATUS @Bits 0..4 : BUCK1VoutStatus */
#define BUCK_BUCK1VOUTSTATUS_BUCK1VOUTSTATUS_Pos (0UL) /*!< Position of BUCK1VOUTSTATUS field.                                 */
#define BUCK_BUCK1VOUTSTATUS_BUCK1VOUTSTATUS_Msk (0x1FUL << BUCK_BUCK1VOUTSTATUS_BUCK1VOUTSTATUS_Pos) /*!< Bit mask of
                                                                            BUCK1VOUTSTATUS field.*/                              


/* BUCK_BUCK2VOUTSTATUS: BUCK2 Vout Status register. Lets software read the Vout value in case its driven by the FSM. */

/* BUCK2VOUTSTATUS @Bits 0..4 : BUCK2VoutStatus */
#define BUCK_BUCK2VOUTSTATUS_BUCK2VOUTSTATUS_Pos (0UL) /*!< Position of BUCK2VOUTSTATUS field.                                 */
#define BUCK_BUCK2VOUTSTATUS_BUCK2VOUTSTATUS_Msk (0x1FUL << BUCK_BUCK2VOUTSTATUS_BUCK2VOUTSTATUS_Pos) /*!< Bit mask of
                                                                            BUCK2VOUTSTATUS field.*/                              


/* BUCK_BUCKCTRL0: BUCK Auto PFM to PWM Control select */

/* BUCK1AUTOCTRLSEL @Bit 0 : BUCK1AutoCtrlSel */
#define BUCK_BUCKCTRL0_BUCK1AUTOCTRLSEL_Pos (0UL)    /*!< Position of BUCK1AUTOCTRLSEL field.                                  */
#define BUCK_BUCKCTRL0_BUCK1AUTOCTRLSEL_Msk (0x1UL << BUCK_BUCKCTRL0_BUCK1AUTOCTRLSEL_Pos) /*!< Bit mask of BUCK1AUTOCTRLSEL
                                                                            field.*/                                              
#define BUCK_BUCKCTRL0_BUCK1AUTOCTRLSEL_AUTO (0)     /*!< Select Auto switching between PFM and PWM                            */
#define BUCK_BUCKCTRL0_BUCK1AUTOCTRLSEL_PFM (1)      /*!< Select PFM mode only                                                 */

/* BUCK2AUTOCTRLSEL @Bit 1 : BUCK2AutoCtrlSel */
#define BUCK_BUCKCTRL0_BUCK2AUTOCTRLSEL_Pos (1UL)    /*!< Position of BUCK2AUTOCTRLSEL field.                                  */
#define BUCK_BUCKCTRL0_BUCK2AUTOCTRLSEL_Msk (0x1UL << BUCK_BUCKCTRL0_BUCK2AUTOCTRLSEL_Pos) /*!< Bit mask of BUCK2AUTOCTRLSEL
                                                                            field.*/                                              
#define BUCK_BUCKCTRL0_BUCK2AUTOCTRLSEL_AUTO (0)     /*!< Select Auto switching between PFM and PWM                            */
#define BUCK_BUCKCTRL0_BUCK2AUTOCTRLSEL_PFM (1)      /*!< Select PFM mode only                                                 */

/* BUCK1ENPULLDOWN @Bit 2 : BUCK1_EN_PULLDOWN */
#define BUCK_BUCKCTRL0_BUCK1ENPULLDOWN_Pos (2UL)     /*!< Position of BUCK1ENPULLDOWN field.                                   */
#define BUCK_BUCKCTRL0_BUCK1ENPULLDOWN_Msk (0x1UL << BUCK_BUCKCTRL0_BUCK1ENPULLDOWN_Pos) /*!< Bit mask of BUCK1ENPULLDOWN
                                                                            field.*/                                              
#define BUCK_BUCKCTRL0_BUCK1ENPULLDOWN_LOW (0)       /*!< BUCK1 Pull Down Disabled                                             */
#define BUCK_BUCKCTRL0_BUCK1ENPULLDOWN_HIGH (1)      /*!< BUCK1 Pull Down Enabled                                              */

/* BUCK2ENPULLDOWN @Bit 3 : BUCK2_EN_PULLDOWN */
#define BUCK_BUCKCTRL0_BUCK2ENPULLDOWN_Pos (3UL)     /*!< Position of BUCK2ENPULLDOWN field.                                   */
#define BUCK_BUCKCTRL0_BUCK2ENPULLDOWN_Msk (0x1UL << BUCK_BUCKCTRL0_BUCK2ENPULLDOWN_Pos) /*!< Bit mask of BUCK2ENPULLDOWN
                                                                            field.*/                                              
#define BUCK_BUCKCTRL0_BUCK2ENPULLDOWN_LOW (0)       /*!< BUCK2 Pull Down Disabled                                             */
#define BUCK_BUCKCTRL0_BUCK2ENPULLDOWN_HIGH (1)      /*!< BUCK2 Pull Down Enabled                                              */


/* BUCK_BUCKSTATUS: BUCK status register */

/* BUCK1MODE @Bits 0..1 : BUCK1Mode */
#define BUCK_BUCKSTATUS_BUCK1MODE_Pos (0UL)          /*!< Position of BUCK1MODE field.                                         */
#define BUCK_BUCKSTATUS_BUCK1MODE_Msk (0x3UL << BUCK_BUCKSTATUS_BUCK1MODE_Pos) /*!< Bit mask of BUCK1MODE field.               */
#define BUCK_BUCKSTATUS_BUCK1MODE_AUTOMODE (0)       /*!< Auto mode                                                            */
#define BUCK_BUCKSTATUS_BUCK1MODE_PFMMODE (1)        /*!< PFM mode                                                             */
#define BUCK_BUCKSTATUS_BUCK1MODE_PWMMODE (2)        /*!< Force PWM mode                                                       */

/* BUCK1PWRGOOD @Bit 2 : BUCK1PwrGood */
#define BUCK_BUCKSTATUS_BUCK1PWRGOOD_Pos (2UL)       /*!< Position of BUCK1PWRGOOD field.                                      */
#define BUCK_BUCKSTATUS_BUCK1PWRGOOD_Msk (0x1UL << BUCK_BUCKSTATUS_BUCK1PWRGOOD_Pos) /*!< Bit mask of BUCK1PWRGOOD field.      */
#define BUCK_BUCKSTATUS_BUCK1PWRGOOD_BUCKDISABLED (0) /*!< BUCK powered off                                                    */
#define BUCK_BUCKSTATUS_BUCK1PWRGOOD_BUCKPOWERED (1) /*!< BUCK powered on                                                      */

/* BUCK1PWMOK @Bit 3 : BUCK1PwmOk */
#define BUCK_BUCKSTATUS_BUCK1PWMOK_Pos (3UL)         /*!< Position of BUCK1PWMOK field.                                        */
#define BUCK_BUCKSTATUS_BUCK1PWMOK_Msk (0x1UL << BUCK_BUCKSTATUS_BUCK1PWMOK_Pos) /*!< Bit mask of BUCK1PWMOK field.            */
#define BUCK_BUCKSTATUS_BUCK1PWMOK_PWMMODEDISABLED (0) /*!< PWM mode disabled                                                  */
#define BUCK_BUCKSTATUS_BUCK1PWMOK_PWMMODEENABLED (1) /*!< PWM mode enabled                                                    */

/* BUCK2MODE @Bits 4..5 : BUCK2Mode */
#define BUCK_BUCKSTATUS_BUCK2MODE_Pos (4UL)          /*!< Position of BUCK2MODE field.                                         */
#define BUCK_BUCKSTATUS_BUCK2MODE_Msk (0x3UL << BUCK_BUCKSTATUS_BUCK2MODE_Pos) /*!< Bit mask of BUCK2MODE field.               */
#define BUCK_BUCKSTATUS_BUCK2MODE_AUTOMODE (0)       /*!< Auto mode                                                            */
#define BUCK_BUCKSTATUS_BUCK2MODE_PFMMODE (1)        /*!< PFM mode                                                             */
#define BUCK_BUCKSTATUS_BUCK2MODE_PWMMODE (2)        /*!< Force PWM mode                                                       */

/* BUCK2PWRGOOD @Bit 6 : BUCK2PwrGood */
#define BUCK_BUCKSTATUS_BUCK2PWRGOOD_Pos (6UL)       /*!< Position of BUCK2PWRGOOD field.                                      */
#define BUCK_BUCKSTATUS_BUCK2PWRGOOD_Msk (0x1UL << BUCK_BUCKSTATUS_BUCK2PWRGOOD_Pos) /*!< Bit mask of BUCK2PWRGOOD field.      */
#define BUCK_BUCKSTATUS_BUCK2PWRGOOD_BUCKDISABLED (0) /*!< BUCK powered off                                                    */
#define BUCK_BUCKSTATUS_BUCK2PWRGOOD_BUCKPOWERED (1) /*!< BUCK powered on                                                      */

/* BUCK2PWMOK @Bit 7 : BUCK2PwmOk */
#define BUCK_BUCKSTATUS_BUCK2PWMOK_Pos (7UL)         /*!< Position of BUCK2PWMOK field.                                        */
#define BUCK_BUCKSTATUS_BUCK2PWMOK_Msk (0x1UL << BUCK_BUCKSTATUS_BUCK2PWMOK_Pos) /*!< Bit mask of BUCK2PWMOK field.            */
#define BUCK_BUCKSTATUS_BUCK2PWMOK_PWMMODEDISABLED (0) /*!< PWM mode disabled                                                  */
#define BUCK_BUCKSTATUS_BUCK2PWMOK_PWMMODEENABLED (1) /*!< PWM mode enabled                                                    */



/* =========================================================================================================================== */
/* ================                                            ADC                                            ================ */
/* =========================================================================================================================== */

/* ======================================================= Struct ADC ======================================================== */
/**
  * @brief Neutrino ADC registers
  */
typedef struct {                                     /*!< ADC Structure                                                        */
  __OM  uint8_t   TASKVBATMEASURE;                   /*!< (@ 0x00000000) Task Take VBAT measurement                            */
  __OM  uint8_t   TASKNTCMEASURE;                    /*!< (@ 0x00000001) Task Take NTC measurement                             */
  __OM  uint8_t   TASKTEMPMEASURE;                   /*!< (@ 0x00000002) Task Take Die Temperature measurement                 */
  __OM  uint8_t   TASKVSYSMEASURE;                   /*!< (@ 0x00000003) Task Take VSYS measurement                            */
  __IM  uint8_t   RESERVED[3];
  __OM  uint8_t   TASKVBUS7MEASURE;                  /*!< (@ 0x00000007) Task Take VBUS 7V range measurement                   */
  __OM  uint8_t   TASKDELAYEDVBATMEASURE;            /*!< (@ 0x00000008) Task Take delayed VBAT measurement                    */
  __IOM uint8_t   ADCCONFIG;                         /*!< (@ 0x00000009) ADC Configuration                                     */
  __IOM uint8_t   ADCNTCRSEL;                        /*!< (@ 0x0000000A) Select Battery NTC register                           */
  __IOM uint8_t   ADCAUTOTIMCONF;                    /*!< (@ 0x0000000B) Auto measurement intervals                            */
  __OM  uint8_t   TASKAUTOTIMUPDATE;                 /*!< (@ 0x0000000C) update toggle for NTC and Die temp AutoTime register
                                                                         bits*/                                                   
  __IOM uint8_t   ADCDELTIMCONF;                     /*!< (@ 0x0000000D) Vbat Delay timer control                              */
  __IM  uint8_t   RESERVED1[3];
  __IM  uint8_t   ADCVBATRESULTMSB;                  /*!< (@ 0x00000011) ADC VBAT measurement result MSB                       */
  __IM  uint8_t   ADCNTCRESULTMSB;                   /*!< (@ 0x00000012) ADC NTC measurement result MSB                        */
  __IM  uint8_t   ADCTEMPRESULTMSB;                  /*!< (@ 0x00000013) ADC DIE TEMP measurement result MSB                   */
  __IM  uint8_t   ADCVSYSRESULTMSB;                  /*!< (@ 0x00000014) ADC VSYS measurement result MSB                       */
  __IM  uint8_t   ADCGP0RESULTLSBS;                  /*!< (@ 0x00000015) ADC result LSB's (Vbat, Ntc, Temp and Vsys)           */
  __IM  uint8_t   ADCVBAT0RESULTMSB;                 /*!< (@ 0x00000016) ADC VBAT0 Burst measurement result MSB                */
  __IM  uint8_t   ADCVBAT1RESULTMSB;                 /*!< (@ 0x00000017) ADC VBAT1 Burst measurement result MSB                */
  __IM  uint8_t   ADCVBAT2RESULTMSB;                 /*!< (@ 0x00000018) ADC VBAT2 Burst measurement result MSB                */
  __IM  uint8_t   ADCVBAT3RESULTMSB;                 /*!< (@ 0x00000019) ADC VBAT3 Burst or VBUS measurement result MSB        */
  __IM  uint8_t   ADCGP1RESULTLSBS;                  /*!< (@ 0x0000001A) ADC result LSB's (Vbat_burst0, 1, 2 and 3)            */
}NPM_ADC_Type;                                       /*!< Size = 27 (0x01B)                                                    */

/* ADC_TASKVBATMEASURE: Task Take VBAT measurement */

/* TASKVBATMEASURE @Bit 0 : Start VBAT Measurement */
#define ADC_TASKVBATMEASURE_TASKVBATMEASURE_Pos (0UL) /*!< Position of TASKVBATMEASURE field.                                  */
#define ADC_TASKVBATMEASURE_TASKVBATMEASURE_Msk (0x1UL << ADC_TASKVBATMEASURE_TASKVBATMEASURE_Pos) /*!< Bit mask of
                                                                            TASKVBATMEASURE field.*/                              
#define ADC_TASKVBATMEASURE_TASKVBATMEASURE_NOEFFECT (0) /*!< no effect                                                        */
#define ADC_TASKVBATMEASURE_TASKVBATMEASURE_TRIGGER (1) /*!< Trigger task                                                      */


/* ADC_TASKNTCMEASURE: Task Take NTC measurement */

/* TASKNTCMEASURE @Bit 0 : Start Battery NTC Measurement */
#define ADC_TASKNTCMEASURE_TASKNTCMEASURE_Pos (0UL)  /*!< Position of TASKNTCMEASURE field.                                    */
#define ADC_TASKNTCMEASURE_TASKNTCMEASURE_Msk (0x1UL << ADC_TASKNTCMEASURE_TASKNTCMEASURE_Pos) /*!< Bit mask of TASKNTCMEASURE
                                                                            field.*/                                              
#define ADC_TASKNTCMEASURE_TASKNTCMEASURE_NOEFFECT (0) /*!< no effect                                                          */
#define ADC_TASKNTCMEASURE_TASKNTCMEASURE_TRIGGER (1) /*!< Trigger task                                                        */


/* ADC_TASKTEMPMEASURE: Task Take Die Temperature measurement */

/* TASKTEMPMEASURE @Bit 0 : Start Die Temperature Measurement */
#define ADC_TASKTEMPMEASURE_TASKTEMPMEASURE_Pos (0UL) /*!< Position of TASKTEMPMEASURE field.                                  */
#define ADC_TASKTEMPMEASURE_TASKTEMPMEASURE_Msk (0x1UL << ADC_TASKTEMPMEASURE_TASKTEMPMEASURE_Pos) /*!< Bit mask of
                                                                            TASKTEMPMEASURE field.*/                              
#define ADC_TASKTEMPMEASURE_TASKTEMPMEASURE_NOEFFECT (0) /*!< no effect                                                        */
#define ADC_TASKTEMPMEASURE_TASKTEMPMEASURE_TRIGGER (1) /*!< Trigger task                                                      */


/* ADC_TASKVSYSMEASURE: Task Take VSYS measurement */

/* TASKVSYSMEASURE @Bit 0 : Start VSYS Measurement */
#define ADC_TASKVSYSMEASURE_TASKVSYSMEASURE_Pos (0UL) /*!< Position of TASKVSYSMEASURE field.                                  */
#define ADC_TASKVSYSMEASURE_TASKVSYSMEASURE_Msk (0x1UL << ADC_TASKVSYSMEASURE_TASKVSYSMEASURE_Pos) /*!< Bit mask of
                                                                            TASKVSYSMEASURE field.*/                              
#define ADC_TASKVSYSMEASURE_TASKVSYSMEASURE_NOEFFECT (0) /*!< no effect                                                        */
#define ADC_TASKVSYSMEASURE_TASKVSYSMEASURE_TRIGGER (1) /*!< Trigger task                                                      */


/* ADC_TASKVBUS7MEASURE: Task Take VBUS 7V range measurement */

/* TASKVBUS7MEASURE @Bit 0 : Start VBUS 7Volt range Measurement */
#define ADC_TASKVBUS7MEASURE_TASKVBUS7MEASURE_Pos (0UL) /*!< Position of TASKVBUS7MEASURE field.                               */
#define ADC_TASKVBUS7MEASURE_TASKVBUS7MEASURE_Msk (0x1UL << ADC_TASKVBUS7MEASURE_TASKVBUS7MEASURE_Pos) /*!< Bit mask of
                                                                            TASKVBUS7MEASURE field.*/                             
#define ADC_TASKVBUS7MEASURE_TASKVBUS7MEASURE_NOEFFECT (0) /*!< no effect                                                      */
#define ADC_TASKVBUS7MEASURE_TASKVBUS7MEASURE_TRIGGER (1) /*!< Trigger task                                                    */


/* ADC_TASKDELAYEDVBATMEASURE: Task Take delayed VBAT measurement */

/* TASKDLYDVBATMEASURE @Bit 0 : Start delayed VBAT Measurement */
#define ADC_TASKDELAYEDVBATMEASURE_TASKDLYDVBATMEASURE_Pos (0UL) /*!< Position of TASKDLYDVBATMEASURE field.                   */
#define ADC_TASKDELAYEDVBATMEASURE_TASKDLYDVBATMEASURE_Msk (0x1UL << ADC_TASKDELAYEDVBATMEASURE_TASKDLYDVBATMEASURE_Pos) /*!<
                                                                            Bit mask of TASKDLYDVBATMEASURE field.*/              
#define ADC_TASKDELAYEDVBATMEASURE_TASKDLYDVBATMEASURE_NOEFFECT (0) /*!< no effect                                             */
#define ADC_TASKDELAYEDVBATMEASURE_TASKDLYDVBATMEASURE_TRIGGER (1) /*!< Trigger task                                           */


/* ADC_ADCCONFIG: ADC Configuration */

/* VBATAUTOENABLE @Bit 0 : Enable VBAT Auto measurement every 1 Second */
#define ADC_ADCCONFIG_VBATAUTOENABLE_Pos (0UL)       /*!< Position of VBATAUTOENABLE field.                                    */
#define ADC_ADCCONFIG_VBATAUTOENABLE_Msk (0x1UL << ADC_ADCCONFIG_VBATAUTOENABLE_Pos) /*!< Bit mask of VBATAUTOENABLE field.    */

/* VBATBURSTENABLE @Bit 1 : Enable VBAT Burst mode VBAT0, VBAT1, VBAt2, VBAT3 */
#define ADC_ADCCONFIG_VBATBURSTENABLE_Pos (1UL)      /*!< Position of VBATBURSTENABLE field.                                   */
#define ADC_ADCCONFIG_VBATBURSTENABLE_Msk (0x1UL << ADC_ADCCONFIG_VBATBURSTENABLE_Pos) /*!< Bit mask of VBATBURSTENABLE field. */


/* ADC_ADCNTCRSEL: Select Battery NTC register */

/* ADCNTCRSEL @Bits 0..1 : Select value and TRIM to match Battery NTC resistance */
#define ADC_ADCNTCRSEL_ADCNTCRSEL_Pos (0UL)          /*!< Position of ADCNTCRSEL field.                                        */
#define ADC_ADCNTCRSEL_ADCNTCRSEL_Msk (0x3UL << ADC_ADCNTCRSEL_ADCNTCRSEL_Pos) /*!< Bit mask of ADCNTCRSEL field.              */
#define ADC_ADCNTCRSEL_ADCNTCRSEL_Hi_Z (0)           /*!< No resistor                                                          */
#define ADC_ADCNTCRSEL_ADCNTCRSEL_10K (1)            /*!< NTC10K                                                               */
#define ADC_ADCNTCRSEL_ADCNTCRSEL_47K (2)            /*!< NTC47K                                                               */
#define ADC_ADCNTCRSEL_ADCNTCRSEL_100K (3)           /*!< NTC100K                                                              */


/* ADC_ADCAUTOTIMCONF: Auto measurement intervals */

/* NTCAUTOTIM @Bits 0..1 : NTC measurement interval during Charging */
#define ADC_ADCAUTOTIMCONF_NTCAUTOTIM_Pos (0UL)      /*!< Position of NTCAUTOTIM field.                                        */
#define ADC_ADCAUTOTIMCONF_NTCAUTOTIM_Msk (0x3UL << ADC_ADCAUTOTIMCONF_NTCAUTOTIM_Pos) /*!< Bit mask of NTCAUTOTIM field.      */
#define ADC_ADCAUTOTIMCONF_NTCAUTOTIM_4MS (0)        /*!< 4ms                                                                  */
#define ADC_ADCAUTOTIMCONF_NTCAUTOTIM_64MS (1)       /*!< 64ms                                                                 */
#define ADC_ADCAUTOTIMCONF_NTCAUTOTIM_128MS (2)      /*!< 128ms                                                                */
#define ADC_ADCAUTOTIMCONF_NTCAUTOTIM_1024MS (3)     /*!< 1024ms                                                               */

/* TEMPAUTOTIM @Bits 2..3 : Die Temp measurement interval during Charging */
#define ADC_ADCAUTOTIMCONF_TEMPAUTOTIM_Pos (2UL)     /*!< Position of TEMPAUTOTIM field.                                       */
#define ADC_ADCAUTOTIMCONF_TEMPAUTOTIM_Msk (0x3UL << ADC_ADCAUTOTIMCONF_TEMPAUTOTIM_Pos) /*!< Bit mask of TEMPAUTOTIM field.   */
#define ADC_ADCAUTOTIMCONF_TEMPAUTOTIM_4MS (0)       /*!< 4ms                                                                  */
#define ADC_ADCAUTOTIMCONF_TEMPAUTOTIM_8MS (1)       /*!< 8ms                                                                  */
#define ADC_ADCAUTOTIMCONF_TEMPAUTOTIM_16MS (2)      /*!< 16ms                                                                 */
#define ADC_ADCAUTOTIMCONF_TEMPAUTOTIM_32MS (3)      /*!< 32ms                                                                 */


/* ADC_TASKAUTOTIMUPDATE: update toggle for NTC and Die temp AutoTime register bits */

/* TASKAUTOTIMUPDATE @Bit 0 : update toggle, handshake signal to flag NtcAutoTim and TempAutoTim change */
#define ADC_TASKAUTOTIMUPDATE_TASKAUTOTIMUPDATE_Pos (0UL) /*!< Position of TASKAUTOTIMUPDATE field.                            */
#define ADC_TASKAUTOTIMUPDATE_TASKAUTOTIMUPDATE_Msk (0x1UL << ADC_TASKAUTOTIMUPDATE_TASKAUTOTIMUPDATE_Pos) /*!< Bit mask of
                                                                            TASKAUTOTIMUPDATE field.*/                            
#define ADC_TASKAUTOTIMUPDATE_TASKAUTOTIMUPDATE_NOEFFECT (0) /*!< no effect                                                    */
#define ADC_TASKAUTOTIMUPDATE_TASKAUTOTIMUPDATE_UPDATEAUTOTIM (1) /*!< Register new NtcAutoTim, TempAutoTim value              */


/* ADC_ADCDELTIMCONF: Vbat Delay timer control */

/* VBATDELTIM @Bits 0..7 : Delayed Vbat measurement control 4ms(value 0) to 514ms(value 255) and the step size is 2ms. */
#define ADC_ADCDELTIMCONF_VBATDELTIM_Pos (0UL)       /*!< Position of VBATDELTIM field.                                        */
#define ADC_ADCDELTIMCONF_VBATDELTIM_Msk (0xFFUL << ADC_ADCDELTIMCONF_VBATDELTIM_Pos) /*!< Bit mask of VBATDELTIM field.       */


/* ADC_ADCVBATRESULTMSB: ADC VBAT measurement result MSB */

/* VBATRESULTMSB @Bits 0..7 : ADC VBAT measurement result upper 8-bits */
#define ADC_ADCVBATRESULTMSB_VBATRESULTMSB_Pos (0UL) /*!< Position of VBATRESULTMSB field.                                     */
#define ADC_ADCVBATRESULTMSB_VBATRESULTMSB_Msk (0xFFUL << ADC_ADCVBATRESULTMSB_VBATRESULTMSB_Pos) /*!< Bit mask of VBATRESULTMSB
                                                                            field.*/                                              


/* ADC_ADCNTCRESULTMSB: ADC NTC measurement result MSB */

/* NTCRESULTMSB @Bits 0..7 : ADC NTC Battery measurement result upper 8-bits */
#define ADC_ADCNTCRESULTMSB_NTCRESULTMSB_Pos (0UL)   /*!< Position of NTCRESULTMSB field.                                      */
#define ADC_ADCNTCRESULTMSB_NTCRESULTMSB_Msk (0xFFUL << ADC_ADCNTCRESULTMSB_NTCRESULTMSB_Pos) /*!< Bit mask of NTCRESULTMSB
                                                                            field.*/                                              


/* ADC_ADCTEMPRESULTMSB: ADC DIE TEMP measurement result MSB */

/* TEMPRESULTMSB @Bits 0..7 : ADC Die Temperature measurement result upper 8-bits */
#define ADC_ADCTEMPRESULTMSB_TEMPRESULTMSB_Pos (0UL) /*!< Position of TEMPRESULTMSB field.                                     */
#define ADC_ADCTEMPRESULTMSB_TEMPRESULTMSB_Msk (0xFFUL << ADC_ADCTEMPRESULTMSB_TEMPRESULTMSB_Pos) /*!< Bit mask of TEMPRESULTMSB
                                                                            field.*/                                              


/* ADC_ADCVSYSRESULTMSB: ADC VSYS measurement result MSB */

/* VSYSRESULTMSB @Bits 0..7 : ADC VSYS measurement result upper 8-bits */
#define ADC_ADCVSYSRESULTMSB_VSYSRESULTMSB_Pos (0UL) /*!< Position of VSYSRESULTMSB field.                                     */
#define ADC_ADCVSYSRESULTMSB_VSYSRESULTMSB_Msk (0xFFUL << ADC_ADCVSYSRESULTMSB_VSYSRESULTMSB_Pos) /*!< Bit mask of VSYSRESULTMSB
                                                                            field.*/                                              


/* ADC_ADCGP0RESULTLSBS: ADC result LSB's (Vbat, Ntc, Temp and Vsys) */

/* VBATRESULTLSB @Bits 0..1 : VBAT measurement result LSBs */
#define ADC_ADCGP0RESULTLSBS_VBATRESULTLSB_Pos (0UL) /*!< Position of VBATRESULTLSB field.                                     */
#define ADC_ADCGP0RESULTLSBS_VBATRESULTLSB_Msk (0x3UL << ADC_ADCGP0RESULTLSBS_VBATRESULTLSB_Pos) /*!< Bit mask of VBATRESULTLSB
                                                                            field.*/                                              

/* NTCRESULTLSB @Bits 2..3 : Battery NTC measurement result LSBs */
#define ADC_ADCGP0RESULTLSBS_NTCRESULTLSB_Pos (2UL)  /*!< Position of NTCRESULTLSB field.                                      */
#define ADC_ADCGP0RESULTLSBS_NTCRESULTLSB_Msk (0x3UL << ADC_ADCGP0RESULTLSBS_NTCRESULTLSB_Pos) /*!< Bit mask of NTCRESULTLSB
                                                                            field.*/                                              

/* TEMPRESULTLSB @Bits 4..5 : Die Temperature measurement result LSBs */
#define ADC_ADCGP0RESULTLSBS_TEMPRESULTLSB_Pos (4UL) /*!< Position of TEMPRESULTLSB field.                                     */
#define ADC_ADCGP0RESULTLSBS_TEMPRESULTLSB_Msk (0x3UL << ADC_ADCGP0RESULTLSBS_TEMPRESULTLSB_Pos) /*!< Bit mask of TEMPRESULTLSB
                                                                            field.*/                                              

/* VSYSRESULTLSB @Bits 6..7 : VSYS measurement result LSBs */
#define ADC_ADCGP0RESULTLSBS_VSYSRESULTLSB_Pos (6UL) /*!< Position of VSYSRESULTLSB field.                                     */
#define ADC_ADCGP0RESULTLSBS_VSYSRESULTLSB_Msk (0x3UL << ADC_ADCGP0RESULTLSBS_VSYSRESULTLSB_Pos) /*!< Bit mask of VSYSRESULTLSB
                                                                            field.*/                                              


/* ADC_ADCVBAT0RESULTMSB: ADC VBAT0 Burst measurement result MSB */

/* VBAT0RESULTMSB @Bits 0..7 : ADC VBAT0 Burst measurement result upper 8-bits */
#define ADC_ADCVBAT0RESULTMSB_VBAT0RESULTMSB_Pos (0UL) /*!< Position of VBAT0RESULTMSB field.                                  */
#define ADC_ADCVBAT0RESULTMSB_VBAT0RESULTMSB_Msk (0xFFUL << ADC_ADCVBAT0RESULTMSB_VBAT0RESULTMSB_Pos) /*!< Bit mask of
                                                                            VBAT0RESULTMSB field.*/                               


/* ADC_ADCVBAT1RESULTMSB: ADC VBAT1 Burst measurement result MSB */

/* VBAT1RESULTMSB @Bits 0..7 : ADC VBAT1 Burst measurement result upper 8-bits */
#define ADC_ADCVBAT1RESULTMSB_VBAT1RESULTMSB_Pos (0UL) /*!< Position of VBAT1RESULTMSB field.                                  */
#define ADC_ADCVBAT1RESULTMSB_VBAT1RESULTMSB_Msk (0xFFUL << ADC_ADCVBAT1RESULTMSB_VBAT1RESULTMSB_Pos) /*!< Bit mask of
                                                                            VBAT1RESULTMSB field.*/                               


/* ADC_ADCVBAT2RESULTMSB: ADC VBAT2 Burst measurement result MSB */

/* VBAT2RESULTMSB @Bits 0..7 : ADC VBAT2 Burst measurement result upper 8-bits */
#define ADC_ADCVBAT2RESULTMSB_VBAT2RESULTMSB_Pos (0UL) /*!< Position of VBAT2RESULTMSB field.                                  */
#define ADC_ADCVBAT2RESULTMSB_VBAT2RESULTMSB_Msk (0xFFUL << ADC_ADCVBAT2RESULTMSB_VBAT2RESULTMSB_Pos) /*!< Bit mask of
                                                                            VBAT2RESULTMSB field.*/                               


/* ADC_ADCVBAT3RESULTMSB: ADC VBAT3 Burst or VBUS measurement result MSB */

/* VBAT3RESULTMSB @Bits 0..7 : If TASK_VBAT_MEASURE is triggered in BURST mode, this register will contain ADC VBAT3 Burst
                               measurement result upper 8-bits
If TASK_VBUS7_MEASURE is triggered, this register will contain
                               VBUS measurement result upper 8-bits */                                                            
                                                                                                                                  
#define ADC_ADCVBAT3RESULTMSB_VBAT3RESULTMSB_Pos (0UL) /*!< Position of VBAT3RESULTMSB field.                                  */
#define ADC_ADCVBAT3RESULTMSB_VBAT3RESULTMSB_Msk (0xFFUL << ADC_ADCVBAT3RESULTMSB_VBAT3RESULTMSB_Pos) /*!< Bit mask of
                                                                            VBAT3RESULTMSB field.*/                               


/* ADC_ADCGP1RESULTLSBS: ADC result LSB's (Vbat_burst0, 1, 2 and 3) */

/* VBAT0RESULTLSB @Bits 0..1 : Burst VBAT0 measurement result LSBs */
#define ADC_ADCGP1RESULTLSBS_VBAT0RESULTLSB_Pos (0UL) /*!< Position of VBAT0RESULTLSB field.                                   */
#define ADC_ADCGP1RESULTLSBS_VBAT0RESULTLSB_Msk (0x3UL << ADC_ADCGP1RESULTLSBS_VBAT0RESULTLSB_Pos) /*!< Bit mask of
                                                                            VBAT0RESULTLSB field.*/                               

/* VBAT1RESULTLSB @Bits 2..3 : Burst VBAT1 measurement result LSBs */
#define ADC_ADCGP1RESULTLSBS_VBAT1RESULTLSB_Pos (2UL) /*!< Position of VBAT1RESULTLSB field.                                   */
#define ADC_ADCGP1RESULTLSBS_VBAT1RESULTLSB_Msk (0x3UL << ADC_ADCGP1RESULTLSBS_VBAT1RESULTLSB_Pos) /*!< Bit mask of
                                                                            VBAT1RESULTLSB field.*/                               

/* VBAT2RESULTLSB @Bits 4..5 : Burst VBAT2 measurement result LSBs */
#define ADC_ADCGP1RESULTLSBS_VBAT2RESULTLSB_Pos (4UL) /*!< Position of VBAT2RESULTLSB field.                                   */
#define ADC_ADCGP1RESULTLSBS_VBAT2RESULTLSB_Msk (0x3UL << ADC_ADCGP1RESULTLSBS_VBAT2RESULTLSB_Pos) /*!< Bit mask of
                                                                            VBAT2RESULTLSB field.*/                               

/* VBAT3RESULTLSB @Bits 6..7 : Burst VBAT3 measurement result LSBs */
#define ADC_ADCGP1RESULTLSBS_VBAT3RESULTLSB_Pos (6UL) /*!< Position of VBAT3RESULTLSB field.                                   */
#define ADC_ADCGP1RESULTLSBS_VBAT3RESULTLSB_Msk (0x3UL << ADC_ADCGP1RESULTLSBS_VBAT3RESULTLSB_Pos) /*!< Bit mask of
                                                                            VBAT3RESULTLSB field.*/                               



/* =========================================================================================================================== */
/* ================                                           GPIOS                                           ================ */
/* =========================================================================================================================== */

/* ====================================================== Struct GPIOS ======================================================= */
/**
  * @brief Neutrino GPIOS registers
  */
typedef struct {                                     /*!< GPIOS Structure                                                      */
  __IOM uint8_t   GPIOMODE0;                         /*!< (@ 0x00000000) GPIO Mode Configuration                               */
  __IOM uint8_t   GPIOMODE1;                         /*!< (@ 0x00000001) GPIO Mode Configuration                               */
  __IOM uint8_t   GPIOMODE2;                         /*!< (@ 0x00000002) GPIO Mode Configuration                               */
  __IOM uint8_t   GPIOMODE3;                         /*!< (@ 0x00000003) GPIO Mode Configuration                               */
  __IOM uint8_t   GPIOMODE4;                         /*!< (@ 0x00000004) GPIO Mode Configuration                               */
  __IOM uint8_t   GPIODRIVE0;                        /*!< (@ 0x00000005) GPIO Drive strength Configuration                     */
  __IOM uint8_t   GPIODRIVE1;                        /*!< (@ 0x00000006) GPIO Drive strength Configuration                     */
  __IOM uint8_t   GPIODRIVE2;                        /*!< (@ 0x00000007) GPIO Drive strength Configuration                     */
  __IOM uint8_t   GPIODRIVE3;                        /*!< (@ 0x00000008) GPIO Drive strength Configuration                     */
  __IOM uint8_t   GPIODRIVE4;                        /*!< (@ 0x00000009) GPIO Drive strength Configuration                     */
  __IOM uint8_t   GPIOPUEN0;                         /*!< (@ 0x0000000A) GPIO Pull-up Enable Configuration                     */
  __IOM uint8_t   GPIOPUEN1;                         /*!< (@ 0x0000000B) GPIO Pull-up Enable Configuration                     */
  __IOM uint8_t   GPIOPUEN2;                         /*!< (@ 0x0000000C) GPIO Pull-up Enable Configuration                     */
  __IOM uint8_t   GPIOPUEN3;                         /*!< (@ 0x0000000D) GPIO Pull-up Enable Configuration                     */
  __IOM uint8_t   GPIOPUEN4;                         /*!< (@ 0x0000000E) GPIO Pull-up Enable Configuration                     */
  __IOM uint8_t   GPIOPDEN0;                         /*!< (@ 0x0000000F) GPIO Pull-down Enable Configuration                   */
  __IOM uint8_t   GPIOPDEN1;                         /*!< (@ 0x00000010) GPIO Pull-down Enable Configuration                   */
  __IOM uint8_t   GPIOPDEN2;                         /*!< (@ 0x00000011) GPIO Pull-down Enable Configuration                   */
  __IOM uint8_t   GPIOPDEN3;                         /*!< (@ 0x00000012) GPIO Pull-down Enable Configuration                   */
  __IOM uint8_t   GPIOPDEN4;                         /*!< (@ 0x00000013) GPIO Pull-down Enable Configuration                   */
  __IOM uint8_t   GPIOOPENDRAIN0;                    /*!< (@ 0x00000014) GPIO Open Drain Configuration                         */
  __IOM uint8_t   GPIOOPENDRAIN1;                    /*!< (@ 0x00000015) GPIO Open Drain Configuration                         */
  __IOM uint8_t   GPIOOPENDRAIN2;                    /*!< (@ 0x00000016) GPIO Open Drain Configuration                         */
  __IOM uint8_t   GPIOOPENDRAIN3;                    /*!< (@ 0x00000017) GPIO Open Drain Configuration                         */
  __IOM uint8_t   GPIOOPENDRAIN4;                    /*!< (@ 0x00000018) GPIO Open Drain Configuration                         */
  __IOM uint8_t   GPIODEBOUNCE0;                     /*!< (@ 0x00000019) GPIO Debounce Configuration                           */
  __IOM uint8_t   GPIODEBOUNCE1;                     /*!< (@ 0x0000001A) GPIO Debounce Configuration                           */
  __IOM uint8_t   GPIODEBOUNCE2;                     /*!< (@ 0x0000001B) GPIO Debounce Configuration                           */
  __IOM uint8_t   GPIODEBOUNCE3;                     /*!< (@ 0x0000001C) GPIO Debounce Configuration                           */
  __IOM uint8_t   GPIODEBOUNCE4;                     /*!< (@ 0x0000001D) GPIO Debounce Configuration                           */
  __IM  uint8_t   GPIOSTATUS;                        /*!< (@ 0x0000001E) GPIO Status from GPIO Pads                            */
}NPM_GPIOS_Type;                                     /*!< Size = 31 (0x01F)                                                    */

/* GPIOS_GPIOMODE0: GPIO Mode Configuration */

/* GPIOMODE @Bits 0..3 : Config for GPIO mode selection */
#define GPIOS_GPIOMODE0_GPIOMODE_Pos (0UL)           /*!< Position of GPIOMODE field.                                          */
#define GPIOS_GPIOMODE0_GPIOMODE_Msk (0xFUL << GPIOS_GPIOMODE0_GPIOMODE_Pos) /*!< Bit mask of GPIOMODE field.                  */
#define GPIOS_GPIOMODE0_GPIOMODE_GPIINPUT (0)        /*!< GPI Input                                                            */
#define GPIOS_GPIOMODE0_GPIOMODE_GPILOGIC1 (1)       /*!< GPI Logic1                                                           */
#define GPIOS_GPIOMODE0_GPIOMODE_GPILOGIC0 (2)       /*!< GPI Logic0                                                           */
#define GPIOS_GPIOMODE0_GPIOMODE_GPIEVENTRISE (3)    /*!< GPI Rising Edge Event                                                */
#define GPIOS_GPIOMODE0_GPIOMODE_GPIEVENTFALL (4)    /*!< GPI Falling Edge Event                                               */
#define GPIOS_GPIOMODE0_GPIOMODE_GPOIRQ (5)          /*!< GPO Interrupt                                                        */
#define GPIOS_GPIOMODE0_GPIOMODE_GPORESET (6)        /*!< GPO Reset                                                            */
#define GPIOS_GPIOMODE0_GPIOMODE_GPOPLW (7)          /*!< GPO PwrLossWarn                                                      */
#define GPIOS_GPIOMODE0_GPIOMODE_GPOLOGIC1 (8)       /*!< GPO Logic1                                                           */
#define GPIOS_GPIOMODE0_GPIOMODE_GPOLOGIC0 (9)       /*!< GPO Logic0                                                           */


/* GPIOS_GPIOMODE1: GPIO Mode Configuration */

/* GPIOMODE @Bits 0..3 : Config for GPIO mode selection */
#define GPIOS_GPIOMODE1_GPIOMODE_Pos (0UL)           /*!< Position of GPIOMODE field.                                          */
#define GPIOS_GPIOMODE1_GPIOMODE_Msk (0xFUL << GPIOS_GPIOMODE1_GPIOMODE_Pos) /*!< Bit mask of GPIOMODE field.                  */
#define GPIOS_GPIOMODE1_GPIOMODE_GPIINPUT (0)        /*!< GPI Input                                                            */
#define GPIOS_GPIOMODE1_GPIOMODE_GPILOGIC1 (1)       /*!< GPI Logic1                                                           */
#define GPIOS_GPIOMODE1_GPIOMODE_GPILOGIC0 (2)       /*!< GPI Logic0                                                           */
#define GPIOS_GPIOMODE1_GPIOMODE_GPIEVENTRISE (3)    /*!< GPI Rising Edge Event                                                */
#define GPIOS_GPIOMODE1_GPIOMODE_GPIEVENTFALL (4)    /*!< GPI Falling Edge Event                                               */
#define GPIOS_GPIOMODE1_GPIOMODE_GPOIRQ (5)          /*!< GPO Interrupt                                                        */
#define GPIOS_GPIOMODE1_GPIOMODE_GPORESET (6)        /*!< GPO Reset                                                            */
#define GPIOS_GPIOMODE1_GPIOMODE_GPOPLW (7)          /*!< GPO PwrLossWarn                                                      */
#define GPIOS_GPIOMODE1_GPIOMODE_GPOLOGIC1 (8)       /*!< GPO Logic1                                                           */
#define GPIOS_GPIOMODE1_GPIOMODE_GPOLOGIC0 (9)       /*!< GPO Logic0                                                           */


/* GPIOS_GPIOMODE2: GPIO Mode Configuration */

/* GPIOMODE @Bits 0..3 : Config for GPIO mode selection */
#define GPIOS_GPIOMODE2_GPIOMODE_Pos (0UL)           /*!< Position of GPIOMODE field.                                          */
#define GPIOS_GPIOMODE2_GPIOMODE_Msk (0xFUL << GPIOS_GPIOMODE2_GPIOMODE_Pos) /*!< Bit mask of GPIOMODE field.                  */
#define GPIOS_GPIOMODE2_GPIOMODE_GPIINPUT (0)        /*!< GPI Input                                                            */
#define GPIOS_GPIOMODE2_GPIOMODE_GPILOGIC1 (1)       /*!< GPI Logic1                                                           */
#define GPIOS_GPIOMODE2_GPIOMODE_GPILOGIC0 (2)       /*!< GPI Logic0                                                           */
#define GPIOS_GPIOMODE2_GPIOMODE_GPIEVENTRISE (3)    /*!< GPI Rising Edge Event                                                */
#define GPIOS_GPIOMODE2_GPIOMODE_GPIEVENTFALL (4)    /*!< GPI Falling Edge Event                                               */
#define GPIOS_GPIOMODE2_GPIOMODE_GPOIRQ (5)          /*!< GPO Interrupt                                                        */
#define GPIOS_GPIOMODE2_GPIOMODE_GPORESET (6)        /*!< GPO Reset                                                            */
#define GPIOS_GPIOMODE2_GPIOMODE_GPOPLW (7)          /*!< GPO PwrLossWarn                                                      */
#define GPIOS_GPIOMODE2_GPIOMODE_GPOLOGIC1 (8)       /*!< GPO Logic1                                                           */
#define GPIOS_GPIOMODE2_GPIOMODE_GPOLOGIC0 (9)       /*!< GPO Logic0                                                           */


/* GPIOS_GPIOMODE3: GPIO Mode Configuration */

/* GPIOMODE @Bits 0..3 : Config for GPIO mode selection */
#define GPIOS_GPIOMODE3_GPIOMODE_Pos (0UL)           /*!< Position of GPIOMODE field.                                          */
#define GPIOS_GPIOMODE3_GPIOMODE_Msk (0xFUL << GPIOS_GPIOMODE3_GPIOMODE_Pos) /*!< Bit mask of GPIOMODE field.                  */
#define GPIOS_GPIOMODE3_GPIOMODE_GPIINPUT (0)        /*!< GPI Input                                                            */
#define GPIOS_GPIOMODE3_GPIOMODE_GPILOGIC1 (1)       /*!< GPI Logic1                                                           */
#define GPIOS_GPIOMODE3_GPIOMODE_GPILOGIC0 (2)       /*!< GPI Logic0                                                           */
#define GPIOS_GPIOMODE3_GPIOMODE_GPIEVENTRISE (3)    /*!< GPI Rising Edge Event                                                */
#define GPIOS_GPIOMODE3_GPIOMODE_GPIEVENTFALL (4)    /*!< GPI Falling Edge Event                                               */
#define GPIOS_GPIOMODE3_GPIOMODE_GPOIRQ (5)          /*!< GPO Interrupt                                                        */
#define GPIOS_GPIOMODE3_GPIOMODE_GPORESET (6)        /*!< GPO Reset                                                            */
#define GPIOS_GPIOMODE3_GPIOMODE_GPOPLW (7)          /*!< GPO PwrLossWarn                                                      */
#define GPIOS_GPIOMODE3_GPIOMODE_GPOLOGIC1 (8)       /*!< GPO Logic1                                                           */
#define GPIOS_GPIOMODE3_GPIOMODE_GPOLOGIC0 (9)       /*!< GPO Logic0                                                           */


/* GPIOS_GPIOMODE4: GPIO Mode Configuration */

/* GPIOMODE @Bits 0..3 : Config for GPIO mode selection */
#define GPIOS_GPIOMODE4_GPIOMODE_Pos (0UL)           /*!< Position of GPIOMODE field.                                          */
#define GPIOS_GPIOMODE4_GPIOMODE_Msk (0xFUL << GPIOS_GPIOMODE4_GPIOMODE_Pos) /*!< Bit mask of GPIOMODE field.                  */
#define GPIOS_GPIOMODE4_GPIOMODE_GPIINPUT (0)        /*!< GPI Input                                                            */
#define GPIOS_GPIOMODE4_GPIOMODE_GPILOGIC1 (1)       /*!< GPI Logic1                                                           */
#define GPIOS_GPIOMODE4_GPIOMODE_GPILOGIC0 (2)       /*!< GPI Logic0                                                           */
#define GPIOS_GPIOMODE4_GPIOMODE_GPIEVENTRISE (3)    /*!< GPI Rising Edge Event                                                */
#define GPIOS_GPIOMODE4_GPIOMODE_GPIEVENTFALL (4)    /*!< GPI Falling Edge Event                                               */
#define GPIOS_GPIOMODE4_GPIOMODE_GPOIRQ (5)          /*!< GPO Interrupt                                                        */
#define GPIOS_GPIOMODE4_GPIOMODE_GPORESET (6)        /*!< GPO Reset                                                            */
#define GPIOS_GPIOMODE4_GPIOMODE_GPOPLW (7)          /*!< GPO PwrLossWarn                                                      */
#define GPIOS_GPIOMODE4_GPIOMODE_GPOLOGIC1 (8)       /*!< GPO Logic1                                                           */
#define GPIOS_GPIOMODE4_GPIOMODE_GPOLOGIC0 (9)       /*!< GPO Logic0                                                           */


/* GPIOS_GPIODRIVE0: GPIO Drive strength Configuration */

/* GPIODRIVE @Bit 0 : Config for GPIO drive strength */
#define GPIOS_GPIODRIVE0_GPIODRIVE_Pos (0UL)         /*!< Position of GPIODRIVE field.                                         */
#define GPIOS_GPIODRIVE0_GPIODRIVE_Msk (0x1UL << GPIOS_GPIODRIVE0_GPIODRIVE_Pos) /*!< Bit mask of GPIODRIVE field.             */
#define GPIOS_GPIODRIVE0_GPIODRIVE_1MA (0)           /*!< 1mA                                                                  */
#define GPIOS_GPIODRIVE0_GPIODRIVE_6MA (1)           /*!< 6mA                                                                  */


/* GPIOS_GPIODRIVE1: GPIO Drive strength Configuration */

/* GPIODRIVE @Bit 0 : Config for GPIO drive strength */
#define GPIOS_GPIODRIVE1_GPIODRIVE_Pos (0UL)         /*!< Position of GPIODRIVE field.                                         */
#define GPIOS_GPIODRIVE1_GPIODRIVE_Msk (0x1UL << GPIOS_GPIODRIVE1_GPIODRIVE_Pos) /*!< Bit mask of GPIODRIVE field.             */
#define GPIOS_GPIODRIVE1_GPIODRIVE_1MA (0)           /*!< 1mA                                                                  */
#define GPIOS_GPIODRIVE1_GPIODRIVE_6MA (1)           /*!< 6mA                                                                  */


/* GPIOS_GPIODRIVE2: GPIO Drive strength Configuration */

/* GPIODRIVE @Bit 0 : Config for GPIO drive strength */
#define GPIOS_GPIODRIVE2_GPIODRIVE_Pos (0UL)         /*!< Position of GPIODRIVE field.                                         */
#define GPIOS_GPIODRIVE2_GPIODRIVE_Msk (0x1UL << GPIOS_GPIODRIVE2_GPIODRIVE_Pos) /*!< Bit mask of GPIODRIVE field.             */
#define GPIOS_GPIODRIVE2_GPIODRIVE_1MA (0)           /*!< 1mA                                                                  */
#define GPIOS_GPIODRIVE2_GPIODRIVE_6MA (1)           /*!< 6mA                                                                  */


/* GPIOS_GPIODRIVE3: GPIO Drive strength Configuration */

/* GPIODRIVE @Bit 0 : Config for GPIO drive strength */
#define GPIOS_GPIODRIVE3_GPIODRIVE_Pos (0UL)         /*!< Position of GPIODRIVE field.                                         */
#define GPIOS_GPIODRIVE3_GPIODRIVE_Msk (0x1UL << GPIOS_GPIODRIVE3_GPIODRIVE_Pos) /*!< Bit mask of GPIODRIVE field.             */
#define GPIOS_GPIODRIVE3_GPIODRIVE_1MA (0)           /*!< 1mA                                                                  */
#define GPIOS_GPIODRIVE3_GPIODRIVE_6MA (1)           /*!< 6mA                                                                  */


/* GPIOS_GPIODRIVE4: GPIO Drive strength Configuration */

/* GPIODRIVE @Bit 0 : Config for GPIO drive strength */
#define GPIOS_GPIODRIVE4_GPIODRIVE_Pos (0UL)         /*!< Position of GPIODRIVE field.                                         */
#define GPIOS_GPIODRIVE4_GPIODRIVE_Msk (0x1UL << GPIOS_GPIODRIVE4_GPIODRIVE_Pos) /*!< Bit mask of GPIODRIVE field.             */
#define GPIOS_GPIODRIVE4_GPIODRIVE_1MA (0)           /*!< 1mA                                                                  */
#define GPIOS_GPIODRIVE4_GPIODRIVE_6MA (1)           /*!< 6mA                                                                  */


/* GPIOS_GPIOPUEN0: GPIO Pull-up Enable Configuration */

/* GPIOPUEN @Bit 0 : Config for GPIO pull-up enable */
#define GPIOS_GPIOPUEN0_GPIOPUEN_Pos (0UL)           /*!< Position of GPIOPUEN field.                                          */
#define GPIOS_GPIOPUEN0_GPIOPUEN_Msk (0x1UL << GPIOS_GPIOPUEN0_GPIOPUEN_Pos) /*!< Bit mask of GPIOPUEN field.                  */
#define GPIOS_GPIOPUEN0_GPIOPUEN_PULLUP0 (0)         /*!< Pull Up Disable                                                      */
#define GPIOS_GPIOPUEN0_GPIOPUEN_PULLUP1 (1)         /*!< Pull Up Enable                                                       */


/* GPIOS_GPIOPUEN1: GPIO Pull-up Enable Configuration */

/* GPIOPUEN @Bit 0 : Config for GPIO pull-up enable */
#define GPIOS_GPIOPUEN1_GPIOPUEN_Pos (0UL)           /*!< Position of GPIOPUEN field.                                          */
#define GPIOS_GPIOPUEN1_GPIOPUEN_Msk (0x1UL << GPIOS_GPIOPUEN1_GPIOPUEN_Pos) /*!< Bit mask of GPIOPUEN field.                  */
#define GPIOS_GPIOPUEN1_GPIOPUEN_PULLUP0 (0)         /*!< Pull Up Disable                                                      */
#define GPIOS_GPIOPUEN1_GPIOPUEN_PULLUP1 (1)         /*!< Pull Up Enable                                                       */


/* GPIOS_GPIOPUEN2: GPIO Pull-up Enable Configuration */

/* GPIOPUEN @Bit 0 : Config for GPIO pull-up enable */
#define GPIOS_GPIOPUEN2_GPIOPUEN_Pos (0UL)           /*!< Position of GPIOPUEN field.                                          */
#define GPIOS_GPIOPUEN2_GPIOPUEN_Msk (0x1UL << GPIOS_GPIOPUEN2_GPIOPUEN_Pos) /*!< Bit mask of GPIOPUEN field.                  */
#define GPIOS_GPIOPUEN2_GPIOPUEN_PULLUP0 (0)         /*!< Pull Up Disable                                                      */
#define GPIOS_GPIOPUEN2_GPIOPUEN_PULLUP1 (1)         /*!< Pull Up Enable                                                       */


/* GPIOS_GPIOPUEN3: GPIO Pull-up Enable Configuration */

/* GPIOPUEN @Bit 0 : Config for GPIO pull-up enable */
#define GPIOS_GPIOPUEN3_GPIOPUEN_Pos (0UL)           /*!< Position of GPIOPUEN field.                                          */
#define GPIOS_GPIOPUEN3_GPIOPUEN_Msk (0x1UL << GPIOS_GPIOPUEN3_GPIOPUEN_Pos) /*!< Bit mask of GPIOPUEN field.                  */
#define GPIOS_GPIOPUEN3_GPIOPUEN_PULLUP0 (0)         /*!< Pull Up Disable                                                      */
#define GPIOS_GPIOPUEN3_GPIOPUEN_PULLUP1 (1)         /*!< Pull Up Enable                                                       */


/* GPIOS_GPIOPUEN4: GPIO Pull-up Enable Configuration */

/* GPIOPUEN @Bit 0 : Config for GPIO pull-up enable */
#define GPIOS_GPIOPUEN4_GPIOPUEN_Pos (0UL)           /*!< Position of GPIOPUEN field.                                          */
#define GPIOS_GPIOPUEN4_GPIOPUEN_Msk (0x1UL << GPIOS_GPIOPUEN4_GPIOPUEN_Pos) /*!< Bit mask of GPIOPUEN field.                  */
#define GPIOS_GPIOPUEN4_GPIOPUEN_PULLUP0 (0)         /*!< Pull Up Disable                                                      */
#define GPIOS_GPIOPUEN4_GPIOPUEN_PULLUP1 (1)         /*!< Pull Up Enable                                                       */


/* GPIOS_GPIOPDEN0: GPIO Pull-down Enable Configuration */

/* GPIOPDEN @Bit 0 : Config for GPIO pull-down enable */
#define GPIOS_GPIOPDEN0_GPIOPDEN_Pos (0UL)           /*!< Position of GPIOPDEN field.                                          */
#define GPIOS_GPIOPDEN0_GPIOPDEN_Msk (0x1UL << GPIOS_GPIOPDEN0_GPIOPDEN_Pos) /*!< Bit mask of GPIOPDEN field.                  */
#define GPIOS_GPIOPDEN0_GPIOPDEN_PULLDOWN0 (0)       /*!< Pull Down Disable                                                    */
#define GPIOS_GPIOPDEN0_GPIOPDEN_PULLDOWN1 (1)       /*!< Pull Down Enable                                                     */


/* GPIOS_GPIOPDEN1: GPIO Pull-down Enable Configuration */

/* GPIOPDEN @Bit 0 : Config for GPIO pull-down enable */
#define GPIOS_GPIOPDEN1_GPIOPDEN_Pos (0UL)           /*!< Position of GPIOPDEN field.                                          */
#define GPIOS_GPIOPDEN1_GPIOPDEN_Msk (0x1UL << GPIOS_GPIOPDEN1_GPIOPDEN_Pos) /*!< Bit mask of GPIOPDEN field.                  */
#define GPIOS_GPIOPDEN1_GPIOPDEN_PULLDOWN0 (0)       /*!< Pull Down Disable                                                    */
#define GPIOS_GPIOPDEN1_GPIOPDEN_PULLDOWN1 (1)       /*!< Pull Down Enable                                                     */


/* GPIOS_GPIOPDEN2: GPIO Pull-down Enable Configuration */

/* GPIOPDEN @Bit 0 : Config for GPIO pull-down enable */
#define GPIOS_GPIOPDEN2_GPIOPDEN_Pos (0UL)           /*!< Position of GPIOPDEN field.                                          */
#define GPIOS_GPIOPDEN2_GPIOPDEN_Msk (0x1UL << GPIOS_GPIOPDEN2_GPIOPDEN_Pos) /*!< Bit mask of GPIOPDEN field.                  */
#define GPIOS_GPIOPDEN2_GPIOPDEN_PULLDOWN0 (0)       /*!< Pull Down Disable                                                    */
#define GPIOS_GPIOPDEN2_GPIOPDEN_PULLDOWN1 (1)       /*!< Pull Down Enable                                                     */


/* GPIOS_GPIOPDEN3: GPIO Pull-down Enable Configuration */

/* GPIOPDEN @Bit 0 : Config for GPIO pull-down enable */
#define GPIOS_GPIOPDEN3_GPIOPDEN_Pos (0UL)           /*!< Position of GPIOPDEN field.                                          */
#define GPIOS_GPIOPDEN3_GPIOPDEN_Msk (0x1UL << GPIOS_GPIOPDEN3_GPIOPDEN_Pos) /*!< Bit mask of GPIOPDEN field.                  */
#define GPIOS_GPIOPDEN3_GPIOPDEN_PULLDOWN0 (0)       /*!< Pull Down Disable                                                    */
#define GPIOS_GPIOPDEN3_GPIOPDEN_PULLDOWN1 (1)       /*!< Pull Down Enable                                                     */


/* GPIOS_GPIOPDEN4: GPIO Pull-down Enable Configuration */

/* GPIOPDEN @Bit 0 : Config for GPIO pull-down enable */
#define GPIOS_GPIOPDEN4_GPIOPDEN_Pos (0UL)           /*!< Position of GPIOPDEN field.                                          */
#define GPIOS_GPIOPDEN4_GPIOPDEN_Msk (0x1UL << GPIOS_GPIOPDEN4_GPIOPDEN_Pos) /*!< Bit mask of GPIOPDEN field.                  */
#define GPIOS_GPIOPDEN4_GPIOPDEN_PULLDOWN0 (0)       /*!< Pull Down Disable                                                    */
#define GPIOS_GPIOPDEN4_GPIOPDEN_PULLDOWN1 (1)       /*!< Pull Down Enable                                                     */


/* GPIOS_GPIOOPENDRAIN0: GPIO Open Drain Configuration */

/* GPIOOPENDRAIN @Bit 0 : Config for GPIO open drain */
#define GPIOS_GPIOOPENDRAIN0_GPIOOPENDRAIN_Pos (0UL) /*!< Position of GPIOOPENDRAIN field.                                     */
#define GPIOS_GPIOOPENDRAIN0_GPIOOPENDRAIN_Msk (0x1UL << GPIOS_GPIOOPENDRAIN0_GPIOOPENDRAIN_Pos) /*!< Bit mask of GPIOOPENDRAIN
                                                                            field.*/                                              
#define GPIOS_GPIOOPENDRAIN0_GPIOOPENDRAIN_OPENDRAIN0 (0) /*!< Open Drain Disable                                              */
#define GPIOS_GPIOOPENDRAIN0_GPIOOPENDRAIN_OPENDRAIN1 (1) /*!< Open Drain Enable                                               */


/* GPIOS_GPIOOPENDRAIN1: GPIO Open Drain Configuration */

/* GPIOOPENDRAIN @Bit 0 : Config for GPIO open drain */
#define GPIOS_GPIOOPENDRAIN1_GPIOOPENDRAIN_Pos (0UL) /*!< Position of GPIOOPENDRAIN field.                                     */
#define GPIOS_GPIOOPENDRAIN1_GPIOOPENDRAIN_Msk (0x1UL << GPIOS_GPIOOPENDRAIN1_GPIOOPENDRAIN_Pos) /*!< Bit mask of GPIOOPENDRAIN
                                                                            field.*/                                              
#define GPIOS_GPIOOPENDRAIN1_GPIOOPENDRAIN_OPENDRAIN0 (0) /*!< Open Drain Disable                                              */
#define GPIOS_GPIOOPENDRAIN1_GPIOOPENDRAIN_OPENDRAIN1 (1) /*!< Open Drain Enable                                               */


/* GPIOS_GPIOOPENDRAIN2: GPIO Open Drain Configuration */

/* GPIOOPENDRAIN @Bit 0 : Config for GPIO open drain */
#define GPIOS_GPIOOPENDRAIN2_GPIOOPENDRAIN_Pos (0UL) /*!< Position of GPIOOPENDRAIN field.                                     */
#define GPIOS_GPIOOPENDRAIN2_GPIOOPENDRAIN_Msk (0x1UL << GPIOS_GPIOOPENDRAIN2_GPIOOPENDRAIN_Pos) /*!< Bit mask of GPIOOPENDRAIN
                                                                            field.*/                                              
#define GPIOS_GPIOOPENDRAIN2_GPIOOPENDRAIN_OPENDRAIN0 (0) /*!< Open Drain Disable                                              */
#define GPIOS_GPIOOPENDRAIN2_GPIOOPENDRAIN_OPENDRAIN1 (1) /*!< Open Drain Enable                                               */


/* GPIOS_GPIOOPENDRAIN3: GPIO Open Drain Configuration */

/* GPIOOPENDRAIN @Bit 0 : Config for GPIO open drain */
#define GPIOS_GPIOOPENDRAIN3_GPIOOPENDRAIN_Pos (0UL) /*!< Position of GPIOOPENDRAIN field.                                     */
#define GPIOS_GPIOOPENDRAIN3_GPIOOPENDRAIN_Msk (0x1UL << GPIOS_GPIOOPENDRAIN3_GPIOOPENDRAIN_Pos) /*!< Bit mask of GPIOOPENDRAIN
                                                                            field.*/                                              
#define GPIOS_GPIOOPENDRAIN3_GPIOOPENDRAIN_OPENDRAIN0 (0) /*!< Open Drain Disable                                              */
#define GPIOS_GPIOOPENDRAIN3_GPIOOPENDRAIN_OPENDRAIN1 (1) /*!< Open Drain Enable                                               */


/* GPIOS_GPIOOPENDRAIN4: GPIO Open Drain Configuration */

/* GPIOOPENDRAIN @Bit 0 : Config for GPIO open drain */
#define GPIOS_GPIOOPENDRAIN4_GPIOOPENDRAIN_Pos (0UL) /*!< Position of GPIOOPENDRAIN field.                                     */
#define GPIOS_GPIOOPENDRAIN4_GPIOOPENDRAIN_Msk (0x1UL << GPIOS_GPIOOPENDRAIN4_GPIOOPENDRAIN_Pos) /*!< Bit mask of GPIOOPENDRAIN
                                                                            field.*/                                              
#define GPIOS_GPIOOPENDRAIN4_GPIOOPENDRAIN_OPENDRAIN0 (0) /*!< Open Drain Disable                                              */
#define GPIOS_GPIOOPENDRAIN4_GPIOOPENDRAIN_OPENDRAIN1 (1) /*!< Open Drain Enable                                               */


/* GPIOS_GPIODEBOUNCE0: GPIO Debounce Configuration */

/* GPIODEBOUNCE @Bit 0 : Config for GPIO debounce */
#define GPIOS_GPIODEBOUNCE0_GPIODEBOUNCE_Pos (0UL)   /*!< Position of GPIODEBOUNCE field.                                      */
#define GPIOS_GPIODEBOUNCE0_GPIODEBOUNCE_Msk (0x1UL << GPIOS_GPIODEBOUNCE0_GPIODEBOUNCE_Pos) /*!< Bit mask of GPIODEBOUNCE
                                                                            field.*/                                              
#define GPIOS_GPIODEBOUNCE0_GPIODEBOUNCE_DEBOUNCE0 (0) /*!< Debounce Disable                                                   */
#define GPIOS_GPIODEBOUNCE0_GPIODEBOUNCE_DEBOUNCE1 (1) /*!< Debounce Enable                                                    */


/* GPIOS_GPIODEBOUNCE1: GPIO Debounce Configuration */

/* GPIODEBOUNCE @Bit 0 : Config for GPIO debounce */
#define GPIOS_GPIODEBOUNCE1_GPIODEBOUNCE_Pos (0UL)   /*!< Position of GPIODEBOUNCE field.                                      */
#define GPIOS_GPIODEBOUNCE1_GPIODEBOUNCE_Msk (0x1UL << GPIOS_GPIODEBOUNCE1_GPIODEBOUNCE_Pos) /*!< Bit mask of GPIODEBOUNCE
                                                                            field.*/                                              
#define GPIOS_GPIODEBOUNCE1_GPIODEBOUNCE_DEBOUNCE0 (0) /*!< Debounce Disable                                                   */
#define GPIOS_GPIODEBOUNCE1_GPIODEBOUNCE_DEBOUNCE1 (1) /*!< Debounce Enable                                                    */


/* GPIOS_GPIODEBOUNCE2: GPIO Debounce Configuration */

/* GPIODEBOUNCE @Bit 0 : Config for GPIO debounce */
#define GPIOS_GPIODEBOUNCE2_GPIODEBOUNCE_Pos (0UL)   /*!< Position of GPIODEBOUNCE field.                                      */
#define GPIOS_GPIODEBOUNCE2_GPIODEBOUNCE_Msk (0x1UL << GPIOS_GPIODEBOUNCE2_GPIODEBOUNCE_Pos) /*!< Bit mask of GPIODEBOUNCE
                                                                            field.*/                                              
#define GPIOS_GPIODEBOUNCE2_GPIODEBOUNCE_DEBOUNCE0 (0) /*!< Debounce Disable                                                   */
#define GPIOS_GPIODEBOUNCE2_GPIODEBOUNCE_DEBOUNCE1 (1) /*!< Debounce Enable                                                    */


/* GPIOS_GPIODEBOUNCE3: GPIO Debounce Configuration */

/* GPIODEBOUNCE @Bit 0 : Config for GPIO debounce */
#define GPIOS_GPIODEBOUNCE3_GPIODEBOUNCE_Pos (0UL)   /*!< Position of GPIODEBOUNCE field.                                      */
#define GPIOS_GPIODEBOUNCE3_GPIODEBOUNCE_Msk (0x1UL << GPIOS_GPIODEBOUNCE3_GPIODEBOUNCE_Pos) /*!< Bit mask of GPIODEBOUNCE
                                                                            field.*/                                              
#define GPIOS_GPIODEBOUNCE3_GPIODEBOUNCE_DEBOUNCE0 (0) /*!< Debounce Disable                                                   */
#define GPIOS_GPIODEBOUNCE3_GPIODEBOUNCE_DEBOUNCE1 (1) /*!< Debounce Enable                                                    */


/* GPIOS_GPIODEBOUNCE4: GPIO Debounce Configuration */

/* GPIODEBOUNCE @Bit 0 : Config for GPIO debounce */
#define GPIOS_GPIODEBOUNCE4_GPIODEBOUNCE_Pos (0UL)   /*!< Position of GPIODEBOUNCE field.                                      */
#define GPIOS_GPIODEBOUNCE4_GPIODEBOUNCE_Msk (0x1UL << GPIOS_GPIODEBOUNCE4_GPIODEBOUNCE_Pos) /*!< Bit mask of GPIODEBOUNCE
                                                                            field.*/                                              
#define GPIOS_GPIODEBOUNCE4_GPIODEBOUNCE_DEBOUNCE0 (0) /*!< Debounce Disable                                                   */
#define GPIOS_GPIODEBOUNCE4_GPIODEBOUNCE_DEBOUNCE1 (1) /*!< Debounce Enable                                                    */


/* GPIOS_GPIOSTATUS: GPIO Status from GPIO Pads */

/* GPIO0STATUS @Bit 0 : gpioMode[0] inside {[0:4]} : GPIO[0] Input
gpioMode[0] inside {[5:9]} : GPIO[0] Outnput
else 0 */
#define GPIOS_GPIOSTATUS_GPIO0STATUS_Pos (0UL)       /*!< Position of GPIO0STATUS field.                                       */
#define GPIOS_GPIOSTATUS_GPIO0STATUS_Msk (0x1UL << GPIOS_GPIOSTATUS_GPIO0STATUS_Pos) /*!< Bit mask of GPIO0STATUS field.       */
#define GPIOS_GPIOSTATUS_GPIO0STATUS_LOW (0)         /*!< Input Low                                                            */
#define GPIOS_GPIOSTATUS_GPIO0STATUS_HIGH (1)        /*!< Input High                                                           */

/* GPIO1STATUS @Bit 1 : gpioMode[1] inside {[0:4]} : GPIO[1] Input
gpioMode[1] inside {[5:9]} : GPIO[1] Outnput
else 0 */
#define GPIOS_GPIOSTATUS_GPIO1STATUS_Pos (1UL)       /*!< Position of GPIO1STATUS field.                                       */
#define GPIOS_GPIOSTATUS_GPIO1STATUS_Msk (0x1UL << GPIOS_GPIOSTATUS_GPIO1STATUS_Pos) /*!< Bit mask of GPIO1STATUS field.       */
#define GPIOS_GPIOSTATUS_GPIO1STATUS_LOW (0)         /*!< Input Low                                                            */
#define GPIOS_GPIOSTATUS_GPIO1STATUS_HIGH (1)        /*!< Input High                                                           */

/* GPIO2STATUS @Bit 2 : gpioMode[2] inside {[0:4]} : GPIO[2] Input
gpioMode[2] inside {[5:9]} : GPIO[2] Outnput
else 0 */
#define GPIOS_GPIOSTATUS_GPIO2STATUS_Pos (2UL)       /*!< Position of GPIO2STATUS field.                                       */
#define GPIOS_GPIOSTATUS_GPIO2STATUS_Msk (0x1UL << GPIOS_GPIOSTATUS_GPIO2STATUS_Pos) /*!< Bit mask of GPIO2STATUS field.       */
#define GPIOS_GPIOSTATUS_GPIO2STATUS_LOW (0)         /*!< Input Low                                                            */
#define GPIOS_GPIOSTATUS_GPIO2STATUS_HIGH (1)        /*!< Input High                                                           */

/* GPIO3STATUS @Bit 3 : gpioMode[3] inside {[0:4]} : GPIO[3] Input
gpioMode[3] inside {[5:9]} : GPIO[3] Outnput
else 0 */
#define GPIOS_GPIOSTATUS_GPIO3STATUS_Pos (3UL)       /*!< Position of GPIO3STATUS field.                                       */
#define GPIOS_GPIOSTATUS_GPIO3STATUS_Msk (0x1UL << GPIOS_GPIOSTATUS_GPIO3STATUS_Pos) /*!< Bit mask of GPIO3STATUS field.       */
#define GPIOS_GPIOSTATUS_GPIO3STATUS_LOW (0)         /*!< Input Low                                                            */
#define GPIOS_GPIOSTATUS_GPIO3STATUS_HIGH (1)        /*!< Input High                                                           */

/* GPIO4STATUS @Bit 4 : gpioMode[4] inside {[0:4]} : GPIO[4] Input
gpioMode[4] inside {[5:9]} : GPIO[4] Outnput
else 0 */
#define GPIOS_GPIOSTATUS_GPIO4STATUS_Pos (4UL)       /*!< Position of GPIO4STATUS field.                                       */
#define GPIOS_GPIOSTATUS_GPIO4STATUS_Msk (0x1UL << GPIOS_GPIOSTATUS_GPIO4STATUS_Pos) /*!< Bit mask of GPIO4STATUS field.       */
#define GPIOS_GPIOSTATUS_GPIO4STATUS_LOW (0)         /*!< Input Low                                                            */
#define GPIOS_GPIOSTATUS_GPIO4STATUS_HIGH (1)        /*!< Input High                                                           */



/* =========================================================================================================================== */
/* ================                                           TIMER                                           ================ */
/* =========================================================================================================================== */

/* ====================================================== Struct TIMER ======================================================= */
/**
  * @brief Neutrino TIMER registers
  */
typedef struct {                                     /*!< TIMER Structure                                                      */
  __OM  uint8_t   TIMERSET;                          /*!< (@ 0x00000000) Start Timer                                           */
  __OM  uint8_t   TIMERCLR;                          /*!< (@ 0x00000001) Stop Timer                                            */
  __IM  uint8_t   RESERVED;
  __OM  uint8_t   TIMERTARGETSTROBE;                 /*!< (@ 0x00000003) Strobe for timer Target                               */
  __OM  uint8_t   WATCHDOGKICK;                      /*!< (@ 0x00000004) Watchdog kick                                         */
  __IOM uint8_t   TIMERCONFIG;                       /*!< (@ 0x00000005) Timer mode selection                                  */
  __IM  uint8_t   TIMERSTATUS;                       /*!< (@ 0x00000006) Timers Status                                         */
  __IM  uint8_t   RESERVED1;
  __IOM uint8_t   TIMERHIBYTE;                       /*!< (@ 0x00000008) Timer Most Significant Byte                           */
  __IOM uint8_t   TIMERMIDBYTE;                      /*!< (@ 0x00000009) Timer Middle Byte                                     */
  __IOM uint8_t   TIMERLOBYTE;                       /*!< (@ 0x0000000A) Timer Least Significant Byte                          */
}NPM_TIMER_Type;                                     /*!< Size = 11 (0x00B)                                                    */

/* TIMER_TIMERSET: Start Timer */

/* TASKTIMEREN @Bit 0 : Start Timer */
#define TIMER_TIMERSET_TASKTIMEREN_Pos (0UL)         /*!< Position of TASKTIMEREN field.                                       */
#define TIMER_TIMERSET_TASKTIMEREN_Msk (0x1UL << TIMER_TIMERSET_TASKTIMEREN_Pos) /*!< Bit mask of TASKTIMEREN field.           */
#define TIMER_TIMERSET_TASKTIMEREN_NOEFFECT (0)      /*!< no effect                                                            */
#define TIMER_TIMERSET_TASKTIMEREN_SET (1)           /*!< Timer Start request                                                  */


/* TIMER_TIMERCLR: Stop Timer */

/* TASKTIMERDIS @Bit 0 : Stop Timer */
#define TIMER_TIMERCLR_TASKTIMERDIS_Pos (0UL)        /*!< Position of TASKTIMERDIS field.                                      */
#define TIMER_TIMERCLR_TASKTIMERDIS_Msk (0x1UL << TIMER_TIMERCLR_TASKTIMERDIS_Pos) /*!< Bit mask of TASKTIMERDIS field.        */
#define TIMER_TIMERCLR_TASKTIMERDIS_NOEFFECT (0)     /*!< no effect                                                            */
#define TIMER_TIMERCLR_TASKTIMERDIS_SET (1)          /*!< Timer Stop request                                                   */


/* TIMER_TIMERTARGETSTROBE: Strobe for timer Target */

/* TASKTIMERTARGETSTROBE @Bit 0 : Timer target strobe */
#define TIMER_TIMERTARGETSTROBE_TASKTIMERTARGETSTROBE_Pos (0UL) /*!< Position of TASKTIMERTARGETSTROBE field.                  */
#define TIMER_TIMERTARGETSTROBE_TASKTIMERTARGETSTROBE_Msk (0x1UL << TIMER_TIMERTARGETSTROBE_TASKTIMERTARGETSTROBE_Pos) /*!< Bit
                                                                            mask of TASKTIMERTARGETSTROBE field.*/                
#define TIMER_TIMERTARGETSTROBE_TASKTIMERTARGETSTROBE_NOEFFECT (0) /*!< no effect                                              */
#define TIMER_TIMERTARGETSTROBE_TASKTIMERTARGETSTROBE_SET (1) /*!< load timer target (24 bit timer val)                        */


/* TIMER_WATCHDOGKICK: Watchdog kick */

/* TASKWATCHDOGKICK @Bit 0 : Watchdog kick */
#define TIMER_WATCHDOGKICK_TASKWATCHDOGKICK_Pos (0UL) /*!< Position of TASKWATCHDOGKICK field.                                 */
#define TIMER_WATCHDOGKICK_TASKWATCHDOGKICK_Msk (0x1UL << TIMER_WATCHDOGKICK_TASKWATCHDOGKICK_Pos) /*!< Bit mask of
                                                                            TASKWATCHDOGKICK field.*/                             
#define TIMER_WATCHDOGKICK_TASKWATCHDOGKICK_NOEFFECT (0) /*!< no effect                                                        */
#define TIMER_WATCHDOGKICK_TASKWATCHDOGKICK_Kick (1) /*!< kick watchdog                                                        */


/* TIMER_TIMERCONFIG: Timer mode selection */

/* TIMERMODESEL @Bits 0..2 : Select Watchdog and timer modes */
#define TIMER_TIMERCONFIG_TIMERMODESEL_Pos (0UL)     /*!< Position of TIMERMODESEL field.                                      */
#define TIMER_TIMERCONFIG_TIMERMODESEL_Msk (0x7UL << TIMER_TIMERCONFIG_TIMERMODESEL_Pos) /*!< Bit mask of TIMERMODESEL field.  */
#define TIMER_TIMERCONFIG_TIMERMODESEL_BOOTMONITOR (0) /*!< Boot Monitor                                                       */
#define TIMER_TIMERCONFIG_TIMERMODESEL_WATCHDOGWARNING (1) /*!< Watchdog Warning                                               */
#define TIMER_TIMERCONFIG_TIMERMODESEL_WATCHDOGRESET (2) /*!< Watchdog Reset                                                   */
#define TIMER_TIMERCONFIG_TIMERMODESEL_GENPURPOSETIMER (3) /*!< GenPurpose Timer                                               */
#define TIMER_TIMERCONFIG_TIMERMODESEL_WAKEUPTIMER (4) /*!< Wakeup Timer                                                       */

/* TIMERPRESCALER @Bit 3 : Switches between 16ms and 2ms Timer Prescale */
#define TIMER_TIMERCONFIG_TIMERPRESCALER_Pos (3UL)   /*!< Position of TIMERPRESCALER field.                                    */
#define TIMER_TIMERCONFIG_TIMERPRESCALER_Msk (0x1UL << TIMER_TIMERCONFIG_TIMERPRESCALER_Pos) /*!< Bit mask of TIMERPRESCALER
                                                                            field.*/                                              
#define TIMER_TIMERCONFIG_TIMERPRESCALER_SLOW (0)    /*!< 16ms Prescale                                                        */
#define TIMER_TIMERCONFIG_TIMERPRESCALER_FAST (1)    /*!< 2ms Prescale                                                         */


/* TIMER_TIMERSTATUS: Timers Status */

/* BOOTMONITORACTIVE @Bit 0 : BootMonitor Active */
#define TIMER_TIMERSTATUS_BOOTMONITORACTIVE_Pos (0UL) /*!< Position of BOOTMONITORACTIVE field.                                */
#define TIMER_TIMERSTATUS_BOOTMONITORACTIVE_Msk (0x1UL << TIMER_TIMERSTATUS_BOOTMONITORACTIVE_Pos) /*!< Bit mask of
                                                                            BOOTMONITORACTIVE field.*/                            
#define TIMER_TIMERSTATUS_BOOTMONITORACTIVE_INACTIVE (0) /*!< Boot Monitor not running                                         */
#define TIMER_TIMERSTATUS_BOOTMONITORACTIVE_ACTIVE (1) /*!< BootMonitor running                                                */

/* SLOWDOMAINCONFIGURED @Bit 1 : slowDomain Configured */
#define TIMER_TIMERSTATUS_SLOWDOMAINCONFIGURED_Pos (1UL) /*!< Position of SLOWDOMAINCONFIGURED field.                          */
#define TIMER_TIMERSTATUS_SLOWDOMAINCONFIGURED_Msk (0x1UL << TIMER_TIMERSTATUS_SLOWDOMAINCONFIGURED_Pos) /*!< Bit mask of
                                                                            SLOWDOMAINCONFIGURED field.*/                         
#define TIMER_TIMERSTATUS_SLOWDOMAINCONFIGURED_NOTCONFIG (0) /*!< No config, TASK_RESET_CFG clears.                            */
#define TIMER_TIMERSTATUS_SLOWDOMAINCONFIGURED_CONFIG (1) /*!< At least one timer related Strobe has been active to configure
                                                               slowDomain*/                                                       


/* TIMER_TIMERHIBYTE: Timer Most Significant Byte */

/* TIMERHIBYTE @Bits 0..7 : Timer Most Significant Byte of 3 */
#define TIMER_TIMERHIBYTE_TIMERHIBYTE_Pos (0UL)      /*!< Position of TIMERHIBYTE field.                                       */
#define TIMER_TIMERHIBYTE_TIMERHIBYTE_Msk (0xFFUL << TIMER_TIMERHIBYTE_TIMERHIBYTE_Pos) /*!< Bit mask of TIMERHIBYTE field.    */


/* TIMER_TIMERMIDBYTE: Timer Middle Byte */

/* TIMERMIDBYTE @Bits 0..7 : Timer Middle Byte of 3 */
#define TIMER_TIMERMIDBYTE_TIMERMIDBYTE_Pos (0UL)    /*!< Position of TIMERMIDBYTE field.                                      */
#define TIMER_TIMERMIDBYTE_TIMERMIDBYTE_Msk (0xFFUL << TIMER_TIMERMIDBYTE_TIMERMIDBYTE_Pos) /*!< Bit mask of TIMERMIDBYTE
                                                                            field.*/                                              


/* TIMER_TIMERLOBYTE: Timer Least Significant Byte */

/* TIMERLOBYTE @Bits 0..7 : Timer Least Significant Byte of 3 */
#define TIMER_TIMERLOBYTE_TIMERLOBYTE_Pos (0UL)      /*!< Position of TIMERLOBYTE field.                                       */
#define TIMER_TIMERLOBYTE_TIMERLOBYTE_Msk (0xFFUL << TIMER_TIMERLOBYTE_TIMERLOBYTE_Pos) /*!< Bit mask of TIMERLOBYTE field.    */



/* =========================================================================================================================== */
/* ================                                           LDSW                                           ================ */
/* =========================================================================================================================== */

/* ======================================================= Struct LDSW ======================================================= */
/**
  * @brief Neutrino LDSW registers
  */
typedef struct {                                     /*!< LDSW Structure                                                       */
  __OM  uint8_t   TASKLDSW1SET;                      /*!< (@ 0x00000000) Enable LDSW1                                          */
  __OM  uint8_t   TASKLDSW1CLR;                      /*!< (@ 0x00000001) Disable LDSW1                                         */
  __OM  uint8_t   TASKLDSW2SET;                      /*!< (@ 0x00000002) Enable LDSW2                                          */
  __OM  uint8_t   TASKLDSW2CLR;                      /*!< (@ 0x00000003) Disable LDSW2                                         */
  __IM  uint8_t   LDSWSTATUS;                        /*!< (@ 0x00000004) Load Switch Status                                    */
  __IOM uint8_t   LDSW1GPISEL;                       /*!< (@ 0x00000005) Load Switch1 GPIO Control Select                      */
  __IOM uint8_t   LDSW2GPISEL;                       /*!< (@ 0x00000006) Load Switch2 GPIO Control Select                      */
  __IOM uint8_t   LDSWCONFIG;                        /*!< (@ 0x00000007) Load Switch Configuration                             */
  __IOM uint8_t   LDSW1LDOSEL;                       /*!< (@ 0x00000008) Load Switch1 / LDO Select                             */
  __IOM uint8_t   LDSW2LDOSEL;                       /*!< (@ 0x00000009) Load Switch2 / LDO Select                             */
  __IM  uint8_t   RESERVED[2];
  __IOM uint8_t   LDSW1VOUTSEL;                      /*!< (@ 0x0000000C) LDO1 programmable output voltage                      */
  __IOM uint8_t   LDSW2VOUTSEL;                      /*!< (@ 0x0000000D) LDO2 programmable output voltage                      */
}NPM_LDSW_Type;                                      /*!< Size = 14 (0x00E)                                                    */

/* LDSW_TASKLDSW1SET: Enable LDSW1 */

/* TASKLDSW1SET @Bit 0 : LDSW1_Enable request SET */
#define LDSW_TASKLDSW1SET_TASKLDSW1SET_Pos (0UL)     /*!< Position of TASKLDSW1SET field.                                      */
#define LDSW_TASKLDSW1SET_TASKLDSW1SET_Msk (0x1UL << LDSW_TASKLDSW1SET_TASKLDSW1SET_Pos) /*!< Bit mask of TASKLDSW1SET field.  */
#define LDSW_TASKLDSW1SET_TASKLDSW1SET_NOEFFECT (0)  /*!< no effect                                                            */
#define LDSW_TASKLDSW1SET_TASKLDSW1SET_SET (1)       /*!< LDSW1 Enable request set                                             */


/* LDSW_TASKLDSW1CLR: Disable LDSW1 */

/* TASKLDSW1CLR @Bit 0 : LDSW1_Enable request CLR */
#define LDSW_TASKLDSW1CLR_TASKLDSW1CLR_Pos (0UL)     /*!< Position of TASKLDSW1CLR field.                                      */
#define LDSW_TASKLDSW1CLR_TASKLDSW1CLR_Msk (0x1UL << LDSW_TASKLDSW1CLR_TASKLDSW1CLR_Pos) /*!< Bit mask of TASKLDSW1CLR field.  */
#define LDSW_TASKLDSW1CLR_TASKLDSW1CLR_NOEFFECT (0)  /*!< no effect                                                            */
#define LDSW_TASKLDSW1CLR_TASKLDSW1CLR_CLR (1)       /*!< LDSW1 Disable request clr                                            */


/* LDSW_TASKLDSW2SET: Enable LDSW2 */

/* TASKLDSW2SET @Bit 0 : LDSW2_Enable request SET */
#define LDSW_TASKLDSW2SET_TASKLDSW2SET_Pos (0UL)     /*!< Position of TASKLDSW2SET field.                                      */
#define LDSW_TASKLDSW2SET_TASKLDSW2SET_Msk (0x1UL << LDSW_TASKLDSW2SET_TASKLDSW2SET_Pos) /*!< Bit mask of TASKLDSW2SET field.  */
#define LDSW_TASKLDSW2SET_TASKLDSW2SET_NOEFFECT (0)  /*!< no effect                                                            */
#define LDSW_TASKLDSW2SET_TASKLDSW2SET_SET (1)       /*!< LDSW2 Enable request set                                             */


/* LDSW_TASKLDSW2CLR: Disable LDSW2 */

/* TASKLDSW2CLR @Bit 0 : LDSW2_Enable request CLR */
#define LDSW_TASKLDSW2CLR_TASKLDSW2CLR_Pos (0UL)     /*!< Position of TASKLDSW2CLR field.                                      */
#define LDSW_TASKLDSW2CLR_TASKLDSW2CLR_Msk (0x1UL << LDSW_TASKLDSW2CLR_TASKLDSW2CLR_Pos) /*!< Bit mask of TASKLDSW2CLR field.  */
#define LDSW_TASKLDSW2CLR_TASKLDSW2CLR_NOEFFECT (0)  /*!< no effect                                                            */
#define LDSW_TASKLDSW2CLR_TASKLDSW2CLR_CLR (1)       /*!< LDSW2 Disable request clr                                            */


/* LDSW_LDSWSTATUS: Load Switch Status */

/* LDSW1PWRUPLDSW @Bit 0 : Power up signal to move load switch 1 into and out of load switch state. When the load switch is
                           enabled the low-dropout regulator is disabled. This is ensured by digital logic. */                    
                                                                                                                                  
#define LDSW_LDSWSTATUS_LDSW1PWRUPLDSW_Pos (0UL)     /*!< Position of LDSW1PWRUPLDSW field.                                    */
#define LDSW_LDSWSTATUS_LDSW1PWRUPLDSW_Msk (0x1UL << LDSW_LDSWSTATUS_LDSW1PWRUPLDSW_Pos) /*!< Bit mask of LDSW1PWRUPLDSW field.*/

/* LDSW1PWRUPLDO @Bit 1 : Power up signal to move low-dropout regulator 1into and out of low-dropout active state. When the
                          low-dropout regulator is enabled the load switch is disabled. */                                        
                                                                                                                                  
#define LDSW_LDSWSTATUS_LDSW1PWRUPLDO_Pos (1UL)      /*!< Position of LDSW1PWRUPLDO field.                                     */
#define LDSW_LDSWSTATUS_LDSW1PWRUPLDO_Msk (0x1UL << LDSW_LDSWSTATUS_LDSW1PWRUPLDO_Pos) /*!< Bit mask of LDSW1PWRUPLDO field.   */

/* LDSW2PWRUPLDSW @Bit 2 : Power up signal to move low-dropout regulator 2 into and out of low-dropout active state. When the
                           low-dropout regulator is enabled the load switch is disabled. This is ensured by digital logic. */     
                                                                                                                                  
#define LDSW_LDSWSTATUS_LDSW2PWRUPLDSW_Pos (2UL)     /*!< Position of LDSW2PWRUPLDSW field.                                    */
#define LDSW_LDSWSTATUS_LDSW2PWRUPLDSW_Msk (0x1UL << LDSW_LDSWSTATUS_LDSW2PWRUPLDSW_Pos) /*!< Bit mask of LDSW2PWRUPLDSW field.*/

/* LDSW2PWRUPLDO @Bit 3 : Load switch 2 softstart causes passfet to deliver a constant current from LS2_IN to LS2_OUT. It brings
                          the load switch into and out of the sofstart state. */                                                  
                                                                                                                                  
#define LDSW_LDSWSTATUS_LDSW2PWRUPLDO_Pos (3UL)      /*!< Position of LDSW2PWRUPLDO field.                                     */
#define LDSW_LDSWSTATUS_LDSW2PWRUPLDO_Msk (0x1UL << LDSW_LDSWSTATUS_LDSW2PWRUPLDO_Pos) /*!< Bit mask of LDSW2PWRUPLDO field.   */

/* LDSWENABLE @Bit 4 : Enable signal to move the overal load switch + low-dropout regulator IP from Awake to Deepsleep state to
                       save power when required. */                                                                               
                                                                                                                                  
#define LDSW_LDSWSTATUS_LDSWENABLE_Pos (4UL)         /*!< Position of LDSWENABLE field.                                        */
#define LDSW_LDSWSTATUS_LDSWENABLE_Msk (0x1UL << LDSW_LDSWSTATUS_LDSWENABLE_Pos) /*!< Bit mask of LDSWENABLE field.            */


/* LDSW_LDSW1GPISEL: Load Switch1 GPIO Control Select */

/* LDSW1GPISEL @Bits 0..2 : Select which GPI controls Load Switch1 */
#define LDSW_LDSW1GPISEL_LDSW1GPISEL_Pos (0UL)       /*!< Position of LDSW1GPISEL field.                                       */
#define LDSW_LDSW1GPISEL_LDSW1GPISEL_Msk (0x7UL << LDSW_LDSW1GPISEL_LDSW1GPISEL_Pos) /*!< Bit mask of LDSW1GPISEL field.       */
#define LDSW_LDSW1GPISEL_LDSW1GPISEL_NOTUSED1 (0)    /*!< no GPI selected                                                      */
#define LDSW_LDSW1GPISEL_LDSW1GPISEL_GPIO0 (1)       /*!< GPI_0 selected                                                       */
#define LDSW_LDSW1GPISEL_LDSW1GPISEL_GPIO1 (2)       /*!< GPI_1 selected                                                       */
#define LDSW_LDSW1GPISEL_LDSW1GPISEL_GPIO2 (3)       /*!< GPI_2 selected                                                       */
#define LDSW_LDSW1GPISEL_LDSW1GPISEL_GPIO3 (4)       /*!< GPI_3 selected                                                       */
#define LDSW_LDSW1GPISEL_LDSW1GPISEL_GPIO4 (5)       /*!< GPI_4 selected                                                       */
#define LDSW_LDSW1GPISEL_LDSW1GPISEL_NOTUSED2 (6)    /*!< no GPI selected                                                      */
#define LDSW_LDSW1GPISEL_LDSW1GPISEL_NOTUSED3 (7)    /*!< no GPI selected                                                      */

/* LDSW1GPIINV @Bit 3 : Invert the sense of the selected GPIO */
#define LDSW_LDSW1GPISEL_LDSW1GPIINV_Pos (3UL)       /*!< Position of LDSW1GPIINV field.                                       */
#define LDSW_LDSW1GPISEL_LDSW1GPIINV_Msk (0x1UL << LDSW_LDSW1GPISEL_LDSW1GPIINV_Pos) /*!< Bit mask of LDSW1GPIINV field.       */
#define LDSW_LDSW1GPISEL_LDSW1GPIINV_NORMAL (0)      /*!< not Inverted                                                         */
#define LDSW_LDSW1GPISEL_LDSW1GPIINV_INVERTED (1)    /*!< Inverted                                                             */


/* LDSW_LDSW2GPISEL: Load Switch2 GPIO Control Select */

/* LDSW2GPISEL @Bits 0..2 : Select which GPI controls Load Switch2 */
#define LDSW_LDSW2GPISEL_LDSW2GPISEL_Pos (0UL)       /*!< Position of LDSW2GPISEL field.                                       */
#define LDSW_LDSW2GPISEL_LDSW2GPISEL_Msk (0x7UL << LDSW_LDSW2GPISEL_LDSW2GPISEL_Pos) /*!< Bit mask of LDSW2GPISEL field.       */
#define LDSW_LDSW2GPISEL_LDSW2GPISEL_NOTUSED1 (0)    /*!< no GPI selected                                                      */
#define LDSW_LDSW2GPISEL_LDSW2GPISEL_GPIO0 (1)       /*!< GPI_0 selected                                                       */
#define LDSW_LDSW2GPISEL_LDSW2GPISEL_GPIO1 (2)       /*!< GPI_1 selected                                                       */
#define LDSW_LDSW2GPISEL_LDSW2GPISEL_GPIO2 (3)       /*!< GPI_2 selected                                                       */
#define LDSW_LDSW2GPISEL_LDSW2GPISEL_GPIO3 (4)       /*!< GPI_3 selected                                                       */
#define LDSW_LDSW2GPISEL_LDSW2GPISEL_GPIO4 (5)       /*!< GPI_4 selected                                                       */
#define LDSW_LDSW2GPISEL_LDSW2GPISEL_NOTUSED2 (6)    /*!< no GPI selected                                                      */
#define LDSW_LDSW2GPISEL_LDSW2GPISEL_NOTUSED3 (7)    /*!< no GPI selected                                                      */

/* LDSW2GPIINV @Bit 3 : Invert the sense of the selected GPIO */
#define LDSW_LDSW2GPISEL_LDSW2GPIINV_Pos (3UL)       /*!< Position of LDSW2GPIINV field.                                       */
#define LDSW_LDSW2GPISEL_LDSW2GPIINV_Msk (0x1UL << LDSW_LDSW2GPISEL_LDSW2GPIINV_Pos) /*!< Bit mask of LDSW2GPIINV field.       */
#define LDSW_LDSW2GPISEL_LDSW2GPIINV_NORMAL (0)      /*!< not Inverted                                                         */
#define LDSW_LDSW2GPISEL_LDSW2GPIINV_INVERTED (1)    /*!< Inverted                                                             */


/* LDSW_LDSWCONFIG: Load Switch Configuration */

/* LDSW1SOFTSTARTDISABLE @Bit 0 : Load Switch1 Soft Start Disable */
#define LDSW_LDSWCONFIG_LDSW1SOFTSTARTDISABLE_Pos (0UL) /*!< Position of LDSW1SOFTSTARTDISABLE field.                          */
#define LDSW_LDSWCONFIG_LDSW1SOFTSTARTDISABLE_Msk (0x1UL << LDSW_LDSWCONFIG_LDSW1SOFTSTARTDISABLE_Pos) /*!< Bit mask of
                                                                            LDSW1SOFTSTARTDISABLE field.*/                        
#define LDSW_LDSWCONFIG_LDSW1SOFTSTARTDISABLE_NOEFFECT (0) /*!< no effect                                                      */
#define LDSW_LDSWCONFIG_LDSW1SOFTSTARTDISABLE_NOSOFTSTART (1) /*!< Soft Start Disabled                                         */

/* LDSW2SOFTSTARTDISABLE @Bit 1 : Load Switch2 Soft Start Disable */
#define LDSW_LDSWCONFIG_LDSW2SOFTSTARTDISABLE_Pos (1UL) /*!< Position of LDSW2SOFTSTARTDISABLE field.                          */
#define LDSW_LDSWCONFIG_LDSW2SOFTSTARTDISABLE_Msk (0x1UL << LDSW_LDSWCONFIG_LDSW2SOFTSTARTDISABLE_Pos) /*!< Bit mask of
                                                                            LDSW2SOFTSTARTDISABLE field.*/                        
#define LDSW_LDSWCONFIG_LDSW2SOFTSTARTDISABLE_NOEFFECT (0) /*!< no effect                                                      */
#define LDSW_LDSWCONFIG_LDSW2SOFTSTARTDISABLE_NOSOFTSTART (1) /*!< Soft Start Disabled                                         */

/* LDSW1SOFTSTARTSEL @Bits 2..3 : Select Soft Start level for Load Switch1 */
#define LDSW_LDSWCONFIG_LDSW1SOFTSTARTSEL_Pos (2UL)  /*!< Position of LDSW1SOFTSTARTSEL field.                                 */
#define LDSW_LDSWCONFIG_LDSW1SOFTSTARTSEL_Msk (0x3UL << LDSW_LDSWCONFIG_LDSW1SOFTSTARTSEL_Pos) /*!< Bit mask of
                                                                            LDSW1SOFTSTARTSEL field.*/                            
#define LDSW_LDSWCONFIG_LDSW1SOFTSTARTSEL_25mA (0)   /*!< 25mA                                                                 */
#define LDSW_LDSWCONFIG_LDSW1SOFTSTARTSEL_50mA (1)   /*!< 50mA                                                                 */
#define LDSW_LDSWCONFIG_LDSW1SOFTSTARTSEL_75mA (2)   /*!< 75mA                                                                 */
#define LDSW_LDSWCONFIG_LDSW1SOFTSTARTSEL_100mA (3)  /*!< 100mA                                                                */

/* LDSW2SOFTSTARTSEL @Bits 4..5 : Select Soft Start level for Load Switch1 */
#define LDSW_LDSWCONFIG_LDSW2SOFTSTARTSEL_Pos (4UL)  /*!< Position of LDSW2SOFTSTARTSEL field.                                 */
#define LDSW_LDSWCONFIG_LDSW2SOFTSTARTSEL_Msk (0x3UL << LDSW_LDSWCONFIG_LDSW2SOFTSTARTSEL_Pos) /*!< Bit mask of
                                                                            LDSW2SOFTSTARTSEL field.*/                            
#define LDSW_LDSWCONFIG_LDSW2SOFTSTARTSEL_25mA (0)   /*!< 25mA                                                                 */
#define LDSW_LDSWCONFIG_LDSW2SOFTSTARTSEL_50mA (1)   /*!< 50mA                                                                 */
#define LDSW_LDSWCONFIG_LDSW2SOFTSTARTSEL_75mA (2)   /*!< 75mA                                                                 */
#define LDSW_LDSWCONFIG_LDSW2SOFTSTARTSEL_100mA (3)  /*!< 100mA                                                                */

/* LDSW1ACTIVEDISCHARGE @Bit 6 : Load Switch1 Active discharge Enable */
#define LDSW_LDSWCONFIG_LDSW1ACTIVEDISCHARGE_Pos (6UL) /*!< Position of LDSW1ACTIVEDISCHARGE field.                            */
#define LDSW_LDSWCONFIG_LDSW1ACTIVEDISCHARGE_Msk (0x1UL << LDSW_LDSWCONFIG_LDSW1ACTIVEDISCHARGE_Pos) /*!< Bit mask of
                                                                            LDSW1ACTIVEDISCHARGE field.*/                         
#define LDSW_LDSWCONFIG_LDSW1ACTIVEDISCHARGE_NODISCHARGE (0) /*!< No Discharge                                                 */
#define LDSW_LDSWCONFIG_LDSW1ACTIVEDISCHARGE_ACTIVE (1) /*!< Active Discharge Enabled                                          */

/* LDSW2ACTIVEDISCHARGE @Bit 7 : Load Switch2 Active discharge Enable */
#define LDSW_LDSWCONFIG_LDSW2ACTIVEDISCHARGE_Pos (7UL) /*!< Position of LDSW2ACTIVEDISCHARGE field.                            */
#define LDSW_LDSWCONFIG_LDSW2ACTIVEDISCHARGE_Msk (0x1UL << LDSW_LDSWCONFIG_LDSW2ACTIVEDISCHARGE_Pos) /*!< Bit mask of
                                                                            LDSW2ACTIVEDISCHARGE field.*/                         
#define LDSW_LDSWCONFIG_LDSW2ACTIVEDISCHARGE_NODISCHARGE (0) /*!< No Discharge                                                 */
#define LDSW_LDSWCONFIG_LDSW2ACTIVEDISCHARGE_ACTIVE (1) /*!< Active Discharge Enabled                                          */


/* LDSW_LDSW1LDOSEL: Load Switch1 / LDO Select */

/* LDSW1LDOSEL @Bit 0 : Select LdswLdo0 to configure either as LDSW or LDO */
#define LDSW_LDSW1LDOSEL_LDSW1LDOSEL_Pos (0UL)       /*!< Position of LDSW1LDOSEL field.                                       */
#define LDSW_LDSW1LDOSEL_LDSW1LDOSEL_Msk (0x1UL << LDSW_LDSW1LDOSEL_LDSW1LDOSEL_Pos) /*!< Bit mask of LDSW1LDOSEL field.       */
#define LDSW_LDSW1LDOSEL_LDSW1LDOSEL_LDSW (0)        /*!< Load Switch                                                          */
#define LDSW_LDSW1LDOSEL_LDSW1LDOSEL_LDO (1)         /*!< LDO                                                                  */


/* LDSW_LDSW2LDOSEL: Load Switch2 / LDO Select */

/* LDSW2LDOSEL @Bit 0 : Select LdswLdo1 to configure either as LDSW or LDO */
#define LDSW_LDSW2LDOSEL_LDSW2LDOSEL_Pos (0UL)       /*!< Position of LDSW2LDOSEL field.                                       */
#define LDSW_LDSW2LDOSEL_LDSW2LDOSEL_Msk (0x1UL << LDSW_LDSW2LDOSEL_LDSW2LDOSEL_Pos) /*!< Bit mask of LDSW2LDOSEL field.       */
#define LDSW_LDSW2LDOSEL_LDSW2LDOSEL_LDSW (0)        /*!< Load Switch                                                          */
#define LDSW_LDSW2LDOSEL_LDSW2LDOSEL_LDO (1)         /*!< LDO                                                                  */


/* LDSW_LDSW1VOUTSEL: LDO1 programmable output voltage */

/* LDSW1VOUTSEL @Bits 0..4 : Low-dropout regulator 1 programmable output voltage */
#define LDSW_LDSW1VOUTSEL_LDSW1VOUTSEL_Pos (0UL)     /*!< Position of LDSW1VOUTSEL field.                                      */
#define LDSW_LDSW1VOUTSEL_LDSW1VOUTSEL_Msk (0x1FUL << LDSW_LDSW1VOUTSEL_LDSW1VOUTSEL_Pos) /*!< Bit mask of LDSW1VOUTSEL field. */
#define LDSW_LDSW1VOUTSEL_LDSW1VOUTSEL_1V (0)        /*!< 1V                                                                   */
#define LDSW_LDSW1VOUTSEL_LDSW1VOUTSEL_1V1 (1)       /*!< 1.1V                                                                 */
#define LDSW_LDSW1VOUTSEL_LDSW1VOUTSEL_1V2 (2)       /*!< 1.2V                                                                 */
#define LDSW_LDSW1VOUTSEL_LDSW1VOUTSEL_1V3 (3)       /*!< 1.3V                                                                 */
#define LDSW_LDSW1VOUTSEL_LDSW1VOUTSEL_1V4 (4)       /*!< 1.4V                                                                 */
#define LDSW_LDSW1VOUTSEL_LDSW1VOUTSEL_1V5 (5)       /*!< 1.5V                                                                 */
#define LDSW_LDSW1VOUTSEL_LDSW1VOUTSEL_1V6 (6)       /*!< 1.6V                                                                 */
#define LDSW_LDSW1VOUTSEL_LDSW1VOUTSEL_1V7 (7)       /*!< 1.7V                                                                 */
#define LDSW_LDSW1VOUTSEL_LDSW1VOUTSEL_1V8 (8)       /*!< 1.8V                                                                 */
#define LDSW_LDSW1VOUTSEL_LDSW1VOUTSEL_1V9 (9)       /*!< 1.9V                                                                 */
#define LDSW_LDSW1VOUTSEL_LDSW1VOUTSEL_2V (10)       /*!< 2V                                                                   */
#define LDSW_LDSW1VOUTSEL_LDSW1VOUTSEL_2V1 (11)      /*!< 2.1V                                                                 */
#define LDSW_LDSW1VOUTSEL_LDSW1VOUTSEL_2V2 (12)      /*!< 2.2V                                                                 */
#define LDSW_LDSW1VOUTSEL_LDSW1VOUTSEL_2V3 (13)      /*!< 2.3V                                                                 */
#define LDSW_LDSW1VOUTSEL_LDSW1VOUTSEL_2V4 (14)      /*!< 2.4V                                                                 */
#define LDSW_LDSW1VOUTSEL_LDSW1VOUTSEL_2V5 (15)      /*!< 2.5V                                                                 */
#define LDSW_LDSW1VOUTSEL_LDSW1VOUTSEL_2V6 (16)      /*!< 2.6V                                                                 */
#define LDSW_LDSW1VOUTSEL_LDSW1VOUTSEL_2V7 (17)      /*!< 2.7V                                                                 */
#define LDSW_LDSW1VOUTSEL_LDSW1VOUTSEL_2V8 (18)      /*!< 2.8V                                                                 */
#define LDSW_LDSW1VOUTSEL_LDSW1VOUTSEL_2V9 (19)      /*!< 2.9V                                                                 */
#define LDSW_LDSW1VOUTSEL_LDSW1VOUTSEL_3V (20)       /*!< 3V                                                                   */
#define LDSW_LDSW1VOUTSEL_LDSW1VOUTSEL_3V1 (21)      /*!< 3.1V                                                                 */
#define LDSW_LDSW1VOUTSEL_LDSW1VOUTSEL_3V2 (22)      /*!< 3.2V                                                                 */
#define LDSW_LDSW1VOUTSEL_LDSW1VOUTSEL_3V3 (23)      /*!< 3.3V                                                                 */


/* LDSW_LDSW2VOUTSEL: LDO2 programmable output voltage */

/* LDSW2VOUTSEL @Bits 0..4 : Low-dropout regulator 2 programmable output voltage */
#define LDSW_LDSW2VOUTSEL_LDSW2VOUTSEL_Pos (0UL)     /*!< Position of LDSW2VOUTSEL field.                                      */
#define LDSW_LDSW2VOUTSEL_LDSW2VOUTSEL_Msk (0x1FUL << LDSW_LDSW2VOUTSEL_LDSW2VOUTSEL_Pos) /*!< Bit mask of LDSW2VOUTSEL field. */
#define LDSW_LDSW2VOUTSEL_LDSW2VOUTSEL_1V (0)        /*!< 1V                                                                   */
#define LDSW_LDSW2VOUTSEL_LDSW2VOUTSEL_1V1 (1)       /*!< 1.1V                                                                 */
#define LDSW_LDSW2VOUTSEL_LDSW2VOUTSEL_1V2 (2)       /*!< 1.2V                                                                 */
#define LDSW_LDSW2VOUTSEL_LDSW2VOUTSEL_1V3 (3)       /*!< 1.3V                                                                 */
#define LDSW_LDSW2VOUTSEL_LDSW2VOUTSEL_1V4 (4)       /*!< 1.4V                                                                 */
#define LDSW_LDSW2VOUTSEL_LDSW2VOUTSEL_1V5 (5)       /*!< 1.5V                                                                 */
#define LDSW_LDSW2VOUTSEL_LDSW2VOUTSEL_1V6 (6)       /*!< 1.6V                                                                 */
#define LDSW_LDSW2VOUTSEL_LDSW2VOUTSEL_1V7 (7)       /*!< 1.7V                                                                 */
#define LDSW_LDSW2VOUTSEL_LDSW2VOUTSEL_1V8 (8)       /*!< 1.8V                                                                 */
#define LDSW_LDSW2VOUTSEL_LDSW2VOUTSEL_1V9 (9)       /*!< 1.9V                                                                 */
#define LDSW_LDSW2VOUTSEL_LDSW2VOUTSEL_2V (10)       /*!< 2V                                                                   */
#define LDSW_LDSW2VOUTSEL_LDSW2VOUTSEL_2V1 (11)      /*!< 2.1V                                                                 */
#define LDSW_LDSW2VOUTSEL_LDSW2VOUTSEL_2V2 (12)      /*!< 2.2V                                                                 */
#define LDSW_LDSW2VOUTSEL_LDSW2VOUTSEL_2V3 (13)      /*!< 2.3V                                                                 */
#define LDSW_LDSW2VOUTSEL_LDSW2VOUTSEL_2V4 (14)      /*!< 2.4V                                                                 */
#define LDSW_LDSW2VOUTSEL_LDSW2VOUTSEL_2V5 (15)      /*!< 2.5V                                                                 */
#define LDSW_LDSW2VOUTSEL_LDSW2VOUTSEL_2V6 (16)      /*!< 2.6V                                                                 */
#define LDSW_LDSW2VOUTSEL_LDSW2VOUTSEL_2V7 (17)      /*!< 2.7V                                                                 */
#define LDSW_LDSW2VOUTSEL_LDSW2VOUTSEL_2V8 (18)      /*!< 2.8V                                                                 */
#define LDSW_LDSW2VOUTSEL_LDSW2VOUTSEL_2V9 (19)      /*!< 2.9V                                                                 */
#define LDSW_LDSW2VOUTSEL_LDSW2VOUTSEL_3V (20)       /*!< 3V                                                                   */
#define LDSW_LDSW2VOUTSEL_LDSW2VOUTSEL_3V1 (21)      /*!< 3.1V                                                                 */
#define LDSW_LDSW2VOUTSEL_LDSW2VOUTSEL_3V2 (22)      /*!< 3.2V                                                                 */
#define LDSW_LDSW2VOUTSEL_LDSW2VOUTSEL_3V3 (23)      /*!< 3.3V                                                                 */



/* =========================================================================================================================== */
/* ================                                            POF                                            ================ */
/* =========================================================================================================================== */

/* ======================================================= Struct POF ======================================================== */
/**
  * @brief Neutrino POF registers
  */
typedef struct {                                     /*!< POF Structure                                                        */
  __IOM uint8_t   POFCONFIG;                         /*!< (@ 0x00000000) Power Failure Detection block configuration           */
}NPM_POF_Type;                                       /*!< Size = 1 (0x001)                                                     */

/* POF_POFCONFIG: Power Failure Detection block configuration */

/* POFENA @Bit 0 : Enable Power Failure feature */
#define POF_POFCONFIG_POFENA_Pos (0UL)               /*!< Position of POFENA field.                                            */
#define POF_POFCONFIG_POFENA_Msk (0x1UL << POF_POFCONFIG_POFENA_Pos) /*!< Bit mask of POFENA field.                            */
#define POF_POFCONFIG_POFENA_OFF (0)                 /*!< Off                                                                  */
#define POF_POFCONFIG_POFENA_ENABLED (1)             /*!< WarningEnabled                                                       */

/* POFWARNPOLARITY @Bit 1 : Power Failure Warning polarity */
#define POF_POFCONFIG_POFWARNPOLARITY_Pos (1UL)      /*!< Position of POFWARNPOLARITY field.                                   */
#define POF_POFCONFIG_POFWARNPOLARITY_Msk (0x1UL << POF_POFCONFIG_POFWARNPOLARITY_Pos) /*!< Bit mask of POFWARNPOLARITY field. */
#define POF_POFCONFIG_POFWARNPOLARITY_LOACTIVE (0)   /*!< LoActive                                                             */
#define POF_POFCONFIG_POFWARNPOLARITY_HIACTIVE (1)   /*!< HiActive                                                             */

/* POFVSYSTHRESHSEL @Bits 2..5 : Vsys Comparator Threshold Select */
#define POF_POFCONFIG_POFVSYSTHRESHSEL_Pos (2UL)     /*!< Position of POFVSYSTHRESHSEL field.                                  */
#define POF_POFCONFIG_POFVSYSTHRESHSEL_Msk (0xFUL << POF_POFCONFIG_POFVSYSTHRESHSEL_Pos) /*!< Bit mask of POFVSYSTHRESHSEL
                                                                            field.*/                                              
#define POF_POFCONFIG_POFVSYSTHRESHSEL_2V8 (0)       /*!< 2.8V                                                                 */
#define POF_POFCONFIG_POFVSYSTHRESHSEL_2V6 (1)       /*!< 2.6V                                                                 */
#define POF_POFCONFIG_POFVSYSTHRESHSEL_2V7 (2)       /*!< 2.7V                                                                 */
#define POF_POFCONFIG_POFVSYSTHRESHSEL_2V9 (3)       /*!< 2.9V                                                                 */
#define POF_POFCONFIG_POFVSYSTHRESHSEL_3V0 (4)       /*!< 3.0V                                                                 */
#define POF_POFCONFIG_POFVSYSTHRESHSEL_3V1 (5)       /*!< 3.1V                                                                 */
#define POF_POFCONFIG_POFVSYSTHRESHSEL_3V2 (6)       /*!< 3.2V                                                                 */
#define POF_POFCONFIG_POFVSYSTHRESHSEL_3V3 (7)       /*!< 3.3V                                                                 */
#define POF_POFCONFIG_POFVSYSTHRESHSEL_3V4 (8)       /*!< 3.4V                                                                 */
#define POF_POFCONFIG_POFVSYSTHRESHSEL_3V5 (9)       /*!< 3.5V                                                                 */
#define POF_POFCONFIG_POFVSYSTHRESHSEL_unused10 (10) /*!< set to 2.8V                                                          */
#define POF_POFCONFIG_POFVSYSTHRESHSEL_unused11 (11) /*!< set to 2.8V                                                          */
#define POF_POFCONFIG_POFVSYSTHRESHSEL_unused12 (12) /*!< set to 2.8V                                                          */
#define POF_POFCONFIG_POFVSYSTHRESHSEL_unused13 (13) /*!< set to 2.8V                                                          */
#define POF_POFCONFIG_POFVSYSTHRESHSEL_unused14 (14) /*!< set to 2.8V                                                          */
#define POF_POFCONFIG_POFVSYSTHRESHSEL_unused15 (15) /*!< set to 2.8V                                                          */



/* =========================================================================================================================== */
/* ================                                          LEDDRV                                          ================ */
/* =========================================================================================================================== */

/* ====================================================== Struct LEDDRV ====================================================== */
/**
  * @brief Neutrino LEDDRV registers
  */
typedef struct {                                     /*!< LEDDRV Structure                                                     */
  __IOM uint8_t   LEDDRV0MODESEL;                    /*!< (@ 0x00000000) Select for LED_0 mode                                 */
  __IOM uint8_t   LEDDRV1MODESEL;                    /*!< (@ 0x00000001) Select for LED_1 mode                                 */
  __IOM uint8_t   LEDDRV2MODESEL;                    /*!< (@ 0x00000002) Select for LED_2 mode                                 */
  __OM  uint8_t   LEDDRV0SET;                        /*!< (@ 0x00000003) Set LED_0 to be On                                    */
  __OM  uint8_t   LEDDRV0CLR;                        /*!< (@ 0x00000004) Clear LED_0 to be Off                                 */
  __OM  uint8_t   LEDDRV1SET;                        /*!< (@ 0x00000005) Set LED_1 to be On                                    */
  __OM  uint8_t   LEDDRV1CLR;                        /*!< (@ 0x00000006) Clear LED_1 to be Off                                 */
  __OM  uint8_t   LEDDRV2SET;                        /*!< (@ 0x00000007) Set LED_2 to be On                                    */
  __OM  uint8_t   LEDDRV2CLR;                        /*!< (@ 0x00000008) Clear LED_2 to be Off                                 */
}NPM_LEDDRV_Type;                                    /*!< Size = 9 (0x009)                                                     */

/* LEDDRV_LEDDRV0MODESEL: Select for LED_0 mode */

/* LEDDRV0MODESEL @Bits 0..1 : Select for LED_0 mode */
#define LEDDRV_LEDDRV0MODESEL_LEDDRV0MODESEL_Pos (0UL) /*!< Position of LEDDRV0MODESEL field.                                  */
#define LEDDRV_LEDDRV0MODESEL_LEDDRV0MODESEL_Msk (0x3UL << LEDDRV_LEDDRV0MODESEL_LEDDRV0MODESEL_Pos) /*!< Bit mask of
                                                                            LEDDRV0MODESEL field.*/                               
#define LEDDRV_LEDDRV0MODESEL_LEDDRV0MODESEL_ERROR (0) /*!< Error condition from Charger                                       */
#define LEDDRV_LEDDRV0MODESEL_LEDDRV0MODESEL_CHARGING (1) /*!< Charging indicator (On during charging)                         */
#define LEDDRV_LEDDRV0MODESEL_LEDDRV0MODESEL_HOST (2) /*!< Driven from register LEDDRV_0_SET/CLR                               */
#define LEDDRV_LEDDRV0MODESEL_LEDDRV0MODESEL_NOTUSED (3) /*!< Not used                                                         */


/* LEDDRV_LEDDRV1MODESEL: Select for LED_1 mode */

/* LEDDRV1MODESEL @Bits 0..1 : Select for LED_1 mode */
#define LEDDRV_LEDDRV1MODESEL_LEDDRV1MODESEL_Pos (0UL) /*!< Position of LEDDRV1MODESEL field.                                  */
#define LEDDRV_LEDDRV1MODESEL_LEDDRV1MODESEL_Msk (0x3UL << LEDDRV_LEDDRV1MODESEL_LEDDRV1MODESEL_Pos) /*!< Bit mask of
                                                                            LEDDRV1MODESEL field.*/                               
#define LEDDRV_LEDDRV1MODESEL_LEDDRV1MODESEL_ERROR (0) /*!< Error condition from Charger                                       */
#define LEDDRV_LEDDRV1MODESEL_LEDDRV1MODESEL_CHARGING (1) /*!< Charging indicator (On during charging)                         */
#define LEDDRV_LEDDRV1MODESEL_LEDDRV1MODESEL_HOST (2) /*!< Driven from register LEDDRV_1_SET/CLR                               */
#define LEDDRV_LEDDRV1MODESEL_LEDDRV1MODESEL_NOTUSED (3) /*!< Not used                                                         */


/* LEDDRV_LEDDRV2MODESEL: Select for LED_2 mode */

/* LEDDRV2MODESEL @Bits 0..1 : Select for LED_2 mode */
#define LEDDRV_LEDDRV2MODESEL_LEDDRV2MODESEL_Pos (0UL) /*!< Position of LEDDRV2MODESEL field.                                  */
#define LEDDRV_LEDDRV2MODESEL_LEDDRV2MODESEL_Msk (0x3UL << LEDDRV_LEDDRV2MODESEL_LEDDRV2MODESEL_Pos) /*!< Bit mask of
                                                                            LEDDRV2MODESEL field.*/                               
#define LEDDRV_LEDDRV2MODESEL_LEDDRV2MODESEL_ERROR (0) /*!< Error condition from Charger                                       */
#define LEDDRV_LEDDRV2MODESEL_LEDDRV2MODESEL_CHARGING (1) /*!< Charging indicator (On during charging)                         */
#define LEDDRV_LEDDRV2MODESEL_LEDDRV2MODESEL_HOST (2) /*!< Driven from register LEDDRV_2_SET/CLR                               */
#define LEDDRV_LEDDRV2MODESEL_LEDDRV2MODESEL_NOTUSED (3) /*!< Not used                                                         */


/* LEDDRV_LEDDRV0SET: Set LED_0 to be On */

/* LEDDRV0ON @Bit 0 : Set LED_0 to be On */
#define LEDDRV_LEDDRV0SET_LEDDRV0ON_Pos (0UL)        /*!< Position of LEDDRV0ON field.                                         */
#define LEDDRV_LEDDRV0SET_LEDDRV0ON_Msk (0x1UL << LEDDRV_LEDDRV0SET_LEDDRV0ON_Pos) /*!< Bit mask of LEDDRV0ON field.           */
#define LEDDRV_LEDDRV0SET_LEDDRV0ON_NOEFFECT (0)     /*!< no effect                                                            */
#define LEDDRV_LEDDRV0SET_LEDDRV0ON_SET (1)          /*!< Used with leddrvModeSel                                              */


/* LEDDRV_LEDDRV0CLR: Clear LED_0 to be Off */

/* LEDDRV0OFF @Bit 0 : Set LED_0 to be Off */
#define LEDDRV_LEDDRV0CLR_LEDDRV0OFF_Pos (0UL)       /*!< Position of LEDDRV0OFF field.                                        */
#define LEDDRV_LEDDRV0CLR_LEDDRV0OFF_Msk (0x1UL << LEDDRV_LEDDRV0CLR_LEDDRV0OFF_Pos) /*!< Bit mask of LEDDRV0OFF field.        */
#define LEDDRV_LEDDRV0CLR_LEDDRV0OFF_NOEFFECT (0)    /*!< no effect                                                            */
#define LEDDRV_LEDDRV0CLR_LEDDRV0OFF_CLR (1)         /*!< Used with leddrvModeSel                                              */


/* LEDDRV_LEDDRV1SET: Set LED_1 to be On */

/* LEDDRV1ON @Bit 0 : Set LED_1 to be On */
#define LEDDRV_LEDDRV1SET_LEDDRV1ON_Pos (0UL)        /*!< Position of LEDDRV1ON field.                                         */
#define LEDDRV_LEDDRV1SET_LEDDRV1ON_Msk (0x1UL << LEDDRV_LEDDRV1SET_LEDDRV1ON_Pos) /*!< Bit mask of LEDDRV1ON field.           */
#define LEDDRV_LEDDRV1SET_LEDDRV1ON_NOEFFECT (0)     /*!< no effect                                                            */
#define LEDDRV_LEDDRV1SET_LEDDRV1ON_SET (1)          /*!< Used with leddrvModeSel                                              */


/* LEDDRV_LEDDRV1CLR: Clear LED_1 to be Off */

/* LEDDRV1OFF @Bit 0 : Set LED_1 to be Off */
#define LEDDRV_LEDDRV1CLR_LEDDRV1OFF_Pos (0UL)       /*!< Position of LEDDRV1OFF field.                                        */
#define LEDDRV_LEDDRV1CLR_LEDDRV1OFF_Msk (0x1UL << LEDDRV_LEDDRV1CLR_LEDDRV1OFF_Pos) /*!< Bit mask of LEDDRV1OFF field.        */
#define LEDDRV_LEDDRV1CLR_LEDDRV1OFF_NOEFFECT (0)    /*!< no effect                                                            */
#define LEDDRV_LEDDRV1CLR_LEDDRV1OFF_CLR (1)         /*!< Used with leddrvModeSel                                              */


/* LEDDRV_LEDDRV2SET: Set LED_2 to be On */

/* LEDDRV2ON @Bit 0 : Set LED_2 to be On */
#define LEDDRV_LEDDRV2SET_LEDDRV2ON_Pos (0UL)        /*!< Position of LEDDRV2ON field.                                         */
#define LEDDRV_LEDDRV2SET_LEDDRV2ON_Msk (0x1UL << LEDDRV_LEDDRV2SET_LEDDRV2ON_Pos) /*!< Bit mask of LEDDRV2ON field.           */
#define LEDDRV_LEDDRV2SET_LEDDRV2ON_NOEFFECT (0)     /*!< no effect                                                            */
#define LEDDRV_LEDDRV2SET_LEDDRV2ON_SET (1)          /*!< Used with leddrvModeSel                                              */


/* LEDDRV_LEDDRV2CLR: Clear LED_2 to be Off */

/* LEDDRV2OFF @Bit 0 : Set LED_2 to be Off */
#define LEDDRV_LEDDRV2CLR_LEDDRV2OFF_Pos (0UL)       /*!< Position of LEDDRV2OFF field.                                        */
#define LEDDRV_LEDDRV2CLR_LEDDRV2OFF_Msk (0x1UL << LEDDRV_LEDDRV2CLR_LEDDRV2OFF_Pos) /*!< Bit mask of LEDDRV2OFF field.        */
#define LEDDRV_LEDDRV2CLR_LEDDRV2OFF_NOEFFECT (0)    /*!< no effect                                                            */
#define LEDDRV_LEDDRV2CLR_LEDDRV2OFF_CLR (1)         /*!< Used with leddrvModeSel                                              */



/* =========================================================================================================================== */
/* ================                                          SHPHLD                                          ================ */
/* =========================================================================================================================== */

/* ====================================================== Struct SHPHLD ====================================================== */
/**
  * @brief Neutrino SHPHLD registers
  */
typedef struct {                                     /*!< SHPHLD Structure                                                     */
  __OM  uint8_t   TASKENTERHIBERNATE;                /*!< (@ 0x00000000) Task Enter Hibernate                                  */
  __OM  uint8_t   TASKSHPHLDCFGSTROBE;               /*!< (@ 0x00000001) Task Ship Hold config                                 */
  __OM  uint8_t   TASKENTERSHIPMODE;                 /*!< (@ 0x00000002) Task enter ShipMode                                   */
  __OM  uint8_t   TASKRESETCFG;                      /*!< (@ 0x00000003) Request reset config                                  */
  __IOM uint8_t   SHPHLDCONFIG;                      /*!< (@ 0x00000004) Ship Hold button press timer config                   */
  __IM  uint8_t   SHPHLDSTATUS;                      /*!< (@ 0x00000005) Status of the SHPHLD pin                              */
  __IOM uint8_t   LPRESETCONFIG;                     /*!< (@ 0x00000006) Long press reset config register                      */
}NPM_SHPHLD_Type;                                    /*!< Size = 7 (0x007)                                                     */

/* SHPHLD_TASKENTERHIBERNATE: Task Enter Hibernate */

/* TASKENTERHIBERNATE @Bit 0 : Enter Hibernate (Shipmode with Wakeup Timer) */
#define SHPHLD_TASKENTERHIBERNATE_TASKENTERHIBERNATE_Pos (0UL) /*!< Position of TASKENTERHIBERNATE field.                      */
#define SHPHLD_TASKENTERHIBERNATE_TASKENTERHIBERNATE_Msk (0x1UL << SHPHLD_TASKENTERHIBERNATE_TASKENTERHIBERNATE_Pos) /*!< Bit
                                                                            mask of TASKENTERHIBERNATE field.*/                   
#define SHPHLD_TASKENTERHIBERNATE_TASKENTERHIBERNATE_NOEFFECT (0) /*!< no effect                                               */
#define SHPHLD_TASKENTERHIBERNATE_TASKENTERHIBERNATE_TRIGGER (1) /*!< trigger task                                             */


/* SHPHLD_TASKSHPHLDCFGSTROBE: Task Ship Hold config */

/* TASKSHPHLDCONFIGSTROBE @Bit 0 : Load the SHPHLD Config */
#define SHPHLD_TASKSHPHLDCFGSTROBE_TASKSHPHLDCONFIGSTROBE_Pos (0UL) /*!< Position of TASKSHPHLDCONFIGSTROBE field.             */
#define SHPHLD_TASKSHPHLDCFGSTROBE_TASKSHPHLDCONFIGSTROBE_Msk (0x1UL << SHPHLD_TASKSHPHLDCFGSTROBE_TASKSHPHLDCONFIGSTROBE_Pos)
                                                                            /*!< Bit mask of TASKSHPHLDCONFIGSTROBE field.*/      
#define SHPHLD_TASKSHPHLDCFGSTROBE_TASKSHPHLDCONFIGSTROBE_NOEFFECT (0) /*!< no effect                                          */
#define SHPHLD_TASKSHPHLDCFGSTROBE_TASKSHPHLDCONFIGSTROBE_TRIGGER (1) /*!< strobe config                                       */


/* SHPHLD_TASKENTERSHIPMODE: Task enter ShipMode */

/* TASKENTERSHIPMODE @Bit 0 : Enter Shipmode (without Wakeup timer) */
#define SHPHLD_TASKENTERSHIPMODE_TASKENTERSHIPMODE_Pos (0UL) /*!< Position of TASKENTERSHIPMODE field.                         */
#define SHPHLD_TASKENTERSHIPMODE_TASKENTERSHIPMODE_Msk (0x1UL << SHPHLD_TASKENTERSHIPMODE_TASKENTERSHIPMODE_Pos) /*!< Bit mask
                                                                            of TASKENTERSHIPMODE field.*/                         
#define SHPHLD_TASKENTERSHIPMODE_TASKENTERSHIPMODE_NOEFFECT (0) /*!< no effect                                                 */
#define SHPHLD_TASKENTERSHIPMODE_TASKENTERSHIPMODE_TRIGGER (1) /*!< trigger task                                               */


/* SHPHLD_TASKRESETCFG: Request reset config */

/* TASKSHPHLDRSTCONFIG @Bit 0 : Use to reset config settings */
#define SHPHLD_TASKRESETCFG_TASKSHPHLDRSTCONFIG_Pos (0UL) /*!< Position of TASKSHPHLDRSTCONFIG field.                          */
#define SHPHLD_TASKRESETCFG_TASKSHPHLDRSTCONFIG_Msk (0x1UL << SHPHLD_TASKRESETCFG_TASKSHPHLDRSTCONFIG_Pos) /*!< Bit mask of
                                                                            TASKSHPHLDRSTCONFIG field.*/                          
#define SHPHLD_TASKRESETCFG_TASKSHPHLDRSTCONFIG_NOEFFECT (0) /*!< no effect                                                    */
#define SHPHLD_TASKRESETCFG_TASKSHPHLDRSTCONFIG_TRIGGER (1) /*!< reset                                                         */


/* SHPHLD_SHPHLDCONFIG: Ship Hold button press timer config */

/* SHPHLDTIM @Bits 0..2 : Ship-Hold press timer */
#define SHPHLD_SHPHLDCONFIG_SHPHLDTIM_Pos (0UL)      /*!< Position of SHPHLDTIM field.                                         */
#define SHPHLD_SHPHLDCONFIG_SHPHLDTIM_Msk (0x7UL << SHPHLD_SHPHLDCONFIG_SHPHLDTIM_Pos) /*!< Bit mask of SHPHLDTIM field.       */
#define SHPHLD_SHPHLDCONFIG_SHPHLDTIM_16ms (0)       /*!< 16ms                                                                 */
#define SHPHLD_SHPHLDCONFIG_SHPHLDTIM_32ms (1)       /*!< 32ms                                                                 */
#define SHPHLD_SHPHLDCONFIG_SHPHLDTIM_64ms (2)       /*!< 64ms                                                                 */
#define SHPHLD_SHPHLDCONFIG_SHPHLDTIM_96ms (3)       /*!< 96ms (default)                                                       */
#define SHPHLD_SHPHLDCONFIG_SHPHLDTIM_304ms (4)      /*!< 304ms                                                                */
#define SHPHLD_SHPHLDCONFIG_SHPHLDTIM_608ms (5)      /*!< 608ms                                                                */
#define SHPHLD_SHPHLDCONFIG_SHPHLDTIM_1008ms (6)     /*!< 1008ms                                                               */
#define SHPHLD_SHPHLDCONFIG_SHPHLDTIM_3008ms (7)     /*!< 3008ms                                                               */

/* SHPHLDPOLARITY @Bit 3 : Polarity of shphld */
#define SHPHLD_SHPHLDCONFIG_SHPHLDPOLARITY_Pos (3UL) /*!< Position of SHPHLDPOLARITY field.                                    */
#define SHPHLD_SHPHLDCONFIG_SHPHLDPOLARITY_Msk (0x1UL << SHPHLD_SHPHLDCONFIG_SHPHLDPOLARITY_Pos) /*!< Bit mask of SHPHLDPOLARITY
                                                                            field.*/                                              
#define SHPHLD_SHPHLDCONFIG_SHPHLDPOLARITY_NOEFFECT (0) /*!< no effect                                                         */
#define SHPHLD_SHPHLDCONFIG_SHPHLDPOLARITY_INVERT (1) /*!< shphld inverted                                                     */


/* SHPHLD_SHPHLDSTATUS: Status of the SHPHLD pin */

/* SHPHLDPINSTATUS @Bit 0 : Ship Hold pin Status */
#define SHPHLD_SHPHLDSTATUS_SHPHLDPINSTATUS_Pos (0UL) /*!< Position of SHPHLDPINSTATUS field.                                  */
#define SHPHLD_SHPHLDSTATUS_SHPHLDPINSTATUS_Msk (0x1UL << SHPHLD_SHPHLDSTATUS_SHPHLDPINSTATUS_Pos) /*!< Bit mask of
                                                                            SHPHLDPINSTATUS field.*/                              
#define SHPHLD_SHPHLDSTATUS_SHPHLDPINSTATUS_LOW (0)  /*!< Low                                                                  */
#define SHPHLD_SHPHLDSTATUS_SHPHLDPINSTATUS_HIGH (1) /*!< High                                                                 */


/* SHPHLD_LPRESETCONFIG: Long press reset config register */

/* LONGTIMRESETDIS @Bit 0 : Long press 10s timer enable */
#define SHPHLD_LPRESETCONFIG_LONGTIMRESETDIS_Pos (0UL) /*!< Position of LONGTIMRESETDIS field.                                 */
#define SHPHLD_LPRESETCONFIG_LONGTIMRESETDIS_Msk (0x1UL << SHPHLD_LPRESETCONFIG_LONGTIMRESETDIS_Pos) /*!< Bit mask of
                                                                            LONGTIMRESETDIS field.*/                              
#define SHPHLD_LPRESETCONFIG_LONGTIMRESETDIS_ENABLED (0) /*!< LongPress Enabled                                                */
#define SHPHLD_LPRESETCONFIG_LONGTIMRESETDIS_DISABLED (1) /*!< Disabled                                                        */

/* LONGTIMTWOBUTTONSEL @Bit 1 : Select one (default) or two buttons to perform longpress reset */
#define SHPHLD_LPRESETCONFIG_LONGTIMTWOBUTTONSEL_Pos (1UL) /*!< Position of LONGTIMTWOBUTTONSEL field.                         */
#define SHPHLD_LPRESETCONFIG_LONGTIMTWOBUTTONSEL_Msk (0x1UL << SHPHLD_LPRESETCONFIG_LONGTIMTWOBUTTONSEL_Pos) /*!< Bit mask of
                                                                            LONGTIMTWOBUTTONSEL field.*/                          
#define SHPHLD_LPRESETCONFIG_LONGTIMTWOBUTTONSEL_SHPHLD (0) /*!< SHPHLD                                                        */
#define SHPHLD_LPRESETCONFIG_LONGTIMTWOBUTTONSEL_SHPHLDGPIO0 (1) /*!< SHPHLD GPIO0                                             */



/* =========================================================================================================================== */
/* ================                                           FICR                                           ================ */
/* =========================================================================================================================== */

/* ======================================================= Struct FICR ======================================================= */
/**
  * @brief FICR register map
  */
typedef struct {                                     /*!< FICR Structure                                                       */
  __IM  uint8_t   RESERVED[61];
  __IM  uint8_t   VBUSINILIM0OTP;                    /*!< (@ 0x0000003D) Select Input Current limit for VBUS                   */
}NPM_FICR_Type;                                      /*!< Size = 62 (0x03E)                                                    */

/* FICR_VBUSINILIM0OTP: Select Input Current limit for VBUS */

/* VBUSINILIM0OTP @Bits 0..3 : Input current limit for VBUS selected by Host */
#define FICR_VBUSINILIM0OTP_VBUSINILIM0OTP_Pos (0UL) /*!< Position of VBUSINILIM0OTP field.                                    */
#define FICR_VBUSINILIM0OTP_VBUSINILIM0OTP_Msk (0xFUL << FICR_VBUSINILIM0OTP_VBUSINILIM0OTP_Pos) /*!< Bit mask of VBUSINILIM0OTP
                                                                            field.*/                                              
#define FICR_VBUSINILIM0OTP_VBUSINILIM0OTP_500MA (0) /*!< 500mA                                                                */
#define FICR_VBUSINILIM0OTP_VBUSINILIM0OTP_100MA (1) /*!< 100mA                                                                */
#define FICR_VBUSINILIM0OTP_VBUSINILIM0OTP_NOTUSED2 (2) /*!< 100mA (Not used)                                                  */
#define FICR_VBUSINILIM0OTP_VBUSINILIM0OTP_NOTUSED3 (3) /*!< 100mA (Not used)                                                  */
#define FICR_VBUSINILIM0OTP_VBUSINILIM0OTP_NOTUSED4 (4) /*!< 100mA (Not used)                                                  */
#define FICR_VBUSINILIM0OTP_VBUSINILIM0OTP_DEFAULT500MA (5) /*!< 500mA (default)                                               */
#define FICR_VBUSINILIM0OTP_VBUSINILIM0OTP_600MA (6) /*!< 600mA                                                                */
#define FICR_VBUSINILIM0OTP_VBUSINILIM0OTP_700MA (7) /*!< 700mA                                                                */
#define FICR_VBUSINILIM0OTP_VBUSINILIM0OTP_800MA (8) /*!< 800mA                                                                */
#define FICR_VBUSINILIM0OTP_VBUSINILIM0OTP_900MA (9) /*!< 900mA                                                                */
#define FICR_VBUSINILIM0OTP_VBUSINILIM0OTP_1000MA (10) /*!< 1000mA                                                             */
#define FICR_VBUSINILIM0OTP_VBUSINILIM0OTP_1100MA (11) /*!< 1100mA                                                             */
#define FICR_VBUSINILIM0OTP_VBUSINILIM0OTP_1200MA (12) /*!< 1200mA                                                             */
#define FICR_VBUSINILIM0OTP_VBUSINILIM0OTP_1300MA (13) /*!< 1300mA                                                             */
#define FICR_VBUSINILIM0OTP_VBUSINILIM0OTP_1400MA (14) /*!< 1400mA                                                             */
#define FICR_VBUSINILIM0OTP_VBUSINILIM0OTP_1500MA (15) /*!< 1500mA                                                             */



/* =========================================================================================================================== */
/* ================                                          ERRLOG                                          ================ */
/* =========================================================================================================================== */

/* ====================================================== Struct ERRLOG ====================================================== */
/**
  * @brief Neutrino ERRLOG registers
  */
typedef struct {                                     /*!< ERRLOG Structure                                                     */
  __OM  uint8_t   TASKCLRERRLOG;                     /*!< (@ 0x00000000) task to clear the Errlog registers                    */
  __IOM uint8_t   SCRATCH0;                          /*!< (@ 0x00000001) Scratch register 0                                    */
  __IOM uint8_t   SCRATCH1;                          /*!< (@ 0x00000002) Scratch register 1                                    */
  __IM  uint8_t   RSTCAUSE;                          /*!< (@ 0x00000003) Error log for internal reset causes. Cleared
                                                                         withTASK_CLR_ERRLOG*/                                    
  __IM  uint8_t   CHARGERERRREASON;                  /*!< (@ 0x00000004) Error log for slowDomain. Cleared with TASK_CLR_ERRLOG*/
  __IM  uint8_t   CHARGERERRSENSOR;                  /*!< (@ 0x00000005) Bcharger Fsm sensor error. Cleared with
                                                                         TASK_CLR_ERRLOG*/                                        
}NPM_ERRLOG_Type;                                    /*!< Size = 6 (0x006)                                                     */

/* ERRLOG_TASKCLRERRLOG: task to clear the Errlog registers */

/* TASKCLRERRLOG @Bit 0 : Clear Errlog */
#define ERRLOG_TASKCLRERRLOG_TASKCLRERRLOG_Pos (0UL) /*!< Position of TASKCLRERRLOG field.                                     */
#define ERRLOG_TASKCLRERRLOG_TASKCLRERRLOG_Msk (0x1UL << ERRLOG_TASKCLRERRLOG_TASKCLRERRLOG_Pos) /*!< Bit mask of TASKCLRERRLOG
                                                                            field.*/                                              


/* ERRLOG_SCRATCH0: Scratch register 0 */

/* BOOTTIMEREN @Bit 0 : Enable Boot Monitor Timer, only cleared by POR */
#define ERRLOG_SCRATCH0_BOOTTIMEREN_Pos (0UL)        /*!< Position of BOOTTIMEREN field.                                       */
#define ERRLOG_SCRATCH0_BOOTTIMEREN_Msk (0x1UL << ERRLOG_SCRATCH0_BOOTTIMEREN_Pos) /*!< Bit mask of BOOTTIMEREN field.         */
#define ERRLOG_SCRATCH0_BOOTTIMEREN_NOBOOTMON (0)    /*!< bootMonitor disable                                                  */
#define ERRLOG_SCRATCH0_BOOTTIMEREN_BOOTMON (1)      /*!< bootMonitor enable                                                   */

/* SCRATCH0 @Bits 1..7 : scratch register, only cleared by POR */
#define ERRLOG_SCRATCH0_SCRATCH0_Pos (1UL)           /*!< Position of SCRATCH0 field.                                          */
#define ERRLOG_SCRATCH0_SCRATCH0_Msk (0x7FUL << ERRLOG_SCRATCH0_SCRATCH0_Pos) /*!< Bit mask of SCRATCH0 field.                 */


/* ERRLOG_SCRATCH1: Scratch register 1 */

/* SCRATCH1 @Bits 0..7 : scratch register, only cleared by POR */
#define ERRLOG_SCRATCH1_SCRATCH1_Pos (0UL)           /*!< Position of SCRATCH1 field.                                          */
#define ERRLOG_SCRATCH1_SCRATCH1_Msk (0xFFUL << ERRLOG_SCRATCH1_SCRATCH1_Pos) /*!< Bit mask of SCRATCH1 field.                 */


/* ERRLOG_RSTCAUSE: Error log for internal reset causes. Cleared withTASK_CLR_ERRLOG */

/* SHIPMODEEXIT @Bit 0 : internal reset caused by shipmode exit */
#define ERRLOG_RSTCAUSE_SHIPMODEEXIT_Pos (0UL)       /*!< Position of SHIPMODEEXIT field.                                      */
#define ERRLOG_RSTCAUSE_SHIPMODEEXIT_Msk (0x1UL << ERRLOG_RSTCAUSE_SHIPMODEEXIT_Pos) /*!< Bit mask of SHIPMODEEXIT field.      */
#define ERRLOG_RSTCAUSE_SHIPMODEEXIT_NORST (0)       /*!< no shipmode reset                                                    */
#define ERRLOG_RSTCAUSE_SHIPMODEEXIT_RST (1)         /*!< reset activated by shipmode exit                                     */

/* BOOTMONITORTIMEOUT @Bit 1 : internal reset caused by boot monitor timeout */
#define ERRLOG_RSTCAUSE_BOOTMONITORTIMEOUT_Pos (1UL) /*!< Position of BOOTMONITORTIMEOUT field.                                */
#define ERRLOG_RSTCAUSE_BOOTMONITORTIMEOUT_Msk (0x1UL << ERRLOG_RSTCAUSE_BOOTMONITORTIMEOUT_Pos) /*!< Bit mask of
                                                                            BOOTMONITORTIMEOUT field.*/                           
#define ERRLOG_RSTCAUSE_BOOTMONITORTIMEOUT_NORST (0) /*!< no bootMonitor reset                                                 */
#define ERRLOG_RSTCAUSE_BOOTMONITORTIMEOUT_RST (1)   /*!< reset activated by bootMonitor                                       */

/* WATCHDOGTIMEOUT @Bit 2 : internal reset caused by watchdog timeout */
#define ERRLOG_RSTCAUSE_WATCHDOGTIMEOUT_Pos (2UL)    /*!< Position of WATCHDOGTIMEOUT field.                                   */
#define ERRLOG_RSTCAUSE_WATCHDOGTIMEOUT_Msk (0x1UL << ERRLOG_RSTCAUSE_WATCHDOGTIMEOUT_Pos) /*!< Bit mask of WATCHDOGTIMEOUT
                                                                            field.*/                                              
#define ERRLOG_RSTCAUSE_WATCHDOGTIMEOUT_NORST (0)    /*!< no watchdog reset                                                    */
#define ERRLOG_RSTCAUSE_WATCHDOGTIMEOUT_RST (1)      /*!< reset activated by watchdog                                          */

/* LONGPRESSTIMEOUT @Bit 3 : internal reset caused by shphld long press */
#define ERRLOG_RSTCAUSE_LONGPRESSTIMEOUT_Pos (3UL)   /*!< Position of LONGPRESSTIMEOUT field.                                  */
#define ERRLOG_RSTCAUSE_LONGPRESSTIMEOUT_Msk (0x1UL << ERRLOG_RSTCAUSE_LONGPRESSTIMEOUT_Pos) /*!< Bit mask of LONGPRESSTIMEOUT
                                                                            field.*/                                              
#define ERRLOG_RSTCAUSE_LONGPRESSTIMEOUT_NORST (0)   /*!< no long press reset                                                  */
#define ERRLOG_RSTCAUSE_LONGPRESSTIMEOUT_RST (1)     /*!< Reset activated by long press of SHPHLD or SHPHLD+GPIO               */

/* THERMALSHUTDOWN @Bit 4 : internal reset caused by TSD */
#define ERRLOG_RSTCAUSE_THERMALSHUTDOWN_Pos (4UL)    /*!< Position of THERMALSHUTDOWN field.                                   */
#define ERRLOG_RSTCAUSE_THERMALSHUTDOWN_Msk (0x1UL << ERRLOG_RSTCAUSE_THERMALSHUTDOWN_Pos) /*!< Bit mask of THERMALSHUTDOWN
                                                                            field.*/                                              
#define ERRLOG_RSTCAUSE_THERMALSHUTDOWN_NORST (0)    /*!< no TSD reset                                                         */
#define ERRLOG_RSTCAUSE_THERMALSHUTDOWN_RST (1)      /*!< reset activated by TSD                                               */

/* VSYSLOW @Bit 5 : internal reset caused by POF, VSYS low */
#define ERRLOG_RSTCAUSE_VSYSLOW_Pos (5UL)            /*!< Position of VSYSLOW field.                                           */
#define ERRLOG_RSTCAUSE_VSYSLOW_Msk (0x1UL << ERRLOG_RSTCAUSE_VSYSLOW_Pos) /*!< Bit mask of VSYSLOW field.                     */
#define ERRLOG_RSTCAUSE_VSYSLOW_NORST (0)            /*!< no VSYS low reset                                                    */
#define ERRLOG_RSTCAUSE_VSYSLOW_RST (1)              /*!< reset activated by VSYS low                                          */

/* SWRESET @Bit 6 : internal reset caused by soft reset */
#define ERRLOG_RSTCAUSE_SWRESET_Pos (6UL)            /*!< Position of SWRESET field.                                           */
#define ERRLOG_RSTCAUSE_SWRESET_Msk (0x1UL << ERRLOG_RSTCAUSE_SWRESET_Pos) /*!< Bit mask of SWRESET field.                     */
#define ERRLOG_RSTCAUSE_SWRESET_NORST (0)            /*!< no s/w reset                                                         */
#define ERRLOG_RSTCAUSE_SWRESET_RST (1)              /*!< reset activated by s/w reset                                         */


/* ERRLOG_CHARGERERRREASON: Error log for slowDomain. Cleared with TASK_CLR_ERRLOG */

/* NTCSENSORERR @Bit 0 : NTC sensor error */
#define ERRLOG_CHARGERERRREASON_NTCSENSORERR_Pos (0UL) /*!< Position of NTCSENSORERR field.                                    */
#define ERRLOG_CHARGERERRREASON_NTCSENSORERR_Msk (0x1UL << ERRLOG_CHARGERERRREASON_NTCSENSORERR_Pos) /*!< Bit mask of
                                                                            NTCSENSORERR field.*/                                 

/* VBATSENSORERR @Bit 1 : VBAT Sensor Error */
#define ERRLOG_CHARGERERRREASON_VBATSENSORERR_Pos (1UL) /*!< Position of VBATSENSORERR field.                                  */
#define ERRLOG_CHARGERERRREASON_VBATSENSORERR_Msk (0x1UL << ERRLOG_CHARGERERRREASON_VBATSENSORERR_Pos) /*!< Bit mask of
                                                                            VBATSENSORERR field.*/                                

/* VBATLOW @Bit 2 : VBAT Low Error */
#define ERRLOG_CHARGERERRREASON_VBATLOW_Pos (2UL)    /*!< Position of VBATLOW field.                                           */
#define ERRLOG_CHARGERERRREASON_VBATLOW_Msk (0x1UL << ERRLOG_CHARGERERRREASON_VBATLOW_Pos) /*!< Bit mask of VBATLOW field.     */

/* VTRICKLE @Bit 3 : Vtrickle Error */
#define ERRLOG_CHARGERERRREASON_VTRICKLE_Pos (3UL)   /*!< Position of VTRICKLE field.                                          */
#define ERRLOG_CHARGERERRREASON_VTRICKLE_Msk (0x1UL << ERRLOG_CHARGERERRREASON_VTRICKLE_Pos) /*!< Bit mask of VTRICKLE field.  */

/* MEASTIMEOUT @Bit 4 : Measurement Timeout Error */
#define ERRLOG_CHARGERERRREASON_MEASTIMEOUT_Pos (4UL) /*!< Position of MEASTIMEOUT field.                                      */
#define ERRLOG_CHARGERERRREASON_MEASTIMEOUT_Msk (0x1UL << ERRLOG_CHARGERERRREASON_MEASTIMEOUT_Pos) /*!< Bit mask of MEASTIMEOUT
                                                                            field.*/                                              

/* CHARGETIMEOUT @Bit 5 : Charge Timeout Error */
#define ERRLOG_CHARGERERRREASON_CHARGETIMEOUT_Pos (5UL) /*!< Position of CHARGETIMEOUT field.                                  */
#define ERRLOG_CHARGERERRREASON_CHARGETIMEOUT_Msk (0x1UL << ERRLOG_CHARGERERRREASON_CHARGETIMEOUT_Pos) /*!< Bit mask of
                                                                            CHARGETIMEOUT field.*/                                

/* TRICKLETIMEOUT @Bit 6 : Trickle Timeout Error */
#define ERRLOG_CHARGERERRREASON_TRICKLETIMEOUT_Pos (6UL) /*!< Position of TRICKLETIMEOUT field.                                */
#define ERRLOG_CHARGERERRREASON_TRICKLETIMEOUT_Msk (0x1UL << ERRLOG_CHARGERERRREASON_TRICKLETIMEOUT_Pos) /*!< Bit mask of
                                                                            TRICKLETIMEOUT field.*/                               


/* ERRLOG_CHARGERERRSENSOR: Bcharger Fsm sensor error. Cleared with TASK_CLR_ERRLOG */

/* SENSORNTCCOLD @Bit 0 : Ntc Cold sensor value during error */
#define ERRLOG_CHARGERERRSENSOR_SENSORNTCCOLD_Pos (0UL) /*!< Position of SENSORNTCCOLD field.                                  */
#define ERRLOG_CHARGERERRSENSOR_SENSORNTCCOLD_Msk (0x1UL << ERRLOG_CHARGERERRSENSOR_SENSORNTCCOLD_Pos) /*!< Bit mask of
                                                                            SENSORNTCCOLD field.*/                                

/* SENSORNTCCOOL @Bit 1 : Ntc Cool sensor value during error */
#define ERRLOG_CHARGERERRSENSOR_SENSORNTCCOOL_Pos (1UL) /*!< Position of SENSORNTCCOOL field.                                  */
#define ERRLOG_CHARGERERRSENSOR_SENSORNTCCOOL_Msk (0x1UL << ERRLOG_CHARGERERRSENSOR_SENSORNTCCOOL_Pos) /*!< Bit mask of
                                                                            SENSORNTCCOOL field.*/                                

/* SENSORNTCWARM @Bit 2 : Ntc Warm sensor value during error */
#define ERRLOG_CHARGERERRSENSOR_SENSORNTCWARM_Pos (2UL) /*!< Position of SENSORNTCWARM field.                                  */
#define ERRLOG_CHARGERERRSENSOR_SENSORNTCWARM_Msk (0x1UL << ERRLOG_CHARGERERRSENSOR_SENSORNTCWARM_Pos) /*!< Bit mask of
                                                                            SENSORNTCWARM field.*/                                

/* SENSORNTCHOT @Bit 3 : Ntc Hot sensor value during error */
#define ERRLOG_CHARGERERRSENSOR_SENSORNTCHOT_Pos (3UL) /*!< Position of SENSORNTCHOT field.                                    */
#define ERRLOG_CHARGERERRSENSOR_SENSORNTCHOT_Msk (0x1UL << ERRLOG_CHARGERERRSENSOR_SENSORNTCHOT_Pos) /*!< Bit mask of
                                                                            SENSORNTCHOT field.*/                                 

/* SENSORVTERM @Bit 4 : Vterm sensor value during error */
#define ERRLOG_CHARGERERRSENSOR_SENSORVTERM_Pos (4UL) /*!< Position of SENSORVTERM field.                                      */
#define ERRLOG_CHARGERERRSENSOR_SENSORVTERM_Msk (0x1UL << ERRLOG_CHARGERERRSENSOR_SENSORVTERM_Pos) /*!< Bit mask of SENSORVTERM
                                                                            field.*/                                              

/* SENSORRECHARGE @Bit 5 : Recharge sensor value during error */
#define ERRLOG_CHARGERERRSENSOR_SENSORRECHARGE_Pos (5UL) /*!< Position of SENSORRECHARGE field.                                */
#define ERRLOG_CHARGERERRSENSOR_SENSORRECHARGE_Msk (0x1UL << ERRLOG_CHARGERERRSENSOR_SENSORRECHARGE_Pos) /*!< Bit mask of
                                                                            SENSORRECHARGE field.*/                               

/* SENSORVTRICKLE @Bit 6 : Vtrickle sensor value during error */
#define ERRLOG_CHARGERERRSENSOR_SENSORVTRICKLE_Pos (6UL) /*!< Position of SENSORVTRICKLE field.                                */
#define ERRLOG_CHARGERERRSENSOR_SENSORVTRICKLE_Msk (0x1UL << ERRLOG_CHARGERERRSENSOR_SENSORVTRICKLE_Pos) /*!< Bit mask of
                                                                            SENSORVTRICKLE field.*/                               

/* SENSORVBATLOW @Bit 7 : VbatLow sensor value during error */
#define ERRLOG_CHARGERERRSENSOR_SENSORVBATLOW_Pos (7UL) /*!< Position of SENSORVBATLOW field.                                  */
#define ERRLOG_CHARGERERRSENSOR_SENSORVBATLOW_Msk (0x1UL << ERRLOG_CHARGERERRSENSOR_SENSORVBATLOW_Pos) /*!< Bit mask of
                                                                            SENSORVBATLOW field.*/                                



/* =========================================================================================================================== */
/* ================                                  Peripheral Address Map                                  ================ */
/* =========================================================================================================================== */

#define NPM_ABS_BASE                      0x00000000UL
#define NPM_MAIN_BASE                     0x00000000UL
#define NPM_SYSTEM_BASE                   0x00000100UL
#define NPM_VBUSIN_BASE                   0x00000200UL
#define NPM_BCHARGER_BASE                 0x00000300UL
#define NPM_BUCK_BASE                     0x00000400UL
#define NPM_ADC_BASE                      0x00000500UL
#define NPM_GPIOS_BASE                    0x00000600UL
#define NPM_TIMER_BASE                    0x00000700UL
#define NPM_LDSW_BASE                     0x00000800UL
#define NPM_POF_BASE                      0x00000900UL
#define NPM_LEDDRV_BASE                   0x00000A00UL
#define NPM_SHIP_BASE                     0x00000B00UL
#define NPM_FICR_BASE                     0x00000C00UL
#define NPM_ERRLOG_BASE                   0x00000E00UL

/* =========================================================================================================================== */
/* ================                                  Peripheral Declaration                                  ================ */
/* =========================================================================================================================== */

#define NPM_ABS                           ((NPM_ABSMAXRATINGS_Type*)            NPM_ABS_BASE)
#define NPM_MAIN                          ((NPM_MAIN_Type*)                     NPM_MAIN_BASE)
#define NPM_SYSTEM                        ((NPM_SYSTEM_Type*)                   NPM_SYSTEM_BASE)
#define NPM_VBUSIN                        ((NPM_VBUSIN_Type*)                   NPM_VBUSIN_BASE)
#define NPM_BCHARGER                      ((NPM_BCHARGER_Type*)                 NPM_BCHARGER_BASE)
#define NPM_BUCK                          ((NPM_BUCK_Type*)                     NPM_BUCK_BASE)
#define NPM_ADC                           ((NPM_ADC_Type*)                      NPM_ADC_BASE)
#define NPM_GPIOS                         ((NPM_GPIOS_Type*)                    NPM_GPIOS_BASE)
#define NPM_TIMER                         ((NPM_TIMER_Type*)                    NPM_TIMER_BASE)
#define NPM_LDSW                          ((NPM_LDSW_Type*)                     NPM_LDSW_BASE)
#define NPM_POF                           ((NPM_POF_Type*)                      NPM_POF_BASE)
#define NPM_LEDDRV                        ((NPM_LEDDRV_Type*)                   NPM_LEDDRV_BASE)
#define NPM_SHIP                          ((NPM_SHPHLD_Type*)                   NPM_SHIP_BASE)
#define NPM_FICR                          ((NPM_FICR_Type*)                     NPM_FICR_BASE)
#define NPM_ERRLOG                        ((NPM_ERRLOG_Type*)                   NPM_ERRLOG_BASE)

/* ========================================== End of section using anonymous unions ========================================== */

#if defined (__CC_ARM)
  #pragma pop
#elif defined (__ICCARM__)
  /* leave anonymous unions enabled */
#elif (__ARMCC_VERSION >= 6010050)
  #pragma clang diagnostic pop
#elif defined (__GNUC__)
  /* anonymous unions are enabled by default */
#elif defined (__TMS470__)
  /* anonymous unions are enabled by default */
#elif defined (__TASKING__)
  #pragma warning restore
#elif defined (__CSMC__)
  /* anonymous unions are enabled by default */
#endif


#ifdef __cplusplus
}
#endif
#endif /* NPM1300_ENG_B_H */
