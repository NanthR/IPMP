#include "linked_list.h"

node* intersect(node *a, node *b) {
  node *dummy = new node(-1);
  node *temp = dummy;
  while(a && b) {
    if(a->val == b->val) {
      temp->next = a;
      a = a->next;
      b = b->next;
      temp = temp->next;
    }
    else if(a->val < b->val)
      a = a->next;
    else
      b = b->next;
  }
  temp->next = NULL;
  return dummy->next;
}

int main() {
  node* a = quick_init();
  node* b = quick_init();
  node* combined = intersect(a, b);
  display(combined);
}
