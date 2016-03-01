#include <duinotech595.h>


void setup() {
  // put your setup code here, to run once:
  setPins();
}

void loop() {
  // put your main code here, to run repeatedly:
  for (int i = 0; i < sizeof(pairArray); i++) {
    updateShiftRegister(pairArray[i]);
    delay(1000);
  }
}
