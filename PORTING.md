# Porting guide
This document is intended to serve as a basic guide for porting npmx to a new hardware platform or SDK.

## Hardware dependencies
The following hardware functionality is used by npmx:
1. (mandatory) TWI (Two-wire interface, also called I2C)
2. (optional) GPIO

TWI is used for communication with the pmic, and is a mandatory requirement.
GPIO is optionally used for interrupt and power failure signalling.

## Compiler configuration
In order to inform npmx of which device you are compiling for, "NPM1300" or "NPM1304" definitions should be added to your preprocessor settings. For example:
```
CFLAGS += -DNPM1300
```

The following .c files should be compiled:
```
 .
 ├── backends
 │   └── npmx_backend.c
 └── drivers
     ├── npmx_adc.c
     ├── npmx_buck.c
     ├── npmx_charger.c
     ├── npmx_common.c
     ├── npmx_core.c
     ├── npmx_errlog.c
     ├── npmx_gpio.c
     ├── npmx_ldsw.c
     ├── npmx_led.c
     ├── npmx_pof.c
     ├── npmx_ship.c
     ├── npmx_timer.c
     └── npmx_vbusin.c
```

The following include directories should be added, **note that this includes the npmx root directory where this porting guide is located**:
```
 .
 ├── backends
 └── drivers/include
```

You should make a copy of the following folder, and add the copy as an include directory:
```
 .
 └── templates
```
In your copy of the `templates` directory you can modify `npmx_glue.h`, implementing the macros defined there. This is an optional step in order to help with debugging.

## TWI implementation
npmx defines two TWI functions which must be implemented, one for reading and one for writing registers. Both functions uses the same prototype definition:
```
typedef npmx_error_t(*npmx_backend_function_t)(void *    p_context,
                                               uint32_t  register_address,
                                               uint8_t * p_data,
                                               size_t    num_of_bytes);
```

Note that nPM13xx PMICs uses 16-bit register addresses, in big endian format. The TWI functions needs to handle this.

You inform npmx of these functions by calling the `npmx_core_init` function, as in the example seen below.
```
#include <npmx.h>
#include <npmx_core.h>
#include <npmx_instance.h>

static npmx_instance_t npm1300_instance;
static npmx_backend_t npm1300_backend;

static npmx_error_t my_i2c_write_function(void * p_context, uint32_t register_address,
    uint8_t * p_data, size_t num_of_bytes);
static npmx_error_t my_i2c_read_function(void * p_context, uint32_t register_address,
    uint8_t * p_data, size_t num_of_bytes);

static void my_npmx_initialization_function(void)
{
    npm1300_backend.p_read = my_i2c_read_function;
    npm1300_backend.p_write = my_i2c_write_function;
    npm1300_backend.p_context = NULL; // Optional context for our use

    npmx_error_t npmx_err = npmx_core_init(&npm1300_instance, &npm1300_backend, NULL, true);
    // TODO: Verify that npmx_err == NPMX_SUCCESS
}
```

