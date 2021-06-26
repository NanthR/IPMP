// Coin change

#include<iostream>
#include<vector>
 
using namespace std;
 
int count(vector<int> &S, int n) {
    int m = S.size();
    int x, y;
 
    vector<vector<int>> table(n + 1, vector<int>(m, 0));
     
    for(int i = 0; i < m; i++)
        table[0][i] = 1;
 
    for (int i = 1; i < n + 1; i++) {
        for (int j = 0; j < m; j++) {
            x = (i-S[j] >= 0) ? table[i - S[j]][j] : 0;
            y = (j >= 1) ? table[i][j - 1] : 0;
            table[i][j] = x + y;
        }
    }
    return table[n][m - 1];
}
 
int main() {
    vector<int> arr = {1, 2, 3};
    int n = 4;
    cout << count(arr, n);
}
