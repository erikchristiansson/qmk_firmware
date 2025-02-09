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

Pressing AltGr+Shift+Pause switches the board to a standard layout,
except for the Pause key that brings back the base layout.
*/

#include QMK_KEYBOARD_H

enum my_keycodes {
    SWE_CRET = SAFE_RANGE, /* ^ RSFT(KC_RBRC) followed by KC_SPC */
    SWE_TLDE,              /* ~ RALT(KC_RBRC) followed by KC_SPC */
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
    BASE,
    SHIFT,
    ALTGR,
    SHIFT_ALTGR,
    STANDARD
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
	[BASE] = LAYOUT(
		KC_ESC,                         KC_F1,          KC_F2,          KC_F3,          KC_F4,          KC_F5,          KC_F6,          KC_F7,          KC_F8,          KC_F9,          KC_F10,         KC_F11,         KC_F12,         KC_PSCR,        KC_NO,          KC_MUTE,
		SWE_BTIC,       KC_1,           KC_2,           KC_3,           KC_4,           KC_5,           KC_6,           KC_7,           KC_8,           KC_9,           KC_0,           KC_SLSH,        RSFT(KC_0),     KC_BSPC,        KC_INS,         KC_HOME,        KC_PGUP,
		KC_TAB,         KC_Q,           KC_W,           KC_E,           KC_R,           KC_T,           KC_Y,           KC_U,           KC_I,           KC_O,           KC_P,           RALT(KC_8),     RALT(KC_9),     RALT(KC_MINS),  KC_DEL,         KC_END,         KC_PGDN,
		KC_F13,         KC_A,           KC_S,           KC_D,           KC_F,           KC_G,           KC_H,           KC_J,           KC_K,           KC_L,           RSFT(KC_COMM),  KC_NUHS,                        KC_ENT,                                         
		LM(SHIFT, MOD_LSFT),KC_NUBS,    KC_Z,           KC_X,           KC_C,           KC_V,           KC_B,           KC_N,           KC_M,           KC_COMM,        KC_DOT,         RSFT(KC_7),     LM(SHIFT, MOD_RSFT),                            KC_UP,          
		KC_LCTL,        KC_LWIN,        KC_LALT,                                                                        KC_SPC,                                         MO(ALTGR),      KC_RWIN,        KC_APP,         KC_RCTL,        KC_LEFT,        KC_DOWN,        KC_RGHT),

	[SHIFT] = LAYOUT(
		KC_ESC,                         RSFT(KC_F1),    RSFT(KC_F2),    RSFT(KC_F3),    RSFT(KC_F4),    RSFT(KC_F5),    RSFT(KC_F6),    RSFT(KC_F7),    RSFT(KC_F8),    RSFT(KC_F9),    RSFT(KC_F10),   RSFT(KC_F11),   RSFT(KC_F12),   _______,        _______,        KC_MUTE,
		SWE_TLDE,       RSFT(KC_1),     SWE_AT,         RSFT(KC_3),     SWE_DOLR,       RSFT(KC_5),     SWE_CRET,       RSFT(KC_6),     RSFT(KC_NUHS),  RSFT(KC_8),     RSFT(KC_9),     RSFT(KC_SLSH),  SWE_PLUS,       RSFT(KC_BSPC),  RSFT(KC_INS),   RSFT(KC_HOME),  RSFT(KC_PGUP),
		RSFT(KC_TAB),   RSFT(KC_Q),     RSFT(KC_W),     RSFT(KC_E),     RSFT(KC_R),     RSFT(KC_T),     RSFT(KC_Y),     RSFT(KC_U),     RSFT(KC_I),     RSFT(KC_O),     RSFT(KC_P),     SWE_LGWB,       SWE_RGWB,       SWE_PIPE,       RSFT(KC_DEL),   RSFT(KC_END),   RSFT(KC_PGDN),
		RSFT(KC_F13),   RSFT(KC_A),     RSFT(KC_S),     RSFT(KC_D),     RSFT(KC_F),     RSFT(KC_G),     RSFT(KC_H),     RSFT(KC_J),     RSFT(KC_K),     RSFT(KC_L),     RSFT(KC_DOT),   RSFT(KC_2),                     RSFT(KC_ENT),                                   
		KC_LSFT,        RSFT(KC_NUBS),  RSFT(KC_Z),     RSFT(KC_X),     RSFT(KC_C),     RSFT(KC_V),     RSFT(KC_B),     RSFT(KC_N),     RSFT(KC_M),     SWE_LT,         RSFT(KC_NUBS),  RSFT(KC_MINS),  KC_RSFT,                                        RSFT(KC_UP),    
		RSFT(KC_LCTL),  RSFT(KC_LWIN),  RSFT(KC_LALT),                                                                  RSFT(KC_SPC),                        LM(SHIFT_ALTGR, MOD_RSFT), RSFT(KC_RWIN),  RSFT(KC_APP),   RSFT(KC_RCTL),  RSFT(KC_LEFT),  RSFT(KC_DOWN),  RSFT(KC_RGHT)),

