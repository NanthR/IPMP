#include<iostream>
#include<vector>

using namespace std;

void print(vector<int> &arr) {
  for(auto it = arr.begin(); it != arr.end(); it++)
    cout << *it << " ";
  cout << "\n";
}

vector<int> segregate(vector<int> &arr) {
  int a, b, c;
  a = b = c = 0;
  vector<int> res;
  for(auto it = arr.begin(); it != arr.end(); it++) {
    if(*it == 0)
      res.push_back(0);
    else if(*it == 1)
      b++;
    else
      c++;
  }
  while(b > 0) {
    res.push_back(1);
    b--;
  }
  while(c > 0) {
    res.push_back(2);
    c--;
  }
  return res;
}

int main() {
  vector<int> arr {0, 1, 1, 0, 1, 2, 1, 2, 0, 0, 0, 1};
  vector<int> res = (segregate(arr));
  print(res);
}
