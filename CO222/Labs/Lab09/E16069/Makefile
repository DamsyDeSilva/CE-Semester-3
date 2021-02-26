CFLAGS=-I./ -Wall -O3
#CFLAGS+=-DDEBUG
CC=gcc

all: main

%.o: %.c
	$(CC) -c -o $@ $< $(CFLAGS)

main: linked.o linked.h

run: main
	./main


clean: 
	rm -f *.o *~ main

