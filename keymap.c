#include "lets_split.h"
#include "action_layer.h"
#include "eeconfig.h"

extern keymap_config_t keymap_config;

// Each layer gets a name for readability, which is then used in the keymap matrix below.
// The underscores don't mean anything - you can have a layer called STUFF or any other name.
// Layer names don't all need to be of the same length, obviously, and you can also skip them
// entirely and just use numbers.
#define _QWERTY 0
#define _GAMING 1
#define _LOWER 3
#define _RAISE 4
#define _ADJUST 16

enum custom_keycodes {
  QWERTY = SAFE_RANGE,
  GAMING,
  LOWER,
  RAISE,
  ADJUST,
};

//Tap Dance Declarations
enum {
  GME_1 = 0,
  GME_2 = 0,
  GME_3 = 0,
  GME_4 = 0,
};


//Tap Dance Definitions
  qk_tap_dance_action_t tap_dance_actions[] = {
  [GME_1] = ACTION_TAP_DANCE_DOUBLE(KC_1, KC_4),
  [GME_2] = ACTION_TAP_DANCE_DOUBLE(KC_2, KC_5), // Tap once for 2tap twice for 5
  [GME_3] = ACTION_TAP_DANCE_DOUBLE(KC_3, KC_6), // Tap once for 3 tap twice for 6
  [TT_HY] = ACTION_TAP_DANCE_DOUBLE(KC_T, KC_Y),  // Tap once for T tap twice for Y
}; // Fillers to make layering more clear

#define _______ KC_TRNS
#define XXXXXXX KC_NO
#define KC_TD TD

// Custom macros
//#define CTL_ESC     CTL_T(KC_ESC)                 // Tap for Esc, hold for Ctrl
#define SFT_ENT     SFT_T(KC_ENT)                   // Tap for Enter, hold for Shift
//#define HPR_TAB     ALL_T(KC_TAB)                 // Tap for Tab, hold for Hyper (Super+Ctrl+Alt+Shift)
//#define MEH_GRV     MEH_T(KC_GRV)                 // Tap for Backtick, hold for Meh (Ctrl+Alt+Shift)
//#define GME_1   ACTION_TAP_DANCE_DOUBLE(KC_1, KC_4) // Tap once for 1 tap twice for 4
//#define GME_2   ACTION_TAP_DANCE_DOUBLE(KC_2, KC_5) // Tap once for 2tap twice for 5
//#define GME_3   ACTION_TAP_DANCE_DOUBLE(KC_3, KC_6) // Tap once for 3 tap twice for 6
//#define TT_HY   ACTION_TAP_DANCE_DOUBLE(KC_T, KC_Y) // Tap once for T tap twice for Y


