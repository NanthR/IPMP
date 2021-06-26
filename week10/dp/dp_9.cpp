// Maximum sum increasing subsequence

#include<iostream>
#include<vector>
using namespace std;
 
int max_sum_inc(vector<int> &arr) {
    int n = arr.size();
    int max = 0;
    vector<int> dp(arr.begin(), arr.end());
 
    for (int i = 1; i < n; i++ ) {
        for (int j = 0; j < i; j++ ) {
            if (arr[i] > arr[j] && dp[i] < dp[j] + arr[i])
                dp[i] = dp[j] + arr[i];
        }
    }
 
    for (int i = 0; i < n; i++) {
        if (max < dp[i])
            max = dp[i];
    }
 
    return max;
}
 
int main() {
    vector<int> arr = {1, 101, 2, 3, 100, 4, 5};
    cout << max_sum_inc(arr) << "\n";
}
