#include <stdio.h>
#include <stdlib.h>

int main() {

    int r, a, b;

    puts("100 Random Numbers");
    for (a = 0; a < 20; a++) {
        for (b = 0; b < 5; b++) {
            r = rand();
            printf("%d\t", r);
        }
        putchar('\n');
    }

    return (0);
}
