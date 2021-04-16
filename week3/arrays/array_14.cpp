#include<bits/stdc++.h>

using namespace std;

int firstMissingPositive(vector<int>& nums) {
  unordered_set<int> seen;
  for(auto it = nums.begin(); it != nums.end(); it++) {
    if(*it > 0)
      seen.insert(*it);
  }
  int c = 1;
  while(true) {
    if(seen.find(c) == seen.end())
        return c;
    c++;
  }
}

int main() {
  vector<int> arr {7,8,9,11,12};
  cout << firstMissingPositive(arr) << "\n";
}
