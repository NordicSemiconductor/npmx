/*

Copyright (c) 2023 - 2023, Nordic Semiconductor ASA

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

#ifndef NPM1300_PERIPHERALS_H
#define NPM1300_PERIPHERALS_H

#ifdef __cplusplus
    extern "C" {
#endif

#include <stdbool.h>
/*abs_max_ratings*/
#define NPM_ABSMAXRATINGS_PRESENT 1
#define NPM_ABSMAXRATINGS_COUNT 1

/*Neutrino MAIN Registers*/
#define NPM_MAIN_PRESENT 1
#define NPM_MAIN_COUNT 1

/*Neutrino SYSTEM registers*/
#define NPM_SYSTEM_PRESENT 1
#define NPM_SYSTEM_COUNT 1

/*Neutrino VBUSIN registers*/
#define NPM_VBUSIN_PRESENT 1
#define NPM_VBUSIN_COUNT 1

/*Neutrino BCHARGER registers*/
#define NPM_BCHARGER_PRESENT 1
#define NPM_BCHARGER_COUNT 1

#define NPM_BCHARGER_ENABLE_LOGIC_POSITIVE_Msk   0x3UL   ///< Used to work with @ref npmx_charger_module_mask_t, two bytes represent BCHGENABLECLR and BCHGENABLESET register.
#define NPM_BCHARGER_ENABLE_LOGIC_POSITIVE_Pos   0x0U    ///< Used to work with @ref npmx_charger_module_mask_t, bytes position shift.

#define NPM_BCHARGER_ENABLE_LOGIC_NEGATIVE_Msk   0x3UL   ///< Used to work with @ref npmx_charger_module_mask_t, two bytes represent BCHGDISABLECLR and BCHGDISABLESET register.
#define NPM_BCHARGER_ENABLE_LOGIC_NEGATIVE_Pos   0x2UL   ///< Used to work with @ref npmx_charger_module_mask_t, bytes position shift.

#define NPM_BCHARGER_ERR_COUNT                   2UL     ///< Errlog errors register count.

#define NPM_BCHARGER_ADC_BITS_RESOLUTION         1024UL  ///< Bits resolution of 10-bit SAR ADC, from the product specification.

#define NPM_BCHARGER_CHARGING_CURRENT_MIN_MA     32UL    ///< Minimum possible charging current in milliamperes, from the product specification.
#define NPM_BCHARGER_CHARGING_CURRENT_MAX_MA     800UL   ///< Maximum possible charging current in milliamperes, from the product specification.
#define NPM_BCHARGER_CHARGING_CURRENT_STEP_MA    2UL     ///< Charging current step in milliamperes, from the product specification.
#define NPM_BCHARGER_CHARGING_CURRENT_DEFAULT    32UL    ///< Default charging current in milliamperes.

#define NPM_BCHARGER_DISCHARGING_CURRENT_MIN_MA  270UL   ///< Minimum possible discharging current in milliamperes, from the product specification.
#define NPM_BCHARGER_DISCHARGING_CURRENT_MAX_MA  1340UL  ///< Maximum possible discharging current in milliamperes, from the product specification.
#define NPM_BCHARGER_DISCHARGING_MULTIPLIER      100UL   ///< Magic number used to calculate discharging code as fixed point number.
#define NPM_BCHARGER_DISCHARGING_CONST           323UL   ///< Magic number used to calculate discharging code.
#define NPM_BCHARGER_DISCHARGING_CURRENT_DEFAULT 1340UL  ///< Default discharging current in milliamperes.

#define NPM_BCHARGER_DIE_TEMPERATURE_CONST_1     3946700UL ///< Magic number from "Equation for die temperature limits" in the product specification.
#define NPM_BCHARGER_DIE_TEMPERATURE_CONST_2     7926UL    ///< Magic number from "Equation for die temperature limits" in the product specification.
#define NPM_BCHARGER_DIE_TEMPERATURE_MULTIPLIER  10000UL   ///< Magic number used to calculate "Equation for die temperature limits" as fixed point number.
#define NPM_BCHARGER_DIE_TEMPERATURE_MAX_VAL     125L      ///< Max temperature value - junction temperature. Reference: nPM1300 OPS v0.7: Chapter: Recommended operating conditions.
#define NPM_BCHARGER_DIE_TEMPERATURE_MIN_VAL     -40L      ///< Min temperature value - junction temperature. Reference: nPM1300 OPS v0.7: Chapter: Recommended operating conditions.
#define NPM_BCHARGER_DIE_TEMPERATURE_MSB_SHIFT   0x2UL     ///< Temperature data from MSB's register needs to be shifted.

