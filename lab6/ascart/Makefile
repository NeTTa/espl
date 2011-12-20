.SUFFIXES: .c .o .h

MDFLAGS=
%.o: %.asm
	nasm -g -f elf -o $@ $<

LDFLAGS=
%.o: %.c
	gcc -m32 -g -nostdlib -fno-stack-protector -c -o $@ $<

.PHONY: all clean dist

all: ascart

ascart: start.o ascart.o asc2idx.o length.o write.o font.o
	ld -melf_i386 -g -o $@ $^

write.o: write.asm
length.o:length.asm
asc2idx.o:asc2idx.asm
start.o: start.asm

clean:
	rm -f *.o *~

dist:
	(cd ..; zip ascart/ascart.zip ascart/font.c ascart/font.h ascart/prsym.c)
