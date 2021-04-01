#include<bits/stdc++.h>

using namespace std;

int no_of_set(int n) {
  int count = 0;
  while(n) {
    count++;
    n = n & (n - 1);
  }
  return count;
}

int main() {
  int a, b;
  cin >> a >> b;
  cout << no_of_set(a ^ b) << "\n";
}
