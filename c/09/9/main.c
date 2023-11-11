#include <stdio.h>

int main()
{
    int n, i, j, k;
    float x;
    printf("n=");
    scanf_s("%d", &n);
    printf("i=");
    scanf_s("%d", &i);
    printf("j=");
    scanf_s("%d", &j);
    printf("x\%=");
    scanf_s("%d", &x);
    x = x/100.0;
    printf("k=");
    scanf_s("%d", &k);

    for (int counter = 1; counter<=k; counter++){
        if (counter % i == 0) {
            n = n*2;
        }
        if (counter % j == 0) {
            n = n*x;
        }
    }

    printf("in the end x=%d\n", x);
    return 0;
}
