#include <stdio.h>
#include <ctype.h>
#include <stdbool.h>

int main(int argc, char *argv[]) {

    int c;
    char *p;
    char lower[] = "lower";
    char upper[] = "upper";

    for (p = argv[0]; *p == '.' || *p == '/'; p++)
        ;

    printf("Filename: %s\n", p);
    printf("Output:\n");

    bool isUpper = (strcmp(p, upper) == 0);
    bool isLower = (strcmp(p, lower) == 0);

    while ((c = getchar()) != EOF) {
        if (isUpper) {
            putchar(toupper(c));
        } else if (isLower) {
            putchar(tolower(c));
        }
    }

    return 0;
}
