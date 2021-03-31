#include<bits/stdc++.h>
#include "print.h"

using namespace std;

void insertion_sort(vector<int> &arr) {
  for(int i = 1; i < arr.size(); i++) {
    int j = i - 1;
    int val = arr[i];
    while(j >= 0 && val < arr[j]) {
      arr[j+1] = arr[j];
      j--;
    }
    arr[j+1] = val;
  }
}

int main() {
  vector<int> arr {12, 11, 13, 5, 6};
  insertion_sort(arr);
  print(arr);
}
