#include <bits/stdc++.h>

using namespace std;

void productArray(vector<int> &arr) {
  int n = arr.size();
  if (n == 1) {
    cout << 0;
    return;
  }

  int i, temp = 1;
  vector<int> prod(n, 1);

  for (i = 0; i < n; i++) {
    prod[i] = temp;
    temp *= arr[i];
  }

  temp = 1;

  for (i = n - 1; i >= 0; i--) {
    prod[i] *= temp;
    temp *= arr[i];
  }

  for (i = 0; i < n; i++)
    cout << prod[i] << " ";
  cout << "\n";
}

int main() {
  vector<int> arr { 10, 3, 5, 6, 2 };
  productArray(arr);
}
