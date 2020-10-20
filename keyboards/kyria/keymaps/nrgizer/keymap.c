/* Copyright 2020 Carl-Magnus Björkell <calle@gibberish.dk>
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

#define _COLEMAK 0
#define _SWE 1
#define _DAN 2
#define _SYMB 3
#define _NAVS 4
#define _NUM 5
#define _FUNC 6
#define _SHORT 7
#define _I3WORK 8
#define _I3MOVE 9
#define _RUNNER 10

#define HSV_BASE 27, 255, 180

enum keycodes {
  THUMBSUP = SAFE_RANGE,
  LAUGHING,
  YUM,
  OK_HAND,
  SHIFT_HOLD
};

bool is_shift_hold_active = false;
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
/*
 * Base Layer: COLEMAK
 *
 * ,-------------------------------------------.                              ,-------------------------------------------.
 * |        |      |      |      |      |      |                              |      |      |      |      |      |        |
 * |--------+------+------+------+------+------|                              |------+------+------+------+------+--------|
 * |        |      |      |      |      |      |                              |      |      |      |      |      |        |
 * |--------+------+------+------+------+------+-------------.  ,-------------+------+------+------+------+------+--------|
 * |        |      |      |      |      |      |      |      |  |      |      |      |      |      |      |      |        |
 * `----------------------+------+------+------+------+------|  |------+------+------+------+------+----------------------'
 *                        |      |      |      |      |      |  |      |      |      |      |      |
 *                        |      |      |      |      |      |  |      |      |      |      |      |
 *                        `----------------------------------'  `----------------------------------'
 */
    [_COLEMAK] = LAYOUT(
      OSL(_SWE),  KC_Q,         KC_W,         LT(_I3WORK,KC_F), LT(_I3MOVE,KC_P), KC_G,                                         KC_J, KC_L,         KC_U,         KC_Y,         KC_SCLN,    _______, \
      KC_TAB,   LSFT_T(KC_A), LCTL_T(KC_R), LALT_T(KC_S),     LT(_NAVS,KC_T),   LT(_FUNC,KC_D),                               KC_H, LGUI_T(KC_N), LALT_T(KC_E), LCTL_T(KC_I), LSFT_T(KC_O), KC_QUOT, \
      KC_LSFT,  KC_Z,         KC_X,         KC_C,             LT(_NUM,KC_V),    KC_B,   THUMBSUP, XXXXXXX, XXXXXXX, LAUGHING, KC_K, KC_M,         KC_COMM,      KC_DOT,       KC_SLSH,      KC_RSFT, \
              KC_MUTE, TG(_RUNNER), KC_DEL, LCTL_T(KC_SPC),LGUI_T(KC_ENT), KC_LEAD, KC_BSPACE, MO(_SYMB), LT(_SHORT,KC_ESCAPE), XXXXXXX

    ),

/*
 * Layer template
 *
 * ,-------------------------------------------.                              ,-------------------------------------------.
 * |        |      |      |      |      |      |                              |      |      |      |      |      |        |
 * |--------+------+------+------+------+------|                              |------+------+------+------+------+--------|
 * |        |      |      |      |      |      |                              |      |      |      |      |      |        |
 * |--------+------+------+------+------+------+-------------.  ,-------------+------+------+------+------+------+--------|
 * |        |      |      |      |      |      |      |      |  |      |      |      |      |      |      |      |        |
 * `----------------------+------+------+------+------+------|  |------+------+------+------+------+----------------------'
 *                        |      |      |      |      |      |  |      |      |      |      |      |
 *                        |      |      |      |      |      |  |      |      |      |      |      |
 *                        `----------------------------------'  `----------------------------------'
 */
    [_SWE] = LAYOUT(
      _______, _______, _______, _______, _______, _______,                                     _______, _______, _______, _______, RALT(KC_W), RALT(KC_P), \
      _______, _______, _______, _______, _______, _______,                                     _______, _______, _______, _______, _______, RALT(KC_Q), \
      _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, \
                                 _______, _______, _______, _______, _______, _______, _______, _______, _______, _______
),

