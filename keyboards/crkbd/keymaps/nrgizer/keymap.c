#include QMK_KEYBOARD_H

#ifdef RGB_MATRIX_ENABLE
  #include "rgb_matrix.h"
#endif

#ifdef RGBLIGHT_ENABLE
//Following line allows macro to read current RGB settings
extern rgblight_config_t rgblight_config;
#endif

extern uint8_t is_master;

// Each layer gets a name for readability, which is then used in the keymap matrix below.
// The underscores don't mean anything - you can have a layer called STUFF or any other name.
// Layer names don't all need to be of the same length, obviously, and you can also skip them
// entirely and just use numbers.
#define _COLEMAK 0
#define _SWE 1
#define _DAN 2
#define _SYMB 3
#define _NAVS 4
#define _LNAVS 5
#define _NUM 6
#define _FUNC 7
#define _SHORT 8
#define _I3WORK 9
#define _I3MOVE 10


enum custom_keycodes {
  DYNAMIC_MACRO_RANGE = SAFE_RANGE,
  RGBRST
};

#include "dynamic_macro.h"

#define ROFI_W LCTL(LGUI(KC_SPACE))

//Mod-tap
#define SHFT_A LSFT_T(KC_A)
#define SHFT_O LSFT_T(KC_O)
#define CTRL_R LCTL_T(KC_R)
#define CTRL_I LCTL_T(KC_I)
#define ALT_S LALT_T(KC_S)
#define ALT_E LALT_T(KC_E)
#define GUI_N LGUI_T(KC_N)
#define CTRL_SPC LCTL_T(KC_SPC)
#define GUI_ENT LGUI_T(KC_ENT)
#define NUM_RBRC LT(_NUM, KC_RBRC)

//layer-tap
#define I3W_F LT(_I3WORK,KC_F)
#define I3M_P LT(_I3MOVE,KC_P)
#define NAVS_T LT(_NAVS,KC_T)
#define FUNC_D LT(_FUNC,KC_D)
#define NUM_C LT(_NUM,KC_V)
#define SHRT_ESC LT(_SHORT,KC_ESCAPE)

