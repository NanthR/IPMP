#include "linked_list.h"

node* reverse(node *head, int n) {
  node* cur = head;
  node* next = NULL;
  node* prev = NULL;
  int c = 0;
  while(cur && c < n) {
    next = cur->next;
    cur->next = prev;
    prev = cur;
    cur = next;
    c++;
  }
  if(head != NULL)
    head->next = cur;
  c = 0;
  while(c < n - 1 && cur) {
    cur = cur->next;
    c++;
  }
  if(cur) {
    cur->next = reverse(cur->next, n);
  }
  return prev;
}

int main() {
  node* head = quick_init();
  display(head);
  int n;
  cin >> n;
  node* rev = reverse(head, n);
  display(rev);
}
