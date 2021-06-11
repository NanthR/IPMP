#include "tree.h"
#include<climits>

bool path(node* head, node* target_leaf) {
  if (head == NULL)
    return false;

  if (head == target_leaf || path(head->left, target_leaf) || path(head->right, target_leaf)) {
    cout << head->val << " ";
    return true;
  }

  return false;
}
  
void get_leaf(node* head, int* max_sum_ref, int curr_sum, node** target_leaf_ref) {
  if (head == NULL)
    return;

  curr_sum = curr_sum + head->val;

  if (head->left == NULL && head->right == NULL) {
    if (curr_sum > *max_sum_ref) {
      *max_sum_ref = curr_sum;
      *target_leaf_ref = head;
    }
  }

  get_leaf(head->left, max_sum_ref, curr_sum, target_leaf_ref);
  get_leaf(head->right, max_sum_ref, curr_sum, target_leaf_ref);
}
  
int max_sum(node* head) {
  if (head == NULL)
    return 0;

  node* target_leaf;
  int max_sum = INT_MIN;

  get_leaf(head, &max_sum, 0, &target_leaf);
  path(head, target_leaf);

  return max_sum;
}

int main() {
  node* head = quick_init();
  cout << max_sum(head) << "\n";
}
