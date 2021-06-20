#include<iostream>
#include<list>
#include<stack>
#include<vector>

using namespace std;

class Graph {
    int V;
    list<int>* adj;

public:
    Graph(int V) {
        this->V = V;
        adj = new list<int>[V];
    }
    void addEdge(int v, int w) {
        adj[v].push_back(w);
    }

    void topological_sort() {
        stack<int> Stack;

        vector<bool> visited (V, false);

        for(int i = 0; i < V; i++) {
            if(visited[i] == false) {
                helper(i, visited, Stack);
            }
        }

        while (Stack.empty() == false) {
            cout << Stack.top() << " ";
            Stack.pop();
        }
        cout << "\n";
    }
    void helper(int v, vector<bool> &visited, stack<int>& Stack) {
        visited[v] = true;

        for(auto i: adj[v]) {
            if (!visited[i])
                helper(i, visited, Stack);
        }

        Stack.push(v);
    }
};

int main() {
    Graph g(6);
    g.addEdge(5, 2);
    g.addEdge(5, 0);
    g.addEdge(4, 0);
    g.addEdge(4, 1);
    g.addEdge(2, 3);
    g.addEdge(3, 1);

    g.topological_sort();
}
