#include<iostream>
#include<unordered_map>

using namespace std;

void first(string x) {
  unordered_map<char, int> st;
  for(auto &i: x) {
    if(st.find(i) == st.end()) {
      st[i] = 1;
    } else {
      st[i]++;
    }
  }
  for(auto &i: x) {
    if(st[i] == 1) {
      cout << i << "\n";
      return;
    }
  }
}

int main() {
  string m = "hello how are you";
  first(m);
}
