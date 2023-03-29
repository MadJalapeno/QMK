// Copyright 2023 Mikee (@MadJalapeno)
// SPDX-License-Identifier: GPL-2.0-or-later

#pragma once

// Adafruit KB2040 Pinout
// https://cdn-learn.adafruit.com/assets/assets/000/106/984/original/adafruit_products_Adafruit_KB2040_Pinout.png?1638564074
//
// using the STEMMA QT with an OLED
// https://learn.adafruit.com/using-qmk-on-rp2040-microcontrollers/kb2040-one-key-keyboard-with-oled-display
//

#define TAP_CODE_DELAY 10

// RGB LED setup
#define RGB_DI_PIN GP10
#define RGBLED_NUM 4

#ifdef RGBLIGHT_ENABLE
    #undef RGBLED_NUM
    #define RGBLIGHT_EFFECT_BREATHING
    #define RGBLIGHT_EFFECT_RAINBOW_MOOD
    #define RGBLIGHT_EFFECT_RAINBOW_SWIRL
    #define RGBLIGHT_EFFECT_SNAKE
    #define RGBLIGHT_EFFECT_KNIGHT
    #define RGBLIGHT_EFFECT_CHRISTMAS
    #define RGBLIGHT_EFFECT_STATIC_GRADIENT
    #define RGBLIGHT_EFFECT_RGB_TEST
    #define RGBLIGHT_EFFECT_ALTERNATING
    #define RGBLIGHT_EFFECT_TWINKLE
    #define RGBLED_NUM 4
    #define RGBLIGHT_LIMIT_VAL 120
    #define RGBLIGHT_HUE_STEP 7
    #define RGBLIGHT_SAT_STEP 7
    #define RGBLIGHT_VAL_STEP 7
#endif


//Encoders setup
// kmk setup
// encoders.pins = ((board.A2, board.A1, board.A0, False), (board.SCK, board.MISO, board.MOSI, False),)
// A2 = GP28 = pad A
// A1 = GP27 = pad B
// A0 = GP26
//
// SCK = GP18 = pad A
// MISO= GP20 = pad B
// MOSI= GP19
//
#define ENCODERS_PAD_A { GP28, GP18 } // where does each encoder pad A connect
#define ENCODERS_PAD_B { GP27, GP20 } // where does each encoder pad B connect
#define ENCODER_RESOLUTION 1
// #define ENCODER_MAP_KEY_DELAY 10
// use encoder push buttons as dip switches
#define DIP_SWITCH_PINS { GP26, GP19 }