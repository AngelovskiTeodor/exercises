#include <stdio.h>

void vnesiMatrica(int **m, int rows, int cols){
    for (int i=0; i<rows; i++) {
        for (int j=0; j<cols; j++) {
            printf("m[%d][%d]=",i,j);
            scanf_s( "%d", m+(rows*i)+j );
        }
    }
}

void pecatiMatrica(int **m, int rows, int cols){
    for (int i=0; i<rows; i++) {
        for (int j=0; j<cols; j++) {
            printf("%3d",*(m+i*rows+j));
        }
        printf("\n");
    }
}

void vnesiMatricaRecursive(int **m, int rows, int cols, int row, int col) {
    printf("m[%d][%d]=",row,col);
    scanf_s( "%d", m+(rows*row)+col );
    if (row+1 >= rows) {
        if (col+1 >= cols) {
            return;     //  end recursive iteration
        }
        col++;
        row = 0;
        vnesiMatricaRecursive(m, rows, cols, row, col);
        return;
    }
    row++;
    vnesiMatricaRecursive(m, rows, cols, row, col);
}

void pecatiMatricaRecursive(int **m, int rows, int cols, int row, int col) {
    printf("%3d",*(m+row*rows+col));
    if (row+1 >= rows) {
        if (col+1 >= cols) {
            return;     //  end recursive iteration
        }
        col++;
        printf("\n");
        row = 0;
        pecatiMatricaRecursive(m, rows, cols, row, col);
        return;
    }
    row++;
    pecatiMatricaRecursive(m, rows, cols, row, col);
}

int main()
{
    int rows, cols;
    printf("Please enter number of rows: ");
    scanf_s("%d", &rows);
    printf("Please enter number of columns: ");
    scanf_s("%d", &cols);

    int m[cols][rows];

    printf("Iterative:\n");
    vnesiMatrica(m, rows, cols);
    pecatiMatrica(m, rows, cols);

    printf("Recursive:\n");
    vnesiMatricaRecursive(m, rows, cols, 0, 0);
    pecatiMatricaRecursive(m, rows, cols, 0, 0);

    return 0;
}
