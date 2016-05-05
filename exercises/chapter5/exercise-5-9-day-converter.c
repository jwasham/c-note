#include <stdio.h>

static char daytab[2][13] = {
    {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31},
    {0, 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31}
};

/* With Pointers */

int day_of_year_pointer(int year, int month, int day)
{
    int i, leap;
    char *p;

    if (month < 1 || month > 12 || year < 0 || year > 9999 || day < 1 || day > 31) {
        printf("Invalid date\n");
        return 0;
    }

    leap = year%4 == 0 && year%100 != 0 || year%400 == 0;

    p = &daytab[leap][1];

    for (i = 1; i < month; i++)
        day += *p++;

    return day;
}

void month_day_pointer(int year, int yearday, int *pmonth, int *pday)
{
    int i, leap;
    char *p;

    if (yearday < 1 || yearday > 366 || year < 0 || year > 9999) {
        printf("Invalid date\n");
        return;
    }

    leap = year%4 == 0 && year%100 != 0 || year%400 == 0;

    p = &daytab[leap][1];

    for (i = 1; yearday > *p; i++)
        yearday -= *p++;

    *pday = yearday;
    *pmonth = i;
}


int main()
{
    int day;
    int month;
    int year = 1977;
    int yearday;

    yearday = day_of_year_pointer(year, 5, 25);

    month_day_pointer(year, yearday, &month, &day);

    if (yearday > 0) {
        printf("yearday: %d\n", yearday);
        printf("date: %d/%d/%d\n", month, day, year);
    }
}
