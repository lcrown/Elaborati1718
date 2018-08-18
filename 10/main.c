#include <stdio.h>
#include "text.h"


int main(int argc, char *argv[]) {
	struct text *T;

	if(argc != 3) {
		fprintf(stderr,"Usage: text <file> <char>\n");
		return 1;
	}

	if((T = read_text(argv[1])) == NULL) {
		fprintf(stderr,"Error reading %s\n",argv[1]);
		return 1;
	}	
	char c=argv[2][0];
	printf("** ORIGINAL TEXT **\n");
	print_text(T);
	
	printf("\n** TEXT WITHOUT %c **\n",c);
	remove_char(T, c);
	print_text(T);
	
	printf("\n** TEXT IN ONE LINE **\n");
	single_line(T);
	print_text(T);
	
	return 0;
}
