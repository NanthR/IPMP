#include<iostream>
#include<vector>
#include<climits>

using namespace std;

int min_dist(vector<int> &dist, vector<bool> &sptSet) {
    int min = INT_MAX, min_index;

    int V = dist.size();
    for (int v = 0; v < V; v++)
        if (sptSet[v] == false && dist[v] <= min)
            min = dist[v], min_index = v;

    return min_index;
}

void print(vector<int> &dist) {
    cout << "Vertex \t\t Distance from Source\n";
    int V = dist.size();
    for (int i = 0; i < V; i++)
        cout << i << " \t\t " <<  dist[i] << "\n";
}

void dijkstra(vector<vector<int>> &graph, int src) {
    int V = graph.size();
    vector<int> dist(V, INT_MAX);

    vector<bool> sptSet(V, false);

    dist[src] = 0;

    for (int count = 0; count < V - 1; count++) {
        int u = min_dist(dist, sptSet);
        sptSet[u] = true;
        for (int v = 0; v < V; v++) {
            if(!sptSet[v] && graph[u][v] && dist[u] != INT_MAX && dist[u] + graph[u][v] < dist[v])
                dist[v] = dist[u] + graph[u][v];
        }
    }

    print(dist);
}

int main() {
    vector<vector<int>> graph = { { 0, 4, 0, 0, 0, 0, 0, 8, 0 },
                        { 4, 0, 8, 0, 0, 0, 0, 11, 0 },
                        { 0, 8, 0, 7, 0, 4, 0, 0, 2 },
                        { 0, 0, 7, 0, 9, 14, 0, 0, 0 },
                        { 0, 0, 0, 9, 0, 10, 0, 0, 0 },
                        { 0, 0, 4, 14, 10, 0, 2, 0, 0 },
                        { 0, 0, 0, 0, 0, 2, 0, 1, 6 },
                        { 8, 11, 0, 0, 0, 0, 1, 0, 7 },
                        { 0, 0, 2, 0, 0, 0, 6, 7, 0 } };

    dijkstra(graph, 0);
}
