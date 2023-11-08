#include <stdio.h>

int main()
{
    int input;
    int sum = 0;
    scanf_s("%d", &input);
    while (input != -1) {
        sum += input;
        scanf_s("%d", &input);
    }
    printf_s("The sum is %d", sum);
    return 0;
}
