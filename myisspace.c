#include "myisspace.h"

//accept a character and check if it is escape key
//that we should be careful
int myisspace(char c) {
  if (c == ' ' || c == '\t' || c == '\r')
    return 1;
  return 0;
}
