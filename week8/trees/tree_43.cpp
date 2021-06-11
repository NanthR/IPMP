#include "tree.h"

node* remove(node* head, int x, int y) {
  if(head == NULL)
    return NULL;
  head->left = remove(head->left, x, y);
  head->right = remove(head->right, x, y);

  if(head->val < x) {
    node* temp = head->right;
    delete head;
    return temp;
  }
  if(head->val > y) {
    node* temp = head->left;
    delete head;
    return temp;
  }
  return head;
}

int main() {
  node* head = bst_quick_init();
  head = remove(head, 30, 50);
  inorder(head);
}
