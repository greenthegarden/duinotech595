#include <duinotech595.h>


Duinotech595 duinotech595(6, 5, 4);

const byte LATCH_PIN = 6;
const byte CLOCK_PIN = 5;
const byte DATA_PIN  = 4;


void setup() {
  // put your setup code here, to run once:
  duinotech595.init();
}

void loop() {
  // put your main code here, to run repeatedly:
  for (int i = 0; i < 256; i++) {
    duinotech595.updateShiftRegister(i);
    delay(1000);
  }
}
