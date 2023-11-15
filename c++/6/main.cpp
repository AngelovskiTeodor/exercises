#include <iostream>
#include <cstring>

using namespace std;

class Covek {
public:
    Covek(const char* name, const char* surname, const char* address, const char* phone) {
        strncpy(this->name, name, sizeof(this->name) - 1);
        strncpy(this->surname, surname, sizeof(this->surname) - 1);
        strncpy(this->address, address, sizeof(this->address) - 1);
        strncpy(this->phone, phone, sizeof(this->phone) - 1);

        this->name[sizeof(this->name) - 1] = '\0';
        this->surname[sizeof(this->surname) - 1] = '\0';
        this->address[sizeof(this->address) - 1] = '\0';
        this->phone[sizeof(this->phone) - 1] = '\0';
    }

    Covek(){}

    const char* getName() const {
        return name;
    }

    void setName(const char* name) {
        strncpy(this->name, name, sizeof(this->name) - 1);
        this->name[sizeof(this->name) - 1] = '\0';
    }

    const char* getSurname() const {
        return surname;
    }

    void setSurname(const char* surname) {
        strncpy(this->surname, surname, sizeof(this->surname) - 1);
        this->surname[sizeof(this->surname) - 1] = '\0';
    }

    const char* getAddress() const {
        return address;
    }

    void setAddress(const char* address) {
        strncpy(this->address, address, sizeof(this->address) - 1);
        this->address[sizeof(this->address) - 1] = '\0';
    }

    const char* getPhone() const {
        return phone;
    }

    void setPhone(const char* phone) {
        strncpy(this->phone, phone, sizeof(this->phone) - 1);
        this->phone[sizeof(this->phone) - 1] = '\0';
    }
private:
    char name[32];
    char surname[32];
    char address[64];
    char phone[16];
};

class Stedac {
public:
    static int brojStedaci;
    Stedac(Covek person, float balance, float credit){
        lice = person;
        bilans = balance;
        kredit = credit;
        brojStedaci++;
    }
    Covek& getLice(){ return lice; }
    void setLice(Covek& person) { lice = person; }
    float getBilans() const { return bilans; }
    void setBilans(float balance) { bilans = balance; }
    float getKredit() const { return kredit; }
    void setKredit(float credit) { kredit = credit; }
private:
    Covek lice;
    float bilans;
    float kredit;
};

int Stedac::brojStedaci = 0;

int main()
{
    char name[32];
    char surname[32];
    char address[64];
    char phone[16];
    float balance;
    float credit;
    cout << "Enter name: "; cin >> name;
    cout << "Enter surname: "; cin >> surname;
    cout << "Enter address: "; cin >> address;
    cout << "Enter phone: "; cin >> phone;
    cout << "Enter balance: "; cin >> balance;
    cout << "Enter credit: "; cin >> credit;
    Covek person = Covek(name, surname, address, phone);
    Stedac account = Stedac(person, balance, credit);
    cout << "Number of total accounts " << Stedac::brojStedaci << endl;
    return 0;
}
