#include "tree.h"

void helper(node* head, int* s) {
  if(head == NULL)
    return;
  helper(head->right, s);
  *s += head->val;
  head->val = *s;
  helper(head->left, s);
}

void add(node* head) {
  int s = 0;
  helper(head, &sum);
}

int main() {
  node* head = quick_init();
  add(head);
}
