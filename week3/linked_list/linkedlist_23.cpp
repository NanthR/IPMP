#include "linked_list.h"

long multiply(node* first, node* second) {
  int num1 = 0, num2 = 0;

  while (first || second) {
    if (first) {
      num1 = num1*10 + first->val;
      first = first->next;
    }
    if (second) {
      num2 = num2*10 + second->val;
      second = second->next;
    }
  }

  return num1*num2;
}

int main(void) {
  node* first = init();
  node* second = init();

  cout << multiply(first, second);
}
