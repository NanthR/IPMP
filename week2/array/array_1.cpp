#include<bits/stdc++.h>

using namespace std;

void intersection(int arr1[], int arr2[], int n1, int n2) {
  unordered_set<int> ans;
  int i = 0, j = 0;
  while(i < n1 && j < n2) {
    if(arr1[i] < arr2[j])
      i++;
    else if(arr1[i] > arr2[j]) {
      j++;
    }
    else {
      if(ans.find(arr1[i]) == ans.end()) {
	ans.insert(arr1[i]);
      }
      i++;
      j++;
    }
  }
  for(typeof(ans.begin()) itr = ans.begin(); itr != ans.end(); itr++)
    cout << *itr << " ";
  cout << "\n";
}

void Union(int arr1[], int arr2[], int n1, int n2) {
  unordered_set<int> ans;
  for(int i = 0; i < n1; i++) {
    if(i == n1 -1 || arr1[i] != arr1[i+1])
      ans.insert(arr1[i]);
  }
  for(int i = 0; i < n2; i++) {
    if((i == n2-1 || arr2[i] != arr2[i+1]) && ans.find(arr2[i]) == ans.end())
      ans.insert(arr2[i]);
  }
  for(typeof(ans.begin()) itr = ans.begin(); itr != ans.end(); itr++)
    cout << *itr << " ";
  cout << "\n";
}

int main() {
  int arr1[] = {1, 2, 2, 2, 3};
  int arr2[] = {2, 3, 4, 5};
  int n1 = sizeof(arr1) / sizeof(arr1[0]);
  int n2 = sizeof(arr2) / sizeof(arr2[0]);
  vector<int> ans;
  if(n1 < n2) {
    intersection(arr1, arr2, n1, n2);
  } else {
    intersection(arr2, arr1, n2, n1);
  }
  Union(arr1, arr2, n1, n2);
}
