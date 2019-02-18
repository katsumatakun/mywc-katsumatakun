#include "mygetchars.h"
#include "myisspace.h"
#include <stdio.h>

int getchars(char* str){

  int index = 0;
  int char_count = 0;
  //printf("%s", str);
  while(str[index] != '\n' && index < 255 && str[index] != '\0' ){
    //if (myisspace(str[index]) == 0)
    char_count++;
    index++;
  }
  return char_count;
}
