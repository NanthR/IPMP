#include "tree.h"
using namespace std;
  
class LNode { 
public:
  int data; 
  LNode* next; 
}; 
  
node* newNode(int data); 
int count_list_nodes(LNode *head); 
node* llist_to_bstRecur(LNode **head_ref, int n); 
  
node* llist_to_bst(LNode *head)  { 
    int n = count_list_nodes(head); 
    return llist_to_bstRecur(&head, n); 
} 
  
node* llist_to_bstRecur(LNode **head_ref, int n)  { 
  if (n <= 0) 
    return NULL; 

  node *left = llist_to_bstRecur(head_ref, n/2); 

  node *root = new node((*head_ref)->data); 
  root->left = left; 

  *head_ref = (*head_ref)->next; 
  root->right = llist_to_bstRecur(head_ref, n - n / 2 - 1); 
  return root; 
} 
  
int count_list_nodes(LNode *head)  { 
  int count = 0; 
  LNode *temp = head; 
  while(temp)  { 
    temp = temp->next; 
    count++; 
  } 
  return count; 
} 
  
void push(LNode** head_ref, int new_data)  { 
  LNode* new_node = new LNode();
  new_node->data = new_data; 
  new_node->next = (*head_ref); 
  (*head_ref) = new_node; 
} 
  
void print_list(LNode *node)  { 
  while(node!=NULL) { 
    cout << node->data << " "; 
    node = node->next; 
  } 
} 
  
int main() { 
  LNode* head = NULL; 

  push(&head, 7); 
  push(&head, 6); 
  push(&head, 5); 
  push(&head, 4); 
  push(&head, 3); 
  push(&head, 2); 
  push(&head, 1); 

  print_list(head); 
  cout << "\n";

  node *root = llist_to_bst(head); 
  inorder(root); 
} 
