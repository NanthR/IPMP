// Kth smallest
#include "tree.h"

int kth(node* head) {
  if(head == NULL)
    return;
  node* l = kth(head->left, k);
  if(l)
    return l;
  k--;
  if(k == 0)
    return head;
  return kth(head->right, k);
}

int main() {
  node* head = quick_init();
  kth(head, 1);
}
