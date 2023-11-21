#include <iostream>
#include <cstring>
using namespace std;

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

void selector(Mnozestvo<int> ints, Mnozestvo<double> doubles, Mnozestvo<char*> strings, const int choice) {
    switch (choice) {
    case 0:
        ints.add( Mnozestvo<int>::read() );
        break;
    case 1:
        doubles.add( Mnozestvo<double>::read() );
        break;
    case 2:
        strings.add( Mnozestvo<char*>::read() );
        break;
    case 3:
        ints.print();
        break;
    case 4:
        doubles.print();
        break;
    case 5:
        strings.print();
        break;
    case 6:
        cout << "Max int: " << ints.max() << endl;
        cout << "Max real: " << doubles.max() << endl;
        cout << "Max string: " << strings.max() << endl;
        break;
    case 7:
        cout << "There are " << Mnozestvo<int>::numElements << " integers" << endl;
        cout << "There are " << Mnozestvo<double>::numElements << " reals" << endl;
        cout << "There are " << Mnozestvo<char*>::numElements << " strings" << endl;
        break;
    default:
        break;
    }
}

void menu(){
    cout << "1.  Add new integer: " << endl;
    cout << "2.  Add new real: " << endl;
    cout << "3.  Add new string: " << endl;
    cout << "4.  List all integers: " << endl;
    cout << "5.  List all reals: " << endl;
    cout << "6.  List all strings: " << endl;
    cout << "7.  Find max elements: " << endl;
    cout << "8.  Count elements: " << endl;
    cout << "9.  Izlez" << endl;
}

int main()
{
    int choice;
    Mnozestvo<int> ints;
    Mnozestvo<double> doubles;
    Mnozestvo<char*> strings;
    do {
        menu();
        cin >> choice;
        selector(ints, doubles, strings, choice-1);
    } while (choice != 9);
    cout << "" << endl;
    return 0;
}

template <class T>
int Mnozestvo<T>::compare(T elem1, T elem2){
    return (-(elem1<elem2)) + (elem1==elem2) + (elem1>elem2);
}

template <>
int Mnozestvo<char*>::compare(char* elem1, char* elem2){
    return strcmp(elem1, elem2);
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
