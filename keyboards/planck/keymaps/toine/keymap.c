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

#include QMK_KEYBOARD_H

#define SPACEFN LT(_FN,KC_SPC)
#define ESCFN LT(_FN,KC_ESC)
#define CTRLSC LCTL_T(KC_ESC)
#define MOSCLN LT(_MOUSE,KC_SCLN)
#define ACCENTS MO(_ACCENTS)
#define SFTQUOT MT(MOD_RSFT,KC_QUOT)
#define SFTENT MT(MOD_RSFT,KC_ENT)
#define NUMPAD TT(_NUMPAD)
#define MOUSE MO(_MOUSE)

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
  _NUMPAD,
  _MOUSE,
  _ADJUST
};

enum planck_keycodes {
  QWERTY = SAFE_RANGE,
  GAMING,
  TGNKRO,
  CAPSLCK,
  BACKLIT
};

#define LOWER MO(_LOWER)
#define RAISE MO(_RAISE)

// Tap Dance Declarations
enum {
  FN_RCTL = 0
//  SFT_CAP, // on ne l'utilise plus, le double tap shift étant préféré dans intellij
//  TAB_ESC // finalement pas utilisé pour l'instant
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

/* Qwerty
 * ,-----------------------------------------------------------------------------------.
 * | Tab  |   Q  |   W  |   E  |   R  |   T  |   Y  |   U  |   I  |   O  |   P  | Bksp |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * |CtrlSc|   A  |   S  |   D  |   F  |   G  |   H  |   J  |   K  |   L  |Mous/;|  '   |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * |Shift |   Z  |   X  |   C  |   V  |   B  |   N  |   M  |   ,  |   .  |   /  |SftEnt|
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |Esc/FN|NUMPAD| GUI  | Alt  |Lower | Space/FN    |Raise |ACCENT|AltGr |TG(FN)|FNRCTL|
 * `-----------------------------------------------------------------------------------'
 */
[_QWERTY] = LAYOUT_planck_grid(
  KC_TAB,  KC_Q,   KC_W,    KC_E,    KC_R,  KC_T,    KC_Y,    KC_U,  KC_I,    KC_O,    KC_P,    KC_BSPC,
  CTRLSC,  KC_A,   KC_S,    KC_D,    KC_F,  KC_G,    KC_H,    KC_J,  KC_K,    KC_L,    MOSCLN,  KC_QUOT,
  KC_LSFT, KC_Z,   KC_X,    KC_C,    KC_V,  KC_B,    KC_N,    KC_M,  KC_COMM, KC_DOT,  KC_SLSH, SFTENT,
  ESCFN,   NUMPAD, KC_LGUI, KC_LALT, LOWER, SPACEFN, SPACEFN, RAISE, ACCENTS, KC_RALT, TG(_FN), TD(FN_RCTL)
),

/* Gaming
 * ,-----------------------------------------------------------------------------------.
 * | Tab  |   Q  |   W  |   E  |   R  |   T  |   Y  |   U  |   I  |   O  |   P  | Bksp |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * |Raise |   A  |   S  |   D  |   F  |   G  |   H  |   J  |   K  |   L  |   ;  |  '   |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * |Shift |   Z  |   X  |   C  |   V  |   B  |   N  |   M  |   ,  |   .  |   /  |SftEnt|
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Ctrl | Esc  | GUI  | Alt  |Lower |    Space    |Raise |ACCENT|AltGr |TG(FN)|MO(FN)|
 * `-----------------------------------------------------------------------------------'
 */
[_GAMING] = LAYOUT_planck_grid(
  KC_TAB,  KC_Q,   KC_W,    KC_E,    KC_R,  KC_T,   KC_Y,   KC_U,  KC_I,    KC_O,    KC_P,    KC_BSPC,
  RAISE,   KC_A,   KC_S,    KC_D,    KC_F,  KC_G,   KC_H,   KC_J,  KC_K,    KC_L,    KC_SCLN, KC_QUOT,
  KC_LSFT, KC_Z,   KC_X,    KC_C,    KC_V,  KC_B,   KC_N,   KC_M,  KC_COMM, KC_DOT,  KC_SLSH, SFTENT,
  KC_LCTL, KC_ESC, KC_LGUI, KC_LALT, LOWER, KC_SPC, KC_SPC, RAISE, ACCENTS, KC_RALT, TG(_FN), MO(_FN)
),

/* Accents, see http://marin.jb.free.fr/qwerty-fr/
 * ,-----------------------------------------------------------------------------------.
 * |      |   â  |   é  |   è  |   ê  |   €  |   û  |   ù  |   î  |   ô  |   œ  |      |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * |      |   à  |   æ  |   ë  |      |   «  |   »  |   ü  |   ï  |   ö  |      |      |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * |      |   ä  |      |   ç  |      |      |      |      |      |   °  |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |             |      |      |      |      |      |
 * `-----------------------------------------------------------------------------------'
 */
[_ACCENTS] = LAYOUT_planck_grid(
  _______, RALT(KC_Q), RALT(KC_W), RALT(KC_E), RALT(KC_4), RALT(KC_5),    RALT(KC_8),    RALT(KC_U), RALT(KC_9), RALT(KC_0),   RALT(KC_P), _______,
  _______, RALT(KC_A), RALT(KC_S), RALT(KC_D), _______,    RALT(KC_LBRC), RALT(KC_RBRC), RALT(KC_J), RALT(KC_K), RALT(KC_L),   _______,    _______,
  _______, RALT(KC_Z), _______,    RALT(KC_C), _______,    _______,       _______,       _______,    _______,    RALT(KC_DOT), _______,    _______,
  _______, _______,    _______,    _______,    _______,    _______,       _______,       _______,    _______,    _______,      _______,    _______
),

/* Lower
 * ,-----------------------------------------------------------------------------------.
 * |   ~  |   !  |   @  |   #  |   $  |   %  |   ^  |   &  |   *  |   (  |   )  | Del |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * |      |  F1  |  F2  |  F3  |  F4  |  F5  |  F6  |   _  |   +  |   {  |   }  |  |   |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * |      |  F7  |  F8  |  F9  |  F10 |  F11 |  F12 |ISO ~ |ISO | | Home | End  |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |             |      |      | Vol- | Vol+ | Mute |
 * `-----------------------------------------------------------------------------------'
 */
[_LOWER] = LAYOUT_planck_grid(
  KC_TILD, KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC, KC_CIRC, KC_AMPR,    KC_ASTR,    KC_LPRN, KC_RPRN, KC_DEL,
  _______, KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_UNDS,    KC_PLUS,    KC_LCBR, KC_RCBR, KC_PIPE,
  _______, KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,  S(KC_NUHS), S(KC_NUBS), KC_HOME, KC_END,  _______,
  _______, _______, _______, _______, _______, _______, _______, _______,    _______,    KC_VOLD, KC_VOLU, KC_MUTE
),

/* Raise
 * ,-----------------------------------------------------------------------------------.
 * |   `  |   1  |   2  |   3  |   4  |   5  |   6  |   7  |   8  |   9  |   0  | Del  |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * |      |  F1  |  F2  |  F3  |  F4  |  F5  |  F6  |   -  |   =  |   [  |   ]  |  \   |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * |      |  F7  |  F8  |  F9  |  F10 |  F11 |  F12 |ISO # |ISO / |Pg Up |Pg Dn |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |             |      |      | Vol- | Vol+ | Mute |
 * `-----------------------------------------------------------------------------------'
 */
[_RAISE] = LAYOUT_planck_grid(
  KC_GRV,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_DEL,
  _______, KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_MINS, KC_EQL,  KC_LBRC, KC_RBRC, KC_BSLS,
  _______, KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,  KC_NUHS, KC_NUBS, KC_PGUP, KC_PGDN, _______,
  _______, _______, _______, _______, _______, _______, _______, _______, _______, KC_VOLD, KC_VOLU, KC_MUTE
),

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
[_FN] = LAYOUT_planck_grid(
  _______, LG1,     LG2,     LG3,     LG4,     _______, _______, KC_PGUP, KC_UP,   KC_PGDN, KC_INS,  KC_DEL,
  _______, _______, _______, _______, _______, _______, KC_HOME, KC_LEFT, KC_DOWN, KC_RGHT, _______, _______,
  _______, _______, _______, _______, _______, _______, KC_SPC,  KC_END,  _______, _______, _______, _______,
  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______
),

/* Numpad
 * ,-----------------------------------------------------------------------------------.
 * |      |      |      |      |      |      |      |  7   |  8   |  9   |  -   |      |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |  4   |  5   |  6   |  +   |      |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |  1   |  2   |  3   |  /   |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      | Vol- | Vol+ | Mute |             |  0   |  .   |  =   |  *   |      |
 * `-----------------------------------------------------------------------------------'
 */
[_NUMPAD] = LAYOUT_planck_grid(
  _______, _______, _______, _______, _______, _______, _______, KC_P7, KC_P8,   KC_P9,   KC_PMNS, _______,
  _______, _______, _______, _______, _______, _______, _______, KC_P4, KC_P5,   KC_P6,   KC_PPLS, _______,
  _______, _______, _______, _______, _______, _______, _______, KC_P1, KC_P2,   KC_P3,   KC_PSLS, _______,
  _______, _______, KC_VOLD, KC_VOLU, KC_MUTE, _______, _______, KC_P0, KC_PDOT, KC_PENT, KC_PAST, _______
),

/* Mouse
 * ,-----------------------------------------------------------------------------------.
 * |      |      |Wh up |Ms up |Wh dn |      |      |      |      |      |      |      |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * |      |      |Ms lft|Ms dn |Ms rgt|      |      | btn1 | btn3 | btn2 |      |      |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * |      |      |Wh lft|      |Wh rgt|      |      |      |      |      |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |             |      |      |      |      |      |
 * `-----------------------------------------------------------------------------------'
 */
[_MOUSE] = LAYOUT_planck_grid(
  _______, _______, KC_WH_U,  KC_MS_U, KC_WH_D, _______, _______, _______, _______, _______, _______, _______,
  _______, _______, KC_MS_L,  KC_MS_D, KC_MS_R, _______, _______, KC_BTN1, KC_BTN3, KC_BTN2, _______, _______,
  _______, _______, KC_WH_L,  _______, KC_WH_R, _______, _______, _______, _______, _______, _______, _______,
  _______, _______, _______,  _______, _______, _______, _______, _______, _______, _______, _______, _______
),

/* Adjust (Lower + Raise)
 * ,-----------------------------------------------------------------------------------.
 * |Pause |Reset | Debug|RgbTog|RgbMod|RgbHui|RgbHud|RgbSai|RgbSad|RgbVai|RgbVad|  Del |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * |PrtScr|TGNKRO|MusMod|Aud on|Audoff|AGnorm|AGswap|Qwerty|      |      |      |Gaming|
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * | Caps |Voice-|Voice+|Mus on|Musoff|MIDIon|MIDIof|TermOn|TermOf|      |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |             |      |      |      |      |      |
 * `-----------------------------------------------------------------------------------'
 */
[_ADJUST] = LAYOUT_planck_grid(
  KC_PAUS, RESET,   DEBUG,   RGB_TOG, RGB_MOD, RGB_HUI, RGB_HUD, RGB_SAI, RGB_SAD,  RGB_VAI, RGB_VAD,  KC_DEL ,
  KC_PSCR, TGNKRO,  MU_MOD,  AU_ON,   AU_OFF,  AG_NORM, AG_SWAP, QWERTY,  _______,  _______,  _______, GAMING ,
  CAPSLCK, MUV_DE,  MUV_IN,  MU_ON,   MU_OFF,  MI_ON,   MI_OFF,  TERM_ON, TERM_OFF, _______, _______,  _______,
  _______, _______, _______, _______, _______, _______, _______, _______, _______,  _______, _______,  _______
)


};


