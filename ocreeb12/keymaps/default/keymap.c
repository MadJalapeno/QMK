// Copyright 2023 QMK
// SPDX-License-Identifier: GPL-2.0-or-later

// keycodes - https://qmk.github.io/qmk_mkdocs/master/en/faq_keymap/

#include QMK_KEYBOARD_H

#define _BASE 0 // default, base layer
#define _RGB 1 // playing with LED's


const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    /*
     * ┌───┬───┬───┬───┐
     * │ 7 │ 8 │ 9 │ / │
     * ├───┼───┼───┼───┤
     * │ 4 │ 5 │ 6 │ 0 │
     * ├───┼───┼───┼───┤
     * │ 1 │ 2 │ 3 │ - │
     * └───┴───┴───┴───┘
     */
    [_BASE] = LAYOUT(
        KC_P7,   KC_P8,   KC_P9,   KC_PSLS,
        KC_P4,   KC_P5,   KC_P6,   KC_P0,
        RGB_TOG,   KC_P2,   KC_P3,   KC_PMNS
    ),
    [_RGB] = LAYOUT(
        KC_NO,      KC_NO,      KC_NO,      KC_NO,
        KC_NO,      KC_NO,      KC_NO,      KC_NO,
        KC_NO,      KC_NO,      KC_NO,      KC_NO        
    )
};

#if defined(ENCODER_MAP_ENABLE)
const uint16_t PROGMEM encoder_map[][NUM_ENCODERS][2] = {
              // Mappings for 1st Encoder          // Mappings for 2nd Encoder
    [_BASE] = { ENCODER_CCW_CW(KC_VOLD, KC_VOLU), ENCODER_CCW_CW(RGB_MOD, RGB_RMOD)   },
    [_RGB ] = { ENCODER_CCW_CW(KC_VOLD, KC_VOLU), ENCODER_CCW_CW(KC_PGUP, KC_PGDN)   }

};
#endif