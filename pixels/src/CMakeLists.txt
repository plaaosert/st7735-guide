add_executable(pixels
        main.c
        lib/fonts.c
        lib/st7735.c
        lib/DEV_Config.c
        )

# pull in common dependencies
target_link_libraries(
  pixels
  hardware_pwm
  hardware_pio
  hardware_spi
  hardware_i2c
  pico_stdlib
)

pico_enable_stdio_usb(pixels 1)
pico_enable_stdio_uart(pixels 0)

# create map/bin/hex file etc.
pico_add_extra_outputs(pixels)

# add url via pico_set_program_url
example_auto_set_url(pixels)
