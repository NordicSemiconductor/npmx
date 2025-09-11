# Changelog
All notable changes to this project are documented in this file.

## [1.2.1] - 2025-09-11
### Fixed
 - Fixed issue in npmx_adc_meas_get where 2 lsbits would be incorrect.

## [1.2.0] - 2025-08-12
### Changed
- `npmx_charger_charging_current_get` and `npmx_charger_charging_current_set` now uses microamperes instead of milliamperes in order to support the more fine-grained adjustment options for nPM1304.
- Allowed values for `npmx_charger_discharging_current_set` is updated to be aligned with nPM1300 Product Specification v1.2. There are now only two allowed values: 200 mA and 1000 mA (low and high limits).
- `npmx_charger_discharging_current_set` no longer returns NPMX_ERROR_NOT_SUPPORTED when used with nPM1304 (which only has a single allowed battery discharge limit value).
- nPM1300 battery current calculation updated to be aligned with nPM1300 Product Specification v1.2.
- Updated LDSW soft start current options to be aligned with nPM1300 Product Specification v1.x.
- Added [porting guide](PORTING.md).

## [1.1.0] - 2025-05-28
### Fixed
 - Fixed offset issue in npmx_adc_meas_all_get.
 - Fixed -Wdouble-promotion build warnings.

### Added
 - Added support for nPM1304 PMIC.

### Changed
- npmx_adc ibat measurement is now reported in microamperes instead of milliamperes.
- NPMX_ADC_IBAT_MEAS_CURRENT_RFU member removed from npmx_adc_ibat_meas_current_t enum.

## [1.0.1] - 2024-07-12
### Fixed
 - Corrected discharge fullscale current.
 - Corrected charge fullscale current.
 - Update current limit on set.

## [1.0.0] - 2023-12-01
### Added
 - Added ADK v1.4.0.
 - Added the `npmx_adc_ntc_config_t` structure to the ADC driver. The structure contains a thermistor type and NTC beta value.
 - Added `npmx_charger_*_temperature_*` functions for getting and setting NTC temperature threshold using temperature in degrees Celsius.
 - Added the `restore_values` initialization parameter to the `npmx_core_init` function. Now, the following values can be restored from a PMIC device during its initialization: ADC burst mode enable, NTC beta value, charging current, discharging current, and ship button inversion status.
 - Added mathematical functions used in npmx to `npmx_common`.

### Changed
 - Changed the temperature type in the `npmx_charger_die_temp_*` functions. Now they accept negative values.
 - Changed a function for setting and reading the NTC type in the ADC driver. Now the `npmx_adc_ntc_config_t` configuration structure is passed as an argument to `npmx_adc_ntc_config_*` functions.
 - Changed the NTC resistance calculation to the battery temperature calculation in the ADC driver. The `NPMX_ADC_MEAS_NTC` enumeration which used to return measurement in Ohms has been replaced by `NPMX_ADC_MEAS_BAT_TEMP` which returns temperature in millidegrees Celsius.
 - Changed a behavior of the `npmx_timer_config_set` function. Now it triggers the `NPMX_TIMER_TASK_STROBE` task after setting the configuration.
 - Changed a compilation define that should be used when building for nPM1300 from `NPM1300_ENG_C` to `NPM1300`.
 - Changed the template file name for nPM1300 from `templates/npmx_config_npm1300_eng_c.h` to `templates/npmx_config_npm1300.h`.
 - Changed the behavior of the `npmx_callback_to_str` and `npmx_callback_bit_to_str` functions. Now, strings will be returned instead of a NULL pointer when building with `NPMX_DEBUG` defined.
 - Changed values in the `npmx_ldsw_soft_start_current_t`.

