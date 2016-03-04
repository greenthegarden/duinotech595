#include <duinotech595.h>


const byte LATCH_PIN = 6;
const byte CLOCK_PIN = 5;
const byte DATA_PIN  = 4;

Duinotech595 duinotech595(LATCH_PIN, DATA_PIN, CLOCK_PIN);

byte pairArray[] = {LED_PAIR_1_GREEN,
                    LED_PAIR_1_RED,
                    LED_PAIR_1_BLUE,
                    LED_PAIR_2_GREEN,
                    LED_PAIR_2_RED,
                    LED_PAIR_2_BLUE,
                    };


void setup() {
  // put your setup code here, to run once:
  duinotech595.init();
}

void loop() {
  // put your main code here, to run repeatedly:
  duinotech595.off();
  delay(1000);
  for (int i = 0; i < sizeof(pairArray); i++) {
    duinotech595.updateShiftRegister(pairArray[i]);
    delay(1000);
  }
}
