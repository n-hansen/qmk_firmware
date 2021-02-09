#include QMK_KEYBOARD_H

// Each layer gets a name for readability, which is then used in the keymap matrix below.
// The underscores don't mean anything - you can have a layer called STUFF or any other name.
// Layer names don't all need to be of the same length, obviously, and you can also skip them
// entirely and just use numbers.
#define _QWERTY 0
#define _SYMB 1
#define _QUD_KP 2
#define _QUD_QWERTY 3

enum custom_keycodes {
  QWERTY = SAFE_RANGE,
  SYMB,
  QUD_KP,
  QUD_QWERY,
};

// Shortcut to make keymap more readable
#define QWERTY_L TO(_QWERTY)
#define SYM_L   TO(_SYMB)
#define SYM_ALT LM(_SYMB, MOD_LALT)
#define QUD_KP_L TO(_QUD_KP)
#define QUD_Q_L TO(_QUD_QWERTY)

#define KC_ALAS LALT_T(KC_PAST)
#define KC_CTPL LCTL_T(KC_BSLS)

#define KC_NAGR LT(_NAV, KC_GRV)
#define KC_NAMI LT(_NAV, KC_MINS)

#define KC_ADEN LT(_ADJUST, KC_END)
#define KC_ADPU LT(_ADJUST, KC_PGUP)

#define LT_SCLN LT(_SYMB, KC_SCLN)
#define LCT_ESC LCTL_T(KC_ESC)

