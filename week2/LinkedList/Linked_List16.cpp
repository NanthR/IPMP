#include "linked_list.h"

node* merge(node* a, node* b) {
  if(a == NULL)
    return b;
  if(b == NULL)
    return a;
  node* dummy = new node(-1);
  node* prev = dummy;
  node* t1 = a;
  node* t2 = b;
  while(t1 && t2) {
    if(t1->val < t2->val) {
      prev->next = t1;
      t1 = t1->next;
    }
    else {
      prev->next = t2;
      t2 = t2->next;
    }
    prev = prev->next;
  }
  prev->next = t1 != NULL ? t1 : t2;
  return dummy->next;
}

int main() {
  node* a = init();
  node* b = init();
  node* comb = merge(a, b);
  display(comb);
}
