#include <iostream>
#include <cstring>
#include <vector>
#include <algorithm>
#include <numeric>

using namespace std;

class Vraboten {
private:
    string ime;
    int bodovi;
public:
    static int multiplier;
    Vraboten(string name, int points) {
        setName(name);
        setPoints(points);
    }
    const string getName() const { return ime; }
    const int getPoints() const { return bodovi; }
    void setName(string name) { ime = name; }
    void setPoints(int points) { bodovi = points; }
    const int getSalary() const { return getPoints() * Vraboten::multiplier; }
    friend bool operator<(const Vraboten& e1, const Vraboten& e2) {
        return e1.getSalary() < e2.getSalary();
    }
    friend ostream& operator <<(ostream& os, const Vraboten& empl) {
        os << empl.getName() << ": " << empl.getSalary() << "$";
        return os;
    }
};
int Vraboten::multiplier = 10;

double operator+ (double d, const Vraboten& empl) {
    return d + empl.getSalary();
}

int main()
{
    vector<Vraboten> employees;
    cout << "How many employees are there? "; int n; cin >> n;
    string name;
    int points;
    for (int i=0; i<n; i++) {
        cout << "Name: "; cin >> name;
        cout << "Points: "; cin >> points;
        employees.push_back( Vraboten(name, points) );
    }
    sort(employees.begin(), employees.end());
    for (Vraboten& empl : employees) {
        cout << empl << endl;
    }
    int total = 0;
    cout << "The total is " << accumulate(employees.begin(), employees.end(), total) << endl;
    return 0;
}
