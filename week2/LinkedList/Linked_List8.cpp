#include "linked_list.h"

int middle(node* head) {
  node *one, *two;
  one = two = head;
  while(one != NULL && one->next != NULL) {
    one = one->next->next;
    two = two->next;
  }
  return two->val;
}

int main() {
  node* head = quick_init();
  if(head == NULL)
    cout << "No middle for empty list\n";
  else
    cout << middle(head) << "\n";
}
