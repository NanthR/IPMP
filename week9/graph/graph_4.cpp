#include<iostream>
#include<list>
#include<vector>

using namespace std;

class Graph {
  int V;
  list<int> *adj;
  bool helper(int v, vector<bool> &visited, vector<bool> &recStack) {
    if(visited[v] == false) {
        visited[v] = true;
        recStack[v] = true;

        list<int>::iterator i;
        for(auto i : adj[v]) {
            if (!visited[i] && helper(i, visited, recStack))
                return true;
            else if (recStack[i])
                return true;
        }

    }
    recStack[v] = false;
    return false;
  }

  public:
    Graph(int V) {
      this->V = V;
      adj = new list<int>[V];
    };

    void addEdge(int v, int w) {
      adj[v].push_back(w);
    }

    bool isCyclic() {
        vector<bool> visited(V, false);
        vector<bool> recStack(V, false);
        for(int i = 0; i < V; i++) {
            if (helper(i, visited, recStack))
                return true;
        }

        return false;
    }
};

int main() {
    Graph g(4);
    g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(1, 2);
    g.addEdge(2, 0);
    g.addEdge(2, 3);
    g.addEdge(3, 3);

    if(g.isCyclic())
        cout << "Graph contains cycle";
    else
        cout << "Graph doesn't contain cycle";
}
