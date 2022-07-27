///************ Arduino-based three-letter Word generator*****************************/////////
///Written by Chimaroke R. Okwara**************************************************
///Makes use of xlwg library version 1.0 by The Eichen Group
///Tested on Arduino Uno. Written using PlatformIO********************************************
///*******************************************************************************************
///////////////////////////////////////////////////////////////////////////////////////////////

#include <Arduino.h>
#include <LiquidCrystal.h>
#include <Wire.h>
#include <xlwg.hpp>
#include <pincontrol.hpp>
// #include "functions.h"

void setup();
void loop();
bool confirm(inputPin &yes, inputPin &no);

inputPin yesButton(2), noButton(3);

LiquidCrystal lcd (7,8,9,10,11,12);                      //pins for the lcd screen.

Generator gen(3);                                        //Three-letter word generator.

void setup()
{
    ///////*************BEGINNING OF SETUP ROUTINE*******************///////
        //Prepares the lcd screen
    lcd.begin(16, 2);
    lcd.clear();

    //print welcome message onto the lcd screen:
    lcd.setCursor(0, 0);
    lcd.print("***Eichen (R)***");
    DELAY(1000);
    lcd.setCursor(0, 1);
    lcd.print("Three Letter Word Generator");
    DELAY(500);
    yesButton.write(1); noButton.write(1);

    for (size_t i=0; i<11; ++i)  //To scroll the second part of the welcome message.
    {
      lcd.scrollDisplayLeft();
      DELAY(500);
    }

    lcd.clear();


    /////////////////****************END OF SETUP ROUTINE****************///////
}

void loop()
{
  lcd.clear();
  DELAY(250);
  lcd.setCursor(0, 0);

  //Generate a word:
  gen.generateWord();



  //Print the word generated to LCD screen:
  lcd.setCursor(0, 0);
  lcd.print(gen.getWord());

  //To confirm whether the generated word exists.
  DELAY(500);
  lcd.setCursor(0,1);
  lcd.print("Word Exists? Y/N");

  if (confirm(yesButton, noButton))      //If the generated word exists...
  {
      lcd.clear();
      lcd.setCursor(0, 0);       //...and print "Yes" to the LCD...
      lcd.print("Yes");
      DELAY(700);
      lcd.clear();
      gen.storeWord();            //...then store the word.
      lcd.clear();
      DELAY(250);
  }

  else                            //If the word doesn't exist...
  {
      lcd.clear();
      lcd.setCursor(0, 0);       //...print "No" to the LCD...
      lcd.print("No");
      DELAY(700);
      lcd.clear();
      DELAY(250);
  }

  delay(500);

  //Whether to continue generating words or not:
  lcd.clear();
  DELAY(250);
  lcd.setCursor(0, 0);
  lcd.print("Continue? Y/N");

  DELAY(500);

  if (!confirm(yesButton, noButton))    //If user wants to stop generating words...
  {
      lcd.setCursor(0,1);
      lcd.print("No");
      DELAY(700);
      lcd.clear();
      DELAY(250);
      lcd.setCursor(0, 0);
      lcd.print("Correct words: ");//...print the total number of correct words to the LCD...
      lcd.setCursor(0, 1);
      lcd.print(gen.getCorrectWordCount());
      for(uint i = 0; i>gen.getCorrectWordCount(); ++i)
      {
        //TODO: Add function to print each word one after the other
      }
  }

  else
  {
      lcd.setCursor(0,1);
      lcd.print("Yes");
      DELAY(700);
  }
}

bool confirm(inputPin &yes, inputPin &no)
{
  while((yes.read() == 1) && (no.read() == 1))
    ;
  return ( (yes.read() == LOW) && (no.read() == 1) ? true : false );
}
