#include <stdio.h>

static char daytab[2][13] = {
    {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31},
    {0, 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31}
};

int day_of_year(int year, int month, int day)
{
    int i, leap;

    if (month < 1 || month > 12 || year < 0 || year > 9999 || day < 1 || day > 31) {
        printf("Invalid date\n");
	return 0; 
    }

    leap = year%4 == 0 && year%100 != 0 || year%400 == 0;
    for (i = 1; i < month; i++)
        day += daytab[leap][i];

    return day;
}

void month_day(int year, int yearday, int *pmonth, int *pday)
{
    int i, leap;

    if (yearday < 1 || yearday > 366 || year < 0 || year > 9999) {
        printf("Invalid date\n");
        return;
    }

    leap = year%4 == 0 && year%100 != 0 || year%400 == 0;
    for (i = 1; yearday > daytab[leap][i]; i++)
        yearday -= daytab[leap][i];
    *pday = yearday;
    *pmonth = i;
}

int main()
{
    int day;
    int month;
    int year = 19732;
    int yearday;

    yearday = day_of_year(year, 3, 10);

    month_day(year, yearday, &month, &day);

    if (yearday > 0) {
        printf("yearday: %d\n", yearday);
        printf("date: %d/%d/%d\n", month, day, year);
    }
}
