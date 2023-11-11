#include <stdio.h>

void printSubarray(int* arr, int start, int end) {
    for (int i=start; i<=end; i++) {
        printf("a[%d]=%d\n",i, arr[i]);
    }
}

void findIncreasingSubarrays(int *arr, int n) {
    int start = 0;
    int end = 0;
    int increasingSubarrays = 0;
    for (int i=1; i<n; i++) {
        if (arr[i] >= arr[i-1]) {
            end = i;
        }
        else {
            if (end - start > 0) {
                increasingSubarrays++;
                printf("Printing increasing subarray no.%d\n", increasingSubarrays);
                printSubarray(arr, start, end);
                start = i;
                end = i;
            }
        }
    }
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

    findIncreasingSubarrays(a, n);

    return 0;
}
