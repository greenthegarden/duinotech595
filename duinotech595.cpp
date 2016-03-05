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
