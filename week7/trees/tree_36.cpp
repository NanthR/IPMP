// BT to sum property

#include "tree.h"

void increment(node* head) {
  if(head->left) {
    head->left->val = head->left->val + diff;
    increment(head->left, diff);
  } else if(head->right) {
    head->right->val = head->right->val + diff;
    increment(head->right, diff);
  }
}

void change(node* head) {
  int l = 0, r = 0;
  if(head == NULL || (head->left == NULL && head->right == NULL))
    return;
  change(head->left);
  change(head->right);
  if(head->left)
    l = head->left->val;
  if(head->right)
    r = head->right->val;

  int d = l + r - head->val;
  if(diff > 0)
    head->val += d;
  else if(diff < 0)
    increment(node, -diff);

}

int main() {
  node* head = quick_init();
  change(head);
}
