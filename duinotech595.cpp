#include "duinotech595.h"

void setPins() {
  pinMode(LATCH_PIN, OUTPUT);
  pinMode(DATA_PIN,  OUTPUT);
  pinMode(CLOCK_PIN, OUTPUT);
}

void updateShiftRegister(byte byteToSet) {
  //ground latchPin and hold low for as long as you are transmitting
  digitalWrite(LATCH_PIN, LOW);
  shiftOut(DATA_PIN, CLOCK_PIN, LSBFIRST, byteToSet);
  //return the latch pin high to signal chip that it
  //no longer needs to listen for information
  digitalWrite(LATCH_PIN, HIGH);
}