/*
 * Layer template
 *
 * ,-------------------------------------------.                              ,-------------------------------------------.
 * |        |      |      |      |      |      |                              |      |      |      |      |      |        |
 * |--------+------+------+------+------+------|                              |------+------+------+------+------+--------|
 * |        |      |      |      |      |      |                              |      |      |      |      |      |        |
 * |--------+------+------+------+------+------+-------------.  ,-------------+------+------+------+------+------+--------|
 * |        |      |      |      |      |      |      |      |  |      |      |      |      |      |      |      |        |
 * `----------------------+------+------+------+------+------|  |------+------+------+------+------+----------------------'
 *                        |      |      |      |      |      |  |      |      |      |      |      |
 *                        |      |      |      |      |      |  |      |      |      |      |      |
 *                        `----------------------------------'  `----------------------------------'
 */
    [_DAN] = LAYOUT(
      _______, _______, _______, _______, _______, _______,                                     _______, _______, _______, _______, RALT(KC_W), RALT(KC_L), \
      _______, _______, _______, _______, _______, _______,                                     _______, _______, _______, _______, _______, RALT(KC_Z), \
      _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, \
                                 _______, _______, _______, _______, _______, _______, _______, _______, _______, _______
),

/*
 * Layer template
 *
 * ,-------------------------------------------.                              ,-------------------------------------------.
 * |        |      |      |      |      |      |                              |      |      |      |      |      |        |
 * |--------+------+------+------+------+------|                              |------+------+------+------+------+--------|
 * |        |      |      |      |      |      |                              |      |      |      |      |      |        |
 * |--------+------+------+------+------+------+-------------.  ,-------------+------+------+------+------+------+--------|
 * |        |      |      |      |      |      |      |      |  |      |      |      |      |      |      |      |        |
 * `----------------------+------+------+------+------+------|  |------+------+------+------+------+----------------------'
 *                        |      |      |      |      |      |  |      |      |      |      |      |
 *                        |      |      |      |      |      |  |      |      |      |      |      |
 *                        `----------------------------------'  `----------------------------------'
 */
    [_SYMB] = LAYOUT(
      _______, KC_CIRC, KC_DLR,  KC_LCBR, KC_RCBR, KC_HASH,                                               KC_AMPR, KC_EXLM, KC_QUES, KC_UNDS, KC_SCOLON, _______, \
      _______, KC_COLN, KC_EQL,  KC_LPRN, KC_RPRN, KC_AT,                                                 KC_DQUO, KC_PLUS, KC_ASTR, KC_MINUS, KC_GRAVE, KC_QUOTE, \
      _______, KC_EXLM, KC_PERC, KC_LBRC, LT(_NUM, KC_RBRC), KC_TILD, OK_HAND, _______, _______, _______, KC_BSLASH, KC_PIPE, KC_LABK, KC_RABK, _______, _______, \
                                 _______, _______, _______, _______, _______, _______, _______, _______, _______, _______
),

/*
 * Layer template
 *
 * ,-------------------------------------------.                              ,-------------------------------------------.
 * |        |      |      |      |      |      |                              |      |      |      |      |      |        |
 * |--------+------+------+------+------+------|                              |------+------+------+------+------+--------|
 * |        |      |      |      |      |      |                              |      |      |      |      |      |        |
 * |--------+------+------+------+------+------+-------------.  ,-------------+------+------+------+------+------+--------|
 * |        |      |      |      |      |      |      |      |  |      |      |      |      |      |      |      |        |
 * `----------------------+------+------+------+------+------|  |------+------+------+------+------+----------------------'
 *                        |      |      |      |      |      |  |      |      |      |      |      |
 *                        |      |      |      |      |      |  |      |      |      |      |      |
 *                        `----------------------------------'  `----------------------------------'
 */
    [_NAVS] = LAYOUT(
      _______,   _______, _______, _______, _______, _______,                                     XXXXXXX, KC_PGUP, KC_UP,  KC_PGDOWN, XXXXXXX, TO(_COLEMAK), \
      _______, _______, _______, _______, _______, _______,                                     KC_HOME, KC_LEFT, KC_DOWN, KC_RIGHT, KC_END,  _______, \
      _______, _______, _______, _______, _______, _______, _______, _______, _______, YUM    , KC_INSERT, LALT(LSFT(KC_LEFT)),LALT(KC_1), LALT(LSFT(KC_RIGHT)), XXXXXXX,  _______, \
                                 _______, _______, _______, _______, _______, _______, _______, _______, _______, _______
),

