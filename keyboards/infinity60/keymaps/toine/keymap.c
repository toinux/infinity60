#include "infinity60.h"


#define _DF 0
#define _GM 1
#define _GA 2
#define _FN 3
#define _SP 4

#define ______ KC_TRNS
#define _no___ KC_NO


const uint16_t keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    /* Default Layer
     * ,-----------------------------------------------------------.
     * |Esc|  1|  2|  3|  4|  5|  6|  7|  8|  9|  0|  -|  =|  \|  `|
     * |-----------------------------------------------------------|
     * |Tab  |  Q|  W|  E|  R|  T|  Y|  U|  I|  O|  P|  [|  ]|Backs|
     * |-----------------------------------------------------------|
     * |Contro|  A|  S|  D|  F|  G|  H|  J|  K|  L|  ;|  '|Enter   |
     * |-----------------------------------------------------------|
     * |Shift   |  Z|  X|  C|  V|  B|  N|  M|  ,|  .|  /|Shift |_FN|
     * |-----------------------------------------------------------'
     * |_FN  |Gui|Alt  |         Space_FN      |Alt  |Gui|_SP|tg_FN|
     * `-----------------------------------------------------------'
     */
    [_DF] = KEYMAP(
      KC_ESC, KC_1,   KC_2,   KC_3,   KC_4,   KC_5,   KC_6,   KC_7,   KC_8,   KC_9,   KC_0,   KC_MINS,KC_EQL, KC_BSLS, KC_GRV, \
      KC_TAB, KC_Q,   KC_W,   KC_E,   KC_R,   KC_T,   KC_Y,   KC_U,   KC_I,   KC_O,   KC_P,   KC_LBRC,KC_RBRC,KC_BSPC, \
      KC_LCTL,KC_A,   KC_S,   KC_D,   KC_F,   KC_G,   KC_H,   KC_J,   KC_K,   KC_L,   KC_SCLN,KC_QUOT,KC_ENT,  \
      KC_LSFT,KC_Z,   KC_X,   KC_C,   KC_V,   KC_B,   KC_N,   KC_M,   KC_COMM,KC_DOT, KC_SLSH,KC_RSFT,MO(_FN), \
      MO(_FN),  KC_LGUI,KC_LALT,    LT(_FN,KC_SPC),                KC_RALT,KC_RGUI,MO(_SP), TG(_FN)),

    /* Gaming Layer
     * ,-----------------------------------------------------------.
     * |Esc|  1|  2|  3|  4|  5|  6|  7|  8|  9|  0|  -|  =|  \|  `|
     * |-----------------------------------------------------------|
     * |Tab  |  Q|  W|  E|  R|  T|  Y|  U|  I|  O|  P|  [|  ]|Backs|
     * |-----------------------------------------------------------|
     * |Caps  |  A|  S|  D|  F|  G|  H|  J|  K|  L|  ;|  '|Enter   |
     * |-----------------------------------------------------------|
     * |Shift   |  Z|  X|  C|  V|  B|  N|  M|  ,|  .|  /| Up   |_FN|
     * |-----------------------------------------------------------'
     * |Ctrl |Gui|Alt  |         Space         |Alt  |Gui|_SP|tg_FN|
     * `-----------------------------------------------------------'
     */
    [_GM] = KEYMAP(
      ______, ______,   ______,   ______,   ______,   ______,   ______,   ______,   ______,   ______,   ______,   ______,______, ______, ______, \
      ______, ______,   ______,   ______,   ______,   ______,   ______,   ______,   ______,   ______,   ______,   ______,______,______, \
      KC_CAPS,______,   ______,   ______,   ______,   ______,   ______,   ______,   ______,   ______,   ______,______,______,  \
      ______, ______,   ______,   ______,   ______,   ______,   ______,   ______,   ______,______, ______,______  ,______, \
      KC_LCTL,______,   ______,         KC_SPC ,                ______,______,______, ______),

    /* Gaming Layer with arrows
     * ,-----------------------------------------------------------.
     * |Esc|  1|  2|  3|  4|  5|  6|  7|  8|  9|  0|  -|  =|  \|  `|
     * |-----------------------------------------------------------|
     * |Tab  |  Q|  W|  E|  R|  T|  Y|  U|  I|  O|  P|  [|  ]|Backs|
     * |-----------------------------------------------------------|
     * |Caps  |  A|  S|  D|  F|  G|  H|  J|  K|  L|  ;|  '|Enter   |
     * |-----------------------------------------------------------|
     * |Shift   |  Z|  X|  C|  V|  B|  N|  M|  ,|  .|  /| Up   |_FN|
     * |-----------------------------------------------------------'
     * |Ctrl |Gui|Alt  |         Space         |Alt  |Lef|Dwn|Rgt  |
     * `-----------------------------------------------------------'
     */
    [_GA] = KEYMAP(
      ______, ______,   ______,   ______,   ______,   ______,   ______,   ______,   ______,   ______,   ______,   ______,______, ______, ______, \
      ______, ______,   ______,   ______,   ______,   ______,   ______,   ______,   ______,   ______,   ______,   ______,______,______, \
      KC_CAPS,______,   ______,   ______,   ______,   ______,   ______,   ______,   ______,   ______,   ______,______,______,  \
      ______, ______,   ______,   ______,   ______,   ______,   ______,   ______,   ______,______, ______,KC_UP  ,______, \
      KC_LCTL, ______,   ______,                       KC_SPC ,                            ______,KC_LEFT,KC_DOWN, KC_RIGHT),

    /* Function layer
     * ,-----------------------------------------------------------.
     * |   | F1| F2| F3| F4| F5| F6| F7| F8| F9|F10|F11|F12|Ins|Del|
     * |-----------------------------------------------------------|
     * |Caps |   |   |   |   |   |   |PgU|Up |PgD|Psc|Slk|Pus|     |
     * |-----------------------------------------------------------|
     * |Ctrl  |VoD|VoU|Mut|   |   |Hom|Lef|Dow|Rig|   |   |Enter   |
     * |-----------------------------------------------------------|
     * |        |B- |B+ |B0 |   |Spc|End|caL|caR|   |_SP|      |   |
     * `-----------------------------------------------------------'
     * |     |   |     |                       |     |   |   |     |
     * `-----------------------------------------------------------'
     */
    [_FN] = KEYMAP(
      ______, KC_F1,  KC_F2,  KC_F3,  KC_F4,  KC_F5,  KC_F6,  KC_F7,  KC_F8,  KC_F9,  KC_F10, KC_F11, KC_F12, KC_INS, KC_DEL, \
      KC_CAPS,_no___,_no___  ,_no___,_no___,_no___,_no___,KC_PGUP, KC_UP,KC_PGDN, KC_PSCR,KC_SLCK,KC_PAUS, ______, \
      KC_LCTL,KC_VOLD,KC_VOLU,KC_MUTE,_no___,_no___,KC_HOME,KC_LEFT,KC_DOWN,KC_RGHT,_no___,_no___,______, \
      ______,_no___ ,_no___ ,_no___,_no___,KC_SPC,KC_END ,LCTL(LALT(KC_LEFT)),LCTL(LALT(KC_RIGHT)),_no___, MO(_SP),______,______, \
      ______ ,______,______,          ______,               ______,______,______,______),

    /* special keys
     * ,-----------------------------------------------------------.
     * |Rst|_DF|_GM|_GA|   |   |   |   |   |   |   |   |   |   |   |
     * |-----------------------------------------------------------|
     * |     |   |   |   |   |   |   |   |   |   |   |   |   |     |
     * |-----------------------------------------------------------|
     * |      |   |   |   |   |   |   |   |   |   |   |   |        |
     * |-----------------------------------------------------------|
     * |        |   |   |   |   |   |   |   |   |   |   |      |   |
     * `-----------------------------------------------------------'
     * |     |   |     |                       |     |   |   |     |
     * `-----------------------------------------------------------'
     */
    [_SP] = KEYMAP(
      RESET,TO(_DF),TO(_GM),TO(_GA),_no___,_no___,_no___,_no___,_no___,_no___,_no___,_no___,_no___,_no___,_no___,   \
      _no___,_no___,_no___  ,_no___,_no___,_no___,_no___,_no___, _no___,_no___, _no___,_no___,_no___, _no___,      \
      _no___,_no___,_no___,_no___,_no___,_no___,_no___,_no___,_no___,_no___,_no___,_no___,_no___,            \
      _no___,_no___ ,_no___ ,_no___,_no___,_no___,_no___ ,_no___,_no___, _no___,_no___,_no___,_no___,            \
      _no___,_no___,_no___,          _no___,               _no___,_no___,______,_no___),
};

const uint16_t fn_actions[] = {

};

// Runs just one time when the keyboard initializes.
void matrix_init_user(void) {

};

// Runs constantly in the background, in a loop.
void matrix_scan_user(void) {

};