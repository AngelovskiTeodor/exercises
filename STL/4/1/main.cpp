#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>

using namespace std;

class Entry {
public:
    char name[32];
    char phone[16];
    Entry(const char* _name = "", const char* _phone = ""){
        strncpy(name, _name, sizeof(_name));
        strncpy(phone, _phone, sizeof(_phone));
    }
    const char* getName() const { return name; }
    const char* getPhone() const { return phone; }
    void setName( const char* _name ) { strncpy(name, _name, sizeof(_name)); }
    void setPhone ( const char* _phone ) { strncpy(phone, _phone, sizeof(_phone)); }
    bool operator <(const Entry& entry) {
        return strcmp(this->getName(), entry.getName()) < 0;
    }
};

int main()
{
    vector<Entry> Imenik;
    int n;
    cout << "How many contact do you want to add? "; cin >> n;
    char name[32], phone[16];
    for (int i=0; i<n; i++) {
        cout << "Name: "; cin >> name;
        cout << "Phone number: "; cin >> phone;
        Imenik.push_back( Entry(name,phone) );
    }
    sort(Imenik.begin(), Imenik.end());
    for (Entry& contact : Imenik) {
        cout << contact.getName() << ": " << contact.getPhone() << endl;
    }
    cout << "" << endl;
    return 0;
}