See example implementations of the i2c read and write functions using nRF5 SDK below.
```
#include <nrfx_twim.h>
#include "nrf_atomic.h"

#define NPM1300_ADDR 0x6b

static const nrfx_twim_t twim = NRFX_TWIM_INSTANCE(0);
static nrfx_twim_config_t twim_config = {
    .scl                = NRF_GPIO_PIN_MAP(0, 27),
    .sda                = NRF_GPIO_PIN_MAP(0, 26),
    .frequency          = (nrf_twim_frequency_t)NRFX_TWIM_DEFAULT_CONFIG_FREQUENCY,
    .interrupt_priority = NRFX_TWIM_DEFAULT_CONFIG_IRQ_PRIORITY,
    .hold_bus_uninit    = NRFX_TWIM_DEFAULT_CONFIG_HOLD_BUS_UNINIT,
};

static nrf_atomic_flag_t twim_op_done;

static void my_twim_event_handler(nrfx_twim_evt_t const * p_event, void * p_context)
{
    nrf_atomic_flag_set(&twim_op_done);
}

static npmx_error_t my_i2c_write_function(void * p_context, uint32_t register_address,
    uint8_t * p_data, size_t num_of_bytes)
{
    uint8_t data[TWIM_BUF_SIZE];

    nrfx_twim_xfer_desc_t desc = {
        .type = NRFX_TWIM_XFER_TX,
        .address = NPM1300_ADDR,
        .primary_length = num_of_bytes + 2,
        .secondary_length = 0,
        .p_primary_buf = data,
        .p_secondary_buf = NULL
    };

    if (num_of_bytes > (TWIM_BUF_SIZE - 2)) {
        return NPMX_ERROR_INVALID_PARAM;
    }

    data[0] = register_address >> 8;
    data[1] = register_address;
    memcpy(&data[2], p_data, num_of_bytes);

    nrfx_err_t err = nrfx_twim_xfer(&twim, &desc, 0);
    if (err) {
        return NPMX_ERROR_IO;
    }

    while (!nrf_atomic_flag_clear_fetch(&twim_op_done)) {
        __WFE();
    }

    return NPMX_SUCCESS;
}

static npmx_error_t my_i2c_read_function(void * p_context, uint32_t register_address,
        uint8_t * p_data, size_t num_of_bytes)
{
    uint8_t reg_addr[2];

    nrfx_twim_xfer_desc_t desc = {
        .type = NRFX_TWIM_XFER_TXRX,
        .address = NPM1300_ADDR,
        .primary_length = sizeof(reg_addr),
        .secondary_length = num_of_bytes,
        .p_primary_buf = reg_addr,
        .p_secondary_buf = p_data
    };

    reg_addr[0] = register_address >> 8;
    reg_addr[1] = register_address;

    nrfx_err_t err = nrfx_twim_xfer(&twim, &desc, 0U);
    if (err) {
        return NPMX_ERROR_IO;
    }

    while (!nrf_atomic_flag_clear_fetch(&twim_op_done)) {
        __WFE();
    }

    return NPMX_SUCCESS;
}

static void my_twim_init_function(void)
{
    nrfx_err_t nrfx_err = nrfx_twim_init(&twim, &twim_config, my_twim_event_handler, NULL);
    APP_ERROR_CHECK_BOOL(nrfx_err == NRFX_SUCCESS);

    nrfx_twim_enable(&twim);
}
```

After `npmx_core_init` is called with the TWI functions, you can start using npmx functions.

> **_NOTE:_**  Be aware of the context you are calling npmx functions from, as they will call the TWI functions directly. For example, if npmx functions are called from an interrupt with higher priority than TWI, you could risk a deadlock.

## Interrupt processing
In order for nPM13xx PMIC to signal interrupts, one of the GPIOs must be configured accordingly. This is done using the `npmx_gpio_mode_set` function. Below is an example of configuring nPM1300 GPIO3 as an interrupt output.
```
npmx_error_t ret;

ret = npmx_gpio_mode_set(npmx_gpio_get(&npm1300_instance, 3), NPMX_GPIO_MODE_OUTPUT_IRQ);
// TODO: Verify that ret == NPMX_SUCCESS
```

This GPIO must be connected to a Host processor GPIO, which must be configured to generate interrupts. This is a hardware specific function which you must implement.

The application must provide callback functions for each interrupt type it wants to receive, and additionally enable these interrupts. This is done via `npmx_core_register_cb` and `npmx_core_event_interrupt_enable` functions.

When an interrupt is detected on the Host processor side, npmx must be informed of this by calling the `npmx_core_interrupt` function. This simply sets a flag in npmx. The actual interrupt processing happens when the `npmx_core_proc` function is called. `npmx_core_proc` reads and clears the event registers, and triggers callback functions registered by the application.
> **_NOTE:_** `npmx_core_interrupt` can be safely called from an interrupt handler, but `npmx_core_proc` should not be. `npmx_core_proc` performs TWI read/write operations and calls user-registered callbacks.

