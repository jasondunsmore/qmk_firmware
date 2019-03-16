#include QMK_KEYBOARD_H

extern keymap_config_t keymap_config;

// Layers
#define _QWERTY 0 // Base layer
#define _SYMBOL 1 // Symbols
#define _ADJUST 2 // Hardware adjustment keys

#define KC_BACK LALT(KC_LEFT)



const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

   [_QWERTY] = LAYOUT_kc(
  //,----+----+----+----+----+----.              ,----+----+----+----+----+----.
    PLUS, 1,   2,   3,   4,   5,                   6,   7,   8,  9,   0,  EQUAL,
  //|----+----+----+----+----+----|              |----+----+----+----+----+----|
 LCA_GRAVE, Q,  W,   E,   R,   T,                  Y,   U,   I,   O,   P,  LCA_BSLASH,
  //|----+----+----+----+----+----|              |----+----+----+----+----+----|
     ESC,  A,   S,   D,   F,   G,                  H,   J,   K,   L, SCOLON, QUOT,
  //|----+----+----+----+----+----+----.    ,----|----+----+----+----+----+----|
     LSPO, Z,   X,   C,   V,   B, L2_MINUS, L2_UNDS, N, M, COMMA, DOT, SLASH, RSPC,
  //`----+----+----+--+-+----+----+----/    \----+----+----+----+----+----+----'
          L1_BACK, LALT_TAB, LCTL_SPACE,   RCTL_ENTER, RALT_BSPACE, L1_DELETE
  //                  `----+----+----'        `----+----+----'
                      ),

   [_SYMBOL] = LAYOUT_kc(
  //,----+----+----+----+----+----.              ,----+----+----+----+----+----.
      F1,  F2,  F3,  F4,  F5,  F6,                 F7,  F8,  F9, F10, F11, F12,
  //|----+----+----+----+----+----|              |----+----+----+----+----+----|
      NO,  NO,  NO,  NO,  NO,  NO,                 NO,  NO,  NO,  NO,  NO,  NO,
  //|----+----+----+----+----+----|              |----+----+----+----+----+----|
      NO, NO, DLR, PERC, AMPR, NO,                LEFT, DOWN, UP, RIGHT, NO, NO,
  //|----+----+----+----+----+----+----.    ,----|----+----+----+----+----+----|
      NO,  NO,  NO,  NO,  NO,  NO, HASH,     PIPE, HOME, PGDOWN, PGUP, END, NO, NO,
  //`----+----+----+--+-+----+----+----/    \----+----+----+----+----+----+----'
                       LEAD, LBRC, LCBR,      RCBR, RBRC, RGUI
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
                                 KC_NO,  KC_NO, KC_NO,                  KC_NO,  KC_NO,  KC_NO
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
