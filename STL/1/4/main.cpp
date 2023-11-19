#include <iostream>

using namespace std;

template< class T >
void printArray( const T *array, const int count ){
    //    for ( int i = 0; i < count; i++ ) { cout << "a[" << i << "]=" <<array[ i ] << endl; }
    for ( int i = 0; i < count; i++ ) { cout << array[ i ] << " "; }
    cout << endl;
}

template< class T >
void printArray( const T *array, const int count, const int lowSubscript, const int highSubscript ){
    if (lowSubscript < 0 || highSubscript > count) { return ; }
    printArray(array+lowSubscript, highSubscript-lowSubscript);
}

void printArray(const int* arr, const int count) {
    for (int i=0; i<count; i++) {
        cout << arr[i] << "\t";
        if (i%4==3) { cout << endl; }
    }
}

int main()
{
    int a[10];
    int n;
    cout << "n=" << endl; cin >> n;
    for (int i=0; i<n; i++) {
        cout << "a[" << i << "]="; cin >> a[i];
    }
//    int lowSubscript, highSubscript;
//    cout << "lowSubscript="; cin >> lowSubscript;
//    cout << "highSubscript="; cin >> highSubscript;
//    printArray(a, n, lowSubscript, highSubscript);
    printArray(a,n);
    cout << "" << endl;
    return 0;
}