// Shift vs capslock function
/* void caps_tap (qk_tap_dance_state_t *state, void *user_data) {
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
 */
// FN layer vs KC_RCTRL
void rctl_tap (qk_tap_dance_state_t *state, void *user_data) {
    if (state->count == 1) {
        layer_on (_FN);
    } else if (state->count == 2) {
        layer_off (_FN);
        register_code (KC_RCTL);
    }
}
void rctl_tap_end (qk_tap_dance_state_t *state, void *user_data) {
    if (state->count == 1) {
        layer_off (_FN);
    } else {
        unregister_code (KC_RCTL);
    }
}

qk_tap_dance_action_t tap_dance_actions[] = {
  // Advanced tap dance feature allows for immediate response to shift
//  [SFT_CAP] = ACTION_TAP_DANCE_FN_ADVANCED(caps_tap, NULL, caps_tap_end),
  [FN_RCTL] = ACTION_TAP_DANCE_FN_ADVANCED(rctl_tap, NULL, rctl_tap_end)
//  [TAB_ESC] = ACTION_TAP_DANCE_DOUBLE(KC_TAB, KC_ESC)
};

#ifdef AUDIO_ENABLE
  float gaming_song[][2]     = SONG(OVERWATCH_THEME);
  float gaming_gb_song[][2]  = SONG(ZELDA_TREASURE);
  float capslock_song[][2]     = SONG(CAPS_LOCK_ON_SOUND);
  float capslock_gb_song[][2]  = SONG(CAPS_LOCK_OFF_SOUND);
  float num_lock_song[][2]  = SONG(NUM_LOCK_ON_SOUND);
