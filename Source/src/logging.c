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

#include "logging.h"

#include <stdio.h>
#include <stdarg.h>

#include "config.h"

void log_print(const char *restrict message, ...) {
    if (!ENABLE_LOGGING) return;

    va_list variable_arguments;
    va_start(variable_arguments, message);

    vprintf(message, variable_arguments);
    printf("\n");

    va_end(variable_arguments);
}
