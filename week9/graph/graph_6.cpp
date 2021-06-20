#include<iostream>
#include<vector>

using namespace std;

int is_safe(vector<vector<int>> &M, int row, int col, vector<vector<bool>> &visited) {
    int m = M.size();
    int n = M[0].size();
    return (row >= 0) && (row < m) && (col >= 0) && (col < n) && (M[row][col] && !visited[row][col]);
}

void dfs(vector<vector<int>> &M, int row, int col, vector<vector<bool>> &visited) {
    vector<int> rowNbr { -1, -1, -1, 0, 0, 1, 1, 1 };
    vector<int> colNbr { -1, 0, 1, -1, 1, -1, 0, 1 };

    visited[row][col] = true;

    for (int k = 0; k < 8; ++k)
        if (is_safe(M, row + rowNbr[k], col + colNbr[k], visited))
            dfs(M, row + rowNbr[k], col + colNbr[k], visited);
}

int count_islands(vector<vector<int>> &M) {
    vector<vector<bool>> visited(M.size(), vector<bool>(M[0].size(), false));

    int count = 0;
    for (int i = 0; i < M.size(); ++i) {
        for (int j = 0; j < M[0].size(); ++j) {
            if (M[i][j] && !visited[i][j]) {
                dfs(M, i, j, visited);
                ++count;
            }
        }
    }

    return count;
}

int main() {
    vector<vector<int>> M {{ 1, 1, 0, 0, 0 },
                     { 0, 1, 0, 0, 1 },
                     { 1, 0, 0, 1, 1 },
                     { 0, 0, 0, 0, 0 },
                     { 1, 0, 1, 0, 1 }};

    cout << count_islands(M);
}
