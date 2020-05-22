#include <Arduino.h>
#include <time.h>
#include <LiquidCrystal.h>
#include <Wire.h>
#include <string.h>

LiquidCrystal lcd (14,15,16,17,18,19);                      //pins for the lcd screen

String confirmation, redo;                                   //To get feedback from user
char firstLetter, secondLetter, thirdLetter;                //the three letters of the Word
char Word[4];                                             //Three letter Word generated.
char alphabets[] = {"aeiouybcdfghjklmnpqrstvwxz"};          //Alphabets to choose from
int count (0);


inline char generateLetter()          //Function to generate a random character
{
  time_t sec;
  time(&sec);
    randomSeed(sec);
    return alphabets[random()%25];      //Generate a random number between 0 and 25
                                              //since the elements in alphabets[] are labelled 0 to 25
}


inline void confirm()                       //Function to confirm if Word exists
{
  confirmation=Serial.readString();         //Reads a string from the serial monitor

  if (confirmation=="y"||confirmation=="Y")
  {
    lcd.setCursor(13,1);
    // lcd.print("yes");
    // Serial.println("yes");
    count++;
  }

  else
  if (confirmation=="n"||confirmation=="N")
  {    // lcd.print("no");
    lcd.setCursor(13,1);
    lcd.print("no");
    // Serial.println("no");
  }

  else

  {
    // Serial.println("No valid response");
    lcd.setCursor (0,1);
    lcd.print("Invalid Response");
  }

}
