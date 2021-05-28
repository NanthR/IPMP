#include<iostream>

using namespace std;

class node {
public:
  int val;
  node* left;
  node* right;
  node* nextRight;
  node(int data) {
    val = data;
    left = right = nextRight = NULL;
  }
};

node *getNextRight(node *p) { 
  node *temp = p->nextRight; 

  while (temp != NULL) { 
    if (temp->left != NULL) 
      return temp->left; 
    if (temp->right != NULL) 
      return temp->right; 
    temp = temp->nextRight; 
  } 

  return NULL; 
} 
  
void join(node* p) { 
  node *temp; 

  if (!p) 
    return; 

  p->nextRight = NULL; 

  while (p != NULL) { 
    node *q = p; 

    while (q != NULL) { 
      if (q->left) { 
	if (q->right) 
	  q->left->nextRight = q->right; 
	else
	  q->left->nextRight = getNextRight(q); 
      } 
      if (q->right) 
	q->right->nextRight = getNextRight(q); 
      q = q->nextRight; 
    } 

    if (p->left) 
      p = p->left; 
    else if (p->right) 
      p = p->right; 
    else
      p = getNextRight(p); 
  } 
} 

node* quick_init() {
  node *head = new node(1);
  head->left = new node(2);
  head->right = new node(3);
  head->left->left = new node(4);
  head->left->right = new node(5);
  head->right->left = new node(6);
  head->right->right = new node(7);
  return head;
}

int main() {
  node *head = quick_init();
  join(head);
}
