#include QMK_KEYBOARD_H


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
                                         _______, _______, _______,    KC_0,    KC_DOT,  _______
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
                                         LALT(LSFT(KC_X)), _______, _______, _______, _______, _______
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

//SSD1306 OLED update loop, make sure to add #define SSD1306OLED in config.h
#ifdef SSD1306OLED

// When add source files to SRC in rules.mk, you can use functions.
const char *read_layer_state(void);
const char *read_logo(void);
void set_keylog(uint16_t keycode, keyrecord_t *record);
const char *read_keylog(void);
const char *read_keylogs(void);

// const char *read_mode_icon(bool swap);
// const char *read_host_led_state(void);
// void set_timelog(void);
// const char *read_timelog(void);

void matrix_scan_user(void) {
   iota_gfx_task();
}

void matrix_render_user(struct CharacterMatrix *matrix) {
  if (is_master) {
    // If you want to change the display of OLED, you need to change here
    matrix_write_ln(matrix, read_layer_state());
    matrix_write_ln(matrix, read_keylog());
    //matrix_write_ln(matrix, read_keylogs());
    //matrix_write_ln(matrix, read_mode_icon(keymap_config.swap_lalt_lgui));
    //matrix_write_ln(matrix, read_host_led_state());
    //matrix_write_ln(matrix, read_timelog());
  } else {
    matrix_write(matrix, read_logo());
  }
}

void matrix_update(struct CharacterMatrix *dest, const struct CharacterMatrix *source) {
  if (memcmp(dest->display, source->display, sizeof(dest->display))) {
    memcpy(dest->display, source->display, sizeof(dest->display));
    dest->dirty = true;
  }
}

void iota_gfx_task_user(void) {
  struct CharacterMatrix matrix;
  matrix_clear(&matrix);
  matrix_render_user(&matrix);
  matrix_update(&display, &matrix);
}
#endif//SSD1306OLED

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
