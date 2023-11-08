#include <stdio.h>

int printStarsInTheMiddle(int numOfStars, int graphicSize) {
    if (graphicSize < numOfStars) {
        //  throw Exception in C++
        printf_s("Graphics size is to small to print %d stars", numOfStars);
        return -1;
    }
    int blankSpacesBefore = (graphicSize-numOfStars)/2;

    for (int i=0; i<blankSpacesBefore; i++) {
        printf_s(" ");
    }

    for (int i=0; i<numOfStars; i++) {
        printf_s("*");
    }

    printf_s("\n");
    return 0;
}

int printTwoStarsWithEmptySpaceInBetween(int numOfBlankSpaces, int graphicSize) {
    if (graphicSize-2 < numOfBlankSpaces) {
        //  throw Exception in C++
        printf_s("Graphics size is to small to print two stars separated with %d blank spaces\n", numOfBlankSpaces);
        return -1;
    }

    int blankSpacesBefore = (graphicSize-numOfBlankSpaces-2)/2;
    //printf_s("blanks before printing: %d\n", blankSpacesBefore);

    for (int i=0; i<blankSpacesBefore; i++) {
        printf_s(" ");
    }

    printf_s("*");

    for (int i=0; i<numOfBlankSpaces; i++) {
        printf_s(" ");
    }

    printf_s("*\n");
}

int printRectangle(int height, int width) {
    for (int i=0; i<height; i++) {
        if (i==0) {
            printStarsInTheMiddle(width, width);
            continue;
        }
        if (i==height-1) {
            printStarsInTheMiddle(width,width);
            continue;
        }
        printTwoStarsWithEmptySpaceInBetween(width-2, width);
    }
}

int printCircle(int height, int width){
    printStarsInTheMiddle(3, width);

    int i;
    for (i = 1; i<(height-3)/2; i++) {
        printTwoStarsWithEmptySpaceInBetween(i*2+1, width);
    }

    for (int j=0; j<3; j++) {
        printTwoStarsWithEmptySpaceInBetween(width-2, width);
    }

    for (i=(height-3)/2-1; i>0; i--){
        printTwoStarsWithEmptySpaceInBetween(i*2+1, width);
    }

    printStarsInTheMiddle(3, width);
}

int printArrow(int height, int width){
    for (int i=1; i<=width; i+=2){
        printStarsInTheMiddle(i, width);
    }
    for (int i=0; i<height-width/2; i++){
        printStarsInTheMiddle(1,width);
    }
}

int printDiamond(int size){
    printStarsInTheMiddle(1, size);

    int i;
    for (i=1; i<size; i+=2) {
        printTwoStarsWithEmptySpaceInBetween(i, size);
    }
    for (i-=4; i>0; i-=2) {
        printTwoStarsWithEmptySpaceInBetween(i, size);
    }

    printStarsInTheMiddle(1, size);
}

int main()
{
    int width1 = 5;
    int height1 = 7;
    int width2 = 7;

    printRectangle(height1, width1);
    printf("\n");

    printCircle(height1,width2);
    printf("\n");

    printArrow(height1, width2);
    printf("\n");

    printDiamond(width2);
    printf("\n");

    return 0;
}
