#include<iostream>

using namespace std;

void reverse(string x) {
  if(x.size() == 0) {
    return;
  }
  reverse(x.substr(1));
  cout << x[0];
}

int main() {
  string x;
  cin >> x;
  reverse(x);
  cout << "\n";
}
