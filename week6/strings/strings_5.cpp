#include<iostream>
#include<unordered_map>

using namespace std;

void dupli(string x) {
  unordered_map<char, int> map;
  for(auto &i: x) {
    if(map.find(i) == map.end())
      map[i] = 1;
    else
      map[i]++;
  }
  for(auto &i: map) {
    if(i.second > 1)
      cout << i.first << "\n";
  }
}

int main() {
  string m = "hello how are you";
  dupli(m);
}
