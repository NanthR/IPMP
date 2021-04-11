#include "linked_list.h"

bool check(node* head) {
  stack<int> st;
  node* temp = head;
  while(temp != NULL) {
    st.push(temp->val);
    temp = temp->next;
  }
  temp = head;
  while(temp != NULL) {
    int x = st.top();
    st.pop();
    if(x != temp->val)
      return false;
    temp = temp->next;
  }
  return true;
}

int main() {
  node* head = init();
  cout << check(head) << "\n";
}
