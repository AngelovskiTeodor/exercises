#include <stdio.h>

struct product {
    int code;
    char name[32];
    int amount;
    float price;
};

void addStartingStock(){
    struct product startingStock[4];
    struct product p1 = {3, "glusec Mico", 7, 10.34};
    startingStock[0] = p1;
    struct product p2 = {56, "monitor Kiki3", 5, 65.09};
    startingStock[1] = p2;
    struct product p3 = {75, "tastatura Biko8", 4, 12.09};
    startingStock[2] = p3;
    struct product p4 = {89, "matploc Ziko32", 6, 87.09};
    startingStock[3] = p4;

    FILE *file;
    if ( ( file = fopen("hardware.dat", "w") ) == NULL) {
        printf("Unable to open file\n");
        return;
    }

    //  Add starting stock
    for (int i=0; i<4; i++){
        fwrite(&startingStock[i], sizeof(struct product), 1, file);
    }

    fclose(file);
}

void printStock() {
    struct product p;

    FILE *file;
    if ( ( file = fopen("hardware.dat", "rb") ) == NULL) {
        printf("Unable to open file\n");
        return;
    }

    int i=0;
    while (!feof(file)) {
        fread(&p, sizeof(struct product), 1, file);
        i++;
        printf("Product no. %d is %s and costs %.2f $. There are %d in stock.\n", p.code, p.name, p.price, p.amount);
    }
    fclose(file);
}

void printProduct(int code) {
    FILE *file;
    if ( ( file = fopen("hardware.dat", "rb") ) == NULL) {
        printf("Unable to open file\n");
        return;
    }

    struct product p;
    int i=0;
    while (!feof(file)) {
        fread(&p, sizeof(struct product), 1, file);
        i++;
        if (p.code == code) {
            printf("Product no. %d is %s and costs %.2f $. There are %d in stock.\n", p.code, p.name, p.price, p.amount);
        }
    }
    fclose(file);
}

void sellProduct(int code, int amount) {
    struct product p;

    FILE *file;
    if ( ( file = fopen("hardware.dat", "rb") ) == NULL) {
        printf("Unable to open file\n");
        return;
    }

    int i=0;
    while (!feof(file)) {
        fread(&p, sizeof(struct product), 1, file);
        i++;
        if (p.code == code) {
            if (p.amount-amount>=0) {
                p.amount -= amount;
                fseek(file, i * sizeof(struct product), SEEK_SET);
                fwrite(&p, sizeof(struct product), 1, file);
                break;
            }
            else {
                printf("Not enought products in stock\n");
                break;
            }
        }
    }
    fclose(file);
}

void removeFile(){
    if (remove("hardware.dat") == 0)
        printf("Deleted successfully");
    else
        printf("Unable to delete the file");
}

int main()
{
    addStartingStock();
    sellProduct(3, 1);
    printStock();

    removeFile();
    printf("\n");
    return 0;
}
