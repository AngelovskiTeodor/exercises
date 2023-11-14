#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int letterToDigit(char letter){
    switch (letter) {
    case 'A':
    case 'B':
    case 'C':
        return 2;
    break;
    case 'D':
    case 'E':
    case 'F':
        return 3;
    break;
    case 'G':
    case 'H':
    case 'I':
        return 4;
    break;
    case 'J':
    case 'K':
    case 'L':
        return 5;
    break;
    case 'M':
    case 'N':
    case 'O':
        return 6;
    break;
    case 'P':
    case 'Q':
    case 'R':
        return 7;
    break;
    case 'S':
    case 'T':
    case 'U':
        return 8;
    break;
    case 'V':
    case 'W':
    case 'X':
        return 9;
    break;
    case 'Y':
    case 'Z':
        return 0;
    break;
    default:
        return -1;
    break;
    }
}

long int digitsToNumber(int digits[7]){
    long int num = 0;
    for (int i=0; i<7; i++) {
        num *= 10;
        num += digits[i];
    }
    return num;
}

int charToDigit(char c){
    return (int) c - (int) '0';
}

void numberToString(char number[8]){
    char *letters[10];
    letters[2] = "ABC";
    letters[3] = "DEF";
    letters[4] = "GHI";
    letters[5] = "JKL";
    letters[6] = "MNO";
    letters[7] = "PQR";
    letters[8] = "STU";
    letters[9] = "VWX";
    letters[0] = "YZ";

    printf("Possible strings for number %s: \n", number);
    for (int i=0; i<3; i++) {
        for (int j=0; number[j] != '\0' && j<7; j++) {
            if (number[j] == '1') {
                continue;
            }
            if ( number[j] == '0' && i == 3) {
                continue;
            }
            printf("%c", letters[ charToDigit(number[j]) ][i] );
        }
        printf("\n");
    }
}

int main()
{
    printf("Enter a string with 7 CAPITAL LETTERS: ");
    char letters[8];
    scanf_s("%s", letters);

    int numberDigits[7];
    int i=0;
    while (letters[i] != '\0' && i<7) {
        numberDigits[i] = letterToDigit(letters[i]);
        i++;
    }

    long int number = digitsToNumber(numberDigits);
    printf("The number is %ld\n", number);

    char numberString[8];
    printf("Enter a number with 7 digits: ");
    scanf_s("%s", numberString);

    numberToString(numberString);

    printf("\n");
    return 0;
}
