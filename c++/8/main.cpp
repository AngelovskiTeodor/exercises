#include <iostream>

using namespace std;

class Complex {
private:
    double real;
    double imaginary;
public:
    Complex( double r = 0.0, double i = 0.0 ) : real( r ), imaginary( i ) { }
    Complex operator+( const Complex &operand2 ) const {
        return Complex( real + operand2.real,
                       imaginary + operand2.imaginary );
    }
    Complex operator-( const Complex &operand2 ) const {
        return Complex( real - operand2.real,
                       imaginary - operand2.imaginary );
    }
    const Complex &operator=( const Complex &right ) {
        real = right.real;
        imaginary = right.imaginary;
        return *this;
    }
    friend ostream& operator<<(ostream& os, Complex& complex) {
        os << '(' << complex.real << ", " << complex.imaginary << ')';
        return os;
    }
    friend istream& operator>>(istream& is, Complex& complex) {
        cout << "Real: "; is >> complex.real;
        cout << "Imaginary: "; is >> complex.imaginary;
        return is;
    }
    Complex operator*(const Complex& operand2) {
        return Complex (real*operand2.real, imaginary*operand2.imaginary);
    }
    Complex operator*(const int operand2) {
        return Complex (real*operand2, imaginary);
    }
    friend Complex operator*(const int operand1, const Complex& operand2) {
        return Complex (operand1*operand2.real, operand2.imaginary);
    }
    bool operator==(const Complex& operand2) {
        return (real == operand2.real) && (imaginary == operand2.imaginary);
    }
    bool operator!=(const Complex& operand2) {
        return (real != operand2.real) || (imaginary != operand2.imaginary);
    }
    Complex& operator+=(const Complex& right) {
        (*this) = (*this) + right;
        return (*this);
    }
    Complex& operator-=(const Complex& right) {
        (*this) = (*this) - right;
        return (*this);
    }
    Complex& operator*=(const Complex& right) {
        (*this) = (*this) * right;
        return (*this);
    }
};

int main()
{
    Complex x, y( 4.3, 8.2 ), z( 3.3, 1.1 );

    cout << "x: ";
    cout << x;
    cout << "\ny: ";
    cout << y;
    cout << "\nz: ";
    cout << z;

    x = y + z;
    cout << "\n\nx = y + z:\n";
    cout << x;
    cout << " = ";
    cout << y;
    cout << " + ";
    cout << z;

    x = y - z;
    cout << "\n\nx = y - z:\n";
    cout << x;
    cout << " = ";
    cout << y;
    cout << " - ";
    cout << z;
    cout << endl;

    return 0;
}
