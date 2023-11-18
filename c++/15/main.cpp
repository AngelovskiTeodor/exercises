#include <iostream>
#include <cmath>

using namespace std;

class Oblik{
public:
    Oblik(){ ++numShapes; }
    ~Oblik(){ --numShapes; }
    virtual void print() const = 0;
    virtual const float perimeter() const = 0;
    virtual const float plostina() const = 0;
    virtual const float volumen() const = 0;
    static int numShapes;
    friend ostream& operator <<(ostream& os, Oblik& shape) {
        //os << shape.a << "x" <<shape.b << "has perimeter of " << shape.perimeter() << ", area of " << shape.plostina() << " and no volume.";
        os << "N/A (Unable to print object of type virtual class Oblik)";
        return os;
    }
};
int Oblik::numShapes = 0;

class DvoDimenzionalni : public Oblik {
public:
    const float perimeter() const  = 0;
    const float plostina() const = 0;
    const float volumen() const = 0;
    virtual void print() const = 0;
    friend ostream& operator <<(ostream& os, const DvoDimenzionalni& shape) {
        //os << shape.a << "x" <<shape.b << " has perimeter of " << shape.perimeter() << ", area of " << shape.plostina() << " and no volume.";
        os << "N/A (Unable to print object of type virtual class DvoDimenzionalni)";
        return os;
    }
};

class TroDimenzionalni : public Oblik {
public:
    const float perimeter() const = 0;
    const float plostina() const = 0;
    const float volumen() const = 0;
    virtual void print() const = 0;
    friend ostream& operator <<(ostream& os, const TroDimenzionalni& shape) {
        //os << shape.a << "x" << shape.b << "x" << shape.c << " has perimeter of " << shape.perimeter() << ", area of " << shape.plostina() << " and volume of" << shape.volumen();
        os << "N/A (Unable to print object of type virtual class TroDimenzionalni)";
        return os;
    }
};

class Square : public DvoDimenzionalni {
private:
    float a;
public:
    void setA(float a) { this->a = a; }
    const float getA() const { return a; }
    Square(float a) { setA(a); }
    const float perimeter() const { return 4*a; }
    const float plostina() const { return a*a; }
    const float volumen() const { return 0; }
    friend ostream& operator <<(ostream& os, const Square& square) {
        os << "Square with a=" << square.a << " has perimeter of " << square.perimeter() << ", area of " << square.plostina() << " and no volume.";
        return os;
    }
    void print() const {
        cout << (*this) << endl;
    }
};

class Rectangle : public DvoDimenzionalni {
private:
    float a;
    float b;
public:
    void setA(float a) { this->a = a; }
    void setB(float b) { this->b = b; }
    const float getA() const { return a; }
    const float getB() const { return b; }
    Rectangle(float a, float b) { setA(a); setB(b); }
    const float perimeter() const { return 2*a + 2*b; }
    const float plostina() const { return a*b; }
    const float volumen() const { return 0; }
    friend ostream& operator <<(ostream& os, const Rectangle& rectangle) {
        os << "Rectangle " << rectangle.a << "x" << rectangle.b << " has perimeter of " << rectangle.perimeter() << ", area of " << rectangle.plostina() << " and no volume.";
        return os;
    }
    void print() const {
        cout << (*this) << endl;
    }
};

class Circle : public DvoDimenzionalni {
private:
    float r;
public:
    void setR(float r) { this->r = r; }
    const float getR() const { return r; }
    Circle(float r) { setR(r); }
    const float perimeter() const { return 2*r*M_PI; }
    const float plostina() const { return r*r*M_PI; }
    const float volumen() const { return 0; }
    friend ostream& operator <<(ostream& os, const Circle& circle) {
        os << "Circle with r=" << circle.r << " has perimeter of " << circle.perimeter() << ", area of " << circle.plostina() << " and no volume.";
        return os;
    }
    void print() const {
        cout << (*this) << endl;
    }
};

class Cube : public TroDimenzionalni {
private:
    float a;
public:
    Cube(float a) { setA(a); }
    void setA(float a) { this->a = a; }
    const float getA() const { return a; }
    const float perimeter() const { return 12*a; }
    const float plostina() const { return 6*a; }
    const float volumen() const { return a*a*a; }
    friend ostream& operator <<(ostream& os, const Cube& cube) {
        os << "Cube with a=" << cube.a << " has perimeter of " << cube.perimeter() << ", area of " << cube.plostina() << " and volume of " << cube.volumen();
        return os;
    }
    void print() const {
        cout << (*this) << endl;
    }
};

class Cuboid : public TroDimenzionalni {
private:
    float a;
    float b;
    float c;
public:
    Cuboid(float a, float b, float c) { setA(a); setB(b); setC(c); }
    void setA(float a) { this->a = a; }
    void setB(float b) { this->b = b; }
    void setC(float c) { this->c = c; }
    const float getA() const { return a; }
    const float getB() const { return b; }
    const float getC() const { return c; }
    const float perimeter() const { return 4*a + 4*b + 4*c; }
    const float plostina() const { return 2*a*b + 2*a*c + 2*b*c; }
    const float volumen() const { return a*b*c; }
    friend ostream& operator <<(ostream& os, const Cuboid& cuboid) {
        os << "Cuboid " << cuboid.a << "x" << cuboid.b << "x" << cuboid.c << " has perimeter of " << cuboid.perimeter() << ", area of " << cuboid.plostina() << " and volume of " << cuboid.volumen();
        return os;
    }
    void print() const {
        cout << (*this) << endl;
    }
};

