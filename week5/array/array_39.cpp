#include<iostream>
#include<vector>

using namespace std;

int min3(int a, int b, int c) { return min(min(a, b), c);}

void diagonalOrder(vector<vector<int>> &matrix) {
  int row = matrix.size();
  if(row == 0)
    return;
  int col = matrix[0].size();
  for (int line=1; line<=(row + col -1); line++) {
    int start_col = max(0, line - row);
    int count = min3(line, (col - start_col), row);

    for (int j=0; j<count; j++)
      cout << matrix[min(row, line)-j-1][start_col+j] << " ";

    cout << "\n";
  }
}

int main() {
  vector<vector<int>> M {{1, 2, 3, 4},
			  {5, 6, 7, 8},
			  {9, 10, 11, 12},
			  {13, 14, 15, 16},
			  {17, 18, 19, 20}};
  diagonalOrder(M);
}
