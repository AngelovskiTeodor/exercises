#include <stdio.h>

int main()
{
    int num;
    scanf_s("%d", &num);
    if ((num < 10000) || (num > 99999)) {
        printf_s("The number has less or more than 5 digits");
        return -1;
    }

    int digits[5];
    for (int i=0; (num>0) && (i<5); i++) {
        digits[i] = num % 10;
        num = num / 10;
    }

    for (int i=4; i>=0; i--){
        printf_s("%d   ",digits[i]);
    }

    printf_s("\n");
    getchar();
    return 0;
}
