// K Distance node
#include "tree.h"

void print(node *head ,int k)  { 
    if(head == NULL) 
      return; 
    if(k == 0) { 
      cout << head->val << " "; 
      return; 
    } else { 
      print(head->left, k - 1) ; 
      print(head->right, k - 1) ; 
    }
} 

int main() {
  node *head = quick_init();
  print(head, 2);
}
