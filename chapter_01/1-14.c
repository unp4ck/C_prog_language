#include <stdio.h>

#define LIMIT 'z'-' ' // int equals chars in C

main() {
	int nchars[LIMIT], i, x, c;
	
	for (i = 0; i < LIMIT; ++i) {
		nchars[i] = 0;
	}
	
	while ((c = getchar()) != EOF) {
		if (c >= ' ' && c <= 'z') {
			++nchars[c-' '];
		}
	}
	
	for (i = 0; i < LIMIT; ++i) {
		printf("%2d ", i);
		for (x = 0; x < nchars[i]; ++x) {
			printf("|");
		}
		printf("\n");
	}
}