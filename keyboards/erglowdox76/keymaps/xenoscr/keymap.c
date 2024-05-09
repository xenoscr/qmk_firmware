// Copyright 2023 QMK
// SPDX-License-Identifier: GPL-2.0-or-later

#include QMK_KEYBOARD_H

#include "split_util.h"

#define KC_MAC_UNDO LGUI(KC_Z)
#define KC_MAC_CUT LGUI(KC_X)
#define KC_MAC_COPY LGUI(KC_C)
#define KC_MAC_PASTE LGUI(KC_V)
#define KC_PC_UNDO LCTL(KC_Z)
#define KC_PC_CUT LCTL(KC_X)
#define KC_PC_COPY LCTL(KC_C)
#define KC_PC_PASTE LCTL(KC_V)
#define ES_LESS_MAC KC_GRAVE
#define ES_GRTR_MAC LSFT(KC_GRAVE)
#define ES_BSLS_MAC ALGR(KC_6)
#define NO_PIPE_ALT KC_GRAVE
#define NO_BSLS_ALT KC_EQUAL
#define LSA_T(kc) MT(MOD_LSFT | MOD_LALT, kc)
#define BP_NDSH_MAC ALGR(KC_8)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    /*
     * ┌────────┬───┬───┬───┬───┬───┬──────┐                               ┌───────┬───┬───┬───┬───┬───┬───────┐
     * │ Reset  │ 1 │ 2 │ 3 │ 4 │ 5 │ Copy │                               │ Paste │ 6 │ 7 │ 8 │ 9 │ 0 │ Pause │
     * ├────────┼───┼───┼───┼───┼───┼──────┤                               ├───────┼───┼───┼───┼───┼───┼───────┤
     * │ `      │ Q │ W │ E │ R │ T │ FN   │                               │ FN    │ Y │ U │ I │ O │ P │ =     │
     * ├────────┼───┼───┼───┼───┼───┤      │                               │       ├───┼───┼───┼───┼───┼───────┤
     * │F22     │ A │ S │ D │ F │ G ├──────┤                               ├───────┤ H │ J │ K │ L │ ; │ '     │
     * ├────────┼───┼───┼───┼───┼───┤      │                               │       ├───┼───┼───┼───┼───┼───────┤
     * │Ctl+D   │ Z │ X │ C │ V │ B │ TAB  │                               │ Enter │ N │ M │ , │ . │ / │ -     │
     * └──┬─────┼───┼───┼───┼───┼───┴──────┘ ┌───┬─────┐ ┌─────┬─────────┐ └───────┴───┼───┼───┼───┼───┼───┬───┘
     *    │PrScr│Ins│GUI│Ctl│Alt│            │Esc│Ctl+A│ │Ctl+Z│Ctl+SFT+Z│             │Alt│Ctl│ [ │ ] │F24│
     *    └─────┴───┴───┴───┴───┘        ┌───┼───┼─────┤ ├─────┼─────────┼───┐         └───┴───┴───┴───┴───┘
     *                                   │   │   │Home │ │PgU  │         │   │
     *                                   │Bsp│SFT├─────┤ ├─────┤SFT      │SPC│
     *                                   │   │   │End  │ │PgU  │         │   │
     *                                   └───┴───┴─────┘ └─────┴─────────┴───┘
     */
  [0] = LAYOUT_ergodox(
    RESET,          KC_1,               KC_2,       KC_3,       KC_4,       KC_5,       KC_PC_COPY,
    KC_GRAVE,       KC_Q,               KC_W,       KC_E,       KC_R,       KC_T,       TG(1),
    KC_F22,         KC_A,               KC_S,       KC_D,       KC_F,       KC_G,
    LCTL(KC_D),     KC_Z,               KC_X,       KC_C,       KC_V,       KC_B,       KC_TAB,
    KC_PSCR,        KC_INSERT,          KC_LGUI,    KC_LCTL,    KC_LALT,    KC_ESCAPE,  LCTL(KC_A),
    KC_HOME,
    KC_BSPC,        KC_LSFT,            LT(1,KC_END),
    KC_PC_PASTE,    KC_6,               KC_7,       KC_8,       KC_9,       KC_0,       KC_PAUSE,
    TG(1),          KC_Y,               KC_U,       KC_I,       KC_O,       KC_P,       KC_EQUAL,
    KC_H,           KC_J,               KC_K,       KC_L,       KC_SCLN,    KC_QUOTE,
    KC_ENTER,       KC_N,               KC_M,       KC_COMMA,   KC_DOT,     KC_SLASH,   KC_MINUS,
    LCTL(KC_Z),     LCTL(LSFT(KC_Z)),   KC_RALT,    KC_RCTL,    KC_LBRC,    KC_RBRC,    KC_F24,
    KC_PGUP,
    LT(1,KC_PGDN),  KC_RSFT, KC_SPACE
    ),
  [1] = LAYOUT_ergodox(
    KC_ESCAPE,      KC_F1,          KC_F2,          KC_F3,          KC_F4,          KC_F5,          KC_TRANSPARENT,
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,
    KC_TRANSPARENT, RGB_TOG,        RGB_MOD,        RGB_HUI,        RGB_VAI,        RGB_SAI,
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,
    KC_SCROLL_LOCK, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,
    KC_TRANSPARENT,
    KC_DELETE, KC_TRANSPARENT, KC_TRANSPARENT,
    KC_TRANSPARENT, KC_F6,                  KC_F7,              KC_F8,                  KC_F9,                  KC_F10,         KC_F11,
    KC_TRANSPARENT, KC_MEDIA_PLAY_PAUSE,    KC_LCBR,            KC_RCBR,                KC_LBRC,                KC_RBRC,        KC_F12,
    KC_LEFT,        KC_DOWN,                KC_UP,              KC_RIGHT,               KC_TRANSPARENT,         KC_TRANSPARENT,
    KC_AUDIO_MUTE,  KC_AUDIO_VOL_DOWN,      KC_AUDIO_VOL_UP,    KC_MEDIA_PREV_TRACK,    KC_MEDIA_NEXT_TRACK,    KC_BACKSLASH,   KC_PIPE,
    KC_TRANSPARENT, KC_TRANSPARENT,         KC_TRANSPARENT,     KC_TRANSPARENT,         KC_TRANSPARENT,         KC_TRANSPARENT, KC_TRANSPARENT,
    KC_TRANSPARENT,
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT
    ),
};

/*void keyboard_post_init_user(void) {
  // Customise these values to desired behaviour
  debug_enable=true;
  debug_matrix=true;
  //debug_keyboard=true;
  //debug_mouse=true;
}*/

#ifdef OLED_DRIVER_ENABLE
void oled_task_user(void) {
    if (!isLeftHand){
    // Host Keyboard Layer Status
        oled_write_P(PSTR("Layer: "), false);

        switch (get_highest_layer(layer_state)) {
            case 0:
                oled_write_P(PSTR("Default\n\n"), false);
                break;
            case 1:
                oled_write_P(PSTR("Symbol\n\n"), false);
                break;
            case 2:
                oled_write_P(PSTR("Fn\n\n"), false);
                break;
            default:
                // Or use the write_ln shortcut over adding '\n' to the end of your string
                oled_write_ln_P(PSTR("Undefined"), false);
        }

        // Host Keyboard LED Status
        led_t led_state = host_keyboard_led_state();
        oled_write_P(led_state.num_lock ? PSTR("NUM ") : PSTR("    "), false);
        oled_write_P(led_state.caps_lock ? PSTR("CAP ") : PSTR("    "), false);
        oled_write_P(led_state.scroll_lock ? PSTR("SCR ") : PSTR("    "), false);
    }
}
#endif
