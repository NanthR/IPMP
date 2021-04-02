#include<bits/stdc++.h>

using namespace std;

int ceil(vector<int> &vals, int left, int right, int x) {
  while(right - left > 1) {
    int mid = left + (right - left) / 2;
    if(vals[mid] >= x)
      right = mid;
    else
      left = mid;
  }
  return right;
}

int longest(vector<int> &arr) {
  if(arr.size() == 0)
    return 0;
  vector<int> vals(arr.size(), 0);
  int length = 1;
  vals[0] = arr[0];
  for(int i = 1; i < arr.size(); i++) {
    if(arr[i] < vals[0])
      vals[0] = arr[i];
    else if(arr[i] >  vals[length - 1]) {
      vals[length] = arr[i];
      length++;
    }
    else
      vals[ceil(vals, -1, length-1, arr[i])] = arr[i];
  }
  return length;
}

int main() {
  vector<int> arr {1, 2, 3, 4, 10, 5, 8, 12};
  cout << longest(arr);
}
