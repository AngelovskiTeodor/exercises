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
    friend istream& operator >>(istream& is, Kvadrat& square) {
        cout << "a="; float a; cin >> a; square.setA(a);
        return is;
    }
    bool operator==(const Kvadrat& square) { return this->getA() == square.getA(); }
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
    friend istream& operator >>(istream& is, Pravoagolnik& rectangle) {
        cout << "a="; float a; cin >> a; rectangle.setA(a);
        cout << "b="; float b; cin >> b; rectangle.setB(b);
        return is;
    }
    bool operator==(const Pravoagolnik& rectangle) { return (this->getA()==rectangle.getA()) && (this->getB()==rectangle.getB()); }
    void print() const {
        cout << (*this) << endl;
    }
};

class Krug : public DvoDimenzionalni {
private:
    float r;
public:
    void setR(float r) { this->r = r; }
    const float getR() const { return r; }
    Krug(float r = 0) { setR(r); }
    const float perimeter() const { return 2*r*M_PI; }
    const float plostina() const { return r*r*M_PI; }
    const float volumen() const { return 0; }
    friend ostream& operator <<(ostream& os, const Krug& circle) {
        os << "Circle with r=" << circle.r << " has perimeter of " << circle.perimeter() << ", area of " << circle.plostina() << " and no volume.";
        return os;
    }
    friend istream& operator >>(istream& is, Krug& circle) {
        cout << "r="; float r; cin >> r; circle.setR(r);
        return is;
    }
    bool operator==(const Krug& circle) { return this->getR()==circle.getR(); }
    void print() const {
        cout << (*this) << endl;
    }
};

template<class T>
class Mnozestvo {
private:
    T set[20];
    static int compare(T elem1, T elem2);
public:
    bool contains(const T elem) const;
    static T read();
    void add(const T elem);
    T get(const int index) const;
    void print() const;
    T max() const;
    static int numElements;
};
template <class T>
int Mnozestvo<T>::numElements = 0;

void selector(Mnozestvo<Kvadrat>& kvadrati, Mnozestvo<Pravoagolnik>& pravoagolnici, Mnozestvo<Krug>& krugovi, const int choice) {
    switch (choice) {
    case 0:
        kvadrati.add( Mnozestvo<Kvadrat>::read() );
        break;
    case 1:
        pravoagolnici.add( Mnozestvo<Pravoagolnik>::read() );
        break;
    case 2:
        krugovi.add( Mnozestvo<Krug>::read() );
        break;
    case 3:
        kvadrati.print();
        break;
    case 4:
        pravoagolnici.print();
        break;
    case 5:
        krugovi.print();
        break;
    case 6:
        cout << "Largest square: " << kvadrati.max() << endl;
        cout << "Largest rectangle: " << pravoagolnici.max() << endl;
        cout << "Largest circle: " << krugovi.max() << endl;
        break;
    case 7:
        cout << "There are " << Mnozestvo<Kvadrat>::numElements << " squares" << endl;
        cout << "There are " << Mnozestvo<Pravoagolnik>::numElements << " rectangles" << endl;
        cout << "There are " << Mnozestvo<Krug>::numElements << " circles" << endl;
        break;
    default:
        break;
    }
}

void menu(){
    cout << "1.  Add new square" << endl;
    cout << "2.  Add new rectangle" << endl;
    cout << "3.  Add new circle" << endl;
    cout << "4.  List all squares" << endl;
    cout << "5.  List all rectangles" << endl;
    cout << "6.  List all circles" << endl;
    cout << "7.  Find max elements" << endl;
    cout << "8.  Count elements" << endl;
    cout << "9.  Exit" << endl;
}

int main()
{
    int choice;
    Mnozestvo<Kvadrat> squares;
    Mnozestvo<Pravoagolnik> rectangles;
    Mnozestvo<Krug> circles;
    do {
        menu();
        cin >> choice;
        selector(squares, rectangles, circles, choice-1);
    } while (choice != 9);
    cout << "" << endl;
    return 0;
}

template <class T>
int Mnozestvo<T>::compare(T elem1, T elem2){
    return (-(elem1<elem2)) + (elem1==elem2) + (elem1>elem2);
}

template <class T>
bool Mnozestvo<T>::contains(const T elem) const {
    for (int i=0; i<Mnozestvo<T>::numElements; i++) {
        if (Mnozestvo<T>::compare(elem,set[i]) == 0) {
            return true;
        }
    }
    return false;
}

template <class T>
T Mnozestvo<T>::read() {
    T temp;
    cout << "Enter new element: "; cin >> temp;
    return temp;
}

template <class T>
void Mnozestvo<T>::add(const T elem) {
    if (Mnozestvo<T>::contains(elem)) {
        return;
    }
    set[Mnozestvo<T>::numElements++] = elem;
}

template <class T>
T Mnozestvo<T>::get(const int index) const {
    return set[index];
}

template <class T>
void Mnozestvo<T>::print() const {
    for (int i=0; i<Mnozestvo<T>::numElements; i++) {
        cout << set[i] << "\t";
        if (i%4==3) { cout << endl; }
    }
    cout << endl;
}

template <class T>
T Mnozestvo<T>::max() const {
    T temp = set[0];
    for (int i=0; i<Mnozestvo<T>::numElements; i++) {
        if (Mnozestvo<T>::compare(set[i], temp)) {
            temp = set[i];
        }
    }
    return temp;
}
