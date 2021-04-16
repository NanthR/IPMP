#include<vector>
#include<iostream>

using namespace std;

int max_diff(vector<int> &arr) {
  int max_diff = arr[1] - arr[0];
  int min_elem = arr[0];
  for(int i = 1; i < arr.size(); i++) {
    if(arr[i] - min_elem > max_diff)
      max_diff = arr[i] - min_elem;
    if(arr[i] < min_elem)
      min_elem = arr[i];
  }
  return max_diff;
}

int main() {
  vector<int> arr {1, 2, 9, 4, 11};
  cout << max_diff(arr) << "\n";
}
