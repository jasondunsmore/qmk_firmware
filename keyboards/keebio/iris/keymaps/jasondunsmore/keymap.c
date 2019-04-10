#include QMK_KEYBOARD_H

extern keymap_config_t keymap_config;

// Layers
#define _QWERTY 0 // Base layer
#define _NUMB 1
#define _NAVI 2
#define _SYMB 3
#define _FUNC 4

// Keys
#define KC_AQUT RALT_T(KC_QUOT)
#define KC_AGRV LALT_T(KC_GRAVE)
#define KC_GUIE LGUI_T(KC_ESC)
#define KC_MISY LT(_SYMB, KC_MINS)
#define KC_EQFU LT(_FUNC, KC_EQL)
#define KC_NUMB MO(_NUMB)
#define KC_NAVI MO(_NAVI)
#define KC_SYMB MO(_SYMB)
#define KC_FUNC MO(_FUNC)
#define KC_REST RESET
#define KC_DBUG DEBUG

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

  [_QWERTY] = LAYOUT_kc(
//,----+----+----+----+----+----.              ,----+----+----+----+----+----.
   GUIE, 1,   2,   3,   4,   5,                  6,   7,   8,   9,   0,  DEL,
//|----+----+----+----+----+----|              |----+----+----+----+----+----|
   TAB,  Q,   W,   E,   R,   T,                  Y,   U,   I,   O,   P,  BSPC,
//|----+----+----+----+----+----|              |----+----+----+----+----+----|
   AGRV, A,   S,   D,   F,   G,                  H,   J,   K,   L,  SCLN,AQUT,
//|----+----+----+----+----+----+----.    ,----|----+----+----+----+----+----|
   LSPO, Z,   X,   C,   V,   B,  MISY,     EQFU, N,   M,  COMM,DOT, SLSH,RSPC,
//`----+----+----+--+-+----+----+----/    \----+----+----+----+----+----+----'
                     NUMB,LCTL,SPC,          ENT, RCTL,NAVI
//                  `----+----+----'        `----+----+----'
     ),

  [_NUMB] = LAYOUT_kc(
//,----+----+----+----+----+----.              ,----+----+----+----+----+----.
    NO,  NO,  NO,  NO,  NO,  NO,                 NO,  NO,  NO,  NO,  NO, TRNS,
//|----+----+----+----+----+----|              |----+----+----+----+----+----|
    NO,  1,   2,   3,   4,   5,                  6,   7,   8,   9,   0,  TRNS,
//|----+----+----+----+----+----|              |----+----+----+----+----+----|
   TRNS, NO,  NO,  NO,  NO,  NO,                ASTR, 4,   5,   6,  PLUS,TRNS,
//|----+----+----+----+----+----+----.    ,----|----+----+----+----+----+----|
   TRNS, NO,  NO,  NO,  NO,  NO, TRNS,     TRNS,SLSH, 1,   2,   3,  MINS,TRNS,
//`----+----+----+--+-+----+----+----/    \----+----+----+----+----+----+----'
                     TRNS,TRNS,TRNS,         SYMB,TRNS,TRNS
//                  `----+----+----'        `----+----+----'
      ),

 [_NAVI] = LAYOUT_kc(
//,----+----+----+----+----+----.              ,----+----+----+----+----+----.
    NO,  NO,  NO,  NO,  NO,  NO,                 NO,  NO,  NO,  NO,  NO, TRNS,
//|----+----+----+----+----+----|              |----+----+----+----+----+----|
    NO,  NO,  NO,  UP,  NO,  NO,                 NO, PGUP,HOME, NO,  NO, TRNS,
//|----+----+----+----+----+----|              |----+----+----+----+----+----|
   TRNS, NO, LEFT,DOWN,RGHT, NO,                 NO, PGDN,END,  NO,  NO, TRNS,
//|----+----+----+----+----+----+----.    ,----|----+----+----+----+----+----|
   TRNS,MUTE,VOLD,VOLU,BRID,BRIU,TRNS,     TRNS, NO, REST,DBUG, NO, PWR, TRNS,
//`----+----+----+--+-+----+----+----/    \----+----+----+----+----+----+----'
                     TRNS,TRNS,TRNS,         TRNS,TRNS,TRNS
//                  `----+----+----'        `----+----+----'
     ),

  [_SYMB] = LAYOUT_kc(
//,----+----+----+----+----+----.              ,----+----+----+----+----+----.
    NO,  NO,  NO,  NO,  NO,  NO,                 NO,  NO,  NO,  NO,  NO, TRNS,
//|----+----+----+----+----+----|              |----+----+----+----+----+----|
    NO,  NO,  NO,  NO,  NO,  NO,                 NO,  NO,  NO,  NO,  NO, TRNS,
//|----+----+----+----+----+----|              |----+----+----+----+----+----|
   TRNS,EXLM, AT, HASH,DLR, PERC,               CIRC,AMPR,ASTR,LBRC,RBRC,TRNS,
//|----+----+----+----+----+----+----.    ,----|----+----+----+----+----+----|
   TRNS, NO,  NO, BSLS,PIPE, NO, TRNS,     TRNS, NO, DOT,  NO, LCBR,RCBR,TRNS,
//`----+----+----+--+-+----+----+----/    \----+----+----+----+----+----+----'
                     TRNS,TRNS,TRNS,         TRNS,TRNS,TRNS
//                  `----+----+----'        `----+----+----'
      ),

 [_FUNC] = LAYOUT_kc(
//,----+----+----+----+----+----.              ,----+----+----+----+----+----.
    NO,  NO,  NO,  NO,  NO,  NO,                 NO,  NO,  NO,  NO,  NO, TRNS,
//|----+----+----+----+----+----|              |----+----+----+----+----+----|
    NO, PAUS,SLCK,PSCR,INS, CAPS,                NO,  NO,  NO,  NO,  NO, TRNS,
//|----+----+----+----+----+----|              |----+----+----+----+----+----|
   F12,  F1,  F2,  F3,  F4,  F5,                 F6,  F7,  F8,  F9, F10, F11,
//|----+----+----+----+----+----+----.    ,----|----+----+----+----+----+----|
   TRNS, NO,  NO,  NO,  NO,  NO, TRNS,     TRNS, NO,  NO,  NO,  NO,  NO, TRNS,
//`----+----+----+--+-+----+----+----/    \----+----+----+----+----+----+----'
                     TRNS,TRNS,TRNS,         TRNS,TRNS,TRNS
 //                  `----+----+----'        `----+----+----'
      )

};
