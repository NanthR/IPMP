#include<vector>
#include<iostream>

using namespace std;

int bitonic(vector<int> &arr) {
  vector<int> inc(arr.size(), 1);
  vector<int> dec(arr.size(), 1);
  int n = arr.size();
  for(int i = 1; i < n; i++) {
    inc[i] = (arr[i] >= arr[i-1]) ? inc[i-1] +1: 1;
  }

  for(int i = n-2; i >= 0; i--) {
    dec[i] = (arr[i] >= arr[i+1]) ? dec[i+1] +1: 1;
  }
  int m = inc[0] + dec[0] - 1;
  for(int i = 1; i < n; i++) {
    int val = inc[i] + dec[i] - 1;
    if(val > m)
      m = val;
  }
  return m;
}

int main() {
  vector<int> arr {1, 2, -1, 7, 5};
  cout << bitonic(arr) << "\n";
}
