/****   File: /include/functons.h                                       **************
*****   Description: Contains definitions of functions for project      **************
*****                                                                   *************/

#ifndef __FUNCTION__H__
#define __FUNCTION__H__

#include <Arduino.h>
#include <LiquidCrystal.h>
#include <Wire.h>
#include <string.h>
#include <avr/io.h>

#define DELAY(x) _delay_ms(x)                               //Macro for delay function

LiquidCrystal lcd (14,15,16,17,18,19);                      //pins for the lcd screen

//  VARIABLES:

char alphabets[] = { "abcdefghijklmnopqrstuvwxyz" },          //Alphabets to choose from
     vowels[] = {"aeiou" },                                   //List of vowels
     *vowelCheck = NULL;

uint8_t count (0);                                              //To count number of correct words.


//  METHODS:
inline char generateLetter(uint8_t &random)                  //To generate a random letter.
{
  return alphabets[random];
}

inline bool confirm (String &confirm)                        //To check if the letter exists.
{
  if (confirm == "y" || confirm == "Y")
      return (true);
  else
      return (false);
}


bool  checkVowel(char * str, char * attributes)              //Checks str for attributes:
{
  bool  position=false;
  while ((*attributes)!='\0')
  {
    while ((*str)!='\0')
    {
      if ((*str)==(*attributes))
      {
        position=true;
        break;
      }

      else
        ++str;
    }

    if (position==false)
      break;
    else
      ++attributes;
  }

  return (position);
}


uint8_t getRandom()                                           //To generate a random number.
{
  static uint8_t number = uint8_t (random()%25);
  return (number);
}


#endif
