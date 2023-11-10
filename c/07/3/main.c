#include <stdio.h>

int obratno(int num) {
    int reversed = 0;
    int digit;
    for (int i=0; num>0; i++) {
        digit = num % 10;
        num = num / 10;
        reversed = reversed * 10 + digit;
    }
    return reversed;
}

int main()
{
    int num;
    printf("Please enter a number: ");
    scanf_s("%d", &num);

    printf("The reversed number is %d\n", obratno(num));

    return 0;
}
