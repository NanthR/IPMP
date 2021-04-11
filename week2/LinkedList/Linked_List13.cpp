#include "linked_list.h"

void rotate(node** head, int n) {
  if(n <= 0)
    return;
  node* cur = *head;
  int c = 1;
  while(c < n && cur != NULL) {
    cur = cur->next;
    c++;
  }
  if(cur == NULL)
    return;
  node* nth_node = cur;
  while(cur->next != NULL)
    cur = cur->next;
  cur->next = *head;
  *head = nth_node->next;
  nth_node->next = NULL;
}

int main() {
  node* head = quick_init();
  int n;
  cin >> n;
  rotate(&head, n);
  display(head);
}
