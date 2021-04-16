#include<bits/stdc++.h>

using namespace std;

int first(vector<int> &arr) {
  int l = 0, r = arr.size() - 1;
  int res = -1;
  while(l <= r) {
    int m = l + (r -l) / 2;
    if(arr[m] == 1) {
      res = m;
      r = m - 1;
    }
    else if(arr[m] < 1)
      l = m + 1;
    else
      r = m - 1;
  }
  return res;
}

int last(vector<int> &arr, int l) {
  int r = arr.size() - 1;
  int res = -1;
  while(l <= r) {
    int m = l + (r -l) / 2;
    if(arr[m] == 1) {
      res = m;
      l = m + 1;
    }
    else if(arr[m] < 1)
      l = m + 1;
    else
      r = m - 1;
  }
  return res;
}

int most_ones(vector<vector<int>> &arr) {
  int most = -1;
  int index = -1;
  for(int i = 0; i < arr.size(); i++) {
    int res;
    int left = first(arr[i]);
    if(left == -1) {
      res = 0;
    }
    else {
      int right = last(arr[i], left);
      res = right - left;
    }
    if(res > most) {
      most = res;
      index = i;
    }
  }
  return index;
}

int main() {
  vector<vector<int>> arr = {
			     {0,1,1,1},
			     {0,0,1,1},
			     {1,1,1,1},
			     {0,0,0,0},
			    };
  cout << most_ones(arr) << "\n";
}
