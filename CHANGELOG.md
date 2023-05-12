# Changelog
All notable changes to this project are documented in this file.

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
 - Fixed an issue in MDK where POF polarity had incorrect values for nPM1300 Engineering B.

### Removed
 - Removed the long press string for the SHIPHOLD event for nPM1300 Engineering B.

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
