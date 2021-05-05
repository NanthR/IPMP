#include "tree.h"

int size(node* head) {
  if(head == NULL)
    return 0;
  return (size(head->left) + 1 + size(head->right));
}

int main() {
  node* head = new node(10);
  head->left = new node(20);
  head->right = new node(30);
  head->left->left = new node(40);
  head->left->right = new node(40);
  cout << size(head) << "\n";
}
