#include <iostream>

using namespace std;

class Oblik{
public:
    Oblik(){ ++numShapes; }
    ~Oblik(){ --numShapes; }
    virtual void print() const = 0;
    virtual const float perimeter() const = 0;
    virtual const float plostina() const = 0;
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
    const float perimeter() const  = 0;
    const float plostina() const = 0;
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
    virtual void print() const = 0;
    friend ostream& operator <<(ostream& os, const TroDimenzionalni& shape) {
        //os << shape.a << "x" << shape.b << "x" << shape.c << " has perimeter of " << shape.perimeter() << ", area of " << shape.plostina() << " and volume of" << shape.volumen();
        os << "N/A (Unable to print object of type virtual class TroDimenzionalni)";
        return os;
    }
};

class Kvadrat : public DvoDimenzionalni {
private:
    float strana;
public:
    void setA(float a) { this->strana = a; }
    const float getA() const { return strana; }
    Kvadrat(float a = 0) { setA(a); }
    const float perimeter() const { return 4*strana; }
    const float plostina() const { return strana*strana; }
    friend ostream& operator <<(ostream& os, const Kvadrat& square) {
        os << "Square with a=" << square.getA() << " has perimeter of " << square.perimeter() << ", area of " << square.plostina() << " and no volume.";
        return os;
    }
    void print() const {
        cout << (*this) << endl;
    }
};

class Pravoagolnik : public DvoDimenzionalni {
private:
    float sirina;
    float dolzina;
public:
    void setA(float a) { this->sirina = a; }
    void setB(float b) { this->dolzina = b; }
    const float getA() const { return sirina; }
    const float getB() const { return dolzina; }
    Pravoagolnik(float a = 0, float b = 0) { setA(a); setB(b); }
    const float perimeter() const { return 2*sirina + 2*dolzina; }
    const float plostina() const { return sirina*dolzina; }
    friend ostream& operator <<(ostream& os, const Pravoagolnik& rectangle) {
        os << "Rectangle " << rectangle.getA() << "x" << rectangle.getB() << " has perimeter of " << rectangle.perimeter() << ", area of " << rectangle.plostina() << " and no volume.";
        return os;
    }
    void print() const {
        cout << (*this) << endl;
    }
};

template <class T>
void sortirajPole (T* a, const int n) {
    T tempValue;
    int tempIndex;
    for (int i=0; i<n-1; i++) {
        tempIndex = i;
        for (int j=i; j<n; j++) {
            if (a[j] < a[tempIndex]) {
                tempIndex = j;
            }
        }
        tempValue = a[i];
        a[i] = a[tempIndex];
        a[tempIndex] = tempValue;
    }
}

template <class T>
void pecatiPole(T* array, const int count) { for ( int i = 0; i < count; i++ ) { cout << array[ i ] << endl; } }

Kvadrat addSquare() {
    float a;
    cout << "a="; cin >> a;
    return Kvadrat(a);
}

Pravoagolnik addRectangle() {
    float a, b;
    cout << "a="; cin >> a;
    cout << "b="; cin >> b;
    return Pravoagolnik(a, b);
}

int main()
{
    int n, m;
    Kvadrat squares[10];
    Pravoagolnik rectangles[10];
    cout << "How many squares do you want? "; cin >> n;
    for (int i=0; i<n; i++) {
        squares[i] = addSquare();
    }
    cout << "How many rectangles do you want? "; cin >> m;
    for (int i=0; i<m; i++) {
        rectangles[i] = addRectangle();
    }
    sortirajPole(squares, n);
    sortirajPole(rectangles, m);
    pecatiPole(squares, n);
    pecatiPole(rectangles, m);
    cout << "" << endl;
    return 0;
}
