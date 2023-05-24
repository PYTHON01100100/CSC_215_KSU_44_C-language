CC=gcc
CFLAGS=-Wall -ansi

All: myfuncs.o test.o
	$(CC) $(CFLAGS) -o All myfuncs.o test.o
	
myfuncs.o: myfuncs.c
	$(CC) $(CFLAGS) -c myfuncs.c
	
test.o: test.c myfuncs.h
	$(CC) $(CFLAGS) -c test.c
	
CLEAN:
	rm *.o *.*~ All