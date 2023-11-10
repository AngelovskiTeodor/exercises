#include <stdio.h>

void fibonacci(int n) {
    if (n<1) {return;}
    printf("1");
    //if (n<2) {return;}
    int prev = 1;
    int curr = 1;
    int next;
    for (int i=0; i<n-1; i++) {
        next = prev + curr;
        prev = curr;
        curr = next;
        printf_s(" %d", next);
    }
}

int main()
{
    printf("How many fibonacci numbers do you want to know? ");
    int n;
    scanf_s("%d", &n);

    fibonacci(n);
    printf("\n");

    return 0;
}
