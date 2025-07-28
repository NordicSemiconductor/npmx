# Porting guide

This document serves as a basic guide for porting npmx to a new hardware platform or SDK.

## Hardware dependencies

npmx uses the the following hardware functionalities:

* (mandatory) TWI (Two-wire interface, also called I2C) - Used for communication with the PMIC
* (optional) GPIO -  Used for interrupt and power failure signalling


## Compiler configuration

To inform npmx of which device you are compiling for, nPM1300 or nPM1304, add their definitions to your preprocessor settings. For example:

```
CFLAGS += -DNPM1300
```

Compile the following .c files:

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

Add the following include directories:

```
 .
 ├── backends
 └── drivers/include
```

> [!NOTE]
> This includes the npmx root directory where this porting guide is located.
    
Make a copy of the `templates` folder, and add it as an include directory.

In your copy of the `templates` directory you can modify the `npmx_glue.h` file, implementing the macros defined there. This is an optional step to help with debugging.

## TWI implementation

npmx defines two TWI functions that you must implement, one for reading and one for writing registers. Both functions uses the same prototype definition:

```
typedef npmx_error_t(*npmx_backend_function_t)(void *    p_context,
                                               uint32_t  register_address,
                                               uint8_t * p_data,
                                               size_t    num_of_bytes);
```


> [!IMPORTANT]
> The nPM13xx PMICs uses 16-bit register addresses, in big endian format. The TWI functions needs to handle this.

To inform npmx of these functions, call the `npmx_core_init` function, as in the following example:

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

See the example implementations of the I2C `read` and `write` functions using nRF5 SDK as follows:
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

After calling `npmx_core_init` with the TWI functions, you can start using npmx functions.

> [!IMPORTANT]
> Be aware of the context you are calling npmx functions from, as they will call the TWI functions directly. For example, if npmx functions are called from an interrupt with higher priority than TWI, you could risk a deadlock.

## Interrupt processing

To make the nPM13xx PMIC signal the interrupts, one of the GPIOs must be configured accordingly using the `npmx_gpio_mode_set` function. See the following example of configuring nPM1300 GPIO3 as an interrupt output:

```
npmx_error_t ret;

ret = npmx_gpio_mode_set(npmx_gpio_get(&npm1300_instance, 3), NPMX_GPIO_MODE_OUTPUT_IRQ);
// TODO: Verify that ret == NPMX_SUCCESS
```

This GPIO must be connected to a host processor GPIO that must be configured to generate interrupts. You must implement this hardware-specific function.

The application must provide callback functions for each interrupt type it wants to receive and enable these interrupts. Use the `npmx_core_register_cb` and `npmx_core_event_interrupt_enable` functions for this.

When an interrupt is detected on the host processor side, npmx must be informed of this using the `npmx_core_interrupt` function. This sets a flag in npmx. The actual interrupt processing happens when the `npmx_core_proc` function is called. It reads and clears the event registers, and triggers callback functions registered by the application.
> [!IMPORTANT]
> `npmx_core_interrupt` can be safely called from an interrupt handler, but `npmx_core_proc` should not be. `npmx_core_proc` performs TWI read/write operations and calls user-registered callbacks.

> [!NOTE]
> The nPM13xx interrupt GPIO signal will be active until the interrupt event registers are cleared by calling the `npmx_core_proc` function.

In the following nRF5 SDK example, the application connects the nPM1300 GPIO3 to nRF52840 P1.12 and enables an interrupt for VBUS events:

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