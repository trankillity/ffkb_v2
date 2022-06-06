#include QMK_KEYBOARD_H

// Defines names for use in layer keycodes and the keymap
enum layer_names {
    _BASE,
    _NUMB,
    _NAVI,
    _SYST,
    _COMB
};

enum custom_keycodes {
    C_CAPW = SAFE_RANGE,
    C_SNKC,
};

#include "trankillity.h"
#include "g/keymap_combo.h"
#include "features/casemodes.h"

#define ___ KC_TRNS
#define XXX KC_NO

#define C_SELA      C(KC_A)
#define C_UNDO      C(KC_Z)
#define C_CUT       C(KC_X)
#define C_COPY      C(KC_C)
#define C_PAST      C(KC_V)
#define C_REDO      C(KC_Y)

#define C_CLFT      C(KC_LEFT)
#define C_CRGT      C(KC_RIGHT)
#define C_TABI      KC_TAB
#define C_TABD      S(KC_TAB)
#define C_WINI      A(KC_TAB)
#define C_WIND      A(S(KC_TAB))
#define C_DSKT      G(KC_TAB)
#define C_PEEK      G(KC_COMMA)

#define OSM_SFT     OSM(MOD_LSFT)
#define OSM_CTL     OSM(MOD_LCTL)
#define OSM_ALT     OSM(MOD_LALT)
#define OSM_GUI     OSM(MOD_LGUI)


const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
/* Base - Colemak
 *
 * ,-----------------------------------------.            ,-----------------------------------------.
 * |      |   Q  |   W  |   F  |   P  |   B  |            |   J  |   U  |   Y  |   Y  |   '  |      |
 * |------+------+------+------+------+------|            |------+------+------+------+------+------|
 * |      |   A  |   R  |   S  |   T  |   G  |            |   M  |   N  |   E  |   I  |   O  |      |
 * |------+------+------+------+------+------|            |------+------+------+------+------+------|
 * |      |   Z  |   X  |   C  |   D  |   V  |            |   K  |   H  |   ,  |   .  |   /  |      |
 * `-----------------------------------------'            `-----------------------------------------'
 *                          ,--------------------.    ,--------------------.
 *                          |      |      |      |    |      |      |      |
 *                          `--------------------'    `--------------------.
 */

[_BASE] = LAYOUT_ffkb(
    C_CLFT,        KC_Q,       KC_W,       KC_F,       KC_P,       KC_B,           KC_J,       KC_L,       KC_U,       KC_Y,       KC_QUOT,    C_CRGT,
    C_TABI,        KC_A,       KC_R,       KC_S,       KC_T,       KC_G,           KC_M,       KC_N,       KC_E,       KC_I,       KC_O,       C_TABD,
    OSM_CTL,       KC_Z,       KC_X,       KC_C,       KC_D,       KC_V,           KC_K,       KC_H,       KC_COMM,    KC_DOT,     KC_SLSH,    OSM_CTL,
                       XXX,      OSL(_NUMB),        OSM_SFT,       KC_BSPC,        KC_ENTER,   KC_SPC,       OSL(_NAVI),       XXX,
                                                                        XXX
),

[_NUMB] = LAYOUT_ffkb(
  KC_F6,    KC_F5,      KC_F4,      KC_F3,      KC_F2,      KC_F1,              KC_PEQL,    KC_7,       KC_8,       KC_9,       KC_PDOT,        KC_EXLM,
  C_TABI,   OSM_GUI,    OSM_ALT,    OSM_CTL,    OSM_SFT,    _______,            KC_PPLS,    KC_4,       KC_5,       KC_6,       KC_PAST,        KC_GRV,
  KC_F12,   KC_F11,     KC_F10,     KC_F9,      KC_F8,      KC_F7,              KC_MINS,    KC_1,       KC_2,       KC_3,       KC_PSLS,        KC_UNDS,
                    _______, _______, _______, _______,      KC_0, _______, _______, _______,
                                                      _______
),

