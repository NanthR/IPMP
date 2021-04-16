#include <bits/stdc++.h>

using namespace std;

int equilibrium(vector<int> arr) {
  int sum = 0;
  int leftsum = 0;
  int n = arr.size();

  for (int i = 0; i < n; ++i)
    sum += arr[i];

  for (int i = 0; i < n; ++i) {
    sum -= arr[i];
    if (leftsum == sum)
	    return i;
    leftsum += arr[i];
  }

  return -1;
}

int main() {
  vector<int> arr { -7, 1, 5, 2, -4, 3, 0 };
  cout << equilibrium(arr) << "\n";
}
