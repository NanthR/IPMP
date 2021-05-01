#include<vector>
#include<iostream>

using namespace std;

void isSub(vector<int> &arr, int sum) {
  int c = arr[0], s = 0;
  for(int i = 1; i <= n; i++) {
    while(c > sum && s < i - 1) {
      c -= arr[s];
      s++;
    }
    if(c == sum) {
      cout << "Found\n";
      return;
    }
    if(i < n)
      c = c + arr[i];
  }
  cout << "Not found\n";
}

int main() {
  vector<int> arr {15. 2. 4. 8, 9, 5, 10, 23};
  int s = 23;
  isSub(arr, s);
}
