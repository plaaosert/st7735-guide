add_executable(strings
        main.c
        lib/fonts.c
        lib/st7735.c
        lib/DEV_Config.c
        )

# pull in common dependencies
target_link_libraries(
  strings
  hardware_pwm
  hardware_pio
  hardware_spi
  hardware_i2c
  pico_stdlib
)

pico_enable_stdio_usb(strings 1)
pico_enable_stdio_uart(strings 0)

# create map/bin/hex file etc.
pico_add_extra_outputs(strings)

# add url via pico_set_program_url
example_auto_set_url(strings)
