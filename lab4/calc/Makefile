.PHONY: all clean

all: calc1

calc1: calc1.o atod.o
	gcc -g -o calc1 calc1.o atod.o

calc1.o: calc1.c
	gcc -g -c -o calc1.o calc1.c

atod.o: atod.c
	gcc -g -c -o atod.o atod.c
#calc: calc.o
#	gcc -o $@ $^

clean:
	rm -rf *.o