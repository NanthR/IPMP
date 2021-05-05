#include "tree.h"

int height(node* head) {
  if(head == NULL)
    return 0;
  return max(height(head->left), height(head->right)) + 1;
}

int main() {
  node* head = new node(10);
  head->left = new node(20);
  head->right = new node(30);
  head->left->left = new node(40);
  head->left->right = new node(40);
  cout << height(head) << "\n";
}
