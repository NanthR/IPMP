#include "linked_list.h"

void sort012(node* head) {
  int c[3] = {0, 0, 0};
  node *temp = head;
  while(temp != NULL) {
    c[temp->val]++;
    temp = temp->next;
  }
  int i = 0;
  temp = head;
  while(temp != NULL) {
    if(c[i] == 0)
      i++;
    else {
      temp->val = i;
      c[i]--;
      temp = temp->next;
    }
  }
}

int main() {
  node* head = init();
  sort012(head);
  display(head);
}
