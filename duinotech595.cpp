#if defined(ARDUINO) && ARDUINO >= 100
#include "Arduino.h"
#else
#include "WProgram.h"
#endif


#include "duinotech595.h"


Duinotech595::Duinotech595(byte latchPin, byte dataPin, byte clockPin)
//Duinotech595::Duinotech595(byte latchPin, byte dataPin, byte clockPin)
  : _latchPin(latchPin), _dataPin(dataPin), _clockPin(clockPin)
{}

void Duinotech595::init() {
  pinMode(this->_latchPin, OUTPUT);
  pinMode(this->_dataPin,  OUTPUT);
  pinMode(this->_clockPin, OUTPUT);
}

void Duinotech595::updateShiftRegister(byte byteToSet) {
  //ground latchPin and hold low for as long as you are transmitting
  digitalWrite(this->_latchPin, LOW);
  shiftOut(this->_dataPin, this->_clockPin, LSBFIRST, byteToSet);
  //return the latch pin high to signal chip that it
  //no longer needs to listen for information
  digitalWrite(this->_latchPin, HIGH);
}

void Duinotech595::off() {
  this->updateShiftRegister(LED_ALL_OFF);
}

void Duinotech595::green() {
  this->updateShiftRegister(LED_ALL_GREEN);
}

void Duinotech595::red() {
  this->updateShiftRegister(LED_ALL_RED);
}

void Duinotech595::blue() {
  this->updateShiftRegister(LED_ALL_BLUE);
}

void Duinotech595::greenred() {
  this->updateShiftRegister(LED_ALL_GREENRED);
}

void Duinotech595::redblue() {
  this->updateShiftRegister(LED_ALL_REDBLUE);
}

void Duinotech595::greenblue() {
  this->updateShiftRegister(LED_ALL_GREENBLUE);
}

void Duinotech595::white() {
  this->updateShiftRegister(LED_ALL_WHITE);
}

void Duinotech595::on() {
  this->white();
}

void Duinotech595::sequenceTest() {
  for (int i = 0; i < sizeof(sequenceArray); i++) {
    this->updateShiftRegister(sequenceArray[i]);
    delay(1000);
    this->off();
    delay(500);
  }
}

void Duinotech595::blinkOk(unsigned int count, unsigned int onDelay, unsigned int offDelay) {
  for (int i=0; i<count; i++) {
    this->green();
    delay(onDelay);
    this->off();
    delay(offDelay);
  }
}

void Duinotech595::blinkError(unsigned int count, unsigned int onDelay, unsigned int offDelay) {
  for (int i=0; i<count; i++) {
    this->red();
    delay(onDelay);
    this->off();
    delay(offDelay);
  }
}

void Duinotech595::flashOk(unsigned int count, unsigned int onDelay) {
  for (int i=0; i<count; i++) {
    this->updateShiftRegister(LED_PAIR_1_GREEN);
    delay(onDelay);
    this->updateShiftRegister(LED_PAIR_2_GREEN);
    delay(onDelay);
  }
}

void Duinotech595::flashError(unsigned int count, unsigned int onDelay) {
  for (int i=0; i<count; i++) {
    this->updateShiftRegister(LED_PAIR_1_RED);
    delay(onDelay);
    this->updateShiftRegister(LED_PAIR_2_RED);
    delay(onDelay);
  }
}
