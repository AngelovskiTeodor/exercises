#include <stdio.h>
#include <math.h>

float perimeter(int n, float a) {
    return n*a;
}

float area(int n, float a) {
    float h = 0.5 * (a / tan(M_PI/n));      //  distance from the center to the sides
    return perimeter(n,a) * h * 0.5;
}

int main()
{
    int n;
    printf("Please enter number of sides of the polygon: ");
    scanf_s("%d", &n);

    float a;
    printf("Please enter size for the side of the polygon: \n");
    scanf_s("%f", &a);

    printf("The perimeter is %.3f\n", perimeter(n,a));
    printf("The area is %.3f\n", area(n,a));
    return 0;
}