### Fixed
 - Fixed an issue in the `npmx_ldsw_soft_start_config_get` function that caused an incorrect enable state.
 - Fixed an issue in the `npmx_charger_die_temp_*` functions that caused incorrect temperature calculations in the charger driver.
 - Fixed an issue with the `NPMX_ADC_MEAS_BAT_TEMP` parameter in the `npmx_adc_meas_get` function. The issue caused an inaccurate die temperature calculation in the charger driver.
 - Fixed an issue in the `npmx_adc_meas_get` and `npmx_adc_meas_all_get` functions that caused an incorrect value to be returned.
 - Fixed an issue in the `npmx_callback_bit_to_str` function that caused an incorrect string description to be returned.
 - Fixed an issue in the `npmx_ship_reset_config_set` function that caused an incorrect task to be called.
 - Fixed minor issues in documentation.

## [0.7.0] - 2023-07-07
### Added
 - Added a GitHub workflow containing the `publish-documentation.yml` file. The file generates a HTML page with documentation that is linked on the GitHub repository page.
 - Added doxygen support for the npmx backend API files.
 - Added Sphinx documentation build system with HTML output.
 - Added the `generic_callback` initialization to the `npmx_core_init` function.
 - Added the battery current measurement support to the npmx ADC driver.
 - Added `charging_current_ma` and `discharging_current_ma` fields to the `npmx_charger_t` structure.
 - Added the `burst` field to the `npmx_adc_t` structure.

### Changed
 - Changed the doxygen main page to `README.md`.
 - Changed the `npmx_backend_t` structure to contain pointers to write and read functions.
 - Changed implementation of the `npmx_core_task_trigger()` function to the generic one.
 - Changed ADC measurements results type from `uint16_t` to `int32_t`.
 - Reworked validation of input parameters passed to functions in all drivers.
 - Reworked convert functions to use the switch case statement and to return a bool conversion status variable in all drivers.
 - Renamed the `NPMX_SHIP_INVALID` enumeration to `NPMX_SHIP_TIME_INVALID`.
 - Renamed the `NPMX_ADC_MEAS_VBAT2` enumeration to `NPMX_ADC_MEAS_VBAT2_IBAT`.
 - Renamed the `NPMX_ADC_MEAS_VBAT3` enumeration to `NPMX_ADC_MEAS_VBAT3_VBUS`.

### Removed
 - Removed support for all leftover MDK symbols.
 - Removed the `main_page.dox` file.

## [0.6.0] - 2023-05-11
### Added
 - Added functions that convert enumerations to integers.
 - Added functions that convert enumerations to strings.
 - Added `npmx_ship_time_convert` function.
 - Added `npmx_adc_ntc_type_convert`, `npmx_adc_ntc_meas_interval_convert` and `npmx_adc_die_temp_meas_interval_convert` functions.
 - Added `npmx_timer_status_t` structure.

### Changed
 - Renamed `NPMX_TIMER_PESCALER_SLOW` to `NPMX_TIMER_PRESCALER_SLOW`.
 - Renamed `NPMX_TIMER_PESCALER_FAST` to `NPMX_TIMER_PRESCALER_FAST`.
 - Renamed `npmx_adc_all_meas_t` to `npmx_adc_meas_all_t`.
 - Renamed `npmx_adc_battery_ntc_type_t` to `npmx_adc_ntc_type_t`.
 - Renamed `npmx_adc_auto_meas_inverval_*_{set, get}` to `npmx_adc_*_meas_interval_{set, get}`.
 - Renamed `npmx_charger_termination_voltage_{normal, warm}_{set, get}` to `npmx_charger_termination_{normal, warm}_voltage_{set, get}`.
 - Renamed `npmx_charger_trickle_{set, get}` to `npmx_charger_trickle_voltage_{set, get}`.
 - Renamed `NPMX_EVENT_GROUP_VBUSIN_OVRVOLT_DETECTED_MASK` to `NPMX_EVENT_GROUP_VBUSIN_OVERVOLT_DETECTED_MASK`.
 - Renamed `NPMX_EVENT_GROUP_THERMAL_SHDN_{DETECTED, REMOVED}_MASK` to `NPMX_EVENT_GROUP_THERMAL_SHUTDOWN_{DETECTED, REMOVED}_MASK`.
 - Renamed `NPMX_GPIO_NO_PULL` to `NPMX_GPIO_PULL_NONE`.
 - Renamed `npmx_gpio_config_t` member `pull_state` to `pull`.
 - Renamed `npmx_gpio_config_t` members: `open_drain_enable` to `open_drain`, `debounce_enable` to `debounce`.
 - Renamed `NPMX_LDSW_STATUS_LDSW_EN_MASK` to `NPMX_LDSW_STATUS_DEEPSLEEP_MASK`.
 - Renamed `NPMX_LDSW_STATUS_PWUP_{LDO, LDSW}_{1, 2}_MASK` to `NPMX_LDSW_STATUS_POWERUP_{LDO, LDSW}_{1, 2}_MASK`.
 - Reworked `npmx_ship_gpio_status_check` to return boolean instead of `npmx_ship_button_t` enumeration.
 - Reworked `npmx_timer_status_get` to return `npmx_timer_status_t` structure.