const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {



/* Qwerty
 * ,-----------------------------------------. ,-----------------------------------------.
 * | Tab  |   Q  |   W  |   E  |   R  |   T  | |   Y  |   U  |   I  |   O  |   P  | Bksp |
 * |------+------+------+------+------+------| |------+------+------+------+------+------|
 * | Esc  |   A  |   S  |   D  |   F  |   G  | |   H  |   J  |   K  |   L  |   ;  |  "   |
 * |------+------+------+------+------+------| |------+------+------+------+------+------|
 * | Shift|   Z  |   X  |   C  |   V  |   B  | |   N  |   M  |   ,  |   .  |   /  |Enter/shift
 * |------+------+------+------+------+------| |------+------+------+------+------+------|
 * | Ctrl | GUI  | Alt  | Del  |Lower |Space | |Space |Raise | Left | Down |  Up  |Right |
 * `-----------------------------------------' `-----------------------------------------'
 */
[_QWERTY] = KEYMAP( \
  KC_TAB, KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_BSPC, \
  KC_ESC, KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT, \
  KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,   KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, SFT_ENT, \
  KC_LCTL, KC_LGUI, KC_LALT, KC_DEL, LOWER,   KC_SPC,  KC_SPC,  RAISE,   KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT
),

/* Gaming
 * ,-----------------------------------------. ,-----------------------------------------.
 * | Tab  |   Q  |   W  |   E  |   R  |  T/Y | |   Y  |   U  |   I  |   O  |   P  | Bksp |
 * |------+------+------+------+------+------| |------+------+------+------+------+------|
 * | Esc  |   A  |   S  |   D  |   F  |   G  | |   H  |   J  |   K  |   L  |   ;  |  "   |
 * |------+------+------+------+------+------| |------+------+------+------+------+------|
 * | Shift|   Z  |   X  |   C  |   V  |   B  | |   N  |   M  |   ,  |   .  |   /  |Enter/shift
 * |------+------+------+------+------+------| |------+------+------+------+------+------|
 * | Ctrl | GUI  |   1  |   2  |   3  |Space | |Lower |Raise | Left | Down |  Up  |Right |
 * `-----------------------------------------' `-----------------------------------------'
 */
[_GAMING] = KEYMAP( \
  KC_TAB,  KC_Q,    KC_W,      KC_E,       KC_R,      TD(TT_HY), KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_BSPC, \
  KC_ESC,  KC_A,    KC_S,      KC_D,       KC_F,      KC_G,      KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT, \
  KC_LSFT, KC_Z,    KC_X,      KC_C,       KC_V,      KC_B,      KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, SFT_ENT, \
  KC_LCTL, KC_LALT, TD(GME_1), TD(GME_2), TD(GME_3), KC_SPC,    LOWER,   RAISE,   KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT
),

/* Lower
 * ,-----------------------------------------. ,-----------------------------------------.
 * | Tab  |   1  |   2  |   3  |   4  |   5  | |   6  |   7  |   8  |   9  |   0  | Del  |
 * |------+------+------+------+------+------| |------+------+------+------+------+------|
 * |   $  |  F1  |  F2  |  F3  |  F4  |  F5  | |  F6  |   4  |   5  |   6  |      |      |
 * |------+------+------+------+------+------| |------+------+------+------+------+------|
 * |      |  F7  |  F8  |  F9  |  F10 |  F11 | |  F12 |   1  |   2  |   3  |      |      |
 * |------+------+------+------+------+------| |------+------+------+------+------+------|
 * |      |      |      |      |      |      | |      |      |   0  | Vol- | Vol+ | Play |
 * `-----------------------------------------' `-----------------------------------------'
 */
[_LOWER] = KEYMAP( \
  KC_TAB,   KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_DEL, \
  CTL_T(KC_DLR), KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_4,    KC_5,    KC_6,    _______, _______, \
  _______,       KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,  KC_1,    KC_2,    KC_3,    _______, _______, \
  _______,       _______, _______, _______, _______, _______, _______, _______, KC_0, KC_VOLD, KC_VOLU, KC_MPLY
),

/* Raise
 * ,-----------------------------------------. ,-----------------------------------------.
 * |   ~  |   !  |   @  |   #  |   $  |   %  | |   ^  |   &  |   *  |   (  |   )  | Del  |
 * |------+------+------+------+------+------| |------+------+------+------+------+------|
 * |      |      |      |      |      |      | |   _  |   ?  |   +  |   {  |   }  |  |   |
 * |------+------+------+------+------+------| |------+------+------+------+------+------|
 * |      |      |      |      |      |      | |   -  |   /  |   =  |   [  |   ]  |  \   |
 * |------+------+------+------+------+------| |------+------+------+------+------+------|
 * |      |      |      |      |      |      | |      |      | Home |PageDn|PageUp| End  |
 * `-----------------------------------------' `-----------------------------------------'
 */
[_RAISE] = KEYMAP( \
  ALL_T(KC_TILD), KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC, KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, KC_DEL, \
  _______,        _______, _______, _______, _______, _______, KC_UNDS, KC_QUES, KC_PLUS, KC_LCBR, KC_RCBR, KC_PIPE, \
  _______,        _______, _______, _______, _______, _______, KC_MINS, KC_SLSH, KC_EQL,  KC_LBRC, KC_RBRC, SFT_T(KC_BSLS), \
  _______,        _______, _______, _______, _______, _______, _______, _______, KC_HOME, KC_PGDN, KC_PGUP, KC_END
),

/* Adjust (Lower + Raise)
 * ,-----------------------------------------. ,-----------------------------------------.
 * |      | Reset|      |      |      |      | |      |      |      |      |      | Reset|
 * |------+------+------+------+------+------| |------+------+------+------+------+------|
 * |      |      |      |AU_ON |AU_OFF|      | |      |QWERTY|GAMING|      |      |      |
 * |------+------+------+------+------+------| |------+------+------+------+------+------|
 * |      |      |      |      |      |      | |      |      |      |      |      |      |
 * |------+------+------+------+------+------| |------+------+------+------+------+------|
 * |      |      |      |      |      |      | |      |      |      |      |      |      |
 * `-----------------------------------------' `-----------------------------------------'
 */
[_ADJUST] = KEYMAP( \
  _______, RESET,   _______, _______, _______, _______, _______, _______, _______, _______, _______, RESET, \
  _______, _______, _______, AU_ON,   AU_OFF,  _______, _______, QWERTY,  GAMING,  _______, _______, _______, \
  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, \
  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______
)
};


void persistent_default_layer_set(uint16_t default_layer) {
  eeconfig_update_default_layer(default_layer);
  default_layer_set(default_layer);
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
 switch (keycode) {
    case QWERTY:
      if (record->event.pressed) {
        #ifdef AUDIO_ENABLE
          PLAY_SONG(tone_qwerty);
        #endif
        persistent_default_layer_set(1UL<<_QWERTY);
      }
      return false;
      break;
    case GAMING:
      if (record->event.pressed) {
        #ifdef AUDIO_ENABLE
          PLAY_SONG(tone_colemak);
        #endif
        persistent_default_layer_set(1UL<<_GAMING);
		}
    case LOWER:
      if (record->event.pressed) {
        layer_on(_LOWER);
        update_tri_layer(_LOWER, _RAISE, _ADJUST);
      } else {
        layer_off(_LOWER);
        update_tri_layer(_LOWER, _RAISE, _ADJUST);
      }
      return false;
      break;
    case RAISE:
      if (record->event.pressed) {
        layer_on(_RAISE);
        update_tri_layer(_LOWER, _RAISE, _ADJUST);
      } else {
        layer_off(_RAISE);
        update_tri_layer(_LOWER, _RAISE, _ADJUST);
      }
      return false;
      break;
    case ADJUST:
      if (record->event.pressed) {
        layer_on(_ADJUST);
      } else {
        layer_off(_ADJUST);
      }
      return false;
      break;
  }
  return true;
}
