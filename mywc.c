#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "mygetwords.h"
#include "mygetchars.h"
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
    FILE *fp;
    char* fname = " ";
    char str[N];
    while (index_of_files < argc){
      fname = argv[index_of_files];
      fp = fopen(fname, "r");
      if(fp == NULL){
        printf("%s file not open \n", fname);
        index_of_files++;
        }
      else{
          while(fgets(str, N, fp) != NULL){
              //printf("aaa\n");
              num_lines++;
              int words = getwords(str);
              printf("%u\n", words);
              num_words = num_words + words;
              num_chars = num_chars + getchars(str);
          }
          if(flags == 0){
            printf("%u %u %u %s\n", num_lines, num_words, num_chars, fname);
          }
          else
          {
            if(l == 1){
              printf("%u ", num_lines);
            }
            if(w == 1){
              printf("%u ", num_words);
            if(c == 1){
              printf("%u ", num_chars);
              }
            printf("%s\n", fname);
            }
          }
          index_of_files++;
          fclose(fp);
        }

      }
      return 0;
    }
