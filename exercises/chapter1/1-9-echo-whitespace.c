#include <stdio.h>

int main()
{
    int c, p, i;
    int input[100];

    for (i = 0; i < 100; i++) {
        input[i] = 0;
    }

    p = 0;

    while ((c = getchar()) != EOF) {
        input[++p] = c;

        if (p == 100) {
            break;
        }
    }

    for (i = 0; i < 100; i++) {
        if (input[i] == '\t') {
            putchar('\\');
            putchar('t');
        } else if (input[i] == '\b') {
            putchar('\\');
            putchar('b');
        } else if (input[i] == '\\') {
            putchar('\\');
            putchar('\\');
        } else {
            putchar(input[i]);
        }
    }

    printf("\n");

    return 0;
}