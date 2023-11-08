#include <stdio.h>

int main()
{
    char letters[5];
    for (int i=0; i<5; i++) {
        scanf_s("%c",&letters[i]);
    }

    int desiredOrderOfPrinting[5] = {5, 3, 2, 1, 4};
    for (int i=0; i<5; i++) {
        printf_s("%c ", letters[ desiredOrderOfPrinting[i]-1 ]);
    }

    getchar();
    return 0;
}
