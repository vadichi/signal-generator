#ifndef SIGNALGENERATOR_CONFIG_H
#define SIGNALGENERATOR_CONFIG_H

#include "pico/stdlib.h"

extern const uint16_t OUTPUT_PIN;
extern const uint16_t ON_OFF_SWITCH_PIN;
extern const uint16_t SQUARE_WAVE_BUTTON_PIN;
extern const uint16_t TRIANGLE_WAVE_BUTTON_PIN;
extern const uint16_t SAWTOOTH_WAVE_BUTTON_PIN;
extern const uint16_t SINE_WAVE_BUTTON_PIN;
extern const uint16_t POTENTIOMETER_FREQUENCY_INPUT_PIN;
extern const uint16_t POTENTIOMETER_FREQUENCY_INPUT_ADC;

extern const uint16_t SAMPLES_PER_PERIOD;
extern const uint16_t PWM_OUTPUT_RESOLUTION;

#endif //SIGNALGENERATOR_CONFIG_H
