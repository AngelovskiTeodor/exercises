#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>
#include <cstring>

using namespace std;

int main()
{
    char in[16];
    cout << "Enter the first word: "; cin >> in;
    char* temp = in;
    vector<char> first(temp, temp+strlen(in));

    cout << "enter the second word: " << endl; cin >> in;
    temp = in;
    vector<char> second(temp, temp+strlen(in));

    cout << "The words " <<
        (equal(first.begin(), first.end(), second.begin()) ? "are":"aren't")
    << " anagrams." << endl;
    return 0;
}
