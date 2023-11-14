/* Program p13_04.c
   Sozdavanje na binarno drvo i pominuvanje vo
   preorder, inorder, i postorder */
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/* samo-referencirachka struktura */
struct treeNode {
    struct treeNode *leftPtr;  /* pokazhuvach do levoto poddrvo */
    int data; /* node value */
    struct treeNode *rightPtr; /* pokazhuvach do desnoto poddrvo */
}; /* kraj structure treeNode */

typedef struct treeNode TreeNode; /* sinonim za struct treeNode */
typedef TreeNode *TreeNodePtr; /* sinonim za TreeNode* */

/* prototipovi */
void insertNode( TreeNodePtr *treePtr, int value );
void inOrder( TreeNodePtr treePtr );
void preOrder( TreeNodePtr treePtr );
void postOrder( TreeNodePtr treePtr );
void delete( TreeNodePtr treePtr, int value );

/* pochetok na izvrshuvanjeto */
int main()
{
    int i; /* brojach od 1-10 */
    int item; /* promenliva shto sodrzhi sluchajni vrednosti */
    TreeNodePtr rootPtr = NULL; /* drvoto vo pochetokot e prazno */

    srand( time( NULL ) );
    printf( "Broevite koi se stavaat vo drvoto se: ");

    int elemToDelete = 6;
    /* vnesi sluchajni broevi megju 1 i 15 vo drvoto */
    for ( i = 1; i <= 10; i++ ) {
        item = rand() % 15;
        printf( "%3d", item );
        insertNode( &rootPtr, item );

        if (i == 3) { elemToDelete = item; }
    } /* kraj for */

    /* pomini go drvoto vo preOrder */
    printf( "\n\nPominuvanjeto vo preOrder dava:\n" );
    preOrder( rootPtr );

    /* pomini go drvoto vo inOrder */
    printf( "\n\nPominuvanjeto vo inOrder dava:\n" );
    inOrder( rootPtr );

    /* pomini go drvoto vo postOrder */
    printf( "\n\nPominuvanjeto vo postOrder dava:\n" );
    postOrder( rootPtr );

    delete( rootPtr, elemToDelete );

    /* pomini go drvoto vo preOrder */
    printf( "\n\nPominuvanjeto vo preOrder dava:\n" );
    preOrder( rootPtr );

    /* pomini go drvoto vo inOrder */
    printf( "\n\nPominuvanjeto vo inOrder dava:\n" );
    inOrder( rootPtr );

    /* pomini go drvoto vo postOrder */
    printf( "\n\nPominuvanjeto vo postOrder dava:\n" );
    postOrder( rootPtr );

    return 0; /* uspeshen kraj */

} /* kraj main */

/* vnesi jazel vo drvo */
void insertNode( TreeNodePtr *treePtr, int value )
{
    /* ako drvoto e prazno */
    if ( *treePtr == NULL ) {
        *treePtr = malloc( sizeof( TreeNode ) );

        /* ako alocirashe memorija, napolni ja so podatoci */
        if ( *treePtr != NULL ) {
            ( *treePtr )->data = value;
            ( *treePtr )->leftPtr = NULL;
            ( *treePtr )->rightPtr = NULL;
        } /* kraj if */
        else {
            printf( "%d ne e vneseno. Nema dovolno memorija.\n", value );
        } /* kraj else */
    } /* kraj if */
    else { /* drvoto ne e prazno */
        /* podatokot shto se vnesuva e pomal od podatokot vo tekovniot jazel */
        if ( value < ( *treePtr )->data ) {
            insertNode( &( ( *treePtr )->leftPtr ), value );
        } /* kraj if */
        else {
            insertNode( &( ( *treePtr )->rightPtr ), value );
        } /* kraj else */
    } /* kraj else */
} /* kraj na funkcijata insertNode */

/* pochni so inorder pominuvanje na drvo */
void inOrder( TreeNodePtr treePtr )
{
    /* ako drvoto ne e prazno, pomini go */
    if ( treePtr != NULL ) {
        inOrder( treePtr->leftPtr );
        printf( "%3d", treePtr->data );
        inOrder( treePtr->rightPtr );
    } /* kraj if */
} /* kraj na funkcijata inOrder */

/* pochni so preorder pominuvanje na drvoto */
void preOrder( TreeNodePtr treePtr )
{
    /* ako drvoto ne e prazno, pomini go */
    if ( treePtr != NULL ) {
        printf( "%3d", treePtr->data );
        preOrder( treePtr->leftPtr );
        preOrder( treePtr->rightPtr );
    } /* kraj if */
} /* kraj na funkcijata preOrder */

/* pochni so postorder pominuvanjeto na drvoto */
void postOrder( TreeNodePtr treePtr )
{
    /* ako drvoto ne e prazno, pomini go */
    if ( treePtr != NULL ) {
        postOrder( treePtr->leftPtr );
        postOrder( treePtr->rightPtr );
        printf( "%3d", treePtr->data );
    } /* kraj if */
} /* kraj na funkcijata postOrder */

void rebalance(TreeNodePtr t1Ptr, TreeNodePtr t2Ptr) {
    if (t2Ptr == NULL) {
        return;
    }
    if (t1Ptr == NULL) {
        *t1Ptr = *t2Ptr;
        return;
    }
    if (t1Ptr->rightPtr == NULL) {
        *t1Ptr->rightPtr = *t2Ptr;
        return;
    }
    TreeNodePtr temp = &(*t1Ptr->rightPtr);
    *t1Ptr->rightPtr = *t2Ptr;
    rebalance(t2Ptr, temp);
}

void delete( TreeNodePtr treePtr, int value ) {
    if (treePtr->data == value) {
        //  remove this node
        TreeNode temp = *treePtr->rightPtr;
        *treePtr = *treePtr->leftPtr;
        rebalance(&treePtr, &temp);
    }
    else {
        if (&(*treePtr->leftPtr) != NULL) delete(&(*treePtr->leftPtr), value);  // search the value in left subtree
        if (&(*treePtr->rightPtr) != NULL) delete(&(*treePtr->rightPtr), value);  // search the value in right subtree
    }
}
