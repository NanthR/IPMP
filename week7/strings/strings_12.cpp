#include<iostream>
#include<set>

using namespace std;

string remove(string x, string y) {
  string res;
  set<char> rem (y.begin(), y.end());
  for(auto i: x) {
    if(rem.find(i) == rem.end())
      res.push_back(i);
  }
  return res;
}

int main() {
  string x, y;
  cin >> x >> y;
  cout << remove(x, y) << "\n";
}
