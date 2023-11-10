#include <stdio.h>

int pogolem(int a, int b) {
    return (a<b) ? b : a ;
}

int pomal(int a, int b) {
    return (a<b) ? a : b ;
}

int nzd(int a, int b) {
    int nzd = 1;
    for (int i=1; i<=pomal(a,b); i++) {
        if ((a%i==0) && (b%i==0)) {
            nzd = i;
        }
    }
    return nzd;
}

int main()
{
    int a, b;
    printf("");
    scanf_s("%d", &a);
    printf("");
    scanf_s("%d", &b);
    printf("%d\n", nzd(a,b));
    return 0;
}
