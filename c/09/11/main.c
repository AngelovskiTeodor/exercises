#include <stdio.h>
#include <stdbool.h>

void printSubarray(int* arr, int start, int end) {
    for (int i=start; i<=end; i++) {
        printf("a[%d]=%d\n",i, arr[i]);
    }
}

bool isAlternating(int* arr, int curr, int n) {
    int prev = (curr-1<0)?curr:curr-1;
    int succ = (curr+1>=n)?curr:curr+1;

    return (arr[prev] <= curr) && (curr >= arr[succ])
        || (arr[prev] >= curr) && (curr <= arr[succ]);

}

void findAlternatingSubarrays(int *arr, int n) {
    int start = 0;
    int end = 0;
    int alternatingSubarrays = 0;
    for (int i=1; i<n; i++) {
        if (isAlternating(arr, i, n)) {
            end = i+1;
        }
        else {
            if (end - start > 0) {
                alternatingSubarrays++;
                printf("Printing alternating subarray no.%d\n", alternatingSubarrays);
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

    findAlternatingSubarrays(a, n);

    return 0;
}
