#include <iostream>
#include <cstring>

using namespace std;

template <class T>
T defaultValue() {
    return (T) 0;
}

template < class T >
class Lica {
private:
    char imeiprezime[32];
    char mat_br[14];
    int vozrast;
    char adresa[64];
    T kod;
public:
    Lica(const char name[32] = "",
         const char ssn[14] = "",
         const int age = 0,
         const char* address = "",
         const T code = defaultValue<T>()
    ) {
        setName(name);
        setSSN(ssn);
        setAge(age);
        setAddress(address);
        setCode(code);
    }
    const char* getName() const { return imeiprezime; }
    void setName(const char* name) { strncpy(this->imeiprezime, name, sizeof(this->imeiprezime) - 1); }
    const char* getSSN() const { return mat_br; }
    void setSSN(const char ssn[14]) { strncpy(this->mat_br, ssn, sizeof(this->mat_br) - 1); }
    int getAge() const { return vozrast; }
    void setAge(int age) { this->vozrast = age; }
    const char* getAddress() const { return adresa; }
    void setAddress(const char* address) { strncpy(this->adresa, address, sizeof(this->adresa) - 1); }
    const T getCode() const { return kod; }
    void setCode(T code) { this->kod = code; }
    friend ostream& operator <<(ostream& os, const Lica& person) {
        os << "[" << person.getCode() << "]: " << person.getName() << " is " << person.getAge() << " years old and lives at " << person.getAddress();
        return os;
    }
    Lica readPerson(){
        char name[32];
        char ssn[14];
        int age;
        char address[64];
        T code;
        cout << "Name: "; cin >> name;
        cout << "Social Security number: "; cin >> ssn;
        cout << "Age: "; cin >> age;
        cout << "Address: "; cin >> address;
        cout << "Code: "; cin >> code;
        return Lica(name, ssn, age, address, code);
    }
};

template <class T>
void pecatiPole(const T* array, const int count) { for ( int i = 0; i < count; i++ ) { cout << array[ i ] << endl; } }

template <class T>
void add(T* persons, int& n){
    T new_person = persons->readPerson();
    persons[n] = new_person;
    n++;
}

template <class T>
void list(const T* persons, int& n) { pecatiPole<T>(persons, n); }

void selector(Lica<int>* employees, int& numEmployees, Lica<char>* clients, int& numClients, const int choice) {
    cout << "debugging selector" << endl;
    switch (choice) {
    case 0:
        cout << "debugging new employee" << endl;
        add<Lica<int>>(employees, numEmployees);
        break;
    case 1:
        cout << "debugging new client" << endl;
        add<Lica<char>>(clients, numClients);
        break;
    case 2:
        cout << "debugging list employees" << endl;
        list<Lica<int>>(employees, numEmployees);
        break;
    case 3:
        cout << "debugging list clients" << endl;
        list<Lica<char>>(clients, numClients);
        break;
    default:
        break;
    }
}

void menu(){
    cout << "1.  Add new employee: " << endl;
    cout << "2.  Add new client: " << endl;
    cout << "3.  List all employees: " << endl;
    cout << "4.  List all clients: " << endl;
    cout << "5.  Izlez" << endl;
}

int main()
{
    int choice;
    const int SIZE = 20;
    Lica<int> Vraboteni[SIZE];
    int numEmployees = 0;
    Lica<char> Klienti[SIZE];
    int numClients = 0;
    do {
        menu();
        cin >> choice;
        selector(Vraboteni, numEmployees, Klienti, numClients, choice-1);
    } while (choice != 5);
    cout << "" << endl;
    return 0;
}
