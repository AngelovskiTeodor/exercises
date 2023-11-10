#include <stdio.h>

int fibonacci(int n, int i, int prev, int curr) {
    printf_s("%d ", curr);
    i++;
    int next = prev + curr;
    if (i >= n-1) {return next;}
    return fibonacci(n, i, curr, next);
}

int main()
{
    printf("How many fibonacci numbers do you want to know? ");
    int n;
    scanf_s("%d", &n);

    printf("%d\n", fibonacci(n, 0, 1, 1));
    return 0;
}
