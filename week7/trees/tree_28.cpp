#include "tree.h"

bool is_leaf(node *head) {
  if(head == NULL)
    return false;
  return (head->left == NULL && head->right == NULL);
}

bool is_sum(node* head) {
  int ls, rs;
  if(head == NULL || is_leaf(head))
    return true;
  if(is_sum(head->left) && is_sum(head->right)) {
    if(head->left == NULL)
      ls = 0;
    else if(is_leaf(head->left))
      ls = head->left->val;
    else
      ls = 2 * (head->left->val);

    if(head->right == NULL)
      rs = 0;
    else if(is_leaf(head->right))
      rs = head->right->val;
    else
      rs = 2 * (head->right->val);

    return (head->val == (ls + rs));
  }
  return false;
}

int main() {
  node* head = quick_init();
  is_sum(head);
}
