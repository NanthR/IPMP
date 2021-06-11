#include "tree.h"

int path_sum(node* head, int sum) {
  if (head == NULL) {
    return (sum == 0);
  }
   
  else {
    bool ans = 0;
 
    int subSum = sum - head->val;
 
    if(subSum == 0 && head->left == NULL && head->right == NULL)
      return 1;
     
    if(head->left)
	ans = ans || path_sum(head->left, subSum);
    if(head->right)
	ans = ans || path_sum(head->right, subSum);
 
    return ans;
  }
}

int main() {
  node* head = quick_init();
  cout << path_sum(head, 20) << "\n";
}
