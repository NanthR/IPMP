#include<bits/stdc++.h>

using namespace std;

bool comp(pair<int, int> &p1, pair<int, int> &p2) {
  if(p1.second == p2.second)
    return p1.first < p2.first;
  return p1.second > p2.second;
}

void sort_by_freq(vector<int> &arr) {
  map<int, int> m;
  for(int i = 0; i < arr.size(); i++) {
    m[arr[i]]++;
  }
  int s = m.size();
  pair<int, int> p[s];
  int i = 0;
  for(auto it = m.begin(); it != m.end(); it++) {
    p[i++] = make_pair(it->first, it->second);
  }
  sort(p, p+s, comp);
  for(int i = 0; i < s; i++) {
    int f = p[1].second;
    while(f--)
      cout << p[i].first << " ";
  }
  cout << "\n";
}

int main() {
  vector<int> arr {2, 3, 2, 4, 5, 12, 2, 3, 3, 3, 12};
  sort_by_freq(arr);
}
