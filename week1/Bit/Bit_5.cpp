#include<bits/stdc++.h>

using namespace std;

int left(int n, int d) {
  return (n << d) | (n >> (sizeof(int)*8 - d));
}

int right(int n, int d) {
  return (n >> d) | (n << (sizeof(int)*8 - d));
}

int main() {
  int n;
  cin >> n;
  int d;
  cin >> d;
  cout << "Left is " << left(n, d) << "\n";
  cout << "Right is " << right(n, d) << "\n";
}
