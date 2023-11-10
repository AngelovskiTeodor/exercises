#include <stdio.h>

int main()
{
    int month[13];
    month[0] = 4;   //  test and debugging
    month[1] = 31;
    month[2] = 28;
    month[3] = 31;
    month[4] = 30;
    month[5] = 31;
    month[6] = 30;
    month[7] = 31;
    month[8] = 31;
    month[9] = 30;
    month[10] = 31;
    month[11] = 30;
    month[12] = 31;

    int choosedMonth;
    printf("Please choose a month: (number from 1 to 12) ");
    scanf("%d", &choosedMonth);

    float measurements[month[choosedMonth]];
    for (int i =0; i<month[choosedMonth]; i++) {
        printf("");
        scanf_s("%d", &measurements[i]);
    }

    return 0;
}
