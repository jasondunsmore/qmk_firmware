#include QMK_KEYBOARD_H

extern keymap_config_t keymap_config;

// Layers
#define _QWERTY 0 // Base layer
#define _SYMBOL 1 // Symbols

#define KC_LCA_TAB LCA_T(KC_TAB)
#define KC_LCA_BSLASH LCA_T(KC_BSLASH)
#define KC_LCTL_DELETE LCTL_T(KC_DELETE)
#define KC_L1_SPACE LT(1,KC_SPACE)
#define KC_L1_ENTER LT(1,KC_ENTER)
#define KC_RCTL_BSPACE RCTL_T(KC_BSPACE)
#define KC_LSFT_A LSFT_T(KC_A)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

   [_QWERTY] = LAYOUT_kc(
  //,----+----+----+----+----+----.              ,----+----+----+----+----+----.
   GRAVE, 1,   2,   3,   4,   5,                   6,   7,   8,  9,   0,  BSPACE,
  //|----+----+----+----+----+----|              |----+----+----+----+----+----|
   LCA_TAB, Q,  W,   E,   R,   T,                  Y,   U,   I,   O,   P,  LCA_BSLASH,
  //|----+----+----+----+----+----|              |----+----+----+----+----+----|
      ESC, LSFT_A,   S,   D,   F,   G,             H,   J,   K,   L, SCOLON, QUOT,
  //|----+----+----+----+----+----+----.    ,----|----+----+----+----+----+----|
    LSPO, Z,   X,   C,   V,   B,  MINUS,    UNDS, N,   M, COMMA, DOT, SLASH, RSPC,
  //`----+----+----+--+-+----+----+----/    \----+----+----+----+----+----+----'
          LALT, LCTL_DELETE, L1_SPACE,   L1_ENTER, RCTL_BSPACE, RALT
  //                  `----+----+----'        `----+----+----'
                      ),

   [_SYMBOL] = LAYOUT_kc(
  //,----+----+----+----+----+----.              ,----+----+----+----+----+----.
      F1,  F2,  F3,  F4,  F5,  F6,                 F7,  F8,  F9, F10, F11, F12,
  //|----+----+----+----+----+----|              |----+----+----+----+----+----|
    BRID, BRIU, F15, F16, F17, F18,                F19, F20, F21, F22, F23, F24,
  //|----+----+----+----+----+----|              |----+----+----+----+----+----|
   DLR, HASH, AT, EXCLAIM, CIRC, ASTR,           LEFT, DOWN, UP, RIGHT, NO, NO,
  //|----+----+----+----+----+----+----.    ,----|----+----+----+----+----+----|
 VOLD, VOLU, MUTE, PWR, PERC, GRAVE, PLUS, EQUAL, HOME, PGDOWN, PGUP, END, NO, CAPSLOCK,
  //`----+----+----+--+-+----+----+----/    \----+----+----+----+----+----+----'
                      LGUI, LBRC, LCBR,      RCBR, RBRC, RGUI
  //                  `----+----+----'        `----+----+----'
                      )
};
