#include<bits/stdc++.h>

using namespace std;
 
int maxRepeating(vector<int> &arr, int k) {
  int n = arr.size();
  for (int i = 0; i< n; i++)
    arr[arr[i]%k] += k;
 
  int max = arr[0], result = 0;
  for (int i = 1; i < n; i++) {
    if (arr[i] > max) {
      max = arr[i];
      result = i;
    }
  }
  return result;
}
 
int main() {
  vector<int> arr {2, 3, 3, 5, 3, 4, 1, 7};
  int k = 8;
  cout << maxRepeating(arr, k) << "\n";
}
