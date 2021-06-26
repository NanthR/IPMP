// Maximum value

#include<iostream>
#include<vector>

using namespace std;
 
int optimal(vector<int> &arr) {
    int n = arr.size();
    vector<vector<int>> dp(n, vector<int>(n, 0));
 
    for (int gap = 0; gap < n; ++gap) {
        for (int i = 0, j = gap; j < n; ++i, ++j) {
            int x = ((i + 2) <= j)
                        ? dp[i + 2][j]
                        : 0;
            int y = ((i + 1) <= (j - 1))
                        ? dp[i + 1][j - 1]
                        : 0;
            int z = (i <= (j - 2))
                        ? dp[i][j - 2]
                        : 0;
 
            dp[i][j] = max(
                arr[i] + min(x, y),
                arr[j] + min(y, z));
        }
    }
 
    return dp[0][n - 1];
}
 
int main() {
    vector<int> arr = { 8, 15, 3, 7 };
    cout << optimal(arr) << "\n";
}
