#include "linked_list.h"

void detect_and_remove(node* head) {
  if(head == NULL || head->next == NULL)
    return;
  node *a = head, *b = head;
  while(b && b->next) {
    a = a->next;
    b = b->next->next;
    if(a == b)
      break;
  }
  if(a == b) {
    a = head;
    if(a == b) {
      while(b -> next != a)
	b = b->next;
    }
    else {
      while(a->next != b->next) {
	a = a->next;
	b = b->next;
      }
    }
    b->next = NULL;
  }
}

int main() {
  node* head = new node(1);
  head-> next = new node(2);
  head->next->next = new node(3);
  head->next->next->next = head->next;
  detect_and_remove(head);
  display(head);
}
