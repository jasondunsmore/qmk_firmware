#include QMK_KEYBOARD_H

extern keymap_config_t keymap_config;

// Layers
#define _QWERTY 0 // Base layer
#define _NUMB 1
#define _NAVI 2
#define _SYMB 3
#define _FUNC 4

// Keys
#define KC_AQUT RALT_T(KC_QUOT)
#define KC_AGRV LALT_T(KC_GRAVE)
#define KC_GUIE LGUI_T(KC_ESC)
#define KC_MISY LT(_SYMB, KC_MINS)
#define KC_EQFU LT(_FUNC, KC_EQL)
#define KC_NUMB MO(_NUMB)
#define KC_NAVI MO(_NAVI)
#define KC_REST RESET
#define KC_DBUG DEBUG

// Tap Dance Declarations
enum {
  TD_SLSH_BSLS = 0,
  TD_LSFT_LBRC,
  TD_RSFT_RBRC,
  TD_NUMB_SYMB,
  TD_NAVI_FUNC
};

bool fn_held;

void numb_symb(qk_tap_dance_state_t *state, void *user_data) {
    if (state->count == 1 && state->pressed) {
      layer_on(_NUMB);
      fn_held = true;
    } else if (state->count == 2 && state->pressed) {
      layer_on(_SYMB);
      fn_held = true;
    }
}

void numb_symb_finish(qk_tap_dance_state_t *state, void *user_data) {
    if (fn_held) {
      layer_off(_NUMB);
      layer_off(_SYMB);
      fn_held = false;
    }
}

void navi_func(qk_tap_dance_state_t *state, void *user_data) {
    if (state->count == 1 && state->pressed) {
      layer_on(_NAVI);
      fn_held = true;
    } else if (state->count == 2 && state->pressed) {
      layer_on(_FUNC);
      fn_held = true;
    }
}

void navi_func_finish(qk_tap_dance_state_t *state, void *user_data) {
    if (fn_held) {
      layer_off(_NAVI);
      layer_off(_FUNC);
      fn_held = false;
    }
}

void left_brackets(qk_tap_dance_state_t *state, void *user_data) {
    if (state->count == 1) {
      if (!state->pressed) {
        register_code(KC_LSFT);
        register_code(KC_9);
      } else {
        register_code(KC_LSFT);
      }
    } else if (state->count == 2) {
        register_code(KC_LBRC);
    } else if (state->count == 3) {
        register_code(KC_LSFT);
        register_code(KC_LBRC);
    }
}

void left_brackets_reset(qk_tap_dance_state_t *state, void *user_data) {
    if (state->count == 1) {
        unregister_code(KC_LSFT);
        unregister_code(KC_9);
    } else if (state->count == 2) {
        unregister_code(KC_LBRC);
    } else if (state->count == 3) {
        unregister_code(KC_LSFT);
        unregister_code(KC_LBRC);
    }
}

void right_brackets(qk_tap_dance_state_t *state, void *user_data) {
    if (state->count == 1) {
      if (!state->pressed) {
        register_code(KC_RSFT);
        register_code(KC_0);
      } else {
        register_code(KC_RSFT);
      }
    } else if (state->count == 2) {
        register_code(KC_RBRC);
    } else if (state->count == 3) {
        register_code(KC_RSFT);
        register_code(KC_RBRC);
    }
}

void right_brackets_reset(qk_tap_dance_state_t *state, void *user_data) {
    if (state->count == 1) {
        unregister_code(KC_RSFT);
        unregister_code(KC_0);
    } else if (state->count == 2) {
        unregister_code(KC_RBRC);
    } else if (state->count == 3) {
        unregister_code(KC_RSFT);
        unregister_code(KC_RBRC);
    }
}

// Tap Dance Definitions
qk_tap_dance_action_t tap_dance_actions[] = {
  // Tap once for KC_SLSH, twice for KC_BSLS
  [TD_SLSH_BSLS]  = ACTION_TAP_DANCE_DOUBLE(KC_SLSH, KC_BSLS),
  [TD_LSFT_LBRC] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, left_brackets, left_brackets_reset),
  [TD_RSFT_RBRC] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, right_brackets, right_brackets_reset),
  [TD_NUMB_SYMB] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, numb_symb, numb_symb_finish),
  [TD_NAVI_FUNC] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, navi_func, navi_func_finish)
};

