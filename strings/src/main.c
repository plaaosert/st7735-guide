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
  
  // Fill with black
  ST7735_FillScreen(ST7735_BLACK);

  // Paint pixels to the screen every 50ms
  int count = 0;
  while (true) {
    char strArray[25];  // buffer overflow if len(count) > 12 :-)
    sprintf(strArray, "hello world! %d", count);

    // Write string using the font defined in fonts.c
    ST7735_WriteString(0, 0, strArray, Font_16x26, ST7735_GREEN, ST7735_BLACK);

    count++;
  }
}
