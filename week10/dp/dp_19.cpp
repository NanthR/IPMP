// Egg Dropping
#include<climits>
#include<iostream>
#include<vector>
 
using namespace std;
 
int egg_drop(int n, int k) {
    vector<vector<int>> dp(n + 1, vector<int>(k + 1, 0));
    int res;
 
    for (int i = 1; i <= n; i++) {
        dp[i][1] = 1;
        dp[i][0] = 0;
    }
 
    for (int j = 1; j <= k; j++)
        dp[1][j] = j;
 
    for (int i = 2; i <= n; i++) {
        for (int j = 2; j <= k; j++) {
            dp[i][j] = INT_MAX;
            for (int x = 1; x <= j; x++) {
                res = 1 + max(dp[i - 1][x - 1], dp[i][j - x]);
                if (res < dp[i][j])
                    dp[i][j] = res;
            }
        }
    }
 
    return dp[n][k];
}
 
int main() {
    int n = 2, k = 36;
    cout << egg_drop(n, k) << "\n";
}
