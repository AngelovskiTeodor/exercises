#include <stdio.h>

int main()
{
    int a, b, c, sum, prod;
    float avg;
    scanf_s("%d", &a);
    scanf_s("%d", &b);
    scanf_s("%d", &c);

    sum = a + b + c;
    printf_s("The sum is %d \n", sum);

    avg = sum / 3.0;
    printf_s("The average is %f \n", avg);

    prod = a*b*c;
    printf_s("The product is %d \n", prod);

    getchar();
    return 0;
}
