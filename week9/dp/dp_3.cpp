#include<iostream>
#include<vector>
#include<climits>

using namespace std;
 
int min(int x, int y) { return (x < y) ? x : y; }
 
int min_jumps(vector<int> arr) {
  int n = arr.size();
  vector<int> jumps (arr.size(), 0);
  int i, j;

  if (n == 0 || arr[0] == 0)
    return INT_MAX;

  jumps[0] = 0;

  for (i = 1; i < n; i++) {
    jumps[i] = INT_MAX;
    for (j = 0; j < i; j++) {
      if (i <= j + arr[j] && jumps[j] != INT_MAX) {
	jumps[i] = min(jumps[i], jumps[j] + 1);
	break;
      }
    }
  }
  return jumps[n - 1];
}
 
int main() {
  vector<int> arr { 1, 3, 6, 1, 0, 9 };
  cout << min_jumps(arr) << "\n";
}
