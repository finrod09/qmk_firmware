// Copyright 2023 Chris Trotter (@Chris Trotter)
// SPDX-License-Identifier: GPL-2.0-or-later

#pragma once

// #define DIODE_DIRECTION COL2ROW
#define MATRIX_ROWS 24                          // Rows are doubled-up in a split kb
#define MATRIX_COLS 6
#define USB_POLLING_INTERVAL_MS 1 /* Set Polling rate to 1000Hz */

// setting the SPI pins for the PMW // why isn't this inside pointing_device_enable?
#define SPI_DRIVER SPID1
#define SPI_SCK_PIN GP10  // clock is shared
#define SPI_MOSI_PIN GP11 // mosi is shared....?
#define SPI_MISO_PIN GP12 // pmw needs this; tft does not

// RP2040 reset functionality
#define RP2040_BOOTLOADER_DOUBLE_TAP_RESET      // Activates the double-tap behavior
#define RP2040_BOOTLOADER_DOUBLE_TAP_RESET_TIMEOUT 200U // Timeout window in ms in which the double tap can occur.
#define RP2040_BOOTLOADER_DOUBLE_TAP_RESET_LED_MASK 0U // Specify a optional status led which blinks when entering the bootloader
#define CRC8_USE_TABLE
#define CRC8_OPTIMIZE_SPEED

// Split settings
#if defined(SPLIT_KEYBOARD)
    #define EE_HANDS                            // cuz we are using hand-targeted flashing, which sets eeprom handednesss
    #define SERIAL_USART_TX_PIN GP1             // I could never get full-duplex working; this is the only config needed for half-duplex
    #define SERIAL_PIO_USE_PIO1                 // using PIO0 i get a lot of dropped packets; none using PIO1
    /*
        Scan rate changes...
        230400 = 640 (default)
        460800 = 780 (labeled as 'experimental')
        700000 = 840
        800000 = 860 (35% improvement! very consistent numbers)
        850000 = 'Failed to execute encoder/pointer' errors
        900000 = 875, but inconsistent numbers, ranging from 855-875
        921600 = 'Failed to execute encoder' errors
    */
    #define SERIAL_USART_SPEED 800000
    // must have eeprom reset buttons on both halves
    #define BOOTMAGIC_LITE_ROW 0
    #define BOOTMAGIC_LITE_COLUMN 0
    // this uses row/col numbering that starts on 0
    #define BOOTMAGIC_LITE_ROW_RIGHT 13
    #define BOOTMAGIC_LITE_COLUMN_RIGHT 0
    // generic split config
    #define SPLIT_WATCHDOG_ENABLE // this took 30 off the scanrate
    #define SPLIT_WATCHDOG_TIMEOUT 3000
    #define SPLIT_TRANSPORT_MIRROR              // docs say use this if you are using RGB_MATRIX_SPLIT { X, Y } // this doesn't seem to do anything...took 10 off scanrate
    #define SPLIT_LAYER_STATE_ENABLE            // docs say use this if you are using split and rgb lighting per layer // this added 20 to scanrate???
    #define SPLIT_MODS_ENABLE                   // docs say it is for telling the other half about modifier (e.g. oneshot) state // this removed 35 from scanrate
#endif

#if defined(POINTING_DEVICE_ENABLE)
    // #define POINTING_DEVICE_DEBUG // enables some handy debug output; pair with 'debug_mouse=true' in your keyboard_post_init_user // also, should wrap debug up in something maybe
    #define MOUSE_EXTENDED_REPORT // do we need this?
    #define POINTING_DEVICE_TASK_THROTTLE_MS 10 // this ensures that the trackball sensor polling happens only every 10ms
    #define SPLIT_POINTING_ENABLE               // required for telling the master side about slave trackball state, i.e. if usb left, and tb right
    #define POINTING_DEVICE_COMBINED
    #define PMW33XX_CS_PIN GP13                 // where the SS (CS) pin on the PMW module connects to the mcu
    #define PMW33XX_LIFTOFF_DISTANCE 0x07       // LIFTOFF_DISTANCE specifies how far from the sensor the trackball is
    #define RIGHT_PMW_CPI 1000       // your mouse cpi (DPI) setting (how fast the ball tracks)
    #define LEFT_PMW_CPI 100    // dragscroll cpi - interestingly, can't be set below 100?
#endif

// WS2812 RGB LED strip input and number of LEDs
#if defined(RGB_MATRIX_ENABLE) || defined(RGB_MATRIX_LEDMAPS_ENABLED)
    #define WS2812_DI_PIN GP28 // evidently this is new
    #define RGBLED_NUM 128                       // Total number of LEDs, total of both halves
    #define RGB_MATRIX_SPLIT { 64, 64 }  //  (4x6) + 5 + 12 + 12 + 11 = 64
    #define RGB_MATRIX_LED_COUNT RGBLED_NUM

    // this brightness is only for 'default' rgb settings; userspace rgb is set in the keymap config.h
    #define RGB_MATRIX_MAXIMUM_BRIGHTNESS 50 // this has no effect unless you eeprom reset  // setting this too high will cause the trackball to reset every min or so, and at highest just brownout entirely
    #define RGB_MATRIX_DEFAULT_HUE 5
    #define RGB_MATRIX_DEFAULT_SAT 5
    #define RGB_MATRIX_DEFAULT_VAL RGB_MATRIX_MAXIMUM_BRIGHTNESS
    #define NOP_FUDGE 0.4                       // not sure what this does - some math about rgb brightness or something? - but it won't compile without this set
#endif

#if defined(ENCODER_ENABLE)
    #define ENCODERS_PAD_A { GP14, GP26 }
    #define ENCODERS_PAD_B { GP15, GP27 }
    #define ENCODER_RESOLUTION 4
#endif

// For the tft display
#if defined(QUANTUM_PAINTER_ENABLE)
    #define DISPLAY_SPI_DIVISOR 0
    #define DISPLAY_DC_PIN GP8
    #define DISPLAY_CS_PIN GP9
    #define DISPLAY_RST_PIN GP0 // without this, white screen
    #define DISPLAY_LED_PIN GP22
    #define QUANTUM_PAINTER_DISPLAY_TIMEOUT 0 // never turn off the display; i'm troubleshooting why QP is not working, this is not really necessary
    #define QUANTUM_PAINTER_TASK_THROTTLE 50 // trying to reduce the scan rate hit
#endif
