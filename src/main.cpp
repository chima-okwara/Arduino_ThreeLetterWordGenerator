///************ Arduino-based three-letter Word generator*****************************/////////
///Written by Chimaroke R. Okwara (AlphaChi)**************************************************
///Copyright (c) 03 Apr., 2020; The Eichen Group(TM)******************************************
///Tested on Arduino Uno. Written using PlatformIO********************************************
///All rights reserved************************************************************************
///All methods used are defined in /include/functions.h***************************************
///*******************************************************************************************
///////////////////////////////////////////////////////////////////////////////////////////////

#include <Arduino.h>
#include "functions.h"

String confirmation{},                                   //To confirm that word exists
       redo{"y"};                                        //To continue generating words.

char Word[4];                                        //To hold the three-letter word.

int main()
{
    ///////*************BEGINNING OF SETUP ROUTINE*******************///////
        //Prepares the serial monitor and the lcd screen

    Serial.begin(9600);
    lcd.begin(16, 2);
    lcd.clear();
    randomSeed(20000L);

    //print welcome message onto the lcd screen:
    lcd.setCursor(0, 0);
    lcd.print("***Eichen (R)***");
    DELAY(1000);
    lcd.setCursor(0, 1);
    lcd.print("Three Letter Word Generator");
    DELAY(500);

    for (size_t i=0; i<11; ++i)  //To scroll the second part of the welcome message.
    {
      lcd.scrollDisplayLeft();
      DELAY(500);
    }

    lcd.clear();


    /////////////////****************END OF SETUP ROUTINE****************///////

    while(1)
    {
        DELAY(200);
        lcd.setCursor(0, 0);
        lcd.print("Word: ");

       do                                 //Generate new letters until at least one is a vowel
        {
          for (uint8_t i{}; i<3; ++i)          //Loop to generate the three letters of the word.
          {
              uint8_t random = getRandom();
              Word[i] = generateLetter(random);
              DELAY(100);
          }

          Word[3] = '\0';

        }  while (!checkVowel(Word, vowels));


        //To print the word Generated:
        lcd.setCursor(6, 0);
        lcd.print(Word);
        Serial.println(Word);


        //To confirm whether the generated word exists.
        DELAY(500);
        lcd.setCursor(1,0);
        lcd.print("Word Exists? Y/N");
        Serial.println("Word Exists? Y/N");

        DELAY(1000);
        confirmation=Serial.readString();
        if (confirm(confirmation))      //If the generated word exists...
        {
            ++count;                    //...add it to the count of corrected words...
            lcd.setCursor(13, 1);       //...and print "Yes" to the LCD...
            lcd.print("Yes");
            lcd.clear();
            Serial.println("Yes");      //...and the Serial monitor.
        }

        else                            //If the word doesn't exist...
        {
            lcd.setCursor(13, 1);       //...print "No" to the LCD...
            lcd.print("No");
            lcd.clear();
            Serial.println("No");       //...and the serial monitor.
        }

        DELAY(500);


        //Whether to continue generating words or not:
        lcd.clear();
        lcd.setCursor(0, 0);
        lcd.print("Continue? Y/N");
        Serial.print("Continue? Y/N");

        DELAY(500);
        redo=Serial.readString();


        if ((redo == "n") || (redo == "N"))    //If user wants to stop generating words...
        {
            lcd.setCursor(0,1);
            lcd.print("No");
            DELAY(500);
            lcd.clear();
            lcd.setCursor(0, 0);
            lcd.print("Correct words: ");     //...print the total number of correct words to the LCD...
            lcd.setCursor(0, 1);
            lcd.print(count);
            Serial.print("Total number of correct words: ");
            Serial.print(count);              //...and serial monitor.
            count=0;
            // Serial.readString();        //*************To pause the game until enter is pressed
            break;
        }

        else if ((redo == "y") || (redo == "Y"))
        {
            lcd.setCursor(0,1);
            lcd.print("Yes");
            Serial.println("Yes");
            DELAY(500);
        }

        else
        {
            lcd.setCursor(0,1);
            lcd.print("Invalid input");
            Serial.println("Invalid input");
        }
    }
}
