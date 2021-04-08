#include<bits/stdc++.h>

using namespace std;

int findMissing(int arr[], int n) {
  int res = 0;
  for(int i = 0; i < n; i++) {
    res ^= (i+1);
    res ^= (arr[i]);
  }
  return res ^ (n+1);
}

int main() {
  int arr[] = {1, 4, 6, 7, 2, 5};
  int n = sizeof(arr) / sizeof(arr[0]);
  cout << findMissing(arr, n) << "\n";
}
