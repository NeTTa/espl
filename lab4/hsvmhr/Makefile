.PHONY: clean all

all: strcmp

strcmp: strcmp.o hsvmhr.o
	gcc -m32 -g -Wall -o strcmp strcmp.o hsvmhr.o

strcmp.o: strcmp.c
	gcc -m32 -g -c -Wall -o strcmp.o strcmp.c

hsvmhr.o: hsvmhr.asm
	nasm -g -f elf -o $@ $<

clean:
	rm *.o hello