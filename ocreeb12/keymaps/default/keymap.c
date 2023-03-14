// Copyright 2023 QMK
// SPDX-License-Identifier: GPL-2.0-or-later

// keycodes - https://qmk.github.io/qmk_mkdocs/master/en/faq_keymap/

#include QMK_KEYBOARD_H

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
    [0] = LAYOUT(
        KC_P7,   KC_P8,   KC_P9,   KC_PSLS,
        KC_P4,   KC_P5,   KC_P6,   KC_P0,-
        KC_P1,   KC_P2,   KC_P3,   KC_PMNS
    )
};

bool encoder_update_user(uint8_t index, bool clockwise) {
    if (index == 0) { /* First encoder */
        if (clockwise) {
            tap_code_delay(KC_VOLU, 2);
        } else {
            tap_code_delay(KC_VOLD, 2);
        }
    } else if (index == 1) { /* Second encoder */
        if (clockwise) {
            tap_code_delay(RGB_MODE_FORWARD);
        } else {
            tap_code_delay(RGB_MODE_REVERSE);
        }
    }
    return false;
}
