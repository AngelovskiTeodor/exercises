#include <stdio.h>

int main()
{
    const float pi = 3.14;
    float radius;
    scanf_s("%f", &radius);
    float area = radius*radius*pi;
    float perimeter = 2*radius*pi;
    printf_s("The perimeter of a circle with radius %f is %f\n",radius,perimeter);
    printf_s("The area of a circle with radius %f is %f\n",radius,area);
    getchar();
    return 0;
}
