#include "mygetwords.h"
#include "myisspace.h"

//accept string (array of characters and return the number of words)
int mygetwords(char* str){

  int word_count = 0;
  int index = 0;

  //some escape keys before the first char of a line will be skiped
  while (myisspace(str[index]) == 1)
  {
    index++;

  }

  //terminate while loop when it finds newline, end of file(just in case), or exceeded index
  while (str[index] != '\n' && index < 255 && str[index] != '\0'){

    //until finfing next escape key, keep readng next char
    while (myisspace(str[index]) == 0)
    {
      index++;
    }

    word_count++;

    //this prevents escape keys in a row
    //e.g. \t\t 
    while (myisspace(str[index]) == 1)
    {
      index++;

    }
  }

  return word_count;

}
