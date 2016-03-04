#include <duinotech595.h>


const byte LATCH_PIN = 6;
const byte CLOCK_PIN = 5;
const byte DATA_PIN  = 4;

Duinotech595 duinotech595(LATCH_PIN, DATA_PIN, CLOCK_PIN);

byte allArray[]  = {LED_ALL_GREEN,
                    LED_ALL_RED,
                    LED_ALL_BLUE,
                    LED_ALL_WHITE,
                   };


void setup() {
  // put your setup code here, to run once:
  duinotech595.init();
}

void loop() {
  // put your main code here, to run repeatedly:
  duinotech595.off();
  delay(1000);
  for (int i = 0; i < sizeof(allArray); i++) {
    duinotech595.updateShiftRegister(allArray[i]);
    delay(1000);
  }
}
