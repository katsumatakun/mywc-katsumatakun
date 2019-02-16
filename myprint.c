#include <stdio.h>
#include "myprint.h"

void myprint(int flags, int num_lines, int num_words, int num_chars, char* fname, int l, int w, int c){
  if(flags == 0){
    printf(" %3u %4u %5u %s\n", num_lines, num_words, num_chars, fname);
  }
  else
  {
    if(l == 1){
      printf("  %u", num_lines);
    }
    if(w == 1){
      printf("  %u", num_words);
    }
    if(c == 1){
      printf("  %u", num_chars);
      }
      printf(" %s\n", fname);
    }
}
