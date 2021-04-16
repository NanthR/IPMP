#include "linked_list.h"

node* swap(node* head) {
  node* temp = head;
  while(temp != NULL && temp->next != NULL) {
    int v = temp->val;
    temp->val = temp->next->val;
    temp->val = v;
    temp = temp->next->next;
  }
  return head;
}

int main() {
  node* head = quick_init();
  node* res = swap(head);
  display(res);
}
