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

int countPrimesToN(int n) {
    int counter = 0;
    for (int i=2; i<=n; i++) {
        if (isPrime(i)) {
            counter++;
        }
    }
    return counter;
}

int* primesToN(int n, int *size) {
    (*size) = 0;
    int primesArrTemp[n];
    for (int i=2; i<=n; i++) {
        if (isPrime(i)) {
            primesArrTemp[i] = i;
            (*size)++;
        }
    }

    int primesArr[(*size)];
    for (int i=0; i<(*size); i++) {
        primesArr[i] = primesArrTemp[i+2];
    }
    return primesArr;
}

void prosti(int *arr, int n) {
    for (int i=1; i<n; i++) {
        if (isPrime(i+1)) {
            arr[i] = 0;
        }
    }
}

void printPrimes(int *arr, int n) {
    for (int i=0; i<n; i++) {
        if (!arr[i]) {
            printf_s("%d\n", i+1);
        }
    }
}

int main()
{
    int n;
    printf_s("Set array size: ");
    scanf_s("%d", &n);

    int arr[n];
    for (int i=0; i<n; i++) {
        arr[i] = 1;
    }

    prosti(arr, n);
    printPrimes(arr, n);

    return 0;
}
