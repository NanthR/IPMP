#include<iostream>
#include<list>
#include<unordered_map>

using namespace std;

class LRUCache {
    list<int> dq;
    unordered_map<int, list<int>::iterator> ma;
    int size;

public:
    LRUCache(int n) {
        size = n;
    }

    void refer(int x) {
        if (ma.find(x) == ma.end()) {
            if (dq.size() == size) {
                int last = dq.back();
                dq.pop_back();
                ma.erase(last);
            }
        }

        else
            dq.erase(ma[x]);

        dq.push_front(x);
        ma[x] = dq.begin();
    }

    void display() {
        for (auto it = dq.begin(); it != dq.end(); it++)
            cout << (*it) << " ";
        cout << "\n";
    }
};



int main() {
    LRUCache ca(4);

    ca.refer(1);
    ca.refer(2);
    ca.refer(3);
    ca.refer(1);
    ca.refer(4);
    ca.refer(5);
    ca.display();
}
