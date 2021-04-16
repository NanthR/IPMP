#include<bits/stdc++.h>

using namespace std;

void swap (int *a, int *b) { 
  int temp = *a; 
  *a = *b; 
  *b = temp; 
}

void shuffle(vector<int> &arr) {
  srand(time(NULL));
  for(int i = arr.size() - 1; i > 0; i--) {
    int j = rand() % (i+1);
    swap(&arr[i], &arr[j]);
  }
}

int main() {
  vector<int> arr {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
  shuffle(arr);
  for(auto it: arr) {
    cout << it << " ";
  }
  cout << "\n";
}
