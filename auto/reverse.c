#include <stdio.h>

const char* reverse(char* word, int len)
{
    int half = len/2;
    static char rev[sizeof(word) + 1];

    printf("%s\n", word);
    printf("%d\n", len);
    printf("%d\n", half);

    for (int i = 0; i < half; i++) {
        rev[i] =  word[len - i];
        rev[len - i] =  word[i];
    }

    rev[len] = '\0';

    return rev;
}

int main(int argc, char* argv[])
{
    char word[] = "go backwards";
    int length = sizeof(word)/sizeof(word[0]);

    printf("should be 'sdrawkcab og': %s\n", reverse(word, length));
}