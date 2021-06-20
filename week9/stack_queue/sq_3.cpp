#include<iostream>
#include<stack>

using namespace std;

class Queue {
  stack<int> s1, s2;
  size_t cur_size;
  public: 
    Queue() {
      cur_size = 0;
    }

    void enqueue(int x) {
      while(!s1.empty()) {
	s2.push(s1.top());
	s1.pop();
      }
      s1.push(x);
      while(!s2.empty()) {
	s1.push(s2.top());
	s2.pop();
      }
    }

    int dequeue() {
      if(s1.empty()) {
	return -1;
      }
      int x = s1.top();
      s1.pop();
      return x;
    }
};

int main() {
  return 0;
}
