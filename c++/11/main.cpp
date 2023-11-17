#include <iostream>
#include <cstring>

using namespace std;

class Date {
public:
    Date( int dy = 1, int mn = 1, int yr = 2007 ) {
        if ( mn > 0 && mn <= 12 ) { month = mn; }
        else { month = 1; }
        year = yr;
        day = checkDay( dy );
    }

    void print() const { cout << month << '/' << day << '/' << year; }

    ~Date(){}

    int getDay() const { return day; }

    int getMonth() const { return month; }

    int getYear() const { return year; }

    friend int operator -(Date const& date1, Date const& date2){
        int days1 = date1.day + date1.month*daysPerMonth[date1.month] + date1.year*365;
        int days2 = date2.day + date2.month*daysPerMonth[date2.month] + date2.year*365;
        return days1 - days2;
    }

    friend ostream& operator <<(ostream& os, Date const& date) {
        os << date.getDay() << '/' << date.getMonth() << '/' << date.getYear();
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

class Artikl {
private:
    char ime_na_artikl[16];
    int golemina;
    float cena;
    Date donesen_vo_prodavnica;
public:
    static int brArtikli;
    Artikl(){}
    Artikl(const char* name, const int size, const float price, const int den, const int mesec, const int godina) {
        strncpy(this->ime_na_artikl, name, sizeof(this->ime_na_artikl) - 1);
        golemina = size;
        cena = price;
        donesen_vo_prodavnica = Date(den, mesec, godina);
        ++brArtikli;
    }
    ~Artikl(){
        --brArtikli;
    }
    const char* getName () const { return ime_na_artikl; }
    const int getSize () const { return golemina; }
    const float getPrice () const { return cena; }
    const Date& getLastProcurementDate() const { return donesen_vo_prodavnica; }
    void setName( const char name[16] ) { strncpy(this->ime_na_artikl, name, sizeof(this->ime_na_artikl) - 1); }
    void setSize( const int size ) { golemina = size; }
    void setPrice( const float price ) { cena = price; }
    void setLastProcurementDate( const int day, const int month, const int year) { donesen_vo_prodavnica = Date(day, month, year); }
    friend ostream& operator <<(ostream& os, const Artikl& product) {
        os << product.getLastProcurementDate() << ": " << product.getSize() << " x " << product.getName() << " * " << product.getPrice() << "$";
        return os;
    }
    void prikazi_podatoci(){
        cout << (*this) << endl;
    }
    bool presmetaj_nabavka() {
        return 0;
    }
};
int Artikl::brArtikli = 0;

class Pantaloni : public Artikl {
private:
    Date datum_na_sledna_nabavka;
public:
    Pantaloni(const char* name, const int size, const float price,
              const int denDoneseni, const int mesecDoneseni, const int godinaDoneseni,
              const int denNabavka, const int mesecNabavka, const int godinaNabavka
    ) {
        setName(name);
        setSize(size);
        setPrice(price);
        setLastProcurementDate(denDoneseni, mesecDoneseni, godinaDoneseni);
        datum_na_sledna_nabavka = Date(denNabavka, mesecNabavka, godinaNabavka);
    }
    const Date& getNextProcurementDate() const { return datum_na_sledna_nabavka; }
    void setNextProcurementDate( const int day, const int month, const int year) { datum_na_sledna_nabavka = Date(day, month, year); }
    friend ostream& operator <<(ostream& os, const Pantaloni& product) {
        os << product.getLastProcurementDate() << ": " << product.getSize() << " x " << product.getName() << " * " << product.getPrice() << "$ (Next procurement: " << product.getNextProcurementDate() << ")";
        return os;
    }
    void prikazi_podatoci(){
        cout << (*this) << endl;
    }
    bool presmetaj_nabavka() {
        int daysToProcurement = getNextProcurementDate() - getLastProcurementDate();
        return daysToProcurement <= 7;
    }
};

class Kosuli : public Artikl {
public:
    Kosuli(const char* name, const int size, const float price, const int den, const int mesec, const int godina){
        setName(name);
        setSize(size);
        setPrice(price);
        setLastProcurementDate(den, mesec, godina);
    }
    friend ostream& operator <<(ostream& os, const Kosuli& product) {
        os << product.getLastProcurementDate() << ": " << product.getSize() << " x " << product.getName() << " * " << product.getPrice() << "$";
        return os;
    }
    void prikazi_podatoci(){
        cout << (*this) << endl;
    }
    bool presmetaj_nabavka() {
        int nextMonth = ((getLastProcurementDate().getMonth() + 1) % 12);
        if (nextMonth == 0) { nextMonth = 12; }
        int nextYear = getLastProcurementDate().getYear();
        if ((getLastProcurementDate().getMonth() + 1)>12) { ++nextYear; }
        Date nextProcurementDate = Date(
            getLastProcurementDate().getDay(),
            nextMonth,
            nextYear
        );
        int daysToProcurement =  nextProcurementDate - getLastProcurementDate();
        return daysToProcurement <= 7;
    }
};

class Shop {
private:
    Artikl* products;
    int size;
public:
    Shop(){
        size = 0;
    }
    ~Shop(){
        size = 0;
        delete [] products;
        free(products);
    }
    const int getSize() const {
        return size;
    }
    void addProduct(Artikl& product) {
        if (getSize() == 0) {
            products = new Artikl[size+1];
            products[size] = product;
            size++;
            return;
        }
        Artikl* temp = products;
        products = new Artikl[size+1];
        for (int i=0; i<size; i++) {
            products[i] = temp[i];
        }
        products[size] = product;
        size++;
    }
    friend ostream& operator <<(ostream& os, const Shop& shop) {
        for (int i=0; i<shop.getSize(); i++) {
            os << shop.products[i] << endl;
        }
        return os;
    }
    void printTrousers(){
        for (int i=0; i<size; i++) {
            if ( typeid(products[i]) == typeid(Pantaloni) ) { cout << products[i] << endl; }
        }
    }
    void printKosuli(){
        for (int i=0; i<size; i++) {
            if ( typeid(products[i]) == typeid(Kosuli) ) { cout << products[i] << endl; }
        }
    }
    void printNextProcurements(){
        for (int i=0; i<size; i++) {
            if ( products[i].presmetaj_nabavka() ) { cout << products[i] << endl; }
        }
    }
};

void addTrousers(Shop& shop) {
    char name[16];
    int size;
    float price;
    int denDoneseni;
    int mesecDoneseni;
    int godinaDoneseni;
    int denNabavka;
    int mesecNabavka;
    int godinaNabavka;
    cout << "Name: "; cin >> name;
    cout << "Size: "; cin >> size;
    cout << "Price: "; cin >> price;
    cout << "Day of last procurement: "; cin >> denDoneseni;
    cout << "Month of last procurement: "; cin >> mesecDoneseni;
    cout << "Year of last procurement: "; cin >> godinaDoneseni;
    cout << "Day of next procurement: "; cin >> denNabavka;
    cout << "Month of next procurement: "; cin >> mesecNabavka;
    cout << "Year of next procurement: "; cin >> godinaNabavka;
    Pantaloni p = Pantaloni(name, size, price, denDoneseni, mesecDoneseni, godinaDoneseni, denNabavka, mesecNabavka, godinaNabavka);
    shop.addProduct(p);
}

void addShirt(Shop& shop) {
    char name[16];
    int size;
    float price;
    int denDoneseni;
    int mesecDoneseni;
    int godinaDoneseni;
    cout << "Name: "; cin >> name;
    cout << "Size: "; cin >> size;
    cout << "Price: "; cin >> price;
    cout << "Day of last procurement: "; cin >> denDoneseni;
    cout << "Month of last procurement: "; cin >> mesecDoneseni;
    cout << "Year of last procurement: "; cin >> godinaDoneseni;
    Kosuli p = Kosuli(name, size, price, denDoneseni, mesecDoneseni, godinaDoneseni);
    shop.addProduct(p);
}

void listTrousers(Shop& shop) {
    shop.printTrousers();
}

void listShirts(Shop& shop) {
    shop.printKosuli();
}

void listAll(Shop& shop){
    cout << shop;
}

void listProcurements(Shop& shop){
    shop.printNextProcurements();
}

void selector(Shop& shop, int choice) {
    void (*options[7]) (Shop& shop) = {addTrousers, addShirt, listTrousers, listShirts, listAll, listProcurements};
    options[choice](shop);
}

void menu(){
    cout << "1. Add new trousers: " << endl;
    cout << "2. Add new shirt: " << endl;
    cout << "3. List all trousers: " << endl;
    cout << "4. List all shirts: " << endl;
    cout << "5. List all products" << endl;
    cout << "6. List expected procurements" << endl;
    cout << "7. Izlez" << endl;
}

int main()
{
    Shop shop = Shop();
    int choice;
    do {
        menu();
        cin >> choice;
        selector(shop, choice-1);
    } while (choice != 7);
    cout << "" << endl;
    return 0;
}
