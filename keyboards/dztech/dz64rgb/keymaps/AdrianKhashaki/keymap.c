/* Copyright 2021 DZTECH <moyi4681@Live.cn>
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */
 
#include QMK_KEYBOARD_H

#define CASE_DOWN(code)      \
if (record->event.pressed) { \
    code;                    \
}                            \
break;

#define WITHOUT_SHIFT(upper, lower)        \
({                                         \
    uint8_t mods_ = get_mods();            \
    if ((mods_ & MOD_MASK_SHIFT) > 0) {    \
        clear_mods();                      \
        upper;                             \
        set_mods(mods_);                   \
    }                                      \
    else {                                 \
        lower;                             \
    }                                      \
})

enum custom_keycodes {
    AE_WIN = SAFE_RANGE,
    AE_MAC,
    OE_WIN,
    OE_MAC,
    UE_WIN,
    UE_MAC,
    SZ_WIN,
    SZ_MAC,
    EU_WIN,
    EU_MAC
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case AE_WIN:
            CASE_DOWN(WITHOUT_SHIFT(
                SEND_STRING(SS_LALT(SS_TAP(X_P1) SS_TAP(X_P4) SS_TAP(X_P2))),
                SEND_STRING(SS_LALT(SS_TAP(X_P1) SS_TAP(X_P3) SS_TAP(X_P2))))
            )
        case AE_MAC:
            CASE_DOWN(WITHOUT_SHIFT(
                SEND_STRING(SS_LALT(SS_TAP(X_U)) SS_LSFT(SS_TAP(X_A))),
                SEND_STRING(SS_LALT(SS_TAP(X_U)) SS_TAP(X_A)))
            )
        case OE_WIN:
            CASE_DOWN(WITHOUT_SHIFT(
                SEND_STRING(SS_LALT(SS_TAP(X_P1) SS_TAP(X_P5) SS_TAP(X_P3))),
                SEND_STRING(SS_LALT(SS_TAP(X_P1) SS_TAP(X_P4) SS_TAP(X_P8))))
            )
        case OE_MAC:
            CASE_DOWN(WITHOUT_SHIFT(
                SEND_STRING(SS_LALT(SS_TAP(X_U)) SS_LSFT(SS_TAP(X_O))),
                SEND_STRING(SS_LALT(SS_TAP(X_U)) SS_TAP(X_O)))
            )
        case UE_WIN:
            CASE_DOWN(WITHOUT_SHIFT(
                SEND_STRING(SS_LALT(SS_TAP(X_P1) SS_TAP(X_P5) SS_TAP(X_P4))),
                SEND_STRING(SS_LALT(SS_TAP(X_P1) SS_TAP(X_P2) SS_TAP(X_P9))))
            )
        case UE_MAC:
            CASE_DOWN(WITHOUT_SHIFT(
                SEND_STRING(SS_LALT(SS_TAP(X_U)) SS_LSFT(SS_TAP(X_U))),
                SEND_STRING(SS_LALT(SS_TAP(X_U)) SS_TAP(X_U)))
            )
        case SZ_WIN:
            CASE_DOWN(WITHOUT_SHIFT(
                SEND_STRING(SS_LALT(SS_TAP(X_P0) SS_TAP(X_P2) SS_TAP(X_P2) SS_TAP(X_P3))),
                SEND_STRING(SS_LALT(SS_TAP(X_P0) SS_TAP(X_P2) SS_TAP(X_P2) SS_TAP(X_P3))))
            )
        case SZ_MAC:
            CASE_DOWN(WITHOUT_SHIFT(
                SEND_STRING(SS_LALT(SS_TAP(X_S))),
                SEND_STRING(SS_LALT(SS_TAP(X_S))))
            )
        case EU_WIN:
            CASE_DOWN(WITHOUT_SHIFT(
                SEND_STRING(SS_LALT(SS_TAP(X_P0) SS_TAP(X_P1) SS_TAP(X_P2) SS_TAP(X_P8))),
                SEND_STRING(SS_LALT(SS_TAP(X_P0) SS_TAP(X_P1) SS_TAP(X_P2) SS_TAP(X_P8))))
            )
        case EU_MAC:
            CASE_DOWN(WITHOUT_SHIFT(
                SEND_STRING(SS_LSFT(SS_LALT(SS_TAP(X_2)))),
                SEND_STRING(SS_LSFT(SS_LALT(SS_TAP(X_2)))))
            )
    }
    return true;
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [0] = LAYOUT_64_ansi(
        KC_ESC,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_MINS, KC_EQL,  KC_BSPC,
        KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_LBRC, KC_RBRC, KC_BSLS,
        KC_LGUI, KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT,          KC_ENT,
        KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_GRV,  KC_UP,   KC_DEL,
        KC_LCTL, KC_LALT, KC_LGUI,                            KC_SPC,                    KC_RGUI, MO(1),   KC_LEFT, KC_DOWN, KC_RGHT
    ),
    [1] = LAYOUT_64_ansi(
        _______, KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,  KC_DEL,
        _______, _______, _______, EU_MAC,  _______, _______, _______, UE_MAC,  _______, OE_MAC,  _______, _______, _______, _______,
        _______, AE_MAC,  SZ_MAC,  _______, _______, _______, _______, _______, _______, _______, _______, _______,          _______,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, KC_VOLU, KC_MUTE,
        DF(0),   DF(2),   _______,                            KC_MPLY,                   _______, _______, KC_MPRV, KC_VOLD, KC_MNXT
    ),
    [2] = LAYOUT_64_ansi(
        KC_ESC,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_MINS, KC_EQL,  KC_BSPC,
        KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_LBRC, KC_RBRC, KC_BSLS,
        KC_LCTL, KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT,          KC_ENT,
        KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_GRV,  KC_UP,   KC_DEL,
        KC_LCTL, KC_LGUI, KC_LALT,                            KC_SPC,                    KC_RALT, MO(3),   KC_LEFT, KC_DOWN, KC_RGHT
    ),
    [3] = LAYOUT_64_ansi(
        _______, KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,  KC_DEL,
        _______, _______, _______, EU_WIN,  _______, _______, _______, UE_WIN,  _______, OE_WIN,  _______, _______, _______, _______,
        _______, AE_WIN,  SZ_WIN,  _______, _______, _______, _______, _______, _______, _______, _______, _______,          _______,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, KC_VOLU, KC_MUTE,
        DF(0),   DF(2),   _______,                            KC_MPLY,                   _______, _______, KC_MPRV, KC_VOLD, KC_MNXT
    )
};
