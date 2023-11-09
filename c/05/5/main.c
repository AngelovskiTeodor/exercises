#include <stdio.h>

int main()
{
    for (int i=1; i<=100; i++) {
        if (i % 3 == 0) {
            continue;
        }
        else {
            printf_s("%d ne e deliv so 3\n", i);
        }
    }
    return 0;
}
