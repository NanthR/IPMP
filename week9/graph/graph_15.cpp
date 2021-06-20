#include<iostream>
#include<list>
#include<stack>
#include<vector>

using namespace std;

class Graph {
    int V;
    list<int> *adj;

public:
    Graph(int V)  {
        this->V = V;
        adj = new list<int>[V];
    }

    void addEdge(int v, int w) {
        adj[v].push_back(w);
    }
    void print() {
        stack<int> Stack;
        vector<bool> visited (V, false);

        for(int i = 0; i < V; i++) {
            if(visited[i] == false)
                fillOrder(i, visited, Stack);
        }

        Graph gr = getTranspose();
        for(int i = 0; i < V; i++)
            visited[i] = false;

        while (Stack.empty() == false) {
            int v = Stack.top();
            Stack.pop();

            if (visited[v] == false) {
                gr.helper(v, visited);
                cout << endl;
            }
        }
    }

    void helper(int v, vector<bool> &visited) {
        visited[v] = true;
        cout << v << " ";

        for(auto i: adj[v]) {
            if(!visited[i])
                helper(i, visited);
        }
    }

    Graph getTranspose() {
        Graph g(V);
        for (int v = 0; v < V; v++) {
            for(auto i: adj[v]) {
                g.adj[i].push_back(v);
            }
        }
        return g;
    }

    void fillOrder(int v, vector<bool> &visited, stack<int> &Stack) {
        visited[v] = true;

        for(auto i: adj[v]) {
            if(!visited[i])
                fillOrder(i, visited, Stack);
        }
        Stack.push(v);
    }
};

int main() {
    Graph g(5);
    g.addEdge(1, 0);
    g.addEdge(0, 2);
    g.addEdge(2, 1);
    g.addEdge(0, 3);
    g.addEdge(3, 4);

    g.print();
}
