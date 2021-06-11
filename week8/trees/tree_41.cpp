#include "tree.h"

void swap(int* a, int* b) {
  int t = *a;
  *a = *b;
  *b = t;
}

void helper(node* head, node** first, node** mid, node** last, node** prev) {
  if(head) {
    helper(head->left, first, mid, last, prev);
    if(*prev && head->val < (*prev)->val) {
      if(!*first) {
	*first = *prev;
	*mid = head;
      } else {
	*last = head;
      }
    }
    *prev = head;
    helper(head->right, first, mid, last, prev);
  }
}

void correct(node* head) {
  node *first, *mid, *last, *prev;
  first = mid = last = prev = NULL;
  helper(head, &first, &mid, &last, &prev);
  if(first && last)
    swap(&(first->val), &(last->val));
  else if(first && mid)
    swap(&(first->val), &(mid->val));
}
