#include "tree.h"

void range(node* head, int x, int y) {
  if(head == NULL)
    return;
  int v = head->val;
  if(x < v)
    range(head->left, x, y);
  if(x <= v && y >= v)
    cout << v << " ";
  if(y > v)
    range(head->right, x, y);
}

int main() {
  node* head = bst_quick_init();
  range(head, 20, 50);
  cout << "\n";
}
