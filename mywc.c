#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "mygetwords.h"
#include "mygetchars.h"
#include "myprint.h"
#define N 256


int main(int argc, char *argv[]){

  if (argc == 1)
  {
    printf("Usage: %s [-l] [-w] [-c] file name\n", argv[0] );
    return -1;
  }

  int flags = 0, opt, l = 0, w = 0, c = 0, num_files = 0;
  int total_lines = 0, total_words = 0, total_chars = 0;

  while((opt = getopt(argc, argv, "lwc-:")) != -1){
    switch(opt){
    case 'l':
      l = 1;
      break;
    case 'w':
      w = 1;
      break;
    case 'c':
      c = 1;
      break;
    /*case '-':
      break;*/
    default:
      printf("Usage: %s [-l] [-w] [-c] file name\n", argv[0]);
      return -1;

      }
  }
  flags = l + w + c;
  //printf("%u\n",flags );
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
      num_files++;
      int num_lines = 0, num_words = 0, num_chars = 0;
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
              int chars = getchars(str);
              //printf("%u\n", words);
              //printf("%u\n", chars);
              num_words = num_words + words;
              num_chars = num_chars + chars;
          }
          num_chars = num_chars + num_lines;

          total_lines = total_lines + num_lines;
          total_words = total_words + num_words;
          total_chars = total_chars + num_chars;
          }
          myprint(flags, num_lines, num_words, num_chars, fname, l, w, c);
          index_of_files++;
          fclose(fp);
        }
      if (num_files > 1){
      myprint(flags, total_lines, total_words, total_chars, "total", l, w, c);
      }
      return 0;
    }
