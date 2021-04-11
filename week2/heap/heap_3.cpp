#include "linked_list.h"

class comp {
public:
  bool operator()(const node *lhs, const node *rhs) const {
    return lhs->val > rhs->val;
  }
};

void print(vector<int> &arr) {
  for(auto it = arr.begin(); it != arr.end(); it++) {
    cout << *it << " ";
  }
  cout << "\n";
}

node* merge_k(node* arr[], int k) {
  priority_queue<node*, vector<node*>, comp> pq;
  for(int i = 0; i < k; i++) {
    pq.push(arr[i]);
  }
  node *head = NULL, *last = NULL;
 
  while (!pq.empty()) {
        node* min = pq.top();
        pq.pop();
 
        if (head == NULL) {
            head = last = min;
        }
        else {
            last->next = min;
            last = min;
        }

        if (min->next != NULL) {
            pq.push(min->next);
        }
    }
    return head;
}

int main() {
  node* arr[3];
  arr[0] = init();
  arr[1] = init();
  arr[2] = init();
  node* head = merge_k(arr, 3);
  display(head);
}
