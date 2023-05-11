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

#include "pin_io.h"

#include "hardware/gpio.h"
#include "hardware/pwm.h"
#include "hardware/adc.h"

#include "waves.h"
#include "logging.h"

WaveType requested_wave_type = WAVE_TYPE_SQUARE;
bool requested_output_enabled = false;

static uint sample = 0;
static uint pwm_output_slice, pwm_output_channel;

static void on_off_switch_isr(__attribute__((unused)) uint pin, __attribute__((unused)) uint32_t event_data) {
    log_print("On/Off switch toggled");
    requested_output_enabled = !requested_output_enabled;
}

static void square_wave_button_isr(__attribute__((unused)) uint pin, __attribute__((unused)) uint32_t event_data) {
    log_print("Square wave button pressed");
    requested_wave_type = WAVE_TYPE_SQUARE;
}

static void triangle_wave_button_isr(__attribute__((unused)) uint pin, __attribute__((unused)) uint32_t event_data) {
    log_print("Triangle wave button pressed");
    requested_wave_type = WAVE_TYPE_TRIANGLE;
}

static void sawtooth_wave_button_isr(__attribute__((unused)) uint pin, __attribute__((unused)) uint32_t event_data) {
    log_print("Sawtooth wave button pressed");
    requested_wave_type = WAVE_TYPE_SAWTOOTH;
}

static void sine_wave_button_isr(__attribute__((unused)) uint pin, __attribute__((unused)) uint32_t event_data) {
    log_print("Sine wave button pressed");
    requested_wave_type = WAVE_TYPE_SINE;
}

static uint16_t get_current_sample(void) {
    return waves[requested_wave_type].samples[sample];
}

void pin_io_initialise(void) {
    gpio_init(OUTPUT_PIN);
    gpio_set_dir(OUTPUT_PIN, GPIO_OUT);
    gpio_set_slew_rate(OUTPUT_PIN, GPIO_SLEW_RATE_FAST);
    gpio_set_drive_strength(OUTPUT_PIN, GPIO_DRIVE_STRENGTH_12MA);
    gpio_set_function(OUTPUT_PIN, GPIO_FUNC_PWM);

    pwm_output_slice = pwm_gpio_to_slice_num(OUTPUT_PIN);
    pwm_output_channel = pwm_gpio_to_channel(OUTPUT_PIN);

    pwm_set_wrap(pwm_output_slice, PWM_OUTPUT_RESOLUTION);
    pwm_set_clkdiv(pwm_output_slice, 1.0f);
    pwm_set_clkdiv_mode(pwm_output_slice, PWM_DIV_FREE_RUNNING);
    pwm_set_chan_level(pwm_output_slice, pwm_output_channel, 0);
    log_print("Initialised output");

    // ToDo — pool from second core
    adc_init();
    gpio_init(POTENTIOMETER_FREQUENCY_INPUT_PIN);
    gpio_set_dir(POTENTIOMETER_FREQUENCY_INPUT_PIN, GPIO_IN);
    adc_gpio_init(POTENTIOMETER_FREQUENCY_INPUT_PIN);
    adc_select_input(POTENTIOMETER_FREQUENCY_INPUT_ADC);
    log_print("Initialised frequency input");

    gpio_init(ON_OFF_SWITCH_PIN);
    gpio_set_dir(ON_OFF_SWITCH_PIN, GPIO_IN);
    gpio_set_pulls(ON_OFF_SWITCH_PIN, true, false);
    gpio_set_irq_enabled_with_callback(ON_OFF_SWITCH_PIN, GPIO_IRQ_EDGE_RISE | GPIO_IRQ_EDGE_FALL, true, &on_off_switch_isr);

    gpio_init(SQUARE_WAVE_BUTTON_PIN);
    gpio_set_dir(SQUARE_WAVE_BUTTON_PIN, GPIO_IN);
    gpio_set_pulls(SQUARE_WAVE_BUTTON_PIN, true, false);
    gpio_set_irq_enabled_with_callback(SQUARE_WAVE_BUTTON_PIN, GPIO_IRQ_EDGE_FALL, true, &square_wave_button_isr);

    gpio_init(TRIANGLE_WAVE_BUTTON_PIN);
    gpio_set_dir(TRIANGLE_WAVE_BUTTON_PIN, GPIO_IN);
    gpio_set_pulls(TRIANGLE_WAVE_BUTTON_PIN, true, false);
    gpio_set_irq_enabled_with_callback(TRIANGLE_WAVE_BUTTON_PIN, GPIO_IRQ_EDGE_FALL, true, &triangle_wave_button_isr);

    gpio_init(SAWTOOTH_WAVE_BUTTON_PIN);
    gpio_set_dir(SAWTOOTH_WAVE_BUTTON_PIN, GPIO_IN);
    gpio_set_pulls(SAWTOOTH_WAVE_BUTTON_PIN, true, false);
    gpio_set_irq_enabled_with_callback(SAWTOOTH_WAVE_BUTTON_PIN, GPIO_IRQ_EDGE_FALL, true, &sawtooth_wave_button_isr);

    gpio_init(SINE_WAVE_BUTTON_PIN);
    gpio_set_dir(SINE_WAVE_BUTTON_PIN, GPIO_IN);
    gpio_set_pulls(SINE_WAVE_BUTTON_PIN, true, false);
    gpio_set_irq_enabled_with_callback(SINE_WAVE_BUTTON_PIN, GPIO_IRQ_EDGE_FALL, true, &sine_wave_button_isr);

    log_print("Initialised buttons");
}

// ToDo — use DMA
void pin_io_tick(void) {
    pwm_set_gpio_level(OUTPUT_PIN, requested_output_enabled ? get_current_sample() : 0);
    sample = (sample + 1) % SAMPLES_PER_PERIOD;

    // ToDo — replace with value derived from frequency
    sleep_us(1);
}
