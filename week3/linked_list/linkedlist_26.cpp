#include "linked_list.h"
  
void skip_m_delete_n(node *head, int m, int n) { 
  node *curr = head, *t; 
  int c; 
  
  while (curr) { 
    for (c = 1; c < m && curr!= NULL; c++) 
      curr = curr->next; 
  
    if (curr == NULL) 
      return; 
  
    t = curr->next; 
    for (c = 1; c<=n && t!= NULL; c++) { 
      node *temp = t; 
      t = t->next; 
      free(temp); 
    } 
    curr->next = t; 
    curr = t; 
  } 
} 
  
int main() { 
    node* head = quick_init(); 
    int m=2, n=3; 
  
    skip_m_delete_n(head, m, n); 
    cout<<"\nLinked list after deletion is :\n"; 
    display(head); 
} 
