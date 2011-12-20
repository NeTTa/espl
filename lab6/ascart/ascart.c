#include "font.h"


//#define asc2idx(asc) (asc-32)

#define SCREEN_WIDTH 80


//int length(char *s) {
//	char *t = s;
//	while(*t) ++t;
//	return t-s;
//}

//int asc2idx(int c){
//	return (c-32);
//}
 
void putsi(char *s){
	int len = length(s);
	write(1, s, len);
}

 void printChar(char * c , int iline){
	while(*c) { 
		putsi(alphabet[asc2idx(*c)][iline]);
		++c;
	}
}
  
void printSpace(int iarg , int iline , int argc){
	if(iarg!=argc-1){
		putsi(alphabet[asc2idx(' ')][iline]);
	}
}
 
 
void printWord(int iline , int argc ,char **argv){
	int iarg;
	for(iarg = 1; iarg != argc; ++iarg) {
		char *c = argv[iarg];
		printChar(c,iline);
		printSpace(iarg , iline , argc);
	}
}
 
void printAll(int argc, char **argv){
  	int iline;
 	for(iline = 0; iline != SYMBOL_HEIGHT; ++iline) {
		printWord(iline ,argc , argv);
		putsi("\n");
	}
}

void main(int argc, char **argv) {
	printAll(argc , argv);
}



