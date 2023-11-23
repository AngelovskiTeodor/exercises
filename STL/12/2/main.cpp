#include <iostream>
#include <algorithm>
#include <vector>
#include <iomanip>
#include <fstream>
#include <numeric>

using namespace std;

class Inventar {
private:
    int id;
    int kolicestvo;
    double cena;
public:
    Inventar(const int _id = 0, const int amount = 0, const double price = 0) {
        setId(_id);
        setKolicestvo(amount);
        setCena(price);
    }
    void setId(int _id) { id = _id; }
    int getId() const { return id; }
    void setKolicestvo(int _kolicestvo) { kolicestvo = _kolicestvo; }
    int getKolicestvo() const { return kolicestvo; }
    void setCena(double _cena) { cena = _cena; }
    double getCena() const { return cena; }
    friend ostream& operator<<(ostream& os, const Inventar& product) {
        os << "Product " << product.getId() << ": " << product.getKolicestvo() << " x " << product.getCena();
        return os;
    }
};

double operator+ (double d, const Inventar& product) {
    return d + (product.getKolicestvo() * product.getCena());
}

void addProducts() {
    ofstream writeToFile ( "inventar.txt", ios::out );

    if ( !writeToFile ) {
        throw runtime_error("Can not open file");
    }

    int id, amount; double price;
    cout << "Enter id, amount and price: ";
    while (cin >> id >> amount >> price) {
        writeToFile << id << " " << amount << " " << price << endl;
        cout << "Enter id, amount and price: ";
    }

    writeToFile.close();
}

vector<Inventar> readProducts() {
    vector<Inventar> ret;

    ifstream readFromFile ( "inventar.txt", ios::in );
    int id, amount; double price;
    while ( readFromFile >> id >> amount >> price ) {
        ret.push_back( Inventar(id,amount,price) );
    }

    readFromFile.close();
    return ret;
}

template <int N>
bool lessThanInStock(Inventar product) {
    return product.getKolicestvo() < N;
}

int main()
{
    addProducts();
    vector<Inventar> products = readProducts();
    vector<Inventar> lowOnStock(products.size());
    remove_copy_if(products.begin(), products.end(), lowOnStock.begin(), lessThanInStock<10>);
    for (Inventar& prod : lowOnStock) {
        cout << prod << endl;;
    }
    double total = 0;
    cout << "The total cost of the products is " << accumulate(products.begin(), products.end(), total) << endl;
    return 0;
}
