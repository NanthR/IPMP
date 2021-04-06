#include "linked_list.h"

void alternate_del(node* head) {
  if(head == NULL)
    return;
  node* cur = head;
  while(cur != NULL && cur->next != NULL) {
    node* next = cur->next;
    cur->next = next->next;
    free(next);
    cur = cur->next;
  }
}

int main() {
  node* head = quick_init();
  display(head);
  alternate_del(head);
  display(head);
}
