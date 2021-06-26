//Largest Independent Set

#include<iostream>
using namespace std;
 
 
class node {
public:
    int data;
    int liss;
    node *left, *right;

    node(int val) {
        left = right = NULL;
        liss = 0;
        data = val;
    }
};
 
int largest_ind_set(node *root) {
    if (root == NULL)
        return 0;
 
    if (root->liss)
        return root->liss;
 
    if (root->left == NULL && root->right == NULL)
        return (root->liss = 1);
 
    int liss_excl = largest_ind_set(root->left) + largest_ind_set(root->right);
 
    int liss_incl = 1;
    if (root->left)
        liss_incl += largest_ind_set(root->left->left) + largest_ind_set(root->left->right);
    if (root->right)
        liss_incl += largest_ind_set(root->right->left) + largest_ind_set(root->right->right);
 
    root->liss = max(liss_incl, liss_excl);
 
    return root->liss;
}
 
int main() {
    node *root = new node(20);
    root->left = new node(8);
    root->left->left = new node(4);
    root->left->right = new node(12);
    root->left->right->left = new node(10);
    root->left->right->right = new node(14);
    root->right = new node(22);
    root->right->right = new node(25);
 
    cout << largest_ind_set(root) << "\n";
}
