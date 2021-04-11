#include<bits/stdc++.h>

using namespace std;

class node {
  public:
    int val;
    node* next;
    node(int data) {
      val = data;
      next = NULL;
    }
};

node* init() {
  int n;
  cin >> n;
  if(n < 1)
    return NULL;
  int a;
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

node* quick_init() {
  int n;
  cin >> n;
  if(n < 1)
    return NULL;
  node* head = new node(1);
  node *temp, *pre;
  temp = head;
  for(int i = 2; i <= n; i++) {
    pre = new node(i);
    temp->next = pre;
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
