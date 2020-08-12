#include "functions.h"

bool  checkVowel(char *str, char *attributes)        //Check if str contains attributes
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


uint8_t &getRandom()                                  //To generate a random number.
{
  static uint8_t number = uint8_t (random()%25);
  return (number);
}
