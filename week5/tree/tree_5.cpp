#include "tree.h"

bool identical(node* a, node* b) {
  if(a == NULL && b == NULL)
    return true;
  if(a != NULL && b != NULL)
    return (a->val == b->val && identical(a->left, b->left) && identical(a->right, b->right));
  return false;
}

int main() {
  node *a = new node(1); 
  a->left = new node(2); 
  a->right = new node(3); 
  a->left->left = new node(4); 
  a->left->right = new node(5); 
  

  node *b = new node(1); 
  b->left = new node(2); 
  b->right = new node(3); 
  b->left->left = new node(4); 
  b->left->right = new node(5); 
  
  cout << identical(a, b) << "\n";
}
