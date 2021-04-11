#include "linked_list.h"

void alternate_split(node* head, node**ac, node**bc) {
  node *d1 = new node(-1);
  node *d2 = new node(-1);
  node *t1 = d1;
  node* t2 = d2;
  node* cur = head;
  int c = 0;
  while(cur != NULL) {
    if(c % 2 == 0) {
      d1->next = cur;
      d1 = d1->next;
    }
    else {
      d2->next = cur;
      d2 = d2->next;
    }
    cur = cur->next;
    c++;
  }
  d1->next = NULL;
  d2->next = NULL;
  *ac = t1->next;
  *bc = t2->next;
}

int main() {
  node* head = quick_init();
  node *a = NULL, *b = NULL;
  alternate_split(head, &a, &b);
  cout << "First\n";
  display(a);

  cout << "Second\n";
  display(b);
}
