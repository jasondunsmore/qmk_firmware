#include QMK_KEYBOARD_H

extern keymap_config_t keymap_config;

// Layers
#define _QWERTY 0 // Base layer
#define _ONE 1
#define _TWO 2

#define KC_AQUT RALT_T(KC_QUOT)
#define KC_AGRV LALT_T(KC_GRAVE)
#define KC_GUIE LGUI_T(KC_ESC)
#define KC_ONE MO(1)
#define KC_TWO MO(2)
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
   LSPO, Z,   X,   C,   V,   B,  MINS,     EQL,  N,   M,  COMM,DOT, SLSH,RSPC,
//`----+----+----+--+-+----+----+----/    \----+----+----+----+----+----+----'
                     ONE, LCTL,SPC,          ENT, RCTL,TWO
//                  `----+----+----'        `----+----+----'
     ),

  [_ONE] = LAYOUT_kc(
//,----+----+----+----+----+----.              ,----+----+----+----+----+----.
    F1,  F2,  F3,  F4,  F5,  F6,                 F7,  F8,  F9, F10, F11, F12,
//|----+----+----+----+----+----|              |----+----+----+----+----+----|
    NO,  1,   2,   3,   4,   5,                  6,   7,   8,   9,   0,  TRNS,
//|----+----+----+----+----+----|              |----+----+----+----+----+----|
   TRNS,EXLM, AT, HASH,DLR, PERC,               CIRC,AMPR,ASTR,LBRC,RBRC,TRNS,
//|----+----+----+----+----+----+----.    ,----|----+----+----+----+----+----|
   TRNS, NO,  NO, BSLS,PIPE, NO, TRNS,     TRNS, NO, DOT,  NO, LCBR,RCBR,TRNS,
//`----+----+----+--+-+----+----+----/    \----+----+----+----+----+----+----'
                     TRNS,TRNS,TRNS,         TRNS,TRNS,MEH
//                  `----+----+----'        `----+----+----'
      ),

 [_TWO] = LAYOUT_kc(
//,----+----+----+----+----+----.              ,----+----+----+----+----+----.
   MUTE,VOLD,VOLU, NO, BRID,BRIU,               CAPS,INS,  NO,  NO, DBUG,REST,
//|----+----+----+----+----+----|              |----+----+----+----+----+----|
   PWR, HOME, NO,  UP,  NO, PGUP,               WH_U,BTN1,MS_U,BTN2, NO, TRNS,
//|----+----+----+----+----+----|              |----+----+----+----+----+----|
   TRNS,END, LEFT,DOWN,RGHT,PGDN,               WH_D,MS_L,MS_D,MS_R, NO, TRNS,
//|----+----+----+----+----+----+----.    ,----|----+----+----+----+----+----|
   TRNS, NO,  NO,  NO,  NO,  NO, TRNS,     TRNS, NO,  NO,  NO,  NO,  NO, TRNS,
//`----+----+----+--+-+----+----+----/    \----+----+----+----+----+----+----'
                     HYPR,TRNS,TRNS,         TRNS,TRNS,TRNS
//                  `----+----+----'        `----+----+----'
     )
};
