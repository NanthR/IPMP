#include<iostream>

using namespace std;

bool is_num(char x) {
  return (x >= '0' && x <= '9');
}

int atoi(string x) {
  if(x.empty())
    return 0;
  int res = 0;
  int s = -1;
  int i = 0;

  if(x[0] == '-') {
    s = -1;
    i++;
  }
  for(; i < x.length(); i++) {
    if(!is_num(x[i]))
      return 0;
    res = res * 10 + (x[i] - '0');
  }
  return s * res;
}

int main() {
  cout << atoi("-1234") << "\n";
}
