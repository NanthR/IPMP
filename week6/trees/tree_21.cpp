#include "tree.h"

void helper(node *head, int level, int *max_level) {
  if (head == NULL) return;

  if (*max_level < level) {
      cout << head->val << " ";
      *max_level = level;
  }

  helper(head->left, level + 1, max_level);
  helper(head->right, level + 1, max_level);
}
 
void left_view(node *head) {
  int max_level = 0;
  helper(head, 1, &max_level);
}

int main() {
  node *head = quick_init();
  left_view(head);
}
