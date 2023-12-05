/*
Copyright 2023 Erik Christiansson <erik.christiansson@gmail.com>

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 2 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program.  If not, see <http://www.gnu.org/licenses/>.

The Minesota layout - Swedish American layout for programmers that
needs to type the Swedish characters å, ä and ö in a cross platform
compatible way.

This layout lets you set your OS to a Swedish while having the keys
behave as if the layout was American. I.e. the key to the right of
the P will yield a [ rather than an å.
Å, ä and ö is typed by holding AltGr and pressing a, e and o
respectively.
Caps Lock is replaced by F13.

When the Win/Mac switch is in the Mac location, the keyboard
behaves like a very standard Windows keyboard.
*/

#include QMK_KEYBOARD_H

enum my_keycodes {
    SWE_CRET = SAFE_RANGE, /* ^ RSFT(KC_RBRC) followed by KC_SPC */
    SWE_TLDE,              /* ~ RALT(KC_RBRC) followed by KC_SPC */
    SWE_TLDD,              /* ~ dead RALT(KC_RBRC) */
    SWE_BTIC,              /* ` RSFT(KC_EQL) followed by KC_SPC */
    SWE_FTIC,              /* ´ KC_EQL followed by KC_SPC */
    SWE_LGWB,              /* { KC_RALT(KC_7) */
    SWE_RGWB,              /* } KC_RALT(KC_0) */
    SWE_PLUS,              /* + KC_MINS without modifiers */
    SWE_AT,                /* @ KC_RALT(KC_2) */
    SWE_DOLR,              /* $ KC_RALT(KC_4) */
    SWE_PIPE,              /* | KC_RALT(KC_NUBS) */
    SWE_LT                 /* < KC_NUBS without modifiers */
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case SWE_CRET:
            if (record->event.pressed) {
                uint8_t modState = get_mods();
                clear_mods();
                add_mods(MOD_BIT(KC_RSFT));
                register_code(KC_RBRC);
                clear_mods();
                register_code(KC_SPC);
                unregister_code(KC_SPC);
                set_mods(modState);
            }
            return false;
        case SWE_TLDE:
            if (record->event.pressed) {
                uint8_t modState = get_mods();
                del_mods(MOD_MASK_SHIFT);
                add_mods(MOD_BIT(KC_RALT));
                register_code(KC_RBRC);
                clear_mods();
                register_code(KC_SPC);
                unregister_code(KC_SPC);
                set_mods(modState);
            }
            return false;
        case SWE_TLDD:
            if (record->event.pressed) {
                uint8_t modState = get_mods();
                clear_mods();
                add_mods(MOD_BIT(KC_RALT));
                register_code(KC_RBRC);
                clear_mods();
                set_mods(modState);
            }
            return false;
        case SWE_BTIC:
            if (record->event.pressed) {
                uint8_t modState = get_mods();
                clear_mods();
                add_mods(MOD_BIT(KC_RSFT));
                register_code(KC_EQL);
                clear_mods();
                register_code(KC_SPC);
                unregister_code(KC_SPC);
                set_mods(modState);
            }
            return false;
        case SWE_FTIC:
            if (record->event.pressed) {
                uint8_t modState = get_mods();
                clear_mods();
                register_code(KC_EQL);
                clear_mods();
                register_code(KC_SPC);
                unregister_code(KC_SPC);
                set_mods(modState);
            }
            return false;
        case SWE_LGWB:
            if (record->event.pressed) {
                uint8_t modState = get_mods();
                clear_mods();
                add_mods(MOD_BIT(KC_RALT));
                register_code(KC_7);
                set_mods(modState);
            } else {
                unregister_code(KC_7);
            }
            return false;
        case SWE_RGWB:
            if (record->event.pressed) {
                uint8_t modState = get_mods();
                clear_mods();
                add_mods(MOD_BIT(KC_RALT));
                register_code(KC_0);
                set_mods(modState);
            } else {
                unregister_code(KC_0);
            }
            return false;
        case SWE_PLUS:
            if (record->event.pressed) {
                uint8_t modState = get_mods();
                clear_mods();
                register_code(KC_MINS);
                set_mods(modState);
            } else {
                unregister_code(KC_MINS);
            }
            return false;
        case SWE_AT:
            if (record->event.pressed) {
                uint8_t modState = get_mods();
                clear_mods();
                add_mods(MOD_BIT(KC_RALT));
                register_code(KC_2);
                set_mods(modState);
            } else {
                unregister_code(KC_2);
            }
            return false;
        case SWE_DOLR:
            if (record->event.pressed) {
                uint8_t modState = get_mods();
                clear_mods();
                add_mods(MOD_BIT(KC_RALT));
                register_code(KC_4);
                set_mods(modState);
            } else {
                unregister_code(KC_4);
            }
            return false;
        case SWE_PIPE:
            if (record->event.pressed) {
                uint8_t modState = get_mods();
                clear_mods();
                add_mods(MOD_BIT(KC_RALT));
                register_code(KC_NUBS);
                set_mods(modState);
            } else {
                unregister_code(KC_NUBS);
            }
            return false;
        case SWE_LT:
            if (record->event.pressed) {
                uint8_t modState = get_mods();
                clear_mods();
                register_code(KC_NUBS);
                set_mods(modState);
            } else {
                unregister_code(KC_NUBS);
            }
            return false;
        default:
            return true; /* Process all other keycodes normally */
    }
}

