int hsvmhr(char *s, char *t) {
	for(;;++s,++t) {
		if(*s!=*t)
			return *s-*t;
		if(!*s)
			return 0;
	}
}

