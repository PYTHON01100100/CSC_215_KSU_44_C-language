CC=gcc
CFLAGS=-Wall -ansi

Prog: mat.o test.o
	$(CC) $(CFLAGS) -o prog mat.o test.o

mat.o: mat.c
	$(CC) $(CFLAGS) -c mat.c

test.o: test.c mat.h
	$(CC) $(CFLAGS) -c test.c

CLEAN: 
	rm *.o *.*~ prog