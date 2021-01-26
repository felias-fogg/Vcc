
#ifndef VCC_H
#define VCC_H

#include <Arduino.h>
#include <avr/eeprom.h>

#define INTREF_AT_END_OF_EEPROM

#if defined(INTREF_AT_END_OF_EEPROM)
#define EE_INTREF (E2END-1)
#else
#define EE_INTREF 0
#endif

class Vcc {
 public:
  static int measure(int repetition=10);
  static int measure(int repetition, int intref);
};
#endif
