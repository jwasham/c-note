#include <stdio.h>

unsigned int getbits(unsigned int x, int p, int n)
{
    return (x >> (p + 1 - n)) & ~(~0 << n);
}

const char* displaybits(unsigned int d)
{
    int i = 0;
    int c;
    char rbits[sizeof(d) + 1];
    static char bits[sizeof(d) + 1];

    if (d == 0) {
        rbits[i++] = '0';
    } else {
        while (d != 0) {
            rbits[i++] = (d & 1) == 1 ? '1' : '0';
            d >>= 1;
        }
    }

    // reverse string
    // @todo create an in-place reverse string algorithm

    i--;

    for (c = 0; c <= i; c++) {
        bits[c] = rbits[i - c];
    }

    bits[c] = '\0';

    return bits;
}

int main()
{
    printf("Should be 0: %s\n", displaybits(0));
    printf("Should be 1: %s\n", displaybits(1));
    printf("Should be 10: %s\n", displaybits(2));
    printf("Should be 11: %s\n", displaybits(3));
    printf("Should be 100: %s\n", displaybits(4));
    printf("Should be 101: %s\n", displaybits(5));
    printf("Should be 110: %s\n", displaybits(6));
    printf("Should be 111: %s\n", displaybits(7));
    printf("Should be 1000: %s\n", displaybits(8));
    printf("Should be 10000: %s\n", displaybits(16));
    printf("Should be 11111: %s\n", displaybits(16 + 8 + 4 + 2 + 1));
    printf("Should be 11011: %s\n", displaybits(16 + 8 + 2 + 1));
    printf("Should be 10011: %s\n", displaybits(16 + 2 + 1));
    printf("Should be 10010: %s\n", displaybits(16 + 2));

    return 0;
}