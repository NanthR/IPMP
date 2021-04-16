#include <bits/stdc++.h>

using namespace std;

void print_repeating(vector<int> &arr) {
  for (int i = 0; i < arr.size(); i++) {
  if (arr[abs(arr[i])] >= 0)
    arr[abs(arr[i])] = -arr[abs(arr[i])];
  else
    cout << abs(arr[i]) << " ";
  }
}

int main() {
  vector<int> arr { 1, 2, 3, 1, 3, 6, 6 };
  print_repeating(arr);
}
