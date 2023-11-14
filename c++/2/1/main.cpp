#include <iostream>

using namespace std;

template< class T >
T minimal_value( T value1, T value2 )
{
    return (value1 < value2)?(value1):(value2);
}

int main()
{
    int integer1, integer2;
    cout << "Enter first value: ";
    cin >> integer1;
    cout << "Enter second value: ";
    cin >> integer2;
    cout << "The minimum is " << minimal_value(integer1, integer2) << endl;

    float float1, float2;
    cout << "Enter first value: ";
    cin >> float1;
    cout << "Enter second value: ";
    cin >> float2;
    cout << "The minimum is " << minimal_value(float1, float2) << endl;

    char char1, char2;
    cout << "Enter first character: ";
    cin >> char1;
    cout << "Enter second character: ";
    cin >> char2;
    cout << "The minimum is " << minimal_value(char1, char2) << endl;
    return 0;
}
