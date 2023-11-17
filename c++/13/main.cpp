#include <iostream>
#include <cstdio>
#include <cstring>
#include <ctime>

using namespace std;

class Date {
public:
    Date( int dy = 1, int mn = 1, int yr = 2007 ) {
        if ( mn > 0 && mn <= 12 ) { month = mn; }
        else { month = 1; }
        year = yr;
        day = checkDay( dy );
    }

    void print() const { cout << day << '/' << month << '/' << year; }

    ~Date(){}

    int getDay() const { return day; }

    int getMonth() const { return month; }

    int getYear() const { return year; }

    long toDays() const { return this->day + this->month*daysPerMonth[this->month] + this->year*365; }

    friend int operator -(Date const& date1, Date const& date2){
        int days1 = date1.day + date1.month*daysPerMonth[date1.month] + date1.year*365;
        int days2 = date2.day + date2.month*daysPerMonth[date2.month] + date2.year*365;
        return days1 - days2;
    }

    friend ostream& operator <<(ostream& os, Date const& date) {
        os << date.getDay() << '/' << date.getMonth() << '/' << date.getYear();
        return os;
    }

    static Date now() {
        time_t t = time(0);
        tm* time_now = localtime(&t);
        int day = time_now->tm_mday;
        int month = time_now->tm_mon + 1;
        int year = time_now->tm_year + 1900;
        return Date(day, month, year);
    }

private:
    int month;
    int day;
    int year;

    static const int daysPerMonth[ 13 ];

    int checkDay( int testDay ){
        if ( testDay > 0 && testDay <= daysPerMonth[ month ] )
            return testDay;

        if (month == 2 &&
            testDay == 29 &&
            ( year % 400 == 0 ||
             ( year % 4 == 0 && year % 100 != 0 ) )
            )
            return testDay;

        return 1;
    }
};
const int Date::daysPerMonth[ 13 ] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

class Zivotno {
protected:
    char Ime[32];
    char Pol;   // (m/z)
    Date Datum_na_ragjanje;
    Date Datum_na_donesuvawe_vo_zoo;
    Date Datum_na_posledna_vakcinacija;
public:
    Zivotno(const char* ime, const char pol,
            const Date datumRagjanje,
            const Date datumDonesuvanje,
            const Date datumPoslednaVakcinacija
            ){
        strncpy(this->Ime, ime, sizeof(this->Ime) - 1);
        //this->tip = tip;
        this->Pol = pol;
        this->Datum_na_ragjanje = datumRagjanje;
        this->Datum_na_donesuvawe_vo_zoo = datumDonesuvanje;
        this->Datum_na_posledna_vakcinacija = datumPoslednaVakcinacija;
    }
    virtual const char* getTypeString() const = 0;
    const char* getGenderString() const {
        if (this->Pol == 'm') { return "maski"; }
        if (this->Pol == 'z') { return "zenski"; }
        else { throw runtime_error("Nevaliden pol"); }
    }
    void Prikazi_Podatoci() {
        cout << "===" << Ime << "===" << endl;
        cout << "\t" << "Pol: " << getGenderString() << endl;
        cout << "\t" << "Datum na ragjanje: " << Datum_na_ragjanje << endl;
        cout << "\t" << "Datum na donesuvanje vo zoo: " << Datum_na_donesuvawe_vo_zoo << endl;
        cout << "\t" << "Datum na posledna vakcinacija: " << Datum_na_posledna_vakcinacija << endl;
    }
    virtual bool Presmetaj_vakcinacija() = 0;
};

class Vlekaci : public Zivotno {
private:
    Date Datum_na_sledna_vakcinacija;
public:
    Vlekaci(const char* ime, const char pol,
            const Date datumRagjanje,
            const Date datumDonesuvanje,
            const Date datumPoslednaVakcinacija,
            const Date datumSlednaVakcinacija
            ) : Zivotno(ime, pol, datumRagjanje, datumDonesuvanje, datumPoslednaVakcinacija) {
        this->Datum_na_sledna_vakcinacija = datumSlednaVakcinacija;
    }
    const char* getTypeString() const { return "vlekac"; }
    bool Presmetaj_vakcinacija() {
        Date now = Date::now();
        int days = Datum_na_sledna_vakcinacija - now;
        const int week = 7;
        return days <= week;
    }
};

class Ptici : public Zivotno {
private:
    bool letac;     //  (d/n)
public:
    Ptici(const char* ime, const char pol,
            const Date datumRagjanje,
            const Date datumDonesuvanje,
            const Date datumPoslednaVakcinacija,
            const char letac
            ) : Zivotno(ime, pol, datumRagjanje, datumDonesuvanje, datumPoslednaVakcinacija) {
        this->letac = letac == 'd';
    }
    const char getLetac() const { return letac?'d':'n'; }
    const char* getTypeString() const { return "ptica"; }
    bool Presmetaj_vakcinacija() {
        Date now = Date::now();
        int days = Datum_na_posledna_vakcinacija.toDays() + 6*180 - now.toDays();
        const int week = 7;
        return days <= week;
    }
};

class Cicaci : public Zivotno {
private:
    bool prezivar;      // (d/n)
public:
    Cicaci(const char* ime, const char pol,
          const Date datumRagjanje,
          const Date datumDonesuvanje,
          const Date datumPoslednaVakcinacija,
          const char prezivar
          ) : Zivotno(ime, pol, datumRagjanje, datumDonesuvanje, datumPoslednaVakcinacija) {
        this->prezivar = prezivar == 'd';
    }
    const char getPrezivar() const { return prezivar?'d':'n'; }
    const char* getTypeString() const { return "cicac"; }
    bool Presmetaj_vakcinacija() {
        Date now = Date::now();
        int days = Datum_na_posledna_vakcinacija.toDays() + 365 - now.toDays();
        const int week = 7;
        return days <= week;
    }
};

