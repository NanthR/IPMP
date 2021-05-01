#include<vector>
#include<iostream>
#include<climits>

using namespace std;

int max_sum(vector<int>&arr) {
  int m1 = INT_MIN, m2 = 0;
  for(auto it: arr) {
    m2 += it;
    if(m1 < m2) {
      m1 = m2;
    }
    if(m2 < 0) {
      m2 = 0;
    }
  }
  return m1;
}

int main() {
  vector<int> arr {-2, -3, 4, -1, -2, 1, 5, -3};
  cout << max_sum(arr) << "\n";
}