// Tap Dance Keys
#define KC_SLBS TD(TD_SLSH_BSLS)
#define KC_LSBK TD(TD_LSFT_LBRC)
#define KC_RSBK TD(TD_RSFT_RBRC)
#define KC_NUSY TD(TD_NUMB_SYMB)
#define KC_NAFU TD(TD_NAVI_FUNC)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

  [_QWERTY] = LAYOUT_kc(
//,----+----+----+----+----+----.              ,----+----+----+----+----+----.
   GUIE, 1,   2,   3,   4,   5,                  6,   7,   8,   9,   0,  DEL,
//|----+----+----+----+----+----|              |----+----+----+----+----+----|
   TAB,  Q,   W,   E,   R,   T,                  Y,   U,   I,   O,   P,  BSPC,
//|----+----+----+----+----+----|              |----+----+----+----+----+----|
   AGRV, A,   S,   D,   F,   G,                  H,   J,   K,   L,  SCLN,AQUT,
//|----+----+----+----+----+----+----.    ,----|----+----+----+----+----+----|
   LSBK, Z,   X,   C,   V,   B,  MINS,     EQL,  N,   M,  COMM,DOT, SLBS,RSBK,
//`----+----+----+--+-+----+----+----/    \----+----+----+----+----+----+----'
                     NUSY,LCTL,SPC,          ENT, RCTL,NAFU
//                  `----+----+----'        `----+----+----'
     ),

  [_NUMB] = LAYOUT_kc(
//,----+----+----+----+----+----.              ,----+----+----+----+----+----.
    NO,  NO,  NO,  NO,  NO,  NO,                 NO,  NO,  NO,  NO,  NO, TRNS,
//|----+----+----+----+----+----|              |----+----+----+----+----+----|
    NO,  1,   2,   3,   4,   5,                  6,   7,   8,   9,   0,  TRNS,
//|----+----+----+----+----+----|              |----+----+----+----+----+----|
   TRNS, NO,  NO,  NO,  NO,  NO,                ASTR, 4,   5,   6,  PLUS,TRNS,
//|----+----+----+----+----+----+----.    ,----|----+----+----+----+----+----|
   TRNS, NO,  NO,  NO,  NO,  NO, TRNS,     TRNS,SLSH, 1,   2,   3,  MINS,TRNS,
//`----+----+----+--+-+----+----+----/    \----+----+----+----+----+----+----'
                     TRNS,TRNS,TRNS,         TRNS,TRNS,TRNS
//                  `----+----+----'        `----+----+----'
      ),

 [_NAVI] = LAYOUT_kc(
//,----+----+----+----+----+----.              ,----+----+----+----+----+----.
   PWR, MUTE,VOLD,VOLU,BRID,BRIU,                NO,  NO,  NO,  NO,  NO, TRNS,
//|----+----+----+----+----+----|              |----+----+----+----+----+----|
   WAKE, HOME, NO,  UP,  NO, PGUP,               NO,  NO,  NO,  NO,  NO, TRNS,
//|----+----+----+----+----+----|              |----+----+----+----+----+----|
   TRNS,END, LEFT,DOWN,RGHT,PGDN,               WAKE, NO,  NO,  NO,  NO, TRNS,
//|----+----+----+----+----+----+----.    ,----|----+----+----+----+----+----|
   TRNS, NO,  NO,  NO,  NO,  NO,  NO,      TRNS,PWR, REST,DBUG, NO,  NO, TRNS,
//`----+----+----+--+-+----+----+----/    \----+----+----+----+----+----+----'
                     TRNS,TRNS,TRNS,         TRNS,TRNS,TRNS
//                  `----+----+----'        `----+----+----'
     ),

  [_SYMB] = LAYOUT_kc(
//,----+----+----+----+----+----.              ,----+----+----+----+----+----.
    NO,  NO,  NO,  NO,  NO,  NO,                 NO,  NO,  NO,  NO,  NO, TRNS,
//|----+----+----+----+----+----|              |----+----+----+----+----+----|
    NO,  NO,  NO,  NO,  NO,  NO,                 NO,  NO,  NO,  NO,  NO, TRNS,
//|----+----+----+----+----+----|              |----+----+----+----+----+----|
   TRNS,EXLM, AT, HASH,DLR, PERC,               CIRC,AMPR,ASTR,LBRC,RBRC,TRNS,
//|----+----+----+----+----+----+----.    ,----|----+----+----+----+----+----|
   TRNS, NO,  NO, BSLS,PIPE, NO, TRNS,     TRNS, NO, DOT,  NO, LCBR,RCBR,TRNS,
//`----+----+----+--+-+----+----+----/    \----+----+----+----+----+----+----'
                     TRNS,TRNS,TRNS,         TRNS,TRNS,TRNS
//                  `----+----+----'        `----+----+----'
      ),

 [_FUNC] = LAYOUT_kc(
//,----+----+----+----+----+----.              ,----+----+----+----+----+----.
    NO,  NO,  NO,  NO,  NO,  NO,                 NO,  NO,  NO,  NO,  NO, TRNS,
//|----+----+----+----+----+----|              |----+----+----+----+----+----|
    NO, PAUS,SLCK,PSCR,INS, CAPS,                NO,  NO,  NO,  NO,  NO, TRNS,
//|----+----+----+----+----+----|              |----+----+----+----+----+----|
   F12,  F1,  F2,  F3,  F4,  F5,                 F6,  F7,  F8,  F9, F10, F11,
//|----+----+----+----+----+----+----.    ,----|----+----+----+----+----+----|
   TRNS, NO,  NO,  NO,  NO,  NO, TRNS,     TRNS, NO,  NO,  NO,  NO,  NO, TRNS,
//`----+----+----+--+-+----+----+----/    \----+----+----+----+----+----+----'
                     TRNS,TRNS,TRNS,         TRNS,TRNS,TRNS
 //                  `----+----+----'        `----+----+----'
      )

};
