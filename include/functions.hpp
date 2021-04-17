#include <Arduino.h>

//Arduino functions:
void setup();
void loop();

//Other functions:
inline bool confirm(uint8_t yesButton, uint8_t noButton, uint8_t state)
{ return ( (digitalRead(yesButton) == state) && (digitalRead(noButton) != state) ? true : false ); }
