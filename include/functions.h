/****   File: /include/functons.h                                       **************
*****   Description: Contains definitions of functions for project      **************
*****                                                                   *************/

#ifndef __FUNCTION__H__
#define __FUNCTION__H__

#include <Arduino.h>
#include <LiquidCrystal.h>
#include <Wire.h>
#include <string.h>

#define DELAY(x) _delay_ms(x)

typedef unsigned char uchar;

LiquidCrystal lcd (14,15,16,17,18,19);                      //pins for the lcd screen

//  VARIABLES:

char alphabets[] = { "abcdefghijklmnopqrstuvwxyz" },          //Alphabets to choose from
     vowels[] = {"aeiou" },                                   //List of vowels
     *vowelCheck = NULL;

short count (0);                                              //To count number of correct words.


//  METHODS:
inline uchar generateLetter(short& random)                  //To generate a random letter.
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

short getRandom()                                           //To generate a random number.
{
    randomSeed(2000);
    return ( static_cast <short> (random()%25) );
}


#endif
