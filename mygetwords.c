#include "mygetwords.h"
#include "myisspace.h"
#include <stdio.h>


int getwords(char* str){

  int word_count = 0;
  int index = 0;
  //printf("%s", str);
  while (myisspace(str[index]) == 1)
  {
    index++;
  }
  while (str[index] != '\n'){
    while (myisspace(str[index]) == 0)
    {
      index++;
    }
    index++;
    word_count++;
  }
  return word_count;

}
