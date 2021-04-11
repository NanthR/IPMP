#include "linked_list.h"

void print_reverse(node* reverse) {
  if(reverse == NULL)
    return;
  print_reverse(reverse->next);
  cout << reverse->val << " ";
}

int main() {
  node* head = quick_init();
  print_reverse(head);
  cout << "\n";
}
