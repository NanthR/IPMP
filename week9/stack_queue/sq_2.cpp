#include<iostream>
#include<queue>

using namespace std;

class Stack {
  queue<int> q1, q2;
  size_t cur_size;

  public:
    Stack() {
      cur_size = 0;
    }
    void push(int x) {
      cur_size++;
      q2.push(x);
      while(!q2.empty()) {
	q2.push(q1.front());
	q1.pop();
      }
      queue<int> temp = q1;
      q1 = q2;
      q2 = temp;
    }
    void pop(int x) {
      if(q1.empty())
	return;
      q1.pop();
      cur_size--;
    }
    int top() {
      if(q1.empty()) {
	return -1;
      }
      return q1.front();
    }
};

int main() {
  return 0;
}
