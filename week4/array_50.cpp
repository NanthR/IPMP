#include<bits/stdc++.h>

using namespace std;

int main() {
  vector<int> arr {1, 23, 12, 9, 30, 2, 50};
  priority_queue<int> pq(arr.begin(), arr.end());
  int k = 3;
  int c = 0;
  while(!pq.empty()) {
    if(c == k)
      break;
    c++;
    cout << pq.top() << " ";
    pq.pop();
  }
  cout << "\n";
}
