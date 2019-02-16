#include <stdio.h>
#include <stdlib.h>
#include "mygetwords.h"
#include "mygetcahrs.h"
#define N 256


int main(int argc, char *argv[]){

  if (argc == 1)
  {
    printf("Usage: %s [-l] [-w] [-c] file name\n", argv[0] );
    return -1;
  }

  int flags = 0, opt, num_lines = 0, num_words = 0, num_chars = 0, l, w, c;

  while((opt = getopt(argc, argv, "lwc:")) != -1){
    switch(opt){
    case 'l':
      l = 1;
      flags++;
      break;
    case 'w':
      w = 1;
      flags++;
      break;
    case 'c':
      c = 1;
      flags++;
      break;
    default:
      printf("Usage: %s [-l] [-w] [-c] file name\n", argv[0]);
      return -1;

      }
  }

  if(flags+1 == argc){
    printf("Usage: %s [-l] [-w] [-c] file name\n", argv[0]);
    return -1;
  }
    int index_of_files = flags+1;

    while (index_of_files < argc){
      FILE *fp;
      char fname[] = argv[index_of_files];
      char str[N];
      fp = fopen(fname, "r");
      if(fp == NULL){
        printf("s% file not open \n", fname);
        index_of_files++;
        fclose(fp);
        }
      else{
          while(fgets(str, N, fp) != NULL){
              num_lines++;
              num_words = num_words + getwords(str);
              num_chars = num_chars + getchars(str);
          }
          if(flags == 0){
            printf("%lu %lu %lu %s\n", num_lines, num_words, num_chars, fname);
          }
          else
          {
            if(l == 1){
              printf("%lu ", num_lines);
            }
            if(w == 1){
              printf("%lu ", num_words);
            if(c == 1){
              printf("%lu ", num_chars);
              }
            printf("%s\n", fname);
            }
          }
        }
      index_of_files++;
      fclose(fp);
      }
      return 0;
    }
