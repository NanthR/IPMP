#include <bits/stdc++.h>
#include <cinttypes>

using namespace std;

class node {
public:
  int val;
  node* npx;
};

node* XOR (node *a, node *b) {
  return reinterpret_cast<node *>( reinterpret_cast<uintptr_t>(a) ^ reinterpret_cast<uintptr_t>(b));
}

void insert(node **head_ref, int val) {
  node *new_node = new node();
  new_node->val = val;
  new_node->npx = *head_ref;

  if (*head_ref != NULL) {
    (*head_ref)->npx = XOR(new_node, (*head_ref)->npx);
  }
  *head_ref = new_node;
}

void display (node *head) {
  node *curr = head;
  node *prev = NULL;
  node *next;

  cout << "Following are the nodes of Linked List: \n";

  while (curr != NULL) {
    cout << curr->val << " ";
    next = XOR (prev, curr->npx);
    prev = curr;
    curr = next;
  }
  cout << "\n";
}

int main () {
  node *head = NULL;
  insert(&head, 10);
  insert(&head, 20);
  insert(&head, 30);
  insert(&head, 40);

  display (head);
}
