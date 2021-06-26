//Longest palindrome substring
 
#include<iostream>
#include<vector>

using namespace std;
 
void print_sub(string str, int low, int high) {
    for (int i = low; i <= high; ++i)
        cout << str[i];
    cout << "\n";
}
 
int longest_palin(string str) {
    int n = str.size();
 
    vector<vector<bool>> table(n, vector<bool>(n, false));

    for(int i = 0; i < n; i++)
        table[i][i] = true;
 
    int maxLength = 1;
 
    int start = 0;
    for (int i = 0; i < n - 1; ++i) {
        if (str[i] == str[i + 1]) {
            table[i][i + 1] = true;
            start = i;
            maxLength = 2;
        }
    }
 
    for (int k = 3; k <= n; ++k) {
        for (int i = 0; i < n - k + 1; ++i) {
            int j = i + k - 1;
 
            if (table[i + 1][j - 1] && str[i] == str[j]) {
                table[i][j] = true;
 
                if (k > maxLength) {
                    start = i;
                    maxLength = k;
                }
            }
        }
    }
 
    print_sub(str, start, start + maxLength - 1);
 
    return maxLength;
}
 
int main() {
    string str = "abcddcba";
    cout << longest_palin(str) << "\n";
}
