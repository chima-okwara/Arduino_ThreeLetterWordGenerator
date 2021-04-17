///************ Arduino-based three-letter Word generator*****************************/////////
///Written by Chimaroke R. Okwara**************************************************
///Makes use of xlwg library version 0.70 by The Eichen Group
///Tested on Arduino Uno. Written using PlatformIO********************************************
///*******************************************************************************************
///////////////////////////////////////////////////////////////////////////////////////////////

#include <Arduino.h>
#include <LiquidCrystal.h>
#include <Wire.h>
#include "xlwg.hpp"
#include "functions.hpp"

uint8_t yesButton = 5, noButton = 6;                   //Connections for pushbuttons

LiquidCrystal lcd (7,8,9,10,11,12);                      //Pins for the lcd screen.
Generator gen(3);                                        //Three-letter word generator.

void setup()
{
  ///////*************BEGINNING OF SETUP ROUTINE*******************///////
  //Sets mode for pins 5 and 6
  pinMode(yesButton, INPUT);
  pinMode(noButton, INPUT);

  //Prepares the lcd screen
  lcd.begin(16, 2);
  lcd.clear();

  //print welcome message onto the lcd screen:
  lcd.setCursor(0, 0);
  lcd.print("***Eichen (R)***");
  delay(1000);
  lcd.setCursor(0, 1);
  lcd.print("Three Letter Word Generator");
  delay(500);
  Serial.println("Done");

  for (size_t i=0; i<11; ++i)  //To scroll the second part of the welcome message.
  {
    lcd.scrollDisplayLeft();
    delay(500);
  }

  lcd.clear();


  /////////////////****************END OF SETUP ROUTINE****************///////
}

void loop()
{
  delay(200);
  lcd.setCursor(0, 0);
  lcd.print("Word: ");

  //Generate a word:
  gen.generateWord();


  //Print the word generated to LCD screen:
  lcd.setCursor(6, 0);
  lcd.print(gen.getWord());


  //To confirm whether the generated word exists.
  delay(500);
  lcd.setCursor(1,0);
  lcd.print("Word Exists? Y/N");


  if (confirm(yesButton, noButton, HIGH))      //If the generated word exists...
  {
      lcd.setCursor(13, 1);       //...print "Yes" to the LCD...
      gen.verifyWord(HIGH); gen.storeWord();
      lcd.print("Yes");
      lcd.clear();
  }

  else                            //If the word doesn't exist...
  {
      lcd.setCursor(13, 1);       //...print "No" to the LCD...
      lcd.print("No");
      lcd.clear();
      while(1)
        ;
  }

  delay(500);


  //Whether to continue generating words or not:
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("Continue? Y/N");

  delay(500);

  if (!confirm(yesButton, noButton, LOW))    //If user wants to stop generating words...
  {
      lcd.setCursor(0,1);
      lcd.print("No");
      delay(500);
      lcd.clear();
      lcd.setCursor(0, 0);
      lcd.print("Correct words: ");//...print the total number of correct words to the LCD...
      lcd.setCursor(0, 1);
      lcd.print(gen.getWordCount());
      while (1);
  }

  else
  {
      lcd.setCursor(0,1);
      lcd.print("Yes");
      delay(500);
  }
}
