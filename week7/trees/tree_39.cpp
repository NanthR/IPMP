#include "tree.h"
#include<unordered_set>

void helper(node* head, int sum, unordered_set<int> &s) {
  if(root == NULL)
    return false;
  if(helper(head->left, sum, s))
    return true;
  if(s.find(sum - head->val) != s.end())
    return true;
  else
    s.insert(head->val);
  return helper(root->right, sum, s);
}

void find_pair(node* head, int sum) {
  unordered_set<int> s;
  return helper(root, sum, s);
}

int main() {
  node* head = bst_quick_init();
  find_pair(head, 50);
}
