#include<iostream>
#include<vector>
#include<utility>

using namespace std;

void print(vector<int> &arr) {
  for(auto it = arr.begin(); it != arr.end(); it++)
    cout << *it << " ";
  cout << "\n";
}

pair<int, int> min_max(vector<int> &arr) {
  int min, max, i;
  if(arr.size() % 2 != 0) {
    min = max = arr[0];
    i = 1;
  } 
  else {
    int x = arr[0], y = arr[1];
    if(x > y) {
      max = x;
      min = y;
    }
    else {
      max = y;
      min = x;
    }
    i = 2;
  }
  while(i < arr.size() - 1) {
    int m, n;
    if(arr[i] > arr[i+1]) {
      m = i;
      n = i+1;
    }
    else {
      m = i+1;
      n = i;
    }
    if(arr[m] > max)
      max = arr[m];
    if(arr[n] < min)
      min = arr[n];
    i++;
  }
  return make_pair(min, max);
}

int main() {
  vector<int> arr {1000, 11, 445, 1, 330, 3000};
  auto res = min_max(arr);
  cout << "Min: " << res.first << "\nMax: " << res.second << "\n";
}
