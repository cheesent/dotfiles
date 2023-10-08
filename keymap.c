/*
Copyright 2019 @foostan
Copyright 2020 Drashna Jaelre <@drashna>

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 2 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

#include QMK_KEYBOARD_H
#include "version.h"
#include "keymap_spanish.h"


// Each layer gets a name for readability, which is then used in the keymap matrix below.
// The underscores don't mean anything - you can have a layer called STUFF or any other name.
// Layer names don't all need to be of the same length, obviously, and you can also skip them
// entirely and just use numbers.
enum layers {
  _QWERTY,
  _NAVIGATE,
  _SYMBOLS,
  _NUMPAD,
  _FUNKEYS
};

// Custom keycodes for layer keys
// Dual function escape with left command
#define KC_LGESC LGUI_T(KC_ESC)

enum custom_keycodes {
  QWERTY = SAFE_RANGE,
//   LOWER,
//   RAISE,
//   ADJUST,
  RGBRST
//   KC_RACL // right alt / colon
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    /*
    //,-----------------------------------------------------.                    ,-----------------------------------------------------.
   LT(3,KC_TAB),       Q,       W,       E,       R,       T,                            Y,       U,       I,       O,       P,    BSPC,
    //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
 LCTL_T(KC_ESC),       A,       S,       D,       F,       G,                            H,       J,       K,       L,       Ñ,      ´ ,
    //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      LSFT_T(<),       Z,       X,       C,       V,       B,                            N,       M,    ,/; ,    ./: ,    -/_ , RSFT_T('),
    //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                            WIN/CMD,   MO(1),  KC_SPC,     KC_SPC,   MO(2),    RALT(SUPR)
                                        //`--------------------------'  `--------------------------'

        */
    [_QWERTY] = LAYOUT_split_3x6_3(
    //,-----------------------------------------------------.                    ,-----------------------------------------------------.
LT(_NUMPAD,KC_TAB),    ES_Q,    ES_W,    ES_E,    ES_R,    ES_T,                         ES_Y,    ES_U,    ES_I,    ES_O,    ES_P, KC_BSPC,
    //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
 LCTL_T(KC_ESC),    ES_A,    ES_S,    ES_D,    ES_F,    ES_G,                         ES_H,    ES_J,    ES_K,    ES_L, ES_NTIL, LALT_T(KC_LBRC),
    //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
LSFT_T(ES_LABK),    ES_Z,    ES_X,    ES_C,    ES_V,    ES_B,                         ES_N,    ES_M, ES_COMM,  ES_DOT, ES_MINS, RSFT_T(ES_QUOT),
    //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                       KC_LGUI, LT(_NAVIGATE,KC_CAPS), KC_SPC,     MO(_NUMPAD), KC_ENT, MO(_SYMBOLS)
                                        //`--------------------------'  `--------------------------'
    ),

    /*
    //,-----------------------------------------------------.                    ,-----------------------------------------------------.
         KC_TAB,   z    ,   v    ,   c    , KC_LCTL,        ,                             ,        ,   ↑    ,        ,        ,        ,
    //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
         KC_ESC,   x    , KC_LSFT, KC_LALT, KC_LGUI,        ,                             ,     ←  ,   ↓    ,  →     ,        ,        ,
    //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
        KC_BRMU, KC_BRMD, XXXXXXX, XXXXXXX, KC_MUTE, KC_VOLD,                      KC_VOLU, KC_MPRV, KC_MPLY, KC_MNXT, XXXXXXX, XXXXXXX,
    //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                            WIN/CMD,        ,  KC_SPC,     KC_SPC,   MO(2), KC_DEL
                                        //`--------------------------'  `--------------------------'

// vim-like navigation on the arrows below
// ks_pscr is for screenshots

        */

    [_NAVIGATE] = LAYOUT_split_3x6_3(
    //,-----------------------------------------------------.                    ,-----------------------------------------------------.
         KC_TAB,    ES_X,    ES_V,    ES_C, ES_Z, XXXXXXX,                      LSA(KC_LEFT), LSA(KC_DOWN), LSA(KC_UP), LSA(KC_RIGHT), LSA(ES_Z), KC_BSPC,
    //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
         KC_ESC, KC_LCTL, KC_LSFT, KC_LALT, KC_LGUI, KC_PSCR,                      KC_LEFT, KC_DOWN, KC_UP  , KC_RIGHT, RCS(ES_L),KC_DEL,
    //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
        KC_BRMU, KC_BRMD, XXXXXXX, XXXXXXX, KC_MUTE, KC_VOLD,                      KC_VOLU, KC_MPRV, KC_MPLY, KC_MNXT, XXXXXXX, XXXXXXX,
    //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                            KC_LGUI, _______,  KC_SPC,     KC_SPC, XXXXXXX  , MO(_FUNKEYS)
                                        //`--------------------------'  `--------------------------'
    ),

    /*
    //,-----------------------------------------------------.                    ,-----------------------------------------------------.
                ,    ¡   ,    !   ,    (   ,   )    ,        ,                             ,    =   ,    *   ,    `   ,   ^   , KC_BSPC,
    //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
                ,    <   ,    >   ,    {   ,   }    ,        ,                        "    ,   /    ,    +   ,    @   ,   #   ,   º    ,
    //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
                ,    ¿   ,    ?   ,    [   ,   ]    ,        ,                             ,   $    ,    &   ,    |   ,   %   ,   \    ,
    //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                            WIN/CMD,        ,  KC_SPC,     KC_SPC,        , KC_RALT
                                        //`--------------------------'  `--------------------------'

        */

    [_SYMBOLS] = LAYOUT_split_3x6_3(
    //,-----------------------------------------------------.                    ,-----------------------------------------------------.
        XXXXXXX, ES_IEXL, ES_QUES, KC_LBRC, ES_LPRN, ES_RPRN,                      ES_DQUO,  ES_EQL, ES_ASTR,  ES_GRV, ES_CIRC, KC_BSPC,
    //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
        KC_NUBS,LSFT(KC_NUBS), ES_AMPR, KC_GRV ,ES_0 ,ES_DLR,                      RALT(KC_MINS), ES_SLSH, ES_PLUS,   ES_AT, S(KC_3), RALT(KC_BSLS),
    //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
        KC_LSFT, ES_IQUE, ES_EXLM, ES_DQUO,RALT(ES_8), RALT(ES_9),                      XXXXXXX,  KC_QUOT, KC_BSLS, RALT(KC_QUOT), ES_PERC, ES_BSLS,
    //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                            KC_LGUI,   MO(_FUNKEYS),  KC_SPC,     KC_SPC, _______, KC_RALT
                                        //`--------------------------'  `--------------------------'
    ),

    /*
    //,-----------------------------------------------------.                    ,-----------------------------------------------------.
                ,        ,        ,        ,        ,        ,                        +    ,    7   ,    8   ,    9   ,   -   ,        ,
    //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
                ,        ,        ,        ,        ,        ,                        *    ,    4   ,    5   ,    6   ,   /   ,        ,
    //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
                ,        ,        ,        ,        ,        ,                        .    ,    1   ,    2   ,    3   ,   0   ,        ,
    //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                            WIN/CMD,        ,  KC_SPC,     KC_SPC,   MO(2), KC_RALT
                                        //`--------------------------'  `--------------------------'

                                        //I need to fix this numpad... forget it, works quite well to switch my apps on gnome with the kc_lgui
        */

    [_NUMPAD] = LAYOUT_split_3x6_3(
    //,-----------------------------------------------------.                    ,-----------------------------------------------------.
         KC_TAB, XXXXXXX, KC_LSFT, XXXXXXX, XXXXXXX, XXXXXXX,                      ES_MINS, S(KC_3),  ES_EQL, ES_ASTR, ES_SLSH, KC_BSPC,
    //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
         KC_ESC, ES_9   ,ES_8    , ES_7   , ES_6,    XXXXXXX,                      ES_PLUS,    ES_1,    ES_2,    ES_3, ES_4, KC_DEL,
    //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, ES_5, XXXXXXX,                       ES_DOT,    ES_0   , XXXXXXX, ES_ASTR, XXXXXXX, XXXXXXX,
    //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                            KC_LGUI, _______,  KC_SPC,     KC_SPC, _______, KC_RALT
                                        //`--------------------------'  `--------------------------'
                                        //
                                        //
                                        //
                                        //
                                        //
    ),


                                        //Below you can select the position of your F keys from KC_F1 to KC_F24
    // [_FUNKEYS] = LAYOUT_split_3x6_3(
    // //,-----------------------------------------------------.                    ,-----------------------------------------------------.
    //     QK_BOOT, KC_F00 , KC_F00, KC_F00,  KC_F00,  RGB_SPD,                      RGB_RMOD, KC_F00, KC_F00,  KC_F00,  KC_F00,  RGBRST,
    // //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
    //     RGB_TOG,  KC_F00, KC_F00, KC_F5,   KC_F00,  RGB_SAI ,                     RGB_VAI, KC_F00,  KC_F3,   KC_F00,  KC_F00,  RGB_SPI,
    // //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
    //     RGB_MOD, KC_F00, KC_F00, KC_F00,   KC_F00,  RGB_HUD,                      RGB_SAD, KC_F00,  KC_F00,  KC_F00,  KC_F00,  RGB_HUI,
    // //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
    //                                         KC_LGUI, _______,  KC_SPC,     KC_SPC, _______, KC_RALT
    //                                     //`--------------------------'  `--------------------------'


    [_FUNKEYS] = LAYOUT_split_3x6_3(
    //,-----------------------------------------------------.                    ,-----------------------------------------------------.
        QK_BOOT, KC_F1 , KC_F2   , KC_F3  ,  KC_F4,   RGB_SPD,                      RGB_RMOD, KC_F13, KC_F14,  KC_F15,  KC_F16,  RGBRST,
    //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
        KC_LSFT,  KC_F5, KC_F6, KC_F7  ,   KC_F8,  RGB_SAI ,                     RGB_VAI, KC_F17,  KC_F18,   KC_F19,  KC_F20,  RGB_SPI,
    //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
        RGB_MOD, KC_F9, KC_F10, KC_F11,   KC_F12,  RGB_HUD,                      RGB_SAD, KC_F21,  KC_F22,  KC_F23,  KC_F24,  RGB_HUI,
    //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                            KC_LGUI, _______,  KC_SPC,     KC_SPC, _______, KC_RALT
                                        //`--------------------------'  `--------------------------'
    )
};



