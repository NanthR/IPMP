#include "linked_list.h"
  
int count(node* a) {
  int c = 0;
  while (a != NULL) {
    c++;
    a = a->next;
  }
  return c;
}
  
void swapKth(struct node** head, int k) {
  int n = count(*head);

  if (n < k)
      return;
  if (2 * k - 1 == n)
      return;

  node* x = *head;
  node* x_prev = NULL;
  for (int i = 1; i < k; i++) {
      x_prev = x;
      x = x->next;
  }

  node* y = *head;
  node* y_prev = NULL;
  for (int i = 1; i < n - k + 1; i++) {
      y_prev = y;
      y = y->next;
  }

  if (x_prev)
      x_prev->next = y;

  if (y_prev)
      y_prev->next = x;

  node* temp = x->next;
  x->next = y->next;
  y->next = temp;

  if (k == 1)
      *head = y;
  if (k == n)
      *head = x;
}
  
int main() {
  node* head = quick_init(); 

  for (int i = 1; i <= 10; i++) {
    swapKth(&head, i);
    cout << "Modified List for k = " << i << "\n";
    display(head);
  }
}
