/*
 * Copyright 2023 Chris Trotter <ctrotter@gmail.com> (@christrotter)
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Publicw License as published by
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
// keyboard config
// this is how long 'hold for effect' takes; 300 feels way too long, 200 causes too many accidental triggers
#undef TAPPING_TERM
#define TAPPING_TERM 225            // time (in ms) for a tap to become a hold
#define TAP_CHECK TAPPING_TERM
#undef TAPPING_TOGGLE
#define TAPPING_TOGGLE 2
//#define DEBOUNCE 5                // trying this down from 45, apparently can contribute to input lag
#define ONESHOT_TAP_TOGGLE 2        /* Tapping this number of times holds the key until tapped once again. */
#define ONESHOT_TIMEOUT 2000        /* Time (in ms) before the one shot key is released */
#define CUSTOM_KEYCODES

#if defined(CONSOLE_ENABLE)
    #define DEBUG_MATRIX_SCAN_RATE // we call it on the TFTs
    // #if defined(QP_DEBUG_ENABLE)
    //     #define QUANTUM_PAINTER_DEBUG // massively degrades performance!!!
    // #endif
#endif

#if defined(POINTING_DEVICE_ENABLE)
    #define POINTING_DEVICE_AUTO_MOUSE_ENABLE
    #define AUTO_MOUSE_DEFAULT_LAYER 1
    #define AUTO_MOUSE_DEBOUNCE 25
    // #define POINTING_DEVICE_INVERT_X_RIGHT
    #define POINTING_DEVICE_INVERT_Y_RIGHT
    #define ROTATIONAL_TRANSFORM_ANGLE 0
    #define DRAGSCROLL_BUFFER_SIZE 6
    // #define POINTING_DEVICE_INVERT_X
    // #define POINTING_DEVICE_ROTATION_90_RIGHT
    // #define POINTING_DEVICE_ROTATION_90
    // #define POINTING_DEVICE_INVERT_X            // Inverted movement for X (not sure why this is set tbh...maybe due to the kb half it's installed on?)
    // #define POINTING_DEVICE_INVERT_Y
    // #define DRAGSCROLL_REVERSE_X                // i must have installed the sensor flipped around
    // CPI not being set correctly...hmm...
    #define RIGHT_PMW_CPI 500       // your mouse cpi (DPI) setting (how fast the ball tracks)
    #define LEFT_PMW_CPI 100    // dragscroll cpi - interestingly, can't be set below 100?
#endif

#if defined(QUANTUM_PAINTER_ENABLE)
    #define SCREEN_TIMEOUT 180000 // this is 180s
#endif
