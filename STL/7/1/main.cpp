#include <iostream>
#include <cstdlib>
#include <vector>
#include <cstddef>
#include <algorithm>

using namespace std;

bool even(int n) { return n%2==0; }
bool odd(int n) { return n%2; }
template <int VALUE>
bool lesserThan(int n) { return n<VALUE; }
template <int START, int END>
bool interval(int n) { return START<=n && n<END; }
float average(vector<int> numbers) {
    float ret = 0;
    for (int& num : numbers) {
        ret += num;
    }
    ret = ret / numbers.size();
    return ret;
}

void printPredicate(vector<int>& numbers, bool (*predicate)(int)) {
    vector<int> temp;
    remove_copy_if(numbers.begin(), numbers.end(), temp.begin(), predicate);
    for (int& num : temp) {
        cout << num << " ";
    }
    cout << endl;
}

int main()
{
    const int N = 10000;
    vector<int> rands;
    for (int i=0; i<N; i++) {
        rands.push_back( rand()%N );
    }
    printPredicate(rands, even);
    printPredicate(rands, lesserThan<2000>);
    printPredicate(rands, interval<2000, 4000>);
    printPredicate(rands, interval<4000, 6000>);
    printPredicate(rands, interval<6000, 8000>);
    printPredicate(rands, interval<8000, 10000>);
    cout << "The average is " <<  average(rands) << endl;
    return 0;
}
