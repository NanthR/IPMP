#include<stack>
#include<iostream>

using namespace std;

bool check_parans(string x) {
    stack<char> s;
    char y;
    for(auto i: x) {
        if(i == '(' || i == '{' || i == '[') {
           s.push(i);
           continue;
        }

        if(s.empty())
            return false;

        switch(i) {
            case ')':
                y = s.top();
                s.pop();
                if(y == '{' || y == '[')
                    return false;
                break;
            case '}':
                y = s.top();
                s.pop();
                if(y == '(' || y == '[')
                    return false;
                break;
            case ']':
                y = s.top();
                s.pop();
                if(y == '(' || y == '{')
                    return false;
                break;
        }
    }
    return (s.empty());
}

int main() {
    string inp;
    cin >> inp;
    cout << check_parans(inp) << "\n";
}
