#include <stdio.h>

int main()
{
    int a, b;
    scanf_s("%d", &a);
    scanf_s("%d", &b);

    printf_s("%d and %d\n", a, b);

    if (a == b) {
        printf_s("Broevite se ednakvi\n");
        return 0;
    }

    if (a > b) {
        printf_s("%d e pogolem od %d\n",a,b);
        printf_s("%f e pogolem od %f\n",a,b);   //  printing as float instead of integer
        return 0;
    }
    else if (b > a) {
        printf_s("%d e pogolem od %d\n",b,a);
        printf_s("%f e pogolem od %f\n",b,a);   //  printing as float instead of integer
        return 0;
    }
    else {
        // should never execute
        printf_s("Error");
        return -1;
    }
}
