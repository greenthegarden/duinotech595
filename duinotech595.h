#ifndef __DUINOTECH595_H__
#define __DUINOTECH595_H__


#if defined(ARDUINO) && ARDUINO >= 100
#include "Arduino.h"
#else
#include "WProgram.h"
#endif


// do not set as const to allow reconfiguration
int LATCH_PIN = 6;
int CLOCK_PIN = 5;
int DATA_PIN  = 4;


const byte LED_PAIR_1_GREEN = 0b00000010;
const byte LED_PAIR_1_RED   = 0b00000100;
const byte LED_PAIR_1_BLUE  = 0b00001000;
const byte LED_PAIR_2_GREEN = 0b00010000;
const byte LED_PAIR_2_RED   = 0b00100000;
const byte LED_PAIR_2_BLUE  = 0b01000000;

const byte LED_PAIR_1_WHITE = LED_PAIR_1_GREEN + LED_PAIR_1_RED + LED_PAIR_1_BLUE;
const byte LED_PAIR_2_WHITE = LED_PAIR_2_GREEN + LED_PAIR_2_RED + LED_PAIR_2_BLUE;

const byte LED_ALL_GREEN    = LED_PAIR_1_GREEN + LED_PAIR_2_GREEN;
const byte LED_ALL_RED      = LED_PAIR_1_RED   + LED_PAIR_2_RED;
const byte LED_ALL_BLUE     = LED_PAIR_1_BLUE  + LED_PAIR_2_BLUE;
const byte LED_ALL_WHITE    = LED_PAIR_1_WHITE + LED_PAIR_2_WHITE;

byte pairArray[] = {LED_PAIR_1_GREEN,
                    LED_PAIR_1_RED,
                    LED_PAIR_1_BLUE,
                    LED_PAIR_2_GREEN,
                    LED_PAIR_2_RED,
                    LED_PAIR_2_BLUE,
                    };

byte allArray[]  = {LED_ALL_GREEN,
                    LED_ALL_RED,
                    LED_ALL_BLUE,
                    LED_ALL_WHITE,
                   };


//void setPins();
//void updateShiftRegister(byte byteToSet);

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


#endif  /* __DUINOTECH595_H__ */
