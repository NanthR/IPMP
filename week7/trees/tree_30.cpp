#include "tree.h"

bool bal(node* head, int* h) {
  int lh, rh = 0;
  bool l = false, r = false;
  if(root == NULL) {
    *height = 0;
    return true;
  }

  l = bal(head->left, &lh);
  r = bal(head->right, &rh);

  *h = (lh > rh ? lh: rh) + 1;
  if(abs(lh - rh) > 1)
    return false;
  else
    return l && r;

}

int main() {
  node* head = quick_init();
  int c = 0;
  cout << bal(head, &c) << "\n";
}
