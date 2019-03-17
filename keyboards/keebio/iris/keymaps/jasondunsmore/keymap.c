#include QMK_KEYBOARD_H

extern keymap_config_t keymap_config;

// Layers
#define _QWERTY 0 // Base layer
#define _SYMBOL 1 // Symbols
#define _KEYBD 2  // Firmware reset keys


const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

   [_QWERTY] = LAYOUT_kc(
  //,----+----+----+----+----+----.              ,----+----+----+----+----+----.
    PLUS, 1,   2,   3,   4,   5,                   6,   7,   8,  9,   0,  L2_EQUAL,
  //|----+----+----+----+----+----|              |----+----+----+----+----+----|
 LCA_GRAVE, Q,  W,   E,   R,   T,                  Y,   U,   I,   O,   P,  LCA_BSLASH,
  //|----+----+----+----+----+----|              |----+----+----+----+----+----|
      ESC, A,   S,   D,   F,   G,                  H,   J,   K,   L, SCOLON, LEAD_QUOT,
  //|----+----+----+----+----+----+----.    ,----|----+----+----+----+----+----|
 LSPO, Z,  X,   C,   V,   B, LEAD_DELETE, LEAD_HASH, N, M, COMMA, DOT, SLASH, RSPC,
  //`----+----+----+--+-+----+----+----/    \----+----+----+----+----+----+----'
          LALT_MINUS, LCTL_TAB, L1_SPACE,   L1_ENTER, RCTL_BSPACE, LALT_UNDS
  //                  `----+----+----'        `----+----+----'
                      ),

   [_SYMBOL] = LAYOUT_kc(
  //,----+----+----+----+----+----.              ,----+----+----+----+----+----.
      F1,  F2,  F3,  F4,  F5,  F6,                 F7,  F8,  F9, F10, F11, F12,
  //|----+----+----+----+----+----|              |----+----+----+----+----+----|
      F13, F14, F15, F16, F17, F18,                F19, F20, F21, F22, F23, F24,
  //|----+----+----+----+----+----|              |----+----+----+----+----+----|
   ASTR, EXCLAIM, AT, HASH, DLR, PERC,            LEFT, DOWN, UP, RIGHT, NO, NO,
  //|----+----+----+----+----+----+----.    ,----|----+----+----+----+----+----|
  MUTE, VOLD, VOLU, PWR, SLEP, WAKE, CIRC,  AMPR, HOME, PGDOWN, PGUP, END, NO, NO,
  //`----+----+----+--+-+----+----+----/    \----+----+----+----+----+----+----'
                      LGUI, LBRC, LCBR,      RCBR, RBRC, RGUI
  //                  `----+----+----'        `----+----+----'
                      ),
   
   [_KEYBD] = LAYOUT(
  //┌────────┬────────┬────────┬────────┬────────┬────────┐                        ┌────────┬────────┬────────┬────────┬────────┬────────┐
     KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_NO,                          KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_NO,
  //├────────┼────────┼────────┼────────┼────────┼────────┤                        ├────────┼────────┼────────┼────────┼────────┼────────┤
     KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_NO,                          KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_NO,
  //├────────┼────────┼────────┼────────┼────────┼────────┤                        ├────────┼────────┼────────┼────────┼────────┼────────┤
     KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_NO,                          KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_NO,
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┐        ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┤
     RESET, EEP_RST, DEBUG,  KC_NO,  KC_NO,  KC_NO,  KC_NO,           KC_NO, KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_NO,
  //└────────┴────────┴────────┴───┬────┴───┬────┴───┬────┴───┬────┘        └───┬────┴───┬────┴───┬────┴───┬────┴────────┴────────┴────────┘
                                 KC_NO,  KC_NO, KC_NO,                   KC_NO,  KC_NO,  KC_NO
                            // └────────┴────────┴────────┘                └────────┴────────┴────────┘
                      )

};

LEADER_EXTERNS();

void matrix_scan_user(void) {
  LEADER_DICTIONARY() {
    leading = false;
    leader_end();

    SEQ_ONE_KEY(KC_0) {
      SEND_STRING("°");
    }
    SEQ_TWO_KEYS(KC_1, KC_2) {
      SEND_STRING("½");
    }
    SEQ_TWO_KEYS(KC_1, KC_3) {
      SEND_STRING("⅓");
    }
    SEQ_TWO_KEYS(KC_2, KC_3) {
      SEND_STRING("⅔");
    }
    SEQ_TWO_KEYS(KC_1, KC_4) {
      SEND_STRING("¼");
    }
    SEQ_TWO_KEYS(KC_3, KC_4) {
      SEND_STRING("¾");
    }
  }
}