#define ALTSYM

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

  [_QWERTY] = LAYOUT(
  //┌────────┬────────┬────────┬────────┬────────┬────────┐                                           ┌────────┬────────┬────────┬────────┬────────┬────────┐
     KC_EQL  ,KC_1    ,KC_2    ,KC_3    ,KC_4    ,KC_5    ,                                            KC_6    ,KC_7    ,KC_8    ,KC_9    ,KC_0    ,KC_MINUS,
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┐                         ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┤
     KC_TAB  ,KC_Q    ,KC_W    ,KC_E    ,KC_R    ,KC_T    ,KC_HOME ,                          KC_PGUP ,KC_Y    ,KC_U    ,KC_I    ,KC_O    ,KC_P    ,KC_BSLASH,
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┤                         ├────────┼────────┼────────┼────────┼────────┼────────┼────────┤
     LCT_ESC ,KC_A    ,KC_S    ,KC_D    ,KC_F    ,KC_G    ,KC_END  ,                          KC_PGDN ,KC_H    ,KC_J    ,KC_K    ,KC_L    ,LT_SCLN ,KC_QUOT ,
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┼────────┐       ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┼────────┤
     KC_LSFT ,KC_Z    ,KC_X    ,KC_C    ,KC_V    ,KC_B    ,KC_DEL  ,KC_LCTL ,        KC_RCTL ,KC_TAB  ,KC_N    ,KC_M    ,KC_COMM ,KC_DOT  ,KC_SLSH ,KC_RSFT ,
  //├────────┼────────┼────────┼────────┼────┬───┴────┬───┼────────┼────────┤       ├────────┼────────┼───┬────┴───┬────┼────────┼────────┼────────┼────────┤
     KC_GRV  ,SYM_L   ,SYM_ALT ,KC_LWIN ,     KC_LOPT ,    KC_SPC  ,KC_BSPC ,        KC_ENT  ,KC_SPC  ,    KC_RCTL ,     KC_LEFT ,KC_DOWN ,KC_UP   ,KC_RGHT
  //└────────┴────────┴────────┴────────┘    └────────┘   └────────┴────────┘       └────────┴────────┘   └────────┘    └────────┴────────┴────────┴────────┘
  ),

  [_SYMB] = LAYOUT(
  //┌────────┬────────┬────────┬────────┬────────┬────────┐                                           ┌────────┬────────┬────────┬────────┬────────┬────────┐
     KC_ESC  ,KC_F1   ,KC_F2   ,KC_F3   ,KC_F4   ,KC_F5   ,                                            KC_F6   ,KC_F7   ,KC_F8   ,KC_F9   ,KC_F10  ,QUD_KP_L,
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┐                         ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┤
     _______ ,KC_EXLM ,KC_AT   ,KC_LCBR ,KC_RCBR ,KC_UNDS ,_______ ,                          _______ ,KC_CIRC ,KC_P7   ,KC_P8   ,KC_P9   ,KC_PMNS ,XXXXXXX ,
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┤                         ├────────┼────────┼────────┼────────┼────────┼────────┼────────┤
     QWERTY_L,KC_HASH ,KC_DLR  ,KC_LPRN ,KC_RPRN ,KC_GRV  ,_______ ,                          _______ ,KC_ASTR ,KC_P4   ,KC_P5   ,KC_P6   ,_______ ,XXXXXXX ,
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┼────────┐       ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┼────────┤
     _______ ,KC_PERC ,KC_CIRC ,KC_LBRC ,KC_RBRC ,KC_TILD ,_______ ,_______ ,        _______ ,_______ ,KC_AMPR ,KC_P1   ,KC_P2   ,KC_P3   ,KC_PENT ,XXXXXXX ,
  //├────────┼────────┼────────┼────────┼────┬───┴────┬───┼────────┼────────┤       ├────────┼────────┼───┬────┴───┬────┼────────┼────────┼────────┼────────┤
     KC_PIPE ,_______ ,_______ ,_______ ,     _______ ,    _______ ,_______ ,        _______ ,_______ ,    KC_P0 ,       KC_P0   ,KC_PDOT ,KC_PENT ,XXXXXXX
  //└────────┴────────┴────────┴────────┘    └────────┘   └────────┴────────┘       └────────┴────────┘   └────────┘    └────────┴────────┴────────┴────────┘
  ),

  [_QUD_KP] = LAYOUT(
  //┌────────┬────────┬────────┬────────┬────────┬────────┐                                           ┌────────┬────────┬────────┬────────┬────────┬────────┐
     KC_EQL  ,KC_F1   ,KC_F2   ,KC_F3   ,KC_F4   ,KC_F5   ,                                            KC_F6   ,KC_F7   ,KC_F8   ,KC_F9   ,KC_F10  ,QWERTY_L,
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┐                         ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┤
     KC_TAB  ,KC_Q    ,KC_W    ,KC_E    ,KC_R    ,KC_T    ,KC_HOME ,                          KC_PGUP ,KC_P7   ,KC_P8   ,KC_P9   ,KC_PAST ,KC_PSLS ,KC_BSLASH,
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┤                         ├────────┼────────┼────────┼────────┼────────┼────────┼────────┤
     LCT_ESC ,KC_A    ,KC_S    ,KC_D    ,KC_F    ,KC_G    ,KC_END  ,                          KC_PGDN ,KC_P4   ,KC_P5   ,KC_P6   ,KC_L    ,QUD_Q_L ,KC_QUOT ,
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┼────────┐       ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┼────────┤
     KC_LSFT ,KC_Z    ,KC_X    ,KC_C    ,KC_V    ,KC_B    ,KC_DEL  ,KC_LCTL ,        KC_RCTL ,KC_TAB  ,KC_P1   ,KC_P2   ,KC_P3   ,KC_PMNS ,KC_PPLS ,KC_RSFT ,
  //├────────┼────────┼────────┼────────┼────┬───┴────┬───┼────────┼────────┤       ├────────┼────────┼───┬────┴───┬────┼────────┼────────┼────────┼────────┤
     KC_GRV  ,XXXXXXX ,XXXXXXX ,KC_LWIN ,     KC_LOPT ,    KC_SPC  ,KC_BSPC ,        KC_PENT ,KC_SPC  ,    KC_P0   ,     KC_PDOT ,KC_DOWN ,KC_UP   ,KC_RGHT
  //└────────┴────────┴────────┴────────┘    └────────┘   └────────┴────────┘       └────────┴────────┘   └────────┘    └────────┴────────┴────────┴────────┘
  ),

  [_QUD_QWERTY] = LAYOUT(
  //┌────────┬────────┬────────┬────────┬────────┬────────┐                                           ┌────────┬────────┬────────┬────────┬────────┬────────┐
     KC_EQL  ,KC_1    ,KC_2    ,KC_3    ,KC_4    ,KC_5    ,                                            KC_6    ,KC_7    ,KC_8    ,KC_9    ,KC_0    ,QWERTY_L,
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┐                         ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┤
     KC_TAB  ,KC_Q    ,KC_W    ,KC_E    ,KC_R    ,KC_T    ,KC_HOME ,                          KC_PGUP ,KC_Y    ,KC_U    ,KC_I    ,KC_O    ,KC_P    ,KC_BSLASH,
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┤                         ├────────┼────────┼────────┼────────┼────────┼────────┼────────┤
     LCT_ESC ,KC_A    ,KC_S    ,KC_D    ,KC_F    ,KC_G    ,KC_END  ,                          KC_PGDN ,KC_H    ,KC_J    ,KC_K    ,KC_L    ,QUD_KP_L,KC_QUOT ,
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┼────────┐       ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┼────────┤
     KC_LSFT ,KC_Z    ,KC_X    ,KC_C    ,KC_V    ,KC_B    ,KC_DEL  ,KC_LCTL ,        KC_RCTL ,KC_TAB  ,KC_N    ,KC_M    ,KC_COMM ,KC_DOT  ,KC_SLSH ,KC_RSFT ,
  //├────────┼────────┼────────┼────────┼────┬───┴────┬───┼────────┼────────┤       ├────────┼────────┼───┬────┴───┬────┼────────┼────────┼────────┼────────┤
     KC_GRV  ,XXXXXXX ,XXXXXXX ,KC_LWIN ,     KC_LOPT ,    KC_SPC  ,KC_BSPC ,        KC_ENT  ,KC_SPC  ,    KC_RCTL ,     KC_LEFT ,KC_DOWN ,KC_UP   ,KC_RGHT
  //└────────┴────────┴────────┴────────┘    └────────┘   └────────┴────────┘       └────────┴────────┘   └────────┘    └────────┴────────┴────────┴────────┘
  )
};


