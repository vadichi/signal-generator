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

#ifndef SIGNALGENERATOR_INPUTS_H
#define SIGNALGENERATOR_INPUTS_H

#include "pico/stdlib.h"

static uint pwm_output_slice;
static uint pwm_output_channel;

void inputs_initialise(void);

#endif //SIGNALGENERATOR_INPUTS_H
