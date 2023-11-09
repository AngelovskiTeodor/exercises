#include <stdio.h>

int main()
{
    float fahrenheit;
    printf("Please enter temperature in fahrenheit: ");
    scanf("%f", &fahrenheit);

    float celsius = 5.0 / 9.0 * (fahrenheit - 32);

    printf("The temperature in celsius is %.3f\n", celsius);

    printf("%10s %10s\n", "fahrenheit", "celsius");
    printf("%+10f %+10f\n", fahrenheit, celsius);

    return 0;
}
