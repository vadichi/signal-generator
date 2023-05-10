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

#include "config.h"

const uint16_t OUTPUT_PIN = 16;
const uint16_t ON_OFF_SWITCH_PIN = 4;
const uint16_t SQUARE_WAVE_BUTTON_PIN = 12;
const uint16_t TRIANGLE_WAVE_BUTTON_PIN = 13;
const uint16_t SAWTOOTH_WAVE_BUTTON_PIN = 14;
const uint16_t SINE_WAVE_BUTTON_PIN = 15;
const uint16_t POTENTIOMETER_FREQUENCY_INPUT_PIN = 27;
const uint16_t POTENTIOMETER_FREQUENCY_INPUT_ADC = 1;

const uint16_t SAMPLES_PER_PERIOD = 255;
const uint16_t PWM_OUTPUT_RESOLUTION = 65535;
