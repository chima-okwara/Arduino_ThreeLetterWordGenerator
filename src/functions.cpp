#include "functions.h"


const char *alphabets = { "abcdefghijklmnopqrstuvwxyz" },   //Letters
        *vowels = { "aeiouy" };                             //Vowels
uint8_t count {0};                                          //Count of correct words.


bool  checkVowel(const char *str, const char *attributes)   //Check if str contains attributes
{
  bool  position=false;
  while ((*attributes)!='\0')
  {
    while ((*str)!='\0')
    {
      if ((*str)==(*attributes))
      {
        position=true;
        break;
      }

      else
        ++str;
    }

    //After checking each letter of str
    ++attributes;
  }

  return (position);
}

bool isConfirm()
{
  return (::confirmation=="y" || ::confirmation=="Y" || ::confirmation=="n" || ::confirmation=="N");
}
