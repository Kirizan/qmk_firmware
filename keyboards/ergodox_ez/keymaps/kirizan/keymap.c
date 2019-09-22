#include QMK_KEYBOARD_H
#include "version.h"

#define L_BASE 0 // default layer
#define L_ALT 1 // alternate keys

enum custom_keycodes {
#ifdef ORYX_CONFIGURATOR
  EPRM = EZ_SAFE_RANGE,
#else
  EPRM = SAFE_RANGE,
#endif
  C_HOME,
  C_END,
  VRSN,
  RGB_SLD
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
/* Keymap 0: Basic layer
 *
 * ,--------------------------------------------------.           ,--------------------------------------------------.
 * | Esc    |   1  |   2  |   3  |   4  |   5  | OSL1 |           |      |   6  |   7  |   8  |   9  |   0  |  BkSp  |
 * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
 * | Tab    |   Q  |   W  |   E  |   R  |   T  |   -  |           | Home |   Y  |   U  |   I  |   O  |   P  |   \    |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * | Caps   |   A  |   S  |   D  |   F  |   G  |------|           |------|   H  |   J  |   K  |   L  |   ;  |    '   |
 * |--------+------+------+------+------+------|   =  |           | End  |------+------+------+------+------+--------|
 * | LShift |   Z  |   X  |   C  |   V  |   B  |      |           |      |   N  |   M  |   ,  |   .  |   /  | RShift |
 * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   |  Grv | LCtrl| LWin | LAlt |      |                                       |      | RAlt | RWin | RCtrl|      |
 *   `----------------------------------'                                       `----------------------------------'
 *                                        ,-------------.       ,-------------.
 *                                        | Left | Right|       | Up   | Down |
 *                                 ,------|------|------|       |------+--------+------.
 *                                 |      |      |      |       |      |        |      |
 *                                 | Space|      |------|       |------| Enter  | Space|
 *                                 |      |      | [    |       |  ]   |        |      |
 *                                 `--------------------'       `----------------------'
 */
[L_BASE] = LAYOUT_ergodox(
  // NOTE: KC_NO means blank key
  // left hand keypad
  KC_ESC,         KC_1,        KC_2,          KC_3,     KC_4,    KC_5,    OSL(L_ALT),
  KC_TAB,         KC_Q,        KC_W,          KC_E,     KC_R,    KC_T,    KC_MINUS,
  KC_CAPSLOCK,    KC_A,        KC_S,          KC_D,     KC_F,    KC_G,
  KC_LSFT,        KC_Z,        KC_X,          KC_C,     KC_V,    KC_B,    KC_EQUAL,
  KC_GRV,         KC_LCTRL,    KC_LGUI,       KC_LALT,  KC_NO,
  // left hand thumb cluster
          KC_LEFT, KC_RIGHT,
                   KC_NO,
  KC_SPC, KC_NO,   KC_LBRACKET,
  // right hand keypad
  KC_NO,       KC_6,    KC_7,    KC_8,    KC_9,       KC_0,           KC_BSPC,
  C_HOME,      KC_Y,    KC_U,    KC_I,    KC_O,       KC_P,           KC_BSLS,
               KC_H,    KC_J,    KC_K,    KC_L,       KC_SCOLON,      KC_QUOT,
  C_END,       KC_N,    KC_M,    KC_COMM, KC_DOT,     KC_SLSH,        KC_RSFT,
                        KC_NO,   KC_RALT, KC_RGUI,    KC_RCTRL,       KC_NO,
  // right hand thumb cluster
  KC_UP, KC_DOWN,
  KC_NO,
  KC_RBRACKET, KC_ENTER, KC_SPACE
),
/* Keymap 1: Symbol Layer
 *
 * ,----------------------------------------------------------.           ,------------------------------------------------.
 * |      Esc       |  F1  |  F2  |  F3  |  F4  |  F5  |      |           | TO_0 |      |NUMLOCK| NUM_/| NUM_*| NUM_- |     |
 * |----------------+------+------+------+------+------+------|           |------+------+-------+------+------+-------+-----|
 * |                |  F6  |  F7  |  F8  |  F9  |  F10 |      |           |      |      | NUM_7 | NUM_8| NUM_9| NUM_+ |     |
 * |----------------+------+------+------+------+------|      |           |      |------+-------+------+------+-------+-----|
 * |                |  F11 |  F12 |  F13 |  F14 |  F15 |------|           |------|      | NUM_4 | NUM_5| NUM_6| NUM_+ |     |
 * |----------------+------+------+------+------+------|      |           |      |------+-------+------+------+-------+-----|
 * |                |  F16 |  F17 |  F18 |  F19 |  F20 |      |           |      |      | NUM_1 | NUM_2| NUM_3|NUM_ENT|     |
 * `----------------+------+------+------+------+-------------'           `-------------+-------+------+------+-------+-----'
 *   | ALT_CTRL_DEL |  F21 |  F22 |  F23 |  F24 |                                       |       | NUM_0| NUM_.|NUM_ENT|     |
 *   `------------------------------------------'                                       `-----------------------------------'
 *                                        ,-------------.       ,-------------.
 *                                        |      |      |       |      |      |
 *                                 ,------|------|------|       |------+------+------.
 *                                 |      |      |      |       |      |      |      |
 *                                 |      |      |------|       |------|      |      |
 *                                 |      |      |      |       |      |      |      |
 *                                 `--------------------'       `--------------------'
 */
[L_ALT] = LAYOUT_ergodox(
  // KC_TRNS means lower layer key
  // left hand keypad
  KC_ESC,               KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_TRNS,
  KC_TRNS,              KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_TRNS,
  KC_TRNS,              KC_F11,  KC_F12,  KC_F13,  KC_F14,  KC_F15,
  KC_TRNS,              KC_F16,  KC_F17,  KC_F18,  KC_F19,  KC_F20,  KC_TRNS,
  LALT(LCTL(KC_DEL)),   KC_F21,  KC_F22,  KC_F23,  KC_F24,
  //left hand thumb cluster
           KC_TRNS, KC_TRNS,
                    KC_TRNS,
  KC_TRNS, KC_TRNS, KC_TRNS,
  // right hand keypad
  TO(L_BASE), KC_TRNS,  KC_NLCK,  KC_PSLS,  KC_PAST,   KC_PMNS,  KC_TRNS,
  KC_TRNS,    KC_TRNS,  KC_KP_7,  KC_KP_8,  KC_KP_9,   KC_PPLS,  KC_TRNS,
              KC_TRNS,  KC_KP_4,  KC_KP_5,  KC_KP_6,   KC_PPLS,  KC_TRNS,
  KC_TRNS,    KC_TRNS,  KC_KP_1,  KC_KP_2,  KC_KP_3,   KC_PENT,  KC_TRNS,
                        KC_TRNS,  KC_KP_0,  KC_PDOT,   KC_PENT,  KC_TRNS,
  // right hand thumb cluster
  KC_TRNS, KC_TRNS,
  KC_TRNS,
  KC_TRNS, KC_TRNS, KC_TRNS
),
/* Keymap *: Template for new layer
 *
 * ,--------------------------------------------------.           ,--------------------------------------------------.
 * |        |      |      |      |      |      |      |           |      |      |      |      |      |      |        |
 * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
 * |        |      |      |      |      |      |      |           |      |      |      |      |      |      |        |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |        |      |      |      |      |      |------|           |------|      |      |      |      |      |        |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |        |      |      |      |      |      |      |           |      |      |      |      |      |      |        |
 * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   |      |      |      |      |      |                                       |      |      |      |      |      |
 *   `----------------------------------'                                       `----------------------------------'
 *                                        ,-------------.       ,-------------.
 *                                        |      |      |       |      |      |
 *                                 ,------|------|------|       |------+------+------.
 *                                 |      |      |      |       |      |      |      |
 *                                 |      |      |------|       |------|      |      |
 *                                 |      |      |      |       |      |      |      |
 *                                 `--------------------'       `--------------------'
 */
/* Blank layout
// Note: must define [NAME] above as layer
[NAME] = LAYOUT_ergodox(
  // left hand keypad
  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,

  // left hand thumb cluster
           KC_TRNS, KC_TRNS,
                    KC_TRNS,
  KC_TRNS, KC_TRNS, KC_TRNS,

  // right hand keypad
  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
           KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
                    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,

  // right hand thumb cluster
  KC_TRNS, KC_TRNS,
  KC_TRNS,
  KC_TRNS, KC_TRNS, KC_TRNS
),
*/
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  static uint16_t custom_timer;

