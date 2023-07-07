/*
 * Copyright (c) 2023, Nordic Semiconductor ASA
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

#ifndef NPM1300_ENG_C_PERIPHERALS_H__
#define NPM1300_ENG_C_PERIPHERALS_H__

/* ADC */
#define NPMX_PERIPH_ADC_PRESENT 1
#define NPMX_PERIPH_ADC_COUNT   1


#define NPMX_PERIPH_ADC_VFS_VBAT_MV        5000UL   ///< Full scale voltage for battery voltage measurement, from the product specification.
#define NPMX_PERIPH_ADC_VFS_VSYS_MV        6375UL   ///< Full scale voltage for external supply voltage measurement, from the product specification.
#define NPMX_PERIPH_ADC_VFS_VBUS_MV        7500UL   ///< Full scale voltage for supply voltage measurement, from the product specification.
#define NPMX_PERIPH_ADC_DIE_TEMP_OFFSET_MC 394670UL ///< Constant for calculating die temperature value from code, from the product specification.
#define NPMX_PERIPH_ADC_DIE_TEMP_MULT_MC   792UL    ///< Multiplier of die temperature code, from the product specification.
#define NPMX_PERIPH_ADC_BITS_RESOLUTION    1024UL   ///< Bits resolution of 10-bit SAR ADC, from the product specification.
#define NPMX_PERIPH_ADC_RESULT_MSB_SHIFT   0x2UL    ///< ADC data from MSB's register needs to be shifted.

#define NPMX_PERIPH_ADC_MEAS_LSB_MAX_OFFSET  5  ///< Max offset of LSB register from MSB register for values returned by ADC.
#define NPMX_PERIPH_ADC_MEAS_REGISTERS_COUNT 10 ///< Number of registers containing values returned by ADC.


/* BUCK */
#define NPMX_PERIPH_BUCK_PRESENT 1
#define NPMX_PERIPH_BUCK_COUNT   2

/* CHARGER */
#define NPMX_PERIPH_CHARGER_PRESENT 1
#define NPMX_PERIPH_CHARGER_COUNT   1

#define NPMX_PERIPH_CHARGER_ENABLE_LOGIC_POSITIVE_Msk   0x3UL   ///< Used to work with @ref npmx_charger_module_mask_t, two bytes represent BCHGENABLECLR and BCHGENABLESET register.
#define NPMX_PERIPH_CHARGER_ENABLE_LOGIC_POSITIVE_Pos   0x0U    ///< Used to work with @ref npmx_charger_module_mask_t, bytes position shift.

#define NPMX_PERIPH_CHARGER_ENABLE_LOGIC_NEGATIVE_Msk   0x3UL   ///< Used to work with @ref npmx_charger_module_mask_t, two bytes represent BCHGDISABLECLR and BCHGDISABLESET register.
#define NPMX_PERIPH_CHARGER_ENABLE_LOGIC_NEGATIVE_Pos   0x2UL   ///< Used to work with @ref npmx_charger_module_mask_t, bytes position shift.

#define NPMX_PERIPH_CHARGER_ERR_COUNT                   2UL     ///< Errlog errors register count.

#define NPMX_PERIPH_CHARGER_ADC_BITS_RESOLUTION         1024UL  ///< Bits resolution of 10-bit SAR ADC, from the product specification.

#define NPMX_PERIPH_CHARGER_CHARGING_CURRENT_MIN_MA     32UL    ///< Minimum possible charging current in milliamperes, from the product specification.
#define NPMX_PERIPH_CHARGER_CHARGING_CURRENT_MAX_MA     800UL   ///< Maximum possible charging current in milliamperes, from the product specification.
#define NPMX_PERIPH_CHARGER_CHARGING_CURRENT_STEP_MA    2UL     ///< Charging current step in milliamperes, from the product specification.
#define NPMX_PERIPH_CHARGER_CHARGING_CURRENT_DEFAULT    32UL    ///< Default charging current in milliamperes.

