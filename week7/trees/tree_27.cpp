#include "tree.h"

node* lca(node* head, int x, int y) {
  if(head == NULL)
    return NULL;
  int v = head->val;
  if(v > x && v > y)
    return lca(head->left, x, y);
  if(v < x && v < y)
    return lca(head->right, x, y);
  return head;
}

int main() {
  node* head = bst_quick_init();
  node* res = lca(head, 60, 80);
  if(res != NULL)
    cout << res->val;
}
