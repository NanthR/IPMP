#include<iostream>
#include<algorithm>

using namespace std;

bool is_anagram(string x, string y) {
  if(x.length() != y.length())
    return false;
  sort(x.begin(), x.end());
  sort(y.begin(), y.end());

  return (x == y);
}

int main() {
  string x, y;
  cin >> x >> y;
  cout << is_anagram(x, y) << "\n";
}
