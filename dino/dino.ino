#include "SSD1306_minimal.h"
#include <avr/pgmspace.h>
#include "dino.h"

SSD1306_Mini oled;

void setup() {
  oled.init(0x3c);
  oled.clear();
  oled.startScreen();
  oled.cursorTo(45, 0);
  oled.printString("dinosaur");
  oled.cursorTo(38, 2);
  oled.printString("by potatoDIY");
}


void loop() {
  oled.drawImage(dino_a, 0, 0, 32, 8);
  delay(300);
  oled.drawImage(dino_b, 0, 0, 32, 8);
  delay(300);
}