#ifdef OLED_ENABLE
oled_rotation_t oled_init_user(oled_rotation_t rotation) { return OLED_ROTATION_270; }

void render_space(void) {
    oled_write_P(PSTR("     "), false);
}

void render_mod_status_gui_alt(uint8_t modifiers) {
    static const char PROGMEM gui_off_1[] = {0x85, 0x86, 0};
    static const char PROGMEM gui_off_2[] = {0xa5, 0xa6, 0};
    static const char PROGMEM gui_on_1[] = {0x8d, 0x8e, 0};
    static const char PROGMEM gui_on_2[] = {0xad, 0xae, 0};

    static const char PROGMEM alt_off_1[] = {0x87, 0x88, 0};
    static const char PROGMEM alt_off_2[] = {0xa7, 0xa8, 0};
    static const char PROGMEM alt_on_1[] = {0x8f, 0x90, 0};
    static const char PROGMEM alt_on_2[] = {0xaf, 0xb0, 0};

    // fillers between the modifier icons bleed into the icon frames
    static const char PROGMEM off_off_1[] = {0xc5, 0};
    static const char PROGMEM off_off_2[] = {0xc6, 0};
    static const char PROGMEM on_off_1[] = {0xc7, 0};
    static const char PROGMEM on_off_2[] = {0xc8, 0};
    static const char PROGMEM off_on_1[] = {0xc9, 0};
    static const char PROGMEM off_on_2[] = {0xca, 0};
    static const char PROGMEM on_on_1[] = {0xcb, 0};
    static const char PROGMEM on_on_2[] = {0xcc, 0};

    if(modifiers & MOD_MASK_GUI) {
        oled_write_P(gui_on_1, false);
    } else {
        oled_write_P(gui_off_1, false);
    }

    if ((modifiers & MOD_MASK_GUI) && (modifiers & MOD_MASK_ALT)) {
        oled_write_P(on_on_1, false);
    } else if(modifiers & MOD_MASK_GUI) {
        oled_write_P(on_off_1, false);
    } else if(modifiers & MOD_MASK_ALT) {
        oled_write_P(off_on_1, false);
    } else {
        oled_write_P(off_off_1, false);
    }

    if(modifiers & MOD_MASK_ALT) {
        oled_write_P(alt_on_1, false);
    } else {
        oled_write_P(alt_off_1, false);
    }

    if(modifiers & MOD_MASK_GUI) {
        oled_write_P(gui_on_2, false);
    } else {
        oled_write_P(gui_off_2, false);
    }

    if (modifiers & MOD_MASK_GUI & MOD_MASK_ALT) {
        oled_write_P(on_on_2, false);
    } else if(modifiers & MOD_MASK_GUI) {
        oled_write_P(on_off_2, false);
    } else if(modifiers & MOD_MASK_ALT) {
        oled_write_P(off_on_2, false);
    } else {
        oled_write_P(off_off_2, false);
    }

    if(modifiers & MOD_MASK_ALT) {
        oled_write_P(alt_on_2, false);
    } else {
        oled_write_P(alt_off_2, false);
    }
}

