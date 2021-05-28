#include "tree.h"

void double_tree(node *head) {
  if(head == NULL)
    return;
  double_tree(head->left);
  double_tree(head->right);

  node* old = head->left;
  head->left = new node(head->val);
  head->left->left = old;
}

int main() {
  node* head = quick_init();
  double_tree(head);
}