#define ONEPASS LALT(LSFT(KC_X))

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [_COLEMAK] = LAYOUT(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
     ROFI_W,  KC_Q,    KC_W,    I3W_F,   I3M_P,   KC_G,                         KC_J,    KC_L,    KC_U,    KC_Y,    KC_SCLN, _______,\
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
     KC_TAB,  SHFT_A,  CTRL_R,  ALT_S,   NAVS_T,  FUNC_D,                       KC_H,    GUI_N,   ALT_E,   CTRL_I,  SHFT_O,  KC_QUOT,\
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
     KC_LSFT, KC_Z,    KC_X,    KC_C,   NUM_C,    KC_B,                         KC_K,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_RSFT,\
                                         KC_DEL, CTRL_SPC, GUI_ENT,    KC_BSPACE, MO(_SYMB), SHRT_ESC
                                      //`--------------------------'  `--------------------------'
  ),

  [_SWE] = LAYOUT(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
     _______, _______, _______, _______, _______, _______,                      _______, _______, _______, _______, RALT(KC_W), RALT(KC_P),\
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
     _______, _______, _______, _______, _______, _______,                      _______, _______, _______, _______, _______, RALT(KC_Q),\
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
     _______, _______, _______, _______, _______, _______,                      _______, _______, _______, _______, _______, _______,\
                                         _______, _______, _______,    _______, _______, _______
                                      //`--------------------------'  `--------------------------'
  ),

  [_DAN] = LAYOUT(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
     _______, _______, _______, _______, _______, _______,                      _______, _______, _______, _______, RALT(KC_W), RALT(KC_L),\
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
     _______, _______, _______, _______, _______, _______,                      _______, _______, _______, _______, _______, RALT(KC_Z),\
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
     _______, _______, _______, _______, _______, _______,                      _______, _______, _______, _______, _______, _______,\
                                         _______, _______, _______,    _______, _______, _______
                                      //`--------------------------'  `--------------------------'
  ),

  [_SYMB] = LAYOUT(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
      _______, KC_CIRC, KC_DLR,  KC_LCBR, KC_RCBR, KC_HASH,                     KC_AMPR, KC_EXLM, KC_QUES, KC_UNDS, KC_SCOLON, _______,\
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      _______, KC_COLN, KC_EQL,  KC_LPRN, KC_RPRN, KC_AT,                       KC_DQUO, KC_PLUS, KC_ASTR, KC_MINUS,KC_GRAVE,KC_QUOTE,\
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      _______, KC_EXLM, KC_PERC, KC_LBRC, NUM_RBRC,KC_TILD,                     KC_BSLASH,KC_PIPE,KC_LABK, KC_RABK, _______, _______,\
                                         _______, _______, _______,    _______, _______, _______
                                      //`--------------------------'  `--------------------------'
  ),

  [_NAVS] = LAYOUT(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
     TO(_LNAVS),_______,_______, _______, _______, _______,                     XXXXXXX, KC_PGUP, KC_UP,  KC_PGDOWN, XXXXXXX, TO(_COLEMAK),\
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      _______, _______, _______, _______, _______, _______,                     KC_HOME, KC_LEFT, KC_DOWN, KC_RIGHT, KC_END,  _______, \
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      _______, _______, _______, _______, _______, _______,                     KC_INSERT, LALT(LSFT(KC_LEFT)),LALT(KC_1), LALT(LSFT(KC_RIGHT)), XXXXXXX,  _______, \
                                         _______, _______, _______,    _______, _______, _______
                                      //`--------------------------'  `--------------------------'
  ),

  [_LNAVS] = LAYOUT(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
     TO(_COLEMAK), XXXXXXX, KC_PGUP, KC_UP, KC_PGDOWN, XXXXXXX,                 _______, _______, _______, _______, _______, _______, \
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
     _______, KC_HOME, KC_LEFT, KC_DOWN, KC_RIGHT,KC_END,                       _______, _______, _______, _______, _______, _______, \
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
     _______, KC_INSERT, LALT(LSFT(KC_LEFT)),LALT(KC_1), LALT(LSFT(KC_RIGHT)), XXXXXXX, _______, _______, _______, _______, _______, _______, \
                                         _______, _______, _______,    _______, _______, _______
                                      //`--------------------------'  `--------------------------'
  ),

  [_NUM] = LAYOUT(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
     _______, _______, _______, _______, _______, _______,                      KC_ASTR, KC_7,    KC_8,    KC_9,    KC_SLSH, TO(_COLEMAK),\
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
     _______, _______, _______, _______, _______, _______,                      KC_PLUS, KC_4,    KC_5,    KC_6,    KC_MINS, _______,\
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
     _______, _______, _______, _______, _______, _______,                      XXXXXXX, KC_1,    KC_2,    KC_3,    KC_COMM, _______,\
                                         _______, _______, _______,    _______, KC_0,    KC_DOT
                                      //`--------------------------'  `--------------------------'
  ),

  [_FUNC] = LAYOUT(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
     _______, _______, _______, _______, _______, _______,                      _______, KC_F7,   KC_F8,   KC_F9,   KC_F10,  _______,\
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
     _______, _______, _______, _______, _______, _______,                      _______, KC_F4,   KC_F5,   KC_F6,   KC_F11,  _______,\
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
     _______, _______, _______, _______, _______, _______,                      _______, KC_F1,   KC_F2,   KC_F3,   KC_F12,  _______,\
                                         _______, _______, _______,    _______, _______, _______
                                      //`--------------------------'  `--------------------------'
  ),

  [_SWE] = LAYOUT(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
     _______, _______, _______, _______, _______, _______,                      _______, _______, _______, _______, RALT(KC_W), RALT(KC_P),\
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
     _______, _______, _______, _______, _______, _______,                      _______, _______, _______, _______, _______, RALT(KC_Q),\
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
     _______, _______, _______, _______, _______, _______,                      _______, _______, _______, _______, _______, _______,\
                                         _______, _______, _______,    _______, _______, _______
                                      //`--------------------------'  `--------------------------'
  ),

  [_SHORT] = LAYOUT(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
     RESET,   RGBRST,  RGB_SAI, RGB_HUI, RGB_VAI, KC_VOLU,                      _______, _______, _______, _______, _______, DYN_REC_START1,\
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
     RGB_MOD, KC_MPRV, KC_MSTP, KC_MEDIA_PLAY_PAUSE, KC_MNXT, KC_VOLD,          _______, TO(_COLEMAK), TO(_SWE), TO(_DAN), XXXXXXX, DYN_REC_STOP,\
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
     RGB_TOG, _______, RGB_SAD, RGB_HUD, RGB_VAD, KC_MUTE,                      _______, TO(_NAVS), TO(_LNAVS), TO(_NUM),  XXXXXXX, DYN_MACRO_PLAY1,\
                                         ONEPASS, _______, EEPROM_RESET, _______, _______, _______
                                      //`--------------------------'  `--------------------------'
  ),

  [_I3WORK] = LAYOUT(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
     _______, _______, _______, _______, LGUI(KC_TAB), _______,                 _______, LGUI(KC_7), LGUI(KC_8), LGUI(KC_9), _______, _______, \
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
     _______, _______, _______, _______, _______, _______,                      LALT(LGUI(KC_LEFT)), LGUI(KC_4), LGUI(KC_5), LGUI(KC_6), LALT(LGUI(KC_RIGHT)), _______, \
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
     _______, _______, _______, _______, _______, _______,                      _______, LGUI(KC_1), LGUI(KC_2), LGUI(KC_3), KC_COLN, _______, \
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                         LCTL(LSFT(KC_PSCREEN)), _______, _______, _______, _______, LGUI(KC_0)
                                      //`--------------------------'  `--------------------------'
  ),

  [_I3MOVE] = LAYOUT(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
     _______, _______, _______, _______, _______, _______,                      _______, LGUI(KC_PGUP), LGUI(KC_UP), _______, _______, _______, \
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
     _______, _______, _______, _______, _______, _______,                      _______, LGUI(KC_LEFT), LGUI(KC_DOWN), LGUI(KC_RIGHT), _______, _______, \
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
     _______, _______, _______, _______, _______, _______,                      _______, _______, _______, _______, _______, _______,\
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                         _______, _______, _______,    _______, _______, _______
                                      //`--------------------------'  `--------------------------'
  )
};