void render_mod_status_ctrl_shift(uint8_t modifiers) {
    static const char PROGMEM ctrl_off_1[] = {0x89, 0x8a, 0};
    static const char PROGMEM ctrl_off_2[] = {0xa9, 0xaa, 0};
    static const char PROGMEM ctrl_on_1[] = {0x91, 0x92, 0};
    static const char PROGMEM ctrl_on_2[] = {0xb1, 0xb2, 0};

    static const char PROGMEM shift_off_1[] = {0x8b, 0x8c, 0};
    static const char PROGMEM shift_off_2[] = {0xab, 0xac, 0};
    static const char PROGMEM shift_on_1[] = {0xcd, 0xce, 0};
    static const char PROGMEM shift_on_2[] = {0xcf, 0xd0, 0};

    // fillers between the modifier icons bleed into the icon frames
    static const char PROGMEM off_off_1[] = {0xc5, 0};
    static const char PROGMEM off_off_2[] = {0xc6, 0};
    static const char PROGMEM on_off_1[] = {0xc7, 0};
    static const char PROGMEM on_off_2[] = {0xc8, 0};
    static const char PROGMEM off_on_1[] = {0xc9, 0};
    static const char PROGMEM off_on_2[] = {0xca, 0};
    static const char PROGMEM on_on_1[] = {0xcb, 0};
    static const char PROGMEM on_on_2[] = {0xcc, 0};

    if(modifiers & MOD_MASK_CTRL) {
        oled_write_P(ctrl_on_1, false);
    } else {
        oled_write_P(ctrl_off_1, false);
    }

    if ((modifiers & MOD_MASK_CTRL) && (modifiers & MOD_MASK_SHIFT)) {
        oled_write_P(on_on_1, false);
    } else if(modifiers & MOD_MASK_CTRL) {
        oled_write_P(on_off_1, false);
    } else if(modifiers & MOD_MASK_SHIFT) {
        oled_write_P(off_on_1, false);
    } else {
        oled_write_P(off_off_1, false);
    }

    if(modifiers & MOD_MASK_SHIFT) {
        oled_write_P(shift_on_1, false);
    } else {
        oled_write_P(shift_off_1, false);
    }

    if(modifiers & MOD_MASK_CTRL) {
        oled_write_P(ctrl_on_2, false);
    } else {
        oled_write_P(ctrl_off_2, false);
    }

    if (modifiers & MOD_MASK_CTRL & MOD_MASK_SHIFT) {
        oled_write_P(on_on_2, false);
    } else if(modifiers & MOD_MASK_CTRL) {
        oled_write_P(on_off_2, false);
    } else if(modifiers & MOD_MASK_SHIFT) {
        oled_write_P(off_on_2, false);
    } else {
        oled_write_P(off_off_2, false);
    }

    if(modifiers & MOD_MASK_SHIFT) {
        oled_write_P(shift_on_2, false);
    } else {
        oled_write_P(shift_off_2, false);
    }
}

