CC=gcc
CFLAGS=-std=c11 -Wall -Wextra -O2
all: bitops
bitops: register_rodeo.c
	$(CC) $(CFLAGS) register_rodeo.c -o bitops
run: bitops
	./bitops demo
clean:
	rm -f bitops
