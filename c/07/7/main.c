#include <stdio.h>

void dzvezdi(int n) {
    for (int i=0; i<n; i++) {
        printf_s("*");
    }
    printf("\n");
    n--;
    if (n <= 0) {return;}
    dzvezdi(n);
}

int main()
{
    printf("How many stars do you want? ");
    int n;
    scanf_s("%d", &n);

    dzvezdi(n);
    return 0;
}
