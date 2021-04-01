#include<bits/stdc++.h>

using namespace std;

int main() {
  unsigned int n;
  cin >> n;
  unsigned int count = sizeof(n) * 8 - 1;
  unsigned int reverse = n;
  n >>= 1;
  while(n) {
    reverse <<= 1;
    reverse |= n & 1;
    n >>= 1;
    count--;
  }
  reverse <<= count;
  cout << reverse << "\n";
}
