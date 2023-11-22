#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

int main()
{
    cout << "Printing the square, square root and cubic root of all numbers to n" << endl;
    int column_width;cout << "Enter the width of the columns: "; cin >> column_width;

    int n; cout << "n="; cin >> n;
    cout << "i\ti squared\tsquare root of i\tcubic root of i"<<endl;
    for (int i=1; i<=n; i++) {
        cout.precision(3);
        cout << setw(column_width) << i << setw(column_width) << i*i << setw(column_width) << sqrt(i) << setw(column_width) << cbrt(i) << endl;
    }
    cout << "" << endl;
    return 0;
}
