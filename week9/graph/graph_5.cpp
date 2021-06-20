#include<iostream>
#include<list>
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
    void add_edge(int v, int w) {
        adj[v].push_back(w);
    }
    bool is_reachable(int s, int d) {
        if(s == d)
            return true;

        vector<bool> visited (V, false);

        list<int> queue;

        visited[s] = true;
        queue.push_back(s);

        while(!queue.empty()) {
            s = queue.front();
            queue.pop_front();

            for(auto i : adj[s]) {
                if(i == d)
                    return true;

                if(!visited[i]) {
                    visited[i] = true;
                    queue.push_back(i);
                }
            }
        }

        return false;
    }
};

int main() {
    Graph g(4);
    g.add_edge(0, 1);
    g.add_edge(0, 2);
    g.add_edge(1, 2);
    g.add_edge(2, 0);
    g.add_edge(2, 3);
    g.add_edge(3, 3);

    cout << g.is_reachable(1, 3) << "\n";
}
