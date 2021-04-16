#include<bits/stdc++.h>

using namespace std;

class node {
public:
  int val;
  node* next;
};


void push(node** head_ref, int new_data) {
  node* new_node = new node[(sizeof(node))];
  new_node->val = new_data;
  new_node->next = (*head_ref);
  (*head_ref) = new_node;
}

void display(node* node) {
  while (node != NULL) {
    cout << node->val << " ";
    node = node->next;
  }
  cout << endl;
}

void swap(node** a, node** b) {
  node* t = *a;
  *a = *b;
  *b = t;
}

int size(node* node) {
  int size = 0;
  while (node != NULL) {
    node = node->next;
    size++;
  }
  return size;
}

node* add_same_size(node* head1, node* head2, int* carry) {
  if (head1 == NULL)
	  return NULL;

  int sum;

  node* result = new node[(sizeof(node))];

  result->next = add_same_size(head1->next, head2->next, carry);

  sum = head1->val + head2->val + *carry;
  *carry = sum / 10;
  sum = sum % 10;

  result->val = sum;

  return result;
}

void add_carry(node* head1, node* cur, int* carry, node** result) {
  int sum;
  if (head1 != cur) {
    add_carry(head1->next, cur, carry, result);

    sum = head1->val + *carry;
    *carry = sum / 10;
    sum %= 10;

    push(result, sum);
  }
}

void add_list(node* head1, node* head2, node** result) {
  node* cur;

  if (head1 == NULL) {
    *result = head2;
    return;
  }

  else if (head2 == NULL) {
    *result = head1;
    return;
  }

  int size1 = size(head1);
  int size2 = size(head2);

  int carry = 0;

  if (size1 == size2)
    *result = add_same_size(head1, head2, &carry);

  else {
    int diff = abs(size1 - size2);

    if (size1 < size2)
	    swap(&head1, &head2);

    for (cur = head1; diff--; cur = cur->next);

    *result = add_same_size(cur, head2, &carry);

    add_carry(head1, cur, &carry, result);
  }

  if (carry)
    push(result, carry);
}

int main() {
	node *head1 = NULL, *head2 = NULL, *result = NULL;

	int arr1[] = { 9, 9, 9 };
	int arr2[] = { 1, 8 };

	int size1 = sizeof(arr1) / sizeof(arr1[0]);
	int size2 = sizeof(arr2) / sizeof(arr2[0]);

	int i;
	for (i = size1 - 1; i >= 0; --i)
		push(&head1, arr1[i]);

	for (i = size2 - 1; i >= 0; --i)
		push(&head2, arr2[i]);

	add_list(head1, head2, &result);

	display(result);
}
