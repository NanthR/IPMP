#include<bits/stdc++.h>

using namespace std;

void print_k(vector<int> &arr, int k) {
    int n = arr.size();
    deque<int> q(k);

    int i;

    for(i = 0; i < k; ++i) {

        while((!q.empty()) && arr[i] >= arr[q.back()])
            q.pop_back();

        q.push_back(i);
    }

    for (; i < n; ++i) {
        cout << arr[q.front()] << " ";

        while ((!q.empty()) && q.front() <= i - k)

            q.pop_front();

        while((!q.empty()) && arr[i] >= arr[q.back()])
            q.pop_back();

        q.push_back(i);
    }

    cout << arr[q.front()];
    cout << "\n";
}

int main() {
    vector<int> arr { 12, 1, 78, 90, 57, 89, 56 };
    int k = 3;
    print_k(arr, k);
}
