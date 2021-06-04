#include "tree.h"

int search_min(node* head) {
  node* cur = head;
  while(cur->left)
    cur = cur->left;
  return cur->val;
}

int main() {
  node* head = bst_quick_init();
  cout << search_min(head) << "\n";
}
