#include<iostream>

using namespace std;

int main() {
  string x;
  cin >> x;
  char cur = x[0];
  int c = 0;
  string res = "";
  for(auto &i: x) {
    if(i == cur) {
      c += 1;
    } else {
      res.push_back(cur);
      res.push_back('0' + c);
      cur = i;
      c = 1;
    }
  }
  res.push_back(cur);
  res.push_back('0' + c);
  cout << res << "\n";
}
