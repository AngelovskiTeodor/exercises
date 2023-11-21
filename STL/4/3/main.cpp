#include <iostream>
#include <cstring>
#include <algorithm>
#include <set>

using namespace std;

int main()
{
    set<string> words;
    cout << "Enter text (-1 to exit): " << endl;
    string word;
    cin >> word;
    while (word != "-1") {
        words.insert(word);
        cin >> word;
    }
    vector<string> sorted(words.begin(), words.end());
    sort( sorted.begin(), sorted.end() );
    for (string w : sorted) {
        cout << w << endl;
    };

    return 0;
}
