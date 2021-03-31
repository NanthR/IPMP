#include "print.h"

using namespace std;

int partition(vector<int> &arr, int left, int right) {
  int pivot = arr[right];
  int x = left - 1;
  for(int i = left; i < right; i++) {
    if(arr[i] < pivot) {
      x++;
      swap(&arr[x], &arr[i]);
    }
  }
  swap(&arr[x+1], &arr[right]);
  return x + 1;
}

void quick_sort(vector<int> &arr, int left, int right) {
  if(left < right) {
    int index = partition(arr, left, right);
    quick_sort(arr, left, index - 1);
    quick_sort(arr, index + 1, right);
  }
}

int main() {
  vector<int> arr {10, 9, 8, 7, 6};
  quick_sort(arr, 0, arr.size()-1);
  print<int>(arr);
}
