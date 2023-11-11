#include <stdio.h>
#include <stdbool.h>
#include <math.h>

bool isPrime(int n) {
    int end = sqrt(n)+1;
    for (int i=2; (i<=end) && (i!=n); i++) {
        if (n % i == 0) {
            return false;
        }
    }
    return true;
}

int main()
{
    int n;
    scanf_s("%d", &n);

    printf("%d=",n);

    bool first=true;
    for (int i=2; (n>0) && (i<=n); (n%i!=0)?(i++):i) {
        if (n%i==0) {
            printf("%s%d",first?"":"*",i);
            first=false;
            n /= i;
        }
    }

    printf("\n");
    return 0;
}
