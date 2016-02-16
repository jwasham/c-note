#include <stdio.h>

int main()
{
    int c, blanks, tabs, newlines;

    blanks = 0;
    tabs = 0;
    newlines = 0;

    while ((c = getchar()) != EOF) {
        if (c == ' ') {
            blanks++;
        } else if (c == '\n') {
            newlines++;
        } else if (c == '\t') {
            tabs++;
        }
    }

    printf("Consisted of %d blanks, %d tabs, %d newlines.", blanks, tabs, newlines);
}