#endif

uint32_t layer_state_set_user(uint32_t state) {
  return update_tri_layer_state(state, _LOWER, _RAISE, _ADJUST);
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case QWERTY:
      if (record->event.pressed) {
        print("mode just switched to qwerty and this is a huge string\n");
        set_single_persistent_default_layer(_QWERTY);
      }
      return false;
      break;
    case TGNKRO:
      if (record->event.pressed) {
        #ifdef AUDIO_ENABLE
        stop_all_notes();
        if (keymap_config.nkro) {
          PLAY_SONG(capslock_gb_song);
        } else {
          PLAY_SONG(capslock_song);
        }
        #endif
        if (!eeconfig_is_enabled()) {
            eeconfig_init();
        }
        keymap_config.raw = eeconfig_read_keymap();
        keymap_config.nkro = !keymap_config.nkro;
        eeconfig_update_keymap(keymap_config.raw);
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
    case CAPSLCK:
      if (record->event.pressed) {
        #ifdef AUDIO_ENABLE
        stop_all_notes();
	      if (!(host_keyboard_leds() & (1<<USB_LED_CAPS_LOCK))) {
	        PLAY_SONG(capslock_song);
        } else {
          PLAY_SONG(capslock_gb_song);
        }
        #endif
	      register_code(KC_CAPSLOCK);
	      unregister_code(KC_CAPSLOCK);
      }
      return false;
      break;
    case NUMPAD:
      if (record->event.pressed) {
	      // enforce numlock when switching to NUMPAD layer
	      if (!(host_keyboard_leds() & (1<<USB_LED_NUM_LOCK))) {
          #ifdef AUDIO_ENABLE
            stop_all_notes();
	          PLAY_SONG(num_lock_song);
          #endif
	        register_code(KC_NUMLOCK);
	        unregister_code(KC_NUMLOCK);
	      }
      }
      return true;
      break;
  }
  return true;
}
