#include<bits/stdc++.h>

using namespace std;

float find_water(int i, int j, float X) {
  if (j > i) {
    return -1;
  }

  vector<float> glass(i * (i + 1) / 2, 0);

  int index = 0;
  glass[index] = X;

  for (int row = 1; row <= i ; ++row) {
    for (int col = 1; col <= row; ++col, ++index) {
      X = glass[index];

      glass[index] = (X >= 1.0f) ? 1.0f : X;
      X = (X >= 1.0f) ? (X - 1) : 0.0f;

      glass[index + row] += X / 2;
      glass[index + row + 1] += X / 2;
    }
  }

  return glass[i*(i-1)/2 + j - 1];
}

int main() {
  int i = 2, j = 2;
  float X = 2.0;

  float res = find_water(i, j, X);
  if(res != -1)
    cout << res << "\n";
}
