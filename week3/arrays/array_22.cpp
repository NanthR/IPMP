#include <bits/stdc++.h>

using namespace std;

void search(vector<vector<int>> &mat, int x) {
  int m = mat.size();
  int n = mat[0].size();

  if (m == 0)
    return;
	
  for(int i = 0; i < m; i++) {
    for(int j = 0; j < n; j++)
    if(mat[i][j] == x) {
      cout<<"Element found at ("<<  i << ", " << j << ")\n";
      return;
    }
  }

  cout << "Element not found";
  return;
}

int main() {
  vector<vector<int>> mat = { {10, 20, 30, 40},
			      {15, 25, 35, 45},
			      {27, 29, 37, 48},
			      {32, 33, 39, 50} };
  search(mat, 29);
}
