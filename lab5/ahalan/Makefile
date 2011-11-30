%.o: %.asm
	nasm -g -f elf -o $@ $<

%.o: %.c
	gcc -m32 -g -nostdlib -fno-stack-protector -c -o $@ $<

.PHONY: clean all

all: ahalan

ahalan: start.o main.o ahalan.o puts.o write.o length.o
	ld -melf_i386 -g -o $@ $^
puts.o: puts.c  
ahalan.o: ahalan.asm
start.o: start.asm
main.o: main.c
write.o: write.asm
length.o: length.c

clean:
	rm *.o ahalan
