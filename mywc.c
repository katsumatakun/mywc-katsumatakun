#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "mygetlines.h"
#include "mygetwords.h"
#include "mygetchars.h"
#include "myprint.h"
#define N 256 //max number of chars that fgtes can put into array


int main(int argc, char *argv[]){

  //buit-in help
  if (argc == 1)
  {
    printf("Usage: %s [-l] [-w] [-c] file name\n", argv[0] );
    printf("-l\tprint the newline counts\n");
    printf("-w\tprint the word  counts\n");
    printf("-c\tprint the character counts\n");
    return -1;
  }

  //l, w, c will check if user types options
  int sum_flags = 0, opt, l = 0, w = 0, c = 0, num_files = 0;
  int total_lines = 0, total_words = 0, total_chars = 0;

  //if -l, -w, or -c is found, it gets 1
  while((opt = getopt(argc, argv, "lwc-:")) != -1){
    switch(opt){
    case 'l':
      l = 1;
      sum_flags++;
      break;
    case 'w':
      w = 1;
      sum_flags++;
      break;
    case 'c':
      c = 1;
      sum_flags++;
      break;
    //default is in the case of invalid options. display help
    default:
      printf("Usage: %s [-l] [-w] [-c] file name\n", argv[0]);
      return -1;

      }
  }

  //if only flags are typed, but file names are not
  if(sum_flags+1 == argc){
    printf("Usage: %s [-l] [-w] [-c] file name\n", argv[0]);
    return -1;
  }

    int index_of_files = optind; //the next index of the last flag
    FILE *fp;
    char* fname;
    char str[N];
    //Fill str with newlines so as not to print logical garvages
    //If you did not do this, you might be going to get different word counts
    //Please tyr with README file if you wanna check.
    for (int i = 0; i < 256;  i++)
    {
      str[i] = '\n';
    }

    //to read multiple files
    while (index_of_files < argc){
      fname = argv[index_of_files];
      num_files++;
      int num_lines = 0, num_words = 0, num_chars = 0;
      fp = fopen(fname, "r");

      //if the program could not find a file typed, display error
      //message and try to find next file typed
      if(fp == NULL){
        printf("%s file not open \n", fname);
        index_of_files++;
        }
      //if you find the file typed
      else{
          while(fgets(str, N, fp) != NULL){

              //counts for each line or each 255 characters
              int words = mygetwords(str);
              int chars = mygetchars(str);
              int lines = mygetlines(str);

              //update sub total (total for one file)
              num_lines = num_lines + lines;
              num_words = num_words + words;
              num_chars = num_chars + chars;

              //before reading next line, fill str with
              //newlines so as not to count logical garvage
              for (int i = 0; i < 256;  i++)
              {
                str[i] = '\n';
              }
          }

          //getchars does not count '\n' so need updating
          num_chars = num_chars + num_lines;

          //keep total counts for all of the files as well
          total_lines = total_lines + num_lines;
          total_words = total_words + num_words;
          total_chars = total_chars + num_chars;

          //display results for a file
          myprint(sum_flags, num_lines, num_words, num_chars, fname, l, w, c);
          index_of_files++;
          fclose(fp);
          }
        }
      //if multiple files are typed, total will be displayed
      if (num_files > 1){
      myprint(sum_flags, total_lines, total_words, total_chars, "total", l, w, c);
      }
      return 0;
    }
