#include <iostream>

using namespace std;

int tripleCallByValue(int count){
    return 3*count;
}

void tripleCallByReference(int &count){
    count = 3*count;
}

int main()
{
    int count;
    cout << "Enter value to triple it: ";
    cin >> count;

    cout << "Tripling by value: " << tripleCallByValue(count) << endl;
    tripleCallByReference(count);
    cout << "Tripling by reference: " << count << endl;
    return 0;
}
