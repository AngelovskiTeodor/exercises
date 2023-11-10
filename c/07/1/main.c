#include <stdio.h>

int paren(int num) {
    return !(num%2);
}

int main()
{
    int num;
    for (int i=0; i<10; i++) {
        printf("");
        scanf_s("%d", &num);
        printf("%d\n", paren(num));
    }
    return 0;
}
