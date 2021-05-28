#include "tree.h"

void print(node* head, int i) {
  if(head == NULL)
    return;
  if(i == 0)
    cout << head->val << " ";
  else {
    print(head->left, i - 1);
    print(head->right, i - 1);
  }
}

void level(node *head) {
  int h = height(head);
  for(int i = h - 1; i >= 0; i--)
    print(head, i);
}

int main() {
  node *head = quick_init();
  level(head);
  cout << "\n";
}