void render_logo(void) {
    static const char PROGMEM corne_logo[] = {
        0x80, 0x81, 0x82, 0x83, 0x84,
        0xa0, 0xa1, 0xa2, 0xa3, 0xa4,
        0xc0, 0xc1, 0xc2, 0xc3, 0xc4, 0};
    oled_write_P(corne_logo, false);
    oled_write_P(PSTR("corne"), false);
}

void render_layer_state(void) {
    static const char PROGMEM raise_layer[] = {
        0x20, 0x97, 0x98, 0x99, 0x20,
        0x20, 0xb7, 0xb8, 0xb9, 0x20,
        0x20, 0xd7, 0xd8, 0xd9, 0x20, 0};
    static const char PROGMEM navigate_layer[] = {
        0x20, 0x94, 0x95, 0x96, 0x20,
        0x20, 0xb4, 0xb5, 0xb6, 0x20,
        0x20, 0xd4, 0xd5, 0xd6, 0x20, 0};
    static const char PROGMEM lower_layer[] = {
        0x20, 0x9a, 0x9b, 0x9c, 0x20,
        0x20, 0xba, 0xbb, 0xbc, 0x20,
        0x20, 0xda, 0xdb, 0xdc, 0x20, 0};
    static const char PROGMEM numpad_layer[] = {
        0x20, 0x9b, 0x9c, 0x94, 0x20,
        0x20, 0xbb, 0xbc, 0xb4, 0x20,
        0x20, 0xdb, 0xdc, 0xd4, 0x20, 0};
    static const char PROGMEM adjust_layer[] = {
        0x20, 0x9d, 0x9e, 0x9f, 0x20,
        0x20, 0xbd, 0xbe, 0xbf, 0x20,
        0x20, 0xdd, 0xde, 0xdf, 0x20, 0};
    if(layer_state_is(_FUNKEYS)) {
        oled_write_P(adjust_layer, false);
    } else if(layer_state_is(_NAVIGATE)) {
        oled_write_P(navigate_layer, false);
    } else if(layer_state_is(_SYMBOLS)) {
        oled_write_P(lower_layer, false);
    } else if(layer_state_is(_NUMPAD)) {
        oled_write_P(numpad_layer, false);
    } else {
        oled_write_P(raise_layer, false);
    }
}

