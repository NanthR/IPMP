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
  int n;
  cin >> n;
  cout << no_of_set(n);
}
