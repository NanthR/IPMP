#include "linked_list.h"

using namespace std;

void push(node** head_ref, int new_data) {
  node* new_node = new node(new_data);
  new_node->next = (*head_ref);
  (*head_ref) = new_node;
}

bool isPresent(node* head, int data) {
  node* t = head;
  while (t != NULL) {
    if (t->val == data)
        return 1;
    t = t->next;
  }
  return 0;
}
 
node* getUnion(node* head1, node* head2) {
  node *result = NULL;
  node *t1 = head1, *t2 = head2;
  while (t1 != NULL) {
    push(&result, t1->val);
    t1 = t1->next;
  }
  while (t2 != NULL) {
    if (!isPresent(result, t2->val))
      push(&result, t2->val);
    t2 = t2->next;
  }
  return result;
}
 
node* getIntersection(node* head1, node* head2) {
  node* result = NULL;
  node* t1 = head1;
  while (t1 != NULL) {
    if (isPresent(head2, t1->val))
      push(&result, t1->val);
    t1 = t1->next;
  }
  return result;
}
 
void printList(node* node) {
  while (node != NULL) {
    cout << node->val << " ";
    node = node->next;
  }
  cout << "\n";
}
 
int main() {
  node* head1 = init();
  node* head2 = init();
  node* intersecn = NULL;
  node* unin = NULL;

  intersecn = getIntersection(head1, head2);
  unin = getUnion(head1, head2);
  cout << "Intersection\n";
  printList(intersecn);
  cout << "Union\n";
  printList(unin);
}
