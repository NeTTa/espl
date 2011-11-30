#include <stdlib.h>
#include <stdio.h>
#include "font.h"


int main(int argc, char **argv) {
  int x;
  
  printf("%d\n",argc);
    for (x=1; x<argc; x++)
        printf("%s\n",argv[x]);
	return 0;
}