/*
 * Layer template
 *
 * ,-------------------------------------------.                              ,-------------------------------------------.
 * |        |      |      |      |      |      |                              |      |      |      |      |      |        |
 * |--------+------+------+------+------+------|                              |------+------+------+------+------+--------|
 * |        |      |      |      |      |      |                              |      |      |      |      |      |        |
 * |--------+------+------+------+------+------+-------------.  ,-------------+------+------+------+------+------+--------|
 * |        |      |      |      |      |      |      |      |  |      |      |      |      |      |      |      |        |
 * `----------------------+------+------+------+------+------|  |------+------+------+------+------+----------------------'
 *                        |      |      |      |      |      |  |      |      |      |      |      |
 *                        |      |      |      |      |      |  |      |      |      |      |      |
 *                        `----------------------------------'  `----------------------------------'
 */
    [_NUM] = LAYOUT(
      _______, _______, _______, _______, _______, _______,                                     KC_ASTR, KC_7,    KC_8,    KC_9, KC_SLSH, TO(_COLEMAK), \
      _______, _______, _______, _______, _______, _______,                                     KC_PLUS, KC_4,    KC_5,    KC_6, KC_MINS, _______, \
      _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, KC_COLN, KC_1,    KC_2,    KC_3, KC_DOT,  _______, \
                                 _______, _______, _______, _______, _______, _______, _______, KC_0,    _______, _______
    ),

