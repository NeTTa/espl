All: runprog

runprog: runprog.o
	gcc -o runprog runprog.o

runprog.o: runprog.c
	gcc -c -o runprog.o runprog.c

clean:
	rm -rf *.o runprog *~
