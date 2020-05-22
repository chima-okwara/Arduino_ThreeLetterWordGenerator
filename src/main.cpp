///************ Arduino-based three-letter Word generator*****************************/////////
///Written by Chimaroke R. Okwara (AlphaChi)***************************************************
///Copyright (c) 03 Apr., 2020; Eichen(R) Technologies*****************************************
///Tested on Arduino Uno. Written using PlatformIO*********************************************
///All rights reserved*************************************************************************
///Modifications to be done:      **************************************************///////////
///*Improve the code so  that at least one of the letters must always be a vowel**************
///*******************************************************************************************
//////////////////////////////////////////////////////////////////////////////////////////////

#include <Arduino.h>
#include <time.h>
#include <LiquidCrystal.h>
#include <Wire.h>
#include <string.h>
#include "functions.h"



void setup()

{
///////*************BEGINNING OF SETUP ROUTINE*******************////////////////////////////////
    //Prepares the serial monitor and the lcd screen
    // Serial.begin(9600);
    lcd.begin(16, 2);
    lcd.clear();

    //print welcome message onto the lcd screen:
    lcd.setCursor(3, 0);
    lcd.print("Eichen(R)");
    delay(1000);
    lcd.setCursor(0, 1);
    lcd.print("Three Letter Word Generator");
    delay(500);

    for (int i (0); i<11; ++i)  //To scroll the second part of the welcome message.
    {
      lcd.scrollDisplayLeft();
      delay(500);
    }

    lcd.clear();
/////////////////****************END OF SETUP ROUTINE****************////////////////////////////
}

void loop()
{
  lcd.clear();

  lcd.setCursor(0,0);
  lcd.print("Word: ");
  lcd.setCursor(6,0);
  lcd.print(Word);

  delay(1000);

//Generate three random letters
  firstLetter=generateLetter();
  secondLetter=generateLetter();
  thirdLetter=generateLetter();

//Assign the random letters to the Word
  Word[0]=firstLetter;
  Word[1]=secondLetter;
  Word[2]=thirdLetter;


  lcd.setCursor(6,0);
  lcd.print(Word);
  // Serial.print("Word: ");
  // lcd.setCursor(0,0);
  // Serial.println(Word);
  delay(1000);
  lcd.setCursor(0,1);
  lcd.print("Word exists?");
  // Serial.println("Word exists?");
  delay(1000);

  confirm();
  delay(1000);

  // Serial.println("Continue?");
  redo=Serial.readString();
  delay(1000);

  if (redo=="n"||redo=="N")
  {
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("Correct Words:");
    lcd.setCursor(0, 1);
    lcd.print(count);
    // Serial.print("Total number of correct Words: ");
    // Serial.println(count);
    // break;
  }

  else;
}
