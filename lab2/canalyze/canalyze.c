#include <stdio.h>
#include <string.h>
#include <ctype.h>


#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main(int argc, char **argv) {
	FILE *file = fopen(argv[1], "r");
////	int inWord = 0;		//1 if inside word, 0 otherwise
	char word[80];		//the current word
	int ch;		//the current char
	int id = 0;
	int i;
	while (!(feof(file)))
	{
		ch = fgetc(file);
		if((isalpha(ch)!=0) || (isdigit(ch)!=0))
		{
				word[id] = ch;
				id++;
//				printf("%s\n", word);
		}
		else
		{
			printf("%s\n", word);
			word[0] = '\0';
	
//			for (i=0; i<80; i++)
//				word[i] = '\0';
			id = 0;
		}
	}
	return 0;
}