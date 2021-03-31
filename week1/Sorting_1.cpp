#include "print.h"

void merge_sort(vector<int> &arr) {
  if(arr.size() > 1) {
    int n = arr.size();
    int mid = n / 2;
    vector<int>left, right;
    for(int i = 0; i < mid; i++)
      left.push_back(arr[i]);
    for(int i = mid; i < n; i++)
      right.push_back(arr[i]);
    merge_sort(left);
    merge_sort(right);
    int i, j, k;
    i = j = k = 0;
    while(i < left.size() && j < right.size()) {
      if(left[i] > right[j]) {
	arr[k] = right[j];
	j++;
      }
      else {
	arr[k] = left[i];
	i++;
      }
      k++;
    }
    while(i < left.size()) {
      arr[k] = left[i];
      i++;
      k++;
    }
    while(j < right.size()) {
      arr[k] = right[j];
      j++;
      k++;
    }
  }
}

int main() {
  vector<int> arr {5, 4, 10, 12, 1};
  merge_sort(arr);
  print<int>(arr);
}
