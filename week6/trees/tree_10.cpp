#include "tree.h"

void print(node* head, int i, bool f) {
  if(head == NULL)
    return;
  if(i == 0)
    cout << head->val << " ";
  else {
    if(f) {
      print(head->left, i - 1, f);
      print(head->right, i - 1, f);
    } else {
      print(head->right, i - 1, f);
      print(head->left, i - 1, f);
    }
  }
}

void level(node *head) {
  int h = height(head);
  bool f = true;
  for(int i = 0; i < h; i++) {
    print(head, i, f);
    f != f;
  }
}

int main() {
  node *head = quick_init();
  level(head);
  cout << "\n";
}
