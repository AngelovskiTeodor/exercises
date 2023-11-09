#include <stdio.h>
#include <math.h>
#include <stdbool.h>

void printPitagorianNumbers(int a, int b, int c) {
    printf_s("a^2 + b^2 = c^2 => %d^2 + %d^2 = %d^2\n", a, b, c);
}

int calculateC(int a, int b) {
    int c_squared = a*a + b*b;
    int c = sqrt(c_squared);
    return c;
}

bool checkPitagorianNumbers(int a, int b, int c) {
    return a*a + b*b == c*c;
}

int main()
{
    int c;
    for (int i = 1; i<100; i++) {
        for (int j=i; j<100; j++) {
            c = calculateC(i,j);
            if (c > 100) {
                return 0;
            }
            printPitagorianNumbers(i,j,c);
        }
    }
    return 0;
}
