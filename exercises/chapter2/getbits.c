#include <stdio.h>

unsigned int getbits(unsigned int x, int p, int n)
{
    return (x >> (p + 1 - n)) & ~(~0 << n);
}

const char* displaybits(unsigned int d)
{
    int i = 0;
    static char bits[sizeof(d) + 1];

    if (d == 0) {
        bits[i] = '0';
        bits[i + 1] = '\0';
    } else {
        while (d != 0) {
            bits[i++] = (d & 1) == 1 ? '1' : '0';
            d >>= 1;
        }
        bits[i] = '\0';
    }

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

    return 0;
}