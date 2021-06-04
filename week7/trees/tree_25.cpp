#include "tree.h"

void helper(node* head, int* sum) {
  if(!head)
    return;
  helper(head->right, sum);
  *sum = *sum + head->val;
  head->val = *sum;
  helper(head->left, sum);
}

void mod(node* head) {
  int sum = 0;
  helper(head, &sum);
}

int main() {
  node* head = bst_quick_init();
  mod(head);
  inorder(head);
}
