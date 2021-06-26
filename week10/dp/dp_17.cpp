// Maximum sum subarray

#include<iostream>
#include<vector>
#include<climits>

using namespace std;
 
int kadane(vector<int> &arr, int* start, int* finish, int n) {
    int sum = 0, maxSum = INT_MIN, i;
 
    *finish = -1;
 
    int local_start = 0;
 
    for (i = 0; i < n; ++i) {
        sum += arr[i];
        if (sum < 0) {
            sum = 0;
            local_start = i + 1;
        }
        else if (sum > maxSum) {
            maxSum = sum;
            *start = local_start;
            *finish = i;
        }
    }
 
    if (*finish != -1)
        return maxSum;
 
    maxSum = arr[0];
    *start = *finish = 0;
 
    for (i = 1; i < n; i++) {
        if (arr[i] > maxSum) {
            maxSum = arr[i];
            *start = *finish = i;
        }
    }
    return maxSum;
}
 
void max_sum(vector<vector<int>> &M) {
    int maxSum = INT_MIN;
    int finalLeft, finalRight, finalTop, finalBottom;

    int row = M.size();
    int col = M[0].size();

 
    int left, right, i;
    int sum, start, finish;
 
    for (left = 0; left < col; ++left) {
        vector<int> temp (row, 0);
 
        for (right = left; right < col; ++right) {
 
            for (i = 0; i < row; ++i)
                temp[i] += M[i][right];
 
            sum = kadane(temp, &start, &finish, row);
 
            if (sum > maxSum) {
                maxSum = sum;
                finalLeft = left;
                finalRight = right;
                finalTop = start;
                finalBottom = finish;
            }
        }
    }
 
    cout << "(Top, Left) (" << finalTop << ", " << finalLeft << ")" << "\n";
    cout << "(Bottom, Right) (" << finalBottom << ", " << finalRight << ")" << "\n";
    cout << "Max sum is: " << maxSum << "\n";
}
 
int main() {
    vector<vector<int>> M = { { 1, 2, -1, -4, -20 },
                        { -8, -3, 4, 2, 1 },
                        { 3, 8, 10, 1, 3 },
                        { -4, -1, 1, 7, -6 } };
    max_sum(M);
}
