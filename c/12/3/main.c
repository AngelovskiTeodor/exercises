#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct vraboten {
    int id;
    char name[16];
    char surname[16];
    int age;
    char gender[8];
    char status[16];    //  marital status
    float credibility;
    char address[32];
    float currentSalary;
    float formerSalary;
};

void readEmployees(struct vraboten employees[], int n){
    for (int i=0; i<n; i++) {
        printf("Enter data for employee:\n");
        struct vraboten empl;
        printf("ID=");
        scanf_s("%d", &empl.id);
        printf("Name=");
        scanf_s("%s", &empl.name);
        printf("Surname=");
        scanf_s("%s", &empl.surname);
        printf("Age=");
        scanf_s("%d", &empl.age);
        printf("Gender=");
        scanf_s("%s", &empl.gender);
        printf("Marital Status=");
        scanf_s("%s", &empl.status);
        printf("Credibility=");
        scanf_s("%f", &empl.credibility);
        printf("Address=");
        scanf_s("%s", &empl.address);
        printf("CurrentSalary=");
        scanf_s("%f", &empl.currentSalary);
        printf("FormerSalary=");
        scanf_s("%f", &empl.formerSalary);
        employees[i] = empl;
    }
}

void printEmployees(struct vraboten employees[], int n) {
    for (int i=0; i<n; i++) {
        struct vraboten empl = employees[i];
        printf("Data for employee no. %d:\n", empl.id);
        printf("Name=%s\n", empl.name);
        printf("Surname=%s\n", empl.surname);
        printf("Age=%d\n", empl.age);
        printf("Gender=%s\n", empl.gender);
        printf("Marital Status=%s\n", empl.status);
        printf("Credibility=%f\n", empl.credibility);
        printf("Address=%s\n", empl.address);
        printf("CurrentSalary=%f\n", empl.currentSalary);
        printf("FormerSalary=%f\n", empl.formerSalary);
    }
}

void koregirajVraboten(struct vraboten employees[], int n, int id) {
    for (int i=0; i<n; i++) {
        struct vraboten empl = employees[i];
        if (empl.id == id) {
            printf("Update data for employee no. %d:\n", empl.id);
            printf("Name=");
            scanf_s("%s", &empl.name);
            printf("Surname=");
            scanf_s("%s", &empl.surname);
            printf("Age=");
            scanf_s("%d", &empl.age);
            printf("Gender=");
            scanf_s("%s", &empl.gender);
            printf("Marital Status=");
            scanf_s("%s", &empl.status);
            printf("Credibility=");
            scanf_s("%f", &empl.credibility);
            printf("Address=");
            scanf_s("%s", &empl.address);
            printf("CurrentSalary=");
            scanf_s("%f", &empl.currentSalary);
            printf("FormerSalary=");
            scanf_s("%f", &empl.formerSalary);
            employees[i] = empl;
            break;
        }
    }
}

void sort_kred(struct vraboten employees[], int n) {
    int tempIndex;
    struct vraboten tempEmpl;
    for (int i=0; i<n-1; i++) {
        tempIndex = i;
        for (int j=i; j<n; j++) {
            if (employees[j].credibility < employees[tempIndex].credibility) {
                tempIndex = j;
            }
        }
        tempEmpl = employees[i];
        employees[i] = employees[tempIndex];
        employees[tempIndex] = tempEmpl;
    }
}

void sort_tekovnaPlata(struct vraboten employees[], int n) {
    int tempIndex;
    struct vraboten tempEmpl;
    for (int i=0; i<n-1; i++) {
        tempIndex = i;
        for (int j=i; j<n; j++) {
            if (employees[j].currentSalary < employees[tempIndex].currentSalary) {
                tempIndex = j;
            }
        }
        tempEmpl = employees[i];
        employees[i] = employees[tempIndex];
        employees[tempIndex] = tempEmpl;
    }
}

void sort_minataPlata(struct vraboten employees[], int n) {
    int tempIndex;
    struct vraboten tempEmpl;
    for (int i=0; i<n-1; i++) {
        tempIndex = i;
        for (int j=i; j<n; j++) {
            if (employees[j].formerSalary < employees[tempIndex].formerSalary) {
                tempIndex = j;
            }
        }
        tempEmpl = employees[i];
        employees[i] = employees[tempIndex];
        employees[tempIndex] = tempEmpl;
    }
}

void koregiraj_kredibilnost(struct vraboten employees[], int n) {
    for (int i=0; i<n; i++) {
        struct vraboten empl = employees[i];
        if (empl.currentSalary > empl.formerSalary) {
            empl.credibility+=3;
            empl.formerSalary = empl.currentSalary;
            employees[i] = empl;
        }
        else {
            if (empl.formerSalary > empl.currentSalary) {
                empl.credibility-=3;
                empl.currentSalary = empl.formerSalary;
                employees[i] = empl;
            }
        }
    }
}

int main()
{
    int n;
    printf("How many employees are there? ");
    scanf_s("%d", &n);
    struct vraboten employees[n];
    readEmployees(employees, n);
    printEmployees(employees, n);

    sort_kred(employees, n);
    printEmployees(employees, n);

    sort_tekovnaPlata(employees, n);
    printEmployees(employees, n);

    sort_minataPlata(employees, n);
    printEmployees(employees, n);

    printf("Which employee do you want to edit? ");
    int i;
    scanf_s("%d", &i);
    koregirajVraboten(employees, n, i);
    printEmployees(employees, n);

    koregiraj_kredibilnost(employees, n);
    printEmployees(employees, n);

    printf("\n");
    return 0;
}
