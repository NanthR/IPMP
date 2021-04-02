#include<bits/stdc++.h>

using namespace std;

int find_pivot(vector<int> &arr, int left, int right) {
  if(right < left)
    return -1;
  if(left == right)
    return left;
  int cur = left + (right - left) / 2;
  int val = arr[cur];
  if(cur < right && val > arr[cur + 1])
    return cur;
  if(cur > left && val < arr[cur-1])
    return cur - 1;
  if(arr[left] >= arr[cur])
    return find_pivot(arr, left, cur-1);
  return find_pivot(arr, cur + 1, right);
}

int binary_search(vector<int> &arr, int x, int left, int right) {
  if(left > right)
    return -1;
  int cur = left + (right - left) / 2;
  int val = arr[cur];
  if(x == val)
    return cur;
  if(x > val)
    return binary_search(arr, x, cur + 1, right);
  return binary_search(arr, x, left, cur - 1);
}

int search(vector<int> &arr, int x) {
  int pivot = find_pivot(arr, 0, arr.size() - 1);
  if(arr[pivot] == x)
    return pivot;
  if(arr[0] <= x)
    return binary_search(arr, x, 0, pivot-1);
  return binary_search(arr, x, pivot + 1, arr.size() - 1);
}

int main() {
  vector<int> arr {12, 14, 17, 19, 4, 5, 10, 11};
  int x;
  cin >> x;
  int index = search(arr, x);
  if(index == -1)
    cout << "Not found\n";
  else
    cout << "Found at " << index << "\n";
}
