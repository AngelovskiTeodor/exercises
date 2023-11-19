#include <iostream>

using namespace std;

template <class T>
T sum(T* arr, const int starting_index, const int ending_index, T starting_value = T(0)) {
    for (int i = starting_index; i < ending_index; i++) {
        starting_value += arr[i];
    }
    return starting_value;
}

int main()
{
    int a[10];
    int n;
    cout << "n=" << endl; cin >> n;
    for (int i=0; i<n; i++) {
        cout << "a[" << i << "]="; cin >> a[i];
    }
    cout << "The sum is " << sum(a, 0, n) << endl;
    return 0;
}
