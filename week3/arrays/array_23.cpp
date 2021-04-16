#include <bits/stdc++.h>

using namespace std;
 
vector<int> spiralOrder(vector<vector<int>> &matrix) {
  vector<int> res;
   
  if (matrix.size() == 0)
    return res;
 
  int m = matrix.size(), n = matrix[0].size();
  bool seen[m][n];
  int dr[] = {0, 1, 0, -1};
  int dc[] = {1, 0, -1, 0};
  int r = 0, c = 0, di = 0;
 
  for (int i = 0; i < m * n; i++) {
    res.push_back(matrix[r]);
    seen[r] = true;
    int cr = r + dr[di];
    int cc = c + dc[di];
 
    if (0 <= cr && cr < m && 0 <= cc && cc < n && !seen[cr][cc]) {
      r = cr;
      c = cc;
    }
    else {
      di = (di + 1) % 4;
      r += dr[di];
      c += dc[di];
    }
  }
  return res;
}
 
int main() {
  vector<vector<int>> arr {{1, 2, 3, 4},
			   {5, 6, 7, 8},
			   {9, 10, 11, 12},
			   {13, 14, 15, 16}};
  for(int x:spiralOrder(arr))
      cout << x << " ";
  cout << "\n";
}
