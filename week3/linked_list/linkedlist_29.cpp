#include "linked_list.h"

node* sorted_merge(node* a, node* b) {
  node* result = NULL;

  if (a == NULL)
    return (b);
  else if (b == NULL)
    return (a);

  if (a->val <= b->val) {
    result = a;
    result->next = sorted_merge(a->next, b);
  }
  else {
    result = b;
    result->next = sorted_merge(a, b->next);
  }
  return result;
}

void front_back_split(node* source, node** front, node** back) {
  node* fast;
  node* slow;
  slow = source;
  fast = source->next;

  while (fast != NULL) {
    fast = fast->next;
    if (fast != NULL) {
	slow = slow->next;
	fast = fast->next;
    }
  }

  *front = source;
  *back = slow->next;
  slow->next = NULL;
}

void merge_sort(node** headRef) {
  node* head = *headRef;
  node* a;
  node* b;

  if ((head == NULL) || (head->next == NULL)) {
    return;
  }

  front_back_split(head, &a, &b);

  merge_sort(&a);
  merge_sort(&b);

  *headRef = sorted_merge(a, b);
}

int main() {
  node* a = init();
  merge_sort(&a);

  display(a);
}
