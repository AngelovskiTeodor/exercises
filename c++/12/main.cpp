#include <iostream>

using namespace std;

class Oblik{
private:
public:
    Oblik(){ ++numShapes; }
    ~Oblik(){ --numShapes; }
    virtual float perimeter() const = 0;
    virtual float area() const = 0;
    virtual float volume() const = 0;
    static int numShapes;
    friend ostream& operator <<(ostream& os, const Oblik& shape) {
        //os << shape.a << "x" <<shape.b << "has perimeter of " << shape.perimeter() << ", area of " << shape.area() << " and no volume.";
        os << "N/A (Unable to print object of type virtual class)";
        return os;
    }
};
int Oblik::numShapes = 0;

class DvoDimenzionalni : public Oblik {
private:
    float a;
    float b;
public:
    DvoDimenzionalni(float a, float b) {
        setA(a);
        setB(b);
    }
    void setA(float a) { this->a = a; }
    void setB(float b) { this->b = b; }
    const float getA() const { return a; }
    const float getB() const { return b; }
    float perimeter() const { return 2*a + 2*b; }
    float area() const { return a*b; }
    float volume() const { return 0; }
    friend ostream& operator <<(ostream& os, const DvoDimenzionalni& shape) {
        os << shape.a << "x" <<shape.b << "has perimeter of " << shape.perimeter() << ", area of " << shape.area() << " and no volume.";
        return os;
    }
};

class TroDimenzionalni : public Oblik {
private:
    float a;
    float b;
    float c;
public:
    TroDimenzionalni(float a, float b, float c) {
        setA(a);
        setB(b);
        setC(c);
    }
    void setA(float a) { this->a = a; }
    void setB(float b) { this->b = b; }
    void setC(float c) { this->c = c; }
    const float getA() const { return a; }
    const float getB() const { return b; }
    const float getC() const { return c; }
    float perimeter() const { return 4*a + 4*b + 4*c; }
    float area() const { return 2*a*b + 2*a*c + 2*b*c; }
    float volume() const { return a*b*c; }
    friend ostream& operator <<(ostream& os, const TroDimenzionalni& shape) {
        os << shape.a << "x" <<shape.b << "has perimeter of " << shape.perimeter() << ", area of " << shape.area() << " and volume of " << shape.volume();
        return os;
    }
};

class Square : public DvoDimenzionalni {
public:
    Square(float a) : DvoDimenzionalni(a, a){}
    float perimeter() const { return DvoDimenzionalni::perimeter(); }
    float area() const { return DvoDimenzionalni::area(); }
    float volume() const { return DvoDimenzionalni::volume(); }
};

class Rectangle : public DvoDimenzionalni {
public:
    Rectangle(float a, float b) : DvoDimenzionalni(a,b){}
    float perimeter() const { return DvoDimenzionalni::perimeter(); }
    float area() const { return DvoDimenzionalni::area(); }
    float volume() const { return DvoDimenzionalni::volume(); }
};

class Cube : public TroDimenzionalni {
public:
    Cube(float a) : TroDimenzionalni(a, a, a){}
    float perimeter() const { return TroDimenzionalni::perimeter(); }
    float area() const { return TroDimenzionalni::area(); }
    float volume() const { return TroDimenzionalni::volume(); }
};

class Cuboid : public TroDimenzionalni {
public:
    Cuboid(float a, float b, float c) : TroDimenzionalni(a, b, c){}
    float perimeter() const { return TroDimenzionalni::perimeter(); }
    float area() const { return TroDimenzionalni::area(); }
    float volume() const { return TroDimenzionalni::volume(); }
};

class Space {
private:
    Oblik **shapes;
    int size;
public:
    Space(){
        size = 0;
    }
    const int getSize() const { return size; }

//    void addSquare(Square square) {}

//    void addRectangle(Rectangle rectangle) {}

//    void addCube(Cube cube) {}

//    void addCuboid(Cuboid cuboid) {}

    void addShape(Oblik& shape) {
        if (getSize() == 0) {
            shapes = new Oblik*[size+1];
            shapes[size] = &shape;
            size++;
            return;
        }
        Oblik** temp = shapes;
        shapes = new Oblik*[size+1];
        for (int i=0; i<size; i++) {
            shapes[i] = temp[i];
        }
        shapes[size] = &shape;
        size++;

    }

    void listSquare() {
        for (int i=0; i<size; i++) {
            for (int i=0; i<size; i++) {
                if ( typeid( (*shapes[i]) )==typeid( Square ) ) {
                    cout << (*shapes[i]) << endl;
                }
            }
        }
    }

    void listRectangle() {
        for (int i=0; i<size; i++) {
            if ( typeid( (*shapes[i]) )==typeid( Rectangle ) ) {
                cout << (*shapes[i]) << endl;
            }
        }
    }

    void listCube() {
        for (int i=0; i<size; i++) {
            if ( typeid( (*shapes[i]) )==typeid( Cube ) ) {
                cout << (*shapes[i]) << endl;
            }
        }
    }

    void listCuboid() {
        for (int i=0; i<size; i++) {
            if ( typeid( (*shapes[i]) )==typeid( Cuboid ) ) {
                cout << (*shapes[i]) << endl;
            }
        }
    }

    void listAll() {
        for (int i=0; i<size; i++) {
            cout << (*shapes[i]) << endl;
        }
    }
};

void addSquare(Space& space) {
    float a;
    cout << "a="; cin >> a;
    Square square = Square(a);
    space.addShape(square);
}

void addRectangle(Space& space) {
    float a, b;
    cout << "a="; cin >> a;
    cout << "b="; cin >> b;
    Rectangle rectangle = Rectangle(a, b);
    space.addShape(rectangle);
}

void addCube(Space& space) {
    float a;
    cout << "a="; cin >> a;
    Cube cube = Cube(a);
    space.addShape(cube);
}

void addCuboid(Space& space) {
    float a, b, c;
    cout << "a="; cin >> a;
    cout << "b="; cin >> b;
    cout << "c="; cin >> c;
    Cuboid cuboid = Cuboid(a, b, c);
    space.addShape(cuboid);
}

void listSquare(Space& space) {
    space.listSquare();
}

void listRectangle(Space& space) {
    space.listRectangle();
}

void listCube(Space& space) {
    space.listCube();
}

void listCuboid(Space& space) {
    space.listCuboid();
}

void listAll(Space& space) {
    space.listAll();
}

void selector(Space& space, int choice) {
    void (*options[10]) (Space& space) = {addSquare, addRectangle, addCube, addCuboid, listSquare, listRectangle, listCube, listCuboid, listAll};
    options[choice](space);
}

void menu(){
    cout << "1.  Add new square: " << endl;
    cout << "2.  Add new rectangle: " << endl;
    cout << "3.  Add new cube: " << endl;
    cout << "4.  Add new cuboid: " << endl;
    cout << "5.  List all squares: " << endl;
    cout << "6.  List all rectangles: " << endl;
    cout << "7.  List all cubes: " << endl;
    cout << "8.  List all cuboids: " << endl;
    cout << "9.  List all shapes" << endl;
    cout << "10. Izlez" << endl;
}

int main()
{
    int choice;
    Space space;
    do {
        menu();
        cin >> choice;
        selector(space, choice-1);
    } while (choice != 10);
    cout << "" << endl;
    return 0;
}
