#include <stdio.h>


int main() {

    int c;
    int blanks_counter = 0;

    while((c = getchar()) != EOF) {
        if ( c == ' ') {
            ++blanks_counter;
            if(blanks_counter == 1) {
                printf(" ");
            } else if (blanks_counter > 1) {
                printf("");
            }
        } else if (c != ' ') {
            blanks_counter = 0;
            putchar(c);
        }
    }

    return 0;
}