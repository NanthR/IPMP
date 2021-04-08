#include<bits/stdc++.h>

using namespace std;

void get_two(int arr[], int n) {
  int m = 0;
  for(int i = 0; i < n; i++)
    m ^= arr[i];
  int mask = m & (-m);
  int a,b;
  a = b = 0;
  for(int i = 0; i < n; i++) {
    int val = mask & arr[i];
    if(val == 0) {
      a ^= arr[i];
    }
    else {
      b ^= arr[i];
    }
  }
  cout << a << " " << b << "\n";
}

int main() {
  int arr[] = {2, 4, 7, 9, 2, 4};
  int n = sizeof(arr) / sizeof(arr[0]);
  get_two(arr, n);
}