/*
 * Func Layer
 *
 * ,-------------------------------------------.                              ,-------------------------------------------.
 * |        |      |      |      |      |      |                              |      | F7   | F8   | F9   | F10  |        |
 * |--------+------+------+------+------+------|                              |------+------+------+------+------+--------|
 * |        |      |      |      |      |      |                              |      | F4   | F5   | F6   | F11  |        |
 * |--------+------+------+------+------+------+-------------.  ,-------------+------+------+------+------+------+--------|
 * |        |      |      |      |      |      |      |      |  |      |      |      | F1   | F2   | F3   | F12  |        |
 * `----------------------+------+------+------+------+------|  |------+------+------+------+------+----------------------'
 *                        |      |      |      |      |      |  |      |      |      |      |      |
 *                        |      |      |      |      |      |  |      |      |      |      |      |
 *                        `----------------------------------'  `----------------------------------'
 */
    [_FUNC] = LAYOUT(
      _______, _______, _______, _______, _______, _______,                                     _______, KC_F7,   KC_F8,   KC_F9,   KC_F10,  _______, \
      _______, _______, _______, _______, _______, _______,                                     _______, KC_F4,   KC_F5,   KC_F6,   KC_F11,  _______, \
      _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, KC_F1,   KC_F2,   KC_F3,   KC_F12,  _______, \
                                 _______, _______, _______, _______, _______, _______, _______, _______, _______, _______
    ),


 /*
  * Layer template
  *
  * ,-------------------------------------------.                              ,-------------------------------------------.
  * |        |      |      |      |      |      |                              |      |      |      |      |      |        |
  * |--------+------+------+------+------+------|                              |------+------+------+------+------+--------|
  * |        |      |      |      |      |      |                              |      |      |      |      |      |        |
  * |--------+------+------+------+------+------+-------------.  ,-------------+------+------+------+------+------+--------|
  * |        |      |      |      |      |      |      |      |  |      |      |      |      |      |      |      |        |
  * `----------------------+------+------+------+------+------|  |------+------+------+------+------+----------------------'
  *                        |      |      |      |      |      |  |      |      |      |      |      |
  *                        |      |      |      |      |      |  |      |      |      |      |      |
  *                        `----------------------------------'  `----------------------------------'
  */
     [_SHORT] = LAYOUT(
       _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_VOLU,                                                           XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, _______, DYN_REC_START1, \
       _______, KC_MPRV, KC_MSTP, KC_MEDIA_PLAY_PAUSE, KC_MNXT, KC_VOLD,                                               XXXXXXX, TO(_COLEMAK), TO(_SWE), TO(_DAN), XXXXXXX, DYN_REC_STOP, \
       _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_MUTE, _______, _______, _______, _______, _______, TO(_NAVS), XXXXXXX, TO(_NUM),  XXXXXXX, DYN_MACRO_PLAY1, \
                                  SHIFT_HOLD, _______, LALT(LSFT(KC_X)), _______, _______, _______, _______, _______, _______, _______
     ),

 /*
  * Layer template
  *
  * ,-------------------------------------------.                              ,-------------------------------------------.
  * |        |      |      |      |      |      |                              |      |      |      |      |      |        |
  * |--------+------+------+------+------+------|                              |------+------+------+------+------+--------|
  * |        |      |      |      |      |      |                              |      |      |      |      |      |        |
  * |--------+------+------+------+------+------+-------------.  ,-------------+------+------+------+------+------+--------|
  * |        |      |      |      |      |      |      |      |  |      |      |      |      |      |      |      |        |
  * `----------------------+------+------+------+------+------|  |------+------+------+------+------+----------------------'
  *                        |      |      |      |      |      |  |      |      |      |      |      |
  *                        |      |      |      |      |      |  |      |      |      |      |      |
  *                        `----------------------------------'  `----------------------------------'
  */
     [_I3WORK] = LAYOUT(
       _______, _______, _______, _______, LGUI(KC_TAB), _______,                                XXXXXXX, LGUI(KC_7), LGUI(KC_8), LGUI(KC_9), XXXXXXX, _______, \
       _______, _______, _______, _______, _______, _______,                                     LALT(LGUI(KC_LEFT)), LGUI(KC_4), LGUI(KC_5), LGUI(KC_6), LALT(LGUI(KC_RIGHT)), _______, \
       _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, XXXXXXX, LGUI(KC_1), LGUI(KC_2), LGUI(KC_3), XXXXXXX, _______, \
                                  _______, _______, LCTL(LSFT(KC_PSCREEN)), _______, _______, _______, _______, LGUI(KC_0), _______,    _______
     ),

 /*
  * Layer template
  *
  * ,-------------------------------------------.                              ,-------------------------------------------.
  * |        |      |      |      |      |      |                              |      |      |      |      |      |        |
  * |--------+------+------+------+------+------|                              |------+------+------+------+------+--------|
  * |        |      |      |      |      |      |                              |      |      |      |      |      |        |
  * |--------+------+------+------+------+------+-------------.  ,-------------+------+------+------+------+------+--------|
  * |        |      |      |      |      |      |      |      |  |      |      |      |      |      |      |      |        |
  * `----------------------+------+------+------+------+------|  |------+------+------+------+------+----------------------'
  *                        |      |      |      |      |      |  |      |      |      |      |      |
  *                        |      |      |      |      |      |  |      |      |      |      |      |
  *                        `----------------------------------'  `----------------------------------'
  */
     [_I3MOVE] = LAYOUT(
       _______, _______, _______, _______, _______, _______,                                     _______, LGUI(KC_PGUP), LGUI(KC_UP), _______, _______, _______, \
       _______, _______, _______, _______, _______, _______,                                     _______, LGUI(KC_LEFT), LGUI(KC_DOWN), LGUI(KC_RIGHT), _______, _______, \
       _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, \
                                  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______
     ),

 /*
  * Runner/debug Layer
  *
  * ,-------------------------------------------.                              ,-------------------------------------------.
  * |        |      |      |      |      |      |                              |      |      |      |      |      |        |
  * |--------+------+------+------+------+------|                              |------+------+------+------+------+--------|
  * |        |      |      |      |      |      |                              |      |      |      |      |      |        |
  * |--------+------+------+------+------+------+-------------.  ,-------------+------+------+------+------+------+--------|
  * |        |      |      |      |      |      |      |      |  |      |      |      |      |      |      |      |        |
  * `----------------------+------+------+------+------+------|  |------+------+------+------+------+----------------------'
  *                        |      |      |      |      |      |  |      |      |      |      |      |
  *                        |      |      |      |      |      |  |      |      |      |      |      |
  *                        `----------------------------------'  `----------------------------------'
  */
     [_RUNNER] = LAYOUT(
       XXXXXXX, LCTL(KC_F2), LCTL(LSFT(KC_F11)), LCTL(KC_F5), LCTL(LSFT(KC_F9)), LCTL(LSFT(KC_F10)),       _______, _______, _______, _______, _______, _______, \
       _______, XXXXXXX, LSFT(KC_F8), KC_F7, KC_F8, KC_F9  ,                                     _______, _______, _______, _______, _______, _______, \
       _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, \
                                  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______
     ),

