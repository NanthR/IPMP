#include<iostream>
#include<unordered_set>

using namespace std;

void find_triplet(int arr[], int sum, int n) {
  unordered_set<int> seen;
  for(int i = 0; i < n; i++) {
    int cur = sum - arr[i];
    for(int j = i+1; j < n; j++) {
      int needed = cur - arr[j];
      if(seen.find(needed) != seen.end()) {
	cout << arr[i] << " " << arr[j] << " " << needed << "\n";
	return;
      }
      seen.insert(arr[j]);
    }
  }
}

int main() {
  int arr[] = {1, 4, 45, 6, 10, 8};
  int sum = 22;
  int n = sizeof(arr) / sizeof(arr[0]);
  find_triplet(arr, sum, n);
}
