#include "tree.h"

bool is_leaf(node *head) {
  if(head == NULL)
    return false;
  return (head->left == NULL && head->right == NULL);
}

void sum_tree(node* head) {
  if(head == NULL || is_leaf(head))
    return;
  sum_tree(head->left);
  sum_tree(head->right);
  int ls = 0, rs = 0;

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

  head->val = ls + rs;
}

int main() {
  node* head = quick_init();
  sum_tree(head);
}
