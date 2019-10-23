#include "SimpleDHT.h"
#include <SoftSerial.h>
#include <TinyPinChange.h>
SimpleDHT11 dht11(2);
SoftSerial blueToothSerial(1, 0); // RX, TX
void setup() {
  blueToothSerial.begin(9600);
}
void loop() {
  delay(5000);
  byte temperature = 0;
  byte humidity = 0;
  int err = SimpleDHTErrSuccess;
  if ((err = dht11.read(&temperature, &humidity, NULL)) != SimpleDHTErrSuccess) {
    return;
  }
  blueToothSerial.print((int)temperature); blueToothSerial.print(" *C, ");
  blueToothSerial.print((int)humidity); blueToothSerial.println(" H");
}
