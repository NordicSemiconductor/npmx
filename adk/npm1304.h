/*

Copyright (c) 2025, Nordic Semiconductor ASA

All rights reserved.

Redistribution and use in source and binary forms, with or without modification,
are permitted provided that the following conditions are met:

1. Redistributions of source code must retain the above copyright notice, this
   list of conditions and the following disclaimer.

2. Redistributions in binary form, except as embedded into a Nordic
   Semiconductor ASA integrated circuit in a product or a software update for
   such product, must reproduce the above copyright notice, this list of
   conditions and the following disclaimer in the documentation and/or other
   materials provided with the distribution.

3. Neither the name of Nordic Semiconductor ASA nor the names of its
   contributors may be used to endorse or promote products derived from this
   software without specific prior written permission.

4. This software, with or without modification, must only be used with a
   Nordic Semiconductor ASA integrated circuit.

5. Any software provided in binary form under this license must not be reverse
   engineered, decompiled, modified and/or disassembled.

THIS SOFTWARE IS PROVIDED BY NORDIC SEMICONDUCTOR ASA "AS IS" AND ANY EXPRESS
OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES
OF MERCHANTABILITY, NONINFRINGEMENT, AND FITNESS FOR A PARTICULAR PURPOSE ARE
DISCLAIMED. IN NO EVENT SHALL NORDIC SEMICONDUCTOR ASA OR CONTRIBUTORS BE
LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE
GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)
HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT
LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT
OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.

*/


#ifndef NPM1304_H
#define NPM1304_H

#ifdef __cplusplus
    extern "C" {
#endif

/* ====================================================== Include types ====================================================== */
#include "npm1304_types.h"

/* ========================================= Start of section using anonymous unions ========================================= */

#include "compiler_abstraction.h"

#if defined (__CC_ARM)
  #pragma push
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
/* ================                                       ABSMAXRATINGS                                       ================ */
/* =========================================================================================================================== */

#if !defined(__ASSEMBLER__) && !defined(__ASSEMBLY__) /*!< Ignore C structs for assembly code.                                 */
/* ================================================== Struct ABSMAXRATINGS =================================================== */
/**
  * @brief abs_max_ratings
  */
  typedef struct {                                   /*!< ABSMAXRATINGS Structure                                              */
    __IM uint8_t RESERVED[4];
  } NPM_ABSMAXRATINGS_Type;                          /*!< Size = 4 (0x004)                                                     */

#endif                                               /*!< !defined(__ASSEMBLER__) && !defined(__ASSEMBLY__)                    */

/* =========================================================================================================================== */
/* ================                                           MAIN                                           ================ */
/* =========================================================================================================================== */

#if !defined(__ASSEMBLER__) && !defined(__ASSEMBLY__) /*!< Ignore C structs for assembly code.                                 */
/* ======================================================= Struct MAIN ======================================================= */
/**
  * @brief nPM1304 MAIN Registers
  */
  typedef struct {                                   /*!< MAIN Structure                                                       */
    __IM uint8_t  RESERVED;
    __OM uint8_t  TASKSWRESET;                       /*!< (@ 0x00000001) Task force a full reboot power-cycle                  */
    __IOM uint8_t EVENTSADCSET;                      /*!< (@ 0x00000002) ADC Event Set                                         */
    __IOM uint8_t EVENTSADCCLR;                      /*!< (@ 0x00000003) ADC Event Clear                                       */
    __IOM uint8_t INTENEVENTSADCSET;                 /*!< (@ 0x00000004) ADC Interrupt Enable Set                              */
    __IOM uint8_t INTENEVENTSADCCLR;                 /*!< (@ 0x00000005) ADC Interrupt Enable Clear                            */
    __IOM uint8_t EVENTSBCHARGER0SET;                /*!< (@ 0x00000006) Battery temperature region and die temperature Event
                                                                         Set*/                                                    
    __IOM uint8_t EVENTSBCHARGER0CLR;                /*!< (@ 0x00000007) Battery temperature region and die temperature Event
                                                                         Clear*/                                                  
    __IOM uint8_t INTENEVENTSBCHARGER0SET;           /*!< (@ 0x00000008) Battery temperature region and die temperature
                                                                         Interrupt Enable Set*/                                   
    __IOM uint8_t INTENEVENTSBCHARGER0CLR;           /*!< (@ 0x00000009) Battery temperature region and die temperature
                                                                         Interrupt Enable Clear*/                                 
    __IOM uint8_t EVENTSBCHARGER1SET;                /*!< (@ 0x0000000A) Charger Event Set                                     */
    __IOM uint8_t EVENTSBCHARGER1CLR;                /*!< (@ 0x0000000B) Charger Event Clear                                   */
    __IOM uint8_t INTENEVENTSBCHARGER1SET;           /*!< (@ 0x0000000C) Charger Interrupt Enable Set                          */
    __IOM uint8_t INTENEVENTSBCHARGER1CLR;           /*!< (@ 0x0000000D) Charger Interrupt Enable Clear                        */
    __IOM uint8_t EVENTSBCHARGER2SET;                /*!< (@ 0x0000000E) Battery Event Set                                     */
    __IOM uint8_t EVENTSBCHARGER2CLR;                /*!< (@ 0x0000000F) Battery Event Clear                                   */
    __IOM uint8_t INTENEVENTSBCHARGER2SET;           /*!< (@ 0x00000010) Battery Interrupt Enable Set                          */
    __IOM uint8_t INTENEVENTSBCHARGER2CLR;           /*!< (@ 0x00000011) Battery Interrupt Enable Clear                        */
    __IOM uint8_t EVENTSSHPHLDSET;                   /*!< (@ 0x00000012) SHPHLD pin and watchdog Event Set                     */
    __IOM uint8_t EVENTSSHPHLDCLR;                   /*!< (@ 0x00000013) SHPHLD pin and watchdog Event Clear                   */
    __IOM uint8_t INTENEVENTSSHPHLDSET;              /*!< (@ 0x00000014) SHPHLD pin and watchdog Interrupt Enable Set          */
    __IOM uint8_t INTENEVENTSSHPHLDCLR;              /*!< (@ 0x00000015) SHPHLD pin and watchdog Interrupt Enable Clear        */
    __IOM uint8_t EVENTSVBUSIN0SET;                  /*!< (@ 0x00000016) VBUS Event Set                                        */
    __IOM uint8_t EVENTSVBUSIN0CLR;                  /*!< (@ 0x00000017) VBUS Event Clear                                      */
    __IOM uint8_t INTENEVENTSVBUSIN0SET;             /*!< (@ 0x00000018) VBUS Interrupt Enable Set                             */
    __IOM uint8_t INTENEVENTSVBUSIN0CLR;             /*!< (@ 0x00000019) VBUS Interrupt Enable Clear                           */
    __IOM uint8_t EVENTSVBUSIN1SET;                  /*!< (@ 0x0000001A) Thermal and charger detection Event Set               */
    __IOM uint8_t EVENTSVBUSIN1CLR;                  /*!< (@ 0x0000001B) Thermal and charger detection Event Clear             */
    __IOM uint8_t INTENEVENTSVBUSIN1SET;             /*!< (@ 0x0000001C) Thermal and charger detection Interrupt Enable Set    */
    __IOM uint8_t INTENEVENTSVBUSIN1CLR;             /*!< (@ 0x0000001D) Thermal and charger detection Interrupt Enable Clear  */
    __IM uint8_t RESERVED1[4];
    __IOM uint8_t EVENTSGPIOSET;                     /*!< (@ 0x00000022) GPIO Event Set                                        */
    __IOM uint8_t EVENTSGPIOCLR;                     /*!< (@ 0x00000023) GPIO Event Clear                                      */
    __IOM uint8_t INTENEVENTSGPIOSET;                /*!< (@ 0x00000024) GPIO Interrupt Enable Set                             */
    __IOM uint8_t INTENEVENTSGPIOCLR;                /*!< (@ 0x00000025) GPIO Interrupt Enable Clear                           */
  } NPM_MAIN_Type;                                   /*!< Size = 38 (0x026)                                                    */

/* MAIN_TASKSWRESET: Task force a full reboot power-cycle */
  #define MAIN_TASKSWRESET_ResetValue (0x00UL)       /*!< Reset value of TASKSWRESET register.                                 */

/* TASKSWRESET @Bit 0 : Turn off all supplies and apply internal reset */
  #define MAIN_TASKSWRESET_TASKSWRESET_Pos (0UL)     /*!< Position of TASKSWRESET field.                                       */
  #define MAIN_TASKSWRESET_TASKSWRESET_Msk (0x1UL << MAIN_TASKSWRESET_TASKSWRESET_Pos) /*!< Bit mask of TASKSWRESET field.     */
  #define MAIN_TASKSWRESET_TASKSWRESET_Min (0x0UL)   /*!< Min enumerator value of TASKSWRESET field.                           */
  #define MAIN_TASKSWRESET_TASKSWRESET_Max (0x1UL)   /*!< Max enumerator value of TASKSWRESET field.                           */
  #define MAIN_TASKSWRESET_TASKSWRESET_NOEFFECT (0x0UL) /*!< No effect                                                         */
  #define MAIN_TASKSWRESET_TASKSWRESET_TRIGGER (0x1UL) /*!< Trigger task                                                       */


/* MAIN_EVENTSADCSET: ADC Event Set */
  #define MAIN_EVENTSADCSET_ResetValue (0x00UL)      /*!< Reset value of EVENTSADCSET register.                                */

/* EVENTADCVBATRDY @Bit 0 : VBAT measurement finished. Writing 1 sets the event (for debugging). */
  #define MAIN_EVENTSADCSET_EVENTADCVBATRDY_Pos (0UL) /*!< Position of EVENTADCVBATRDY field.                                  */
  #define MAIN_EVENTSADCSET_EVENTADCVBATRDY_Msk (0x1UL << MAIN_EVENTSADCSET_EVENTADCVBATRDY_Pos) /*!< Bit mask of
                                                                            EVENTADCVBATRDY field.*/                              
  #define MAIN_EVENTSADCSET_EVENTADCVBATRDY_Min (0x0UL) /*!< Min enumerator value of EVENTADCVBATRDY field.                    */
  #define MAIN_EVENTSADCSET_EVENTADCVBATRDY_Max (0x1UL) /*!< Max enumerator value of EVENTADCVBATRDY field.                    */
  #define MAIN_EVENTSADCSET_EVENTADCVBATRDY_LOW (0x0UL) /*!< Low                                                               */
  #define MAIN_EVENTSADCSET_EVENTADCVBATRDY_HIGH (0x1UL) /*!< High                                                             */

/* EVENTADCNTCRDY @Bit 1 : Battery NTC measurement finished. Writing 1 sets the event (for debugging). */
  #define MAIN_EVENTSADCSET_EVENTADCNTCRDY_Pos (1UL) /*!< Position of EVENTADCNTCRDY field.                                    */
  #define MAIN_EVENTSADCSET_EVENTADCNTCRDY_Msk (0x1UL << MAIN_EVENTSADCSET_EVENTADCNTCRDY_Pos) /*!< Bit mask of EVENTADCNTCRDY
                                                                            field.*/                                              
  #define MAIN_EVENTSADCSET_EVENTADCNTCRDY_Min (0x0UL) /*!< Min enumerator value of EVENTADCNTCRDY field.                      */
  #define MAIN_EVENTSADCSET_EVENTADCNTCRDY_Max (0x1UL) /*!< Max enumerator value of EVENTADCNTCRDY field.                      */
  #define MAIN_EVENTSADCSET_EVENTADCNTCRDY_LOW (0x0UL) /*!< Low                                                                */
  #define MAIN_EVENTSADCSET_EVENTADCNTCRDY_HIGH (0x1UL) /*!< High                                                              */

/* EVENTADCTEMPRDY @Bit 2 : Internal die temperature measurement finished. Writing 1 sets the event (for debugging). */
  #define MAIN_EVENTSADCSET_EVENTADCTEMPRDY_Pos (2UL) /*!< Position of EVENTADCTEMPRDY field.                                  */
  #define MAIN_EVENTSADCSET_EVENTADCTEMPRDY_Msk (0x1UL << MAIN_EVENTSADCSET_EVENTADCTEMPRDY_Pos) /*!< Bit mask of
                                                                            EVENTADCTEMPRDY field.*/                              
  #define MAIN_EVENTSADCSET_EVENTADCTEMPRDY_Min (0x0UL) /*!< Min enumerator value of EVENTADCTEMPRDY field.                    */
  #define MAIN_EVENTSADCSET_EVENTADCTEMPRDY_Max (0x1UL) /*!< Max enumerator value of EVENTADCTEMPRDY field.                    */
  #define MAIN_EVENTSADCSET_EVENTADCTEMPRDY_LOW (0x0UL) /*!< Low                                                               */
  #define MAIN_EVENTSADCSET_EVENTADCTEMPRDY_HIGH (0x1UL) /*!< High                                                             */

/* EVENTADCVSYSRDY @Bit 3 : VSYS voltage measurement measurement finished. Writing 1 sets the event (for debugging). */
  #define MAIN_EVENTSADCSET_EVENTADCVSYSRDY_Pos (3UL) /*!< Position of EVENTADCVSYSRDY field.                                  */
  #define MAIN_EVENTSADCSET_EVENTADCVSYSRDY_Msk (0x1UL << MAIN_EVENTSADCSET_EVENTADCVSYSRDY_Pos) /*!< Bit mask of
                                                                            EVENTADCVSYSRDY field.*/                              
  #define MAIN_EVENTSADCSET_EVENTADCVSYSRDY_Min (0x0UL) /*!< Min enumerator value of EVENTADCVSYSRDY field.                    */
  #define MAIN_EVENTSADCSET_EVENTADCVSYSRDY_Max (0x1UL) /*!< Max enumerator value of EVENTADCVSYSRDY field.                    */
  #define MAIN_EVENTSADCSET_EVENTADCVSYSRDY_LOW (0x0UL) /*!< Low                                                               */
  #define MAIN_EVENTSADCSET_EVENTADCVSYSRDY_HIGH (0x1UL) /*!< High                                                             */

/* EVENTADCVSET1RDY @Bit 4 : VSET1 pin measurement finished. Writing 1 sets the event (for debugging). */
  #define MAIN_EVENTSADCSET_EVENTADCVSET1RDY_Pos (4UL) /*!< Position of EVENTADCVSET1RDY field.                                */
  #define MAIN_EVENTSADCSET_EVENTADCVSET1RDY_Msk (0x1UL << MAIN_EVENTSADCSET_EVENTADCVSET1RDY_Pos) /*!< Bit mask of
                                                                            EVENTADCVSET1RDY field.*/                             
  #define MAIN_EVENTSADCSET_EVENTADCVSET1RDY_Min (0x0UL) /*!< Min enumerator value of EVENTADCVSET1RDY field.                  */
  #define MAIN_EVENTSADCSET_EVENTADCVSET1RDY_Max (0x1UL) /*!< Max enumerator value of EVENTADCVSET1RDY field.                  */
  #define MAIN_EVENTSADCSET_EVENTADCVSET1RDY_LOW (0x0UL) /*!< Low                                                              */
  #define MAIN_EVENTSADCSET_EVENTADCVSET1RDY_HIGH (0x1UL) /*!< High                                                            */

/* EVENTADCVSET2RDY @Bit 5 : VSET2 pin measurement finished. Writing 1 sets the event (for debugging). */
  #define MAIN_EVENTSADCSET_EVENTADCVSET2RDY_Pos (5UL) /*!< Position of EVENTADCVSET2RDY field.                                */
  #define MAIN_EVENTSADCSET_EVENTADCVSET2RDY_Msk (0x1UL << MAIN_EVENTSADCSET_EVENTADCVSET2RDY_Pos) /*!< Bit mask of
                                                                            EVENTADCVSET2RDY field.*/                             
  #define MAIN_EVENTSADCSET_EVENTADCVSET2RDY_Min (0x0UL) /*!< Min enumerator value of EVENTADCVSET2RDY field.                  */
  #define MAIN_EVENTSADCSET_EVENTADCVSET2RDY_Max (0x1UL) /*!< Max enumerator value of EVENTADCVSET2RDY field.                  */
  #define MAIN_EVENTSADCSET_EVENTADCVSET2RDY_LOW (0x0UL) /*!< Low                                                              */
  #define MAIN_EVENTSADCSET_EVENTADCVSET2RDY_HIGH (0x1UL) /*!< High                                                            */

/* EVENTADCIBATRDY @Bit 6 : IBAT measurement finished. Writing 1 sets the event (for debugging). */
  #define MAIN_EVENTSADCSET_EVENTADCIBATRDY_Pos (6UL) /*!< Position of EVENTADCIBATRDY field.                                  */
  #define MAIN_EVENTSADCSET_EVENTADCIBATRDY_Msk (0x1UL << MAIN_EVENTSADCSET_EVENTADCIBATRDY_Pos) /*!< Bit mask of
                                                                            EVENTADCIBATRDY field.*/                              
  #define MAIN_EVENTSADCSET_EVENTADCIBATRDY_Min (0x0UL) /*!< Min enumerator value of EVENTADCIBATRDY field.                    */
  #define MAIN_EVENTSADCSET_EVENTADCIBATRDY_Max (0x1UL) /*!< Max enumerator value of EVENTADCIBATRDY field.                    */
  #define MAIN_EVENTSADCSET_EVENTADCIBATRDY_LOW (0x0UL) /*!< Low                                                               */
  #define MAIN_EVENTSADCSET_EVENTADCIBATRDY_HIGH (0x1UL) /*!< High                                                             */

/* EVENTADCVBUS7V0RDY @Bit 7 : VBUS measurement finished. Writing 1 sets the event (for debugging). */
  #define MAIN_EVENTSADCSET_EVENTADCVBUS7V0RDY_Pos (7UL) /*!< Position of EVENTADCVBUS7V0RDY field.                            */
  #define MAIN_EVENTSADCSET_EVENTADCVBUS7V0RDY_Msk (0x1UL << MAIN_EVENTSADCSET_EVENTADCVBUS7V0RDY_Pos) /*!< Bit mask of
                                                                            EVENTADCVBUS7V0RDY field.*/                           
  #define MAIN_EVENTSADCSET_EVENTADCVBUS7V0RDY_Min (0x0UL) /*!< Min enumerator value of EVENTADCVBUS7V0RDY field.              */
  #define MAIN_EVENTSADCSET_EVENTADCVBUS7V0RDY_Max (0x1UL) /*!< Max enumerator value of EVENTADCVBUS7V0RDY field.              */
  #define MAIN_EVENTSADCSET_EVENTADCVBUS7V0RDY_LOW (0x0UL) /*!< Low                                                            */
  #define MAIN_EVENTSADCSET_EVENTADCVBUS7V0RDY_HIGH (0x1UL) /*!< High                                                          */


/* MAIN_EVENTSADCCLR: ADC Event Clear */
  #define MAIN_EVENTSADCCLR_ResetValue (0x00UL)      /*!< Reset value of EVENTSADCCLR register.                                */

/* EVENTADCVBATRDY @Bit 0 : VBAT measurement finished. Writing 1 clears the event (e.g. to acknowledge an interrupt). */
  #define MAIN_EVENTSADCCLR_EVENTADCVBATRDY_Pos (0UL) /*!< Position of EVENTADCVBATRDY field.                                  */
  #define MAIN_EVENTSADCCLR_EVENTADCVBATRDY_Msk (0x1UL << MAIN_EVENTSADCCLR_EVENTADCVBATRDY_Pos) /*!< Bit mask of
                                                                            EVENTADCVBATRDY field.*/                              
  #define MAIN_EVENTSADCCLR_EVENTADCVBATRDY_Min (0x0UL) /*!< Min enumerator value of EVENTADCVBATRDY field.                    */
  #define MAIN_EVENTSADCCLR_EVENTADCVBATRDY_Max (0x1UL) /*!< Max enumerator value of EVENTADCVBATRDY field.                    */
  #define MAIN_EVENTSADCCLR_EVENTADCVBATRDY_LOW (0x0UL) /*!< Low                                                               */
  #define MAIN_EVENTSADCCLR_EVENTADCVBATRDY_HIGH (0x1UL) /*!< High                                                             */

/* EVENTADCNTCRDY @Bit 1 : Battery NTC measurement finished. Writing 1 clears the event (e.g. to acknowledge an interrupt). */
  #define MAIN_EVENTSADCCLR_EVENTADCNTCRDY_Pos (1UL) /*!< Position of EVENTADCNTCRDY field.                                    */
  #define MAIN_EVENTSADCCLR_EVENTADCNTCRDY_Msk (0x1UL << MAIN_EVENTSADCCLR_EVENTADCNTCRDY_Pos) /*!< Bit mask of EVENTADCNTCRDY
                                                                            field.*/                                              
  #define MAIN_EVENTSADCCLR_EVENTADCNTCRDY_Min (0x0UL) /*!< Min enumerator value of EVENTADCNTCRDY field.                      */
  #define MAIN_EVENTSADCCLR_EVENTADCNTCRDY_Max (0x1UL) /*!< Max enumerator value of EVENTADCNTCRDY field.                      */
  #define MAIN_EVENTSADCCLR_EVENTADCNTCRDY_LOW (0x0UL) /*!< Low                                                                */
  #define MAIN_EVENTSADCCLR_EVENTADCNTCRDY_HIGH (0x1UL) /*!< High                                                              */

/* EVENTADCTEMPRDY @Bit 2 : Internal die temperature measurement finished. Writing 1 clears the event (e.g. to acknowledge an
                            interrupt). */                                                                                        
                                                                                                                                  
  #define MAIN_EVENTSADCCLR_EVENTADCTEMPRDY_Pos (2UL) /*!< Position of EVENTADCTEMPRDY field.                                  */
  #define MAIN_EVENTSADCCLR_EVENTADCTEMPRDY_Msk (0x1UL << MAIN_EVENTSADCCLR_EVENTADCTEMPRDY_Pos) /*!< Bit mask of
                                                                            EVENTADCTEMPRDY field.*/                              
  #define MAIN_EVENTSADCCLR_EVENTADCTEMPRDY_Min (0x0UL) /*!< Min enumerator value of EVENTADCTEMPRDY field.                    */
  #define MAIN_EVENTSADCCLR_EVENTADCTEMPRDY_Max (0x1UL) /*!< Max enumerator value of EVENTADCTEMPRDY field.                    */
  #define MAIN_EVENTSADCCLR_EVENTADCTEMPRDY_LOW (0x0UL) /*!< Low                                                               */
  #define MAIN_EVENTSADCCLR_EVENTADCTEMPRDY_HIGH (0x1UL) /*!< High                                                             */

/* EVENTADCVSYSRDY @Bit 3 : VSYS voltage measurement measurement finished. Writing 1 clears the event (e.g. to acknowledge an
                            interrupt). */                                                                                        
                                                                                                                                  
  #define MAIN_EVENTSADCCLR_EVENTADCVSYSRDY_Pos (3UL) /*!< Position of EVENTADCVSYSRDY field.                                  */
  #define MAIN_EVENTSADCCLR_EVENTADCVSYSRDY_Msk (0x1UL << MAIN_EVENTSADCCLR_EVENTADCVSYSRDY_Pos) /*!< Bit mask of
                                                                            EVENTADCVSYSRDY field.*/                              
  #define MAIN_EVENTSADCCLR_EVENTADCVSYSRDY_Min (0x0UL) /*!< Min enumerator value of EVENTADCVSYSRDY field.                    */
  #define MAIN_EVENTSADCCLR_EVENTADCVSYSRDY_Max (0x1UL) /*!< Max enumerator value of EVENTADCVSYSRDY field.                    */
  #define MAIN_EVENTSADCCLR_EVENTADCVSYSRDY_LOW (0x0UL) /*!< Low                                                               */
  #define MAIN_EVENTSADCCLR_EVENTADCVSYSRDY_HIGH (0x1UL) /*!< High                                                             */

/* EVENTADCVSET1RDY @Bit 4 : VSET1 pin measurement finished. Writing 1 clears the event (e.g. to acknowledge an interrupt). */
  #define MAIN_EVENTSADCCLR_EVENTADCVSET1RDY_Pos (4UL) /*!< Position of EVENTADCVSET1RDY field.                                */
  #define MAIN_EVENTSADCCLR_EVENTADCVSET1RDY_Msk (0x1UL << MAIN_EVENTSADCCLR_EVENTADCVSET1RDY_Pos) /*!< Bit mask of
                                                                            EVENTADCVSET1RDY field.*/                             
  #define MAIN_EVENTSADCCLR_EVENTADCVSET1RDY_Min (0x0UL) /*!< Min enumerator value of EVENTADCVSET1RDY field.                  */
  #define MAIN_EVENTSADCCLR_EVENTADCVSET1RDY_Max (0x1UL) /*!< Max enumerator value of EVENTADCVSET1RDY field.                  */
  #define MAIN_EVENTSADCCLR_EVENTADCVSET1RDY_LOW (0x0UL) /*!< Low                                                              */
  #define MAIN_EVENTSADCCLR_EVENTADCVSET1RDY_HIGH (0x1UL) /*!< High                                                            */

/* EVENTADCVSET2RDY @Bit 5 : VSET2 pin measurement finished. Writing 1 clears the event (e.g. to acknowledge an interrupt). */
  #define MAIN_EVENTSADCCLR_EVENTADCVSET2RDY_Pos (5UL) /*!< Position of EVENTADCVSET2RDY field.                                */
  #define MAIN_EVENTSADCCLR_EVENTADCVSET2RDY_Msk (0x1UL << MAIN_EVENTSADCCLR_EVENTADCVSET2RDY_Pos) /*!< Bit mask of
                                                                            EVENTADCVSET2RDY field.*/                             
  #define MAIN_EVENTSADCCLR_EVENTADCVSET2RDY_Min (0x0UL) /*!< Min enumerator value of EVENTADCVSET2RDY field.                  */
  #define MAIN_EVENTSADCCLR_EVENTADCVSET2RDY_Max (0x1UL) /*!< Max enumerator value of EVENTADCVSET2RDY field.                  */
  #define MAIN_EVENTSADCCLR_EVENTADCVSET2RDY_LOW (0x0UL) /*!< Low                                                              */
  #define MAIN_EVENTSADCCLR_EVENTADCVSET2RDY_HIGH (0x1UL) /*!< High                                                            */

/* EVENTADCIBATRDY @Bit 6 : IBAT measurement finished. Writing 1 clears the event (e.g. to acknowledge an interrupt). */
  #define MAIN_EVENTSADCCLR_EVENTADCIBATRDY_Pos (6UL) /*!< Position of EVENTADCIBATRDY field.                                  */
  #define MAIN_EVENTSADCCLR_EVENTADCIBATRDY_Msk (0x1UL << MAIN_EVENTSADCCLR_EVENTADCIBATRDY_Pos) /*!< Bit mask of
                                                                            EVENTADCIBATRDY field.*/                              
  #define MAIN_EVENTSADCCLR_EVENTADCIBATRDY_Min (0x0UL) /*!< Min enumerator value of EVENTADCIBATRDY field.                    */
  #define MAIN_EVENTSADCCLR_EVENTADCIBATRDY_Max (0x1UL) /*!< Max enumerator value of EVENTADCIBATRDY field.                    */
  #define MAIN_EVENTSADCCLR_EVENTADCIBATRDY_LOW (0x0UL) /*!< Low                                                               */
  #define MAIN_EVENTSADCCLR_EVENTADCIBATRDY_HIGH (0x1UL) /*!< High                                                             */

/* EVENTADCVBUS7V0RDY @Bit 7 : VBUS measurement finished. Writing 1 clears the event (e.g. to acknowledge an interrupt). */
  #define MAIN_EVENTSADCCLR_EVENTADCVBUS7V0RDY_Pos (7UL) /*!< Position of EVENTADCVBUS7V0RDY field.                            */
  #define MAIN_EVENTSADCCLR_EVENTADCVBUS7V0RDY_Msk (0x1UL << MAIN_EVENTSADCCLR_EVENTADCVBUS7V0RDY_Pos) /*!< Bit mask of
                                                                            EVENTADCVBUS7V0RDY field.*/                           
  #define MAIN_EVENTSADCCLR_EVENTADCVBUS7V0RDY_Min (0x0UL) /*!< Min enumerator value of EVENTADCVBUS7V0RDY field.              */
  #define MAIN_EVENTSADCCLR_EVENTADCVBUS7V0RDY_Max (0x1UL) /*!< Max enumerator value of EVENTADCVBUS7V0RDY field.              */
  #define MAIN_EVENTSADCCLR_EVENTADCVBUS7V0RDY_LOW (0x0UL) /*!< Low                                                            */
  #define MAIN_EVENTSADCCLR_EVENTADCVBUS7V0RDY_HIGH (0x1UL) /*!< High                                                          */


/* MAIN_INTENEVENTSADCSET: ADC Interrupt Enable Set */
  #define MAIN_INTENEVENTSADCSET_ResetValue (0x00UL) /*!< Reset value of INTENEVENTSADCSET register.                           */

/* EVENTADCVBATRDY @Bit 0 : Writing 1 enables interrupts from EVENTADCVBATRDY */
  #define MAIN_INTENEVENTSADCSET_EVENTADCVBATRDY_Pos (0UL) /*!< Position of EVENTADCVBATRDY field.                             */
  #define MAIN_INTENEVENTSADCSET_EVENTADCVBATRDY_Msk (0x1UL << MAIN_INTENEVENTSADCSET_EVENTADCVBATRDY_Pos) /*!< Bit mask of
                                                                            EVENTADCVBATRDY field.*/                              
  #define MAIN_INTENEVENTSADCSET_EVENTADCVBATRDY_Min (0x0UL) /*!< Min enumerator value of EVENTADCVBATRDY field.               */
  #define MAIN_INTENEVENTSADCSET_EVENTADCVBATRDY_Max (0x1UL) /*!< Max enumerator value of EVENTADCVBATRDY field.               */
  #define MAIN_INTENEVENTSADCSET_EVENTADCVBATRDY_LOW (0x0UL) /*!< Low                                                          */
  #define MAIN_INTENEVENTSADCSET_EVENTADCVBATRDY_HIGH (0x1UL) /*!< High                                                        */

/* EVENTADCNTCRDY @Bit 1 : Writing 1 enables interrupts from EVENTADCNTCRDY */
  #define MAIN_INTENEVENTSADCSET_EVENTADCNTCRDY_Pos (1UL) /*!< Position of EVENTADCNTCRDY field.                               */
  #define MAIN_INTENEVENTSADCSET_EVENTADCNTCRDY_Msk (0x1UL << MAIN_INTENEVENTSADCSET_EVENTADCNTCRDY_Pos) /*!< Bit mask of
                                                                            EVENTADCNTCRDY field.*/                               
  #define MAIN_INTENEVENTSADCSET_EVENTADCNTCRDY_Min (0x0UL) /*!< Min enumerator value of EVENTADCNTCRDY field.                 */
  #define MAIN_INTENEVENTSADCSET_EVENTADCNTCRDY_Max (0x1UL) /*!< Max enumerator value of EVENTADCNTCRDY field.                 */
  #define MAIN_INTENEVENTSADCSET_EVENTADCNTCRDY_LOW (0x0UL) /*!< Low                                                           */
  #define MAIN_INTENEVENTSADCSET_EVENTADCNTCRDY_HIGH (0x1UL) /*!< High                                                         */

/* EVENTADCTEMPRDY @Bit 2 : Writing 1 enables interrupts from EVENTADCTEMPRDY */
  #define MAIN_INTENEVENTSADCSET_EVENTADCTEMPRDY_Pos (2UL) /*!< Position of EVENTADCTEMPRDY field.                             */
  #define MAIN_INTENEVENTSADCSET_EVENTADCTEMPRDY_Msk (0x1UL << MAIN_INTENEVENTSADCSET_EVENTADCTEMPRDY_Pos) /*!< Bit mask of
                                                                            EVENTADCTEMPRDY field.*/                              
  #define MAIN_INTENEVENTSADCSET_EVENTADCTEMPRDY_Min (0x0UL) /*!< Min enumerator value of EVENTADCTEMPRDY field.               */
  #define MAIN_INTENEVENTSADCSET_EVENTADCTEMPRDY_Max (0x1UL) /*!< Max enumerator value of EVENTADCTEMPRDY field.               */
  #define MAIN_INTENEVENTSADCSET_EVENTADCTEMPRDY_LOW (0x0UL) /*!< Low                                                          */
  #define MAIN_INTENEVENTSADCSET_EVENTADCTEMPRDY_HIGH (0x1UL) /*!< High                                                        */

/* EVENTADCVSYSRDY @Bit 3 : Writing 1 enables interrupts from EVENTADCVSYSRDY */
  #define MAIN_INTENEVENTSADCSET_EVENTADCVSYSRDY_Pos (3UL) /*!< Position of EVENTADCVSYSRDY field.                             */
  #define MAIN_INTENEVENTSADCSET_EVENTADCVSYSRDY_Msk (0x1UL << MAIN_INTENEVENTSADCSET_EVENTADCVSYSRDY_Pos) /*!< Bit mask of
                                                                            EVENTADCVSYSRDY field.*/                              
  #define MAIN_INTENEVENTSADCSET_EVENTADCVSYSRDY_Min (0x0UL) /*!< Min enumerator value of EVENTADCVSYSRDY field.               */
  #define MAIN_INTENEVENTSADCSET_EVENTADCVSYSRDY_Max (0x1UL) /*!< Max enumerator value of EVENTADCVSYSRDY field.               */
  #define MAIN_INTENEVENTSADCSET_EVENTADCVSYSRDY_LOW (0x0UL) /*!< Low                                                          */
  #define MAIN_INTENEVENTSADCSET_EVENTADCVSYSRDY_HIGH (0x1UL) /*!< High                                                        */

/* EVENTADCVSET1RDY @Bit 4 : Writing 1 enables interrupts from EVENTADCVSET1RDY */
  #define MAIN_INTENEVENTSADCSET_EVENTADCVSET1RDY_Pos (4UL) /*!< Position of EVENTADCVSET1RDY field.                           */
  #define MAIN_INTENEVENTSADCSET_EVENTADCVSET1RDY_Msk (0x1UL << MAIN_INTENEVENTSADCSET_EVENTADCVSET1RDY_Pos) /*!< Bit mask of
                                                                            EVENTADCVSET1RDY field.*/                             
  #define MAIN_INTENEVENTSADCSET_EVENTADCVSET1RDY_Min (0x0UL) /*!< Min enumerator value of EVENTADCVSET1RDY field.             */
  #define MAIN_INTENEVENTSADCSET_EVENTADCVSET1RDY_Max (0x1UL) /*!< Max enumerator value of EVENTADCVSET1RDY field.             */
  #define MAIN_INTENEVENTSADCSET_EVENTADCVSET1RDY_LOW (0x0UL) /*!< Low                                                         */
  #define MAIN_INTENEVENTSADCSET_EVENTADCVSET1RDY_HIGH (0x1UL) /*!< High                                                       */

/* EVENTADCVSET2RDY @Bit 5 : Writing 1 enables interrupts from EVENTADCVSET2RDY */
  #define MAIN_INTENEVENTSADCSET_EVENTADCVSET2RDY_Pos (5UL) /*!< Position of EVENTADCVSET2RDY field.                           */
  #define MAIN_INTENEVENTSADCSET_EVENTADCVSET2RDY_Msk (0x1UL << MAIN_INTENEVENTSADCSET_EVENTADCVSET2RDY_Pos) /*!< Bit mask of
                                                                            EVENTADCVSET2RDY field.*/                             
  #define MAIN_INTENEVENTSADCSET_EVENTADCVSET2RDY_Min (0x0UL) /*!< Min enumerator value of EVENTADCVSET2RDY field.             */
  #define MAIN_INTENEVENTSADCSET_EVENTADCVSET2RDY_Max (0x1UL) /*!< Max enumerator value of EVENTADCVSET2RDY field.             */
  #define MAIN_INTENEVENTSADCSET_EVENTADCVSET2RDY_LOW (0x0UL) /*!< Low                                                         */
  #define MAIN_INTENEVENTSADCSET_EVENTADCVSET2RDY_HIGH (0x1UL) /*!< High                                                       */

/* EVENTADCIBATRDY @Bit 6 : Writing 1 enables interrupts from EVENTADCIBATRDY */
  #define MAIN_INTENEVENTSADCSET_EVENTADCIBATRDY_Pos (6UL) /*!< Position of EVENTADCIBATRDY field.                             */
  #define MAIN_INTENEVENTSADCSET_EVENTADCIBATRDY_Msk (0x1UL << MAIN_INTENEVENTSADCSET_EVENTADCIBATRDY_Pos) /*!< Bit mask of
                                                                            EVENTADCIBATRDY field.*/                              
  #define MAIN_INTENEVENTSADCSET_EVENTADCIBATRDY_Min (0x0UL) /*!< Min enumerator value of EVENTADCIBATRDY field.               */
  #define MAIN_INTENEVENTSADCSET_EVENTADCIBATRDY_Max (0x1UL) /*!< Max enumerator value of EVENTADCIBATRDY field.               */
  #define MAIN_INTENEVENTSADCSET_EVENTADCIBATRDY_LOW (0x0UL) /*!< Low                                                          */
  #define MAIN_INTENEVENTSADCSET_EVENTADCIBATRDY_HIGH (0x1UL) /*!< High                                                        */

/* EVENTADCVBUS7V0RDY @Bit 7 : Writing 1 enables interrupts from EVENTADCVBUS7V0RDY */
  #define MAIN_INTENEVENTSADCSET_EVENTADCVBUS7V0RDY_Pos (7UL) /*!< Position of EVENTADCVBUS7V0RDY field.                       */
  #define MAIN_INTENEVENTSADCSET_EVENTADCVBUS7V0RDY_Msk (0x1UL << MAIN_INTENEVENTSADCSET_EVENTADCVBUS7V0RDY_Pos) /*!< Bit mask
                                                                            of EVENTADCVBUS7V0RDY field.*/                        
  #define MAIN_INTENEVENTSADCSET_EVENTADCVBUS7V0RDY_Min (0x0UL) /*!< Min enumerator value of EVENTADCVBUS7V0RDY field.         */
  #define MAIN_INTENEVENTSADCSET_EVENTADCVBUS7V0RDY_Max (0x1UL) /*!< Max enumerator value of EVENTADCVBUS7V0RDY field.         */
  #define MAIN_INTENEVENTSADCSET_EVENTADCVBUS7V0RDY_LOW (0x0UL) /*!< Low                                                       */
  #define MAIN_INTENEVENTSADCSET_EVENTADCVBUS7V0RDY_HIGH (0x1UL) /*!< High                                                     */


/* MAIN_INTENEVENTSADCCLR: ADC Interrupt Enable Clear */
  #define MAIN_INTENEVENTSADCCLR_ResetValue (0x00UL) /*!< Reset value of INTENEVENTSADCCLR register.                           */

/* EVENTADCVBATRDY @Bit 0 : Writing 1 disables interrupts from EVENTADCVBATRDY */
  #define MAIN_INTENEVENTSADCCLR_EVENTADCVBATRDY_Pos (0UL) /*!< Position of EVENTADCVBATRDY field.                             */
  #define MAIN_INTENEVENTSADCCLR_EVENTADCVBATRDY_Msk (0x1UL << MAIN_INTENEVENTSADCCLR_EVENTADCVBATRDY_Pos) /*!< Bit mask of
                                                                            EVENTADCVBATRDY field.*/                              
  #define MAIN_INTENEVENTSADCCLR_EVENTADCVBATRDY_Min (0x0UL) /*!< Min enumerator value of EVENTADCVBATRDY field.               */
  #define MAIN_INTENEVENTSADCCLR_EVENTADCVBATRDY_Max (0x1UL) /*!< Max enumerator value of EVENTADCVBATRDY field.               */
  #define MAIN_INTENEVENTSADCCLR_EVENTADCVBATRDY_LOW (0x0UL) /*!< Low                                                          */
  #define MAIN_INTENEVENTSADCCLR_EVENTADCVBATRDY_HIGH (0x1UL) /*!< High                                                        */

/* EVENTADCNTCRDY @Bit 1 : Writing 1 disables interrupts from EVENTADCNTCRDY */
  #define MAIN_INTENEVENTSADCCLR_EVENTADCNTCRDY_Pos (1UL) /*!< Position of EVENTADCNTCRDY field.                               */
  #define MAIN_INTENEVENTSADCCLR_EVENTADCNTCRDY_Msk (0x1UL << MAIN_INTENEVENTSADCCLR_EVENTADCNTCRDY_Pos) /*!< Bit mask of
                                                                            EVENTADCNTCRDY field.*/                               
  #define MAIN_INTENEVENTSADCCLR_EVENTADCNTCRDY_Min (0x0UL) /*!< Min enumerator value of EVENTADCNTCRDY field.                 */
  #define MAIN_INTENEVENTSADCCLR_EVENTADCNTCRDY_Max (0x1UL) /*!< Max enumerator value of EVENTADCNTCRDY field.                 */
  #define MAIN_INTENEVENTSADCCLR_EVENTADCNTCRDY_LOW (0x0UL) /*!< Low                                                           */
  #define MAIN_INTENEVENTSADCCLR_EVENTADCNTCRDY_HIGH (0x1UL) /*!< High                                                         */

/* EVENTADCTEMPRDY @Bit 2 : Writing 1 disables interrupts from EVENTADCTEMPRDY */
  #define MAIN_INTENEVENTSADCCLR_EVENTADCTEMPRDY_Pos (2UL) /*!< Position of EVENTADCTEMPRDY field.                             */
  #define MAIN_INTENEVENTSADCCLR_EVENTADCTEMPRDY_Msk (0x1UL << MAIN_INTENEVENTSADCCLR_EVENTADCTEMPRDY_Pos) /*!< Bit mask of
                                                                            EVENTADCTEMPRDY field.*/                              
  #define MAIN_INTENEVENTSADCCLR_EVENTADCTEMPRDY_Min (0x0UL) /*!< Min enumerator value of EVENTADCTEMPRDY field.               */
  #define MAIN_INTENEVENTSADCCLR_EVENTADCTEMPRDY_Max (0x1UL) /*!< Max enumerator value of EVENTADCTEMPRDY field.               */
  #define MAIN_INTENEVENTSADCCLR_EVENTADCTEMPRDY_LOW (0x0UL) /*!< Low                                                          */
  #define MAIN_INTENEVENTSADCCLR_EVENTADCTEMPRDY_HIGH (0x1UL) /*!< High                                                        */

/* EVENTADCVSYSRDY @Bit 3 : Writing 1 disables interrupts from EVENTADCVSYSRDY */
  #define MAIN_INTENEVENTSADCCLR_EVENTADCVSYSRDY_Pos (3UL) /*!< Position of EVENTADCVSYSRDY field.                             */
  #define MAIN_INTENEVENTSADCCLR_EVENTADCVSYSRDY_Msk (0x1UL << MAIN_INTENEVENTSADCCLR_EVENTADCVSYSRDY_Pos) /*!< Bit mask of
                                                                            EVENTADCVSYSRDY field.*/                              
  #define MAIN_INTENEVENTSADCCLR_EVENTADCVSYSRDY_Min (0x0UL) /*!< Min enumerator value of EVENTADCVSYSRDY field.               */
  #define MAIN_INTENEVENTSADCCLR_EVENTADCVSYSRDY_Max (0x1UL) /*!< Max enumerator value of EVENTADCVSYSRDY field.               */
  #define MAIN_INTENEVENTSADCCLR_EVENTADCVSYSRDY_LOW (0x0UL) /*!< Low                                                          */
  #define MAIN_INTENEVENTSADCCLR_EVENTADCVSYSRDY_HIGH (0x1UL) /*!< High                                                        */

/* EVENTADCVSET1RDY @Bit 4 : Writing 1 disables interrupts from EVENTADCVSET1RDY */
  #define MAIN_INTENEVENTSADCCLR_EVENTADCVSET1RDY_Pos (4UL) /*!< Position of EVENTADCVSET1RDY field.                           */
  #define MAIN_INTENEVENTSADCCLR_EVENTADCVSET1RDY_Msk (0x1UL << MAIN_INTENEVENTSADCCLR_EVENTADCVSET1RDY_Pos) /*!< Bit mask of
                                                                            EVENTADCVSET1RDY field.*/                             
  #define MAIN_INTENEVENTSADCCLR_EVENTADCVSET1RDY_Min (0x0UL) /*!< Min enumerator value of EVENTADCVSET1RDY field.             */
  #define MAIN_INTENEVENTSADCCLR_EVENTADCVSET1RDY_Max (0x1UL) /*!< Max enumerator value of EVENTADCVSET1RDY field.             */
  #define MAIN_INTENEVENTSADCCLR_EVENTADCVSET1RDY_LOW (0x0UL) /*!< Low                                                         */
  #define MAIN_INTENEVENTSADCCLR_EVENTADCVSET1RDY_HIGH (0x1UL) /*!< High                                                       */

/* EVENTADCVSET2RDY @Bit 5 : Writing 1 disables interrupts from EVENTADCVSET2RDY */
  #define MAIN_INTENEVENTSADCCLR_EVENTADCVSET2RDY_Pos (5UL) /*!< Position of EVENTADCVSET2RDY field.                           */
  #define MAIN_INTENEVENTSADCCLR_EVENTADCVSET2RDY_Msk (0x1UL << MAIN_INTENEVENTSADCCLR_EVENTADCVSET2RDY_Pos) /*!< Bit mask of
                                                                            EVENTADCVSET2RDY field.*/                             
  #define MAIN_INTENEVENTSADCCLR_EVENTADCVSET2RDY_Min (0x0UL) /*!< Min enumerator value of EVENTADCVSET2RDY field.             */
  #define MAIN_INTENEVENTSADCCLR_EVENTADCVSET2RDY_Max (0x1UL) /*!< Max enumerator value of EVENTADCVSET2RDY field.             */
  #define MAIN_INTENEVENTSADCCLR_EVENTADCVSET2RDY_LOW (0x0UL) /*!< Low                                                         */
  #define MAIN_INTENEVENTSADCCLR_EVENTADCVSET2RDY_HIGH (0x1UL) /*!< High                                                       */

/* EVENTADCIBATRDY @Bit 6 : Writing 1 disables interrupts from EVENTADCIBATRDY */
  #define MAIN_INTENEVENTSADCCLR_EVENTADCIBATRDY_Pos (6UL) /*!< Position of EVENTADCIBATRDY field.                             */
  #define MAIN_INTENEVENTSADCCLR_EVENTADCIBATRDY_Msk (0x1UL << MAIN_INTENEVENTSADCCLR_EVENTADCIBATRDY_Pos) /*!< Bit mask of
                                                                            EVENTADCIBATRDY field.*/                              
  #define MAIN_INTENEVENTSADCCLR_EVENTADCIBATRDY_Min (0x0UL) /*!< Min enumerator value of EVENTADCIBATRDY field.               */
  #define MAIN_INTENEVENTSADCCLR_EVENTADCIBATRDY_Max (0x1UL) /*!< Max enumerator value of EVENTADCIBATRDY field.               */
  #define MAIN_INTENEVENTSADCCLR_EVENTADCIBATRDY_LOW (0x0UL) /*!< Low                                                          */
  #define MAIN_INTENEVENTSADCCLR_EVENTADCIBATRDY_HIGH (0x1UL) /*!< High                                                        */

/* EVENTADCVBUS7V0RDY @Bit 7 : Writing 1 disables interrupts from EVENTADCVBUS7V0RDY */
  #define MAIN_INTENEVENTSADCCLR_EVENTADCVBUS7V0RDY_Pos (7UL) /*!< Position of EVENTADCVBUS7V0RDY field.                       */
  #define MAIN_INTENEVENTSADCCLR_EVENTADCVBUS7V0RDY_Msk (0x1UL << MAIN_INTENEVENTSADCCLR_EVENTADCVBUS7V0RDY_Pos) /*!< Bit mask
                                                                            of EVENTADCVBUS7V0RDY field.*/                        
  #define MAIN_INTENEVENTSADCCLR_EVENTADCVBUS7V0RDY_Min (0x0UL) /*!< Min enumerator value of EVENTADCVBUS7V0RDY field.         */
  #define MAIN_INTENEVENTSADCCLR_EVENTADCVBUS7V0RDY_Max (0x1UL) /*!< Max enumerator value of EVENTADCVBUS7V0RDY field.         */
  #define MAIN_INTENEVENTSADCCLR_EVENTADCVBUS7V0RDY_LOW (0x0UL) /*!< Low                                                       */
  #define MAIN_INTENEVENTSADCCLR_EVENTADCVBUS7V0RDY_HIGH (0x1UL) /*!< High                                                     */


/* MAIN_EVENTSBCHARGER0SET: Battery temperature region and die temperature Event Set */
  #define MAIN_EVENTSBCHARGER0SET_ResetValue (0x00UL) /*!< Reset value of EVENTSBCHARGER0SET register.                         */

/* EVENTNTCCOLD @Bit 0 : Battery temperature in cold region. Writing 1 sets the event (for debugging). */
  #define MAIN_EVENTSBCHARGER0SET_EVENTNTCCOLD_Pos (0UL) /*!< Position of EVENTNTCCOLD field.                                  */
  #define MAIN_EVENTSBCHARGER0SET_EVENTNTCCOLD_Msk (0x1UL << MAIN_EVENTSBCHARGER0SET_EVENTNTCCOLD_Pos) /*!< Bit mask of
                                                                            EVENTNTCCOLD field.*/                                 
  #define MAIN_EVENTSBCHARGER0SET_EVENTNTCCOLD_Min (0x0UL) /*!< Min enumerator value of EVENTNTCCOLD field.                    */
  #define MAIN_EVENTSBCHARGER0SET_EVENTNTCCOLD_Max (0x1UL) /*!< Max enumerator value of EVENTNTCCOLD field.                    */
  #define MAIN_EVENTSBCHARGER0SET_EVENTNTCCOLD_LOW (0x0UL) /*!< Low                                                            */
  #define MAIN_EVENTSBCHARGER0SET_EVENTNTCCOLD_HIGH (0x1UL) /*!< High                                                          */

/* EVENTNTCCOOL @Bit 1 : Battery temperature in cool region. Writing 1 sets the event (for debugging). */
  #define MAIN_EVENTSBCHARGER0SET_EVENTNTCCOOL_Pos (1UL) /*!< Position of EVENTNTCCOOL field.                                  */
  #define MAIN_EVENTSBCHARGER0SET_EVENTNTCCOOL_Msk (0x1UL << MAIN_EVENTSBCHARGER0SET_EVENTNTCCOOL_Pos) /*!< Bit mask of
                                                                            EVENTNTCCOOL field.*/                                 
  #define MAIN_EVENTSBCHARGER0SET_EVENTNTCCOOL_Min (0x0UL) /*!< Min enumerator value of EVENTNTCCOOL field.                    */
  #define MAIN_EVENTSBCHARGER0SET_EVENTNTCCOOL_Max (0x1UL) /*!< Max enumerator value of EVENTNTCCOOL field.                    */
  #define MAIN_EVENTSBCHARGER0SET_EVENTNTCCOOL_LOW (0x0UL) /*!< Low                                                            */
  #define MAIN_EVENTSBCHARGER0SET_EVENTNTCCOOL_HIGH (0x1UL) /*!< High                                                          */

/* EVENTNTCWARM @Bit 2 : Battery temperature in warm region. Writing 1 sets the event (for debugging). */
  #define MAIN_EVENTSBCHARGER0SET_EVENTNTCWARM_Pos (2UL) /*!< Position of EVENTNTCWARM field.                                  */
  #define MAIN_EVENTSBCHARGER0SET_EVENTNTCWARM_Msk (0x1UL << MAIN_EVENTSBCHARGER0SET_EVENTNTCWARM_Pos) /*!< Bit mask of
                                                                            EVENTNTCWARM field.*/                                 
  #define MAIN_EVENTSBCHARGER0SET_EVENTNTCWARM_Min (0x0UL) /*!< Min enumerator value of EVENTNTCWARM field.                    */
  #define MAIN_EVENTSBCHARGER0SET_EVENTNTCWARM_Max (0x1UL) /*!< Max enumerator value of EVENTNTCWARM field.                    */
  #define MAIN_EVENTSBCHARGER0SET_EVENTNTCWARM_LOW (0x0UL) /*!< Low                                                            */
  #define MAIN_EVENTSBCHARGER0SET_EVENTNTCWARM_HIGH (0x1UL) /*!< High                                                          */

/* EVENTNTCHOT @Bit 3 : Battery temperature in hot region. Writing 1 sets the event (for debugging). */
  #define MAIN_EVENTSBCHARGER0SET_EVENTNTCHOT_Pos (3UL) /*!< Position of EVENTNTCHOT field.                                    */
  #define MAIN_EVENTSBCHARGER0SET_EVENTNTCHOT_Msk (0x1UL << MAIN_EVENTSBCHARGER0SET_EVENTNTCHOT_Pos) /*!< Bit mask of
                                                                            EVENTNTCHOT field.*/                                  
  #define MAIN_EVENTSBCHARGER0SET_EVENTNTCHOT_Min (0x0UL) /*!< Min enumerator value of EVENTNTCHOT field.                      */
  #define MAIN_EVENTSBCHARGER0SET_EVENTNTCHOT_Max (0x1UL) /*!< Max enumerator value of EVENTNTCHOT field.                      */
  #define MAIN_EVENTSBCHARGER0SET_EVENTNTCHOT_LOW (0x0UL) /*!< Low                                                             */
  #define MAIN_EVENTSBCHARGER0SET_EVENTNTCHOT_HIGH (0x1UL) /*!< High                                                           */

/* EVENTDIETEMPHIGH @Bit 4 : Die temperature is over TCHGSTOP. Charging stops. Writing 1 sets the event (for debugging). */
  #define MAIN_EVENTSBCHARGER0SET_EVENTDIETEMPHIGH_Pos (4UL) /*!< Position of EVENTDIETEMPHIGH field.                          */
  #define MAIN_EVENTSBCHARGER0SET_EVENTDIETEMPHIGH_Msk (0x1UL << MAIN_EVENTSBCHARGER0SET_EVENTDIETEMPHIGH_Pos) /*!< Bit mask of
                                                                            EVENTDIETEMPHIGH field.*/                             
  #define MAIN_EVENTSBCHARGER0SET_EVENTDIETEMPHIGH_Min (0x0UL) /*!< Min enumerator value of EVENTDIETEMPHIGH field.            */
  #define MAIN_EVENTSBCHARGER0SET_EVENTDIETEMPHIGH_Max (0x1UL) /*!< Max enumerator value of EVENTDIETEMPHIGH field.            */
  #define MAIN_EVENTSBCHARGER0SET_EVENTDIETEMPHIGH_LOW (0x0UL) /*!< Low                                                        */
  #define MAIN_EVENTSBCHARGER0SET_EVENTDIETEMPHIGH_HIGH (0x1UL) /*!< High                                                      */

/* EVENTDIETEMPRESUME @Bit 5 : Die temperature is under TCHGRESUME. Charging resumes. Writing 1 sets the event (for debugging).
                               */                                                                                                 
                                                                                                                                  
  #define MAIN_EVENTSBCHARGER0SET_EVENTDIETEMPRESUME_Pos (5UL) /*!< Position of EVENTDIETEMPRESUME field.                      */
  #define MAIN_EVENTSBCHARGER0SET_EVENTDIETEMPRESUME_Msk (0x1UL << MAIN_EVENTSBCHARGER0SET_EVENTDIETEMPRESUME_Pos) /*!< Bit mask
                                                                            of EVENTDIETEMPRESUME field.*/                        
  #define MAIN_EVENTSBCHARGER0SET_EVENTDIETEMPRESUME_Min (0x0UL) /*!< Min enumerator value of EVENTDIETEMPRESUME field.        */
  #define MAIN_EVENTSBCHARGER0SET_EVENTDIETEMPRESUME_Max (0x1UL) /*!< Max enumerator value of EVENTDIETEMPRESUME field.        */
  #define MAIN_EVENTSBCHARGER0SET_EVENTDIETEMPRESUME_LOW (0x0UL) /*!< Low                                                      */
  #define MAIN_EVENTSBCHARGER0SET_EVENTDIETEMPRESUME_HIGH (0x1UL) /*!< High                                                    */


/* MAIN_EVENTSBCHARGER0CLR: Battery temperature region and die temperature Event Clear */
  #define MAIN_EVENTSBCHARGER0CLR_ResetValue (0x00UL) /*!< Reset value of EVENTSBCHARGER0CLR register.                         */

/* EVENTNTCCOLD @Bit 0 : Battery temperature in cold region. Writing 1 clears the event (e.g. to acknowledge an interrupt). */
  #define MAIN_EVENTSBCHARGER0CLR_EVENTNTCCOLD_Pos (0UL) /*!< Position of EVENTNTCCOLD field.                                  */
  #define MAIN_EVENTSBCHARGER0CLR_EVENTNTCCOLD_Msk (0x1UL << MAIN_EVENTSBCHARGER0CLR_EVENTNTCCOLD_Pos) /*!< Bit mask of
                                                                            EVENTNTCCOLD field.*/                                 
  #define MAIN_EVENTSBCHARGER0CLR_EVENTNTCCOLD_Min (0x0UL) /*!< Min enumerator value of EVENTNTCCOLD field.                    */
  #define MAIN_EVENTSBCHARGER0CLR_EVENTNTCCOLD_Max (0x1UL) /*!< Max enumerator value of EVENTNTCCOLD field.                    */
  #define MAIN_EVENTSBCHARGER0CLR_EVENTNTCCOLD_LOW (0x0UL) /*!< Low                                                            */
  #define MAIN_EVENTSBCHARGER0CLR_EVENTNTCCOLD_HIGH (0x1UL) /*!< High                                                          */

/* EVENTNTCCOOL @Bit 1 : Battery temperature in cool region. Writing 1 clears the event (e.g. to acknowledge an interrupt). */
  #define MAIN_EVENTSBCHARGER0CLR_EVENTNTCCOOL_Pos (1UL) /*!< Position of EVENTNTCCOOL field.                                  */
  #define MAIN_EVENTSBCHARGER0CLR_EVENTNTCCOOL_Msk (0x1UL << MAIN_EVENTSBCHARGER0CLR_EVENTNTCCOOL_Pos) /*!< Bit mask of
                                                                            EVENTNTCCOOL field.*/                                 
  #define MAIN_EVENTSBCHARGER0CLR_EVENTNTCCOOL_Min (0x0UL) /*!< Min enumerator value of EVENTNTCCOOL field.                    */
  #define MAIN_EVENTSBCHARGER0CLR_EVENTNTCCOOL_Max (0x1UL) /*!< Max enumerator value of EVENTNTCCOOL field.                    */
  #define MAIN_EVENTSBCHARGER0CLR_EVENTNTCCOOL_LOW (0x0UL) /*!< Low                                                            */
  #define MAIN_EVENTSBCHARGER0CLR_EVENTNTCCOOL_HIGH (0x1UL) /*!< High                                                          */

/* EVENTNTCWARM @Bit 2 : Battery temperature in warm region. Writing 1 clears the event (e.g. to acknowledge an interrupt). */
  #define MAIN_EVENTSBCHARGER0CLR_EVENTNTCWARM_Pos (2UL) /*!< Position of EVENTNTCWARM field.                                  */
  #define MAIN_EVENTSBCHARGER0CLR_EVENTNTCWARM_Msk (0x1UL << MAIN_EVENTSBCHARGER0CLR_EVENTNTCWARM_Pos) /*!< Bit mask of
                                                                            EVENTNTCWARM field.*/                                 
  #define MAIN_EVENTSBCHARGER0CLR_EVENTNTCWARM_Min (0x0UL) /*!< Min enumerator value of EVENTNTCWARM field.                    */
  #define MAIN_EVENTSBCHARGER0CLR_EVENTNTCWARM_Max (0x1UL) /*!< Max enumerator value of EVENTNTCWARM field.                    */
  #define MAIN_EVENTSBCHARGER0CLR_EVENTNTCWARM_LOW (0x0UL) /*!< Low                                                            */
  #define MAIN_EVENTSBCHARGER0CLR_EVENTNTCWARM_HIGH (0x1UL) /*!< High                                                          */

/* EVENTNTCHOT @Bit 3 : Battery temperature in hot region. Writing 1 clears the event (e.g. to acknowledge an interrupt). */
  #define MAIN_EVENTSBCHARGER0CLR_EVENTNTCHOT_Pos (3UL) /*!< Position of EVENTNTCHOT field.                                    */
  #define MAIN_EVENTSBCHARGER0CLR_EVENTNTCHOT_Msk (0x1UL << MAIN_EVENTSBCHARGER0CLR_EVENTNTCHOT_Pos) /*!< Bit mask of
                                                                            EVENTNTCHOT field.*/                                  
  #define MAIN_EVENTSBCHARGER0CLR_EVENTNTCHOT_Min (0x0UL) /*!< Min enumerator value of EVENTNTCHOT field.                      */
  #define MAIN_EVENTSBCHARGER0CLR_EVENTNTCHOT_Max (0x1UL) /*!< Max enumerator value of EVENTNTCHOT field.                      */
  #define MAIN_EVENTSBCHARGER0CLR_EVENTNTCHOT_LOW (0x0UL) /*!< Low                                                             */
  #define MAIN_EVENTSBCHARGER0CLR_EVENTNTCHOT_HIGH (0x1UL) /*!< High                                                           */

/* EVENTDIETEMPHIGH @Bit 4 : Die temperature is over TCHGSTOP. Charging stops. Writing 1 clears the event (e.g. to acknowledge
                             an interrupt). */                                                                                    
                                                                                                                                  
  #define MAIN_EVENTSBCHARGER0CLR_EVENTDIETEMPHIGH_Pos (4UL) /*!< Position of EVENTDIETEMPHIGH field.                          */
  #define MAIN_EVENTSBCHARGER0CLR_EVENTDIETEMPHIGH_Msk (0x1UL << MAIN_EVENTSBCHARGER0CLR_EVENTDIETEMPHIGH_Pos) /*!< Bit mask of
                                                                            EVENTDIETEMPHIGH field.*/                             
  #define MAIN_EVENTSBCHARGER0CLR_EVENTDIETEMPHIGH_Min (0x0UL) /*!< Min enumerator value of EVENTDIETEMPHIGH field.            */
  #define MAIN_EVENTSBCHARGER0CLR_EVENTDIETEMPHIGH_Max (0x1UL) /*!< Max enumerator value of EVENTDIETEMPHIGH field.            */
  #define MAIN_EVENTSBCHARGER0CLR_EVENTDIETEMPHIGH_LOW (0x0UL) /*!< Low                                                        */
  #define MAIN_EVENTSBCHARGER0CLR_EVENTDIETEMPHIGH_HIGH (0x1UL) /*!< High                                                      */

/* EVENTDIETEMPRESUME @Bit 5 : Die temperature is under TCHGRESUME. Charging resumes. Writing 1 clears the event (e.g. to
                               acknowledge an interrupt). */                                                                      
                                                                                                                                  
  #define MAIN_EVENTSBCHARGER0CLR_EVENTDIETEMPRESUME_Pos (5UL) /*!< Position of EVENTDIETEMPRESUME field.                      */
  #define MAIN_EVENTSBCHARGER0CLR_EVENTDIETEMPRESUME_Msk (0x1UL << MAIN_EVENTSBCHARGER0CLR_EVENTDIETEMPRESUME_Pos) /*!< Bit mask
                                                                            of EVENTDIETEMPRESUME field.*/                        
  #define MAIN_EVENTSBCHARGER0CLR_EVENTDIETEMPRESUME_Min (0x0UL) /*!< Min enumerator value of EVENTDIETEMPRESUME field.        */
  #define MAIN_EVENTSBCHARGER0CLR_EVENTDIETEMPRESUME_Max (0x1UL) /*!< Max enumerator value of EVENTDIETEMPRESUME field.        */
  #define MAIN_EVENTSBCHARGER0CLR_EVENTDIETEMPRESUME_LOW (0x0UL) /*!< Low                                                      */
  #define MAIN_EVENTSBCHARGER0CLR_EVENTDIETEMPRESUME_HIGH (0x1UL) /*!< High                                                    */


/* MAIN_INTENEVENTSBCHARGER0SET: Battery temperature region and die temperature Interrupt Enable Set */
  #define MAIN_INTENEVENTSBCHARGER0SET_ResetValue (0x00UL) /*!< Reset value of INTENEVENTSBCHARGER0SET register.               */

/* EVENTNTCCOLD @Bit 0 : Writing 1 enables interrupts from EVENTNTCCOLD */
  #define MAIN_INTENEVENTSBCHARGER0SET_EVENTNTCCOLD_Pos (0UL) /*!< Position of EVENTNTCCOLD field.                             */
  #define MAIN_INTENEVENTSBCHARGER0SET_EVENTNTCCOLD_Msk (0x1UL << MAIN_INTENEVENTSBCHARGER0SET_EVENTNTCCOLD_Pos) /*!< Bit mask
                                                                            of EVENTNTCCOLD field.*/                              
  #define MAIN_INTENEVENTSBCHARGER0SET_EVENTNTCCOLD_Min (0x0UL) /*!< Min enumerator value of EVENTNTCCOLD field.               */
  #define MAIN_INTENEVENTSBCHARGER0SET_EVENTNTCCOLD_Max (0x1UL) /*!< Max enumerator value of EVENTNTCCOLD field.               */
  #define MAIN_INTENEVENTSBCHARGER0SET_EVENTNTCCOLD_LOW (0x0UL) /*!< Low                                                       */
  #define MAIN_INTENEVENTSBCHARGER0SET_EVENTNTCCOLD_HIGH (0x1UL) /*!< High                                                     */

/* EVENTNTCCOOL @Bit 1 : Writing 1 enables interrupts from EVENTNTCCOOL */
  #define MAIN_INTENEVENTSBCHARGER0SET_EVENTNTCCOOL_Pos (1UL) /*!< Position of EVENTNTCCOOL field.                             */
  #define MAIN_INTENEVENTSBCHARGER0SET_EVENTNTCCOOL_Msk (0x1UL << MAIN_INTENEVENTSBCHARGER0SET_EVENTNTCCOOL_Pos) /*!< Bit mask
                                                                            of EVENTNTCCOOL field.*/                              
  #define MAIN_INTENEVENTSBCHARGER0SET_EVENTNTCCOOL_Min (0x0UL) /*!< Min enumerator value of EVENTNTCCOOL field.               */
  #define MAIN_INTENEVENTSBCHARGER0SET_EVENTNTCCOOL_Max (0x1UL) /*!< Max enumerator value of EVENTNTCCOOL field.               */
  #define MAIN_INTENEVENTSBCHARGER0SET_EVENTNTCCOOL_LOW (0x0UL) /*!< Low                                                       */
  #define MAIN_INTENEVENTSBCHARGER0SET_EVENTNTCCOOL_HIGH (0x1UL) /*!< High                                                     */

/* EVENTNTCWARM @Bit 2 : Writing 1 enables interrupts from EVENTNTCWARM */
  #define MAIN_INTENEVENTSBCHARGER0SET_EVENTNTCWARM_Pos (2UL) /*!< Position of EVENTNTCWARM field.                             */
  #define MAIN_INTENEVENTSBCHARGER0SET_EVENTNTCWARM_Msk (0x1UL << MAIN_INTENEVENTSBCHARGER0SET_EVENTNTCWARM_Pos) /*!< Bit mask
                                                                            of EVENTNTCWARM field.*/                              
  #define MAIN_INTENEVENTSBCHARGER0SET_EVENTNTCWARM_Min (0x0UL) /*!< Min enumerator value of EVENTNTCWARM field.               */
  #define MAIN_INTENEVENTSBCHARGER0SET_EVENTNTCWARM_Max (0x1UL) /*!< Max enumerator value of EVENTNTCWARM field.               */
  #define MAIN_INTENEVENTSBCHARGER0SET_EVENTNTCWARM_LOW (0x0UL) /*!< Low                                                       */
  #define MAIN_INTENEVENTSBCHARGER0SET_EVENTNTCWARM_HIGH (0x1UL) /*!< High                                                     */

/* EVENTNTCHOT @Bit 3 : Writing 1 enables interrupts from EVENTNTCHOT */
  #define MAIN_INTENEVENTSBCHARGER0SET_EVENTNTCHOT_Pos (3UL) /*!< Position of EVENTNTCHOT field.                               */
  #define MAIN_INTENEVENTSBCHARGER0SET_EVENTNTCHOT_Msk (0x1UL << MAIN_INTENEVENTSBCHARGER0SET_EVENTNTCHOT_Pos) /*!< Bit mask of
                                                                            EVENTNTCHOT field.*/                                  
  #define MAIN_INTENEVENTSBCHARGER0SET_EVENTNTCHOT_Min (0x0UL) /*!< Min enumerator value of EVENTNTCHOT field.                 */
  #define MAIN_INTENEVENTSBCHARGER0SET_EVENTNTCHOT_Max (0x1UL) /*!< Max enumerator value of EVENTNTCHOT field.                 */
  #define MAIN_INTENEVENTSBCHARGER0SET_EVENTNTCHOT_LOW (0x0UL) /*!< Low                                                        */
  #define MAIN_INTENEVENTSBCHARGER0SET_EVENTNTCHOT_HIGH (0x1UL) /*!< High                                                      */

/* EVENTDIETEMPHIGH @Bit 4 : Writing 1 enables interrupts from EVENTDIETEMPHIGH */
  #define MAIN_INTENEVENTSBCHARGER0SET_EVENTDIETEMPHIGH_Pos (4UL) /*!< Position of EVENTDIETEMPHIGH field.                     */
  #define MAIN_INTENEVENTSBCHARGER0SET_EVENTDIETEMPHIGH_Msk (0x1UL << MAIN_INTENEVENTSBCHARGER0SET_EVENTDIETEMPHIGH_Pos) /*!<
                                                                            Bit mask of EVENTDIETEMPHIGH field.*/                 
  #define MAIN_INTENEVENTSBCHARGER0SET_EVENTDIETEMPHIGH_Min (0x0UL) /*!< Min enumerator value of EVENTDIETEMPHIGH field.       */
  #define MAIN_INTENEVENTSBCHARGER0SET_EVENTDIETEMPHIGH_Max (0x1UL) /*!< Max enumerator value of EVENTDIETEMPHIGH field.       */
  #define MAIN_INTENEVENTSBCHARGER0SET_EVENTDIETEMPHIGH_LOW (0x0UL) /*!< Low                                                   */
  #define MAIN_INTENEVENTSBCHARGER0SET_EVENTDIETEMPHIGH_HIGH (0x1UL) /*!< High                                                 */

/* EVENTDIETEMPRESUME @Bit 5 : Writing 1 enables interrupts from EVENTDIETEMPRESUME */
  #define MAIN_INTENEVENTSBCHARGER0SET_EVENTDIETEMPRESUME_Pos (5UL) /*!< Position of EVENTDIETEMPRESUME field.                 */
  #define MAIN_INTENEVENTSBCHARGER0SET_EVENTDIETEMPRESUME_Msk (0x1UL << MAIN_INTENEVENTSBCHARGER0SET_EVENTDIETEMPRESUME_Pos)
                                                                            /*!< Bit mask of EVENTDIETEMPRESUME field.*/          
  #define MAIN_INTENEVENTSBCHARGER0SET_EVENTDIETEMPRESUME_Min (0x0UL) /*!< Min enumerator value of EVENTDIETEMPRESUME field.   */
  #define MAIN_INTENEVENTSBCHARGER0SET_EVENTDIETEMPRESUME_Max (0x1UL) /*!< Max enumerator value of EVENTDIETEMPRESUME field.   */
  #define MAIN_INTENEVENTSBCHARGER0SET_EVENTDIETEMPRESUME_LOW (0x0UL) /*!< Low                                                 */
  #define MAIN_INTENEVENTSBCHARGER0SET_EVENTDIETEMPRESUME_HIGH (0x1UL) /*!< High                                               */


/* MAIN_INTENEVENTSBCHARGER0CLR: Battery temperature region and die temperature Interrupt Enable Clear */
  #define MAIN_INTENEVENTSBCHARGER0CLR_ResetValue (0x00UL) /*!< Reset value of INTENEVENTSBCHARGER0CLR register.               */

/* EVENTNTCCOLD @Bit 0 : Writing 1 disables interrupts from EVENTNTCCOLD */
  #define MAIN_INTENEVENTSBCHARGER0CLR_EVENTNTCCOLD_Pos (0UL) /*!< Position of EVENTNTCCOLD field.                             */
  #define MAIN_INTENEVENTSBCHARGER0CLR_EVENTNTCCOLD_Msk (0x1UL << MAIN_INTENEVENTSBCHARGER0CLR_EVENTNTCCOLD_Pos) /*!< Bit mask
                                                                            of EVENTNTCCOLD field.*/                              
  #define MAIN_INTENEVENTSBCHARGER0CLR_EVENTNTCCOLD_Min (0x0UL) /*!< Min enumerator value of EVENTNTCCOLD field.               */
  #define MAIN_INTENEVENTSBCHARGER0CLR_EVENTNTCCOLD_Max (0x1UL) /*!< Max enumerator value of EVENTNTCCOLD field.               */
  #define MAIN_INTENEVENTSBCHARGER0CLR_EVENTNTCCOLD_LOW (0x0UL) /*!< Low                                                       */
  #define MAIN_INTENEVENTSBCHARGER0CLR_EVENTNTCCOLD_HIGH (0x1UL) /*!< High                                                     */

/* EVENTNTCCOOL @Bit 1 : Writing 1 disables interrupts from EVENTNTCCOOL */
  #define MAIN_INTENEVENTSBCHARGER0CLR_EVENTNTCCOOL_Pos (1UL) /*!< Position of EVENTNTCCOOL field.                             */
  #define MAIN_INTENEVENTSBCHARGER0CLR_EVENTNTCCOOL_Msk (0x1UL << MAIN_INTENEVENTSBCHARGER0CLR_EVENTNTCCOOL_Pos) /*!< Bit mask
                                                                            of EVENTNTCCOOL field.*/                              
  #define MAIN_INTENEVENTSBCHARGER0CLR_EVENTNTCCOOL_Min (0x0UL) /*!< Min enumerator value of EVENTNTCCOOL field.               */
  #define MAIN_INTENEVENTSBCHARGER0CLR_EVENTNTCCOOL_Max (0x1UL) /*!< Max enumerator value of EVENTNTCCOOL field.               */
  #define MAIN_INTENEVENTSBCHARGER0CLR_EVENTNTCCOOL_LOW (0x0UL) /*!< Low                                                       */
  #define MAIN_INTENEVENTSBCHARGER0CLR_EVENTNTCCOOL_HIGH (0x1UL) /*!< High                                                     */

/* EVENTNTCWARM @Bit 2 : Writing 1 disables interrupts from EVENTNTCWARM */
  #define MAIN_INTENEVENTSBCHARGER0CLR_EVENTNTCWARM_Pos (2UL) /*!< Position of EVENTNTCWARM field.                             */
  #define MAIN_INTENEVENTSBCHARGER0CLR_EVENTNTCWARM_Msk (0x1UL << MAIN_INTENEVENTSBCHARGER0CLR_EVENTNTCWARM_Pos) /*!< Bit mask
                                                                            of EVENTNTCWARM field.*/                              
  #define MAIN_INTENEVENTSBCHARGER0CLR_EVENTNTCWARM_Min (0x0UL) /*!< Min enumerator value of EVENTNTCWARM field.               */
  #define MAIN_INTENEVENTSBCHARGER0CLR_EVENTNTCWARM_Max (0x1UL) /*!< Max enumerator value of EVENTNTCWARM field.               */
  #define MAIN_INTENEVENTSBCHARGER0CLR_EVENTNTCWARM_LOW (0x0UL) /*!< Low                                                       */
  #define MAIN_INTENEVENTSBCHARGER0CLR_EVENTNTCWARM_HIGH (0x1UL) /*!< High                                                     */

/* EVENTNTCHOT @Bit 3 : Writing 1 disables interrupts from EVENTNTCHOT */
  #define MAIN_INTENEVENTSBCHARGER0CLR_EVENTNTCHOT_Pos (3UL) /*!< Position of EVENTNTCHOT field.                               */
  #define MAIN_INTENEVENTSBCHARGER0CLR_EVENTNTCHOT_Msk (0x1UL << MAIN_INTENEVENTSBCHARGER0CLR_EVENTNTCHOT_Pos) /*!< Bit mask of
                                                                            EVENTNTCHOT field.*/                                  
  #define MAIN_INTENEVENTSBCHARGER0CLR_EVENTNTCHOT_Min (0x0UL) /*!< Min enumerator value of EVENTNTCHOT field.                 */
  #define MAIN_INTENEVENTSBCHARGER0CLR_EVENTNTCHOT_Max (0x1UL) /*!< Max enumerator value of EVENTNTCHOT field.                 */
  #define MAIN_INTENEVENTSBCHARGER0CLR_EVENTNTCHOT_LOW (0x0UL) /*!< Low                                                        */
  #define MAIN_INTENEVENTSBCHARGER0CLR_EVENTNTCHOT_HIGH (0x1UL) /*!< High                                                      */

/* EVENTDIETEMPHIGH @Bit 4 : Writing 1 disables interrupts from EVENTDIETEMPHIGH */
  #define MAIN_INTENEVENTSBCHARGER0CLR_EVENTDIETEMPHIGH_Pos (4UL) /*!< Position of EVENTDIETEMPHIGH field.                     */
  #define MAIN_INTENEVENTSBCHARGER0CLR_EVENTDIETEMPHIGH_Msk (0x1UL << MAIN_INTENEVENTSBCHARGER0CLR_EVENTDIETEMPHIGH_Pos) /*!<
                                                                            Bit mask of EVENTDIETEMPHIGH field.*/                 
  #define MAIN_INTENEVENTSBCHARGER0CLR_EVENTDIETEMPHIGH_Min (0x0UL) /*!< Min enumerator value of EVENTDIETEMPHIGH field.       */
  #define MAIN_INTENEVENTSBCHARGER0CLR_EVENTDIETEMPHIGH_Max (0x1UL) /*!< Max enumerator value of EVENTDIETEMPHIGH field.       */
  #define MAIN_INTENEVENTSBCHARGER0CLR_EVENTDIETEMPHIGH_LOW (0x0UL) /*!< Low                                                   */
  #define MAIN_INTENEVENTSBCHARGER0CLR_EVENTDIETEMPHIGH_HIGH (0x1UL) /*!< High                                                 */

/* EVENTDIETEMPRESUME @Bit 5 : Writing 1 disables interrupts from EVENTDIETEMPRESUME */
  #define MAIN_INTENEVENTSBCHARGER0CLR_EVENTDIETEMPRESUME_Pos (5UL) /*!< Position of EVENTDIETEMPRESUME field.                 */
  #define MAIN_INTENEVENTSBCHARGER0CLR_EVENTDIETEMPRESUME_Msk (0x1UL << MAIN_INTENEVENTSBCHARGER0CLR_EVENTDIETEMPRESUME_Pos)
                                                                            /*!< Bit mask of EVENTDIETEMPRESUME field.*/          
  #define MAIN_INTENEVENTSBCHARGER0CLR_EVENTDIETEMPRESUME_Min (0x0UL) /*!< Min enumerator value of EVENTDIETEMPRESUME field.   */
  #define MAIN_INTENEVENTSBCHARGER0CLR_EVENTDIETEMPRESUME_Max (0x1UL) /*!< Max enumerator value of EVENTDIETEMPRESUME field.   */
  #define MAIN_INTENEVENTSBCHARGER0CLR_EVENTDIETEMPRESUME_LOW (0x0UL) /*!< Low                                                 */
  #define MAIN_INTENEVENTSBCHARGER0CLR_EVENTDIETEMPRESUME_HIGH (0x1UL) /*!< High                                               */


/* MAIN_EVENTSBCHARGER1SET: Charger Event Set */
  #define MAIN_EVENTSBCHARGER1SET_ResetValue (0x00UL) /*!< Reset value of EVENTSBCHARGER1SET register.                         */

/* EVENTSUPPLEMENT @Bit 0 : Supplement mode activated. Writing 1 sets the event (for debugging). */
  #define MAIN_EVENTSBCHARGER1SET_EVENTSUPPLEMENT_Pos (0UL) /*!< Position of EVENTSUPPLEMENT field.                            */
  #define MAIN_EVENTSBCHARGER1SET_EVENTSUPPLEMENT_Msk (0x1UL << MAIN_EVENTSBCHARGER1SET_EVENTSUPPLEMENT_Pos) /*!< Bit mask of
                                                                            EVENTSUPPLEMENT field.*/                              
  #define MAIN_EVENTSBCHARGER1SET_EVENTSUPPLEMENT_Min (0x0UL) /*!< Min enumerator value of EVENTSUPPLEMENT field.              */
  #define MAIN_EVENTSBCHARGER1SET_EVENTSUPPLEMENT_Max (0x1UL) /*!< Max enumerator value of EVENTSUPPLEMENT field.              */
  #define MAIN_EVENTSBCHARGER1SET_EVENTSUPPLEMENT_LOW (0x0UL) /*!< Low                                                         */
  #define MAIN_EVENTSBCHARGER1SET_EVENTSUPPLEMENT_HIGH (0x1UL) /*!< High                                                       */

/* EVENTCHGTRICKLE @Bit 1 : Tickle charge started. Writing 1 sets the event (for debugging). */
  #define MAIN_EVENTSBCHARGER1SET_EVENTCHGTRICKLE_Pos (1UL) /*!< Position of EVENTCHGTRICKLE field.                            */
  #define MAIN_EVENTSBCHARGER1SET_EVENTCHGTRICKLE_Msk (0x1UL << MAIN_EVENTSBCHARGER1SET_EVENTCHGTRICKLE_Pos) /*!< Bit mask of
                                                                            EVENTCHGTRICKLE field.*/                              
  #define MAIN_EVENTSBCHARGER1SET_EVENTCHGTRICKLE_Min (0x0UL) /*!< Min enumerator value of EVENTCHGTRICKLE field.              */
  #define MAIN_EVENTSBCHARGER1SET_EVENTCHGTRICKLE_Max (0x1UL) /*!< Max enumerator value of EVENTCHGTRICKLE field.              */
  #define MAIN_EVENTSBCHARGER1SET_EVENTCHGTRICKLE_LOW (0x0UL) /*!< Low                                                         */
  #define MAIN_EVENTSBCHARGER1SET_EVENTCHGTRICKLE_HIGH (0x1UL) /*!< High                                                       */

/* EVENTCHGCC @Bit 2 : Constant current charging started. Writing 1 sets the event (for debugging). */
  #define MAIN_EVENTSBCHARGER1SET_EVENTCHGCC_Pos (2UL) /*!< Position of EVENTCHGCC field.                                      */
  #define MAIN_EVENTSBCHARGER1SET_EVENTCHGCC_Msk (0x1UL << MAIN_EVENTSBCHARGER1SET_EVENTCHGCC_Pos) /*!< Bit mask of EVENTCHGCC
                                                                            field.*/                                              
  #define MAIN_EVENTSBCHARGER1SET_EVENTCHGCC_Min (0x0UL) /*!< Min enumerator value of EVENTCHGCC field.                        */
  #define MAIN_EVENTSBCHARGER1SET_EVENTCHGCC_Max (0x1UL) /*!< Max enumerator value of EVENTCHGCC field.                        */
  #define MAIN_EVENTSBCHARGER1SET_EVENTCHGCC_LOW (0x0UL) /*!< Low                                                              */
  #define MAIN_EVENTSBCHARGER1SET_EVENTCHGCC_HIGH (0x1UL) /*!< High                                                            */

/* EVENTCHGCV @Bit 3 : Constant voltage charging started. Writing 1 sets the event (for debugging). */
  #define MAIN_EVENTSBCHARGER1SET_EVENTCHGCV_Pos (3UL) /*!< Position of EVENTCHGCV field.                                      */
  #define MAIN_EVENTSBCHARGER1SET_EVENTCHGCV_Msk (0x1UL << MAIN_EVENTSBCHARGER1SET_EVENTCHGCV_Pos) /*!< Bit mask of EVENTCHGCV
                                                                            field.*/                                              
  #define MAIN_EVENTSBCHARGER1SET_EVENTCHGCV_Min (0x0UL) /*!< Min enumerator value of EVENTCHGCV field.                        */
  #define MAIN_EVENTSBCHARGER1SET_EVENTCHGCV_Max (0x1UL) /*!< Max enumerator value of EVENTCHGCV field.                        */
  #define MAIN_EVENTSBCHARGER1SET_EVENTCHGCV_LOW (0x0UL) /*!< Low                                                              */
  #define MAIN_EVENTSBCHARGER1SET_EVENTCHGCV_HIGH (0x1UL) /*!< High                                                            */

/* EVENTCHGCOMPLETED @Bit 4 : Charging completed (battery full). Writing 1 sets the event (for debugging). */
  #define MAIN_EVENTSBCHARGER1SET_EVENTCHGCOMPLETED_Pos (4UL) /*!< Position of EVENTCHGCOMPLETED field.                        */
  #define MAIN_EVENTSBCHARGER1SET_EVENTCHGCOMPLETED_Msk (0x1UL << MAIN_EVENTSBCHARGER1SET_EVENTCHGCOMPLETED_Pos) /*!< Bit mask
                                                                            of EVENTCHGCOMPLETED field.*/                         
  #define MAIN_EVENTSBCHARGER1SET_EVENTCHGCOMPLETED_Min (0x0UL) /*!< Min enumerator value of EVENTCHGCOMPLETED field.          */
  #define MAIN_EVENTSBCHARGER1SET_EVENTCHGCOMPLETED_Max (0x1UL) /*!< Max enumerator value of EVENTCHGCOMPLETED field.          */
  #define MAIN_EVENTSBCHARGER1SET_EVENTCHGCOMPLETED_LOW (0x0UL) /*!< Low                                                       */
  #define MAIN_EVENTSBCHARGER1SET_EVENTCHGCOMPLETED_HIGH (0x1UL) /*!< High                                                     */

/* EVENTCHGERROR @Bit 5 : Charging error. Writing 1 sets the event (for debugging). */
  #define MAIN_EVENTSBCHARGER1SET_EVENTCHGERROR_Pos (5UL) /*!< Position of EVENTCHGERROR field.                                */
  #define MAIN_EVENTSBCHARGER1SET_EVENTCHGERROR_Msk (0x1UL << MAIN_EVENTSBCHARGER1SET_EVENTCHGERROR_Pos) /*!< Bit mask of
                                                                            EVENTCHGERROR field.*/                                
  #define MAIN_EVENTSBCHARGER1SET_EVENTCHGERROR_Min (0x0UL) /*!< Min enumerator value of EVENTCHGERROR field.                  */
  #define MAIN_EVENTSBCHARGER1SET_EVENTCHGERROR_Max (0x1UL) /*!< Max enumerator value of EVENTCHGERROR field.                  */
  #define MAIN_EVENTSBCHARGER1SET_EVENTCHGERROR_LOW (0x0UL) /*!< Low                                                           */
  #define MAIN_EVENTSBCHARGER1SET_EVENTCHGERROR_HIGH (0x1UL) /*!< High                                                         */


/* MAIN_EVENTSBCHARGER1CLR: Charger Event Clear */
  #define MAIN_EVENTSBCHARGER1CLR_ResetValue (0x00UL) /*!< Reset value of EVENTSBCHARGER1CLR register.                         */

/* EVENTSUPPLEMENT @Bit 0 : Supplement mode activated. Writing 1 clears the event (e.g. to acknowledge an interrupt). */
  #define MAIN_EVENTSBCHARGER1CLR_EVENTSUPPLEMENT_Pos (0UL) /*!< Position of EVENTSUPPLEMENT field.                            */
  #define MAIN_EVENTSBCHARGER1CLR_EVENTSUPPLEMENT_Msk (0x1UL << MAIN_EVENTSBCHARGER1CLR_EVENTSUPPLEMENT_Pos) /*!< Bit mask of
                                                                            EVENTSUPPLEMENT field.*/                              
  #define MAIN_EVENTSBCHARGER1CLR_EVENTSUPPLEMENT_Min (0x0UL) /*!< Min enumerator value of EVENTSUPPLEMENT field.              */
  #define MAIN_EVENTSBCHARGER1CLR_EVENTSUPPLEMENT_Max (0x1UL) /*!< Max enumerator value of EVENTSUPPLEMENT field.              */
  #define MAIN_EVENTSBCHARGER1CLR_EVENTSUPPLEMENT_LOW (0x0UL) /*!< Low                                                         */
  #define MAIN_EVENTSBCHARGER1CLR_EVENTSUPPLEMENT_HIGH (0x1UL) /*!< High                                                       */

/* EVENTCHGTRICKLE @Bit 1 : Tickle charge started. Writing 1 clears the event (e.g. to acknowledge an interrupt). */
  #define MAIN_EVENTSBCHARGER1CLR_EVENTCHGTRICKLE_Pos (1UL) /*!< Position of EVENTCHGTRICKLE field.                            */
  #define MAIN_EVENTSBCHARGER1CLR_EVENTCHGTRICKLE_Msk (0x1UL << MAIN_EVENTSBCHARGER1CLR_EVENTCHGTRICKLE_Pos) /*!< Bit mask of
                                                                            EVENTCHGTRICKLE field.*/                              
  #define MAIN_EVENTSBCHARGER1CLR_EVENTCHGTRICKLE_Min (0x0UL) /*!< Min enumerator value of EVENTCHGTRICKLE field.              */
  #define MAIN_EVENTSBCHARGER1CLR_EVENTCHGTRICKLE_Max (0x1UL) /*!< Max enumerator value of EVENTCHGTRICKLE field.              */
  #define MAIN_EVENTSBCHARGER1CLR_EVENTCHGTRICKLE_LOW (0x0UL) /*!< Low                                                         */
  #define MAIN_EVENTSBCHARGER1CLR_EVENTCHGTRICKLE_HIGH (0x1UL) /*!< High                                                       */

/* EVENTCHGCC @Bit 2 : Constant current charging started. Writing 1 clears the event (e.g. to acknowledge an interrupt). */
  #define MAIN_EVENTSBCHARGER1CLR_EVENTCHGCC_Pos (2UL) /*!< Position of EVENTCHGCC field.                                      */
  #define MAIN_EVENTSBCHARGER1CLR_EVENTCHGCC_Msk (0x1UL << MAIN_EVENTSBCHARGER1CLR_EVENTCHGCC_Pos) /*!< Bit mask of EVENTCHGCC
                                                                            field.*/                                              
  #define MAIN_EVENTSBCHARGER1CLR_EVENTCHGCC_Min (0x0UL) /*!< Min enumerator value of EVENTCHGCC field.                        */
  #define MAIN_EVENTSBCHARGER1CLR_EVENTCHGCC_Max (0x1UL) /*!< Max enumerator value of EVENTCHGCC field.                        */
  #define MAIN_EVENTSBCHARGER1CLR_EVENTCHGCC_LOW (0x0UL) /*!< Low                                                              */
  #define MAIN_EVENTSBCHARGER1CLR_EVENTCHGCC_HIGH (0x1UL) /*!< High                                                            */

/* EVENTCHGCV @Bit 3 : Constant voltage charging started. Writing 1 clears the event (e.g. to acknowledge an interrupt). */
  #define MAIN_EVENTSBCHARGER1CLR_EVENTCHGCV_Pos (3UL) /*!< Position of EVENTCHGCV field.                                      */
  #define MAIN_EVENTSBCHARGER1CLR_EVENTCHGCV_Msk (0x1UL << MAIN_EVENTSBCHARGER1CLR_EVENTCHGCV_Pos) /*!< Bit mask of EVENTCHGCV
                                                                            field.*/                                              
  #define MAIN_EVENTSBCHARGER1CLR_EVENTCHGCV_Min (0x0UL) /*!< Min enumerator value of EVENTCHGCV field.                        */
  #define MAIN_EVENTSBCHARGER1CLR_EVENTCHGCV_Max (0x1UL) /*!< Max enumerator value of EVENTCHGCV field.                        */
  #define MAIN_EVENTSBCHARGER1CLR_EVENTCHGCV_LOW (0x0UL) /*!< Low                                                              */
  #define MAIN_EVENTSBCHARGER1CLR_EVENTCHGCV_HIGH (0x1UL) /*!< High                                                            */

/* EVENTCHGCOMPLETED @Bit 4 : Charging completed (battery full). Writing 1 clears the event (e.g. to acknowledge an interrupt).
                              */                                                                                                  
                                                                                                                                  
  #define MAIN_EVENTSBCHARGER1CLR_EVENTCHGCOMPLETED_Pos (4UL) /*!< Position of EVENTCHGCOMPLETED field.                        */
  #define MAIN_EVENTSBCHARGER1CLR_EVENTCHGCOMPLETED_Msk (0x1UL << MAIN_EVENTSBCHARGER1CLR_EVENTCHGCOMPLETED_Pos) /*!< Bit mask
                                                                            of EVENTCHGCOMPLETED field.*/                         
  #define MAIN_EVENTSBCHARGER1CLR_EVENTCHGCOMPLETED_Min (0x0UL) /*!< Min enumerator value of EVENTCHGCOMPLETED field.          */
  #define MAIN_EVENTSBCHARGER1CLR_EVENTCHGCOMPLETED_Max (0x1UL) /*!< Max enumerator value of EVENTCHGCOMPLETED field.          */
  #define MAIN_EVENTSBCHARGER1CLR_EVENTCHGCOMPLETED_LOW (0x0UL) /*!< Low                                                       */
  #define MAIN_EVENTSBCHARGER1CLR_EVENTCHGCOMPLETED_HIGH (0x1UL) /*!< High                                                     */

/* EVENTCHGERROR @Bit 5 : Charging error. Writing 1 clears the event (e.g. to acknowledge an interrupt). */
  #define MAIN_EVENTSBCHARGER1CLR_EVENTCHGERROR_Pos (5UL) /*!< Position of EVENTCHGERROR field.                                */
  #define MAIN_EVENTSBCHARGER1CLR_EVENTCHGERROR_Msk (0x1UL << MAIN_EVENTSBCHARGER1CLR_EVENTCHGERROR_Pos) /*!< Bit mask of
                                                                            EVENTCHGERROR field.*/                                
  #define MAIN_EVENTSBCHARGER1CLR_EVENTCHGERROR_Min (0x0UL) /*!< Min enumerator value of EVENTCHGERROR field.                  */
  #define MAIN_EVENTSBCHARGER1CLR_EVENTCHGERROR_Max (0x1UL) /*!< Max enumerator value of EVENTCHGERROR field.                  */
  #define MAIN_EVENTSBCHARGER1CLR_EVENTCHGERROR_LOW (0x0UL) /*!< Low                                                           */
  #define MAIN_EVENTSBCHARGER1CLR_EVENTCHGERROR_HIGH (0x1UL) /*!< High                                                         */


/* MAIN_INTENEVENTSBCHARGER1SET: Charger Interrupt Enable Set */
  #define MAIN_INTENEVENTSBCHARGER1SET_ResetValue (0x00UL) /*!< Reset value of INTENEVENTSBCHARGER1SET register.               */

/* EVENTSUPPLEMENT @Bit 0 : Writing 1 enables interrupts from EVENTSUPPLEMENT */
  #define MAIN_INTENEVENTSBCHARGER1SET_EVENTSUPPLEMENT_Pos (0UL) /*!< Position of EVENTSUPPLEMENT field.                       */
  #define MAIN_INTENEVENTSBCHARGER1SET_EVENTSUPPLEMENT_Msk (0x1UL << MAIN_INTENEVENTSBCHARGER1SET_EVENTSUPPLEMENT_Pos) /*!< Bit
                                                                            mask of EVENTSUPPLEMENT field.*/                      
  #define MAIN_INTENEVENTSBCHARGER1SET_EVENTSUPPLEMENT_Min (0x0UL) /*!< Min enumerator value of EVENTSUPPLEMENT field.         */
  #define MAIN_INTENEVENTSBCHARGER1SET_EVENTSUPPLEMENT_Max (0x1UL) /*!< Max enumerator value of EVENTSUPPLEMENT field.         */
  #define MAIN_INTENEVENTSBCHARGER1SET_EVENTSUPPLEMENT_LOW (0x0UL) /*!< Low                                                    */
  #define MAIN_INTENEVENTSBCHARGER1SET_EVENTSUPPLEMENT_HIGH (0x1UL) /*!< High                                                  */

/* EVENTCHGTRICKLE @Bit 1 : Writing 1 enables interrupts from EVENTCHGTRICKLE */
  #define MAIN_INTENEVENTSBCHARGER1SET_EVENTCHGTRICKLE_Pos (1UL) /*!< Position of EVENTCHGTRICKLE field.                       */
  #define MAIN_INTENEVENTSBCHARGER1SET_EVENTCHGTRICKLE_Msk (0x1UL << MAIN_INTENEVENTSBCHARGER1SET_EVENTCHGTRICKLE_Pos) /*!< Bit
                                                                            mask of EVENTCHGTRICKLE field.*/                      
  #define MAIN_INTENEVENTSBCHARGER1SET_EVENTCHGTRICKLE_Min (0x0UL) /*!< Min enumerator value of EVENTCHGTRICKLE field.         */
  #define MAIN_INTENEVENTSBCHARGER1SET_EVENTCHGTRICKLE_Max (0x1UL) /*!< Max enumerator value of EVENTCHGTRICKLE field.         */
  #define MAIN_INTENEVENTSBCHARGER1SET_EVENTCHGTRICKLE_LOW (0x0UL) /*!< Low                                                    */
  #define MAIN_INTENEVENTSBCHARGER1SET_EVENTCHGTRICKLE_HIGH (0x1UL) /*!< High                                                  */

/* EVENTCHGCC @Bit 2 : Writing 1 enables interrupts from EVENTCHGCC */
  #define MAIN_INTENEVENTSBCHARGER1SET_EVENTCHGCC_Pos (2UL) /*!< Position of EVENTCHGCC field.                                 */
  #define MAIN_INTENEVENTSBCHARGER1SET_EVENTCHGCC_Msk (0x1UL << MAIN_INTENEVENTSBCHARGER1SET_EVENTCHGCC_Pos) /*!< Bit mask of
                                                                            EVENTCHGCC field.*/                                   
  #define MAIN_INTENEVENTSBCHARGER1SET_EVENTCHGCC_Min (0x0UL) /*!< Min enumerator value of EVENTCHGCC field.                   */
  #define MAIN_INTENEVENTSBCHARGER1SET_EVENTCHGCC_Max (0x1UL) /*!< Max enumerator value of EVENTCHGCC field.                   */
  #define MAIN_INTENEVENTSBCHARGER1SET_EVENTCHGCC_LOW (0x0UL) /*!< Low                                                         */
  #define MAIN_INTENEVENTSBCHARGER1SET_EVENTCHGCC_HIGH (0x1UL) /*!< High                                                       */

/* EVENTCHGCV @Bit 3 : Writing 1 enables interrupts from EVENTCHGCV */
  #define MAIN_INTENEVENTSBCHARGER1SET_EVENTCHGCV_Pos (3UL) /*!< Position of EVENTCHGCV field.                                 */
  #define MAIN_INTENEVENTSBCHARGER1SET_EVENTCHGCV_Msk (0x1UL << MAIN_INTENEVENTSBCHARGER1SET_EVENTCHGCV_Pos) /*!< Bit mask of
                                                                            EVENTCHGCV field.*/                                   
  #define MAIN_INTENEVENTSBCHARGER1SET_EVENTCHGCV_Min (0x0UL) /*!< Min enumerator value of EVENTCHGCV field.                   */
  #define MAIN_INTENEVENTSBCHARGER1SET_EVENTCHGCV_Max (0x1UL) /*!< Max enumerator value of EVENTCHGCV field.                   */
  #define MAIN_INTENEVENTSBCHARGER1SET_EVENTCHGCV_LOW (0x0UL) /*!< Low                                                         */
  #define MAIN_INTENEVENTSBCHARGER1SET_EVENTCHGCV_HIGH (0x1UL) /*!< High                                                       */

/* EVENTCHGCOMPLETED @Bit 4 : Writing 1 enables interrupts from EVENTCHGCOMPLETED */
  #define MAIN_INTENEVENTSBCHARGER1SET_EVENTCHGCOMPLETED_Pos (4UL) /*!< Position of EVENTCHGCOMPLETED field.                   */
  #define MAIN_INTENEVENTSBCHARGER1SET_EVENTCHGCOMPLETED_Msk (0x1UL << MAIN_INTENEVENTSBCHARGER1SET_EVENTCHGCOMPLETED_Pos) /*!<
                                                                            Bit mask of EVENTCHGCOMPLETED field.*/                
  #define MAIN_INTENEVENTSBCHARGER1SET_EVENTCHGCOMPLETED_Min (0x0UL) /*!< Min enumerator value of EVENTCHGCOMPLETED field.     */
  #define MAIN_INTENEVENTSBCHARGER1SET_EVENTCHGCOMPLETED_Max (0x1UL) /*!< Max enumerator value of EVENTCHGCOMPLETED field.     */
  #define MAIN_INTENEVENTSBCHARGER1SET_EVENTCHGCOMPLETED_LOW (0x0UL) /*!< Low                                                  */
  #define MAIN_INTENEVENTSBCHARGER1SET_EVENTCHGCOMPLETED_HIGH (0x1UL) /*!< High                                                */

/* EVENTCHGERROR @Bit 5 : Writing 1 enables interrupts from EVENTCHGERROR */
  #define MAIN_INTENEVENTSBCHARGER1SET_EVENTCHGERROR_Pos (5UL) /*!< Position of EVENTCHGERROR field.                           */
  #define MAIN_INTENEVENTSBCHARGER1SET_EVENTCHGERROR_Msk (0x1UL << MAIN_INTENEVENTSBCHARGER1SET_EVENTCHGERROR_Pos) /*!< Bit mask
                                                                            of EVENTCHGERROR field.*/                             
  #define MAIN_INTENEVENTSBCHARGER1SET_EVENTCHGERROR_Min (0x0UL) /*!< Min enumerator value of EVENTCHGERROR field.             */
  #define MAIN_INTENEVENTSBCHARGER1SET_EVENTCHGERROR_Max (0x1UL) /*!< Max enumerator value of EVENTCHGERROR field.             */
  #define MAIN_INTENEVENTSBCHARGER1SET_EVENTCHGERROR_LOW (0x0UL) /*!< Low                                                      */
  #define MAIN_INTENEVENTSBCHARGER1SET_EVENTCHGERROR_HIGH (0x1UL) /*!< High                                                    */


/* MAIN_INTENEVENTSBCHARGER1CLR: Charger Interrupt Enable Clear */
  #define MAIN_INTENEVENTSBCHARGER1CLR_ResetValue (0x00UL) /*!< Reset value of INTENEVENTSBCHARGER1CLR register.               */

/* EVENTSUPPLEMENT @Bit 0 : Writing 1 disables interrupts from EVENTSUPPLEMENT */
  #define MAIN_INTENEVENTSBCHARGER1CLR_EVENTSUPPLEMENT_Pos (0UL) /*!< Position of EVENTSUPPLEMENT field.                       */
  #define MAIN_INTENEVENTSBCHARGER1CLR_EVENTSUPPLEMENT_Msk (0x1UL << MAIN_INTENEVENTSBCHARGER1CLR_EVENTSUPPLEMENT_Pos) /*!< Bit
                                                                            mask of EVENTSUPPLEMENT field.*/                      
  #define MAIN_INTENEVENTSBCHARGER1CLR_EVENTSUPPLEMENT_Min (0x0UL) /*!< Min enumerator value of EVENTSUPPLEMENT field.         */
  #define MAIN_INTENEVENTSBCHARGER1CLR_EVENTSUPPLEMENT_Max (0x1UL) /*!< Max enumerator value of EVENTSUPPLEMENT field.         */
  #define MAIN_INTENEVENTSBCHARGER1CLR_EVENTSUPPLEMENT_LOW (0x0UL) /*!< Low                                                    */
  #define MAIN_INTENEVENTSBCHARGER1CLR_EVENTSUPPLEMENT_HIGH (0x1UL) /*!< High                                                  */

/* EVENTCHGTRICKLE @Bit 1 : Writing 1 disables interrupts from EVENTCHGTRICKLE */
  #define MAIN_INTENEVENTSBCHARGER1CLR_EVENTCHGTRICKLE_Pos (1UL) /*!< Position of EVENTCHGTRICKLE field.                       */
  #define MAIN_INTENEVENTSBCHARGER1CLR_EVENTCHGTRICKLE_Msk (0x1UL << MAIN_INTENEVENTSBCHARGER1CLR_EVENTCHGTRICKLE_Pos) /*!< Bit
                                                                            mask of EVENTCHGTRICKLE field.*/                      
  #define MAIN_INTENEVENTSBCHARGER1CLR_EVENTCHGTRICKLE_Min (0x0UL) /*!< Min enumerator value of EVENTCHGTRICKLE field.         */
  #define MAIN_INTENEVENTSBCHARGER1CLR_EVENTCHGTRICKLE_Max (0x1UL) /*!< Max enumerator value of EVENTCHGTRICKLE field.         */
  #define MAIN_INTENEVENTSBCHARGER1CLR_EVENTCHGTRICKLE_LOW (0x0UL) /*!< Low                                                    */
  #define MAIN_INTENEVENTSBCHARGER1CLR_EVENTCHGTRICKLE_HIGH (0x1UL) /*!< High                                                  */

/* EVENTCHGCC @Bit 2 : Writing 1 disables interrupts from EVENTCHGCC */
  #define MAIN_INTENEVENTSBCHARGER1CLR_EVENTCHGCC_Pos (2UL) /*!< Position of EVENTCHGCC field.                                 */
  #define MAIN_INTENEVENTSBCHARGER1CLR_EVENTCHGCC_Msk (0x1UL << MAIN_INTENEVENTSBCHARGER1CLR_EVENTCHGCC_Pos) /*!< Bit mask of
                                                                            EVENTCHGCC field.*/                                   
  #define MAIN_INTENEVENTSBCHARGER1CLR_EVENTCHGCC_Min (0x0UL) /*!< Min enumerator value of EVENTCHGCC field.                   */
  #define MAIN_INTENEVENTSBCHARGER1CLR_EVENTCHGCC_Max (0x1UL) /*!< Max enumerator value of EVENTCHGCC field.                   */
  #define MAIN_INTENEVENTSBCHARGER1CLR_EVENTCHGCC_LOW (0x0UL) /*!< Low                                                         */
  #define MAIN_INTENEVENTSBCHARGER1CLR_EVENTCHGCC_HIGH (0x1UL) /*!< High                                                       */

/* EVENTCHGCV @Bit 3 : Writing 1 disables interrupts from EVENTCHGCV */
  #define MAIN_INTENEVENTSBCHARGER1CLR_EVENTCHGCV_Pos (3UL) /*!< Position of EVENTCHGCV field.                                 */
  #define MAIN_INTENEVENTSBCHARGER1CLR_EVENTCHGCV_Msk (0x1UL << MAIN_INTENEVENTSBCHARGER1CLR_EVENTCHGCV_Pos) /*!< Bit mask of
                                                                            EVENTCHGCV field.*/                                   
  #define MAIN_INTENEVENTSBCHARGER1CLR_EVENTCHGCV_Min (0x0UL) /*!< Min enumerator value of EVENTCHGCV field.                   */
  #define MAIN_INTENEVENTSBCHARGER1CLR_EVENTCHGCV_Max (0x1UL) /*!< Max enumerator value of EVENTCHGCV field.                   */
  #define MAIN_INTENEVENTSBCHARGER1CLR_EVENTCHGCV_LOW (0x0UL) /*!< Low                                                         */
  #define MAIN_INTENEVENTSBCHARGER1CLR_EVENTCHGCV_HIGH (0x1UL) /*!< High                                                       */

/* EVENTCHGCOMPLETED @Bit 4 : Writing 1 disables interrupts from EVENTCHGCOMPLETED */
  #define MAIN_INTENEVENTSBCHARGER1CLR_EVENTCHGCOMPLETED_Pos (4UL) /*!< Position of EVENTCHGCOMPLETED field.                   */
  #define MAIN_INTENEVENTSBCHARGER1CLR_EVENTCHGCOMPLETED_Msk (0x1UL << MAIN_INTENEVENTSBCHARGER1CLR_EVENTCHGCOMPLETED_Pos) /*!<
                                                                            Bit mask of EVENTCHGCOMPLETED field.*/                
  #define MAIN_INTENEVENTSBCHARGER1CLR_EVENTCHGCOMPLETED_Min (0x0UL) /*!< Min enumerator value of EVENTCHGCOMPLETED field.     */
  #define MAIN_INTENEVENTSBCHARGER1CLR_EVENTCHGCOMPLETED_Max (0x1UL) /*!< Max enumerator value of EVENTCHGCOMPLETED field.     */
  #define MAIN_INTENEVENTSBCHARGER1CLR_EVENTCHGCOMPLETED_LOW (0x0UL) /*!< Low                                                  */
  #define MAIN_INTENEVENTSBCHARGER1CLR_EVENTCHGCOMPLETED_HIGH (0x1UL) /*!< High                                                */

/* EVENTCHGERROR @Bit 5 : Writing 1 disables interrupts from EVENTCHGERROR */
  #define MAIN_INTENEVENTSBCHARGER1CLR_EVENTCHGERROR_Pos (5UL) /*!< Position of EVENTCHGERROR field.                           */
  #define MAIN_INTENEVENTSBCHARGER1CLR_EVENTCHGERROR_Msk (0x1UL << MAIN_INTENEVENTSBCHARGER1CLR_EVENTCHGERROR_Pos) /*!< Bit mask
                                                                            of EVENTCHGERROR field.*/                             
  #define MAIN_INTENEVENTSBCHARGER1CLR_EVENTCHGERROR_Min (0x0UL) /*!< Min enumerator value of EVENTCHGERROR field.             */
  #define MAIN_INTENEVENTSBCHARGER1CLR_EVENTCHGERROR_Max (0x1UL) /*!< Max enumerator value of EVENTCHGERROR field.             */
  #define MAIN_INTENEVENTSBCHARGER1CLR_EVENTCHGERROR_LOW (0x0UL) /*!< Low                                                      */
  #define MAIN_INTENEVENTSBCHARGER1CLR_EVENTCHGERROR_HIGH (0x1UL) /*!< High                                                    */


/* MAIN_EVENTSBCHARGER2SET: Battery Event Set */
  #define MAIN_EVENTSBCHARGER2SET_ResetValue (0x00UL) /*!< Reset value of EVENTSBCHARGER2SET register.                         */

/* EVENTBATDETECTED @Bit 0 : Reserved (Battery detected.) Writing 1 sets the event (for debugging). */
  #define MAIN_EVENTSBCHARGER2SET_EVENTBATDETECTED_Pos (0UL) /*!< Position of EVENTBATDETECTED field.                          */
  #define MAIN_EVENTSBCHARGER2SET_EVENTBATDETECTED_Msk (0x1UL << MAIN_EVENTSBCHARGER2SET_EVENTBATDETECTED_Pos) /*!< Bit mask of
                                                                            EVENTBATDETECTED field.*/                             
  #define MAIN_EVENTSBCHARGER2SET_EVENTBATDETECTED_Min (0x0UL) /*!< Min enumerator value of EVENTBATDETECTED field.            */
  #define MAIN_EVENTSBCHARGER2SET_EVENTBATDETECTED_Max (0x1UL) /*!< Max enumerator value of EVENTBATDETECTED field.            */
  #define MAIN_EVENTSBCHARGER2SET_EVENTBATDETECTED_LOW (0x0UL) /*!< Low                                                        */
  #define MAIN_EVENTSBCHARGER2SET_EVENTBATDETECTED_HIGH (0x1UL) /*!< High                                                      */

/* EVENTBATLOST @Bit 1 : Battery lost. Writing 1 sets the event (for debugging). */
  #define MAIN_EVENTSBCHARGER2SET_EVENTBATLOST_Pos (1UL) /*!< Position of EVENTBATLOST field.                                  */
  #define MAIN_EVENTSBCHARGER2SET_EVENTBATLOST_Msk (0x1UL << MAIN_EVENTSBCHARGER2SET_EVENTBATLOST_Pos) /*!< Bit mask of
                                                                            EVENTBATLOST field.*/                                 
  #define MAIN_EVENTSBCHARGER2SET_EVENTBATLOST_Min (0x0UL) /*!< Min enumerator value of EVENTBATLOST field.                    */
  #define MAIN_EVENTSBCHARGER2SET_EVENTBATLOST_Max (0x1UL) /*!< Max enumerator value of EVENTBATLOST field.                    */
  #define MAIN_EVENTSBCHARGER2SET_EVENTBATLOST_LOW (0x0UL) /*!< Low                                                            */
  #define MAIN_EVENTSBCHARGER2SET_EVENTBATLOST_HIGH (0x1UL) /*!< High                                                          */

/* EVENTBATRECHARGE @Bit 2 : Battery re-charge needed. Writing 1 sets the event (for debugging). */
  #define MAIN_EVENTSBCHARGER2SET_EVENTBATRECHARGE_Pos (2UL) /*!< Position of EVENTBATRECHARGE field.                          */
  #define MAIN_EVENTSBCHARGER2SET_EVENTBATRECHARGE_Msk (0x1UL << MAIN_EVENTSBCHARGER2SET_EVENTBATRECHARGE_Pos) /*!< Bit mask of
                                                                            EVENTBATRECHARGE field.*/                             
  #define MAIN_EVENTSBCHARGER2SET_EVENTBATRECHARGE_Min (0x0UL) /*!< Min enumerator value of EVENTBATRECHARGE field.            */
  #define MAIN_EVENTSBCHARGER2SET_EVENTBATRECHARGE_Max (0x1UL) /*!< Max enumerator value of EVENTBATRECHARGE field.            */
  #define MAIN_EVENTSBCHARGER2SET_EVENTBATRECHARGE_LOW (0x0UL) /*!< Low                                                        */
  #define MAIN_EVENTSBCHARGER2SET_EVENTBATRECHARGE_HIGH (0x1UL) /*!< High                                                      */


/* MAIN_EVENTSBCHARGER2CLR: Battery Event Clear */
  #define MAIN_EVENTSBCHARGER2CLR_ResetValue (0x00UL) /*!< Reset value of EVENTSBCHARGER2CLR register.                         */

/* EVENTBATDETECTED @Bit 0 : Reserved (Battery detected.) Writing 1 clears the event (e.g. to acknowledge an interrupt). */
  #define MAIN_EVENTSBCHARGER2CLR_EVENTBATDETECTED_Pos (0UL) /*!< Position of EVENTBATDETECTED field.                          */
  #define MAIN_EVENTSBCHARGER2CLR_EVENTBATDETECTED_Msk (0x1UL << MAIN_EVENTSBCHARGER2CLR_EVENTBATDETECTED_Pos) /*!< Bit mask of
                                                                            EVENTBATDETECTED field.*/                             
  #define MAIN_EVENTSBCHARGER2CLR_EVENTBATDETECTED_Min (0x0UL) /*!< Min enumerator value of EVENTBATDETECTED field.            */
  #define MAIN_EVENTSBCHARGER2CLR_EVENTBATDETECTED_Max (0x1UL) /*!< Max enumerator value of EVENTBATDETECTED field.            */
  #define MAIN_EVENTSBCHARGER2CLR_EVENTBATDETECTED_LOW (0x0UL) /*!< Low                                                        */
  #define MAIN_EVENTSBCHARGER2CLR_EVENTBATDETECTED_HIGH (0x1UL) /*!< High                                                      */

/* EVENTBATLOST @Bit 1 : Battery lost. Writing 1 clears the event (e.g. to acknowledge an interrupt). */
  #define MAIN_EVENTSBCHARGER2CLR_EVENTBATLOST_Pos (1UL) /*!< Position of EVENTBATLOST field.                                  */
  #define MAIN_EVENTSBCHARGER2CLR_EVENTBATLOST_Msk (0x1UL << MAIN_EVENTSBCHARGER2CLR_EVENTBATLOST_Pos) /*!< Bit mask of
                                                                            EVENTBATLOST field.*/                                 
  #define MAIN_EVENTSBCHARGER2CLR_EVENTBATLOST_Min (0x0UL) /*!< Min enumerator value of EVENTBATLOST field.                    */
  #define MAIN_EVENTSBCHARGER2CLR_EVENTBATLOST_Max (0x1UL) /*!< Max enumerator value of EVENTBATLOST field.                    */
  #define MAIN_EVENTSBCHARGER2CLR_EVENTBATLOST_LOW (0x0UL) /*!< Low                                                            */
  #define MAIN_EVENTSBCHARGER2CLR_EVENTBATLOST_HIGH (0x1UL) /*!< High                                                          */

/* EVENTBATRECHARGE @Bit 2 : Battery re-charge needed. Writing 1 clears the event (e.g. to acknowledge an interrupt). */
  #define MAIN_EVENTSBCHARGER2CLR_EVENTBATRECHARGE_Pos (2UL) /*!< Position of EVENTBATRECHARGE field.                          */
  #define MAIN_EVENTSBCHARGER2CLR_EVENTBATRECHARGE_Msk (0x1UL << MAIN_EVENTSBCHARGER2CLR_EVENTBATRECHARGE_Pos) /*!< Bit mask of
                                                                            EVENTBATRECHARGE field.*/                             
  #define MAIN_EVENTSBCHARGER2CLR_EVENTBATRECHARGE_Min (0x0UL) /*!< Min enumerator value of EVENTBATRECHARGE field.            */
  #define MAIN_EVENTSBCHARGER2CLR_EVENTBATRECHARGE_Max (0x1UL) /*!< Max enumerator value of EVENTBATRECHARGE field.            */
  #define MAIN_EVENTSBCHARGER2CLR_EVENTBATRECHARGE_LOW (0x0UL) /*!< Low                                                        */
  #define MAIN_EVENTSBCHARGER2CLR_EVENTBATRECHARGE_HIGH (0x1UL) /*!< High                                                      */


/* MAIN_INTENEVENTSBCHARGER2SET: Battery Interrupt Enable Set */
  #define MAIN_INTENEVENTSBCHARGER2SET_ResetValue (0x00UL) /*!< Reset value of INTENEVENTSBCHARGER2SET register.               */

/* EVENTBATDETECTED @Bit 0 : Reserved (Writing 1 enables interrupts from EVENTBATDETECTED) */
  #define MAIN_INTENEVENTSBCHARGER2SET_EVENTBATDETECTED_Pos (0UL) /*!< Position of EVENTBATDETECTED field.                     */
  #define MAIN_INTENEVENTSBCHARGER2SET_EVENTBATDETECTED_Msk (0x1UL << MAIN_INTENEVENTSBCHARGER2SET_EVENTBATDETECTED_Pos) /*!<
                                                                            Bit mask of EVENTBATDETECTED field.*/                 
  #define MAIN_INTENEVENTSBCHARGER2SET_EVENTBATDETECTED_Min (0x0UL) /*!< Min enumerator value of EVENTBATDETECTED field.       */
  #define MAIN_INTENEVENTSBCHARGER2SET_EVENTBATDETECTED_Max (0x1UL) /*!< Max enumerator value of EVENTBATDETECTED field.       */
  #define MAIN_INTENEVENTSBCHARGER2SET_EVENTBATDETECTED_LOW (0x0UL) /*!< Low                                                   */
  #define MAIN_INTENEVENTSBCHARGER2SET_EVENTBATDETECTED_HIGH (0x1UL) /*!< High                                                 */

/* EVENTBATLOST @Bit 1 : Reserved (Writing 1 enables interrupts from EVENTBATLOST) */
  #define MAIN_INTENEVENTSBCHARGER2SET_EVENTBATLOST_Pos (1UL) /*!< Position of EVENTBATLOST field.                             */
  #define MAIN_INTENEVENTSBCHARGER2SET_EVENTBATLOST_Msk (0x1UL << MAIN_INTENEVENTSBCHARGER2SET_EVENTBATLOST_Pos) /*!< Bit mask
                                                                            of EVENTBATLOST field.*/                              
  #define MAIN_INTENEVENTSBCHARGER2SET_EVENTBATLOST_Min (0x0UL) /*!< Min enumerator value of EVENTBATLOST field.               */
  #define MAIN_INTENEVENTSBCHARGER2SET_EVENTBATLOST_Max (0x1UL) /*!< Max enumerator value of EVENTBATLOST field.               */
  #define MAIN_INTENEVENTSBCHARGER2SET_EVENTBATLOST_LOW (0x0UL) /*!< Low                                                       */
  #define MAIN_INTENEVENTSBCHARGER2SET_EVENTBATLOST_HIGH (0x1UL) /*!< High                                                     */

/* EVENTBATRECHARGE @Bit 2 : Writing 1 enables interrupts from EVENTBATRECHARGE */
  #define MAIN_INTENEVENTSBCHARGER2SET_EVENTBATRECHARGE_Pos (2UL) /*!< Position of EVENTBATRECHARGE field.                     */
  #define MAIN_INTENEVENTSBCHARGER2SET_EVENTBATRECHARGE_Msk (0x1UL << MAIN_INTENEVENTSBCHARGER2SET_EVENTBATRECHARGE_Pos) /*!<
                                                                            Bit mask of EVENTBATRECHARGE field.*/                 
  #define MAIN_INTENEVENTSBCHARGER2SET_EVENTBATRECHARGE_Min (0x0UL) /*!< Min enumerator value of EVENTBATRECHARGE field.       */
  #define MAIN_INTENEVENTSBCHARGER2SET_EVENTBATRECHARGE_Max (0x1UL) /*!< Max enumerator value of EVENTBATRECHARGE field.       */
  #define MAIN_INTENEVENTSBCHARGER2SET_EVENTBATRECHARGE_LOW (0x0UL) /*!< Low                                                   */
  #define MAIN_INTENEVENTSBCHARGER2SET_EVENTBATRECHARGE_HIGH (0x1UL) /*!< High                                                 */


/* MAIN_INTENEVENTSBCHARGER2CLR: Battery Interrupt Enable Clear */
  #define MAIN_INTENEVENTSBCHARGER2CLR_ResetValue (0x00UL) /*!< Reset value of INTENEVENTSBCHARGER2CLR register.               */

/* EVENTBATDETECTED @Bit 0 : Reserved (Writing 1 disables interrupts from EVENTBATDETECTED) */
  #define MAIN_INTENEVENTSBCHARGER2CLR_EVENTBATDETECTED_Pos (0UL) /*!< Position of EVENTBATDETECTED field.                     */
  #define MAIN_INTENEVENTSBCHARGER2CLR_EVENTBATDETECTED_Msk (0x1UL << MAIN_INTENEVENTSBCHARGER2CLR_EVENTBATDETECTED_Pos) /*!<
                                                                            Bit mask of EVENTBATDETECTED field.*/                 
  #define MAIN_INTENEVENTSBCHARGER2CLR_EVENTBATDETECTED_Min (0x0UL) /*!< Min enumerator value of EVENTBATDETECTED field.       */
  #define MAIN_INTENEVENTSBCHARGER2CLR_EVENTBATDETECTED_Max (0x1UL) /*!< Max enumerator value of EVENTBATDETECTED field.       */
  #define MAIN_INTENEVENTSBCHARGER2CLR_EVENTBATDETECTED_LOW (0x0UL) /*!< Low                                                   */
  #define MAIN_INTENEVENTSBCHARGER2CLR_EVENTBATDETECTED_HIGH (0x1UL) /*!< High                                                 */

/* EVENTBATLOST @Bit 1 : Reserved (Writing 1 disables interrupts from EVENTBATLOST) */
  #define MAIN_INTENEVENTSBCHARGER2CLR_EVENTBATLOST_Pos (1UL) /*!< Position of EVENTBATLOST field.                             */
  #define MAIN_INTENEVENTSBCHARGER2CLR_EVENTBATLOST_Msk (0x1UL << MAIN_INTENEVENTSBCHARGER2CLR_EVENTBATLOST_Pos) /*!< Bit mask
                                                                            of EVENTBATLOST field.*/                              
  #define MAIN_INTENEVENTSBCHARGER2CLR_EVENTBATLOST_Min (0x0UL) /*!< Min enumerator value of EVENTBATLOST field.               */
  #define MAIN_INTENEVENTSBCHARGER2CLR_EVENTBATLOST_Max (0x1UL) /*!< Max enumerator value of EVENTBATLOST field.               */
  #define MAIN_INTENEVENTSBCHARGER2CLR_EVENTBATLOST_LOW (0x0UL) /*!< Low                                                       */
  #define MAIN_INTENEVENTSBCHARGER2CLR_EVENTBATLOST_HIGH (0x1UL) /*!< High                                                     */

/* EVENTBATRECHARGE @Bit 2 : Writing 1 disables interrupts from EVENTBATRECHARGE */
  #define MAIN_INTENEVENTSBCHARGER2CLR_EVENTBATRECHARGE_Pos (2UL) /*!< Position of EVENTBATRECHARGE field.                     */
  #define MAIN_INTENEVENTSBCHARGER2CLR_EVENTBATRECHARGE_Msk (0x1UL << MAIN_INTENEVENTSBCHARGER2CLR_EVENTBATRECHARGE_Pos) /*!<
                                                                            Bit mask of EVENTBATRECHARGE field.*/                 
  #define MAIN_INTENEVENTSBCHARGER2CLR_EVENTBATRECHARGE_Min (0x0UL) /*!< Min enumerator value of EVENTBATRECHARGE field.       */
  #define MAIN_INTENEVENTSBCHARGER2CLR_EVENTBATRECHARGE_Max (0x1UL) /*!< Max enumerator value of EVENTBATRECHARGE field.       */
  #define MAIN_INTENEVENTSBCHARGER2CLR_EVENTBATRECHARGE_LOW (0x0UL) /*!< Low                                                   */
  #define MAIN_INTENEVENTSBCHARGER2CLR_EVENTBATRECHARGE_HIGH (0x1UL) /*!< High                                                 */


/* MAIN_EVENTSSHPHLDSET: SHPHLD pin and watchdog Event Set */
  #define MAIN_EVENTSSHPHLDSET_ResetValue (0x00UL)   /*!< Reset value of EVENTSSHPHLDSET register.                             */

/* EVENTSHPHLDBTNPRESS @Bit 0 : SHPHLD button is pressed. Writing 1 sets the event (for debugging). */
  #define MAIN_EVENTSSHPHLDSET_EVENTSHPHLDBTNPRESS_Pos (0UL) /*!< Position of EVENTSHPHLDBTNPRESS field.                       */
  #define MAIN_EVENTSSHPHLDSET_EVENTSHPHLDBTNPRESS_Msk (0x1UL << MAIN_EVENTSSHPHLDSET_EVENTSHPHLDBTNPRESS_Pos) /*!< Bit mask of
                                                                            EVENTSHPHLDBTNPRESS field.*/                          
  #define MAIN_EVENTSSHPHLDSET_EVENTSHPHLDBTNPRESS_Min (0x0UL) /*!< Min enumerator value of EVENTSHPHLDBTNPRESS field.         */
  #define MAIN_EVENTSSHPHLDSET_EVENTSHPHLDBTNPRESS_Max (0x1UL) /*!< Max enumerator value of EVENTSHPHLDBTNPRESS field.         */
  #define MAIN_EVENTSSHPHLDSET_EVENTSHPHLDBTNPRESS_LOW (0x0UL) /*!< Low                                                        */
  #define MAIN_EVENTSSHPHLDSET_EVENTSHPHLDBTNPRESS_HIGH (0x1UL) /*!< High                                                      */

/* EVENTSHPHLDBTNRELEASE @Bit 1 : SHPHLD button is released. Writing 1 sets the event (for debugging). */
  #define MAIN_EVENTSSHPHLDSET_EVENTSHPHLDBTNRELEASE_Pos (1UL) /*!< Position of EVENTSHPHLDBTNRELEASE field.                   */
  #define MAIN_EVENTSSHPHLDSET_EVENTSHPHLDBTNRELEASE_Msk (0x1UL << MAIN_EVENTSSHPHLDSET_EVENTSHPHLDBTNRELEASE_Pos) /*!< Bit mask
                                                                            of EVENTSHPHLDBTNRELEASE field.*/                     
  #define MAIN_EVENTSSHPHLDSET_EVENTSHPHLDBTNRELEASE_Min (0x0UL) /*!< Min enumerator value of EVENTSHPHLDBTNRELEASE field.     */
  #define MAIN_EVENTSSHPHLDSET_EVENTSHPHLDBTNRELEASE_Max (0x1UL) /*!< Max enumerator value of EVENTSHPHLDBTNRELEASE field.     */
  #define MAIN_EVENTSSHPHLDSET_EVENTSHPHLDBTNRELEASE_LOW (0x0UL) /*!< Low                                                      */
  #define MAIN_EVENTSSHPHLDSET_EVENTSHPHLDBTNRELEASE_HIGH (0x1UL) /*!< High                                                    */

/* EVENTSHPHLDEXIT @Bit 2 : SHPHLD button held to exit Ship mode. Writing 1 sets the event (for debugging). */
  #define MAIN_EVENTSSHPHLDSET_EVENTSHPHLDEXIT_Pos (2UL) /*!< Position of EVENTSHPHLDEXIT field.                               */
  #define MAIN_EVENTSSHPHLDSET_EVENTSHPHLDEXIT_Msk (0x1UL << MAIN_EVENTSSHPHLDSET_EVENTSHPHLDEXIT_Pos) /*!< Bit mask of
                                                                            EVENTSHPHLDEXIT field.*/                              
  #define MAIN_EVENTSSHPHLDSET_EVENTSHPHLDEXIT_Min (0x0UL) /*!< Min enumerator value of EVENTSHPHLDEXIT field.                 */
  #define MAIN_EVENTSSHPHLDSET_EVENTSHPHLDEXIT_Max (0x1UL) /*!< Max enumerator value of EVENTSHPHLDEXIT field.                 */
  #define MAIN_EVENTSSHPHLDSET_EVENTSHPHLDEXIT_LOW (0x0UL) /*!< Low                                                            */
  #define MAIN_EVENTSSHPHLDSET_EVENTSHPHLDEXIT_HIGH (0x1UL) /*!< High                                                          */

/* EVENTWATCHDOGWARN @Bit 3 : Watchdog timeout warning. Writing 1 sets the event (for debugging). */
  #define MAIN_EVENTSSHPHLDSET_EVENTWATCHDOGWARN_Pos (3UL) /*!< Position of EVENTWATCHDOGWARN field.                           */
  #define MAIN_EVENTSSHPHLDSET_EVENTWATCHDOGWARN_Msk (0x1UL << MAIN_EVENTSSHPHLDSET_EVENTWATCHDOGWARN_Pos) /*!< Bit mask of
                                                                            EVENTWATCHDOGWARN field.*/                            
  #define MAIN_EVENTSSHPHLDSET_EVENTWATCHDOGWARN_Min (0x0UL) /*!< Min enumerator value of EVENTWATCHDOGWARN field.             */
  #define MAIN_EVENTSSHPHLDSET_EVENTWATCHDOGWARN_Max (0x1UL) /*!< Max enumerator value of EVENTWATCHDOGWARN field.             */
  #define MAIN_EVENTSSHPHLDSET_EVENTWATCHDOGWARN_LOW (0x0UL) /*!< Low                                                          */
  #define MAIN_EVENTSSHPHLDSET_EVENTWATCHDOGWARN_HIGH (0x1UL) /*!< High                                                        */


/* MAIN_EVENTSSHPHLDCLR: SHPHLD pin and watchdog Event Clear */
  #define MAIN_EVENTSSHPHLDCLR_ResetValue (0x00UL)   /*!< Reset value of EVENTSSHPHLDCLR register.                             */

/* EVENTSHPHLDBTNPRESS @Bit 0 : SHPHLD button is pressed. Writing 1 clears the event (e.g. to acknowledge an interrupt). */
  #define MAIN_EVENTSSHPHLDCLR_EVENTSHPHLDBTNPRESS_Pos (0UL) /*!< Position of EVENTSHPHLDBTNPRESS field.                       */
  #define MAIN_EVENTSSHPHLDCLR_EVENTSHPHLDBTNPRESS_Msk (0x1UL << MAIN_EVENTSSHPHLDCLR_EVENTSHPHLDBTNPRESS_Pos) /*!< Bit mask of
                                                                            EVENTSHPHLDBTNPRESS field.*/                          
  #define MAIN_EVENTSSHPHLDCLR_EVENTSHPHLDBTNPRESS_Min (0x0UL) /*!< Min enumerator value of EVENTSHPHLDBTNPRESS field.         */
  #define MAIN_EVENTSSHPHLDCLR_EVENTSHPHLDBTNPRESS_Max (0x1UL) /*!< Max enumerator value of EVENTSHPHLDBTNPRESS field.         */
  #define MAIN_EVENTSSHPHLDCLR_EVENTSHPHLDBTNPRESS_LOW (0x0UL) /*!< Low                                                        */
  #define MAIN_EVENTSSHPHLDCLR_EVENTSHPHLDBTNPRESS_HIGH (0x1UL) /*!< High                                                      */

/* EVENTSHPHLDBTNRELEASE @Bit 1 : SHPHLD button is released. Writing 1 clears the event (e.g. to acknowledge an interrupt). */
  #define MAIN_EVENTSSHPHLDCLR_EVENTSHPHLDBTNRELEASE_Pos (1UL) /*!< Position of EVENTSHPHLDBTNRELEASE field.                   */
  #define MAIN_EVENTSSHPHLDCLR_EVENTSHPHLDBTNRELEASE_Msk (0x1UL << MAIN_EVENTSSHPHLDCLR_EVENTSHPHLDBTNRELEASE_Pos) /*!< Bit mask
                                                                            of EVENTSHPHLDBTNRELEASE field.*/                     
  #define MAIN_EVENTSSHPHLDCLR_EVENTSHPHLDBTNRELEASE_Min (0x0UL) /*!< Min enumerator value of EVENTSHPHLDBTNRELEASE field.     */
  #define MAIN_EVENTSSHPHLDCLR_EVENTSHPHLDBTNRELEASE_Max (0x1UL) /*!< Max enumerator value of EVENTSHPHLDBTNRELEASE field.     */
  #define MAIN_EVENTSSHPHLDCLR_EVENTSHPHLDBTNRELEASE_LOW (0x0UL) /*!< Low                                                      */
  #define MAIN_EVENTSSHPHLDCLR_EVENTSHPHLDBTNRELEASE_HIGH (0x1UL) /*!< High                                                    */

/* EVENTSHPHLDEXIT @Bit 2 : SHPHLD button held to exit Ship mode. Writing 1 clears the event (e.g. to acknowledge an interrupt).
                            */                                                                                                    
                                                                                                                                  
  #define MAIN_EVENTSSHPHLDCLR_EVENTSHPHLDEXIT_Pos (2UL) /*!< Position of EVENTSHPHLDEXIT field.                               */
  #define MAIN_EVENTSSHPHLDCLR_EVENTSHPHLDEXIT_Msk (0x1UL << MAIN_EVENTSSHPHLDCLR_EVENTSHPHLDEXIT_Pos) /*!< Bit mask of
                                                                            EVENTSHPHLDEXIT field.*/                              
  #define MAIN_EVENTSSHPHLDCLR_EVENTSHPHLDEXIT_Min (0x0UL) /*!< Min enumerator value of EVENTSHPHLDEXIT field.                 */
  #define MAIN_EVENTSSHPHLDCLR_EVENTSHPHLDEXIT_Max (0x1UL) /*!< Max enumerator value of EVENTSHPHLDEXIT field.                 */
  #define MAIN_EVENTSSHPHLDCLR_EVENTSHPHLDEXIT_LOW (0x0UL) /*!< Low                                                            */
  #define MAIN_EVENTSSHPHLDCLR_EVENTSHPHLDEXIT_HIGH (0x1UL) /*!< High                                                          */

/* EVENTWATCHDOGWARN @Bit 3 : Watchdog timeout warning. Writing 1 clears the event (e.g. to acknowledge an interrupt). */
  #define MAIN_EVENTSSHPHLDCLR_EVENTWATCHDOGWARN_Pos (3UL) /*!< Position of EVENTWATCHDOGWARN field.                           */
  #define MAIN_EVENTSSHPHLDCLR_EVENTWATCHDOGWARN_Msk (0x1UL << MAIN_EVENTSSHPHLDCLR_EVENTWATCHDOGWARN_Pos) /*!< Bit mask of
                                                                            EVENTWATCHDOGWARN field.*/                            
  #define MAIN_EVENTSSHPHLDCLR_EVENTWATCHDOGWARN_Min (0x0UL) /*!< Min enumerator value of EVENTWATCHDOGWARN field.             */
  #define MAIN_EVENTSSHPHLDCLR_EVENTWATCHDOGWARN_Max (0x1UL) /*!< Max enumerator value of EVENTWATCHDOGWARN field.             */
  #define MAIN_EVENTSSHPHLDCLR_EVENTWATCHDOGWARN_LOW (0x0UL) /*!< Low                                                          */
  #define MAIN_EVENTSSHPHLDCLR_EVENTWATCHDOGWARN_HIGH (0x1UL) /*!< High                                                        */


/* MAIN_INTENEVENTSSHPHLDSET: SHPHLD pin and watchdog Interrupt Enable Set */
  #define MAIN_INTENEVENTSSHPHLDSET_ResetValue (0x00UL) /*!< Reset value of INTENEVENTSSHPHLDSET register.                     */

/* EVENTSHPHLDBTNPRESS @Bit 0 : Writing 1 enables interrupts from EVENTSHPHLDBTNPRESS */
  #define MAIN_INTENEVENTSSHPHLDSET_EVENTSHPHLDBTNPRESS_Pos (0UL) /*!< Position of EVENTSHPHLDBTNPRESS field.                  */
  #define MAIN_INTENEVENTSSHPHLDSET_EVENTSHPHLDBTNPRESS_Msk (0x1UL << MAIN_INTENEVENTSSHPHLDSET_EVENTSHPHLDBTNPRESS_Pos) /*!<
                                                                            Bit mask of EVENTSHPHLDBTNPRESS field.*/              
  #define MAIN_INTENEVENTSSHPHLDSET_EVENTSHPHLDBTNPRESS_Min (0x0UL) /*!< Min enumerator value of EVENTSHPHLDBTNPRESS field.    */
  #define MAIN_INTENEVENTSSHPHLDSET_EVENTSHPHLDBTNPRESS_Max (0x1UL) /*!< Max enumerator value of EVENTSHPHLDBTNPRESS field.    */
  #define MAIN_INTENEVENTSSHPHLDSET_EVENTSHPHLDBTNPRESS_LOW (0x0UL) /*!< Low                                                   */
  #define MAIN_INTENEVENTSSHPHLDSET_EVENTSHPHLDBTNPRESS_HIGH (0x1UL) /*!< High                                                 */

/* EVENTSHPHLDBTNRELEASE @Bit 1 : Writing 1 enables interrupts from EVENTSHPHLDBTNRELEASE */
  #define MAIN_INTENEVENTSSHPHLDSET_EVENTSHPHLDBTNRELEASE_Pos (1UL) /*!< Position of EVENTSHPHLDBTNRELEASE field.              */
  #define MAIN_INTENEVENTSSHPHLDSET_EVENTSHPHLDBTNRELEASE_Msk (0x1UL << MAIN_INTENEVENTSSHPHLDSET_EVENTSHPHLDBTNRELEASE_Pos)
                                                                            /*!< Bit mask of EVENTSHPHLDBTNRELEASE field.*/       
  #define MAIN_INTENEVENTSSHPHLDSET_EVENTSHPHLDBTNRELEASE_Min (0x0UL) /*!< Min enumerator value of EVENTSHPHLDBTNRELEASE field.*/
  #define MAIN_INTENEVENTSSHPHLDSET_EVENTSHPHLDBTNRELEASE_Max (0x1UL) /*!< Max enumerator value of EVENTSHPHLDBTNRELEASE field.*/
  #define MAIN_INTENEVENTSSHPHLDSET_EVENTSHPHLDBTNRELEASE_LOW (0x0UL) /*!< Low                                                 */
  #define MAIN_INTENEVENTSSHPHLDSET_EVENTSHPHLDBTNRELEASE_HIGH (0x1UL) /*!< High                                               */

/* EVENTSHPHLDEXIT @Bit 2 : Writing 1 enables interrupts from EVENTSHPHLDEXIT */
  #define MAIN_INTENEVENTSSHPHLDSET_EVENTSHPHLDEXIT_Pos (2UL) /*!< Position of EVENTSHPHLDEXIT field.                          */
  #define MAIN_INTENEVENTSSHPHLDSET_EVENTSHPHLDEXIT_Msk (0x1UL << MAIN_INTENEVENTSSHPHLDSET_EVENTSHPHLDEXIT_Pos) /*!< Bit mask
                                                                            of EVENTSHPHLDEXIT field.*/                           
  #define MAIN_INTENEVENTSSHPHLDSET_EVENTSHPHLDEXIT_Min (0x0UL) /*!< Min enumerator value of EVENTSHPHLDEXIT field.            */
  #define MAIN_INTENEVENTSSHPHLDSET_EVENTSHPHLDEXIT_Max (0x1UL) /*!< Max enumerator value of EVENTSHPHLDEXIT field.            */
  #define MAIN_INTENEVENTSSHPHLDSET_EVENTSHPHLDEXIT_LOW (0x0UL) /*!< Low                                                       */
  #define MAIN_INTENEVENTSSHPHLDSET_EVENTSHPHLDEXIT_HIGH (0x1UL) /*!< High                                                     */

/* EVENTWATCHDOGWARN @Bit 3 : Writing 1 enables interrupts from EVENTWATCHDOGWARN */
  #define MAIN_INTENEVENTSSHPHLDSET_EVENTWATCHDOGWARN_Pos (3UL) /*!< Position of EVENTWATCHDOGWARN field.                      */
  #define MAIN_INTENEVENTSSHPHLDSET_EVENTWATCHDOGWARN_Msk (0x1UL << MAIN_INTENEVENTSSHPHLDSET_EVENTWATCHDOGWARN_Pos) /*!< Bit
                                                                            mask of EVENTWATCHDOGWARN field.*/                    
  #define MAIN_INTENEVENTSSHPHLDSET_EVENTWATCHDOGWARN_Min (0x0UL) /*!< Min enumerator value of EVENTWATCHDOGWARN field.        */
  #define MAIN_INTENEVENTSSHPHLDSET_EVENTWATCHDOGWARN_Max (0x1UL) /*!< Max enumerator value of EVENTWATCHDOGWARN field.        */
  #define MAIN_INTENEVENTSSHPHLDSET_EVENTWATCHDOGWARN_LOW (0x0UL) /*!< Low                                                     */
  #define MAIN_INTENEVENTSSHPHLDSET_EVENTWATCHDOGWARN_HIGH (0x1UL) /*!< High                                                   */


/* MAIN_INTENEVENTSSHPHLDCLR: SHPHLD pin and watchdog Interrupt Enable Clear */
  #define MAIN_INTENEVENTSSHPHLDCLR_ResetValue (0x00UL) /*!< Reset value of INTENEVENTSSHPHLDCLR register.                     */

/* EVENTSHPHLDBTNPRESS @Bit 0 : Writing 1 disables interrupts from EVENTSHPHLDBTNPRESS */
  #define MAIN_INTENEVENTSSHPHLDCLR_EVENTSHPHLDBTNPRESS_Pos (0UL) /*!< Position of EVENTSHPHLDBTNPRESS field.                  */
  #define MAIN_INTENEVENTSSHPHLDCLR_EVENTSHPHLDBTNPRESS_Msk (0x1UL << MAIN_INTENEVENTSSHPHLDCLR_EVENTSHPHLDBTNPRESS_Pos) /*!<
                                                                            Bit mask of EVENTSHPHLDBTNPRESS field.*/              
  #define MAIN_INTENEVENTSSHPHLDCLR_EVENTSHPHLDBTNPRESS_Min (0x0UL) /*!< Min enumerator value of EVENTSHPHLDBTNPRESS field.    */
  #define MAIN_INTENEVENTSSHPHLDCLR_EVENTSHPHLDBTNPRESS_Max (0x1UL) /*!< Max enumerator value of EVENTSHPHLDBTNPRESS field.    */
  #define MAIN_INTENEVENTSSHPHLDCLR_EVENTSHPHLDBTNPRESS_LOW (0x0UL) /*!< Low                                                   */
  #define MAIN_INTENEVENTSSHPHLDCLR_EVENTSHPHLDBTNPRESS_HIGH (0x1UL) /*!< High                                                 */

/* EVENTSHPHLDBTNRELEASE @Bit 1 : Writing 1 disables interrupts from EVENTSHPHLDBTNRELEASE */
  #define MAIN_INTENEVENTSSHPHLDCLR_EVENTSHPHLDBTNRELEASE_Pos (1UL) /*!< Position of EVENTSHPHLDBTNRELEASE field.              */
  #define MAIN_INTENEVENTSSHPHLDCLR_EVENTSHPHLDBTNRELEASE_Msk (0x1UL << MAIN_INTENEVENTSSHPHLDCLR_EVENTSHPHLDBTNRELEASE_Pos)
                                                                            /*!< Bit mask of EVENTSHPHLDBTNRELEASE field.*/       
  #define MAIN_INTENEVENTSSHPHLDCLR_EVENTSHPHLDBTNRELEASE_Min (0x0UL) /*!< Min enumerator value of EVENTSHPHLDBTNRELEASE field.*/
  #define MAIN_INTENEVENTSSHPHLDCLR_EVENTSHPHLDBTNRELEASE_Max (0x1UL) /*!< Max enumerator value of EVENTSHPHLDBTNRELEASE field.*/
  #define MAIN_INTENEVENTSSHPHLDCLR_EVENTSHPHLDBTNRELEASE_LOW (0x0UL) /*!< Low                                                 */
  #define MAIN_INTENEVENTSSHPHLDCLR_EVENTSHPHLDBTNRELEASE_HIGH (0x1UL) /*!< High                                               */

/* EVENTSHPHLDEXIT @Bit 2 : Writing 1 disables interrupts from EVENTSHPHLDEXIT */
  #define MAIN_INTENEVENTSSHPHLDCLR_EVENTSHPHLDEXIT_Pos (2UL) /*!< Position of EVENTSHPHLDEXIT field.                          */
  #define MAIN_INTENEVENTSSHPHLDCLR_EVENTSHPHLDEXIT_Msk (0x1UL << MAIN_INTENEVENTSSHPHLDCLR_EVENTSHPHLDEXIT_Pos) /*!< Bit mask
                                                                            of EVENTSHPHLDEXIT field.*/                           
  #define MAIN_INTENEVENTSSHPHLDCLR_EVENTSHPHLDEXIT_Min (0x0UL) /*!< Min enumerator value of EVENTSHPHLDEXIT field.            */
  #define MAIN_INTENEVENTSSHPHLDCLR_EVENTSHPHLDEXIT_Max (0x1UL) /*!< Max enumerator value of EVENTSHPHLDEXIT field.            */
  #define MAIN_INTENEVENTSSHPHLDCLR_EVENTSHPHLDEXIT_LOW (0x0UL) /*!< Low                                                       */
  #define MAIN_INTENEVENTSSHPHLDCLR_EVENTSHPHLDEXIT_HIGH (0x1UL) /*!< High                                                     */

/* EVENTWATCHDOGWARN @Bit 3 : Writing 1 disables interrupts from EVENTWATCHDOGWARN */
  #define MAIN_INTENEVENTSSHPHLDCLR_EVENTWATCHDOGWARN_Pos (3UL) /*!< Position of EVENTWATCHDOGWARN field.                      */
  #define MAIN_INTENEVENTSSHPHLDCLR_EVENTWATCHDOGWARN_Msk (0x1UL << MAIN_INTENEVENTSSHPHLDCLR_EVENTWATCHDOGWARN_Pos) /*!< Bit
                                                                            mask of EVENTWATCHDOGWARN field.*/                    
  #define MAIN_INTENEVENTSSHPHLDCLR_EVENTWATCHDOGWARN_Min (0x0UL) /*!< Min enumerator value of EVENTWATCHDOGWARN field.        */
  #define MAIN_INTENEVENTSSHPHLDCLR_EVENTWATCHDOGWARN_Max (0x1UL) /*!< Max enumerator value of EVENTWATCHDOGWARN field.        */
  #define MAIN_INTENEVENTSSHPHLDCLR_EVENTWATCHDOGWARN_LOW (0x0UL) /*!< Low                                                     */
  #define MAIN_INTENEVENTSSHPHLDCLR_EVENTWATCHDOGWARN_HIGH (0x1UL) /*!< High                                                   */


/* MAIN_EVENTSVBUSIN0SET: VBUS Event Set */
  #define MAIN_EVENTSVBUSIN0SET_ResetValue (0x00UL)  /*!< Reset value of EVENTSVBUSIN0SET register.                            */

/* EVENTVBUSDETECTED @Bit 0 : VBUS detected. Writing 1 sets the event (for debugging). */
  #define MAIN_EVENTSVBUSIN0SET_EVENTVBUSDETECTED_Pos (0UL) /*!< Position of EVENTVBUSDETECTED field.                          */
  #define MAIN_EVENTSVBUSIN0SET_EVENTVBUSDETECTED_Msk (0x1UL << MAIN_EVENTSVBUSIN0SET_EVENTVBUSDETECTED_Pos) /*!< Bit mask of
                                                                            EVENTVBUSDETECTED field.*/                            
  #define MAIN_EVENTSVBUSIN0SET_EVENTVBUSDETECTED_Min (0x0UL) /*!< Min enumerator value of EVENTVBUSDETECTED field.            */
  #define MAIN_EVENTSVBUSIN0SET_EVENTVBUSDETECTED_Max (0x1UL) /*!< Max enumerator value of EVENTVBUSDETECTED field.            */
  #define MAIN_EVENTSVBUSIN0SET_EVENTVBUSDETECTED_LOW (0x0UL) /*!< Low                                                         */
  #define MAIN_EVENTSVBUSIN0SET_EVENTVBUSDETECTED_HIGH (0x1UL) /*!< High                                                       */

/* EVENTVBUSREMOVED @Bit 1 : VBUS removed. Writing 1 sets the event (for debugging). */
  #define MAIN_EVENTSVBUSIN0SET_EVENTVBUSREMOVED_Pos (1UL) /*!< Position of EVENTVBUSREMOVED field.                            */
  #define MAIN_EVENTSVBUSIN0SET_EVENTVBUSREMOVED_Msk (0x1UL << MAIN_EVENTSVBUSIN0SET_EVENTVBUSREMOVED_Pos) /*!< Bit mask of
                                                                            EVENTVBUSREMOVED field.*/                             
  #define MAIN_EVENTSVBUSIN0SET_EVENTVBUSREMOVED_Min (0x0UL) /*!< Min enumerator value of EVENTVBUSREMOVED field.              */
  #define MAIN_EVENTSVBUSIN0SET_EVENTVBUSREMOVED_Max (0x1UL) /*!< Max enumerator value of EVENTVBUSREMOVED field.              */
  #define MAIN_EVENTSVBUSIN0SET_EVENTVBUSREMOVED_LOW (0x0UL) /*!< Low                                                          */
  #define MAIN_EVENTSVBUSIN0SET_EVENTVBUSREMOVED_HIGH (0x1UL) /*!< High                                                        */

/* EVENTVBUSOVRVOLTDETECTED @Bit 2 : VBUS over voltage detected. Writing 1 sets the event (for debugging). */
  #define MAIN_EVENTSVBUSIN0SET_EVENTVBUSOVRVOLTDETECTED_Pos (2UL) /*!< Position of EVENTVBUSOVRVOLTDETECTED field.            */
  #define MAIN_EVENTSVBUSIN0SET_EVENTVBUSOVRVOLTDETECTED_Msk (0x1UL << MAIN_EVENTSVBUSIN0SET_EVENTVBUSOVRVOLTDETECTED_Pos) /*!<
                                                                            Bit mask of EVENTVBUSOVRVOLTDETECTED field.*/         
  #define MAIN_EVENTSVBUSIN0SET_EVENTVBUSOVRVOLTDETECTED_Min (0x0UL) /*!< Min enumerator value of EVENTVBUSOVRVOLTDETECTED
                                                                          field.*/                                                
  #define MAIN_EVENTSVBUSIN0SET_EVENTVBUSOVRVOLTDETECTED_Max (0x1UL) /*!< Max enumerator value of EVENTVBUSOVRVOLTDETECTED
                                                                          field.*/                                                
  #define MAIN_EVENTSVBUSIN0SET_EVENTVBUSOVRVOLTDETECTED_LOW (0x0UL) /*!< Low                                                  */
  #define MAIN_EVENTSVBUSIN0SET_EVENTVBUSOVRVOLTDETECTED_HIGH (0x1UL) /*!< High                                                */

/* EVENTVBUSOVRVOLTREMOVED @Bit 3 : VBUS over voltage removed. Writing 1 sets the event (for debugging). */
  #define MAIN_EVENTSVBUSIN0SET_EVENTVBUSOVRVOLTREMOVED_Pos (3UL) /*!< Position of EVENTVBUSOVRVOLTREMOVED field.              */
  #define MAIN_EVENTSVBUSIN0SET_EVENTVBUSOVRVOLTREMOVED_Msk (0x1UL << MAIN_EVENTSVBUSIN0SET_EVENTVBUSOVRVOLTREMOVED_Pos) /*!<
                                                                            Bit mask of EVENTVBUSOVRVOLTREMOVED field.*/          
  #define MAIN_EVENTSVBUSIN0SET_EVENTVBUSOVRVOLTREMOVED_Min (0x0UL) /*!< Min enumerator value of EVENTVBUSOVRVOLTREMOVED field.*/
  #define MAIN_EVENTSVBUSIN0SET_EVENTVBUSOVRVOLTREMOVED_Max (0x1UL) /*!< Max enumerator value of EVENTVBUSOVRVOLTREMOVED field.*/
  #define MAIN_EVENTSVBUSIN0SET_EVENTVBUSOVRVOLTREMOVED_LOW (0x0UL) /*!< Low                                                   */
  #define MAIN_EVENTSVBUSIN0SET_EVENTVBUSOVRVOLTREMOVED_HIGH (0x1UL) /*!< High                                                 */

/* EVENTVBUSUNDVOLTDETECTED @Bit 4 : VBUS under voltage detected. Writing 1 sets the event (for debugging). */
  #define MAIN_EVENTSVBUSIN0SET_EVENTVBUSUNDVOLTDETECTED_Pos (4UL) /*!< Position of EVENTVBUSUNDVOLTDETECTED field.            */
  #define MAIN_EVENTSVBUSIN0SET_EVENTVBUSUNDVOLTDETECTED_Msk (0x1UL << MAIN_EVENTSVBUSIN0SET_EVENTVBUSUNDVOLTDETECTED_Pos) /*!<
                                                                            Bit mask of EVENTVBUSUNDVOLTDETECTED field.*/         
  #define MAIN_EVENTSVBUSIN0SET_EVENTVBUSUNDVOLTDETECTED_Min (0x0UL) /*!< Min enumerator value of EVENTVBUSUNDVOLTDETECTED
                                                                          field.*/                                                
  #define MAIN_EVENTSVBUSIN0SET_EVENTVBUSUNDVOLTDETECTED_Max (0x1UL) /*!< Max enumerator value of EVENTVBUSUNDVOLTDETECTED
                                                                          field.*/                                                
  #define MAIN_EVENTSVBUSIN0SET_EVENTVBUSUNDVOLTDETECTED_LOW (0x0UL) /*!< Low                                                  */
  #define MAIN_EVENTSVBUSIN0SET_EVENTVBUSUNDVOLTDETECTED_HIGH (0x1UL) /*!< High                                                */

/* EVENTVBUSUNDVOLTREMOVED @Bit 5 : VBUS under voltage removed. Writing 1 sets the event (for debugging). */
  #define MAIN_EVENTSVBUSIN0SET_EVENTVBUSUNDVOLTREMOVED_Pos (5UL) /*!< Position of EVENTVBUSUNDVOLTREMOVED field.              */
  #define MAIN_EVENTSVBUSIN0SET_EVENTVBUSUNDVOLTREMOVED_Msk (0x1UL << MAIN_EVENTSVBUSIN0SET_EVENTVBUSUNDVOLTREMOVED_Pos) /*!<
                                                                            Bit mask of EVENTVBUSUNDVOLTREMOVED field.*/          
  #define MAIN_EVENTSVBUSIN0SET_EVENTVBUSUNDVOLTREMOVED_Min (0x0UL) /*!< Min enumerator value of EVENTVBUSUNDVOLTREMOVED field.*/
  #define MAIN_EVENTSVBUSIN0SET_EVENTVBUSUNDVOLTREMOVED_Max (0x1UL) /*!< Max enumerator value of EVENTVBUSUNDVOLTREMOVED field.*/
  #define MAIN_EVENTSVBUSIN0SET_EVENTVBUSUNDVOLTREMOVED_LOW (0x0UL) /*!< Low                                                   */
  #define MAIN_EVENTSVBUSIN0SET_EVENTVBUSUNDVOLTREMOVED_HIGH (0x1UL) /*!< High                                                 */


/* MAIN_EVENTSVBUSIN0CLR: VBUS Event Clear */
  #define MAIN_EVENTSVBUSIN0CLR_ResetValue (0x00UL)  /*!< Reset value of EVENTSVBUSIN0CLR register.                            */

/* EVENTVBUSDETECTED @Bit 0 : VBUS detected. Writing 1 clears the event (e.g. to acknowledge an interrupt). */
  #define MAIN_EVENTSVBUSIN0CLR_EVENTVBUSDETECTED_Pos (0UL) /*!< Position of EVENTVBUSDETECTED field.                          */
  #define MAIN_EVENTSVBUSIN0CLR_EVENTVBUSDETECTED_Msk (0x1UL << MAIN_EVENTSVBUSIN0CLR_EVENTVBUSDETECTED_Pos) /*!< Bit mask of
                                                                            EVENTVBUSDETECTED field.*/                            
  #define MAIN_EVENTSVBUSIN0CLR_EVENTVBUSDETECTED_Min (0x0UL) /*!< Min enumerator value of EVENTVBUSDETECTED field.            */
  #define MAIN_EVENTSVBUSIN0CLR_EVENTVBUSDETECTED_Max (0x1UL) /*!< Max enumerator value of EVENTVBUSDETECTED field.            */
  #define MAIN_EVENTSVBUSIN0CLR_EVENTVBUSDETECTED_LOW (0x0UL) /*!< Low                                                         */
  #define MAIN_EVENTSVBUSIN0CLR_EVENTVBUSDETECTED_HIGH (0x1UL) /*!< High                                                       */

/* EVENTVBUSREMOVED @Bit 1 : VBUS removed. Writing 1 clears the event (e.g. to acknowledge an interrupt). */
  #define MAIN_EVENTSVBUSIN0CLR_EVENTVBUSREMOVED_Pos (1UL) /*!< Position of EVENTVBUSREMOVED field.                            */
  #define MAIN_EVENTSVBUSIN0CLR_EVENTVBUSREMOVED_Msk (0x1UL << MAIN_EVENTSVBUSIN0CLR_EVENTVBUSREMOVED_Pos) /*!< Bit mask of
                                                                            EVENTVBUSREMOVED field.*/                             
  #define MAIN_EVENTSVBUSIN0CLR_EVENTVBUSREMOVED_Min (0x0UL) /*!< Min enumerator value of EVENTVBUSREMOVED field.              */
  #define MAIN_EVENTSVBUSIN0CLR_EVENTVBUSREMOVED_Max (0x1UL) /*!< Max enumerator value of EVENTVBUSREMOVED field.              */
  #define MAIN_EVENTSVBUSIN0CLR_EVENTVBUSREMOVED_LOW (0x0UL) /*!< Low                                                          */
  #define MAIN_EVENTSVBUSIN0CLR_EVENTVBUSREMOVED_HIGH (0x1UL) /*!< High                                                        */

/* EVENTVBUSOVRVOLTDETECTED @Bit 2 : VBUS over voltage detected. Writing 1 clears the event (e.g. to acknowledge an interrupt).
                                     */                                                                                           
                                                                                                                                  
  #define MAIN_EVENTSVBUSIN0CLR_EVENTVBUSOVRVOLTDETECTED_Pos (2UL) /*!< Position of EVENTVBUSOVRVOLTDETECTED field.            */
  #define MAIN_EVENTSVBUSIN0CLR_EVENTVBUSOVRVOLTDETECTED_Msk (0x1UL << MAIN_EVENTSVBUSIN0CLR_EVENTVBUSOVRVOLTDETECTED_Pos) /*!<
                                                                            Bit mask of EVENTVBUSOVRVOLTDETECTED field.*/         
  #define MAIN_EVENTSVBUSIN0CLR_EVENTVBUSOVRVOLTDETECTED_Min (0x0UL) /*!< Min enumerator value of EVENTVBUSOVRVOLTDETECTED
                                                                          field.*/                                                
  #define MAIN_EVENTSVBUSIN0CLR_EVENTVBUSOVRVOLTDETECTED_Max (0x1UL) /*!< Max enumerator value of EVENTVBUSOVRVOLTDETECTED
                                                                          field.*/                                                
  #define MAIN_EVENTSVBUSIN0CLR_EVENTVBUSOVRVOLTDETECTED_LOW (0x0UL) /*!< Low                                                  */
  #define MAIN_EVENTSVBUSIN0CLR_EVENTVBUSOVRVOLTDETECTED_HIGH (0x1UL) /*!< High                                                */

/* EVENTVBUSOVRVOLTREMOVED @Bit 3 : VBUS over voltage removed. Writing 1 clears the event (e.g. to acknowledge an interrupt). */
  #define MAIN_EVENTSVBUSIN0CLR_EVENTVBUSOVRVOLTREMOVED_Pos (3UL) /*!< Position of EVENTVBUSOVRVOLTREMOVED field.              */
  #define MAIN_EVENTSVBUSIN0CLR_EVENTVBUSOVRVOLTREMOVED_Msk (0x1UL << MAIN_EVENTSVBUSIN0CLR_EVENTVBUSOVRVOLTREMOVED_Pos) /*!<
                                                                            Bit mask of EVENTVBUSOVRVOLTREMOVED field.*/          
  #define MAIN_EVENTSVBUSIN0CLR_EVENTVBUSOVRVOLTREMOVED_Min (0x0UL) /*!< Min enumerator value of EVENTVBUSOVRVOLTREMOVED field.*/
  #define MAIN_EVENTSVBUSIN0CLR_EVENTVBUSOVRVOLTREMOVED_Max (0x1UL) /*!< Max enumerator value of EVENTVBUSOVRVOLTREMOVED field.*/
  #define MAIN_EVENTSVBUSIN0CLR_EVENTVBUSOVRVOLTREMOVED_LOW (0x0UL) /*!< Low                                                   */
  #define MAIN_EVENTSVBUSIN0CLR_EVENTVBUSOVRVOLTREMOVED_HIGH (0x1UL) /*!< High                                                 */

/* EVENTVBUSUNDVOLTDETECTED @Bit 4 : VBUS under voltage detected. Writing 1 clears the event (e.g. to acknowledge an interrupt).
                                     */                                                                                           
                                                                                                                                  
  #define MAIN_EVENTSVBUSIN0CLR_EVENTVBUSUNDVOLTDETECTED_Pos (4UL) /*!< Position of EVENTVBUSUNDVOLTDETECTED field.            */
  #define MAIN_EVENTSVBUSIN0CLR_EVENTVBUSUNDVOLTDETECTED_Msk (0x1UL << MAIN_EVENTSVBUSIN0CLR_EVENTVBUSUNDVOLTDETECTED_Pos) /*!<
                                                                            Bit mask of EVENTVBUSUNDVOLTDETECTED field.*/         
  #define MAIN_EVENTSVBUSIN0CLR_EVENTVBUSUNDVOLTDETECTED_Min (0x0UL) /*!< Min enumerator value of EVENTVBUSUNDVOLTDETECTED
                                                                          field.*/                                                
  #define MAIN_EVENTSVBUSIN0CLR_EVENTVBUSUNDVOLTDETECTED_Max (0x1UL) /*!< Max enumerator value of EVENTVBUSUNDVOLTDETECTED
                                                                          field.*/                                                
  #define MAIN_EVENTSVBUSIN0CLR_EVENTVBUSUNDVOLTDETECTED_LOW (0x0UL) /*!< Low                                                  */
  #define MAIN_EVENTSVBUSIN0CLR_EVENTVBUSUNDVOLTDETECTED_HIGH (0x1UL) /*!< High                                                */

/* EVENTVBUSUNDVOLTREMOVED @Bit 5 : VBUS under voltage removed. Writing 1 clears the event (e.g. to acknowledge an interrupt). */
  #define MAIN_EVENTSVBUSIN0CLR_EVENTVBUSUNDVOLTREMOVED_Pos (5UL) /*!< Position of EVENTVBUSUNDVOLTREMOVED field.              */
  #define MAIN_EVENTSVBUSIN0CLR_EVENTVBUSUNDVOLTREMOVED_Msk (0x1UL << MAIN_EVENTSVBUSIN0CLR_EVENTVBUSUNDVOLTREMOVED_Pos) /*!<
                                                                            Bit mask of EVENTVBUSUNDVOLTREMOVED field.*/          
  #define MAIN_EVENTSVBUSIN0CLR_EVENTVBUSUNDVOLTREMOVED_Min (0x0UL) /*!< Min enumerator value of EVENTVBUSUNDVOLTREMOVED field.*/
  #define MAIN_EVENTSVBUSIN0CLR_EVENTVBUSUNDVOLTREMOVED_Max (0x1UL) /*!< Max enumerator value of EVENTVBUSUNDVOLTREMOVED field.*/
  #define MAIN_EVENTSVBUSIN0CLR_EVENTVBUSUNDVOLTREMOVED_LOW (0x0UL) /*!< Low                                                   */
  #define MAIN_EVENTSVBUSIN0CLR_EVENTVBUSUNDVOLTREMOVED_HIGH (0x1UL) /*!< High                                                 */


/* MAIN_INTENEVENTSVBUSIN0SET: VBUS Interrupt Enable Set */
  #define MAIN_INTENEVENTSVBUSIN0SET_ResetValue (0x00UL) /*!< Reset value of INTENEVENTSVBUSIN0SET register.                   */

/* EVENTVBUSDETECTED @Bit 0 : Writing 1 enables interrupts from EVENTVBUSDETECTED */
  #define MAIN_INTENEVENTSVBUSIN0SET_EVENTVBUSDETECTED_Pos (0UL) /*!< Position of EVENTVBUSDETECTED field.                     */
  #define MAIN_INTENEVENTSVBUSIN0SET_EVENTVBUSDETECTED_Msk (0x1UL << MAIN_INTENEVENTSVBUSIN0SET_EVENTVBUSDETECTED_Pos) /*!< Bit
                                                                            mask of EVENTVBUSDETECTED field.*/                    
  #define MAIN_INTENEVENTSVBUSIN0SET_EVENTVBUSDETECTED_Min (0x0UL) /*!< Min enumerator value of EVENTVBUSDETECTED field.       */
  #define MAIN_INTENEVENTSVBUSIN0SET_EVENTVBUSDETECTED_Max (0x1UL) /*!< Max enumerator value of EVENTVBUSDETECTED field.       */
  #define MAIN_INTENEVENTSVBUSIN0SET_EVENTVBUSDETECTED_LOW (0x0UL) /*!< Low                                                    */
  #define MAIN_INTENEVENTSVBUSIN0SET_EVENTVBUSDETECTED_HIGH (0x1UL) /*!< High                                                  */

/* EVENTVBUSREMOVED @Bit 1 : Writing 1 enables interrupts from EVENTVBUSREMOVED */
  #define MAIN_INTENEVENTSVBUSIN0SET_EVENTVBUSREMOVED_Pos (1UL) /*!< Position of EVENTVBUSREMOVED field.                       */
  #define MAIN_INTENEVENTSVBUSIN0SET_EVENTVBUSREMOVED_Msk (0x1UL << MAIN_INTENEVENTSVBUSIN0SET_EVENTVBUSREMOVED_Pos) /*!< Bit
                                                                            mask of EVENTVBUSREMOVED field.*/                     
  #define MAIN_INTENEVENTSVBUSIN0SET_EVENTVBUSREMOVED_Min (0x0UL) /*!< Min enumerator value of EVENTVBUSREMOVED field.         */
  #define MAIN_INTENEVENTSVBUSIN0SET_EVENTVBUSREMOVED_Max (0x1UL) /*!< Max enumerator value of EVENTVBUSREMOVED field.         */
  #define MAIN_INTENEVENTSVBUSIN0SET_EVENTVBUSREMOVED_LOW (0x0UL) /*!< Low                                                     */
  #define MAIN_INTENEVENTSVBUSIN0SET_EVENTVBUSREMOVED_HIGH (0x1UL) /*!< High                                                   */

/* EVENTVBUSOVRVOLTDETECTED @Bit 2 : Writing 1 enables interrupts from EVENTVBUSOVRVOLTDETECTED */
  #define MAIN_INTENEVENTSVBUSIN0SET_EVENTVBUSOVRVOLTDETECTED_Pos (2UL) /*!< Position of EVENTVBUSOVRVOLTDETECTED field.       */
  #define MAIN_INTENEVENTSVBUSIN0SET_EVENTVBUSOVRVOLTDETECTED_Msk (0x1UL << MAIN_INTENEVENTSVBUSIN0SET_EVENTVBUSOVRVOLTDETECTED_Pos)
                                                                            /*!< Bit mask of EVENTVBUSOVRVOLTDETECTED field.*/    
  #define MAIN_INTENEVENTSVBUSIN0SET_EVENTVBUSOVRVOLTDETECTED_Min (0x0UL) /*!< Min enumerator value of EVENTVBUSOVRVOLTDETECTED
                                                                            field.*/                                              
  #define MAIN_INTENEVENTSVBUSIN0SET_EVENTVBUSOVRVOLTDETECTED_Max (0x1UL) /*!< Max enumerator value of EVENTVBUSOVRVOLTDETECTED
                                                                            field.*/                                              
  #define MAIN_INTENEVENTSVBUSIN0SET_EVENTVBUSOVRVOLTDETECTED_LOW (0x0UL) /*!< Low                                             */
  #define MAIN_INTENEVENTSVBUSIN0SET_EVENTVBUSOVRVOLTDETECTED_HIGH (0x1UL) /*!< High                                           */

/* EVENTVBUSOVRVOLTREMOVED @Bit 3 : Writing 1 enables interrupts from EVENTVBUSOVRVOLTREMOVED */
  #define MAIN_INTENEVENTSVBUSIN0SET_EVENTVBUSOVRVOLTREMOVED_Pos (3UL) /*!< Position of EVENTVBUSOVRVOLTREMOVED field.         */
  #define MAIN_INTENEVENTSVBUSIN0SET_EVENTVBUSOVRVOLTREMOVED_Msk (0x1UL << MAIN_INTENEVENTSVBUSIN0SET_EVENTVBUSOVRVOLTREMOVED_Pos)
                                                                            /*!< Bit mask of EVENTVBUSOVRVOLTREMOVED field.*/     
  #define MAIN_INTENEVENTSVBUSIN0SET_EVENTVBUSOVRVOLTREMOVED_Min (0x0UL) /*!< Min enumerator value of EVENTVBUSOVRVOLTREMOVED
                                                                            field.*/                                              
  #define MAIN_INTENEVENTSVBUSIN0SET_EVENTVBUSOVRVOLTREMOVED_Max (0x1UL) /*!< Max enumerator value of EVENTVBUSOVRVOLTREMOVED
                                                                            field.*/                                              
  #define MAIN_INTENEVENTSVBUSIN0SET_EVENTVBUSOVRVOLTREMOVED_LOW (0x0UL) /*!< Low                                              */
  #define MAIN_INTENEVENTSVBUSIN0SET_EVENTVBUSOVRVOLTREMOVED_HIGH (0x1UL) /*!< High                                            */

/* EVENTVBUSUNDVOLTDETECTED @Bit 4 : Writing 1 enables interrupts from EVENTVBUSUNDVOLTDETECTED */
  #define MAIN_INTENEVENTSVBUSIN0SET_EVENTVBUSUNDVOLTDETECTED_Pos (4UL) /*!< Position of EVENTVBUSUNDVOLTDETECTED field.       */
  #define MAIN_INTENEVENTSVBUSIN0SET_EVENTVBUSUNDVOLTDETECTED_Msk (0x1UL << MAIN_INTENEVENTSVBUSIN0SET_EVENTVBUSUNDVOLTDETECTED_Pos)
                                                                            /*!< Bit mask of EVENTVBUSUNDVOLTDETECTED field.*/    
  #define MAIN_INTENEVENTSVBUSIN0SET_EVENTVBUSUNDVOLTDETECTED_Min (0x0UL) /*!< Min enumerator value of EVENTVBUSUNDVOLTDETECTED
                                                                            field.*/                                              
  #define MAIN_INTENEVENTSVBUSIN0SET_EVENTVBUSUNDVOLTDETECTED_Max (0x1UL) /*!< Max enumerator value of EVENTVBUSUNDVOLTDETECTED
                                                                            field.*/                                              
  #define MAIN_INTENEVENTSVBUSIN0SET_EVENTVBUSUNDVOLTDETECTED_LOW (0x0UL) /*!< Low                                             */
  #define MAIN_INTENEVENTSVBUSIN0SET_EVENTVBUSUNDVOLTDETECTED_HIGH (0x1UL) /*!< High                                           */

/* EVENTVBUSUNDVOLTREMOVED @Bit 5 : Writing 1 enables interrupts from EVENTVBUSUNDVOLTREMOVED */
  #define MAIN_INTENEVENTSVBUSIN0SET_EVENTVBUSUNDVOLTREMOVED_Pos (5UL) /*!< Position of EVENTVBUSUNDVOLTREMOVED field.         */
  #define MAIN_INTENEVENTSVBUSIN0SET_EVENTVBUSUNDVOLTREMOVED_Msk (0x1UL << MAIN_INTENEVENTSVBUSIN0SET_EVENTVBUSUNDVOLTREMOVED_Pos)
                                                                            /*!< Bit mask of EVENTVBUSUNDVOLTREMOVED field.*/     
  #define MAIN_INTENEVENTSVBUSIN0SET_EVENTVBUSUNDVOLTREMOVED_Min (0x0UL) /*!< Min enumerator value of EVENTVBUSUNDVOLTREMOVED
                                                                            field.*/                                              
  #define MAIN_INTENEVENTSVBUSIN0SET_EVENTVBUSUNDVOLTREMOVED_Max (0x1UL) /*!< Max enumerator value of EVENTVBUSUNDVOLTREMOVED
                                                                            field.*/                                              
  #define MAIN_INTENEVENTSVBUSIN0SET_EVENTVBUSUNDVOLTREMOVED_LOW (0x0UL) /*!< Low                                              */
  #define MAIN_INTENEVENTSVBUSIN0SET_EVENTVBUSUNDVOLTREMOVED_HIGH (0x1UL) /*!< High                                            */


/* MAIN_INTENEVENTSVBUSIN0CLR: VBUS Interrupt Enable Clear */
  #define MAIN_INTENEVENTSVBUSIN0CLR_ResetValue (0x00UL) /*!< Reset value of INTENEVENTSVBUSIN0CLR register.                   */

/* EVENTVBUSDETECTED @Bit 0 : Writing 1 disables interrupts from EVENTVBUSDETECTED */
  #define MAIN_INTENEVENTSVBUSIN0CLR_EVENTVBUSDETECTED_Pos (0UL) /*!< Position of EVENTVBUSDETECTED field.                     */
  #define MAIN_INTENEVENTSVBUSIN0CLR_EVENTVBUSDETECTED_Msk (0x1UL << MAIN_INTENEVENTSVBUSIN0CLR_EVENTVBUSDETECTED_Pos) /*!< Bit
                                                                            mask of EVENTVBUSDETECTED field.*/                    
  #define MAIN_INTENEVENTSVBUSIN0CLR_EVENTVBUSDETECTED_Min (0x0UL) /*!< Min enumerator value of EVENTVBUSDETECTED field.       */
  #define MAIN_INTENEVENTSVBUSIN0CLR_EVENTVBUSDETECTED_Max (0x1UL) /*!< Max enumerator value of EVENTVBUSDETECTED field.       */
  #define MAIN_INTENEVENTSVBUSIN0CLR_EVENTVBUSDETECTED_LOW (0x0UL) /*!< Low                                                    */
  #define MAIN_INTENEVENTSVBUSIN0CLR_EVENTVBUSDETECTED_HIGH (0x1UL) /*!< High                                                  */

/* EVENTVBUSREMOVED @Bit 1 : Writing 1 disables interrupts from EVENTVBUSREMOVED */
  #define MAIN_INTENEVENTSVBUSIN0CLR_EVENTVBUSREMOVED_Pos (1UL) /*!< Position of EVENTVBUSREMOVED field.                       */
  #define MAIN_INTENEVENTSVBUSIN0CLR_EVENTVBUSREMOVED_Msk (0x1UL << MAIN_INTENEVENTSVBUSIN0CLR_EVENTVBUSREMOVED_Pos) /*!< Bit
                                                                            mask of EVENTVBUSREMOVED field.*/                     
  #define MAIN_INTENEVENTSVBUSIN0CLR_EVENTVBUSREMOVED_Min (0x0UL) /*!< Min enumerator value of EVENTVBUSREMOVED field.         */
  #define MAIN_INTENEVENTSVBUSIN0CLR_EVENTVBUSREMOVED_Max (0x1UL) /*!< Max enumerator value of EVENTVBUSREMOVED field.         */
  #define MAIN_INTENEVENTSVBUSIN0CLR_EVENTVBUSREMOVED_LOW (0x0UL) /*!< Low                                                     */
  #define MAIN_INTENEVENTSVBUSIN0CLR_EVENTVBUSREMOVED_HIGH (0x1UL) /*!< High                                                   */

/* EVENTVBUSOVRVOLTDETECTED @Bit 2 : Writing 1 disables interrupts from EVENTVBUSOVRVOLTDETECTED */
  #define MAIN_INTENEVENTSVBUSIN0CLR_EVENTVBUSOVRVOLTDETECTED_Pos (2UL) /*!< Position of EVENTVBUSOVRVOLTDETECTED field.       */
  #define MAIN_INTENEVENTSVBUSIN0CLR_EVENTVBUSOVRVOLTDETECTED_Msk (0x1UL << MAIN_INTENEVENTSVBUSIN0CLR_EVENTVBUSOVRVOLTDETECTED_Pos)
                                                                            /*!< Bit mask of EVENTVBUSOVRVOLTDETECTED field.*/    
  #define MAIN_INTENEVENTSVBUSIN0CLR_EVENTVBUSOVRVOLTDETECTED_Min (0x0UL) /*!< Min enumerator value of EVENTVBUSOVRVOLTDETECTED
                                                                            field.*/                                              
  #define MAIN_INTENEVENTSVBUSIN0CLR_EVENTVBUSOVRVOLTDETECTED_Max (0x1UL) /*!< Max enumerator value of EVENTVBUSOVRVOLTDETECTED
                                                                            field.*/                                              
  #define MAIN_INTENEVENTSVBUSIN0CLR_EVENTVBUSOVRVOLTDETECTED_LOW (0x0UL) /*!< Low                                             */
  #define MAIN_INTENEVENTSVBUSIN0CLR_EVENTVBUSOVRVOLTDETECTED_HIGH (0x1UL) /*!< High                                           */

/* EVENTVBUSOVRVOLTREMOVED @Bit 3 : Writing 1 disables interrupts from EVENTVBUSOVRVOLTREMOVED */
  #define MAIN_INTENEVENTSVBUSIN0CLR_EVENTVBUSOVRVOLTREMOVED_Pos (3UL) /*!< Position of EVENTVBUSOVRVOLTREMOVED field.         */
  #define MAIN_INTENEVENTSVBUSIN0CLR_EVENTVBUSOVRVOLTREMOVED_Msk (0x1UL << MAIN_INTENEVENTSVBUSIN0CLR_EVENTVBUSOVRVOLTREMOVED_Pos)
                                                                            /*!< Bit mask of EVENTVBUSOVRVOLTREMOVED field.*/     
  #define MAIN_INTENEVENTSVBUSIN0CLR_EVENTVBUSOVRVOLTREMOVED_Min (0x0UL) /*!< Min enumerator value of EVENTVBUSOVRVOLTREMOVED
                                                                            field.*/                                              
  #define MAIN_INTENEVENTSVBUSIN0CLR_EVENTVBUSOVRVOLTREMOVED_Max (0x1UL) /*!< Max enumerator value of EVENTVBUSOVRVOLTREMOVED
                                                                            field.*/                                              
  #define MAIN_INTENEVENTSVBUSIN0CLR_EVENTVBUSOVRVOLTREMOVED_LOW (0x0UL) /*!< Low                                              */
  #define MAIN_INTENEVENTSVBUSIN0CLR_EVENTVBUSOVRVOLTREMOVED_HIGH (0x1UL) /*!< High                                            */

/* EVENTVBUSUNDVOLTDETECTED @Bit 4 : Writing 1 disables interrupts from EVENTVBUSUNDVOLTDETECTED */
  #define MAIN_INTENEVENTSVBUSIN0CLR_EVENTVBUSUNDVOLTDETECTED_Pos (4UL) /*!< Position of EVENTVBUSUNDVOLTDETECTED field.       */
  #define MAIN_INTENEVENTSVBUSIN0CLR_EVENTVBUSUNDVOLTDETECTED_Msk (0x1UL << MAIN_INTENEVENTSVBUSIN0CLR_EVENTVBUSUNDVOLTDETECTED_Pos)
                                                                            /*!< Bit mask of EVENTVBUSUNDVOLTDETECTED field.*/    
  #define MAIN_INTENEVENTSVBUSIN0CLR_EVENTVBUSUNDVOLTDETECTED_Min (0x0UL) /*!< Min enumerator value of EVENTVBUSUNDVOLTDETECTED
                                                                            field.*/                                              
  #define MAIN_INTENEVENTSVBUSIN0CLR_EVENTVBUSUNDVOLTDETECTED_Max (0x1UL) /*!< Max enumerator value of EVENTVBUSUNDVOLTDETECTED
                                                                            field.*/                                              
  #define MAIN_INTENEVENTSVBUSIN0CLR_EVENTVBUSUNDVOLTDETECTED_LOW (0x0UL) /*!< Low                                             */
  #define MAIN_INTENEVENTSVBUSIN0CLR_EVENTVBUSUNDVOLTDETECTED_HIGH (0x1UL) /*!< High                                           */

/* EVENTVBUSUNDVOLTREMOVED @Bit 5 : Writing 1 disables interrupts from EVENTVBUSUNDVOLTREMOVED */
  #define MAIN_INTENEVENTSVBUSIN0CLR_EVENTVBUSUNDVOLTREMOVED_Pos (5UL) /*!< Position of EVENTVBUSUNDVOLTREMOVED field.         */
  #define MAIN_INTENEVENTSVBUSIN0CLR_EVENTVBUSUNDVOLTREMOVED_Msk (0x1UL << MAIN_INTENEVENTSVBUSIN0CLR_EVENTVBUSUNDVOLTREMOVED_Pos)
                                                                            /*!< Bit mask of EVENTVBUSUNDVOLTREMOVED field.*/     
  #define MAIN_INTENEVENTSVBUSIN0CLR_EVENTVBUSUNDVOLTREMOVED_Min (0x0UL) /*!< Min enumerator value of EVENTVBUSUNDVOLTREMOVED
                                                                            field.*/                                              
  #define MAIN_INTENEVENTSVBUSIN0CLR_EVENTVBUSUNDVOLTREMOVED_Max (0x1UL) /*!< Max enumerator value of EVENTVBUSUNDVOLTREMOVED
                                                                            field.*/                                              
  #define MAIN_INTENEVENTSVBUSIN0CLR_EVENTVBUSUNDVOLTREMOVED_LOW (0x0UL) /*!< Low                                              */
  #define MAIN_INTENEVENTSVBUSIN0CLR_EVENTVBUSUNDVOLTREMOVED_HIGH (0x1UL) /*!< High                                            */


/* MAIN_EVENTSVBUSIN1SET: Thermal and charger detection Event Set */
  #define MAIN_EVENTSVBUSIN1SET_ResetValue (0x00UL)  /*!< Reset value of EVENTSVBUSIN1SET register.                            */

/* EVENTTHERMALWARNDETECTED @Bit 0 : Thermal warning detected. Writing 1 sets the event (for debugging). */
  #define MAIN_EVENTSVBUSIN1SET_EVENTTHERMALWARNDETECTED_Pos (0UL) /*!< Position of EVENTTHERMALWARNDETECTED field.            */
  #define MAIN_EVENTSVBUSIN1SET_EVENTTHERMALWARNDETECTED_Msk (0x1UL << MAIN_EVENTSVBUSIN1SET_EVENTTHERMALWARNDETECTED_Pos) /*!<
                                                                            Bit mask of EVENTTHERMALWARNDETECTED field.*/         
  #define MAIN_EVENTSVBUSIN1SET_EVENTTHERMALWARNDETECTED_Min (0x0UL) /*!< Min enumerator value of EVENTTHERMALWARNDETECTED
                                                                          field.*/                                                
  #define MAIN_EVENTSVBUSIN1SET_EVENTTHERMALWARNDETECTED_Max (0x1UL) /*!< Max enumerator value of EVENTTHERMALWARNDETECTED
                                                                          field.*/                                                
  #define MAIN_EVENTSVBUSIN1SET_EVENTTHERMALWARNDETECTED_LOW (0x0UL) /*!< Low                                                  */
  #define MAIN_EVENTSVBUSIN1SET_EVENTTHERMALWARNDETECTED_HIGH (0x1UL) /*!< High                                                */

/* EVENTTHERMALWARNREMOVED @Bit 1 : Thermal warning removed. Writing 1 sets the event (for debugging). */
  #define MAIN_EVENTSVBUSIN1SET_EVENTTHERMALWARNREMOVED_Pos (1UL) /*!< Position of EVENTTHERMALWARNREMOVED field.              */
  #define MAIN_EVENTSVBUSIN1SET_EVENTTHERMALWARNREMOVED_Msk (0x1UL << MAIN_EVENTSVBUSIN1SET_EVENTTHERMALWARNREMOVED_Pos) /*!<
                                                                            Bit mask of EVENTTHERMALWARNREMOVED field.*/          
  #define MAIN_EVENTSVBUSIN1SET_EVENTTHERMALWARNREMOVED_Min (0x0UL) /*!< Min enumerator value of EVENTTHERMALWARNREMOVED field.*/
  #define MAIN_EVENTSVBUSIN1SET_EVENTTHERMALWARNREMOVED_Max (0x1UL) /*!< Max enumerator value of EVENTTHERMALWARNREMOVED field.*/
  #define MAIN_EVENTSVBUSIN1SET_EVENTTHERMALWARNREMOVED_LOW (0x0UL) /*!< Low                                                   */
  #define MAIN_EVENTSVBUSIN1SET_EVENTTHERMALWARNREMOVED_HIGH (0x1UL) /*!< High                                                 */

/* EVENTTHERMALSHUTDOWNDETECTED @Bit 2 : Thermal shutown detected. Writing 1 sets the event (for debugging). */
  #define MAIN_EVENTSVBUSIN1SET_EVENTTHERMALSHUTDOWNDETECTED_Pos (2UL) /*!< Position of EVENTTHERMALSHUTDOWNDETECTED field.    */
  #define MAIN_EVENTSVBUSIN1SET_EVENTTHERMALSHUTDOWNDETECTED_Msk (0x1UL << MAIN_EVENTSVBUSIN1SET_EVENTTHERMALSHUTDOWNDETECTED_Pos)
                                                                            /*!< Bit mask of EVENTTHERMALSHUTDOWNDETECTED
                                                                            field.*/                                              
  #define MAIN_EVENTSVBUSIN1SET_EVENTTHERMALSHUTDOWNDETECTED_Min (0x0UL) /*!< Min enumerator value of
                                                                            EVENTTHERMALSHUTDOWNDETECTED field.*/                 
  #define MAIN_EVENTSVBUSIN1SET_EVENTTHERMALSHUTDOWNDETECTED_Max (0x1UL) /*!< Max enumerator value of
                                                                            EVENTTHERMALSHUTDOWNDETECTED field.*/                 
  #define MAIN_EVENTSVBUSIN1SET_EVENTTHERMALSHUTDOWNDETECTED_LOW (0x0UL) /*!< Low                                              */
  #define MAIN_EVENTSVBUSIN1SET_EVENTTHERMALSHUTDOWNDETECTED_HIGH (0x1UL) /*!< High                                            */

/* EVENTTHERMALSHUTDOWNREMOVED @Bit 3 : Thermal shutdown removed. Writing 1 sets the event (for debugging). */
  #define MAIN_EVENTSVBUSIN1SET_EVENTTHERMALSHUTDOWNREMOVED_Pos (3UL) /*!< Position of EVENTTHERMALSHUTDOWNREMOVED field.      */
  #define MAIN_EVENTSVBUSIN1SET_EVENTTHERMALSHUTDOWNREMOVED_Msk (0x1UL << MAIN_EVENTSVBUSIN1SET_EVENTTHERMALSHUTDOWNREMOVED_Pos)
                                                                            /*!< Bit mask of EVENTTHERMALSHUTDOWNREMOVED field.*/ 
  #define MAIN_EVENTSVBUSIN1SET_EVENTTHERMALSHUTDOWNREMOVED_Min (0x0UL) /*!< Min enumerator value of EVENTTHERMALSHUTDOWNREMOVED
                                                                            field.*/                                              
  #define MAIN_EVENTSVBUSIN1SET_EVENTTHERMALSHUTDOWNREMOVED_Max (0x1UL) /*!< Max enumerator value of EVENTTHERMALSHUTDOWNREMOVED
                                                                            field.*/                                              
  #define MAIN_EVENTSVBUSIN1SET_EVENTTHERMALSHUTDOWNREMOVED_LOW (0x0UL) /*!< Low                                               */
  #define MAIN_EVENTSVBUSIN1SET_EVENTTHERMALSHUTDOWNREMOVED_HIGH (0x1UL) /*!< High                                             */

/* EVENTCC1STATECHANGE @Bit 4 : Voltage changed on pin CC1. Writing 1 sets the event (for debugging). */
  #define MAIN_EVENTSVBUSIN1SET_EVENTCC1STATECHANGE_Pos (4UL) /*!< Position of EVENTCC1STATECHANGE field.                      */
  #define MAIN_EVENTSVBUSIN1SET_EVENTCC1STATECHANGE_Msk (0x1UL << MAIN_EVENTSVBUSIN1SET_EVENTCC1STATECHANGE_Pos) /*!< Bit mask
                                                                            of EVENTCC1STATECHANGE field.*/                       
  #define MAIN_EVENTSVBUSIN1SET_EVENTCC1STATECHANGE_Min (0x0UL) /*!< Min enumerator value of EVENTCC1STATECHANGE field.        */
  #define MAIN_EVENTSVBUSIN1SET_EVENTCC1STATECHANGE_Max (0x1UL) /*!< Max enumerator value of EVENTCC1STATECHANGE field.        */
  #define MAIN_EVENTSVBUSIN1SET_EVENTCC1STATECHANGE_LOW (0x0UL) /*!< Low                                                       */
  #define MAIN_EVENTSVBUSIN1SET_EVENTCC1STATECHANGE_HIGH (0x1UL) /*!< High                                                     */

/* EVENTCC2STATECHANGE @Bit 5 : Voltage changed on pin CC2. Writing 1 sets the event (for debugging). */
  #define MAIN_EVENTSVBUSIN1SET_EVENTCC2STATECHANGE_Pos (5UL) /*!< Position of EVENTCC2STATECHANGE field.                      */
  #define MAIN_EVENTSVBUSIN1SET_EVENTCC2STATECHANGE_Msk (0x1UL << MAIN_EVENTSVBUSIN1SET_EVENTCC2STATECHANGE_Pos) /*!< Bit mask
                                                                            of EVENTCC2STATECHANGE field.*/                       
  #define MAIN_EVENTSVBUSIN1SET_EVENTCC2STATECHANGE_Min (0x0UL) /*!< Min enumerator value of EVENTCC2STATECHANGE field.        */
  #define MAIN_EVENTSVBUSIN1SET_EVENTCC2STATECHANGE_Max (0x1UL) /*!< Max enumerator value of EVENTCC2STATECHANGE field.        */
  #define MAIN_EVENTSVBUSIN1SET_EVENTCC2STATECHANGE_LOW (0x0UL) /*!< Low                                                       */
  #define MAIN_EVENTSVBUSIN1SET_EVENTCC2STATECHANGE_HIGH (0x1UL) /*!< High                                                     */


/* MAIN_EVENTSVBUSIN1CLR: Thermal and charger detection Event Clear */
  #define MAIN_EVENTSVBUSIN1CLR_ResetValue (0x00UL)  /*!< Reset value of EVENTSVBUSIN1CLR register.                            */

/* EVENTTHERMALWARNDETECTED @Bit 0 : Thermal warning detected. Writing 1 clears the event (e.g. to acknowledge an interrupt). */
  #define MAIN_EVENTSVBUSIN1CLR_EVENTTHERMALWARNDETECTED_Pos (0UL) /*!< Position of EVENTTHERMALWARNDETECTED field.            */
  #define MAIN_EVENTSVBUSIN1CLR_EVENTTHERMALWARNDETECTED_Msk (0x1UL << MAIN_EVENTSVBUSIN1CLR_EVENTTHERMALWARNDETECTED_Pos) /*!<
                                                                            Bit mask of EVENTTHERMALWARNDETECTED field.*/         
  #define MAIN_EVENTSVBUSIN1CLR_EVENTTHERMALWARNDETECTED_Min (0x0UL) /*!< Min enumerator value of EVENTTHERMALWARNDETECTED
                                                                          field.*/                                                
  #define MAIN_EVENTSVBUSIN1CLR_EVENTTHERMALWARNDETECTED_Max (0x1UL) /*!< Max enumerator value of EVENTTHERMALWARNDETECTED
                                                                          field.*/                                                
  #define MAIN_EVENTSVBUSIN1CLR_EVENTTHERMALWARNDETECTED_LOW (0x0UL) /*!< Low                                                  */
  #define MAIN_EVENTSVBUSIN1CLR_EVENTTHERMALWARNDETECTED_HIGH (0x1UL) /*!< High                                                */

/* EVENTTHERMALWARNREMOVED @Bit 1 : Thermal warning removed. Writing 1 clears the event (e.g. to acknowledge an interrupt). */
  #define MAIN_EVENTSVBUSIN1CLR_EVENTTHERMALWARNREMOVED_Pos (1UL) /*!< Position of EVENTTHERMALWARNREMOVED field.              */
  #define MAIN_EVENTSVBUSIN1CLR_EVENTTHERMALWARNREMOVED_Msk (0x1UL << MAIN_EVENTSVBUSIN1CLR_EVENTTHERMALWARNREMOVED_Pos) /*!<
                                                                            Bit mask of EVENTTHERMALWARNREMOVED field.*/          
  #define MAIN_EVENTSVBUSIN1CLR_EVENTTHERMALWARNREMOVED_Min (0x0UL) /*!< Min enumerator value of EVENTTHERMALWARNREMOVED field.*/
  #define MAIN_EVENTSVBUSIN1CLR_EVENTTHERMALWARNREMOVED_Max (0x1UL) /*!< Max enumerator value of EVENTTHERMALWARNREMOVED field.*/
  #define MAIN_EVENTSVBUSIN1CLR_EVENTTHERMALWARNREMOVED_LOW (0x0UL) /*!< Low                                                   */
  #define MAIN_EVENTSVBUSIN1CLR_EVENTTHERMALWARNREMOVED_HIGH (0x1UL) /*!< High                                                 */

/* EVENTTHERMALSHUTDOWNDETECTED @Bit 2 : Thermal shutown detected. Writing 1 clears the event (e.g. to acknowledge an
                                         interrupt). */                                                                           
                                                                                                                                  
  #define MAIN_EVENTSVBUSIN1CLR_EVENTTHERMALSHUTDOWNDETECTED_Pos (2UL) /*!< Position of EVENTTHERMALSHUTDOWNDETECTED field.    */
  #define MAIN_EVENTSVBUSIN1CLR_EVENTTHERMALSHUTDOWNDETECTED_Msk (0x1UL << MAIN_EVENTSVBUSIN1CLR_EVENTTHERMALSHUTDOWNDETECTED_Pos)
                                                                            /*!< Bit mask of EVENTTHERMALSHUTDOWNDETECTED
                                                                            field.*/                                              
  #define MAIN_EVENTSVBUSIN1CLR_EVENTTHERMALSHUTDOWNDETECTED_Min (0x0UL) /*!< Min enumerator value of
                                                                            EVENTTHERMALSHUTDOWNDETECTED field.*/                 
  #define MAIN_EVENTSVBUSIN1CLR_EVENTTHERMALSHUTDOWNDETECTED_Max (0x1UL) /*!< Max enumerator value of
                                                                            EVENTTHERMALSHUTDOWNDETECTED field.*/                 
  #define MAIN_EVENTSVBUSIN1CLR_EVENTTHERMALSHUTDOWNDETECTED_LOW (0x0UL) /*!< Low                                              */
  #define MAIN_EVENTSVBUSIN1CLR_EVENTTHERMALSHUTDOWNDETECTED_HIGH (0x1UL) /*!< High                                            */

/* EVENTTHERMALSHUTDOWNREMOVED @Bit 3 : Thermal shutdown removed. Writing 1 clears the event (e.g. to acknowledge an interrupt).
                                        */                                                                                        
                                                                                                                                  
  #define MAIN_EVENTSVBUSIN1CLR_EVENTTHERMALSHUTDOWNREMOVED_Pos (3UL) /*!< Position of EVENTTHERMALSHUTDOWNREMOVED field.      */
  #define MAIN_EVENTSVBUSIN1CLR_EVENTTHERMALSHUTDOWNREMOVED_Msk (0x1UL << MAIN_EVENTSVBUSIN1CLR_EVENTTHERMALSHUTDOWNREMOVED_Pos)
                                                                            /*!< Bit mask of EVENTTHERMALSHUTDOWNREMOVED field.*/ 
  #define MAIN_EVENTSVBUSIN1CLR_EVENTTHERMALSHUTDOWNREMOVED_Min (0x0UL) /*!< Min enumerator value of EVENTTHERMALSHUTDOWNREMOVED
                                                                            field.*/                                              
  #define MAIN_EVENTSVBUSIN1CLR_EVENTTHERMALSHUTDOWNREMOVED_Max (0x1UL) /*!< Max enumerator value of EVENTTHERMALSHUTDOWNREMOVED
                                                                            field.*/                                              
  #define MAIN_EVENTSVBUSIN1CLR_EVENTTHERMALSHUTDOWNREMOVED_LOW (0x0UL) /*!< Low                                               */
  #define MAIN_EVENTSVBUSIN1CLR_EVENTTHERMALSHUTDOWNREMOVED_HIGH (0x1UL) /*!< High                                             */

/* EVENTCC1STATECHANGE @Bit 4 : Voltage changed on pin CC1. Writing 1 clears the event (e.g. to acknowledge an interrupt). */
  #define MAIN_EVENTSVBUSIN1CLR_EVENTCC1STATECHANGE_Pos (4UL) /*!< Position of EVENTCC1STATECHANGE field.                      */
  #define MAIN_EVENTSVBUSIN1CLR_EVENTCC1STATECHANGE_Msk (0x1UL << MAIN_EVENTSVBUSIN1CLR_EVENTCC1STATECHANGE_Pos) /*!< Bit mask
                                                                            of EVENTCC1STATECHANGE field.*/                       
  #define MAIN_EVENTSVBUSIN1CLR_EVENTCC1STATECHANGE_Min (0x0UL) /*!< Min enumerator value of EVENTCC1STATECHANGE field.        */
  #define MAIN_EVENTSVBUSIN1CLR_EVENTCC1STATECHANGE_Max (0x1UL) /*!< Max enumerator value of EVENTCC1STATECHANGE field.        */
  #define MAIN_EVENTSVBUSIN1CLR_EVENTCC1STATECHANGE_LOW (0x0UL) /*!< Low                                                       */
  #define MAIN_EVENTSVBUSIN1CLR_EVENTCC1STATECHANGE_HIGH (0x1UL) /*!< High                                                     */

/* EVENTCC2STATECHANGE @Bit 5 : Voltage changed on pin CC2. Writing 1 clears the event (e.g. to acknowledge an interrupt). */
  #define MAIN_EVENTSVBUSIN1CLR_EVENTCC2STATECHANGE_Pos (5UL) /*!< Position of EVENTCC2STATECHANGE field.                      */
  #define MAIN_EVENTSVBUSIN1CLR_EVENTCC2STATECHANGE_Msk (0x1UL << MAIN_EVENTSVBUSIN1CLR_EVENTCC2STATECHANGE_Pos) /*!< Bit mask
                                                                            of EVENTCC2STATECHANGE field.*/                       
  #define MAIN_EVENTSVBUSIN1CLR_EVENTCC2STATECHANGE_Min (0x0UL) /*!< Min enumerator value of EVENTCC2STATECHANGE field.        */
  #define MAIN_EVENTSVBUSIN1CLR_EVENTCC2STATECHANGE_Max (0x1UL) /*!< Max enumerator value of EVENTCC2STATECHANGE field.        */
  #define MAIN_EVENTSVBUSIN1CLR_EVENTCC2STATECHANGE_LOW (0x0UL) /*!< Low                                                       */
  #define MAIN_EVENTSVBUSIN1CLR_EVENTCC2STATECHANGE_HIGH (0x1UL) /*!< High                                                     */


/* MAIN_INTENEVENTSVBUSIN1SET: Thermal and charger detection Interrupt Enable Set */
  #define MAIN_INTENEVENTSVBUSIN1SET_ResetValue (0x00UL) /*!< Reset value of INTENEVENTSVBUSIN1SET register.                   */

/* EVENTTHERMALWARNDETECTED @Bit 0 : Writing 1 enables interrupts from EVENTTHERMALWARNDETECTED */
  #define MAIN_INTENEVENTSVBUSIN1SET_EVENTTHERMALWARNDETECTED_Pos (0UL) /*!< Position of EVENTTHERMALWARNDETECTED field.       */
  #define MAIN_INTENEVENTSVBUSIN1SET_EVENTTHERMALWARNDETECTED_Msk (0x1UL << MAIN_INTENEVENTSVBUSIN1SET_EVENTTHERMALWARNDETECTED_Pos)
                                                                            /*!< Bit mask of EVENTTHERMALWARNDETECTED field.*/    
  #define MAIN_INTENEVENTSVBUSIN1SET_EVENTTHERMALWARNDETECTED_Min (0x0UL) /*!< Min enumerator value of EVENTTHERMALWARNDETECTED
                                                                            field.*/                                              
  #define MAIN_INTENEVENTSVBUSIN1SET_EVENTTHERMALWARNDETECTED_Max (0x1UL) /*!< Max enumerator value of EVENTTHERMALWARNDETECTED
                                                                            field.*/                                              
  #define MAIN_INTENEVENTSVBUSIN1SET_EVENTTHERMALWARNDETECTED_LOW (0x0UL) /*!< Low                                             */
  #define MAIN_INTENEVENTSVBUSIN1SET_EVENTTHERMALWARNDETECTED_HIGH (0x1UL) /*!< High                                           */

/* EVENTTHERMALWARNREMOVED @Bit 1 : Writing 1 enables interrupts from EVENTTHERMALWARNREMOVED */
  #define MAIN_INTENEVENTSVBUSIN1SET_EVENTTHERMALWARNREMOVED_Pos (1UL) /*!< Position of EVENTTHERMALWARNREMOVED field.         */
  #define MAIN_INTENEVENTSVBUSIN1SET_EVENTTHERMALWARNREMOVED_Msk (0x1UL << MAIN_INTENEVENTSVBUSIN1SET_EVENTTHERMALWARNREMOVED_Pos)
                                                                            /*!< Bit mask of EVENTTHERMALWARNREMOVED field.*/     
  #define MAIN_INTENEVENTSVBUSIN1SET_EVENTTHERMALWARNREMOVED_Min (0x0UL) /*!< Min enumerator value of EVENTTHERMALWARNREMOVED
                                                                            field.*/                                              
  #define MAIN_INTENEVENTSVBUSIN1SET_EVENTTHERMALWARNREMOVED_Max (0x1UL) /*!< Max enumerator value of EVENTTHERMALWARNREMOVED
                                                                            field.*/                                              
  #define MAIN_INTENEVENTSVBUSIN1SET_EVENTTHERMALWARNREMOVED_LOW (0x0UL) /*!< Low                                              */
  #define MAIN_INTENEVENTSVBUSIN1SET_EVENTTHERMALWARNREMOVED_HIGH (0x1UL) /*!< High                                            */

/* EVENTTHERMALSHUTDOWNDETECTED @Bit 2 : Writing 1 enables interrupts from EVENTTHERMALSHUTDOWNDETECTED */
  #define MAIN_INTENEVENTSVBUSIN1SET_EVENTTHERMALSHUTDOWNDETECTED_Pos (2UL) /*!< Position of EVENTTHERMALSHUTDOWNDETECTED
                                                                            field.*/                                              
  #define MAIN_INTENEVENTSVBUSIN1SET_EVENTTHERMALSHUTDOWNDETECTED_Msk (0x1UL << MAIN_INTENEVENTSVBUSIN1SET_EVENTTHERMALSHUTDOWNDETECTED_Pos)
                                                                            /*!< Bit mask of EVENTTHERMALSHUTDOWNDETECTED
                                                                            field.*/                                              
  #define MAIN_INTENEVENTSVBUSIN1SET_EVENTTHERMALSHUTDOWNDETECTED_Min (0x0UL) /*!< Min enumerator value of
                                                                            EVENTTHERMALSHUTDOWNDETECTED field.*/                 
  #define MAIN_INTENEVENTSVBUSIN1SET_EVENTTHERMALSHUTDOWNDETECTED_Max (0x1UL) /*!< Max enumerator value of
                                                                            EVENTTHERMALSHUTDOWNDETECTED field.*/                 
  #define MAIN_INTENEVENTSVBUSIN1SET_EVENTTHERMALSHUTDOWNDETECTED_LOW (0x0UL) /*!< Low                                         */
  #define MAIN_INTENEVENTSVBUSIN1SET_EVENTTHERMALSHUTDOWNDETECTED_HIGH (0x1UL) /*!< High                                       */

/* EVENTTHERMALSHUTDOWNREMOVED @Bit 3 : Writing 1 enables interrupts from EVENTTHERMALSHUTDOWNREMOVED */
  #define MAIN_INTENEVENTSVBUSIN1SET_EVENTTHERMALSHUTDOWNREMOVED_Pos (3UL) /*!< Position of EVENTTHERMALSHUTDOWNREMOVED field. */
  #define MAIN_INTENEVENTSVBUSIN1SET_EVENTTHERMALSHUTDOWNREMOVED_Msk (0x1UL << MAIN_INTENEVENTSVBUSIN1SET_EVENTTHERMALSHUTDOWNREMOVED_Pos)
                                                                            /*!< Bit mask of EVENTTHERMALSHUTDOWNREMOVED field.*/ 
  #define MAIN_INTENEVENTSVBUSIN1SET_EVENTTHERMALSHUTDOWNREMOVED_Min (0x0UL) /*!< Min enumerator value of
                                                                            EVENTTHERMALSHUTDOWNREMOVED field.*/                  
  #define MAIN_INTENEVENTSVBUSIN1SET_EVENTTHERMALSHUTDOWNREMOVED_Max (0x1UL) /*!< Max enumerator value of
                                                                            EVENTTHERMALSHUTDOWNREMOVED field.*/                  
  #define MAIN_INTENEVENTSVBUSIN1SET_EVENTTHERMALSHUTDOWNREMOVED_LOW (0x0UL) /*!< Low                                          */
  #define MAIN_INTENEVENTSVBUSIN1SET_EVENTTHERMALSHUTDOWNREMOVED_HIGH (0x1UL) /*!< High                                        */

/* EVENTCC1STATECHANGE @Bit 4 : Writing 1 enables interrupts from EVENTCC1STATECHANGE */
  #define MAIN_INTENEVENTSVBUSIN1SET_EVENTCC1STATECHANGE_Pos (4UL) /*!< Position of EVENTCC1STATECHANGE field.                 */
  #define MAIN_INTENEVENTSVBUSIN1SET_EVENTCC1STATECHANGE_Msk (0x1UL << MAIN_INTENEVENTSVBUSIN1SET_EVENTCC1STATECHANGE_Pos) /*!<
                                                                            Bit mask of EVENTCC1STATECHANGE field.*/              
  #define MAIN_INTENEVENTSVBUSIN1SET_EVENTCC1STATECHANGE_Min (0x0UL) /*!< Min enumerator value of EVENTCC1STATECHANGE field.   */
  #define MAIN_INTENEVENTSVBUSIN1SET_EVENTCC1STATECHANGE_Max (0x1UL) /*!< Max enumerator value of EVENTCC1STATECHANGE field.   */
  #define MAIN_INTENEVENTSVBUSIN1SET_EVENTCC1STATECHANGE_LOW (0x0UL) /*!< Low                                                  */
  #define MAIN_INTENEVENTSVBUSIN1SET_EVENTCC1STATECHANGE_HIGH (0x1UL) /*!< High                                                */

/* EVENTCC2STATECHANGE @Bit 5 : Writing 1 enables interrupts from EVENTCC2STATECHANGE */
  #define MAIN_INTENEVENTSVBUSIN1SET_EVENTCC2STATECHANGE_Pos (5UL) /*!< Position of EVENTCC2STATECHANGE field.                 */
  #define MAIN_INTENEVENTSVBUSIN1SET_EVENTCC2STATECHANGE_Msk (0x1UL << MAIN_INTENEVENTSVBUSIN1SET_EVENTCC2STATECHANGE_Pos) /*!<
                                                                            Bit mask of EVENTCC2STATECHANGE field.*/              
  #define MAIN_INTENEVENTSVBUSIN1SET_EVENTCC2STATECHANGE_Min (0x0UL) /*!< Min enumerator value of EVENTCC2STATECHANGE field.   */
  #define MAIN_INTENEVENTSVBUSIN1SET_EVENTCC2STATECHANGE_Max (0x1UL) /*!< Max enumerator value of EVENTCC2STATECHANGE field.   */
  #define MAIN_INTENEVENTSVBUSIN1SET_EVENTCC2STATECHANGE_LOW (0x0UL) /*!< Low                                                  */
  #define MAIN_INTENEVENTSVBUSIN1SET_EVENTCC2STATECHANGE_HIGH (0x1UL) /*!< High                                                */


/* MAIN_INTENEVENTSVBUSIN1CLR: Thermal and charger detection Interrupt Enable Clear */
  #define MAIN_INTENEVENTSVBUSIN1CLR_ResetValue (0x00UL) /*!< Reset value of INTENEVENTSVBUSIN1CLR register.                   */

/* EVENTTHERMALWARNDETECTED @Bit 0 : Writing 1 disables interrupts from EVENTTHERMALWARNDETECTED */
  #define MAIN_INTENEVENTSVBUSIN1CLR_EVENTTHERMALWARNDETECTED_Pos (0UL) /*!< Position of EVENTTHERMALWARNDETECTED field.       */
  #define MAIN_INTENEVENTSVBUSIN1CLR_EVENTTHERMALWARNDETECTED_Msk (0x1UL << MAIN_INTENEVENTSVBUSIN1CLR_EVENTTHERMALWARNDETECTED_Pos)
                                                                            /*!< Bit mask of EVENTTHERMALWARNDETECTED field.*/    
  #define MAIN_INTENEVENTSVBUSIN1CLR_EVENTTHERMALWARNDETECTED_Min (0x0UL) /*!< Min enumerator value of EVENTTHERMALWARNDETECTED
                                                                            field.*/                                              
  #define MAIN_INTENEVENTSVBUSIN1CLR_EVENTTHERMALWARNDETECTED_Max (0x1UL) /*!< Max enumerator value of EVENTTHERMALWARNDETECTED
                                                                            field.*/                                              
  #define MAIN_INTENEVENTSVBUSIN1CLR_EVENTTHERMALWARNDETECTED_LOW (0x0UL) /*!< Low                                             */
  #define MAIN_INTENEVENTSVBUSIN1CLR_EVENTTHERMALWARNDETECTED_HIGH (0x1UL) /*!< High                                           */

/* EVENTTHERMALWARNREMOVED @Bit 1 : Writing 1 disables interrupts from EVENTTHERMALWARNREMOVED */
  #define MAIN_INTENEVENTSVBUSIN1CLR_EVENTTHERMALWARNREMOVED_Pos (1UL) /*!< Position of EVENTTHERMALWARNREMOVED field.         */
  #define MAIN_INTENEVENTSVBUSIN1CLR_EVENTTHERMALWARNREMOVED_Msk (0x1UL << MAIN_INTENEVENTSVBUSIN1CLR_EVENTTHERMALWARNREMOVED_Pos)
                                                                            /*!< Bit mask of EVENTTHERMALWARNREMOVED field.*/     
  #define MAIN_INTENEVENTSVBUSIN1CLR_EVENTTHERMALWARNREMOVED_Min (0x0UL) /*!< Min enumerator value of EVENTTHERMALWARNREMOVED
                                                                            field.*/                                              
  #define MAIN_INTENEVENTSVBUSIN1CLR_EVENTTHERMALWARNREMOVED_Max (0x1UL) /*!< Max enumerator value of EVENTTHERMALWARNREMOVED
                                                                            field.*/                                              
  #define MAIN_INTENEVENTSVBUSIN1CLR_EVENTTHERMALWARNREMOVED_LOW (0x0UL) /*!< Low                                              */
  #define MAIN_INTENEVENTSVBUSIN1CLR_EVENTTHERMALWARNREMOVED_HIGH (0x1UL) /*!< High                                            */

/* EVENTTHERMALSHUTDOWNDETECTED @Bit 2 : Writing 1 disables interrupts from EVENTTHERMALSHUTDOWNDETECTED */
  #define MAIN_INTENEVENTSVBUSIN1CLR_EVENTTHERMALSHUTDOWNDETECTED_Pos (2UL) /*!< Position of EVENTTHERMALSHUTDOWNDETECTED
                                                                            field.*/                                              
  #define MAIN_INTENEVENTSVBUSIN1CLR_EVENTTHERMALSHUTDOWNDETECTED_Msk (0x1UL << MAIN_INTENEVENTSVBUSIN1CLR_EVENTTHERMALSHUTDOWNDETECTED_Pos)
                                                                            /*!< Bit mask of EVENTTHERMALSHUTDOWNDETECTED
                                                                            field.*/                                              
  #define MAIN_INTENEVENTSVBUSIN1CLR_EVENTTHERMALSHUTDOWNDETECTED_Min (0x0UL) /*!< Min enumerator value of
                                                                            EVENTTHERMALSHUTDOWNDETECTED field.*/                 
  #define MAIN_INTENEVENTSVBUSIN1CLR_EVENTTHERMALSHUTDOWNDETECTED_Max (0x1UL) /*!< Max enumerator value of
                                                                            EVENTTHERMALSHUTDOWNDETECTED field.*/                 
  #define MAIN_INTENEVENTSVBUSIN1CLR_EVENTTHERMALSHUTDOWNDETECTED_LOW (0x0UL) /*!< Low                                         */
  #define MAIN_INTENEVENTSVBUSIN1CLR_EVENTTHERMALSHUTDOWNDETECTED_HIGH (0x1UL) /*!< High                                       */

/* EVENTTHERMALSHUTDOWNREMOVED @Bit 3 : Writing 1 disables interrupts from EVENTTHERMALSHUTDOWNREMOVED */
  #define MAIN_INTENEVENTSVBUSIN1CLR_EVENTTHERMALSHUTDOWNREMOVED_Pos (3UL) /*!< Position of EVENTTHERMALSHUTDOWNREMOVED field. */
  #define MAIN_INTENEVENTSVBUSIN1CLR_EVENTTHERMALSHUTDOWNREMOVED_Msk (0x1UL << MAIN_INTENEVENTSVBUSIN1CLR_EVENTTHERMALSHUTDOWNREMOVED_Pos)
                                                                            /*!< Bit mask of EVENTTHERMALSHUTDOWNREMOVED field.*/ 
  #define MAIN_INTENEVENTSVBUSIN1CLR_EVENTTHERMALSHUTDOWNREMOVED_Min (0x0UL) /*!< Min enumerator value of
                                                                            EVENTTHERMALSHUTDOWNREMOVED field.*/                  
  #define MAIN_INTENEVENTSVBUSIN1CLR_EVENTTHERMALSHUTDOWNREMOVED_Max (0x1UL) /*!< Max enumerator value of
                                                                            EVENTTHERMALSHUTDOWNREMOVED field.*/                  
  #define MAIN_INTENEVENTSVBUSIN1CLR_EVENTTHERMALSHUTDOWNREMOVED_LOW (0x0UL) /*!< Low                                          */
  #define MAIN_INTENEVENTSVBUSIN1CLR_EVENTTHERMALSHUTDOWNREMOVED_HIGH (0x1UL) /*!< High                                        */

/* EVENTCC1STATECHANGE @Bit 4 : Writing 1 disables interrupts from EVENTCC1STATECHANGE */
  #define MAIN_INTENEVENTSVBUSIN1CLR_EVENTCC1STATECHANGE_Pos (4UL) /*!< Position of EVENTCC1STATECHANGE field.                 */
  #define MAIN_INTENEVENTSVBUSIN1CLR_EVENTCC1STATECHANGE_Msk (0x1UL << MAIN_INTENEVENTSVBUSIN1CLR_EVENTCC1STATECHANGE_Pos) /*!<
                                                                            Bit mask of EVENTCC1STATECHANGE field.*/              
  #define MAIN_INTENEVENTSVBUSIN1CLR_EVENTCC1STATECHANGE_Min (0x0UL) /*!< Min enumerator value of EVENTCC1STATECHANGE field.   */
  #define MAIN_INTENEVENTSVBUSIN1CLR_EVENTCC1STATECHANGE_Max (0x1UL) /*!< Max enumerator value of EVENTCC1STATECHANGE field.   */
  #define MAIN_INTENEVENTSVBUSIN1CLR_EVENTCC1STATECHANGE_LOW (0x0UL) /*!< Low                                                  */
  #define MAIN_INTENEVENTSVBUSIN1CLR_EVENTCC1STATECHANGE_HIGH (0x1UL) /*!< High                                                */

/* EVENTCC2STATECHANGE @Bit 5 : Writing 1 disables interrupts from EVENTCC2STATECHANGE */
  #define MAIN_INTENEVENTSVBUSIN1CLR_EVENTCC2STATECHANGE_Pos (5UL) /*!< Position of EVENTCC2STATECHANGE field.                 */
  #define MAIN_INTENEVENTSVBUSIN1CLR_EVENTCC2STATECHANGE_Msk (0x1UL << MAIN_INTENEVENTSVBUSIN1CLR_EVENTCC2STATECHANGE_Pos) /*!<
                                                                            Bit mask of EVENTCC2STATECHANGE field.*/              
  #define MAIN_INTENEVENTSVBUSIN1CLR_EVENTCC2STATECHANGE_Min (0x0UL) /*!< Min enumerator value of EVENTCC2STATECHANGE field.   */
  #define MAIN_INTENEVENTSVBUSIN1CLR_EVENTCC2STATECHANGE_Max (0x1UL) /*!< Max enumerator value of EVENTCC2STATECHANGE field.   */
  #define MAIN_INTENEVENTSVBUSIN1CLR_EVENTCC2STATECHANGE_LOW (0x0UL) /*!< Low                                                  */
  #define MAIN_INTENEVENTSVBUSIN1CLR_EVENTCC2STATECHANGE_HIGH (0x1UL) /*!< High                                                */


/* MAIN_EVENTSGPIOSET: GPIO Event Set */
  #define MAIN_EVENTSGPIOSET_ResetValue (0x00UL)     /*!< Reset value of EVENTSGPIOSET register.                               */

/* EVENTGPIOEDGEDETECT0 @Bit 0 : Edge is detected on GPIO0. GPIOMODE = 3 : rising edge GPIOMODE = 4 : falling edge. Writing 1
                                 sets the event (for debugging). */                                                               
                                                                                                                                  
  #define MAIN_EVENTSGPIOSET_EVENTGPIOEDGEDETECT0_Pos (0UL) /*!< Position of EVENTGPIOEDGEDETECT0 field.                       */
  #define MAIN_EVENTSGPIOSET_EVENTGPIOEDGEDETECT0_Msk (0x1UL << MAIN_EVENTSGPIOSET_EVENTGPIOEDGEDETECT0_Pos) /*!< Bit mask of
                                                                            EVENTGPIOEDGEDETECT0 field.*/                         
  #define MAIN_EVENTSGPIOSET_EVENTGPIOEDGEDETECT0_Min (0x0UL) /*!< Min enumerator value of EVENTGPIOEDGEDETECT0 field.         */
  #define MAIN_EVENTSGPIOSET_EVENTGPIOEDGEDETECT0_Max (0x1UL) /*!< Max enumerator value of EVENTGPIOEDGEDETECT0 field.         */
  #define MAIN_EVENTSGPIOSET_EVENTGPIOEDGEDETECT0_LOW (0x0UL) /*!< Low                                                         */
  #define MAIN_EVENTSGPIOSET_EVENTGPIOEDGEDETECT0_HIGH (0x1UL) /*!< High                                                       */

/* EVENTGPIOEDGEDETECT1 @Bit 1 : Edge is detected on GPIO1. GPIOMODE = 3 : rising edge GPIOMODE = 4 : falling edge. Writing 1
                                 sets the event (for debugging). */                                                               
                                                                                                                                  
  #define MAIN_EVENTSGPIOSET_EVENTGPIOEDGEDETECT1_Pos (1UL) /*!< Position of EVENTGPIOEDGEDETECT1 field.                       */
  #define MAIN_EVENTSGPIOSET_EVENTGPIOEDGEDETECT1_Msk (0x1UL << MAIN_EVENTSGPIOSET_EVENTGPIOEDGEDETECT1_Pos) /*!< Bit mask of
                                                                            EVENTGPIOEDGEDETECT1 field.*/                         
  #define MAIN_EVENTSGPIOSET_EVENTGPIOEDGEDETECT1_Min (0x0UL) /*!< Min enumerator value of EVENTGPIOEDGEDETECT1 field.         */
  #define MAIN_EVENTSGPIOSET_EVENTGPIOEDGEDETECT1_Max (0x1UL) /*!< Max enumerator value of EVENTGPIOEDGEDETECT1 field.         */
  #define MAIN_EVENTSGPIOSET_EVENTGPIOEDGEDETECT1_LOW (0x0UL) /*!< Low                                                         */
  #define MAIN_EVENTSGPIOSET_EVENTGPIOEDGEDETECT1_HIGH (0x1UL) /*!< High                                                       */

/* EVENTGPIOEDGEDETECT2 @Bit 2 : Edge is detected on GPIO2. GPIOMODE = 3 : rising edge GPIOMODE = 4 : falling edge. Writing 1
                                 sets the event (for debugging). */                                                               
                                                                                                                                  
  #define MAIN_EVENTSGPIOSET_EVENTGPIOEDGEDETECT2_Pos (2UL) /*!< Position of EVENTGPIOEDGEDETECT2 field.                       */
  #define MAIN_EVENTSGPIOSET_EVENTGPIOEDGEDETECT2_Msk (0x1UL << MAIN_EVENTSGPIOSET_EVENTGPIOEDGEDETECT2_Pos) /*!< Bit mask of
                                                                            EVENTGPIOEDGEDETECT2 field.*/                         
  #define MAIN_EVENTSGPIOSET_EVENTGPIOEDGEDETECT2_Min (0x0UL) /*!< Min enumerator value of EVENTGPIOEDGEDETECT2 field.         */
  #define MAIN_EVENTSGPIOSET_EVENTGPIOEDGEDETECT2_Max (0x1UL) /*!< Max enumerator value of EVENTGPIOEDGEDETECT2 field.         */
  #define MAIN_EVENTSGPIOSET_EVENTGPIOEDGEDETECT2_LOW (0x0UL) /*!< Low                                                         */
  #define MAIN_EVENTSGPIOSET_EVENTGPIOEDGEDETECT2_HIGH (0x1UL) /*!< High                                                       */

/* EVENTGPIOEDGEDETECT3 @Bit 3 : Edge is detected on GPIO3. GPIOMODE = 3 : rising edge GPIOMODE = 4 : falling edge. Writing 1
                                 sets the event (for debugging). */                                                               
                                                                                                                                  
  #define MAIN_EVENTSGPIOSET_EVENTGPIOEDGEDETECT3_Pos (3UL) /*!< Position of EVENTGPIOEDGEDETECT3 field.                       */
  #define MAIN_EVENTSGPIOSET_EVENTGPIOEDGEDETECT3_Msk (0x1UL << MAIN_EVENTSGPIOSET_EVENTGPIOEDGEDETECT3_Pos) /*!< Bit mask of
                                                                            EVENTGPIOEDGEDETECT3 field.*/                         
  #define MAIN_EVENTSGPIOSET_EVENTGPIOEDGEDETECT3_Min (0x0UL) /*!< Min enumerator value of EVENTGPIOEDGEDETECT3 field.         */
  #define MAIN_EVENTSGPIOSET_EVENTGPIOEDGEDETECT3_Max (0x1UL) /*!< Max enumerator value of EVENTGPIOEDGEDETECT3 field.         */
  #define MAIN_EVENTSGPIOSET_EVENTGPIOEDGEDETECT3_LOW (0x0UL) /*!< Low                                                         */
  #define MAIN_EVENTSGPIOSET_EVENTGPIOEDGEDETECT3_HIGH (0x1UL) /*!< High                                                       */

/* EVENTGPIOEDGEDETECT4 @Bit 4 : Edge is detected on GPIO4. GPIOMODE = 3 : rising edge GPIOMODE = 4 : falling edge. Writing 1
                                 sets the event (for debugging). */                                                               
                                                                                                                                  
  #define MAIN_EVENTSGPIOSET_EVENTGPIOEDGEDETECT4_Pos (4UL) /*!< Position of EVENTGPIOEDGEDETECT4 field.                       */
  #define MAIN_EVENTSGPIOSET_EVENTGPIOEDGEDETECT4_Msk (0x1UL << MAIN_EVENTSGPIOSET_EVENTGPIOEDGEDETECT4_Pos) /*!< Bit mask of
                                                                            EVENTGPIOEDGEDETECT4 field.*/                         
  #define MAIN_EVENTSGPIOSET_EVENTGPIOEDGEDETECT4_Min (0x0UL) /*!< Min enumerator value of EVENTGPIOEDGEDETECT4 field.         */
  #define MAIN_EVENTSGPIOSET_EVENTGPIOEDGEDETECT4_Max (0x1UL) /*!< Max enumerator value of EVENTGPIOEDGEDETECT4 field.         */
  #define MAIN_EVENTSGPIOSET_EVENTGPIOEDGEDETECT4_LOW (0x0UL) /*!< Low                                                         */
  #define MAIN_EVENTSGPIOSET_EVENTGPIOEDGEDETECT4_HIGH (0x1UL) /*!< High                                                       */


/* MAIN_EVENTSGPIOCLR: GPIO Event Clear */
  #define MAIN_EVENTSGPIOCLR_ResetValue (0x00UL)     /*!< Reset value of EVENTSGPIOCLR register.                               */

/* EVENTGPIOEDGEDETECT0 @Bit 0 : Edge is detected on GPIO0. GPIOMODE = 3 : rising edge GPIOMODE = 4 : falling edge. Writing 1
                                 clears the event (e.g. to acknowledge an interrupt). */                                          
                                                                                                                                  
  #define MAIN_EVENTSGPIOCLR_EVENTGPIOEDGEDETECT0_Pos (0UL) /*!< Position of EVENTGPIOEDGEDETECT0 field.                       */
  #define MAIN_EVENTSGPIOCLR_EVENTGPIOEDGEDETECT0_Msk (0x1UL << MAIN_EVENTSGPIOCLR_EVENTGPIOEDGEDETECT0_Pos) /*!< Bit mask of
                                                                            EVENTGPIOEDGEDETECT0 field.*/                         
  #define MAIN_EVENTSGPIOCLR_EVENTGPIOEDGEDETECT0_Min (0x0UL) /*!< Min enumerator value of EVENTGPIOEDGEDETECT0 field.         */
  #define MAIN_EVENTSGPIOCLR_EVENTGPIOEDGEDETECT0_Max (0x1UL) /*!< Max enumerator value of EVENTGPIOEDGEDETECT0 field.         */
  #define MAIN_EVENTSGPIOCLR_EVENTGPIOEDGEDETECT0_LOW (0x0UL) /*!< Low                                                         */
  #define MAIN_EVENTSGPIOCLR_EVENTGPIOEDGEDETECT0_HIGH (0x1UL) /*!< High                                                       */

/* EVENTGPIOEDGEDETECT1 @Bit 1 : Edge is detected on GPIO1. GPIOMODE = 3 : rising edge GPIOMODE = 4 : falling edge. Writing 1
                                 clears the event (e.g. to acknowledge an interrupt). */                                          
                                                                                                                                  
  #define MAIN_EVENTSGPIOCLR_EVENTGPIOEDGEDETECT1_Pos (1UL) /*!< Position of EVENTGPIOEDGEDETECT1 field.                       */
  #define MAIN_EVENTSGPIOCLR_EVENTGPIOEDGEDETECT1_Msk (0x1UL << MAIN_EVENTSGPIOCLR_EVENTGPIOEDGEDETECT1_Pos) /*!< Bit mask of
                                                                            EVENTGPIOEDGEDETECT1 field.*/                         
  #define MAIN_EVENTSGPIOCLR_EVENTGPIOEDGEDETECT1_Min (0x0UL) /*!< Min enumerator value of EVENTGPIOEDGEDETECT1 field.         */
  #define MAIN_EVENTSGPIOCLR_EVENTGPIOEDGEDETECT1_Max (0x1UL) /*!< Max enumerator value of EVENTGPIOEDGEDETECT1 field.         */
  #define MAIN_EVENTSGPIOCLR_EVENTGPIOEDGEDETECT1_LOW (0x0UL) /*!< Low                                                         */
  #define MAIN_EVENTSGPIOCLR_EVENTGPIOEDGEDETECT1_HIGH (0x1UL) /*!< High                                                       */

/* EVENTGPIOEDGEDETECT2 @Bit 2 : Edge is detected on GPIO2. GPIOMODE = 3 : rising edge GPIOMODE = 4 : falling edge. Writing 1
                                 clears the event (e.g. to acknowledge an interrupt). */                                          
                                                                                                                                  
  #define MAIN_EVENTSGPIOCLR_EVENTGPIOEDGEDETECT2_Pos (2UL) /*!< Position of EVENTGPIOEDGEDETECT2 field.                       */
  #define MAIN_EVENTSGPIOCLR_EVENTGPIOEDGEDETECT2_Msk (0x1UL << MAIN_EVENTSGPIOCLR_EVENTGPIOEDGEDETECT2_Pos) /*!< Bit mask of
                                                                            EVENTGPIOEDGEDETECT2 field.*/                         
  #define MAIN_EVENTSGPIOCLR_EVENTGPIOEDGEDETECT2_Min (0x0UL) /*!< Min enumerator value of EVENTGPIOEDGEDETECT2 field.         */
  #define MAIN_EVENTSGPIOCLR_EVENTGPIOEDGEDETECT2_Max (0x1UL) /*!< Max enumerator value of EVENTGPIOEDGEDETECT2 field.         */
  #define MAIN_EVENTSGPIOCLR_EVENTGPIOEDGEDETECT2_LOW (0x0UL) /*!< Low                                                         */
  #define MAIN_EVENTSGPIOCLR_EVENTGPIOEDGEDETECT2_HIGH (0x1UL) /*!< High                                                       */

/* EVENTGPIOEDGEDETECT3 @Bit 3 : Edge is detected on GPIO3. GPIOMODE = 3 : rising edge GPIOMODE = 4 : falling edge. Writing 1
                                 clears the event (e.g. to acknowledge an interrupt). */                                          
                                                                                                                                  
  #define MAIN_EVENTSGPIOCLR_EVENTGPIOEDGEDETECT3_Pos (3UL) /*!< Position of EVENTGPIOEDGEDETECT3 field.                       */
  #define MAIN_EVENTSGPIOCLR_EVENTGPIOEDGEDETECT3_Msk (0x1UL << MAIN_EVENTSGPIOCLR_EVENTGPIOEDGEDETECT3_Pos) /*!< Bit mask of
                                                                            EVENTGPIOEDGEDETECT3 field.*/                         
  #define MAIN_EVENTSGPIOCLR_EVENTGPIOEDGEDETECT3_Min (0x0UL) /*!< Min enumerator value of EVENTGPIOEDGEDETECT3 field.         */
  #define MAIN_EVENTSGPIOCLR_EVENTGPIOEDGEDETECT3_Max (0x1UL) /*!< Max enumerator value of EVENTGPIOEDGEDETECT3 field.         */
  #define MAIN_EVENTSGPIOCLR_EVENTGPIOEDGEDETECT3_LOW (0x0UL) /*!< Low                                                         */
  #define MAIN_EVENTSGPIOCLR_EVENTGPIOEDGEDETECT3_HIGH (0x1UL) /*!< High                                                       */

/* EVENTGPIOEDGEDETECT4 @Bit 4 : Edge is detected on GPIO4. GPIOMODE = 3 : rising edge GPIOMODE = 4 : falling edge. Writing 1
                                 clears the event (e.g. to acknowledge an interrupt). */                                          
                                                                                                                                  
  #define MAIN_EVENTSGPIOCLR_EVENTGPIOEDGEDETECT4_Pos (4UL) /*!< Position of EVENTGPIOEDGEDETECT4 field.                       */
  #define MAIN_EVENTSGPIOCLR_EVENTGPIOEDGEDETECT4_Msk (0x1UL << MAIN_EVENTSGPIOCLR_EVENTGPIOEDGEDETECT4_Pos) /*!< Bit mask of
                                                                            EVENTGPIOEDGEDETECT4 field.*/                         
  #define MAIN_EVENTSGPIOCLR_EVENTGPIOEDGEDETECT4_Min (0x0UL) /*!< Min enumerator value of EVENTGPIOEDGEDETECT4 field.         */
  #define MAIN_EVENTSGPIOCLR_EVENTGPIOEDGEDETECT4_Max (0x1UL) /*!< Max enumerator value of EVENTGPIOEDGEDETECT4 field.         */
  #define MAIN_EVENTSGPIOCLR_EVENTGPIOEDGEDETECT4_LOW (0x0UL) /*!< Low                                                         */
  #define MAIN_EVENTSGPIOCLR_EVENTGPIOEDGEDETECT4_HIGH (0x1UL) /*!< High                                                       */


/* MAIN_INTENEVENTSGPIOSET: GPIO Interrupt Enable Set */
  #define MAIN_INTENEVENTSGPIOSET_ResetValue (0x00UL) /*!< Reset value of INTENEVENTSGPIOSET register.                         */

/* EVENTGPIOEDGEDETECT0 @Bit 0 : Writing 1 enables interrupts from EVENTGPIOEDGEDETECT0 */
  #define MAIN_INTENEVENTSGPIOSET_EVENTGPIOEDGEDETECT0_Pos (0UL) /*!< Position of EVENTGPIOEDGEDETECT0 field.                  */
  #define MAIN_INTENEVENTSGPIOSET_EVENTGPIOEDGEDETECT0_Msk (0x1UL << MAIN_INTENEVENTSGPIOSET_EVENTGPIOEDGEDETECT0_Pos) /*!< Bit
                                                                            mask of EVENTGPIOEDGEDETECT0 field.*/                 
  #define MAIN_INTENEVENTSGPIOSET_EVENTGPIOEDGEDETECT0_Min (0x0UL) /*!< Min enumerator value of EVENTGPIOEDGEDETECT0 field.    */
  #define MAIN_INTENEVENTSGPIOSET_EVENTGPIOEDGEDETECT0_Max (0x1UL) /*!< Max enumerator value of EVENTGPIOEDGEDETECT0 field.    */
  #define MAIN_INTENEVENTSGPIOSET_EVENTGPIOEDGEDETECT0_LOW (0x0UL) /*!< Low                                                    */
  #define MAIN_INTENEVENTSGPIOSET_EVENTGPIOEDGEDETECT0_HIGH (0x1UL) /*!< High                                                  */

/* EVENTGPIOEDGEDETECT1 @Bit 1 : Writing 1 enables interrupts from EVENTGPIOEDGEDETECT1 */
  #define MAIN_INTENEVENTSGPIOSET_EVENTGPIOEDGEDETECT1_Pos (1UL) /*!< Position of EVENTGPIOEDGEDETECT1 field.                  */
  #define MAIN_INTENEVENTSGPIOSET_EVENTGPIOEDGEDETECT1_Msk (0x1UL << MAIN_INTENEVENTSGPIOSET_EVENTGPIOEDGEDETECT1_Pos) /*!< Bit
                                                                            mask of EVENTGPIOEDGEDETECT1 field.*/                 
  #define MAIN_INTENEVENTSGPIOSET_EVENTGPIOEDGEDETECT1_Min (0x0UL) /*!< Min enumerator value of EVENTGPIOEDGEDETECT1 field.    */
  #define MAIN_INTENEVENTSGPIOSET_EVENTGPIOEDGEDETECT1_Max (0x1UL) /*!< Max enumerator value of EVENTGPIOEDGEDETECT1 field.    */
  #define MAIN_INTENEVENTSGPIOSET_EVENTGPIOEDGEDETECT1_LOW (0x0UL) /*!< Low                                                    */
  #define MAIN_INTENEVENTSGPIOSET_EVENTGPIOEDGEDETECT1_HIGH (0x1UL) /*!< High                                                  */

/* EVENTGPIOEDGEDETECT2 @Bit 2 : Writing 1 enables interrupts from EVENTGPIOEDGEDETECT2 */
  #define MAIN_INTENEVENTSGPIOSET_EVENTGPIOEDGEDETECT2_Pos (2UL) /*!< Position of EVENTGPIOEDGEDETECT2 field.                  */
  #define MAIN_INTENEVENTSGPIOSET_EVENTGPIOEDGEDETECT2_Msk (0x1UL << MAIN_INTENEVENTSGPIOSET_EVENTGPIOEDGEDETECT2_Pos) /*!< Bit
                                                                            mask of EVENTGPIOEDGEDETECT2 field.*/                 
  #define MAIN_INTENEVENTSGPIOSET_EVENTGPIOEDGEDETECT2_Min (0x0UL) /*!< Min enumerator value of EVENTGPIOEDGEDETECT2 field.    */
  #define MAIN_INTENEVENTSGPIOSET_EVENTGPIOEDGEDETECT2_Max (0x1UL) /*!< Max enumerator value of EVENTGPIOEDGEDETECT2 field.    */
  #define MAIN_INTENEVENTSGPIOSET_EVENTGPIOEDGEDETECT2_LOW (0x0UL) /*!< Low                                                    */
  #define MAIN_INTENEVENTSGPIOSET_EVENTGPIOEDGEDETECT2_HIGH (0x1UL) /*!< High                                                  */

/* EVENTGPIOEDGEDETECT3 @Bit 3 : Writing 1 enables interrupts from EVENTGPIOEDGEDETECT3 */
  #define MAIN_INTENEVENTSGPIOSET_EVENTGPIOEDGEDETECT3_Pos (3UL) /*!< Position of EVENTGPIOEDGEDETECT3 field.                  */
  #define MAIN_INTENEVENTSGPIOSET_EVENTGPIOEDGEDETECT3_Msk (0x1UL << MAIN_INTENEVENTSGPIOSET_EVENTGPIOEDGEDETECT3_Pos) /*!< Bit
                                                                            mask of EVENTGPIOEDGEDETECT3 field.*/                 
  #define MAIN_INTENEVENTSGPIOSET_EVENTGPIOEDGEDETECT3_Min (0x0UL) /*!< Min enumerator value of EVENTGPIOEDGEDETECT3 field.    */
  #define MAIN_INTENEVENTSGPIOSET_EVENTGPIOEDGEDETECT3_Max (0x1UL) /*!< Max enumerator value of EVENTGPIOEDGEDETECT3 field.    */
  #define MAIN_INTENEVENTSGPIOSET_EVENTGPIOEDGEDETECT3_LOW (0x0UL) /*!< Low                                                    */
  #define MAIN_INTENEVENTSGPIOSET_EVENTGPIOEDGEDETECT3_HIGH (0x1UL) /*!< High                                                  */

/* EVENTGPIOEDGEDETECT4 @Bit 4 : Writing 1 enables interrupts from EVENTGPIOEDGEDETECT4 */
  #define MAIN_INTENEVENTSGPIOSET_EVENTGPIOEDGEDETECT4_Pos (4UL) /*!< Position of EVENTGPIOEDGEDETECT4 field.                  */
  #define MAIN_INTENEVENTSGPIOSET_EVENTGPIOEDGEDETECT4_Msk (0x1UL << MAIN_INTENEVENTSGPIOSET_EVENTGPIOEDGEDETECT4_Pos) /*!< Bit
                                                                            mask of EVENTGPIOEDGEDETECT4 field.*/                 
  #define MAIN_INTENEVENTSGPIOSET_EVENTGPIOEDGEDETECT4_Min (0x0UL) /*!< Min enumerator value of EVENTGPIOEDGEDETECT4 field.    */
  #define MAIN_INTENEVENTSGPIOSET_EVENTGPIOEDGEDETECT4_Max (0x1UL) /*!< Max enumerator value of EVENTGPIOEDGEDETECT4 field.    */
  #define MAIN_INTENEVENTSGPIOSET_EVENTGPIOEDGEDETECT4_LOW (0x0UL) /*!< Low                                                    */
  #define MAIN_INTENEVENTSGPIOSET_EVENTGPIOEDGEDETECT4_HIGH (0x1UL) /*!< High                                                  */


/* MAIN_INTENEVENTSGPIOCLR: GPIO Interrupt Enable Clear */
  #define MAIN_INTENEVENTSGPIOCLR_ResetValue (0x00UL) /*!< Reset value of INTENEVENTSGPIOCLR register.                         */

/* EVENTGPIOEDGEDETECT0 @Bit 0 : Writing 1 disables interrupts from EVENTGPIOEDGEDETECT0 */
  #define MAIN_INTENEVENTSGPIOCLR_EVENTGPIOEDGEDETECT0_Pos (0UL) /*!< Position of EVENTGPIOEDGEDETECT0 field.                  */
  #define MAIN_INTENEVENTSGPIOCLR_EVENTGPIOEDGEDETECT0_Msk (0x1UL << MAIN_INTENEVENTSGPIOCLR_EVENTGPIOEDGEDETECT0_Pos) /*!< Bit
                                                                            mask of EVENTGPIOEDGEDETECT0 field.*/                 
  #define MAIN_INTENEVENTSGPIOCLR_EVENTGPIOEDGEDETECT0_Min (0x0UL) /*!< Min enumerator value of EVENTGPIOEDGEDETECT0 field.    */
  #define MAIN_INTENEVENTSGPIOCLR_EVENTGPIOEDGEDETECT0_Max (0x1UL) /*!< Max enumerator value of EVENTGPIOEDGEDETECT0 field.    */
  #define MAIN_INTENEVENTSGPIOCLR_EVENTGPIOEDGEDETECT0_LOW (0x0UL) /*!< Low                                                    */
  #define MAIN_INTENEVENTSGPIOCLR_EVENTGPIOEDGEDETECT0_HIGH (0x1UL) /*!< High                                                  */

/* EVENTGPIOEDGEDETECT1 @Bit 1 : Writing 1 disables interrupts from EVENTGPIOEDGEDETECT1 */
  #define MAIN_INTENEVENTSGPIOCLR_EVENTGPIOEDGEDETECT1_Pos (1UL) /*!< Position of EVENTGPIOEDGEDETECT1 field.                  */
  #define MAIN_INTENEVENTSGPIOCLR_EVENTGPIOEDGEDETECT1_Msk (0x1UL << MAIN_INTENEVENTSGPIOCLR_EVENTGPIOEDGEDETECT1_Pos) /*!< Bit
                                                                            mask of EVENTGPIOEDGEDETECT1 field.*/                 
  #define MAIN_INTENEVENTSGPIOCLR_EVENTGPIOEDGEDETECT1_Min (0x0UL) /*!< Min enumerator value of EVENTGPIOEDGEDETECT1 field.    */
  #define MAIN_INTENEVENTSGPIOCLR_EVENTGPIOEDGEDETECT1_Max (0x1UL) /*!< Max enumerator value of EVENTGPIOEDGEDETECT1 field.    */
  #define MAIN_INTENEVENTSGPIOCLR_EVENTGPIOEDGEDETECT1_LOW (0x0UL) /*!< Low                                                    */
  #define MAIN_INTENEVENTSGPIOCLR_EVENTGPIOEDGEDETECT1_HIGH (0x1UL) /*!< High                                                  */

/* EVENTGPIOEDGEDETECT2 @Bit 2 : Writing 1 disables interrupts from EVENTGPIOEDGEDETECT2 */
  #define MAIN_INTENEVENTSGPIOCLR_EVENTGPIOEDGEDETECT2_Pos (2UL) /*!< Position of EVENTGPIOEDGEDETECT2 field.                  */
  #define MAIN_INTENEVENTSGPIOCLR_EVENTGPIOEDGEDETECT2_Msk (0x1UL << MAIN_INTENEVENTSGPIOCLR_EVENTGPIOEDGEDETECT2_Pos) /*!< Bit
                                                                            mask of EVENTGPIOEDGEDETECT2 field.*/                 
  #define MAIN_INTENEVENTSGPIOCLR_EVENTGPIOEDGEDETECT2_Min (0x0UL) /*!< Min enumerator value of EVENTGPIOEDGEDETECT2 field.    */
  #define MAIN_INTENEVENTSGPIOCLR_EVENTGPIOEDGEDETECT2_Max (0x1UL) /*!< Max enumerator value of EVENTGPIOEDGEDETECT2 field.    */
  #define MAIN_INTENEVENTSGPIOCLR_EVENTGPIOEDGEDETECT2_LOW (0x0UL) /*!< Low                                                    */
  #define MAIN_INTENEVENTSGPIOCLR_EVENTGPIOEDGEDETECT2_HIGH (0x1UL) /*!< High                                                  */

/* EVENTGPIOEDGEDETECT3 @Bit 3 : Writing 1 disables interrupts from EVENTGPIOEDGEDETECT3 */
  #define MAIN_INTENEVENTSGPIOCLR_EVENTGPIOEDGEDETECT3_Pos (3UL) /*!< Position of EVENTGPIOEDGEDETECT3 field.                  */
  #define MAIN_INTENEVENTSGPIOCLR_EVENTGPIOEDGEDETECT3_Msk (0x1UL << MAIN_INTENEVENTSGPIOCLR_EVENTGPIOEDGEDETECT3_Pos) /*!< Bit
                                                                            mask of EVENTGPIOEDGEDETECT3 field.*/                 
  #define MAIN_INTENEVENTSGPIOCLR_EVENTGPIOEDGEDETECT3_Min (0x0UL) /*!< Min enumerator value of EVENTGPIOEDGEDETECT3 field.    */
  #define MAIN_INTENEVENTSGPIOCLR_EVENTGPIOEDGEDETECT3_Max (0x1UL) /*!< Max enumerator value of EVENTGPIOEDGEDETECT3 field.    */
  #define MAIN_INTENEVENTSGPIOCLR_EVENTGPIOEDGEDETECT3_LOW (0x0UL) /*!< Low                                                    */
  #define MAIN_INTENEVENTSGPIOCLR_EVENTGPIOEDGEDETECT3_HIGH (0x1UL) /*!< High                                                  */

/* EVENTGPIOEDGEDETECT4 @Bit 4 : Writing 1 disables interrupts from EVENTGPIOEDGEDETECT4 */
  #define MAIN_INTENEVENTSGPIOCLR_EVENTGPIOEDGEDETECT4_Pos (4UL) /*!< Position of EVENTGPIOEDGEDETECT4 field.                  */
  #define MAIN_INTENEVENTSGPIOCLR_EVENTGPIOEDGEDETECT4_Msk (0x1UL << MAIN_INTENEVENTSGPIOCLR_EVENTGPIOEDGEDETECT4_Pos) /*!< Bit
                                                                            mask of EVENTGPIOEDGEDETECT4 field.*/                 
  #define MAIN_INTENEVENTSGPIOCLR_EVENTGPIOEDGEDETECT4_Min (0x0UL) /*!< Min enumerator value of EVENTGPIOEDGEDETECT4 field.    */
  #define MAIN_INTENEVENTSGPIOCLR_EVENTGPIOEDGEDETECT4_Max (0x1UL) /*!< Max enumerator value of EVENTGPIOEDGEDETECT4 field.    */
  #define MAIN_INTENEVENTSGPIOCLR_EVENTGPIOEDGEDETECT4_LOW (0x0UL) /*!< Low                                                    */
  #define MAIN_INTENEVENTSGPIOCLR_EVENTGPIOEDGEDETECT4_HIGH (0x1UL) /*!< High                                                  */


#endif                                               /*!< !defined(__ASSEMBLER__) && !defined(__ASSEMBLY__)                    */

/* =========================================================================================================================== */
/* ================                                          SYSTEM                                          ================ */
/* =========================================================================================================================== */

#if !defined(__ASSEMBLER__) && !defined(__ASSEMBLY__) /*!< Ignore C structs for assembly code.                                 */
/* ====================================================== Struct SYSTEM ====================================================== */
/**
  * @brief nPM1304 SYSTEM registers
  */
  typedef struct {                                   /*!< SYSTEM Structure                                                     */
    __IM uint8_t  RESERVED;
    __IM uint8_t  SYSLABEL;                          /*!< (@ 0x00000001) Label value                                           */
  } NPM_SYSTEM_Type;                                 /*!< Size = 2 (0x002)                                                     */

/* SYSTEM_SYSLABEL: Label value */
  #define SYSTEM_SYSLABEL_ResetValue (0x00UL)        /*!< Reset value of SYSLABEL register.                                    */

/* SYSLABEL @Bits 0..7 : label word */
  #define SYSTEM_SYSLABEL_SYSLABEL_Pos (0UL)         /*!< Position of SYSLABEL field.                                          */
  #define SYSTEM_SYSLABEL_SYSLABEL_Msk (0xFFUL << SYSTEM_SYSLABEL_SYSLABEL_Pos) /*!< Bit mask of SYSLABEL field.               */


#endif                                               /*!< !defined(__ASSEMBLER__) && !defined(__ASSEMBLY__)                    */

/* =========================================================================================================================== */
/* ================                                          VBUSIN                                          ================ */
/* =========================================================================================================================== */

#if !defined(__ASSEMBLER__) && !defined(__ASSEMBLY__) /*!< Ignore C structs for assembly code.                                 */
/* ====================================================== Struct VBUSIN ====================================================== */
/**
  * @brief nPM1304 VBUSIN registers
  */
  typedef struct {                                   /*!< VBUSIN Structure                                                     */
    __OM uint8_t  TASKUPDATEILIMSW;                  /*!< (@ 0x00000000) Select input current limit                            */
    __IOM uint8_t VBUSINILIM0;                       /*!< (@ 0x00000001) Configure input current limit NOTE: Reset value from
                                                                         OTP, value listed in this table may not be correct.*/    
    __IOM uint8_t VBUSINILIMSTARTUP;                 /*!< (@ 0x00000002) Configure input current limit for startup NOTE: Reset
                                                                         value from OTP, value listed in this table may not be
                                                                         correct.*/                                               
    __IOM uint8_t VBUSSUSPEND;                       /*!< (@ 0x00000003) Enable suspend mode                                   */
    __IM uint8_t  RESERVED;
    __IM uint8_t  USBCDETECTSTATUS;                  /*!< (@ 0x00000005) Status of charger detection                           */
    __IM uint8_t  RESERVED1;
    __IM uint8_t  VBUSINSTATUS;                      /*!< (@ 0x00000007) Status register                                       */
  } NPM_VBUSIN_Type;                                 /*!< Size = 8 (0x008)                                                     */

/* VBUSIN_TASKUPDATEILIMSW: Select input current limit */
  #define VBUSIN_TASKUPDATEILIMSW_ResetValue (0x00UL) /*!< Reset value of TASKUPDATEILIMSW register.                           */

/* TASKUPDATEILIM @Bit 0 : Switch from VBUSINLIMSTARTUP to VBUSINLIM0 */
  #define VBUSIN_TASKUPDATEILIMSW_TASKUPDATEILIM_Pos (0UL) /*!< Position of TASKUPDATEILIM field.                              */
  #define VBUSIN_TASKUPDATEILIMSW_TASKUPDATEILIM_Msk (0x1UL << VBUSIN_TASKUPDATEILIMSW_TASKUPDATEILIM_Pos) /*!< Bit mask of
                                                                            TASKUPDATEILIM field.*/                               
  #define VBUSIN_TASKUPDATEILIMSW_TASKUPDATEILIM_Min (0x0UL) /*!< Min enumerator value of TASKUPDATEILIM field.                */
  #define VBUSIN_TASKUPDATEILIMSW_TASKUPDATEILIM_Max (0x1UL) /*!< Max enumerator value of TASKUPDATEILIM field.                */
  #define VBUSIN_TASKUPDATEILIMSW_TASKUPDATEILIM_NOEFFECT (0x0UL) /*!< No effect                                               */
  #define VBUSIN_TASKUPDATEILIMSW_TASKUPDATEILIM_SELVBUSILIM0 (0x1UL) /*!< Use VBUSINLIM0. VBUS removal switches back to
                                                                           VBUSINLIMSTARTUP*/                                     


/* VBUSIN_VBUSINILIM0: Configure input current limit NOTE: Reset value from OTP, value listed in this table may not be correct.
                        */                                                                                                        
                                                                                                                                  
  #define VBUSIN_VBUSINILIM0_ResetValue (0x00UL)     /*!< Reset value of VBUSINILIM0 register.                                 */

/* VBUSINILIM0 @Bits 0..3 : Input current limit for VBUS selected by host */
  #define VBUSIN_VBUSINILIM0_VBUSINILIM0_Pos (0UL)   /*!< Position of VBUSINILIM0 field.                                       */
  #define VBUSIN_VBUSINILIM0_VBUSINILIM0_Msk (0xFUL << VBUSIN_VBUSINILIM0_VBUSINILIM0_Pos) /*!< Bit mask of VBUSINILIM0 field. */
  #define VBUSIN_VBUSINILIM0_VBUSINILIM0_Min (0x0UL) /*!< Min enumerator value of VBUSINILIM0 field.                           */
  #define VBUSIN_VBUSINILIM0_VBUSINILIM0_Max (0xFUL) /*!< Max enumerator value of VBUSINILIM0 field.                           */
  #define VBUSIN_VBUSINILIM0_VBUSINILIM0_500MA0 (0x0UL) /*!< 500 mA                                                            */
  #define VBUSIN_VBUSINILIM0_VBUSINILIM0_100MA (0x1UL) /*!< 100 mA                                                             */
  #define VBUSIN_VBUSINILIM0_VBUSINILIM0_200MA (0x2UL) /*!< 200 mA                                                             */
  #define VBUSIN_VBUSINILIM0_VBUSINILIM0_300MA (0x3UL) /*!< 300 mA                                                             */
  #define VBUSIN_VBUSINILIM0_VBUSINILIM0_400MA (0x4UL) /*!< 400 mA                                                             */
  #define VBUSIN_VBUSINILIM0_VBUSINILIM0_500MA (0x5UL) /*!< 500 mA                                                             */
  #define VBUSIN_VBUSINILIM0_VBUSINILIM0_600MA (0x6UL) /*!< 600 mA                                                             */
  #define VBUSIN_VBUSINILIM0_VBUSINILIM0_700MA (0x7UL) /*!< 700 mA                                                             */
  #define VBUSIN_VBUSINILIM0_VBUSINILIM0_800MA (0x8UL) /*!< 800 mA                                                             */
  #define VBUSIN_VBUSINILIM0_VBUSINILIM0_900MA (0x9UL) /*!< 900 mA                                                             */
  #define VBUSIN_VBUSINILIM0_VBUSINILIM0_1000MA (0xAUL) /*!< 1000 mA                                                           */
  #define VBUSIN_VBUSINILIM0_VBUSINILIM0_1100MA (0xBUL) /*!< 1100 mA                                                           */
  #define VBUSIN_VBUSINILIM0_VBUSINILIM0_1200MA (0xCUL) /*!< 1200 mA                                                           */
  #define VBUSIN_VBUSINILIM0_VBUSINILIM0_1300MA (0xDUL) /*!< 1300 mA                                                           */
  #define VBUSIN_VBUSINILIM0_VBUSINILIM0_1400MA (0xEUL) /*!< 1400 mA                                                           */
  #define VBUSIN_VBUSINILIM0_VBUSINILIM0_1500MA (0xFUL) /*!< 1500 mA                                                           */


/* VBUSIN_VBUSINILIMSTARTUP: Configure input current limit for startup NOTE: Reset value from OTP, value listed in this table
                              may not be correct. */                                                                              
                                                                                                                                  
  #define VBUSIN_VBUSINILIMSTARTUP_ResetValue (0x00UL) /*!< Reset value of VBUSINILIMSTARTUP register.                         */

/* VBUSINILIMSTARTUP @Bits 0..3 : Default input current limit for VBUS */
  #define VBUSIN_VBUSINILIMSTARTUP_VBUSINILIMSTARTUP_Pos (0UL) /*!< Position of VBUSINILIMSTARTUP field.                       */
  #define VBUSIN_VBUSINILIMSTARTUP_VBUSINILIMSTARTUP_Msk (0xFUL << VBUSIN_VBUSINILIMSTARTUP_VBUSINILIMSTARTUP_Pos) /*!< Bit mask
                                                                            of VBUSINILIMSTARTUP field.*/                         
  #define VBUSIN_VBUSINILIMSTARTUP_VBUSINILIMSTARTUP_Min (0x0UL) /*!< Min enumerator value of VBUSINILIMSTARTUP field.         */
  #define VBUSIN_VBUSINILIMSTARTUP_VBUSINILIMSTARTUP_Max (0xFUL) /*!< Max enumerator value of VBUSINILIMSTARTUP field.         */
  #define VBUSIN_VBUSINILIMSTARTUP_VBUSINILIMSTARTUP_500MA0 (0x0UL) /*!< 500 mA                                                */
  #define VBUSIN_VBUSINILIMSTARTUP_VBUSINILIMSTARTUP_100MA (0x1UL) /*!< 100 mA                                                 */
  #define VBUSIN_VBUSINILIMSTARTUP_VBUSINILIMSTARTUP_200MA (0x2UL) /*!< 200 mA                                                 */
  #define VBUSIN_VBUSINILIMSTARTUP_VBUSINILIMSTARTUP_300MA (0x3UL) /*!< 300 mA                                                 */
  #define VBUSIN_VBUSINILIMSTARTUP_VBUSINILIMSTARTUP_400MA (0x4UL) /*!< 400 mA                                                 */
  #define VBUSIN_VBUSINILIMSTARTUP_VBUSINILIMSTARTUP_500MA (0x5UL) /*!< 500 mA                                                 */
  #define VBUSIN_VBUSINILIMSTARTUP_VBUSINILIMSTARTUP_600MA (0x6UL) /*!< 600 mA                                                 */
  #define VBUSIN_VBUSINILIMSTARTUP_VBUSINILIMSTARTUP_700MA (0x7UL) /*!< 700 mA                                                 */
  #define VBUSIN_VBUSINILIMSTARTUP_VBUSINILIMSTARTUP_800MA (0x8UL) /*!< 800 mA                                                 */
  #define VBUSIN_VBUSINILIMSTARTUP_VBUSINILIMSTARTUP_900MA (0x9UL) /*!< 900 mA                                                 */
  #define VBUSIN_VBUSINILIMSTARTUP_VBUSINILIMSTARTUP_1000MA (0xAUL) /*!< 1000 mA                                               */
  #define VBUSIN_VBUSINILIMSTARTUP_VBUSINILIMSTARTUP_1100MA (0xBUL) /*!< 1100 mA                                               */
  #define VBUSIN_VBUSINILIMSTARTUP_VBUSINILIMSTARTUP_1200MA (0xCUL) /*!< 1200 mA                                               */
  #define VBUSIN_VBUSINILIMSTARTUP_VBUSINILIMSTARTUP_1300MA (0xDUL) /*!< 1300 mA                                               */
  #define VBUSIN_VBUSINILIMSTARTUP_VBUSINILIMSTARTUP_1400MA (0xEUL) /*!< 1400 mA                                               */
  #define VBUSIN_VBUSINILIMSTARTUP_VBUSINILIMSTARTUP_1500MA (0xFUL) /*!< 1500 mA                                               */


/* VBUSIN_VBUSSUSPEND: Enable suspend mode */
  #define VBUSIN_VBUSSUSPEND_ResetValue (0x00UL)     /*!< Reset value of VBUSSUSPEND register.                                 */

/* VBUSSUSPENDENA @Bit 0 : Control suspend mode */
  #define VBUSIN_VBUSSUSPEND_VBUSSUSPENDENA_Pos (0UL) /*!< Position of VBUSSUSPENDENA field.                                   */
  #define VBUSIN_VBUSSUSPEND_VBUSSUSPENDENA_Msk (0x1UL << VBUSIN_VBUSSUSPEND_VBUSSUSPENDENA_Pos) /*!< Bit mask of VBUSSUSPENDENA
                                                                            field.*/                                              
  #define VBUSIN_VBUSSUSPEND_VBUSSUSPENDENA_Min (0x0UL) /*!< Min enumerator value of VBUSSUSPENDENA field.                     */
  #define VBUSIN_VBUSSUSPEND_VBUSSUSPENDENA_Max (0x1UL) /*!< Max enumerator value of VBUSSUSPENDENA field.                     */
  #define VBUSIN_VBUSSUSPEND_VBUSSUSPENDENA_NORMAL (0x0UL) /*!< Normal mode                                                    */
  #define VBUSIN_VBUSSUSPEND_VBUSSUSPENDENA_SUSPENDMODE (0x1UL) /*!< Suspend mode                                              */


/* VBUSIN_USBCDETECTSTATUS: Status of charger detection */
  #define VBUSIN_USBCDETECTSTATUS_ResetValue (0x00UL) /*!< Reset value of USBCDETECTSTATUS register.                           */

/* VBUSINCC1CMP @Bits 0..1 : CC1 charger detection */
  #define VBUSIN_USBCDETECTSTATUS_VBUSINCC1CMP_Pos (0UL) /*!< Position of VBUSINCC1CMP field.                                  */
  #define VBUSIN_USBCDETECTSTATUS_VBUSINCC1CMP_Msk (0x3UL << VBUSIN_USBCDETECTSTATUS_VBUSINCC1CMP_Pos) /*!< Bit mask of
                                                                            VBUSINCC1CMP field.*/                                 
  #define VBUSIN_USBCDETECTSTATUS_VBUSINCC1CMP_Min (0x0UL) /*!< Min enumerator value of VBUSINCC1CMP field.                    */
  #define VBUSIN_USBCDETECTSTATUS_VBUSINCC1CMP_Max (0x3UL) /*!< Max enumerator value of VBUSINCC1CMP field.                    */
  #define VBUSIN_USBCDETECTSTATUS_VBUSINCC1CMP_NOCONNECTION (0x0UL) /*!< No connection                                         */
  #define VBUSIN_USBCDETECTSTATUS_VBUSINCC1CMP_DEFAULTUSB (0x1UL) /*!< Default USB 100/500 mA                                  */
  #define VBUSIN_USBCDETECTSTATUS_VBUSINCC1CMP_1A5HIGHPOWER (0x2UL) /*!< 1.5 A high power                                      */
  #define VBUSIN_USBCDETECTSTATUS_VBUSINCC1CMP_3AHIGHPOWER (0x3UL) /*!< 3 A high power                                         */

/* VBUSINCC2CMP @Bits 2..3 : CC2 charger detection */
  #define VBUSIN_USBCDETECTSTATUS_VBUSINCC2CMP_Pos (2UL) /*!< Position of VBUSINCC2CMP field.                                  */
  #define VBUSIN_USBCDETECTSTATUS_VBUSINCC2CMP_Msk (0x3UL << VBUSIN_USBCDETECTSTATUS_VBUSINCC2CMP_Pos) /*!< Bit mask of
                                                                            VBUSINCC2CMP field.*/                                 
  #define VBUSIN_USBCDETECTSTATUS_VBUSINCC2CMP_Min (0x0UL) /*!< Min enumerator value of VBUSINCC2CMP field.                    */
  #define VBUSIN_USBCDETECTSTATUS_VBUSINCC2CMP_Max (0x3UL) /*!< Max enumerator value of VBUSINCC2CMP field.                    */
  #define VBUSIN_USBCDETECTSTATUS_VBUSINCC2CMP_NOCONNECTION (0x0UL) /*!< No connection                                         */
  #define VBUSIN_USBCDETECTSTATUS_VBUSINCC2CMP_DEFAULTUSB (0x1UL) /*!< Default USB 100/500 mA                                  */
  #define VBUSIN_USBCDETECTSTATUS_VBUSINCC2CMP_1A5HIGHPOWER (0x2UL) /*!< 1.5 A high power                                      */
  #define VBUSIN_USBCDETECTSTATUS_VBUSINCC2CMP_3AHIGHPOWER (0x3UL) /*!< 3 A high power                                         */


/* VBUSIN_VBUSINSTATUS: Status register */
  #define VBUSIN_VBUSINSTATUS_ResetValue (0x00UL)    /*!< Reset value of VBUSINSTATUS register.                                */

/* VBUSINPRESENT @Bit 0 : VBUS present */
  #define VBUSIN_VBUSINSTATUS_VBUSINPRESENT_Pos (0UL) /*!< Position of VBUSINPRESENT field.                                    */
  #define VBUSIN_VBUSINSTATUS_VBUSINPRESENT_Msk (0x1UL << VBUSIN_VBUSINSTATUS_VBUSINPRESENT_Pos) /*!< Bit mask of VBUSINPRESENT
                                                                            field.*/                                              
  #define VBUSIN_VBUSINSTATUS_VBUSINPRESENT_Min (0x0UL) /*!< Min enumerator value of VBUSINPRESENT field.                      */
  #define VBUSIN_VBUSINSTATUS_VBUSINPRESENT_Max (0x1UL) /*!< Max enumerator value of VBUSINPRESENT field.                      */
  #define VBUSIN_VBUSINSTATUS_VBUSINPRESENT_NOTDETECTED (0x0UL) /*!< Not present                                               */
  #define VBUSIN_VBUSINSTATUS_VBUSINPRESENT_DETECTED (0x1UL) /*!< Present                                                      */

/* VBUSINCURRLIMACTIVE @Bit 1 : VBUS current limit */
  #define VBUSIN_VBUSINSTATUS_VBUSINCURRLIMACTIVE_Pos (1UL) /*!< Position of VBUSINCURRLIMACTIVE field.                        */
  #define VBUSIN_VBUSINSTATUS_VBUSINCURRLIMACTIVE_Msk (0x1UL << VBUSIN_VBUSINSTATUS_VBUSINCURRLIMACTIVE_Pos) /*!< Bit mask of
                                                                            VBUSINCURRLIMACTIVE field.*/                          
  #define VBUSIN_VBUSINSTATUS_VBUSINCURRLIMACTIVE_Min (0x0UL) /*!< Min enumerator value of VBUSINCURRLIMACTIVE field.          */
  #define VBUSIN_VBUSINSTATUS_VBUSINCURRLIMACTIVE_Max (0x1UL) /*!< Max enumerator value of VBUSINCURRLIMACTIVE field.          */
  #define VBUSIN_VBUSINSTATUS_VBUSINCURRLIMACTIVE_NOTDETECTED (0x0UL) /*!< Not active                                          */
  #define VBUSIN_VBUSINSTATUS_VBUSINCURRLIMACTIVE_DETECTED (0x1UL) /*!< Active                                                 */

/* VBUSINOVRPROTACTIVE @Bit 2 : VBUS overvoltage */
  #define VBUSIN_VBUSINSTATUS_VBUSINOVRPROTACTIVE_Pos (2UL) /*!< Position of VBUSINOVRPROTACTIVE field.                        */
  #define VBUSIN_VBUSINSTATUS_VBUSINOVRPROTACTIVE_Msk (0x1UL << VBUSIN_VBUSINSTATUS_VBUSINOVRPROTACTIVE_Pos) /*!< Bit mask of
                                                                            VBUSINOVRPROTACTIVE field.*/                          
  #define VBUSIN_VBUSINSTATUS_VBUSINOVRPROTACTIVE_Min (0x0UL) /*!< Min enumerator value of VBUSINOVRPROTACTIVE field.          */
  #define VBUSIN_VBUSINSTATUS_VBUSINOVRPROTACTIVE_Max (0x1UL) /*!< Max enumerator value of VBUSINOVRPROTACTIVE field.          */
  #define VBUSIN_VBUSINSTATUS_VBUSINOVRPROTACTIVE_NOTACTIVE (0x0UL) /*!< Not active                                            */
  #define VBUSIN_VBUSINSTATUS_VBUSINOVRPROTACTIVE_ACTIVE (0x1UL) /*!< Active                                                   */

/* VBUSINUNDERVOLTAGE @Bit 3 : VBUS undervoltage */
  #define VBUSIN_VBUSINSTATUS_VBUSINUNDERVOLTAGE_Pos (3UL) /*!< Position of VBUSINUNDERVOLTAGE field.                          */
  #define VBUSIN_VBUSINSTATUS_VBUSINUNDERVOLTAGE_Msk (0x1UL << VBUSIN_VBUSINSTATUS_VBUSINUNDERVOLTAGE_Pos) /*!< Bit mask of
                                                                            VBUSINUNDERVOLTAGE field.*/                           
  #define VBUSIN_VBUSINSTATUS_VBUSINUNDERVOLTAGE_Min (0x0UL) /*!< Min enumerator value of VBUSINUNDERVOLTAGE field.            */
  #define VBUSIN_VBUSINSTATUS_VBUSINUNDERVOLTAGE_Max (0x1UL) /*!< Max enumerator value of VBUSINUNDERVOLTAGE field.            */
  #define VBUSIN_VBUSINSTATUS_VBUSINUNDERVOLTAGE_NOTDETECTED (0x0UL) /*!< Not detected                                         */
  #define VBUSIN_VBUSINSTATUS_VBUSINUNDERVOLTAGE_DETECTED (0x1UL) /*!< Detected                                                */

/* VBUSINSUSPENDMODEACTIVE @Bit 4 : Suspend mode */
  #define VBUSIN_VBUSINSTATUS_VBUSINSUSPENDMODEACTIVE_Pos (4UL) /*!< Position of VBUSINSUSPENDMODEACTIVE field.                */
  #define VBUSIN_VBUSINSTATUS_VBUSINSUSPENDMODEACTIVE_Msk (0x1UL << VBUSIN_VBUSINSTATUS_VBUSINSUSPENDMODEACTIVE_Pos) /*!< Bit
                                                                            mask of VBUSINSUSPENDMODEACTIVE field.*/              
  #define VBUSIN_VBUSINSTATUS_VBUSINSUSPENDMODEACTIVE_Min (0x0UL) /*!< Min enumerator value of VBUSINSUSPENDMODEACTIVE field.  */
  #define VBUSIN_VBUSINSTATUS_VBUSINSUSPENDMODEACTIVE_Max (0x1UL) /*!< Max enumerator value of VBUSINSUSPENDMODEACTIVE field.  */
  #define VBUSIN_VBUSINSTATUS_VBUSINSUSPENDMODEACTIVE_NORMAL (0x0UL) /*!< Normal                                               */
  #define VBUSIN_VBUSINSTATUS_VBUSINSUSPENDMODEACTIVE_SUSPEND (0x1UL) /*!< Suspend                                             */

/* VBUSINVBUSOUTACTIVE @Bit 5 : VBUSOUT pin */
  #define VBUSIN_VBUSINSTATUS_VBUSINVBUSOUTACTIVE_Pos (5UL) /*!< Position of VBUSINVBUSOUTACTIVE field.                        */
  #define VBUSIN_VBUSINSTATUS_VBUSINVBUSOUTACTIVE_Msk (0x1UL << VBUSIN_VBUSINSTATUS_VBUSINVBUSOUTACTIVE_Pos) /*!< Bit mask of
                                                                            VBUSINVBUSOUTACTIVE field.*/                          
  #define VBUSIN_VBUSINSTATUS_VBUSINVBUSOUTACTIVE_Min (0x0UL) /*!< Min enumerator value of VBUSINVBUSOUTACTIVE field.          */
  #define VBUSIN_VBUSINSTATUS_VBUSINVBUSOUTACTIVE_Max (0x1UL) /*!< Max enumerator value of VBUSINVBUSOUTACTIVE field.          */
  #define VBUSIN_VBUSINSTATUS_VBUSINVBUSOUTACTIVE_NOTACTIVE (0x0UL) /*!< Not active                                            */
  #define VBUSIN_VBUSINSTATUS_VBUSINVBUSOUTACTIVE_ACTIVE (0x1UL) /*!< Active                                                   */


#endif                                               /*!< !defined(__ASSEMBLER__) && !defined(__ASSEMBLY__)                    */

/* =========================================================================================================================== */
/* ================                                         BCHARGER                                         ================ */
/* =========================================================================================================================== */

#if !defined(__ASSEMBLER__) && !defined(__ASSEMBLY__) /*!< Ignore C structs for assembly code.                                 */
/* ===================================================== Struct BCHARGER ===================================================== */
/**
  * @brief nPM1304 BCHARGER registers
  */
  typedef struct {                                   /*!< BCHARGER Structure                                                   */
    __OM uint8_t  TASKRELEASEERR;                    /*!< (@ 0x00000000) Release charger from error                            */
    __OM uint8_t  TASKCLEARCHGERR;                   /*!< (@ 0x00000001) Clear error registers                                 */
    __OM uint8_t  TASKCLEARSAFETYTIMER;              /*!< (@ 0x00000002) Clear safety timers                                   */
    __IM uint8_t  RESERVED;
    __IOM uint8_t BCHGENABLESET;                     /*!< (@ 0x00000004) Enable charger                                        */
    __IOM uint8_t BCHGENABLECLR;                     /*!< (@ 0x00000005) Disable charger                                       */
    __IOM uint8_t BCHGDISABLESET;                    /*!< (@ 0x00000006) Disable automatic recharge and battery temperature
                                                                         monitoring*/                                             
    __IOM uint8_t BCHGDISABLECLR;                    /*!< (@ 0x00000007) Enable automatic recharge and battery temperature
                                                                         monitoring*/                                             
    __IOM uint8_t BCHGISETMSB;                       /*!< (@ 0x00000008) Configure charge current MSB                          */
    __IOM uint8_t BCHGISETLSB;                       /*!< (@ 0x00000009) Configure charge current LSB                          */
    __IOM uint8_t BCHGISETDISCHARGEMSB;              /*!< (@ 0x0000000A) Configure discharge current limit MSB                 */
    __IOM uint8_t BCHGISETDISCHARGELSB;              /*!< (@ 0x0000000B) Configure discharge current limit LSB                 */
    __IOM uint8_t BCHGVTERM;                         /*!< (@ 0x0000000C) Configure termination voltage for cool and nominal
                                                                         temperature region*/                                     
    __IOM uint8_t BCHGVTERMR;                        /*!< (@ 0x0000000D) Configure termination voltage for warm temperature
                                                                         region*/                                                 
    __IOM uint8_t BCHGVTRICKLESEL;                   /*!< (@ 0x0000000E) Select trickle charge voltage threshold               */
    __IOM uint8_t BCHGITERMSEL;                      /*!< (@ 0x0000000F) Select terminaton current                             */
    __IOM uint8_t NTCCOLD;                           /*!< (@ 0x00000010) NTC thermistor threshold for cold temperature region  */
    __IOM uint8_t NTCCOLDLSB;                        /*!< (@ 0x00000011) NTC thermistor threshold for cold temperature region  */
    __IOM uint8_t NTCCOOL;                           /*!< (@ 0x00000012) NTC thermistor threshold for cool temperature region  */
    __IOM uint8_t NTCCOOLLSB;                        /*!< (@ 0x00000013) NTC thermistor threshold for cool temperature region  */
    __IOM uint8_t NTCWARM;                           /*!< (@ 0x00000014) NTC thermistor threshold for warm temperature region  */
    __IOM uint8_t NTCWARMLSB;                        /*!< (@ 0x00000015) NTC thermistor threshold for warm temperature region  */
    __IOM uint8_t NTCHOT;                            /*!< (@ 0x00000016) NTC thermistor threshold for hot temperature region   */
    __IOM uint8_t NTCHOTLSB;                         /*!< (@ 0x00000017) NTC thermistor threshold for hot temperature region   */
    __IOM uint8_t DIETEMPSTOP;                       /*!< (@ 0x00000018) Die temperature threshold to stop charging            */
    __IOM uint8_t DIETEMPSTOPLSB;                    /*!< (@ 0x00000019) Die temperature threshold to stop charging            */
    __IOM uint8_t DIETEMPRESUME;                     /*!< (@ 0x0000001A) Die temperature threshold to resume charging          */
    __IOM uint8_t DIETEMPRESUMELSB;                  /*!< (@ 0x0000001B) Die temperature threshold to resume charging          */
    __IM uint8_t  RESERVED1[17];
    __IM uint8_t  BCHGILIMSTATUS;                    /*!< (@ 0x0000002D) Battery discharge current limit status                */
    __IM uint8_t RESERVED2[4];
    __IM uint8_t  NTCSTATUS;                         /*!< (@ 0x00000032) Battery temperature region status                     */
    __IM uint8_t  DIETEMPSTATUS;                     /*!< (@ 0x00000033) Die temperature status                                */
    __IM uint8_t  BCHGCHARGESTATUS;                  /*!< (@ 0x00000034) Charging status                                       */
    __IM uint8_t  RESERVED3;
    __IM uint8_t  BCHGERRREASON;                     /*!< (@ 0x00000036) Charge error. Latched error reasons. Cleared with
                                                                         TASKSCLEARCHGERR*/                                       
    __IM uint8_t  BCHGERRSENSOR;                     /*!< (@ 0x00000037) Charger error. Latched conditions. Cleared with
                                                                         TASKSCLEARCHGERR*/                                       
    __IM uint8_t RESERVED4[4];
    __IOM uint8_t BCHGCONFIG;                        /*!< (@ 0x0000003C) Charger configuration                                 */
    __IM uint8_t  RESERVED5[19];
    __IOM uint8_t BCHGVBATLOWCHARGE;                 /*!< (@ 0x00000050) Enable charging at low battery voltage NOTE: Reset
                                                                         value from OTP, value listed in this table may not be
                                                                         correct.*/                                               
  } NPM_BCHARGER_Type;                               /*!< Size = 81 (0x051)                                                    */

/* BCHARGER_TASKRELEASEERR: Release charger from error */
  #define BCHARGER_TASKRELEASEERR_ResetValue (0x00UL) /*!< Reset value of TASKRELEASEERR register.                             */

/* TASKRELEASEERROR @Bit 0 : Release charger from error */
  #define BCHARGER_TASKRELEASEERR_TASKRELEASEERROR_Pos (0UL) /*!< Position of TASKRELEASEERROR field.                          */
  #define BCHARGER_TASKRELEASEERR_TASKRELEASEERROR_Msk (0x1UL << BCHARGER_TASKRELEASEERR_TASKRELEASEERROR_Pos) /*!< Bit mask of
                                                                            TASKRELEASEERROR field.*/                             
  #define BCHARGER_TASKRELEASEERR_TASKRELEASEERROR_Min (0x0UL) /*!< Min enumerator value of TASKRELEASEERROR field.            */
  #define BCHARGER_TASKRELEASEERR_TASKRELEASEERROR_Max (0x1UL) /*!< Max enumerator value of TASKRELEASEERROR field.            */
  #define BCHARGER_TASKRELEASEERR_TASKRELEASEERROR_NOEFFECT (0x0UL) /*!< No effect                                             */
  #define BCHARGER_TASKRELEASEERR_TASKRELEASEERROR_TRIGGER (0x1UL) /*!< Trigger task                                           */


/* BCHARGER_TASKCLEARCHGERR: Clear error registers */
  #define BCHARGER_TASKCLEARCHGERR_ResetValue (0x00UL) /*!< Reset value of TASKCLEARCHGERR register.                           */

/* TASKCLEARCHGERR @Bit 0 : Clear registers BCHGERRREASON and BCHGERRSENSOR */
  #define BCHARGER_TASKCLEARCHGERR_TASKCLEARCHGERR_Pos (0UL) /*!< Position of TASKCLEARCHGERR field.                           */
  #define BCHARGER_TASKCLEARCHGERR_TASKCLEARCHGERR_Msk (0x1UL << BCHARGER_TASKCLEARCHGERR_TASKCLEARCHGERR_Pos) /*!< Bit mask of
                                                                            TASKCLEARCHGERR field.*/                              
  #define BCHARGER_TASKCLEARCHGERR_TASKCLEARCHGERR_Min (0x0UL) /*!< Min enumerator value of TASKCLEARCHGERR field.             */
  #define BCHARGER_TASKCLEARCHGERR_TASKCLEARCHGERR_Max (0x1UL) /*!< Max enumerator value of TASKCLEARCHGERR field.             */
  #define BCHARGER_TASKCLEARCHGERR_TASKCLEARCHGERR_NOEFFECT (0x0UL) /*!< No effect                                             */
  #define BCHARGER_TASKCLEARCHGERR_TASKCLEARCHGERR_TRIGGER (0x1UL) /*!< Trigger task                                           */


/* BCHARGER_TASKCLEARSAFETYTIMER: Clear safety timers */
  #define BCHARGER_TASKCLEARSAFETYTIMER_ResetValue (0x00UL) /*!< Reset value of TASKCLEARSAFETYTIMER register.                 */

/* TASKCLEARSAFETYTIMER @Bit 0 : Clear trickle and charge safety timers */
  #define BCHARGER_TASKCLEARSAFETYTIMER_TASKCLEARSAFETYTIMER_Pos (0UL) /*!< Position of TASKCLEARSAFETYTIMER field.            */
  #define BCHARGER_TASKCLEARSAFETYTIMER_TASKCLEARSAFETYTIMER_Msk (0x1UL << BCHARGER_TASKCLEARSAFETYTIMER_TASKCLEARSAFETYTIMER_Pos)
                                                                            /*!< Bit mask of TASKCLEARSAFETYTIMER field.*/        
  #define BCHARGER_TASKCLEARSAFETYTIMER_TASKCLEARSAFETYTIMER_Min (0x0UL) /*!< Min enumerator value of TASKCLEARSAFETYTIMER
                                                                            field.*/                                              
  #define BCHARGER_TASKCLEARSAFETYTIMER_TASKCLEARSAFETYTIMER_Max (0x1UL) /*!< Max enumerator value of TASKCLEARSAFETYTIMER
                                                                            field.*/                                              
  #define BCHARGER_TASKCLEARSAFETYTIMER_TASKCLEARSAFETYTIMER_NOEFFECT (0x0UL) /*!< No effect                                   */
  #define BCHARGER_TASKCLEARSAFETYTIMER_TASKCLEARSAFETYTIMER_TRIGGER (0x1UL) /*!< Trigger task                                 */


/* BCHARGER_BCHGENABLESET: Enable charger */
  #define BCHARGER_BCHGENABLESET_ResetValue (0x00UL) /*!< Reset value of BCHGENABLESET register.                               */

/* ENABLECHARGING @Bit 0 : Enable charger. (Read 0: Charging disabled). (Read 1: Charging enabled). */
  #define BCHARGER_BCHGENABLESET_ENABLECHARGING_Pos (0UL) /*!< Position of ENABLECHARGING field.                               */
  #define BCHARGER_BCHGENABLESET_ENABLECHARGING_Msk (0x1UL << BCHARGER_BCHGENABLESET_ENABLECHARGING_Pos) /*!< Bit mask of
                                                                            ENABLECHARGING field.*/                               
  #define BCHARGER_BCHGENABLESET_ENABLECHARGING_Min (0x0UL) /*!< Min enumerator value of ENABLECHARGING field.                 */
  #define BCHARGER_BCHGENABLESET_ENABLECHARGING_Max (0x1UL) /*!< Max enumerator value of ENABLECHARGING field.                 */
  #define BCHARGER_BCHGENABLESET_ENABLECHARGING_NOEFFECT (0x0UL) /*!< No effect                                                */
  #define BCHARGER_BCHGENABLESET_ENABLECHARGING_ENABLECHG (0x1UL) /*!< Enable battery charging                                 */

/* ENABLEFULLCHGCOOL @Bit 1 : Enable charging of cool battery with full current. (Read 0: 50 percent charge current value of
                              BCHGISETMSB and BCHGISETLSB registers). (Read 1: 100 percent charge current value of BCHGISETMSB
                              and BCHGISETLSB registers). */                                                                      
                                                                                                                                  
  #define BCHARGER_BCHGENABLESET_ENABLEFULLCHGCOOL_Pos (1UL) /*!< Position of ENABLEFULLCHGCOOL field.                         */
  #define BCHARGER_BCHGENABLESET_ENABLEFULLCHGCOOL_Msk (0x1UL << BCHARGER_BCHGENABLESET_ENABLEFULLCHGCOOL_Pos) /*!< Bit mask of
                                                                            ENABLEFULLCHGCOOL field.*/                            
  #define BCHARGER_BCHGENABLESET_ENABLEFULLCHGCOOL_Min (0x0UL) /*!< Min enumerator value of ENABLEFULLCHGCOOL field.           */
  #define BCHARGER_BCHGENABLESET_ENABLEFULLCHGCOOL_Max (0x1UL) /*!< Max enumerator value of ENABLEFULLCHGCOOL field.           */
  #define BCHARGER_BCHGENABLESET_ENABLEFULLCHGCOOL_NOEFFECT (0x0UL) /*!< No effect                                             */
  #define BCHARGER_BCHGENABLESET_ENABLEFULLCHGCOOL_ENABLECOOL (0x1UL) /*!< Enable charging of cool battery                     */


/* BCHARGER_BCHGENABLECLR: Disable charger */
  #define BCHARGER_BCHGENABLECLR_ResetValue (0x00UL) /*!< Reset value of BCHGENABLECLR register.                               */

/* ENABLECHARGING @Bit 0 : Disable charger. (Read 0: Charging disabled). (Read 1: Charging enabled). */
  #define BCHARGER_BCHGENABLECLR_ENABLECHARGING_Pos (0UL) /*!< Position of ENABLECHARGING field.                               */
  #define BCHARGER_BCHGENABLECLR_ENABLECHARGING_Msk (0x1UL << BCHARGER_BCHGENABLECLR_ENABLECHARGING_Pos) /*!< Bit mask of
                                                                            ENABLECHARGING field.*/                               
  #define BCHARGER_BCHGENABLECLR_ENABLECHARGING_Min (0x0UL) /*!< Min enumerator value of ENABLECHARGING field.                 */
  #define BCHARGER_BCHGENABLECLR_ENABLECHARGING_Max (0x1UL) /*!< Max enumerator value of ENABLECHARGING field.                 */
  #define BCHARGER_BCHGENABLECLR_ENABLECHARGING_NOEFFECT (0x0UL) /*!< No effect                                                */
  #define BCHARGER_BCHGENABLECLR_ENABLECHARGING_DISABLECHG (0x1UL) /*!< Disable battery charging                               */

/* ENABLEFULLCHGCOOL @Bit 1 : Disable charging of cool battery with full current. (Read 0: 50 percent charge current value of
                              BCHGISETMSB and BCHGISETLSB registers). (Read 1: 100 percent charge current value of BCHGISETMSB
                              and BCHGISETLSB registers). */                                                                      
                                                                                                                                  
  #define BCHARGER_BCHGENABLECLR_ENABLEFULLCHGCOOL_Pos (1UL) /*!< Position of ENABLEFULLCHGCOOL field.                         */
  #define BCHARGER_BCHGENABLECLR_ENABLEFULLCHGCOOL_Msk (0x1UL << BCHARGER_BCHGENABLECLR_ENABLEFULLCHGCOOL_Pos) /*!< Bit mask of
                                                                            ENABLEFULLCHGCOOL field.*/                            
  #define BCHARGER_BCHGENABLECLR_ENABLEFULLCHGCOOL_Min (0x0UL) /*!< Min enumerator value of ENABLEFULLCHGCOOL field.           */
  #define BCHARGER_BCHGENABLECLR_ENABLEFULLCHGCOOL_Max (0x1UL) /*!< Max enumerator value of ENABLEFULLCHGCOOL field.           */
  #define BCHARGER_BCHGENABLECLR_ENABLEFULLCHGCOOL_NOEFFECT (0x0UL) /*!< No effect                                             */
  #define BCHARGER_BCHGENABLECLR_ENABLEFULLCHGCOOL_DISABLECOOL (0x1UL) /*!< Disable charging of cool battery                   */


/* BCHARGER_BCHGDISABLESET: Disable automatic recharge and battery temperature monitoring */
  #define BCHARGER_BCHGDISABLESET_ResetValue (0x00UL) /*!< Reset value of BCHGDISABLESET register.                             */

/* DISABLERECHARGE @Bit 0 : Disable automatic recharge. (Read 0: Recharge enabled). (Read 1: Recharge disabled). */
  #define BCHARGER_BCHGDISABLESET_DISABLERECHARGE_Pos (0UL) /*!< Position of DISABLERECHARGE field.                            */
  #define BCHARGER_BCHGDISABLESET_DISABLERECHARGE_Msk (0x1UL << BCHARGER_BCHGDISABLESET_DISABLERECHARGE_Pos) /*!< Bit mask of
                                                                            DISABLERECHARGE field.*/                              
  #define BCHARGER_BCHGDISABLESET_DISABLERECHARGE_Min (0x0UL) /*!< Min enumerator value of DISABLERECHARGE field.              */
  #define BCHARGER_BCHGDISABLESET_DISABLERECHARGE_Max (0x1UL) /*!< Max enumerator value of DISABLERECHARGE field.              */
  #define BCHARGER_BCHGDISABLESET_DISABLERECHARGE_NOEFFECT (0x0UL) /*!< No effect                                              */
  #define BCHARGER_BCHGDISABLESET_DISABLERECHARGE_DISABLERCHG (0x1UL) /*!< Disable recharging of battery once charged          */

/* DISABLENTC @Bit 1 : Disable battery temperature monitoring. (Read 0: battery temperature monitoring enabled) (Read 1: battery
                       temperature monitoring disabled) */                                                                        
                                                                                                                                  
  #define BCHARGER_BCHGDISABLESET_DISABLENTC_Pos (1UL) /*!< Position of DISABLENTC field.                                      */
  #define BCHARGER_BCHGDISABLESET_DISABLENTC_Msk (0x1UL << BCHARGER_BCHGDISABLESET_DISABLENTC_Pos) /*!< Bit mask of DISABLENTC
                                                                            field.*/                                              
  #define BCHARGER_BCHGDISABLESET_DISABLENTC_Min (0x0UL) /*!< Min enumerator value of DISABLENTC field.                        */
  #define BCHARGER_BCHGDISABLESET_DISABLENTC_Max (0x1UL) /*!< Max enumerator value of DISABLENTC field.                        */
  #define BCHARGER_BCHGDISABLESET_DISABLENTC_NOEFFECT (0x0UL) /*!< No effect                                                   */
  #define BCHARGER_BCHGDISABLESET_DISABLENTC_IGNORENTC (0x1UL) /*!< Disable battery temperature monitoring                     */


/* BCHARGER_BCHGDISABLECLR: Enable automatic recharge and battery temperature monitoring */
  #define BCHARGER_BCHGDISABLECLR_ResetValue (0x00UL) /*!< Reset value of BCHGDISABLECLR register.                             */

/* DISABLERECHARGE @Bit 0 : Enable automatic recharge. (Read 0: Recharge enabled). (Read 1: Recharge disabled). */
  #define BCHARGER_BCHGDISABLECLR_DISABLERECHARGE_Pos (0UL) /*!< Position of DISABLERECHARGE field.                            */
  #define BCHARGER_BCHGDISABLECLR_DISABLERECHARGE_Msk (0x1UL << BCHARGER_BCHGDISABLECLR_DISABLERECHARGE_Pos) /*!< Bit mask of
                                                                            DISABLERECHARGE field.*/                              
  #define BCHARGER_BCHGDISABLECLR_DISABLERECHARGE_Min (0x0UL) /*!< Min enumerator value of DISABLERECHARGE field.              */
  #define BCHARGER_BCHGDISABLECLR_DISABLERECHARGE_Max (0x1UL) /*!< Max enumerator value of DISABLERECHARGE field.              */
  #define BCHARGER_BCHGDISABLECLR_DISABLERECHARGE_NOEFFECT (0x0UL) /*!< No effect                                              */
  #define BCHARGER_BCHGDISABLECLR_DISABLERECHARGE_ENABLERCHG (0x1UL) /*!< Enable recharging of battery once charged            */

/* DISABLENTC @Bit 1 : Enable battery temperature monitoring. (Read 0: battery temperature monitoring enabled) (Read 1: battery
                       temperature monitoring disabled) */                                                                        
                                                                                                                                  
  #define BCHARGER_BCHGDISABLECLR_DISABLENTC_Pos (1UL) /*!< Position of DISABLENTC field.                                      */
  #define BCHARGER_BCHGDISABLECLR_DISABLENTC_Msk (0x1UL << BCHARGER_BCHGDISABLECLR_DISABLENTC_Pos) /*!< Bit mask of DISABLENTC
                                                                            field.*/                                              
  #define BCHARGER_BCHGDISABLECLR_DISABLENTC_Min (0x0UL) /*!< Min enumerator value of DISABLENTC field.                        */
  #define BCHARGER_BCHGDISABLECLR_DISABLENTC_Max (0x1UL) /*!< Max enumerator value of DISABLENTC field.                        */
  #define BCHARGER_BCHGDISABLECLR_DISABLENTC_NOEFFECT (0x0UL) /*!< No effect                                                   */
  #define BCHARGER_BCHGDISABLECLR_DISABLENTC_USENTC (0x1UL) /*!< Enable battery temperature monitoring                         */


/* BCHARGER_BCHGISETMSB: Configure charge current MSB */
  #define BCHARGER_BCHGISETMSB_ResetValue (0x08UL)   /*!< Reset value of BCHGISETMSB register.                                 */

/* BCHGISETCHARGEMSB @Bits 0..7 : Charge current (BCHGISETCHARGE MSB bits [8:1]). Default 4 mA. See chapter Charge current
                                  limit. */                                                                                       
                                                                                                                                  
  #define BCHARGER_BCHGISETMSB_BCHGISETCHARGEMSB_Pos (0UL) /*!< Position of BCHGISETCHARGEMSB field.                           */
  #define BCHARGER_BCHGISETMSB_BCHGISETCHARGEMSB_Msk (0xFFUL << BCHARGER_BCHGISETMSB_BCHGISETCHARGEMSB_Pos) /*!< Bit mask of
                                                                            BCHGISETCHARGEMSB field.*/                            


/* BCHARGER_BCHGISETLSB: Configure charge current LSB */
  #define BCHARGER_BCHGISETLSB_ResetValue (0x00UL)   /*!< Reset value of BCHGISETLSB register.                                 */

/* BCHGISETCHARGELSB @Bit 0 : Charge current fine tune by 0.25 mA (BCHGISETCHARGE LSB bit [0]). See chapter Charge current
                              limit. */                                                                                           
                                                                                                                                  
  #define BCHARGER_BCHGISETLSB_BCHGISETCHARGELSB_Pos (0UL) /*!< Position of BCHGISETCHARGELSB field.                           */
  #define BCHARGER_BCHGISETLSB_BCHGISETCHARGELSB_Msk (0x1UL << BCHARGER_BCHGISETLSB_BCHGISETCHARGELSB_Pos) /*!< Bit mask of
                                                                            BCHGISETCHARGELSB field.*/                            


/* BCHARGER_BCHGISETDISCHARGEMSB: Configure discharge current limit MSB */
  #define BCHARGER_BCHGISETDISCHARGEMSB_ResetValue (0xCFUL) /*!< Reset value of BCHGISETDISCHARGEMSB register.                 */

/* BCHGISETDISCHARGEMSB @Bits 0..7 : Discharge current limit (BCHGISETDISCHARGE MSB bits [8:1]). See more from chapter Battery
                                     discharge current limit. */                                                                  
                                                                                                                                  
  #define BCHARGER_BCHGISETDISCHARGEMSB_BCHGISETDISCHARGEMSB_Pos (0UL) /*!< Position of BCHGISETDISCHARGEMSB field.            */
  #define BCHARGER_BCHGISETDISCHARGEMSB_BCHGISETDISCHARGEMSB_Msk (0xFFUL << BCHARGER_BCHGISETDISCHARGEMSB_BCHGISETDISCHARGEMSB_Pos)
                                                                            /*!< Bit mask of BCHGISETDISCHARGEMSB field.*/        


/* BCHARGER_BCHGISETDISCHARGELSB: Configure discharge current limit LSB */
  #define BCHARGER_BCHGISETDISCHARGELSB_ResetValue (0x01UL) /*!< Reset value of BCHGISETDISCHARGELSB register.                 */

/* BCHGISETDISCHARGELSB @Bit 0 : Discharge current limit fine tune (BCHGISETDISCHARGE LSB bit [0]). See more from chapter
                                 Battery discharge current limit. */                                                              
                                                                                                                                  
  #define BCHARGER_BCHGISETDISCHARGELSB_BCHGISETDISCHARGELSB_Pos (0UL) /*!< Position of BCHGISETDISCHARGELSB field.            */
  #define BCHARGER_BCHGISETDISCHARGELSB_BCHGISETDISCHARGELSB_Msk (0x1UL << BCHARGER_BCHGISETDISCHARGELSB_BCHGISETDISCHARGELSB_Pos)
                                                                            /*!< Bit mask of BCHGISETDISCHARGELSB field.*/        


/* BCHARGER_BCHGVTERM: Configure termination voltage for cool and nominal temperature region */
  #define BCHARGER_BCHGVTERM_ResetValue (0x02UL)     /*!< Reset value of BCHGVTERM register.                                   */

/* BCHGVTERMNORM @Bits 0..3 : Configure termination voltage for cool and nominal temperature region. */
  #define BCHARGER_BCHGVTERM_BCHGVTERMNORM_Pos (0UL) /*!< Position of BCHGVTERMNORM field.                                     */
  #define BCHARGER_BCHGVTERM_BCHGVTERMNORM_Msk (0xFUL << BCHARGER_BCHGVTERM_BCHGVTERMNORM_Pos) /*!< Bit mask of BCHGVTERMNORM
                                                                            field.*/                                              
  #define BCHARGER_BCHGVTERM_BCHGVTERMNORM_Min (0x0UL) /*!< Min enumerator value of BCHGVTERMNORM field.                       */
  #define BCHARGER_BCHGVTERM_BCHGVTERMNORM_Max (0xFUL) /*!< Max enumerator value of BCHGVTERMNORM field.                       */
  #define BCHARGER_BCHGVTERM_BCHGVTERMNORM_3V60 (0x0UL) /*!< 3.60 V                                                            */
  #define BCHARGER_BCHGVTERM_BCHGVTERMNORM_3V65 (0x1UL) /*!< 3.65 V                                                            */
  #define BCHARGER_BCHGVTERM_BCHGVTERMNORM_4V0 (0x2UL) /*!< 4.0 V (default)                                                    */
  #define BCHARGER_BCHGVTERM_BCHGVTERMNORM_4V05 (0x3UL) /*!< 4.05 V                                                            */
  #define BCHARGER_BCHGVTERM_BCHGVTERMNORM_4V10 (0x4UL) /*!< 4.10 V                                                            */
  #define BCHARGER_BCHGVTERM_BCHGVTERMNORM_4V15 (0x5UL) /*!< 4.15 V                                                            */
  #define BCHARGER_BCHGVTERM_BCHGVTERMNORM_4V20 (0x6UL) /*!< 4.20 V                                                            */
  #define BCHARGER_BCHGVTERM_BCHGVTERMNORM_4V25 (0x7UL) /*!< 4.25 V                                                            */
  #define BCHARGER_BCHGVTERM_BCHGVTERMNORM_4V30 (0x8UL) /*!< 4.30 V                                                            */
  #define BCHARGER_BCHGVTERM_BCHGVTERMNORM_4V35 (0x9UL) /*!< 4.35 V                                                            */
  #define BCHARGER_BCHGVTERM_BCHGVTERMNORM_4V40 (0xAUL) /*!< 4.40 V                                                            */
  #define BCHARGER_BCHGVTERM_BCHGVTERMNORM_4V45 (0xBUL) /*!< 4.45 V                                                            */
  #define BCHARGER_BCHGVTERM_BCHGVTERMNORM_4V50 (0xCUL) /*!< 4.50 V                                                            */
  #define BCHARGER_BCHGVTERM_BCHGVTERMNORM_4V55 (0xDUL) /*!< 4.55 V                                                            */
  #define BCHARGER_BCHGVTERM_BCHGVTERMNORM_4V60 (0xEUL) /*!< 4.60 V                                                            */
  #define BCHARGER_BCHGVTERM_BCHGVTERMNORM_4V65 (0xFUL) /*!< 4.65 V                                                            */


/* BCHARGER_BCHGVTERMR: Configure termination voltage for warm temperature region */
  #define BCHARGER_BCHGVTERMR_ResetValue (0x02UL)    /*!< Reset value of BCHGVTERMR register.                                  */

/* BCHGVTERMREDUCED @Bits 0..3 : Configure termination voltage for warm temperature region. */
  #define BCHARGER_BCHGVTERMR_BCHGVTERMREDUCED_Pos (0UL) /*!< Position of BCHGVTERMREDUCED field.                              */
  #define BCHARGER_BCHGVTERMR_BCHGVTERMREDUCED_Msk (0xFUL << BCHARGER_BCHGVTERMR_BCHGVTERMREDUCED_Pos) /*!< Bit mask of
                                                                            BCHGVTERMREDUCED field.*/                             
  #define BCHARGER_BCHGVTERMR_BCHGVTERMREDUCED_Min (0x0UL) /*!< Min enumerator value of BCHGVTERMREDUCED field.                */
  #define BCHARGER_BCHGVTERMR_BCHGVTERMREDUCED_Max (0xFUL) /*!< Max enumerator value of BCHGVTERMREDUCED field.                */
  #define BCHARGER_BCHGVTERMR_BCHGVTERMREDUCED_3V60 (0x0UL) /*!< 3.60 V                                                        */
  #define BCHARGER_BCHGVTERMR_BCHGVTERMREDUCED_3V65 (0x1UL) /*!< 3.65 V                                                        */
  #define BCHARGER_BCHGVTERMR_BCHGVTERMREDUCED_4V00 (0x2UL) /*!< 4.0 V (default)                                                */
  #define BCHARGER_BCHGVTERMR_BCHGVTERMREDUCED_4V05 (0x3UL) /*!< 4.05 V                                                        */
  #define BCHARGER_BCHGVTERMR_BCHGVTERMREDUCED_4V10 (0x4UL) /*!< 4.10 V                                                        */
  #define BCHARGER_BCHGVTERMR_BCHGVTERMREDUCED_4V15 (0x5UL) /*!< 4.15 V                                                        */
  #define BCHARGER_BCHGVTERMR_BCHGVTERMREDUCED_4V20 (0x6UL) /*!< 4.20 V                                                        */
  #define BCHARGER_BCHGVTERMR_BCHGVTERMREDUCED_4V25 (0x7UL) /*!< 4.25 V                                                        */
  #define BCHARGER_BCHGVTERMR_BCHGVTERMREDUCED_4V30 (0x8UL) /*!< 4.30 V                                                        */
  #define BCHARGER_BCHGVTERMR_BCHGVTERMREDUCED_4V35 (0x9UL) /*!< 4.35 V                                                        */
  #define BCHARGER_BCHGVTERMR_BCHGVTERMREDUCED_4V40 (0xAUL) /*!< 4.40 V                                                        */
  #define BCHARGER_BCHGVTERMR_BCHGVTERMREDUCED_4V45 (0xBUL) /*!< 4.45 V                                                        */
  #define BCHARGER_BCHGVTERMR_BCHGVTERMREDUCED_4V50 (0xCUL) /*!< 4.50 V                                                        */
  #define BCHARGER_BCHGVTERMR_BCHGVTERMREDUCED_4V55 (0xDUL) /*!< 4.55 V                                                        */
  #define BCHARGER_BCHGVTERMR_BCHGVTERMREDUCED_4V60 (0xEUL) /*!< 4.60 V                                                        */
  #define BCHARGER_BCHGVTERMR_BCHGVTERMREDUCED_4V65 (0xFUL) /*!< 4.65 V                                                        */


/* BCHARGER_BCHGVTRICKLESEL: Select trickle charge voltage threshold */
  #define BCHARGER_BCHGVTRICKLESEL_ResetValue (0x00UL) /*!< Reset value of BCHGVTRICKLESEL register.                           */

/* BCHGVTRICKLESEL @Bit 0 : Select trickle charge voltage threshold */
  #define BCHARGER_BCHGVTRICKLESEL_BCHGVTRICKLESEL_Pos (0UL) /*!< Position of BCHGVTRICKLESEL field.                           */
  #define BCHARGER_BCHGVTRICKLESEL_BCHGVTRICKLESEL_Msk (0x1UL << BCHARGER_BCHGVTRICKLESEL_BCHGVTRICKLESEL_Pos) /*!< Bit mask of
                                                                            BCHGVTRICKLESEL field.*/                              
  #define BCHARGER_BCHGVTRICKLESEL_BCHGVTRICKLESEL_Min (0x0UL) /*!< Min enumerator value of BCHGVTRICKLESEL field.             */
  #define BCHARGER_BCHGVTRICKLESEL_BCHGVTRICKLESEL_Max (0x1UL) /*!< Max enumerator value of BCHGVTRICKLESEL field.             */
  #define BCHARGER_BCHGVTRICKLESEL_BCHGVTRICKLESEL_2V9 (0x0UL) /*!< 2.9 V (default)                                            */
  #define BCHARGER_BCHGVTRICKLESEL_BCHGVTRICKLESEL_2V5 (0x1UL) /*!< 2.5 V                                                      */


/* BCHARGER_BCHGITERMSEL: Select terminaton current */
  #define BCHARGER_BCHGITERMSEL_ResetValue (0x00UL)  /*!< Reset value of BCHGITERMSEL register.                                */

/* BCHGITERMSEL @Bit 0 : Select terminaton current */
  #define BCHARGER_BCHGITERMSEL_BCHGITERMSEL_Pos (0UL) /*!< Position of BCHGITERMSEL field.                                    */
  #define BCHARGER_BCHGITERMSEL_BCHGITERMSEL_Msk (0x1UL << BCHARGER_BCHGITERMSEL_BCHGITERMSEL_Pos) /*!< Bit mask of BCHGITERMSEL
                                                                            field.*/                                              
  #define BCHARGER_BCHGITERMSEL_BCHGITERMSEL_Min (0x0UL) /*!< Min enumerator value of BCHGITERMSEL field.                      */
  #define BCHARGER_BCHGITERMSEL_BCHGITERMSEL_Max (0x1UL) /*!< Max enumerator value of BCHGITERMSEL field.                      */
  #define BCHARGER_BCHGITERMSEL_BCHGITERMSEL_SEL10 (0x0UL) /*!< 10 percent (default)                                           */
  #define BCHARGER_BCHGITERMSEL_BCHGITERMSEL_SEL5 (0x1UL) /*!< 5 percent                                                       */


/* BCHARGER_NTCCOLD: NTC thermistor threshold for cold temperature region */
  #define BCHARGER_NTCCOLD_ResetValue (0xBBUL)       /*!< Reset value of NTCCOLD register.                                     */

/* NTCCOLDLVLMSB @Bits 0..7 : NTC cold level MSB */
  #define BCHARGER_NTCCOLD_NTCCOLDLVLMSB_Pos (0UL)   /*!< Position of NTCCOLDLVLMSB field.                                     */
  #define BCHARGER_NTCCOLD_NTCCOLDLVLMSB_Msk (0xFFUL << BCHARGER_NTCCOLD_NTCCOLDLVLMSB_Pos) /*!< Bit mask of NTCCOLDLVLMSB
                                                                            field.*/                                              


/* BCHARGER_NTCCOLDLSB: NTC thermistor threshold for cold temperature region */
  #define BCHARGER_NTCCOLDLSB_ResetValue (0x01UL)    /*!< Reset value of NTCCOLDLSB register.                                  */

/* NTCCOLDLVLLSB @Bits 0..1 : NTC cold level LSB */
  #define BCHARGER_NTCCOLDLSB_NTCCOLDLVLLSB_Pos (0UL) /*!< Position of NTCCOLDLVLLSB field.                                    */
  #define BCHARGER_NTCCOLDLSB_NTCCOLDLVLLSB_Msk (0x3UL << BCHARGER_NTCCOLDLSB_NTCCOLDLVLLSB_Pos) /*!< Bit mask of NTCCOLDLVLLSB
                                                                            field.*/                                              


/* BCHARGER_NTCCOOL: NTC thermistor threshold for cool temperature region */
  #define BCHARGER_NTCCOOL_ResetValue (0xA4UL)       /*!< Reset value of NTCCOOL register.                                     */

/* NTCCOOLLVLMSB @Bits 0..7 : NTC cool level MSB */
  #define BCHARGER_NTCCOOL_NTCCOOLLVLMSB_Pos (0UL)   /*!< Position of NTCCOOLLVLMSB field.                                     */
  #define BCHARGER_NTCCOOL_NTCCOOLLVLMSB_Msk (0xFFUL << BCHARGER_NTCCOOL_NTCCOOLLVLMSB_Pos) /*!< Bit mask of NTCCOOLLVLMSB
                                                                            field.*/                                              


/* BCHARGER_NTCCOOLLSB: NTC thermistor threshold for cool temperature region */
  #define BCHARGER_NTCCOOLLSB_ResetValue (0x02UL)    /*!< Reset value of NTCCOOLLSB register.                                  */

/* NTCCOOLLVLLSB @Bits 0..1 : NTC cool level LSB */
  #define BCHARGER_NTCCOOLLSB_NTCCOOLLVLLSB_Pos (0UL) /*!< Position of NTCCOOLLVLLSB field.                                    */
  #define BCHARGER_NTCCOOLLSB_NTCCOOLLVLLSB_Msk (0x3UL << BCHARGER_NTCCOOLLSB_NTCCOOLLVLLSB_Pos) /*!< Bit mask of NTCCOOLLVLLSB
                                                                            field.*/                                              


/* BCHARGER_NTCWARM: NTC thermistor threshold for warm temperature region */
  #define BCHARGER_NTCWARM_ResetValue (0x54UL)       /*!< Reset value of NTCWARM register.                                     */

/* NTCWARMLVLMSB @Bits 0..7 : NTC warm level MSB */
  #define BCHARGER_NTCWARM_NTCWARMLVLMSB_Pos (0UL)   /*!< Position of NTCWARMLVLMSB field.                                     */
  #define BCHARGER_NTCWARM_NTCWARMLVLMSB_Msk (0xFFUL << BCHARGER_NTCWARM_NTCWARMLVLMSB_Pos) /*!< Bit mask of NTCWARMLVLMSB
                                                                            field.*/                                              


/* BCHARGER_NTCWARMLSB: NTC thermistor threshold for warm temperature region */
  #define BCHARGER_NTCWARMLSB_ResetValue (0x01UL)    /*!< Reset value of NTCWARMLSB register.                                  */

/* NTCWARMLVLLSB @Bits 0..1 : NTC warm level LSB */
  #define BCHARGER_NTCWARMLSB_NTCWARMLVLLSB_Pos (0UL) /*!< Position of NTCWARMLVLLSB field.                                    */
  #define BCHARGER_NTCWARMLSB_NTCWARMLVLLSB_Msk (0x3UL << BCHARGER_NTCWARMLSB_NTCWARMLVLLSB_Pos) /*!< Bit mask of NTCWARMLVLLSB
                                                                            field.*/                                              


/* BCHARGER_NTCHOT: NTC thermistor threshold for hot temperature region */
  #define BCHARGER_NTCHOT_ResetValue (0x3BUL)        /*!< Reset value of NTCHOT register.                                      */

/* NTCHOTLVLMSB @Bits 0..7 : NTC hot level MSB */
  #define BCHARGER_NTCHOT_NTCHOTLVLMSB_Pos (0UL)     /*!< Position of NTCHOTLVLMSB field.                                      */
  #define BCHARGER_NTCHOT_NTCHOTLVLMSB_Msk (0xFFUL << BCHARGER_NTCHOT_NTCHOTLVLMSB_Pos) /*!< Bit mask of NTCHOTLVLMSB field.   */


/* BCHARGER_NTCHOTLSB: NTC thermistor threshold for hot temperature region */
  #define BCHARGER_NTCHOTLSB_ResetValue (0x01UL)     /*!< Reset value of NTCHOTLSB register.                                   */

/* NTCHOTLVLLSB @Bits 0..1 : NTC hot level LSB */
  #define BCHARGER_NTCHOTLSB_NTCHOTLVLLSB_Pos (0UL)  /*!< Position of NTCHOTLVLLSB field.                                      */
  #define BCHARGER_NTCHOTLSB_NTCHOTLVLLSB_Msk (0x3UL << BCHARGER_NTCHOTLSB_NTCHOTLVLLSB_Pos) /*!< Bit mask of NTCHOTLVLLSB
                                                                            field.*/                                              


/* BCHARGER_DIETEMPSTOP: Die temperature threshold to stop charging */
  #define BCHARGER_DIETEMPSTOP_ResetValue (0x5AUL)   /*!< Reset value of DIETEMPSTOP register.                                 */

/* DIETEMPSTOPCHG @Bits 0..7 : Die temperature stop charging level */
  #define BCHARGER_DIETEMPSTOP_DIETEMPSTOPCHG_Pos (0UL) /*!< Position of DIETEMPSTOPCHG field.                                 */
  #define BCHARGER_DIETEMPSTOP_DIETEMPSTOPCHG_Msk (0xFFUL << BCHARGER_DIETEMPSTOP_DIETEMPSTOPCHG_Pos) /*!< Bit mask of
                                                                            DIETEMPSTOPCHG field.*/                               


/* BCHARGER_DIETEMPSTOPLSB: Die temperature threshold to stop charging */
  #define BCHARGER_DIETEMPSTOPLSB_ResetValue (0x00UL) /*!< Reset value of DIETEMPSTOPLSB register.                             */

/* DIETEMPSTOPCHGLSB @Bits 0..1 : Die temperature stop charging level LSB */
  #define BCHARGER_DIETEMPSTOPLSB_DIETEMPSTOPCHGLSB_Pos (0UL) /*!< Position of DIETEMPSTOPCHGLSB field.                        */
  #define BCHARGER_DIETEMPSTOPLSB_DIETEMPSTOPCHGLSB_Msk (0x3UL << BCHARGER_DIETEMPSTOPLSB_DIETEMPSTOPCHGLSB_Pos) /*!< Bit mask
                                                                            of DIETEMPSTOPCHGLSB field.*/                         


/* BCHARGER_DIETEMPRESUME: Die temperature threshold to resume charging */
  #define BCHARGER_DIETEMPRESUME_ResetValue (0x5DUL) /*!< Reset value of DIETEMPRESUME register.                               */

/* DIETEMPRESUMECHG @Bits 0..7 : Die temperature resume charging level */
  #define BCHARGER_DIETEMPRESUME_DIETEMPRESUMECHG_Pos (0UL) /*!< Position of DIETEMPRESUMECHG field.                           */
  #define BCHARGER_DIETEMPRESUME_DIETEMPRESUMECHG_Msk (0xFFUL << BCHARGER_DIETEMPRESUME_DIETEMPRESUMECHG_Pos) /*!< Bit mask of
                                                                            DIETEMPRESUMECHG field.*/                             


/* BCHARGER_DIETEMPRESUMELSB: Die temperature threshold to resume charging */
  #define BCHARGER_DIETEMPRESUMELSB_ResetValue (0x00UL) /*!< Reset value of DIETEMPRESUMELSB register.                         */

/* DIETEMPRESUMECHGLSB @Bits 0..1 : Die temperature resume charging level LSB */
  #define BCHARGER_DIETEMPRESUMELSB_DIETEMPRESUMECHGLSB_Pos (0UL) /*!< Position of DIETEMPRESUMECHGLSB field.                  */
  #define BCHARGER_DIETEMPRESUMELSB_DIETEMPRESUMECHGLSB_Msk (0x3UL << BCHARGER_DIETEMPRESUMELSB_DIETEMPRESUMECHGLSB_Pos) /*!<
                                                                            Bit mask of DIETEMPRESUMECHGLSB field.*/              


/* BCHARGER_BCHGILIMSTATUS: Battery discharge current limit status */
  #define BCHARGER_BCHGILIMSTATUS_ResetValue (0x00UL) /*!< Reset value of BCHGILIMSTATUS register.                             */

/* BCHGILIMBATACTIVE @Bit 0 : Discharge current limiter active */
  #define BCHARGER_BCHGILIMSTATUS_BCHGILIMBATACTIVE_Pos (0UL) /*!< Position of BCHGILIMBATACTIVE field.                        */
  #define BCHARGER_BCHGILIMSTATUS_BCHGILIMBATACTIVE_Msk (0x1UL << BCHARGER_BCHGILIMSTATUS_BCHGILIMBATACTIVE_Pos) /*!< Bit mask
                                                                            of BCHGILIMBATACTIVE field.*/                         
  #define BCHARGER_BCHGILIMSTATUS_BCHGILIMBATACTIVE_Min (0x0UL) /*!< Min enumerator value of BCHGILIMBATACTIVE field.          */
  #define BCHARGER_BCHGILIMSTATUS_BCHGILIMBATACTIVE_Max (0x1UL) /*!< Max enumerator value of BCHGILIMBATACTIVE field.          */
  #define BCHARGER_BCHGILIMSTATUS_BCHGILIMBATACTIVE_INACTIVE (0x0UL) /*!< Battery current limiter not active                   */
  #define BCHARGER_BCHGILIMSTATUS_BCHGILIMBATACTIVE_ACTIVE (0x1UL) /*!< Battery current limiter active                         */


/* BCHARGER_NTCSTATUS: Battery temperature region status */
  #define BCHARGER_NTCSTATUS_ResetValue (0x00UL)     /*!< Reset value of NTCSTATUS register.                                   */

/* NTCCOLD @Bit 0 : Cold */
  #define BCHARGER_NTCSTATUS_NTCCOLD_Pos (0UL)       /*!< Position of NTCCOLD field.                                           */
  #define BCHARGER_NTCSTATUS_NTCCOLD_Msk (0x1UL << BCHARGER_NTCSTATUS_NTCCOLD_Pos) /*!< Bit mask of NTCCOLD field.             */

/* NTCCOOL @Bit 1 : Cool */
  #define BCHARGER_NTCSTATUS_NTCCOOL_Pos (1UL)       /*!< Position of NTCCOOL field.                                           */
  #define BCHARGER_NTCSTATUS_NTCCOOL_Msk (0x1UL << BCHARGER_NTCSTATUS_NTCCOOL_Pos) /*!< Bit mask of NTCCOOL field.             */

/* NTCWARM @Bit 2 : Warm */
  #define BCHARGER_NTCSTATUS_NTCWARM_Pos (2UL)       /*!< Position of NTCWARM field.                                           */
  #define BCHARGER_NTCSTATUS_NTCWARM_Msk (0x1UL << BCHARGER_NTCSTATUS_NTCWARM_Pos) /*!< Bit mask of NTCWARM field.             */

/* NTCHOT @Bit 3 : Hot */
  #define BCHARGER_NTCSTATUS_NTCHOT_Pos (3UL)        /*!< Position of NTCHOT field.                                            */
  #define BCHARGER_NTCSTATUS_NTCHOT_Msk (0x1UL << BCHARGER_NTCSTATUS_NTCHOT_Pos) /*!< Bit mask of NTCHOT field.                */


/* BCHARGER_DIETEMPSTATUS: Die temperature status */
  #define BCHARGER_DIETEMPSTATUS_ResetValue (0x00UL) /*!< Reset value of DIETEMPSTATUS register.                               */

/* DIETEMPHIGH @Bit 0 : Die temperature status */
  #define BCHARGER_DIETEMPSTATUS_DIETEMPHIGH_Pos (0UL) /*!< Position of DIETEMPHIGH field.                                     */
  #define BCHARGER_DIETEMPSTATUS_DIETEMPHIGH_Msk (0x1UL << BCHARGER_DIETEMPSTATUS_DIETEMPHIGH_Pos) /*!< Bit mask of DIETEMPHIGH
                                                                            field.*/                                              
  #define BCHARGER_DIETEMPSTATUS_DIETEMPHIGH_Min (0x0UL) /*!< Min enumerator value of DIETEMPHIGH field.                       */
  #define BCHARGER_DIETEMPSTATUS_DIETEMPHIGH_Max (0x1UL) /*!< Max enumerator value of DIETEMPHIGH field.                       */
  #define BCHARGER_DIETEMPSTATUS_DIETEMPHIGH_NORMAL (0x0UL) /*!< Die temperature below DIETEMPSTOP                             */
  #define BCHARGER_DIETEMPSTATUS_DIETEMPHIGH_HIGH (0x1UL) /*!< Die temperature above DIETEMPSTOP                               */


/* BCHARGER_BCHGCHARGESTATUS: Charging status */
  #define BCHARGER_BCHGCHARGESTATUS_ResetValue (0x00UL) /*!< Reset value of BCHGCHARGESTATUS register.                         */

/* BATTERYDETECTED @Bit 0 : Reserved (battery is connected) */
  #define BCHARGER_BCHGCHARGESTATUS_BATTERYDETECTED_Pos (0UL) /*!< Position of BATTERYDETECTED field.                          */
  #define BCHARGER_BCHGCHARGESTATUS_BATTERYDETECTED_Msk (0x1UL << BCHARGER_BCHGCHARGESTATUS_BATTERYDETECTED_Pos) /*!< Bit mask
                                                                            of BATTERYDETECTED field.*/                           

/* COMPLETED @Bit 1 : Charging completed (battery full) */
  #define BCHARGER_BCHGCHARGESTATUS_COMPLETED_Pos (1UL) /*!< Position of COMPLETED field.                                      */
  #define BCHARGER_BCHGCHARGESTATUS_COMPLETED_Msk (0x1UL << BCHARGER_BCHGCHARGESTATUS_COMPLETED_Pos) /*!< Bit mask of COMPLETED
                                                                            field.*/                                              

/* TRICKLECHARGE @Bit 2 : Trickle charge */
  #define BCHARGER_BCHGCHARGESTATUS_TRICKLECHARGE_Pos (2UL) /*!< Position of TRICKLECHARGE field.                              */
  #define BCHARGER_BCHGCHARGESTATUS_TRICKLECHARGE_Msk (0x1UL << BCHARGER_BCHGCHARGESTATUS_TRICKLECHARGE_Pos) /*!< Bit mask of
                                                                            TRICKLECHARGE field.*/                                

/* CONSTANTCURRENT @Bit 3 : Constant current charging */
  #define BCHARGER_BCHGCHARGESTATUS_CONSTANTCURRENT_Pos (3UL) /*!< Position of CONSTANTCURRENT field.                          */
  #define BCHARGER_BCHGCHARGESTATUS_CONSTANTCURRENT_Msk (0x1UL << BCHARGER_BCHGCHARGESTATUS_CONSTANTCURRENT_Pos) /*!< Bit mask
                                                                            of CONSTANTCURRENT field.*/                           

/* CONSTANTVOLTAGE @Bit 4 : Constant voltage charging */
  #define BCHARGER_BCHGCHARGESTATUS_CONSTANTVOLTAGE_Pos (4UL) /*!< Position of CONSTANTVOLTAGE field.                          */
  #define BCHARGER_BCHGCHARGESTATUS_CONSTANTVOLTAGE_Msk (0x1UL << BCHARGER_BCHGCHARGESTATUS_CONSTANTVOLTAGE_Pos) /*!< Bit mask
                                                                            of CONSTANTVOLTAGE field.*/                           

/* RECHARGE @Bit 5 : Battery re-charge is needed */
  #define BCHARGER_BCHGCHARGESTATUS_RECHARGE_Pos (5UL) /*!< Position of RECHARGE field.                                        */
  #define BCHARGER_BCHGCHARGESTATUS_RECHARGE_Msk (0x1UL << BCHARGER_BCHGCHARGESTATUS_RECHARGE_Pos) /*!< Bit mask of RECHARGE
                                                                            field.*/                                              

/* DIETEMPHIGHCHGPAUSED @Bit 6 : Charging stopped due to die temperature high */
  #define BCHARGER_BCHGCHARGESTATUS_DIETEMPHIGHCHGPAUSED_Pos (6UL) /*!< Position of DIETEMPHIGHCHGPAUSED field.                */
  #define BCHARGER_BCHGCHARGESTATUS_DIETEMPHIGHCHGPAUSED_Msk (0x1UL << BCHARGER_BCHGCHARGESTATUS_DIETEMPHIGHCHGPAUSED_Pos) /*!<
                                                                            Bit mask of DIETEMPHIGHCHGPAUSED field.*/             

/* SUPPLEMENTACTIVE @Bit 7 : Supplement mode active */
  #define BCHARGER_BCHGCHARGESTATUS_SUPPLEMENTACTIVE_Pos (7UL) /*!< Position of SUPPLEMENTACTIVE field.                        */
  #define BCHARGER_BCHGCHARGESTATUS_SUPPLEMENTACTIVE_Msk (0x1UL << BCHARGER_BCHGCHARGESTATUS_SUPPLEMENTACTIVE_Pos) /*!< Bit mask
                                                                            of SUPPLEMENTACTIVE field.*/                          


/* BCHARGER_BCHGERRREASON: Charge error. Latched error reasons. Cleared with TASKSCLEARCHGERR */
  #define BCHARGER_BCHGERRREASON_ResetValue (0x00UL) /*!< Reset value of BCHGERRREASON register.                               */

/* NTCSENSORERROR @Bit 0 : NTC sensor error */
  #define BCHARGER_BCHGERRREASON_NTCSENSORERROR_Pos (0UL) /*!< Position of NTCSENSORERROR field.                               */
  #define BCHARGER_BCHGERRREASON_NTCSENSORERROR_Msk (0x1UL << BCHARGER_BCHGERRREASON_NTCSENSORERROR_Pos) /*!< Bit mask of
                                                                            NTCSENSORERROR field.*/                               

/* VBATSENSORERROR @Bit 1 : Vbat sensor error */
  #define BCHARGER_BCHGERRREASON_VBATSENSORERROR_Pos (1UL) /*!< Position of VBATSENSORERROR field.                             */
  #define BCHARGER_BCHGERRREASON_VBATSENSORERROR_Msk (0x1UL << BCHARGER_BCHGERRREASON_VBATSENSORERROR_Pos) /*!< Bit mask of
                                                                            VBATSENSORERROR field.*/                              

/* VBATLOW @Bit 2 : VbatLow error */
  #define BCHARGER_BCHGERRREASON_VBATLOW_Pos (2UL)   /*!< Position of VBATLOW field.                                           */
  #define BCHARGER_BCHGERRREASON_VBATLOW_Msk (0x1UL << BCHARGER_BCHGERRREASON_VBATLOW_Pos) /*!< Bit mask of VBATLOW field.     */

/* VTRICKLE @Bit 3 : Vtrickle error */
  #define BCHARGER_BCHGERRREASON_VTRICKLE_Pos (3UL)  /*!< Position of VTRICKLE field.                                          */
  #define BCHARGER_BCHGERRREASON_VTRICKLE_Msk (0x1UL << BCHARGER_BCHGERRREASON_VTRICKLE_Pos) /*!< Bit mask of VTRICKLE field.  */

/* MEASTIMEOUT @Bit 4 : Measurement timer timeout */
  #define BCHARGER_BCHGERRREASON_MEASTIMEOUT_Pos (4UL) /*!< Position of MEASTIMEOUT field.                                     */
  #define BCHARGER_BCHGERRREASON_MEASTIMEOUT_Msk (0x1UL << BCHARGER_BCHGERRREASON_MEASTIMEOUT_Pos) /*!< Bit mask of MEASTIMEOUT
                                                                            field.*/                                              

/* CHARGETIMEOUT @Bit 5 : Charge timer timeout */
  #define BCHARGER_BCHGERRREASON_CHARGETIMEOUT_Pos (5UL) /*!< Position of CHARGETIMEOUT field.                                 */
  #define BCHARGER_BCHGERRREASON_CHARGETIMEOUT_Msk (0x1UL << BCHARGER_BCHGERRREASON_CHARGETIMEOUT_Pos) /*!< Bit mask of
                                                                            CHARGETIMEOUT field.*/                                

/* TRICKLETIMEOUT @Bit 6 : Trickle timer timeout */
  #define BCHARGER_BCHGERRREASON_TRICKLETIMEOUT_Pos (6UL) /*!< Position of TRICKLETIMEOUT field.                               */
  #define BCHARGER_BCHGERRREASON_TRICKLETIMEOUT_Msk (0x1UL << BCHARGER_BCHGERRREASON_TRICKLETIMEOUT_Pos) /*!< Bit mask of
                                                                            TRICKLETIMEOUT field.*/                               


/* BCHARGER_BCHGERRSENSOR: Charger error. Latched conditions. Cleared with TASKSCLEARCHGERR */
  #define BCHARGER_BCHGERRSENSOR_ResetValue (0x00UL) /*!< Reset value of BCHGERRSENSOR register.                               */

/* SENSORNTCCOLD @Bit 0 : NTC cold region active when error occurs */
  #define BCHARGER_BCHGERRSENSOR_SENSORNTCCOLD_Pos (0UL) /*!< Position of SENSORNTCCOLD field.                                 */
  #define BCHARGER_BCHGERRSENSOR_SENSORNTCCOLD_Msk (0x1UL << BCHARGER_BCHGERRSENSOR_SENSORNTCCOLD_Pos) /*!< Bit mask of
                                                                            SENSORNTCCOLD field.*/                                

/* SENSORNTCCOOL @Bit 1 : NTC cool region active when error occurs */
  #define BCHARGER_BCHGERRSENSOR_SENSORNTCCOOL_Pos (1UL) /*!< Position of SENSORNTCCOOL field.                                 */
  #define BCHARGER_BCHGERRSENSOR_SENSORNTCCOOL_Msk (0x1UL << BCHARGER_BCHGERRSENSOR_SENSORNTCCOOL_Pos) /*!< Bit mask of
                                                                            SENSORNTCCOOL field.*/                                

/* SENSORNTCWARM @Bit 2 : NTC warm region active when error occurs */
  #define BCHARGER_BCHGERRSENSOR_SENSORNTCWARM_Pos (2UL) /*!< Position of SENSORNTCWARM field.                                 */
  #define BCHARGER_BCHGERRSENSOR_SENSORNTCWARM_Msk (0x1UL << BCHARGER_BCHGERRSENSOR_SENSORNTCWARM_Pos) /*!< Bit mask of
                                                                            SENSORNTCWARM field.*/                                

/* SENSORNTCHOT @Bit 3 : NTC hot region active when error occurs */
  #define BCHARGER_BCHGERRSENSOR_SENSORNTCHOT_Pos (3UL) /*!< Position of SENSORNTCHOT field.                                   */
  #define BCHARGER_BCHGERRSENSOR_SENSORNTCHOT_Msk (0x1UL << BCHARGER_BCHGERRSENSOR_SENSORNTCHOT_Pos) /*!< Bit mask of
                                                                            SENSORNTCHOT field.*/                                 

/* SENSORVTERM @Bit 4 : Vterm status when error occurs */
  #define BCHARGER_BCHGERRSENSOR_SENSORVTERM_Pos (4UL) /*!< Position of SENSORVTERM field.                                     */
  #define BCHARGER_BCHGERRSENSOR_SENSORVTERM_Msk (0x1UL << BCHARGER_BCHGERRSENSOR_SENSORVTERM_Pos) /*!< Bit mask of SENSORVTERM
                                                                            field.*/                                              

/* SENSORRECHARGE @Bit 5 : Recharge status when error occurs */
  #define BCHARGER_BCHGERRSENSOR_SENSORRECHARGE_Pos (5UL) /*!< Position of SENSORRECHARGE field.                               */
  #define BCHARGER_BCHGERRSENSOR_SENSORRECHARGE_Msk (0x1UL << BCHARGER_BCHGERRSENSOR_SENSORRECHARGE_Pos) /*!< Bit mask of
                                                                            SENSORRECHARGE field.*/                               

/* SENSORVTRICKLE @Bit 6 : Vtrickle status when error occurs */
  #define BCHARGER_BCHGERRSENSOR_SENSORVTRICKLE_Pos (6UL) /*!< Position of SENSORVTRICKLE field.                               */
  #define BCHARGER_BCHGERRSENSOR_SENSORVTRICKLE_Msk (0x1UL << BCHARGER_BCHGERRSENSOR_SENSORVTRICKLE_Pos) /*!< Bit mask of
                                                                            SENSORVTRICKLE field.*/                               

/* SENSORVBATLOW @Bit 7 : Vbatlow status when error occurs */
  #define BCHARGER_BCHGERRSENSOR_SENSORVBATLOW_Pos (7UL) /*!< Position of SENSORVBATLOW field.                                 */
  #define BCHARGER_BCHGERRSENSOR_SENSORVBATLOW_Msk (0x1UL << BCHARGER_BCHGERRSENSOR_SENSORVBATLOW_Pos) /*!< Bit mask of
                                                                            SENSORVBATLOW field.*/                                


/* BCHARGER_BCHGCONFIG: Charger configuration */
  #define BCHARGER_BCHGCONFIG_ResetValue (0x00UL)    /*!< Reset value of BCHGCONFIG register.                                  */

/* DISABLECHARGEWARM @Bit 0 : Disable charging if battery is warm */
  #define BCHARGER_BCHGCONFIG_DISABLECHARGEWARM_Pos (0UL) /*!< Position of DISABLECHARGEWARM field.                            */
  #define BCHARGER_BCHGCONFIG_DISABLECHARGEWARM_Msk (0x1UL << BCHARGER_BCHGCONFIG_DISABLECHARGEWARM_Pos) /*!< Bit mask of
                                                                            DISABLECHARGEWARM field.*/                            
  #define BCHARGER_BCHGCONFIG_DISABLECHARGEWARM_Min (0x0UL) /*!< Min enumerator value of DISABLECHARGEWARM field.              */
  #define BCHARGER_BCHGCONFIG_DISABLECHARGEWARM_Max (0x1UL) /*!< Max enumerator value of DISABLECHARGEWARM field.              */
  #define BCHARGER_BCHGCONFIG_DISABLECHARGEWARM_ENABLED (0x0UL) /*!< Enable charging if battery is warm                        */
  #define BCHARGER_BCHGCONFIG_DISABLECHARGEWARM_DISABLED (0x1UL) /*!< Disable charging if battery is warm                      */


/* BCHARGER_BCHGVBATLOWCHARGE: Enable charging at low battery voltage NOTE: Reset value from OTP, value listed in this table may
                                not be correct. */                                                                                
                                                                                                                                  
  #define BCHARGER_BCHGVBATLOWCHARGE_ResetValue (0x00UL) /*!< Reset value of BCHGVBATLOWCHARGE register.                       */

/* ENABLEVBATLOWCHARGE @Bit 0 : Enable charging when low battery is below VBATLOW */
  #define BCHARGER_BCHGVBATLOWCHARGE_ENABLEVBATLOWCHARGE_Pos (0UL) /*!< Position of ENABLEVBATLOWCHARGE field.                 */
  #define BCHARGER_BCHGVBATLOWCHARGE_ENABLEVBATLOWCHARGE_Msk (0x1UL << BCHARGER_BCHGVBATLOWCHARGE_ENABLEVBATLOWCHARGE_Pos) /*!<
                                                                            Bit mask of ENABLEVBATLOWCHARGE field.*/              
  #define BCHARGER_BCHGVBATLOWCHARGE_ENABLEVBATLOWCHARGE_Min (0x0UL) /*!< Min enumerator value of ENABLEVBATLOWCHARGE field.   */
  #define BCHARGER_BCHGVBATLOWCHARGE_ENABLEVBATLOWCHARGE_Max (0x1UL) /*!< Max enumerator value of ENABLEVBATLOWCHARGE field.   */
  #define BCHARGER_BCHGVBATLOWCHARGE_ENABLEVBATLOWCHARGE_Disable (0x0UL) /*!< Disable                                          */
  #define BCHARGER_BCHGVBATLOWCHARGE_ENABLEVBATLOWCHARGE_Enable (0x1UL) /*!< Enable                                            */


#endif                                               /*!< !defined(__ASSEMBLER__) && !defined(__ASSEMBLY__)                    */

/* =========================================================================================================================== */
/* ================                                           BUCK                                           ================ */
/* =========================================================================================================================== */

#if !defined(__ASSEMBLER__) && !defined(__ASSEMBLY__) /*!< Ignore C structs for assembly code.                                 */
/* ======================================================= Struct BUCK ======================================================= */
/**
  * @brief nPM1304 BUCK registers
  */
  typedef struct {                                   /*!< BUCK Structure                                                       */
    __OM uint8_t  BUCK1ENASET;                       /*!< (@ 0x00000000) Enable BUCK1                                          */
    __OM uint8_t  BUCK1ENACLR;                       /*!< (@ 0x00000001) Disable BUCK1                                         */
    __OM uint8_t  BUCK2ENASET;                       /*!< (@ 0x00000002) Enable BUCK2                                          */
    __OM uint8_t  BUCK2ENACLR;                       /*!< (@ 0x00000003) Disable BUCK2                                         */
    __OM uint8_t  BUCK1PWMSET;                       /*!< (@ 0x00000004) Enable PWM mode for BUCK1                             */
    __OM uint8_t  BUCK1PWMCLR;                       /*!< (@ 0x00000005) Disable PWM mode for BUCK1                            */
    __OM uint8_t  BUCK2PWMSET;                       /*!< (@ 0x00000006) Enable PWM mode for BUCK2                             */
    __OM uint8_t  BUCK2PWMCLR;                       /*!< (@ 0x00000007) Disable PWM mode for BUCK2                            */
    __IOM uint8_t BUCK1NORMVOUT;                     /*!< (@ 0x00000008) Configure BUCK1 output voltage normal mode            */
    __IOM uint8_t BUCK1RETVOUT;                      /*!< (@ 0x00000009) Configure BUCK1 output voltage retention mode         */
    __IOM uint8_t BUCK2NORMVOUT;                     /*!< (@ 0x0000000A) Configure BUCK2 output voltage normal mode            */
    __IOM uint8_t BUCK2RETVOUT;                      /*!< (@ 0x0000000B) Configure BUCK2 output voltage retention mode         */
    __IOM uint8_t BUCKENCTRL;                        /*!< (@ 0x0000000C) Select GPIOs for BUCK1 and BUCK2 enabling             */
    __IOM uint8_t BUCKVRETCTRL;                      /*!< (@ 0x0000000D) Select GPIOs for controlling BUCK1 and BUCK2 retention
                                                                         voltage selection*/                                      
    __IOM uint8_t BUCKPWMCTRL;                       /*!< (@ 0x0000000E) Select GPIOs for PWM mode controlling BUCK1 and BUCK2 */
    __IOM uint8_t BUCKSWCTRLSEL;                     /*!< (@ 0x0000000F) BUCK output voltage set by pin or register            */
    __IM uint8_t  BUCK1VOUTSTATUS;                   /*!< (@ 0x00000010) BUCK1 output voltage target                           */
    __IM uint8_t  BUCK2VOUTSTATUS;                   /*!< (@ 0x00000011) BUCK2 output voltage target                           */
    __IM uint8_t  RESERVED[3];
    __IOM uint8_t BUCKCTRL0;                         /*!< (@ 0x00000015) BUCK auto mode and pull down control                  */
    __IM uint16_t RESERVED1[15];
    __IM uint8_t  BUCKSTATUS;                        /*!< (@ 0x00000034) BUCK status register                                  */
  } NPM_BUCK_Type;                                   /*!< Size = 53 (0x035)                                                    */

/* BUCK_BUCK1ENASET: Enable BUCK1 */
  #define BUCK_BUCK1ENASET_ResetValue (0x00UL)       /*!< Reset value of BUCK1ENASET register.                                 */

/* TASKBUCK1ENASET @Bit 0 : Enable BUCK1 */
  #define BUCK_BUCK1ENASET_TASKBUCK1ENASET_Pos (0UL) /*!< Position of TASKBUCK1ENASET field.                                   */
  #define BUCK_BUCK1ENASET_TASKBUCK1ENASET_Msk (0x1UL << BUCK_BUCK1ENASET_TASKBUCK1ENASET_Pos) /*!< Bit mask of TASKBUCK1ENASET
                                                                            field.*/                                              
  #define BUCK_BUCK1ENASET_TASKBUCK1ENASET_Min (0x0UL) /*!< Min enumerator value of TASKBUCK1ENASET field.                     */
  #define BUCK_BUCK1ENASET_TASKBUCK1ENASET_Max (0x1UL) /*!< Max enumerator value of TASKBUCK1ENASET field.                     */
  #define BUCK_BUCK1ENASET_TASKBUCK1ENASET_NOEFFECT (0x0UL) /*!< No effect                                                     */
  #define BUCK_BUCK1ENASET_TASKBUCK1ENASET_SET (0x1UL) /*!< Enable                                                             */


/* BUCK_BUCK1ENACLR: Disable BUCK1 */
  #define BUCK_BUCK1ENACLR_ResetValue (0x00UL)       /*!< Reset value of BUCK1ENACLR register.                                 */

/* TASKBUCK1ENACLR @Bit 0 : Disable BUCK1 */
  #define BUCK_BUCK1ENACLR_TASKBUCK1ENACLR_Pos (0UL) /*!< Position of TASKBUCK1ENACLR field.                                   */
  #define BUCK_BUCK1ENACLR_TASKBUCK1ENACLR_Msk (0x1UL << BUCK_BUCK1ENACLR_TASKBUCK1ENACLR_Pos) /*!< Bit mask of TASKBUCK1ENACLR
                                                                            field.*/                                              
  #define BUCK_BUCK1ENACLR_TASKBUCK1ENACLR_Min (0x0UL) /*!< Min enumerator value of TASKBUCK1ENACLR field.                     */
  #define BUCK_BUCK1ENACLR_TASKBUCK1ENACLR_Max (0x1UL) /*!< Max enumerator value of TASKBUCK1ENACLR field.                     */
  #define BUCK_BUCK1ENACLR_TASKBUCK1ENACLR_NOEFFECT (0x0UL) /*!< No effect                                                     */
  #define BUCK_BUCK1ENACLR_TASKBUCK1ENACLR_SET (0x1UL) /*!< Disable                                                            */


/* BUCK_BUCK2ENASET: Enable BUCK2 */
  #define BUCK_BUCK2ENASET_ResetValue (0x00UL)       /*!< Reset value of BUCK2ENASET register.                                 */

/* TASKBUCK2ENASET @Bit 0 : Enable BUCK2 */
  #define BUCK_BUCK2ENASET_TASKBUCK2ENASET_Pos (0UL) /*!< Position of TASKBUCK2ENASET field.                                   */
  #define BUCK_BUCK2ENASET_TASKBUCK2ENASET_Msk (0x1UL << BUCK_BUCK2ENASET_TASKBUCK2ENASET_Pos) /*!< Bit mask of TASKBUCK2ENASET
                                                                            field.*/                                              
  #define BUCK_BUCK2ENASET_TASKBUCK2ENASET_Min (0x0UL) /*!< Min enumerator value of TASKBUCK2ENASET field.                     */
  #define BUCK_BUCK2ENASET_TASKBUCK2ENASET_Max (0x1UL) /*!< Max enumerator value of TASKBUCK2ENASET field.                     */
  #define BUCK_BUCK2ENASET_TASKBUCK2ENASET_NOEFFECT (0x0UL) /*!< No effect                                                     */
  #define BUCK_BUCK2ENASET_TASKBUCK2ENASET_SET (0x1UL) /*!< Enable                                                             */


/* BUCK_BUCK2ENACLR: Disable BUCK2 */
  #define BUCK_BUCK2ENACLR_ResetValue (0x00UL)       /*!< Reset value of BUCK2ENACLR register.                                 */

/* TASKBUCK2ENACLR @Bit 0 : Disable BUCK2 */
  #define BUCK_BUCK2ENACLR_TASKBUCK2ENACLR_Pos (0UL) /*!< Position of TASKBUCK2ENACLR field.                                   */
  #define BUCK_BUCK2ENACLR_TASKBUCK2ENACLR_Msk (0x1UL << BUCK_BUCK2ENACLR_TASKBUCK2ENACLR_Pos) /*!< Bit mask of TASKBUCK2ENACLR
                                                                            field.*/                                              
  #define BUCK_BUCK2ENACLR_TASKBUCK2ENACLR_Min (0x0UL) /*!< Min enumerator value of TASKBUCK2ENACLR field.                     */
  #define BUCK_BUCK2ENACLR_TASKBUCK2ENACLR_Max (0x1UL) /*!< Max enumerator value of TASKBUCK2ENACLR field.                     */
  #define BUCK_BUCK2ENACLR_TASKBUCK2ENACLR_NOEFFECT (0x0UL) /*!< No effect                                                     */
  #define BUCK_BUCK2ENACLR_TASKBUCK2ENACLR_SET (0x1UL) /*!< Disable                                                            */


/* BUCK_BUCK1PWMSET: Enable PWM mode for BUCK1 */
  #define BUCK_BUCK1PWMSET_ResetValue (0x00UL)       /*!< Reset value of BUCK1PWMSET register.                                 */

/* TASKBUCK1PWMSET @Bit 0 : Enable PWM mode for BUCK1 */
  #define BUCK_BUCK1PWMSET_TASKBUCK1PWMSET_Pos (0UL) /*!< Position of TASKBUCK1PWMSET field.                                   */
  #define BUCK_BUCK1PWMSET_TASKBUCK1PWMSET_Msk (0x1UL << BUCK_BUCK1PWMSET_TASKBUCK1PWMSET_Pos) /*!< Bit mask of TASKBUCK1PWMSET
                                                                            field.*/                                              
  #define BUCK_BUCK1PWMSET_TASKBUCK1PWMSET_Min (0x0UL) /*!< Min enumerator value of TASKBUCK1PWMSET field.                     */
  #define BUCK_BUCK1PWMSET_TASKBUCK1PWMSET_Max (0x1UL) /*!< Max enumerator value of TASKBUCK1PWMSET field.                     */
  #define BUCK_BUCK1PWMSET_TASKBUCK1PWMSET_NOEFFECT (0x0UL) /*!< No effect                                                     */
  #define BUCK_BUCK1PWMSET_TASKBUCK1PWMSET_SET (0x1UL) /*!< Enable                                                             */


/* BUCK_BUCK1PWMCLR: Disable PWM mode for BUCK1 */
  #define BUCK_BUCK1PWMCLR_ResetValue (0x00UL)       /*!< Reset value of BUCK1PWMCLR register.                                 */

/* TASKBUCK1PWMCLR @Bit 0 : Disable PWM mode for BUCK1 and return to auto mode */
  #define BUCK_BUCK1PWMCLR_TASKBUCK1PWMCLR_Pos (0UL) /*!< Position of TASKBUCK1PWMCLR field.                                   */
  #define BUCK_BUCK1PWMCLR_TASKBUCK1PWMCLR_Msk (0x1UL << BUCK_BUCK1PWMCLR_TASKBUCK1PWMCLR_Pos) /*!< Bit mask of TASKBUCK1PWMCLR
                                                                            field.*/                                              
  #define BUCK_BUCK1PWMCLR_TASKBUCK1PWMCLR_Min (0x0UL) /*!< Min enumerator value of TASKBUCK1PWMCLR field.                     */
  #define BUCK_BUCK1PWMCLR_TASKBUCK1PWMCLR_Max (0x1UL) /*!< Max enumerator value of TASKBUCK1PWMCLR field.                     */
  #define BUCK_BUCK1PWMCLR_TASKBUCK1PWMCLR_NOEFFECT (0x0UL) /*!< No effect                                                     */
  #define BUCK_BUCK1PWMCLR_TASKBUCK1PWMCLR_SET (0x1UL) /*!< Disable                                                            */


/* BUCK_BUCK2PWMSET: Enable PWM mode for BUCK2 */
  #define BUCK_BUCK2PWMSET_ResetValue (0x00UL)       /*!< Reset value of BUCK2PWMSET register.                                 */

/* TASKBUCK2PWMSET @Bit 0 : Enable PWM mode for BUCK2 */
  #define BUCK_BUCK2PWMSET_TASKBUCK2PWMSET_Pos (0UL) /*!< Position of TASKBUCK2PWMSET field.                                   */
  #define BUCK_BUCK2PWMSET_TASKBUCK2PWMSET_Msk (0x1UL << BUCK_BUCK2PWMSET_TASKBUCK2PWMSET_Pos) /*!< Bit mask of TASKBUCK2PWMSET
                                                                            field.*/                                              
  #define BUCK_BUCK2PWMSET_TASKBUCK2PWMSET_Min (0x0UL) /*!< Min enumerator value of TASKBUCK2PWMSET field.                     */
  #define BUCK_BUCK2PWMSET_TASKBUCK2PWMSET_Max (0x1UL) /*!< Max enumerator value of TASKBUCK2PWMSET field.                     */
  #define BUCK_BUCK2PWMSET_TASKBUCK2PWMSET_NOEFFECT (0x0UL) /*!< No effect                                                     */
  #define BUCK_BUCK2PWMSET_TASKBUCK2PWMSET_SET (0x1UL) /*!< Enable                                                             */


/* BUCK_BUCK2PWMCLR: Disable PWM mode for BUCK2 */
  #define BUCK_BUCK2PWMCLR_ResetValue (0x00UL)       /*!< Reset value of BUCK2PWMCLR register.                                 */

/* TASKBUCK2PWMCLR @Bit 0 : Disable PWM mode for BUCK2 and return to auto mode */
  #define BUCK_BUCK2PWMCLR_TASKBUCK2PWMCLR_Pos (0UL) /*!< Position of TASKBUCK2PWMCLR field.                                   */
  #define BUCK_BUCK2PWMCLR_TASKBUCK2PWMCLR_Msk (0x1UL << BUCK_BUCK2PWMCLR_TASKBUCK2PWMCLR_Pos) /*!< Bit mask of TASKBUCK2PWMCLR
                                                                            field.*/                                              
  #define BUCK_BUCK2PWMCLR_TASKBUCK2PWMCLR_Min (0x0UL) /*!< Min enumerator value of TASKBUCK2PWMCLR field.                     */
  #define BUCK_BUCK2PWMCLR_TASKBUCK2PWMCLR_Max (0x1UL) /*!< Max enumerator value of TASKBUCK2PWMCLR field.                     */
  #define BUCK_BUCK2PWMCLR_TASKBUCK2PWMCLR_NOEFFECT (0x0UL) /*!< No effect                                                     */
  #define BUCK_BUCK2PWMCLR_TASKBUCK2PWMCLR_SET (0x1UL) /*!< Disable                                                            */


/* BUCK_BUCK1NORMVOUT: Configure BUCK1 output voltage normal mode */
  #define BUCK_BUCK1NORMVOUT_ResetValue (0x02UL)     /*!< Reset value of BUCK1NORMVOUT register.                               */

/* BUCK1NORMVOUT @Bits 0..4 : Configure BUCK1 output voltage normal mode */
  #define BUCK_BUCK1NORMVOUT_BUCK1NORMVOUT_Pos (0UL) /*!< Position of BUCK1NORMVOUT field.                                     */
  #define BUCK_BUCK1NORMVOUT_BUCK1NORMVOUT_Msk (0x1FUL << BUCK_BUCK1NORMVOUT_BUCK1NORMVOUT_Pos) /*!< Bit mask of BUCK1NORMVOUT
                                                                            field.*/                                              
  #define BUCK_BUCK1NORMVOUT_BUCK1NORMVOUT_Min (0x0UL) /*!< Min enumerator value of BUCK1NORMVOUT field.                       */
  #define BUCK_BUCK1NORMVOUT_BUCK1NORMVOUT_Max (0x18UL) /*!< Max enumerator value of BUCK1NORMVOUT field.                      */
  #define BUCK_BUCK1NORMVOUT_BUCK1NORMVOUT_1V (0x00UL) /*!< 1.0 V                                                              */
  #define BUCK_BUCK1NORMVOUT_BUCK1NORMVOUT_1V1 (0x01UL) /*!< 1.1 V                                                             */
  #define BUCK_BUCK1NORMVOUT_BUCK1NORMVOUT_1V2 (0x02UL) /*!< 1.2 V (default)                                                   */
  #define BUCK_BUCK1NORMVOUT_BUCK1NORMVOUT_1V3 (0x03UL) /*!< 1.3 V                                                             */
  #define BUCK_BUCK1NORMVOUT_BUCK1NORMVOUT_1V4 (0x04UL) /*!< 1.4 V                                                             */
  #define BUCK_BUCK1NORMVOUT_BUCK1NORMVOUT_1V5 (0x05UL) /*!< 1.5 V                                                             */
  #define BUCK_BUCK1NORMVOUT_BUCK1NORMVOUT_1V6 (0x06UL) /*!< 1.6 V                                                             */
  #define BUCK_BUCK1NORMVOUT_BUCK1NORMVOUT_1V7 (0x07UL) /*!< 1.7 V                                                             */
  #define BUCK_BUCK1NORMVOUT_BUCK1NORMVOUT_1V8 (0x08UL) /*!< 1.8 V                                                             */
  #define BUCK_BUCK1NORMVOUT_BUCK1NORMVOUT_1V9 (0x09UL) /*!< 1.9 V                                                             */
  #define BUCK_BUCK1NORMVOUT_BUCK1NORMVOUT_2V0 (0x0AUL) /*!< 2.0 V                                                             */
  #define BUCK_BUCK1NORMVOUT_BUCK1NORMVOUT_2V1 (0x0BUL) /*!< 2.1 V                                                             */
  #define BUCK_BUCK1NORMVOUT_BUCK1NORMVOUT_2V2 (0x0CUL) /*!< 2.2 V                                                             */
  #define BUCK_BUCK1NORMVOUT_BUCK1NORMVOUT_2V3 (0x0DUL) /*!< 2.3 V                                                             */
  #define BUCK_BUCK1NORMVOUT_BUCK1NORMVOUT_2V4 (0x0EUL) /*!< 2.4 V                                                             */
  #define BUCK_BUCK1NORMVOUT_BUCK1NORMVOUT_2V5 (0x0FUL) /*!< 2.5 V                                                             */
  #define BUCK_BUCK1NORMVOUT_BUCK1NORMVOUT_2V6 (0x10UL) /*!< 2.6 V                                                             */
  #define BUCK_BUCK1NORMVOUT_BUCK1NORMVOUT_2V7 (0x11UL) /*!< 2.7 V                                                             */
  #define BUCK_BUCK1NORMVOUT_BUCK1NORMVOUT_2V8 (0x12UL) /*!< 2.8 V                                                             */
  #define BUCK_BUCK1NORMVOUT_BUCK1NORMVOUT_2V9 (0x13UL) /*!< 2.9 V                                                             */
  #define BUCK_BUCK1NORMVOUT_BUCK1NORMVOUT_3V0 (0x14UL) /*!< 3.0 V                                                             */
  #define BUCK_BUCK1NORMVOUT_BUCK1NORMVOUT_3V1 (0x15UL) /*!< 3.1 V                                                             */
  #define BUCK_BUCK1NORMVOUT_BUCK1NORMVOUT_3V2 (0x16UL) /*!< 3.2 V                                                             */
  #define BUCK_BUCK1NORMVOUT_BUCK1NORMVOUT_3V3 (0x17UL) /*!< 3.3 V                                                             */
  #define BUCK_BUCK1NORMVOUT_BUCK1NORMVOUT_3V30 (0x18UL) /*!< 3.3 V                                                            */


/* BUCK_BUCK1RETVOUT: Configure BUCK1 output voltage retention mode */
  #define BUCK_BUCK1RETVOUT_ResetValue (0x02UL)      /*!< Reset value of BUCK1RETVOUT register.                                */

/* BUCK1RETVOUT @Bits 0..4 : Configure BUCK1 output voltage retention mode */
  #define BUCK_BUCK1RETVOUT_BUCK1RETVOUT_Pos (0UL)   /*!< Position of BUCK1RETVOUT field.                                      */
  #define BUCK_BUCK1RETVOUT_BUCK1RETVOUT_Msk (0x1FUL << BUCK_BUCK1RETVOUT_BUCK1RETVOUT_Pos) /*!< Bit mask of BUCK1RETVOUT
                                                                            field.*/                                              
  #define BUCK_BUCK1RETVOUT_BUCK1RETVOUT_Min (0x0UL) /*!< Min enumerator value of BUCK1RETVOUT field.                          */
  #define BUCK_BUCK1RETVOUT_BUCK1RETVOUT_Max (0x18UL) /*!< Max enumerator value of BUCK1RETVOUT field.                         */
  #define BUCK_BUCK1RETVOUT_BUCK1RETVOUT_1V (0x00UL) /*!< 1.0 V                                                                */
  #define BUCK_BUCK1RETVOUT_BUCK1RETVOUT_1V1 (0x01UL) /*!< 1.1 V                                                               */
  #define BUCK_BUCK1RETVOUT_BUCK1RETVOUT_1V2 (0x02UL) /*!< 1.2 V (default)                                                     */
  #define BUCK_BUCK1RETVOUT_BUCK1RETVOUT_1V3 (0x03UL) /*!< 1.3 V                                                               */
  #define BUCK_BUCK1RETVOUT_BUCK1RETVOUT_1V4 (0x04UL) /*!< 1.4 V                                                               */
  #define BUCK_BUCK1RETVOUT_BUCK1RETVOUT_1V5 (0x05UL) /*!< 1.5 V                                                               */
  #define BUCK_BUCK1RETVOUT_BUCK1RETVOUT_1V6 (0x06UL) /*!< 1.6 V                                                               */
  #define BUCK_BUCK1RETVOUT_BUCK1RETVOUT_1V7 (0x07UL) /*!< 1.7 V                                                               */
  #define BUCK_BUCK1RETVOUT_BUCK1RETVOUT_1V8 (0x08UL) /*!< 1.8 V                                                               */
  #define BUCK_BUCK1RETVOUT_BUCK1RETVOUT_1V9 (0x09UL) /*!< 1.9 V                                                               */
  #define BUCK_BUCK1RETVOUT_BUCK1RETVOUT_2V0 (0x0AUL) /*!< 2.0 V                                                               */
  #define BUCK_BUCK1RETVOUT_BUCK1RETVOUT_2V1 (0x0BUL) /*!< 2.1 V                                                               */
  #define BUCK_BUCK1RETVOUT_BUCK1RETVOUT_2V2 (0x0CUL) /*!< 2.2 V                                                               */
  #define BUCK_BUCK1RETVOUT_BUCK1RETVOUT_2V3 (0x0DUL) /*!< 2.3 V                                                               */
  #define BUCK_BUCK1RETVOUT_BUCK1RETVOUT_2V4 (0x0EUL) /*!< 2.4 V                                                               */
  #define BUCK_BUCK1RETVOUT_BUCK1RETVOUT_2V5 (0x0FUL) /*!< 2.5 V                                                               */
  #define BUCK_BUCK1RETVOUT_BUCK1RETVOUT_2V6 (0x10UL) /*!< 2.6 V                                                               */
  #define BUCK_BUCK1RETVOUT_BUCK1RETVOUT_2V7 (0x11UL) /*!< 2.7 V                                                               */
  #define BUCK_BUCK1RETVOUT_BUCK1RETVOUT_2V8 (0x12UL) /*!< 2.8 V                                                               */
  #define BUCK_BUCK1RETVOUT_BUCK1RETVOUT_2V9 (0x13UL) /*!< 2.9 V                                                               */
  #define BUCK_BUCK1RETVOUT_BUCK1RETVOUT_3V0 (0x14UL) /*!< 3.0 V                                                               */
  #define BUCK_BUCK1RETVOUT_BUCK1RETVOUT_3V1 (0x15UL) /*!< 3.1 V                                                               */
  #define BUCK_BUCK1RETVOUT_BUCK1RETVOUT_3V2 (0x16UL) /*!< 3.2 V                                                               */
  #define BUCK_BUCK1RETVOUT_BUCK1RETVOUT_3V3 (0x17UL) /*!< 3.3 V                                                               */
  #define BUCK_BUCK1RETVOUT_BUCK1RETVOUT_3V30 (0x18UL) /*!< 3.3 V                                                              */


/* BUCK_BUCK2NORMVOUT: Configure BUCK2 output voltage normal mode */
  #define BUCK_BUCK2NORMVOUT_ResetValue (0x08UL)     /*!< Reset value of BUCK2NORMVOUT register.                               */

/* BUCK2NORMVOUT @Bits 0..4 : Configure BUCK2 output voltage normal mode */
  #define BUCK_BUCK2NORMVOUT_BUCK2NORMVOUT_Pos (0UL) /*!< Position of BUCK2NORMVOUT field.                                     */
  #define BUCK_BUCK2NORMVOUT_BUCK2NORMVOUT_Msk (0x1FUL << BUCK_BUCK2NORMVOUT_BUCK2NORMVOUT_Pos) /*!< Bit mask of BUCK2NORMVOUT
                                                                            field.*/                                              
  #define BUCK_BUCK2NORMVOUT_BUCK2NORMVOUT_Min (0x0UL) /*!< Min enumerator value of BUCK2NORMVOUT field.                       */
  #define BUCK_BUCK2NORMVOUT_BUCK2NORMVOUT_Max (0x18UL) /*!< Max enumerator value of BUCK2NORMVOUT field.                      */
  #define BUCK_BUCK2NORMVOUT_BUCK2NORMVOUT_1V (0x00UL) /*!< 1.0 V                                                              */
  #define BUCK_BUCK2NORMVOUT_BUCK2NORMVOUT_1V1 (0x01UL) /*!< 1.1 V                                                             */
  #define BUCK_BUCK2NORMVOUT_BUCK2NORMVOUT_1V2 (0x02UL) /*!< 1.2 V                                                             */
  #define BUCK_BUCK2NORMVOUT_BUCK2NORMVOUT_1V3 (0x03UL) /*!< 1.3 V                                                             */
  #define BUCK_BUCK2NORMVOUT_BUCK2NORMVOUT_1V4 (0x04UL) /*!< 1.4 V                                                             */
  #define BUCK_BUCK2NORMVOUT_BUCK2NORMVOUT_1V5 (0x05UL) /*!< 1.5 V                                                             */
  #define BUCK_BUCK2NORMVOUT_BUCK2NORMVOUT_1V6 (0x06UL) /*!< 1.6 V                                                             */
  #define BUCK_BUCK2NORMVOUT_BUCK2NORMVOUT_1V7 (0x07UL) /*!< 1.7 V                                                             */
  #define BUCK_BUCK2NORMVOUT_BUCK2NORMVOUT_1V8 (0x08UL) /*!< 1.8 V (default)                                                   */
  #define BUCK_BUCK2NORMVOUT_BUCK2NORMVOUT_1V9 (0x09UL) /*!< 1.9 V                                                             */
  #define BUCK_BUCK2NORMVOUT_BUCK2NORMVOUT_2V0 (0x0AUL) /*!< 2.0 V                                                             */
  #define BUCK_BUCK2NORMVOUT_BUCK2NORMVOUT_2V1 (0x0BUL) /*!< 2.1 V                                                             */
  #define BUCK_BUCK2NORMVOUT_BUCK2NORMVOUT_2V2 (0x0CUL) /*!< 2.2 V                                                             */
  #define BUCK_BUCK2NORMVOUT_BUCK2NORMVOUT_2V3 (0x0DUL) /*!< 2.3 V                                                             */
  #define BUCK_BUCK2NORMVOUT_BUCK2NORMVOUT_2V4 (0x0EUL) /*!< 2.4 V                                                             */
  #define BUCK_BUCK2NORMVOUT_BUCK2NORMVOUT_2V5 (0x0FUL) /*!< 2.5 V                                                             */
  #define BUCK_BUCK2NORMVOUT_BUCK2NORMVOUT_2V6 (0x10UL) /*!< 2.6 V                                                             */
  #define BUCK_BUCK2NORMVOUT_BUCK2NORMVOUT_2V7 (0x11UL) /*!< 2.7 V                                                             */
  #define BUCK_BUCK2NORMVOUT_BUCK2NORMVOUT_2V8 (0x12UL) /*!< 2.8 V                                                             */
  #define BUCK_BUCK2NORMVOUT_BUCK2NORMVOUT_2V9 (0x13UL) /*!< 2.9 V                                                             */
  #define BUCK_BUCK2NORMVOUT_BUCK2NORMVOUT_3V0 (0x14UL) /*!< 3.0 V                                                             */
  #define BUCK_BUCK2NORMVOUT_BUCK2NORMVOUT_3V1 (0x15UL) /*!< 3.1 V                                                             */
  #define BUCK_BUCK2NORMVOUT_BUCK2NORMVOUT_3V2 (0x16UL) /*!< 3.2 V                                                             */
  #define BUCK_BUCK2NORMVOUT_BUCK2NORMVOUT_3V3 (0x17UL) /*!< 3.3 V                                                             */
  #define BUCK_BUCK2NORMVOUT_BUCK2NORMVOUT_3V30 (0x18UL) /*!< 3.3 V                                                            */


/* BUCK_BUCK2RETVOUT: Configure BUCK2 output voltage retention mode */
  #define BUCK_BUCK2RETVOUT_ResetValue (0x08UL)      /*!< Reset value of BUCK2RETVOUT register.                                */

/* BUCK2RETVOUT @Bits 0..4 : Configure BUCK2 output voltage retention mode */
  #define BUCK_BUCK2RETVOUT_BUCK2RETVOUT_Pos (0UL)   /*!< Position of BUCK2RETVOUT field.                                      */
  #define BUCK_BUCK2RETVOUT_BUCK2RETVOUT_Msk (0x1FUL << BUCK_BUCK2RETVOUT_BUCK2RETVOUT_Pos) /*!< Bit mask of BUCK2RETVOUT
                                                                            field.*/                                              
  #define BUCK_BUCK2RETVOUT_BUCK2RETVOUT_Min (0x0UL) /*!< Min enumerator value of BUCK2RETVOUT field.                          */
  #define BUCK_BUCK2RETVOUT_BUCK2RETVOUT_Max (0x18UL) /*!< Max enumerator value of BUCK2RETVOUT field.                         */
  #define BUCK_BUCK2RETVOUT_BUCK2RETVOUT_1V (0x00UL) /*!< 1.0 V                                                                */
  #define BUCK_BUCK2RETVOUT_BUCK2RETVOUT_1V1 (0x01UL) /*!< 1.1 V                                                               */
  #define BUCK_BUCK2RETVOUT_BUCK2RETVOUT_1V2 (0x02UL) /*!< 1.2 V                                                               */
  #define BUCK_BUCK2RETVOUT_BUCK2RETVOUT_1V3 (0x03UL) /*!< 1.3 V                                                               */
  #define BUCK_BUCK2RETVOUT_BUCK2RETVOUT_1V4 (0x04UL) /*!< 1.4 V                                                               */
  #define BUCK_BUCK2RETVOUT_BUCK2RETVOUT_1V5 (0x05UL) /*!< 1.5 V                                                               */
  #define BUCK_BUCK2RETVOUT_BUCK2RETVOUT_1V6 (0x06UL) /*!< 1.6 V                                                               */
  #define BUCK_BUCK2RETVOUT_BUCK2RETVOUT_1V7 (0x07UL) /*!< 1.7 V                                                               */
  #define BUCK_BUCK2RETVOUT_BUCK2RETVOUT_1V8 (0x08UL) /*!< 1.8 V (default)                                                     */
  #define BUCK_BUCK2RETVOUT_BUCK2RETVOUT_1V9 (0x09UL) /*!< 1.9 V                                                               */
  #define BUCK_BUCK2RETVOUT_BUCK2RETVOUT_2V0 (0x0AUL) /*!< 2.0 V                                                               */
  #define BUCK_BUCK2RETVOUT_BUCK2RETVOUT_2V1 (0x0BUL) /*!< 2.1 V                                                               */
  #define BUCK_BUCK2RETVOUT_BUCK2RETVOUT_2V2 (0x0CUL) /*!< 2.2 V                                                               */
  #define BUCK_BUCK2RETVOUT_BUCK2RETVOUT_2V3 (0x0DUL) /*!< 2.3 V                                                               */
  #define BUCK_BUCK2RETVOUT_BUCK2RETVOUT_2V4 (0x0EUL) /*!< 2.4 V                                                               */
  #define BUCK_BUCK2RETVOUT_BUCK2RETVOUT_2V5 (0x0FUL) /*!< 2.5 V                                                               */
  #define BUCK_BUCK2RETVOUT_BUCK2RETVOUT_2V6 (0x10UL) /*!< 2.6 V                                                               */
  #define BUCK_BUCK2RETVOUT_BUCK2RETVOUT_2V7 (0x11UL) /*!< 2.7 V                                                               */
  #define BUCK_BUCK2RETVOUT_BUCK2RETVOUT_2V8 (0x12UL) /*!< 2.8 V                                                               */
  #define BUCK_BUCK2RETVOUT_BUCK2RETVOUT_2V9 (0x13UL) /*!< 2.9 V                                                               */
  #define BUCK_BUCK2RETVOUT_BUCK2RETVOUT_3V0 (0x14UL) /*!< 3.0 V                                                               */
  #define BUCK_BUCK2RETVOUT_BUCK2RETVOUT_3V1 (0x15UL) /*!< 3.1 V                                                               */
  #define BUCK_BUCK2RETVOUT_BUCK2RETVOUT_3V2 (0x16UL) /*!< 3.2 V                                                               */
  #define BUCK_BUCK2RETVOUT_BUCK2RETVOUT_3V3 (0x17UL) /*!< 3.3 V                                                               */
  #define BUCK_BUCK2RETVOUT_BUCK2RETVOUT_3V30 (0x18UL) /*!< 3.3 V                                                              */


/* BUCK_BUCKENCTRL: Select GPIOs for BUCK1 and BUCK2 enabling */
  #define BUCK_BUCKENCTRL_ResetValue (0x00UL)        /*!< Reset value of BUCKENCTRL register.                                  */

/* BUCK1ENGPISEL @Bits 0..2 : Select which GPIO controls BUCK1 enable */
  #define BUCK_BUCKENCTRL_BUCK1ENGPISEL_Pos (0UL)    /*!< Position of BUCK1ENGPISEL field.                                     */
  #define BUCK_BUCKENCTRL_BUCK1ENGPISEL_Msk (0x7UL << BUCK_BUCKENCTRL_BUCK1ENGPISEL_Pos) /*!< Bit mask of BUCK1ENGPISEL field. */
  #define BUCK_BUCKENCTRL_BUCK1ENGPISEL_Min (0x0UL)  /*!< Min enumerator value of BUCK1ENGPISEL field.                         */
  #define BUCK_BUCKENCTRL_BUCK1ENGPISEL_Max (0x7UL)  /*!< Max enumerator value of BUCK1ENGPISEL field.                         */
  #define BUCK_BUCKENCTRL_BUCK1ENGPISEL_NOTUSED (0x0UL) /*!< Not used                                                          */
  #define BUCK_BUCKENCTRL_BUCK1ENGPISEL_GPIO0 (0x1UL) /*!< GPIO 0 selected                                                     */
  #define BUCK_BUCKENCTRL_BUCK1ENGPISEL_GPIO1 (0x2UL) /*!< GPIO 1 selected                                                     */
  #define BUCK_BUCKENCTRL_BUCK1ENGPISEL_GPIO2 (0x3UL) /*!< GPIO 2 selected                                                     */
  #define BUCK_BUCKENCTRL_BUCK1ENGPISEL_GPIO3 (0x4UL) /*!< GPIO 3 selected                                                     */
  #define BUCK_BUCKENCTRL_BUCK1ENGPISEL_GPIO4 (0x5UL) /*!< GPIO 4 selected                                                     */
  #define BUCK_BUCKENCTRL_BUCK1ENGPISEL_NOTUSED1 (0x6UL) /*!< No GPIO selected                                                 */
  #define BUCK_BUCKENCTRL_BUCK1ENGPISEL_NOTUSED2 (0x7UL) /*!< No GPIO selected                                                 */

/* BUCK2ENGPISEL @Bits 3..5 : Select which GPIO controls BUCK2 enable */
  #define BUCK_BUCKENCTRL_BUCK2ENGPISEL_Pos (3UL)    /*!< Position of BUCK2ENGPISEL field.                                     */
  #define BUCK_BUCKENCTRL_BUCK2ENGPISEL_Msk (0x7UL << BUCK_BUCKENCTRL_BUCK2ENGPISEL_Pos) /*!< Bit mask of BUCK2ENGPISEL field. */
  #define BUCK_BUCKENCTRL_BUCK2ENGPISEL_Min (0x0UL)  /*!< Min enumerator value of BUCK2ENGPISEL field.                         */
  #define BUCK_BUCKENCTRL_BUCK2ENGPISEL_Max (0x7UL)  /*!< Max enumerator value of BUCK2ENGPISEL field.                         */
  #define BUCK_BUCKENCTRL_BUCK2ENGPISEL_NOTUSED1 (0x0UL) /*!< Not used                                                         */
  #define BUCK_BUCKENCTRL_BUCK2ENGPISEL_GPIO0 (0x1UL) /*!< GPIO 0 selected                                                     */
  #define BUCK_BUCKENCTRL_BUCK2ENGPISEL_GPIO1 (0x2UL) /*!< GPIO 1 selected                                                     */
  #define BUCK_BUCKENCTRL_BUCK2ENGPISEL_GPIO2 (0x3UL) /*!< GPIO 2 selected                                                     */
  #define BUCK_BUCKENCTRL_BUCK2ENGPISEL_GPIO3 (0x4UL) /*!< GPIO 3 selected                                                     */
  #define BUCK_BUCKENCTRL_BUCK2ENGPISEL_GPIO4 (0x5UL) /*!< GPIO 4 selected                                                     */
  #define BUCK_BUCKENCTRL_BUCK2ENGPISEL_NOTUSED3 (0x6UL) /*!< No GPIO selected                                                 */
  #define BUCK_BUCKENCTRL_BUCK2ENGPISEL_NOTUSED4 (0x7UL) /*!< No GPIO selected                                                 */

/* BUCK1ENGPIINV @Bit 6 : Invert the sense of the selected GPIO for BUCK1 */
  #define BUCK_BUCKENCTRL_BUCK1ENGPIINV_Pos (6UL)    /*!< Position of BUCK1ENGPIINV field.                                     */
  #define BUCK_BUCKENCTRL_BUCK1ENGPIINV_Msk (0x1UL << BUCK_BUCKENCTRL_BUCK1ENGPIINV_Pos) /*!< Bit mask of BUCK1ENGPIINV field. */
  #define BUCK_BUCKENCTRL_BUCK1ENGPIINV_Min (0x0UL)  /*!< Min enumerator value of BUCK1ENGPIINV field.                         */
  #define BUCK_BUCKENCTRL_BUCK1ENGPIINV_Max (0x1UL)  /*!< Max enumerator value of BUCK1ENGPIINV field.                         */
  #define BUCK_BUCKENCTRL_BUCK1ENGPIINV_NORMAL (0x0UL) /*!< Not inverted                                                       */
  #define BUCK_BUCKENCTRL_BUCK1ENGPIINV_INVERTED (0x1UL) /*!< Inverted                                                         */

/* BUCK2ENGPIINV @Bit 7 : Invert the sense of the selected GPIO for BUCK2 */
  #define BUCK_BUCKENCTRL_BUCK2ENGPIINV_Pos (7UL)    /*!< Position of BUCK2ENGPIINV field.                                     */
  #define BUCK_BUCKENCTRL_BUCK2ENGPIINV_Msk (0x1UL << BUCK_BUCKENCTRL_BUCK2ENGPIINV_Pos) /*!< Bit mask of BUCK2ENGPIINV field. */
  #define BUCK_BUCKENCTRL_BUCK2ENGPIINV_Min (0x0UL)  /*!< Min enumerator value of BUCK2ENGPIINV field.                         */
  #define BUCK_BUCKENCTRL_BUCK2ENGPIINV_Max (0x1UL)  /*!< Max enumerator value of BUCK2ENGPIINV field.                         */
  #define BUCK_BUCKENCTRL_BUCK2ENGPIINV_NORMAL (0x0UL) /*!< Not inverted                                                       */
  #define BUCK_BUCKENCTRL_BUCK2ENGPIINV_INVERTED (0x1UL) /*!< Inverted                                                         */


/* BUCK_BUCKVRETCTRL: Select GPIOs for controlling BUCK1 and BUCK2 retention voltage selection */
  #define BUCK_BUCKVRETCTRL_ResetValue (0x00UL)      /*!< Reset value of BUCKVRETCTRL register.                                */

/* BUCK1VRETGPISEL @Bits 0..2 : Select which GPIO controls BUCK1 retention voltage */
  #define BUCK_BUCKVRETCTRL_BUCK1VRETGPISEL_Pos (0UL) /*!< Position of BUCK1VRETGPISEL field.                                  */
  #define BUCK_BUCKVRETCTRL_BUCK1VRETGPISEL_Msk (0x7UL << BUCK_BUCKVRETCTRL_BUCK1VRETGPISEL_Pos) /*!< Bit mask of
                                                                            BUCK1VRETGPISEL field.*/                              
  #define BUCK_BUCKVRETCTRL_BUCK1VRETGPISEL_Min (0x0UL) /*!< Min enumerator value of BUCK1VRETGPISEL field.                    */
  #define BUCK_BUCKVRETCTRL_BUCK1VRETGPISEL_Max (0x7UL) /*!< Max enumerator value of BUCK1VRETGPISEL field.                    */
  #define BUCK_BUCKVRETCTRL_BUCK1VRETGPISEL_NOTUSED (0x0UL) /*!< Not used                                                      */
  #define BUCK_BUCKVRETCTRL_BUCK1VRETGPISEL_GPIO0 (0x1UL) /*!< GPIO 0 selected                                                 */
  #define BUCK_BUCKVRETCTRL_BUCK1VRETGPISEL_GPIO1 (0x2UL) /*!< GPIO 1 selected                                                 */
  #define BUCK_BUCKVRETCTRL_BUCK1VRETGPISEL_GPIO2 (0x3UL) /*!< GPIO 2 selected                                                 */
  #define BUCK_BUCKVRETCTRL_BUCK1VRETGPISEL_GPIO3 (0x4UL) /*!< GPIO 3 selected                                                 */
  #define BUCK_BUCKVRETCTRL_BUCK1VRETGPISEL_GPIO4 (0x5UL) /*!< GPIO 4 selected                                                 */
  #define BUCK_BUCKVRETCTRL_BUCK1VRETGPISEL_NOTUSED2 (0x6UL) /*!< Not used                                                     */
  #define BUCK_BUCKVRETCTRL_BUCK1VRETGPISEL_NOTUSED1 (0x7UL) /*!< Not used                                                     */

/* BUCK2VRETGPISEL @Bits 3..5 : Select which GPIO controls BUCK2 retention voltage */
  #define BUCK_BUCKVRETCTRL_BUCK2VRETGPISEL_Pos (3UL) /*!< Position of BUCK2VRETGPISEL field.                                  */
  #define BUCK_BUCKVRETCTRL_BUCK2VRETGPISEL_Msk (0x7UL << BUCK_BUCKVRETCTRL_BUCK2VRETGPISEL_Pos) /*!< Bit mask of
                                                                            BUCK2VRETGPISEL field.*/                              
  #define BUCK_BUCKVRETCTRL_BUCK2VRETGPISEL_Min (0x0UL) /*!< Min enumerator value of BUCK2VRETGPISEL field.                    */
  #define BUCK_BUCKVRETCTRL_BUCK2VRETGPISEL_Max (0x7UL) /*!< Max enumerator value of BUCK2VRETGPISEL field.                    */
  #define BUCK_BUCKVRETCTRL_BUCK2VRETGPISEL_NOTUSED (0x0UL) /*!< Not used                                                      */
  #define BUCK_BUCKVRETCTRL_BUCK2VRETGPISEL_GPIO0 (0x1UL) /*!< GPIO 0 selected                                                 */
  #define BUCK_BUCKVRETCTRL_BUCK2VRETGPISEL_GPIO1 (0x2UL) /*!< GPIO 1 selected                                                 */
  #define BUCK_BUCKVRETCTRL_BUCK2VRETGPISEL_GPIO2 (0x3UL) /*!< GPIO 2 selected                                                 */
  #define BUCK_BUCKVRETCTRL_BUCK2VRETGPISEL_GPIO3 (0x4UL) /*!< GPIO 3 selected                                                 */
  #define BUCK_BUCKVRETCTRL_BUCK2VRETGPISEL_GPIO4 (0x5UL) /*!< GPIO 4 selected                                                 */
  #define BUCK_BUCKVRETCTRL_BUCK2VRETGPISEL_NOTUSED2 (0x6UL) /*!< Not used                                                     */
  #define BUCK_BUCKVRETCTRL_BUCK2VRETGPISEL_NOTUSED1 (0x7UL) /*!< Not used                                                     */

/* BUCK1VRETGPIINV @Bit 6 : Invert the sense of the selected GPIO for BUCK1 */
  #define BUCK_BUCKVRETCTRL_BUCK1VRETGPIINV_Pos (6UL) /*!< Position of BUCK1VRETGPIINV field.                                  */
  #define BUCK_BUCKVRETCTRL_BUCK1VRETGPIINV_Msk (0x1UL << BUCK_BUCKVRETCTRL_BUCK1VRETGPIINV_Pos) /*!< Bit mask of
                                                                            BUCK1VRETGPIINV field.*/                              
  #define BUCK_BUCKVRETCTRL_BUCK1VRETGPIINV_Min (0x0UL) /*!< Min enumerator value of BUCK1VRETGPIINV field.                    */
  #define BUCK_BUCKVRETCTRL_BUCK1VRETGPIINV_Max (0x1UL) /*!< Max enumerator value of BUCK1VRETGPIINV field.                    */
  #define BUCK_BUCKVRETCTRL_BUCK1VRETGPIINV_NORMAL (0x0UL) /*!< Not inverted                                                   */
  #define BUCK_BUCKVRETCTRL_BUCK1VRETGPIINV_INVERTED (0x1UL) /*!< Inverted                                                     */

/* BUCK2VRETGPIINV @Bit 7 : Invert the sense of the selected GPIO for BUCK2 */
  #define BUCK_BUCKVRETCTRL_BUCK2VRETGPIINV_Pos (7UL) /*!< Position of BUCK2VRETGPIINV field.                                  */
  #define BUCK_BUCKVRETCTRL_BUCK2VRETGPIINV_Msk (0x1UL << BUCK_BUCKVRETCTRL_BUCK2VRETGPIINV_Pos) /*!< Bit mask of
                                                                            BUCK2VRETGPIINV field.*/                              
  #define BUCK_BUCKVRETCTRL_BUCK2VRETGPIINV_Min (0x0UL) /*!< Min enumerator value of BUCK2VRETGPIINV field.                    */
  #define BUCK_BUCKVRETCTRL_BUCK2VRETGPIINV_Max (0x1UL) /*!< Max enumerator value of BUCK2VRETGPIINV field.                    */
  #define BUCK_BUCKVRETCTRL_BUCK2VRETGPIINV_NORMAL (0x0UL) /*!< Not inverted                                                   */
  #define BUCK_BUCKVRETCTRL_BUCK2VRETGPIINV_INVERTED (0x1UL) /*!< Inverted                                                     */


/* BUCK_BUCKPWMCTRL: Select GPIOs for PWM mode controlling BUCK1 and BUCK2 */
  #define BUCK_BUCKPWMCTRL_ResetValue (0x00UL)       /*!< Reset value of BUCKPWMCTRL register.                                 */

/* BUCK1PWMGPISEL @Bits 0..2 : Select which GPIO controls BUCK1 force PWM */
  #define BUCK_BUCKPWMCTRL_BUCK1PWMGPISEL_Pos (0UL)  /*!< Position of BUCK1PWMGPISEL field.                                    */
  #define BUCK_BUCKPWMCTRL_BUCK1PWMGPISEL_Msk (0x7UL << BUCK_BUCKPWMCTRL_BUCK1PWMGPISEL_Pos) /*!< Bit mask of BUCK1PWMGPISEL
                                                                            field.*/                                              
  #define BUCK_BUCKPWMCTRL_BUCK1PWMGPISEL_Min (0x0UL) /*!< Min enumerator value of BUCK1PWMGPISEL field.                       */
  #define BUCK_BUCKPWMCTRL_BUCK1PWMGPISEL_Max (0x7UL) /*!< Max enumerator value of BUCK1PWMGPISEL field.                       */
  #define BUCK_BUCKPWMCTRL_BUCK1PWMGPISEL_NOTUSED1 (0x0UL) /*!< Not used                                                       */
  #define BUCK_BUCKPWMCTRL_BUCK1PWMGPISEL_GPIO0 (0x1UL) /*!< GPIO 0 selected                                                   */
  #define BUCK_BUCKPWMCTRL_BUCK1PWMGPISEL_GPIO1 (0x2UL) /*!< GPIO 1 selected                                                   */
  #define BUCK_BUCKPWMCTRL_BUCK1PWMGPISEL_GPIO2 (0x3UL) /*!< GPIO 2 selected                                                   */
  #define BUCK_BUCKPWMCTRL_BUCK1PWMGPISEL_GPIO3 (0x4UL) /*!< GPIO 3 selected                                                   */
  #define BUCK_BUCKPWMCTRL_BUCK1PWMGPISEL_GPIO4 (0x5UL) /*!< GPIO 4 selected                                                   */
  #define BUCK_BUCKPWMCTRL_BUCK1PWMGPISEL_NOTUSED (0x6UL) /*!< Not used                                                        */
  #define BUCK_BUCKPWMCTRL_BUCK1PWMGPISEL_NOTUSED2 (0x7UL) /*!< Not used                                                       */

/* BUCK2PWMGPISEL @Bits 3..5 : Select which GPIO controls BUCK2 force PWM */
  #define BUCK_BUCKPWMCTRL_BUCK2PWMGPISEL_Pos (3UL)  /*!< Position of BUCK2PWMGPISEL field.                                    */
  #define BUCK_BUCKPWMCTRL_BUCK2PWMGPISEL_Msk (0x7UL << BUCK_BUCKPWMCTRL_BUCK2PWMGPISEL_Pos) /*!< Bit mask of BUCK2PWMGPISEL
                                                                            field.*/                                              
  #define BUCK_BUCKPWMCTRL_BUCK2PWMGPISEL_Min (0x0UL) /*!< Min enumerator value of BUCK2PWMGPISEL field.                       */
  #define BUCK_BUCKPWMCTRL_BUCK2PWMGPISEL_Max (0x7UL) /*!< Max enumerator value of BUCK2PWMGPISEL field.                       */
  #define BUCK_BUCKPWMCTRL_BUCK2PWMGPISEL_NOTUSED1 (0x0UL) /*!< Not used                                                       */
  #define BUCK_BUCKPWMCTRL_BUCK2PWMGPISEL_GPIO0 (0x1UL) /*!< GPIO 0 selected                                                   */
  #define BUCK_BUCKPWMCTRL_BUCK2PWMGPISEL_GPIO1 (0x2UL) /*!< GPIO 1 selected                                                   */
  #define BUCK_BUCKPWMCTRL_BUCK2PWMGPISEL_GPIO2 (0x3UL) /*!< GPIO 2 selected                                                   */
  #define BUCK_BUCKPWMCTRL_BUCK2PWMGPISEL_GPIO3 (0x4UL) /*!< GPIO 3 selected                                                   */
  #define BUCK_BUCKPWMCTRL_BUCK2PWMGPISEL_GPIO4 (0x5UL) /*!< GPIO 4 selected                                                   */
  #define BUCK_BUCKPWMCTRL_BUCK2PWMGPISEL_NOTUSED (0x6UL) /*!< Not used                                                        */
  #define BUCK_BUCKPWMCTRL_BUCK2PWMGPISEL_NOTUSED2 (0x7UL) /*!< Not used                                                       */

/* BUCK1PWMGPIINV @Bit 6 : Invert the sense of the selected GPIO for BUCK1 */
  #define BUCK_BUCKPWMCTRL_BUCK1PWMGPIINV_Pos (6UL)  /*!< Position of BUCK1PWMGPIINV field.                                    */
  #define BUCK_BUCKPWMCTRL_BUCK1PWMGPIINV_Msk (0x1UL << BUCK_BUCKPWMCTRL_BUCK1PWMGPIINV_Pos) /*!< Bit mask of BUCK1PWMGPIINV
                                                                            field.*/                                              
  #define BUCK_BUCKPWMCTRL_BUCK1PWMGPIINV_Min (0x0UL) /*!< Min enumerator value of BUCK1PWMGPIINV field.                       */
  #define BUCK_BUCKPWMCTRL_BUCK1PWMGPIINV_Max (0x1UL) /*!< Max enumerator value of BUCK1PWMGPIINV field.                       */
  #define BUCK_BUCKPWMCTRL_BUCK1PWMGPIINV_NORMAL (0x0UL) /*!< Not inverted                                                     */
  #define BUCK_BUCKPWMCTRL_BUCK1PWMGPIINV_INVERTED (0x1UL) /*!< Inverted                                                       */

/* BUCK2PWMGPIINV @Bit 7 : Invert the sense of the selected GPIO for BUCK2 */
  #define BUCK_BUCKPWMCTRL_BUCK2PWMGPIINV_Pos (7UL)  /*!< Position of BUCK2PWMGPIINV field.                                    */
  #define BUCK_BUCKPWMCTRL_BUCK2PWMGPIINV_Msk (0x1UL << BUCK_BUCKPWMCTRL_BUCK2PWMGPIINV_Pos) /*!< Bit mask of BUCK2PWMGPIINV
                                                                            field.*/                                              
  #define BUCK_BUCKPWMCTRL_BUCK2PWMGPIINV_Min (0x0UL) /*!< Min enumerator value of BUCK2PWMGPIINV field.                       */
  #define BUCK_BUCKPWMCTRL_BUCK2PWMGPIINV_Max (0x1UL) /*!< Max enumerator value of BUCK2PWMGPIINV field.                       */
  #define BUCK_BUCKPWMCTRL_BUCK2PWMGPIINV_NORMAL (0x0UL) /*!< Not inverted                                                     */
  #define BUCK_BUCKPWMCTRL_BUCK2PWMGPIINV_INVERTED (0x1UL) /*!< Inverted                                                       */


/* BUCK_BUCKSWCTRLSEL: BUCK output voltage set by pin or register */
  #define BUCK_BUCKSWCTRLSEL_ResetValue (0x00UL)     /*!< Reset value of BUCKSWCTRLSEL register.                               */

/* BUCK1SWCTRLSEL @Bit 0 : Output voltage control for BUCK1 */
  #define BUCK_BUCKSWCTRLSEL_BUCK1SWCTRLSEL_Pos (0UL) /*!< Position of BUCK1SWCTRLSEL field.                                   */
  #define BUCK_BUCKSWCTRLSEL_BUCK1SWCTRLSEL_Msk (0x1UL << BUCK_BUCKSWCTRLSEL_BUCK1SWCTRLSEL_Pos) /*!< Bit mask of BUCK1SWCTRLSEL
                                                                            field.*/                                              
  #define BUCK_BUCKSWCTRLSEL_BUCK1SWCTRLSEL_Min (0x0UL) /*!< Min enumerator value of BUCK1SWCTRLSEL field.                     */
  #define BUCK_BUCKSWCTRLSEL_BUCK1SWCTRLSEL_Max (0x1UL) /*!< Max enumerator value of BUCK1SWCTRLSEL field.                     */
  #define BUCK_BUCKSWCTRLSEL_BUCK1SWCTRLSEL_VSETANDSWCTRL (0x0UL) /*!< VSET pin controls output voltage                        */
  #define BUCK_BUCKSWCTRLSEL_BUCK1SWCTRLSEL_SWCTRL (0x1UL) /*!< Register controls output voltage                               */

/* BUCK2SWCTRLSEL @Bit 1 : Output voltage control for BUCK2 */
  #define BUCK_BUCKSWCTRLSEL_BUCK2SWCTRLSEL_Pos (1UL) /*!< Position of BUCK2SWCTRLSEL field.                                   */
  #define BUCK_BUCKSWCTRLSEL_BUCK2SWCTRLSEL_Msk (0x1UL << BUCK_BUCKSWCTRLSEL_BUCK2SWCTRLSEL_Pos) /*!< Bit mask of BUCK2SWCTRLSEL
                                                                            field.*/                                              
  #define BUCK_BUCKSWCTRLSEL_BUCK2SWCTRLSEL_Min (0x0UL) /*!< Min enumerator value of BUCK2SWCTRLSEL field.                     */
  #define BUCK_BUCKSWCTRLSEL_BUCK2SWCTRLSEL_Max (0x1UL) /*!< Max enumerator value of BUCK2SWCTRLSEL field.                     */
  #define BUCK_BUCKSWCTRLSEL_BUCK2SWCTRLSEL_VSETANDSWCTRL (0x0UL) /*!< VSET pin controls output voltage                        */
  #define BUCK_BUCKSWCTRLSEL_BUCK2SWCTRLSEL_SWCTRL (0x1UL) /*!< Register controls output voltage                               */


/* BUCK_BUCK1VOUTSTATUS: BUCK1 output voltage target */
  #define BUCK_BUCK1VOUTSTATUS_ResetValue (0x00UL)   /*!< Reset value of BUCK1VOUTSTATUS register.                             */

/* BUCK1VOUTSTATUS @Bits 0..4 : Selected VOUT target */
  #define BUCK_BUCK1VOUTSTATUS_BUCK1VOUTSTATUS_Pos (0UL) /*!< Position of BUCK1VOUTSTATUS field.                               */
  #define BUCK_BUCK1VOUTSTATUS_BUCK1VOUTSTATUS_Msk (0x1FUL << BUCK_BUCK1VOUTSTATUS_BUCK1VOUTSTATUS_Pos) /*!< Bit mask of
                                                                            BUCK1VOUTSTATUS field.*/                              


/* BUCK_BUCK2VOUTSTATUS: BUCK2 output voltage target */
  #define BUCK_BUCK2VOUTSTATUS_ResetValue (0x00UL)   /*!< Reset value of BUCK2VOUTSTATUS register.                             */

/* BUCK2VOUTSTATUS @Bits 0..4 : Selected VOUT target */
  #define BUCK_BUCK2VOUTSTATUS_BUCK2VOUTSTATUS_Pos (0UL) /*!< Position of BUCK2VOUTSTATUS field.                               */
  #define BUCK_BUCK2VOUTSTATUS_BUCK2VOUTSTATUS_Msk (0x1FUL << BUCK_BUCK2VOUTSTATUS_BUCK2VOUTSTATUS_Pos) /*!< Bit mask of
                                                                            BUCK2VOUTSTATUS field.*/                              


/* BUCK_BUCKCTRL0: BUCK auto mode and pull down control */
  #define BUCK_BUCKCTRL0_ResetValue (0x00UL)         /*!< Reset value of BUCKCTRL0 register.                                   */

/* BUCK1AUTOCTRLSEL @Bit 0 : BUCK1 control */
  #define BUCK_BUCKCTRL0_BUCK1AUTOCTRLSEL_Pos (0UL)  /*!< Position of BUCK1AUTOCTRLSEL field.                                  */
  #define BUCK_BUCKCTRL0_BUCK1AUTOCTRLSEL_Msk (0x1UL << BUCK_BUCKCTRL0_BUCK1AUTOCTRLSEL_Pos) /*!< Bit mask of BUCK1AUTOCTRLSEL
                                                                            field.*/                                              
  #define BUCK_BUCKCTRL0_BUCK1AUTOCTRLSEL_Min (0x0UL) /*!< Min enumerator value of BUCK1AUTOCTRLSEL field.                     */
  #define BUCK_BUCKCTRL0_BUCK1AUTOCTRLSEL_Max (0x1UL) /*!< Max enumerator value of BUCK1AUTOCTRLSEL field.                     */
  #define BUCK_BUCKCTRL0_BUCK1AUTOCTRLSEL_AUTO (0x0UL) /*!< Select auto switching between PFM and PWM                          */
  #define BUCK_BUCKCTRL0_BUCK1AUTOCTRLSEL_PFM (0x1UL) /*!< Select PFM mode only                                                */

/* BUCK2AUTOCTRLSEL @Bit 1 : BUCK2 control */
  #define BUCK_BUCKCTRL0_BUCK2AUTOCTRLSEL_Pos (1UL)  /*!< Position of BUCK2AUTOCTRLSEL field.                                  */
  #define BUCK_BUCKCTRL0_BUCK2AUTOCTRLSEL_Msk (0x1UL << BUCK_BUCKCTRL0_BUCK2AUTOCTRLSEL_Pos) /*!< Bit mask of BUCK2AUTOCTRLSEL
                                                                            field.*/                                              
  #define BUCK_BUCKCTRL0_BUCK2AUTOCTRLSEL_Min (0x0UL) /*!< Min enumerator value of BUCK2AUTOCTRLSEL field.                     */
  #define BUCK_BUCKCTRL0_BUCK2AUTOCTRLSEL_Max (0x1UL) /*!< Max enumerator value of BUCK2AUTOCTRLSEL field.                     */
  #define BUCK_BUCKCTRL0_BUCK2AUTOCTRLSEL_AUTO (0x0UL) /*!< Select auto switching between PFM and PWM                          */
  #define BUCK_BUCKCTRL0_BUCK2AUTOCTRLSEL_PFM (0x1UL) /*!< Select PFM mode only                                                */

/* BUCK1ENPULLDOWN @Bit 2 : BUCK1 pull down */
  #define BUCK_BUCKCTRL0_BUCK1ENPULLDOWN_Pos (2UL)   /*!< Position of BUCK1ENPULLDOWN field.                                   */
  #define BUCK_BUCKCTRL0_BUCK1ENPULLDOWN_Msk (0x1UL << BUCK_BUCKCTRL0_BUCK1ENPULLDOWN_Pos) /*!< Bit mask of BUCK1ENPULLDOWN
                                                                            field.*/                                              
  #define BUCK_BUCKCTRL0_BUCK1ENPULLDOWN_Min (0x0UL) /*!< Min enumerator value of BUCK1ENPULLDOWN field.                       */
  #define BUCK_BUCKCTRL0_BUCK1ENPULLDOWN_Max (0x1UL) /*!< Max enumerator value of BUCK1ENPULLDOWN field.                       */
  #define BUCK_BUCKCTRL0_BUCK1ENPULLDOWN_LOW (0x0UL) /*!< BUCK1 pull down disabled                                             */
  #define BUCK_BUCKCTRL0_BUCK1ENPULLDOWN_HIGH (0x1UL) /*!< BUCK1 pull down enabled                                             */

/* BUCK2ENPULLDOWN @Bit 3 : BUCK2 pull down */
  #define BUCK_BUCKCTRL0_BUCK2ENPULLDOWN_Pos (3UL)   /*!< Position of BUCK2ENPULLDOWN field.                                   */
  #define BUCK_BUCKCTRL0_BUCK2ENPULLDOWN_Msk (0x1UL << BUCK_BUCKCTRL0_BUCK2ENPULLDOWN_Pos) /*!< Bit mask of BUCK2ENPULLDOWN
                                                                            field.*/                                              
  #define BUCK_BUCKCTRL0_BUCK2ENPULLDOWN_Min (0x0UL) /*!< Min enumerator value of BUCK2ENPULLDOWN field.                       */
  #define BUCK_BUCKCTRL0_BUCK2ENPULLDOWN_Max (0x1UL) /*!< Max enumerator value of BUCK2ENPULLDOWN field.                       */
  #define BUCK_BUCKCTRL0_BUCK2ENPULLDOWN_LOW (0x0UL) /*!< BUCK2 pull down disabled                                             */
  #define BUCK_BUCKCTRL0_BUCK2ENPULLDOWN_HIGH (0x1UL) /*!< BUCK2 pull down enabled                                             */


/* BUCK_BUCKSTATUS: BUCK status register */
  #define BUCK_BUCKSTATUS_ResetValue (0x00UL)        /*!< Reset value of BUCKSTATUS register.                                  */

/* BUCK1MODE @Bits 0..1 : BUCK1 mode */
  #define BUCK_BUCKSTATUS_BUCK1MODE_Pos (0UL)        /*!< Position of BUCK1MODE field.                                         */
  #define BUCK_BUCKSTATUS_BUCK1MODE_Msk (0x3UL << BUCK_BUCKSTATUS_BUCK1MODE_Pos) /*!< Bit mask of BUCK1MODE field.             */
  #define BUCK_BUCKSTATUS_BUCK1MODE_Min (0x0UL)      /*!< Min enumerator value of BUCK1MODE field.                             */
  #define BUCK_BUCKSTATUS_BUCK1MODE_Max (0x3UL)      /*!< Max enumerator value of BUCK1MODE field.                             */
  #define BUCK_BUCKSTATUS_BUCK1MODE_AUTOMODE (0x0UL) /*!< Auto mode                                                            */
  #define BUCK_BUCKSTATUS_BUCK1MODE_PFMMODE (0x1UL)  /*!< PFM mode                                                             */
  #define BUCK_BUCKSTATUS_BUCK1MODE_PWMMODE (0x2UL)  /*!< Force PWM mode                                                       */
  #define BUCK_BUCKSTATUS_BUCK1MODE_RFU (0x3UL)      /*!< Reserved (PWM mode)                                                  */

/* BUCK1PWRGOOD @Bit 2 : BUCK1 status */
  #define BUCK_BUCKSTATUS_BUCK1PWRGOOD_Pos (2UL)     /*!< Position of BUCK1PWRGOOD field.                                      */
  #define BUCK_BUCKSTATUS_BUCK1PWRGOOD_Msk (0x1UL << BUCK_BUCKSTATUS_BUCK1PWRGOOD_Pos) /*!< Bit mask of BUCK1PWRGOOD field.    */
  #define BUCK_BUCKSTATUS_BUCK1PWRGOOD_Min (0x0UL)   /*!< Min enumerator value of BUCK1PWRGOOD field.                          */
  #define BUCK_BUCKSTATUS_BUCK1PWRGOOD_Max (0x1UL)   /*!< Max enumerator value of BUCK1PWRGOOD field.                          */
  #define BUCK_BUCKSTATUS_BUCK1PWRGOOD_BUCKDISABLED (0x0UL) /*!< BUCK powered off                                              */
  #define BUCK_BUCKSTATUS_BUCK1PWRGOOD_BUCKPOWERED (0x1UL) /*!< BUCK powered on                                                */

/* BUCK1PWMOK @Bit 3 : BUCK1 PWM status */
  #define BUCK_BUCKSTATUS_BUCK1PWMOK_Pos (3UL)       /*!< Position of BUCK1PWMOK field.                                        */
  #define BUCK_BUCKSTATUS_BUCK1PWMOK_Msk (0x1UL << BUCK_BUCKSTATUS_BUCK1PWMOK_Pos) /*!< Bit mask of BUCK1PWMOK field.          */
  #define BUCK_BUCKSTATUS_BUCK1PWMOK_Min (0x0UL)     /*!< Min enumerator value of BUCK1PWMOK field.                            */
  #define BUCK_BUCKSTATUS_BUCK1PWMOK_Max (0x1UL)     /*!< Max enumerator value of BUCK1PWMOK field.                            */
  #define BUCK_BUCKSTATUS_BUCK1PWMOK_PWMMODEDISABLED (0x0UL) /*!< PWM mode disabled                                            */
  #define BUCK_BUCKSTATUS_BUCK1PWMOK_PWMMODEENABLED (0x1UL) /*!< PWM mode enabled                                              */

/* BUCK2MODE @Bits 4..5 : BUCK2 mode */
  #define BUCK_BUCKSTATUS_BUCK2MODE_Pos (4UL)        /*!< Position of BUCK2MODE field.                                         */
  #define BUCK_BUCKSTATUS_BUCK2MODE_Msk (0x3UL << BUCK_BUCKSTATUS_BUCK2MODE_Pos) /*!< Bit mask of BUCK2MODE field.             */
  #define BUCK_BUCKSTATUS_BUCK2MODE_Min (0x0UL)      /*!< Min enumerator value of BUCK2MODE field.                             */
  #define BUCK_BUCKSTATUS_BUCK2MODE_Max (0x3UL)      /*!< Max enumerator value of BUCK2MODE field.                             */
  #define BUCK_BUCKSTATUS_BUCK2MODE_AUTOMODE (0x0UL) /*!< Auto mode                                                            */
  #define BUCK_BUCKSTATUS_BUCK2MODE_PFMMODE (0x1UL)  /*!< PFM mode                                                             */
  #define BUCK_BUCKSTATUS_BUCK2MODE_PWMMODE (0x2UL)  /*!< Force PWM mode                                                       */
  #define BUCK_BUCKSTATUS_BUCK2MODE_RFU (0x3UL)      /*!< Reserved (PWM mode)                                                  */

/* BUCK2PWRGOOD @Bit 6 : BUCK2 status */
  #define BUCK_BUCKSTATUS_BUCK2PWRGOOD_Pos (6UL)     /*!< Position of BUCK2PWRGOOD field.                                      */
  #define BUCK_BUCKSTATUS_BUCK2PWRGOOD_Msk (0x1UL << BUCK_BUCKSTATUS_BUCK2PWRGOOD_Pos) /*!< Bit mask of BUCK2PWRGOOD field.    */
  #define BUCK_BUCKSTATUS_BUCK2PWRGOOD_Min (0x0UL)   /*!< Min enumerator value of BUCK2PWRGOOD field.                          */
  #define BUCK_BUCKSTATUS_BUCK2PWRGOOD_Max (0x1UL)   /*!< Max enumerator value of BUCK2PWRGOOD field.                          */
  #define BUCK_BUCKSTATUS_BUCK2PWRGOOD_BUCKDISABLED (0x0UL) /*!< BUCK powered off                                              */
  #define BUCK_BUCKSTATUS_BUCK2PWRGOOD_BUCKPOWERED (0x1UL) /*!< BUCK powered on                                                */

/* BUCK2PWMOK @Bit 7 : BUCK2 PWM status */
  #define BUCK_BUCKSTATUS_BUCK2PWMOK_Pos (7UL)       /*!< Position of BUCK2PWMOK field.                                        */
  #define BUCK_BUCKSTATUS_BUCK2PWMOK_Msk (0x1UL << BUCK_BUCKSTATUS_BUCK2PWMOK_Pos) /*!< Bit mask of BUCK2PWMOK field.          */
  #define BUCK_BUCKSTATUS_BUCK2PWMOK_Min (0x0UL)     /*!< Min enumerator value of BUCK2PWMOK field.                            */
  #define BUCK_BUCKSTATUS_BUCK2PWMOK_Max (0x1UL)     /*!< Max enumerator value of BUCK2PWMOK field.                            */
  #define BUCK_BUCKSTATUS_BUCK2PWMOK_PWMMODEDISABLED (0x0UL) /*!< PWM mode disabled                                            */
  #define BUCK_BUCKSTATUS_BUCK2PWMOK_PWMMODEENABLED (0x1UL) /*!< PWM mode enabled                                              */


#endif                                               /*!< !defined(__ASSEMBLER__) && !defined(__ASSEMBLY__)                    */

/* =========================================================================================================================== */
/* ================                                            ADC                                            ================ */
/* =========================================================================================================================== */

#if !defined(__ASSEMBLER__) && !defined(__ASSEMBLY__) /*!< Ignore C structs for assembly code.                                 */
/* ======================================================= Struct ADC ======================================================== */
/**
  * @brief nPM1304 ADC registers
  */
  typedef struct {                                   /*!< ADC Structure                                                        */
    __OM uint8_t  TASKVBATMEASURE;                   /*!< (@ 0x00000000) Battery voltage measurement                           */
    __OM uint8_t  TASKNTCMEASURE;                    /*!< (@ 0x00000001) Battery temperature measurement                       */
    __OM uint8_t  TASKTEMPMEASURE;                   /*!< (@ 0x00000002) Die temperature measurement                           */
    __OM uint8_t  TASKVSYSMEASURE;                   /*!< (@ 0x00000003) VSYS measurement                                      */
    __IM uint16_t RESERVED;
    __OM uint8_t  TASKIBATMEASURE;                   /*!< (@ 0x00000006) Battery current measurement                           */
    __OM uint8_t  TASKVBUS7MEASURE;                  /*!< (@ 0x00000007) VBUS measurement                                      */
    __OM uint8_t  TASKDELAYEDVBATMEASURE;            /*!< (@ 0x00000008) Delayed battery voltage measurement                   */
    __IOM uint8_t ADCCONFIG;                         /*!< (@ 0x00000009) ADC configuration                                     */
    __IOM uint8_t ADCNTCRSEL;                        /*!< (@ 0x0000000A) Select battery NTC thermistor                         */
    __IOM uint8_t ADCAUTOTIMCONF;                    /*!< (@ 0x0000000B) Auto measurement intervals                            */
    __OM uint8_t  TASKAUTOTIMUPDATE;                 /*!< (@ 0x0000000C) Strobe for AUTOTIMCONF                                */
    __IOM uint8_t ADCDELTIMCONF;                     /*!< (@ 0x0000000D) Configure delay for battery voltage measurement       */
    __IM uint16_t RESERVED1;
    __IM uint8_t  ADCIBATMEASSTATUS;                 /*!< (@ 0x00000010) Battery current measurement status                    */
    __IM uint8_t  ADCVBATRESULTMSB;                  /*!< (@ 0x00000011) Battery voltage measurement result MSB                */
    __IM uint8_t  ADCNTCRESULTMSB;                   /*!< (@ 0x00000012) Battery temperature measurement result MSB            */
    __IM uint8_t  ADCTEMPRESULTMSB;                  /*!< (@ 0x00000013) Die temperature measurement result MSB                */
    __IM uint8_t  ADCVSYSRESULTMSB;                  /*!< (@ 0x00000014) VSYS measurement result MSB                           */
    __IM uint8_t  ADCGP0RESULTLSBS;                  /*!< (@ 0x00000015) Result LSBs (VBAT, battery temperature, die temperature
                                                                         and VSYS)*/                                              
    __IM uint8_t  ADCVBAT0RESULTMSB;                 /*!< (@ 0x00000016) VBAT0 burst measurement result MSB                    */
    __IM uint8_t  ADCVBAT1RESULTMSB;                 /*!< (@ 0x00000017) VBAT1 burst measurement result MSB                    */
    __IM uint8_t  ADCVBAT2RESULTMSB;                 /*!< (@ 0x00000018) VBAT2 burst measurement result MSB                    */
    __IM uint8_t  ADCVBAT3RESULTMSB;                 /*!< (@ 0x00000019) VBAT3 burst or VBUS measurement result MSB            */
    __IM uint8_t  ADCGP1RESULTLSBS;                  /*!< (@ 0x0000001A) VBAT burst measurement result LSBs (VBAT0, VBAT1, VBAT2
                                                                         and VBAT3)*/                                             
    __IM uint8_t  RESERVED2[9];
    __IOM uint8_t ADCIBATMEASEN;                     /*!< (@ 0x00000024) Enable automatic battery current measurement          */
  } NPM_ADC_Type;                                    /*!< Size = 37 (0x025)                                                    */

/* ADC_TASKVBATMEASURE: Battery voltage measurement */
  #define ADC_TASKVBATMEASURE_ResetValue (0x00UL)    /*!< Reset value of TASKVBATMEASURE register.                             */

/* TASKVBATMEASURE @Bit 0 : Start VBAT measurement */
  #define ADC_TASKVBATMEASURE_TASKVBATMEASURE_Pos (0UL) /*!< Position of TASKVBATMEASURE field.                                */
  #define ADC_TASKVBATMEASURE_TASKVBATMEASURE_Msk (0x1UL << ADC_TASKVBATMEASURE_TASKVBATMEASURE_Pos) /*!< Bit mask of
                                                                            TASKVBATMEASURE field.*/                              
  #define ADC_TASKVBATMEASURE_TASKVBATMEASURE_Min (0x0UL) /*!< Min enumerator value of TASKVBATMEASURE field.                  */
  #define ADC_TASKVBATMEASURE_TASKVBATMEASURE_Max (0x1UL) /*!< Max enumerator value of TASKVBATMEASURE field.                  */
  #define ADC_TASKVBATMEASURE_TASKVBATMEASURE_NOEFFECT (0x0UL) /*!< No effect                                                  */
  #define ADC_TASKVBATMEASURE_TASKVBATMEASURE_TRIGGER (0x1UL) /*!< Trigger task                                                */


/* ADC_TASKNTCMEASURE: Battery temperature measurement */
  #define ADC_TASKNTCMEASURE_ResetValue (0x00UL)     /*!< Reset value of TASKNTCMEASURE register.                              */

/* TASKNTCMEASURE @Bit 0 : Start battery NTC thermistor measurement */
  #define ADC_TASKNTCMEASURE_TASKNTCMEASURE_Pos (0UL) /*!< Position of TASKNTCMEASURE field.                                   */
  #define ADC_TASKNTCMEASURE_TASKNTCMEASURE_Msk (0x1UL << ADC_TASKNTCMEASURE_TASKNTCMEASURE_Pos) /*!< Bit mask of TASKNTCMEASURE
                                                                            field.*/                                              
  #define ADC_TASKNTCMEASURE_TASKNTCMEASURE_Min (0x0UL) /*!< Min enumerator value of TASKNTCMEASURE field.                     */
  #define ADC_TASKNTCMEASURE_TASKNTCMEASURE_Max (0x1UL) /*!< Max enumerator value of TASKNTCMEASURE field.                     */
  #define ADC_TASKNTCMEASURE_TASKNTCMEASURE_NOEFFECT (0x0UL) /*!< No effect                                                    */
  #define ADC_TASKNTCMEASURE_TASKNTCMEASURE_TRIGGER (0x1UL) /*!< Trigger task                                                  */


/* ADC_TASKTEMPMEASURE: Die temperature measurement */
  #define ADC_TASKTEMPMEASURE_ResetValue (0x00UL)    /*!< Reset value of TASKTEMPMEASURE register.                             */

/* TASKTEMPMEASURE @Bit 0 : Start die temperature measurement */
  #define ADC_TASKTEMPMEASURE_TASKTEMPMEASURE_Pos (0UL) /*!< Position of TASKTEMPMEASURE field.                                */
  #define ADC_TASKTEMPMEASURE_TASKTEMPMEASURE_Msk (0x1UL << ADC_TASKTEMPMEASURE_TASKTEMPMEASURE_Pos) /*!< Bit mask of
                                                                            TASKTEMPMEASURE field.*/                              
  #define ADC_TASKTEMPMEASURE_TASKTEMPMEASURE_Min (0x0UL) /*!< Min enumerator value of TASKTEMPMEASURE field.                  */
  #define ADC_TASKTEMPMEASURE_TASKTEMPMEASURE_Max (0x1UL) /*!< Max enumerator value of TASKTEMPMEASURE field.                  */
  #define ADC_TASKTEMPMEASURE_TASKTEMPMEASURE_NOEFFECT (0x0UL) /*!< No effect                                                  */
  #define ADC_TASKTEMPMEASURE_TASKTEMPMEASURE_TRIGGER (0x1UL) /*!< Trigger task                                                */


/* ADC_TASKVSYSMEASURE: VSYS measurement */
  #define ADC_TASKVSYSMEASURE_ResetValue (0x00UL)    /*!< Reset value of TASKVSYSMEASURE register.                             */

/* TASKVSYSMEASURE @Bit 0 : Start VSYS measurement */
  #define ADC_TASKVSYSMEASURE_TASKVSYSMEASURE_Pos (0UL) /*!< Position of TASKVSYSMEASURE field.                                */
  #define ADC_TASKVSYSMEASURE_TASKVSYSMEASURE_Msk (0x1UL << ADC_TASKVSYSMEASURE_TASKVSYSMEASURE_Pos) /*!< Bit mask of
                                                                            TASKVSYSMEASURE field.*/                              
  #define ADC_TASKVSYSMEASURE_TASKVSYSMEASURE_Min (0x0UL) /*!< Min enumerator value of TASKVSYSMEASURE field.                  */
  #define ADC_TASKVSYSMEASURE_TASKVSYSMEASURE_Max (0x1UL) /*!< Max enumerator value of TASKVSYSMEASURE field.                  */
  #define ADC_TASKVSYSMEASURE_TASKVSYSMEASURE_NOEFFECT (0x0UL) /*!< No effect                                                  */
  #define ADC_TASKVSYSMEASURE_TASKVSYSMEASURE_TRIGGER (0x1UL) /*!< Trigger task                                                */


/* ADC_TASKIBATMEASURE: Battery current measurement */
  #define ADC_TASKIBATMEASURE_ResetValue (0x00UL)    /*!< Reset value of TASKIBATMEASURE register.                             */

/* TASKIBATMEASURE @Bit 0 : Start IBAT measurement */
  #define ADC_TASKIBATMEASURE_TASKIBATMEASURE_Pos (0UL) /*!< Position of TASKIBATMEASURE field.                                */
  #define ADC_TASKIBATMEASURE_TASKIBATMEASURE_Msk (0x1UL << ADC_TASKIBATMEASURE_TASKIBATMEASURE_Pos) /*!< Bit mask of
                                                                            TASKIBATMEASURE field.*/                              
  #define ADC_TASKIBATMEASURE_TASKIBATMEASURE_Min (0x0UL) /*!< Min enumerator value of TASKIBATMEASURE field.                  */
  #define ADC_TASKIBATMEASURE_TASKIBATMEASURE_Max (0x1UL) /*!< Max enumerator value of TASKIBATMEASURE field.                  */
  #define ADC_TASKIBATMEASURE_TASKIBATMEASURE_NOEFFECT (0x0UL) /*!< No effect                                                  */
  #define ADC_TASKIBATMEASURE_TASKIBATMEASURE_TRIGGER (0x1UL) /*!< Trigger task                                                */


/* ADC_TASKVBUS7MEASURE: VBUS measurement */
  #define ADC_TASKVBUS7MEASURE_ResetValue (0x00UL)   /*!< Reset value of TASKVBUS7MEASURE register.                            */

/* TASKVBUS7MEASURE @Bit 0 : Start VBUS measurement */
  #define ADC_TASKVBUS7MEASURE_TASKVBUS7MEASURE_Pos (0UL) /*!< Position of TASKVBUS7MEASURE field.                             */
  #define ADC_TASKVBUS7MEASURE_TASKVBUS7MEASURE_Msk (0x1UL << ADC_TASKVBUS7MEASURE_TASKVBUS7MEASURE_Pos) /*!< Bit mask of
                                                                            TASKVBUS7MEASURE field.*/                             
  #define ADC_TASKVBUS7MEASURE_TASKVBUS7MEASURE_Min (0x0UL) /*!< Min enumerator value of TASKVBUS7MEASURE field.               */
  #define ADC_TASKVBUS7MEASURE_TASKVBUS7MEASURE_Max (0x1UL) /*!< Max enumerator value of TASKVBUS7MEASURE field.               */
  #define ADC_TASKVBUS7MEASURE_TASKVBUS7MEASURE_NOEFFECT (0x0UL) /*!< No effect                                                */
  #define ADC_TASKVBUS7MEASURE_TASKVBUS7MEASURE_TRIGGER (0x1UL) /*!< Trigger task                                              */


/* ADC_TASKDELAYEDVBATMEASURE: Delayed battery voltage measurement */
  #define ADC_TASKDELAYEDVBATMEASURE_ResetValue (0x00UL) /*!< Reset value of TASKDELAYEDVBATMEASURE register.                  */

/* TASKDLYDVBATMEASURE @Bit 0 : Start delayed VBAT measurement */
  #define ADC_TASKDELAYEDVBATMEASURE_TASKDLYDVBATMEASURE_Pos (0UL) /*!< Position of TASKDLYDVBATMEASURE field.                 */
  #define ADC_TASKDELAYEDVBATMEASURE_TASKDLYDVBATMEASURE_Msk (0x1UL << ADC_TASKDELAYEDVBATMEASURE_TASKDLYDVBATMEASURE_Pos) /*!<
                                                                            Bit mask of TASKDLYDVBATMEASURE field.*/              
  #define ADC_TASKDELAYEDVBATMEASURE_TASKDLYDVBATMEASURE_Min (0x0UL) /*!< Min enumerator value of TASKDLYDVBATMEASURE field.   */
  #define ADC_TASKDELAYEDVBATMEASURE_TASKDLYDVBATMEASURE_Max (0x1UL) /*!< Max enumerator value of TASKDLYDVBATMEASURE field.   */
  #define ADC_TASKDELAYEDVBATMEASURE_TASKDLYDVBATMEASURE_NOEFFECT (0x0UL) /*!< No effect                                       */
  #define ADC_TASKDELAYEDVBATMEASURE_TASKDLYDVBATMEASURE_TRIGGER (0x1UL) /*!< Trigger task                                     */


/* ADC_ADCCONFIG: ADC configuration */
  #define ADC_ADCCONFIG_ResetValue (0x00UL)          /*!< Reset value of ADCCONFIG register.                                   */

/* VBATAUTOENABLE @Bit 0 : Enable VBAT Auto measurement every 1 s */
  #define ADC_ADCCONFIG_VBATAUTOENABLE_Pos (0UL)     /*!< Position of VBATAUTOENABLE field.                                    */
  #define ADC_ADCCONFIG_VBATAUTOENABLE_Msk (0x1UL << ADC_ADCCONFIG_VBATAUTOENABLE_Pos) /*!< Bit mask of VBATAUTOENABLE field.  */
  #define ADC_ADCCONFIG_VBATAUTOENABLE_Min (0x0UL)   /*!< Min enumerator value of VBATAUTOENABLE field.                        */
  #define ADC_ADCCONFIG_VBATAUTOENABLE_Max (0x1UL)   /*!< Max enumerator value of VBATAUTOENABLE field.                        */
  #define ADC_ADCCONFIG_VBATAUTOENABLE_NOAUTO (0x0UL) /*!< No automatic measurements                                           */
  #define ADC_ADCCONFIG_VBATAUTOENABLE_AUTOENABLE (0x1UL) /*!< Trigger measurement every 1 s                                   */

/* VBATBURSTENABLE @Bit 1 : Enable VBAT burst mode VBAT0, VBAT1, VBAT2, VBAT3 */
  #define ADC_ADCCONFIG_VBATBURSTENABLE_Pos (1UL)    /*!< Position of VBATBURSTENABLE field.                                   */
  #define ADC_ADCCONFIG_VBATBURSTENABLE_Msk (0x1UL << ADC_ADCCONFIG_VBATBURSTENABLE_Pos) /*!< Bit mask of VBATBURSTENABLE
                                                                            field.*/                                              
  #define ADC_ADCCONFIG_VBATBURSTENABLE_Min (0x0UL)  /*!< Min enumerator value of VBATBURSTENABLE field.                       */
  #define ADC_ADCCONFIG_VBATBURSTENABLE_Max (0x1UL)  /*!< Max enumerator value of VBATBURSTENABLE field.                       */
  #define ADC_ADCCONFIG_VBATBURSTENABLE_SINGLEMODE (0x0UL) /*!< Trigger a single measurement                                   */
  #define ADC_ADCCONFIG_VBATBURSTENABLE_BURSTMODE (0x1UL) /*!< Trigger 4 consecutive measurements                              */


/* ADC_ADCNTCRSEL: Select battery NTC thermistor */
  #define ADC_ADCNTCRSEL_ResetValue (0x01UL)         /*!< Reset value of ADCNTCRSEL register.                                  */

/* ADCNTCRSEL @Bits 0..1 : Select thermistor value */
  #define ADC_ADCNTCRSEL_ADCNTCRSEL_Pos (0UL)        /*!< Position of ADCNTCRSEL field.                                        */
  #define ADC_ADCNTCRSEL_ADCNTCRSEL_Msk (0x3UL << ADC_ADCNTCRSEL_ADCNTCRSEL_Pos) /*!< Bit mask of ADCNTCRSEL field.            */
  #define ADC_ADCNTCRSEL_ADCNTCRSEL_Min (0x0UL)      /*!< Min enumerator value of ADCNTCRSEL field.                            */
  #define ADC_ADCNTCRSEL_ADCNTCRSEL_Max (0x3UL)      /*!< Max enumerator value of ADCNTCRSEL field.                            */
  #define ADC_ADCNTCRSEL_ADCNTCRSEL_Hi_Z (0x0UL)     /*!< No thermistor                                                        */
  #define ADC_ADCNTCRSEL_ADCNTCRSEL_10K (0x1UL)      /*!< NTC 10 kOhm                                                          */
  #define ADC_ADCNTCRSEL_ADCNTCRSEL_47K (0x2UL)      /*!< NTC 47 kOhm                                                          */
  #define ADC_ADCNTCRSEL_ADCNTCRSEL_100K (0x3UL)     /*!< NTC 100 kOhm                                                         */


/* ADC_ADCAUTOTIMCONF: Auto measurement intervals */
  #define ADC_ADCAUTOTIMCONF_ResetValue (0x03UL)     /*!< Reset value of ADCAUTOTIMCONF register.                              */

/* NTCAUTOTIM @Bits 0..1 : Battery thermistor measurement interval when charging */
  #define ADC_ADCAUTOTIMCONF_NTCAUTOTIM_Pos (0UL)    /*!< Position of NTCAUTOTIM field.                                        */
  #define ADC_ADCAUTOTIMCONF_NTCAUTOTIM_Msk (0x3UL << ADC_ADCAUTOTIMCONF_NTCAUTOTIM_Pos) /*!< Bit mask of NTCAUTOTIM field.    */
  #define ADC_ADCAUTOTIMCONF_NTCAUTOTIM_Min (0x0UL)  /*!< Min enumerator value of NTCAUTOTIM field.                            */
  #define ADC_ADCAUTOTIMCONF_NTCAUTOTIM_Max (0x3UL)  /*!< Max enumerator value of NTCAUTOTIM field.                            */
  #define ADC_ADCAUTOTIMCONF_NTCAUTOTIM_4MS (0x0UL)  /*!< 4 ms                                                                 */
  #define ADC_ADCAUTOTIMCONF_NTCAUTOTIM_64MS (0x1UL) /*!< 64 ms                                                                */
  #define ADC_ADCAUTOTIMCONF_NTCAUTOTIM_128MS (0x2UL) /*!< 128 ms                                                              */
  #define ADC_ADCAUTOTIMCONF_NTCAUTOTIM_1024MS (0x3UL) /*!< 1024 ms                                                            */

/* TEMPAUTOTIM @Bits 2..3 : Die temperature measurement interval when charging */
  #define ADC_ADCAUTOTIMCONF_TEMPAUTOTIM_Pos (2UL)   /*!< Position of TEMPAUTOTIM field.                                       */
  #define ADC_ADCAUTOTIMCONF_TEMPAUTOTIM_Msk (0x3UL << ADC_ADCAUTOTIMCONF_TEMPAUTOTIM_Pos) /*!< Bit mask of TEMPAUTOTIM field. */
  #define ADC_ADCAUTOTIMCONF_TEMPAUTOTIM_Min (0x0UL) /*!< Min enumerator value of TEMPAUTOTIM field.                           */
  #define ADC_ADCAUTOTIMCONF_TEMPAUTOTIM_Max (0x3UL) /*!< Max enumerator value of TEMPAUTOTIM field.                           */
  #define ADC_ADCAUTOTIMCONF_TEMPAUTOTIM_4MS (0x0UL) /*!< 4 ms                                                                 */
  #define ADC_ADCAUTOTIMCONF_TEMPAUTOTIM_8MS (0x1UL) /*!< 8 ms                                                                 */
  #define ADC_ADCAUTOTIMCONF_TEMPAUTOTIM_16MS (0x2UL) /*!< 16 ms                                                               */
  #define ADC_ADCAUTOTIMCONF_TEMPAUTOTIM_32MS (0x3UL) /*!< 32 ms                                                               */


/* ADC_TASKAUTOTIMUPDATE: Strobe for AUTOTIMCONF */
  #define ADC_TASKAUTOTIMUPDATE_ResetValue (0x00UL)  /*!< Reset value of TASKAUTOTIMUPDATE register.                           */

/* TASKAUTOTIMUPDATE @Bit 0 : Update NTCAUTOTIM and TEMPAUTOTIM measurement intervals */
  #define ADC_TASKAUTOTIMUPDATE_TASKAUTOTIMUPDATE_Pos (0UL) /*!< Position of TASKAUTOTIMUPDATE field.                          */
  #define ADC_TASKAUTOTIMUPDATE_TASKAUTOTIMUPDATE_Msk (0x1UL << ADC_TASKAUTOTIMUPDATE_TASKAUTOTIMUPDATE_Pos) /*!< Bit mask of
                                                                            TASKAUTOTIMUPDATE field.*/                            
  #define ADC_TASKAUTOTIMUPDATE_TASKAUTOTIMUPDATE_Min (0x0UL) /*!< Min enumerator value of TASKAUTOTIMUPDATE field.            */
  #define ADC_TASKAUTOTIMUPDATE_TASKAUTOTIMUPDATE_Max (0x1UL) /*!< Max enumerator value of TASKAUTOTIMUPDATE field.            */
  #define ADC_TASKAUTOTIMUPDATE_TASKAUTOTIMUPDATE_NOEFFECT (0x0UL) /*!< No effect                                              */
  #define ADC_TASKAUTOTIMUPDATE_TASKAUTOTIMUPDATE_UPDATEAUTOTIM (0x1UL) /*!< Update                                            */


/* ADC_ADCDELTIMCONF: Configure delay for battery voltage measurement */
  #define ADC_ADCDELTIMCONF_ResetValue (0x00UL)      /*!< Reset value of ADCDELTIMCONF register.                               */

/* VBATDELTIM @Bits 0..7 : Delay from 4 ms (value 0) to 514 ms (value 255) in 2 ms steps */
  #define ADC_ADCDELTIMCONF_VBATDELTIM_Pos (0UL)     /*!< Position of VBATDELTIM field.                                        */
  #define ADC_ADCDELTIMCONF_VBATDELTIM_Msk (0xFFUL << ADC_ADCDELTIMCONF_VBATDELTIM_Pos) /*!< Bit mask of VBATDELTIM field.     */


/* ADC_ADCIBATMEASSTATUS: Battery current measurement status */
  #define ADC_ADCIBATMEASSTATUS_ResetValue (0x00UL)  /*!< Reset value of ADCIBATMEASSTATUS register.                           */

/* BCHARGERICHARGE @Bits 0..1 : Scaling factor for charging current (00=10 percent, 01=50 percent, 11=100 percent) */
  #define ADC_ADCIBATMEASSTATUS_BCHARGERICHARGE_Pos (0UL) /*!< Position of BCHARGERICHARGE field.                              */
  #define ADC_ADCIBATMEASSTATUS_BCHARGERICHARGE_Msk (0x3UL << ADC_ADCIBATMEASSTATUS_BCHARGERICHARGE_Pos) /*!< Bit mask of
                                                                            BCHARGERICHARGE field.*/                              

/* BCHARGERMODE @Bits 2..3 : Battery charger mode (01=discharging, 11=charging) */
  #define ADC_ADCIBATMEASSTATUS_BCHARGERMODE_Pos (2UL) /*!< Position of BCHARGERMODE field.                                    */
  #define ADC_ADCIBATMEASSTATUS_BCHARGERMODE_Msk (0x3UL << ADC_ADCIBATMEASSTATUS_BCHARGERMODE_Pos) /*!< Bit mask of BCHARGERMODE
                                                                            field.*/                                              

/* IBATMEASEINVALID @Bit 4 : IBAT measurement invalid */
  #define ADC_ADCIBATMEASSTATUS_IBATMEASEINVALID_Pos (4UL) /*!< Position of IBATMEASEINVALID field.                            */
  #define ADC_ADCIBATMEASSTATUS_IBATMEASEINVALID_Msk (0x1UL << ADC_ADCIBATMEASSTATUS_IBATMEASEINVALID_Pos) /*!< Bit mask of
                                                                            IBATMEASEINVALID field.*/                             


/* ADC_ADCVBATRESULTMSB: Battery voltage measurement result MSB */
  #define ADC_ADCVBATRESULTMSB_ResetValue (0x00UL)   /*!< Reset value of ADCVBATRESULTMSB register.                            */

/* VBATRESULTMSB @Bits 0..7 : Battery voltage measurement result MSB */
  #define ADC_ADCVBATRESULTMSB_VBATRESULTMSB_Pos (0UL) /*!< Position of VBATRESULTMSB field.                                   */
  #define ADC_ADCVBATRESULTMSB_VBATRESULTMSB_Msk (0xFFUL << ADC_ADCVBATRESULTMSB_VBATRESULTMSB_Pos) /*!< Bit mask of
                                                                            VBATRESULTMSB field.*/                                


/* ADC_ADCNTCRESULTMSB: Battery temperature measurement result MSB */
  #define ADC_ADCNTCRESULTMSB_ResetValue (0x00UL)    /*!< Reset value of ADCNTCRESULTMSB register.                             */

/* NTCRESULTMSB @Bits 0..7 : Battery temperature measurement result MSB */
  #define ADC_ADCNTCRESULTMSB_NTCRESULTMSB_Pos (0UL) /*!< Position of NTCRESULTMSB field.                                      */
  #define ADC_ADCNTCRESULTMSB_NTCRESULTMSB_Msk (0xFFUL << ADC_ADCNTCRESULTMSB_NTCRESULTMSB_Pos) /*!< Bit mask of NTCRESULTMSB
                                                                            field.*/                                              


/* ADC_ADCTEMPRESULTMSB: Die temperature measurement result MSB */
  #define ADC_ADCTEMPRESULTMSB_ResetValue (0x00UL)   /*!< Reset value of ADCTEMPRESULTMSB register.                            */

/* TEMPRESULTMSB @Bits 0..7 : Die temperature measurement result MSB */
  #define ADC_ADCTEMPRESULTMSB_TEMPRESULTMSB_Pos (0UL) /*!< Position of TEMPRESULTMSB field.                                   */
  #define ADC_ADCTEMPRESULTMSB_TEMPRESULTMSB_Msk (0xFFUL << ADC_ADCTEMPRESULTMSB_TEMPRESULTMSB_Pos) /*!< Bit mask of
                                                                            TEMPRESULTMSB field.*/                                


/* ADC_ADCVSYSRESULTMSB: VSYS measurement result MSB */
  #define ADC_ADCVSYSRESULTMSB_ResetValue (0x00UL)   /*!< Reset value of ADCVSYSRESULTMSB register.                            */

/* VSYSRESULTMSB @Bits 0..7 : VSYS measurement result MSB */
  #define ADC_ADCVSYSRESULTMSB_VSYSRESULTMSB_Pos (0UL) /*!< Position of VSYSRESULTMSB field.                                   */
  #define ADC_ADCVSYSRESULTMSB_VSYSRESULTMSB_Msk (0xFFUL << ADC_ADCVSYSRESULTMSB_VSYSRESULTMSB_Pos) /*!< Bit mask of
                                                                            VSYSRESULTMSB field.*/                                


/* ADC_ADCGP0RESULTLSBS: Result LSBs (VBAT, battery temperature, die temperature and VSYS) */
  #define ADC_ADCGP0RESULTLSBS_ResetValue (0x00UL)   /*!< Reset value of ADCGP0RESULTLSBS register.                            */

/* VBATRESULTLSB @Bits 0..1 : Battery voltage measurement result LSBs */
  #define ADC_ADCGP0RESULTLSBS_VBATRESULTLSB_Pos (0UL) /*!< Position of VBATRESULTLSB field.                                   */
  #define ADC_ADCGP0RESULTLSBS_VBATRESULTLSB_Msk (0x3UL << ADC_ADCGP0RESULTLSBS_VBATRESULTLSB_Pos) /*!< Bit mask of
                                                                            VBATRESULTLSB field.*/                                

/* NTCRESULTLSB @Bits 2..3 : Battery temperature measurement result LSBs */
  #define ADC_ADCGP0RESULTLSBS_NTCRESULTLSB_Pos (2UL) /*!< Position of NTCRESULTLSB field.                                     */
  #define ADC_ADCGP0RESULTLSBS_NTCRESULTLSB_Msk (0x3UL << ADC_ADCGP0RESULTLSBS_NTCRESULTLSB_Pos) /*!< Bit mask of NTCRESULTLSB
                                                                            field.*/                                              

/* TEMPRESULTLSB @Bits 4..5 : Die temperature measurement result LSBs */
  #define ADC_ADCGP0RESULTLSBS_TEMPRESULTLSB_Pos (4UL) /*!< Position of TEMPRESULTLSB field.                                   */
  #define ADC_ADCGP0RESULTLSBS_TEMPRESULTLSB_Msk (0x3UL << ADC_ADCGP0RESULTLSBS_TEMPRESULTLSB_Pos) /*!< Bit mask of
                                                                            TEMPRESULTLSB field.*/                                

/* VSYSRESULTLSB @Bits 6..7 : VSYS measurement result LSBs */
  #define ADC_ADCGP0RESULTLSBS_VSYSRESULTLSB_Pos (6UL) /*!< Position of VSYSRESULTLSB field.                                   */
  #define ADC_ADCGP0RESULTLSBS_VSYSRESULTLSB_Msk (0x3UL << ADC_ADCGP0RESULTLSBS_VSYSRESULTLSB_Pos) /*!< Bit mask of
                                                                            VSYSRESULTLSB field.*/                                


/* ADC_ADCVBAT0RESULTMSB: VBAT0 burst measurement result MSB */
  #define ADC_ADCVBAT0RESULTMSB_ResetValue (0x00UL)  /*!< Reset value of ADCVBAT0RESULTMSB register.                           */

/* VBAT0RESULTMSB @Bits 0..7 : VBAT0 burst measurement result MSB */
  #define ADC_ADCVBAT0RESULTMSB_VBAT0RESULTMSB_Pos (0UL) /*!< Position of VBAT0RESULTMSB field.                                */
  #define ADC_ADCVBAT0RESULTMSB_VBAT0RESULTMSB_Msk (0xFFUL << ADC_ADCVBAT0RESULTMSB_VBAT0RESULTMSB_Pos) /*!< Bit mask of
                                                                            VBAT0RESULTMSB field.*/                               


/* ADC_ADCVBAT1RESULTMSB: VBAT1 burst measurement result MSB */
  #define ADC_ADCVBAT1RESULTMSB_ResetValue (0x00UL)  /*!< Reset value of ADCVBAT1RESULTMSB register.                           */

/* VBAT1RESULTMSB @Bits 0..7 : VBAT1 burst measurement result MSB */
  #define ADC_ADCVBAT1RESULTMSB_VBAT1RESULTMSB_Pos (0UL) /*!< Position of VBAT1RESULTMSB field.                                */
  #define ADC_ADCVBAT1RESULTMSB_VBAT1RESULTMSB_Msk (0xFFUL << ADC_ADCVBAT1RESULTMSB_VBAT1RESULTMSB_Pos) /*!< Bit mask of
                                                                            VBAT1RESULTMSB field.*/                               


/* ADC_ADCVBAT2RESULTMSB: VBAT2 burst measurement result MSB */
  #define ADC_ADCVBAT2RESULTMSB_ResetValue (0x00UL)  /*!< Reset value of ADCVBAT2RESULTMSB register.                           */

/* VBAT2RESULTMSB @Bits 0..7 : ADC VBAT2 burst measurement result MSB */
  #define ADC_ADCVBAT2RESULTMSB_VBAT2RESULTMSB_Pos (0UL) /*!< Position of VBAT2RESULTMSB field.                                */
  #define ADC_ADCVBAT2RESULTMSB_VBAT2RESULTMSB_Msk (0xFFUL << ADC_ADCVBAT2RESULTMSB_VBAT2RESULTMSB_Pos) /*!< Bit mask of
                                                                            VBAT2RESULTMSB field.*/                               


/* ADC_ADCVBAT3RESULTMSB: VBAT3 burst or VBUS measurement result MSB */
  #define ADC_ADCVBAT3RESULTMSB_ResetValue (0x00UL)  /*!< Reset value of ADCVBAT3RESULTMSB register.                           */

/* VBAT3RESULTMSB @Bits 0..7 : If TASKVBATMEASURE is triggered in burst mode, this register will contain ADC VBAT3 burst
                               measurement result MSB If TASKVBUS7MEASURE is triggered, this register will contain VBUS
                               measurement result MSB */                                                                          
                                                                                                                                  
  #define ADC_ADCVBAT3RESULTMSB_VBAT3RESULTMSB_Pos (0UL) /*!< Position of VBAT3RESULTMSB field.                                */
  #define ADC_ADCVBAT3RESULTMSB_VBAT3RESULTMSB_Msk (0xFFUL << ADC_ADCVBAT3RESULTMSB_VBAT3RESULTMSB_Pos) /*!< Bit mask of
                                                                            VBAT3RESULTMSB field.*/                               


/* ADC_ADCGP1RESULTLSBS: VBAT burst measurement result LSBs (VBAT0, VBAT1, VBAT2 and VBAT3) */
  #define ADC_ADCGP1RESULTLSBS_ResetValue (0x00UL)   /*!< Reset value of ADCGP1RESULTLSBS register.                            */

/* VBAT0RESULTLSB @Bits 0..1 : Burst VBAT0 measurement result LSBs */
  #define ADC_ADCGP1RESULTLSBS_VBAT0RESULTLSB_Pos (0UL) /*!< Position of VBAT0RESULTLSB field.                                 */
  #define ADC_ADCGP1RESULTLSBS_VBAT0RESULTLSB_Msk (0x3UL << ADC_ADCGP1RESULTLSBS_VBAT0RESULTLSB_Pos) /*!< Bit mask of
                                                                            VBAT0RESULTLSB field.*/                               

/* VBAT1RESULTLSB @Bits 2..3 : Burst VBAT1 measurement result LSBs */
  #define ADC_ADCGP1RESULTLSBS_VBAT1RESULTLSB_Pos (2UL) /*!< Position of VBAT1RESULTLSB field.                                 */
  #define ADC_ADCGP1RESULTLSBS_VBAT1RESULTLSB_Msk (0x3UL << ADC_ADCGP1RESULTLSBS_VBAT1RESULTLSB_Pos) /*!< Bit mask of
                                                                            VBAT1RESULTLSB field.*/                               

/* VBAT2RESULTLSB @Bits 4..5 : Burst VBAT2 measurement result LSBs */
  #define ADC_ADCGP1RESULTLSBS_VBAT2RESULTLSB_Pos (4UL) /*!< Position of VBAT2RESULTLSB field.                                 */
  #define ADC_ADCGP1RESULTLSBS_VBAT2RESULTLSB_Msk (0x3UL << ADC_ADCGP1RESULTLSBS_VBAT2RESULTLSB_Pos) /*!< Bit mask of
                                                                            VBAT2RESULTLSB field.*/                               

/* VBAT3RESULTLSB @Bits 6..7 : Burst VBAT3 measurement result LSBs */
  #define ADC_ADCGP1RESULTLSBS_VBAT3RESULTLSB_Pos (6UL) /*!< Position of VBAT3RESULTLSB field.                                 */
  #define ADC_ADCGP1RESULTLSBS_VBAT3RESULTLSB_Msk (0x3UL << ADC_ADCGP1RESULTLSBS_VBAT3RESULTLSB_Pos) /*!< Bit mask of
                                                                            VBAT3RESULTLSB field.*/                               


/* ADC_ADCIBATMEASEN: Enable automatic battery current measurement */
  #define ADC_ADCIBATMEASEN_ResetValue (0x00UL)      /*!< Reset value of ADCIBATMEASEN register.                               */

/* IBATMEASENABLE @Bit 0 : Enable IBAT measurement after VBAT measurement */
  #define ADC_ADCIBATMEASEN_IBATMEASENABLE_Pos (0UL) /*!< Position of IBATMEASENABLE field.                                    */
  #define ADC_ADCIBATMEASEN_IBATMEASENABLE_Msk (0x1UL << ADC_ADCIBATMEASEN_IBATMEASENABLE_Pos) /*!< Bit mask of IBATMEASENABLE
                                                                            field.*/                                              
  #define ADC_ADCIBATMEASEN_IBATMEASENABLE_DISABLE (0) /*!< Disable auto IBAT measurement                                      */
  #define ADC_ADCIBATMEASEN_IBATMEASENABLE_ENABLE (1) /*!< Enable auto IBAT measurement                                        */

#endif                                               /*!< !defined(__ASSEMBLER__) && !defined(__ASSEMBLY__)                    */

/* =========================================================================================================================== */
/* ================                                           GPIOS                                           ================ */
/* =========================================================================================================================== */

#if !defined(__ASSEMBLER__) && !defined(__ASSEMBLY__) /*!< Ignore C structs for assembly code.                                 */
/* ====================================================== Struct GPIOS ======================================================= */
/**
  * @brief nPM1304 GPIOS registers
  */
  typedef struct {                                   /*!< GPIOS Structure                                                      */
    __IOM uint8_t GPIOMODE0;                         /*!< (@ 0x00000000) GPIO mode configuration                               */
    __IOM uint8_t GPIOMODE1;                         /*!< (@ 0x00000001) GPIO mode configuration                               */
    __IOM uint8_t GPIOMODE2;                         /*!< (@ 0x00000002) GPIO mode configuration                               */
    __IOM uint8_t GPIOMODE3;                         /*!< (@ 0x00000003) GPIO mode configuration                               */
    __IOM uint8_t GPIOMODE4;                         /*!< (@ 0x00000004) GPIO mode configuration                               */
    __IOM uint8_t GPIODRIVE0;                        /*!< (@ 0x00000005) GPIO drive strength configuration                     */
    __IOM uint8_t GPIODRIVE1;                        /*!< (@ 0x00000006) GPIO drive strength configuration                     */
    __IOM uint8_t GPIODRIVE2;                        /*!< (@ 0x00000007) GPIO drive strength configuration                     */
    __IOM uint8_t GPIODRIVE3;                        /*!< (@ 0x00000008) GPIO drive strength configuration                     */
    __IOM uint8_t GPIODRIVE4;                        /*!< (@ 0x00000009) GPIO drive strength configuration                     */
    __IOM uint8_t GPIOPUEN0;                         /*!< (@ 0x0000000A) GPIO pull up enable configuration                     */
    __IOM uint8_t GPIOPUEN1;                         /*!< (@ 0x0000000B) GPIO pull up enable configuration                     */
    __IOM uint8_t GPIOPUEN2;                         /*!< (@ 0x0000000C) GPIO pull up enable configuration                     */
    __IOM uint8_t GPIOPUEN3;                         /*!< (@ 0x0000000D) GPIO pull up enable configuration                     */
    __IOM uint8_t GPIOPUEN4;                         /*!< (@ 0x0000000E) GPIO pull up enable configuration                     */
    __IOM uint8_t GPIOPDEN0;                         /*!< (@ 0x0000000F) GPIO pull down enable configuration                   */
    __IOM uint8_t GPIOPDEN1;                         /*!< (@ 0x00000010) GPIO pull down enable configuration                   */
    __IOM uint8_t GPIOPDEN2;                         /*!< (@ 0x00000011) GPIO pull down enable configuration                   */
    __IOM uint8_t GPIOPDEN3;                         /*!< (@ 0x00000012) GPIO pull down enable configuration                   */
    __IOM uint8_t GPIOPDEN4;                         /*!< (@ 0x00000013) GPIO pull down enable configuration                   */
    __IOM uint8_t GPIOOPENDRAIN0;                    /*!< (@ 0x00000014) GPIO open drain configuration                         */
    __IOM uint8_t GPIOOPENDRAIN1;                    /*!< (@ 0x00000015) GPIO open drain configuration                         */
    __IOM uint8_t GPIOOPENDRAIN2;                    /*!< (@ 0x00000016) GPIO open drain configuration                         */
    __IOM uint8_t GPIOOPENDRAIN3;                    /*!< (@ 0x00000017) GPIO open drain configuration                         */
    __IOM uint8_t GPIOOPENDRAIN4;                    /*!< (@ 0x00000018) GPIO open drain configuration                         */
    __IOM uint8_t GPIODEBOUNCE0;                     /*!< (@ 0x00000019) GPIO debounce configuration                           */
    __IOM uint8_t GPIODEBOUNCE1;                     /*!< (@ 0x0000001A) GPIO debounce configuration                           */
    __IOM uint8_t GPIODEBOUNCE2;                     /*!< (@ 0x0000001B) GPIO debounce configuration                           */
    __IOM uint8_t GPIODEBOUNCE3;                     /*!< (@ 0x0000001C) GPIO debounce configuration                           */
    __IOM uint8_t GPIODEBOUNCE4;                     /*!< (@ 0x0000001D) GPIO debounce configuration                           */
    __IM uint8_t  GPIOSTATUS;                        /*!< (@ 0x0000001E) GPIO status                                           */
  } NPM_GPIOS_Type;                                  /*!< Size = 31 (0x01F)                                                    */

/* GPIOS_GPIOMODE0: GPIO mode configuration */
  #define GPIOS_GPIOMODE0_ResetValue (0x00UL)        /*!< Reset value of GPIOMODE0 register.                                   */

/* GPIOMODE @Bits 0..3 : GPIO mode selection */
  #define GPIOS_GPIOMODE0_GPIOMODE_Pos (0UL)         /*!< Position of GPIOMODE field.                                          */
  #define GPIOS_GPIOMODE0_GPIOMODE_Msk (0xFUL << GPIOS_GPIOMODE0_GPIOMODE_Pos) /*!< Bit mask of GPIOMODE field.                */
  #define GPIOS_GPIOMODE0_GPIOMODE_Min (0x0UL)       /*!< Min enumerator value of GPIOMODE field.                              */
  #define GPIOS_GPIOMODE0_GPIOMODE_Max (0x9UL)       /*!< Max enumerator value of GPIOMODE field.                              */
  #define GPIOS_GPIOMODE0_GPIOMODE_GPIINPUT (0x0UL)  /*!< Input                                                                */
  #define GPIOS_GPIOMODE0_GPIOMODE_GPILOGIC1 (0x1UL) /*!< Input, internally driven high                                        */
  #define GPIOS_GPIOMODE0_GPIOMODE_GPILOGIC0 (0x2UL) /*!< Input, internally driven low                                         */
  #define GPIOS_GPIOMODE0_GPIOMODE_GPIEVENTRISE (0x3UL) /*!< Input, event from rising edge                                     */
  #define GPIOS_GPIOMODE0_GPIOMODE_GPIEVENTFALL (0x4UL) /*!< Input, event from falling edge                                    */
  #define GPIOS_GPIOMODE0_GPIOMODE_GPOIRQ (0x5UL)    /*!< Interrupt output                                                     */
  #define GPIOS_GPIOMODE0_GPIOMODE_GPORESET (0x6UL)  /*!< Reset output                                                         */
  #define GPIOS_GPIOMODE0_GPIOMODE_GPOPLW (0x7UL)    /*!< Power failure warning output                                         */
  #define GPIOS_GPIOMODE0_GPIOMODE_GPOLOGIC1 (0x8UL) /*!< Output, pin driven high                                              */
  #define GPIOS_GPIOMODE0_GPIOMODE_GPOLOGIC0 (0x9UL) /*!< Output, pin driven low                                               */


/* GPIOS_GPIOMODE1: GPIO mode configuration */
  #define GPIOS_GPIOMODE1_ResetValue (0x00UL)        /*!< Reset value of GPIOMODE1 register.                                   */

/* GPIOMODE @Bits 0..3 : GPIO mode selection */
  #define GPIOS_GPIOMODE1_GPIOMODE_Pos (0UL)         /*!< Position of GPIOMODE field.                                          */
  #define GPIOS_GPIOMODE1_GPIOMODE_Msk (0xFUL << GPIOS_GPIOMODE1_GPIOMODE_Pos) /*!< Bit mask of GPIOMODE field.                */
  #define GPIOS_GPIOMODE1_GPIOMODE_Min (0x0UL)       /*!< Min enumerator value of GPIOMODE field.                              */
  #define GPIOS_GPIOMODE1_GPIOMODE_Max (0x9UL)       /*!< Max enumerator value of GPIOMODE field.                              */
  #define GPIOS_GPIOMODE1_GPIOMODE_GPIINPUT (0x0UL)  /*!< Input                                                                */
  #define GPIOS_GPIOMODE1_GPIOMODE_GPILOGIC1 (0x1UL) /*!< Input, internally driven high                                        */
  #define GPIOS_GPIOMODE1_GPIOMODE_GPILOGIC0 (0x2UL) /*!< Input, internally driven low                                         */
  #define GPIOS_GPIOMODE1_GPIOMODE_GPIEVENTRISE (0x3UL) /*!< Input, event from rising edge                                     */
  #define GPIOS_GPIOMODE1_GPIOMODE_GPIEVENTFALL (0x4UL) /*!< Input, event from falling edge                                    */
  #define GPIOS_GPIOMODE1_GPIOMODE_GPOIRQ (0x5UL)    /*!< Interrupt output                                                     */
  #define GPIOS_GPIOMODE1_GPIOMODE_GPORESET (0x6UL)  /*!< Reset output                                                         */
  #define GPIOS_GPIOMODE1_GPIOMODE_GPOPLW (0x7UL)    /*!< Power failure warning output                                         */
  #define GPIOS_GPIOMODE1_GPIOMODE_GPOLOGIC1 (0x8UL) /*!< Output, pin driven high                                              */
  #define GPIOS_GPIOMODE1_GPIOMODE_GPOLOGIC0 (0x9UL) /*!< Output, pin driven low                                               */


/* GPIOS_GPIOMODE2: GPIO mode configuration */
  #define GPIOS_GPIOMODE2_ResetValue (0x00UL)        /*!< Reset value of GPIOMODE2 register.                                   */

/* GPIOMODE @Bits 0..3 : GPIO mode selection */
  #define GPIOS_GPIOMODE2_GPIOMODE_Pos (0UL)         /*!< Position of GPIOMODE field.                                          */
  #define GPIOS_GPIOMODE2_GPIOMODE_Msk (0xFUL << GPIOS_GPIOMODE2_GPIOMODE_Pos) /*!< Bit mask of GPIOMODE field.                */
  #define GPIOS_GPIOMODE2_GPIOMODE_Min (0x0UL)       /*!< Min enumerator value of GPIOMODE field.                              */
  #define GPIOS_GPIOMODE2_GPIOMODE_Max (0x9UL)       /*!< Max enumerator value of GPIOMODE field.                              */
  #define GPIOS_GPIOMODE2_GPIOMODE_GPIINPUT (0x0UL)  /*!< Input                                                                */
  #define GPIOS_GPIOMODE2_GPIOMODE_GPILOGIC1 (0x1UL) /*!< Input, internally driven high                                        */
  #define GPIOS_GPIOMODE2_GPIOMODE_GPILOGIC0 (0x2UL) /*!< Input, internally driven low                                         */
  #define GPIOS_GPIOMODE2_GPIOMODE_GPIEVENTRISE (0x3UL) /*!< Input, event from rising edge                                     */
  #define GPIOS_GPIOMODE2_GPIOMODE_GPIEVENTFALL (0x4UL) /*!< Input, event from falling edge                                    */
  #define GPIOS_GPIOMODE2_GPIOMODE_GPOIRQ (0x5UL)    /*!< Interrupt output                                                     */
  #define GPIOS_GPIOMODE2_GPIOMODE_GPORESET (0x6UL)  /*!< Reset output                                                         */
  #define GPIOS_GPIOMODE2_GPIOMODE_GPOPLW (0x7UL)    /*!< Power failure warning output                                         */
  #define GPIOS_GPIOMODE2_GPIOMODE_GPOLOGIC1 (0x8UL) /*!< Output, pin driven high                                              */
  #define GPIOS_GPIOMODE2_GPIOMODE_GPOLOGIC0 (0x9UL) /*!< Output, pin driven low                                               */


/* GPIOS_GPIOMODE3: GPIO mode configuration */
  #define GPIOS_GPIOMODE3_ResetValue (0x00UL)        /*!< Reset value of GPIOMODE3 register.                                   */

/* GPIOMODE @Bits 0..3 : GPIO mode selection */
  #define GPIOS_GPIOMODE3_GPIOMODE_Pos (0UL)         /*!< Position of GPIOMODE field.                                          */
  #define GPIOS_GPIOMODE3_GPIOMODE_Msk (0xFUL << GPIOS_GPIOMODE3_GPIOMODE_Pos) /*!< Bit mask of GPIOMODE field.                */
  #define GPIOS_GPIOMODE3_GPIOMODE_Min (0x0UL)       /*!< Min enumerator value of GPIOMODE field.                              */
  #define GPIOS_GPIOMODE3_GPIOMODE_Max (0x9UL)       /*!< Max enumerator value of GPIOMODE field.                              */
  #define GPIOS_GPIOMODE3_GPIOMODE_GPIINPUT (0x0UL)  /*!< Input                                                                */
  #define GPIOS_GPIOMODE3_GPIOMODE_GPILOGIC1 (0x1UL) /*!< Input, internally driven high                                        */
  #define GPIOS_GPIOMODE3_GPIOMODE_GPILOGIC0 (0x2UL) /*!< Input, internally driven low                                         */
  #define GPIOS_GPIOMODE3_GPIOMODE_GPIEVENTRISE (0x3UL) /*!< Input, event from rising edge                                     */
  #define GPIOS_GPIOMODE3_GPIOMODE_GPIEVENTFALL (0x4UL) /*!< Input, event from falling edge                                    */
  #define GPIOS_GPIOMODE3_GPIOMODE_GPOIRQ (0x5UL)    /*!< Interrupt output                                                     */
  #define GPIOS_GPIOMODE3_GPIOMODE_GPORESET (0x6UL)  /*!< Reset output                                                         */
  #define GPIOS_GPIOMODE3_GPIOMODE_GPOPLW (0x7UL)    /*!< Power failure warning output                                         */
  #define GPIOS_GPIOMODE3_GPIOMODE_GPOLOGIC1 (0x8UL) /*!< Output, pin driven high                                              */
  #define GPIOS_GPIOMODE3_GPIOMODE_GPOLOGIC0 (0x9UL) /*!< Output, pin driven low                                               */


/* GPIOS_GPIOMODE4: GPIO mode configuration */
  #define GPIOS_GPIOMODE4_ResetValue (0x00UL)        /*!< Reset value of GPIOMODE4 register.                                   */

/* GPIOMODE @Bits 0..3 : GPIO mode selection */
  #define GPIOS_GPIOMODE4_GPIOMODE_Pos (0UL)         /*!< Position of GPIOMODE field.                                          */
  #define GPIOS_GPIOMODE4_GPIOMODE_Msk (0xFUL << GPIOS_GPIOMODE4_GPIOMODE_Pos) /*!< Bit mask of GPIOMODE field.                */
  #define GPIOS_GPIOMODE4_GPIOMODE_Min (0x0UL)       /*!< Min enumerator value of GPIOMODE field.                              */
  #define GPIOS_GPIOMODE4_GPIOMODE_Max (0x9UL)       /*!< Max enumerator value of GPIOMODE field.                              */
  #define GPIOS_GPIOMODE4_GPIOMODE_GPIINPUT (0x0UL)  /*!< Input                                                                */
  #define GPIOS_GPIOMODE4_GPIOMODE_GPILOGIC1 (0x1UL) /*!< Input, internally driven high                                        */
  #define GPIOS_GPIOMODE4_GPIOMODE_GPILOGIC0 (0x2UL) /*!< Input, internally driven low                                         */
  #define GPIOS_GPIOMODE4_GPIOMODE_GPIEVENTRISE (0x3UL) /*!< Input, event from rising edge                                     */
  #define GPIOS_GPIOMODE4_GPIOMODE_GPIEVENTFALL (0x4UL) /*!< Input, event from falling edge                                    */
  #define GPIOS_GPIOMODE4_GPIOMODE_GPOIRQ (0x5UL)    /*!< Interrupt output                                                     */
  #define GPIOS_GPIOMODE4_GPIOMODE_GPORESET (0x6UL)  /*!< Reset output                                                         */
  #define GPIOS_GPIOMODE4_GPIOMODE_GPOPLW (0x7UL)    /*!< Power failure warning output                                         */
  #define GPIOS_GPIOMODE4_GPIOMODE_GPOLOGIC1 (0x8UL) /*!< Output, pin driven high                                              */
  #define GPIOS_GPIOMODE4_GPIOMODE_GPOLOGIC0 (0x9UL) /*!< Output, pin driven low                                               */


/* GPIOS_GPIODRIVE0: GPIO drive strength configuration */
  #define GPIOS_GPIODRIVE0_ResetValue (0x00UL)       /*!< Reset value of GPIODRIVE0 register.                                  */

/* GPIODRIVE @Bit 0 : GPIO drive strength */
  #define GPIOS_GPIODRIVE0_GPIODRIVE_Pos (0UL)       /*!< Position of GPIODRIVE field.                                         */
  #define GPIOS_GPIODRIVE0_GPIODRIVE_Msk (0x1UL << GPIOS_GPIODRIVE0_GPIODRIVE_Pos) /*!< Bit mask of GPIODRIVE field.           */
  #define GPIOS_GPIODRIVE0_GPIODRIVE_Min (0x0UL)     /*!< Min enumerator value of GPIODRIVE field.                             */
  #define GPIOS_GPIODRIVE0_GPIODRIVE_Max (0x1UL)     /*!< Max enumerator value of GPIODRIVE field.                             */
  #define GPIOS_GPIODRIVE0_GPIODRIVE_1MA (0x0UL)     /*!< 1 mA                                                                 */
  #define GPIOS_GPIODRIVE0_GPIODRIVE_6MA (0x1UL)     /*!< 6 mA                                                                 */


/* GPIOS_GPIODRIVE1: GPIO drive strength configuration */
  #define GPIOS_GPIODRIVE1_ResetValue (0x00UL)       /*!< Reset value of GPIODRIVE1 register.                                  */

/* GPIODRIVE @Bit 0 : GPIO drive strength */
  #define GPIOS_GPIODRIVE1_GPIODRIVE_Pos (0UL)       /*!< Position of GPIODRIVE field.                                         */
  #define GPIOS_GPIODRIVE1_GPIODRIVE_Msk (0x1UL << GPIOS_GPIODRIVE1_GPIODRIVE_Pos) /*!< Bit mask of GPIODRIVE field.           */
  #define GPIOS_GPIODRIVE1_GPIODRIVE_Min (0x0UL)     /*!< Min enumerator value of GPIODRIVE field.                             */
  #define GPIOS_GPIODRIVE1_GPIODRIVE_Max (0x1UL)     /*!< Max enumerator value of GPIODRIVE field.                             */
  #define GPIOS_GPIODRIVE1_GPIODRIVE_1MA (0x0UL)     /*!< 1 mA                                                                 */
  #define GPIOS_GPIODRIVE1_GPIODRIVE_6MA (0x1UL)     /*!< 6 mA                                                                 */


/* GPIOS_GPIODRIVE2: GPIO drive strength configuration */
  #define GPIOS_GPIODRIVE2_ResetValue (0x00UL)       /*!< Reset value of GPIODRIVE2 register.                                  */

/* GPIODRIVE @Bit 0 : GPIO drive strength */
  #define GPIOS_GPIODRIVE2_GPIODRIVE_Pos (0UL)       /*!< Position of GPIODRIVE field.                                         */
  #define GPIOS_GPIODRIVE2_GPIODRIVE_Msk (0x1UL << GPIOS_GPIODRIVE2_GPIODRIVE_Pos) /*!< Bit mask of GPIODRIVE field.           */
  #define GPIOS_GPIODRIVE2_GPIODRIVE_Min (0x0UL)     /*!< Min enumerator value of GPIODRIVE field.                             */
  #define GPIOS_GPIODRIVE2_GPIODRIVE_Max (0x1UL)     /*!< Max enumerator value of GPIODRIVE field.                             */
  #define GPIOS_GPIODRIVE2_GPIODRIVE_1MA (0x0UL)     /*!< 1 mA                                                                 */
  #define GPIOS_GPIODRIVE2_GPIODRIVE_6MA (0x1UL)     /*!< 6 mA                                                                 */


/* GPIOS_GPIODRIVE3: GPIO drive strength configuration */
  #define GPIOS_GPIODRIVE3_ResetValue (0x00UL)       /*!< Reset value of GPIODRIVE3 register.                                  */

/* GPIODRIVE @Bit 0 : GPIO drive strength */
  #define GPIOS_GPIODRIVE3_GPIODRIVE_Pos (0UL)       /*!< Position of GPIODRIVE field.                                         */
  #define GPIOS_GPIODRIVE3_GPIODRIVE_Msk (0x1UL << GPIOS_GPIODRIVE3_GPIODRIVE_Pos) /*!< Bit mask of GPIODRIVE field.           */
  #define GPIOS_GPIODRIVE3_GPIODRIVE_Min (0x0UL)     /*!< Min enumerator value of GPIODRIVE field.                             */
  #define GPIOS_GPIODRIVE3_GPIODRIVE_Max (0x1UL)     /*!< Max enumerator value of GPIODRIVE field.                             */
  #define GPIOS_GPIODRIVE3_GPIODRIVE_1MA (0x0UL)     /*!< 1 mA                                                                 */
  #define GPIOS_GPIODRIVE3_GPIODRIVE_6MA (0x1UL)     /*!< 6 mA                                                                 */


/* GPIOS_GPIODRIVE4: GPIO drive strength configuration */
  #define GPIOS_GPIODRIVE4_ResetValue (0x00UL)       /*!< Reset value of GPIODRIVE4 register.                                  */

/* GPIODRIVE @Bit 0 : GPIO drive strength */
  #define GPIOS_GPIODRIVE4_GPIODRIVE_Pos (0UL)       /*!< Position of GPIODRIVE field.                                         */
  #define GPIOS_GPIODRIVE4_GPIODRIVE_Msk (0x1UL << GPIOS_GPIODRIVE4_GPIODRIVE_Pos) /*!< Bit mask of GPIODRIVE field.           */
  #define GPIOS_GPIODRIVE4_GPIODRIVE_Min (0x0UL)     /*!< Min enumerator value of GPIODRIVE field.                             */
  #define GPIOS_GPIODRIVE4_GPIODRIVE_Max (0x1UL)     /*!< Max enumerator value of GPIODRIVE field.                             */
  #define GPIOS_GPIODRIVE4_GPIODRIVE_1MA (0x0UL)     /*!< 1 mA                                                                 */
  #define GPIOS_GPIODRIVE4_GPIODRIVE_6MA (0x1UL)     /*!< 6 mA                                                                 */


/* GPIOS_GPIOPUEN0: GPIO pull up enable configuration */
  #define GPIOS_GPIOPUEN0_ResetValue (0x00UL)        /*!< Reset value of GPIOPUEN0 register.                                   */

/* GPIOPUEN @Bit 0 : GPIO pull up enable */
  #define GPIOS_GPIOPUEN0_GPIOPUEN_Pos (0UL)         /*!< Position of GPIOPUEN field.                                          */
  #define GPIOS_GPIOPUEN0_GPIOPUEN_Msk (0x1UL << GPIOS_GPIOPUEN0_GPIOPUEN_Pos) /*!< Bit mask of GPIOPUEN field.                */
  #define GPIOS_GPIOPUEN0_GPIOPUEN_Min (0x0UL)       /*!< Min enumerator value of GPIOPUEN field.                              */
  #define GPIOS_GPIOPUEN0_GPIOPUEN_Max (0x1UL)       /*!< Max enumerator value of GPIOPUEN field.                              */
  #define GPIOS_GPIOPUEN0_GPIOPUEN_PULLUP0 (0x0UL)   /*!< Pull up disable                                                      */
  #define GPIOS_GPIOPUEN0_GPIOPUEN_PULLUP1 (0x1UL)   /*!< Pull up enable                                                       */


/* GPIOS_GPIOPUEN1: GPIO pull up enable configuration */
  #define GPIOS_GPIOPUEN1_ResetValue (0x00UL)        /*!< Reset value of GPIOPUEN1 register.                                   */

/* GPIOPUEN @Bit 0 : GPIO pull up enable */
  #define GPIOS_GPIOPUEN1_GPIOPUEN_Pos (0UL)         /*!< Position of GPIOPUEN field.                                          */
  #define GPIOS_GPIOPUEN1_GPIOPUEN_Msk (0x1UL << GPIOS_GPIOPUEN1_GPIOPUEN_Pos) /*!< Bit mask of GPIOPUEN field.                */
  #define GPIOS_GPIOPUEN1_GPIOPUEN_Min (0x0UL)       /*!< Min enumerator value of GPIOPUEN field.                              */
  #define GPIOS_GPIOPUEN1_GPIOPUEN_Max (0x1UL)       /*!< Max enumerator value of GPIOPUEN field.                              */
  #define GPIOS_GPIOPUEN1_GPIOPUEN_PULLUP0 (0x0UL)   /*!< Pull up disable                                                      */
  #define GPIOS_GPIOPUEN1_GPIOPUEN_PULLUP1 (0x1UL)   /*!< Pull up enable                                                       */


/* GPIOS_GPIOPUEN2: GPIO pull up enable configuration */
  #define GPIOS_GPIOPUEN2_ResetValue (0x00UL)        /*!< Reset value of GPIOPUEN2 register.                                   */

/* GPIOPUEN @Bit 0 : GPIO pull up enable */
  #define GPIOS_GPIOPUEN2_GPIOPUEN_Pos (0UL)         /*!< Position of GPIOPUEN field.                                          */
  #define GPIOS_GPIOPUEN2_GPIOPUEN_Msk (0x1UL << GPIOS_GPIOPUEN2_GPIOPUEN_Pos) /*!< Bit mask of GPIOPUEN field.                */
  #define GPIOS_GPIOPUEN2_GPIOPUEN_Min (0x0UL)       /*!< Min enumerator value of GPIOPUEN field.                              */
  #define GPIOS_GPIOPUEN2_GPIOPUEN_Max (0x1UL)       /*!< Max enumerator value of GPIOPUEN field.                              */
  #define GPIOS_GPIOPUEN2_GPIOPUEN_PULLUP0 (0x0UL)   /*!< Pull up disable                                                      */
  #define GPIOS_GPIOPUEN2_GPIOPUEN_PULLUP1 (0x1UL)   /*!< Pull up enable                                                       */


/* GPIOS_GPIOPUEN3: GPIO pull up enable configuration */
  #define GPIOS_GPIOPUEN3_ResetValue (0x00UL)        /*!< Reset value of GPIOPUEN3 register.                                   */

/* GPIOPUEN @Bit 0 : GPIO pull up enable */
  #define GPIOS_GPIOPUEN3_GPIOPUEN_Pos (0UL)         /*!< Position of GPIOPUEN field.                                          */
  #define GPIOS_GPIOPUEN3_GPIOPUEN_Msk (0x1UL << GPIOS_GPIOPUEN3_GPIOPUEN_Pos) /*!< Bit mask of GPIOPUEN field.                */
  #define GPIOS_GPIOPUEN3_GPIOPUEN_Min (0x0UL)       /*!< Min enumerator value of GPIOPUEN field.                              */
  #define GPIOS_GPIOPUEN3_GPIOPUEN_Max (0x1UL)       /*!< Max enumerator value of GPIOPUEN field.                              */
  #define GPIOS_GPIOPUEN3_GPIOPUEN_PULLUP0 (0x0UL)   /*!< Pull up disable                                                      */
  #define GPIOS_GPIOPUEN3_GPIOPUEN_PULLUP1 (0x1UL)   /*!< Pull up enable                                                       */


/* GPIOS_GPIOPUEN4: GPIO pull up enable configuration */
  #define GPIOS_GPIOPUEN4_ResetValue (0x00UL)        /*!< Reset value of GPIOPUEN4 register.                                   */

/* GPIOPUEN @Bit 0 : GPIO pull up enable */
  #define GPIOS_GPIOPUEN4_GPIOPUEN_Pos (0UL)         /*!< Position of GPIOPUEN field.                                          */
  #define GPIOS_GPIOPUEN4_GPIOPUEN_Msk (0x1UL << GPIOS_GPIOPUEN4_GPIOPUEN_Pos) /*!< Bit mask of GPIOPUEN field.                */
  #define GPIOS_GPIOPUEN4_GPIOPUEN_Min (0x0UL)       /*!< Min enumerator value of GPIOPUEN field.                              */
  #define GPIOS_GPIOPUEN4_GPIOPUEN_Max (0x1UL)       /*!< Max enumerator value of GPIOPUEN field.                              */
  #define GPIOS_GPIOPUEN4_GPIOPUEN_PULLUP0 (0x0UL)   /*!< Pull up disable                                                      */
  #define GPIOS_GPIOPUEN4_GPIOPUEN_PULLUP1 (0x1UL)   /*!< Pull up enable                                                       */


/* GPIOS_GPIOPDEN0: GPIO pull down enable configuration */
  #define GPIOS_GPIOPDEN0_ResetValue (0x01UL)        /*!< Reset value of GPIOPDEN0 register.                                   */

/* GPIOPDEN @Bit 0 : GPIO pull down enable */
  #define GPIOS_GPIOPDEN0_GPIOPDEN_Pos (0UL)         /*!< Position of GPIOPDEN field.                                          */
  #define GPIOS_GPIOPDEN0_GPIOPDEN_Msk (0x1UL << GPIOS_GPIOPDEN0_GPIOPDEN_Pos) /*!< Bit mask of GPIOPDEN field.                */
  #define GPIOS_GPIOPDEN0_GPIOPDEN_Min (0x0UL)       /*!< Min enumerator value of GPIOPDEN field.                              */
  #define GPIOS_GPIOPDEN0_GPIOPDEN_Max (0x1UL)       /*!< Max enumerator value of GPIOPDEN field.                              */
  #define GPIOS_GPIOPDEN0_GPIOPDEN_PULLDOWN0 (0x0UL) /*!< Pull up disable                                                      */
  #define GPIOS_GPIOPDEN0_GPIOPDEN_PULLDOWN1 (0x1UL) /*!< Pull up enable                                                       */


/* GPIOS_GPIOPDEN1: GPIO pull down enable configuration */
  #define GPIOS_GPIOPDEN1_ResetValue (0x01UL)        /*!< Reset value of GPIOPDEN1 register.                                   */

/* GPIOPDEN @Bit 0 : GPIO pull down enable */
  #define GPIOS_GPIOPDEN1_GPIOPDEN_Pos (0UL)         /*!< Position of GPIOPDEN field.                                          */
  #define GPIOS_GPIOPDEN1_GPIOPDEN_Msk (0x1UL << GPIOS_GPIOPDEN1_GPIOPDEN_Pos) /*!< Bit mask of GPIOPDEN field.                */
  #define GPIOS_GPIOPDEN1_GPIOPDEN_Min (0x0UL)       /*!< Min enumerator value of GPIOPDEN field.                              */
  #define GPIOS_GPIOPDEN1_GPIOPDEN_Max (0x1UL)       /*!< Max enumerator value of GPIOPDEN field.                              */
  #define GPIOS_GPIOPDEN1_GPIOPDEN_PULLDOWN0 (0x0UL) /*!< Pull up disable                                                      */
  #define GPIOS_GPIOPDEN1_GPIOPDEN_PULLDOWN1 (0x1UL) /*!< Pull up enable                                                       */


/* GPIOS_GPIOPDEN2: GPIO pull down enable configuration */
  #define GPIOS_GPIOPDEN2_ResetValue (0x01UL)        /*!< Reset value of GPIOPDEN2 register.                                   */

/* GPIOPDEN @Bit 0 : GPIO pull down enable */
  #define GPIOS_GPIOPDEN2_GPIOPDEN_Pos (0UL)         /*!< Position of GPIOPDEN field.                                          */
  #define GPIOS_GPIOPDEN2_GPIOPDEN_Msk (0x1UL << GPIOS_GPIOPDEN2_GPIOPDEN_Pos) /*!< Bit mask of GPIOPDEN field.                */
  #define GPIOS_GPIOPDEN2_GPIOPDEN_Min (0x0UL)       /*!< Min enumerator value of GPIOPDEN field.                              */
  #define GPIOS_GPIOPDEN2_GPIOPDEN_Max (0x1UL)       /*!< Max enumerator value of GPIOPDEN field.                              */
  #define GPIOS_GPIOPDEN2_GPIOPDEN_PULLDOWN0 (0x0UL) /*!< Pull up disable                                                      */
  #define GPIOS_GPIOPDEN2_GPIOPDEN_PULLDOWN1 (0x1UL) /*!< Pull up enable                                                       */


/* GPIOS_GPIOPDEN3: GPIO pull down enable configuration */
  #define GPIOS_GPIOPDEN3_ResetValue (0x01UL)        /*!< Reset value of GPIOPDEN3 register.                                   */

/* GPIOPDEN @Bit 0 : GPIO pull down enable */
  #define GPIOS_GPIOPDEN3_GPIOPDEN_Pos (0UL)         /*!< Position of GPIOPDEN field.                                          */
  #define GPIOS_GPIOPDEN3_GPIOPDEN_Msk (0x1UL << GPIOS_GPIOPDEN3_GPIOPDEN_Pos) /*!< Bit mask of GPIOPDEN field.                */
  #define GPIOS_GPIOPDEN3_GPIOPDEN_Min (0x0UL)       /*!< Min enumerator value of GPIOPDEN field.                              */
  #define GPIOS_GPIOPDEN3_GPIOPDEN_Max (0x1UL)       /*!< Max enumerator value of GPIOPDEN field.                              */
  #define GPIOS_GPIOPDEN3_GPIOPDEN_PULLDOWN0 (0x0UL) /*!< Pull up disable                                                      */
  #define GPIOS_GPIOPDEN3_GPIOPDEN_PULLDOWN1 (0x1UL) /*!< Pull up enable                                                       */


/* GPIOS_GPIOPDEN4: GPIO pull down enable configuration */
  #define GPIOS_GPIOPDEN4_ResetValue (0x01UL)        /*!< Reset value of GPIOPDEN4 register.                                   */

/* GPIOPDEN @Bit 0 : GPIO pull down enable */
  #define GPIOS_GPIOPDEN4_GPIOPDEN_Pos (0UL)         /*!< Position of GPIOPDEN field.                                          */
  #define GPIOS_GPIOPDEN4_GPIOPDEN_Msk (0x1UL << GPIOS_GPIOPDEN4_GPIOPDEN_Pos) /*!< Bit mask of GPIOPDEN field.                */
  #define GPIOS_GPIOPDEN4_GPIOPDEN_Min (0x0UL)       /*!< Min enumerator value of GPIOPDEN field.                              */
  #define GPIOS_GPIOPDEN4_GPIOPDEN_Max (0x1UL)       /*!< Max enumerator value of GPIOPDEN field.                              */
  #define GPIOS_GPIOPDEN4_GPIOPDEN_PULLDOWN0 (0x0UL) /*!< Pull up disable                                                      */
  #define GPIOS_GPIOPDEN4_GPIOPDEN_PULLDOWN1 (0x1UL) /*!< Pull up enable                                                       */


/* GPIOS_GPIOOPENDRAIN0: GPIO open drain configuration */
  #define GPIOS_GPIOOPENDRAIN0_ResetValue (0x00UL)   /*!< Reset value of GPIOOPENDRAIN0 register.                              */

/* GPIOOPENDRAIN @Bit 0 : GPIO open drain */
  #define GPIOS_GPIOOPENDRAIN0_GPIOOPENDRAIN_Pos (0UL) /*!< Position of GPIOOPENDRAIN field.                                   */
  #define GPIOS_GPIOOPENDRAIN0_GPIOOPENDRAIN_Msk (0x1UL << GPIOS_GPIOOPENDRAIN0_GPIOOPENDRAIN_Pos) /*!< Bit mask of
                                                                            GPIOOPENDRAIN field.*/                                
  #define GPIOS_GPIOOPENDRAIN0_GPIOOPENDRAIN_Min (0x0UL) /*!< Min enumerator value of GPIOOPENDRAIN field.                     */
  #define GPIOS_GPIOOPENDRAIN0_GPIOOPENDRAIN_Max (0x1UL) /*!< Max enumerator value of GPIOOPENDRAIN field.                     */
  #define GPIOS_GPIOOPENDRAIN0_GPIOOPENDRAIN_OPENDRAIN0 (0x0UL) /*!< Open drain disable                                        */
  #define GPIOS_GPIOOPENDRAIN0_GPIOOPENDRAIN_OPENDRAIN1 (0x1UL) /*!< Open drain enable                                         */


/* GPIOS_GPIOOPENDRAIN1: GPIO open drain configuration */
  #define GPIOS_GPIOOPENDRAIN1_ResetValue (0x00UL)   /*!< Reset value of GPIOOPENDRAIN1 register.                              */

/* GPIOOPENDRAIN @Bit 0 : GPIO open drain */
  #define GPIOS_GPIOOPENDRAIN1_GPIOOPENDRAIN_Pos (0UL) /*!< Position of GPIOOPENDRAIN field.                                   */
  #define GPIOS_GPIOOPENDRAIN1_GPIOOPENDRAIN_Msk (0x1UL << GPIOS_GPIOOPENDRAIN1_GPIOOPENDRAIN_Pos) /*!< Bit mask of
                                                                            GPIOOPENDRAIN field.*/                                
  #define GPIOS_GPIOOPENDRAIN1_GPIOOPENDRAIN_Min (0x0UL) /*!< Min enumerator value of GPIOOPENDRAIN field.                     */
  #define GPIOS_GPIOOPENDRAIN1_GPIOOPENDRAIN_Max (0x1UL) /*!< Max enumerator value of GPIOOPENDRAIN field.                     */
  #define GPIOS_GPIOOPENDRAIN1_GPIOOPENDRAIN_OPENDRAIN0 (0x0UL) /*!< Open drain disable                                        */
  #define GPIOS_GPIOOPENDRAIN1_GPIOOPENDRAIN_OPENDRAIN1 (0x1UL) /*!< Open drain enable                                         */


/* GPIOS_GPIOOPENDRAIN2: GPIO open drain configuration */
  #define GPIOS_GPIOOPENDRAIN2_ResetValue (0x00UL)   /*!< Reset value of GPIOOPENDRAIN2 register.                              */

/* GPIOOPENDRAIN @Bit 0 : GPIO open drain */
  #define GPIOS_GPIOOPENDRAIN2_GPIOOPENDRAIN_Pos (0UL) /*!< Position of GPIOOPENDRAIN field.                                   */
  #define GPIOS_GPIOOPENDRAIN2_GPIOOPENDRAIN_Msk (0x1UL << GPIOS_GPIOOPENDRAIN2_GPIOOPENDRAIN_Pos) /*!< Bit mask of
                                                                            GPIOOPENDRAIN field.*/                                
  #define GPIOS_GPIOOPENDRAIN2_GPIOOPENDRAIN_Min (0x0UL) /*!< Min enumerator value of GPIOOPENDRAIN field.                     */
  #define GPIOS_GPIOOPENDRAIN2_GPIOOPENDRAIN_Max (0x1UL) /*!< Max enumerator value of GPIOOPENDRAIN field.                     */
  #define GPIOS_GPIOOPENDRAIN2_GPIOOPENDRAIN_OPENDRAIN0 (0x0UL) /*!< Open drain disable                                        */
  #define GPIOS_GPIOOPENDRAIN2_GPIOOPENDRAIN_OPENDRAIN1 (0x1UL) /*!< Open drain enable                                         */


/* GPIOS_GPIOOPENDRAIN3: GPIO open drain configuration */
  #define GPIOS_GPIOOPENDRAIN3_ResetValue (0x00UL)   /*!< Reset value of GPIOOPENDRAIN3 register.                              */

/* GPIOOPENDRAIN @Bit 0 : GPIO open drain */
  #define GPIOS_GPIOOPENDRAIN3_GPIOOPENDRAIN_Pos (0UL) /*!< Position of GPIOOPENDRAIN field.                                   */
  #define GPIOS_GPIOOPENDRAIN3_GPIOOPENDRAIN_Msk (0x1UL << GPIOS_GPIOOPENDRAIN3_GPIOOPENDRAIN_Pos) /*!< Bit mask of
                                                                            GPIOOPENDRAIN field.*/                                
  #define GPIOS_GPIOOPENDRAIN3_GPIOOPENDRAIN_Min (0x0UL) /*!< Min enumerator value of GPIOOPENDRAIN field.                     */
  #define GPIOS_GPIOOPENDRAIN3_GPIOOPENDRAIN_Max (0x1UL) /*!< Max enumerator value of GPIOOPENDRAIN field.                     */
  #define GPIOS_GPIOOPENDRAIN3_GPIOOPENDRAIN_OPENDRAIN0 (0x0UL) /*!< Open drain disable                                        */
  #define GPIOS_GPIOOPENDRAIN3_GPIOOPENDRAIN_OPENDRAIN1 (0x1UL) /*!< Open drain enable                                         */


/* GPIOS_GPIOOPENDRAIN4: GPIO open drain configuration */
  #define GPIOS_GPIOOPENDRAIN4_ResetValue (0x00UL)   /*!< Reset value of GPIOOPENDRAIN4 register.                              */

/* GPIOOPENDRAIN @Bit 0 : GPIO open drain */
  #define GPIOS_GPIOOPENDRAIN4_GPIOOPENDRAIN_Pos (0UL) /*!< Position of GPIOOPENDRAIN field.                                   */
  #define GPIOS_GPIOOPENDRAIN4_GPIOOPENDRAIN_Msk (0x1UL << GPIOS_GPIOOPENDRAIN4_GPIOOPENDRAIN_Pos) /*!< Bit mask of
                                                                            GPIOOPENDRAIN field.*/                                
  #define GPIOS_GPIOOPENDRAIN4_GPIOOPENDRAIN_Min (0x0UL) /*!< Min enumerator value of GPIOOPENDRAIN field.                     */
  #define GPIOS_GPIOOPENDRAIN4_GPIOOPENDRAIN_Max (0x1UL) /*!< Max enumerator value of GPIOOPENDRAIN field.                     */
  #define GPIOS_GPIOOPENDRAIN4_GPIOOPENDRAIN_OPENDRAIN0 (0x0UL) /*!< Open drain disable                                        */
  #define GPIOS_GPIOOPENDRAIN4_GPIOOPENDRAIN_OPENDRAIN1 (0x1UL) /*!< Open drain enable                                         */


/* GPIOS_GPIODEBOUNCE0: GPIO debounce configuration */
  #define GPIOS_GPIODEBOUNCE0_ResetValue (0x00UL)    /*!< Reset value of GPIODEBOUNCE0 register.                               */

/* GPIODEBOUNCE @Bit 0 : GPIO debounce */
  #define GPIOS_GPIODEBOUNCE0_GPIODEBOUNCE_Pos (0UL) /*!< Position of GPIODEBOUNCE field.                                      */
  #define GPIOS_GPIODEBOUNCE0_GPIODEBOUNCE_Msk (0x1UL << GPIOS_GPIODEBOUNCE0_GPIODEBOUNCE_Pos) /*!< Bit mask of GPIODEBOUNCE
                                                                            field.*/                                              
  #define GPIOS_GPIODEBOUNCE0_GPIODEBOUNCE_Min (0x0UL) /*!< Min enumerator value of GPIODEBOUNCE field.                        */
  #define GPIOS_GPIODEBOUNCE0_GPIODEBOUNCE_Max (0x1UL) /*!< Max enumerator value of GPIODEBOUNCE field.                        */
  #define GPIOS_GPIODEBOUNCE0_GPIODEBOUNCE_DEBOUNCE0 (0x0UL) /*!< Debounce disable                                             */
  #define GPIOS_GPIODEBOUNCE0_GPIODEBOUNCE_DEBOUNCE1 (0x1UL) /*!< Debounce enable                                              */


/* GPIOS_GPIODEBOUNCE1: GPIO debounce configuration */
  #define GPIOS_GPIODEBOUNCE1_ResetValue (0x00UL)    /*!< Reset value of GPIODEBOUNCE1 register.                               */

/* GPIODEBOUNCE @Bit 0 : GPIO debounce */
  #define GPIOS_GPIODEBOUNCE1_GPIODEBOUNCE_Pos (0UL) /*!< Position of GPIODEBOUNCE field.                                      */
  #define GPIOS_GPIODEBOUNCE1_GPIODEBOUNCE_Msk (0x1UL << GPIOS_GPIODEBOUNCE1_GPIODEBOUNCE_Pos) /*!< Bit mask of GPIODEBOUNCE
                                                                            field.*/                                              
  #define GPIOS_GPIODEBOUNCE1_GPIODEBOUNCE_Min (0x0UL) /*!< Min enumerator value of GPIODEBOUNCE field.                        */
  #define GPIOS_GPIODEBOUNCE1_GPIODEBOUNCE_Max (0x1UL) /*!< Max enumerator value of GPIODEBOUNCE field.                        */
  #define GPIOS_GPIODEBOUNCE1_GPIODEBOUNCE_DEBOUNCE0 (0x0UL) /*!< Debounce disable                                             */
  #define GPIOS_GPIODEBOUNCE1_GPIODEBOUNCE_DEBOUNCE1 (0x1UL) /*!< Debounce enable                                              */


/* GPIOS_GPIODEBOUNCE2: GPIO debounce configuration */
  #define GPIOS_GPIODEBOUNCE2_ResetValue (0x00UL)    /*!< Reset value of GPIODEBOUNCE2 register.                               */

/* GPIODEBOUNCE @Bit 0 : GPIO debounce */
  #define GPIOS_GPIODEBOUNCE2_GPIODEBOUNCE_Pos (0UL) /*!< Position of GPIODEBOUNCE field.                                      */
  #define GPIOS_GPIODEBOUNCE2_GPIODEBOUNCE_Msk (0x1UL << GPIOS_GPIODEBOUNCE2_GPIODEBOUNCE_Pos) /*!< Bit mask of GPIODEBOUNCE
                                                                            field.*/                                              
  #define GPIOS_GPIODEBOUNCE2_GPIODEBOUNCE_Min (0x0UL) /*!< Min enumerator value of GPIODEBOUNCE field.                        */
  #define GPIOS_GPIODEBOUNCE2_GPIODEBOUNCE_Max (0x1UL) /*!< Max enumerator value of GPIODEBOUNCE field.                        */
  #define GPIOS_GPIODEBOUNCE2_GPIODEBOUNCE_DEBOUNCE0 (0x0UL) /*!< Debounce disable                                             */
  #define GPIOS_GPIODEBOUNCE2_GPIODEBOUNCE_DEBOUNCE1 (0x1UL) /*!< Debounce enable                                              */


/* GPIOS_GPIODEBOUNCE3: GPIO debounce configuration */
  #define GPIOS_GPIODEBOUNCE3_ResetValue (0x00UL)    /*!< Reset value of GPIODEBOUNCE3 register.                               */

/* GPIODEBOUNCE @Bit 0 : GPIO debounce */
  #define GPIOS_GPIODEBOUNCE3_GPIODEBOUNCE_Pos (0UL) /*!< Position of GPIODEBOUNCE field.                                      */
  #define GPIOS_GPIODEBOUNCE3_GPIODEBOUNCE_Msk (0x1UL << GPIOS_GPIODEBOUNCE3_GPIODEBOUNCE_Pos) /*!< Bit mask of GPIODEBOUNCE
                                                                            field.*/                                              
  #define GPIOS_GPIODEBOUNCE3_GPIODEBOUNCE_Min (0x0UL) /*!< Min enumerator value of GPIODEBOUNCE field.                        */
  #define GPIOS_GPIODEBOUNCE3_GPIODEBOUNCE_Max (0x1UL) /*!< Max enumerator value of GPIODEBOUNCE field.                        */
  #define GPIOS_GPIODEBOUNCE3_GPIODEBOUNCE_DEBOUNCE0 (0x0UL) /*!< Debounce disable                                             */
  #define GPIOS_GPIODEBOUNCE3_GPIODEBOUNCE_DEBOUNCE1 (0x1UL) /*!< Debounce enable                                              */


/* GPIOS_GPIODEBOUNCE4: GPIO debounce configuration */
  #define GPIOS_GPIODEBOUNCE4_ResetValue (0x00UL)    /*!< Reset value of GPIODEBOUNCE4 register.                               */

/* GPIODEBOUNCE @Bit 0 : GPIO debounce */
  #define GPIOS_GPIODEBOUNCE4_GPIODEBOUNCE_Pos (0UL) /*!< Position of GPIODEBOUNCE field.                                      */
  #define GPIOS_GPIODEBOUNCE4_GPIODEBOUNCE_Msk (0x1UL << GPIOS_GPIODEBOUNCE4_GPIODEBOUNCE_Pos) /*!< Bit mask of GPIODEBOUNCE
                                                                            field.*/                                              
  #define GPIOS_GPIODEBOUNCE4_GPIODEBOUNCE_Min (0x0UL) /*!< Min enumerator value of GPIODEBOUNCE field.                        */
  #define GPIOS_GPIODEBOUNCE4_GPIODEBOUNCE_Max (0x1UL) /*!< Max enumerator value of GPIODEBOUNCE field.                        */
  #define GPIOS_GPIODEBOUNCE4_GPIODEBOUNCE_DEBOUNCE0 (0x0UL) /*!< Debounce disable                                             */
  #define GPIOS_GPIODEBOUNCE4_GPIODEBOUNCE_DEBOUNCE1 (0x1UL) /*!< Debounce enable                                              */


/* GPIOS_GPIOSTATUS: GPIO status */
  #define GPIOS_GPIOSTATUS_ResetValue (0x00UL)       /*!< Reset value of GPIOSTATUS register.                                  */

/* GPIO0STATUS @Bit 0 : GPIO0 status */
  #define GPIOS_GPIOSTATUS_GPIO0STATUS_Pos (0UL)     /*!< Position of GPIO0STATUS field.                                       */
  #define GPIOS_GPIOSTATUS_GPIO0STATUS_Msk (0x1UL << GPIOS_GPIOSTATUS_GPIO0STATUS_Pos) /*!< Bit mask of GPIO0STATUS field.     */
  #define GPIOS_GPIOSTATUS_GPIO0STATUS_Min (0x0UL)   /*!< Min enumerator value of GPIO0STATUS field.                           */
  #define GPIOS_GPIOSTATUS_GPIO0STATUS_Max (0x1UL)   /*!< Max enumerator value of GPIO0STATUS field.                           */
  #define GPIOS_GPIOSTATUS_GPIO0STATUS_LOW (0x0UL)   /*!< Low                                                                  */
  #define GPIOS_GPIOSTATUS_GPIO0STATUS_HIGH (0x1UL)  /*!< High                                                                 */

/* GPIO1STATUS @Bit 1 : GPIO1 status */
  #define GPIOS_GPIOSTATUS_GPIO1STATUS_Pos (1UL)     /*!< Position of GPIO1STATUS field.                                       */
  #define GPIOS_GPIOSTATUS_GPIO1STATUS_Msk (0x1UL << GPIOS_GPIOSTATUS_GPIO1STATUS_Pos) /*!< Bit mask of GPIO1STATUS field.     */
  #define GPIOS_GPIOSTATUS_GPIO1STATUS_Min (0x0UL)   /*!< Min enumerator value of GPIO1STATUS field.                           */
  #define GPIOS_GPIOSTATUS_GPIO1STATUS_Max (0x1UL)   /*!< Max enumerator value of GPIO1STATUS field.                           */
  #define GPIOS_GPIOSTATUS_GPIO1STATUS_LOW (0x0UL)   /*!< Low                                                                  */
  #define GPIOS_GPIOSTATUS_GPIO1STATUS_HIGH (0x1UL)  /*!< High                                                                 */

/* GPIO2STATUS @Bit 2 : GPIO2 status */
  #define GPIOS_GPIOSTATUS_GPIO2STATUS_Pos (2UL)     /*!< Position of GPIO2STATUS field.                                       */
  #define GPIOS_GPIOSTATUS_GPIO2STATUS_Msk (0x1UL << GPIOS_GPIOSTATUS_GPIO2STATUS_Pos) /*!< Bit mask of GPIO2STATUS field.     */
  #define GPIOS_GPIOSTATUS_GPIO2STATUS_Min (0x0UL)   /*!< Min enumerator value of GPIO2STATUS field.                           */
  #define GPIOS_GPIOSTATUS_GPIO2STATUS_Max (0x1UL)   /*!< Max enumerator value of GPIO2STATUS field.                           */
  #define GPIOS_GPIOSTATUS_GPIO2STATUS_LOW (0x0UL)   /*!< Low                                                                  */
  #define GPIOS_GPIOSTATUS_GPIO2STATUS_HIGH (0x1UL)  /*!< High                                                                 */

/* GPIO3STATUS @Bit 3 : GPIO3 status */
  #define GPIOS_GPIOSTATUS_GPIO3STATUS_Pos (3UL)     /*!< Position of GPIO3STATUS field.                                       */
  #define GPIOS_GPIOSTATUS_GPIO3STATUS_Msk (0x1UL << GPIOS_GPIOSTATUS_GPIO3STATUS_Pos) /*!< Bit mask of GPIO3STATUS field.     */
  #define GPIOS_GPIOSTATUS_GPIO3STATUS_Min (0x0UL)   /*!< Min enumerator value of GPIO3STATUS field.                           */
  #define GPIOS_GPIOSTATUS_GPIO3STATUS_Max (0x1UL)   /*!< Max enumerator value of GPIO3STATUS field.                           */
  #define GPIOS_GPIOSTATUS_GPIO3STATUS_LOW (0x0UL)   /*!< Low                                                                  */
  #define GPIOS_GPIOSTATUS_GPIO3STATUS_HIGH (0x1UL)  /*!< High                                                                 */

/* GPIO4STATUS @Bit 4 : GPIO4 status */
  #define GPIOS_GPIOSTATUS_GPIO4STATUS_Pos (4UL)     /*!< Position of GPIO4STATUS field.                                       */
  #define GPIOS_GPIOSTATUS_GPIO4STATUS_Msk (0x1UL << GPIOS_GPIOSTATUS_GPIO4STATUS_Pos) /*!< Bit mask of GPIO4STATUS field.     */
  #define GPIOS_GPIOSTATUS_GPIO4STATUS_Min (0x0UL)   /*!< Min enumerator value of GPIO4STATUS field.                           */
  #define GPIOS_GPIOSTATUS_GPIO4STATUS_Max (0x1UL)   /*!< Max enumerator value of GPIO4STATUS field.                           */
  #define GPIOS_GPIOSTATUS_GPIO4STATUS_LOW (0x0UL)   /*!< Low                                                                  */
  #define GPIOS_GPIOSTATUS_GPIO4STATUS_HIGH (0x1UL)  /*!< High                                                                 */


#endif                                               /*!< !defined(__ASSEMBLER__) && !defined(__ASSEMBLY__)                    */

/* =========================================================================================================================== */
/* ================                                           TIMER                                           ================ */
/* =========================================================================================================================== */

#if !defined(__ASSEMBLER__) && !defined(__ASSEMBLY__) /*!< Ignore C structs for assembly code.                                 */
/* ====================================================== Struct TIMER ======================================================= */
/**
  * @brief nPM1304 TIMER registers
  */
  typedef struct {                                   /*!< TIMER Structure                                                      */
    __OM uint8_t  TIMERSET;                          /*!< (@ 0x00000000) Start timer                                           */
    __OM uint8_t  TIMERCLR;                          /*!< (@ 0x00000001) Stop timer                                            */
    __IM uint8_t  RESERVED;
    __OM uint8_t  TIMERTARGETSTROBE;                 /*!< (@ 0x00000003) Strobe for timer target                               */
    __OM uint8_t  WATCHDOGKICK;                      /*!< (@ 0x00000004) Watchdog kick                                         */
    __IOM uint8_t TIMERCONFIG;                       /*!< (@ 0x00000005) Timer mode selection                                  */
    __IM uint8_t  TIMERSTATUS;                       /*!< (@ 0x00000006) Timers status                                         */
    __IM uint8_t  RESERVED1;
    __IOM uint8_t TIMERHIBYTE;                       /*!< (@ 0x00000008) Timer most significant byte                           */
    __IOM uint8_t TIMERMIDBYTE;                      /*!< (@ 0x00000009) Timer middle byte                                     */
    __IOM uint8_t TIMERLOBYTE;                       /*!< (@ 0x0000000A) Timer least significant byte                          */
  } NPM_TIMER_Type;                                  /*!< Size = 11 (0x00B)                                                    */

/* TIMER_TIMERSET: Start timer */
  #define TIMER_TIMERSET_ResetValue (0x00UL)         /*!< Reset value of TIMERSET register.                                    */

/* TASKTIMEREN @Bit 0 : Start timer */
  #define TIMER_TIMERSET_TASKTIMEREN_Pos (0UL)       /*!< Position of TASKTIMEREN field.                                       */
  #define TIMER_TIMERSET_TASKTIMEREN_Msk (0x1UL << TIMER_TIMERSET_TASKTIMEREN_Pos) /*!< Bit mask of TASKTIMEREN field.         */
  #define TIMER_TIMERSET_TASKTIMEREN_Min (0x0UL)     /*!< Min enumerator value of TASKTIMEREN field.                           */
  #define TIMER_TIMERSET_TASKTIMEREN_Max (0x1UL)     /*!< Max enumerator value of TASKTIMEREN field.                           */
  #define TIMER_TIMERSET_TASKTIMEREN_NOEFFECT (0x0UL) /*!< No effect                                                           */
  #define TIMER_TIMERSET_TASKTIMEREN_SET (0x1UL)     /*!< Timer start request                                                  */


/* TIMER_TIMERCLR: Stop timer */
  #define TIMER_TIMERCLR_ResetValue (0x00UL)         /*!< Reset value of TIMERCLR register.                                    */

/* TASKTIMERDIS @Bit 0 : Stop timer */
  #define TIMER_TIMERCLR_TASKTIMERDIS_Pos (0UL)      /*!< Position of TASKTIMERDIS field.                                      */
  #define TIMER_TIMERCLR_TASKTIMERDIS_Msk (0x1UL << TIMER_TIMERCLR_TASKTIMERDIS_Pos) /*!< Bit mask of TASKTIMERDIS field.      */
  #define TIMER_TIMERCLR_TASKTIMERDIS_Min (0x0UL)    /*!< Min enumerator value of TASKTIMERDIS field.                          */
  #define TIMER_TIMERCLR_TASKTIMERDIS_Max (0x1UL)    /*!< Max enumerator value of TASKTIMERDIS field.                          */
  #define TIMER_TIMERCLR_TASKTIMERDIS_NOEFFECT (0x0UL) /*!< No effect                                                          */
  #define TIMER_TIMERCLR_TASKTIMERDIS_SET (0x1UL)    /*!< Timer stop request                                                   */


/* TIMER_TIMERTARGETSTROBE: Strobe for timer target */
  #define TIMER_TIMERTARGETSTROBE_ResetValue (0x00UL) /*!< Reset value of TIMERTARGETSTROBE register.                          */

/* TASKTIMERTARGETSTROBE @Bit 0 : Timer target strobe */
  #define TIMER_TIMERTARGETSTROBE_TASKTIMERTARGETSTROBE_Pos (0UL) /*!< Position of TASKTIMERTARGETSTROBE field.                */
  #define TIMER_TIMERTARGETSTROBE_TASKTIMERTARGETSTROBE_Msk (0x1UL << TIMER_TIMERTARGETSTROBE_TASKTIMERTARGETSTROBE_Pos) /*!<
                                                                            Bit mask of TASKTIMERTARGETSTROBE field.*/            
  #define TIMER_TIMERTARGETSTROBE_TASKTIMERTARGETSTROBE_Min (0x0UL) /*!< Min enumerator value of TASKTIMERTARGETSTROBE field.  */
  #define TIMER_TIMERTARGETSTROBE_TASKTIMERTARGETSTROBE_Max (0x1UL) /*!< Max enumerator value of TASKTIMERTARGETSTROBE field.  */
  #define TIMER_TIMERTARGETSTROBE_TASKTIMERTARGETSTROBE_NOEFFECT (0x0UL) /*!< No effect                                        */
  #define TIMER_TIMERTARGETSTROBE_TASKTIMERTARGETSTROBE_SET (0x1UL) /*!< Load timer target (24-bit timer value)                */


/* TIMER_WATCHDOGKICK: Watchdog kick */
  #define TIMER_WATCHDOGKICK_ResetValue (0x00UL)     /*!< Reset value of WATCHDOGKICK register.                                */

/* TASKWATCHDOGKICK @Bit 0 : Watchdog kick */
  #define TIMER_WATCHDOGKICK_TASKWATCHDOGKICK_Pos (0UL) /*!< Position of TASKWATCHDOGKICK field.                               */
  #define TIMER_WATCHDOGKICK_TASKWATCHDOGKICK_Msk (0x1UL << TIMER_WATCHDOGKICK_TASKWATCHDOGKICK_Pos) /*!< Bit mask of
                                                                            TASKWATCHDOGKICK field.*/                             
  #define TIMER_WATCHDOGKICK_TASKWATCHDOGKICK_Min (0x0UL) /*!< Min enumerator value of TASKWATCHDOGKICK field.                 */
  #define TIMER_WATCHDOGKICK_TASKWATCHDOGKICK_Max (0x1UL) /*!< Max enumerator value of TASKWATCHDOGKICK field.                 */
  #define TIMER_WATCHDOGKICK_TASKWATCHDOGKICK_NOEFFECT (0x0UL) /*!< No effect                                                  */
  #define TIMER_WATCHDOGKICK_TASKWATCHDOGKICK_Kick (0x1UL) /*!< Kick watchdog                                                  */


/* TIMER_TIMERCONFIG: Timer mode selection */
  #define TIMER_TIMERCONFIG_ResetValue (0x00UL)      /*!< Reset value of TIMERCONFIG register.                                 */

/* TIMERMODESEL @Bits 0..2 : Select watchdog and timer modes */
  #define TIMER_TIMERCONFIG_TIMERMODESEL_Pos (0UL)   /*!< Position of TIMERMODESEL field.                                      */
  #define TIMER_TIMERCONFIG_TIMERMODESEL_Msk (0x7UL << TIMER_TIMERCONFIG_TIMERMODESEL_Pos) /*!< Bit mask of TIMERMODESEL field.*/
  #define TIMER_TIMERCONFIG_TIMERMODESEL_Min (0x0UL) /*!< Min enumerator value of TIMERMODESEL field.                          */
  #define TIMER_TIMERCONFIG_TIMERMODESEL_Max (0x4UL) /*!< Max enumerator value of TIMERMODESEL field.                          */
  #define TIMER_TIMERCONFIG_TIMERMODESEL_BOOTMONITOR (0x0UL) /*!< Boot monitor                                                 */
  #define TIMER_TIMERCONFIG_TIMERMODESEL_WATCHDOGWARNING (0x1UL) /*!< Watchdog warning                                         */
  #define TIMER_TIMERCONFIG_TIMERMODESEL_WATCHDOGRESET (0x2UL) /*!< Watchdog reset                                             */
  #define TIMER_TIMERCONFIG_TIMERMODESEL_GENPURPOSETIMER (0x3UL) /*!< General purpose timer                                    */
  #define TIMER_TIMERCONFIG_TIMERMODESEL_WAKEUPTIMER (0x4UL) /*!< Wakeup timer                                                 */

/* TIMERPRESCALER @Bit 3 : Select between 16 ms and 2 ms timer prescaler */
  #define TIMER_TIMERCONFIG_TIMERPRESCALER_Pos (3UL) /*!< Position of TIMERPRESCALER field.                                    */
  #define TIMER_TIMERCONFIG_TIMERPRESCALER_Msk (0x1UL << TIMER_TIMERCONFIG_TIMERPRESCALER_Pos) /*!< Bit mask of TIMERPRESCALER
                                                                            field.*/                                              
  #define TIMER_TIMERCONFIG_TIMERPRESCALER_Min (0x0UL) /*!< Min enumerator value of TIMERPRESCALER field.                      */
  #define TIMER_TIMERCONFIG_TIMERPRESCALER_Max (0x1UL) /*!< Max enumerator value of TIMERPRESCALER field.                      */
  #define TIMER_TIMERCONFIG_TIMERPRESCALER_SLOW (0x0UL) /*!< 16 ms prescaler                                                   */
  #define TIMER_TIMERCONFIG_TIMERPRESCALER_FAST (0x1UL) /*!< 2 ms prescaler                                                    */


/* TIMER_TIMERSTATUS: Timers status */
  #define TIMER_TIMERSTATUS_ResetValue (0x00UL)      /*!< Reset value of TIMERSTATUS register.                                 */

/* BOOTMONITORACTIVE @Bit 0 : Boot monitor active */
  #define TIMER_TIMERSTATUS_BOOTMONITORACTIVE_Pos (0UL) /*!< Position of BOOTMONITORACTIVE field.                              */
  #define TIMER_TIMERSTATUS_BOOTMONITORACTIVE_Msk (0x1UL << TIMER_TIMERSTATUS_BOOTMONITORACTIVE_Pos) /*!< Bit mask of
                                                                            BOOTMONITORACTIVE field.*/                            
  #define TIMER_TIMERSTATUS_BOOTMONITORACTIVE_Min (0x0UL) /*!< Min enumerator value of BOOTMONITORACTIVE field.                */
  #define TIMER_TIMERSTATUS_BOOTMONITORACTIVE_Max (0x1UL) /*!< Max enumerator value of BOOTMONITORACTIVE field.                */
  #define TIMER_TIMERSTATUS_BOOTMONITORACTIVE_INACTIVE (0x0UL) /*!< Boot monitor not running                                   */
  #define TIMER_TIMERSTATUS_BOOTMONITORACTIVE_ACTIVE (0x1UL) /*!< Boot monitor running                                         */

/* SLOWDOMAINCONFIGURED @Bit 1 : Timer ready after TIMERTARGETSTROBE */
  #define TIMER_TIMERSTATUS_SLOWDOMAINCONFIGURED_Pos (1UL) /*!< Position of SLOWDOMAINCONFIGURED field.                        */
  #define TIMER_TIMERSTATUS_SLOWDOMAINCONFIGURED_Msk (0x1UL << TIMER_TIMERSTATUS_SLOWDOMAINCONFIGURED_Pos) /*!< Bit mask of
                                                                            SLOWDOMAINCONFIGURED field.*/                         
  #define TIMER_TIMERSTATUS_SLOWDOMAINCONFIGURED_Min (0x0UL) /*!< Min enumerator value of SLOWDOMAINCONFIGURED field.          */
  #define TIMER_TIMERSTATUS_SLOWDOMAINCONFIGURED_Max (0x1UL) /*!< Max enumerator value of SLOWDOMAINCONFIGURED field.          */
  #define TIMER_TIMERSTATUS_SLOWDOMAINCONFIGURED_NOTCONFIG (0x0UL) /*!< Not configured                                         */
  #define TIMER_TIMERSTATUS_SLOWDOMAINCONFIGURED_CONFIG (0x1UL) /*!< Timer configured                                          */


/* TIMER_TIMERHIBYTE: Timer most significant byte */
  #define TIMER_TIMERHIBYTE_ResetValue (0x00UL)      /*!< Reset value of TIMERHIBYTE register.                                 */

/* TIMERHIBYTE @Bits 0..7 : Timer most significant byte */
  #define TIMER_TIMERHIBYTE_TIMERHIBYTE_Pos (0UL)    /*!< Position of TIMERHIBYTE field.                                       */
  #define TIMER_TIMERHIBYTE_TIMERHIBYTE_Msk (0xFFUL << TIMER_TIMERHIBYTE_TIMERHIBYTE_Pos) /*!< Bit mask of TIMERHIBYTE field.  */


/* TIMER_TIMERMIDBYTE: Timer middle byte */
  #define TIMER_TIMERMIDBYTE_ResetValue (0x00UL)     /*!< Reset value of TIMERMIDBYTE register.                                */

/* TIMERMIDBYTE @Bits 0..7 : Timer middle byte */
  #define TIMER_TIMERMIDBYTE_TIMERMIDBYTE_Pos (0UL)  /*!< Position of TIMERMIDBYTE field.                                      */
  #define TIMER_TIMERMIDBYTE_TIMERMIDBYTE_Msk (0xFFUL << TIMER_TIMERMIDBYTE_TIMERMIDBYTE_Pos) /*!< Bit mask of TIMERMIDBYTE
                                                                            field.*/                                              


/* TIMER_TIMERLOBYTE: Timer least significant byte */
  #define TIMER_TIMERLOBYTE_ResetValue (0x00UL)      /*!< Reset value of TIMERLOBYTE register.                                 */

/* TIMERLOBYTE @Bits 0..7 : Timer least significant byte */
  #define TIMER_TIMERLOBYTE_TIMERLOBYTE_Pos (0UL)    /*!< Position of TIMERLOBYTE field.                                       */
  #define TIMER_TIMERLOBYTE_TIMERLOBYTE_Msk (0xFFUL << TIMER_TIMERLOBYTE_TIMERLOBYTE_Pos) /*!< Bit mask of TIMERLOBYTE field.  */


#endif                                               /*!< !defined(__ASSEMBLER__) && !defined(__ASSEMBLY__)                    */

/* =========================================================================================================================== */
/* ================                                           LDSW                                           ================ */
/* =========================================================================================================================== */

#if !defined(__ASSEMBLER__) && !defined(__ASSEMBLY__) /*!< Ignore C structs for assembly code.                                 */
/* ======================================================= Struct LDSW ======================================================= */
/**
  * @brief nPM1304 LDSW registers
  */
  typedef struct {                                   /*!< LDSW Structure                                                       */
    __OM uint8_t  TASKLDSW1SET;                      /*!< (@ 0x00000000) Enable LDSW1                                          */
    __OM uint8_t  TASKLDSW1CLR;                      /*!< (@ 0x00000001) Disable LDSW1                                         */
    __OM uint8_t  TASKLDSW2SET;                      /*!< (@ 0x00000002) Enable LDSW2                                          */
    __OM uint8_t  TASKLDSW2CLR;                      /*!< (@ 0x00000003) Disable LDSW2                                         */
    __IM uint8_t  LDSWSTATUS;                        /*!< (@ 0x00000004) Load switch and LDO status                            */
    __IOM uint8_t LDSW1GPISEL;                       /*!< (@ 0x00000005) LDSW1 GPIO control select                             */
    __IOM uint8_t LDSW2GPISEL;                       /*!< (@ 0x00000006) LDSW2 GPIO control select                             */
    __IOM uint8_t LDSWCONFIG;                        /*!< (@ 0x00000007) Load switch or LDO configuration                      */
    __IOM uint8_t LDSW1LDOSEL;                       /*!< (@ 0x00000008) Select LDSW1 mode                                     */
    __IOM uint8_t LDSW2LDOSEL;                       /*!< (@ 0x00000009) Select LDSW2 mode                                     */
    __IM uint16_t RESERVED;
    __IOM uint8_t LDSW1VOUTSEL;                      /*!< (@ 0x0000000C) LDO1 programmable output voltage                      */
    __IOM uint8_t LDSW2VOUTSEL;                      /*!< (@ 0x0000000D) LDO2 programmable output voltage                      */
  } NPM_LDSW_Type;                                   /*!< Size = 14 (0x00E)                                                    */

/* LDSW_TASKLDSW1SET: Enable LDSW1 */
  #define LDSW_TASKLDSW1SET_ResetValue (0x00UL)      /*!< Reset value of TASKLDSW1SET register.                                */

/* TASKLDSW1SET @Bit 0 : Set LDSW1 enable */
  #define LDSW_TASKLDSW1SET_TASKLDSW1SET_Pos (0UL)   /*!< Position of TASKLDSW1SET field.                                      */
  #define LDSW_TASKLDSW1SET_TASKLDSW1SET_Msk (0x1UL << LDSW_TASKLDSW1SET_TASKLDSW1SET_Pos) /*!< Bit mask of TASKLDSW1SET field.*/
  #define LDSW_TASKLDSW1SET_TASKLDSW1SET_Min (0x0UL) /*!< Min enumerator value of TASKLDSW1SET field.                          */
  #define LDSW_TASKLDSW1SET_TASKLDSW1SET_Max (0x1UL) /*!< Max enumerator value of TASKLDSW1SET field.                          */
  #define LDSW_TASKLDSW1SET_TASKLDSW1SET_NOEFFECT (0x0UL) /*!< No effect                                                       */
  #define LDSW_TASKLDSW1SET_TASKLDSW1SET_SET (0x1UL) /*!< Set enable                                                           */


/* LDSW_TASKLDSW1CLR: Disable LDSW1 */
  #define LDSW_TASKLDSW1CLR_ResetValue (0x00UL)      /*!< Reset value of TASKLDSW1CLR register.                                */

/* TASKLDSW1CLR @Bit 0 : Clear LDSW1 enable */
  #define LDSW_TASKLDSW1CLR_TASKLDSW1CLR_Pos (0UL)   /*!< Position of TASKLDSW1CLR field.                                      */
  #define LDSW_TASKLDSW1CLR_TASKLDSW1CLR_Msk (0x1UL << LDSW_TASKLDSW1CLR_TASKLDSW1CLR_Pos) /*!< Bit mask of TASKLDSW1CLR field.*/
  #define LDSW_TASKLDSW1CLR_TASKLDSW1CLR_Min (0x0UL) /*!< Min enumerator value of TASKLDSW1CLR field.                          */
  #define LDSW_TASKLDSW1CLR_TASKLDSW1CLR_Max (0x1UL) /*!< Max enumerator value of TASKLDSW1CLR field.                          */
  #define LDSW_TASKLDSW1CLR_TASKLDSW1CLR_NOEFFECT (0x0UL) /*!< No effect                                                       */
  #define LDSW_TASKLDSW1CLR_TASKLDSW1CLR_CLR (0x1UL) /*!< Clear enable                                                         */


/* LDSW_TASKLDSW2SET: Enable LDSW2 */
  #define LDSW_TASKLDSW2SET_ResetValue (0x00UL)      /*!< Reset value of TASKLDSW2SET register.                                */

/* TASKLDSW2SET @Bit 0 : Set LDSW2 enable */
  #define LDSW_TASKLDSW2SET_TASKLDSW2SET_Pos (0UL)   /*!< Position of TASKLDSW2SET field.                                      */
  #define LDSW_TASKLDSW2SET_TASKLDSW2SET_Msk (0x1UL << LDSW_TASKLDSW2SET_TASKLDSW2SET_Pos) /*!< Bit mask of TASKLDSW2SET field.*/
  #define LDSW_TASKLDSW2SET_TASKLDSW2SET_Min (0x0UL) /*!< Min enumerator value of TASKLDSW2SET field.                          */
  #define LDSW_TASKLDSW2SET_TASKLDSW2SET_Max (0x1UL) /*!< Max enumerator value of TASKLDSW2SET field.                          */
  #define LDSW_TASKLDSW2SET_TASKLDSW2SET_NOEFFECT (0x0UL) /*!< No effect                                                       */
  #define LDSW_TASKLDSW2SET_TASKLDSW2SET_SET (0x1UL) /*!< Set enable                                                           */


/* LDSW_TASKLDSW2CLR: Disable LDSW2 */
  #define LDSW_TASKLDSW2CLR_ResetValue (0x00UL)      /*!< Reset value of TASKLDSW2CLR register.                                */

/* TASKLDSW2CLR @Bit 0 : Clear LDSW2 enable */
  #define LDSW_TASKLDSW2CLR_TASKLDSW2CLR_Pos (0UL)   /*!< Position of TASKLDSW2CLR field.                                      */
  #define LDSW_TASKLDSW2CLR_TASKLDSW2CLR_Msk (0x1UL << LDSW_TASKLDSW2CLR_TASKLDSW2CLR_Pos) /*!< Bit mask of TASKLDSW2CLR field.*/
  #define LDSW_TASKLDSW2CLR_TASKLDSW2CLR_Min (0x0UL) /*!< Min enumerator value of TASKLDSW2CLR field.                          */
  #define LDSW_TASKLDSW2CLR_TASKLDSW2CLR_Max (0x1UL) /*!< Max enumerator value of TASKLDSW2CLR field.                          */
  #define LDSW_TASKLDSW2CLR_TASKLDSW2CLR_NOEFFECT (0x0UL) /*!< No effect                                                       */
  #define LDSW_TASKLDSW2CLR_TASKLDSW2CLR_CLR (0x1UL) /*!< Clear enable                                                         */


/* LDSW_LDSWSTATUS: Load switch and LDO status */
  #define LDSW_LDSWSTATUS_ResetValue (0x00UL)        /*!< Reset value of LDSWSTATUS register.                                  */

/* LDSW1PWRUPLDSW @Bit 0 : Load switch 1 status */
  #define LDSW_LDSWSTATUS_LDSW1PWRUPLDSW_Pos (0UL)   /*!< Position of LDSW1PWRUPLDSW field.                                    */
  #define LDSW_LDSWSTATUS_LDSW1PWRUPLDSW_Msk (0x1UL << LDSW_LDSWSTATUS_LDSW1PWRUPLDSW_Pos) /*!< Bit mask of LDSW1PWRUPLDSW
                                                                            field.*/                                              
  #define LDSW_LDSWSTATUS_LDSW1PWRUPLDSW_Min (0x0UL) /*!< Min enumerator value of LDSW1PWRUPLDSW field.                        */
  #define LDSW_LDSWSTATUS_LDSW1PWRUPLDSW_Max (0x1UL) /*!< Max enumerator value of LDSW1PWRUPLDSW field.                        */
  #define LDSW_LDSWSTATUS_LDSW1PWRUPLDSW_OFF (0x0UL) /*!< OFF                                                                  */
  #define LDSW_LDSWSTATUS_LDSW1PWRUPLDSW_ON (0x1UL)  /*!< ON                                                                   */

/* LDSW1PWRUPLDO @Bit 1 : LDO1 status */
  #define LDSW_LDSWSTATUS_LDSW1PWRUPLDO_Pos (1UL)    /*!< Position of LDSW1PWRUPLDO field.                                     */
  #define LDSW_LDSWSTATUS_LDSW1PWRUPLDO_Msk (0x1UL << LDSW_LDSWSTATUS_LDSW1PWRUPLDO_Pos) /*!< Bit mask of LDSW1PWRUPLDO field. */
  #define LDSW_LDSWSTATUS_LDSW1PWRUPLDO_Min (0x0UL)  /*!< Min enumerator value of LDSW1PWRUPLDO field.                         */
  #define LDSW_LDSWSTATUS_LDSW1PWRUPLDO_Max (0x1UL)  /*!< Max enumerator value of LDSW1PWRUPLDO field.                         */
  #define LDSW_LDSWSTATUS_LDSW1PWRUPLDO_OFF (0x0UL)  /*!< OFF                                                                  */
  #define LDSW_LDSWSTATUS_LDSW1PWRUPLDO_ON (0x1UL)   /*!< ON                                                                   */

/* LDSW2PWRUPLDSW @Bit 2 : Load switch 2 status */
  #define LDSW_LDSWSTATUS_LDSW2PWRUPLDSW_Pos (2UL)   /*!< Position of LDSW2PWRUPLDSW field.                                    */
  #define LDSW_LDSWSTATUS_LDSW2PWRUPLDSW_Msk (0x1UL << LDSW_LDSWSTATUS_LDSW2PWRUPLDSW_Pos) /*!< Bit mask of LDSW2PWRUPLDSW
                                                                            field.*/                                              
  #define LDSW_LDSWSTATUS_LDSW2PWRUPLDSW_Min (0x0UL) /*!< Min enumerator value of LDSW2PWRUPLDSW field.                        */
  #define LDSW_LDSWSTATUS_LDSW2PWRUPLDSW_Max (0x1UL) /*!< Max enumerator value of LDSW2PWRUPLDSW field.                        */
  #define LDSW_LDSWSTATUS_LDSW2PWRUPLDSW_OFF (0x0UL) /*!< OFF                                                                  */
  #define LDSW_LDSWSTATUS_LDSW2PWRUPLDSW_ON (0x1UL)  /*!< ON                                                                   */

/* LDSW2PWRUPLDO @Bit 3 : LDO2 status */
  #define LDSW_LDSWSTATUS_LDSW2PWRUPLDO_Pos (3UL)    /*!< Position of LDSW2PWRUPLDO field.                                     */
  #define LDSW_LDSWSTATUS_LDSW2PWRUPLDO_Msk (0x1UL << LDSW_LDSWSTATUS_LDSW2PWRUPLDO_Pos) /*!< Bit mask of LDSW2PWRUPLDO field. */
  #define LDSW_LDSWSTATUS_LDSW2PWRUPLDO_Min (0x0UL)  /*!< Min enumerator value of LDSW2PWRUPLDO field.                         */
  #define LDSW_LDSWSTATUS_LDSW2PWRUPLDO_Max (0x1UL)  /*!< Max enumerator value of LDSW2PWRUPLDO field.                         */
  #define LDSW_LDSWSTATUS_LDSW2PWRUPLDO_OFF (0x0UL)  /*!< OFF                                                                  */
  #define LDSW_LDSWSTATUS_LDSW2PWRUPLDO_ON (0x1UL)   /*!< ON                                                                   */

/* LDSWENABLE @Bit 4 : LDSW1 or LDSW2 in use */
  #define LDSW_LDSWSTATUS_LDSWENABLE_Pos (4UL)       /*!< Position of LDSWENABLE field.                                        */
  #define LDSW_LDSWSTATUS_LDSWENABLE_Msk (0x1UL << LDSW_LDSWSTATUS_LDSWENABLE_Pos) /*!< Bit mask of LDSWENABLE field.          */
  #define LDSW_LDSWSTATUS_LDSWENABLE_Min (0x0UL)     /*!< Min enumerator value of LDSWENABLE field.                            */
  #define LDSW_LDSWSTATUS_LDSWENABLE_Max (0x1UL)     /*!< Max enumerator value of LDSWENABLE field.                            */
  #define LDSW_LDSWSTATUS_LDSWENABLE_OFF (0x0UL)     /*!< OFF                                                                  */
  #define LDSW_LDSWSTATUS_LDSWENABLE_ON (0x1UL)      /*!< ON                                                                   */


/* LDSW_LDSW1GPISEL: LDSW1 GPIO control select */
  #define LDSW_LDSW1GPISEL_ResetValue (0x00UL)       /*!< Reset value of LDSW1GPISEL register.                                 */

/* LDSW1GPISEL @Bits 0..2 : Select which GPIO controls LDSW1 */
  #define LDSW_LDSW1GPISEL_LDSW1GPISEL_Pos (0UL)     /*!< Position of LDSW1GPISEL field.                                       */
  #define LDSW_LDSW1GPISEL_LDSW1GPISEL_Msk (0x7UL << LDSW_LDSW1GPISEL_LDSW1GPISEL_Pos) /*!< Bit mask of LDSW1GPISEL field.     */
  #define LDSW_LDSW1GPISEL_LDSW1GPISEL_Min (0x0UL)   /*!< Min enumerator value of LDSW1GPISEL field.                           */
  #define LDSW_LDSW1GPISEL_LDSW1GPISEL_Max (0x7UL)   /*!< Max enumerator value of LDSW1GPISEL field.                           */
  #define LDSW_LDSW1GPISEL_LDSW1GPISEL_NOTUSED1 (0x0UL) /*!< No GPIO selected                                                  */
  #define LDSW_LDSW1GPISEL_LDSW1GPISEL_GPIO0 (0x1UL) /*!< GPIO 0 selected                                                      */
  #define LDSW_LDSW1GPISEL_LDSW1GPISEL_GPIO1 (0x2UL) /*!< GPIO 1 selected                                                      */
  #define LDSW_LDSW1GPISEL_LDSW1GPISEL_GPIO2 (0x3UL) /*!< GPIO 2 selected                                                      */
  #define LDSW_LDSW1GPISEL_LDSW1GPISEL_GPIO3 (0x4UL) /*!< GPIO 3 selected                                                      */
  #define LDSW_LDSW1GPISEL_LDSW1GPISEL_GPIO4 (0x5UL) /*!< GPIO 4 selected                                                      */
  #define LDSW_LDSW1GPISEL_LDSW1GPISEL_NOTUSED2 (0x6UL) /*!< No GPIO selected                                                  */
  #define LDSW_LDSW1GPISEL_LDSW1GPISEL_NOTUSED3 (0x7UL) /*!< No GPIO selected                                                  */

/* LDSW1GPIINV @Bit 3 : Invert the sense of the selected GPIO */
  #define LDSW_LDSW1GPISEL_LDSW1GPIINV_Pos (3UL)     /*!< Position of LDSW1GPIINV field.                                       */
  #define LDSW_LDSW1GPISEL_LDSW1GPIINV_Msk (0x1UL << LDSW_LDSW1GPISEL_LDSW1GPIINV_Pos) /*!< Bit mask of LDSW1GPIINV field.     */
  #define LDSW_LDSW1GPISEL_LDSW1GPIINV_Min (0x0UL)   /*!< Min enumerator value of LDSW1GPIINV field.                           */
  #define LDSW_LDSW1GPISEL_LDSW1GPIINV_Max (0x1UL)   /*!< Max enumerator value of LDSW1GPIINV field.                           */
  #define LDSW_LDSW1GPISEL_LDSW1GPIINV_NORMAL (0x0UL) /*!< Not inverted                                                        */
  #define LDSW_LDSW1GPISEL_LDSW1GPIINV_INVERTED (0x1UL) /*!< Inverted                                                          */


/* LDSW_LDSW2GPISEL: LDSW2 GPIO control select */
  #define LDSW_LDSW2GPISEL_ResetValue (0x00UL)       /*!< Reset value of LDSW2GPISEL register.                                 */

/* LDSW2GPISEL @Bits 0..2 : Select which GPIO controls LDSW2 */
  #define LDSW_LDSW2GPISEL_LDSW2GPISEL_Pos (0UL)     /*!< Position of LDSW2GPISEL field.                                       */
  #define LDSW_LDSW2GPISEL_LDSW2GPISEL_Msk (0x7UL << LDSW_LDSW2GPISEL_LDSW2GPISEL_Pos) /*!< Bit mask of LDSW2GPISEL field.     */
  #define LDSW_LDSW2GPISEL_LDSW2GPISEL_Min (0x0UL)   /*!< Min enumerator value of LDSW2GPISEL field.                           */
  #define LDSW_LDSW2GPISEL_LDSW2GPISEL_Max (0x7UL)   /*!< Max enumerator value of LDSW2GPISEL field.                           */
  #define LDSW_LDSW2GPISEL_LDSW2GPISEL_NOTUSED1 (0x0UL) /*!< No GPIO selected                                                  */
  #define LDSW_LDSW2GPISEL_LDSW2GPISEL_GPIO0 (0x1UL) /*!< GPIO 0 selected                                                      */
  #define LDSW_LDSW2GPISEL_LDSW2GPISEL_GPIO1 (0x2UL) /*!< GPIO 1 selected                                                      */
  #define LDSW_LDSW2GPISEL_LDSW2GPISEL_GPIO2 (0x3UL) /*!< GPIO 2 selected                                                      */
  #define LDSW_LDSW2GPISEL_LDSW2GPISEL_GPIO3 (0x4UL) /*!< GPIO 3 selected                                                      */
  #define LDSW_LDSW2GPISEL_LDSW2GPISEL_GPIO4 (0x5UL) /*!< GPIO 4 selected                                                      */
  #define LDSW_LDSW2GPISEL_LDSW2GPISEL_NOTUSED2 (0x6UL) /*!< No GPIO selected                                                  */
  #define LDSW_LDSW2GPISEL_LDSW2GPISEL_NOTUSED3 (0x7UL) /*!< No GPIO selected                                                  */

/* LDSW2GPIINV @Bit 3 : Invert the sense of the selected GPIO */
  #define LDSW_LDSW2GPISEL_LDSW2GPIINV_Pos (3UL)     /*!< Position of LDSW2GPIINV field.                                       */
  #define LDSW_LDSW2GPISEL_LDSW2GPIINV_Msk (0x1UL << LDSW_LDSW2GPISEL_LDSW2GPIINV_Pos) /*!< Bit mask of LDSW2GPIINV field.     */
  #define LDSW_LDSW2GPISEL_LDSW2GPIINV_Min (0x0UL)   /*!< Min enumerator value of LDSW2GPIINV field.                           */
  #define LDSW_LDSW2GPISEL_LDSW2GPIINV_Max (0x1UL)   /*!< Max enumerator value of LDSW2GPIINV field.                           */
  #define LDSW_LDSW2GPISEL_LDSW2GPIINV_NORMAL (0x0UL) /*!< Not inverted                                                        */
  #define LDSW_LDSW2GPISEL_LDSW2GPIINV_INVERTED (0x1UL) /*!< Inverted                                                          */


/* LDSW_LDSWCONFIG: Load switch or LDO configuration */
  #define LDSW_LDSWCONFIG_ResetValue (0x00UL)        /*!< Reset value of LDSWCONFIG register.                                  */

/* LDSW1SOFTSTARTDISABLE @Bit 0 : LDSW1 soft start disable */
  #define LDSW_LDSWCONFIG_LDSW1SOFTSTARTDISABLE_Pos (0UL) /*!< Position of LDSW1SOFTSTARTDISABLE field.                        */
  #define LDSW_LDSWCONFIG_LDSW1SOFTSTARTDISABLE_Msk (0x1UL << LDSW_LDSWCONFIG_LDSW1SOFTSTARTDISABLE_Pos) /*!< Bit mask of
                                                                            LDSW1SOFTSTARTDISABLE field.*/                        
  #define LDSW_LDSWCONFIG_LDSW1SOFTSTARTDISABLE_Min (0x0UL) /*!< Min enumerator value of LDSW1SOFTSTARTDISABLE field.          */
  #define LDSW_LDSWCONFIG_LDSW1SOFTSTARTDISABLE_Max (0x1UL) /*!< Max enumerator value of LDSW1SOFTSTARTDISABLE field.          */
  #define LDSW_LDSWCONFIG_LDSW1SOFTSTARTDISABLE_NOEFFECT (0x0UL) /*!< No effect                                                */
  #define LDSW_LDSWCONFIG_LDSW1SOFTSTARTDISABLE_NOSOFTSTART (0x1UL) /*!< Soft start disabled                                   */

/* LDSW2SOFTSTARTDISABLE @Bit 1 : LDSW2 soft start disable */
  #define LDSW_LDSWCONFIG_LDSW2SOFTSTARTDISABLE_Pos (1UL) /*!< Position of LDSW2SOFTSTARTDISABLE field.                        */
  #define LDSW_LDSWCONFIG_LDSW2SOFTSTARTDISABLE_Msk (0x1UL << LDSW_LDSWCONFIG_LDSW2SOFTSTARTDISABLE_Pos) /*!< Bit mask of
                                                                            LDSW2SOFTSTARTDISABLE field.*/                        
  #define LDSW_LDSWCONFIG_LDSW2SOFTSTARTDISABLE_Min (0x0UL) /*!< Min enumerator value of LDSW2SOFTSTARTDISABLE field.          */
  #define LDSW_LDSWCONFIG_LDSW2SOFTSTARTDISABLE_Max (0x1UL) /*!< Max enumerator value of LDSW2SOFTSTARTDISABLE field.          */
  #define LDSW_LDSWCONFIG_LDSW2SOFTSTARTDISABLE_NOEFFECT (0x0UL) /*!< No effect                                                */
  #define LDSW_LDSWCONFIG_LDSW2SOFTSTARTDISABLE_NOSOFTSTART (0x1UL) /*!< Soft start disabled                                   */

/* LDSW1SOFTSTARTSEL @Bits 2..3 : Select soft start level for LDSW1 */
  #define LDSW_LDSWCONFIG_LDSW1SOFTSTARTSEL_Pos (2UL) /*!< Position of LDSW1SOFTSTARTSEL field.                                */
  #define LDSW_LDSWCONFIG_LDSW1SOFTSTARTSEL_Msk (0x3UL << LDSW_LDSWCONFIG_LDSW1SOFTSTARTSEL_Pos) /*!< Bit mask of
                                                                            LDSW1SOFTSTARTSEL field.*/                            
  #define LDSW_LDSWCONFIG_LDSW1SOFTSTARTSEL_Min (0x0UL) /*!< Min enumerator value of LDSW1SOFTSTARTSEL field.                  */
  #define LDSW_LDSWCONFIG_LDSW1SOFTSTARTSEL_Max (0x3UL) /*!< Max enumerator value of LDSW1SOFTSTARTSEL field.                  */
  #define LDSW_LDSWCONFIG_LDSW1SOFTSTARTSEL_10MA (0x0UL) /*!< 10 mA                                                            */
  #define LDSW_LDSWCONFIG_LDSW1SOFTSTARTSEL_20MA (0x1UL) /*!< 20 mA                                                            */
  #define LDSW_LDSWCONFIG_LDSW1SOFTSTARTSEL_35MA (0x2UL) /*!< 35 mA                                                            */
  #define LDSW_LDSWCONFIG_LDSW1SOFTSTARTSEL_50MA (0x3UL) /*!< 50 mA                                                            */

/* LDSW2SOFTSTARTSEL @Bits 4..5 : Select soft start level for LDSW2 */
  #define LDSW_LDSWCONFIG_LDSW2SOFTSTARTSEL_Pos (4UL) /*!< Position of LDSW2SOFTSTARTSEL field.                                */
  #define LDSW_LDSWCONFIG_LDSW2SOFTSTARTSEL_Msk (0x3UL << LDSW_LDSWCONFIG_LDSW2SOFTSTARTSEL_Pos) /*!< Bit mask of
                                                                            LDSW2SOFTSTARTSEL field.*/                            
  #define LDSW_LDSWCONFIG_LDSW2SOFTSTARTSEL_Min (0x0UL) /*!< Min enumerator value of LDSW2SOFTSTARTSEL field.                  */
  #define LDSW_LDSWCONFIG_LDSW2SOFTSTARTSEL_Max (0x3UL) /*!< Max enumerator value of LDSW2SOFTSTARTSEL field.                  */
  #define LDSW_LDSWCONFIG_LDSW2SOFTSTARTSEL_10MA (0x0UL) /*!< 10 mA                                                            */
  #define LDSW_LDSWCONFIG_LDSW2SOFTSTARTSEL_20MA (0x1UL) /*!< 20 mA                                                            */
  #define LDSW_LDSWCONFIG_LDSW2SOFTSTARTSEL_35MA (0x2UL) /*!< 35 mA                                                            */
  #define LDSW_LDSWCONFIG_LDSW2SOFTSTARTSEL_50MA (0x3UL) /*!< 50 mA                                                            */

/* LDSW1ACTIVEDISCHARGE @Bit 6 : LDSW1 active discharge enable */
  #define LDSW_LDSWCONFIG_LDSW1ACTIVEDISCHARGE_Pos (6UL) /*!< Position of LDSW1ACTIVEDISCHARGE field.                          */
  #define LDSW_LDSWCONFIG_LDSW1ACTIVEDISCHARGE_Msk (0x1UL << LDSW_LDSWCONFIG_LDSW1ACTIVEDISCHARGE_Pos) /*!< Bit mask of
                                                                            LDSW1ACTIVEDISCHARGE field.*/                         
  #define LDSW_LDSWCONFIG_LDSW1ACTIVEDISCHARGE_Min (0x0UL) /*!< Min enumerator value of LDSW1ACTIVEDISCHARGE field.            */
  #define LDSW_LDSWCONFIG_LDSW1ACTIVEDISCHARGE_Max (0x1UL) /*!< Max enumerator value of LDSW1ACTIVEDISCHARGE field.            */
  #define LDSW_LDSWCONFIG_LDSW1ACTIVEDISCHARGE_NODISCHARGE (0x0UL) /*!< No discharge                                           */
  #define LDSW_LDSWCONFIG_LDSW1ACTIVEDISCHARGE_ACTIVE (0x1UL) /*!< Active discharge enabled                                    */

/* LDSW2ACTIVEDISCHARGE @Bit 7 : LDSW2 active discharge enable */
  #define LDSW_LDSWCONFIG_LDSW2ACTIVEDISCHARGE_Pos (7UL) /*!< Position of LDSW2ACTIVEDISCHARGE field.                          */
  #define LDSW_LDSWCONFIG_LDSW2ACTIVEDISCHARGE_Msk (0x1UL << LDSW_LDSWCONFIG_LDSW2ACTIVEDISCHARGE_Pos) /*!< Bit mask of
                                                                            LDSW2ACTIVEDISCHARGE field.*/                         
  #define LDSW_LDSWCONFIG_LDSW2ACTIVEDISCHARGE_Min (0x0UL) /*!< Min enumerator value of LDSW2ACTIVEDISCHARGE field.            */
  #define LDSW_LDSWCONFIG_LDSW2ACTIVEDISCHARGE_Max (0x1UL) /*!< Max enumerator value of LDSW2ACTIVEDISCHARGE field.            */
  #define LDSW_LDSWCONFIG_LDSW2ACTIVEDISCHARGE_NODISCHARGE (0x0UL) /*!< No discharge                                           */
  #define LDSW_LDSWCONFIG_LDSW2ACTIVEDISCHARGE_ACTIVE (0x1UL) /*!< Active discharge enabled                                    */


/* LDSW_LDSW1LDOSEL: Select LDSW1 mode */
  #define LDSW_LDSW1LDOSEL_ResetValue (0x00UL)       /*!< Reset value of LDSW1LDOSEL register.                                 */

/* LDSW1LDOSEL @Bit 0 : Select Load switch or LDO */
  #define LDSW_LDSW1LDOSEL_LDSW1LDOSEL_Pos (0UL)     /*!< Position of LDSW1LDOSEL field.                                       */
  #define LDSW_LDSW1LDOSEL_LDSW1LDOSEL_Msk (0x1UL << LDSW_LDSW1LDOSEL_LDSW1LDOSEL_Pos) /*!< Bit mask of LDSW1LDOSEL field.     */
  #define LDSW_LDSW1LDOSEL_LDSW1LDOSEL_Min (0x0UL)   /*!< Min enumerator value of LDSW1LDOSEL field.                           */
  #define LDSW_LDSW1LDOSEL_LDSW1LDOSEL_Max (0x1UL)   /*!< Max enumerator value of LDSW1LDOSEL field.                           */
  #define LDSW_LDSW1LDOSEL_LDSW1LDOSEL_LDSW (0x0UL)  /*!< Load switch                                                          */
  #define LDSW_LDSW1LDOSEL_LDSW1LDOSEL_LDO (0x1UL)   /*!< LDO                                                                  */


/* LDSW_LDSW2LDOSEL: Select LDSW2 mode */
  #define LDSW_LDSW2LDOSEL_ResetValue (0x00UL)       /*!< Reset value of LDSW2LDOSEL register.                                 */

/* LDSW2LDOSEL @Bit 0 : Select Load switch or LDO */
  #define LDSW_LDSW2LDOSEL_LDSW2LDOSEL_Pos (0UL)     /*!< Position of LDSW2LDOSEL field.                                       */
  #define LDSW_LDSW2LDOSEL_LDSW2LDOSEL_Msk (0x1UL << LDSW_LDSW2LDOSEL_LDSW2LDOSEL_Pos) /*!< Bit mask of LDSW2LDOSEL field.     */
  #define LDSW_LDSW2LDOSEL_LDSW2LDOSEL_Min (0x0UL)   /*!< Min enumerator value of LDSW2LDOSEL field.                           */
  #define LDSW_LDSW2LDOSEL_LDSW2LDOSEL_Max (0x1UL)   /*!< Max enumerator value of LDSW2LDOSEL field.                           */
  #define LDSW_LDSW2LDOSEL_LDSW2LDOSEL_LDSW (0x0UL)  /*!< Load switch                                                          */
  #define LDSW_LDSW2LDOSEL_LDSW2LDOSEL_LDO (0x1UL)   /*!< LDO                                                                  */


/* LDSW_LDSW1VOUTSEL: LDO1 programmable output voltage */
  #define LDSW_LDSW1VOUTSEL_ResetValue (0x00UL)      /*!< Reset value of LDSW1VOUTSEL register.                                */

/* LDSW1VOUTSEL @Bits 0..4 : LDO1 programmable output voltage */
  #define LDSW_LDSW1VOUTSEL_LDSW1VOUTSEL_Pos (0UL)   /*!< Position of LDSW1VOUTSEL field.                                      */
  #define LDSW_LDSW1VOUTSEL_LDSW1VOUTSEL_Msk (0x1FUL << LDSW_LDSW1VOUTSEL_LDSW1VOUTSEL_Pos) /*!< Bit mask of LDSW1VOUTSEL
                                                                            field.*/                                              
  #define LDSW_LDSW1VOUTSEL_LDSW1VOUTSEL_Min (0x0UL) /*!< Min enumerator value of LDSW1VOUTSEL field.                          */
  #define LDSW_LDSW1VOUTSEL_LDSW1VOUTSEL_Max (0x17UL) /*!< Max enumerator value of LDSW1VOUTSEL field.                         */
  #define LDSW_LDSW1VOUTSEL_LDSW1VOUTSEL_1V (0x00UL) /*!< 1.0 V                                                                */
  #define LDSW_LDSW1VOUTSEL_LDSW1VOUTSEL_1V1 (0x01UL) /*!< 1.1 V                                                               */
  #define LDSW_LDSW1VOUTSEL_LDSW1VOUTSEL_1V2 (0x02UL) /*!< 1.2 V                                                               */
  #define LDSW_LDSW1VOUTSEL_LDSW1VOUTSEL_1V3 (0x03UL) /*!< 1.3 V                                                               */
  #define LDSW_LDSW1VOUTSEL_LDSW1VOUTSEL_1V4 (0x04UL) /*!< 1.4 V                                                               */
  #define LDSW_LDSW1VOUTSEL_LDSW1VOUTSEL_1V5 (0x05UL) /*!< 1.5 V                                                               */
  #define LDSW_LDSW1VOUTSEL_LDSW1VOUTSEL_1V6 (0x06UL) /*!< 1.6 V                                                               */
  #define LDSW_LDSW1VOUTSEL_LDSW1VOUTSEL_1V7 (0x07UL) /*!< 1.7 V                                                               */
  #define LDSW_LDSW1VOUTSEL_LDSW1VOUTSEL_1V8 (0x08UL) /*!< 1.8 V                                                               */
  #define LDSW_LDSW1VOUTSEL_LDSW1VOUTSEL_1V9 (0x09UL) /*!< 1.9 V                                                               */
  #define LDSW_LDSW1VOUTSEL_LDSW1VOUTSEL_2V (0x0AUL) /*!< 2.0 V                                                                */
  #define LDSW_LDSW1VOUTSEL_LDSW1VOUTSEL_2V1 (0x0BUL) /*!< 2.1 V                                                               */
  #define LDSW_LDSW1VOUTSEL_LDSW1VOUTSEL_2V2 (0x0CUL) /*!< 2.2 V                                                               */
  #define LDSW_LDSW1VOUTSEL_LDSW1VOUTSEL_2V3 (0x0DUL) /*!< 2.3 V                                                               */
  #define LDSW_LDSW1VOUTSEL_LDSW1VOUTSEL_2V4 (0x0EUL) /*!< 2.4 V                                                               */
  #define LDSW_LDSW1VOUTSEL_LDSW1VOUTSEL_2V5 (0x0FUL) /*!< 2.5 V                                                               */
  #define LDSW_LDSW1VOUTSEL_LDSW1VOUTSEL_2V6 (0x10UL) /*!< 2.6 V                                                               */
  #define LDSW_LDSW1VOUTSEL_LDSW1VOUTSEL_2V7 (0x11UL) /*!< 2.7 V                                                               */
  #define LDSW_LDSW1VOUTSEL_LDSW1VOUTSEL_2V8 (0x12UL) /*!< 2.8 V                                                               */
  #define LDSW_LDSW1VOUTSEL_LDSW1VOUTSEL_2V9 (0x13UL) /*!< 2.9 V                                                               */
  #define LDSW_LDSW1VOUTSEL_LDSW1VOUTSEL_3V (0x14UL) /*!< 3.0 V                                                                */
  #define LDSW_LDSW1VOUTSEL_LDSW1VOUTSEL_3V1 (0x15UL) /*!< 3.1 V                                                               */
  #define LDSW_LDSW1VOUTSEL_LDSW1VOUTSEL_3V2 (0x16UL) /*!< 3.2 V                                                               */
  #define LDSW_LDSW1VOUTSEL_LDSW1VOUTSEL_3V3 (0x17UL) /*!< 3.3 V                                                               */


/* LDSW_LDSW2VOUTSEL: LDO2 programmable output voltage */
  #define LDSW_LDSW2VOUTSEL_ResetValue (0x00UL)      /*!< Reset value of LDSW2VOUTSEL register.                                */

/* LDSW2VOUTSEL @Bits 0..4 : LDO2 programmable output voltage */
  #define LDSW_LDSW2VOUTSEL_LDSW2VOUTSEL_Pos (0UL)   /*!< Position of LDSW2VOUTSEL field.                                      */
  #define LDSW_LDSW2VOUTSEL_LDSW2VOUTSEL_Msk (0x1FUL << LDSW_LDSW2VOUTSEL_LDSW2VOUTSEL_Pos) /*!< Bit mask of LDSW2VOUTSEL
                                                                            field.*/                                              
  #define LDSW_LDSW2VOUTSEL_LDSW2VOUTSEL_Min (0x0UL) /*!< Min enumerator value of LDSW2VOUTSEL field.                          */
  #define LDSW_LDSW2VOUTSEL_LDSW2VOUTSEL_Max (0x17UL) /*!< Max enumerator value of LDSW2VOUTSEL field.                         */
  #define LDSW_LDSW2VOUTSEL_LDSW2VOUTSEL_1V (0x00UL) /*!< 1.0 V                                                                */
  #define LDSW_LDSW2VOUTSEL_LDSW2VOUTSEL_1V1 (0x01UL) /*!< 1.1 V                                                               */
  #define LDSW_LDSW2VOUTSEL_LDSW2VOUTSEL_1V2 (0x02UL) /*!< 1.2 V                                                               */
  #define LDSW_LDSW2VOUTSEL_LDSW2VOUTSEL_1V3 (0x03UL) /*!< 1.3 V                                                               */
  #define LDSW_LDSW2VOUTSEL_LDSW2VOUTSEL_1V4 (0x04UL) /*!< 1.4 V                                                               */
  #define LDSW_LDSW2VOUTSEL_LDSW2VOUTSEL_1V5 (0x05UL) /*!< 1.5 V                                                               */
  #define LDSW_LDSW2VOUTSEL_LDSW2VOUTSEL_1V6 (0x06UL) /*!< 1.6 V                                                               */
  #define LDSW_LDSW2VOUTSEL_LDSW2VOUTSEL_1V7 (0x07UL) /*!< 1.7 V                                                               */
  #define LDSW_LDSW2VOUTSEL_LDSW2VOUTSEL_1V8 (0x08UL) /*!< 1.8 V                                                               */
  #define LDSW_LDSW2VOUTSEL_LDSW2VOUTSEL_1V9 (0x09UL) /*!< 1.9 V                                                               */
  #define LDSW_LDSW2VOUTSEL_LDSW2VOUTSEL_2V (0x0AUL) /*!< 2.0 V                                                                */
  #define LDSW_LDSW2VOUTSEL_LDSW2VOUTSEL_2V1 (0x0BUL) /*!< 2.1 V                                                               */
  #define LDSW_LDSW2VOUTSEL_LDSW2VOUTSEL_2V2 (0x0CUL) /*!< 2.2 V                                                               */
  #define LDSW_LDSW2VOUTSEL_LDSW2VOUTSEL_2V3 (0x0DUL) /*!< 2.3 V                                                               */
  #define LDSW_LDSW2VOUTSEL_LDSW2VOUTSEL_2V4 (0x0EUL) /*!< 2.4 V                                                               */
  #define LDSW_LDSW2VOUTSEL_LDSW2VOUTSEL_2V5 (0x0FUL) /*!< 2.5 V                                                               */
  #define LDSW_LDSW2VOUTSEL_LDSW2VOUTSEL_2V6 (0x10UL) /*!< 2.6 V                                                               */
  #define LDSW_LDSW2VOUTSEL_LDSW2VOUTSEL_2V7 (0x11UL) /*!< 2.7 V                                                               */
  #define LDSW_LDSW2VOUTSEL_LDSW2VOUTSEL_2V8 (0x12UL) /*!< 2.8 V                                                               */
  #define LDSW_LDSW2VOUTSEL_LDSW2VOUTSEL_2V9 (0x13UL) /*!< 2.9 V                                                               */
  #define LDSW_LDSW2VOUTSEL_LDSW2VOUTSEL_3V (0x14UL) /*!< 3.0 V                                                                */
  #define LDSW_LDSW2VOUTSEL_LDSW2VOUTSEL_3V1 (0x15UL) /*!< 3.1 V                                                               */
  #define LDSW_LDSW2VOUTSEL_LDSW2VOUTSEL_3V2 (0x16UL) /*!< 3.2 V                                                               */
  #define LDSW_LDSW2VOUTSEL_LDSW2VOUTSEL_3V3 (0x17UL) /*!< 3.3 V                                                               */


#endif                                               /*!< !defined(__ASSEMBLER__) && !defined(__ASSEMBLY__)                    */

/* =========================================================================================================================== */
/* ================                                            POF                                            ================ */
/* =========================================================================================================================== */

#if !defined(__ASSEMBLER__) && !defined(__ASSEMBLY__) /*!< Ignore C structs for assembly code.                                 */
/* ======================================================= Struct POF ======================================================== */
/**
  * @brief nPM1304 POF registers
  */
  typedef struct {                                   /*!< POF Structure                                                        */
    __IOM uint8_t POFCONFIG;                         /*!< (@ 0x00000000) Configuration for power failure                       */
  } NPM_POF_Type;                                    /*!< Size = 1 (0x001)                                                     */

/* POF_POFCONFIG: Configuration for power failure */
  #define POF_POFCONFIG_ResetValue (0x00UL)          /*!< Reset value of POFCONFIG register.                                   */

/* POFENA @Bit 0 : Enable power failure warning */
  #define POF_POFCONFIG_POFENA_Pos (0UL)             /*!< Position of POFENA field.                                            */
  #define POF_POFCONFIG_POFENA_Msk (0x1UL << POF_POFCONFIG_POFENA_Pos) /*!< Bit mask of POFENA field.                          */
  #define POF_POFCONFIG_POFENA_Min (0x0UL)           /*!< Min enumerator value of POFENA field.                                */
  #define POF_POFCONFIG_POFENA_Max (0x1UL)           /*!< Max enumerator value of POFENA field.                                */
  #define POF_POFCONFIG_POFENA_OFF (0x0UL)           /*!< Warning disabled                                                     */
  #define POF_POFCONFIG_POFENA_ENABLED (0x1UL)       /*!< Warning enabled                                                      */

/* POFWARNPOLARITY @Bit 1 : Power failure warning polarity */
  #define POF_POFCONFIG_POFWARNPOLARITY_Pos (1UL)    /*!< Position of POFWARNPOLARITY field.                                   */
  #define POF_POFCONFIG_POFWARNPOLARITY_Msk (0x1UL << POF_POFCONFIG_POFWARNPOLARITY_Pos) /*!< Bit mask of POFWARNPOLARITY
                                                                            field.*/                                              
  #define POF_POFCONFIG_POFWARNPOLARITY_Min (0x0UL)  /*!< Min enumerator value of POFWARNPOLARITY field.                       */
  #define POF_POFCONFIG_POFWARNPOLARITY_Max (0x1UL)  /*!< Max enumerator value of POFWARNPOLARITY field.                       */
  #define POF_POFCONFIG_POFWARNPOLARITY_LOACTIVE (0x0UL) /*!< Active low                                                       */
  #define POF_POFCONFIG_POFWARNPOLARITY_HIACTIVE (0x1UL) /*!< Active high                                                      */

/* POFVSYSTHRESHSEL @Bits 2..5 : Power failure threshold select */
  #define POF_POFCONFIG_POFVSYSTHRESHSEL_Pos (2UL)   /*!< Position of POFVSYSTHRESHSEL field.                                  */
  #define POF_POFCONFIG_POFVSYSTHRESHSEL_Msk (0xFUL << POF_POFCONFIG_POFVSYSTHRESHSEL_Pos) /*!< Bit mask of POFVSYSTHRESHSEL
                                                                            field.*/                                              
  #define POF_POFCONFIG_POFVSYSTHRESHSEL_Min (0x0UL) /*!< Min enumerator value of POFVSYSTHRESHSEL field.                      */
  #define POF_POFCONFIG_POFVSYSTHRESHSEL_Max (0xFUL) /*!< Max enumerator value of POFVSYSTHRESHSEL field.                      */
  #define POF_POFCONFIG_POFVSYSTHRESHSEL_2V8 (0x0UL) /*!< 2.8 V                                                                */
  #define POF_POFCONFIG_POFVSYSTHRESHSEL_2V6 (0x1UL) /*!< 2.6 V                                                                */
  #define POF_POFCONFIG_POFVSYSTHRESHSEL_2V7 (0x2UL) /*!< 2.7 V                                                                */
  #define POF_POFCONFIG_POFVSYSTHRESHSEL_2V9 (0x3UL) /*!< 2.9 V                                                                */
  #define POF_POFCONFIG_POFVSYSTHRESHSEL_3V0 (0x4UL) /*!< 3.0 V                                                                */
  #define POF_POFCONFIG_POFVSYSTHRESHSEL_3V1 (0x5UL) /*!< 3.1 V                                                                */
  #define POF_POFCONFIG_POFVSYSTHRESHSEL_3V2 (0x6UL) /*!< 3.2 V                                                                */
  #define POF_POFCONFIG_POFVSYSTHRESHSEL_3V3 (0x7UL) /*!< 3.3 V                                                                */
  #define POF_POFCONFIG_POFVSYSTHRESHSEL_3V4 (0x8UL) /*!< 3.4 V                                                                */
  #define POF_POFCONFIG_POFVSYSTHRESHSEL_3V5 (0x9UL) /*!< 3.5 V                                                                */
  #define POF_POFCONFIG_POFVSYSTHRESHSEL_unused10 (0xAUL) /*!< 2.8 V                                                           */
  #define POF_POFCONFIG_POFVSYSTHRESHSEL_unused11 (0xBUL) /*!< 2.8 V                                                           */
  #define POF_POFCONFIG_POFVSYSTHRESHSEL_unused12 (0xCUL) /*!< 2.8 V                                                           */
  #define POF_POFCONFIG_POFVSYSTHRESHSEL_unused13 (0xDUL) /*!< 2.8 V                                                           */
  #define POF_POFCONFIG_POFVSYSTHRESHSEL_unused14 (0xEUL) /*!< 2.8 V                                                           */
  #define POF_POFCONFIG_POFVSYSTHRESHSEL_unused15 (0xFUL) /*!< 2.8 V                                                           */


#endif                                               /*!< !defined(__ASSEMBLER__) && !defined(__ASSEMBLY__)                    */

/* =========================================================================================================================== */
/* ================                                          LEDDRV                                          ================ */
/* =========================================================================================================================== */

#if !defined(__ASSEMBLER__) && !defined(__ASSEMBLY__) /*!< Ignore C structs for assembly code.                                 */
/* ====================================================== Struct LEDDRV ====================================================== */
/**
  * @brief nPM1304 LEDDRV registers
  */
  typedef struct {                                   /*!< LEDDRV Structure                                                     */
    __IOM uint8_t LEDDRV0MODESEL;                    /*!< (@ 0x00000000) Select LED0 mode                                      */
    __IOM uint8_t LEDDRV1MODESEL;                    /*!< (@ 0x00000001) Select LED1 mode                                      */
    __IOM uint8_t LEDDRV2MODESEL;                    /*!< (@ 0x00000002) Select LED2 mode                                      */
    __OM uint8_t  LEDDRV0SET;                        /*!< (@ 0x00000003) Turn LED0 On                                          */
    __OM uint8_t  LEDDRV0CLR;                        /*!< (@ 0x00000004) Turn LED0 Off                                         */
    __OM uint8_t  LEDDRV1SET;                        /*!< (@ 0x00000005) Turn LED1 On                                          */
    __OM uint8_t  LEDDRV1CLR;                        /*!< (@ 0x00000006) Turn LED1 Off                                         */
    __OM uint8_t  LEDDRV2SET;                        /*!< (@ 0x00000007) Turn LED2 On                                          */
    __OM uint8_t  LEDDRV2CLR;                        /*!< (@ 0x00000008) Turn LED2 Off                                         */
  } NPM_LEDDRV_Type;                                 /*!< Size = 9 (0x009)                                                     */

/* LEDDRV_LEDDRV0MODESEL: Select LED0 mode */
  #define LEDDRV_LEDDRV0MODESEL_ResetValue (0x00UL)  /*!< Reset value of LEDDRV0MODESEL register.                              */

/* LEDDRV0MODESEL @Bits 0..1 : Select LED0 mode */
  #define LEDDRV_LEDDRV0MODESEL_LEDDRV0MODESEL_Pos (0UL) /*!< Position of LEDDRV0MODESEL field.                                */
  #define LEDDRV_LEDDRV0MODESEL_LEDDRV0MODESEL_Msk (0x3UL << LEDDRV_LEDDRV0MODESEL_LEDDRV0MODESEL_Pos) /*!< Bit mask of
                                                                            LEDDRV0MODESEL field.*/                               
  #define LEDDRV_LEDDRV0MODESEL_LEDDRV0MODESEL_Min (0x0UL) /*!< Min enumerator value of LEDDRV0MODESEL field.                  */
  #define LEDDRV_LEDDRV0MODESEL_LEDDRV0MODESEL_Max (0x3UL) /*!< Max enumerator value of LEDDRV0MODESEL field.                  */
  #define LEDDRV_LEDDRV0MODESEL_LEDDRV0MODESEL_ERROR (0x0UL) /*!< Error condition from charger                                 */
  #define LEDDRV_LEDDRV0MODESEL_LEDDRV0MODESEL_CHARGING (0x1UL) /*!< Charging indicator (On during charging)                   */
  #define LEDDRV_LEDDRV0MODESEL_LEDDRV0MODESEL_HOST (0x2UL) /*!< Driven from register LEDDRV0SET/CLR                           */
  #define LEDDRV_LEDDRV0MODESEL_LEDDRV0MODESEL_NOTUSED (0x3UL) /*!< Not used                                                   */


/* LEDDRV_LEDDRV1MODESEL: Select LED1 mode */
  #define LEDDRV_LEDDRV1MODESEL_ResetValue (0x01UL)  /*!< Reset value of LEDDRV1MODESEL register.                              */

/* LEDDRV1MODESEL @Bits 0..1 : Select LED1 mode */
  #define LEDDRV_LEDDRV1MODESEL_LEDDRV1MODESEL_Pos (0UL) /*!< Position of LEDDRV1MODESEL field.                                */
  #define LEDDRV_LEDDRV1MODESEL_LEDDRV1MODESEL_Msk (0x3UL << LEDDRV_LEDDRV1MODESEL_LEDDRV1MODESEL_Pos) /*!< Bit mask of
                                                                            LEDDRV1MODESEL field.*/                               
  #define LEDDRV_LEDDRV1MODESEL_LEDDRV1MODESEL_Min (0x0UL) /*!< Min enumerator value of LEDDRV1MODESEL field.                  */
  #define LEDDRV_LEDDRV1MODESEL_LEDDRV1MODESEL_Max (0x3UL) /*!< Max enumerator value of LEDDRV1MODESEL field.                  */
  #define LEDDRV_LEDDRV1MODESEL_LEDDRV1MODESEL_ERROR (0x0UL) /*!< Error condition from charger                                 */
  #define LEDDRV_LEDDRV1MODESEL_LEDDRV1MODESEL_CHARGING (0x1UL) /*!< Charging indicator (On during charging)                   */
  #define LEDDRV_LEDDRV1MODESEL_LEDDRV1MODESEL_HOST (0x2UL) /*!< Driven from register LEDDRV1SET/CLR                           */
  #define LEDDRV_LEDDRV1MODESEL_LEDDRV1MODESEL_NOTUSED (0x3UL) /*!< Not used                                                   */


/* LEDDRV_LEDDRV2MODESEL: Select LED2 mode */
  #define LEDDRV_LEDDRV2MODESEL_ResetValue (0x02UL)  /*!< Reset value of LEDDRV2MODESEL register.                              */

/* LEDDRV2MODESEL @Bits 0..1 : Select LED2 mode */
  #define LEDDRV_LEDDRV2MODESEL_LEDDRV2MODESEL_Pos (0UL) /*!< Position of LEDDRV2MODESEL field.                                */
  #define LEDDRV_LEDDRV2MODESEL_LEDDRV2MODESEL_Msk (0x3UL << LEDDRV_LEDDRV2MODESEL_LEDDRV2MODESEL_Pos) /*!< Bit mask of
                                                                            LEDDRV2MODESEL field.*/                               
  #define LEDDRV_LEDDRV2MODESEL_LEDDRV2MODESEL_Min (0x0UL) /*!< Min enumerator value of LEDDRV2MODESEL field.                  */
  #define LEDDRV_LEDDRV2MODESEL_LEDDRV2MODESEL_Max (0x3UL) /*!< Max enumerator value of LEDDRV2MODESEL field.                  */
  #define LEDDRV_LEDDRV2MODESEL_LEDDRV2MODESEL_ERROR (0x0UL) /*!< Error condition from charger                                 */
  #define LEDDRV_LEDDRV2MODESEL_LEDDRV2MODESEL_CHARGING (0x1UL) /*!< Charging indicator (On during charging)                   */
  #define LEDDRV_LEDDRV2MODESEL_LEDDRV2MODESEL_HOST (0x2UL) /*!< Driven from register LEDDRV2SET/CLR                           */
  #define LEDDRV_LEDDRV2MODESEL_LEDDRV2MODESEL_NOTUSED (0x3UL) /*!< Not used                                                   */


/* LEDDRV_LEDDRV0SET: Turn LED0 On */
  #define LEDDRV_LEDDRV0SET_ResetValue (0x00UL)      /*!< Reset value of LEDDRV0SET register.                                  */

/* LEDDRV0ON @Bit 0 : Set LED0 to be On */
  #define LEDDRV_LEDDRV0SET_LEDDRV0ON_Pos (0UL)      /*!< Position of LEDDRV0ON field.                                         */
  #define LEDDRV_LEDDRV0SET_LEDDRV0ON_Msk (0x1UL << LEDDRV_LEDDRV0SET_LEDDRV0ON_Pos) /*!< Bit mask of LEDDRV0ON field.         */
  #define LEDDRV_LEDDRV0SET_LEDDRV0ON_Min (0x0UL)    /*!< Min enumerator value of LEDDRV0ON field.                             */
  #define LEDDRV_LEDDRV0SET_LEDDRV0ON_Max (0x1UL)    /*!< Max enumerator value of LEDDRV0ON field.                             */
  #define LEDDRV_LEDDRV0SET_LEDDRV0ON_NOEFFECT (0x0UL) /*!< No effect                                                          */
  #define LEDDRV_LEDDRV0SET_LEDDRV0ON_SET (0x1UL)    /*!< Turns On LED0 if LEDDRVMODESEL = HOST                                */


/* LEDDRV_LEDDRV0CLR: Turn LED0 Off */
  #define LEDDRV_LEDDRV0CLR_ResetValue (0x00UL)      /*!< Reset value of LEDDRV0CLR register.                                  */

/* LEDDRV0OFF @Bit 0 : Set LED0 to be Off */
  #define LEDDRV_LEDDRV0CLR_LEDDRV0OFF_Pos (0UL)     /*!< Position of LEDDRV0OFF field.                                        */
  #define LEDDRV_LEDDRV0CLR_LEDDRV0OFF_Msk (0x1UL << LEDDRV_LEDDRV0CLR_LEDDRV0OFF_Pos) /*!< Bit mask of LEDDRV0OFF field.      */
  #define LEDDRV_LEDDRV0CLR_LEDDRV0OFF_Min (0x0UL)   /*!< Min enumerator value of LEDDRV0OFF field.                            */
  #define LEDDRV_LEDDRV0CLR_LEDDRV0OFF_Max (0x1UL)   /*!< Max enumerator value of LEDDRV0OFF field.                            */
  #define LEDDRV_LEDDRV0CLR_LEDDRV0OFF_NOEFFECT (0x0UL) /*!< No effect                                                         */
  #define LEDDRV_LEDDRV0CLR_LEDDRV0OFF_CLR (0x1UL)   /*!< Turns Off LED0 if LEDDRVMODESEL = HOST                               */


/* LEDDRV_LEDDRV1SET: Turn LED1 On */
  #define LEDDRV_LEDDRV1SET_ResetValue (0x00UL)      /*!< Reset value of LEDDRV1SET register.                                  */

/* LEDDRV1ON @Bit 0 : Set LED1 to be On */
  #define LEDDRV_LEDDRV1SET_LEDDRV1ON_Pos (0UL)      /*!< Position of LEDDRV1ON field.                                         */
  #define LEDDRV_LEDDRV1SET_LEDDRV1ON_Msk (0x1UL << LEDDRV_LEDDRV1SET_LEDDRV1ON_Pos) /*!< Bit mask of LEDDRV1ON field.         */
  #define LEDDRV_LEDDRV1SET_LEDDRV1ON_Min (0x0UL)    /*!< Min enumerator value of LEDDRV1ON field.                             */
  #define LEDDRV_LEDDRV1SET_LEDDRV1ON_Max (0x1UL)    /*!< Max enumerator value of LEDDRV1ON field.                             */
  #define LEDDRV_LEDDRV1SET_LEDDRV1ON_NOEFFECT (0x0UL) /*!< No effect                                                          */
  #define LEDDRV_LEDDRV1SET_LEDDRV1ON_SET (0x1UL)    /*!< Turns On LED1 if LEDDRVMODESEL = HOST                                */


/* LEDDRV_LEDDRV1CLR: Turn LED1 Off */
  #define LEDDRV_LEDDRV1CLR_ResetValue (0x00UL)      /*!< Reset value of LEDDRV1CLR register.                                  */

/* LEDDRV1OFF @Bit 0 : Set LED1 to be Off */
  #define LEDDRV_LEDDRV1CLR_LEDDRV1OFF_Pos (0UL)     /*!< Position of LEDDRV1OFF field.                                        */
  #define LEDDRV_LEDDRV1CLR_LEDDRV1OFF_Msk (0x1UL << LEDDRV_LEDDRV1CLR_LEDDRV1OFF_Pos) /*!< Bit mask of LEDDRV1OFF field.      */
  #define LEDDRV_LEDDRV1CLR_LEDDRV1OFF_Min (0x0UL)   /*!< Min enumerator value of LEDDRV1OFF field.                            */
  #define LEDDRV_LEDDRV1CLR_LEDDRV1OFF_Max (0x1UL)   /*!< Max enumerator value of LEDDRV1OFF field.                            */
  #define LEDDRV_LEDDRV1CLR_LEDDRV1OFF_NOEFFECT (0x0UL) /*!< No effect                                                         */
  #define LEDDRV_LEDDRV1CLR_LEDDRV1OFF_CLR (0x1UL)   /*!< Turns Off LED1 if LEDDRVMODESEL = HOST                               */


/* LEDDRV_LEDDRV2SET: Turn LED2 On */
  #define LEDDRV_LEDDRV2SET_ResetValue (0x00UL)      /*!< Reset value of LEDDRV2SET register.                                  */

/* LEDDRV2ON @Bit 0 : Set LED2 to be On */
  #define LEDDRV_LEDDRV2SET_LEDDRV2ON_Pos (0UL)      /*!< Position of LEDDRV2ON field.                                         */
  #define LEDDRV_LEDDRV2SET_LEDDRV2ON_Msk (0x1UL << LEDDRV_LEDDRV2SET_LEDDRV2ON_Pos) /*!< Bit mask of LEDDRV2ON field.         */
  #define LEDDRV_LEDDRV2SET_LEDDRV2ON_Min (0x0UL)    /*!< Min enumerator value of LEDDRV2ON field.                             */
  #define LEDDRV_LEDDRV2SET_LEDDRV2ON_Max (0x1UL)    /*!< Max enumerator value of LEDDRV2ON field.                             */
  #define LEDDRV_LEDDRV2SET_LEDDRV2ON_NOEFFECT (0x0UL) /*!< No effect                                                          */
  #define LEDDRV_LEDDRV2SET_LEDDRV2ON_SET (0x1UL)    /*!< Turns On LED2 if LEDDRVMODESEL = HOST                                */


/* LEDDRV_LEDDRV2CLR: Turn LED2 Off */
  #define LEDDRV_LEDDRV2CLR_ResetValue (0x00UL)      /*!< Reset value of LEDDRV2CLR register.                                  */

/* LEDDRV2OFF @Bit 0 : Set LED2 to be Off */
  #define LEDDRV_LEDDRV2CLR_LEDDRV2OFF_Pos (0UL)     /*!< Position of LEDDRV2OFF field.                                        */
  #define LEDDRV_LEDDRV2CLR_LEDDRV2OFF_Msk (0x1UL << LEDDRV_LEDDRV2CLR_LEDDRV2OFF_Pos) /*!< Bit mask of LEDDRV2OFF field.      */
  #define LEDDRV_LEDDRV2CLR_LEDDRV2OFF_Min (0x0UL)   /*!< Min enumerator value of LEDDRV2OFF field.                            */
  #define LEDDRV_LEDDRV2CLR_LEDDRV2OFF_Max (0x1UL)   /*!< Max enumerator value of LEDDRV2OFF field.                            */
  #define LEDDRV_LEDDRV2CLR_LEDDRV2OFF_NOEFFECT (0x0UL) /*!< No effect                                                         */
  #define LEDDRV_LEDDRV2CLR_LEDDRV2OFF_CLR (0x1UL)   /*!< Turns Off LED2 if LEDDRVMODESEL = HOST                               */


#endif                                               /*!< !defined(__ASSEMBLER__) && !defined(__ASSEMBLY__)                    */

/* =========================================================================================================================== */
/* ================                                          SHPHLD                                          ================ */
/* =========================================================================================================================== */

#if !defined(__ASSEMBLER__) && !defined(__ASSEMBLY__) /*!< Ignore C structs for assembly code.                                 */
/* ====================================================== Struct SHPHLD ====================================================== */
/**
  * @brief nPM1304 SHPHLD registers
  */
  typedef struct {                                   /*!< SHPHLD Structure                                                     */
    __OM uint8_t  TASKENTERHIBERNATE;                /*!< (@ 0x00000000) Enter Hibernate                                       */
    __OM uint8_t  TASKSHPHLDCFGSTROBE;               /*!< (@ 0x00000001) Load SHPHLD configuration                             */
    __OM uint8_t  TASKENTERSHIPMODE;                 /*!< (@ 0x00000002) Enter Ship mode                                       */
    __OM uint8_t  TASKRESETCFG;                      /*!< (@ 0x00000003) Reset configuration                                   */
    __IOM uint8_t SHPHLDCONFIG;                      /*!< (@ 0x00000004) Configuration for SHPHLD                              */
    __IM uint8_t  SHPHLDSTATUS;                      /*!< (@ 0x00000005) Status of the SHPHLD pin                              */
    __IOM uint8_t LPRESETCONFIG;                     /*!< (@ 0x00000006) Long press reset configuration                        */
  } NPM_SHPHLD_Type;                                 /*!< Size = 7 (0x007)                                                     */

/* SHPHLD_TASKENTERHIBERNATE: Enter Hibernate */
  #define SHPHLD_TASKENTERHIBERNATE_ResetValue (0x00UL) /*!< Reset value of TASKENTERHIBERNATE register.                       */

/* TASKENTERHIBERNATE @Bit 0 : Enter Hibernate (Ship mode with Wake-up timer) */
  #define SHPHLD_TASKENTERHIBERNATE_TASKENTERHIBERNATE_Pos (0UL) /*!< Position of TASKENTERHIBERNATE field.                    */
  #define SHPHLD_TASKENTERHIBERNATE_TASKENTERHIBERNATE_Msk (0x1UL << SHPHLD_TASKENTERHIBERNATE_TASKENTERHIBERNATE_Pos) /*!< Bit
                                                                            mask of TASKENTERHIBERNATE field.*/                   
  #define SHPHLD_TASKENTERHIBERNATE_TASKENTERHIBERNATE_Min (0x0UL) /*!< Min enumerator value of TASKENTERHIBERNATE field.      */
  #define SHPHLD_TASKENTERHIBERNATE_TASKENTERHIBERNATE_Max (0x1UL) /*!< Max enumerator value of TASKENTERHIBERNATE field.      */
  #define SHPHLD_TASKENTERHIBERNATE_TASKENTERHIBERNATE_NOEFFECT (0x0UL) /*!< No effect                                         */
  #define SHPHLD_TASKENTERHIBERNATE_TASKENTERHIBERNATE_TRIGGER (0x1UL) /*!< Trigger task                                       */


/* SHPHLD_TASKSHPHLDCFGSTROBE: Load SHPHLD configuration */
  #define SHPHLD_TASKSHPHLDCFGSTROBE_ResetValue (0x00UL) /*!< Reset value of TASKSHPHLDCFGSTROBE register.                     */

/* TASKSHPHLDCONFIGSTROBE @Bit 0 : Load the SHPHLD configuration */
  #define SHPHLD_TASKSHPHLDCFGSTROBE_TASKSHPHLDCONFIGSTROBE_Pos (0UL) /*!< Position of TASKSHPHLDCONFIGSTROBE field.           */
  #define SHPHLD_TASKSHPHLDCFGSTROBE_TASKSHPHLDCONFIGSTROBE_Msk (0x1UL << SHPHLD_TASKSHPHLDCFGSTROBE_TASKSHPHLDCONFIGSTROBE_Pos)
                                                                            /*!< Bit mask of TASKSHPHLDCONFIGSTROBE field.*/      
  #define SHPHLD_TASKSHPHLDCFGSTROBE_TASKSHPHLDCONFIGSTROBE_Min (0x0UL) /*!< Min enumerator value of TASKSHPHLDCONFIGSTROBE
                                                                            field.*/                                              
  #define SHPHLD_TASKSHPHLDCFGSTROBE_TASKSHPHLDCONFIGSTROBE_Max (0x1UL) /*!< Max enumerator value of TASKSHPHLDCONFIGSTROBE
                                                                            field.*/                                              
  #define SHPHLD_TASKSHPHLDCFGSTROBE_TASKSHPHLDCONFIGSTROBE_NOEFFECT (0x0UL) /*!< No effect                                    */
  #define SHPHLD_TASKSHPHLDCFGSTROBE_TASKSHPHLDCONFIGSTROBE_TRIGGER (0x1UL) /*!< Strobe config                                 */


/* SHPHLD_TASKENTERSHIPMODE: Enter Ship mode */
  #define SHPHLD_TASKENTERSHIPMODE_ResetValue (0x00UL) /*!< Reset value of TASKENTERSHIPMODE register.                         */

/* TASKENTERSHIPMODE @Bit 0 : Enter Ship mode (without Wake-up timer) */
  #define SHPHLD_TASKENTERSHIPMODE_TASKENTERSHIPMODE_Pos (0UL) /*!< Position of TASKENTERSHIPMODE field.                       */
  #define SHPHLD_TASKENTERSHIPMODE_TASKENTERSHIPMODE_Msk (0x1UL << SHPHLD_TASKENTERSHIPMODE_TASKENTERSHIPMODE_Pos) /*!< Bit mask
                                                                            of TASKENTERSHIPMODE field.*/                         
  #define SHPHLD_TASKENTERSHIPMODE_TASKENTERSHIPMODE_Min (0x0UL) /*!< Min enumerator value of TASKENTERSHIPMODE field.         */
  #define SHPHLD_TASKENTERSHIPMODE_TASKENTERSHIPMODE_Max (0x1UL) /*!< Max enumerator value of TASKENTERSHIPMODE field.         */
  #define SHPHLD_TASKENTERSHIPMODE_TASKENTERSHIPMODE_NOEFFECT (0x0UL) /*!< No effect                                           */
  #define SHPHLD_TASKENTERSHIPMODE_TASKENTERSHIPMODE_TRIGGER (0x1UL) /*!< Trigger task                                         */


/* SHPHLD_TASKRESETCFG: Reset configuration */
  #define SHPHLD_TASKRESETCFG_ResetValue (0x00UL)    /*!< Reset value of TASKRESETCFG register.                                */

/* TASKSHPHLDRSTCONFIG @Bit 0 : Reset configuration settings */
  #define SHPHLD_TASKRESETCFG_TASKSHPHLDRSTCONFIG_Pos (0UL) /*!< Position of TASKSHPHLDRSTCONFIG field.                        */
  #define SHPHLD_TASKRESETCFG_TASKSHPHLDRSTCONFIG_Msk (0x1UL << SHPHLD_TASKRESETCFG_TASKSHPHLDRSTCONFIG_Pos) /*!< Bit mask of
                                                                            TASKSHPHLDRSTCONFIG field.*/                          
  #define SHPHLD_TASKRESETCFG_TASKSHPHLDRSTCONFIG_Min (0x0UL) /*!< Min enumerator value of TASKSHPHLDRSTCONFIG field.          */
  #define SHPHLD_TASKRESETCFG_TASKSHPHLDRSTCONFIG_Max (0x1UL) /*!< Max enumerator value of TASKSHPHLDRSTCONFIG field.          */
  #define SHPHLD_TASKRESETCFG_TASKSHPHLDRSTCONFIG_NOEFFECT (0x0UL) /*!< No effect                                              */
  #define SHPHLD_TASKRESETCFG_TASKSHPHLDRSTCONFIG_TRIGGER (0x1UL) /*!< Reset                                                   */


/* SHPHLD_SHPHLDCONFIG: Configuration for SHPHLD */
  #define SHPHLD_SHPHLDCONFIG_ResetValue (0x03UL)    /*!< Reset value of SHPHLDCONFIG register.                                */

/* SHPHLDTIM @Bits 0..2 : Configuration for SHPHLD debounce */
  #define SHPHLD_SHPHLDCONFIG_SHPHLDTIM_Pos (0UL)    /*!< Position of SHPHLDTIM field.                                         */
  #define SHPHLD_SHPHLDCONFIG_SHPHLDTIM_Msk (0x7UL << SHPHLD_SHPHLDCONFIG_SHPHLDTIM_Pos) /*!< Bit mask of SHPHLDTIM field.     */
  #define SHPHLD_SHPHLDCONFIG_SHPHLDTIM_Min (0x0UL)  /*!< Min enumerator value of SHPHLDTIM field.                             */
  #define SHPHLD_SHPHLDCONFIG_SHPHLDTIM_Max (0x7UL)  /*!< Max enumerator value of SHPHLDTIM field.                             */
  #define SHPHLD_SHPHLDCONFIG_SHPHLDTIM_16ms (0x0UL) /*!< 16 ms                                                                */
  #define SHPHLD_SHPHLDCONFIG_SHPHLDTIM_32ms (0x1UL) /*!< 32 ms                                                                */
  #define SHPHLD_SHPHLDCONFIG_SHPHLDTIM_64ms (0x2UL) /*!< 64 ms                                                                */
  #define SHPHLD_SHPHLDCONFIG_SHPHLDTIM_96ms (0x3UL) /*!< 96 ms (default)                                                      */
  #define SHPHLD_SHPHLDCONFIG_SHPHLDTIM_304ms (0x4UL) /*!< 304 ms                                                              */
  #define SHPHLD_SHPHLDCONFIG_SHPHLDTIM_608ms (0x5UL) /*!< 608 ms                                                              */
  #define SHPHLD_SHPHLDCONFIG_SHPHLDTIM_1008ms (0x6UL) /*!< 1008 ms                                                            */
  #define SHPHLD_SHPHLDCONFIG_SHPHLDTIM_3008ms (0x7UL) /*!< 3008 ms                                                            */

/* SHPHLDPOLARITY @Bit 3 : Polarity of shphld */
  #define SHPHLD_SHPHLDCONFIG_SHPHLDPOLARITY_Pos (3UL) /*!< Position of SHPHLDPOLARITY field.                                  */
  #define SHPHLD_SHPHLDCONFIG_SHPHLDPOLARITY_Msk (0x1UL << SHPHLD_SHPHLDCONFIG_SHPHLDPOLARITY_Pos) /*!< Bit mask of
                                                                            SHPHLDPOLARITY field.*/
  #define SHPHLD_SHPHLDCONFIG_SHPHLDPOLARITY_Min (0x0UL) /*!< Min enumerator value of SHPHLDPOLARITY field.                    */
  #define SHPHLD_SHPHLDCONFIG_SHPHLDPOLARITY_Max (0x1UL) /*!< Max enumerator value of SHPHLDPOLARITY field.                    */
  #define SHPHLD_SHPHLDCONFIG_SHPHLDPOLARITY_NOEFFECT (0x0UL) /*!< no effect                                                   */
  #define SHPHLD_SHPHLDCONFIG_SHPHLDPOLARITY_INVERT (0x1UL) /*!< shphld inverted                                               */


/* SHPHLD_SHPHLDSTATUS: Status of the SHPHLD pin */
  #define SHPHLD_SHPHLDSTATUS_ResetValue (0x00UL)    /*!< Reset value of SHPHLDSTATUS register.                                */

/* SHPHLDPINSTATUS @Bit 0 : SHPHLD pin status */
  #define SHPHLD_SHPHLDSTATUS_SHPHLDPINSTATUS_Pos (0UL) /*!< Position of SHPHLDPINSTATUS field.                                */
  #define SHPHLD_SHPHLDSTATUS_SHPHLDPINSTATUS_Msk (0x1UL << SHPHLD_SHPHLDSTATUS_SHPHLDPINSTATUS_Pos) /*!< Bit mask of
                                                                            SHPHLDPINSTATUS field.*/                              
  #define SHPHLD_SHPHLDSTATUS_SHPHLDPINSTATUS_Min (0x0UL) /*!< Min enumerator value of SHPHLDPINSTATUS field.                  */
  #define SHPHLD_SHPHLDSTATUS_SHPHLDPINSTATUS_Max (0x1UL) /*!< Max enumerator value of SHPHLDPINSTATUS field.                  */
  #define SHPHLD_SHPHLDSTATUS_SHPHLDPINSTATUS_LOW (0x0UL) /*!< Low                                                             */
  #define SHPHLD_SHPHLDSTATUS_SHPHLDPINSTATUS_HIGH (0x1UL) /*!< High                                                           */


/* SHPHLD_LPRESETCONFIG: Long press reset configuration */
  #define SHPHLD_LPRESETCONFIG_ResetValue (0x00UL)   /*!< Reset value of LPRESETCONFIG register.                               */

/* LONGTIMRESETDIS @Bit 0 : Long press reset disable */
  #define SHPHLD_LPRESETCONFIG_LONGTIMRESETDIS_Pos (0UL) /*!< Position of LONGTIMRESETDIS field.                               */
  #define SHPHLD_LPRESETCONFIG_LONGTIMRESETDIS_Msk (0x1UL << SHPHLD_LPRESETCONFIG_LONGTIMRESETDIS_Pos) /*!< Bit mask of
                                                                            LONGTIMRESETDIS field.*/                              
  #define SHPHLD_LPRESETCONFIG_LONGTIMRESETDIS_Min (0x0UL) /*!< Min enumerator value of LONGTIMRESETDIS field.                 */
  #define SHPHLD_LPRESETCONFIG_LONGTIMRESETDIS_Max (0x1UL) /*!< Max enumerator value of LONGTIMRESETDIS field.                 */
  #define SHPHLD_LPRESETCONFIG_LONGTIMRESETDIS_ENABLED (0x0UL) /*!< Long press reset enabled                                   */
  #define SHPHLD_LPRESETCONFIG_LONGTIMRESETDIS_DISABLED (0x1UL) /*!< Long press reset disabled                                 */

/* LONGTIMTWOBUTTONSEL @Bit 1 : Select one (default) or two buttons to perform long press reset */
  #define SHPHLD_LPRESETCONFIG_LONGTIMTWOBUTTONSEL_Pos (1UL) /*!< Position of LONGTIMTWOBUTTONSEL field.                       */
  #define SHPHLD_LPRESETCONFIG_LONGTIMTWOBUTTONSEL_Msk (0x1UL << SHPHLD_LPRESETCONFIG_LONGTIMTWOBUTTONSEL_Pos) /*!< Bit mask of
                                                                            LONGTIMTWOBUTTONSEL field.*/                          
  #define SHPHLD_LPRESETCONFIG_LONGTIMTWOBUTTONSEL_Min (0x0UL) /*!< Min enumerator value of LONGTIMTWOBUTTONSEL field.         */
  #define SHPHLD_LPRESETCONFIG_LONGTIMTWOBUTTONSEL_Max (0x1UL) /*!< Max enumerator value of LONGTIMTWOBUTTONSEL field.         */
  #define SHPHLD_LPRESETCONFIG_LONGTIMTWOBUTTONSEL_SHPHLD (0x0UL) /*!< One button (SHPHLD)                                     */
  #define SHPHLD_LPRESETCONFIG_LONGTIMTWOBUTTONSEL_SHPHLDGPIO0 (0x1UL) /*!< Two buttons (SHPHLD and GPIO0)                     */


#endif                                               /*!< !defined(__ASSEMBLER__) && !defined(__ASSEMBLY__)                    */

/* =========================================================================================================================== */
/* ================                                           FICR                                           ================ */
/* =========================================================================================================================== */

#if !defined(__ASSEMBLER__) && !defined(__ASSEMBLY__) /*!< Ignore C structs for assembly code.                                 */
/* ======================================================= Struct FICR ======================================================= */
/**
  * @brief FICR register map
  */
  typedef struct {                                   /*!< FICR Structure                                                       */
    __IM uint8_t  RESERVED[61];
    __IM uint8_t  VBUSINILIM0OTP;                    /*!< (@ 0x0000003D) Configure input current limit                         */
    __IM uint8_t  VBUSINILIMSTARTUPOTP;              /*!< (@ 0x0000003E) Configure input current limit for startup             */
  } NPM_FICR_Type;                                   /*!< Size = 63 (0x03F)                                                    */

/* FICR_VBUSINILIM0OTP: Configure input current limit */
  #define FICR_VBUSINILIM0OTP_ResetValue (0x00UL)    /*!< Reset value of VBUSINILIM0OTP register.                              */

/* VBUSINILIM0OTP @Bits 0..3 : Input current limit for VBUS selected by host */
  #define FICR_VBUSINILIM0OTP_VBUSINILIM0OTP_Pos (0UL) /*!< Position of VBUSINILIM0OTP field.                                  */
  #define FICR_VBUSINILIM0OTP_VBUSINILIM0OTP_Msk (0xFUL << FICR_VBUSINILIM0OTP_VBUSINILIM0OTP_Pos) /*!< Bit mask of
                                                                            VBUSINILIM0OTP field.*/                               
  #define FICR_VBUSINILIM0OTP_VBUSINILIM0OTP_Min (0x0UL) /*!< Min enumerator value of VBUSINILIM0OTP field.                    */
  #define FICR_VBUSINILIM0OTP_VBUSINILIM0OTP_Max (0xFUL) /*!< Max enumerator value of VBUSINILIM0OTP field.                    */
  #define FICR_VBUSINILIM0OTP_VBUSINILIM0OTP_500MA0 (0x0UL) /*!< 500 mA                                                        */
  #define FICR_VBUSINILIM0OTP_VBUSINILIM0OTP_100MA (0x1UL) /*!< 100 mA                                                         */
  #define FICR_VBUSINILIM0OTP_VBUSINILIM0OTP_200MA (0x2UL) /*!< 200 mA                                                         */
  #define FICR_VBUSINILIM0OTP_VBUSINILIM0OTP_300MA (0x3UL) /*!< 300 mA                                                         */
  #define FICR_VBUSINILIM0OTP_VBUSINILIM0OTP_400MA (0x4UL) /*!< 400 mA                                                         */
  #define FICR_VBUSINILIM0OTP_VBUSINILIM0OTP_500MA (0x5UL) /*!< 500 mA                                                         */
  #define FICR_VBUSINILIM0OTP_VBUSINILIM0OTP_600MA (0x6UL) /*!< 600 mA                                                         */
  #define FICR_VBUSINILIM0OTP_VBUSINILIM0OTP_700MA (0x7UL) /*!< 700 mA                                                         */
  #define FICR_VBUSINILIM0OTP_VBUSINILIM0OTP_800MA (0x8UL) /*!< 800 mA                                                         */
  #define FICR_VBUSINILIM0OTP_VBUSINILIM0OTP_900MA (0x9UL) /*!< 900 mA                                                         */
  #define FICR_VBUSINILIM0OTP_VBUSINILIM0OTP_1000MA (0xAUL) /*!< 1000 mA                                                       */
  #define FICR_VBUSINILIM0OTP_VBUSINILIM0OTP_1100MA (0xBUL) /*!< 1100 mA                                                       */
  #define FICR_VBUSINILIM0OTP_VBUSINILIM0OTP_1200MA (0xCUL) /*!< 1200 mA                                                       */
  #define FICR_VBUSINILIM0OTP_VBUSINILIM0OTP_1300MA (0xDUL) /*!< 1300 mA                                                       */
  #define FICR_VBUSINILIM0OTP_VBUSINILIM0OTP_1400MA (0xEUL) /*!< 1400 mA                                                       */
  #define FICR_VBUSINILIM0OTP_VBUSINILIM0OTP_1500MA (0xFUL) /*!< 1500 mA                                                       */


/* FICR_VBUSINILIMSTARTUPOTP: Configure input current limit for startup */
  #define FICR_VBUSINILIMSTARTUPOTP_ResetValue (0x00UL) /*!< Reset value of VBUSINILIMSTARTUPOTP register.                     */

/* VBUSINILIMSTARTUPOTP @Bits 0..3 : Default input current limit for VBUS */
  #define FICR_VBUSINILIMSTARTUPOTP_VBUSINILIMSTARTUPOTP_Pos (0UL) /*!< Position of VBUSINILIMSTARTUPOTP field.                */
  #define FICR_VBUSINILIMSTARTUPOTP_VBUSINILIMSTARTUPOTP_Msk (0xFUL << FICR_VBUSINILIMSTARTUPOTP_VBUSINILIMSTARTUPOTP_Pos) /*!<
                                                                            Bit mask of VBUSINILIMSTARTUPOTP field.*/             
  #define FICR_VBUSINILIMSTARTUPOTP_VBUSINILIMSTARTUPOTP_Min (0x0UL) /*!< Min enumerator value of VBUSINILIMSTARTUPOTP field.  */
  #define FICR_VBUSINILIMSTARTUPOTP_VBUSINILIMSTARTUPOTP_Max (0xFUL) /*!< Max enumerator value of VBUSINILIMSTARTUPOTP field.  */
  #define FICR_VBUSINILIMSTARTUPOTP_VBUSINILIMSTARTUPOTP_500MA0 (0x0UL) /*!< 500 mA                                            */
  #define FICR_VBUSINILIMSTARTUPOTP_VBUSINILIMSTARTUPOTP_100MA (0x1UL) /*!< 100 mA                                             */
  #define FICR_VBUSINILIMSTARTUPOTP_VBUSINILIMSTARTUPOTP_200MA (0x2UL) /*!< 200 mA                                             */
  #define FICR_VBUSINILIMSTARTUPOTP_VBUSINILIMSTARTUPOTP_300MA (0x3UL) /*!< 300 mA                                             */
  #define FICR_VBUSINILIMSTARTUPOTP_VBUSINILIMSTARTUPOTP_400MA (0x4UL) /*!< 400 mA                                             */
  #define FICR_VBUSINILIMSTARTUPOTP_VBUSINILIMSTARTUPOTP_500MA (0x5UL) /*!< 500 mA                                             */
  #define FICR_VBUSINILIMSTARTUPOTP_VBUSINILIMSTARTUPOTP_600MA (0x6UL) /*!< 600 mA                                             */
  #define FICR_VBUSINILIMSTARTUPOTP_VBUSINILIMSTARTUPOTP_700MA (0x7UL) /*!< 700 mA                                             */
  #define FICR_VBUSINILIMSTARTUPOTP_VBUSINILIMSTARTUPOTP_800MA (0x8UL) /*!< 800 mA                                             */
  #define FICR_VBUSINILIMSTARTUPOTP_VBUSINILIMSTARTUPOTP_900MA (0x9UL) /*!< 900 mA                                             */
  #define FICR_VBUSINILIMSTARTUPOTP_VBUSINILIMSTARTUPOTP_1000MA (0xAUL) /*!< 1000 mA                                           */
  #define FICR_VBUSINILIMSTARTUPOTP_VBUSINILIMSTARTUPOTP_1100MA (0xBUL) /*!< 1100 mA                                           */
  #define FICR_VBUSINILIMSTARTUPOTP_VBUSINILIMSTARTUPOTP_1200MA (0xCUL) /*!< 1200 mA                                           */
  #define FICR_VBUSINILIMSTARTUPOTP_VBUSINILIMSTARTUPOTP_1300MA (0xDUL) /*!< 1300 mA                                           */
  #define FICR_VBUSINILIMSTARTUPOTP_VBUSINILIMSTARTUPOTP_1400MA (0xEUL) /*!< 1400 mA                                           */
  #define FICR_VBUSINILIMSTARTUPOTP_VBUSINILIMSTARTUPOTP_1500MA (0xFUL) /*!< 1500 mA                                           */


#endif                                               /*!< !defined(__ASSEMBLER__) && !defined(__ASSEMBLY__)                    */

/* =========================================================================================================================== */
/* ================                                          ERRLOG                                          ================ */
/* =========================================================================================================================== */

#if !defined(__ASSEMBLER__) && !defined(__ASSEMBLY__) /*!< Ignore C structs for assembly code.                                 */
/* ====================================================== Struct ERRLOG ====================================================== */
/**
  * @brief nPM1304 ERRLOG registers
  */
  typedef struct {                                   /*!< ERRLOG Structure                                                     */
    __OM uint8_t  TASKCLRERRLOG;                     /*!< (@ 0x00000000) Task to clear the Errlog registers                    */
    __IOM uint8_t SCRATCH0;                          /*!< (@ 0x00000001) Boot monitor control and scratch register 0           */
    __IOM uint8_t SCRATCH1;                          /*!< (@ 0x00000002) Scratch register 1                                    */
    __IM uint8_t  RSTCAUSE;                          /*!< (@ 0x00000003) Reset reasons. Cleared with TASKCLRERRLOG             */
    __IM uint8_t  CHARGERERRREASON;                  /*!< (@ 0x00000004) Error log for charger. Cleared with TASKCLRERRLOG     */
    __IM uint8_t  CHARGERERRSENSOR;                  /*!< (@ 0x00000005) Error log for charger. Cleared with TASKCLRERRLOG     */
  } NPM_ERRLOG_Type;                                 /*!< Size = 6 (0x006)                                                     */

/* ERRLOG_TASKCLRERRLOG: Task to clear the Errlog registers */
  #define ERRLOG_TASKCLRERRLOG_ResetValue (0x00UL)   /*!< Reset value of TASKCLRERRLOG register.                               */

/* TASKCLRERRLOG @Bit 0 : Clear registers RSTCAUSE, CHARGERERRREASON and CHARGERERRSENSOR */
  #define ERRLOG_TASKCLRERRLOG_TASKCLRERRLOG_Pos (0UL) /*!< Position of TASKCLRERRLOG field.                                   */
  #define ERRLOG_TASKCLRERRLOG_TASKCLRERRLOG_Msk (0x1UL << ERRLOG_TASKCLRERRLOG_TASKCLRERRLOG_Pos) /*!< Bit mask of
                                                                            TASKCLRERRLOG field.*/                                


/* ERRLOG_SCRATCH0: Boot monitor control and scratch register 0 */
  #define ERRLOG_SCRATCH0_ResetValue (0x00UL)        /*!< Reset value of SCRATCH0 register.                                    */

/* BOOTTIMEREN @Bit 0 : Enable boot monitor timer, only cleared by POR */
  #define ERRLOG_SCRATCH0_BOOTTIMEREN_Pos (0UL)      /*!< Position of BOOTTIMEREN field.                                       */
  #define ERRLOG_SCRATCH0_BOOTTIMEREN_Msk (0x1UL << ERRLOG_SCRATCH0_BOOTTIMEREN_Pos) /*!< Bit mask of BOOTTIMEREN field.       */
  #define ERRLOG_SCRATCH0_BOOTTIMEREN_Min (0x0UL)    /*!< Min enumerator value of BOOTTIMEREN field.                           */
  #define ERRLOG_SCRATCH0_BOOTTIMEREN_Max (0x1UL)    /*!< Max enumerator value of BOOTTIMEREN field.                           */
  #define ERRLOG_SCRATCH0_BOOTTIMEREN_NOBOOTMON (0x0UL) /*!< Boot monitor disable                                              */
  #define ERRLOG_SCRATCH0_BOOTTIMEREN_BOOTMON (0x1UL) /*!< Boot monitor enable                                                 */

/* SCRATCH0 @Bits 1..7 : Scratch register, only cleared by POR */
  #define ERRLOG_SCRATCH0_SCRATCH0_Pos (1UL)         /*!< Position of SCRATCH0 field.                                          */
  #define ERRLOG_SCRATCH0_SCRATCH0_Msk (0x7FUL << ERRLOG_SCRATCH0_SCRATCH0_Pos) /*!< Bit mask of SCRATCH0 field.               */


/* ERRLOG_SCRATCH1: Scratch register 1 */
  #define ERRLOG_SCRATCH1_ResetValue (0x00UL)        /*!< Reset value of SCRATCH1 register.                                    */

/* SCRATCH1 @Bits 0..7 : Scratch register, only cleared by POR */
  #define ERRLOG_SCRATCH1_SCRATCH1_Pos (0UL)         /*!< Position of SCRATCH1 field.                                          */
  #define ERRLOG_SCRATCH1_SCRATCH1_Msk (0xFFUL << ERRLOG_SCRATCH1_SCRATCH1_Pos) /*!< Bit mask of SCRATCH1 field.               */


/* ERRLOG_RSTCAUSE: Reset reasons. Cleared with TASKCLRERRLOG */
  #define ERRLOG_RSTCAUSE_ResetValue (0x00UL)        /*!< Reset value of RSTCAUSE register.                                    */

/* SHIPMODEEXIT @Bit 0 : Reset caused by Ship mode exit */
  #define ERRLOG_RSTCAUSE_SHIPMODEEXIT_Pos (0UL)     /*!< Position of SHIPMODEEXIT field.                                      */
  #define ERRLOG_RSTCAUSE_SHIPMODEEXIT_Msk (0x1UL << ERRLOG_RSTCAUSE_SHIPMODEEXIT_Pos) /*!< Bit mask of SHIPMODEEXIT field.    */
  #define ERRLOG_RSTCAUSE_SHIPMODEEXIT_Min (0x0UL)   /*!< Min enumerator value of SHIPMODEEXIT field.                          */
  #define ERRLOG_RSTCAUSE_SHIPMODEEXIT_Max (0x1UL)   /*!< Max enumerator value of SHIPMODEEXIT field.                          */
  #define ERRLOG_RSTCAUSE_SHIPMODEEXIT_NORST (0x0UL) /*!< No reset                                                             */
  #define ERRLOG_RSTCAUSE_SHIPMODEEXIT_RST (0x1UL)   /*!< Reset activated by Ship mode exit                                    */

/* BOOTMONITORTIMEOUT @Bit 1 : Reset caused by boot monitor timeout */
  #define ERRLOG_RSTCAUSE_BOOTMONITORTIMEOUT_Pos (1UL) /*!< Position of BOOTMONITORTIMEOUT field.                              */
  #define ERRLOG_RSTCAUSE_BOOTMONITORTIMEOUT_Msk (0x1UL << ERRLOG_RSTCAUSE_BOOTMONITORTIMEOUT_Pos) /*!< Bit mask of
                                                                            BOOTMONITORTIMEOUT field.*/                           
  #define ERRLOG_RSTCAUSE_BOOTMONITORTIMEOUT_Min (0x0UL) /*!< Min enumerator value of BOOTMONITORTIMEOUT field.                */
  #define ERRLOG_RSTCAUSE_BOOTMONITORTIMEOUT_Max (0x1UL) /*!< Max enumerator value of BOOTMONITORTIMEOUT field.                */
  #define ERRLOG_RSTCAUSE_BOOTMONITORTIMEOUT_NORST (0x0UL) /*!< No reset                                                       */
  #define ERRLOG_RSTCAUSE_BOOTMONITORTIMEOUT_RST (0x1UL) /*!< Reset activated by boot monitor                                  */

/* WATCHDOGTIMEOUT @Bit 2 : Reset caused by watchdog timeout */
  #define ERRLOG_RSTCAUSE_WATCHDOGTIMEOUT_Pos (2UL)  /*!< Position of WATCHDOGTIMEOUT field.                                   */
  #define ERRLOG_RSTCAUSE_WATCHDOGTIMEOUT_Msk (0x1UL << ERRLOG_RSTCAUSE_WATCHDOGTIMEOUT_Pos) /*!< Bit mask of WATCHDOGTIMEOUT
                                                                            field.*/                                              
  #define ERRLOG_RSTCAUSE_WATCHDOGTIMEOUT_Min (0x0UL) /*!< Min enumerator value of WATCHDOGTIMEOUT field.                      */
  #define ERRLOG_RSTCAUSE_WATCHDOGTIMEOUT_Max (0x1UL) /*!< Max enumerator value of WATCHDOGTIMEOUT field.                      */
  #define ERRLOG_RSTCAUSE_WATCHDOGTIMEOUT_NORST (0x0UL) /*!< No reset                                                          */
  #define ERRLOG_RSTCAUSE_WATCHDOGTIMEOUT_RST (0x1UL) /*!< Reset activated by watchdog                                         */

/* LONGPRESSTIMEOUT @Bit 3 : Reset caused by long press reset */
  #define ERRLOG_RSTCAUSE_LONGPRESSTIMEOUT_Pos (3UL) /*!< Position of LONGPRESSTIMEOUT field.                                  */
  #define ERRLOG_RSTCAUSE_LONGPRESSTIMEOUT_Msk (0x1UL << ERRLOG_RSTCAUSE_LONGPRESSTIMEOUT_Pos) /*!< Bit mask of LONGPRESSTIMEOUT
                                                                            field.*/                                              
  #define ERRLOG_RSTCAUSE_LONGPRESSTIMEOUT_Min (0x0UL) /*!< Min enumerator value of LONGPRESSTIMEOUT field.                    */
  #define ERRLOG_RSTCAUSE_LONGPRESSTIMEOUT_Max (0x1UL) /*!< Max enumerator value of LONGPRESSTIMEOUT field.                    */
  #define ERRLOG_RSTCAUSE_LONGPRESSTIMEOUT_NORST (0x0UL) /*!< No reset                                                         */
  #define ERRLOG_RSTCAUSE_LONGPRESSTIMEOUT_RST (0x1UL) /*!< Long press reset                                                   */

/* THERMALSHUTDOWN @Bit 4 : Reset caused by thermal shutdown (TSD) */
  #define ERRLOG_RSTCAUSE_THERMALSHUTDOWN_Pos (4UL)  /*!< Position of THERMALSHUTDOWN field.                                   */
  #define ERRLOG_RSTCAUSE_THERMALSHUTDOWN_Msk (0x1UL << ERRLOG_RSTCAUSE_THERMALSHUTDOWN_Pos) /*!< Bit mask of THERMALSHUTDOWN
                                                                            field.*/                                              
  #define ERRLOG_RSTCAUSE_THERMALSHUTDOWN_Min (0x0UL) /*!< Min enumerator value of THERMALSHUTDOWN field.                      */
  #define ERRLOG_RSTCAUSE_THERMALSHUTDOWN_Max (0x1UL) /*!< Max enumerator value of THERMALSHUTDOWN field.                      */
  #define ERRLOG_RSTCAUSE_THERMALSHUTDOWN_NORST (0x0UL) /*!< No reset                                                          */
  #define ERRLOG_RSTCAUSE_THERMALSHUTDOWN_RST (0x1UL) /*!< Reset activated by TSD                                              */

/* VSYSLOW @Bit 5 : Reset caused by power failure (POF) */
  #define ERRLOG_RSTCAUSE_VSYSLOW_Pos (5UL)          /*!< Position of VSYSLOW field.                                           */
  #define ERRLOG_RSTCAUSE_VSYSLOW_Msk (0x1UL << ERRLOG_RSTCAUSE_VSYSLOW_Pos) /*!< Bit mask of VSYSLOW field.                   */
  #define ERRLOG_RSTCAUSE_VSYSLOW_Min (0x0UL)        /*!< Min enumerator value of VSYSLOW field.                               */
  #define ERRLOG_RSTCAUSE_VSYSLOW_Max (0x1UL)        /*!< Max enumerator value of VSYSLOW field.                               */
  #define ERRLOG_RSTCAUSE_VSYSLOW_NORST (0x0UL)      /*!< No reset                                                             */
  #define ERRLOG_RSTCAUSE_VSYSLOW_RST (0x1UL)        /*!< Reset activated by POF                                               */

/* SWRESET @Bit 6 : Reset caused by TASKSWRESET */
  #define ERRLOG_RSTCAUSE_SWRESET_Pos (6UL)          /*!< Position of SWRESET field.                                           */
  #define ERRLOG_RSTCAUSE_SWRESET_Msk (0x1UL << ERRLOG_RSTCAUSE_SWRESET_Pos) /*!< Bit mask of SWRESET field.                   */
  #define ERRLOG_RSTCAUSE_SWRESET_Min (0x0UL)        /*!< Min enumerator value of SWRESET field.                               */
  #define ERRLOG_RSTCAUSE_SWRESET_Max (0x1UL)        /*!< Max enumerator value of SWRESET field.                               */
  #define ERRLOG_RSTCAUSE_SWRESET_NORST (0x0UL)      /*!< No reset                                                             */
  #define ERRLOG_RSTCAUSE_SWRESET_RST (0x1UL)        /*!< Reset activated by TASKSWRESET                                       */


/* ERRLOG_CHARGERERRREASON: Error log for charger. Cleared with TASKCLRERRLOG */
  #define ERRLOG_CHARGERERRREASON_ResetValue (0x00UL) /*!< Reset value of CHARGERERRREASON register.                           */

/* NTCSENSORERR @Bit 0 : NTC thermistor sensor error */
  #define ERRLOG_CHARGERERRREASON_NTCSENSORERR_Pos (0UL) /*!< Position of NTCSENSORERR field.                                  */
  #define ERRLOG_CHARGERERRREASON_NTCSENSORERR_Msk (0x1UL << ERRLOG_CHARGERERRREASON_NTCSENSORERR_Pos) /*!< Bit mask of
                                                                            NTCSENSORERR field.*/                                 

/* VBATSENSORERR @Bit 1 : VBAT sensor error */
  #define ERRLOG_CHARGERERRREASON_VBATSENSORERR_Pos (1UL) /*!< Position of VBATSENSORERR field.                                */
  #define ERRLOG_CHARGERERRREASON_VBATSENSORERR_Msk (0x1UL << ERRLOG_CHARGERERRREASON_VBATSENSORERR_Pos) /*!< Bit mask of
                                                                            VBATSENSORERR field.*/                                

/* VBATLOW @Bit 2 : VBAT low error */
  #define ERRLOG_CHARGERERRREASON_VBATLOW_Pos (2UL)  /*!< Position of VBATLOW field.                                           */
  #define ERRLOG_CHARGERERRREASON_VBATLOW_Msk (0x1UL << ERRLOG_CHARGERERRREASON_VBATLOW_Pos) /*!< Bit mask of VBATLOW field.   */

/* VTRICKLE @Bit 3 : Vtrickle error */
  #define ERRLOG_CHARGERERRREASON_VTRICKLE_Pos (3UL) /*!< Position of VTRICKLE field.                                          */
  #define ERRLOG_CHARGERERRREASON_VTRICKLE_Msk (0x1UL << ERRLOG_CHARGERERRREASON_VTRICKLE_Pos) /*!< Bit mask of VTRICKLE field.*/

/* MEASTIMEOUT @Bit 4 : Measurement timeout error */
  #define ERRLOG_CHARGERERRREASON_MEASTIMEOUT_Pos (4UL) /*!< Position of MEASTIMEOUT field.                                    */
  #define ERRLOG_CHARGERERRREASON_MEASTIMEOUT_Msk (0x1UL << ERRLOG_CHARGERERRREASON_MEASTIMEOUT_Pos) /*!< Bit mask of
                                                                            MEASTIMEOUT field.*/                                  

/* CHARGETIMEOUT @Bit 5 : Charge timeout error */
  #define ERRLOG_CHARGERERRREASON_CHARGETIMEOUT_Pos (5UL) /*!< Position of CHARGETIMEOUT field.                                */
  #define ERRLOG_CHARGERERRREASON_CHARGETIMEOUT_Msk (0x1UL << ERRLOG_CHARGERERRREASON_CHARGETIMEOUT_Pos) /*!< Bit mask of
                                                                            CHARGETIMEOUT field.*/                                

/* TRICKLETIMEOUT @Bit 6 : Trickle timeout error */
  #define ERRLOG_CHARGERERRREASON_TRICKLETIMEOUT_Pos (6UL) /*!< Position of TRICKLETIMEOUT field.                              */
  #define ERRLOG_CHARGERERRREASON_TRICKLETIMEOUT_Msk (0x1UL << ERRLOG_CHARGERERRREASON_TRICKLETIMEOUT_Pos) /*!< Bit mask of
                                                                            TRICKLETIMEOUT field.*/                               


/* ERRLOG_CHARGERERRSENSOR: Error log for charger. Cleared with TASKCLRERRLOG */
  #define ERRLOG_CHARGERERRSENSOR_ResetValue (0x00UL) /*!< Reset value of CHARGERERRSENSOR register.                           */

/* SENSORNTCCOLD @Bit 0 : NTC cold region active when error occurs */
  #define ERRLOG_CHARGERERRSENSOR_SENSORNTCCOLD_Pos (0UL) /*!< Position of SENSORNTCCOLD field.                                */
  #define ERRLOG_CHARGERERRSENSOR_SENSORNTCCOLD_Msk (0x1UL << ERRLOG_CHARGERERRSENSOR_SENSORNTCCOLD_Pos) /*!< Bit mask of
                                                                            SENSORNTCCOLD field.*/                                

/* SENSORNTCCOOL @Bit 1 : NTC cool region active when error occurs */
  #define ERRLOG_CHARGERERRSENSOR_SENSORNTCCOOL_Pos (1UL) /*!< Position of SENSORNTCCOOL field.                                */
  #define ERRLOG_CHARGERERRSENSOR_SENSORNTCCOOL_Msk (0x1UL << ERRLOG_CHARGERERRSENSOR_SENSORNTCCOOL_Pos) /*!< Bit mask of
                                                                            SENSORNTCCOOL field.*/                                

/* SENSORNTCWARM @Bit 2 : NTC warm region active when error occurs */
  #define ERRLOG_CHARGERERRSENSOR_SENSORNTCWARM_Pos (2UL) /*!< Position of SENSORNTCWARM field.                                */
  #define ERRLOG_CHARGERERRSENSOR_SENSORNTCWARM_Msk (0x1UL << ERRLOG_CHARGERERRSENSOR_SENSORNTCWARM_Pos) /*!< Bit mask of
                                                                            SENSORNTCWARM field.*/                                

/* SENSORNTCHOT @Bit 3 : NTC hot region active when error occurs */
  #define ERRLOG_CHARGERERRSENSOR_SENSORNTCHOT_Pos (3UL) /*!< Position of SENSORNTCHOT field.                                  */
  #define ERRLOG_CHARGERERRSENSOR_SENSORNTCHOT_Msk (0x1UL << ERRLOG_CHARGERERRSENSOR_SENSORNTCHOT_Pos) /*!< Bit mask of
                                                                            SENSORNTCHOT field.*/                                 

/* SENSORVTERM @Bit 4 : Vterm status when error occurs */
  #define ERRLOG_CHARGERERRSENSOR_SENSORVTERM_Pos (4UL) /*!< Position of SENSORVTERM field.                                    */
  #define ERRLOG_CHARGERERRSENSOR_SENSORVTERM_Msk (0x1UL << ERRLOG_CHARGERERRSENSOR_SENSORVTERM_Pos) /*!< Bit mask of
                                                                            SENSORVTERM field.*/                                  

/* SENSORRECHARGE @Bit 5 : Recharge status when error occurs */
  #define ERRLOG_CHARGERERRSENSOR_SENSORRECHARGE_Pos (5UL) /*!< Position of SENSORRECHARGE field.                              */
  #define ERRLOG_CHARGERERRSENSOR_SENSORRECHARGE_Msk (0x1UL << ERRLOG_CHARGERERRSENSOR_SENSORRECHARGE_Pos) /*!< Bit mask of
                                                                            SENSORRECHARGE field.*/                               

/* SENSORVTRICKLE @Bit 6 : Vtrickle status when error occurs */
  #define ERRLOG_CHARGERERRSENSOR_SENSORVTRICKLE_Pos (6UL) /*!< Position of SENSORVTRICKLE field.                              */
  #define ERRLOG_CHARGERERRSENSOR_SENSORVTRICKLE_Msk (0x1UL << ERRLOG_CHARGERERRSENSOR_SENSORVTRICKLE_Pos) /*!< Bit mask of
                                                                            SENSORVTRICKLE field.*/                               

/* SENSORVBATLOW @Bit 7 : Vbatlow status when error occurs */
  #define ERRLOG_CHARGERERRSENSOR_SENSORVBATLOW_Pos (7UL) /*!< Position of SENSORVBATLOW field.                                */
  #define ERRLOG_CHARGERERRSENSOR_SENSORVBATLOW_Msk (0x1UL << ERRLOG_CHARGERERRSENSOR_SENSORVBATLOW_Pos) /*!< Bit mask of
                                                                            SENSORVBATLOW field.*/                                


#endif                                               /*!< !defined(__ASSEMBLER__) && !defined(__ASSEMBLY__)                    */

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
#elif defined(__ARMCC_VERSION) && (__ARMCC_VERSION >= 6010050)
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
#endif /* NPM1304_H */

