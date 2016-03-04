#include <duinotech595.h>

Duinotech595 duinotech595(6, 5, 4);

void setup() {
  // put your setup code here, to run once:
  duinotech595.init();
}

void loop() {
  // put your main code here, to run repeatedly:
  for (int i = 0; i < sizeof(pairArray); i++) {
    duinotech595.updateShiftRegister(pairArray[i]);
    delay(1000);
  }
}
