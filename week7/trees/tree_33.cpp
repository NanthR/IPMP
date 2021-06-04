#include "tree.h"

void mirror(node* head) {
  mirror(head->left);
  mirror(head->right);
  node* t = head->left;
  head->left = head->right;
  head->right = t;
}

int main() {
  node* head = quick_init();
  mirror(head);
  inorder(head);
}
