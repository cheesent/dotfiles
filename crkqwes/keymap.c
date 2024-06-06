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
LSFT_T(ES_LABK),    ES_Z,    ES_X,    ES_C,    ES_V,    ES_B,                         ES_N,    ES_M, ES_COMM,  ES_DOT, ES_MINS, KC_RSFT,
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
        RALT(KC_RBRC), ES_IEXL, ES_QUES, ES_QUOT, ES_LPRN, ES_RPRN,                      ES_DQUO,  ES_EQL, ES_ASTR,  ES_GRV, ES_CIRC, KC_BSPC,
    //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
        KC_NUBS,LSFT(KC_NUBS), ES_AMPR, KC_GRV ,ES_0 ,ES_DLR,                      RALT(KC_MINS), ES_SLSH, ES_PLUS,   ES_AT, S(KC_3), RALT(KC_BSLS),
    //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
        KC_LSFT, ES_IQUE, ES_EXLM, ES_DQUO,RALT(ES_8), RALT(ES_9),                      ES_QUOT,  KC_QUOT, KC_BSLS, RALT(KC_QUOT), ES_PERC, ES_BSLS,
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
         KC_ESC, ES_1   ,ES_2    , ES_3   , ES_4,    ES_5,                      ES_5,    ES_6,    ES_7,    ES_8, ES_9, KC_DEL,
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
        QK_BOOT, KC_F1 , KC_F2   , KC_F3  ,  KC_F4,   RGB_SPD,                      RGB_RMOD, RSFT(KC_F1), RSFT(KC_F2),  RSFT(KC_F3),  RSFT(KC_F4),  RGBRST,
    //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
        KC_LSFT,  KC_F5, KC_F6, KC_F7  ,   KC_F8,  RGB_SAI ,                     RGB_VAI, RSFT(KC_F5), RSFT(KC_F6),  RSFT(KC_F7),  RSFT(KC_F8),  RGB_SPI,
    //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
        RGB_MOD, KC_F9, KC_F10, KC_F11,   KC_F12,  RGB_HUD,                      RGB_SAD, RSFT(KC_F9), RSFT(KC_F10),  RSFT(KC_F11),  RSFT(KC_F12),  RGB_HUI,
    //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                            KC_LGUI, _______,  KC_SPC,     KC_SPC, _______, KC_RALT
                                        //`--------------------------'  `--------------------------'
    )
};

