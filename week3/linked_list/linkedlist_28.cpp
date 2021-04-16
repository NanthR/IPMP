#include "linked_list.h"
  
void merge(node *p, node **q) { 
  node *p_curr = p, *q_curr = *q; 
  node *p_next, *q_next; 

  while (p_curr != NULL && q_curr != NULL) { 
    p_next = p_curr->next; 
    q_next = q_curr->next; 

    q_curr->next = p_next;
    p_curr->next = q_curr;

    p_curr = p_next; 
    q_curr = q_next; 
  } 

  *q = q_curr;
} 
  
int main() { 
  node *p = NULL, *q = NULL; 
  p = init();
  q = init();

  merge(p, &q); 

  cout<<"Modified First Linked List:\n"; 
  display(p); 

  cout<<"Modified Second Linked List:\n"; 
  display(q); 
} 
