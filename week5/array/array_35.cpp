#include <bits/stdc++.h>

using namespace std;

void modify(vector<vector<bool>> &mat) {
  int R = mat.size();
  if(R == 0)
    return;
  int C = mat[0].size();
  vector<bool> row(R, false);
  vector<bool> col(C, false);

  for (int i = 0; i < R; i++) {
    for (int j = 0; j < C; j++) {
      if (mat[i][j] == 1) {
	      row[i] = 1;
	      col[j] = 1;
      }
    }
  }

  for (int i = 0; i < R; i++) {
    for (int j = 0; j < C; j++) {
      if (row[i] == true || col[j] == true) {
	mat[i][j] = 1;
      }
    }
  }
}

void print(vector<vector<bool>> &mat) {
  for(auto &i: mat) {
    for(auto j: i) {
      cout << j << " ";
    }
    cout << "\n";
  }
}

int main() {
  vector<vector<bool>> mat {{1, 0, 0, 1},
		      {0, 0, 1, 0},
		      {0, 0, 0, 0}};

  cout << "Input Matrix\n";
  print(mat);

  modify(mat);

  cout << "Matrix after modification\n";
  print(mat);
}
