#include <stdio.h>

void incrementNumber(int *num){
    (*num)++;
}

int main()
{
    int x = 15399;
    printf_s("Initial value of x is %d\n", x);
    x++;
    printf_s("The new value of x is %d\n", x);
    x+=1;
    printf_s("The new value of x is %d\n", x);
    int increment = 1;
    x = x + increment;
    printf_s("The new value of x is %d\n", x);
    incrementNumber(&x);
    printf_s("The new value of x is %d\n", x);
    return 0;
}
