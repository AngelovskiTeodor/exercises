#include <iostream>
#include <exception>
#include <vector>
#include <cstddef>
#include <algorithm>

using namespace std;

class Exception : public exception {
private:
    string msg;
public:
    Exception(string message) : exception() {
        msg = message;
    }
    const string Message() { return msg; }
};

class DifferentSizesException : public Exception {
public:
    DifferentSizesException() : Exception ("The vectors have different number of elements") {}
};

vector<int> generateRandomVector(const int size, const int start, const int end) {
    vector<int> rands;
    for (int i=0; i<size; i++) {
        rands.push_back( start + rand()%(end-start) );
    }
    return rands;
}

int main()
{
    const int START = 1;
    const int END = 1000;
    int size;
    vector<int> v1;
    vector<int> v2;

    for (int i=0; i<100; i++) {
        size = rand()%(END-START);
        v1 = generateRandomVector(size, START, END);
        size = rand()%(END-START);
        v2 = generateRandomVector(size, START, END);
        try {
            if (v1.size() != v2.size()) { throw DifferentSizesException(); }
        }
        catch (DifferentSizesException & differentSizesException) {
            cout << differentSizesException.Message() << endl;
        }
    }

    cout << "" << endl;
    return 0;
}
