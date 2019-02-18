#This is a Makefile for mywc

OBJS = mygetwords.o mygetchars.o myisspace.o myprint.o mygetlines.o
HEDEARS = mygetwords.h mygetchars.h myprint.h mygetlines.h

all: mywc

mywc: mywc.o $(OBJS) 

#no need of myisspace.h since it is not included
mywc.o: mywc.c $(HEADERS)
	gcc -c mywc.c

#need myisspace.h since it is incuded
mygetwords.o: mygetwords.c mygetwords.h myisspace.h
	gcc -c mygetwords.c

mygetchars.o: mygetchars.c mygetchars.h
	gcc -c mygetchars.c

mygetlines.o: mygetlines.c mygetlines.h
	gcc -c mygetlines.c

myisspace.o: myisspace.c myisspace.h
	gcc -c myisspace.c

myprint.o: myprint.c myprint.h
	gcc -c myprint.c

clean:
	rm -rf mywc *.o
