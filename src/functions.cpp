#include <Arduino.h>
#include <functions.hpp>

bool confirm(uint8_t yes, uint8_t no, uint8_t state)
{
  return ( (digitalRead(yes) == state) && (digitalRead(no) != state) ? true : false );
}
