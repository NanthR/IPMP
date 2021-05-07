#include<iostream>
#include<vector>

using namespace std;

vector<vector<int>> rotate(vector<vector<int>> &image) {
  int r, c;
  int row = image.size();
  if(row == 0) {
    vector<vector<int>> res (0, vector<int>(0, 0));
    return res;
  }
  int col = image[0].size();
  vector<vector<int>> res (col, vector<int>(row, 0));
  for (r = 0; r < row; r++) {
    for (c = 0; c < col; c++) {
      res[c][row-r-1] = image[r][c];
    }
  }
  return res;
}

void print(vector<vector<int>> &mat) {
  for(auto &i: mat) {
    for(auto j: i) {
      cout << j << " ";
    }
    cout << "\n";
  }
}

int main() {
  vector<vector<int>> image {{1, 2, 3, 4},
				{5, 6, 7, 8},
				{9, 10, 11, 12}};
  vector<vector<int>> res = rotate(image);
  print(res);
}
