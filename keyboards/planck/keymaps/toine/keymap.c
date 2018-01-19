/* Copyright 2015-2017 Jack Humbert
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#include "planck.h"
#include "action_layer.h"

extern keymap_config_t keymap_config;

#define SPACEFN LT(_FN,KC_SPC)
#define ESCFN LT(_FN,KC_ESC)
#define SFTQUOT MT(MOD_RSFT,KC_QUOT)

#define LG1 LSFT(LCTL(KC_F1))
#define LG2 LSFT(LCTL(KC_F2))
#define LG3 LSFT(LCTL(KC_F3))
#define LG4 LSFT(LCTL(KC_F4))

enum planck_layers {
  _QWERTY,
  _GAMING,
  _ACCENTS,
  _LOWER,
  _RAISE,
  _FN,
  _ADJUST
};

enum planck_keycodes {
  QWERTY = SAFE_RANGE,
  GAMING,
  ACCENTS,
  LOWER,
  RAISE,
  BACKLIT
};

// Tap Dance Declarations
enum {
  SFT_CAP = 0,
  TAB_ESC // finalement pas utilis� pour l'instant
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

/* Qwerty
 * ,-----------------------------------------------------------------------------------.
 * | Tab  |   Q  |   W  |   E  |   R  |   T  |   Y  |   U  |   I  |   O  |   P  | Bksp |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * | Ctrl |   A  |   S  |   D  |   F  |   G  |   H  |   J  |   K  |   L  |   ;  |Enter |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * |SftCap|   Z  |   X  |   C  |   V  |   B  |   N  |   M  |   ,  |   .  |   /  |Sft/' |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |Esc/FN|Brite | GUI  | Alt  |Lower | Space/FN    |Raise |ACCENT|AltGr |TG(FN)|MO(FN)|
 * `-----------------------------------------------------------------------------------'
 */
[_QWERTY] = {
  {KC_TAB     , KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_BSPC},
  {KC_LCTL    , KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_ENT },
  {TD(SFT_CAP), KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, SFTQUOT},
  {ESCFN      , BACKLIT, KC_LGUI, KC_LALT, LOWER,   SPACEFN, SPACEFN,  RAISE,  ACCENTS, KC_RALT, TG(_FN), MO(_FN)}
},

/* Gaming
 * ,-----------------------------------------------------------------------------------.
 * | Tab  |   Q  |   W  |   E  |   R  |   T  |   Y  |   U  |   I  |   O  |   P  | Bksp |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * |Raise |   A  |   S  |   D  |   F  |   G  |   H  |   J  |   K  |   L  |   ;  |Enter |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * |Shift |   Z  |   X  |   C  |   V  |   B  |   N  |   M  |   ,  |   .  |   /  |Sft/' |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Ctrl | Esc  | GUI  | Alt  |Lower |    Space    |Raise |ACCENT|AltGr |TG(FN)|MO(FN)|
 * `-----------------------------------------------------------------------------------'
 */
[_GAMING] = {
  {KC_TAB , KC_Q,   KC_W,    KC_E,    KC_R,  KC_T,   KC_Y,   KC_U,  KC_I,    KC_O,    KC_P,    KC_BSPC},
  {RAISE,   KC_A,   KC_S,    KC_D,    KC_F,  KC_G,   KC_H,   KC_J,  KC_K,    KC_L,    KC_SCLN, KC_ENT },
  {KC_LSFT, KC_Z,   KC_X,    KC_C,    KC_V,  KC_B,   KC_N,   KC_M,  KC_COMM, KC_DOT,  KC_SLSH, SFTQUOT},
  {KC_LCTL, KC_ESC, KC_LGUI, KC_LALT, LOWER, KC_SPC, KC_SPC, RAISE, ACCENTS, KC_RALT, TG(_FN), MO(_FN)}
},

/* Accents, see http://marin.jb.free.fr/qwerty-fr/
 * ,-----------------------------------------------------------------------------------.
 * |      |   �  |   �  |   �  |   �  | EURO |      |   �  |   �  |   �  |  oe  |      |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * |      |   �  |   �  |   �  |      |      |      |   �  |   �  |   �  |      |      |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * |      |   �  |      |   �  |      |      |      |      |      |   �  |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |             |      |      |      |      |      |
 * `-----------------------------------------------------------------------------------'
 */
[_ACCENTS] = {
  {_______ , _______,  _______, _______, KC_4,   KC_5,     _______, KC_8,    KC_9,    KC_0,    _______, _______},
  {_______ , _______,  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______},
  {_______ , _______,  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______},
  {_______ , _______,  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______}
},

/* Lower
 * ,-----------------------------------------------------------------------------------.
 * |   ~  |   !  |   @  |   #  |   $  |   %  |   ^  |   &  |   *  |   (  |   )  | Del |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * |      |  F1  |  F2  |  F3  |  F4  |  F5  |  F6  |   _  |   +  |   {  |   }  |      |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * |      |  F7  |  F8  |  F9  |  F10 |  F11 |  F12 |ISO ~ |ISO | | Home | End  |  |   |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |             |      |      | Vol- | Vol+ | Mute |
 * `-----------------------------------------------------------------------------------'
 */
[_LOWER] = {
  {KC_TILD, KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC, KC_CIRC, KC_AMPR,    KC_ASTR,    KC_LPRN, KC_RPRN, KC_DEL},
  {_______, KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_UNDS,    KC_PLUS,    KC_LCBR, KC_RCBR, _______},
  {_______, KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,  S(KC_NUHS), S(KC_NUBS), KC_HOME, KC_END,  KC_PIPE},
  {_______, _______, _______, _______, _______, _______, _______, _______,    _______,    KC_VOLD, KC_VOLU, KC_MUTE}
},

