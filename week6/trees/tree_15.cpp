#include "tree.h"

void delete_tree(node* head) {
  if(head == NULL) return;
  delete_tree(head->left);
  delete_tree(head->right);
  delete head;
}

int main() {
  node *head = quick_init();
  delete_tree(head);
  head = NULL;
}
