#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "font.h"

#define asc2idx(asc) (asc-32)

#define SCREEN_WIDTH 80
int main(int argc, char **argv) {
	int iline, iarg;
	for(iline = 0; iline != SYMBOL_HEIGHT; ++iline) {
		for(iarg = 1; iarg != argc; ++iarg) {
			char *c = argv[iarg];
			while(*c) { 
				printf("%s", alphabet[asc2idx(*c)][iline]);
				++c;
			}
			if(iarg!=argc-1)
				printf("%s", alphabet[asc2idx(' ')][iline]);
		}	
		printf("\n");
	}
	return 0;
}
