#include<bits/stdc++.h>

using namespace std;

int main() {
  int n;
  cin >> n;
  cout << ((n & 0b1111) << 4 | (n & 0b11110000) >> 4);
}
