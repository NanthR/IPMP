#include<iostream>

using namespace std;

void print_all(string x, int l, int r) {
  if(l == r)
    cout << x << "\n";
  else {
    for(int i = 1; i <= r; i++) {
      swap(x[l], x[i]);
      print_all(x, l + 1, r);
      swap(x[l], x[i]);
    }
  }

}

int main() {
  string x = "ABC";
  print_all(x, 0, x.size() - 1);
}
