#include <iostream>
#include <cstring>

using namespace std;

class Vraboten {
private:
    char ime[16];
    char prezime[16];
    int godina_na_vrabotuvanje;
public:
    Vraboten() {
        strncpy(this->ime, "", 0);
        this->ime[0] = '\0';
        strncpy(this->prezime, "", 0);
        this->prezime[0] = '\0';
        godina_na_vrabotuvanje = 0;
        //++brVraboteni;
    }
    Vraboten(const char* name, const char* surname, const int yearOfEmployment) {
        strncpy(this->ime, name, sizeof(this->ime) - 1);
        this->ime[ sizeof(this->ime)-1 ] = '\0';
        strncpy(this->prezime, surname, sizeof(this->prezime) - 1);
        this->prezime[ sizeof(this->prezime)-1 ] = '\0';
        godina_na_vrabotuvanje = yearOfEmployment;
        ++brVraboteni;
    }
    const char* getName() const { return ime; }
    void setName(const char* name) {
        strncpy(this->ime, name, sizeof(this->ime) - 1);
        this->ime[ sizeof(this->ime)-1 ] = '\0';
    }
    const char* getSurame() const { return prezime; }
    void setSurname(const char* surname) {
        strncpy(this->prezime, surname, sizeof(this->prezime) - 1);
        this->prezime[ sizeof(this->prezime)-1 ] = '\0';
    }
    int getYearOfEmployment() const { return godina_na_vrabotuvanje; }
    void setYearOfEmployment(int yearOfEmployment) { godina_na_vrabotuvanje = yearOfEmployment; }
    void prikazi_podatoci(){
        cout << "Ime: " << ime << endl;
        cout << "Prezime: " << prezime << endl;
        cout << "Godina na vrabotuvanje: " << godina_na_vrabotuvanje<< endl;
    }
    static int brVraboteni;
};

class Profesor:public Vraboten {
private:
    char zvanje[16];
    char oblast[16];
    int br_predmeti;
public:
    Profesor(){
        setZvanje("");
        setOblast("");
        setBrPredmeti(0);
        //++brProfesori;
    }
    Profesor(const char* name, const char* surname, const int yearOfEmployment,
             const char* title, const char* area, const int numOfSubjects):br_predmeti(numOfSubjects)
    {
        setName(name);
        setSurname(surname);
        setYearOfEmployment(yearOfEmployment);
        setZvanje(title);
        setOblast(area);
        ++brProfesori;
    }
    void setZvanje(const char* title) {
        strncpy(zvanje, title, sizeof(zvanje) - 1);
        zvanje[sizeof(zvanje) - 1] = '\0';
    }
    const char* getZvanje() const {
        return zvanje;
    }
    void setOblast(const char* area) {
        strncpy(oblast, area, sizeof(oblast) - 1);
        oblast[sizeof(oblast) - 1] = '\0';
    }
    const char* getOblast() const {
        return oblast;
    }
    void setBrPredmeti(int value) {
        br_predmeti = value;
    }
    int getBrPredmeti() const {
        return br_predmeti;
    }
    void prikazi_podatoci(){
        Vraboten::prikazi_podatoci();
        cout << "Zvanje: " << zvanje << endl;
        cout << "Oblast: " << oblast << endl;
        cout << "Broj predmeti: " << br_predmeti << endl;
    }
    static int brProfesori;
};

class Asistent:public Vraboten {
private:
    char zvanje[16];
    char mentor[16];
    int br_predmeti;
public:
    Asistent(){
        setZvanje("");
        setMentor("");
        setBrPredmeti(0);
        //++brAsistenti;
    }
    Asistent(const char* name, const char* surname, const int yearOfEmployment,
             const char* title, const char* _mentor, const int numOfSubjects) : br_predmeti(numOfSubjects)
    {
        setName(name);
        setSurname(surname);
        setYearOfEmployment(yearOfEmployment);
        setZvanje(title);
        setMentor(_mentor);
        ++brAsistenti;
    }
    void setZvanje(const char* title) {
        strncpy(zvanje, title, sizeof(zvanje) - 1);
        zvanje[sizeof(zvanje) - 1] = '\0';
    }
    const char* getZvanje() const {
        return zvanje;
    }
    void setMentor(const char* _mentor) {
        strncpy(mentor, _mentor, sizeof(mentor) - 1);
        mentor[sizeof(mentor) - 1] = '\0';
    }
    const char* getMentor() const {
        return mentor;
    }
    void setBrPredmeti(int value) {
        br_predmeti = value;
    }
    int getBrPredmeti() const {
        return br_predmeti;
    }
    void prikazi_podatoci(){
        Vraboten::prikazi_podatoci();
        cout << "Zvanje: " << zvanje << endl;
        cout << "Mentor: " << mentor << endl;
        cout << "Broj predmeti: " << br_predmeti << endl;
    }
    static int brAsistenti;
};