#define NPM_BCHARGER_CHARGING_CURRENT_DIVIDER    2UL     ///< Magic number used to get charging code from current in milliamperes, from the product specification.
#define NPM_BCHARGER_CHARGING_CODE_MSB_SHIFT     1UL     ///< Shift used to divide charging code value into two bytes.
#define NPM_BCHARGER_DISCHARGING_CODE_MSB_SHIFT  1UL     ///< Shift used to divide discharging code value into two bytes.

#define NPM_BCHARGER_RESISTANCE_MSB_SHIFT        2UL     ///< Shift used to combine two uint8_t registers into one uint16_t variable.

/*Neutrino BUCK registers*/
#define NPM_BUCK_PRESENT 1
#define NPM_BUCK_COUNT 2

/*Neutrino ADC registers*/
#define NPM_ADC_PRESENT 1
#define NPM_ADC_COUNT 1

#define NPM_ADC_VFS_VBAT_MV      5000UL    ///< Full scale voltage for battery voltage measurement from the product specification.
#define NPM_ADC_VFS_VSYS_MV      6375UL    ///< Full scale voltage for external supply voltage measurement from the product specification.
#define NPM_ADC_VFS_VBUS_MV      7500UL    ///< Full scale voltage for supply voltage measurement from the product specification.
#define NPM_ADC_DIE_TEMP_OFFSET  3946700UL ///< Constant for calculating die temperature value from code from the product specification.
#define NPM_ADC_DIE_TEMP_MULT    7926UL    ///< Multiplier of die temperature code from the product specification.
#define NPM_ADC_BITS_RESOLUTION  1024UL    ///< Bits resolution of 10-bit SAR ADC from the product specification.
#define NPM_ADC_RESULT_MSB_SHIFT 0x2UL     ///< ADC data from MSB's register needs to be shifted.

#define NPM_ADC_MEAS_LSB_MAX_OFFSET  5UL    ///< Max offset of LSB register from MSB register for values returned by ADC.
#define NPM_ADC_MEAS_REGISTERS_COUNT 10UL   ///< Number of registers containing values returned by ADC.

/*Neutrino GPIOS registers*/
#define NPM_GPIOS_PRESENT 1
#define NPM_GPIOS_COUNT 5

/*Neutrino TIMER registers*/
#define NPM_TIMER_PRESENT 1
#define NPM_TIMER_COUNT 1

#define NPM_TIMER_COUNTER_COMPARE_VALUE_MAX 0xFFFFFFUL ///< Timer counter compare max value.

/*Neutrino LDSW registers*/
#define NPM_LDSW_PRESENT 1
#define NPM_LDSW_COUNT 2

/*Neutrino POF registers*/
#define NPM_POF_PRESENT 1
#define NPM_POF_COUNT 1

/*Neutrino LEDDRV registers*/
#define NPM_LEDDRV_PRESENT 1
#define NPM_LEDDRV_COUNT 3

/*Neutrino SHPHLD registers*/
#define NPM_SHPHLD_PRESENT 1
#define NPM_SHPHLD_COUNT 1

/*FICR register map*/
#define NPM_FICR_PRESENT 1
#define NPM_FICR_COUNT 1

/*Neutrino ERRLOG registers*/
#define NPM_ERRLOG_PRESENT 1
#define NPM_ERRLOG_COUNT 1

#define NPM_ERRLOG_ERR_COUNT        3UL
#define NPM_ERRLOG_SCRATCH0_MAX_VAL 127UL ///< Max value of scratch0 as it occupies 7 bits as part of SCRATCH0 register.

#ifdef __cplusplus
}
#endif
#endif /* NPM1300_PERIPHERALS_H */

