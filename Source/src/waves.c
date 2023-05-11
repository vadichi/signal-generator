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

#include "waves.h"

Wave waves[(uint8_t) WAVE_TYPES_COUNT] = {
        { .samples = {0} },
        { .samples = {0} },
        { .samples = {0} },
        { .samples = {0} },
};

static void generate_square_waveform(Wave *wave) {
    for (uint sample = 0; sample < SAMPLES_PER_PERIOD; sample++) {
        wave->samples[sample] = (sample < SAMPLES_PER_PERIOD / 2) ? PWM_OUTPUT_RESOLUTION : 0;
    }
}

static void generate_triangle_waveform(Wave *wave) {
    // ToDo: Implement

    for (uint sample = 0; sample < SAMPLES_PER_PERIOD; sample++) {
        wave->samples[sample] = 0;
    }
}

static void generate_sawtooth_waveform(Wave *wave) {
    // ToDo: Implement

    for (uint sample = 0; sample < SAMPLES_PER_PERIOD; sample++) {
        wave->samples[sample] = 0;
    }
}

static void generate_sine_waveform(Wave *wave) {
    // ToDo: Implement

    for (uint sample = 0; sample < SAMPLES_PER_PERIOD; sample++) {
        wave->samples[sample] = 0;
    }
}

void waves_initialise(void) {
    generate_square_waveform(&waves[WAVE_TYPE_SQUARE]);
    generate_triangle_waveform(&waves[WAVE_TYPE_TRIANGLE]);
    generate_sawtooth_waveform(&waves[WAVE_TYPE_SAWTOOTH]);
    generate_sine_waveform(&waves[WAVE_TYPE_SINE]);
}
