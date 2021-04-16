#include "linked_list.h"

void pair_swap(node* a) {
  node *temp = a;
  while(temp != NULL & temp->next != NULL) {
    int val = temp->val;
    temp->val = temp->next->val;
    temp->next->val = val;
    temp = temp->next->next;
  }
}

int main() {
  node* a = quick_init();
  pair_swap(a);
  display(a);
}
