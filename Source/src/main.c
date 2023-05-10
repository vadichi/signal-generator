#include "pico/stdlib.h"

#include "inputs.h"
#include "waves.h"

int main(void) {
    stdio_init_all();

    inputs_initialise();
    waves_initialise();
}
