#include <stdio.h>




int main(int argc, char** argv) {

	//File 1 open:
	char buffer_f1[1];
	FILE* f1 = fopen(argv[1],"r");

	//File 2 open:
	char buffer_f2[1];
	FILE* f2 = fopen(argv[2],"r");

	int char_counter=1; //Line counter.

	while (!feof(f1)) { //Start reading file in binary mode:
		fread(buffer_f1, 1, 1, f1); //Binary read byte by byte.
		fread(buffer_f2, 1, 1, f2);

		if (buffer_f1[0] != buffer_f2[0]) { //Once a difference has been spoted:
			printf("byte %d %d %d",char_counter,buffer_f1[0],buffer_f2[0]);
			break;
		}
		char_counter++;
	}


	fclose(f1);
	fclose(f2);
	return 0;
}
