#include "mygetchars.h"
#include "myisspace.h"
#include <stdio.h>

int getchars(char* str){

  int index = 0;
  int char_count = 0;

  while(str[index] != '\n'){
    if (myisspace(str[index]) == 0)
      char_count++;
    index++;
  }
  return char_count;
}
