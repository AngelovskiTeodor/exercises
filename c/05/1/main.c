/* Program p05_02.c
   Sumiranje so for */
#include <stdio.h>

/* pochnuva izvrshuvanjeto na programot */
int main()
{
    int sum; /* inicijaliziraj sum */
    int number;  /* brojot shto kje mu bide dodaden na sum */

    for ( number = 2, sum = 0; number <= 100; number += 2 ) {
        sum += number; /* dodaj broj na sum */
    } /* kraj for */

    printf( "Sumata e %d\n", sum ); /* ispechati suma */

    return 0; /* programot uspeshno zavrshil */

} /* kraj na main */
