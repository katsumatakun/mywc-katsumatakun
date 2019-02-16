OBJS = mygetwords.o mygetchars.o myisspace.o
OBJS2 = mygetwords.h mygetchars.h

all: mywc

mywc: mywc.o $(OBJS) $(OBJS2)
	gcc -o mywc mywc.o $(OBJS)

mywc.o: mywc.c $(OBJS2)
	gcc -c mywc.c

mygetwords.o: mygetwords.c mygetwords.h myisspace.h
	gcc -c mygetwords.c

mygetchars.o: mygetchars.c mygetchars.h myisspace.h
	gcc -c mygetchars.c

myisspace.o: myisspace.c myisspace.h
	gcc -c myisspace.c

clean:
	rm -rf mywc *.o
