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

int noOfOccur(vector<int> &nums, int x) {
  int firstIndex = first(nums, x);
  if(firstIndex == -1)
    return 0;
  int lastIndex = last(nums, x, firstIndex);
  return (lastIndex - firstIndex);
}

int main() {
  vector<int> nums {1,1,2,2,2,2,3};
  int x;
  cin >> x;
  cout << noOfOccur(nums, x) << "\n";
}
