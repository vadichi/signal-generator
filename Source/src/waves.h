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

#ifndef SIGNALGENERATOR_WAVES_H
#define SIGNALGENERATOR_WAVES_H

#include "pico/stdlib.h"

#include "config.h"

typedef struct {
    uint16_t samples[SAMPLES_PER_PERIOD];
} Wave;

typedef enum {
    WAVE_TYPE_SQUARE,
    WAVE_TYPE_TRIANGLE,
    WAVE_TYPE_SAWTOOTH,
    WAVE_TYPE_SINE,

    WAVE_TYPES_COUNT,
} WaveType;

extern Wave waves[(uint8_t) WAVE_TYPES_COUNT];

static void generate_square_waveform(Wave *wave);
static void generate_triangle_waveform(Wave *wave);
static void generate_sawtooth_waveform(Wave *wave);
static void generate_sine_waveform(Wave *wave);

void waves_initialise(void);

#endif //SIGNALGENERATOR_WAVES_H
