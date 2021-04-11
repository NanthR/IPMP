#include<bits/stdc++.h>

using namespace std;

void sortK(vector<int>&arr, int k) {
  priority_queue<int, vector<int>, greater<int>> pq(arr.begin(), arr.begin()+k+1);
  int index = 0;
  for(int i = k + 1; i < arr.size(); i++) {
    arr[index++] = pq.top();
    pq.pop();
    pq.push(arr[i]);
  }
  while(!pq.empty()) {
    arr[index++] = pq.top();
    pq.pop();
  }
}

int main() {
  int k = 3;
  vector<int> arr {2,6,3,12,56,8};
  sortK(arr, k);
  for(int i = 0; i < arr.size(); i++)
    cout << arr[i] << " ";
  cout << "\n";
}