	[ALTGR] = LAYOUT(                                                                                                                                                                                                                                                      
		_______,                        KC_BRID,        KC_BRIU,        _______,        _______,        _______,        _______,        KC_MPRV,        KC_MPLY,        KC_MNXT,        KC_MUTE,        KC_VOLD,        KC_VOLU,        _______,        _______,        _______,
		KC_GRV,         _______,        _______,        RALT(KC_3),     RSFT(KC_4),     RALT(KC_5),     _______,        _______,        _______,        _______,        _______,        _______,        _______,        _______,        _______,        _______,        _______,
		_______,        _______,        _______,        KC_QUOT,        _______,        _______,        _______,        _______,        _______,        KC_SCLN,        _______,        _______,        KC_RBRC,        SWE_FTIC,       _______,        _______,        _______,
		_______,        KC_LBRC,        _______,        _______,        _______,        _______,        _______,        _______,        _______,        _______,        _______,        _______,                        _______,                                        
		LM(SHIFT_ALTGR, MOD_LSFT),SWE_PIPE,_______,     _______,        _______,        _______,        _______,        _______,        _______,        _______,        _______,        _______, LM(SHIFT_ALTGR, MOD_RSFT),                             _______,        
		_______,        _______,        _______,                                                                        _______,                                        _______,        _______,        _______,        _______,        _______,        _______,        _______),

	[SHIFT_ALTGR] = LAYOUT(                                                                                                                                                                                                                                                
		_______,                        KC_BRID,        KC_BRIU,        _______,        _______,        _______,        _______,        KC_MPRV,        KC_MPLY,        KC_MNXT,        KC_MUTE,        KC_VOLD,        KC_VOLU,        _______,        _______,        TG(STANDARD),
		KC_GRV,         _______,        _______,        _______,        _______,        _______,        _______,        _______,        _______,        _______,        _______,        _______,        _______,        _______,        _______,        _______,        _______,
		_______,        _______,        _______,        KC_QUOT,        _______,        _______,        _______,        _______,        _______,        KC_SCLN,        _______,        _______,        KC_RBRC,        SWE_FTIC,       _______,        _______,        _______,
		_______,        KC_LBRC,        _______,        _______,        _______,        _______,        _______,        _______,        _______,        _______,        _______,        _______,                        _______,                                        
		_______,        _______,        _______,        _______,        _______,        _______,        _______,        _______,        _______,        _______,        _______,        _______,        _______,                                        _______,        
		_______,        _______,        _______,                                                                        _______,                                        _______,        _______,        _______,        _______,        _______,        _______,        _______),

	[STANDARD] = LAYOUT(
		KC_ESC,           KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,     KC_PSCR, KC_SCRL, TG(STANDARD),
		KC_GRV,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_MINS, KC_EQL,  KC_BSPC,    KC_INS,  KC_HOME, KC_PGUP,
		KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_LBRC, KC_RBRC, KC_BSLS,    KC_DEL,  KC_END,  KC_PGDN,
		KC_CAPS, KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT,          KC_ENT,
		KC_LSFT, KC_NUBS, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH,          KC_RSFT,             KC_UP,
		KC_LCTL, KC_LGUI, KC_LALT,                            KC_SPC,                             KC_RALT, KC_RGUI, KC_MENU, KC_RCTL,    KC_LEFT, KC_DOWN, KC_RGHT
	),
};