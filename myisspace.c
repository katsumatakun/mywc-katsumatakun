#include "myisspace.h"

int myisspace(char c) {
  if (c == ' ' || c == '\t' || c == '\r')
    return 1;

  return 0;
}
