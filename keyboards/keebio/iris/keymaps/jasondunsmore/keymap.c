#include QMK_KEYBOARD_H

extern keymap_config_t keymap_config;

// Layers
#define _QWERTY 0 // Base layer
#define _ONE 1
#define _TWO 2

#define KC_LCA_TAB LCA_T(KC_TAB)
#define KC_LCA_BSLASH LCA_T(KC_BSLASH)
#define KC_RALT_QUOT RALT_T(KC_QUOT)
#define KC_LALT_GRAVE LALT_T(KC_GRAVE)
#define KC_ONE MO(1)
#define KC_TWO MO(2)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

   [_QWERTY] = LAYOUT_kc(
  //,----+----+----+----+----+----.              ,----+----+----+----+----+----.
     ESC, 1,   2,   3,   4,   5,                   6,   7,   8,  9,   0,  LCA_BSLASH,
  //|----+----+----+----+----+----|              |----+----+----+----+----+----|
   LCA_TAB, Q,  W,   E,   R,   T,                  Y,   U,   I,   O,   P, BSPACE,
  //|----+----+----+----+----+----|              |----+----+----+----+----+----|
  LALT_GRAVE, A, S,  D,   F,   G,                  H,   J,   K,   L, SCOLON, RALT_QUOT,
  //|----+----+----+----+----+----+----.    ,----|----+----+----+----+----+----|
    LSPO, Z,   X,   C,   V,   B,  MINUS,    EQUAL,  N,   M, COMMA, DOT, SLASH, RSPC,
  //`----+----+----+--+-+----+----+----/    \----+----+----+----+----+----+----'
                      LCTL, ONE, SPACE,      ENTER, TWO, RCTL
  //                  `----+----+----'        `----+----+----'
                      ),

   [_ONE] = LAYOUT_kc(
  //,----+----+----+----+----+----.              ,----+----+----+----+----+----.
      F1,  F2,  F3,  F4,  F5,  F6,                 F7,  F8,  F9, F10, F11, F12,
  //|----+----+----+----+----+----|              |----+----+----+----+----+----|
      NO,  1,   2,   3,   4,   5,                  6,   7,   8,   9,   0,  DELETE,
  //|----+----+----+----+----+----|              |----+----+----+----+----+----|
     TRNS, EXLM, AT, HASH, DLR, PERC,          CIRC, AMPR, ASTR, LBRC, RBRC, TRNS,
  //|----+----+----+----+----+----+----.    ,----|----+----+----+----+----+----|
     TRNS, NO, NO, NO, NO, PIPE, TRNS,        TRNS, NO, DOT,  NO, LCBR, RCBR, TRNS,
  //`----+----+----+--+-+----+----+----/    \----+----+----+----+----+----+----'
                        TRNS, NO, TRNS,       TRNS, INS, TRNS
  //                  `----+----+----'        `----+----+----'
                      ),

   [_TWO] = LAYOUT_kc(
  //,----+----+----+----+----+----.              ,----+----+----+----+----+----.
      MUTE, VOLD, VOLU, NO, BRID, BRIU,           NO,  NO,  NO,  NO,  NO,  NO,
  //|----+----+----+----+----+----|              |----+----+----+----+----+----|
      PWR,  HOME,  NO, UP,  NO, PGUP,              NO,  NO,  NO,  NO,  NO, NO,
  //|----+----+----+----+----+----|              |----+----+----+----+----+----|
   TRNS, END, LEFT, DOWN, RIGHT, PGDOWN,           NO,  NO,  NO,  NO,  NO, TRNS,
  //|----+----+----+----+----+----+----.    ,----|----+----+----+----+----+----|
      TRNS, NO,  NO,  NO,  NO, NO,  TRNS,    TRNS, NO,  NO,  NO,  NO,  NO, TRNS,
  //`----+----+----+--+-+----+----+----/    \----+----+----+----+----+----+----'
                        TRNS, CAPS, DEL,      TRNS,  NO, TRNS
  //                  `----+----+----'        `----+----+----'
                      )
};

