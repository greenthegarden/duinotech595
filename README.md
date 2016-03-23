# duinotech 595 Library

Library to support the [duinotech 595](http://www.jaycar.com.au/Kits%2C-Science-%26-Learning/Science-Lab-Equipment/Instruments/Arduino-Compatible-4-x-5050-RGB-LED-Module/p/XC4466) which is a module containing 4 [5050 LED](https://en.wikipedia.org/wiki/SMD_LED_Module)s controlled by a [74HC595 shift register](https://www.nxp.com/documents/data_sheet/74HC_HCT595.pdf). The library is based on the example at https://www.arduino.cc/en/Tutorial/ShftOut13.

The tri-colour 5050 LEDs on the module are connected to the 74HC595 shift register in two pairs. The library defines the byte codes for each primary LED colour for each pair as:

```
const byte LED_PAIR_1_GREEN = 0b00000010;
const byte LED_PAIR_1_RED   = 0b00000100;
const byte LED_PAIR_1_BLUE  = 0b00001000;
const byte LED_PAIR_2_GREEN = 0b00010000;
const byte LED_PAIR_2_RED   = 0b00100000;
const byte LED_PAIR_2_BLUE  = 0b01000000;
```

The byte codes for the primary colours can then be combined to provide different combinations of colours. 

Definitions for two colour combinations are provided as:

```
const byte LED_PAIR_1_GREENRED  = LED_PAIR_1_GREEN + LED_PAIR_1_RED;
const byte LED_PAIR_2_GREENRED  = LED_PAIR_2_GREEN + LED_PAIR_2_RED;

const byte LED_PAIR_1_REDBLUE   = LED_PAIR_1_RED   + LED_PAIR_1_BLUE;
const byte LED_PAIR_2_REDBLUE   = LED_PAIR_2_RED   + LED_PAIR_2_BLUE;

const byte LED_PAIR_1_GREENBLUE = LED_PAIR_1_GREEN + LED_PAIR_1_BLUE;
const byte LED_PAIR_2_GREENBLUE = LED_PAIR_2_GREEN + LED_PAIR_2_BLUE;
```

In addition, definitions for white (all colours combined) are provided as:

```
const byte LED_PAIR_1_WHITE = LED_PAIR_1_GREEN + LED_PAIR_1_RED + LED_PAIR_1_BLUE;
const byte LED_PAIR_2_WHITE = LED_PAIR_2_GREEN + LED_PAIR_2_RED + LED_PAIR_2_BLUE;
```

Additional definitions for all LEDs (both pairs) are provided as:

```
const byte LED_ALL_GREEN     = LED_PAIR_1_GREEN     + LED_PAIR_2_GREEN;
const byte LED_ALL_RED       = LED_PAIR_1_RED       + LED_PAIR_2_RED;
const byte LED_ALL_BLUE      = LED_PAIR_1_BLUE      + LED_PAIR_2_BLUE;
const byte LED_ALL_GREENRED  = LED_PAIR_1_GREENRED  + LED_PAIR_2_GREENRED;
const byte LED_ALL_REDBLUE   = LED_PAIR_1_REDBLUE   + LED_PAIR_2_REDBLUE;
const byte LED_ALL_GREENBLUE = LED_PAIR_1_GREENBLUE + LED_PAIR_2_GREENBLUE;
const byte LED_ALL_WHITE     = LED_PAIR_1_WHITE     + LED_PAIR_2_WHITE;
```

The configuration of the pins is defined within the libray as

```
int LATCH_PIN = 6;
int CLOCK_PIN = 5;
int DATA_PIN  = 4;
```

