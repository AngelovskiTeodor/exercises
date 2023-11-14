#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct element {
    struct element* leftPointer;
    int num;
    struct element* rightPointer;
};

struct list {
    struct element* first;
    struct element* last;
};

struct element Element(int num) {
    struct element elem;
    elem.leftPointer = NULL;
    elem.num = num;
    elem.rightPointer = NULL;
    return elem;
}

struct list List (){
    struct list l;
    l.first = NULL;
    l.last = l.first;
}

struct element add(struct element* curr, struct element elem){
    if (curr == NULL) {
        curr = &elem;
        return *curr;
    }
    elem.leftPointer = curr;
    curr->rightPointer=&elem;
    return elem;
}

struct list vnesi(struct list l){
    struct element *curr = l.first;

    char choice = 'y';

    while (choice != 'n') {
        printf("Enter number for the list: ");
        int num;
        scanf_s("%d", &num);

        struct element elem = Element(num); //  next element
        elem = add(curr, elem);
        curr = &elem;
        l.last = curr;

        if (l.first == NULL) {
            l.first = l.last;
        }

        printf("Do you want to enter a new element? (y/n) ");
        scanf_s(" %c", &choice);
    }
    return l;
}

void swap(struct element *e1, struct element *e2) {
    struct element *temp;

    //  swap prev
    temp = e1->leftPointer;
    e1->leftPointer = e2->leftPointer;
    e2->leftPointer = temp;

    // swap next
    temp = e1->rightPointer;
    e1->rightPointer = e2->rightPointer;
    e2->rightPointer = temp;

    //  swap elements
    temp = e1;
    e1 = e2;
    e2 = temp;
}

void sortOpagjanje(struct list l) {
    struct element tempElement;
    struct element *curr = l.first;

    bool swapped = true;
    do {
        if (curr->num < curr->rightPointer->num) {
            swap(curr, curr->rightPointer);
        }
        curr = curr->rightPointer;
    } while (curr->rightPointer->rightPointer != NULL);
}

void printElement(struct element elem){
    printf("%d ", elem.num);
}

void printList(struct list l){
    struct element* curr = l.last;
    do {
        printElement(*curr);
        curr = curr->rightPointer;
    } while (curr->rightPointer != NULL);
}

int main()
{
    struct list l = List();
    vnesi(l);
    printList(l);
    sortOpagjanje(l);
    printList(l);
    printf("\n");
    return 0;
}
