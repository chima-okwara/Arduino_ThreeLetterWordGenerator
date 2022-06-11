///************ Arduino-based three-letter Word generator*****************************/////////
///Written by Chimaroke R. Okwara (AlphaChi)**************************************************
///Copyright (c) 03 Apr., 2020; The Eichen Group(TM)******************************************
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
inputPin yesButton(15), noButton(16);

LiquidCrystal lcd (7,8,9,10,11,12);                      //pins for the lcd screen.
Generator gen(3);                                        //Three-letter word generator.

bool confirm(inputPin &yes, inputPin &no)
{
  return ( (yesButton.read() == HIGH) && (noButton.read() == LOW) ? true : false );
}

void setup()
{
    ///////*************BEGINNING OF SETUP ROUTINE*******************///////
        //Prepares the lcd screen
    Serial.begin(9600);
    lcd.begin(16, 2);
    lcd.clear();

    //print welcome message onto the lcd screen:
    lcd.setCursor(0, 0);
    lcd.print("***Eichen (R)***");
    DELAY(1000);
    lcd.setCursor(0, 1);
    lcd.print("Three Letter Word Generator");
    DELAY(500);
    Serial.println("Done");

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
        DELAY(200);
        lcd.setCursor(0, 0);
        lcd.print("Word: ");
        Serial.print("Word: ");

      //Generate a word:
       gen.generateWord();


        //Print the word generated to LCD screen:
        lcd.setCursor(6, 0);
        lcd.print(gen.getWord());
        Serial.println(gen.getWord());


        //To confirm whether the generated word exists.
        DELAY(500);
        lcd.setCursor(1,0);
        lcd.print("Word Exists? Y/N");
        Serial.println("Word Exists? Y/N");


      if (confirm(yesButton, noButton))      //If the generated word exists...
        {
            lcd.setCursor(13, 1);       //...and print "Yes" to the LCD...
            lcd.print("Yes");
            lcd.clear();
            Serial.println("Yes");      //...and the Serial monitor...
            gen.storeWord();            //...then store the word.
        }

        else                            //If the word doesn't exist...
        {
            lcd.setCursor(13, 1);       //...print "No" to the LCD...
            lcd.print("No");
            lcd.clear();
            Serial.println("No");
        }

        DELAY(500);


        //Whether to continue generating words or not:
        lcd.clear();
        lcd.setCursor(0, 0);
        lcd.print("Continue? Y/N");
        Serial.println("Continue? Y/N");

        DELAY(500);

        if (!confirm(yesButton, noButton))    //If user wants to stop generating words...
        {
            lcd.setCursor(0,1);
            lcd.print("No");
            Serial.println("No");
            DELAY(500);
            lcd.clear();
            lcd.setCursor(0, 0);
            lcd.print("Correct words: ");//...print the total number of correct words to the LCD...
            lcd.setCursor(0, 1);
            lcd.print(gen.getWordCount());
            Serial.print("Total number of correct words: ");
            Serial.println(gen.getWordCount());              //...and serial monitor.
            Serial.println("List of Correct words: ");
            for(int i = 0; i>gen.getWordCount(); ++i)
              Serial.println(gen.getWord(i));
        }

        else
        {
            lcd.setCursor(0,1);
            lcd.print("Yes");
            Serial.println("Yes");
            DELAY(500);
        }
}
