#include <iostream>
#include <vector>
#include <deque>

using namespace std;

template <class T>
deque<T> readDeque() {
    int n; cout << "How many elements will you enter in this queue? "; cin >> n;
    deque<T> ret;
    T elem;
    for (int i=0; i<n; i++) {
        cout << "Enter an element: "; cin >> elem;
        ret.push_front(elem);
    }
    return ret;
}

template <class T>
vector<T> reverseDeque(deque<T>& queue) {
    vector<T> ret(queue.begin(), queue.end());
    return ret;
}

template <class T>
void printVector (vector<T> &_vector) {
    for (T& elem : _vector) {
        cout << elem << " ";
    }
    cout << endl;
}

int main()
{
    deque<int> queue = readDeque<int>();
    cout << "The elements in reverse order are: " << endl;
    vector<int> reversed = reverseDeque<int>(queue);
    printVector<int>( reversed );
    return 0;
}
