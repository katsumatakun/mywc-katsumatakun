#include "mygetlines.h"

//accept string (arrar of chars) and check if there is '\n'
//then return the number of '\n'
int mygetlines(char* str){

  int index = 0;

  //while finish if it finds newline or if it reach the max number
  // of chars that str can hold
  while(str[index] != '\n' && str[index] != '\0'){
    index++;
  }

  //if find newline, return 1, otherwise return 0
  if (str[index] == '\n')
   return 1;
  else
    return 0;
}
