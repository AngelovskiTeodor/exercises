#include <stdio.h>

float calculateWage(float revenue) {
    return 200 + (revenue * 0.09);
}

int main()
{
    float revenue = 0;
    while (revenue != -1.0) {
        printf_s("Vnesi promet vo evra (-1 za kraj): ");
        scanf_s("%f", &revenue);
        if (revenue == -1.0) {
            break;
        }
        printf_s("Platata e: %.2f evra\n", calculateWage(revenue));
    }
    return 0;
}
