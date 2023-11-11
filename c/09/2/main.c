#include <stdio.h>

void printSystem(float coefs[][4], int equasions, int vars){
    printf("The system of equasions is: \n");
    for (int i =0; i<equasions; i++) {
        for (int j=0; j<vars+1; j++) {
            if (j == vars) {
                printf(" = %.1f\n", coefs[i][j]);
                continue;
            }
            printf(" %s%.1f*(x%d)", (coefs[i][j] < 0)?"":((j==0)?"":"+"), coefs[i][j], j+1);
        }
    }
}

float determinant(float coefs[][4], int equasions, int vars) {
    float det = coefs[0][0] * (coefs[1][1] * coefs[2][2] - coefs[2][1] * coefs[1][2])
          - coefs[0][1] * (coefs[1][0] * coefs[2][2] - coefs[1][2] * coefs[2][0])
          + coefs[0][2] * (coefs[1][0] * coefs[2][1] - coefs[1][1] * coefs[2][0]);
    return det;
}

void solveEquasions(float coefs[][4], int equasions, int vars) {
    float d[3][3] = {
       { coefs[0][0], coefs[0][1], coefs[0][2] },
       { coefs[1][0], coefs[1][1], coefs[1][2] },
        { coefs[2][0], coefs[2][1], coefs[2][2] },
   };
    float d1[3][3] = {
        { coefs[0][3], coefs[0][1], coefs[0][2] },
        { coefs[1][3], coefs[1][1], coefs[1][2] },
        { coefs[2][3], coefs[2][1], coefs[2][2] },
    };
    float d2[3][3] = {
        { coefs[0][0], coefs[0][3], coefs[0][2] },
        { coefs[1][0], coefs[1][3], coefs[1][2] },
        { coefs[2][0], coefs[2][3], coefs[2][2] },
    };
    float d3[3][3] = {
        { coefs[0][0], coefs[0][1], coefs[0][3] },
        { coefs[1][0], coefs[1][1], coefs[1][3] },
        { coefs[2][0], coefs[2][1], coefs[2][3] },
    };

    float D = determinant(d, equasions, vars);
    float D1 = determinant(d1, equasions, vars);
    float D2 = determinant(d2, equasions, vars);
    float D3 = determinant(d3, equasions, vars);

    if (D != 0) {
        double x1 = D1 / D;
        double x2 = D2 / D;
        double x3 = D3 / D;
        printf("The solution for x1 is %.1f\n", x1);
        printf("The solution for x2 is %.1f\n", x2);
        printf("The solution for x3 is %.1f\n", x3);
    }
    else {
        if (D1 == 0 && D2 == 0 && D3 == 0)
            printf("This system of equasions has infinite number of solutions\n");
        else if (D1 != 0 || D2 != 0 || D3 != 0)
            printf("This system of equasions has no solutions\n");
    }
}

int main()
{
    const int equasions = 3;
    const int vars = 3;

    float coefs[equasions][vars+1];     //  we need to save the value on the right-hand side as one extra coefsicient
    for (int i =0; i<equasions; i++) {
        for (int j=0; j<vars+1; j++) {
            if (j == vars) {
                printf("Enter right-hand side value for equasion no. %d: ", i+1);
                scanf_s("%f", &coefs[i][j]);
                continue;
            }
            printf("Enter coefficient no. %d for equasion no. %d: ", j+1, i+1);
            scanf_s("%f", &coefs[i][j]);
        }
    }

    printSystem(coefs, equasions, vars);

    solveEquasions(coefs, equasions, vars);
    return 0;
}
