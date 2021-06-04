#include "tree.h"
 
node* minValue(node* head);
 
node* inOrderSuccessor(node* root, node* n) {
  if (n->right != NULL)
    return minValue(n->right);

  node* succ = NULL;

  while (root != NULL) {
    if (n->val < root->val) {
      succ = root;
      root = root->left;
    }
    else if (n->val > root->val)
      root = root->right;
    else
      break;
  }

  return succ;
}
 
node* minValue(node* head) {
  node* current = head;

  while (current->left != NULL) {
    current = current->left;
  }
  return current;
}
 
int main() {
  node *root = NULL, *temp, *succ, *min;

  root = insert(20, root);
  root = insert(8, root);
  root = insert(22, root);
  root = insert(4, root);
  root = insert(12, root);
  root = insert(10, root);
  root = insert(14, root);
  temp = root->left->right->right;
   
  succ = inOrderSuccessor(root, temp);
  if (succ != NULL)
    cout << "Inorder Successor of " << (temp->val) << "is " <<  (succ->val);
  else
    cout << "\n Inorder Successor doesn't exit";
}