  switch (keycode) {
    case EPRM:
      if (record->event.pressed) {
        eeconfig_init();
        return false;
      }
    case VRSN:
      if (record->event.pressed) {
        SEND_STRING (QMK_KEYBOARD "/" QMK_KEYMAP " @ " QMK_VERSION);
        return false;
      }
    #ifdef RGBLIGHT_ENABLE
    case RGB_SLD:
      if (record->event.pressed) {
        rgblight_mode(1);
        return false;
      }
    #endif
    case C_HOME:
      if(record->event.pressed) {
        custom_timer = timer_read();
        register_code(KC_LSFT);
      } else {
        if (timer_elapsed(custom_timer) < TAPPING_TERM) {
          unregister_code(KC_LSFT);
        }
        SEND_STRING(SS_TAP(X_HOME));        
        unregister_code(KC_LSFT);
      }
      return false;
    case C_END:
      if(record->event.pressed) {
        custom_timer = timer_read();
        register_code(KC_LSFT);
      } else {
        if (timer_elapsed(custom_timer) < TAPPING_TERM) {
          unregister_code(KC_LSFT);
        }
        SEND_STRING(SS_TAP(X_END));
        unregister_code(KC_LSFT);
      }
      return false;
  }
  return true;
}

// Runs just one time when the keyboard initializes.
void matrix_init_user(void) {
#ifdef RGBLIGHT_COLOR_LAYER_0
  rgblight_setrgb(RGBLIGHT_COLOR_LAYER_0);
#endif
};

