#include<vector>
#include<iostream>

using namespace std

int maxVal(vector<int> &arr) {
  int r = arr[0];
  for(int i = 0; i < arr.size(); i++) {
    int m = arr[i];
    for(int j = i + 1; j < arr.size(); j++) {
      r = max(r, m);
      m *= arr[j];
    }
    r = max(r, m);
  }
  return r;
}

int main() {
  vector<int> arr {1, 2, -1, 7, 5};
  cout << maxVal(arr) << "\n";
}
