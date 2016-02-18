#include <stdio.h>
#include <math.h>

int htoi(char hex[])
{
    int c;
    int n = 0;
    int v;

    for (int i = 0; hex[i] != '\0'; i++) {
        c = hex[i];
        if (c >= '0' && c <= '9') {
            v = c - '0';
        } else if (c >= 'a' && c <= 'f') {
            v = c - 'a' + 9;
        } else if (c >= 'A' && c <= 'F') {
            v = c - 'A' + 10;
        }
        n = n * i + v;
    }

    return n;
}

int main()
{
    printf("Should be 0: %d\n", htoi("0"));
    printf("Should be 1: %d\n", htoi("1"));
    printf("Should be 9: %d\n", htoi("9"));
    printf("Should be 10: %d\n", htoi("A"));
    printf("Should be 15: %d\n", htoi("F"));
    printf("Should be 16: %d\n", htoi("10"));
    printf("Should be 17: %d\n", htoi("11"));
    printf("Should be 21: %d\n", htoi("15"));
    printf("Should be 26: %d\n", htoi("1A"));
    printf("Should be 31: %d\n", htoi("1F"));
    printf("Should be 32: %d\n", htoi("20"));
    printf("Should be 48: %d\n", htoi("30"));
    printf("Should be 255: %d\n", htoi("FF"));
    printf("Should be 2048: %d\n", htoi("800"));

    return 0;
}