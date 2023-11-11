#include <stdio.h>

void printIntervalRecursive(int start, int current, int end, int direction) {
    if (start == 0) {
        direction = 1;
        start += direction;
        current = start;
    }

    printf("%d ", current);

    if (current >= end) {
        start += direction;
        printf("\n");
        if (start > end) {return;}
        else {return printIntervalRecursive(start, start, end, direction);}
    }
    printIntervalRecursive(start, ++current, end, direction);
}

int main()
{
    int n;
    printf("n=");
    scanf_s("%d", &n);
    printIntervalRecursive(n, n, n, -1);
    return 0;
}
