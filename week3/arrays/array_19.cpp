#include <bits/stdc++.h>

using namespace std;

int main() {

  vector<int> arr { 0, 4, 3, 2, 7, 8, 2, 3, 1 };
  int arr_size = arr.size();

  for (int i = 0; i < arr_size; i++) {
    arr[arr[i] % arr_size] = arr[arr[i] % arr_size] + arr_size;
  }

  for (int i = 0; i < arr_size; i++) {
    if (arr[i] >= arr_size * 2) {
      cout << i << " " << "\n";
    }
  }
}