[_NAVI] = LAYOUT_ffkb(
  C_SNKC, KC_INS, KC_HOME, KC_UP,   KC_END,  KC_PGUP,      KC_ESC, C_WIND, C_WINI, C_DSKT, C_PEEK, KC_BSLS,
  C_TABI, C_SELA, KC_LEFT, KC_DOWN, KC_RGHT, KC_PGDN,      KC_VOLU, OSM_SFT, OSM_CTL, OSM_ALT, OSM_GUI, C_TABD,
  C_CAPW, C_UNDO, C_CUT,   C_COPY,  C_PAST,  C_REDO,       KC_VOLD, KC_MPRV, KC_MPLY, KC_MNXT, KC_MSTP, KC_MUTE,
                    _______, _______, _______, _______,      _______, _______, _______, _______,
                                                      _______
),

[_SYST] = LAYOUT_ffkb(
  _______, RGB_SPI, RGB_HUI, RGB_SAI, RGB_VAI, RGB_MOD,      RGB_RMOD, RGB_VAD, RGB_SAD, RGB_HUD, RGB_SPD, _______,
  _______, _______, _______, _______, _______, RGB_TOG,      RGB_TOG, _______, _______, _______, _______, _______,
  QK_BOOT, _______, _______, KC_PAUS, KC_PSCR, _______,      _______, KC_PSCR, KC_PAUS, _______, _______, QK_BOOT,
                    _______, _______, _______, _______,      _______, _______, _______, _______,
                                                      _______
),

// Combo layer. Never to be activated, just used or combo indexing purposes.
[_COMB] = LAYOUT_ffkb(
    KC_1,       KC_Q,       KC_W,       KC_F,       KC_P,       KC_B,           KC_J,       KC_L,       KC_U,       KC_Y,       KC_QUOT,    KC_4,
    KC_2,       KC_A,       KC_R,       KC_S,       KC_T,       KC_G,           KC_M,       KC_N,       KC_E,       KC_I,       KC_O,       KC_5,
    KC_3,       KC_Z,       KC_X,       KC_C,       KC_D,       KC_V,           KC_K,       KC_H,       KC_COMM,    KC_DOT,     KC_SLSH,    KC_6,
                            _______,    _______,    _______,    _______,        _______,    _______,    _______,    _______,
                                                                        _______
),

// [BLANK] = LAYOUT_ffkb(
//   _______, _______, _______, _______, _______, _______,      _______, _______, _______, _______, _______, _______,
//   _______, _______, _______, _______, _______, _______,      _______, _______, _______, _______, _______, _______,
//   _______, _______, _______, _______, _______, _______,      _______, _______, _______, _______, _______, _______,
//                     _______, _______, _______, _______,      _______, _______, _______, _______,
//                                                       _______
// ),


};

layer_state_t layer_state_set_user(layer_state_t state) {
  return update_tri_layer_state(state, _NUMB, _NAVI, _SYST);
};

const key_override_t comma_override = ko_make_basic(MOD_MASK_SHIFT, KC_COMMA, KC_SCLN);
const key_override_t fstop_override = ko_make_basic(MOD_MASK_SHIFT, KC_DOT, KC_COLON);
//const key_override_t bspce_override = ko_make_basic(MOD_MASK_SHIFT, KC_BSPC, KC_DEL);

// This globally defines all key overrides to be used
const key_override_t **key_overrides = (const key_override_t *[]){
    &comma_override,
    &fstop_override,
//    &bspce_override,
    NULL // Null terminate the array of overrides!
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    // Process case modes
    if (!process_case_modes(keycode, record)) {
        return false;
    }

    // Regular user keycode case statement
    switch (keycode) {
        case C_CAPW:
            if (record->event.pressed) {
                enable_caps_word();
            }
            return false;
        case C_SNKC:
            if (record->event.pressed) {
                enable_xcase_with(KC_UNDS);
            }
            return false;
        default:
            return true;
    }
}
