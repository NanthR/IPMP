#include "tree.h"
#include<stack>

void ancestor(node *root, int key) {
  if (root == NULL) return;

  stack<node*> st;

  while (1) {
    while (root && root->val != key) {
      st.push(root);
      root = root->left;
    }

    if (root && root->val == key)
      break;

    if (st.top()->right == NULL) {
      root = st.top();
      st.pop();

      while (!st.empty() && st.top()->right == root) {
	root = st.top();
	st.pop();
       }
    }

    root = st.empty()? NULL: st.top()->right;
  }

  while (!st.empty()) {
    cout<<st.top()->val<<" ";
    st.pop();
  }
}

int main() {
  node* head = quick_init();
  ancestor(head, 4);
}
