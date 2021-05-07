#include <iostream>
#include <bitset>
#define HASH_SIZE 128

using namespace std;

void print(int *A, int nr, int nc) {
  for(int r = 0; r < nr; r++) {
    for(int c = 0; c < nc; c++)
      cout << *(A + r*nc + c) << " ";
    cout << "\n";
  }
  cout << "\n";
}

void transpose(int *A, int r, int c) {
  int size = r*c - 1;
  int t;
  int next;
  int cycleBegin;
  int i;
  bitset<HASH_SIZE> b;

  b.reset();
  b[0] = b[size] = 1;
  i = 1;
  while (i < size) {
    cycleBegin = i;
    t = A[i];
    do {
      next = (i*r)%size;
      swap(A[next], t);
      b[i] = 1;
      i = next;
    }
    while (i != cycleBegin);

    for (i = 1; i < size && b[i]; i++);
  }
}

int main(void) {
  int r = 4, c = 5;
  int size = r*c;
  int *A = new int[size];

  for(int i = 0; i < size; i++)
    A[i] = i+1;

  print(A, r, c);
  transpose(A, r, c);
  print(A, c, r);
}
