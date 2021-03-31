#include "print.h"

using namespace std;

void count_sort(vector<int> &arr) {
  vector<int> count(255, 0);
  vector<int>output(arr.size());
  for(int i = 0; i < arr.size(); i++)
    count[arr[i]]++;
  for(int i = 1; i < 256; i++)
    count[i] += count[i-1];
  for(int i = 0; i < arr.size(); i++) {
    output[count[arr[i]] - 1] = arr[i];
    count[arr[i]]--;
  }
  print(output);
}

int main() {
  vector<int> arr = {1, 1, 2, 4, 5, 6};
  count_sort(arr);
}
