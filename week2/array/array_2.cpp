#include<iostream>

using namespace std;

int getOdd(int arr[], int n) {
  int result = 0;
  for(int i = 0; i < n; i++) {
    result ^= arr[i];
  }
  return result;
}

int main() {
  int arr[] = {1, 2, 3, 2, 3, 1, 3};
  int n = sizeof(arr) / sizeof(arr[0]);
  cout << getOdd(arr, n) << "\n";
}
