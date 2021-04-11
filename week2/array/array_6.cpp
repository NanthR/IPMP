#include<iostream>

using namespace std;

bool all_nine(int arr[], int n) {
  for(int i = 0; i < n; i++) {
    if(arr[i] != 9)
      return false;
  }
  return true;
}

void next_palin(int arr[], int n) {
  if(all_nine(arr, n)) {
    cout << "1";
    for(int i = 1; i < n; i++)
      cout << "0";
    cout << "1\n";
    return;
  }
  int mid = n / 2;
  bool isLeft = false;
  int i = mid - 1;
  int j = (n % 2) ? mid + 1 : mid;
  while(i >= 0 && arr[i] == arr[j]) {
    i--;
    j++;
  }
  if(i < 0 || arr[i] < arr[j])
    isLeft = true;
  while(i >= 0) {
    arr[j] = arr[i];
    j++;
    i--;
  }
  if(isLeft) {
    int carry = 1;
    i = mid - 1;
    if(n % 2 == 1) {
      arr[mid] += carry;
      carry = arr[mid] / 10;
      arr[mid] %= 10;
      j = mid + 1;
    }
    else
      j = mid;

    while(i >= 0) {
      arr[i] += carry;
      carry = arr[i] / 10;
      arr[i] %= 10;
      arr[j] = arr[i];
      j++;
      i--;
    }
  }
  for(int i = 0; i < n; i++)
    cout << arr[i];
  cout << "\n";
}

int main() {
  int arr[] = {9, 9, 9, 9};
  int n = sizeof(arr) / sizeof(arr[0]);
  next_palin(arr, n);
  int barr[] = {1, 2, 3, 4, 5, 6, 7, 8};
  int bn = sizeof(barr) / sizeof(barr[0]);
  next_palin(barr, bn);
}
