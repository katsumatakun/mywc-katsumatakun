#include "mygetwords.h"
#include "myisspace.h"


int getwords(char* str){

  int word_count = 0;
  int index = 0;
  while (str[index] != '\n'){

    while (myisspace(str[index]) == 0)
    {
      index++;
    }

    word_count++;
  }

  return word_count;

}
