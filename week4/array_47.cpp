#include<bits/stdc++.h>

using namespace std;
 
void findMajority(vector<int> &arr) {
  int n = arr.size();
  unordered_map<int, int> m;
  for(int i = 0; i < n; i++)
    m[arr[i]]++;
  int count = 0;
  for(auto i : m) {
      if(i.second > n / 2) {
	count =1;
	cout << "Majority found :- " << i.first << "\n";
	break;
      }
  }
  if(count == 0)
    cout << "No Majority element" << "\n";
}
 
int main() {
    vector<int> arr {2, 2, 2, 2, 5, 5, 2, 3, 3};
    findMajority(arr);
}