// /*
//  * Layer template
//  *
//  * ,-------------------------------------------.                              ,-------------------------------------------.
//  * |        |      |      |      |      |      |                              |      |      |      |      |      |        |
//  * |--------+------+------+------+------+------|                              |------+------+------+------+------+--------|
//  * |        |      |      |      |      |      |                              |      |      |      |      |      |        |
//  * |--------+------+------+------+------+------+-------------.  ,-------------+------+------+------+------+------+--------|
//  * |        |      |      |      |      |      |      |      |  |      |      |      |      |      |      |      |        |
//  * `----------------------+------+------+------+------+------|  |------+------+------+------+------+----------------------'
//  *                        |      |      |      |      |      |  |      |      |      |      |      |
//  *                        |      |      |      |      |      |  |      |      |      |      |      |
//  *                        `----------------------------------'  `----------------------------------'
//  */
//     [_LAYERINDEX] = LAYOUT(
//       _______, _______, _______, _______, _______, _______,                                     _______, _______, _______, _______, _______, _______,
//       _______, _______, _______, _______, _______, _______,                                     _______, _______, _______, _______, _______, _______,
//       _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
//                                  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______
//     ),
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    if (record->event.pressed) {
        switch(keycode) {
            case THUMBSUP:
                SEND_STRING(":thumbsup:");
                return false;
            case LAUGHING:
                SEND_STRING(":laughing:");
                return false;
            case YUM:
                SEND_STRING(":yum:");
                return false;
            case OK_HAND:
                SEND_STRING(":ok_hand:");
                return false;
            case SHIFT_HOLD:
                if (is_shift_hold_active) {
                    unregister_code(KC_LSFT);
                } else {
                    register_code(KC_LSFT);
                }
                is_shift_hold_active = !is_shift_hold_active;
                return false;
        }
    }
    return true;
}

LEADER_EXTERNS();

void matrix_scan_user(void) {
    LEADER_DICTIONARY() {
        leading = false;
        leader_end();

        SEQ_ONE_KEY(KC_C) { // Markdown code
            SEND_STRING("`` " SS_TAP(X_LEFT) SS_TAP(X_LEFT));
        }
        SEQ_TWO_KEYS(KC_C, KC_B) { // Markdown code block
            SEND_STRING("```" SS_LSFT(SS_TAP(X_ENTER) SS_TAP(X_ENTER)) "``` " SS_TAP(X_UP));
        }
        SEQ_TWO_KEYS(KC_E, KC_N) { // if not nil
            SEND_STRING("if err != nil {" SS_TAP(X_ENTER));
        }
        SEQ_TWO_KEYS(KC_S, KC_K) { // kill ssh sessions
            SEND_STRING(SS_TAP(X_ENTER) "~.");
        }
    }
}

uint16_t get_tapping_term(uint16_t keycode) {
  switch (keycode) {
    case LT(_NUM,KC_V):
      return 150;
    case LSFT_T(KC_A):
      return TAPPING_TERM + 50;
    default:
      return TAPPING_TERM;
  }
}

void rgblight_set_hsv_and_mode(uint8_t hue, uint8_t sat, uint8_t val, uint8_t mode) {
    rgblight_sethsv_noeeprom(hue, sat, val);
    wait_us(175);  // Add a slight delay between color and mode to ensure it's processed correctly
    rgblight_mode_noeeprom(mode);
}

void keyboard_post_init_user(void){
    rgblight_enable_noeeprom();
    rgblight_set_hsv_and_mode(HSV_BASE, RGBLIGHT_MODE_STATIC_LIGHT);
}

#ifdef OLED_DRIVER_ENABLE
oled_rotation_t oled_init_user(oled_rotation_t rotation) {
	return OLED_ROTATION_180;
}

