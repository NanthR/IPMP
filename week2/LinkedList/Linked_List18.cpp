#include "linked_list.h"

void segregate(node** head) {
  node *es = NULL, *ee = NULL, *os = NULL, *oe = NULL;
  node* cur = *head;
  while(cur != NULL) {
    int val = cur->val;
    if(val % 2 == 0) {
      if(es == NULL) {
	es = cur;
	ee = es;
      }
      else {
	ee->next = cur;
	ee = cur;
      }
    }
    else {
      if(os == NULL) {
	os = cur;
	oe = os;
      }
      else {
	oe->next = cur;
	oe = cur;
      }
    }
    cur = cur->next;
  }
  if(es == NULL || os == NULL)
    return;
  ee->next = os;
  oe->next = NULL;
  *head = es;
}

int main() {
  node* head = quick_init();
  display(head);
  segregate(&head);
  display(head);
}
