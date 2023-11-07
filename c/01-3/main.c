#include <stdio.h>

int main()
{
    printf("1 2 3 4\n");

    printf("%d %d %d %d\n", 1, 2, 3, 4);

    printf("1");
    printf("2");
    printf("3");
    printf("4");
    printf("\n");

    const int size = 4;
    int nums[size];
    for (int i=0; i<size; i++){
        nums[i] = i+1;
    }

    for (int i=0; i<size; i++){
        printf("%d", nums[i]);
    }
    printf("\n");

    getchar();
    return 0;
}
