#include <iostream>
#include <queue>

using namespace std;

class Process {
private:
    int id;
    int priority;
public:
    Process(int id = 0, int priority = 0) {
        this->id = id;
        this->priority = priority;
    }
    int getId() const {
        return id;
    }
    void setId(int id) {
        this->id = id;
    }
    int getPriority() const {
        return priority;
    }
    void setPriority(int priority) {
        this->priority = priority;
    }
    friend bool operator<(const Process& p1, const Process& p2) {
        return p1.getPriority() < p2.getPriority();
    }
    friend ostream& operator <<(ostream& os, const Process& process) {
        os << "Process " << process.getId() << " has priority of " << process.getPriority() << endl;
        return os;
    }
    static const Process read(){
        int id, priority;
        cout << "ID: "; cin >> id;
        cout << "Priority: "; cin >> priority;
        return Process(id, priority);
    }
};

int main()
{
    priority_queue<Process> order;
    cout << "How many processes are there? "; int n; cin >> n;
    for (int i=0; i<n; i++) {
        order.push( Process::read() );
    }
    while (!order.empty()) {
        cout << order.top();
        order.pop();
    }
    cout << "" << endl;
    return 0;
}
