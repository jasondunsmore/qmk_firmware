#include QMK_KEYBOARD_H

extern keymap_config_t keymap_config;

// Layers
#define _COLEMAKDHM 0 // Colemak-DHm
#define _NAVI       1 // Navigation
#define _NUMP       2 // Numpad

// Keys
#define KC_NLFT LT(_NAVI, KC_LEFT)
#define KC_NRGT LT(_NAVI, KC_RGHT)
#define KC_NPUP LT(_NUMP, KC_PGUP)
#define KC_NPDN LT(_NUMP, KC_PGDN)
#define KC_AGRV LALT_T(KC_GRAVE)
#define KC_AQUO RALT_T(KC_QUOTE)
#define KC_GUIE LGUI_T(KC_ESC)
#define KC_DSFT LSFT_T(KC_DOWN)
#define KC_USFT RSFT_T(KC_UP)
#define KC_ECTL RCTL_T(KC_EQL)
#define KC_MCTL LCTL_T(KC_MINS)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

  [_COLEMAKDHM] = LAYOUT_kc(
//,----+----+----+----+----+----.              ,----+----+----+----+----+----.
   GUIE, 1,   2,   3,   4,   5,                  6,   7,   8,   9,   0,  DEL,
//|----+----+----+----+----+----|              |----+----+----+----+----+----|
   TAB,  Q,   W,   F,   P,   B,                  J,   L,   U,   Y,  SCLN,BSPC,
//|----+----+----+----+----+----|              |----+----+----+----+----+----|
   AGRV, A,   R,   S,   T,   G,                  M,   N,   E,   I,   O,  AQUO,
//|----+----+----+----+----+----+----.    ,----|----+----+----+----+----+----|
   DSFT, Z,   X,   C,   D,   V,  NPUP,     NPDN, K,   H,  COMM,DOT, SLSH,USFT,
//`----+----+----+--+-+----+----+----/    \----+----+----+----+----+----+----'
                     NLFT,MCTL,SPC,          ENT, ECTL,NRGT
//                  `----+----+----'        `----+----+----'
     ),

  [_NAVI] = LAYOUT_kc(
//,----+----+----+----+----+----.              ,----+----+----+----+----+----.
   F12,  F1,  F2,  F3,  F4,  F5,                 F6,  F7,  F8,  F9, F10, F11,
//|----+----+----+----+----+----|              |----+----+----+----+----+----|
   TRNS,TRNS,MUTE,VOLU,TRNS,TRNS,               PGUP,HOME, UP, END, TRNS,BSLS,
//|----+----+----+----+----+----|              |----+----+----+----+----+----|
   TRNS,TRNS,BRID,VOLD,BRIU,TRNS,               PGDN,LEFT,DOWN,RGHT,TRNS,TRNS,
//|----+----+----+----+----+----+----.    ,----|----+----+----+----+----+----|
   TRNS,TRNS,TRNS,CAPS,INS, TRNS,TRNS,     TRNS,TRNS,CAPS,LBRC,RBRC,TRNS,TRNS,
//`----+----+----+--+-+----+----+----/    \----+----+----+----+----+----+----'
                     HOME,TRNS,TRNS,         TRNS,TRNS,END
//                  `----+----+----'        `----+----+----'
     ),

  [_NUMP] = LAYOUT_kc(
//,----+----+----+----+----+----.              ,----+----+----+----+----+----.
   TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,               TRNS,NLCK,PSLS,PAST,PMNS,TRNS,
//|----+----+----+----+----+----|              |----+----+----+----+----+----|
   TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,               TRNS, P7,  P8,  P9, PPLS,TRNS,
//|----+----+----+----+----+----|              |----+----+----+----+----+----|
   TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,               TRNS, P4,  P5,  P6, PCMM,TRNS,
//|----+----+----+----+----+----+----.    ,----|----+----+----+----+----+----|
   TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,     TRNS,TRNS, P1,  P2,  P3, PEQL,TRNS,
//`----+----+----+--+-+----+----+----/    \----+----+----+----+----+----+----'
                     TRNS,TRNS,TRNS,         PENT, P0, PDOT
//                  `----+----+----'        `----+----+----'
     )
};
