all:canalyze 

canalyze: canalyze.o namelist.o namelist.h
	gcc -g -Wall -o canalyze canalyze.o

namelist.o: namelist.c namelist.h
	gcc -c -g -Wall -o namelist.o namelist.c

canalyze.o: canalyze.c namelist.c namelist.h
	gcc -c -g -Wall -o canalyze.o canalyze.c

