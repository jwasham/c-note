/* dice: Gather statistics about rolling
 * two dice.  A Monte Carlo simulation using
 * the random number generator rand()
*/
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void initarray(int d[]);

void printarray(int d[]);

void printstar(int n);

void fancyprint(int d[]);

int roll(void);

int numrolls;

int main(void) {

    int d[13]; /* 2-12 hold num of rolls */
    int i;     /* loop variable */
    int starttime = time(NULL); /* clock time */
    srand((long) starttime);
    printf("Enter # of rolls ---> ");
    scanf("%i", &numrolls); /* need & on var */

    initarray(d);
    printf("Total rolls: %1d\n\n", numrolls);

    for (i = 0; i < numrolls; i++)
        d[roll() + roll()]++;
    printarray(d);
    fancyprint(d);
    printf("Elapsed time: %ld seconds\n",
           time(NULL) - starttime);
    return 0;
}

/* initarray: initialize statistic array */
void initarray(int d[]) {
    int i;
    for (i = 2; i < 13; i++)
        d[i] = 0;
}

/* printarray: print each num of rolls */
void printarray(int d[]) {
    int i;
    double e[] = {0, 0,
                  1.0 / 36.0, 2.0 / 36.0, 3.0 / 36.0, 4.0 / 36.0,
                  5.0 / 36.0, 6.0 / 36.0, 5.0 / 36.0, 4.0 / 36.0,
                  3.0 / 36.0, 2.0 / 36.0, 1.0 / 36.0};
    printf("Sum  Times   Frequency");
    printf("      Exact    Diff\n\n");
    for (i = 2; i < 13; i++)
        printf("%2d %7d %11.7f %10.7f %8.4f\n",
               i,
               d[i],
               (double) d[i] / numrolls * 100.0,

               e[i] * 100.0,
               ((double) (d[i]) -
                e[i] * numrolls) / numrolls * 100.0);
}

/* printstar: print n stars */
void printstar(int n) {
    while (n > 0) {
        printf("*");
        n--;
    }
}

/* fancyprint: print bar graph */
void fancyprint(int d[]) {
    int i;
    printf("\n");
    for (i = 2; i < 13; i++) {
        printf("Sum:%3d |", i);

        printstar(300 * d[i] / numrolls);

        printf("\n");
    }
    printf("\n");
}

/* roll: simulate rolling a die */
int roll(void) {
    return (int) (6.0 * (rand() / (double) RAND_MAX)
                  + 1.0);
}