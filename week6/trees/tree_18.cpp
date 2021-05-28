// Leaf nodes
#include "tree.h"

int num(node* head) {
  if(head == NULL)
    return 0;
  if(head->left == NULL && head->right == NULL)
    return 1;
  return num(head->left) + num(head->right);
}

int main() {
  node *head = quick_init();
  cout << num(head) << "\n";
}
