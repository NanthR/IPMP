#include "linked_list.h"

bool isSum(node* a, node *b, node *c, int sum) {
  node *ta = a;
  while(ta) {
    node *tb = b;
    node *tc = c;
    while(tb && tc) {
      int val = a->val + b->val + c->val;
      if(val == sum)
	return true;
      else if(val < sum)
	tb = tb->next;
      else
	tc = tc->next;
    }
    ta = ta->next;
  }
  return false;
}

int main() {
  node* a = init();
  node* b = init();
  node* c = init();
  int sum;
  cin >> sum;
  cout << isSum(a, b, c, sum) << "\n";
}
