#include<iostream>
#include<map>
#include<vector>
#include<queue>

using namespace std;

class Graph {
  public:
    map<int, bool> visited;
    map<int, vector<int>> adj;

    void add_edge(int v, int w) {
      adj[v].push_back(w);
    }

    void bfs(int s) {
      queue<int> q;
      q.push(s);
      visited[s] = true;
      while(!q.empty()) {
	s = q.front();
	cout << s << " ";
	q.pop();
	for(auto it: adj[s]) {
	  if(!visited[it]) {
	    visited[it] = true;
	    q.push(it);
	  }
	}
      }
      cout << "\n";
    }
};

int main() {
  Graph g;
  g.add_edge(0, 1);
  g.add_edge(0, 2);
  g.add_edge(1, 2);
  g.add_edge(2, 0);
  g.add_edge(2, 3);
  g.add_edge(3, 3);
  g.bfs(2);
}
