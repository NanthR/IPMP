#include "linked_list.h"

void nthFromEnd(node* head, int n) {
  node* temp = head;
  int c = 0;
  while(c < n) {
    if(temp == NULL) {
      cout << "Not enough elements\n";
      return;
    }
    temp = temp->next;;
    c++;
  }
  node* next = head;
  while(temp != NULL) {
    temp = temp->next;
    next = next->next;
  }
  cout << next->val << "\n";
}

int main() {
  node* head = quick_init();
  int n;
  cin >> n;
  nthFromEnd(head, n);
}
