#include <stdio.h>

/* print Celsius-Fahrenheit table
    for celsius = 0, 20, ..., 300 */

int main()
{
    float fahr, celsius;
    int lower, upper, step;

    lower = -20;
    upper = 150;
    step = 5;

    celsius = lower;

    printf(" C     F\n");
    printf("___   ___\n");

    while (celsius <= upper) {
        fahr = ((9.0/5.0) * celsius) + 32.0;
        printf("%6.1f  %3.1f\n", celsius, fahr);

        celsius += step;
    }
}