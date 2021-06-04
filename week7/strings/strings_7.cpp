#include<iostream>
 
using namespace std;

int fact(int n) {
  return (n <= 1) ? 1 : n * fact(n - 1);
}
 
int smaller_right(string str, int low, int high) {
  int cr = 0, i;

  for (i = low + 1; i <= high; ++i)
    if (str[i] < str[low])
      cr++;

  return cr;
}
 
int rank_str(string str) {
  int len = str.size();
  int mul = fact(len);
  int rank = 1;
  int cr;

  for(int i = 0; i < len; ++i) {
    mul /= len - i;
    cr = smaller_right(str, i, len - 1);
    rank += cr * mul;
  }

  return rank;
}
 
int main() {
  string str = "string";
  cout << rank_str(str);
}
