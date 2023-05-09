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

static void generate_square_waveform(Wave *wave);
static void generate_triangle_waveform(Wave *wave);
static void generate_sawtooth_waveform(Wave *wave);
static void generate_sine_waveform(Wave *wave);

void waves_initialise(void);

Wave waves[(uint8_t) WAVE_TYPES_COUNT] = {
        { .samples = {0} },
        { .samples = {0} },
        { .samples = {0} },
        { .samples = {0} },
};

#endif //SIGNALGENERATOR_WAVES_H
