#include "DigiKeyboard.h"
void setup() {
  pinMode(0, INPUT);
}
void loop() {
  if (digitalRead(0) == LOW) {
    DigiKeyboard.sendKeyStroke(0);
    DigiKeyboard.sendKeyStroke(KEY_SPACE);
    delay(50);
  }
}
