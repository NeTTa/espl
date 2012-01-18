C_SRCS += \
src/canalyze.c \
src/namelist.c \

OBJS += \
bin/canalyze.o \
bin/namelist.o \

all: canalyze

canalyze: $(OBJS)
	@echo 'Building target'
	@echo 'Invoking GCC linker'
	gcc -o canalyze $(OBJS) 
	@echo 'Finished building target'

bin/namelist.o: src/namelist.c
	@echo 'Creating namelist.o'
	gcc -Wall -c -o bin/namelist.o src/namelist.c

bin/canalyze.o: src/canalyze.c
	@echo 'Creating canalyze.o'
	gcc -Wall -c -o bin/canalyze.o src/canalyze.c
clean:
	rm -rf bin/* canalyze
