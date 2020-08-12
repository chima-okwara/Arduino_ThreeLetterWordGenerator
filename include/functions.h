/****   File: /include/functons.h                                       **************
*****   Description: Contains definitions of functions for project      **************
*****                                                                   *************/

#include <Arduino.h>
#ifndef __FUNCTION__H__
#define __FUNCTION__H__

#define DELAY(x) _delay_ms(x)                               //Macro for delay function

//  VARIABLES:

char alphabets[] = { "abcdefghijklmnopqrstuvwxyz" },          //Alphabets to choose from
     vowels[] = {"aeiou" };                                   //List of vowels


uint8_t count (0);                                              //To count number of correct words.


//  METHODS:

uint8_t &getRandom();                                    //To generate a random number.

bool  checkVowel(char *str, char *attributes);          //Checks str for attributes:

inline bool confirm (String &confirm)                   //To check if the letter exists.
{
  return ((confirm=="y")||(confirm=="Y"));
}

inline char generateLetter(uint8_t &random)              //To generate a random letter.
{
  return alphabets[random];
}


#endif
