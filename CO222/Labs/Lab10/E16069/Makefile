CC=gcc
CFLAGS=-Wall -I./

all:wordcount

%.o:%.c
	$(CC) $(CFLAGS) $? -c 

clean:
	rm -f *~ *.o

wordcount: map.o wc.o
	$(CC)  map.o wc.o -o $@
