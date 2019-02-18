#include <stdio.h>
#include "myprint.h"

/*note: I assume that lines < 10000, words < 100000, chars < 1000000 to print the result beautifuly.
I suspect that the number of fixed width in original wc is baced on each result(line word char) of a total,
which means wc prints results of each file AFTER it gets the result of the total.
To accomplish this stratedy, you need to keep results of each file until figuring out the result of the total,
and probably you need arrays of int (I would use queue). But I did not do in that way since we have not
learned array of integers in class*/

//accept the number of flags, results to be displayed, file name, and each flag
//and print result based off of parameters
void myprint(int flags, int num_lines, int num_words, int num_chars, char* fname, int l, int w, int c){
  if(flags == 0){
    printf(" %4u %5u %6u %s\n", num_lines, num_words, num_chars, fname);
  }
  else
  {
    if(l == 1){
      printf("  %4u", num_lines);
    }
    if(w == 1){
      printf("  %5u", num_words);
    }
    if(c == 1){
      printf("  %6u", num_chars);
      }
      printf(" %s\n", fname);
    }
}
