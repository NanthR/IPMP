#include "tree.h"

int height(node* head) {
  if(head == NULL)
    return 0;
  return max(height(head->left), height(head->right)) + 1;
}

int diameter(node* a) {
  if(a == NULL)
    return 0;
  int lh = height(a->left);
  int rh = height(a->right);
  int ld = diameter(a->left);
  int rd = diameter(a->right);
  return max(lh+rh+1, max(ld, rd))
}
