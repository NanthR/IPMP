#include<bits/stdc++.h>

using namespace std;

int main() {
  unsigned int n;
  cin >> n;
  unsigned int even = n & 0xAAAAAAAA;
  unsigned int odd = n & 0x55555555;
  even >>= 1;
  odd <<= 1;
  cout << (even | odd) << "\n";
}
