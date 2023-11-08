#include <stdio.h>
#include <stdlib.h>

int main()
{
    char input[8];
    int num = 0;
    int sum = 0;
    scanf_s("%s", &input);

    if (input[0] == 'n') {
        printf_s("The sum is %d\n", sum);
        return 0;
    }

    while (input[0] != 'n') {
        num = atoi(input);
        sum += num;
        printf_s("");   //  why is it buggy if printf is not used before scanf?
        scanf_s("%s", &input);
    }

    printf_s("The sum is %d\n", sum);
    return 0;
}
