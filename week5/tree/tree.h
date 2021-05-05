#include<iostream>

using namespace std;

class node {
  public:
    int val;
    node* left;
    node* right;
    node(int data) {
      val = data;
      left = right = NULL;
    }
};
