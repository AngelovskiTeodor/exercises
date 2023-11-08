#include <stdio.h>

int main()
{
    int a, b;
    scanf_s("%d", &a);
    scanf_s("%d", &b);

    float total = a + b;
    float average = total / 2.0;

    printf_s("The total is %.3f\n", total);
    printf_s("The average is %.3f\n", average);
}