static void render_kyria_logo(void) {
    static const char PROGMEM kyria_logo[] = {
        0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,128,128,192,224,240,112,120, 56, 60, 28, 30, 14, 14, 14,  7,  7,  7,  7,  7,  7,  7,  7,  7,  7,  7,  7,  7,  7,  7,  7, 14, 14, 14, 30, 28, 60, 56,120,112,240,224,192,128,128,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,
        0,  0,  0,  0,  0,  0,  0,192,224,240,124, 62, 31, 15,  7,  3,  1,128,192,224,240,120, 56, 60, 28, 30, 14, 14,  7,  7,135,231,127, 31,255,255, 31,127,231,135,  7,  7, 14, 14, 30, 28, 60, 56,120,240,224,192,128,  1,  3,  7, 15, 31, 62,124,240,224,192,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,
        0,  0,  0,  0,240,252,255, 31,  7,  1,  0,  0,192,240,252,254,255,247,243,177,176, 48, 48, 48, 48, 48, 48, 48,120,254,135,  1,  0,  0,255,255,  0,  0,  1,135,254,120, 48, 48, 48, 48, 48, 48, 48,176,177,243,247,255,254,252,240,192,  0,  0,  1,  7, 31,255,252,240,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,
        0,  0,  0,255,255,255,  0,  0,  0,  0,  0,254,255,255,  1,  1,  7, 30,120,225,129,131,131,134,134,140,140,152,152,177,183,254,248,224,255,255,224,248,254,183,177,152,152,140,140,134,134,131,131,129,225,120, 30,  7,  1,  1,255,255,254,  0,  0,  0,  0,  0,255,255,255,  0,  0,  0,  0,255,255,  0,  0,192,192, 48, 48,  0,  0,240,240,  0,  0,  0,  0,  0,  0,240,240,  0,  0,240,240,192,192, 48, 48, 48, 48,192,192,  0,  0, 48, 48,243,243,  0,  0,  0,  0,  0,  0, 48, 48, 48, 48, 48, 48,192,192,  0,  0,  0,  0,  0,
        0,  0,  0,255,255,255,  0,  0,  0,  0,  0,127,255,255,128,128,224,120, 30,135,129,193,193, 97, 97, 49, 49, 25, 25,141,237,127, 31,  7,255,255,  7, 31,127,237,141, 25, 25, 49, 49, 97, 97,193,193,129,135, 30,120,224,128,128,255,255,127,  0,  0,  0,  0,  0,255,255,255,  0,  0,  0,  0, 63, 63,  3,  3, 12, 12, 48, 48,  0,  0,  0,  0, 51, 51, 51, 51, 51, 51, 15, 15,  0,  0, 63, 63,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0, 48, 48, 63, 63, 48, 48,  0,  0, 12, 12, 51, 51, 51, 51, 51, 51, 63, 63,  0,  0,  0,  0,  0,
        0,  0,  0,  0, 15, 63,255,248,224,128,  0,  0,  3, 15, 63,127,255,239,207,141, 13, 12, 12, 12, 12, 12, 12, 12, 30,127,225,128,  0,  0,255,255,  0,  0,128,225,127, 30, 12, 12, 12, 12, 12, 12, 12, 13,141,207,239,255,127, 63, 15,  3,  0,  0,128,224,248,255, 63, 15,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,
        0,  0,  0,  0,  0,  0,  0,  3,  7, 15, 62,124,248,240,224,192,128,  1,  3,  7, 15, 30, 28, 60, 56,120,112,112,224,224,225,231,254,248,255,255,248,254,231,225,224,224,112,112,120, 56, 60, 28, 30, 15,  7,  3,  1,128,192,224,240,248,124, 62, 15,  7,  3,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,
        0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  1,  1,  3,  7, 15, 14, 30, 28, 60, 56,120,112,112,112,224,224,224,224,224,224,224,224,224,224,224,224,224,224,224,224,112,112,112,120, 56, 60, 28, 30, 14, 15,  7,  3,  1,  1,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0
    };
    oled_write_raw_P(kyria_logo, sizeof(kyria_logo));
}

static void render_qmk_logo(void) {
  static const char PROGMEM qmk_logo[] = {
    0x80,0x81,0x82,0x83,0x84,0x85,0x86,0x87,0x88,0x89,0x8a,0x8b,0x8c,0x8d,0x8e,0x8f,0x90,0x91,0x92,0x93,0x94,
    0xa0,0xa1,0xa2,0xa3,0xa4,0xa5,0xa6,0xa7,0xa8,0xa9,0xaa,0xab,0xac,0xad,0xae,0xaf,0xb0,0xb1,0xb2,0xb3,0xb4,
    0xc0,0xc1,0xc2,0xc3,0xc4,0xc5,0xc6,0xc7,0xc8,0xc9,0xca,0xcb,0xcc,0xcd,0xce,0xcf,0xd0,0xd1,0xd2,0xd3,0xd4,0};

  oled_write_P(qmk_logo, false);
}

