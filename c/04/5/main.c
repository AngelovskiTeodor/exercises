#include <stdio.h>

int main()
{
    int input;
    int prod = 1;
    for (int i=0; i<10; i++) {
        scanf_s("%d", &input);
        if (input ==0) {
            break;
        }
        prod *= input;
    }
    printf_s("The product is %d", prod);
    return 0;
}
