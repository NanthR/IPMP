#include<bits/stdc++.h>

using namespace std;

bool check_pow_2(long long int n) {
  if(n == 0)
    return false;
  return ((n&(n-1)) == 0);
}

int main() {
  long long int n;
  cin >> n;
  check_pow_2(n);
}
