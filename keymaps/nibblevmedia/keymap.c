/* Copyright 2020 Jay Greco
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
 *
 * Add Key Media, Copy past Undo 
 */
#include QMK_KEYBOARD_H

enum layer_names {
  _MA,
  _FN1,
  _FN2
};

enum custom_keycodes {
  KC_CUST = SAFE_RANGE,
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [_MA] = LAYOUT_ansi(
            KC_ESC,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_MINS, KC_EQL,  KC_BSPC, KC_HOME,
    RGB_MOD, KC_TAB,  KC_Q,   KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_LBRC, KC_RBRC, KC_BSLS, KC_DEL,
    KC_F14, KC_CAPS, KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT,          KC_ENT,  KC_PGUP,
    LCTL(KC_C), KC_LSFT, KC_Z,KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_RSFT,          KC_UP,   KC_PGDN,
    LCTL(KC_V), KC_LCTL, KC_LGUI, KC_LALT,                   KC_SPC,                    KC_RALT, MO(_FN1), MO(_FN2), KC_LEFT,          KC_DOWN, KC_RGHT
  ),
  
  [_FN1] = LAYOUT_ansi(
               RESET,   KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,  KC_F10,  KC_F11,  KC_F12,  KC_DEL,  KC_END,
   RGB_TOG,_______, RALT(KC_Q), RALT(KC_W), RALT(KC_E),RALT(KC_R), _______, _______, RALT(KC_U),RALT(KC_I),RALT(KC_O), _______, KC_LPRN, KC_RPRN, KC_ASTR, KC_INS,
    _______, _______,RALT(KC_A),RALT(KC_S),RALT(KC_D), _______, _______, _______, _______, _______, _______, _______, KC_AT,            _______, KC_HOME,
    LCTL(KC_X), _______, _______,_______, RALT(KC_C), _______, _______, RALT(KC_N), _______, KC_LPRN, KC_RPRN, KC_EXLM, _______,          _______, KC_END,
    C_S_T(KC_T), _______, _______, _______,                   KC_MPLY,                   _______, _______, _______,          KC_MPRV, KC_MPLY, KC_MNXT
  ),
  
  [_FN2] = LAYOUT_ansi(
            EEP_RST,RGB_M_SW,RGB_M_SN,RGB_M_K,  RGB_M_G, RGB_M_X, RGB_M_P, RGB_M_R, RGB_M_B, RGB_M_T, _______, _______, _______,  KC_DEL,  KC_END,
    RGB_TOG,_______, RALT(KC_Q), RALT(KC_W), RALT(KC_E),RALT(KC_R), _______, _______, RALT(KC_U),RALT(KC_I),RALT(KC_O), _______, KC_LPRN, KC_RPRN, KC_ASTR, KC_INS,
    _______, _______,RALT(KC_A),RALT(KC_S),RALT(KC_D), _______, _______, _______, _______, _______, _______, _______, KC_AT,            _______, KC_HOME,
    LCTL(KC_Z), _______, _______,_______, RALT(KC_C), _______, _______, RALT(KC_N), _______, KC_LPRN, KC_RPRN, KC_EXLM, _______,          _______, KC_END,
    LCTL(KC_Y), _______, _______, _______,                   KC_MPLY,                   _______, _______, _______,          KC_MPRV, KC_MPLY, KC_MNXT
  ),

};
 
bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  // Send keystrokes to host keyboard, if connected (see readme)
  process_record_remote_kb(keycode, record);
  switch(keycode) {
    case KC_CUST: //custom macro
      if (record->event.pressed) {
      }
    break;

    case RM_1: //remote macro 1
      if (record->event.pressed) {
      }
    break;

    case RM_2: //remote macro 2
      if (record->event.pressed) {
      }
    break;

    case RM_3: //remote macro 3
      if (record->event.pressed) {
      }
    break;

    case RM_4: //remote macro 4
      if (record->event.pressed) {
      }
    break;

  }
return true;
}

// RGB config, for changing RGB settings on non-VIA firmwares
void change_RGB(bool clockwise) {
    bool shift = get_mods() & MOD_MASK_SHIFT;
    bool alt = get_mods() & MOD_MASK_ALT;
    bool ctrl = get_mods() & MOD_MASK_CTRL;

    if (clockwise) {
        if (alt) {
            rgblight_increase_hue();
        } else if (ctrl) {
            rgblight_increase_val();
        } else if (shift) {
            rgblight_increase_sat();
        } else {
            rgblight_step();
        }

  } else {
      if (alt) {
            rgblight_decrease_hue();
        } else if (ctrl) {
            rgblight_decrease_val();
        } else if (shift) {
            rgblight_decrease_sat();
        } else {
            rgblight_step_reverse();
        }
    }
}

void encoder_update_user(uint8_t index, bool clockwise) {
  if (layer_state_is(1)) {
    //change RGB settings
    change_RGB(clockwise);
  }
  else {
    if (clockwise) {
      tap_code(KC_VOLU);
  } else {
      tap_code(KC_VOLD);
    }
  }
}

void matrix_init_user(void) {
  // Initialize remote keyboard, if connected (see readme)
  matrix_init_remote_kb();
}

void matrix_scan_user(void) {
  // Scan and parse keystrokes from remote keyboard, if connected (see readme)
  matrix_scan_remote_kb();
   }