// Runs whenever there is a layer state change.
layer_state_t layer_state_set_user(layer_state_t state) {
  ergodox_board_led_off();
  ergodox_right_led_1_off();
  ergodox_right_led_2_off();
  ergodox_right_led_3_off();

  uint8_t layer = biton32(state);
  switch (layer) {
      case 0:
        #ifdef RGBLIGHT_COLOR_LAYER_0
          rgblight_setrgb(RGBLIGHT_COLOR_LAYER_0);
        #else
        #ifdef RGBLIGHT_ENABLE
          rgblight_init();
        #endif
        #endif
        break;
      case 1:
        ergodox_right_led_1_on();
        #ifdef RGBLIGHT_COLOR_LAYER_1
          rgblight_setrgb(RGBLIGHT_COLOR_LAYER_1);
        #endif
        break;
      case 2:
        ergodox_right_led_2_on();
        #ifdef RGBLIGHT_COLOR_LAYER_2
          rgblight_setrgb(RGBLIGHT_COLOR_LAYER_2);
        #endif
        break;
      case 3:
        ergodox_right_led_3_on();
        #ifdef RGBLIGHT_COLOR_LAYER_3
          rgblight_setrgb(RGBLIGHT_COLOR_LAYER_3);
        #endif
        break;
      case 4:
        ergodox_right_led_1_on();
        ergodox_right_led_2_on();
        #ifdef RGBLIGHT_COLOR_LAYER_4
          rgblight_setrgb(RGBLIGHT_COLOR_LAYER_4);
        #endif
        break;
      case 5:
        ergodox_right_led_1_on();
        ergodox_right_led_3_on();
        #ifdef RGBLIGHT_COLOR_LAYER_5
          rgblight_setrgb(RGBLIGHT_COLOR_LAYER_5);
        #endif
        break;
      case 6:
        ergodox_right_led_2_on();
        ergodox_right_led_3_on();
        #ifdef RGBLIGHT_COLOR_LAYER_6
          rgblight_setrgb(RGBLIGHT_COLOR_LAYER_6);
        #endif
        break;
      case 7:
        ergodox_right_led_1_on();
        ergodox_right_led_2_on();
        ergodox_right_led_3_on();
        #ifdef RGBLIGHT_COLOR_LAYER_7
          rgblight_setrgb(RGBLIGHT_COLOR_LAYER_7);
        #endif
        break;
      default:
        break;
    }

  return state;
};