/* Raise
 * ,-----------------------------------------------------------------------------------.
 * |   `  |   1  |   2  |   3  |   4  |   5  |   6  |   7  |   8  |   9  |   0  | Del  |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * |      |  F1  |  F2  |  F3  |  F4  |  F5  |  F6  |   -  |   =  |   [  |   ]  |      |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * |      |  F7  |  F8  |  F9  |  F10 |  F11 |  F12 |ISO # |ISO / |Pg Up |Pg Dn |  \   |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |             |      |      | Vol- | Vol+ | Mute |
 * `-----------------------------------------------------------------------------------'
 */
[_RAISE] = {
  {KC_GRV,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_DEL},
  {_______, KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_MINS, KC_EQL,  KC_LBRC, KC_RBRC, _______},
  {_______, KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,  KC_NUHS, KC_NUBS, KC_PGUP, KC_PGDN, KC_BSLS},
  {_______, _______, _______, _______, _______, _______, _______, _______, _______, KC_VOLD, KC_VOLU, KC_MUTE}
},

/* Functions
 * ,-----------------------------------------------------------------------------------.
 * |      | LG1  | LG2  | LG3  | LG4  |      |      |Pg Up |  Up  |Pg Dn | Ins  | Del  |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * |      |      |      |      |      |      | Home | Left | Down |Right |      |      |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * |      |      |      |      |      |      |Space | End  |      |      |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |             |      |      |      |      |      |
 * `-----------------------------------------------------------------------------------'
 */
[_FN] = {
  {_______, LG1    , LG2    ,   LG3    , LG4    ,_______,_______,KC_PGUP,KC_UP,  KC_PGDN,KC_INS ,KC_DEL},
  {_______, _______, _______,   _______, _______,_______,KC_HOME,KC_LEFT,KC_DOWN,KC_RGHT,_______,_______},
  {_______, _______, _______,   _______, _______,_______,KC_SPC ,KC_END ,_______,_______,_______,_______},
  {_______, _______, _______,   _______, _______,_______,_______,_______,_______,_______,_______,_______}
},

/* Adjust (Lower + Raise)
 * ,-----------------------------------------------------------------------------------.
 * |Pause | Reset|      |      |      |      |      |      |      |      |      |  Del |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * |      |      |      |Aud on|Audoff|AGnorm|AGswap|Qwerty|      |      |      |Gaming|
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * |      |Voice-|Voice+|Mus on|Musoff|MIDIon|MIDIof|      |      |      |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |             |      |      |      |      |      |
 * `-----------------------------------------------------------------------------------'
 */
[_ADJUST] = {
  {KC_PAUS, RESET,   DEBUG,   RGB_TOG, RGB_MOD, RGB_HUI, RGB_HUD, RGB_SAI, RGB_SAD,  RGB_VAI, RGB_VAD,  KC_DEL },
  {_______, _______, MU_MOD,  AU_ON,   AU_OFF,  AG_NORM, AG_SWAP, QWERTY,  _______,  _______,  _______, GAMING },
  {_______, MUV_DE,  MUV_IN,  MU_ON,   MU_OFF,  MI_ON,   MI_OFF,  TERM_ON, TERM_OFF, _______, _______,  _______},
  {_______, _______, _______, _______, _______, _______, _______, _______, _______,  _______, _______,  _______}
}


};

// Shift vs capslock function
void caps_tap (qk_tap_dance_state_t *state, void *user_data) {
    if (state->count == 1) {
        register_code (KC_LSFT);
    } else if (state->count == 2) {
        unregister_code (KC_LSFT);
        register_code (KC_CAPS);
    }
}
void caps_tap_end (qk_tap_dance_state_t *state, void *user_data) {
    if (state->count == 1) {
        unregister_code (KC_LSFT);
    } else {
        unregister_code (KC_CAPS);
    }
}

qk_tap_dance_action_t tap_dance_actions[] = {
  // Advanced tap dance feature allows for immediate response to shift
  [SFT_CAP] = ACTION_TAP_DANCE_FN_ADVANCED(caps_tap, NULL, caps_tap_end),
  [TAB_ESC] = ACTION_TAP_DANCE_DOUBLE(KC_TAB, KC_ESC)
};

#ifdef AUDIO_ENABLE
  float gaming_song[][2]     = SONG(ZELDA_PUZZLE);
  float gaming_gb_song[][2]  = SONG(ZELDA_TREASURE);
#endif

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case QWERTY:
      if (record->event.pressed) {
        print("mode just switched to qwerty and this is a huge string\n");
        set_single_persistent_default_layer(_QWERTY);
      }
      return false;
      break;
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
    case ACCENTS:
      if (record->event.pressed) {
	  layer_on(_ACCENTS);
	  register_code(KC_RALT);
      } else {
	  unregister_code(KC_RALT);
	  layer_off(_ACCENTS);
      }
      return false;
      break;
    case BACKLIT:
      if (record->event.pressed) {
        register_code(KC_RSFT);
        #ifdef BACKLIGHT_ENABLE
          backlight_step();
        #endif
        PORTE &= ~(1<<6);
      } else {
        unregister_code(KC_RSFT);
        PORTE |= (1<<6);
      }
      return false;
      break;
    case GAMING:
      if (record->event.pressed) {
        if (layer_state_is(_GAMING)) {
          #ifdef AUDIO_ENABLE
          stop_all_notes();
          PLAY_SONG(gaming_gb_song);
          #endif
          layer_off(_GAMING);
        } else {
          #ifdef AUDIO_ENABLE
	  stop_all_notes();
	  PLAY_SONG(gaming_song);
          #endif
	  layer_on(_GAMING);
        }
      }
      return false;
      break;
  }
  return true;
}
