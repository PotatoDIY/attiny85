#include "DigiKeyboard.h"
void setup() {

  pinMode(0, INPUT);
  pinMode(1, INPUT);
  pinMode(2, INPUT);

}
void loop() {
  
  
  if (digitalRead(0) == HIGH) {
    DigiKeyboard.sendKeyStroke(0);
    DigiKeyboard.sendKeyStroke(KEY_R,MOD_GUI_LEFT);
    DigiKeyboard.delay(1000);
    DigiKeyboard.println("chrome.exe");
    DigiKeyboard.delay(1000);
    DigiKeyboard.println("chrome://dino");
    DigiKeyboard.delay(1000);
  }
  
  if (digitalRead(1) == HIGH) {
    DigiKeyboard.sendKeyStroke(0);
    DigiKeyboard.sendKeyStroke(KEY_SPACE);
    DigiKeyboard.delay(1000);
  }

  if (digitalRead(2) == HIGH) {
    DigiKeyboard.sendKeyStroke(0);
    DigiKeyboard.sendKeyStroke(KEY_F4,MOD_ALT_LEFT);
    DigiKeyboard.delay(1000);
  }
}
