#ifndef NPMX_FIXUPS_H__
#define NPMX_FIXUPS_H__

#if defined(NPM1300_ENG_C)
#define ADC_ADCCONFIG_VBATAUTOENABLE_NOAUTO     (0) ///< Make single measurement when triggered.
#define ADC_ADCCONFIG_VBATAUTOENABLE_AUTOENABLE (1) ///< Make measurement every 1 second.

#define ADC_ADCCONFIG_VBATBURSTENABLE_SINGLEMODE (0) ///< Make a single measurement.
#define ADC_ADCCONFIG_VBATBURSTENABLE_BURSTMODE  (1) ///< Make 4 consecutive measurements.



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
  __IM  uint8_t   RESERVED1[2];
  __IM  uint8_t   ADCIBATMEASSTATUS;                 /*!< (@ 0x00000010) Battery current measurement status                    */
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
  __IM  uint8_t   RESERVED2[9];
  __IOM  uint8_t  ADCIBATMEASEN;                     /*!< (@ 0x00000024) Enable auto IBAT measurement                          */
}NPM_ADC_Type_fixed;                                 /*!< Size = 37 (0x025)                                                    */

#if defined(NPM_ADC)
    #undef NPM_ADC
    #define NPM_ADC ((NPM_ADC_Type_fixed*) NPM_ADC_BASE)
#endif

/* ADC_ADCIBATMEASSTATUS: ADC Battery current measurement status */

/* BCHARGERICHARGE @Bits 0..1 : BCHARGERICHARGE */
#define ADC_ADCIBATMEASSTATUS_BCHARGERICHARGE_Pos (0UL) /*!< Position of BCHARGERICHARGE field.                                  */
#define ADC_ADCIBATMEASSTATUS_BCHARGERICHARGE_Msk (0x03UL << ADC_ADCIBATMEASSTATUS_BCHARGERICHARGE_Pos)
#define ADC_ADCIBATMEASSTATUS_BCHARGERICHARGE_TRICKLE (0) /*!< 10% charge (Trickle) */
#define ADC_ADCIBATMEASSTATUS_BCHARGERICHARGE_LOWTEMP (1) /*!< 50% charge (Low Temp)*/
#define ADC_ADCIBATMEASSTATUS_BCHARGERICHARGE_RFU (2) /*!< RFU (default 10% charge) */
#define ADC_ADCIBATMEASSTATUS_BCHARGERICHARGE_FAST (3) /*!< 100% charge (Fast) */

/* BCHARGERMODE @Bits 2..3 : BCHARGERMODE */
#define ADC_ADCIBATMEASSTATUS_BCHARGERMODE_Pos (2UL) /*!< Position of BCHARGERMODE field.                                  */
#define ADC_ADCIBATMEASSTATUS_BCHARGERMODE_Msk (0x03UL << ADC_ADCIBATMEASSTATUS_BCHARGERMODE_Pos)
#define ADC_ADCIBATMEASSTATUS_BCHARGERMODE_DISCHARGE (1) /*!< Battery is being discharged */
#define ADC_ADCIBATMEASSTATUS_BCHARGERMODE_CHARGE (3)    /*!< Battery is being charged */

/* IBATMEASEINVALID @Bit 4 : IBATMEASEINVALID */
#define ADC_ADCIBATMEASSTATUS_IBATMEASEINVALID_Pos (4UL) /*!< Position of IBATMEASEINVALID field.                                  */
#define ADC_ADCIBATMEASSTATUS_IBATMEASEINVALID_Msk (0x01UL << ADC_ADCIBATMEASSTATUS_IBATMEASEINVALID_Pos)
#define ADC_ADCIBATMEASSTATUS_IBATMEASEINVALID_VALID (0)   /*!< measurement results are valid */
#define ADC_ADCIBATMEASSTATUS_IBATMEASEINVALID_INVALID (1) /*!< measurement results are invalid */

/* ADC_ADCIBATMEASEN: ADC Enable auto IBAT measurement */

/* IBATMEASENABLE @Bit 4 : IBATMEASENABLE */
#define ADC_ADCIBATMEASEN_IBATMEASENABLE_Pos (0UL) /*!< Position of IBATMEASENABLE field.                                  */
#define ADC_ADCIBATMEASEN_IBATMEASENABLE_Msk (0x01UL << ADC_ADCIBATMEASEN_IBATMEASENABLE_Pos)
#define ADC_ADCIBATMEASEN_IBATMEASENABLE_DISABLE (0) /*!< Disable auto IBAT measurement */
#define ADC_ADCIBATMEASEN_IBATMEASENABLE_ENABLE (1)  /*!< Enable auto IBAT measurement */

#endif // defined(NPM1300_ENG_C)

#endif // NPMX_FIXUPS_H__
