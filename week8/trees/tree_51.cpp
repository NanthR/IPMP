#include<bits/stdc++.h>
using namespace std;
  
class node  { 
public:
  int data; 
  node* next; 
  node* prev; 
}; 
  
int counts(node *head); 
node* helper(node **head_ref, int n); 
  
node* sortedListToBST(node *head)  { 
  int n = counts(head); 
  return helper(&head, n); 
} 
  
node* helper(node **head_ref, int n) { 
  if (n <= 0) 
    return NULL; 

  node *left = helper(head_ref, n/2); 

  node *root = *head_ref; 
  root->prev = left; 

  *head_ref = (*head_ref)->next; 
  root->next = helper(head_ref, n-n/2-1); 

  return root; 
} 
  
int counts(node *head) { 
  int count = 0; 
  node *temp = head; 
  while(temp) { 
      temp = temp->next; 
      count++; 
  } 
  return count; 
} 
  
void push(node** head_ref, int new_data) { 
  node* new_node = new node();
  new_node->data = new_data; 
  new_node->prev = NULL; 

  new_node->next = (*head_ref); 

  if((*head_ref) != NULL) 
    (*head_ref)->prev = new_node; 

  (*head_ref) = new_node; 
} 
  
void print_list(node *node)  { 
  while (node!=NULL)  { 
    cout<<node->data<<" "; 
    node = node->next; 
  } 
} 
  
void pre_order(node* node)  { 
  if (node == NULL) 
      return; 
  cout<<node->data<<" "; 
  pre_order(node->prev); 
  pre_order(node->next); 
} 
  
int main()  { 
  node* head = NULL; 

  push(&head, 7); 
  push(&head, 6); 
  push(&head, 5); 
  push(&head, 4); 
  push(&head, 3); 
  push(&head, 2); 
  push(&head, 1); 

  print_list(head); 

  node *root = sortedListToBST(head); 
  pre_order(root); 
  cout << "\n";
} 
