#include <stdio.h>
#include <stdlib.h>

int isPrintable(int ch)
{
    char *printable = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ1234567890 !\"#%&'()*+,-./:;<=>?[\\]^_{|}~\t\f\v\r\n";
    int found = 0;
    char *p = printable;

    while (found == 0 && *p != '\0') {
        if (*p++ == ch) {
            found = 1;
        }
    }

    return found;
}

int main(int argc, char *argv[])
{
    int c;
    int lineLength = 80;
    int charCount = 0;

    while ((c = getchar()) != EOF) {
        charCount++;
        if (charCount > lineLength || c == '\n') {
            printf("\n");
            charCount = 0;
        }
        if (isPrintable(c)) {
            printf("%c", c);
        } else {
            printf("%x", c);
        }
    }

    return EXIT_SUCCESS;
}