layer_state_t layer_state_set_user(layer_state_t state) {
#if defined(RGBLIGHT_ENABLE)
    switch (get_highest_layer(state)) {
        case _RUNNER:
            rgblight_set_hsv_and_mode(HSV_BLUE, RGBLIGHT_MODE_BREATHING + 2);
            break;
        default:  //  for any other layers, or the default layer
            rgblight_set_hsv_and_mode(HSV_BASE, RGBLIGHT_MODE_STATIC_LIGHT);
            break;
    }
#endif
    return state;
}

static void render_status(void) {
    // QMK Logo and version information
    render_qmk_logo();
    oled_write_P(PSTR("       Calle's Kyria\n\n"), false);

    // Host Keyboard Layer Status
    oled_write_P(PSTR("Layer: "), false);
    switch (get_highest_layer(layer_state)) {
        case _COLEMAK:
            oled_write_P(PSTR("Colemak\n"), false);
            break;
        case _SWE:
            oled_write_P(PSTR("Swedish\n"), false);
            break;
        case _DAN:
            oled_write_P(PSTR("Danish\n"), false);
            break;
        case _NAVS:
            oled_write_P(PSTR("Navigation\n"), false);
            break;
        case _SYMB:
            oled_write_P(PSTR("Symbols\n"), false);
            break;
        case _NUM:
            oled_write_P(PSTR("Numpad\n"), false);
            break;
        case _FUNC:
            oled_write_P(PSTR("Function\n"), false);
            break;
        case _I3MOVE:
            oled_write_P(PSTR("i3 Move\n"), false);
            break;
        case _I3WORK:
            oled_write_P(PSTR("i3 Workspace\n"), false);
            break;
        case _SHORT:
            oled_write_P(PSTR("Shortcuts\n"), false);
            break;
        case _RUNNER:
            oled_write_P(PSTR("Debug\n"), false);
            break;
        default:
            oled_write_P(PSTR("Undefined\n"), false);
    }

    // Host Keyboard LED Status
    uint8_t led_usb_state = host_keyboard_leds();
    oled_write_P(led_usb_state & (1<<USB_LED_NUM_LOCK) ? PSTR("NUMLCK ") : PSTR("       "), false);
    oled_write_P(led_usb_state & (1<<USB_LED_CAPS_LOCK) ? PSTR("CAPLCK ") : PSTR("       "), false);
    oled_write_P(led_usb_state & (1<<USB_LED_SCROLL_LOCK) ? PSTR("SCRLCK ") : PSTR("       "), false);
}

void oled_task_user(void) {
    if (is_keyboard_master()) {
        render_status(); // Renders the current keyboard state (layer, lock, caps, scroll, etc)
    } else {
        render_kyria_logo();
    }
}
#endif

#ifdef ENCODER_ENABLE
void encoder_update_user(uint8_t index, bool clockwise) {
    if (index == 0) {
        switch (get_highest_layer(layer_state)) {
            case _COLEMAK:
            case _SWE:
            case _DAN:
                if (clockwise) {
                    tap_code(KC_VOLD);
                } else {
                    tap_code(KC_VOLU);
                }
                break;
            default:
                // Move whole words. Hold shift to select while moving.
                if (clockwise) {
                    SEND_STRING(SS_DOWN(X_LCTRL)SS_TAP(X_LEFT)SS_UP(X_LCTRL));
                } else {
                    SEND_STRING(SS_DOWN(X_LCTRL)SS_TAP(X_RIGHT)SS_UP(X_LCTRL));
                }
                break;
        }
    } else if (index == 1) {
        switch (get_highest_layer(layer_state)) {
            case _COLEMAK:
            case _SWE:
            case _DAN:
                if (clockwise) {
                    tap_code(KC_MS_WH_DOWN);
                } else {
                    tap_code(KC_MS_WH_UP);
                }
                break;
            default:
                if (clockwise) {
                    tap_code(KC_MS_WH_RIGHT);
                } else {
                    tap_code(KC_MS_WH_LEFT);
                }
                break;
        }
    }
}
#endif
