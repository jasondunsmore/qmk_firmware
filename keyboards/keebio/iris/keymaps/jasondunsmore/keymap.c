#include QMK_KEYBOARD_H

extern keymap_config_t keymap_config;

// Layers
#define _QWERTY 0 // Base layer
#define _NAVI 1

// Keys
#define KC_NAVI MO(_NAVI)
#define KC_AGRV LALT_T(KC_GRAVE)
#define KC_AQUO RALT_T(KC_QUOTE)
#define KC_GUIE LGUI_T(KC_ESC)
#define KC_DSFT RSFT_T(KC_DEL)
#define KC_MCTL LCTL_T(KC_MINS)
#define KC_ECTL RCTL_T(KC_EQL)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

  [_QWERTY] = LAYOUT_kc(
//,----+----+----+----+----+----.              ,----+----+----+----+----+----.
   GUIE, 1,   2,   3,   4,   5,                  6,   7,   8,   9,   0,  BSLS,
//|----+----+----+----+----+----|              |----+----+----+----+----+----|
   TAB,  Q,   W,   E,   R,   T,                  Y,   U,   I,   O,   P,  BSPC,
//|----+----+----+----+----+----|              |----+----+----+----+----+----|
   AGRV, A,   S,   D,   F,   G,                  H,   J,   K,   L,  SCLN,AQUO,
//|----+----+----+----+----+----+----.    ,----|----+----+----+----+----+----|
   LSFT, Z,   X,   C,   V,   B,  NAVI,     NAVI, N,   M,  COMM,DOT, SLSH,DSFT,
//`----+----+----+--+-+----+----+----/    \----+----+----+----+----+----+----'
                     NAVI,MCTL, SPC,         ENT, ECTL,NAVI
//                  `----+----+----'        `----+----+----'
     ),

  [_NAVI] = LAYOUT_kc(
//,----+----+----+----+----+----.              ,----+----+----+----+----+----.
   F12,  F1,  F2,  F3,  F4,  F5,                 F6,  F7,  F8,  F9, F10, F11,
//|----+----+----+----+----+----|              |----+----+----+----+----+----|
   TILD, NO,  NO, VOLU, NO,  NO,                 NO, PGUP, UP, PGDN,HOME, NO,
//|----+----+----+----+----+----|              |----+----+----+----+----+----|
   TRNS, NO, BRID,VOLD,BRIU, NO,                 NO, LEFT,DOWN,RGHT,END, TRNS,
//|----+----+----+----+----+----+----.    ,----|----+----+----+----+----+----|
   TRNS, NO, PWR, MUTE, NO,  NO, INS,      CAPS, NO,  NO, LBRC,RBRC, NO, TRNS,
//`----+----+----+--+-+----+----+----/    \----+----+----+----+----+----+----'
                      NO, TRNS,TRNS,         TRNS,TRNS, NO
//                  `----+----+----'        `----+----+----'
      )
};
