#include<iostream>
#include<vector>
#include<string.h>

using namespace std;
 
int LCS(string X, string Y) {
    int m = X.size();
    int n = Y.size();
    vector<vector<int>> suffix(m + 1, vector<int>(n + 1, 0));
    int result = 0;
 
    for (int i = 0; i <= m; i++) {
        for (int j = 0; j <= n; j++) {
            if (i == 0 || j == 0)
                suffix[i][j] = 0;
 
            else if (X[i - 1] == Y[j - 1]) {
                suffix[i][j] = suffix[i - 1][j - 1] + 1;
                result = max(result, suffix[i][j]);
            }
            else
                suffix[i][j] = 0;
        }
    }
    return result;
}
 
int main() {
    string X = "HelloHowAre";
    char Y[] = "How";
 
    cout << LCS(X, Y);
}
