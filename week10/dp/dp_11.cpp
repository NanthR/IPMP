// Rod Cutting

#include<iostream>
#include<climits>
#include<vector>

using namespace std;
 
int cut_rod(vector<int> &price) {
    int n = price.size();
    vector<int> val(n+1, 0);
 
    for (int i = 1; i<=n; i++) {
        int max_val = INT_MIN;
        for (int j = 0; j < i; j++)
            max_val = max(max_val, price[j] + val[i-j-1]);
        val[i] = max_val;
   }
 
    return val[n];
}
 
int main() {
    vector<int> arr = {1, 5, 8, 9, 10, 17, 17, 20};
    cout << cut_rod(arr);
}
