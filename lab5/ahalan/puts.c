int length (char* s);

void puts (char *s){
	int len = length(s);
	return write(1, s, len);
}