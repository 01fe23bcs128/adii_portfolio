#include <iostream>
#include <vector>
#include <queue>
using namespace std;

void bfsOfGraph(int V, vector<int> adj[], int start) {
    vector<bool> visited(V, false);
    queue<int> q;
    q.push(start);
    visited[start] = true;

    cout << "BFS Traversal: ";
    while (!q.empty()) {
        int node = q.front();
        q.pop();
        cout << node << " ";

        // Explore all the neighbors
        for (int neighbor : adj[node]) {
            if (!visited[neighbor]) {
                visited[neighbor] = true;
                q.push(neighbor);
            }
        }
    }
    cout << endl;
}

int main() {
    int V, E;
    cout << "Enter number of vertices and edges: ";
    cin >> V >> E;

    vector<int> adj[V];
    
    cout << "Enter the edges (u v) for each edge:\n";
    for (int i = 0; i < E; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);  // For an undirected graph
    }

    int start;
    cout << "Enter the starting vertex for BFS: ";
    cin >> start;

    bfsOfGraph(V, adj, start);
    
    return 0;
}
