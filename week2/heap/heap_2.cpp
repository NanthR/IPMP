#include<iostream>
#include<fstream>
#include<vector>
#include<queue>
#include<map>
#include<sstream>

using namespace std;

typedef pair<int, string> info;

void topwords(vector<string>&st, int k) {
  priority_queue<info, vector<info>, greater<info>> pq;
  map<string, int> word_freq;
  for(auto it = st.begin(); it != st.end(); it++) 
    word_freq[*it]++;
   
  for(auto it = word_freq.begin(); it != word_freq.end(); it++) {
    pq.push(make_pair(it->second, it->first));
    if(pq.size() > k)
      pq.pop();
  }
  while(!pq.empty()) {
    auto val = pq.top();
    cout << val.second << ":" << val.first << "\n";
    pq.pop();
  }
}

int main() {
  int k;
  cin >> k;
  ifstream f("./file.txt");
  string line;
  vector<string> st;
  while(getline(f, line)) {
    istringstream iss(line);
    string word;
    while(iss >> word) {
      st.push_back(word);
    }
  }
  topwords(st, k);
}
