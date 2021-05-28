#include "tree.h"

bool findPath(node *head, vector<int> &path, int k) {
  if (head == NULL) return false;
  path.push_back(head->key);

  if (head->key == k)
    return true;

  if ((head->left && findPath(head->left, path, k)) || (head->right && findPath(head->right, path, k)) )
    return true;

  path.pop_back();
  return false;
}
 
int findLCA(node *head, int n1, int n2) {
  vector<int> path1, path2;

  if(!findPath(head, path1, n1) || !findPath(head, path2, n2))
    return -1;

  int i;
  for(i = 0; i < path1.size() && i < path2.size() ; i++)
    if(path1[i] != path2[i])
      break;
  return path1[i-1];
}

int main() {
  node *head = quick_init();
}