// LIGHT LAYER STUFF

const rgblight_segment_t PROGMEM my_qwerty_light_layer[] = RGBLIGHT_LAYER_SEGMENTS(
    {0, 14, HSV_MAGENTA}
);

const rgblight_segment_t PROGMEM my_symb_light_layer[] = RGBLIGHT_LAYER_SEGMENTS(
    {0, 14, HSV_SPRINGGREEN}
);

const rgblight_segment_t PROGMEM my_qud_kp_light_layer[] = RGBLIGHT_LAYER_SEGMENTS(
    {0, 14, HSV_BLUE}
);

const rgblight_segment_t PROGMEM my_qud_qwerty_light_layer[] = RGBLIGHT_LAYER_SEGMENTS(
    {0, 14, HSV_CYAN}
);

const rgblight_segment_t* const PROGMEM my_rgb_layers[] = RGBLIGHT_LAYERS_LIST(
    my_qwerty_light_layer,
    my_symb_light_layer,
    my_qud_kp_light_layer,
    my_qud_qwerty_light_layer
);

void keyboard_post_init_user(void) {
  // Enable LED layers
  rgblight_layers = my_rgb_layers;
};

layer_state_t layer_state_set_user(layer_state_t state) {
  rgblight_set_layer_state(_QWERTY, layer_state_cmp(state, _QWERTY));
  rgblight_set_layer_state(_SYMB, layer_state_cmp(state, _SYMB));
  rgblight_set_layer_state(_QUD_KP, layer_state_cmp(state, _QUD_KP));
  rgblight_set_layer_state(_QUD_QWERTY, layer_state_cmp(state, _QUD_QWERTY));
  return state;
};