enum layers{
    MAC_BASE,
    MAC_FN,
    WIN_BASE,
    WIN_SHIFT,
    WIN_FN,
    WIN_SHIFT_FN
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [MAC_BASE] = LAYOUT_tkl_iso(
        KC_ESC,                         KC_F1,          KC_F2,          KC_F3,          KC_F4,          KC_F5,          KC_F6,          KC_F7,          KC_F8,          KC_F9,          KC_F10,        KC_F11,         KC_F12,         KC_PSCR,        KC_NO,          KC_MUTE,
        KC_GRV,         KC_1,           KC_2,           KC_3,           KC_4,           KC_5,           KC_6,           KC_7,           KC_8,           KC_9,           KC_0,           KC_MINS,       KC_EQL,         KC_BSPC,        KC_INS,         KC_HOME,        KC_PGUP,
        KC_TAB,         KC_Q,           KC_W,           KC_E,           KC_R,           KC_T,           KC_Y,           KC_U,           KC_I,           KC_O,           KC_P,           KC_LBRC,       KC_RBRC,                        KC_DEL,         KC_END,         KC_PGDN,
        KC_CAPS,        KC_A,           KC_S,           KC_D,           KC_F,           KC_G,           KC_H,           KC_J,           KC_K,           KC_L,           KC_SCLN,        KC_QUOT,       KC_NUHS,        KC_ENT,
        KC_LSFT,        KC_NUBS,        KC_Z,           KC_X,           KC_C,           KC_V,           KC_B,           KC_N,           KC_M,           KC_COMM,        KC_DOT,         KC_SLSH,                       KC_RSFT,                        KC_UP,
        KC_LCTL,        KC_LWIN,        KC_LALT,                                                        KC_SPC,                                                   LM(MAC_FN, MOD_RALT), KC_RWIN,       KC_APP,         KC_RCTL,        KC_LEFT,        KC_DOWN,        KC_RGHT),
																																																       
    [MAC_FN] = LAYOUT_tkl_iso(                                                                                                                                                                         
        _______,                        KC_BRID,        KC_BRIU,        KC_NO,          KC_NO,          RGB_VAD,        RGB_VAI,        KC_MPRV,        KC_MPLY,        KC_MNXT,        KC_MUTE,       KC_VOLD,        KC_VOLU,        KC_NO,          KC_NO,          RGB_TOG,
        _______,        _______,        _______,        _______,        _______,        _______,        _______,        _______,        _______,        _______,        _______,        _______,       _______,        _______,        _______,        _______,        _______,
        _______,        _______,        _______,        _______,        _______,        _______,        _______,        _______,        _______,        _______,        _______,        _______,       _______,                        _______,        _______,        _______,
        _______,        _______,        _______,        _______,        _______,        _______,        _______,        _______,        _______,        _______,        _______,        _______,       _______,        _______,                      
        _______,        _______,        _______,        _______,        _______,        _______,        _______,        _______,        _______,        _______,        _______,        _______,                       _______,                        _______,
        _______,        _______,        _______,                                                        _______,                                                        _______,        _______,       _______,        _______,        _______,        _______,        _______),

    [WIN_BASE] = LAYOUT_tkl_iso(
        KC_ESC,                         KC_F1,          KC_F2,          KC_F3,          KC_F4,          KC_F5,          KC_F6,          KC_F7,          KC_F8,          KC_F9,          KC_F10,        KC_F11,         KC_F12,         KC_PSCR,        KC_NO,          KC_MUTE,
        SWE_BTIC,       KC_1,           KC_2,           KC_3,           KC_4,           KC_5,           KC_6,           KC_7,           KC_8,           KC_9,           KC_0,           KC_SLSH,       RSFT(KC_0),     KC_BSPC,        KC_INS,         KC_HOME,        KC_PGUP,
        KC_TAB,         KC_Q,           KC_W,           KC_E,           KC_R,           KC_T,           KC_Y,           KC_U,           KC_I,           KC_O,           KC_P,           RALT(KC_8),    RALT(KC_9),                     KC_DEL,         KC_END,         KC_PGDN,
        KC_F13,         KC_A,           KC_S,           KC_D,           KC_F,           KC_G,           KC_H,           KC_J,           KC_K,           KC_L,           RSFT(KC_COMM),  KC_NUHS,       RALT(KC_MINS),  KC_ENT,
        LM(WIN_SHIFT, MOD_LSFT),KC_NUBS,KC_Z,           KC_X,           KC_C,           KC_V,           KC_B,           KC_N,           KC_M,           KC_COMM,        KC_DOT,         RSFT(KC_7),    LM(WIN_SHIFT, MOD_RSFT),                        KC_UP,
        KC_LCTL,        KC_LWIN,        KC_LALT,                                                        KC_SPC,                                                         MO(WIN_FN),     KC_RWIN,       KC_APP,         KC_RCTL,        KC_LEFT,        KC_DOWN,        KC_RGHT),

