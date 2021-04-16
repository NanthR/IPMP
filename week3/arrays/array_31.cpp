#include<iostream>
#include<vector>

using namespace std;

void print(vector<int> &arr) {
  for(auto it = arr.begin(); it != arr.end(); it++)
    cout << *it << " ";
  cout << "\n";
}

void move_to_end(vector<int>&arr) {
  int c = 0;
  for(auto it = arr.begin(); it != arr.end(); it++) {
    if(*it != 0) {
      arr[c] = *it;
      c++;
    }
  }
  while(c < arr.size()) {
    arr[c] = 0;
    c++;
  }
}

int main() {
  vector<int> arr {1, 9, 8, 4, 0, 0, 2, 7, 0, 6, 0, 9};
  move_to_end(arr);
  print(arr);
}
