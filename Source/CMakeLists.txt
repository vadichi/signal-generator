cmake_minimum_required(VERSION 3.24)

include(~/Path/pico-sdk/pico_sdk_init.cmake)

project(SignalGenerator C CXX ASM)

set(CMAKE_C_STANDARD 11)
set(CMAKE_CXX_STANDARD  17)

set(PICO_BOARD pico)

pico_sdk_init()

include_directories(
        src/
)

add_executable(SignalGenerator
        src/main.c
        src/config.h
        src/pin_io.h src/pin_io.c
        src/waves.h src/waves.c
)

pico_enable_stdio_usb(SignalGenerator 1)
pico_enable_stdio_uart(SignalGenerator 0)

pico_add_extra_outputs(SignalGenerator)

target_link_libraries(SignalGenerator
    pico_stdlib
    hardware_pwm
    hardware_adc
)
