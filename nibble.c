/* Copyright 2020 Jay Greco & Falcaux
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
 * 
 * Change bitc_led by Big Led in RGB
 */
#include QMK_KEYBOARD_H
#include "big_led.h"

// Use big_led LED to show CAPS LOCK status
bool led_update_kb(led_t led_state) {
    bool res = led_update_user(led_state);
	bool red_enabled = 0;
	bool green_enabled = 0;
	bool blue_enabled = 0;
    if (res) {
		if (led_state.caps_lock) {
			red_enabled = rand()&1;
			green_enabled = rand()&1;
			blue_enabled = rand()&1;
			if (green_enabled == 0 && red_enabled == 0 && blue_enabled == 0) {
				green_enabled = 1;
			}
		}
		set_big_LED_rgb(red_enabled ? LED_ON : LED_OFF, green_enabled ? LED_ON : LED_OFF, blue_enabled ? LED_ON : LED_OFF);		
    }
    return res;
}
