#include <stdio.h>
#include <stdlib.h>

int* readArray(int* a, int n) {
    a = malloc(n * sizeof(int));
    printf("\n");
    for (int i=0; i<n; i++) {
        printf("a[%d]=",i);
        scanf_s("%d", a);
        if (i!=n-1) {
            a++;
        }
    }
    return a;
}

int* pecatiNizaNanazad(int* a, int n){
    for (int i=n; i>0; i--) {
        printf("a[%d]=%d\n",i, *a);
        if (i!=1) {
            a--;
        }
    }
}

struct element {
    struct element* leftPointer;
    int num;
    char letter;
    struct element* rightPointer;
};

struct list {
    struct element* first;
    struct element* last;
};

//struct element Element(struct element *left, int num, char letter, struct element *right) {
//    struct element elem;
//    elem.leftPointer = left;
//    elem.num = num;
//    elem.letter = letter;
//    elem.rightPointer = right;
//    return elem;
//}

struct element Element(int num, char letter) {
    struct element elem;
    elem.leftPointer = NULL;
    elem.num = num;
    elem.letter = letter;
    elem.rightPointer = NULL;
    return elem;
}

struct element* add(struct element* curr, struct element elem){
    if (curr == NULL) {
        curr = &elem;
        return curr;
    }
    elem.leftPointer = curr;
    curr->rightPointer=&elem;
    return &elem;
}

struct list List(){
    struct list l;
    l.first = NULL;
    l.last = l.first;

    struct element *curr = l.first;

    char choice = 'y';

    while (choice != 'n') {
        printf("Enter number for the list: ");
        int num;
        scanf_s("%d", &num);

        printf("Enter letter for the list: ");
        char letter;
        scanf_s(" %c", &letter);

        struct element elem = Element(num, letter);
        curr = add(curr, elem);
        l.last = curr;

        if (l.first == NULL) {
            l.first = l.last;
        }

        printf("Do you want to enter a new element? (y/n) ");
        scanf_s(" %c", &choice);
    }
    return l;
}

void printElement(struct element elem){
    printf("%d: %c\n", elem.num, elem.letter);
}

void pecatiListaNanazad(struct list l){
    struct element* curr = l.last;
    do {
        printElement(*curr);
        curr = curr->leftPointer;
    } while (curr->leftPointer != NULL);
}

int main()
{
    printf("Enter size of the array: ");
    int n;
    scanf_s("%d", &n);

    int* a;
    int* last = readArray(a, n);
    int* first = pecatiNizaNanazad(last, n);

    struct list l = List();
    pecatiListaNanazad(l);

    return 0;
}
