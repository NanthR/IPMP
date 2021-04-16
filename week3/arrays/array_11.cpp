#include<iostream>

using namespace std;

void find_four(int arr[], int n, int x) {
  unordered_map<int, pair<int, int>> um;
  for(int i = 0; i < n; i++) {
    for(int j = i+1; j < n; j++) {
      mp[arr[i] + arr[j]] = {i, j};
    }
  }
  for(int i = 0; i < n; i++) {
    for(int j = i + 1; j < n; j++) {
      int s = arr[i] + arr[j];
      if(um.find(x - s) != um.end()) {
	pair<int, int> p = um[x - sum];
	if(p.first != i && p.first != j && p.second != j && p.second != i) {
	  cout << arr[i] << " " <<  arr[j] << " " << arr[p.first] << " " << arr[p.second] << "\n";
	  return;
	}
      }
    }
  }
}

int main() {
  int arr[] = { 10, 20, 30, 40, 1, 2 };
  int n = sizeof(arr) / sizeof(arr[0]);
  int X = 91;
  find_four(arr, n, x);
}