> **_NOTE:_** The nPM13xx interrupt GPIO signal will be active until the interrupt event registers are cleared by calling the `npmx_core_proc` function.

Below is an example using nRF5 SDK where the application connects nPM1300 GPIO3 to nRF52840 P1.12, and enables interrupt for "VBUS" events.

```
#include <nrfx_gpiote.h>

#include <npmx.h>
#include <npmx_core.h>
#include <npmx_instance.h>

static npmx_instance_t npm1300_instance;

static bool pmic_interrupt;

static void in_pin_handler(nrfx_gpiote_pin_t pin, nrf_gpiote_polarity_t action) {
    (void)pin;
    (void)action;

    if (pin == NRF_GPIO_PIN_MAP(1, 12)) {
        nrfx_gpiote_in_event_disable(NRF_GPIO_PIN_MAP(1, 12));
        pmic_interrupt = true;
    }
}

static void vbusin_callback(npmx_instance_t *p_pm, npmx_callback_type_t type, uint8_t mask)
{
    if (mask & (uint8_t)NPMX_EVENT_GROUP_VBUSIN_DETECTED_MASK) {
        NRF_LOG_INFO("VBUS detected");
    }
    if (mask & (uint8_t)NPMX_EVENT_GROUP_VBUSIN_REMOVED_MASK) {
        NRF_LOG_INFO("VBUS removed");
    }
}

int main(void)
{
    npmx_error_t npmx_err;
    nrfx_err_t nrfx_err;

    // NOTE: ASSUMES TWI and basic npmx_core_init functions are called at this point. Ref. code snippets above.

    // Clear all events before enabling interrupts, just in case other interrupt source was configured before.
    for (uint32_t i = 0; i < NPMX_EVENT_GROUP_COUNT; i++) {
        npmx_err = npmx_core_event_interrupt_disable(&npm1300_instance, (npmx_event_group_t)i,
                                NPMX_EVENT_GROUP_ALL_EVENTS_MASK);
        APP_ERROR_CHECK_BOOL(npmx_err == NPMX_SUCCESS);
    }

    // Enable interrupt pin from PMIC
    npmx_err = npmx_gpio_mode_set(npmx_gpio_get(&npm1300_instance, 3), NPMX_GPIO_MODE_OUTPUT_IRQ);
    APP_ERROR_CHECK_BOOL(npmx_err == NPMX_SUCCESS);

    // Enable interrupt pin on nRF52840
    // Note that interrupt is level-triggered, if a new event occurs while processing the current events, it will
    // trigger again after the interrupt is reenabled
    nrfx_gpiote_in_config_t in_config = NRFX_GPIOTE_CONFIG_IN_SENSE_LOTOHI(false);
    nrfx_err = nrfx_gpiote_init();
    APP_ERROR_CHECK(nrfx_err);
    nrfx_err = nrfx_gpiote_in_init(NRF_GPIO_PIN_MAP(1, 12), &in_config, in_pin_handler);
    APP_ERROR_CHECK(nrfx_err);

    nrfx_gpiote_in_event_enable(NRF_GPIO_PIN_MAP(1, 12), true);

    // Register callback for VBUS events.
    npmx_core_register_cb(&npm1300_instance, vbusin_callback,
        NPMX_CALLBACK_TYPE_EVENT_VBUSIN_VOLTAGE);

    // Enable VBUS detected and VBUS removed events
    npmx_core_event_interrupt_enable(&npm1300_instance, NPMX_EVENT_GROUP_VBUSIN_VOLTAGE,
        NPMX_EVENT_GROUP_VBUSIN_DETECTED_MASK |
            NPMX_EVENT_GROUP_VBUSIN_REMOVED_MASK);

    // Event processing loop
    while (true)
    {
        if (pmic_interrupt) {
            npmx_core_interrupt(&npm1300_instance);
            npmx_core_proc(&npm1300_instance);

            pmic_interrupt = false;
            nrfx_gpiote_in_event_enable(NRF_GPIO_PIN_MAP(1, 12), true);
        }

        NRF_LOG_FLUSH();

        __WFE();
    }
}
```