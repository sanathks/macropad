// Copyright 2023 QMK
// SPDX-License-Identifier: GPL-2.0-or-later

#include QMK_KEYBOARD_H

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [0] = LAYOUT_ortho_3x3(
        KC_1,   KC_2,   KC_3,
        KC_4,   KC_5,   KC_6,
        KC_7,   KC_8,   KC_9
    )
};

void keyboard_pre_init_user(void) {
    setPinOutput(F5);
    setPinOutput(F6);
    setPinOutput(F7);
}
layer_state_t layer_state_set_user(layer_state_t state) {
    if(IS_LAYER_ON_STATE(state, 1)) {
        writePinHigh(F5);
    }
    else {
        writePinLow(F5);
    }
    if(IS_LAYER_ON_STATE(state, 2)) {
        writePinHigh(F6);
    }
    else {
        writePinLow(F6);
    }
    if(IS_LAYER_ON_STATE(state, 3)) {
        writePinHigh(F7);
    }
    else {
        writePinLow(F7);
    }
return state;
}
