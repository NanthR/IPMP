#include "tree.h"

bool check(node* head) {
  if(head == NULL)
    return true;
  int val = head->val;
  return ((!(head->left) || (val >= head->left->val)) && (!(head->right) || (val < head->right->val)) && check(head->left) && check(head->right));
}

int main() {
  node* head1 = quick_init();
  node* head2 = bst_quick_init();
  cout << check(head1) << " " << check(head2) << "\n";
}
