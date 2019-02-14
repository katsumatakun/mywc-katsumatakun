# mywc

In this homework you will create a command line version of the popular unix command wc which we will call mywc to avoid conflicts. mywc will take up to 3 optional flags (-l, -w, -c) and 1 or more files. Look at man7.org for man page for additional info.  mywc without any flags and a file will return results as if all 3 flags were specified.  If multiple files are specified then results (depending on the flags) will be returned per file with filename and totals for each column will be displayed as well.

## Requirements of the homework

* Program will be called mywc
* Must have at minimum mywc.c myisspace.c mygetwords.c and mygetchars.c and appropriate header files.
* One function per .c file
* Not allowed to use any str functions in libc - must write your own if you want to use.
* Will include a Makefile that builds and cleans the code with correct dependencies
*  Program should have built in help, i.e., it will display usage if command is typed and protect itself from human error.
*  All code should be properly commented as well.
*  Must use branches and pull requests to change code.  You will just confirm and merge without review.
* This will be due at 11:59 PM on Monday before class.  Code must be in master to be considered for grade.

This program is pretty straight forward but there are some subtleties that you need to think about.  I would highly recommend not waiting till the last minute to start the work.
