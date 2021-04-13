////////////////////////////////////////////////////////////////////////////////////////////////////
//*FILE NAME:       xlwg.hpp
//*FILE DESC:       Header files for xlwg library.
//*FILE AUTHOR:     The Eichen Group
//*CONTRIBUTORS:    Chimaroke Okwara
//*LAST MODIFIED:   Tuesday, 13 April 2021 09:16
////////////////////////////////////////////////////////////////////////////////////////////////////
#ifndef GENERATOR_HPP
#define GENERATOR_HPP
#include <stdlib.h>
#include "xlwgDefinitions.hpp"
#define BINLENGTH 100                 //This value is to be changed as suits the application


#define GENERATOR_HPP

class Generator
{
private:
  const int8_t letterCount;
  const static char *const alphabets;
  const static char vowels[7];
  char *word;                     //TODO: Reimplement using a smart pointer or a vector container.
  bool wordExists {false};


  int correctWordCount;
  const char *wordBin[BINLENGTH];

  char generateLetter(void);

public:
  Generator(const uint8_t &xLetters);
  char getAlphabet(uint8_t index) { return *(alphabets+index); }
  void generateWord();
  void verifyWord(bool state);
  void storeWord();


  const char *getWord() const { return (word); }

  const char *getWord(uint8_t index) const { return wordBin[index]; }
};


#endif
