/*
This is the c configuration file for the keymap

Copyright 2012 Jun Wako <wakojun@gmail.com>
Copyright 2015 Jack Humbert

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
*/

#pragma once

//#define USE_MATRIX_I2C

/* Select hand configuration */

#undef SSD1306OLED
#define MASTER_LEFT
#define USE_SERIAL_PD2
#define TAPPING_TERM 225
#define IGNORE_MOD_TAP_INTERRUPT
#define NO_ACTION_ONESHOT

#ifdef RGBLIGHT_ENABLE
  #undef RGBLIGHT_ANIMATIONS
  #undef RGBLED_NUM
  #define RGBLIGHT_ANIMATIONS
  #define RGBLIGHT_LIMIT_VAL 120
  #define RGBLED_NUM 27
  #define RGBLIGHT_HUE_STEP 6
  #define RGBLIGHT_SAT_STEP 6
  #define RGBLIGHT_VAL_STEP 8
#endif

#ifdef RGB_MATRIX_ENABLE
  #define RGB_MATRIX_KEYPRESSES  // reacts to keypresses
  #define RGB_DISABLE_WHEN_USB_SUSPENDED true  // turn off effects when suspended
  #define RGB_MATRIX_MAXIMUM_BRIGHTNESS 150  // limits maximum brightness of LEDs to x out of 255.
  #define RGB_MATRIX_HUE_STEP 6
  #define RGB_MATRIX_SAT_STEP 6
  #define RGB_MATRIX_VAL_STEP 6
  #define RGB_MATRIX_SPD_STEP 8

  #define DISABLE_RGB_MATRIX_ALPHAS_MODS
  #define DISABLE_RGB_MATRIX_GRADIENT_UP_DOWN
  #define DISABLE_RGB_MATRIX_BREATHING
  #define DISABLE_RGB_MATRIX_BAND_SAT
  #define DISABLE_RGB_MATRIX_BAND_VAL
  #define DISABLE_RGB_MATRIX_BAND_PINWHEEL_SAT
  #define DISABLE_RGB_MATRIX_BAND_PINWHEEL_VAL
  #define DISABLE_RGB_MATRIX_BAND_SPIRAL_SAT
  #define DISABLE_RGB_MATRIX_BAND_SPIRAL_VAL
  #define DISABLE_RGB_MATRIX_CYCLE_ALL
  #define DISABLE_RGB_MATRIX_CYCLE_LEFT_RIGHT
  #define DISABLE_RGB_MATRIX_CYCLE_UP_DOWN
  #define DISABLE_RGB_MATRIX_CYCLE_OUT_IN
  #define DISABLE_RGB_MATRIX_CYCLE_OUT_IN_DUAL
  #define DISABLE_RGB_MATRIX_RAINBOW_MOVING_CHEVRON
  #define DISABLE_RGB_MATRIX_CYCLE_PINWHEEL
  #define DISABLE_RGB_MATRIX_CYCLE_SPIRAL
  #define DISABLE_RGB_MATRIX_DUAL_BEACON
  #define DISABLE_RGB_MATRIX_RAINBOW_BEACON
  #define DISABLE_RGB_MATRIX_RAINBOW_PINWHEELS
  #define DISABLE_RGB_MATRIX_RAINDROPS
  #define DISABLE_RGB_MATRIX_JELLYBEAN_RAINDROPS

  #define DISABLE_RGB_MATRIX_FRAMEBUFFER_EFFECTS
  #define DISABLE_RGB_MATRIX_TYPING_HEATMAP
//  #define DISABLE_RGB_MATRIX_DIGITAL_RAIN

  #define DISABLE_RGB_MATRIX_SOLID_REACTIVE_SIMPLE
//  #define DISABLE_RGB_MATRIX_SOLID_REACTIVE
  #define DISABLE_RGB_MATRIX_SOLID_REACTIVE_WIDE
  #define DISABLE_RGB_MATRIX_SOLID_REACTIVE_MULTIWIDE
  #define DISABLE_RGB_MATRIX_SOLID_REACTIVE_CROSS
  #define DISABLE_RGB_MATRIX_SOLID_REACTIVE_MULTICROSS
  #define DISABLE_RGB_MATRIX_SOLID_REACTIVE_NEXUS
  #define DISABLE_RGB_MATRIX_SOLID_REACTIVE_MULTINEXUS

  #define DISABLE_RGB_MATRIX_SPLASH
  #define DISABLE_RGB_MATRIX_MULTISPLASH
  #define DISABLE_RGB_MATRIX_SOLID_SPLASH
  #define DISABLE_RGB_MATRIX_SOLID_MULTISPLASH

  #define RGB_MATRIX_STARTUP_MODE RGB_MATRIX_SOLID_REACTIVE
#endif

#undef PRODUCT
#define PRODUCT Awesome Calle Corne

#define OLED_FONT_H "keyboards/crkbd/keymaps/nrgizer/glcdfont.c"
