#include<iostream>
#include<queue>

using namespace std;

typedef pair<int, pair<int, int>> info;

void print(vector<int> &arr) {
  for(auto it = arr.begin(); it != arr.end(); it++) {
    cout << *it << " ";
  }
  cout << "\n";
}

void merge_k(vector<vector<int>> &arr) {
  priority_queue<info, vector<info>, greater<info>> pq;
  vector<int> res;
  for(int i = 0; i < arr.size(); i++) {
    pq.push(make_pair(arr[i][0], make_pair(i, 1)));
  }
  /* auto val = pq.top(); */
  /* cout << val.first; */
  for(int i = 0; i < arr.size() * arr[0].size(); i++) {
    auto val = pq.top();
    res.push_back(val.first);
    int array_no = val.second.first;
    int index = val.second.second;
    pq.push(make_pair(arr[array_no][index], make_pair(array_no, index+1)));
    pq.pop();
  }
  print(res);
}

int main() {
  vector<vector<int>> arr {{2, 6, 12, 34}, {1, 9, 20, 1000}, {23, 34, 90, 2000}};
  merge_k(arr);
}
