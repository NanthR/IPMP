#include "tree.h"

bool helper(node* x, node* y) {
  if(x == NULL && y == NULL)
    return true;
  if(x == NULL || y == NULL)
    return false;
  return helper(x->left, y->right) && (helper(x->right, y->left));
}

bool is_fold(node *head) {
  if(head == NULL)
    return true;
  return helper(head->left, head->right);
}

int main() {
  node* head = quick_init();
  cout << is_fold(head);
}
