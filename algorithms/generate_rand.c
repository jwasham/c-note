#include <time.h>
#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    int num;
    /* Seed number for rand() */
    srand((unsigned int) time(0) + getpid());
    printf("\nGenerating a random number using srand and rand function.\n");
    num = rand();

    printf("%d\n", num);

    return EXIT_SUCCESS;
}