#include<iostream>
#include<vector>
#include<sstream>
#include<algorithm>

using namespace std;

int main() {
  string x;
  getline(cin , x);
  vector<string> y;
  stringstream ss(x);
  string temp;
  while(ss >> temp) {
    y.push_back(temp);
  }
  string res = "";
  reverse(y.begin(), y.end());
  bool f = false; 
  for(auto &i: y) {
    if(f) res += " ";
    else f = true;
    res += i;
  }
  cout << res;
  cout << "\n";
}
