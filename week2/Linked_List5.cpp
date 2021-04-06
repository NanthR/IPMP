#include "linked_list.h"

void l_delete(node* &head) {
  while(head != NULL) {
    node* next = head->next;
    free(head);
    head = next;
  }
}

int main() {
  node* head = quick_init();
  display(head);
  l_delete(head);
  display(head);
}
