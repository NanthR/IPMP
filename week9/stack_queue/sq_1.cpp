#include<iostream>
#include<vector>
#include<stdlib.h>

using namespace std;

class two_stacks {
  vector<int> arr;
  int size;
  int t1, t2;
  public:
    two_stacks(int n) {
      size = n;
      arr = vector<int>(size, 0);
      t1 = -1;
      t2 = size;
    }
    void push1(int x) {
      if(t1 < t2 - 1) {
        t1++;
        arr[t1] = x;
      } else {
        cout << "Overflow\n";
      }
    }

    void push2(int x) {
      if(t1 < t2 - 1) {
        t2--;
        arr[t2] = x;
      } else {
        cout << "Overflow\n";
      }
    }

    int pop1() {
      if(t1 >= 0) {
        int t = arr[t1];
        t1--;
        return t;
      } else {
        cout << "Underflow\n";
        exit(1);
      }
    }

    int pop2() {
      if(t2 < size) {
        int t = arr[t2];
        t1++;
        return t;
      } else {
        cout << "Underflow\n";
        exit(1);
      }
    }
};

int main() {
  return 0;
}
