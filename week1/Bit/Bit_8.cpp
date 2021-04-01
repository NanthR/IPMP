#include<bits/stdc++.h>

using namespace std;

int add(int a, int b) {
  while(a) {
    int carry = a & b;
    b = b ^ a;
    a = carry << 1;
  }
  return b;
}

int main() {
  int a, b;
  cin >> a >> b;
  cout << "Val is: " << add(a, b) << "\n";
}
