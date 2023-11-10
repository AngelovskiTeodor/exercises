#include <stdio.h>

void sort(int *a, int n) {
    int tempValue, tempIndex;
    for (int i=0; i<n-1; i++) {
        tempIndex = i;
        for (int j=i; j<n; j++) {
            if (a[j] < a[tempIndex]) {
                tempIndex = j;
            }
        }
        tempValue = a[i];
        a[i] = a[tempIndex];
        a[tempIndex] = tempValue;
    }
}

void recursiveSort(int *a, int n, int i, int j, int indexMin){
    if (j >= n) {
        int tempValue = a[i];
        a[i] = a[indexMin];
        a[indexMin] = tempValue;

        i++;
        j = i;
        recursiveSort(a, n, i, j, i);
        return;
    }
    if (i >= n-1) {
        return;
    }

    if (a[j] < a[indexMin]) {
        indexMin = j;
    }

    j++;
    recursiveSort(a, n, i, j, indexMin);
}

int main()
{
    int n;
    printf("Please enter the number of elements: ");
    scanf_s("%d", &n);

    int a[n];
    for (int i=0; i<n; i++) {
        printf("a[%d]=",i);
        scanf_s( "%d", a+i );
    }

    recursiveSort(a, n, 0, 0, 0);

    for (int i=0; i<n; i++) {
        printf("a[%d]=%d\n",i, a[i]);
    }

    return 0;
}
