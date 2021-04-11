#include<iostream>

using namespace std;

class node {
  public:
    char val;
    node* next;
    node(char data) {
      val = data;
      next = NULL;
    }
};

node* init() {
  int n;
  cin >> n;
  if(n < 1)
    return NULL;
  char a;
  cin >> a;
  node* head = new node(a);
  node *temp, *pre;
  temp = head;
  for(int i = 2; i <= n; i++) {
    cin >> a;
    pre = new node(a);
    temp-> next = pre;
    temp = temp->next;
  }
  return head;
}

void display(node* head) {
  if(head == NULL)
    cout << "Empty list\n";
  node* temp = head;
  while(temp != NULL) {
    cout << temp->val << " ";
    temp = temp->next;
  }
  cout << "\n";
}

void segregate(node** head) {
  node *es = NULL, *ee = NULL, *os = NULL, *oe = NULL;
  node* cur = *head;
  while(cur != NULL) {
    int val = cur->val;
    if(!(val == 'a' || val == 'e' || val == 'i' || val == 'o' || val == 'u')) {
      if(es == NULL) {
	es = cur;
	ee = es;
      }
      else {
	ee->next = cur;
	ee = cur;
      }
    }
    else {
      if(os == NULL) {
	os = cur;
	oe = os;
      }
      else {
	oe->next = cur;
	oe = cur;
      }
    }
    cur = cur->next;
  }
  if(es == NULL || os == NULL)
    return;
  ee->next = os;
  oe->next = NULL;
  *head = es;

}

int main() {
  node* head = init();
  segregate(&head);
  display(head);
}
