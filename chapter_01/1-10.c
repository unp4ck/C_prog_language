#include <stdio.h>


int main() {

    int c;
    int count = 0;


    while((c = getchar()) != EOF) {
        if (c == '\t') {
            printf("\\t");
        } else if (c == ' ') {
            printf("\\b");
        } else if (c == '\\') {
            printf("\\");
        }

        putchar(c);

    }
    
    return 0;

}