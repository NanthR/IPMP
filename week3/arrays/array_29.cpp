#include<iostream>
#include<vector>

using namespace std;

void print(vector<int> &arr) {
  for(auto it = arr.begin(); it != arr.end(); it++)
    cout << *it << " ";
  cout << "\n";
}

void segregate(vector<int> &arr) {
  int l = 0, r = arr.size() - 1;
  while(l < r) {
    while(arr[l] % 2 == 0 && l < r)
      l++;
    while(arr[r] % 2 == 1 && r > l)
      r--;
    if(l < r) {
      int temp = arr[r];
      arr[r] = arr[l];
      arr[l] = temp;
      l++;
      r--;
    }
  }
}

int main() {
  vector<int> arr {12, 34, 45, 9, 8, 90, 3};
  segregate(arr);
  print(arr);
}
