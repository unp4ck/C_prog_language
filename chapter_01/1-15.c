#include <stdio.h>

int celToFah(float celsius) {
    float fah;
    int upper = 300;
    int step = 20;

    while (celsius <= upper)
    {
         fah = (9.0/5.0) * celsius + 32;
        printf("%6.1f | %6.1f\n", celsius, fah);
        celsius = celsius + step;
    }
    
}



int main() {
    float c = 300;
    celToFah(300);
}