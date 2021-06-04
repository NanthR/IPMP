// Children sum
#include "tree.h"

bool check(node* head) {
  if(head == NULL || (head->left == NULL && head->right == NULL))
    return true;
  else {
    int l = 0, r = 0;
    if(head->left)
      l = head->left->val;
    if(head->right)
      r = head->right->val;
    return ((head->val == l + r) && check(head->left) && check(head->right));
  }
}

int main() {
  node* head = quick_init();
  cout << check(head);
}
