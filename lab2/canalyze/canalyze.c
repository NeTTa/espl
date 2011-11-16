#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>
#include "./namelist.h"

int const MAX_WORD_SIZE = 80;
namelist reservedNames; //name list which contains all reserved words in c langauge which should not be counted.

//int isalphaNew(int inChar) {
//	if (((inChar>='A') && (inChar<='Z')) || ((inChar>='a') && (inChar<='z')))
//		return 1;
//	else
//		return 0;
//
//}

char* extractWord(char inWord[]) {
	int LastChar = 0;
	while (inWord[LastChar]!= '\0')
		LastChar++;

	char* extractedWord = (char*)calloc(LastChar,sizeof(char));
	int i;
	for (i=0; i<LastChar;i++)
		extractedWord[i] = inWord[i];
	return extractedWord;
}


void printNamesList(namelist nl) {
	int i;
	for(i=0;i<nl->size;i++)
		printf("%s\t%d\n",nl->names[i].name,nl->names[i].count);
}

int stringCompare(char* str1, char* str2) {
	int ans = 0;

	int minLength;
	int whichStrIsBigger;
	if (strlen(str1)<strlen(str2)) {
		minLength = strlen(str1);
		whichStrIsBigger = 2;;
	}
	else if (strlen(str1)>strlen(str2)) {
		minLength = strlen(str2);
		whichStrIsBigger = 1;
	} else {
		minLength = strlen(str1);
		whichStrIsBigger = 0;
	}

	int i;
	for (i=0;i<minLength;i++) {
		if(str1[i]<str2[i]){
			ans=-1;
			break;
		}
		if(str2[i]<str1[i]) {
			ans = 1;
			break;
		}
	}

	if (ans == 0) { //if the text is equal up to the min length, check where is remaining text.
		if (whichStrIsBigger == 2) {
			ans = 1;
		}
		else if (whichStrIsBigger == 1) {
			ans = -1;
		}
	}
	return ans;
}

int areStringsIdentical (char* str1, char* str2){
	int ans = 0;
	int index;
	if ( strlen(str1) != strlen(str2) )
		return ans;
	else
		//printf("%d %d", (int)strlen(str1), (int)strlen(str2));
		for (index = 0; index < strlen(str1); index++) {
			if (str1[index] != str2[index]) {
				return ans;
			}
		}
	if (index == strlen(str1))
		ans = 1;
	return ans;
}

int existsInReserved(char words[], namelist nl) {
	//Input: a word and the reserved words namelist
	//Output: 1 if word exists in namelist list, 0 if not.

	int i;
	int flag = 0;
	char* word2;// = (*nl).names[i].name;
	char* word1 = extractWord(words);
	for(i=0; i<(*nl).size;i++) {
		word2 = extractWord((*nl).names[i].name);
		if( areStringsIdentical(word1,word2)==1 ) {
			flag=1;
			//free(word1);
			free(word2);
			break;
		}
		free(word2);
	}
	free(word1);
	return flag;
}


//int stringCompare (char str1[], char str2[]){



int main(int argc, char **argv) {



	///////////////////////////////////////////////////////////
	namelist reservedNames = make_namelist();
	add_name(reservedNames,"auto");
	add_name(reservedNames,"break");
	add_name(reservedNames,"case");
	add_name(reservedNames,"char");
	add_name(reservedNames,"continue");
	add_name(reservedNames,"default");
	add_name(reservedNames,"do");
	add_name(reservedNames,"double");
	add_name(reservedNames,"else");
	add_name(reservedNames,"entry");
	add_name(reservedNames,"extern");
	add_name(reservedNames,"float");
	add_name(reservedNames,"for");
	add_name(reservedNames,"goto");
	add_name(reservedNames,"if");
	add_name(reservedNames,"int");
	add_name(reservedNames,"long");
	add_name(reservedNames,"register");
	add_name(reservedNames,"return");
	add_name(reservedNames,"short");
	add_name(reservedNames,"sizeof");
	add_name(reservedNames,"static");
	add_name(reservedNames,"struct");
	add_name(reservedNames,"switch");
	add_name(reservedNames,"typedef");
	add_name(reservedNames,"union");
	add_name(reservedNames,"unsigned");
	add_name(reservedNames,"while");
	add_name(reservedNames,"enum");
	add_name(reservedNames,"void");
	add_name(reservedNames,"const");
	add_name(reservedNames,"signed");
	add_name(reservedNames,"volatile");

//	printf ("%d\n",reservedNames->size);
	///////////////////////////////////////////////////////////

	namelist nl = make_namelist(); //wanted namelist
	int isWord = 0; //Flag if scanning of text is at a word.
	char currWord[MAX_WORD_SIZE]; //Variable which contains the current read word.

	currWord[0]='\0';

	FILE *fileToRead;
	//Later on, disassemble the argv[1] to the different file names and run the function scannign earch file but on a global word counter.

	fileToRead = fopen(argv[1],"r");
	int ch = fgetc(fileToRead);
	int prevCh;
	int isSpecial = 0; //A flag to indicate if we have encountered a % or \ sign.
	int isBeginningOfSpecial = 0;
	int reachedEndOfSpecial = 0;
	if ((ch=='"')) {
		isSpecial = 1;
		isBeginningOfSpecial = 1;
		reachedEndOfSpecial = 0; //A flag to indicate If i have reached an a..z,A..Z letter after I met a special char % or backslash
	}


	int wordCounter = 0;

	while(!feof(fileToRead)) {
//		printf("%c",ch);
		//read the words



		//If currently not scanning a word, then look for [a..z,A..Z] letters only:
		if(isSpecial!=1) {
			if (isWord == 0) { //Not currently scanning a word
				if (isalpha(ch) != 0) { //If I wasn't scannign a word already and I have found an [a..z,A..Z] than a new word is starting.
					isWord = 1; //Update flag that a word is being scanned.
					currWord[wordCounter] = ch;
					wordCounter++;
				}
			}
			else { //Scanning a word
				if ((isalpha(ch)!=0) || (isdigit(ch)!=0)) {
					currWord[wordCounter] = ch;
					wordCounter++;
				}
				else {
					//Finished scanning word, update env for scanning a new word.
					currWord[wordCounter] = '\0';
					isWord = 0;
					if (existsInReserved(currWord,reservedNames)!=1) {
						add_name(nl,currWord);
						//printf("%*.*s\n",wordCounter,wordCounter,currWord);
					}
					wordCounter = 0;
					currWord[0]='\0';
				}
			}
		}

		if (reachedEndOfSpecial == 1) {
			isSpecial = 0;
			reachedEndOfSpecial = 0;
			isBeginningOfSpecial=0;
		}
		prevCh = ch;
		ch = fgetc(fileToRead);
		if ((isSpecial==0) && (ch=='"'))  {
				isSpecial = 1;
				isBeginningOfSpecial = 1;
				reachedEndOfSpecial = 0;
		}

		if ((isBeginningOfSpecial==1) && (prevCh=='"'))
			isBeginningOfSpecial=0;

		if ((isSpecial==1) && (prevCh!='\\') && (ch=='"') && (isBeginningOfSpecial==0)) {
			reachedEndOfSpecial=1;
		}
	}



	fclose(fileToRead);

	//Chech that the namelist holds the it:
	qsort(&((*nl).names[0]),(*nl).size,sizeof((*nl).names[0]),stringCompare);
	printNamesList(nl);

}