#include <stdio.h>

int main()
{
    int m;      //  number of rows
    int n;      //  number of columns
    printf("Enter number of rows: ");
    scanf_s("%d", &m);
    printf("Enter number of columns: ");
    scanf_s("%d", &n);

    int a[m][n];
    int counter = 1;
    for (int j=0; j<n; j++) {
        for (int i=0; i<m; i++) {
            a[
                (j%2==0) ? i : m-1-i
            ][j] = counter;
            counter++;
        }
    }

    for (int i=0; i<m; i++) {
        for (int j=0; j<n; j++) {
            printf("%3d",a[i][j]);
        }
        printf("\n");
    }

    printf("\n");
    return 0;
}
