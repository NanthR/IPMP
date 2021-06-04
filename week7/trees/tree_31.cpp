#include "tree.h"
#include<queue>

bool is_com(node* head) {
  if(head == NULL)
    return true;

  queue<node*> q;
  q.push(root);

  bool f = false;

  while(!q.empty()) {
    node *t = q.front();
    q.pop();

    if(t->left) {
      if(f == true)
	return false;
      q.push(t->left);
    } else {
      f = true;
    }

    if(t->right) {
      if(f == true)
	return false;
      q.push(t->right);
    } else {
      f = true;
    }
  }
  return true;
}

int main() {
  node* head = quick_init();
  is_com(head);
}
