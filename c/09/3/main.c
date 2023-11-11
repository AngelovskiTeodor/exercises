#include <stdio.h>

void printArray(int *arr, int size){
    for (int i=0; i< size; i++) {
        printf("%d", arr[i]);
    }
    printf_s("\n");
}

int countDigits (int num) {
    int i;
    for (i=0; num>0; i++) {
        num = num / 10;
    }
    return i;
}

void getReversedDigits(int digits[], int size, int num) {
    for (int i=0; num>0; i++) {
        digits[i] = num % 10;
        num = num / 10;
    }
}

int digitsToNumber(int digits[], int size) {
    int num = 0;
    for (int i = 0; i<size; i++) {
        num *= 10;
        num += digits[i];
    }
    return num;
}

int main()
{
    int num;
    scanf_s("%d", &num);

    int size = countDigits(num);

    int digits[size];
    getReversedDigits(digits, size, num);

    printf_s("%d\n", digitsToNumber(digits, size));
    getchar();
    return 0;
}
