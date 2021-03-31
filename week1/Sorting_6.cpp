#include "print.h"

void heapify(vector<int> &arr, int n, int i) {
  int a = i;
  int left = 2 * i + 1;
  int right = 2 * i + 2;
  if(left < n && arr[left] > arr[a])
    a = left;
  if(right < n && arr[right] > arr[a])
    a = right;
  if(a != i) {
    swap(arr[i], arr[a]);
    heapify(arr, n, a);
  }
}

void heap_sort(vector<int> &arr) {
  int n = arr.size();
  for(int i = n / 2 - 1; i >= 0; i--)
    heapify(arr, n, i);
  for(int i = n - 1; i > 0; i--) {
    swap<int>(arr[0], arr[i]);
    heapify(arr, i, 0);
  }
}

int main() {
  vector<int> arr {5, 4, 3, 2, 1};
  heap_sort(arr);
  print<int>(arr);
}
