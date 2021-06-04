#include<iostream>

using namespace std;

int str_cmp(string x, string y) {
  int i;
  for(i = 0; x[i] && x2[i]; i++) {
    if(x[i] == y[i] || (x[i] ^ 32) == y[i])
      continue;
    break;
  }
  if(x[i] == y[i])
    return 0;
  if((x[i] | 32) < (x[i] | 32))
    return -1;
  return 1;
}

int main() {
  string x, y;
  cin >> x >> y;
  cout << str_cmp(x, y);
}
