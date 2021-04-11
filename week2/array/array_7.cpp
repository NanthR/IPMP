#include<iostream>

using namespace std;

int next(int a) {
  string x = to_string(a);
  int i, n;
  n = x.size();
  for(i = n-1; i >= 0; i--) {
    if(i == 0)
      return -1;
    if(x[i] > x[i-1]) {
      break;
    }
  }
  string s1 = x.substr(0, i);
  string s2 = x.substr(i, n-i);
  for(int i = s2.size() - 1; i >= 0; i--) {
    if(s2[i] > s1[s1.size() - 1]) {
      auto temp = s2[i];
      s2[i] = s1[s1.size() - 1];
      s1[s1.size() - 1] = temp;
    }
  }
  return stoi(s1+s2);
}

int main() {
  int a;
  cin >> a;
  cout << next(a) << "\n";
}
