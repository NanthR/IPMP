// Dice throws

#include<iostream>
#include<vector>

using namespace std;
 
long find_ways(int f, int d, int s) {
    vector<vector<long>> dp(d + 1, vector<long>(s + 1, 0));
    dp[0][0] = 1;
    for (int i = 1; i <= d; i++) {
        for (int j = i; j <= s; j++) {
            dp[i][j] = dp[i][j - 1] + dp[i - 1][j - 1];
            if (j - f - 1 >= 0)
                dp[i][j] -= dp[i - 1][j - f - 1];
        }
    }
    return dp[d][s];
}
 
int main(void) {
    cout << find_ways(2, 2, 3) << endl;
}
