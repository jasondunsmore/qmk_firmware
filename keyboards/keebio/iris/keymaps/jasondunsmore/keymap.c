#include QMK_KEYBOARD_H

extern keymap_config_t keymap_config;

// Layers
#define _QWERTY 0 // Base layer
#define _SYMBOL 1 // Symbols
#define _ADJUST 2 // Hardware adjustment keys

#define KC_BACK LALT(KC_LEFT)
#define KC_D_L2 LT(2,KC_D)
#define KC_F_L1 LT(1,KC_F)
#define KC_J_L1 LT(1,KC_J)
#define KC_K_L2 LT(2,KC_K)
#define KC_LCTL_LEFT LCTL_T(KC_LEFT)
#define KC_LSFT_SPC LSFT_T(KC_SPC)
#define KC_RSFT_ENT RSFT_T(KC_ENT)
#define KC_RCTL_RGHT RCTL_T(KC_RGHT)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

   [_QWERTY] = LAYOUT_kc(
  //,----+----+----+----+----+----.              ,----+----+----+----+----+----.
     BACK, 1,   2,   3,   4,   5,                   6,   7,   8,  9,   0,  BSPC,
  //|----+----+----+----+----+----|              |----+----+----+----+----+----|
     UNDS, Q,   W,   E,   R,   T,                   Y,   U,   I,   O,   P, BSLS,
  //|----+----+----+----+----+----|              |----+----+----+----+----+----|
     MINS, A,  S,  D_L2, F_L1, G,                  H, J_L1, K_L2, L, SCLN, QUOT,
  //|----+----+----+----+----+----+----.    ,----|----+----+----+----+----+----|
     LEFT, Z,  X,   C,    V,  B,   TAB,      GESC, N,   M, COMM, DOT, SLSH, RGHT,
  //`----+----+----+--+-+----+----+----/    \----+----+----+----+----+----+----'
               LALT, LCTL_LEFT, LSFT_SPC,     RSFT_ENT, RCTL_RGHT, RALT
  //                  `----+----+----'        `----+----+----'
                      ),

   [_SYMBOL] = LAYOUT_kc(
  //,----+----+----+----+----+----.              ,----+----+----+----+----+----.
     F1,  F2,  F3,  F4,  F5,  F6,                  F7,  F8,  F9, F10, F11, F12,
  //|----+----+----+----+----+----|              |----+----+----+----+----+----|
     NO, EXLM, AT, HASH, DLR, PERC,            CIRC, AMPR, ASTR, PLUS, PEQL, DEL,
  //|----+----+----+----+----+----|              |----+----+----+----+----+----|
     GRV, TILD, BSLS, LPRN, RPRN, PIPE,          LEFT, DOWN, UP, RGHT, PMNS, NO,
  //|----+----+----+----+----+----+----.    ,----|----+----+----+----+----+----|
     DOWN, NO, NO, LCBR, RCBR, NO, CAPS,    INS, DQUO, LBRC, RBRC, NO, NO,  UP,
  //`----+----+----+--+-+----+----+----/    \----+----+----+----+----+----+----'
                       HOME, LEFT, BSPC,      DEL, RGHT, END
  //                  `----+----+----'        `----+----+----'
                      ),
   
   [_ADJUST] = LAYOUT(
  //┌────────┬────────┬────────┬────────┬────────┬────────┐                        ┌────────┬────────┬────────┬────────┬────────┬────────┐
     KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_NO,                          KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_NO,
  //├────────┼────────┼────────┼────────┼────────┼────────┤                        ├────────┼────────┼────────┼────────┼────────┼────────┤
     BL_TOGG, KC_NO, KC_MUTE, KC_VOLD, KC_VOLU, KC_NO,                       KC_BTN1, KC_BTN2, KC_BTN3, KC_NO, KC_NO, KC_NO,
  //├────────┼────────┼────────┼────────┼────────┼────────┤                        ├────────┼────────┼────────┼────────┼────────┼────────┤
     BL_STEP, BL_DEC, BL_INC, BL_ON, BL_OFF, BL_BRTG,                        KC_MS_L, KC_MS_D, KC_MS_U, KC_MS_R, KC_NO, KC_NO,
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┐        ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┤
 RESET, EEP_RST, DEBUG, KC_PWR, KC_WAKE, KC_SLEP, KC_PSCR, KC_SLCK,   KC_WH_L, KC_WH_D, KC_WH_U, KC_WH_R, KC_CAPS, KC_RGUI,
  //└────────┴────────┴────────┴───┬────┴───┬────┴───┬────┴───┬────┘        └───┬────┴───┬────┴───┬────┴───┬────┴────────┴────────┴────────┘
                               KC_PAUS, KC_UNDO, KC_CUT,               KC_COPY, KC_PSTE, KC_NLCK
                            // └────────┴────────┴────────┘                └────────┴────────┴────────┘
                      )
};
