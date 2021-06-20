#include<iostream>
#include<vector>

using namespace std;

#define INF 99999

void print(vector<vector<int>> &dist) {
    for(auto i: dist) {
        for(auto j: i) {
            if(j == INF)
                cout << "INF ";
            else {
                cout << j << " ";
            }
        }
        cout << "\n";
    }
}

void floyd_warshal(vector<vector<int>> &graph) {
    int i, j, k;
    vector<vector<int>> dist (graph.size(), vector<int>(graph[0].size(), 0));

    int V = dist.size();
    for (i = 0; i < V; i++) {
        for (j = 0; j < V; j++) {
            dist[i][j] = graph[i][j];
        }
    }

    for (k = 0; k < V; k++) {
        for (i = 0; i < V; i++) {
            for (j = 0; j < V; j++) {
                if (dist[i][j] > (dist[i][k] + dist[k][j]) && (dist[k][j] != INF && dist[i][k] != INF))
                    dist[i][j] = dist[i][k] + dist[k][j];
            }
        }
    }

    print(dist);
}


int main() {
    vector<vector<int>> graph {{ 0, 5, INF, 10 },
                        { INF, 0, 3, INF },
                        { INF, INF, 0, 1 },
                        { INF, INF, INF, 0 }};

    floyd_warshal(graph);
}
