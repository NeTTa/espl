//#include "../include/complines.h"
#include <stdio.h>
#include <string.h>

int main(int argc, char **argv) {
	FILE *readA = fopen(argv[1], "r");
	FILE *readB = fopen(argv[2], "r");
	char lineA[80];
	char lineB[80];
	int counter = 0;
	
	while(!feof(readA)) {
		
		fgets(lineA, 80, readA);
		fgets(lineB, 80, readB);
		counter++;
		if ((strcmp(lineA, lineB))!=0)
		{
			  printf("-%d: %s", counter, lineA);
			  printf("+%d: %s", counter, lineB);
		}	
	}
	fclose(readA);
	fclose(readB);
	
	return 0;
}