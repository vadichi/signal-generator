#include "waves.h"

static void generate_square_waveform(Wave *wave) {
    for (uint16_t sample = 0; sample < SAMPLES_PER_PERIOD; sample++) {
        wave->samples[sample] = (sample < SAMPLES_PER_PERIOD / 2) ? PWM_OUTPUT_RESOLUTION : 0;
    }
}

static void generate_triangle_waveform(Wave *wave) {
    // ToDo: Implement

    for (uint16_t sample = 0; sample < SAMPLES_PER_PERIOD; sample++) {
        wave->samples[sample] = 0;
    }
}

static void generate_sawtooth_waveform(Wave *wave) {
    // ToDo: Implement

    for (uint16_t sample = 0; sample < SAMPLES_PER_PERIOD; sample++) {
        wave->samples[sample] = 0;
    }
}

static void generate_sine_waveform(Wave *wave) {
    // ToDo: Implement

    for (uint16_t sample = 0; sample < SAMPLES_PER_PERIOD; sample++) {
        wave->samples[sample] = 0;
    }
}

void waves_initialise(void) {
    generate_square_waveform(&waves[WAVE_TYPE_SQUARE]);
    generate_triangle_waveform(&waves[WAVE_TYPE_TRIANGLE]);
    generate_sawtooth_waveform(&waves[WAVE_TYPE_SAWTOOTH]);
    generate_sine_waveform(&waves[WAVE_TYPE_SINE]);
}
