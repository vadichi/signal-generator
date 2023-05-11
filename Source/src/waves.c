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

#include <math.h>

#include "logging.h"

Wave waves[(uint8_t) WAVE_TYPES_COUNT] = {
        { .samples = {0} },
        { .samples = {0} },
        { .samples = {0} },
        { .samples = {0} },
};

static void generate_square_waveform(Wave *wave) {
    for (uint sample = 0; sample < SAMPLES_PER_PERIOD; sample++) {
        wave->samples[sample] = (sample < SAMPLES_PER_PERIOD / 2) ? PWM_OUTPUT_RESOLUTION : 0;
        log_print("square_waveform[%d] = %d", sample, wave->samples[sample]);
    }
}

static void generate_triangle_waveform(Wave *wave) {
    uint samples_per_half_period = SAMPLES_PER_PERIOD / 2;

    for (uint sample = 0; sample < SAMPLES_PER_PERIOD; sample++) {
        double height_fraction;
        if (sample < samples_per_half_period) {
            // Rising edge
            height_fraction = ((double)(sample) / (double)(samples_per_half_period));

        } else {
            // Falling edge
            height_fraction = ((double)(SAMPLES_PER_PERIOD - sample) / (double)(samples_per_half_period));
        }

        uint16_t pwm_level = (uint16_t)(height_fraction * PWM_OUTPUT_RESOLUTION);

        wave->samples[sample] = pwm_level;
        log_print("triangle_waveform[%d] = %d", sample, wave->samples[sample]);
    }
}

static void generate_sawtooth_waveform(Wave *wave) {
    for (uint sample = 0; sample < SAMPLES_PER_PERIOD; sample++) {
        double height_fraction = ((double)(sample) / (double)(SAMPLES_PER_PERIOD));
        uint16_t pwm_level = (uint16_t)(height_fraction * PWM_OUTPUT_RESOLUTION);

        wave->samples[sample] = pwm_level;
        log_print("sawtooth_waveform[%d] = %d", sample, wave->samples[sample]);
    }
}

static void generate_sine_waveform(Wave *wave) {
    for (uint sample = 0; sample < SAMPLES_PER_PERIOD; sample++) {
        double angle_fraction = ((double)(sample) / (double)(SAMPLES_PER_PERIOD));
        double angle_radians = angle_fraction * 2.0f * M_PI;
        double sine = sin(angle_radians);

        uint16_t scale_factor = (uint16_t)(ceil((double)(PWM_OUTPUT_RESOLUTION) / 2.0f));
        int32_t zero_centered_pwm_level = (int32_t)(sine * scale_factor);

        int32_t normalised_pwm_level = zero_centered_pwm_level + (int32_t)(scale_factor);
        if (normalised_pwm_level > PWM_OUTPUT_RESOLUTION) normalised_pwm_level = PWM_OUTPUT_RESOLUTION;

        wave->samples[sample] = (uint16_t)(normalised_pwm_level);
        log_print("sine_waveform[%d] = %d", sample, wave->samples[sample]);
    }
}

void waves_initialise(void) {
    log_print("Generating square waveform...");
    generate_square_waveform(&waves[WAVE_TYPE_SQUARE]);

    log_print("Generating triangle waveform...");
    generate_triangle_waveform(&waves[WAVE_TYPE_TRIANGLE]);

    log_print("Generating sawtooth waveform...");
    generate_sawtooth_waveform(&waves[WAVE_TYPE_SAWTOOTH]);

    log_print("Generating sine waveform...");
    generate_sine_waveform(&waves[WAVE_TYPE_SINE]);
}
