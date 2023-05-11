// Copyright 2023 Vadim Chichikalyuk
//
// This file is part of Signal-Generator
//
// Signal-Generator is free software: you can redistribute it and/or modify it under
// the terms of the GNU General Public License as published by the Free Software
// Foundation, either version 3 of the License, or (at your option) any later version.
//
// Signal-Generator is distributed in the hope that it will be useful, but WITHOUT ANY
// WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS
// FOR A PARTICULAR PURPOSE. See the GNU General Public License for more details.
//
// You should have received a copy of the GNU General Public License along with
// Signal-Generator. If not, see <https://www.gnu.org/licenses/>.

#ifndef SIGNALGENERATOR_CONFIG_H
#define SIGNALGENERATOR_CONFIG_H

#include "pico/stdlib.h"

typedef enum {
    OUTPUT_PIN = 16,
    ON_OFF_SWITCH_PIN = 4,
    SQUARE_WAVE_BUTTON_PIN = 12,
    TRIANGLE_WAVE_BUTTON_PIN = 13,
    SAWTOOTH_WAVE_BUTTON_PIN = 14,
    SINE_WAVE_BUTTON_PIN = 15,
    POTENTIOMETER_FREQUENCY_INPUT_PIN = 27,
    POTENTIOMETER_FREQUENCY_INPUT_ADC = 1,

    SAMPLES_PER_PERIOD = 255,
    PWM_OUTPUT_RESOLUTION = 65535,

    ENABLE_LOGGING = true,
} Config;

#endif //SIGNALGENERATOR_CONFIG_H
