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

#define KC_LSFT_BACK LSFT_T(KC_BACK)
#define KC_RSFT_UNDS RSFT_T(KC_UNDS)

#define KC_S_LALT RALT_T(KC_S)
#define KC_L_RALT RALT_T(KC_L)

#define KC_A_LCTL RCTL_T(KC_A)
#define KC_SCOLON_RCTL RCTL_T(KC_SCOLON)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

   [_QWERTY] = LAYOUT_kc(
  //,----+----+----+----+----+----.              ,----+----+----+----+----+----.
    GRAVE, 1,   2,   3,   4,   5,                   6,   7,   8,  9,   0,  MINUS,
  //|----+----+----+----+----+----|              |----+----+----+----+----+----|
     TAB, Q,   W,   E,   R,   T,                   Y,   U,   I,   O,   P,  BSLASH,
  //|----+----+----+----+----+----|              |----+----+----+----+----+----|
    ESC, A_LCTL, S_LALT, D_L2, F_L1, G,           H, J_L1, K_L2, L_RALT, SCOLON_RCTL, QUOT,
  //|----+----+----+----+----+----+----.    ,----|----+----+----+----+----+----|
 LSFT_BACK, Z,  X,   C,   V,   B,  BSPACE, DELETE,  N,  M, COMMA, DOT, SLASH, RSFT_UNDS,
  //`----+----+----+--+-+----+----+----/    \----+----+----+----+----+----+----'
                        LEFT, DOWN, SPACE,   ENTER, UP, RGHT
  //                  `----+----+----'        `----+----+----'
                      ),

   [_SYMBOL] = LAYOUT_kc(
  //,----+----+----+----+----+----.              ,----+----+----+----+----+----.
     F1,  F2,  F3,  F4,  F5,  F6,                  F7,  F8,  F9, F10, F11, F12,
  //|----+----+----+----+----+----|              |----+----+----+----+----+----|
   NO,  NO,  NO,  NO,  NO,  NO,                CIRC, LCBR, RCBR, NO, NO, NO,
  //|----+----+----+----+----+----|              |----+----+----+----+----+----|
   PERC, PLUS, EQUAL, ASTR, AMPR, HASH,          EXLM, LPRN, RPRN, DLR, AT, PIPE,
  //|----+----+----+----+----+----+----.    ,----|----+----+----+----+----+----|
      NO,  NO,  NO,  NO,  NO,  LEAD, CAPS,     INS,  NO, LBRC, RBRC, NO, NO,  NO,
  //`----+----+----+--+-+----+----+----/    \----+----+----+----+----+----+----'
                     LGUI, PGDOWN, BSPACE, DELETE, PGUP, END
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
                                 KC_NO,  KC_END, KC_NO,                  KC_NO,  KC_HOME,  KC_NO
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
    SEQ_TWO_KEYS(KC_1, KC_4) {
      SEND_STRING("¼");
    }
    SEQ_TWO_KEYS(KC_3, KC_4) {
      SEND_STRING("¾");
    }
  }
}
