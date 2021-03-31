#include<bits/stdc++.h>

using namespace std;

int max(vector<int> &nums) {
  int n = nums.size();
  if(n == 1)
    return nums[0];
  int left = 0;
  int right = n - 1;
  // No rotation
  if(nums[right] > nums[left]) {
    return nums[right];
  }
  while(left <= right) {
    int cur = left + (right - left) / 2;
    if(nums[cur] > nums[cur+1])
      return nums[cur];
    if(nums[cur-1] > nums[cur])
      return nums[cur-1];
    if(nums[cur] > nums[0])
      right = cur - 1;
    else
      left = cur + 1;
  }
}

int main() {
  vector<int> nums {8, 10, 20, 80, 100, 200, 400, 500, 3, 2, 1};
  cout << max(nums) << "\n";
}
