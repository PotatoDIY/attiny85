#include "Tiny4kOLED.h"
#include "font16x32digits.h"

#include <avr/pgmspace.h>
#include "DHT.h"
#define DHTPIN 1     // what pin we're connected to
dht _dht;
void setup() {
  oled.begin();

  // Clear the memory before turning on the display
  oled.clear();
  // Turn on the display
  oled.on();
  // Switch the half of RAM that we are writing to, to be the half that is non currently displayed
  oled.switchRenderFrame();
}
void loop() {
  char temp[16];
  int chk =  _dht.read11(1);
  itoa((int)_dht.temperature, temp, 10);
  char hum[16];
  itoa((int)_dht.humidity, hum, 10);

  oled.setFont(FONT16X32DIGITS);
  oled.setCursor(0, 0);
  oled.print(temp);
  oled.setCursor(80, 0);
  oled.print(hum);

  oled.setFont(FONT6X8);
  oled.setCursor(40, 15);
  oled.print(F("*C"));
  oled.setCursor(120, 15);
  oled.print(F("%"));

  oled.switchFrame();
  delay(1000);
}
