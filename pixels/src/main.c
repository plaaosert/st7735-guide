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
    // x, y, col
    ST7735_DrawPixel(count, 13, ST7735_CYAN);
    ST7735_DrawPixel(count, 102, ST7735_RED);

    ST7735_DrawPixel(7, count, ST7735_MAGENTA);
    ST7735_DrawPixel(67, count, ST7735_BLUE);

    // COLOR565 is a macro that converts an RGB888 (0-255 each) colour to a RGB565 colour for the screen.
    // Use this for custom colours, but be aware there will be rounding errors. 
    ST7735_DrawPixel(count, count, ST7735_COLOR565(255, 128, 0));

    count++;
    sleep_ms(50);  // Sleep 50ms or so
  }
}
