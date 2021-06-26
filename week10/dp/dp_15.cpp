// Palindrome partitioning

#include<iostream>
#include<vector>
#include<climits>

using namespace std;
 
int pal_part(string str) {
    int n = str.length();
 
    vector<vector<int>> C(n, vector<int>(n, 0));
    vector<vector<bool>> P(n, vector<bool>(n, true));
 
    for (int L = 2; L <= n; L++) {
        for (int i = 0; i < n - L + 1; i++) {
            int j = i + L - 1;
 
            if (L == 2)
                P[i][j] = (str[i] == str[j]);
            else
                P[i][j] = (str[i] == str[j]) && P[i + 1][j - 1];
 
            if (P[i][j] == true)
                C[i][j] = 0;
            else {
                C[i][j] = INT_MAX;
                for (int k = i; k <= j - 1; k++)
                    C[i][j] = min(C[i][j], C[i][k] + C[k + 1][j] + 1);
            }
        }
    }
 
    return C[0][n - 1];
}
 
int main() {
    string str;
    cin >> str;
    cout << pal_part(str) << "\n";
}
