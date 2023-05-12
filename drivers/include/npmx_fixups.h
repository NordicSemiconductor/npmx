#ifndef NPMX_FIXUPS_H__
#define NPMX_FIXUPS_H__

#if defined(NPM1300_ENG_B)
#define ADC_ADCCONFIG_VBATAUTOENABLE_NOAUTO     (0) ///< Make single measurement when triggered.
#define ADC_ADCCONFIG_VBATAUTOENABLE_AUTOENABLE (1) ///< Make measurement every 1 second.

#define ADC_ADCCONFIG_VBATBURSTENABLE_SINGLEMODE (0) ///< Make a single measurement.
#define ADC_ADCCONFIG_VBATBURSTENABLE_BURSTMODE  (1) ///< Make 4 consecutive measurements.
#endif // defined(NPM1300_ENG_B)

#endif // NPMX_FIXUPS_H__
