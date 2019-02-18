#include <stdio.h>
#include "myprint.h"

//accept the number of flags, results to be displayed, file name, and each flag
//and print result based off of parameters
void myprint(int flags, int num_lines, int num_words, int num_chars, char* fname, int l, int w, int c){
  if(flags == 0){
    printf(" %10d %10d %10d %s\n", num_lines, num_words, num_chars, fname);
  }
  else
  {
    if(l == 1){
      printf(" %10d", num_lines);
    }
    if(w == 1){
      printf(" %10d", num_words);
    }
    if(c == 1){
      printf(" %10d", num_chars);
      }
      printf(" %s\n", fname);
    }
}