int RGB_current_mode;

void persistent_default_layer_set(uint16_t default_layer) {
  eeconfig_update_default_layer(default_layer);
  default_layer_set(default_layer);
}

void matrix_init_user(void) {
    #ifdef RGBLIGHT_ENABLE
      RGB_current_mode = rgblight_config.mode;
    #endif
    //SSD1306 OLED init, make sure to add #define SSD1306OLED in config.h
    #ifdef SSD1306OLED
        iota_gfx_init(!has_usb());   // turns on the display
    #endif
}

#ifdef OLED_DRIVER_ENABLE
oled_rotation_t oled_init_user(oled_rotation_t rotation) { return OLED_ROTATION_0; }

static void render_qmk_logo(void) {
  static const char PROGMEM qmk_logo[] = {
    0x80,0x81,0x82,0x83,0x84,0x85,0x86,0x87,0x88,0x89,0x8a,0x8b,0x8c,0x8d,0x8e,0x8f,0x90,0x91,0x92,0x93,0x94,
    0xa0,0xa1,0xa2,0xa3,0xa4,0xa5,0xa6,0xa7,0xa8,0xa9,0xaa,0xab,0xac,0xad,0xae,0xaf,0xb0,0xb1,0xb2,0xb3,0xb4,
    0xc0,0xc1,0xc2,0xc3,0xc4,0xc5,0xc6,0xc7,0xc8,0xc9,0xca,0xcb,0xcc,0xcd,0xce,0xcf,0xd0,0xd1,0xd2,0xd3,0xd4,0};

  oled_write_P(qmk_logo, false);
}

static void render_status(void) {
    oled_write_P(PSTR("       Calle's Corne\n\n"), false);

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
        case _LNAVS:
            oled_write_P(PSTR("Left navs\n"), false);
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
        default:
            oled_write_P(PSTR("Undefined\n"), false);
    }
}

void oled_task_user(void) {
    if (is_keyboard_master()) {
        render_status(); // Renders the current keyboard state
    } else {
        // QMK Logo and version information
        render_qmk_logo();
    }
}
#endif


bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  if (record->event.pressed) {
#ifdef SSD1306OLED
    set_keylog(keycode, record);
#endif
    // set_timelog();
  }

  switch (keycode) {
    case RGB_MOD:
      #ifdef RGBLIGHT_ENABLE
        if (record->event.pressed) {
          rgblight_mode(RGB_current_mode);
          rgblight_step();
          RGB_current_mode = rgblight_config.mode;
        }
      #endif
      return false;
    case RGBRST:
      #ifdef RGBLIGHT_ENABLE
        if (record->event.pressed) {
          eeconfig_update_rgblight_default();
          rgblight_enable();
          RGB_current_mode = rgblight_config.mode;
        }
      #endif
      break;
  }
  return true;
}
