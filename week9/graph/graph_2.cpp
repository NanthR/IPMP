#include<iostream>
#include<map>
#include<vector>

using namespace std;

class Graph {
  public:
    map<int, bool> visited;
    map<int, vector<int>> adj;

    void add_edge(int v, int w) {
      adj[v].push_back(w);
    }

    void dfs(int s) {
      visited[s] = true;
      cout << s << " ";
      for(auto it: adj[s]) {
	if(!visited[it]) {
	  dfs(it);
	}
      }
    }
};

int main() {
  Graph g;
  g.add_edge(0, 1);
  g.add_edge(0, 9);
  g.add_edge(1, 2);
  g.add_edge(2, 0);
  g.add_edge(2, 3);
  g.add_edge(9, 3);
  g.dfs(2);
  cout << "\n";
  return 0;
}
