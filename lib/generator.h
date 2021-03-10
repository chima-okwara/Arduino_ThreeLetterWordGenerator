#include <Arduino.h>
#include <time.h>

#ifndef GENERATOR_H
#define GENERATOR_H


class Generator
{
private:
  Generator() { }   //TODO: make constructor perform some tasks.
  const static char alphabets[27];
  const static char vowels[7];
  static char word[4];
  static int correctWordCount;
  char *correctWordBuffer[15] {};

  char generateLetter();
  bool checkVowel(const char str[], const char attributes[]);

public:
  void generateWord();
  bool verifyWord(int yesValue) { return (yesValue == HIGH ? true:false); }
  void storeWord();     //TODO: Implement the method such that it makes use of the buffer


  char *getWord() { return (word); }
};


#endif
