/****   File: /include/functons.h                                       **************
*****   Description: Contains definitions of functions for project      **************
*****                                                                   *************/

#include <Arduino.h>
#include <stdlib.h>
#ifndef __FUNCTION__H__
#define __FUNCTION__H__

#define DELAY(x) _delay_ms(x)                               //Macro for delay function

//  VARIABLES:

extern const char *alphabets,                                //Alphabets to choose from
            *vowels;                                   //List of vowels

extern String confirmation, redo;


extern uint8_t count;                                   //To count number of correct words.


//  METHODS:

bool  checkVowel(const char *str, const char *attributes);        //Checks str for attributes:

void setup();
void loop();
bool isConfirm();
inline bool confirm (String &confirm)                           //To check if the letter exists.
{
  return ((confirm=="y")||(confirm=="Y"));
}

#endif
