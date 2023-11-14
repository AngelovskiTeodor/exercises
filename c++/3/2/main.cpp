#include <iostream>
#include <cstring>

using namespace std;

class Stedac {
public:
    void vnesi_podatoci();
    void prikazi_podatoci();
    void uplata(unsigned long i);
    void isplata(unsigned long i);
    long sostojba();
    Stedac();
    Stedac(int broj, const char* imeprezime, const char* adresa, long saldo);
    int getBroj() const;
    const char* getImeprezime() const;
    const char* getAdresa() const;
    long getSaldo() const;
    void setBroj(int broj);
    void setImeprezime(const char* imeprezime);
    void setAdresa(const char* adresa);
    void setSaldo(long saldo);
private:
    int broj;
    char imeprezime[30], adresa[50];
    long saldo;
};

void menu() {
    cout << "Izberete opcija: " << endl;
    cout << "0 Vnesi nov stedac" << endl;
    cout << "1 Prikaz na stedac" << endl;
    cout << "2 Uplata na sredstva" << endl;
    cout << "3 Isplata na sredstva" << endl;
    cout << "4 Prikaz na saldo" << endl;
    cout << "5 Izlez" << endl;
}

void vnesi_podatoci(Stedac& stedac){
    stedac.vnesi_podatoci();
}

void prikazi_podatoci(Stedac& stedac){
    stedac.prikazi_podatoci();
}

void uplata(Stedac& stedac){
    cout << "Kolku sakate da uplatite? ";
    long amount; cin >> amount;
    stedac.uplata(amount);
}

void isplata(Stedac& stedac){
    cout << "Kolku sakate da osplatite? ";
    long amount; cin >> amount;
    stedac.isplata(amount);
}

void sostojba(Stedac& stedac){
    cout << "Stedacot ima " << stedac.sostojba() << endl;
}

void selector(Stedac& stedac, int choice) {
    void (*options[5]) (Stedac& stedac) = {vnesi_podatoci, prikazi_podatoci, uplata, isplata, sostojba};
    options[choice](stedac);
}

int main()
{
    Stedac stedac;

    int choice;
    do {
        menu();
        cin >> choice;
        selector(stedac, choice);
    } while (choice != 5);

    cout << "" << endl;
    return 0;
}


Stedac::Stedac(int broj, const char* imeprezime, const char* adresa, long saldo) {
    this->broj = broj;
    strncpy(this->imeprezime, imeprezime, sizeof(this->imeprezime));
    strncpy(this->adresa, adresa, sizeof(this->adresa));
    this->saldo = saldo;
}

Stedac::Stedac(){
    this->broj = 0;
    strncpy(this->imeprezime, "", sizeof(this->imeprezime));
    strncpy(this->adresa, "", sizeof(this->adresa));
    this->saldo = 0;
}

int Stedac::getBroj() const { return broj; }


void Stedac::setBroj(int broj) { this->broj = broj; }


const char* Stedac::getImeprezime() const { return imeprezime; }


void Stedac::setImeprezime(const char* imeprezime) { strncpy(this->imeprezime, imeprezime, sizeof(this->imeprezime)); }


const char* Stedac::getAdresa() const { return adresa; }


void Stedac::setAdresa(const char* adresa) { strncpy(this->adresa, adresa, sizeof(this->adresa)); }


long Stedac::getSaldo() const { return saldo; }


void Stedac::setSaldo(long saldo) { this->saldo = saldo; }

void Stedac::vnesi_podatoci() {
    int broj;
    char imeprezime[30], adresa[50];
    long saldo;

    cout << "Vnesi broj: "; cin >> broj;
    cout << "Vnesi ime i prezime: "; cin >> imeprezime;
    cout << "Vnesi adresa: "; cin >> adresa;
    cout << "Vnesi saldo: "; cin >> saldo;

    this->setBroj(broj);
    this->setImeprezime(imeprezime);
    this->setAdresa(adresa);
    this->setSaldo(saldo);
}

void Stedac::prikazi_podatoci() {
    cout << "Stedac br. " << this->getBroj()
         << ": " << this->imeprezime << " na adresa "
         << this->getAdresa() << " ima saldo " << this->getSaldo() << endl;
}

void Stedac::uplata(unsigned long i) {
    long balance = this->getSaldo();
    balance += i;
    this->setSaldo(balance);
}

void Stedac::isplata(unsigned long i) {
    long balance = this->getSaldo();
    balance -= i;
    if (balance < 0) {
        cout << "Stedacot nema dovolno sredstva za da se izvrsi isplatata" << endl;
        return;
    }
    this->setSaldo(balance);
}

long Stedac::sostojba() {
    return this->getSaldo();
}
