#include <stdio.h>

const char* reverse(char* word, int len)
{
    int half = (len)/2 + 1; // added one for odd length
    int maxIndex = len - 1;
    static char rev[sizeof(word) + 1];

    for (int i = 0; i < half; i++) {
        rev[i] = word[maxIndex - i];
        rev[maxIndex - i] =  word[i];
    }

    rev[len] = '\0';

    return rev;
}

int main(int argc, char* argv[])
{
    char phrase[] = "go backwards";
    char time[] = "time";
    char odd[] = "odd";

    printf("should be 'sdrawkcab og': %s\n", reverse(phrase, sizeof(phrase)/sizeof(phrase[0]) - 1));
    printf("should be 'emit': %s\n", reverse(time, sizeof(time)/sizeof(time[0]) - 1));
    printf("should be 'ddo': %s\n", reverse(odd, sizeof(odd)/sizeof(odd[0]) - 1));
}