#include <stdio.h>

int getWeekday(int month, int day, int lastTwoDigits, int firstYearDigits);

int getRest(int value);

int getQuotient(int yearDigits);

int truncate(int month);

int getFirstTwoDigitsFromYear(int year);

int getLastTwoDigitsFromYear(int year);

typedef struct Date
{
    int month;
    int day;
    int year;
} DateStructure;

int main(void)
{
    DateStructure date;

    scanf("%d %d %d", &date.day, &date.month, &date.year);

    do
    {
        int lastTwoDigits = getLastTwoDigitsFromYear(date.year);
        int firstTwoDigits = getFirstTwoDigitsFromYear(date.year);
        int weekday = getWeekday(date.month, date.day, lastTwoDigits, firstTwoDigits);
        char *weekdayName[1];

        switch (weekday)
        {
        case 0:
            weekdayName[0] = "Domingo";
            break;
        case 1:
            weekdayName[0] = "Segunda-feira";
            break;
        case 2:
            weekdayName[0] = "Terça-feira";
            break;
        case 3:
            weekdayName[0] = "Quarta-feira";
            break;
        case 4:
            weekdayName[0] = "Quinta-feira";
            break;
        case 5:
            weekdayName[0] = "Sexta-feira";
            break;
        case 6:
            weekdayName[0] = "Sábado";
            break;
        }

        printf("%02d/%02d/%d: %s\n", date.day, date.month, date.year, *weekdayName);

        scanf("%d %d %d", &date.day, &date.month, &date.year);
    } while (date.day != 0 && date.month != 0 && date.year != 0);
}

int truncate(int month)
{
    return (int)(2.6 * month - 0.1);
}

int getQuotient(int yearDigits)
{
    return yearDigits / 4;
}

int getRest(int value)
{
    return value % 7;
}

int getLastTwoDigitsFromYear(int year)
{
    return year % 100;
}

int getFirstTwoDigitsFromYear(int year)
{
    return (int)(year / 100);
}

int getWeekday(int month, int day, int lastTwoDigits, int firstTwoDigits)
{
    int formatedMonth = month < 3 ? month + 10 : month - 2;
    int calculate = truncate(formatedMonth) + day + lastTwoDigits + getQuotient(lastTwoDigits) + getQuotient(firstTwoDigits) - (2 * firstTwoDigits);
    int rest = getRest(calculate) < 0 ? getRest(calculate) + 7 : getRest(calculate);
    return rest;
}