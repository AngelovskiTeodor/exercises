#include <iostream>
#include <fstream>
#include <iomanip>
#include <vector>

using namespace std;

class Oblik{
public:
    Oblik(){ ++numShapes; }
    ~Oblik(){ --numShapes; }
    virtual void print() const = 0;
    virtual const double perimeter() const = 0;
    virtual const double plostina() const = 0;
    static int numShapes;
    friend ostream& operator <<(ostream& os, Oblik& shape) {
        //os << shape.a << "x" <<shape.b << "has perimeter of " << shape.perimeter() << ", area of " << shape.plostina() << " and no volume.";
        os << "N/A (Unable to print object of type virtual class Oblik)";
        return os;
    }
    bool operator<(const Oblik& shape) {
        return this->plostina() < shape.plostina();
    }
    bool operator>(const Oblik& shape) {
        return this->plostina() > shape.plostina();
    }
};
int Oblik::numShapes = 0;

class DvoDimenzionalni : public Oblik {
public:
    const double perimeter() const  = 0;
    const double plostina() const = 0;
    virtual void print() const = 0;
    friend ostream& operator <<(ostream& os, const DvoDimenzionalni& shape) {
        //os << shape.a << "x" <<shape.b << " has perimeter of " << shape.perimeter() << ", area of " << shape.plostina() << " and no volume.";
        os << "N/A (Unable to print object of type virtual class DvoDimenzionalni)";
        return os;
    }
};

class Kvadrat : public DvoDimenzionalni {
private:
    double strana;
public:
    void setA(double a) { this->strana = a; }
    const double getA() const { return strana; }
    Kvadrat(double a = 0) { setA(a); }
    const double perimeter() const { return 4*strana; }
    const double plostina() const { return strana*strana; }
    friend ostream& operator <<(ostream& os, const Kvadrat& square) {
        os << "Square with a=" << square.getA() << " has perimeter of " << square.perimeter() << ", area of " << square.plostina() << " and no volume.";
        return os;
    }
    friend istream& operator >>(istream& is, Kvadrat& square) {
        cout << "a="; double a; cin >> a; square.setA(a);
        return is;
    }
    bool operator==(const Kvadrat& square) { return this->getA() == square.getA(); }
    void print() const {
        cout << (*this) << endl;
    }
};

class Pravoagolnik : public DvoDimenzionalni {
private:
    double sirina;
    double dolzina;
public:
    void setA(double a) { this->sirina = a; }
    void setB(double b) { this->dolzina = b; }
    const double getA() const { return sirina; }
    const double getB() const { return dolzina; }
    Pravoagolnik(double a = 0, double b = 0) { setA(a); setB(b); }
    const double perimeter() const { return 2*sirina + 2*dolzina; }
    const double plostina() const { return sirina*dolzina; }
    friend ostream& operator <<(ostream& os, const Pravoagolnik& rectangle) {
        os << "Rectangle " << rectangle.getA() << "x" << rectangle.getB() << " has perimeter of " << rectangle.perimeter() << ", area of " << rectangle.plostina() << " and no volume.";
        return os;
    }
    friend istream& operator >>(istream& is, Pravoagolnik& rectangle) {
        cout << "a="; double a; cin >> a; rectangle.setA(a);
        cout << "b="; double b; cin >> b; rectangle.setB(b);
        return is;
    }
    bool operator==(const Pravoagolnik& rectangle) { return (this->getA()==rectangle.getA()) && (this->getB()==rectangle.getB()); }
    void print() const {
        cout << (*this) << endl;
    }
};

vector<DvoDimenzionalni*> readShapes (string file = "shapes.txt") {
    vector<DvoDimenzionalni*> ret;

    ifstream readFromFile ( file, ios::in );
    int type; double a, b;
    while ( readFromFile >> type >> a ) {
        if (type != 1 && type != 2) { throw runtime_error("Invalid shape type"); }
        if (type == 1) {
            readFromFile >> b;
            ret.push_back( new Pravoagolnik(a,b) );
            continue;
        }
        ret.push_back( new Kvadrat(a) );
    }

    readFromFile.close();
    return ret;
}

int main()
{
    vector<DvoDimenzionalni*> shapes = readShapes();
    for (DvoDimenzionalni* shape : shapes) {
//        cout << *shape << endl;
        shape->print();
    }
    cout << "" << endl;
    return 0;
}
