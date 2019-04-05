#include QMK_KEYBOARD_H

extern keymap_config_t keymap_config;

// Layers
#define _QWERTY 0 // Base layer
#define _ONE 1
#define _TWO 2

#define KC_LCA_TAB LCA_T(KC_TAB)
#define KC_LCA_BSLASH LCA_T(KC_BSLASH)
#define KC_RCTL_QUOT RCTL_T(KC_QUOT)
#define KC_LCTL_GRAVE LCTL_T(KC_GRAVE)
#define KC_ONE MO(1)
#define KC_TWO MO(2)

// Org-mode
#define KC_LCS_LEFT LALT(LSFT(KC_LEFT))
#define KC_LCS_RIGHT LALT(LSFT(KC_RIGHT))
#define KC_LCS_UP LALT(LSFT(KC_UP))
#define KC_LCS_DOWN LALT(LSFT(KC_DOWN))

// Web browser
#define KC_C_PGUP C(KC_PGUP)
#define KC_C_PGDOWN C(KC_PGDOWN)
#define KC_A_LEFT A(KC_LEFT)
#define KC_A_RIGHT A(KC_RIGHT)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

   [_QWERTY] = LAYOUT_kc(
  //,----+----+----+----+----+----.              ,----+----+----+----+----+----.
   ESC, 1,   2,   3,   4,   5,                   6,   7,   8,  9,   0,  BSPACE,
  //|----+----+----+----+----+----|              |----+----+----+----+----+----|
   LCA_TAB, Q,  W,   E,   R,   T,                  Y,   U,   I,   O,   P,  LCA_BSLASH,
  //|----+----+----+----+----+----|              |----+----+----+----+----+----|
  LCTL_GRAVE, A, S,  D,   F,   G,                  H,   J,   K,   L, SCOLON, RCTL_QUOT,
  //|----+----+----+----+----+----+----.    ,----|----+----+----+----+----+----|
    LSPO, Z,   X,   C,   V,   B,  MINUS,    UNDS, N,   M, COMMA, DOT, SLASH, RSPC,
  //`----+----+----+--+-+----+----+----/    \----+----+----+----+----+----+----'
                      LALT, ONE, SPACE,   ENTER, TWO, RALT
  //                  `----+----+----'        `----+----+----'
                      ),

   [_ONE] = LAYOUT_kc(
  //,----+----+----+----+----+----.              ,----+----+----+----+----+----.
      F1,  F2,  F3,  F4,  F5,  F6,                 F7,  F8,  F9, F10, F11, F12,
  //|----+----+----+----+----+----|              |----+----+----+----+----+----|
      NO,  1,   2,   3,   4,   5,                  6,   7,   8,   9,   0,  MINUS,
  //|----+----+----+----+----+----|              |----+----+----+----+----+----|
      TILD, EXLM, AT, HASH, DLR, PERC,          CIRC, AMPR, ASTR, LBRC, RBRC, PLUS,
  //|----+----+----+----+----+----+----.    ,----|----+----+----+----+----+----|
      NO, NO, NO, NO, NO, NO, NO,            NO, NO, NO,  NO, LCBR, RCBR, EQUAL,
  //`----+----+----+--+-+----+----+----/    \----+----+----+----+----+----+----'
                        NO,  NO,  NO,          DEL, EQUAL, LGUI
  //                  `----+----+----'        `----+----+----'
                      ),

   [_TWO] = LAYOUT_kc(
  //,----+----+----+----+----+----.              ,----+----+----+----+----+----.
      PWR,  NO,  NO, VOLU, BRIU, NO,              NO, C_PGUP, NO,  NO, C_PGUP, PGUP,
  //|----+----+----+----+----+----|              |----+----+----+----+----+----|
      NO,  NO,  MUTE, VOLD, BRID, NO,    NO, C_PGDOWN, A_LEFT, A_RIGHT, C_PGDOWN, PGDOWN,
  //|----+----+----+----+----+----|              |----+----+----+----+----+----|
      NO,  NO,  LEFT, RIGHT, UP, NO,         NO, LCS_UP, LCS_LEFT, LCS_RIGHT, NO, HOME,
  //|----+----+----+----+----+----+----.    ,----|----+----+----+----+----+----|
      NO, NO,  NO,  NO,  DOWN, NO,  NO,       NO, NO, LCS_DOWN, NO, NO, NO, END,
  //`----+----+----+--+-+----+----+----/    \----+----+----+----+----+----+----'
                        INS, CAPS, DEL,          NO,  NO,  NO
  //                  `----+----+----'        `----+----+----'
                      )
};
