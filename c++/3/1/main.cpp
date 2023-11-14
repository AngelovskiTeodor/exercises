#include <iostream>

using namespace std;

class Cuboid {
private:
    float length;
    float width;
    float height;
public:
    Cuboid(){
        this->length = 0;
        this->width = 0;
        this->height = 0;
    }

    Cuboid(float length, float width, float height) {
        this->length = length;
        this->width = width;
        this->height = height;
    }

    void setLength(float l) {
        length = l;
    }

    float getLength() const {
        return length;
    }

    void setWidth(float w) {
        width = w;
    }

    float getWidth() const {
        return width;
    }

    void setHeight(float h) {
        height = h;
    }

    float getHeight() const {
        return height;
    }

    bool isRegular(){
        return this->length == this->width && this->width == this->height;
    }

    float area() {
        return 2*this->length*this->width + 2*this->width*this->height + 2*this->length*this->height;
    }

    float volume() {
        return this->length*this->width*this->height;
    }

    friend ostream& operator<<(ostream& os, Cuboid const& cuboid){
        os << cuboid.getLength() << "x" << cuboid.getWidth() << "x" << cuboid.getHeight();
        return os;
    }
};

Cuboid leastArea(Cuboid cuboids[], int n){
    int minIndex = 0;
    for (int i=0; i<n; i++) {
        if (cuboids[i].area() < cuboids[minIndex].area() && !cuboids[i].isRegular()) {
            minIndex = i;
        }
    }
    return cuboids[minIndex];
}

int add(Cuboid cuboids[], int n, Cuboid cuboid) {
    cuboids[n] = cuboid;
    return n+1;
}

void menu(){
    cout << "Choose an option: " << endl;
    cout << "0 Add new cuboid" << endl;
    cout << "1 Update dimensions" << endl;
    cout << "2 Print all cuboids" << endl;
    cout << "3 Print single cuboid" << endl;
    cout << "4 Exit" << endl;
}

void addCuboid(Cuboid cuboids[], int& n) {
    cout << "Enter dimensions the cuboid: " << endl;
    float a, b ,c;
    cout << "a="; cin >> a;
    cout << "b="; cin >> b;
    cout << "c="; cin >> c;
    n = add(cuboids, n , Cuboid(a,b,c));
}

void updateCuboid(Cuboid cuboids[], int& n) {
    cout << "Which cuboid do you wish to edit? (from 0 to " << n << ") ";
    int i; cin >> i;
    cout << "Enter updated dimensions the cuboid: " << endl;
    float a, b ,c;
    cout << "a="; cin >> a;
    cout << "b="; cin >> b;
    cout << "c="; cin >> c;
    cuboids[i].setLength(a);
    cuboids[i].setWidth(b);
    cuboids[i].setHeight(c);
}

void printAllCuboids(Cuboid cuboids[], int& n){
    for (int i=0; i<n; i++) {
        cout << cuboids[i] << endl;
    }
}

void printSingleCuboid(Cuboid cuboids[], int& n) {
    cout << "Which cuboid do you wish to print? (from 0 to " << n << ") ";
    int i; cin >> i;
    cout << cuboids[i] << endl;
}

void selector(Cuboid cuboids[], int& n, int choice) {
    void (*options[4]) (Cuboid cuboids[], int& n) = {addCuboid, updateCuboid, printAllCuboids, printSingleCuboid};
    options[choice](cuboids, n);
}

int main()
{
    int n;
    cout << "How many cuboids do you wish to create? ";
    cin >> n;
    Cuboid cuboids[100];

    float a, b ,c;
    for (int i=0; i<n; i++) {
        cout << "Enter dimensions for cuboid " << i << ": " << endl;
        cout << "a="; cin >> a;
        cout << "b="; cin >> b;
        cout << "c="; cin >> c;
        cuboids[i] = Cuboid(a,b,c);
    }

    cout << leastArea(cuboids, n) << endl;

    int choice;
    do {
        menu();
        cin >> choice;
        selector(cuboids, n, choice);
    } while (choice != 4);

    cout << "" << endl;
    return 0;
}
