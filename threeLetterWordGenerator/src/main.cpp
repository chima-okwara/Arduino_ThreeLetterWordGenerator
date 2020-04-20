#include <Arduino.h>
#include <time.h>
#include <LiquidCrystal.h>
#include <Wire.h>
#include <string.h>

int count (0);                          //To count the number of correct words.

LiquidCrystal lcd (14,15,16,17,18,19);  //pins for the lcd screen

String confirmation, redo;                                   //To get feedback from user
char firstLetter, secondLetter, thirdLetter;                //the three letters of the word
char output[4];                                             //Three letter word generated.
char alphabets[] = {"aeiouybcdfghjklmnpqrstvwxz"};          //Alphabets to choose from
void confirm();                                            //Function to confirm if word exists.

/////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////********FUNCTION TO GENERATE RANDOM LETTER**********//////////////////////////
inline char generateLetter()////////////////////////////////////////////////////////
{
  int number;
  time_t sec;
  time(&sec);
    randomSeed(sec);
    number=random()%26+1;            //since there are 26 elements in the array alphabets[]/////
    return alphabets[number-1];       ///////////////////////////////////////////////////////////
}                                     //and the elements are labelled 0 to 25////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////

inline void confirm()
{
  confirmation=Serial.readString();
  if (confirmation=="y"||confirmation=="Y")
  {
    lcd.setCursor(13,1);
    lcd.print("yes");
    Serial.println("yes");
    count++;
  }

  else
  if (confirmation=="n"||confirmation=="N")
  {    // lcd.print("no");
    lcd.setCursor(13,1);
    lcd.print("no");
    Serial.println("no");
  }

  else
    Serial.println("No valid response");

  // else;
}

void setup()

{
/////////////////////////////////////////////////////////////////////////////////////////////////
///////*************BEGINNING OF SETUP ROUTINE*******************////////////////////////////////
    //Prepares the serial monitor and the lcd screen
    Serial.begin(9600);
    lcd.begin(16, 2);
    lcd.clear();
/////////////////////////////////////////////////////////////////////////////////////////////////
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
/////////////////////////////////////////////////////////////////////////////////////////////////
}

void loop()
{
  lcd.clear();

  lcd.print(output);
  lcd.setCursor(0,0);
  // Serial.print("Word: ");

  // randomSeed(random());   //Seed for Random number Generator
  // lcd.clear();
  // lcd.setCursor(0,0);
  // lcd.print("Word: ");

  delay(1000);


  firstLetter=generateLetter();
  secondLetter=generateLetter();
  thirdLetter=generateLetter();

  output[0]=firstLetter;
  output[1]=secondLetter;
  output[2]=thirdLetter;


  // lcd.print(output);
  // lcd.setCursor(0,0);
  Serial.print("Word: ");
  lcd.setCursor(6,0);
  Serial.println(output);
  delay(500);
  lcd.setCursor(0,1);
  lcd.print("Word exists?");
  Serial.println("Word exists?");
  delay(500);

  confirm();
  delay(1000);

  Serial.println("Continue?");
  redo=Serial.readString();
  delay(600);

  if (redo=="n"||redo=="N")
  {
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("Correct words:");
    lcd.setCursor(0, 1);
    lcd.print(count);
    Serial.print("Total number of correct words: ");
    Serial.println(count);
    // break;
  }

  else;
}
