#include <stdio.h>

int main() {

    int c;

    printf("[*] verify the expresion: %d\n\n", (c = getchar() != EOF));

    while ((c = getchar()) != EOF)
    {
        putchar(c);
    }
    
    return 0;
    
}