/* Copyright 2021 Mikael Manukyan <arm.localhost@gmail.com>
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
#pragma once

#include "quantum.h"

#ifdef RGB_MATRIX_LEDMAPS_ENABLED

// no association keycode
#    define XXX \
        { 0, 0, 0 }

// led_config_t g_led_config = { {
//     {2,      3,      8,      9,  14, 15, 26, 27},
//     {1,      4,      7,      10, 13, 16, 25, 28},
//     {0,      5,      6,      11, 12, 17, 24, 29},
//     {NO_LED, NO_LED, 31,     35, 33, 37, 36, 39},
//     {NO_LED, NO_LED, 30,     32, 34, 38, 41, 40},
//     {NO_LED, NO_LED, 23,     18, 19, 20, 21, 22}
// }, {
//     {0,32},{3,19},{7,5},{25,4},{21,18},{17,31},{35,26},{39,12},{43,0},{60,0},{56,12},{52,26},
//     {66,33},{70,20},{74,6},{89,12},{85,25},{81,38},{61,50},{77,55},{93,63},{129,63},{145,55},{161,50},
//     {141,38},{137,25},{133,12},{148,6},{152,20},{156,33},{170,26},{166,12},{162,0},{179,0},{183,12},{187,26},
//     {205,31},{201,18},{197,4},{215,5},{219,19},{223,32}
// }, {
//     1, 1, 1, 4, 4, 4, 4, 4, 4, 4, 4, 4,
//     4, 4, 4, 4, 4, 4, 1, 1, 1, 1, 1, 1,
//     4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4,
//     4, 4, 4, 1, 1, 1
// } };

// clang-format off
#   define RGB_MATRIX_LAYOUT_LEDMAP( \
        k01, k02, k03, k04, k05, k06,   k07, k08, k09, k0A, k0B, k0C, \
        k11, k12, k13, k14, k15, k16,   k17, k18, k19, k1A, k1B, k1C, \
        k21, k22, k23, k24, k25, k26,   k27, k28, k29, k2A, k2B, k2C, \
                  t01, t02, t03,   t04, t05, t06             \
    ) \
    { \
        k21, k11, k01, k02, k12, k22, k23, k13, k03, \
        k04, k14, k24, k25, k15, k05, k06, k16, k26, \
        k18, k18, k18, k18, k18, k18, k18, k18, k18, \
        k18, k18, k18, k18, k18, k18, k18, k18, k18, \
        k18, k18, k18, k18, k18 \
    }
// clang-format on
typedef uint8_t ledmap[DRIVER_LED_TOTAL][3];
extern const ledmap ledmaps[];

void set_layer_rgb(uint8_t led_min, uint8_t led_max, int layer);

void rgb_matrix_layers_enable(void);
void rgb_matrix_layers_disable(void);

#endif  // RGB_MATRIX_LEDMAPS_ENABLED

void rgb_matrix_indicators_keymap(void);
void rgb_matrix_indicators_advanced_keymap(uint8_t led_min, uint8_t led_max);
