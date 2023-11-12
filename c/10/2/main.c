#include <stdio.h>

const int subjects = 2;     //  number of grades
const int students = 2;     //  number of students

void max(int grades[students][subjects]);
void min(int grades[students][subjects]);
void pecatiNiza(int grades[students][subjects]);
void рrosek(int grades[students][subjects]);

void printUI(){
    printf("Vnesi izbor:\n");
    printf("0 Ispechati ja nizata so oceni\n");
    printf("1 Najdi ja maksimalnataocena\n");
    printf("2 Najdi ja minimalnata ocena\n");
    printf("3 Ispecati ja prosechnata ocena za sekoja student\n");
    printf("4 Kraj\n");
}

int main()
{
    void (*obrabotiOceni[4])(int grades[students][subjects]) = {pecatiNiza, max, min, рrosek};

    int grades[students][subjects];
    for (int i=0; i<students; i++) {
        printf("Enter grades for student no. %d:\n", i+1);
        for (int j=0; j<subjects; j++){
            printf("Subject %d: ", j+1);
            scanf_s("%d", &grades[i][j]);
        }
        printf("\n");
    }

    int choise;
    printUI();
    scanf_s("%d", &choise);
    while (choise != 4) {
        if (choise >= 0 && choise <= 3) {
            (*obrabotiOceni[choise])(grades);
        }
        printUI();
        scanf_s("%d", &choise);
    }

    printf("\n");
    return 0;
}

void max(int grades[students][subjects]) {
    for (int i=0; i<students; i++) {
        int mj = 0;     //  index j for the highest grade
        for (int j=0; j<subjects; j++){
            if (grades[i][j] > grades[i][mj]) {
                mj = j;
            }
        }
        printf("%d is the highest grade for student no. %d for the subject no. %d\n", grades[i][mj], i+1, mj+1);
    }
}

void min(int grades[students][subjects]) {
    for (int i=0; i<students; i++) {
        int mj = 0;     //  index j for the lowest grade
        for (int j=0; j<subjects; j++){
            if (grades[i][j] < grades[i][mj]) {
                mj = j;
            }
        }
        printf("%d is the lowest grade for student no. %d for the subject no. %d\n", grades[i][mj], i+1, mj+1);
    }
}

void pecatiNiza(int grades[students][subjects]) {
    for (int i=0; i<students; i++) {
        printf("Grades for student no. %d:", i+1);
        for (int j=0; j<subjects; j++){
            printf(" %d", grades[i][j]);
        }
        printf("\n");
    }
}

void рrosek(int grades[students][subjects]) {
    for (int i=0; i<students; i++) {
        float sum = 0;
        for (int j=0; j<subjects; j++){
            sum += grades[i][j];
        }
        float avg = sum / subjects;
        printf("The average grade for student no. %d is %.2f\n",i+1, avg);
    }
}
