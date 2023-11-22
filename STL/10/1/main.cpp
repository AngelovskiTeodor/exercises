#include <iostream>

using namespace std;

class MyException : public exception {};

class MyClass {
public:
    static int numObjects;
    MyClass() { ++numObjects; }
    ~MyClass() { --numObjects; }
    void throwException() {
        throw MyException();
    }
};
int MyClass::numObjects = 0;

int main()
{
    MyClass myObject = MyClass();
    cout << "There is/are " << MyClass::numObjects << " object(s) before throwing exception" << endl;
    try {
        myObject.throwException();
    } catch (MyException& myException) {
        cout << "MyException has been thrown" << endl;
    }
    cout << "There is/are " << MyClass::numObjects << " object(s) after throwing exception" << endl;
    cout << "" << endl;
    return 0;
}
