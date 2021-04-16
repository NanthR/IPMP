#include<vector>
#include<iostream>
#include<climits>

using namespace std;

void find_seq(vector<int> &arr) {
  if(arr.size() < 3) {
    cout << "Less than 3\n";
    return;
  }
  int found = 1;
  int min = arr[0];
  int max_found = INT_MIN;
  int x = min;
  for(int i = 1; i < arr.size(); i++) {
    if(arr[i] == min)
      continue;
    else if(arr[i] < min)
      min = arr[i];
    else if(arr[i] < max_found) {
      max_found = arr[i];
      x = min;
    }
    else if(arr[i] > max_found) {
      found++;
      if(found == 3) {
	cout << x << " " << max_found << " " << arr[i] << "\n";
	return;
      }
      max_found = arr[i];
    }
  }
  cout << "No triplets\n";
}

int main() {
  vector<int> arr {1, 2, -1, 7, 5};
  find_seq(arr);
}
