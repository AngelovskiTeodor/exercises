#include <iostream>

using namespace std;

template <class T>
void sort (T* a, const int n) {
    T tempValue;
    int tempIndex;
    for (int i=0; i<n-1; i++) {
        tempIndex = i;
        for (int j=i; j<n; j++) {
            if (a[j] < a[tempIndex]) {
                tempIndex = j;
            }
        }
        tempValue = a[i];
        a[i] = a[tempIndex];
        a[tempIndex] = tempValue;
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
    sort( a, n );
    for (int i=0; i<n; i++) {
        cout << "a[" << i << "]=" << a[i] << endl;
    }
    cout << "" << endl;
    return 0;
}
