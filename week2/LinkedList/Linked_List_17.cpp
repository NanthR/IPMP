#include<iostream>

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

void add(node** head, int val) {
  node* next = new node(val);

}
