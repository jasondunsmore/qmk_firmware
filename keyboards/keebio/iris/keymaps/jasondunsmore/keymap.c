#include QMK_KEYBOARD_H

extern keymap_config_t keymap_config;

// Layers
#define _COLEMAKDHM 0 // Colemak Mod-DH
#define _COLEMAK    1 // Colemak
#define _TARMAK1    2 // Tarmak level 1
#define _TARMAK2    3 // Tarmak level 2
#define _TARMAK3    4 // Tarmak level 3
#define _TARMAK4    5 // Tarmak level 4
#define _QWERTY     6 // QWERTY
#define _NAVI       7 // Navigation
#define _NUMP       8 // Numpad

// Keys
#define KC_NLFT LT(_NAVI, KC_LEFT)
#define KC_NDWN LT(_NAVI, KC_DOWN)
#define KC_NUP  LT(_NAVI, KC_UP)
#define KC_NRGT LT(_NAVI, KC_RGHT)
#define KC_NUMP MO(_NUMP)
#define KC_TMK1 DF(_TARMAK1)
#define KC_TMK2 DF(_TARMAK2)
#define KC_TMK3 DF(_TARMAK3)
#define KC_TMK4 DF(_TARMAK4)
#define KC_QWER DF(_QWERTY)
#define KC_CMAK DF(_COLEMAK)
#define KC_CMDH DF(_COLEMAKDHM)
#define KC_AGRV LALT_T(KC_GRAVE)
#define KC_AQUO RALT_T(KC_QUOTE)
#define KC_GUIE LGUI_T(KC_ESC)
#define KC_DSFT RSFT_T(KC_DEL)
#define KC_PSFT LSFT_T(KC_KP_PLUS)
#define KC_MCTL RCTL_T(KC_MINS)
#define KC_ECTL LCTL_T(KC_EQL)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

  [_COLEMAKDHM] = LAYOUT_kc(
//,----+----+----+----+----+----.              ,----+----+----+----+----+----.
   GUIE, 1,   2,   3,   4,   5,                  6,   7,   8,   9,   0,  BSLS,
//|----+----+----+----+----+----|              |----+----+----+----+----+----|
   TAB,  Q,   W,   F,   P,   B,                  J,   L,   U,   Y,  SCLN,BSPC,
//|----+----+----+----+----+----|              |----+----+----+----+----+----|
   AGRV, A,   R,   S,   T,   G,                  M,   N,   E,   I,   O,  AQUO,
//|----+----+----+----+----+----+----.    ,----|----+----+----+----+----+----|
   PSFT, Z,   X,   C,   D,   V,  NDWN,     NUP,  K,   H,  COMM,DOT, SLSH,DSFT,
//`----+----+----+--+-+----+----+----/    \----+----+----+----+----+----+----'
                     NLFT,ECTL,SPC,          ENT, MCTL,NRGT
//                  `----+----+----'        `----+----+----'
     ),

  [_COLEMAK] = LAYOUT_kc(
//,----+----+----+----+----+----.              ,----+----+----+----+----+----.
   GUIE, 1,   2,   3,   4,   5,                  6,   7,   8,   9,   0,  BSLS,
//|----+----+----+----+----+----|              |----+----+----+----+----+----|
   TAB,  Q,   W,   F,   P,   G,                  J,   L,   U,   Y,  SCLN,BSPC,
//|----+----+----+----+----+----|              |----+----+----+----+----+----|
   AGRV, A,   R,   S,   T,   D,                  H,   N,   E,   I,   O,  AQUO,
//|----+----+----+----+----+----+----.    ,----|----+----+----+----+----+----|
   PSFT, Z,   X,   C,   V,   B,  NDWN,     NUP,  K,   M,  COMM,DOT, SLSH,DSFT,
//`----+----+----+--+-+----+----+----/    \----+----+----+----+----+----+----'
                     NLFT,ECTL,SPC,          ENT, MCTL,NRGT
//                  `----+----+----'        `----+----+----'
     ),

  [_TARMAK1] = LAYOUT_kc(
//,----+----+----+----+----+----.              ,----+----+----+----+----+----.
   GUIE, 1,   2,   3,   4,   5,                  6,   7,   8,   9,   0,  BSLS,
//|----+----+----+----+----+----|              |----+----+----+----+----+----|
   TAB,  Q,   W,   J,   R,   T,                  Y,   U,   I,   O,   P,  BSPC,
//|----+----+----+----+----+----|              |----+----+----+----+----+----|
   AGRV, A,   S,   D,   F,   G,                  H,   N,   E,   L,  SCLN,AQUO,
//|----+----+----+----+----+----+----.    ,----|----+----+----+----+----+----|
   PSFT, Z,   X,   C,   V,   B,  NDWN,     NUP,  K,   M,  COMM,DOT, SLSH,DSFT,
//`----+----+----+--+-+----+----+----/    \----+----+----+----+----+----+----'
                     NLFT,ECTL,SPC,          ENT, MCTL,NRGT
//                  `----+----+----'        `----+----+----'
     ),

  [_TARMAK2] = LAYOUT_kc(
//,----+----+----+----+----+----.              ,----+----+----+----+----+----.
   GUIE, 1,   2,   3,   4,   5,                  6,   7,   8,   9,   0,  BSLS,
//|----+----+----+----+----+----|              |----+----+----+----+----+----|
   TAB,  Q,   W,   F,   R,   G,                  Y,   U,   I,   O,   P,  BSPC,
//|----+----+----+----+----+----|              |----+----+----+----+----+----|
   AGRV, A,   S,   D,   T,   J,                  H,   N,   E,   L,  SCLN,AQUO,
//|----+----+----+----+----+----+----.    ,----|----+----+----+----+----+----|
   PSFT, Z,   X,   C,   V,   B,  NDWN,     NUP,  K,   M,  COMM,DOT, SLSH,DSFT,
//`----+----+----+--+-+----+----+----/    \----+----+----+----+----+----+----'
                     NLFT,ECTL,SPC,          ENT, MCTL,NRGT
//                  `----+----+----'        `----+----+----'
     ),

  [_TARMAK3] = LAYOUT_kc(
//,----+----+----+----+----+----.              ,----+----+----+----+----+----.
   GUIE, 1,   2,   3,   4,   5,                  6,   7,   8,   9,   0,  BSLS,
//|----+----+----+----+----+----|              |----+----+----+----+----+----|
   TAB,  Q,   W,   F,   J,   G,                  Y,   U,   I,   O,   P,  BSPC,
//|----+----+----+----+----+----|              |----+----+----+----+----+----|
   AGRV, A,   R,   S,   T,   D,                  H,   N,   E,   L,  SCLN,AQUO,
//|----+----+----+----+----+----+----.    ,----|----+----+----+----+----+----|
   PSFT, Z,   X,   C,   V,   B,  NDWN,     NUP,  K,   M,  COMM,DOT, SLSH,DSFT,
//`----+----+----+--+-+----+----+----/    \----+----+----+----+----+----+----'
                     NLFT,ECTL,SPC,          ENT, MCTL,NRGT
//                  `----+----+----'        `----+----+----'
     ),

  [_TARMAK4] = LAYOUT_kc(
//,----+----+----+----+----+----.              ,----+----+----+----+----+----.
   GUIE, 1,   2,   3,   4,   5,                  6,   7,   8,   9,   0,  BSLS,
//|----+----+----+----+----+----|              |----+----+----+----+----+----|
   TAB,  Q,   W,   F,   P,   G,                  J,   U,   I,   Y,  SCLN,BSPC,
//|----+----+----+----+----+----|              |----+----+----+----+----+----|
   AGRV, A,   R,   S,   T,   D,                  H,   N,   E,   L,   O,  AQUO,
//|----+----+----+----+----+----+----.    ,----|----+----+----+----+----+----|
   PSFT, Z,   X,   C,   V,   B,  NDWN,     NUP,  K,   M,  COMM,DOT, SLSH,DSFT,
//`----+----+----+--+-+----+----+----/    \----+----+----+----+----+----+----'
                     NLFT,ECTL,SPC,          ENT, MCTL,NRGT
//                  `----+----+----'        `----+----+----'
     ),

  [_QWERTY] = LAYOUT_kc(
//,----+----+----+----+----+----.              ,----+----+----+----+----+----.
   GUIE, 1,   2,   3,   4,   5,                  6,   7,   8,   9,   0,  BSLS,
//|----+----+----+----+----+----|              |----+----+----+----+----+----|
   TAB,  Q,   W,   E,   R,   T,                  Y,   U,   I,   O,   P,  BSPC,
//|----+----+----+----+----+----|              |----+----+----+----+----+----|
   AGRV, A,   S,   D,   F,   G,                  H,   J,   K,   L,  SCLN,AQUO,
//|----+----+----+----+----+----+----.    ,----|----+----+----+----+----+----|
   PSFT, Z,   X,   C,   V,   B,  NDWN,     NUP,  N,   M,  COMM,DOT, SLSH,DSFT,
//`----+----+----+--+-+----+----+----/    \----+----+----+----+----+----+----'
                     NLFT,ECTL,SPC,          ENT, MCTL,NRGT
//                  `----+----+----'        `----+----+----'
     ),

  [_NAVI] = LAYOUT_kc(
//,----+----+----+----+----+----.              ,----+----+----+----+----+----.
   F12,  F1,  F2,  F3,  F4,  F5,                 F6,  F7,  F8,  F9, F10, F11,
//|----+----+----+----+----+----|              |----+----+----+----+----+----|
   TMK1,TMK2,MUTE,VOLU,TRNS,TRNS,               PGUP,HOME, UP, END, TRNS,TRNS,
//|----+----+----+----+----+----|              |----+----+----+----+----+----|
   TMK3,TMK4,BRID,VOLD,BRIU,TRNS,               PGDN,LEFT,DOWN,RGHT,TRNS,TRNS,
//|----+----+----+----+----+----+----.    ,----|----+----+----+----+----+----|
   CMDH,CMAK,QWER,NUMP,INS, TRNS,TRNS,     TRNS,TRNS,CAPS,LBRC,RBRC,TRNS,TRNS,
//`----+----+----+--+-+----+----+----/    \----+----+----+----+----+----+----'
                     TRNS,TRNS,TRNS,         TRNS,TRNS,TRNS
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
     ),
};
