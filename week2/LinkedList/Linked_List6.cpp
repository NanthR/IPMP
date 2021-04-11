#include "linked_list.h"

bool detect_loop(node* head) {
  node *a, *b;
  a = b = head;
  while(a != NULL && a->next != NULL) {
    a = a->next->next;
    b = b->next;
    if(a == b)
      return true;
  }
  return false;
}

int main() {
  node* head = quick_init();
  cout << detect_loop(head) << "\n";
}
