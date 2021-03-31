#include<bits/stdc++.h>

using namespace std;

int fixed_pont(vector<int> &nums) {
  int left = 0;
  int right = nums.size() - 1;
  while(left <= right) {
    int cur = left + (right - left) / 2;
    int val = nums[cur];
    if(val == cur)
      return cur;
    if(val > cur)
      right = cur - 1;
    else
      left = cur + 1;
  }
  return -1;
}

int main() {
  vector <int> nums {-10, -5, 3, 4, 7, 9};
  int index = fixed_pont(nums);
  if(index == -1)
    cout << "No fixed point found\n";
  else
    cout << "Fixed point is " << nums[index] << "\n";
}
