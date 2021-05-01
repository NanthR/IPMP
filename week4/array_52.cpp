#include<iostream>
#include<vector>

using namespace std;
 
void printLeaders(vector<int> &arr) {
  int n = arr.size();
  for (int i = 0; i < n; i++) {
    int j;
    for (j = i+1; j < n; j++) {
      if (arr[i] < arr[j])
	break;
    }   
    if (j == n)
      cout << arr[i] << " ";
  }
}
 
int main() {
  vector<int> arr {16, 17, 4, 3, 5, 2};
  printLeaders(arr);
}
