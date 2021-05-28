#include "tree.h"
#include<queue>
#include<climits>

bool check(node* head) {
  if(head == NULL)
    return true;

  queue<node*> q;
  q.push(head);

  int result = INT_MAX;
  int level = 0;

  while(!q.empty()) {
    int size = q.size();
    level++;

    while(size > 0) {
      node* temp = q.front();
      q.pop();

      if(temp->left) {
	q.push(temp->left);
	if(temp->left->right == NULL && temp->left->left == NULL) {
	  if(result == INT_MAX)
	    result = level;
	  else if(result != level)
	    return false;
	}
      }
      if(temp->right) {
	q.push(temp->right);
	if(temp->right->right == NULL && temp->right->left == NULL) {
	  if(result == INT_MAX)
	    result = level;
	  else if(result != level)
	    return false;
	}
      }
      size -= 1;
    }
  }
  return true;
}

int main() {
  node* head = quick_init();
  cout << check(head) << "\n";
}
