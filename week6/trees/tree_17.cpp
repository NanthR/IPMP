#include "tree.h"

void print_leaves(struct node* head) {
  if (head == NULL)
    return;

  print_leaves(head->left);

  if (!(head->left) && !(head->right))
    cout << head->val << " ";

  print_leaves(head->right);
}
  
void print_left(struct node* head) {
  if (head == NULL)
    return;

  if (head->left) {
    cout << head->val << " ";
    print_left(head->left);
  } else if (head->right) {
    cout << head->val << " ";
    print_left(head->right);
  }
}
  
void print_right(struct node* head) {
  if (head == NULL)
    return;

  if (head->right) {
    print_right(head->right);
    cout << head->val << " ";
  } else if (head->left) {
    print_right(head->left);
    cout << head->val << " ";
  }
}
  
void print(node* head) {
  if (head == NULL)
    return;

  cout << head->val << " ";

  print_left(head->left);
  print_leaves(head->left);
  print_leaves(head->right);
  print_right(head->right);
}

int main() {
  node *head = quick_init();
  print(head);
  cout << "\n";
}
