#include<bits/stdc++.h>
#include "tree.h"

void zizagtraversal(node* root) {
  if (!root)
      return;

  stack<node*> currentlevel;
  stack<node*> nextlevel;

  currentlevel.push(root);

  bool lefttoright = true;
  while (!currentlevel.empty()) {

    node* temp = currentlevel.top();
    currentlevel.pop();

    if (temp) {

      cout << temp->val << " ";

      if (lefttoright) {
	if (temp->left)
	  nextlevel.push(temp->left);
	if (temp->right)
	  nextlevel.push(temp->right);
      }
      else {
	if (temp->right)
	  nextlevel.push(temp->right);
	if (temp->left)
	  nextlevel.push(temp->left);
      }
    }

    if (currentlevel.empty()) {
      lefttoright = !lefttoright;
      swap(currentlevel, nextlevel);
    }
  }
}

int main() {
  node *head = quick_init();
  zizagtraversal(head);
}
