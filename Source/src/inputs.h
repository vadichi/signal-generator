#ifndef SIGNALGENERATOR_INPUTS_H
#define SIGNALGENERATOR_INPUTS_H

#include "pico/stdlib.h"

static uint pwm_output_slice;
static uint pwm_output_channel;

void inputs_initialise(void);

#endif //SIGNALGENERATOR_INPUTS_H
