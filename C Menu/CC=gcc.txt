CC=gcc
CFLAGS=-I.

assign3: assign3.o
	$(CC) -o assign3 assign3.o

assign3.o: assign3.c
	$(CC) $(CFLAGS) -c assign3.c

clean:
	rm -f assign3 assign3.o