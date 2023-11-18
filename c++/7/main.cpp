#include <iostream>
#include <stdexcept>

using namespace std;

long minimumValue(long val1, long val2){
    return (val1 < val2) ? (val1) : (val2);
}

long maximumValue(long val1, long val2){
    return (val1 > val2) ? (val1) : (val2);
}

class Dropki {
private:
    long numerator;
    long denominator;
    void reduce(){
        long min = minimumValue(this->getNumerator(), this->getDenominator());
        long max = maximumValue(this->getNumerator(), this->getDenominator());
        for (long i=2; i<=min; i++) {
            if ((numerator%i==0) && (denominator%i==0)) {
                this->denominator = this->denominator/i;
                this->numerator = this->numerator/i;
                i--;
                min = minimumValue(this->getNumerator(), this->getDenominator());
            }
        }
    }

public:
    Dropki(long numerator, long denominator){
        this->numerator = numerator;
        this->setDenominator(denominator);
    }

    long getNumerator() const {
        return this->numerator;
    }

    void setNumerator(long numerator) {
        this->numerator = numerator;
        this->reduce();
    }

    long getDenominator() const {
        return this->denominator;
    }

    void setDenominator(long denominator) {
        if (denominator == 0) {
            throw runtime_error("The denominator can not be 0");
        }
        this->denominator = denominator;
        this->reduce();
    }

    float getFloat(){
        return (float) this->numerator / (float) this->denominator;
    }

    Dropki operator + (const Dropki& frac) {
        long newNumerator = this->getNumerator()*frac.getDenominator() + frac.getNumerator()*this->getDenominator();
        long newDenominator = this->getDenominator() * frac.getDenominator();
        Dropki newFrac = Dropki(newNumerator, newDenominator);
        return newFrac;
    }

    Dropki operator - (const Dropki& frac) {
        long newNumerator = this->getNumerator()*frac.getDenominator() - frac.getNumerator()*this->getDenominator();
        long newDenominator = this->getDenominator() * frac.getDenominator();
        Dropki newFrac = Dropki(newNumerator, newDenominator);
        return newFrac;
    }

    Dropki operator * (const Dropki& frac) {
        long newNumerator = this->getNumerator() * frac.getNumerator();
        long newDenominator = this->getDenominator() * frac.getDenominator();
        Dropki newFrac = Dropki(newNumerator, newDenominator);
        return newFrac;
    }

    Dropki operator / (const Dropki& frac) {
        long newNumerator = this->getNumerator() / frac.getDenominator();
        long newDenominator = this->getDenominator() / frac.getNumerator();
        Dropki newFrac = Dropki(newNumerator, newDenominator);
        return newFrac;
    }

    //  fraction and integer
    Dropki operator + (const int num) {
        long newNumerator = this->getNumerator() + num*this->getDenominator();
        long newDenominator = this->getDenominator();
        Dropki newFrac = Dropki(newNumerator, newDenominator);
        return newFrac;
    }

    Dropki operator - (const int num) {
        long newNumerator = this->getNumerator() - num*this->getDenominator();
        long newDenominator = this->getDenominator();
        Dropki newFrac = Dropki(newNumerator, newDenominator);
        return newFrac;
    }

    Dropki operator * (const int num) {
        long newNumerator = this->getNumerator() * num;
        long newDenominator = this->getDenominator();
        Dropki newFrac = Dropki(newNumerator, newDenominator);
        return newFrac;
    }

    Dropki operator / (const int num) {
        long newNumerator = this->getNumerator();
        long newDenominator = this->getDenominator() * num;
        Dropki newFrac = Dropki(newNumerator, newDenominator);
        return newFrac;
    }
    //  end fraction and integer

    friend ostream& operator<<(ostream& os, Dropki const& frac) {
        os << frac.getNumerator() <<"/"<< frac.getDenominator();
        return os;
    }
    void printFraction(){
        cout << "The fraction is " << *this;
    }
    void printFloat(){
        cout << "The fraction " << (*this) << " is equal to the real number " << this->getFloat() << endl;
    }
};

Dropki readFrac() {
    long numerator;
    long denominator;
    cout << "Enter numerator" << endl;
    cin >> numerator;
    cout << "Enter denominator" << endl;
    cin >> denominator;
    return Dropki(numerator, denominator);
}

void add() {
    cout << "Enter the first fraction: " << endl;
    Dropki frac1 = readFrac();
    cout << "Enter the second fraction to add: " << endl;
    Dropki frac2 = readFrac();
    cout << frac1 << "+" << frac2 << "=" << (frac1+frac2) << endl;
}

void substract() {
    cout << "Enter the first fraction: " << endl;
    Dropki frac1 = readFrac();
    cout << "Enter the second fraction to substract: " << endl;
    Dropki frac2 = readFrac();
    cout << frac1 << "-" << frac2 << "=" << (frac1-frac2) << endl;
}

void multiply() {
    cout << "Enter the first fraction: " << endl;
    Dropki frac1 = readFrac();
    cout << "Enter the second fraction to multiply: " << endl;
    Dropki frac2 = readFrac();
    cout << frac1 << "*" << frac2 << "=" << (frac1*frac2) << endl;
}

void divide() {
    cout << "Enter the first fraction: " << endl;
    Dropki frac1 = readFrac();
    cout << "Enter the second fraction to divide: " << endl;
    Dropki frac2 = readFrac();
    cout << frac1 << "/" << frac2 << "=" << (frac1/frac2) << endl;
}

//  fraction and integer
void addInt() {
    cout << "Enter the first fraction: " << endl;
    Dropki frac1 = readFrac();
    cout << "Enter the integer to add: " << endl;
    int num; cin >> num;
    cout << frac1 << "+" << num << "=" << (frac1+num) << endl;
}

void substractInt() {
    cout << "Enter the first fraction: " << endl;
    Dropki frac1 = readFrac();
    cout << "Enter the integer to substract: " << endl;
    int num; cin >> num;
    cout << frac1 << "-" << num << "=" << (frac1-num) << endl;
}

void multiplyInt() {
    cout << "Enter the first fraction: " << endl;
    Dropki frac1 = readFrac();
    cout << "Enter the integer to multiply: " << endl;
    int num; cin >> num;
    cout << frac1 << "*" << num << "=" << (frac1*num) << endl;
}

void divideInt() {
    cout << "Enter the first fraction: " << endl;
    Dropki frac1 = readFrac();
    cout << "Enter the integer to divide: " << endl;
    int num; cin >> num;
    cout << frac1 << "/" << num << "=" << (frac1/num) << endl;
}

void selector(int choice) {
    void (*options[8]) () = {add, substract, multiply, divide, addInt, substractInt, multiplyInt, divideInt};
    options[choice]();
}

void menu() {
    cout << "Please choose an option: " << endl;
    cout << "1 Add fractions" << endl;
    cout << "2 Substract fractions" << endl;
    cout << "3 Multiply fractions" << endl;
    cout << "4 Divide fractions" << endl;
    cout << "5 Add fractions" << endl;
    cout << "6 Substract fractions" << endl;
    cout << "7 Multiply fractions" << endl;
    cout << "8 Divide fractions" << endl;
    cout << "9 Exit" << endl;
}

void fractionsDriver() {
    int choice;
    do {
        menu();
        cin >> choice;
        selector(choice-1);
    } while (choice != 9);
}

int main()
{
    fractionsDriver();

    cout << "" << endl;
    return 0;
}
