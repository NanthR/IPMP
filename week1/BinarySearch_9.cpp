#include<bits/stdc++.h>

using namespace std;
 
#define NA -1
 
void moveToEnd(vector<int> &a, int size) {
 int j = size - 1;
 for (int i = size - 1; i >= 0; i--)
   if (a[i] != NA) {
    a[j] = a[i];
    j--;
   }
}
 
int merge(vector<int> &a, vector<int> &b, int m, int n) {
  int i = n;
  int j = 0;
  int k = 0;
  while (k < (m + n)) {
    if ((j == n)||(i < (m + n) && a[i] <= b[j])) {
      a[k] = a[i];
      k++;
      i++;
   }
   else {
     a[k] = b[j];
     k++;
     j++;
   }
  }
}
 
int main() {
  vector<int> a {2, 8, NA, NA, NA, 13, NA, 15, 20};
  vector<int> b {5, 7, 9, 25};
    
  int n = b.size();
  int m = a.size() - n;

  moveToEnd(a, m + n);
 
  merge(a, b, m, n);
 
  for(typeof(a.begin()) it = a.begin(); it != a.end(); it++)
    cout << *it << " ";
  cout << "\n";
}
