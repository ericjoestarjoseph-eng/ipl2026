
#include <stdio.h>

// Function to print bits of an integer
void printBits(int n) {
    for (int i = 31; i >= 0; i--) {
        int bit = (n >> i) & 1;

        printf("%d", bit);

        // Space after every 8 bits
        if (i % 8 == 0) {
            printf(" ");
        }
    }

    printf("\n");
}

// Function to count number of set bits (1s)
int countSetBits(int n) {
    int count = 0;

    // Convert to unsigned for proper handling of negative numbers
    unsigned int un = (unsigned int)n;

    while (un > 0) {
        un = un & (un - 1);
        count++;
    }

    return count;
}

int main() {
    int num;

    printf("Enter an integer: ");
    scanf("%d", &num);

    printf("\nBinary representation:\n");
    printBits(num);

    printf("\nNumber of set bits: %d\n", countSetBits(num));

    return 0;
}