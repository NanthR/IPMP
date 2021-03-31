#include<bits/stdc++.h>

using namespace std;

void bubble_sort(vector<int>&arr) {
  for(int i = 0; i < arr.size(); i++) {
    for(int j = i + 1; j < arr.size(); j++) {
      if(arr[i] > arr[j]) {
	int temp = arr[i];
	arr[i] = arr[j];
	arr[j] = temp;
      }
    }
  }
}

int main() {
  vector<int> arr {6, 5, 4, 3, 2, 1};
  bubble_sort(arr);
  for(vector<int>::iterator it = arr.begin(); it != arr.end(); it++)
    cout << *it << " ";
  cout << "\n";
}
