#include <stdio.h>

void calculateCheck(float *check, int *order, float *prices, int size)//=5)
{
    for (int i=0; i<size; i++) {
        check[i] = order[i] * prices[i];
    }
}

float printCheck(float *check, int *order, float *prices, int size)//=5)
{
    float total = 0;
    for (int i=0; i<size; i++) {
        total += check[i];
        printf_s("Product %d has been sold %d times for total price of %.2f\n",i+1, order[i], check[i]);
    }
    printf_s("The total price for all products is %.2f", total);
    return total;
}

int main()
{
    float prices[5] = {50.5,45.6,32.8,65.3,20.0};    //  the price for each product

    int order[5] = {0,0,0,0,0};     //  number of products in each order

    float check[5];     //  amount of money in the order for each product
    calculateCheck(check, order, prices, 5);

    int numIterations, productNumber, amount;
    printf_s("How many different products have been sold? ");
    scanf_s("%d", &numIterations);
    for (int i =0; i<numIterations; i++) {
        printf_s("Which product has been sold? ");
        scanf_s("%d", &productNumber);

        printf_s("How many items have been sold from product %d? ", productNumber);
        scanf_s("%d", &amount);
        order[productNumber-1] += amount;
    }

    calculateCheck(check, order, prices, 5);
    printCheck(check, order, prices, 5);

    return 0;
}
