#include<iostream>
#include<list>
#include<climits>
#include<vector>

using namespace std;

class Graph {
    int V;
    list<int> *adj;

public:
    Graph(int V) {
        this->V = V;
        adj = new list<int>[V];
    }

    void addEdge(int v, int w) {
        adj[v].push_back(w);
        adj[w].push_back(v);
    }

    bool is_cycle() {
        vector<bool> visited(V, false);

        for (int u = 0; u < V; u++) {
            if(!visited[u]) {
                if (helper(u, visited, -1))
                    return true;
            }
        }
        return false;
    }

    bool helper(int v, vector<bool> &visited, int parent) {
        visited[v] = true;
        for (auto i: adj[v]) {

            if (!visited[i]) {
                if(helper(i, visited, v))
                    return true;
            }

            else if (i != parent)
                return true;
        }
        return false;
    }
};

int main() {
    Graph g(5);
    g.addEdge(1, 0);
    g.addEdge(0, 2);
    g.addEdge(2, 1);
    g.addEdge(0, 3);
    g.addEdge(3, 4);
    cout << g.is_cycle() << "\n";
}