    [WIN_SHIFT] = LAYOUT_tkl_iso(
        KC_ESC,                         _______,        _______,        _______,        _______,        _______,        _______,        _______,        _______,        _______,        _______,       _______,        _______,        _______,        _______,        KC_MUTE,
        SWE_TLDE,       _______,        SWE_AT,         _______,        SWE_DOLR,       _______,        SWE_CRET,       KC_6,           KC_NUHS,        KC_8,           KC_9,           KC_SLSH,       SWE_PLUS,       KC_BSPC,        KC_INS,         KC_HOME,        KC_PGUP,
        _______,        _______,        _______,        _______,        _______,        _______,        _______,        _______,        _______,        _______,        _______,        SWE_LGWB,      SWE_RGWB,                       KC_DEL,         KC_END,         KC_PGDN,
        KC_F13,         _______,        _______,        _______,        _______,        _______,        _______,        _______,        _______,        _______,        KC_DOT,         KC_2,          SWE_PIPE,       KC_ENT,
        _______,        _______,        _______,        _______,        _______,        _______,        _______,        _______,        _______,        SWE_LT,         KC_NUBS,        KC_MINS,       KC_RSFT,                                        KC_UP,
        _______,        _______,        _______,                                                        _______,                                                      MO(WIN_SHIFT_FN), _______,       _______,        _______,        KC_LEFT,        KC_DOWN,        KC_RGHT),

    [WIN_FN] = LAYOUT_tkl_iso(
        _______,                        KC_BRID,        KC_BRIU,        _______,        _______,        RGB_VAD,        RGB_VAI,        KC_MPRV,        KC_MPLY,        KC_MNXT,        KC_MUTE,       KC_VOLD,       KC_VOLU,         _______,        _______,        RGB_TOG,
        SWE_FTIC,       KC_GRV,         RSFT(KC_GRV),   RALT(KC_3),     RSFT(KC_4),     RALT(KC_5),     _______,        _______,        _______,        _______,        _______,        _______,       _______,       _______,         _______,        _______,        _______,
        _______,        _______,        _______,        KC_QUOT,        _______,        _______,        _______,        _______,        _______,        KC_SCLN,        _______,        KC_NO,         KC_RBRC,                        _______,        _______,        _______,
        _______,        KC_LBRC,        _______,        _______,        _______,        _______,        _______,        _______,        _______,        _______,        _______,        SWE_FTIC,      _______,       _______,
        LM(WIN_SHIFT_FN, MOD_LSFT),SWE_PIPE,_______,    _______,        _______,        _______,        _______,        _______,        RALT(KC_M),     _______,        _______,        _______,       LM(WIN_SHIFT_FN, MOD_RSFT),                                     _______,
        _______,        _______,        _______,                                                        _______,                                                        _______,        _______,       _______,       _______,         _______,        _______,        _______),

    [WIN_SHIFT_FN] = LAYOUT_tkl_iso(
        _______,                        KC_BRID,        KC_BRIU,        _______,        _______,        RGB_VAD,        RGB_VAI,        KC_MPRV,        KC_MPLY,        KC_MNXT,        KC_MUTE,       KC_VOLD,       KC_VOLU,         _______,        _______,        RGB_TOG,
        _______,        KC_NO,          KC_NO,          _______,        _______,        _______,        _______,        _______,        _______,        _______,        _______,        _______,       _______,       _______,         _______,        _______,        _______,
        _______,        _______,        _______,        KC_QUOT,        _______,        _______,        _______,        _______,        _______,        KC_SCLN,        _______,        KC_NO,         SWE_TLDD,                       _______,        _______,        _______,
        _______,        KC_LBRC,        _______,        _______,        _______,        _______,        _______,        _______,        _______,        _______,        _______,        _______,       _______,       _______,
        _______,        _______,        _______,        _______,        _______,        _______,        _______,        _______,        _______,        _______,        _______,        _______,       _______,                                        _______,
        _______,        _______,        _______,                                                        _______,                                                        _______,        _______,       _______,       _______,         _______,        _______,        _______),
};
