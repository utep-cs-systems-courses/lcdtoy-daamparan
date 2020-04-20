//Quiz for the Lab 4/20

#include <libTimer.h>
#include "lcdutils.h"
#include "lcddraw.h"

int main() {
  //first we initialize all the needed files
  configureClocks();
  lcd_init();
  u_char width = screenWidth, height = screenHeight;
  u_char x;
  u_char y;
  u_char z;
  clearScreen(COLOR_BLUE);

  for (x = 0; x < 15; x++) {
    drawPixel(0, x, COLOR_BLACK);
    drawPixel(x, 15, COLOR_BLACK);
    drawPixel(x, x, COLOR_BLACK);
  }
}
