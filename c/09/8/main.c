#include <stdio.h>
#include <stdbool.h>

bool containsDigit(int num, int digit) {
    while (num > 0) {
        int temp = num % 10;
        num /= 10;
        if (temp = digit) {
            return true;
        }
    }
    return false;
}

bool digitInCube(int num, int digit){
    return containsDigit(num*num*num, digit);
}

bool digitInSquare(int num, int digit) {
    return containsDigit(num*num, digit);
}

bool digitInSquareAndCube(int num, int digit) {
    return digitInSquare(num, digit) || digitInCube(num, digit);
}


bool squareAndCubeContainAllDigits(int num){
    for (int i=0; i<10; i++) {
        if (!digitInSquareAndCube(num, i)) {
            return false;
        }
    }
    return true;
}

int main()
{
    int n1, n2;
    printf("Start of interval: ");
    scanf_s("%d", &n1);
    printf("End of interval: ");
    scanf_s("%d", &n2);

    for (int i=n1; i<=n2; i++) {
        if (squareAndCubeContainAllDigits(i)) {
            printf("%d ",i);
        }
    }

    printf("\n");
    return 0;
}
