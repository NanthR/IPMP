#include "tree.h"

int diff(node* head) {
  if(head == NULL)
    return 0;
  return head->val - diff(head->left) - diff(head->right);
}

int main() {
  node *head = quick_init();
  cout << diff(head) << "\n";
}
