#include "linked_list.h"

void reverse(node* &head) {
  node *prev, *cur, *next;
  prev = NULL;
  cur = head;
  next = NULL;
  while(cur != NULL) {
    next = cur->next;
    cur->next = prev;
    prev = cur;
    cur = next;
  }
  head = prev;
}

int main() {
  node* head = quick_init();
  reverse(head);
  display(head);
}
