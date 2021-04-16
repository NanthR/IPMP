#include <iostream>

using namespace std;

class node {
public:
  int val;
  node *next,*random;
  node(int data) {
    val = data;
    next = random = NULL;
  }
};

void display(node *start) {
  node *ptr = start;
  while (ptr) {
    cout << "Data = " << ptr->val << ", Random = " << ptr->random->val << "\n";
    ptr = ptr->next;
  }
}

node* clone(node *start) {
  node* curr = start, *temp;

  while (curr) {
    temp = curr->next;

    curr->next = new node(curr->val);
    curr->next->next = temp;
    curr = temp;
  }

  curr = start;

  while (curr) {
    if(curr->next)
      curr->next->random = curr->random ? curr->random->next : curr->random;

    curr = curr->next?curr->next->next:curr->next;
  }

  node* original = start, *copy = start->next;

  temp = copy;

  while (original && copy) {
    original->next =
    original->next? original->next->next : original->next;

    copy->next = copy->next?copy->next->next:copy->next;
    original = original->next;
    copy = copy->next;
  }

  return temp;
}

int main() {
  node* start = new node(1);
  start->next = new node(2);
  start->next->next = new node(3);
  start->next->next->next = new node(4);
  start->next->next->next->next = new node(5);

  start->random = start->next->next;
  start->next->random = start;
  start->next->next->random = start->next->next->next->next;
  start->next->next->next->random = start->next->next->next->next;
  start->next->next->next->next->random = start->next;

  display(start);

  cout << "\nCloned list : \n";
  node *cloned_list = clone(start);
  display(cloned_list);
}
