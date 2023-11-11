#include <stdio.h>
#include <stdbool.h>

bool isPerfect(int n) {
    int sum = 0;
    for (int i=1; i<n; i++) {
        if (n % i == 0) {
            sum += i;
        }
    }
    if (sum == n) {
        return true;
    }
    return false;
}

void printPerfectNumberToN(int n){
    for (int i=2; i<=n; i++) {
        if (isPerfect(i)) {
            printf_s("%d ", i);
        }
    }
    printf("\n");
}

int main()
{
    printf("Please enter a number: \n");
    int n;
    scanf_s("%d", &n);
    printPerfectNumberToN(n);
    return 0;
}
