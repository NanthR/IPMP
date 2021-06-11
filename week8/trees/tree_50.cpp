#include "tree.h"

node* helper(node* head) {
  if (head == NULL)
      return head;

  if (head->left != NULL) {
    node* left = helper(head->left);
    for (; left->right != NULL; left = left->right)
    
    left->right = head;
    head->left = left;
  }

  
  if (head->right != NULL) {
    node* right = helper(head->right);
    for (; right->left != NULL; right = right->left)
    
    right->left = head;
    head->right = right;
  }

  return head;
}

node* bst_to_dll(node* head) {
  if (head == NULL)
    return head;

  head = helper(head);

  while (head->left != NULL)
    head = head->left;

  return (head);
}

int main() {
  node *head = bst_quick_init();
  bst_to_dll(head);
}
