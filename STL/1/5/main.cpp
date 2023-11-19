#include <iostream>

using namespace std;

template < class T >
class Array {
private:
    T array[50];
    int count;
public:
    Array(int n) {
        count = n;
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
    friend ostream& operator <<(ostream& os, const Array& arr) {
        for (int i=0; i<arr.count; i++) {
            os << arr.get(i) << "\t";
            if (i%4==3) { os << endl; }
        }
        return os;
    }
};

int main()
{
    int n;
    cout << "n=" << endl; cin >> n;
    Array a = Array<int>(n);
    for (int i=0; i<n; i++) {
        int temp;
        cout << "a[" << i << "]="; cin >> temp;
        a.add(temp);
    }
    cout << a << endl;

    cout << "n=" << endl; cin >> n;
    Array b = Array<double>(n);
    for (int i=0; i<n; i++) {
        double temp;
        cout << "b[" << i << "]="; cin >> temp;
        b.add(temp);
    }
    cout << b << endl;

    cout << "" << endl;
    return 0;
}
