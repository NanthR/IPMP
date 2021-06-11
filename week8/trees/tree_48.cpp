#include "tree.h"

bool ancestor(node *root, int target) {
  if (root == NULL)
     return false;
  
  if (root->val == target)
     return true;
  
  if (ancestor(root->left, target) || ancestor(root->right, target)) {
    cout << root->val << " ";
    return true;
  }
  
  return false;
}

int main() {
  node* head = quick_init();
  ancestor(head, 4);
}
