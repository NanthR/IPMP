#include<iostream>
#include<vector>
#include<list>
#include<climits>
#include<stack>

#define INF INT_MAX

using namespace std;

class AdjListNode {
    int v;
    int weight;
public:
    AdjListNode(int x, int y) {
        v = x;  weight = y;
    }
    int getV(){
        return v;
    }
    int getWeight() {
        return weight;
    }
};

class Graph {
    int V;
    list<AdjListNode> *adj;
    void helper(int v, vector<bool> &visited, stack<int> &Stack) {
        visited[v] = true;

        for(auto i: adj[v]) {
            AdjListNode node = i;
            if (!visited[node.getV()])
                helper(node.getV(), visited, Stack);
        }

        Stack.push(v);
    }
public:
    Graph(int V) {
        this->V = V;
        adj = new list<AdjListNode>[V];
    }

    void add_edge(int u, int v, int weight) {
        AdjListNode node(v, weight);
        adj[u].push_back(node);
    }

    void shortest_path(int s) {
        stack<int> Stack;
        int dist[V];

        vector<bool> visited(V, false);
        for (int i = 0; i < V; i++)
            visited[i] = false;

        for (int i = 0; i < V; i++)
            if (visited[i] == false)
                helper(i, visited, Stack);

        for (int i = 0; i < V; i++)
            dist[i] = INF;
        dist[s] = 0;

        while (Stack.empty() == false) {
            int u = Stack.top();
            Stack.pop();
            list<AdjListNode>::iterator i;
            if (dist[u] != INF) {
            for (auto i: adj[u]) {
                if (dist[i.getV()] > dist[u] + i.getWeight())
                    dist[i.getV()] = dist[u] + i.getWeight();
            }
        }
    }

    for (int i = 0; i < V; i++)
        (dist[i] == INF)? cout << "INF ": cout << dist[i] << " ";
    }
};

int main() {
    Graph g(6);
    g.add_edge(0, 1, 5);
    g.add_edge(0, 2, 3);
    g.add_edge(1, 3, 6);
    g.add_edge(1, 2, 2);
    g.add_edge(2, 4, 4);
    g.add_edge(2, 5, 2);
    g.add_edge(2, 3, 7);
    g.add_edge(3, 4, -1);
    g.add_edge(4, 5, -2);

    int s = 1;
    g.shortest_path(s);
}
