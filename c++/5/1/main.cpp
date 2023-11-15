#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

class Date {
public:
    Date( int dy = 1, int mn = 1, int yr = 2007 )
    {
        if ( mn > 0 && mn <= 12 )
            month = mn;
        else {
            month = 1;
            //cout << "Mesec " << mn << " ne postoi. Postavi go month na 1.\n";
        }

        year = yr;
        day = checkDay( dy );

        //print();
        //cout << endl;
    }

    void print() const { cout << month << '/' << day << '/' << year; }

    ~Date(){
        //print();
        //cout << endl;
    }

    int getDay() const { return day; }

    int getMonth() const { return month; }

    int getYear() const { return year; }

    friend int substractDatesWithResultInDays(Date const& date1, Date const& date2){
        int days1 = date1.day + date1.month*daysPerMonth[date1.month] + date1.year*365;
        int days2 = date2.day + date2.month*daysPerMonth[date2.month] + date2.year*365;
        return days1 - days2;
    }

    friend ostream& operator <<(ostream& os, Date const& date) {
        os << date.getMonth() << '/' << date.getDay() << '/' << date.getYear();
        return os;
    }

private:
    int month;
    int day;
    int year;

    static const int daysPerMonth[ 13 ];

    int checkDay( int testDay ){
        if ( testDay > 0 && testDay <= daysPerMonth[ month ] )
            return testDay;

        if ( month == 2 &&
            testDay == 29 &&
            ( year % 400 == 0 ||
             ( year % 4 == 0 && year % 100 != 0 ) ) )
            return testDay;

        //cout << "Denot " << testDay << " e greshen. Postavi vrednost za day na 1.\n";

        return 1;
    }
};

const int Date::daysPerMonth[ 13 ] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

class Zivotno {
private:
    Date Datum_na_ragjanje;
    Date Datum_na_donesuvawe_vo_zoo;
    char tip;   //  (c/v/p) - cicac/vlekac/ptica
    char Pol;   // (m/z)
    char Ime[32];
    Date Datum_na_posledna_vakcinacija;
public:
    Zivotno(){
        strncpy(this->Ime, "N/A", sizeof(this->Ime) - 1);
        this->tip = '\0';
        this->Pol = '\0';
        this->Datum_na_ragjanje = NULL;
        this->Datum_na_donesuvawe_vo_zoo = NULL;
        this->Datum_na_posledna_vakcinacija = NULL;
    }
    Zivotno(const char* ime, const char tip, const char pol,
            const Date datumRagjanje,
            const Date datumDonesuvanje,
            const Date datumVakcinacija
    ){
        strncpy(this->Ime, ime, sizeof(this->Ime) - 1);
        this->tip = tip;
        this->Pol = pol;
        this->Datum_na_ragjanje = datumRagjanje;
        this->Datum_na_donesuvawe_vo_zoo = datumDonesuvanje;
        this->Datum_na_posledna_vakcinacija = datumVakcinacija;
    }
    char getType() const {
        return tip;
    }
    char* getTypeString() const {
        if (this->getType() == 'c') { return "cicac"; }
        if (this->getType() == 'v') { return "vlekac"; }
        if (this->getType() == 'p') { return "ptica"; }
    }
    char* getGenderString() {
        if (this->Pol == 'm') { return "maski"; }
        if (this->Pol == 'z') { return "zenski"; }
    }
    void Prikazi_Podatoci() {
        cout << "===" << getTypeString() << " " << Ime << "===" << endl;
        cout << "\t" << "Pol: " << getGenderString() << endl;
        cout << "\t" << "Datum na ragjanje: " << Datum_na_ragjanje << endl;
        cout << "\t" << "Datum na donesuvanje vo zoo: " << Datum_na_donesuvawe_vo_zoo << endl;
        cout << "\t" << "Datum na posledna vakcinacija: " << Datum_na_posledna_vakcinacija << endl;
    }
    bool Presmetaj_vakcinacija() {
        int daysSinceLastVaccination = substractDatesWithResultInDays(Date(9,1,2003), this->Datum_na_posledna_vakcinacija);
        int intervalBetweenVaccination = 365;
        if (this->getType() == 'c') { intervalBetweenVaccination = 365; }
        if (this->getType() == 'v') { intervalBetweenVaccination = 8*30; }
        if (this->getType() == 'p') { intervalBetweenVaccination = 6*30; }
        if (daysSinceLastVaccination > intervalBetweenVaccination-7) {
            return true;
        }
        return false;
    }
};

class Zoo {
private:
    int n;  //  number of animals in the zoo
    Zivotno animals[20];
public:
    Zoo(){
        this->n=0;
    }
    void addAnimal(Zivotno animal) {
        animals[n]=animal;
        n++;
    }
    int countAnimals(){
        return this->n;
    }
    void printAllAnimals(){
        for (int i=0; i<n; i++) {
            animals[i].Prikazi_Podatoci();
        }
    }
    void printAnimalsFromType(char type) {
        for (int i=0; i<n; i++) {
            if (animals[i].getType() == type) { animals[i].Prikazi_Podatoci(); }
        }
    }
    void printAnimalsToBeVaccinated(Date now) {
        for (int i=0; i<n; i++) {
            if (animals[i].Presmetaj_vakcinacija()) {
                animals[i].Prikazi_Podatoci();
            }
        }
    }
};

void menu() {
    cout << "Izberi opcija: " << endl;
    cout << "1 Dodadi zivotno vo zoo" << endl;
    cout << "2 Izbroj gi zivotnite vo zoo" << endl;
    cout << "3 Prikazi gi zivotnite od ist tip" << endl;
    cout << "4 Prikazi gi site zivotni vo zoo" << endl;
    cout << "5 Prikazi gi zivotnite koi treba da se vakciniraat za edna nedela" << endl;
    cout << "6 Izlez" << endl;
}

void add(Zoo& zoo) {
    Date Datum_na_ragjanje;
    Date Datum_na_donesuvawe_vo_zoo;
    char tip;   //  (c/v/p) - cicac/vlekac/ptica
    char pol;   // (m/z)
    char ime[32];
    Date Datum_na_posledna_vakcinacija;
    cout << "Vnesi ime: "; cin >> ime;
    cout << "Vnesi tip: "; cin >> tip;
    cout << "Vnesi pol: "; cin >> pol;
    int month, day, year;
    cout << "Vnesi datum na ragjanje (mm/dd/yyyy): "; scanf_s("%d/%d/%d", &month, &day, &year);
    Datum_na_ragjanje = Date(day, month, year);
    cout << "Vnesi datum na donesuvanje vo zoo (mm/dd/yyyy): "; scanf_s("%d/%d/%d", &month, &day, &year);
    Datum_na_donesuvawe_vo_zoo = Date(day, month, year);
    cout << "Vnesi datum na posledna vakcinacija (mm/dd/yyyy): "; scanf_s("%d/%d/%d", &month, &day, &year);
    Datum_na_posledna_vakcinacija = Date(day, month, year);
    Zivotno animal = Zivotno(ime, tip, pol, Datum_na_ragjanje, Datum_na_donesuvawe_vo_zoo, Datum_na_posledna_vakcinacija);
    zoo.addAnimal(animal);
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
    zoo.printAnimalsFromType(tip);
}

void printVaccination(Zoo& zoo) {
    zoo.printAnimalsToBeVaccinated(Date(9,1,2023));
}

void selector(Zoo& zoo, int choice) {
    void (*options[5]) (Zoo& zoo) = {add, count, printType, printAll, printVaccination};
    options[choice](zoo);
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
