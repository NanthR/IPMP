#include<bits/stdc++.h>

using namespace std;

int main() {
  int n;
  cin >> n;
  int l = (n >> (sizeof(int) * 8 - 1));
  cout << ((n + l) ^ l);
}
