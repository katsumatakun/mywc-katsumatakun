#include "mygetwords.h"
#include "myisspace.h"
#include <stdio.h>


int mygetwords(char* str){

  int word_count = 0;
  int index = 0;
  printf("%s", str);
  while (myisspace(str[index]) == 1)
  {
    index++;

  }
  while (str[index] != '\n' && str[index] != '\0' && index < 255  ){

    while (myisspace(str[index]) == 0)
    {
      //printf("%c",str[index] );
      index++;
    }
    word_count++;
    while (myisspace(str[index]) == 1)
    {
      index++;

    }
    //printf("\n");
  }

  return word_count;

}
