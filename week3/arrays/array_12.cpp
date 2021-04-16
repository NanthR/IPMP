#include<iostream>

using namespace std;

void find_repeating(int arr[], int size, int n) {
  int r = 0;
  for(int i = 1; i <= n; i++)
    r ^= i;
  for(int i = 0; i < size; i++)
    r ^= arr[i];
  int mask = r & ~(r-1);
  int a = 0, b = 0;
  for(int i = 1; i <= n; i++) {
    if(i & mask)
      a ^= i;
    else
      b ^= i;
  }
  for(int i = 0; i < size; i++) {
    if(arr[i] & mask)
      a ^= arr[i];
    else
      b ^= arr[i];
  }
  cout << a << " " << b << "\n";
}

int main() {
  int arr[] = {4, 2, 4, 5, 2, 3, 1};
  int n = 5;
  int size = sizeof(arr) / sizeof(arr[0]);
  find_repeating(arr, size, n);
}
