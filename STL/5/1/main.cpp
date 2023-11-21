#include <iostream>
#include <cstring>
#include <algorithm>
#include <deque>
#include <vector>

using namespace std;

vector<char> strToVector(string str) {
    vector<char> ret(str.begin(), str.end());
    ret.push_back('\0');
    return ret;
}

template <class T>
bool palindrom(vector<T> word) {
    deque<T> letters(word.begin(), word.end());
    T front, back;
    while (letters.size() > 1) {
        front = letters.front();
        back = letters.back();
        if (back == '\0') {
            letters.pop_back();
            continue;
        }
        if ( front != back ) { return false; }
        letters.pop_front();
        letters.pop_back();
    }
    return true;
}

int main()
{
    cout << "Enter a word: "; string str; cin >> str;
    cout << "The word " << str << " " <<
        ( palindrom(strToVector(str))? "is":"isn't" )
        << " a palindrome" << endl;
    return 0;
}
