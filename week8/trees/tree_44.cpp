#include "tree.h"

node *pruneUtil(node *root, int k, int *sum) {
  if (root == NULL)  return NULL;

  int lsum = *sum + (root->val);
  int rsum = lsum;

  root->left = pruneUtil(root->left, k, &lsum);
  root->right = pruneUtil(root->right, k, &rsum);

  *sum = max(lsum, rsum);

  if (*sum < k) {
      free(root);
      root = NULL;
  }

  return root;
}
  
node *prune(node *root, int k) {
  int sum = 0;
  return pruneUtil(root, k, &sum);
}

int main() {
  node* head = bst_quick_init();
  node* res = prune(head, 40);
}
