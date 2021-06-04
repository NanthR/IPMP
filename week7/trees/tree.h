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

node* insert(int val, node* head) {
  if(!head)
    return (new node(val));
  else {
    if(val <= head->val) {
      head->left = insert(val, head->left);
    } else {
      head->right = insert(val, head->right);
    }
    return head;
  }
}

void inorder(node* head) {
  if(!head)
    return;
  inorder(head->left);
  cout << head->val << " ";
  inorder(head->right);
}

node* bst_quick_init() {
  node* root = NULL;
  /* root = insert(4, root); */
  /* insert(2, root); */
  /* insert(1, root); */
  /* insert(3, root); */
  /* insert(6, root); */
  /* insert(5, root); */
  root = insert(50, root);
  insert(30, root);
  insert(70, root);
  insert(20, root);
  insert(40, root);
  insert(60, root);
  insert(80, root);
  return root;
}

int height(node* head) {
  if(head == NULL)
    return 0;
  int l = height(head->left);
  int r = height(head->left);

  return (l > r) ? l + 1 : r + 1;
}
