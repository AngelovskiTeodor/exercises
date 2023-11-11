#include <stdio.h>
#include <stdbool.h>

bool isSumOfCubesEqualToN(int n){
    int nTemp;
    int sum = 0;
    while (nTemp>0) {
        int digit = nTemp%10;
        nTemp /= 10;
        sum += (digit*digit*digit);
    }
    return sum == n;
}

int main()
{
    int n;
    scanf_s("%d", &n);

    for (int i=1; i<=n; i++) {
        if (isSumOfCubesEqualToN(i)) {
            printf_s("%d ", i);
        }
    }

    printf("\n");
    return 0;
}
