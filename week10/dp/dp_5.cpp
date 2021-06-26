// Matrix Chain order

#include<iostream>
#include<vector>
#include<climits>

using namespace std;

vector<vector<int>> dp(100, vector<int> (100, -1));
 
int helper(vector<int> &p, int i, int j) {
    if (i == j) {
        return 0;
    }
    if (dp[i][j] != -1) {
        return dp[i][j];
    }
    dp[i][j] = INT_MAX;
    for (int k = i; k < j; k++) {
        dp[i][j] = min(dp[i][j], helper(p, i, k) + helper(p, k + 1, j) + p[i - 1] * p[k] * p[j]);
    }
    return dp[i][j];
}
int chain(vector<int> &p) {
    int n = p.size();
    int i = 1, j = n - 1;
    return helper(p, i, j);
}
 
int main() {
    vector<int> arr = { 1, 2, 3, 4 };
    cout << chain(arr) << "\n";
}
