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

#ifndef SIGNALGENERATOR_PIN_IO_H
#define SIGNALGENERATOR_PIN_IO_H

#include "pico/stdlib.h"

static uint pwm_output_slice;
static uint pwm_output_channel;

static uint sample;

static void on_off_switch_isr(uint pin, uint32_t event_data);
static void square_wave_button_isr(uint pin, uint32_t event_data);
static void triangle_wave_button_isr(uint pin, uint32_t event_data);
static void sawtooth_wave_button_isr(uint pin, uint32_t event_data);
static void sine_wave_button_isr(uint pin, uint32_t event_data);

static uint16_t get_current_sample(void);

void pin_io_initialise(void);
void pin_io_tick(void);

#endif //SIGNALGENERATOR_PIN_IO_H