### Fixed
 - Fixed an issue in `npmx_ldsw_mode_get` that caused an incorrect mode to be returned.
 - Multiple documentation fixes.
 - Multiple formatting fixes.

### Removed
 - Removed `npmx_ship_button_t` enumeration.
 - Removed `npmx_timer_boot_monitor_t` enumeration.
 - Removed `npmx_timer_slow_domain_t` enumeration.

## [0.5.0] - 2023-04-21
### Fixed
 - Fixed an issue in MDK where reserved registers were using the `uint32_t` type. All registers are using the `uint8_t` type now.
 - Fixed an issue in MDK where POF polarity had incorrect values for nPM1300 Engineering C.

### Removed
 - Removed the long press string for the SHIPHOLD event for nPM1300 Engineering C.

## [0.4.0] - 2023-04-19
### Added
 - Added the `npmx_charger_iterm_convert` function.

### Fixed
 - Fixed values for the `*_INVALID` enumerators.

## [0.3.1] - 2023-03-08
### Fixed
 - Fixed a calculation code error in `vbus_value_from_code`.
 - Fixed the charger error handling procedure. `NPMX_CHARGER_TASK_RELEASE` is now triggered when an error is detected.

## [0.3.0] - 2023-02-08
### Added
 - Added conversion functions for enumerations.
 - Added assertions and `NPMX_CHECK` macro.
 - Added user-defined context data to npmx_instance. `npmx_core_context_set` and `npmx_core_context_get` can be used to modify it.
 - Added the `npmx_adc_meas_check` function.
 - Added enumerations for invalid values.

### Changed
 - Reworked ADC driver not to use NTC resistance stored on host side.

### Fixed
 - Fixed MAX and DEFAULT enum values.
 - Fixed: casting errors, division by 0, wrong read functions.
 - Fixed multiple minor issues.

## [0.2.0] - 2022-10-20
### Added
- Added new drivers:
  - ERRLOG,
  - SHIP,
  - VBUSIN.
- Added missing functionality in the following drivers:
  - ADC,
  - BUCK,
  - CHARGER,
  - CORE,
  - GPIO,
  - LDSW,
  - LED,
  - POF,
  - TIMER.
- Extended npmx instance structure to contain device-specific instance structures.

### Changed
- npmx API now returns npmx_error_t enumeration instead of bool.
- Minor code alignments in all drivers.

### Fixed
- Initialization order in npmx_core.

## [0.1.0] - 2022-09-09
### Added
- Added CHANGELOG.md file.
- Added README.md file.
- Added new drivers:
  - ADC,
  - BUCK,
  - CHARGER,
  - COMMON,
  - CORE,
  - EVENT,
  - GPIO,
  - LDSW,
  - LED,
  - POF,
  - TIMER.
- Added template integration files.
