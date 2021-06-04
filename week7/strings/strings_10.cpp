#include<iostream>
#include<vector>
#include<climits>

using namespace std;

char first(string x) {
  pair<int, int> arr[256];
  for(int i = 0; i < x.length(); i++) {
    arr[x[i]].first++;
    arr[x[i]].second = i;
  }
  int res = INT_MAX;
  for(int i = 0; i < 256; i++) {
    if(arr[i].first == 1)
      res = min(res, arr[i].second);
  }
  return x[res];
}

int main() {
  string x;
  cin >> x;
  cout << first(x) << "\n";
}
