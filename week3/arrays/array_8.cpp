#include<iostream>
#include<unordered_set>

using namespace std;

void find_pair(int arr[], int sum, int n) {
  unordered_set<int> seen;
  for(int i = 0; i < n; i++) {
    int needed = sum - arr[i];
    if(seen.find(needed) != seen.end()) {
      cout << "Pair is " << arr[i] << " and " << needed << "\n";
      return;
    }
    seen.insert(arr[i]);
  }
}

int main() {
  int arr[] = {1, 4, 45, 8, 6, 10, 8};
  int sum = 16;
  int n = sizeof(arr) / sizeof(arr[0]);
  find_pair(arr, sum, n);
}
