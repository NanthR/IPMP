#include<iostream>
#include<stack>

using namespace std;

class MyStack {
    stack<int> s;
    int minEle;

public:
    void getMin() {
        if (s.empty())
            cout << "Stack is empty\n";
        else
            cout << minEle << "\n";
    }

    void peek() {
        if (s.empty()) {
            cout << "Stack is empty\n";
            return;
        }

        int t = s.top();

        (t < minEle)? cout << minEle: cout << t;
    }

    void pop() {
        if (s.empty()) {
            cout << "Stack is empty\n";
            return;
        }

        int t = s.top();
        s.pop();

        if (t < minEle) {
            cout << minEle << "\n";
            minEle = 2*minEle - t;
        }

        else
            cout << t << "\n";
    }

    void push(int x) {
        if (s.empty()) {
            minEle = x;
            s.push(x);
            cout << "Number Inserted: " << x << "\n";
            return;
        }

        if (x < minEle) {
            s.push(2*x - minEle);
            minEle = x;
        }

        else
           s.push(x);

        cout << "Number Inserted: " << x << "\n";
    }
};

int main() {
    MyStack s;
    s.push(3);
    s.getMin();
    s.push(2);
    s.getMin();
    s.pop();
    s.getMin();
    s.peek();
}
