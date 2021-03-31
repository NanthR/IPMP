#include<bits/stdc++.h>

using namespace std;

int findMin(vector<int> &arr) {
  if(arr.size() == 1)
    return arr[0];
  int left = 0;
  int right = arr.size() - 1;
  if(arr[right] > arr[left]) {
    return arr[left];
  }
  while(left <= right) {
    int cur = left + (right - left) / 2;
    if(arr[cur] > arr[cur + 1])
      return arr[cur + 1];

    if(arr[cur - 1] > arr[cur])
      return arr[cur];

    if(arr[cur] > arr[0])
      left = cur + 1;
    else
      right = cur - 1;
  }
}

int main() {
  vector<int> arr {5, 6, 1, 2, 3, 4};
  cout << "Min is " << findMin(arr) << "\n";
}
