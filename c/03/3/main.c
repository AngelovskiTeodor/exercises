#include <stdio.h>

int main()
{
    int a, b;
    scanf_s("%d", &a);
    scanf_s("%d", &b);

    int r1 = a % 2;
    int r2 = b % 2;

    if (r1) {
        printf_s("The first number is ODD\n");
    }
    else {
        printf_s("The first number is EVEN\n");
    }

    if (r2) {
        printf_s("The second number is ODD\n");
    }
    else {
        printf_s("The second number is EVEN\n");
    }

    return 0;
}
