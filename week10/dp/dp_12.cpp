// Min insertions to palindrome

#include<iostream>
#include<vector>

using namespace std;
 
 
int min_to_palin(string str) {
    int n = str.size();
    vector<vector<int>> table(n, vector<int> (n , 0));
    int l, h, gap;
 
    for (gap = 1; gap < n; ++gap) {
        for (l = 0, h = gap; h < n; ++l, ++h)
            table[l][h] = (str[l] == str[h])? table[l + 1][h - 1] : (min(table[l][h - 1], table[l + 1][h]) + 1);
    }
 
    return table[0][n - 1];
}
 
int main() {
    string str = "geeks";
    cout << min_to_palin(str) << "\n";
}