#define NPMX_PERIPH_CHARGER_DISCHARGING_CURRENT_MIN_MA  270UL   ///< Minimum possible discharging current in milliamperes, from the product specification.
#define NPMX_PERIPH_CHARGER_DISCHARGING_CURRENT_MAX_MA  1340UL  ///< Maximum possible discharging current in milliamperes, from the product specification.
#define NPMX_PERIPH_CHARGER_DISCHARGING_MULTIPLIER      100UL   ///< Magic number used to calculate discharging code as fixed point number.
#define NPMX_PERIPH_CHARGER_DISCHARGING_CONST           323UL   ///< Magic number used to calculate discharging code.
#define NPMX_PERIPH_CHARGER_DISCHARGING_CURRENT_DEFAULT 1340UL  ///< Default discharging current in milliamperes.

#define NPMX_PERIPH_CHARGER_DIE_TEMPERATURE_CONST_1     39467UL ///< Magic number from "Equation for die temperature limits" in the product specification.
#define NPMX_PERIPH_CHARGER_DIE_TEMPERATURE_CONST_2     317UL   ///< Magic number from "Equation for die temperature limits" in the product specification.
#define NPMX_PERIPH_CHARGER_DIE_TEMPERATURE_MULTIPLIER  100UL   ///< Magic number used to calculate "Equation for die temperature limits" as fixed point number.
#define NPMX_PERIPH_CHARGER_DIE_TEMPERATURE_MAX_VAL     1023UL  ///< Max temperature value as it is a 10-bit value.
#define NPMX_PERIPH_CHARGER_DIE_TEMPERATURE_MSB_SHIFT   0x2UL   ///< Temperature data from MSB's register needs to be shifted.

#define NPMX_PERIPH_CHARGER_CHARGING_CURRENT_DIVIDER    2UL     ///< Magic number used to get charging code from current in milliamperes, from the product specification.
#define NPMX_PERIPH_CHARGER_CHARGING_CODE_MSB_SHIFT     1UL     ///< Shift used to divide charging code value into two bytes.
#define NPMX_PERIPH_CHARGER_DISCHARGING_CODE_MSB_SHIFT  1UL     ///< Shift used to divide discharging code value into two bytes.

#define NPMX_PERIPH_CHARGER_RESISTANCE_MSB_SHIFT        2UL     ///< Shift used to combine two uint8_t registers into one uint16_t variable.

/* ERRLOG */
#define NPMX_PERIPH_ERRLOG_PRESENT          1
#define NPMX_PERIPH_ERRLOG_COUNT            1
#define NPMX_PERIPH_ERRLOG_ERR_COUNT        3
#define NPMX_PERIPH_ERRLOG_SCRATCH0_MAX_VAL 127UL ///< Max value of scratch0 as it occupies 7 bits as part of SCRATCH0 register.

/* GPIO */
#define NPMX_PERIPH_GPIO_PRESENT 1
#define NPMX_PERIPH_GPIO_COUNT   5

/* LDSW */
#define NPMX_PERIPH_LDSW_PRESENT 1
#define NPMX_PERIPH_LDSW_COUNT   2

/* LED */
#define NPMX_PERIPH_LED_PRESENT 1
#define NPMX_PERIPH_LED_COUNT   3

/* POF */
#define NPMX_PERIPH_POF_PRESENT 1
#define NPMX_PERIPH_POF_COUNT   1

/* SHIP */
#define NPMX_PERIPH_SHIP_PRESENT 1
#define NPMX_PERIPH_SHIP_COUNT   1

/* TIMER */
#define NPMX_PERIPH_TIMER_PRESENT 1
#define NPMX_PERIPH_TIMER_COUNT   1

/* VBUSIN */
#define NPMX_PERIPH_VBUSIN_PRESENT 1
#define NPMX_PERIPH_VBUSIN_COUNT   1

#endif // NPM1300_ENG_C_PERIPHERALS_H__
