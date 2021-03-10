#include <Arduino.h>
#include <time.h>
#include <avr/io.h>
#include "generator.h"

const char Generator::alphabets[27] = "abcdefghijklmnopqrstuvwxyz";
const char Generator::vowels[7] = "aeiouy";


char Generator::generateLetter(void)  //Generates a single letter from the alphabet
{
  randomSeed(100ul);
  uint8_t letter = rand()%26;
  return (alphabets[letter]);
}

bool Generator::checkVowel(const char str[], const char attributes[]) //Checks for vowel in word.
{

  static bool  position=false;
  uint8_t i = 0;
  while (attributes[i] != '\0')
  {
    uint8_t j = 0;
    while (str[j] != '\0')
    {
      if ((*str)==(*attributes))
      {
        position=true;
        break;
      }

      else
        ++j;
    }

    ++i;
  }

  return (position);
}


void Generator::generateWord(void) //Generates a three letter word
{
  auto hasVowel = false;
  while (hasVowel == false)   //If no vowel exists in the generated word...
  {
    for (size_t i = 0; i<3; ++i)
      word[i] = generateLetter();
    word[4] = '\0';
  }                           //...regenerate word.

  hasVowel = checkVowel(word, vowels);
}

void Generator::storeWord()
{
  correctWordBuffer[correctWordCount++] = word;
}
