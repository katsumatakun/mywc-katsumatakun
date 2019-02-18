#include "mygetchars.h"

//accept string (array) of chars and return the number of chars
// including escape keys
//new line will not be counted. it will be added to num_chars by the line counter
int mygetchars(char* str){

  int index = 0;
  int char_count = 0;

  //terminate while loop when it finds newline, end of file(just in case), or exceeded index
  while(str[index] != '\n' && index < 255 && str[index] != '\0' ){
    char_count++;
    index++;
  }
  return char_count;
}
