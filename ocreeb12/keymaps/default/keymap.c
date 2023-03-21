// Copyright 2023 QMK
// SPDX-License-Identifier: GPL-2.0-or-later

// keycodes - https://qmk.github.io/qmk_mkdocs/master/en/faq_keymap/

#include QMK_KEYBOARD_H

#define _BASE 0 // default, base layer
#define _RGB 1 // playing with LED's


const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    /*
     * numpad            numpad & shift
     * ┌───┬───┬───┬───┐ ┌────────┬────────┬──────┬────────┐
     * │ 0 │ 1 │ 4 │ 7 │ | insert | end    | left | home   |
     * ├───┼───┼───┼───┤ ├────────┼────────┼──────┼────────┤
     * │ . │ 2 │ 5 │ 8 │ | delete | down   |      | up     |
     * ├───┼───┼───┼───┤ ├────────┼────────┼──────┼────────┤
     * │ L │ 3 │ 6 │ 9 │ |        | page.d | right| page.up|
     * └───┴───┴───┴───┘ └──-----─┴-----───┴─---──┴-----───┘
     */
    [_BASE] = LAYOUT(
        KC_P0,      KC_P1,   KC_P4,   KC_P7,
        KC_PDOT,    KC_P2,   KC_P5,   KC_P8,
        MO(_RGB),   KC_P3,   KC_P6,   KC_P9
    ),

    /*
     * ┌            ┬   ┬          ┬          ┐
     * | RGB on/off |   | RGB Hue- | RGB Hue+ |
     * ├            ┼   ┼          ┼          ┤
     * | RGB static |   | RGB Sat- | RGB Sat+ |
     * ├            ┼   ┼          ┼          ┤
     * |  kc_trans  |   | RGB Val- | RGB Val+ |
     * └            ┴   ┴          ┴          ┘
     */
      
    [_RGB] = LAYOUT(
        RGB_TOG,        KC_NO,      RGB_HUD,    RGB_HUI,
        RGB_M_P,        KC_NO,      RGB_SAD,    RGB_SAI,
        KC_TRNS,       KC_NO,      RGB_VAD,    RGB_VAI        
    )
};


#if defined(ENCODER_MAP_ENABLE)
const uint16_t PROGMEM encoder_map[][NUM_ENCODERS][2] = {
              // Mappings for 1st Encoder          // Mappings for 2nd Encoder
    [_BASE] = { ENCODER_CCW_CW(KC_VOLD, KC_VOLU), ENCODER_CCW_CW(RGB_MOD, RGB_RMOD)   },
    [_RGB ] = { ENCODER_CCW_CW(KC_VOLD, KC_VOLU), ENCODER_CCW_CW(KC_PGUP, KC_PGDN)   }
};

#else

bool encoder_update_user(uint8_t index, bool clockwise) {
    if (index == 0) { /* First encoder */
        if (clockwise) {
            tap_code_delay(KC_VOLU, 20);
        } else {
            tap_code_delay(KC_VOLD, 20);
        }
    } else if (index == 1) { /* Second encoder */
        if (clockwise) {
            tap_code_delay(KC_PGUP, 15);
        } else {
            tap_code_delay(KC_PGDN, 15);
        }
    }
    return false;
}
#endif


bool dip_switch_update_user(uint8_t index, bool active) { 
    switch (index) {
        case 0:         // ENC0_SW
            if(active)  // ENC0 pressed
            { tap_code( KC_MUTE ); } 
            else        // ENC0 released 
            {  }
            break;
    }
    return true;
}