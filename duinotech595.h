#ifndef DUINOTECH595_H_
#define DUINOTECH595_H_


#if defined(ARDUINO) && ARDUINO >= 100
#include "Arduino.h"
#else
#include "WProgram.h"
#endif


const byte LED_PAIR_1_OFF   = 0b00000000;
const byte LED_PAIR_1_GREEN = 0b00000010;
const byte LED_PAIR_1_RED   = 0b00000100;
const byte LED_PAIR_1_BLUE  = 0b00001000;
const byte LED_PAIR_2_OFF   = 0b10000000;
const byte LED_PAIR_2_GREEN = 0b00010000;
const byte LED_PAIR_2_RED   = 0b00100000;
const byte LED_PAIR_2_BLUE  = 0b01000000;

const byte LED_PAIR_1_WHITE = LED_PAIR_1_GREEN + LED_PAIR_1_RED + LED_PAIR_1_BLUE;
const byte LED_PAIR_2_WHITE = LED_PAIR_2_GREEN + LED_PAIR_2_RED + LED_PAIR_2_BLUE;

const byte LED_ALL_OFF      = LED_PAIR_1_OFF   + LED_PAIR_2_OFF;
const byte LED_ALL_GREEN    = LED_PAIR_1_GREEN + LED_PAIR_2_GREEN;
const byte LED_ALL_RED      = LED_PAIR_1_RED   + LED_PAIR_2_RED;
const byte LED_ALL_BLUE     = LED_PAIR_1_BLUE  + LED_PAIR_2_BLUE;
const byte LED_ALL_WHITE    = LED_PAIR_1_WHITE + LED_PAIR_2_WHITE;


class Duinotech595
{
public:
//  Duinotech595();
  Duinotech595(byte latchPin, byte dataPin, byte clockPin);
private:
  byte _latchPin;
  byte _dataPin;
  byte _clockPin;
public:
  void init();
  void updateShiftRegister(byte byteToSet);
  void off();
  void green();
  void red();
  void blue();
  void white();
  void on();
};


#endif  /* DUINOTECH595_H_ */
