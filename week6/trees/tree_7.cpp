#include<iostream>
using namespace std;


class node {
public:
  int val;
  node* left;
  node* right;
  node* next;

  node(int data) {
    val = data;
    left = right = next = NULL;
  }
};

void helper(node* head, node **next);

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
void populate(node *head) {
  node *next = NULL;
  helper(head, &next);
}
 
void helper(node* head, node **next_ref) {
  if (head) {
    helper(head->right, next_ref);
    head->next = *next_ref;
    *next_ref = head;
    helper(head->left, next_ref);
  }
}

int main() {
  node* head = quick_init();
  populate(head);
}
