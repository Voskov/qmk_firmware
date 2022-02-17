// this is the style you want to emulate.
// This is the canonical layout file for the Quantum project. If you want to add another keyboard,

#include QMK_KEYBOARD_H

// Each layer gets a name for readability, which is then used in the keymap matrix below.
// The underscores don't mean anything - you can have a layer called STUFF or any other name.
// Layer names don't all need to be of the same length, obviously, and you can also skip them
// entirely and just use numbers.

enum ferris_layers {
  _QWERTY,
  _COLEMAC,
  _LOWER,
  _RAISE,
  _CONFIG
};

enum ferris_tap_dances {
  TD_Q_ESC
};

#define KC_LGUA LGUI_T(KC_A)
#define KC_LALR LALT_T(KC_S)
#define KC_LALS LALT_T(KC_S)
#define KC_LSHS LSFT_T(KC_S)
#define KC_LSHD LSFT_T(KC_D)
#define KC_LCTF LCTL_T(KC_F)
#define KC_LCTT LCTL_T(KC_T)

#define KC_RCTJ RCTL_T(KC_J)
#define KC_RSHK RSFT_T(KC_K)
#define KC_LALL LALT_T(KC_L)
#define KC_RGUS RGUI_T(KC_SCLN)
#define KC_RCTN RCTL_T(KC_N)
#define KC_RSHE RSFT_T(KC_E)
#define KC_LALI LALT_T(KC_I)
#define KC_RGUO RGUI_T(KC_O)

#define KC_LWSP LT(3,KC_SPC)
#define KC_RSTB LT(4,KC_TAB)
#define KC_RSEN LT(4,KC_ENT)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [_QWERTY] = LAYOUT( /* QWERTY */
      KC_Q,     KC_W,     KC_E,     KC_R,     KC_T,           KC_Y,     KC_U,     KC_I,     KC_O,     KC_P,
      KC_LGUA,  KC_LALS,  KC_LSHD,  KC_LCTF,  KC_G,           KC_H,     KC_RCTJ,  KC_RSHK,  KC_LALL,  KC_RGUS,
      KC_Z,     KC_X,     KC_C,     KC_V,     KC_B,           KC_N,     KC_M,     KC_COMM,  KC_DOT,   KC_SLSH,
                                    KC_RSTB,  KC_LWSP,        KC_LWSP,  KC_RSEN
  ),

  [_COLEMAC] = LAYOUT( /* COLEMAK */
      KC_Q,     KC_W,     KC_F,     KC_P,     KC_G,           KC_J,     KC_L,     KC_U,     KC_Y,     KC_SCLN,
      KC_LGUA,  KC_LALR,  KC_LSHS,  KC_LCTT,  KC_D,           KC_H,     KC_RCTN,  KC_RSHE,  KC_LALI,  KC_RGUO,
      KC_Z,     KC_X,     KC_C,     KC_V,     KC_B,           KC_K,     KC_M,     KC_COMM,  KC_DOT,   KC_SLSH,
                                    KC_RSTB,  KC_LWSP,        KC_LWSP,  KC_RSEN
  ),

  [_LOWER] = LAYOUT( /* [> LOWER <] */
      KC_TAB,   KC_EXLM,  KC_AT,    KC_LCBR,  KC_RCBR,        KC_PGUP,  KC_HOME,  KC_UP,    KC_END,   KC_BSPC,
      KC_ESC,   KC_HASH,  KC_ASTR,  KC_LBRC,  KC_RBRC,        KC_PGDN,  KC_LEFT,  KC_DOWN,  KC_RGHT,  KC_QUOT,
      KC_GRV,   KC_DLR,   KC_AMPR,  KC_LPRN,  KC_RPRN,        KC_MINS,  KC_EQL,   KC_DEL,   KC_INS,   KC_ENT,
                                    MO(5),    KC_TRNS,        KC_TRNS,  MO(5)
  ),

  [_RAISE] = LAYOUT( /* [> RAISE <] */
      KC_F1,    KC_F2,    KC_F3,    KC_F4,    KC_VOLU,        KC_VOLU,  KC_7,     KC_8,     KC_9,     KC_BSPC,
      KC_F5,    KC_F6,    KC_F7,    KC_F8,    KC_VOLD,        KC_VOLD,  KC_4,     KC_5,     KC_6,     KC_BSLS,
      KC_F9,    KC_F10,   KC_F11,   KC_F12,   KC_APP,         KC_0,     KC_1,     KC_2,     KC_3,     KC_ENT,
                                    KC_TRNS,  MO(5),          MO(5),    KC_TRNS
  ),

  [_CONFIG] = LAYOUT( /* [> CONFIG <] */
      KC_TRNS,  KC_ACL0,  KC_ACL1,  KC_ACL2,  KC_TRNS,        KC_WH_U,  KC_BTN1,  KC_MS_U,  KC_BTN2,  KC_TRNS,
      KC_TRNS,  KC_BTN2,  KC_NO,    KC_BTN1,  KC_TRNS,        KC_WH_D,  KC_MS_L,  KC_MS_D,  KC_MS_R,  KC_TRNS,
      RESET,    KC_TRNS,  KC_TRNS,  DF(1),    DF(0),          KC_TRNS,  KC_WH_L,  KC_TRNS,  KC_WH_R,  RESET,
                                    KC_TRNS,  KC_TRNS,        KC_TRNS,  KC_TRNS
  )
};

// Tap Dance Definitions
qk_tap_dance_action_t tap_dance_actions[] = {
    // Tap once for Q, twice for ESC
    [TD_Q_ESC] = ACTION_TAP_DANCE_DOUBLE(KC_Q, KC_ESC)
};
