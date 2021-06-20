#include<iostream>

using namespace std;

class DLLNode {
public:
  DLLNode* prev;
  int val;
  DLLNode* next;

  DLLNode(int x) {
    val = x;
    prev = NULL;
    next = NULL;
  }
};

class Stack {
public:
  DLLNode* head;
  DLLNode* mid;
  size_t count; 

  Stack() {
    head = NULL;
    mid = NULL;
    count = 0;
  }
  void push(int x) {
    DLLNode* new_node = new DLLNode(x);
    new_node->next = head;
    count += 1;
    if(count == 1)
      mid = new_node;
    else {
      head->prev = new_node;
      if(count % 2 == 0)
	mid = mid->prev;
    }
    head = new_node;
  }
  
  int pop() {
    if(count == 0)
      return -1;
    DLLNode* cur = head->next;
    int removed = head->val;
    if(cur != NULL)
      cur->prev = head->prev;
    head = cur;
    count -= 1;
    if(count % 2 == 0) {
      mid = mid->next;
    }
    free(head);
    return removed;
  }

  int middle() {
    if(count == 0)
      return -1;
    return mid->val;
  }

  int remove_middle() {
    int removed = mid->val;
    mid->prev->next = mid->next;
    mid->next->prev = mid->prev->next;
    mid = mid->next;
    return removed;
  }
  
};

int main() {
  auto s = Stack();
  s.push(2);
  s.push(3);
  s.push(4);
  cout << s.remove_middle() << "\n";
  cout << s.remove_middle() << "\n";
  cout << s.remove_middle() << "\n";
  cout << s.pop() << "\n";
}