class Demonstrator:public Vraboten {
private:
    int rabotno_vreme_od;
    int rabotno_vreme_do;
public:
    Demonstrator(){
        setRabotnoVremeOd(0);
        setRabotnoVremeDo(0);
        //++brDemonstratori;
    }
    Demonstrator(const char* name, const char* surname, const int yearOfEmployment, const int startWorkingHours, const int endWorkingHours)
        : rabotno_vreme_od(startWorkingHours), rabotno_vreme_do(endWorkingHours)
    {
        setName(name);
        setSurname(surname);
        Vraboten::setYearOfEmployment(yearOfEmployment);
        ++brDemonstratori;
    }
    void setRabotnoVremeOd(int value) {
        rabotno_vreme_od = value;
    }
    int getRabotnoVremeOd() const {
        return rabotno_vreme_od;
    }
    void setRabotnoVremeDo(int value) {
        rabotno_vreme_do = value;
    }
    int getRabotnoVremeDo() const {
        return rabotno_vreme_do;
    }
    void prikazi_podatoci(){
        Vraboten::prikazi_podatoci();
        cout << "Rabotno vreme od: " << rabotno_vreme_od << endl;
        cout << "Rabotno vreme do: " << rabotno_vreme_do << endl;
    }
    static int brDemonstratori;
};

int Vraboten::brVraboteni = 0;
int Profesor::brProfesori = 0;
int Asistent::brAsistenti = 0;
int Demonstrator::brDemonstratori = 0;

void addEmpl(Vraboten university[]){
    char ime[16];
    char prezime[16];
    int godina_na_vrabotuvanje;
    cout << "Ime: "; cin >> ime;
    cout << "Prezime: "; cin >> prezime;
    cout << "Godina na vrabotuvanje: "; cin >> godina_na_vrabotuvanje;
    Vraboten v = Vraboten(ime, prezime, godina_na_vrabotuvanje);
    university[Vraboten::brVraboteni] = v;
}

void addProf(Vraboten university[]){
    char ime[16];
    char prezime[16];
    int godina_na_vrabotuvanje;
    char zvanje[16];
    char oblast[16];
    int brPredmeti;
    cout << "Ime: "; cin >> ime;
    cout << "Prezime: "; cin >> prezime;
    cout << "Godina na vrabotuvanje: "; cin >> godina_na_vrabotuvanje;
    cout << "Zvanje: "; cin >> zvanje;
    cout << "Oblast: "; cin >> oblast;
    cout << "Broj na predmeti: "; cin >> brPredmeti;
    Profesor v = Profesor(ime, prezime, godina_na_vrabotuvanje, zvanje, oblast, brPredmeti);
    university[Vraboten::brVraboteni] = v;
}

void addAsist(Vraboten university[]){
    char ime[16];
    char prezime[16];
    int godina_na_vrabotuvanje;
    char zvanje[16];
    char mentor[16];
    int brPredmeti;
    cout << "Ime: "; cin >> ime;
    cout << "Prezime: "; cin >> prezime;
    cout << "Godina na vrabotuvanje: "; cin >> godina_na_vrabotuvanje;
    cout << "Zvanje: "; cin >> zvanje;
    cout << "Mentor: "; cin >> mentor;
    cout << "Broj na predmeti: "; cin >> brPredmeti;
    Asistent v = Asistent(ime, prezime, godina_na_vrabotuvanje, zvanje, mentor, brPredmeti);
    university[Vraboten::brVraboteni] = v;
}

void addDem(Vraboten university[]){
    char ime[16];
    char prezime[16];
    int godina_na_vrabotuvanje;
    int rabotnoVremeOd;
    int rabotnoVremeDo;
    cout << "Ime: "; cin >> ime;
    cout << "Prezime: "; cin >> prezime;
    cout << "Godina na vrabotuvanje: "; cin >> godina_na_vrabotuvanje;
    cout << "Rabotno vreme od: "; cin >> rabotnoVremeOd;
    cout << "Rabotno vreme do: "; cin >> rabotnoVremeDo;
    Demonstrator v = Demonstrator(ime, prezime, godina_na_vrabotuvanje, rabotnoVremeOd, rabotnoVremeDo);
    university[Vraboten::brVraboteni] = v;
}

void print(Vraboten university[]){
    for (int i=0; i<Vraboten::brVraboteni; i++) {
        university[i].prikazi_podatoci();
    }
}

void selector(Vraboten university[], int choice) {
    void (*options[5]) (Vraboten university[]) = {addEmpl, addProf, addAsist, addDem, print};
    options[choice](university);
}

void menu(){
    cout << "1. Dodadi nov vraboten: " << endl;
    cout << "2. Dodadi nov profesor: " << endl;
    cout << "3. Dodadi nov asistent: " << endl;
    cout << "4. Dodadi nov demonstrator: " << endl;
    cout << "5. Prikazi gi vrabotenite" << endl;
    cout << "6. Izlez" << endl;
}

int main()
{
    Vraboten university[10];
    int choice;
    do {
        menu();
        cin >> choice;
        selector(university, choice-1);
    } while (choice != 6);

    cout << "" << endl;
    return 0;
}
