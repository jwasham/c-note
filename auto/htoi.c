#include <stdio.h>

int htoi(char hex[])
{
    int c;
    int v;
    int n = 0;

    for (int i = 0; hex[i] != '\0'; i++) {
        c = hex[i];
        if (c >= '0' && c <= '9') {
            v = c - '0';
        } else if (c >= 'a' && c <= 'f') {
            v = c - 'a' + 10;
        } else if (c >= 'A' && c <= 'F') {
            v = c - 'A' + 10;
        } else {
            continue;
        }

        n = 16 * n + v;
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
    printf("Should be 12113: %d\n", htoi("2F51"));
    printf("Should be 19008: %d\n", htoi("4A40"));
    printf("Should be 809149: %d\n", htoi("C58BD"));

    // mixed-case

    printf("Should be 12113: %d\n", htoi("2f51"));
    printf("Should be 809149: %d\n", htoi("c58bD"));

    // with 0x at beginning

    printf("Should be 12113: %d\n", htoi("0x2f51"));
    printf("Should be 809149: %d\n", htoi("0xc58bD"));

    // oddballs with non-hex characters

    printf("Should be 0: %d\n", htoi(""));
    printf("Should be 0: %d\n", htoi("^^^^"));
    printf("Should be 0: %d\n", htoi("     "));
    printf("Should be 0: %d\n", htoi("!\nYo\t\a"));
    printf("Should be 0: %d\n", htoi("000"));
    printf("Should be 0: %d\n", htoi("0HK"));
    printf("Should be 0: %d\n", htoi("\05"));
    printf("Should be 4: %d\n", htoi("4HK"));
    printf("Should be 103: %d\n", htoi("6Z7Z"));
    printf("Should be 103: %d\n", htoi("-6Z7Z"));
    printf("Should be 365307: %d\n", htoi("M592FSUB"));

    return 0;
}