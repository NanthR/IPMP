#include<bits/stdc++.h>

using namespace std;

class node {
  public:
    int val;
    node* next;
    node(int data) {
      val = data;
      next = NULL;
    }
};

int length(node* head) {
  int c = 0;
  node* temp = head;
  while(temp != NULL) {
    c++;
    temp = temp->next;
  }
  return c;
}

node* helper(int v, node* a, node *b) {
  node* t1 = a;
  node* t2 = b;
  for(int i = 0; i < v; i++) {
    t1 = t1->next;
  }
  while(t1 != NULL && t2 != NULL) {
    if(t1 == t2)
      return t1;
    t1 = t1->next;
    t2 = t2->next;
  }
  return NULL;
}

node* intersect(node *a, node *b) {
  int lenA = length(a);
  int lenB = length(b);
  if(lenA > lenB) {
    int v = lenA - lenB;
    return helper(v, a, b);
  }
  else {
    int v = lenB - lenA;
    return helper(v, b, a);
  }
}

int main() {
  // 1st : 1 -> 2 -> 3 -> 4
  // 2nd : 2 -> 3 -> 4
  node* a = new node(1);
  node* b = new node(2);

  a->next = b;

  node* temp;
  temp = new node(3);
  a->next->next = temp;
  b->next = temp;

  temp = new node(4);
  a->next->next->next = temp;
  b->next->next = temp;

  node* in = intersect(a, b);
  if(in == NULL)
    cout << "No intersection\n";
  else
    cout << "Intersection occurs at node with value " << in->val << "\n";
}
