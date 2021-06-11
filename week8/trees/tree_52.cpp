#include "tree.h"
  
node* array_to_bst(int arr[], int start, int end) { 
  if (start > end) 
    return NULL; 

  int mid = (start + end)/2; 
  node *head = new node(arr[mid]); 

  head->left = array_to_bst(arr, start, mid - 1); 

  head->right = array_to_bst(arr, mid + 1, end); 

  return head; 
} 
  
int main()  { 
    int arr[] = {1, 2, 3, 4, 5, 6, 7}; 
    int n = sizeof(arr) / sizeof(arr[0]); 
  
    node *head = array_to_bst(arr, 0, n-1); 
    inorder(head); 
} 
