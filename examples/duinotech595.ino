#include <duinotech595.h>

const int LATCH_PIN = 6;
const int CLOCK_PIN = 5;
const int DATA_PIN  = 4;


void setup() {
  // put your setup code here, to run once:
  pinSetup();
}

void loop() {
  // put your main code here, to run repeatedly:
  for (int j = 0; j < 256; j++) {
    updateShiftRegister(j);
    delay(1000);
  }

  for (int i = 0; i < sizeof(pairArray); i++) {
    updateShiftRegister(pairArray[i]);
    delay(1000);
  }

  for (int i = 0; i < sizeof(allArray); i++) {
    updateShiftRegister(allArray[i]);
    delay(1000);
  }
}
