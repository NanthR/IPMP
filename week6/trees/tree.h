#include<iostream>

using namespace std;

class node {
  public:
    int val;
    node* left;
    node* right;
    node(int data) {
      val = data;
      left = right = NULL;
    }
};

node* quick_init() {
  node *head = new node(1);
  head->left = new node(2);
  head->right = new node(3);
  head->left->left = new node(4);
  head->left->right = new node(5);
  head->right->left = new node(6);
  head->right->right = new node(7);
  return head;
}

int height(node* head) {
  if(head == NULL)
    return 0;
  int l = height(head->left);
  int r = height(head->left);

  return (l > r) ? l + 1 : r + 1;
}
