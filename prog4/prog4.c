#include <stdio.h>

struct Bitfield {
    unsigned int firstbit : 1;
    unsigned int secondbit : 2;
};

int main() {

    struct Bitfield a;

    // Test normal values
    a.firstbit = 1;
    a.secondbit = 3; 
    printf("Normal values:\n");
    printf("firstbit = %u\n", a.firstbit);
    printf("secondbit = %u\n", a.secondbit);

    // Test overflow values
    a.firstbit = 5;
    a.secondbit = 10;

    printf("\nAfter overflow:\n");
    printf("firstbit = %u\n", a.firstbit);
    printf("secondbit = %u\n", a.secondbit);

    return 0;
}