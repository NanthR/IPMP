#include<vector>
#include<iostream>

using namespace std;

void left_rotate(vector<int> &arr, int d) {
  for(int i = 0; i < d; i++) {
    int temp = arr[0];
    for(int i = 0; i < arr.size() - 1; i++) {
      arr[i] = arr[i+1];
    }
    arr[arr.size() - 1] = temp;
  }
}

int main() {
  vector<int> arr {1, 2, -1, 7, 5};
  left_rotate(arr, 2);
  for(auto i: arr) {
    cout << i << " ";
  }
  cout << "\n";
}
