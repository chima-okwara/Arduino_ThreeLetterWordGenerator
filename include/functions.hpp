#include <Arduino.h>
#include <pincontrol.hpp>

//Arduino functions:
void setup();
void loop();

//Other functions:
inline bool confirm(inputPin &yesButton, inputPin &noButton, uint8_t state)
{
  while(!yesButton.read() && !noButton.read())
  {

  }
  return ( (yesButton.read() == state) && (noButton.read() != state) ? true : false ); }
