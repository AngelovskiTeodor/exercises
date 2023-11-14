/* Program za stek (magacin) */
#include <stdio.h>
#include <stdlib.h>

/* samo-referencirachka struktura */
struct stackNode {
    char character;
    struct stackNode *nextPtr; /* stackNode pokazhuvach */
}; /* kraj na strukturata stackNode */

typedef struct stackNode StackNode; /* sinonim za struct stackNode */
typedef StackNode *StackNodePtr; /* sinonim za StackNode* */

/* prototipovi */
StackNodePtr push( StackNodePtr topPtr, char character );
char pop( StackNodePtr *topPtr );
int isEmpty( StackNodePtr topPtr );
void printStack( StackNodePtr currentPtr );

/* pochetok na izvrshuvanjeto */
int main()
{
    StackNodePtr stackPtr = NULL; /* pokazhuva na vrvot na stekot */

    printf( "Enter a sentence: " );
    char sentence[50];
    //scanf( "%s", &sentence );
    gets(&sentence);

    char *c = sentence;
    while ((*c) != '\0') {
        stackPtr = push(stackPtr, *c);
        c++;
    }

    printStack( stackPtr );

    return 0; /* uspeshen kraj */
} /* kraj main */

/* Vnesi jazel na vrvot na stekot */
StackNodePtr push( StackNodePtr topPtr, char character )
{
    StackNodePtr newPtr; /* pokazhuvach do noviot jazel */
    newPtr = malloc( sizeof( StackNode ) );
    if ( newPtr == NULL ) {
        printf( "Unable to store %c in stack. Not enough memory.\n", character );
        return topPtr;
    }
    newPtr->nextPtr = topPtr;
    newPtr->character = character;
    return newPtr;
} /* kraj na funkcijata push */

/* Izvadi jazel od vrvot na stekot */
char pop( StackNodePtr *topPtr )
{
    StackNodePtr tempPtr; /* pokazhuvach do privremen jazol */
    char popValue; /* vrednost na jazelot */

    tempPtr = *topPtr;
    popValue = ( *topPtr )->character;
    *topPtr = ( *topPtr )->nextPtr;
    free( tempPtr );

    return popValue;
} /* kraj na funkcijata pop */

/* Ispechati go stekot */
void printStack( StackNodePtr currentPtr )
{
    /* ako stekot e prazen */
    if ( currentPtr == NULL ) {
        printf( "The stack is empty\n" );
    } /* kraj if */
    else {
        printf( "The sentence in reverse is: " );
        /* dodeka ne e kraj na stekot */
        while ( currentPtr != NULL ) {
            printf( "%c", currentPtr->character );
            currentPtr = currentPtr->nextPtr;
        } /* kraj while */

        printf( "\n" );
    } /* kraj else */
} /* kraj na funkcijata printList */

/* Vrati 1 ako stekot e prazen,0 inaku */
int isEmpty( StackNodePtr topPtr )
{
    return topPtr == NULL;
} /* kraj na funkcijata isEmpty */
