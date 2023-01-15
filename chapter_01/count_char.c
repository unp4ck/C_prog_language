#include <stdio.h>


int main() {
    long c;
    int count;

    while((c = getchar()) != EOF) {
        ++count;
        printf("[*] Quantity: %1d\n", count);
    }
}