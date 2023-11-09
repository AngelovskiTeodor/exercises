#include <stdio.h>

int main()
{
    char *januari = "januari";
    char *fevruari = "fevruari";
    char *mart = "mart";
    char *april = "april";
    char *maj = "maj";
    char *juni = "juni";
    char *juli = "juli";
    char *avgust = "avgust";
    char *septemvri = "septemvri";
    char *oktomvri = "oktomvri";
    char *noemvri = "noemvri";
    char *dekemvri = "dekemvri";

    int year, month, day;
    printf("Please enter date: ");
    scanf("%d%*c%d%*c%d", &year, &month, &day);

    char *monthString;

    switch(month) {
    case 1:
        monthString = januari;
        break;
    case 2:
        monthString = fevruari;
        break;
    case 3:
        monthString = mart;
        break;
    case 4:
        monthString = april;
        break;
    case 5:
        monthString = maj;
        break;
    case 6:
        monthString = juni;
        break;
    case 7:
        monthString = juli;
        break;
    case 8:
        monthString = avgust;
        break;
    case 9:
        monthString = septemvri;
        break;
    case 10:
        monthString = oktomvri;
        break;
    case 11:
        monthString = noemvri;
        break;
    case 12:
        monthString = dekemvri;
        break;
    default:
        printf("Invalid month\n");
        return 0;
    }

    printf("Datumot e %d %s %d godina.\n", day, monthString, year);

    return 0;
}
