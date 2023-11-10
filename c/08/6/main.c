#include <stdio.h>
#include <stdbool.h>

void printArray(int *a, int n) {
    for (int i=0; i<n; i++) {
        printf("array[%d]=%d\n", i, a[i]);
    }
}

void copyArray(int *dest, int *src, int size) {
    for (int i=0; i<size; i++) {
        dest[i] = src[i];
    }
}

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

bool contains(int *arr, int startingIndex, int n, int value) {
    for (int i=startingIndex; i<n; i++) {
        if (arr[i] == value) {
            return true;
        }
    }
    return false;
}

int countValues(int *a, int n){
    int counter = 0;
    for (int i=0; i<n; i++) {
        if (!contains(a,0,i,a[i])) {
            counter++;
        }
    }
    return counter;
}

int countValuesSorted(int *a, int n) {
    int counter = 0;
    for (int i=0; i<n; i++) {
        if (i == 0) {
            counter++;
//            printf("Debugging countValuesSorted(): %d is a new value\n", a[i]);     //  debugging
            continue;
        }
        if (a[i] != a[i-1]) {
            counter++;
//            printf("Debugging countValuesSorted(): %d is a new value\n", a[i]);     //  debugging
        }
    }
    return counter;
}

void getValues(int *dest, int* src, int total, int elements){
    int j = 0;
    for (int i=0; i<elements; i++) {
        if (!contains(dest, 0, j, src[i])) {
            dest[j] = src[i];
            j++;
        }
    }
}

void getValuesSorted(int *dest, int* src, int total, int elements){
    int j = 0;
    for (int i=0; i<elements; i++) {
        if (i == 0) {
            dest[j] = src[i];
            j++;
            continue;
        }
        if (src[i] != src[i-1]) {
            dest[j] = src[i];
            j++;
        }
    }
}

int findMaxValue(int *a, int n) {
    int max = a[0];
    for (int i=0; i<n; i++) {
        if (a[i] > max) {
            max = a[i];
        }
    }
    return max;
}

int findMaxValueSorted(int *a, int n) {
    return a[n-1];
}

void initEmptyArray(int *a, int n){
    for (int i=0; i<n; i++) {
        a[i]=0;
    }
}

int calculateSum(int *a, int n){
    int sum = 0;
    for (int i=0; i<n; i++) {
        sum+=a[i];
    }
    return sum;
}

float calculateAverage(int *a, int n){
    int sum = calculateSum(a, n);
    float avg = sum / (float) n;
    return avg;
}

float findMedianSorted(int *a, int n) {
    if (n%2){
        return (a[(n/2)-1] + a[n/2]) / 2.0;
    }
    return a[n/2];
}

void calculateFrequencies(int *src, int elements, int *map){
    for (int i=0; i<elements; i++) {
        map[src[i]]++;
    }
}

void printFrequencies(int *map, int *keys, int total) {
    for (int i=0; i<total; i++) {
        printf("There %s %d elements with the value %d\n", (map[ keys[i] ] == 1)?("is"):("are"), map[ keys[i] ], keys[i]);
    }
}

void drawBar(int length){
    for (int i=0; i<length; i++) {
        printf_s("*");
    }
    printf("\n");
}

void drawHistogram(int *map, int *keys, int total) {
    for (int i=0; i<total; i++) {
        printf("%3d|", keys[i]);
        drawBar(map[keys[i]]);
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

    int sorted[n];
    copyArray(sorted, a, n);
    sort(sorted, n);
//    printf("Debugging sorted array: \n");printArray(sorted, n);    //  debugging

    int totalValues = countValuesSorted(sorted, n);
//    printf("There are %d different values in the array.\n", totalValues);   //  debugging
    int values[totalValues];
//    printf("Debugging values before initializing : \n");printArray(values, totalValues);    //  debugging
    getValuesSorted(values, sorted, totalValues, n);    //  TODO: debugging
//    printf("Debugging values before sorting: \n");printArray(values, totalValues);    //  debugging
    int sortedValues[totalValues];
    copyArray(sortedValues, values, totalValues);
    sort(sortedValues, totalValues);
//    printf("Debugging sorted values: \n");printArray(values, totalValues);    //  debugging

    int maxValue = findMaxValueSorted(sortedValues, totalValues);
    int map[maxValue+1];    //  keys are the different elements from the array. the stored values are the frequencies for each element
    initEmptyArray(map, maxValue+1);
    calculateFrequencies(a, n, map);
//    printf("Debugging original array: \n");printArray(a, n);    //  debugging
//    printf("Debugging map: \n");printArray(map, maxValue+1);    //  debugging

    printf("The average is %.2f\n", calculateAverage(a,n));
    printf("The median is %.1f\n", findMedianSorted(sorted,n));
    printFrequencies(map, sortedValues, totalValues);
    drawHistogram(map, sortedValues, totalValues);

    return 0;
}
