#ifndef __DUINOTECH595_H__
#define __DUINOTECH595_H__


#if defined(ARDUINO) && ARDUINO >= 100
#include "Arduino.h"
#else
#include "WProgram.h"
#endif


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

void setPins();
void updateShiftRegister(byte byteToSet);

#endif  /* __DUINOTECH595_H__ */
