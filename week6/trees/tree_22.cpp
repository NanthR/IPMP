#include<iostream>
#include<math.h>

using namespace std;

int no_of_ones(int m) {
  int c = 0;
  while(m) {
    m = m & (m-1);
    c += 1; 
  }
  return c;
}

int result(int n, int k) {
  if(pow(2, n) < k)
    return -1;
  return no_of_ones(k) % 2;
}

int main() {
  int n,k;
  cin >> n >> k;
  cout << result(n, k) << "\n";
}
