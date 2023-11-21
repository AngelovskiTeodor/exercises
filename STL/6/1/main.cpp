#include <iostream>
#include <map>
#include <cstring>

using namespace std;

class Uplata {
private:
    string name;
    float amount;
public:
    Uplata(string _name = "", float _amount = 0.0){
        setName(_name);
        setAmount(_amount);
    }
    const string getName() const { return name; }
    const float getAmount() const { return amount; }
    void setName(string _name) { name = _name; }
    void setAmount(float _amount) { amount = _amount; }
    friend ostream& operator<<(ostream& os, const Uplata& uplata) {
        os << uplata.getName() << ": " << uplata.getAmount() << "$";
        return os;
    }
};

void selector(multimap<string, Uplata>& transfers, const int choice) {
    string name;
    float amount;
    switch (choice) {
    case 0: {
        cout << "Enter name: "; cin >> name;
        cout << "Enter amount: "; cin >> amount;
        Uplata uplata = Uplata(name, amount);
        pair<string, Uplata> entry = pair<string, Uplata>(name, uplata);
        transfers.insert(entry);
        break;}
    case 1:{
        cout << "Enter name: "; cin >> name;
        pair<
            multimap<string, Uplata>::iterator,
            multimap<string, Uplata>::iterator
        > results = transfers.equal_range(name);
        multimap<string, Uplata>::iterator it;
        for (it = results.first; it != results.second; ++it) {
            cout << it->second << endl;
        }
        break;}
    default:{ break; }
    }
}

void menu() {
    cout << "1.  Add new transfer" << endl;
    cout << "2.  List transfers per person" << endl;
    cout << "3.  Exit" << endl;
}

int main()
{
    int choice;
    multimap<string, Uplata> transfers;
    do {
        menu();
        cin >> choice;
        selector(transfers, choice-1);
    } while (choice != 3);
    cout << "" << endl;
    return 0;
}