bool oled_task_user(void) {
    // Renders the current keyboard state (layers and mods)
    render_logo();
    render_space();
    render_layer_state();
    render_space();
    render_mod_status_gui_alt(get_mods()|get_oneshot_mods());
    render_mod_status_ctrl_shift(get_mods()|get_oneshot_mods());
    return false;
}

#endif
bool process_record_user(uint16_t keycode, keyrecord_t *record) {
//   static uint16_t my_colon_timer;

  switch (keycode) {
    /* case LOWER:
      if (record->event.pressed) {
        layer_on(_NAVIGATE);
        update_tri_layer_RGB(_NAVIGATE, _SYMBOLS, _FUNKEYS);
      } else {
        layer_off(_NAVIGATE);
        update_tri_layer_RGB(_NAVIGATE, _SYMBOLS, _FUNKEYS);
      }
      return false;
    case RAISE:
      if (record->event.pressed) {
        layer_on(_SYMBOLS);
        update_tri_layer_RGB(_NAVIGATE, _SYMBOLS, _FUNKEYS);
      } else {
        layer_off(_SYMBOLS);
        update_tri_layer_RGB(_NAVIGATE, _SYMBOLS, _FUNKEYS);
      }
      return false;
    case ADJUST:
        if (record->event.pressed) {
          layer_on(_FUNKEYS);
        } else {
          layer_off(_FUNKEYS);
        }
        return false;
    case KC_RACL:
        if (record->event.pressed) {
          my_colon_timer = timer_read();
          register_code(KC_RALT);
        } else {
          unregister_code(KC_RALT);
          if (timer_elapsed(my_colon_timer) < TAPPING_TERM) {
            SEND_STRING(":"); // Change the character(s) to be sent on tap here
          }
        }
        return false; */
    case RGBRST:
      #ifdef RGBLIGHT_ENABLE
        if (record->event.pressed) {
          eeconfig_update_rgblight_default();
          rgblight_enable();
        }
      #endif
      #ifdef RGB_MATRIX_ENABLE
        if (record->event.pressed) {
          eeconfig_update_rgb_matrix_default();
          rgb_matrix_enable();
        }
      #endif
      break;
  }
  return true;
}

