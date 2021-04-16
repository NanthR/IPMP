#include<iostream>
#include <stdlib.h>

using namespace std;

typedef struct node {
	int val;
	struct node *right;
	struct node *down;
} node;

void push (node** head_ref, int new_data) {
  node* new_node = (node *) malloc(sizeof(node));
  new_node->right = NULL;

  new_node->val = new_data;

  new_node->down = (*head_ref);

  (*head_ref) = new_node;
}

void display(node *node) {
  while (node != NULL) {
    cout << node->val << " ";
    node = node->down;
  }
  cout << "\n";
}

node* merge( node* a, node* b ) {
  if(a == NULL)
    return b;

  if(b == NULL)
    return a;

  node* result;
  if (a->val < b->val) {
    result = a;
    result->down = merge( a->down, b );
  }
  else {
    result = b;
    result->down = merge( a, b->down );
  }

  result->right = NULL;
  return result;
}

node* flatten (node* root) {
	if (root == NULL || root->right == NULL)
		return root;

	return merge( root, flatten(root->right) );
}

int main() {
	node* root = NULL;

	push( &root, 30 );
	push( &root, 8 );
	push( &root, 7 );
	push( &root, 5 );

	push( &( root->right ), 20 );
	push( &( root->right ), 10 );

	push( &( root->right->right ), 50 );
	push( &( root->right->right ), 22 );
	push( &( root->right->right ), 19 );

	push( &( root->right->right->right ), 45 );
	push( &( root->right->right->right ), 40 );
	push( &( root->right->right->right ), 35 );
	push( &( root->right->right->right ), 20 );

	root = flatten(root);

	display(root);
}
