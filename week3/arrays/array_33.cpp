#include<bits/stdc++.h>

using namespace std;

void swap(vector<char> arr) {
  vector<char> a1, a2;
  for(int i = 0; i < arr.size(); i+= 2) {
    a1.push_back(arr[i]);
    a2.push_back(arr[i+1]);
  } 
  cout << string(a1.begin(), a1.end()) << string(a2.begin(), a2.end());
}

int main() {
  vector<char> arr = {'a', '1', 'b', '2', 'c', '3', 'd', '4'};
  swap(arr);
}
