#include <iostream>

using namespace std;

template <class T>
class Zapis {
private:
    T x;
    T y;
    T z;
public:
    Zapis(T x, T y, T z) : x(x), y(y), z(z) {}
    T getX() const { return x; }
    T getY() const { return y; }
    T getZ() const { return z; }
    friend ostream& operator<<(ostream& os, const Zapis<T>& record) {
        os << "x: " << record.x << ", y: " << record.y << ", z: " << record.z;
        return os;
    }
};

template <class T>
bool kontrolor(Zapis<T> record) {
    return (record.getX() + record.getY() + record.getZ()) >= 10000;
}

int main()
{
    Zapis<int> intRecord(5000, 2000, 8000);
    Zapis<double> doubleRecord(3.25, 17.32, 245.009);
    cout << "Checking intRecord: " << ((kontrolor<int>(intRecord))?("checked"):("failed")) << endl;
    cout << "Checking doubleRecord: " << ((kontrolor<double>(doubleRecord))?("checked"):("failed")) << endl;
    return 0;
}
