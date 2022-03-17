#include <stdio.h>

#include "pico/stdlib.h"
#include "lib/fonts.h"
#include "lib/st7735.h"

int main() {
  // Screen and other boilerplate initialisation
  stdio_init_all();  // Initialise serial in/output
  setvbuf ( stdout , NULL , _IONBF , 0 );  // Disable line and block buffering on stdout (for talking through serial)
  sleep_ms(1000);  // Give the Pico some time to think...
  ST7735_Init();  // Initialise the screen
  ST7735_DrawImage(0, 0, 80, 160, plaao_logo);  // Draw the image.
  sleep_ms(20000);  // Sleep for 20 seconds
}
