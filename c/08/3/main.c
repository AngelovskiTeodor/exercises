#include <stdio.h>
#include <string.h>

int palindrom(char *word) {
    int len = strlen(word);
    for (int i=0; i<len/2; i++) {
        if (word[i] != word[len-1-i]) {
            return 0;
        }
    }
    return 1;
}

int main()
{
    char word[32];
    printf("Please enter a word: ");
    scanf_s("%s", word);

    printf("%d", palindrom(word));

    return 0;
}
