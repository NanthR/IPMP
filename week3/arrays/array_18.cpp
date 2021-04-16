#include <bits/stdc++.h>

using namespace std;

void minAbsSumPair(vector<int> &arr) {

  int sum, min_sum = INT_MAX;
  int n = arr.size();
  int l = 0, r = n-1;

  int min_l = l, min_r = n-1;

  if(n < 2) {
    return;
  }

  sort(arr.begin(), arr.end());

  while(l < r) {
    sum = arr[l] + arr[r];

    if(abs(sum) < abs(min_sum)) {
      min_sum = sum;
      min_l = l;
      min_r = r;
    }
    if(sum < 0)
      l++;
    else
      r--;
  }
  cout << arr[min_l] << " " << arr[min_r] << "\n";
}

int main() {
  vector<int> arr {1, 60, -10, 70, -80, 85};
  minAbsSumPair(arr);
}
