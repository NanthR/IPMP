#include "tree.h"

void preorder(node* a) {
  if(a == NULL)
    return;
  cout << a->val << " ";
  preorder(a->left);
  preorder(a->right);
}

void postorder(node* a) {
  if(a == NULL)
    return;
  postorder(a->left);
  postorder(a->right);
  cout << a->val << " ";
}

void inorder(node* a) {
  if(a == NULL)
    return;
  inorder(a->left);
  cout << a->val << " ";
  inorder(a->right);
}

int main() {
  node *a = new node(1); 
  a->left = new node(2); 
  a->right = new node(3); 
  a->left->left = new node(4); 
  a->left->right = new node(5); 
  cout << "Pre Order\n";
  preorder(a);
  cout << "\n";
  cout << "Post Order\n";
  postorder(a);
  cout << "\n";
  cout << "In Order\n";
  inorder(a);
  cout << "\n";
}
