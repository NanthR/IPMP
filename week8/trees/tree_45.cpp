#include "tree.h"

void helper(node* node, int path[], int pathLen);

void print_arr(int ints[], int len) {
  for(int i = 0; i < len; i++) {
    cout << ints[i] << " ";
  }
  cout << "\n";
}

 
void paths(node* node) {
  int path[1000];
  helper(node, path, 0);
}
 
void helper(node* node, int path[], int pathLen) {
  if (node == NULL)
    return;
   
  path[pathLen] = node->val;
  pathLen++;
   
  if (node->left == NULL && node->right == NULL) {
    print_arr(path, pathLen);
  }
  else {
    helper(node->left, path, pathLen);
    helper(node->right, path, pathLen);
  }
}
