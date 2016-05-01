#include<stdio.h>
#include<conio.h>

char rev(char s[50], int, int);

void main() {
    int i, l;
    char a[50], b[50];
    clrscr();
    printf("Enter the string\n");
    gets(a);
    l = strlen(a);
    rev(a, 0, l - 1);
    printf("Reverse string is:");
    puts(a);
    getch();
}

char rev(char *s, int beg, int end) {
    char p;
    if (beg >= end) {
        return 0;
    }
    else {
        p = *(s + beg);
        *(s + beg) = *(s + end);
        *(s + end) = p;
        return rev(s, ++beg, --end);
    }
}