#include "tree.h"
#include<map>

void helper(node *head, int d, map<int, int> &m) {
  if(head == NULL)
    return;
  helper(head->left, d - 1, m);
  m[d] += head->val;
  helper(head->right, d + 1, m);
}

void vertical(node* head) {
  map<int, int> m;
  helper(head, 0, m);
  for(auto &i: m) {
    cout << i.first << ": " << i.second << "\n";
  }
}

int main() {
  node* head = quick_init();
  vertical(head);
}
