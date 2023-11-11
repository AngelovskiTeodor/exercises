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

int opposite(int num) {
    int size = countDigits(num);
    int digits[size];
    getReversedDigits(digits, size, num);
    return digitsToNumber(digits, size);
}

int main()
{
    int n1, n2;
    printf("Start of interval: ");
    scanf_s("%d",&n1);
    printf("End of interval: ");
    scanf_s("%d",&n2);

    for (int i=n1; i<=n2; i++) {
        int oppositeNumber = opposite(i);
        if (i % oppositeNumber == 0) {
            printf("%d ",i);
        }
    }

    printf("\n");
    return 0;
}
