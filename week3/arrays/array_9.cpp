#include<bits/stdc++.h>

using namespace std;

vector<int> squares(int n) {
  vector<int> all_squares;
  int c = 1, i = 1;
  while(c <= n) {
    all_squares.push_back(c);
    i++;
    c = pow(i, 2);
  }
  return all_squares;
}

void findall_squares(int n) {
  vector<int> all_squares = squares(pow(n, 2));
  int count = 0;
  for(int a = 1; a <= n; a++) {
    int aSquare = pow(a, 2);
    for(int i = 0; i < all_squares.size(); i++) {
      int cSquare = all_squares[i];
      int bSquare = abs(cSquare - aSquare);
      int b = sqrt(bSquare);
      int c = sqrt(cSquare);
 
      if (c < a || (find(all_squares.begin(), all_squares.end(), bSquare) == all_squares.end()))
        continue;
 
      if ((b >= a) && (b <= c) && (aSquare + bSquare == cSquare))
        count++;
    }
  }
  cout << count << "\n";
}

int main() {
  int n = 10;
  findall_squares(n);
}