class Cylinder : public TroDimenzionalni {
private:
    Circle* base;
    float h;
public:
    void setR(float r) { this->base = new Circle(r); }
    const float getR() const { return base->getR(); }
    void setH(float h) { this->h = h; }
    const float getH() const { return h; }
    Cylinder(float r, float h) { setR(r); setH(h); }
    ~Cylinder() { delete base; }
    const float perimeter() const { return 2*base->perimeter()+h; }
    const float plostina() const { return (2*base->plostina()) + (base->perimeter()*h); }
    const float volumen() const { return base->perimeter()*h; }
    friend ostream& operator <<(ostream& os, const Cylinder& cylinder) {
        os << "Cylinder " << cylinder.getR() << "x" << cylinder.h << " has perimeter of " << cylinder.perimeter() << ", area of " << cylinder.plostina() << " and volume of " << cylinder.volumen();
        return os;
    }
    void print() const {
        cout << (*this) << endl;
    }
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

    void addShape(Oblik* shape) {
        if (getSize() == 0) {
            shapes = new Oblik*[size+1];
            shapes[size] = shape;
            size++;
            return;
        }
        Oblik** temp = shapes;
        shapes = new Oblik*[size+1];
        for (int i=0; i<size; i++) {
            shapes[i] = temp[i];
        }
        shapes[size] = shape;
        size++;

    }

    void listSquare() {
        for (int i=0; i<size; i++) {
            if ( typeid( (*shapes[i]) )==typeid( Square ) ) {
                shapes[i]->print();
            }
        }
    }

    void listRectangle() {
        for (int i=0; i<size; i++) {
            if ( typeid( (*shapes[i]) )==typeid( Rectangle ) ) {
                shapes[i]->print();
            }
        }
    }

    void listCircle() {
        for (int i=0; i<size; i++) {
            if ( typeid( (*shapes[i]) )==typeid( Circle ) ) {
                shapes[i]->print();
            }
        }
    }

    void listCube() {
        for (int i=0; i<size; i++) {
            if ( typeid( (*shapes[i]) )==typeid( Cube ) ) {
                shapes[i]->print();
            }
        }
    }

    void listCuboid() {
        for (int i=0; i<size; i++) {
            if ( typeid( (*shapes[i]) )==typeid( Cuboid ) ) {
                shapes[i]->print();
            }
        }
    }

    void listCylinder() {
        for (int i=0; i<size; i++) {
            if ( typeid( (*shapes[i]) )==typeid( Cylinder ) ) {
                shapes[i]->print();
            }
        }
    }

    void listAll() {
        for (int i=0; i<size; i++) {
            //cout << (*shapes[i]) << endl;
            shapes[i]->print();
        }
    }
};

void addSquare(Space& space) {
    float a;
    cout << "a="; cin >> a;
    Square* square = new Square(a);
    space.addShape(square);
}

void addRectangle(Space& space) {
    float a, b;
    cout << "a="; cin >> a;
    cout << "b="; cin >> b;
    Rectangle* rectangle = new Rectangle(a, b);
    space.addShape(rectangle);
}

void addCircle(Space& space) {
    float r;
    cout << "r="; cin >> r;
    Circle* circle = new Circle(r);
    space.addShape(circle);
}

void addCube(Space& space) {
    float a;
    cout << "a="; cin >> a;
    Cube* cube = new Cube(a);
    space.addShape(cube);
}

void addCuboid(Space& space) {
    float a, b, c;
    cout << "a="; cin >> a;
    cout << "b="; cin >> b;
    cout << "c="; cin >> c;
    Cuboid* cuboid = new Cuboid(a, b, c);
    space.addShape(cuboid);
}

void addCylinder(Space& space){
    float r;
    cout << "r="; cin >> r;
    float h;
    cout << "h="; cin >> h;
    Cylinder* cylinder = new Cylinder(r, h);
    space.addShape(cylinder);
}

void listSquare(Space& space) {
    space.listSquare();
}

void listRectangle(Space& space) {
    space.listRectangle();
}

void listCircle(Space& space){
    space.listCircle();
}

void listCube(Space& space) {
    space.listCube();
}

void listCuboid(Space& space) {
    space.listCuboid();
}

void listCylinder(Space& space) {
    space.listCylinder();
}

void listAll(Space& space) {
    space.listAll();
}

void selector(Space& space, int choice) {
    void (*options[13]) (Space& space) = {addSquare, addRectangle, addCircle, addCube, addCuboid, addCylinder, listSquare, listRectangle, listCircle, listCube, listCuboid, listCylinder, listAll};
    options[choice](space);
}

void menu(){
    cout << "1.  Add new square: " << endl;
    cout << "2.  Add new rectangle: " << endl;
    cout << "3.  Add new circle: " << endl;
    cout << "4.  Add new cube: " << endl;
    cout << "5.  Add new cuboid: " << endl;
    cout << "6.  Add new cylinder: " << endl;
    cout << "7.  List all squares: " << endl;
    cout << "8.  List all rectangles: " << endl;
    cout << "9.  List all circles: " << endl;
    cout << "10. List all cubes: " << endl;
    cout << "11. List all cuboids: " << endl;
    cout << "12. List all cylinders: " << endl;
    cout << "13. List all shapes" << endl;
    cout << "14. Izlez" << endl;
}

int main()
{
    int choice;
    Space space;
    do {
        menu();
        cin >> choice;
        selector(space, choice-1);
    } while (choice != 14);
    cout << "" << endl;
    return 0;
}