class Zoo {
private:
    int n;  //  number of animals in the zoo
    Zivotno **animals;
public:
    Zoo(){
        this->n=0;
    }
    void addAnimal(Zivotno& animal) {
        if (n==0) {
            animals = new Zivotno*[n+1];
            animals[n] = &animal;
            n++;
            return;
        }
        Zivotno** temp = animals;
        animals = new Zivotno*[n+1];
        for (int i=0; i<n+1; i++) {
            animals[i] = temp[i];
        }
        animals[n] = &animal;
        n++;
    }
    int countAnimals(){
        return this->n;
    }
    void printAllAnimals(){
        for (int i=0; i<n; i++) {
            animals[i]->Prikazi_Podatoci();
        }
    }
    void printVlekaci() {
        for (int i=0; i<n; i++) {
            if (typeid((*animals[i])) == typeid(Vlekaci)) { animals[i]->Prikazi_Podatoci(); }
        }
    }
    void printPtici() {
        for (int i=0; i<n; i++) {
            if (typeid((*animals[i])) == typeid(Ptici)) { animals[i]->Prikazi_Podatoci(); }
        }
    }
    void printCicaci() {
        for (int i=0; i<n; i++) {
            if (typeid((*animals[i])) == typeid(Cicaci)) { animals[i]->Prikazi_Podatoci(); }
        }
    }
    void printAnimalsToBeVaccinated() {
        for (int i=0; i<n; i++) {
            if (animals[i]->Presmetaj_vakcinacija()) {
                animals[i]->Prikazi_Podatoci();
            }
        }
    }
};

void add(Zoo& zoo) {
    Date Datum_na_ragjanje;
    Date Datum_na_donesuvawe_vo_zoo;
    char tip;   //  (c/v/p) - cicac/vlekac/ptica
    char pol;   // (m/z)
    char ime[32];
    Date Datum_na_posledna_vakcinacija;
    cout << "Vnesi ime: "; cin >> ime;
    cout << "Vnesi pol (m/z): "; cin >> pol;
    int month, day, year;
    cout << "Vnesi datum na ragjanje (mm/dd/yyyy): "; scanf_s("%d/%d/%d", &month, &day, &year);
    Datum_na_ragjanje = Date(day, month, year);
    cout << "Vnesi datum na donesuvanje vo zoo (mm/dd/yyyy): "; scanf_s("%d/%d/%d", &month, &day, &year);
    Datum_na_donesuvawe_vo_zoo = Date(day, month, year);
    cout << "Vnesi datum na posledna vakcinacija (mm/dd/yyyy): "; scanf_s("%d/%d/%d", &month, &day, &year);
    Datum_na_posledna_vakcinacija = Date(day, month, year);
    cout << "Vnesi tip (v/p/c): "; cin >> tip;
    if (tip == 'v') {
        cout << "Vnesi datum na sledna vakcinacija (mm/dd/yyyy): "; scanf_s("%d/%d/%d", &month, &day, &year);
        Date Datum_na_sledna_vakcinacija = Date(day, month, year);
        Vlekaci animal = Vlekaci(ime, pol, Datum_na_ragjanje, Datum_na_donesuvawe_vo_zoo, Datum_na_posledna_vakcinacija, Datum_na_sledna_vakcinacija);
        zoo.addAnimal(animal);
    }
    else if (tip == 'p') {
        char letac;
        cout << "Dali pticata e letac (d/n): "; cin >> letac;
        Ptici animal = Ptici(ime, pol, Datum_na_ragjanje, Datum_na_donesuvawe_vo_zoo, Datum_na_posledna_vakcinacija, letac);
        zoo.addAnimal(animal);
    }
    else if (tip == 'c') {
        char prezivar;
        cout << "Dali cicacot e prezivar (d/n): "; cin >> prezivar;
        Cicaci animal = Cicaci(ime, pol, Datum_na_ragjanje, Datum_na_donesuvawe_vo_zoo, Datum_na_posledna_vakcinacija, prezivar);
        zoo.addAnimal(animal);
    }
    else { cout << "Pogresen tip" << endl; }
}
void count(Zoo& zoo) {
    cout << "Ima " << zoo.countAnimals() << " zivotni vo zoo." <<endl;
}
void printAll(Zoo& zoo) {
    zoo.printAllAnimals();
}
void printType(Zoo& zoo) {
    char tip;
    cout << "Vnesi tip na zivotno (c/v/p): "; cin >> tip;
    if (tip == 'v') { zoo.printVlekaci(); }
    else if (tip == 'p') { zoo.printPtici(); }
    else if (tip == 'c') { zoo.printCicaci(); }
    else { cout << "Pogresen tip" << endl; }
}
void printVaccination(Zoo& zoo) {
    zoo.printAnimalsToBeVaccinated();
}
void selector(Zoo& zoo, int choice) {
    void (*options[5]) (Zoo& zoo) = {add, count, printType, printAll, printVaccination};
    options[choice](zoo);
}
void menu() {
    cout << "Izberi opcija: " << endl;
    cout << "1 Dodadi zivotno vo zoo" << endl;
    cout << "2 Izbroj gi zivotnite vo zoo" << endl;
    cout << "3 Prikazi gi zivotnite od ist tip" << endl;
    cout << "4 Prikazi gi site zivotni vo zoo" << endl;
    cout << "5 Prikazi gi zivotnite koi treba da se vakciniraat za edna nedela" << endl;
    cout << "6 Izlez" << endl;
}

int main()
{
    Zoo zoo = Zoo();
    int choice;
    do {
        menu();
        cin >> choice;
        selector(zoo, choice-1);
    } while (choice != 6);

    cout << "" << endl;
    return 0;
}
