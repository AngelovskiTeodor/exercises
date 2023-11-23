#include <iostream>

using namespace std;

int generateRandomInt(const int min, const int max) {
    int ret = rand()%(max-min);
    return ret + min;
}

char generateRandomChar() {
    char ret = (char)generateRandomInt( (char)'A', (char)'Z' );
    return ret;
}

string generateRandomString() {
    string ret;
    int size = rand()%(10-5);
    ret.reserve(size);
    for (int i=0; i<size; i++) {
        ret += generateRandomChar();
    }
    return ret;
}

template < class T >
class Pole {
private:
    T array[50];
    int count;
public:
    Pole(int n = 0) {
        count = n;
    }
    void set(T elem, const int index) {
        array[index] = elem;
    }
    void add(T elem) {
        if (count >= 50) {
            cout << "Max size reached" << endl;
            return;
        }
        array[count] = elem;
        count++;
    }
    T get(const int index) const {
        if (index < 0 || index >= count) {
            throw runtime_error("Invalid index");
        }
        return array[index];
    }
    friend ostream& operator <<(ostream& os, const Pole& arr) {
        for (int i=0; i<arr.count; i++) {
            os << arr.get(i) << "\t";
            if (i%4==3) { os << endl; }
        }
        return os;
    }
    const int size() const { return count; }
    const T max() {
        T ret = this->get(0);
        for (int i=0; i<this->size(); i++) {
            if (this->get(i) > ret) {
                ret = this->get(i);
            }
        }
        return ret;
    }
    static T read() {
        T temp;
        cout << "Enter new element: "; cin >> temp;
        return temp;
    }
    void print() const {
        for (int i=0; i<this->size(); i++) {
            cout << array[i] << "\t";
            if (i%4==3) { cout << endl; }
        }
        cout << endl;
    }
};

void selector(Pole<int>& ints, Pole<char>& chars, Pole<string>& strings, const int choice) {
    switch (choice) {
    case 0:
        ints.add( Pole<int>::read() );
        break;
    case 1:
        chars.add( Pole<char>::read() );
        break;
    case 2:
        strings.add( Pole<string>::read() );
        break;
    case 3:
        ints.print();
        break;
    case 4:
        chars.print();
        break;
    case 5:
        strings.print();
        break;
    case 6:
        cout << "Max int: " << ints.max() << endl;
        cout << "Max real: " << chars.max() << endl;
        cout << "Max string: " << strings.max() << endl;
        break;
    case 7:
        cout << "There are " << ints.size() << " integers" << endl;
        cout << "There are " << chars.size() << " characters" << endl;
        cout << "There are " << strings.size() << " strings" << endl;
        break;
    default:
        break;
    }
}


void menu(){
    cout << "1.  Add new integer " << endl;
    cout << "2.  Add new char " << endl;
    cout << "3.  Add new string " << endl;
    cout << "4.  List all integers " << endl;
    cout << "5.  List all chars " << endl;
    cout << "6.  List all strings " << endl;
    cout << "7.  Find max elements " << endl;
    cout << "8.  Count elements " << endl;
    cout << "9.  Exit " << endl;
}

int main()
{
    int choice;
    Pole<int> ints;
    Pole<char> chars;
    Pole<string> strings;
    do {
        menu();
        cin >> choice;
        selector(ints, chars, strings, choice-1);
    } while (choice != 9);

    cout << "" << endl;
    return 0;
}
