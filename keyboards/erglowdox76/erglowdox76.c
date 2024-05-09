/* Copyright 2018 Ryota Goto
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
#include "erglowdox76.h"
#include "split_util.h"

/* void i2c_init(void) {
    // Try releasing special pins for a short time
    palSetPadMode(I2C1_SCL_BANK, I2C1_SCL, PAL_MODE_INPUT);
    palSetPadMode(I2C1_SDA_BANK, I2C1_SDA, PAL_MODE_INPUT);

    palSetPadMode(I2C1_SCL_BANK, I2C1_SCL, PAL_MODE_ALTERNATE(I2C1_SCL_PAL_MODE) | PAL_STM32_OTYPE_OPENDRAIN | PAL_STM32_PUPDR_PULLUP);
    palSetPadMode(I2C1_SDA_BANK, I2C1_SDA, PAL_MODE_ALTERNATE(I2C1_SDA_PAL_MODE) | PAL_STM32_OTYPE_OPENDRAIN | PAL_STM32_PUPDR_PULLUP);
}

bool is_keyboard_left(void) {
    // Test pin SPLIT_HAND_PIN for High/Low, if low it's right hand
    setPinInputLow(SPLIT_HAND_PIN);
    return readPin(SPLIT_HAND_PIN);
}

#ifdef OLED_DRIVER_ENABLE
oled_rotation_t oled_init_user(oled_rotation_t rotation) {

    if (!isLeftHand) {
        return OLED_ROTATION_180;
    }

    return rotation;
}
#endif */

void led_init_ports(void) {
    setPinOutput(LED_PIN_1);
    setPinOutput(LED_PIN_2);
    setPinOutput(LED_PIN_3);
    set_layer_indicators(0);
}

void led_toggle(uint8_t id, bool on) {
    switch (id) {
        case 0:
            writePin(LED_PIN_1, on);
            break;
        case 1:
            writePin(LED_PIN_2, on);
            break;
        case 2:
            writePin(LED_PIN_3, on);
            break;
        default:
            break;
    }
}

/*void set_all_leds(bool leds[6]) {
    for (int i = 0; i < 6; i++) {
        led_toggle(i, leds[i]);
    }
}*/

void set_layer_indicators(uint8_t layer) {
    switch (layer) {
        case 0:
            led_toggle(0, true);
            led_toggle(1, false);
            led_toggle(2, false);
            break;
        case 1:
            led_toggle(0, true);
            led_toggle(1, true);
            led_toggle(2, false);
            break;
        case 2:
            led_toggle(0, true);
            led_toggle(1, true);
            led_toggle(2, true);
            break;
        case 3:
            led_toggle(0, false);
            led_toggle(1, true);
            led_toggle(2, true);
            break;
        case 4:
            led_toggle(0, false);
            led_toggle(1, false);
            led_toggle(2, true);
            break;
        default:
            led_toggle(0, true);
            led_toggle(1, false);
            led_toggle(2, true);
            break;
    }
}

layer_state_t layer_state_set_kb(layer_state_t state) {
    set_layer_indicators(get_highest_layer(state));

    return layer_state_set_user(state);
}
