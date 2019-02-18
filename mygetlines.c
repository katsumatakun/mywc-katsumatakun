#include "mygetlines.h"
#include "myisspace.h"
#include <stdio.h>

int getlines(char* str){

  int index = 0;
  int char_count = 0;
  //printf("%s", str);
  while(str[index] != '\n' && index < 255 && str[index] != '\0'){
    //if (myisspace(str[index]) == 0)
    char_count++;
    index++;
  }
  if (str[index] == '\n')
   return 1;
  else
    return 0;
}
