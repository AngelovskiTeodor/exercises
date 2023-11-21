#include <iostream>
#include <vector>
#include <cstring>
#include <set>
#include <algorithm>

using namespace std;

vector<string> readEmails() {
    int n; cout << "How many emails will you enter in this list? "; cin >> n;
    vector<string> ret;
    string email;
    for (int i=0; i<n; i++) {
        cout << "Enter an email address: "; cin >> email;
        ret.push_back(email);
    }
    return ret;
}

template <class T>
void printSet (set<T> &_set) {
    vector<T> temp(_set.begin(), _set.end());
    for (T& elem : temp) {
        cout << elem << endl;
    }
}

int main()
{
    vector<string> first= readEmails();
    vector<string> second= readEmails();
    vector<string> third= readEmails();

    set<string> uniques(first.begin(), first.end());
    for (string& str : second) {
        uniques.insert(str);
    }
    for (string& str : third) {
        uniques.insert(str);
    }

    cout << "The unique emails are:" << endl;
    printSet<string>(uniques);
    return 0;
}
