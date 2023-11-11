#include <stdio.h>

void printPolynomial(float* polynomial, int degree) {
    for (int i = degree; i>=0; i--) {
        printf("%+.1fx^%d",polynomial[i],i);
    }
    printf("\n");
}

int main()
{
    int n;      //  degree of the first polynomial
    int m;      //  degree of the second polynomial
    printf("Enter the degree of the first polynomial: ");
    scanf_s("%d", &n);
    printf("Enter the degree of the second polynomial: ");
    scanf_s("%d", &m);

    float first[n+1];   //  coefficients of the first polynomial
    float second[m+1];   //  coefficients of the second polynomial

    printf("Enter the coefficients of the first polynomial: ");
    for (int i=0; i<=n; i++) {
        printf("(x^%d)*",i);
        scanf_s("%f", &first[i]);
    }
    printf("Enter the coefficients of the second polynomial: ");
    for (int i=0; i<=m; i++) {
        printf("(x^%d)*",i);
        scanf_s("%f", &second[i]);
    }

    int lesser = (n<m)?n:m;
    int greater = (n>m)?n:m;

    float result[greater+1];    //  the addition of the polynomials
    for (int i=0; i<=lesser; i++) {
        result[i] = first[i] + second[i];
    }
    for (int i = lesser+1; i<=greater; i++) {
        result[i] = (n>m)?first[i]:second[i];
    }

    printPolynomial(result, greater);
    return 0;
}
