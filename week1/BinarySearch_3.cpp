#include<bits/stdc++.h>

using namespace std;

int first(vector<int> &nums, int x) {
  int left = 0;
  int right = nums.size() - 1;
  int result = -1;
  while(left <= right) {
    int cur = left + (right - left) / 2;
    int val = nums[cur];
    if(x == val) {
      result = cur;
      right = cur - 1;
    }
    else if(x < val)
      right = cur - 1;
    else
      left = cur + 1;
  }
  return result;
}

int last(vector<int> &nums, int x, int left) {
  int right = nums.size() - 1;
  int result = -1;
  while(left <= right) {
    int cur = left + (right - left) / 2;
    int val = nums[cur];
    int n = nums.size();
    if(x == val) {
      result = cur;
      left = cur + 1;
    }
    else if(x < val)
      right = cur - 1;
    else
      left = cur + 1;
  }
  return result;
}

int count(vector<int> &nums, int x) {
  int left = first(nums, x);
  if(left == -1)
    return 0;
  int right = last(nums, x, left);
  return (right - left);
}

bool isMajority(vector<int> &arr, int x) {
  int c = count(arr, x);
  if(c >= (arr.size()/2))
    return true;
  return false;
}

int main() {
  vector<int> arr {1, 2, 3, 3, 3, 3, 10};
  int x;
  cin >> x;
  if(isMajority(arr, x)) {
    cout << x << " is a majortiy\n";
  }
  else {
    cout << x << " is not a majortiy\n";
  }
}
