#include<bits/stdc++.h>

using namespace std;

void ceilFloor(vector<int>& nums, int x) {
  if(nums.empty()) {
    printf("Empty array");
  }
  int left = 0;
  int right = nums.size() - 1;
  int ceil = -1;
  int floor = -1;
  while(left <= right) {
    int cur = left + (right - left) / 2;
    int val = nums[cur];
    if(val == x) {
      ceil = cur;
      floor = cur;
      break;
    }
    if(val < x) {
      left = cur + 1;
      floor = cur;
    }
    else {
      right = cur - 1;
      ceil = cur;
    }
  }
  if(ceil == -1)
    cout << "No ceil exists\n";
  else
    cout << "Ceil is " << ceil << "\n";
  if(floor == -1)
    cout << "No floor exists\n";
  else
     cout << "Floor is " << floor << "\n";
}

int main() {
  vector<int> nums {1, 2, 8, 10, 10, 12, 19};
  int x;
  cin >> x;
  ceilFloor(nums, x);
}
