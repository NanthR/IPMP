#include "tree.h"
#include<queue>

int width(node* a) {
  if(a == NULL)
    return 0;
  int r = 0;
  queue<node*> q;
  q.push(a);
  while(!q.empty()) {
    int c = q.size();
    r = max(c, r);
    while(c--) {
      node* temp = q.front();
      q.pop();
      if(temp->left != NULL)
	q.push(temp->left)
      if(temp->right != NULL)
	q.push(temp->right)
    }
  }
  return r;
}
